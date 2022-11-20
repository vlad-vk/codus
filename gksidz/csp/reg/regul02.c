//---------------------------------------------------------------------------
// Подкачка воды

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR02;                 // текущий сигнал (комманда) выхода на исполн
_i far  DONCN02=0;               // счетчик цикла передергивания              
_i far  DONCH02=2;               // заданное кол-во циклов для передергивания 
_i far  DONTM02=2;               // кол-во секунд вкл и паузы

//---------------------------------------------------------------------------
//  Определения для передергивание исполнителей регулятора при несработке
vd  Isp02PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR02= IOPNT;
    DONCH02= hM;
    DONTM02= hS;
    STEP02 = Step; 
    STEP02_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_02off(vd){
    DON201___V =  OFF;
    DON061___V =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выполнение действий при выключении регулятора
vd  far Regul_02m(vd){
    //-----------------------------------------------------------------------
    if ( STEP02 == 101 ){
         REG02SW__V = 1001;
         if(RegRUN==OFF){ return; }
         // комманда на выключение-закрытие исполнителей регулятора
         DON061___V=OFF; DON201___V=OFF;
         switch ( Check_TO  (21, TIME_ISNSV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         };  Clear_TO (21);
         // повторная комманда на закрытие исполнителей
         Regul_02off();
         //
         COUN_VDDZC=COUN_VDDZW;
         //
         STEP02 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 == 102 ){
         STEP02P = 102;
         REG02SW__V = 1002;
         REG02R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP02=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_02(vd){
    // установки для работы регулятора, определяемые оператором
    // время ожидания сред уровня сборника воды 
    if (TIME_VODMM <  0){ TIME_VODMM = 10; }
    if (TIME_VODMM != TIME_VODMV){ TIME_VODMV = TIME_VODMM; }     // 10 MIN
    // время ожидания верх уровня сборника воды 
    if (TIME_VODHM <  0){ TIME_VODHM = 10; }
    if (TIME_VODHM != TIME_VODHV){ TIME_VODHV = TIME_VODHM; }     // 10 MIN
    // температура выключения подачи конденсата в сборник воды
    if (TEMP_VODBM <  0){ TEMP_VODBM = 45; }
    if (TEMP_VODBM != TEMP_VODBV){ TEMP_VODBV = TEMP_VODBM; }     // 45 C
    // время отведенное для закачки конденсата
    if (TIME_CONDM <  0){ TIME_CONDM =  7; }
    if (TIME_CONDM != TIME_CONDV){ TIME_CONDV = TIME_CONDM; }     //  7 MIN
    // время паузы между включениями исполнителей
    if (TIME_VDPKW <  0){ TIME_VDPKW = 5;  }                      // 5 SEC
    //  Счетчик количества дозировок
    if (COUN_VDDZW <  0){ COUN_VDDZW = 4;  }                      // 4 DOZ
    //  Контроль нижнего уровня зборника воды
    if (CTRL_LLSVM <  0){ CTRL_LLSVV = ON; CTRL_LLSVM = OFF; }    // ON
    if (CTRL_LLSVM == SWITCH){ 
        CTRL_LLSVV = (CTRL_LLSVV!=ON) then_ ON else_ OFF; CTRL_LLSVM=OFF;
    }
    //  Контроль среднего уровня зборника воды
    if (CTRL_MLSVM <  0){ CTRL_MLSVV = ON; CTRL_MLSVM = OFF; }    // ON
    if (CTRL_MLSVM == SWITCH){ 
        CTRL_MLSVV = (CTRL_MLSVV!=ON) then_ ON else_ OFF; CTRL_MLSVM=OFF;
    }
    //  Контроль верхнего уровня зборника воды
    if (CTRL_HLSVM <  0){ CTRL_HLSVV = ON; CTRL_HLSVM = OFF; }    // ON
    if (CTRL_HLSVM == SWITCH){ 
        CTRL_HLSVV = (CTRL_HLSVV!=ON) then_ ON else_ OFF; CTRL_HLSVM=OFF;
    }
    //  Контроль нижнего уровня зборника конденсата
    if (CTRL_LLSKM <  0){ CTRL_LLSKV = ON; CTRL_LLSKM = OFF; }    // ON
    if (CTRL_LLSKM == SWITCH){ 
        CTRL_LLSKV = (CTRL_LLSKV!=ON) then_ ON else_ OFF; CTRL_LLSKM=OFF;
    }

    // включение-выключение регулятора
    if ( REG02RS__M == SWITCH ){ 
         REG02R___M = (REG02R___M==ON) then_ OFF else_ ON; REG02RS__M=OFF;
    }
    if ( REG02R___M != REG02R___V ){ 
         REG02R___M  =(REG02R___M==ON) then_ ON else_ OFF;
         REG02R___V  = REG02R___M;
         if ( REG02R___V == ON ){ Message(330); STEP02 =   0; }   // автомат
         else                   { Message(331); STEP02 = 101; }   // ручное
    }
    // если ключ сборника воды на руке или 
    // включен ручной режим регулятора - выйти
    if ( DIR200___V == MANUAL or REG02R___V == OFF ){ Regul_02m(); return; }

    //-----------------------------------------------------------------------
    // Контроль количества дозировок воды
    if (RegRUN==ON){
        // если вес больше 70 кг и флаг счетчика=0 увеличить счетчик загрузки
        if(AIW230___V>70  and FLAG_VDDZC==0)  { FLAG_VDDZZ++; }
        else                                  { FLAG_VDDZZ=0; }
        // если вес меньше 50  кг и флаг счетчика=1 увеличить счетчик выгрузки
        if(AIW230___V<30  and FLAG_VDDZC==1)  { FLAG_VDDZV++; }
        else                                  { FLAG_VDDZV=0; }
        //---------
        // если вес удерживается более 3 сек - считаем, что дозатор загружен
        if(AIW230___V>70  and FLAG_VDDZC==0 and FLAG_VDDZZ== 3 ){
           FLAG_VDDZC=1;
        }
        // если вес удерживается более 3 сек - считаем, что дозатор выгружен
        // (прошла одна дозировка воды)
        if(AIW230___V<50  and FLAG_VDDZC==1 and FLAG_VDDZV== 3 ){
           FLAG_VDDZC=0;  COUN_VDDZC++;
        }
        //---------
        if(FLAG_VDDZZ>100){ FLAG_VDDZZ=100; }
        if(FLAG_VDDZV>100){ FLAG_VDDZV=100; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    if ( STEP02 ==0 ){
         if(STEP02P!=0){
            ;;
         }; STEP02P =0;
         if (RegRUN==OFF){ return; }

         Regul_02off();
         // ждать, пропадания сигнала верхнего уровня сборника воды
         REG02SW__V = 0;
         if(CTRL_HLSVV==ON){
            switch ( Check_TO  (21, 5*MIN, DIH200___V,'=',OFF, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(21); return;; }
            }
         }
         // ждать, пропадания сигнала среднего уровня сборника воды
         REG02SW__V = 1;
         if(CTRL_MLSVV==ON){
            switch ( Check_TO  (22, 5*MIN, DIM200___V,'=',OFF, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(22); return;; }
            }
         }
         // ждать, появления сигнала нижнего уровня сборника воды
         REG02SW__V = 2;
         if(CTRL_LLSVV==ON){
            switch ( Check_TO  (23, 5*MIN, DIL200___V,'=',ON, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(23); return;; }
            }
         }
         // проверка клапана выгрузки воды из сборника (убедится что закрыт)
         REG02SW__V = 3;
         switch ( Check_TO  (24, TIME_ISPKV*SEC, DIS202___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { Clear_TO(24); return;; }
         }
         //  проверка начального состояния всех исполнителей регулятора
         REG01SW__V = 4;
         if((DIR200___V==AUTO and (DIS201___V==ON)) or
            (DIR061___V==AUTO and (DIS061___V==ON)) ){
             switch ( Check_TO (25,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(262); Bell(1); Clear_TO(25); return;; }
             }
         };  Clear_TO(25);
         //  если количество дозировок воды меньше заданного- выйти
         REG02SW__V = 5;
         if (COUN_VDDZC<COUN_VDDZW){ return; }
         // обнулить таймеры и счетчики
         Clear_TO(21);
         Clear_TO(22);
         Clear_TO(23);
         Clear_TO(24);
         Clear_TO(25);
         TIME_VODMCMin=0;
         TIME_VODMC   =0;
         TIME_VODHCMin=0;
         TIME_VODHC   =0;
         TIME_CONDCMin=0;
         TIME_CONDC   =0;
         //
         DONCN02= 0;
         STEP02 = 1;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==1 ){
         if(STEP02P!=1){
            TIME_VODHCMin = 0;
            TIME_VODMCMin = 0;
            TIME_CONDCMin = 0;
         }; STEP02P =1;
         if (RegRUN==OFF){ return; }

         // открыть клапан подачи технической воды
         REG02SW__V = 10;
         DON201___V = ON;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS201___V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN02>2){ REG02R___M=OFF; return;; }
                         Isp02PD(&DON201___V,3,TIME_ISPPW,70, 1, 21); return;; }
             case END: { DONCN02=0; break;; }
         };  Clear_TO(21);

         REG02SW__V = 11;
         //--------------------------------------------------------------------
         // проверка среднего уровня сборника воды.
         // если за определенное время уровень не появился-сообщение оператору.
         // переход на начало цикла (шаг 0).
         switch ( Check_TO (22, TIME_VODMV*MIN, DIH200___V,'=',ON, TIME_LSTBV)){
             case RUN: { 
                          // считать время набора среднего и верхнего уровней
                          TIME_VODHCMin++; 
                          TIME_VODHC=TIME_VODHCMin/MIN; 
                          TIME_VODMCMin++; 
                          TIME_VODMC=TIME_VODMCMin/MIN; 
                          // если есть сигнал верхнего уровня
                          if(DIH200___V==ON){ STEP02=4; }
                          return;; 
                       }
             case BAD: {
                          if(TIME_VODL1==ON){ Bell(1); }
                          if(TIME_VODL3==ON){ Message(203); }
                          Clear_TO(22);
                          // если есть сигнал верхнего уровня
                          if(DIH200___V==ON){ STEP02=4; return;; }
                          // если вкл контроль сред уровня- на начало цикла
                          if(CTRL_MLSVV==ON){
                             COUN_VDDZC=0; 
                             DON201___V=OFF; DON061___V=OFF; STEP02=0;
                             return;;
                          } 
                          // если контроль среднего уровня выкл- продолж набор
                          break;;
                       }
             case END: {
                          // если выключен контроль среднего уровня-
                          // считать ожидание набора среднего и верхнего
                          // уровня
                          if(CTRL_MLSVV==OFF){
                             TIME_VODMCMin++; 
                             TIME_VODMC=TIME_VODMCMin/MIN; 
                             TIME_VODHCMin++; 
                             TIME_VODHC=TIME_VODHCMin/MIN; 
                          }
                          break;;
                       }
         }
         // если есть сигнал верхнего уровня
         if(DIH200___V==ON){ STEP02=4; return;; }
         Clear_TO(21);
         Clear_TO(22);
         REG02SW__V = 12;
         STEP02 = 2; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==2 ){
         if(STEP02P!=2){
            ;;
         }; STEP02P =2;
         if (RegRUN==OFF){ return; }

         // если сборник конденсата на руке или если выкл контроль ниж уровня
         // сборника конденсата или если есть сиг нижн уровня и включен контр-
         // добрать сборник тех водой до верхнего уровня
         if (DIR061___V==OFF or CTRL_LLSKV==OFF or
            (DIL060___V==ON and CTRL_LLSKV==ON )){ 
             STEP02=4; return; 
         }
         // закрыть клапан подачи технической воды
         DON201___V = OFF;
         REG02SW__V = 20;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS201___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN02>2){ REG02R___M=OFF; return;; }
                         Isp02PD(&DON201___V,3,TIME_ISPPW,70, 2, 21); return;; 
                       }
             case END: { DONCN02=0; break;; }
         };  Clear_TO(21);
         REG02SW__V = 21;

         // если нет сигнала нижнего уровня в сборнике конденсата 
         // и насос переключен на автоматический режим и
         // температура в сборнике воды меньше заданной- 
         // включить насос подкачки конденсата в сборник воды
         if((CTRL_LLSKV==ON and DIL060___V==OFF) and (DIR061___V==AUTO) and
            (AIT200___V <TEMP_VODBV)){
             STEP02 = 3;
             return;
         }
         REG02SW__V = 22;
         // если какое-то условие для включения насоса не выполнилось - 
         // перейти на шаг 0
         COUN_VDDZC = 0;
         STEP02 = 0;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==3 ){
         if(STEP02P!=3){
            TIME_CONDCMin=0;
         }; STEP02P =3;
         if (RegRUN==OFF){ return; }

         // включить насос подачи конденсата в сборник воды
         DON061___V = ON;
         REG02SW__V = 30;
         switch ( Check_TO  (21, TIME_ISNSV*SEC, DIS061___V,'=',ON, 1 )){
             case RUN: { return;; }
         };  Clear_TO(21);
         REG02SW__V = 31;
         // если сработал сигнал верхнего уровня сборника воды или температура
         // повысилась больше заданной- выключить насос
         if((CTRL_HLSVV==ON and DIH200___V==ON) or (AIT200___V>TEMP_VODBV)){
             DON061___V =OFF;
             COUN_VDDZC =0;
             Message(300);
             STEP02 =0;  
             return;
         }
         // если вышло допустимое время закачки конденсата- выключить насос
         switch ( Check_TO  (22, TIME_CONDV*MIN, ZERO,'=',ON,  1 )){
             case RUN: { 
                          TIME_CONDCMin++; 
                          TIME_CONDC=TIME_CONDCMin/MIN;
                          return;; 
                       }
             case BAD: {
                          if(TIME_COND1==ON){ Bell(1); }
                          if(TIME_COND3==ON){ Message(206); }
                          Clear_TO(22); 
                          break;
                       }
         }  
         REG02SW__V = 32;
         Clear_TO(22);
         DON061___V = OFF;
         COUN_VDDZC = 0;
         STEP02 = 0; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==4 ){
         if(STEP02P!=4){
            ;;
         }; STEP02P =4;
         if (RegRUN==OFF){ return; }

         // проверка верхнего уровня сборника воды.
         // если за определенное время уровень не появился-сообщение оператору.
         // переход на начало цикла (шаг 0).
         REG02SW__V = 40;
         switch ( Check_TO(21, TIME_VODHV*MIN, DIH200___V,'=',ON, TIME_LSTBV)){
             case RUN: {
                          TIME_VODHCMin++; 
                          TIME_VODHC=TIME_VODHCMin/MIN; 
                          return;; 
                       }
             case BAD: {
                          if(TIME_VODL1==ON){ Bell(1); }
                          if(TIME_VODL3==ON){ Message(257); }
                          Clear_TO(21);
                          COUN_VDDZC=0;
                          DON201___V=OFF;  DON061___V=OFF;
                          STEP02=0;
                          return;;
                       }
             case END: {
                          // если выкл контр верх уровня сбор воды- считать вр
                          if(CTRL_HLSVV==OFF){
                             TIME_VODHCMin++; 
                             TIME_VODHC=TIME_VODHCMin/MIN; 
                             return;; 
                          }
                          Message(301);
                          break;;
                       }
         }
         Clear_TO(21);
         COUN_VDDZC=0;
         DON201___V=OFF;  DON061___V=OFF;
         STEP02=0; 
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
    //-----------------------------------------------------------------------
    if ( STEP02 ==70 ){
         if(STEP02P!=70){
            ;;
         }; STEP02P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN02>=DONCH02){ STEP02 = STEP02_PRBK; return; }
         REG02SW__V =700;
         if(Check_TO(202, DONTM02*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(202);
        *DONPR02=(*DONPR02!=ON)?ON:OFF;
         DONCN02++;
         STEP02 = STEP02_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // если задан несуществующий шаг регулятора - регулятор в ручной режим
    Regul_02m();
    return;
}
//---------------------------------------------------------------------------
