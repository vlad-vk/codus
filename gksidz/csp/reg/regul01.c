//---------------------------------------------------------------------------
//  Подкачка шлама

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f  far  DIH220___C=0;            // верхний уровень мешалки шлама для контроля
_f  far *DONPR01;                 // текущий сигнал (комманда) выхода на исполн
_i  far  DONCN01=0;               // счетчик цикла передергивания
_i  far  DONCH01=2;               // заданное кол-во циклов для передергивания
_i  far  DONTM01=2;               // кол-во секунд вкл и паузы

//---------------------------------------------------------------------------
//  Определения для передергивание исполнителей регулятора при несработке
vd  Isp01PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR01= IOPNT;
    DONCH01= hM;
    DONTM01= hS;
    STEP01 = Step; 
    STEP01_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_01off(vd){
    DON011___V =  OFF;
    DON012___V =  OFF;
    DON021___V =  OFF;
    DON022___V =  OFF;
    DON031___V =  OFF;
    DON032___V =  OFF;
    DON041___V =  OFF;
    DON042___V =  OFF;
    DON051___V =  OFF;
    DON052___V =  OFF;
    DONR01P1_V =  OFF;
    DONR01PK_V =  OFF;
    DONR01PKSV =  OFF;
    DONR01PKVV =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выполнение действий при выключеном регуляторе
vd  far Regul_01m(vd){
    //-----------------------------------------------------------------------
    if ( STEP01 == 101 ){
         REG01SW__V = 1001;
         // если выключили регулятор где-то посередине-
         // сделать выгрузку, продувку и вернуться на этот же шаг
         if(STEP01P>1 and STEP01P<5 and DIRR01PN_V==AUTO){ 
            STEP01=4; STEP01_BACK=101;  REG01R___V =REG01R___M=ON;
            return; 
         }
         if(STEP01P==6 and DIRR01PN_V==AUTO){ 
            STEP01=15; STEP01_BACK=101; REG01R___M=OFF; 
            return; 
         }
         if(RegRUN==OFF){ return; }
         // комманда на закрытие клапанов в шламобассейнах
         DON032___V=OFF; DON042___V=OFF; DON052___V=OFF;
         switch ( Check_TO  (11, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         }
         // комманда на закрытие клапанов из шламобассейнов
         // и клапанов подачи шлама в пн.насосы
         DON031___V=OFF; DON041___V=OFF; DON051___V=OFF;
         DON012___V=OFF; DON022___V=OFF;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         // комманда на закрытие клапанов подачи воздуха в пн.насосы
         DON011___V=OFF; DON021___V=OFF;
         switch ( Check_TO  (14, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         Clear_TO(15);
         Clear_TO(16);
         Clear_TO(17);
         Clear_TO(18);
         // повторная комманда на закрытие всех исполнителей регулятора
         Regul_01off();
         // обнуление счетчиков и таймеров
         LOAD_SLCNC=0;
         COUN_SLDZC=COUN_SLDZW;
         STEP01 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 == 102 ){
         STEP01P = 102;
         REG01SW__V = 1002;
         REG01R___M = OFF;
         STEP01_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP01=101;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  Определение соответствий входов-выходов для каждого ШламоБассейна
vd  far RegNSET(vd){
    if ( DIR031SETV == ON ){
         DIRR01___V =  DIR031SETV;               // выбранный шламобассейн
         DISR01P1_V =  DIS031___V;               // клапан ШБ закрыт
         DISR01PK_V =  DIS032___V;               // пн.клапан ШБ
         DISR01MS_V =  DIS030___V;               // мешалка ШБ
         DIHR01___V =  DIH030___V;               // верхний уровень ШБ
         DILR01___V =  DIL030___V;               // нижний  уровень ШБ
         DIRR01PN_V =  DIR010___V;               // ключ РА пн.насоса 
         DISR01PKSV =  DIS012___V;               // пн.клапан шлама   пн.насоса
         DISR01PKVV =  DIS011___V;               // пн.клапан воздуха пн.насоса
         DIHR01PN_V =  DIH010___V;               // уровень пн.насоса          

         DON031___V =  DONR01P1_V;               // клапан в  ШБ
         DON032___V =  DONR01PK_V;               // клапан из ШБ       
         DON012___V =  DONR01PKSV;               // клапан шлама   в пн.насос
         DON011___V =  DONR01PKVV;               // клапан воздуха в пн.насос
         // если ШБ2 на автомате- он работает параллельно ШБ3
         if(DIR041___V==ON){
            DON041___V =  DONR01P1_V;            //
            DON042___V =  DONR01PK_V;            //
         }
    }
    if ( DIR041SETV == ON ){
         DIRR01___V =  DIR041SETV;
         DISR01P1_V =  DIS041___V;
         DISR01PK_V =  DIS042___V;
         DISR01MS_V =  DIS040___V;
         DIHR01___V =  DIH040___V;
         DILR01___V =  DIL040___V;
         DIRR01PN_V =  DIR010___V;
         DISR01PKSV =  DIS012___V;
         DISR01PKVV =  DIS011___V;
         DIHR01PN_V =  DIH010___V;
         DON041___V =  DONR01P1_V;
         DON042___V =  DONR01PK_V;
         DON012___V =  DONR01PKSV;
         DON011___V =  DONR01PKVV;
         if(DIR031___V==ON){
            DON031___V =  DONR01P1_V;
            DON032___V =  DONR01PK_V;
         }
    }
    if ( DIR051SETV == ON ){
         DIRR01___V =  DIR051SETV;
         DISR01P1_V =  DIS051___V;
         DISR01PK_V =  DIS052___V;
         DISR01MS_V =  DIS050___V;
         DIHR01___V =  DIH050___V;
         DILR01___V =  DIL050___V;
         DIRR01PN_V =  DIR020___V;
         DISR01PKSV =  DIS022___V;
         DISR01PKVV =  DIS021___V;
         DIHR01PN_V =  DIH020___V;
         DON051___V =  DONR01P1_V;
         DON052___V =  DONR01PK_V;
         DON022___V =  DONR01PKSV;
         DON021___V =  DONR01PKVV;
    }
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Определить номер текущего Шламобассейна для подкачки шлама
vd  far DefineSLBAS(vd){
    if (STEP01==0 or STEP01>100 or DSB>0){
       //  если выбран ШБ3 и в нем нет сигнала нижн уровня и ключ на автомате
       if (DIR031SETM == ON and DIL030___V == OFF and DIR031___V == AUTO){ 
           DIR031NEXV =  ON;
           DIR031SETV =  ON;
           DIR031SETM =  OFF;
           DIR041SETV =  DIR041SETM = OFF;
           DIR051SETV =  DIR051SETM = OFF;
           DIR041NEXV =  DIR051NEXV = OFF;
       }
       //  если выбран ШБ2 и в нем нет сигнала нижн уровня и ключ на автомате
       if (DIR041SETM == ON and DIL040___V == OFF and DIR041___V == AUTO){ 
           DIR031SETV =  DIR031SETM = OFF;
           DIR041NEXV =  ON;
           DIR041SETV =  ON;
           DIR041SETM =  OFF;
           DIR051SETV =  DIR051SETM = OFF;
           DIR031NEXV =  DIR051NEXV = OFF;
       }
       //  если выбран ШБ1 и в нем нет сигнала нижн уровня и ключ на автомате
       if (DIR051SETM == ON and DIL050___V == OFF and DIR051___V == AUTO){ 
           DIR031SETV =  DIR031SETM = OFF;
           DIR041SETV =  DIR041SETM = OFF;
           DIR051NEXV =  ON;
           DIR051SETV =  ON;
           DIR051SETM =  OFF; 
           DIR031NEXV =  DIR041NEXV = OFF;
       };  DSB=0;
    }
    //  Выбор пневмонасоса для следующих подкачек шлама
    if (DIR031SETM == ON and DIL030___V == OFF and DIR031___V == AUTO){
        DIR031NEXV =  ON;    DIR041NEXV =  OFF;    DIR051NEXV =  OFF;
    }
    if (DIR041SETM == ON and DIL040___V == OFF and DIR041___V == AUTO){
        DIR031NEXV =  OFF;   DIR041NEXV =  ON;     DIR051NEXV =  OFF;
    }
    if (DIR051SETM == ON and DIL050___V == OFF and DIR051___V == AUTO){
        DIR031NEXV =  OFF;   DIR041NEXV =  OFF;    DIR051NEXV =  ON; 
    }
    DIR031SETM = DIR041SETM = DIR051SETM = OFF;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_01(vd){
    //  установки для работы регулятора, определяемые оператором:
    //  время загрузки пн.насоса шлама
    if (TIME_SLNZM <  0){ TIME_SLNZM = 2; }
    if (TIME_SLNZM != TIME_SLNZV){ TIME_SLNZV = TIME_SLNZM; }     // 2 MIN
    //  время выгрузки пн.насоса шлама
    if (TIME_SLNVM <  0){ TIME_SLNVM = 4; }
    if (TIME_SLNVM != TIME_SLNVV){ TIME_SLNVV = TIME_SLNVM; }     // 4 MIN
    //  количество загруженных пн.насосов шлама
    if (LOAD_SLCNM <  0){ LOAD_SLCNM = 2; }
    if (LOAD_SLCNM != LOAD_SLCNV){ LOAD_SLCNV = LOAD_SLCNM; }     // 2 NAS
    //  время ожидания выключения сигнала нижнего уровня мешалки шлама
    if (TIME_LLVSM <  0){ TIME_LLVSM = 7; }
    if (TIME_LLVSM != TIME_LLVSV){ TIME_LLVSV = TIME_LLVSM; }     // 7 MIN
    //  время ожидания включения сигнала верхнего уровня мешалки шлама
    if (TIME_HLVSW <  0){ TIME_HLVSW =30; }                       // 30 MIN
    //  время продувки пн.насоса шлама
    if (TIME_PRDSM <  0){ TIME_PRDSM = 5; }
    if (TIME_PRDSM != TIME_PRDSV){ TIME_PRDSV = TIME_PRDSM; }     // 5 MIN
    //  Время паузы между включениями исполнителей
    if (TIME_SLPKW <  0){ TIME_SLPKW = 5;  }                      // 5 SEC
    //  Счетчик количества дозировок шлама
    if (COUN_SLDZW <  0){ COUN_SLDZW = 4;  }                      // 4 DOZ
    //  Контроль нижнего уровня мешалки шлама
    if (CTRL_LLMSM <  0){ CTRL_LLMSV = ON; CTRL_LLMSM = OFF; }    // ON
    if (CTRL_LLMSM == SWITCH){ 
        CTRL_LLMSV = (CTRL_LLMSV!=ON) then_ ON else_ OFF; CTRL_LLMSM=OFF;
    }
    //  Контроль верхнего уровня мешалки шлама
    if (CTRL_HLMSM <  0){ CTRL_HLMSV = ON; CTRL_HLMSM = OFF; }    // ON
    if (CTRL_HLMSM == SWITCH){ 
        CTRL_HLMSV = (CTRL_HLMSV!=ON) then_ ON else_ OFF; CTRL_HLMSM=OFF;
    }
    //  Контроль уровня пн насоса мешалки шлама
    if (CTRL_LPSLM <  0){ CTRL_LPSLV = ON; CTRL_LPSLM = OFF; }    // ON
    if (CTRL_LPSLM == SWITCH){ 
        CTRL_LPSLV = (CTRL_LPSLV!=ON) then_ ON else_ OFF; CTRL_LPSLM=OFF;
    }

    //  определить соответствие клапанов для шламобассейна
    DefineSLBAS();
    //  включение-выключение регулятора
    if ( REG01RS__M == SWITCH ){ 
         REG01R___M = (REG01R___M==ON) then_ OFF else_ ON; REG01RS__M=OFF;
    }
    if ( REG01R___M != REG01R___V ){ 
         REG01R___M  =(REG01R___M==ON) then_ ON else_ OFF;
         REG01R___V  = REG01R___M;
         if(REG01R___V>0){ Message(320); STEP01 =   0; }          // автомат
         else            { Message(321); STEP01 = 101; }          // ручное
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //  если регулятор выключен и текущий шаг не продувка- выйти
    //  для выполнения продувки разрешен переход на ШАГ 15..25
    if (REG01R___V == OFF and (STEP01<15 or STEP01>25)){ 
        Regul_01m(); return; 
    }
    //  если пн.насосы шлама в ручном режиме - выйти
    if (DIR010___V == MANUAL and DIR020___V == MANUAL){ 
        REG01SW__V = 106;
        Regul_01m(); return; 
    }
    //  если все шламобассейны в ручном режиме - выйти
    if (DIR031___V == MANUAL and DIR041___V == MANUAL and DIR051___V== MANUAL){
        REG01SW__V = 107;
        Regul_01m(); return; 
    }
    //-----------------------------------------------------------------------

    //  определить соответствие каналов входов-выходов для выбранного Шлам.Бас.
    RegNSET();

    //-----------------------------------------------------------------------
    // Контроль количества дозировок шлама
    if (RegRUN==ON){
        // если вес больше 700 кг и флаг счетчика=0 увеличить счетчик загрузки
        if(AIW230___V>700 and FLAG_SLDZC==0)  { FLAG_SLDZZ++; }
        else                                  { FLAG_SLDZZ=0; }
        // если вес меньше 50  кг и флаг счетчика=1 увеличить счетчик выгрузки
        if(AIW230___V<50  and FLAG_SLDZC==1)  { FLAG_SLDZV++; }
        else                                  { FLAG_SLDZV=0; }
        //---------
        // если вес удерживается более 7 сек - считаем, что дозатор загружен
        if(AIW230___V>700 and FLAG_SLDZC==0 and FLAG_SLDZZ== 7 ){
           FLAG_SLDZC=1;
        }
        // если вес удерживается более 7 сек - считаем, что дозатор выгружен
        // (прошла одна дозировка мокрого)
        if(AIW230___V<50  and FLAG_SLDZC==1 and FLAG_SLDZV== 7 ){
           FLAG_SLDZC=0;  COUN_SLDZC++;
        }
        //---------
        if(FLAG_SLDZZ>100){ FLAG_SLDZZ=100; }
        if(FLAG_SLDZV>100){ FLAG_SLDZV=100; }
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА УСЛОВИЙ включения регулятора
    //-----------------------------------------------------------------------
    if ( STEP01 ==0 ){
         if(STEP01P!=0){
            ;;
         }; STEP01P =0;
         if(RegRUN==OFF){ return; }

         Regul_01off();
         //  переопределение выбранного для подкачки шламобассейна
         if(DIR031NEXV==ON){ DIR031SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR041NEXV==ON){ DIR041SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR051NEXV==ON){ DIR051SETM=ON; DSB=1; DefineSLBAS(); }
         //  если есть сигнал ниж уровня в шламобассейне- выйти из регулятора
         REG01SW__V = 0;
         switch ( Check_TO (11,4*SEC, DILR01___V,'=',OFF, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(11); return;; }
         }
         //  если есть сигнал верх уровня мешалки шлама- выйти из регулятора
         if(CTRL_HLMSV==ON){
            REG01SW__V = 1;
            switch ( Check_TO (12,4*SEC, DIH220___V,'=',OFF, 2)){
                case RUN: { return;; }
                case BAD: { Clear_TO(12); return;; }
            }
         }
         //  если нет сигнала нижнего уровня мешалки шлама- выйти из регулятора
         if(CTRL_LLMSV==ON){
            REG01SW__V = 2;
            switch ( Check_TO (13,4*SEC, DIL220___V,'=',ON, 2)){
                case RUN: { return;; }
                case BAD: { Clear_TO(13); return;; }
            }
         }
         //  если есть уровень в пн насосе шлама- выйти из регулятора
         REG01SW__V = 3;
         if(CTRL_LPSLV==ON){
            if(DIHR01PN_V==ON){ return; }
         }
         //  если мешалка шламобассейна выключена- выйти из регулятора
         REG01SW__V = 4;
         switch ( Check_TO (14,4*SEC, DISR01MS_V,'=',ON, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(14); return;; }
         }
         //  если мешалка шлама выключена- выйти из регулятора
         REG01SW__V = 5;
         switch ( Check_TO (15,4*SEC, DIS220___V,'=',ON, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(15); return;; }
         }
         //  проверка начального состояния всех исполнителей регулятора
         REG01SW__V = 6;
         if((DIR031___V==AUTO and (DIS031___V==ON or DIS032___V==ON)) or
            (DIR041___V==AUTO and (DIS041___V==ON or DIS042___V==ON)) or
            (DIR051___V==AUTO and (DIS051___V==ON or DIS052___V==ON)) or
            (DIR010___V==AUTO and (DIS011___V==ON or DIS012___V==ON)) or
            (DIR020___V==AUTO and (DIS021___V==ON or DIS022___V==ON)) ){
             switch ( Check_TO (16,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(261); Bell(1); Clear_TO(16); return;; }
             }
         };  Clear_TO(16);
         //  если количество дозировок шлама меньше заданного- выйти
         REG01SW__V = 7;
         if (COUN_SLDZC<COUN_SLDZW){ return; }
         //  если мешалка шлама на РУКЕ- запрос оператору
         REG01SW__V = 8;
         if(REG01ZO1_W==END){ REG01ZO1_W=OFF; Clear_TO(17); }
         if(DIR220___V==OFF){
            switch ( Check_TO (17,60*SEC, REG01ZO1_W,'=', YES, 2)){
                case RUN: { return;; }
                case BAD: { 
                            REG01ZO1_W=REQ; Message(280); Bell(1); Clear_TO(17);
                            return;; 
                          }
            }
         }
         //  обнулить таймеры и счетчики
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         Clear_TO(15);
         Clear_TO(16);
         Clear_TO(17);
         REG01ZO1_W    = OFF;
         TIME_LLVSCMin = 0;                      // нижний уровень
         TIME_LLVSC    = 0;
         TIME_HLVSCMin = 0;                      // верхний уровень
         TIME_HLVSC    = 0;
         TIME_SLNZCMin = 0;                      // загрузка ПН
         TIME_SLNZC    = 0;
         TIME_SLNVCMin = 0;                      // выгрузка ПН
         TIME_SLNVC    = 0;
         TIME_PRDSCMin = 0;                      // продувка
         TIME_PRDSC    = 0;
         STEP01 = 10;
         return;
    }
    //-----------------------------------------------------------------------


    // УСТАНОВКА НАЧАЛЬНОГО СОСТОЯНИЯ исполнителей регулятора
    //-----------------------------------------------------------------------
    if ( STEP01 ==10 ){
         if(STEP01P!=10){
            ;;
         }; STEP01P =10;
         REG01SW__V = 6;
         //  начальное состояние всех исполнителей и таймеров
         Regul_01off();
         //  переопределение выбранного для подкачки шламобассейна
         if(DIR031NEXV==ON){ DIR031SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR041NEXV==ON){ DIR041SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR051NEXV==ON){ DIR051SETM=ON; DSB=1; DefineSLBAS(); }
         //  сбросить счетчики и таймеры
         LOAD_SLCNC = 0;
         FLAG_HLVSExit = OFF;
         STEP01 =  1;
         return;
    }
    //-----------------------------------------------------------------------


    // ЗАГРУЗКА ШЛАМА в пн.насос
    //-----------------------------------------------------------------------
    if ( STEP01 ==1 ){
         if(STEP01P!=1){
            ;;
         }; STEP01P =1;
         if(RegRUN==OFF){ return; }

         //  открыть клапан набора шлама в пн.насос
         REG01SW__V = 10;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=ON;   DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  1, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11); 
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  открыть клапан подачи шлама из шламобассейна
         REG01SW__V = 11;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;   DONR01PK_V=OFF;  DONR01PKSV=ON;   DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01P1_V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01P1_V,3,TIME_ISPPW,70,  1, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         switch ( Check_TO  (14, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         REG01SW__V = 12;
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==2 ){
         if(STEP01P!=2){
            ;;
         }; STEP01P =2;
         if(RegRUN==OFF){ return; }

         //  открыть клапан шлама в пн.насос
         REG01SW__V = 20;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  2, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  открыть клапан в шламобассейне
         REG01SW__V = 21;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=ON;;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01PK_V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70,  2, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         REG01SW__V = 21;
         STEP01 = 3;
         return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА УРОВНЯ пн.насоса
    //-----------------------------------------------------------------------
    if ( STEP01 ==3 ){
         if(STEP01P!=3){
            TIME_SLNZCMin=0;
            TIME_SLNZC   =0;
         }; STEP01P =3;
         if (RegRUN==OFF){ return; }

         REG01SW__V = 30;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=ON;;  DONR01PKSV=ON;;  DONR01PKVV=OFF;
         // если выключен контроль уровня пневмонасоса- исключить сигнал уровня
         if(CTRL_LPSLV==OFF){ DIHR01PN_V=OFF; }
         // ждать сигнал уровня пн.насоса, считать время набора пн.насоса шлама
         switch ( Check_TO  (11, TIME_SLNZV*MIN, DIHR01PN_V,'=',ON, TIME_LSTBV )){
            case RUN:{ TIME_SLNZCMin++; TIME_SLNZC=TIME_SLNZCMin/MIN; return;; }
            case BAD:{ 
                        if(TIME_SLNZ1==ON){ Bell(1); }
                        if(TIME_SLNZ3==ON){ Message(210); }  // по времени
                        break;;
                     }
            case END:{ 
                        if(TIME_SLNZ1==ON){ Bell(1); }
                        if(TIME_SLNZ3==ON){ Message(211); }  // по уровню
                        break;;
                     }
         }
         Clear_TO(11);

         REG01SW__V = 31;
         STEP01_BACK= 0;
         STEP01 = 4;
         return;
    }
    //-----------------------------------------------------------------------


    // ВЫКЛЮЧИТЬ ЗАГРУЗКУ пн.насоса
    //-----------------------------------------------------------------------
    if ( STEP01 ==4 ){
         if(STEP01P!=4){
            ;;
         }; STEP01P =4;
         if (RegRUN==OFF){ return; }

         //  закрыть клапан в шламобассейне
         REG01SW__V = 40;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PK_V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70,  4, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  закрыть клапан подачи шлама в пн.насос
         REG01SW__V = 41;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01PKSV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  4, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         switch ( Check_TO  (14, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         REG01SW__V = 41;
         STEP01 = 5;
         return;
    }
    //-----------------------------------------------------------------------


    // ВКЛЮЧИТЬ ВЫГРУЗКУ пн.насоса (вкл подачу воздуха в пн.насос)
    //-----------------------------------------------------------------------
    if ( STEP01 ==5 ){
         if(STEP01P!=5){
            ;;
         }; STEP01P =5;
         if (RegRUN==OFF){ return; }

         //  открыть пн.клапан подачи воздуха в пн.насос
         REG01SW__V = 50;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70,  5, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         REG01SW__V   = 51;
         STEP01 = 6;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==6 ){
         if(STEP01P!=6){
            TIME_SLNVCMin= 0;
            TIME_SLNVC   = 0;
         }; STEP01P =6;
         if (RegRUN==OFF){ return; }

         //  считать время выгрузки из пн.насоса шлама
         REG01SW__V = 60;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_SLNVV*MIN, ZERO,'=',ON,  1 )){
            case RUN:{ 
                        TIME_SLNVCMin++; TIME_SLNVC=TIME_SLNVCMin/MIN; break;; 
                     }
            case BAD:{ 
                        if(TIME_SLNV1==ON){ Bell(1); }
                        if(TIME_SLNV3==ON){ Message(212); }
                        Clear_TO(11);
                        Clear_TO(12);
                        Clear_TO(14);
                        if(STEP01_BACK==101){ STEP01=101; }
                        else                { STEP01=7;   }
                        return;;
                     }
         }

         //------------------------------------------------------------------
         // счетчик ожидания выключен сигнала нижнего уровня мешалки шлама:
         switch ( Check_TO (18, TIME_LLVSV*MIN,DIL220___V,'=',OFF,TIME_LSTBV )){
             case RUN:{ 
                         if(CTRL_LLBCV==ON and DIL220___V==ON){
                            TIME_LLVSCMin++; TIME_LLVSC=TIME_LLVSCMin/MIN; 
                         }
                         break;; 
                      }
             // если за заданное время сигнал нижнего уровня мешалки шлама
             // остался сработанным
             case BAD:{ 
                         if(TIME_LLVS1==ON){ Bell(1); }
                         if(TIME_LLVS3==ON){ Message(328); }
                         Clear_TO(18);
                         break;;  
                      }
             // за заданное время сигнал нижнего уровня мешалки шлама пропал
             case END:{ 
                         Clear_TO(18);
                         break;;
                      }
         }

         //------------------------------------------------------------------
         // счетчик ожидания включен сигнала верхнего уровня мешалки шлама:
         if(CTRL_HLMSV==OFF){ DIH220___C=OFF; }
         else               { DIH220___C=DIH220___V; }
         switch ( Check_TO (17, TIME_HLVSW*MIN,DIH220___C,'=',ON, TIME_LSTBV)){
             case RUN:{ 
                         if(CTRL_HLMSV==ON and DIH220___C==OFF){
                            TIME_HLVSCMin++; TIME_HLVSC=TIME_HLVSCMin/MIN;
                         }
                         break;; 
                      }
             // если за заданное время нет сигнала верхн уровня мешалки шлама
             case BAD:{ 
                         Bell(1); Message(252);
                         FLAG_HLVSExit=ON;
                         Clear_TO(17);
                         break;;  
                      }
             // за заданное время включ сигнал верхнего уровня мешалки шлама
             case END:{ 
                         // если выкл контр верх уровня- считать время
                         if(CTRL_HLMSV==OFF){
                            if(TIME_HLVSCMin>TIME_HLVSW){ FLAG_HLVSExit=ON; }
                            TIME_HLVSCMin++; TIME_HLVSC=TIME_HLVSCMin/MIN;
                         }
                         Clear_TO(17);
                         break;;
                      }
         }
         //------------------------------------------------------------------
         return;
    }
    //-----------------------------------------------------------------------


    // ВЫКЛЮЧИТЬ ВЫГРУЗКУ пн.насоса (выкл подачу воздуха в пн.насос)
    //-----------------------------------------------------------------------
    if ( STEP01 ==7 ){
         if(STEP01P!=7){
            ;;
         }; STEP01P =7;
         if (RegRUN==OFF){ return; }

         //  закрыть пн.клапан подачи воздуха в пн.насос
         REG01SW__V = 70;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70,  7, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(11);
         Clear_TO(12);
         REG01SW__V = 71;
         STEP01 = 8;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==8 ){
         if(STEP01P!=8){
            ;;
         }; STEP01P =8;
         REG01SW__V = 80;

         //  увеличить счетчик загруженных насосов
         LOAD_SLCNC++;
         //  если текущий счетчик загруженных насосов > или = заданному-
         //  перейти на ШАГ 15 (закрыть исполнители регулятора и на ШАГ0)
         if (LOAD_SLCNC >= LOAD_SLCNV){ 
             STEP01=15; 
             COUN_SLDZC =0;
             Message(253);
             STEP01_BACK=0; 
             return; 
         }
         //  если есть сигнал верхнего уровня в мешалке шлама- 
         //  перейти на ШАГ 15
         if (DIH220___V == ON && CTRL_HLMSV == ON){ 
             STEP01=15; 
             COUN_SLDZC   =0;
             Message(254);
             STEP01_BACK  =0;
             return; 
         }
         //  если мешалка шлама выключена- перейти на ШАГ 15
         if (DISR01MS_V == OFF){ 
             STEP01=15; 
             Message(255);
             STEP01_BACK=0;
             return; 
         }
         //  если вышло время набора верхнего уровня мешалки шлама-
         //  выключить регулятор
         if (FLAG_HLVSExit == ON){
             STEP01=15; 
             Message(256); Bell(1);
             COUN_SLDZC   =0;
             STEP01_BACK  =0;
             return; 
         }
         //  перейти на повторную загрузку
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------




    //-----------------------------------------------------------------------
    // ПРОДУВКА
    //-----------------------------------------------------------------------
    if ( STEP01 ==15 ){
         if(STEP01P!=15){
            ;;
         }; STEP01P =15;
         if(RegRUN==OFF){ return; }

         // закрыть клапан в шламобассейне и открыть клапан в пн.насосе
         REG01SW__V = 150;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PK_V,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70, 15, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);

         REG01SW__V = 151;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISR01PKSV,'=',ON, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70, 15, 12); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(12);
         switch ( Check_TO  (13, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(13);
         STEP01 = 16;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==16 ){
         if(STEP01P!=16){
            ;;
         }; STEP01P =16;
         if(RegRUN==OFF){ return; }

         // закрыть клапан из шламобассейна
         REG01SW__V = 160;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01P1_V,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01P1_V,3,TIME_ISPPW,70, 16, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 17;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==17 ){
         if(STEP01P!=17){
            ;;
         }; STEP01P =17;
         if(RegRUN==OFF){ return; }

         // закрыть клапан шлама в пн.насос
         REG01SW__V = 170;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70, 17, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*3*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 21;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==21 ){
         if(STEP01P!=21){
            ;;
         }; STEP01P =21;
         if (RegRUN==OFF){ return; }

         //  открыть клапан подачи воздуха в пн.насос для продувки
         REG01SW__V = 210;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70, 21, 11); return;; 
                       }
         };  Clear_TO(11); DONCN01=0;
         REG01SW__V = 211;
         STEP01 = 22;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==22 ){
         if(STEP01P!=22){
            TIME_PRDSC = 0;
            TIME_PRDSCMin = 0;
         }; STEP01P =22;
         if (RegRUN==OFF){ return; }

         //  считать время подачи воздуха в пн.насос шлама (продувка)
         REG01SW__V = 220;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_SLNVV*MIN, ZERO,'=',ON,  1 )){
            case RUN:{ TIME_PRDSCMin++; TIME_PRDSC=TIME_PRDSCMin/MIN; return; }
            case BAD:{ 
                        if(TIME_PRDS1==ON){ Bell(1); }
                        if(TIME_PRDS3==ON){ Message(212); }
                        break;;
                     }
         }
         Clear_TO(11);

         REG01SW__V = 221;
         STEP01 = 23;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==23 ){
         if(STEP01P!=23){
            ;;
         }; STEP01P =23;
         if (RegRUN==OFF){ return; }

         //  закрыть пн.клапан подачи воздуха в пн.насос
         REG01SW__V = 230;
         // изШБ          в_ШБ             ш_ПН             в_ПН
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF;;

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70, 23, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         REG01SW__V = 231;
         STEP01 = 25;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==25 ){
         if(STEP01P!=25){
            ;;
         }; STEP01P =25;
         //  дать повторную комманду на закрытие всех исполнителей регулятора
         Regul_01off();
         STEP01 = STEP01_BACK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
    //-----------------------------------------------------------------------
    if ( STEP01 ==70 ){
         if(STEP01P!=70){
            ;;
         }; STEP01P =70;
         if(DONCN01>=DONCH01){ STEP01 = STEP01_PRBK; return; }
         REG01SW__V = 700;
         if(RegRUN==OFF){ return; }
         if(Check_TO(201, DONTM01*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(201);
        *DONPR01=(*DONPR01!=ON)?ON:OFF;
         DONCN01++;
         STEP01 = STEP01_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // если задан несуществующий шаг регулятора - регулятор в ручной режим
    Regul_01m();
    return;
}
//---------------------------------------------------------------------------
