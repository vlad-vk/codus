//---------------------------------------------------------------------------
// Подкачка отходов

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR03;                 // текущий сигнал (комманда) выхода на исполн
_i far  DONCN03=0;               // счетчик цикла передергивания              
_i far  DONCH03=2;               // заданное кол-во циклов для передергивания 
_i far  DONTM03=2;               // кол-во секунд вкл и паузы

//---------------------------------------------------------------------------
//  Определения для передергивание исполнителей регулятора при несработке
vd  Isp03PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR03= IOPNT;
    DONCH03= hM;
    DONTM03= hS;
    STEP03 = Step; 
    STEP03_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_03off(vd){
    DON071___V =  OFF;
    DON081___V =  OFF;
    DON082___V =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выполнение действий при выключеном регуляторе
vd  far Regul_03m(vd){
    //-----------------------------------------------------------------------
    if ( STEP03 == 101 ){
         REG03SW__V = 1001;
         // если выключили регулятор где-то посередине и ключ на автомате- 
         // сделать выгрузку, продувку и вернуться на этот же шаг
         if(STEP03P>1 and STEP03P<6 and DIR070___V==AUTO){ 
            STEP03=4; STEP03_BACK=101;  REG03R___V =REG03R___M=ON; return;
         }
         if(STEP03P==6 and DIR070___V==AUTO){ 
            STEP03=8; STEP03_BACK=101; REG03R___M=OFF; return; 
         }
         // дать повторную комманду на закрытие исполнителей регулятора
         Regul_03off();
         // обнулить флаги
         LOAD_NS08C    = 0;
         COUN_OTDZC=COUN_OTDZW;
         // обнулить таймеры
         Clear_TO(31);
         Clear_TO(32);
         Clear_TO(33);
         Clear_TO(34);
         Clear_TO(35);
         Clear_TO(36);
         Clear_TO(37);
         Clear_TO(38);
         // следующий шаг ручного режима
         STEP03 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 == 102 ){
         STEP03P = 102;
         REG03SW__V = 1002;
         REG03R___M = OFF;
         STEP03_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP03=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_03(vd){
    // установки для работы регулятора, определяемые оператором:
    // время подачи воды в мешалку отходов РК
    if (TIME_OTHVM <  0){ TIME_OTHVM =  2; }
    if (TIME_OTHVM != TIME_OTHVV){ TIME_OTHVV = TIME_OTHVM; }    // 2 MIN
    // время загрузки пн.насоса отходов, если нет сигнала уровня
    if (TIME_NS31M <  0){ TIME_NS31M =  2; }
    if (TIME_NS31M != TIME_NS31V){ TIME_NS31V = TIME_NS31M; }    // 2 MIN
    // время выгрузки пн.насоса отходов
    if (TIME_NS32M <  0){ TIME_NS32M =  3; }
    if (TIME_NS32M != TIME_NS32V){ TIME_NS32V = TIME_NS32M; }    // 3 MIN
    // количество пн.насосов загружаемых в мешалку отходов
    if (LOAD_NS08M <  0){ LOAD_NS08M =  2; }
    if (LOAD_NS08M != LOAD_NS08V){ LOAD_NS08V = LOAD_NS08M; }    // 2 NAS
    // время продувки пн.насосов отходов
    if (TIME_PRDOM <  0){ TIME_PRDOM =  2; }
    if (TIME_PRDOM != TIME_PRDOV){ TIME_PRDOV = TIME_PRDOM; }    // 2 MIN
    // время ожидания выключения сигнала нижнего уровня мешалки отходов
    if (TIME_LLVOM <  0){ TIME_LLVOM =  4; }
    if (TIME_LLVOM != TIME_LLVOV){ TIME_LLVOV = TIME_LLVOM; }    // 4 MIN
    // время ожидания набора верхнего уровня мешалки отходов
    if (TIME_HLVOW <  0){ TIME_HLVOW = 10; }                     // 10 MIN
    // Время паузы между включениями исполнителей
    if (TIME_OTPKW <  0){ TIME_OTPKW = 5;  }                     // 5 SEC
    // Счетчик количества дозировок 
    if (COUN_OTDZW <  0){ COUN_OTDZW = 4;  }                     // 4 DOZ
    //  Контроль нижнего уровня мешалки отходов
    if (CTRL_LLMOM <  0){ CTRL_LLMOV = ON; CTRL_LLMOM = OFF; }   // ON
    if (CTRL_LLMOM == SWITCH){ 
        CTRL_LLMOV = (CTRL_LLMOV!=ON) then_ ON else_ OFF; CTRL_LLMOM=OFF;
    }
    //  Контроль верхнего уровня мешалки отходов
    if (CTRL_HLMOM <  0){ CTRL_HLMOV = ON; CTRL_HLMOM = OFF; }    // ON
    if (CTRL_HLMOM == SWITCH){ 
        CTRL_HLMOV = (CTRL_HLMOV!=ON) then_ ON else_ OFF; CTRL_HLMOM=OFF;
    }
    //  Контроль уровня пн насоса отходов
    if (CTRL_LPOTM <  0){ CTRL_LPOTV = ON; CTRL_LPOTM = OFF; }    // ON
    if (CTRL_LPOTM == SWITCH){ 
        CTRL_LPOTV = (CTRL_LPOTV!=ON) then_ ON else_ OFF; CTRL_LPOTM=OFF;
    }

    // включение-выключение регулятора
    if ( REG03RS__M == SWITCH ){ 
         REG03R___M = (REG03R___M==ON) then_ OFF else_ ON; REG03RS__M=OFF;
    }
    if ( REG03R___M != REG03R___V ){ 
         REG03R___M  =(REG03R___M==ON) then_ ON else_ OFF;
         REG03R___V  = REG03R___M;
         if ( REG03R___V == ON ){ Message(340); STEP03 =   0; }
         else                   { Message(341); STEP03 = 101; }
    }
    // если мешалка РК на ручном режиме или регулятор выключен 
    // и шаг регулятора не продувка- выйти
    if(( DIR070___V == MANUAL or REG03R___V == OFF) and 
       ( STEP03<8   or STEP03>10 ) ){ 
         Regul_03m(); return; 
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Контроль количества дозировок отходов
    if (RegRUN==ON){
        // если вес больше 200 кг и флаг счетчика=0 увеличить счетчик загрузки
        if(AIW230___V>200 and FLAG_OTDZC==0)  { FLAG_OTDZZ++; }
        else                                  { FLAG_OTDZZ=0; }
        // если вес меньше 50  кг и флаг счетчика=1 увеличить счетчик выгрузки
        if(AIW230___V<50  and FLAG_OTDZC==1)  { FLAG_OTDZV++; }
        else                                  { FLAG_OTDZV=0; }
        //---------
        // если вес удерживается более 7 сек - считаем, что дозатор загружен
        if(AIW230___V>200 and FLAG_OTDZC==0 and FLAG_OTDZZ== 7 ){
           FLAG_OTDZC=1;
        }
        // если вес удерживается более 7 сек - считаем, что дозатор выгружен
        // (прошла одна дозировка мокрого)
        if(AIW230___V<50  and FLAG_OTDZC==1 and FLAG_OTDZV== 7 ){
           FLAG_OTDZC=0;  COUN_OTDZC++;
        }
        //---------
        if(FLAG_OTDZZ>100){ FLAG_OTDZZ=100; }
        if(FLAG_OTDZV>100){ FLAG_OTDZV=100; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    if ( STEP03 ==0 ){
         if(STEP03P!=0){
         }; STEP03P =0;
         if(RegRUN==OFF){ return; }

         Regul_03off();
         // если есть сигнал верхнего уровня в мешалке отходов - выйти
         REG03SW__V = 0;
         if (CTRL_HLMOV == ON and DIH210___V == ON){ return; }
         // если нет сигнала нижнего уровня мешалки отходов - выйти
         REG03SW__V = 1;
         if (CTRL_LLMOV == ON and DIL210___V == OFF){ return; }
         // если мешалка отходов не включена - дозировку не начинать
         REG03SW__V = 2;
         if (DIS210___V == OFF){ return; }
         // если мешалка отходов РК не включена - дозировку не начинать
         REG03SW__V = 3;
         if (DIS070___V == OFF){ return; }
         // если есть уровень в пневмонасосе отходов - выйти
         REG03SW__V = 4;
         if (CTRL_LPOTV == ON and DIH080___V == ON ){ return; }
         //  проверка начального состояния всех исполнителей регулятора
         REG03SW__V = 5;
         if (DIR070___V==AUTO and 
            (DIS071___V==ON or DIS081___V==ON or DIS082___V==ON)){
             switch ( Check_TO (31,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(263); Bell(1); Clear_TO(31); return;; }
             }
         };  Clear_TO(31);
         //  если количество дозировок отходов меньше заданного- выйти
         REG03SW__V = 6;
         if (COUN_OTDZC<COUN_OTDZW){ return; }
         //  если мешалка отходов на РУКЕ- запрос оператору
         REG03SW__V = 7;
         if(REG03ZO1_W==END){ REG03ZO1_W=OFF; Clear_TO(32); }
         if(DIR210___V==OFF){
            switch ( Check_TO (32,60*SEC, REG03ZO1_W,'=', YES, 2)){
                case RUN: { return;; }
                case BAD: { 
                            REG03ZO1_W=REQ; Message(281); Bell(1); Clear_TO(32);
                            return;; 
                          }
            }
         }
         // сбросить таймеры
         Clear_TO(31);
         Clear_TO(32);
         // обнулить счетчики
         REG03ZO1_W = OFF;
         LOAD_NS08C = 0;
         TIME_OTHVCMin=0;
         TIME_OTHVC   =0;
         TIME_NS31CMin=0;
         TIME_NS31C   =0;
         TIME_NS32CMin=0;
         TIME_NS32C   =0;
         TIME_PRDOCMin=0;
         TIME_PRDOC   =0;
         TIME_LLVOCMin=0;
         TIME_LLVOC   =0;
         TIME_HLVOCMin=0;
         TIME_HLVOC   =0;
         FLAG_HLMOExit=OFF;
         STEP03=1;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==1 ){
         if(STEP03P!=1){
            Regul_03off();
            TIME_OTHVCMin=0;
            TIME_OTHVC   =0;
         }; STEP03P =1;
         if (RegRUN==OFF){ return; }

         // Открыть клапан подачи воды в Мешалку отходов РК и подождать
         // заданное время для набора воды
         // вода           отходы             воздух
         DON071___V = ON;  DON081___V = OFF;  DON082___V = OFF;
         REG03SW__V = 10;
         switch ( Check_TO  (31, TIME_OTHVV*MIN, ZERO,'=',ON,  1 )){
            case RUN:{ TIME_OTHVCMin++; TIME_OTHVC=TIME_OTHVCMin/MIN; return;; }
            case BAD:{ 
                        if(TIME_OTHV1==ON){ Bell(1); }
                        if(TIME_OTHV3==ON){ Message(231); }
                        break;;  
                     }
         }
         Clear_TO(31);
         REG03SW__V = 11;
         // После заданного времени дать комманду на закрытие клапан подач воды
         DON071___V = OFF;
         STEP03 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==2 ){
         if(STEP03P!=2){
            Regul_03off();
         }; STEP03P =2;
         if (RegRUN==OFF){ return; }

         // Открыть клапан подачи отходов в пневмонасос
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = ON;;  DON082___V = OFF;
         REG03SW__V = 20;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS081___V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>2){ 
                            Message(271); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON081___V,3,TIME_ISPPW,70, 2, 31); return;; 
                       }
             case END: { DONCN03=0; break;; }
         }
         switch ( Check_TO  (34, TIME_OTPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(31);
         Clear_TO(34);
         REG03SW__V = 21;
         STEP03 = 3; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==3 ){
         if(STEP03P!=3){
            TIME_NS31CMin=0;
            TIME_NS31C   =0; 
         }; STEP03P =3;
            STEP03_BACK=0;
         if (RegRUN==OFF){ return; }

         // Ждать сработки уровня пневмонасоса
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = ON;;  DON082___V = OFF;
         REG03SW__V = 30;

         switch ( Check_TO  (31, TIME_NS31V*MIN, DIH080___V,'=',ON, TIME_LSTBV )){
            case RUN:{ 
                        TIME_NS31CMin++; TIME_NS31C=TIME_NS31CMin/MIN; return; 
                     }
            // загрузка пневмонасоса закончена по вреени
            case BAD:{ 
                        if(TIME_NS311==ON){ Bell(1); }
                        if(TIME_NS313==ON){ Message(207); }
                        break;;  
                     }
            // загрузка пневмонасоса закончена по уровню пн.насоса
            case END:{ 
                        // если контрол уровня пн насос выкл- считать время...
                        if(CTRL_LPOTV==OFF){
                           if(TIME_NS31CMin>TIME_NS31V){ break; }
                           TIME_NS31CMin++; TIME_NS31C=TIME_NS31CMin/MIN; return; 
                        }
                        if(TIME_NS311==ON ){ Bell(1); }
                        if(TIME_NS313==ON ){ Message(208); }
                        break;;
                     }
         }
         Clear_TO(31);
         REG03SW__V = 31;
         STEP03 = 4;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==4 ){
         if(STEP03P!=4){
            ;;
         }; STEP03P =4;
         if (RegRUN==OFF){ return; }

         // Закрыть клапан подачи отходов в пневмонасос (ждать полного закр)
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = OFF;
         REG03SW__V = 40;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS081___V,'=',OFF, 1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>1){ 
                            Message(272); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON081___V,3,TIME_ISPPW,70, 4, 31); return;; 
                       }
             case END: { DONCN03=0; break;; }
         }
         switch ( Check_TO  (34, TIME_OTPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(31);
         Clear_TO(34);
         REG03SW__V = 41;
         STEP03 = 5;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==5 ){
         if(STEP03P!=5){
            ;;
         }; STEP03P =5;
         if (RegRUN==OFF){ return; }

         // Открыть клапан подачи воздуха в пневмонасос
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = ON;;
         REG03SW__V = 50;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS082___V,'=',ON, 1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>1){ 
                            Message(273); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON082___V,3,TIME_ISPPW,70, 5, 31); return;; 
                       }
             case END: { DONCN03=0; break;; }
         };  
         Clear_TO(31); 
         DONCN03=0;
         REG03SW__V=51;
         STEP03 = 6; 
         return;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    if ( STEP03 ==6 ){
         if(STEP03P!=6){
            TIME_NS32CMin= 0;
            TIME_NS32C   = 0;
         }; STEP03P =6;
         if (RegRUN==OFF){ return; }

         //-------------------------------------------------------------------
         // счетчик ожидания выключения сигнала нижнего уровня мешалки отходов:
         switch ( Check_TO  (38, TIME_LLVOV*MIN, DIL210___V,'=',OFF, TIME_LSTBV )){
             case RUN:{ 
                         TIME_LLVOCMin++; TIME_LLVOC=TIME_LLVOCMin/MIN; break;; 
                      }
             // если за заданное время сигнал нижнего уровня мешалки отходов
             // остался сработанным
             case BAD:{ 
                         Bell(1); Message(348); Clear_TO(38);
                         break;;  
                      }
             // за заданное время сигнал нижнего уровня мешалки отходов пропал
             case END:{ 
                         // если выкл контр ниж ур меш отходов- считать время
                         if(CTRL_LLMOV==OFF){
                            TIME_LLVOCMin++; TIME_LLVOC=TIME_LLVOCMin/MIN;
                         } else {
                            Clear_TO(38);
                         }
                         break;;
                      }
         }
         //-------------------------------------------------------------------
         // счетчик ожидания сигнала верхнего уровня мешалки отходов:
         switch ( Check_TO  (37, TIME_HLVOW*MIN, DIH210___V,'=',OFF, TIME_LSTBV )){
             case RUN:{ 
                        TIME_HLVOCMin++; TIME_HLVOC=TIME_HLVOCMin/MIN; break;;
                      }
             // если за заданное время сигнал верхнего уровня мешалки отходов
             // остался не сработанным- сообщение,звонок и выкл.регулятор
             case BAD:{ 
                         Message(251); Bell(1); Clear_TO(37);
                         FLAG_HLMOExit=ON;
                         break;;
                      }
             // за заданное время сигнал верхнего уровня мешалки отходов 
             // сработал
             case END:{ 
                         // если выкл контр вер ур меш отходов- считать время
                         if(CTRL_HLMOV==OFF){
                            TIME_HLVOCMin++; TIME_HLVOC=TIME_HLVOCMin/MIN;
                         }
                         break;;
                      }
         }
         Clear_TO(37);
         //-------------------------------------------------------------------

         // Ожидать время выгрузки пневмонасоса отходов
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = ON;;
         REG03SW__V = 60;
         if(CTRL_HLMOV==OFF or (CTRL_HLMOV==ON and DIH210___V==OFF)){
            switch ( Check_TO  (31, TIME_NS32V*MIN, ZERO,'=',ON, 1 )){
               case RUN:{ 
                           TIME_NS32CMin++; TIME_NS32C=TIME_NS32CMin/MIN; 
                           return;; 
                        }
               case BAD:{ 
                           if(TIME_NS321==ON){ Bell(1); }
                           if(TIME_NS323==ON){ Message(209); }
                           break;;
                        }
            }  
         }
         REG03SW__V  =61;
         Clear_TO(31);
         // Если уровень пн.пасоса не пропал- вывести сообщение оператору
         // и выключить регулятор
         if(CTRL_LPOTV==ON and DIH080___V == ON){ 
            Message(205); Bell(1); REG03R___M=OFF; 
         }
         if(STEP07_BACK==101){ STEP03=101; }
         else                { STEP03=7;   }
         return;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    if ( STEP03 ==7 ){
         if(STEP03P!=7){
            Regul_03off();
         }; STEP03P =7;
         if (RegRUN==OFF){ return; }

         // Дать комманду на закрытие клапана подачи воздуха в пн.насос
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = OFF;
         REG03SW__V = 70;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS082___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>1){ 
                            Message(274); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON082___V,3,TIME_ISPPW,70, 7, 31); return;; 
                       }
             case END: { DONCN03=0; break;; }
         };  Clear_TO(31);
         switch ( Check_TO  (34, TIME_OTPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: return;;            
         }
         Clear_TO(31);
         Clear_TO(34);
         REG03SW__V = 71;
         LOAD_NS08C++;
         // Если есть сигнал верхнего уровня мешалки отходов -
         // перейти на шаг 8 (продувка) и начало подкачки
         if (CTRL_HLMOV==ON and DIH210___V==ON){
             Message(249); 
             COUN_OTDZC=0;
             STEP03_BACK = 0; 
             STEP03 = 8;  
             return;
         }
         // Если количество загруженных насосов больше заданного -
         // перейти на шаг 8 (продувка) и начало подкачки
         if (LOAD_NS08C>=LOAD_NS08V){
             Message(250); 
             COUN_OTDZC=0;
             STEP03_BACK = 0; 
             STEP03 = 8;  
             return;
         }
         // Если мешалка отходов выключена -
         // перейти на шаг 8 (продувка) и начало подкачки
         if (DIS210___V==OFF){
             Message(258); 
             COUN_OTDZC=0;
             STEP03 = 8;  
             STEP03_BACK = 0; 
             return;
         }
         // Если закончилось время набора верхнего уровня
         if (FLAG_HLMOExit==ON){
             Message(259); 
             COUN_OTDZC=0;
             STEP03 = 8;  
             STEP03_BACK = 0; 
             return;
         }

         REG03SW__V= 72;
         // Продолжить набор отходов
         STEP03 = 2;
         return;
    }
    //-----------------------------------------------------------------------



    //-----------------------------------------------------------------------
    // ПРОДУВКА:
    if ( STEP03 ==8 ){
         if(STEP03P!=8){
            Regul_03off();
         }; STEP03P =8;
         if (RegRUN==OFF){ return; }

         // Ждать некоторое время перед продувкой
         REG03SW__V = 80;
         switch ( Check_TO  (31, TIME_PRDOV*SEC, ZERO,'=',ON, 1 )){
             case RUN: { return;; }
         }
         REG03SW__V = 81;
         // Открыть клапан воздуха для продувки
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = ON;;
         switch ( Check_TO  (32, TIME_ISPKV*SEC, DIS082___V,'=',ON, 1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>1){ 
                            Message(273); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON082___V,3,TIME_ISPPW,70, 8, 32); return;; 
                       }
             case END: { DONCN03=0; break;; }
         }
         Clear_TO(31);
         Clear_TO(32);
         REG03SW__V = 82;
         STEP03 = 9; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==9 ){
         if(STEP03P!=9){
            TIME_PRDOCMin=0;
            TIME_PRDOC   =0;
         }; STEP03P =9;
         if(RegRUN==OFF){ return; }

         // Ждать время продувки (ПРОДУВКА)
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = ON;;
         REG03SW__V = 90;
         switch ( Check_TO  (31, TIME_PRDOV*MIN, ZERO,'=',ON, 1 )){
            case RUN:{ TIME_PRDOCMin++; TIME_PRDOC=TIME_PRDOCMin/MIN; return;; }
            case BAD:{ 
                        if(TIME_PRDO1==ON){ Bell(1); }
                        if(TIME_PRDO3==ON){ Message(209); }
                        break;;
                     }
         }
         Clear_TO(31);
         REG03SW__V = 91;
         STEP03 = 10;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 ==10 ){
         if(STEP03P!=10){
            ;;
         }; STEP03P =10;
         if (RegRUN==OFF){ return; }

         // Закрыть клапан воздуха после продувки
         // вода           отходы             воздух
         DON071___V = OFF; DON081___V = OFF;  DON082___V = OFF;
         REG03SW__V = 100;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS082___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN03>1){ 
                            Message(274); Bell(1); REG03R___M=OFF; return;;
                         }
                         Isp03PD(&DON082___V,3,TIME_ISPPW,70, 10, 31); return;; 
                       }
             case END: { DONCN03=0; break;; }
         }
         Clear_TO(31);
         // Перейти на шаг возврата
         STEP03 = STEP03_BACK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
    //-----------------------------------------------------------------------
    if ( STEP03 ==70 ){
         if(STEP03P!=70){
            ;;
         }; STEP03P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN03>=DONCH03){ STEP03 = STEP03_PRBK; return; }
         REG03SW__V =700;
         if(Check_TO(203, DONTM03*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(203);
        *DONPR03=(*DONPR03!=ON)?ON:OFF;
         DONCN03++;
         STEP03 = STEP03_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // если задан несуществующий шаг регулятора - регулятор в ручной режим
    Regul_03m();
    return;
}
//---------------------------------------------------------------------------
