// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// Дозировка мокрого

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR07;
_i far  DONCN07=0;                // счетчик цикла передергивания             
_i far  DONCH07=2;                // заданное кол-во циклов для передергивания
_i far  DONTM07=2;                // кол-во секунд вкл и паузы

_i far  GERMDOWN=0;               // счетчик на опускание герметизатора

_f far  CNTTEMP=0;                // временный счетчик
_f far  REG07ZO1_F=0;             // флаг вывода запроса

_f far  CYRSLMS=0;               // шаг включения циркуляции шлама
_f far  CYROTHS=0;               // шаг включения циркуляции обратного шлама
_f far  DIS06xC=0;
_f far  DIS05xC=0;
_f far  DIS251x=0;

_f far  PO2511=0;                // процент открытия клапана набора прямого шлама
_f far  PO2512=0;                // процент открытия клапана набора обратного шлама

//---------------------------------------------------------------------------
//  Определения для передергивания исполнителей регулятора при несработке
vd  Isp07PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR07= IOPNT;
    DONCH07= hM;
    DONTM07= hS;
    STEP07 = Step; 
    STEP07_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  Если регулятор включен - управлять исполнителями вручную нельзя
vd  far ModeKO_07(vd){
    if (REG07R___V==ON /*||REG07GL__V==ON*/ ){
    DON064C__M = OFF;
    DON065C__M = OFF;
    DON064E__M = OFF;
    DON065E__M = OFF;
    DON251E1_M = OFF;
    DON266E__M = OFF;
    DON251B1_M = OFF;
    DON251C1_M = OFF;
    DON251F1_M = OFF;
                     
    DON056C__M = OFF;
    DON057C__M = OFF;
    DON056E__M = OFF;
    DON057E__M = OFF;
    DON251E2_M = OFF;
    DON258E__M = OFF;
    DON251B2_M = OFF;
    DON251C2_M = OFF;
    DON251F2_M = OFF;

    DON251H1_M = OFF;
    DON251H2_M = OFF;
    DON251G1_M = OFF;
    DON251G2_M = OFF;
    DON2x07__M = OFF;
    DON2x01__M = OFF;
    DON2x02__M = OFF;
    DON2x03__M = OFF;
    DON2x04__M = OFF;
}   }
//---------------------------------------------------------------------------
//  Выключение исполнителей
vd  far Regul_07off_V(vd){
    DON251H1_V = OFF; // х вода
    DON251H2_V = OFF; // бар
    DON251G1_V = OFF; // г вода
    DON251G2_V = OFF; // выгр ДМокр
    DON2x07__V = OFF; // выгр ДВоды
    DON2x01__V = OFF; // вода на ДМ
    DON2x02__V = OFF; // вода на ВГБМ
    DON2x03__V = OFF; // вода на алл.
    DON2x04__V = OFF; // насос
}
//-------------------------------
vd  far Regul_07off_S(int far m){
    // исполнители дозировки
    if(m<2){
    DON251F1_V = OFF; // пр шл (не исп)
    AON2511_OM = 0;   AON2511_OV = 0;
    DON251E1_V = OFF;
    }
    if(m==1&&CYRSLMS>0&&CYRSLMS<101) return;
    // исполнители циркуляции
    DON251B1_V = OFF;
    DON251C1_V = OFF;
    DON064C__V = OFF; // из меш
    DON065C__V = OFF;
    DON064E__V = OFF; // в меш
    DON065E__V = OFF;
    DON266E__V = OFF; // нас
    AON266A_OM = 0;
}
//-------------------------------
vd  far Regul_07off_O(int far m){
    // исполнители дозировки (=0,=1)
    if(m<2){
    DON251F2_V = OFF; // об шл (не исп)
    AON2512_OM = 0;   AON2512_OV = 0;
    DON251E2_V = OFF;
    }
    if(m==1&&CYROTHS>0&&CYROTHS<101) return;
    // исполнители циркуляции (=0,=2)
    DON251B2_V = OFF;
    DON251C2_V = OFF;
    DON056C__V = OFF;
    DON057C__V = OFF;
    DON056E__V = OFF;
    DON057E__V = OFF;
    DON258E__V = OFF;
    AON258A_OM = 0;
}
//-------------------------------
vd  far Regul_07off(vd){
    Regul_07off_V(); Regul_07off_S(0); Regul_07off_O(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Regul_07_Save(vd){
    if(STEP07 ==70) STEP07__SV=STEP07_PRBK;  else STEP07__SV=STEP07;
    if(STEP07v==70) STEP07v_SV=STEP07v_PRBK; else STEP07v_SV=STEP07v;
}
//---------------------------------------------------------------------------
vd  far Regul_07_Rest(vd){
    STEP07 =STEP07__SV;
    STEP07v=STEP07v_SV;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Установка выходов "двойных" клапанов и получение их состояния
vd  far Set_5xC(_f far SV){
    if(OBJM56___V>0){ DON056C__V=SV;; DON057C__V=OFF; }
    if(OBJM57___V>0){ DON056C__V=OFF; DON057C__V=SV;; }
}
vd  far Set_6xC(_f far SV){
    if(OBJM64___V>0){ DON064C__V=SV;; DON065C__V=OFF; }
    if(OBJM65___V>0){ DON064C__V=OFF; DON065C__V=SV;; }
}
vd  far Get_5xC(vd){
    if(OBJM56___V>0){ DIS05xC=DIS056C__V; }
    else            { DIS05xC=DIS057C__V; }
}
vd  far Get_6xC(vd){
    if(OBJM64___V>0){ DIS06xC=DIS064C__V; }
    else            { DIS06xC=DIS065C__V; }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ВЫКЛЮЧЕНИЕ РЕГУЛЯТОРА
vd  far Regul_07m(vd){
    //-----------------------------------------------------------------------
    // выключение регулятора
    if ( STEP07 == 101 ){
         Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);
         REG07SW__V = 1001;
         STEP07 =  102;
         STEP07v=  102;
    }
    //-----------------------------------------------------------------------
    // регулятор выключен
    if ( STEP07 == 102 ){
         STEP07P = 102;
         REG07SW__V = 1002;
         REG07R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP07 =101;
    STEP07v=101;
    VDFLAG___V=0;
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far Regul_07(vd){

    //  Значения с таблицы настроек ЧП
    NASSLMOSTV=NASSLMOSTM;
    NASSLMCYRV=NASSLMCYRM;
    NASSLMZAGV=NASSLMZAGM;
    NASSLMGRUV=NASSLMGRUM;
    NASSLMMANV=NASSLMMANM;
    NASOTHOSTV=NASOTHOSTM;
    NASOTHCYRV=NASOTHCYRM;
    NASOTHZAGV=NASOTHZAGM;
    NASOTHGRUV=NASOTHGRUM;
    NASOTHMANV=NASOTHMANM;

    //  включение-выключение регулятора
    if ( REG07RS__M == SWITCH ){ 
         REG07R___M = (REG07R___M==ON) then_ OFF else_ ON; REG07RS__M=OFF;
    }
    if (REG07R___M != REG07R___V){ 
        REG07R___M  =(REG07R___M==ON) then_ ON else_ OFF;
        REG07R___V  = REG07R___M; 
        if (REG07R___V>0){
            // включить
            Message(380,NOKV); STEP07=0; STEP07v=0;
            // если включен общий регулятор и регулятор в работе - восстановить состояние регулятора
            if (RegPublicV==ON and REG07GL__V==ON and STEP07__SV>1){
                Regul_07_Rest(); Message(236,NOKV); return;
            }
        } else { 
            // если включен общий регулятор и регулятор в работе - записать состояние регулятора
            if (RegPublicV==ON and REG07GL__V==ON and STEP07>1 and STEP07<70){ 
                Regul_07_Save(); Message(235,NOKV);
            }
            // выключить
            Message(381,NOKV); Regul_07off(); STEP07=101; STEP07v=101; return;
        }
    }
    // при выключении общего регулятора сбрасываются значения записанного шага
    if (RegPublicV==OFF or REG07GL__V==OFF){ STEP07__SV=0; STEP07v_SV=0; }

    //  загрузка-выгрузка
    if ( REG07ZV__M != REG07ZV__V ){ 
         REG07ZV__M  =(REG07ZV__M==ON) then_ ON else_ OFF;
         REG07ZV__V  = REG07ZV__M;
         if(REG07ZV__V>0){ Message(480,NOKV); }                      // загрузка
         else            { Message(481,NOKV); }                      // выгрузка
    }

    //  общий-локальный
    if ( REG07GL__M != REG07GL__V ){ 
         REG07GL__M  =(REG07GL__M==ON) then_ ON else_ OFF;
         REG07GL__V  = REG07GL__M;
         if(REG07GL__V>0){ Message(482,NOKV); }                      // общий
         else            { Message(483,NOKV); }                      // локальный
    }

    //------------------------------
    //  вкл-выкл циркуляции шлама
    if ( CYRSLM___M != CYRSLM___V ){ 
         CYRSLM___V  = CYRSLM___M;
         if(CYRSLM___V>0){ Message(100,NOKV); CYRSLMS= 10; }         // вкл циркуляцию
         else            { Message(101,NOKV); CYRSLMS=101; }         // выкл
         // если выкл лок реж регул (переключ только в лок режиме)
         if(CYRSLMS<101&&REG07GL__V==1){ Message(101,NOKV); CYRSLMS=101; }
         // выключить все исполнители
         Regul_07off(); return;
    }
    // при работе циркуляции открыть только клапана циркуляции и после этого включить насос
    if ( CYRSLMS>0 && CYRSLMS<101 ){
         // выключить циркуляцию,а потом включить,что надо (насос по-умолчанию включен,надо выключать)
         Regul_07off_S (2); DON266E__V=ON; if(DIS251C1_V>0) AON266A_OM=NASSLMCYRV;
         // открыть клапана циркуляции
         if (OBJM64___V>0){ DON064C__V=ON; /*из меш*/ DON064E__V=ON; /*в меш*/ }
         if (OBJM65___V>0){ DON065C__V=ON; /*из меш*/ DON065E__V=ON; /*в меш*/ }
         DON251B1_V=ON; /*на нас*/ DON251C1_V=ON; /*после нас*/
         // каждую секунду проверка счетчика несработки...
         if (RegRUN==ON){
             // если клапана циркуляции открыты - сбросить счетчик несработки (не более 10сек)
             if((DIS064C__V==ON && DIS064E__V==ON)||(DIS065C__V==ON && DIS065E__V==ON)){
                 if(CYRSLMS>1) CYRSLMS--; if(CYRSLMS>10) CYRSLMS=10;
             } else {
             // если что-то закрыто - включить счетчик несработки (сек)
             // чтобы избежать "дребезга" при включении-выключении, минамальный счетчик установить=3сек
                 if(CYRSLMS<3) CYRSLMS=3; if(CYRSLMS<200) CYRSLMS++; // при =101 будет выход из циркуляции
         }   }
         // если счетчик несработки больше 5сек- выключить насос (по-умолчанию включен)
         if(CYRSLMS>7){ DON266E__V=OFF; AON266A_OM=0; }
    }    
    // если есть комманда на выключение циркуляции
    if ( CYRSLMS>=101 ){
         Regul_07off_S(0); Message(102,NOKV); CYRSLMS=0; CYRSLM___V=CYRSLM___M=OFF; return;
    }
    //------------------------------
    //  вкл-выкл циркуляции ОБРАТНОГО шлама
    if ( CYROTH___M != CYROTH___V ){ 
         CYROTH___V  = CYROTH___M;
         if(CYROTH___V>0){ Message(103,NOKV); CYROTHS= 10; }         // вкл циркуляцию
         else            { Message(104,NOKV); CYROTHS=101; }         // выкл
         // если выкл лок реж регул (переключ только в лок режиме)
         if(CYROTHS<101&&REG07GL__V==1){ Message(104,NOKV); CYROTHS=101; }
         // выключить все исполнители
         Regul_07off(); return;
    }
    // при работе циркуляции открыть только клапана циркуляции и после этого включить насос
    if ( CYROTHS>0 && CYROTHS<101 ){
         // выключить циркуляцию,а потом включить,что надо (насос по-умолчанию включен,надо выключать)
         Regul_07off_S (2); DON258E__V=ON; if(DIS251C2_V>0) AON258A_OM=NASOTHCYRV;
         // открыть клапана циркуляции
         if (OBJM56___V>0){ DON056C__V=ON; /*из меш*/ DON056E__V=ON; /*в меш*/ }
         if (OBJM57___V>0){ DON057C__V=ON; /*из меш*/ DON057E__V=ON; /*в меш*/ }
         DON251B2_V=ON; /*на нас*/ DON251C2_V=ON; /*после нас*/
         // каждую секунду проверка счетчика несработки...
         if (RegRUN==ON){
             // если клапана циркуляции открыты - сбросить счетчик несработки (не более 10сек)
             if((DIS056C__V==ON && DIS056E__V==ON)||(DIS057C__V==ON && DIS057E__V==ON)){
                 if(CYROTHS>1) CYROTHS--; if(CYROTHS>10) CYROTHS=10;
             } else {
             // если что-то закрыто - включить счетчик несработки (сек)
             // чтобы избежать "дребезга" при включении-выключении, минамальный счетчик установить=3сек
                 if(CYROTHS<3) CYROTHS=3; if(CYROTHS<200) CYROTHS++; // при =101 будет выход из циркуляции
         }   }
         // если счетчик несработки больше 5сек- выключить насос (по-умолчанию включен)
         if(CYROTHS>7){ DON258E__V=OFF; AON258A_OM=0; }
    }    
    // если есть комманда на выключение циркуляции
    if ( CYROTHS>=101 ){
         Regul_07off_S(0); Message(105,NOKV); CYROTHS=0; CYROTH___V=CYROTH___M=OFF; return;
    }
    //------------------------------



    //  если регулятор выключен - выйти
    if (REG07R___V == OFF && REG07GL__V == OFF){ Regul_07m(); return; }

    // !!!!
    // если во время загрузки-выгрузки мокрого поднялся герметизатор -
    // закрыть клапан выгрузки и выключить регулятор
    if (STEP07>=52 and STEP07<=60 and DISVGBMG_V==OFF and RegRUN==ON){
//  if (STEP07 >1  and STEP07< 60 and DISVGBMG_V==OFF and RegRUN==ON){
        GERMDOWN++;
        if (GERMDOWN>1){
            Bell(1,1); Message(116,NOKV); Message(677,NOKV); GERMDOWN=0; Regul_07m(); return;
        }
    } else { GERMDOWN=0; }
    // !!!!

    //  если сработал аварийный уровень дозатора мокрого-
    //  дать комманду на закрытие клапанов и выключении регулятора
    if (DIH252A__V>0){
        Bell(1,1); Message(150,KVIT); // Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1); Regul_07m(); return;
    }

    // ПРОВЕРКА УСЛОВИЙ включения регулятора
    //-----------------------------------------------------------------------
    if (STEP07== 0 ){
        if(STEP07P!=0){
           Clear_TO(73);
        }; STEP07P =0;
        Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);

        if (RegRUN==OFF){ return; }

        //  ключ дозатора мокрого в режиме Наладка - выйти
        REG07SW__V =2;
        if(DIR219___V==1){ return; }

        //  проверка начального состояния исполнителей дозатора мокрого
        REG07SW__V =6; Get_6xC(); Get_5xC();
        if (DIS251E1_V==ON or DIS251F1_V==ON or DIS251G1_V==ON or DIS251H1_V==ON or
            DIS251E2_V==ON or DIS251F2_V==ON or DIS251G2_V==ON){
            switch(Check_TO(73,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(268,KVIT); Bell(1,1); Clear_TO(73); return;; }
            }
        }

        REG07SW__V =2001;

        Clear_TO(71); Clear_TO(72); Clear_TO(73);

        STEP07=1;
        return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА УСЛОВИЙ и определение направления работы регулятора
    //-----------------------------------------------------------------------
    if (STEP07== 1 ){
        if(STEP07P!=1){
           ;;
        }; STEP07P =1;
        if (RegRUN==OFF){ return; }

        // Если регулятор в ЛОКАЛЬНОМ режиме проверить ротор ВГБМ и герметизатор
        if (REG07GL__V==OFF){ 
            //  ВГБМ не включена
            REG07SW__V =12;
            switch ( Check_TO  (72, 2*MIN, DISVGBMR_V,'=',ON, 1 )){
                case RUN: { return;; }
                case BAD: { Clear_TO(72); Message(386,NOKV); Bell(1,1); return;; }
            };  Clear_TO(72);
            //  герметизатор не опущен
            REG07SW__V =14;
            switch ( Check_TO  (73, 2*MIN, DISVGBMG_V,'=',ON, 1 )){  
                case RUN: { return;; }
                case BAD: { Clear_TO(73); Message(387,NOKV); Bell(1,1); return;; }
            };  Clear_TO(73);
        }

        //  если регулятор в ЛОКАЛЬНОМ режиме и выбран режим ВЫГРУЗКИ-
        //  перейти на шаг выгрузки
        if (REG07GL__V==OFF and REG07ZV__V==OFF){ STEP07=51; STEP07v=51; STEP07_BACK=30; return; }

        //  если регулятор в ЛОКАЛЬНОМ режиме и выбран режим набора
        if (REG07GL__V==OFF){ STEP07=5; STEP07v=22; DON211A1_V=0; }

        //  если регулятор в ОБЩЕМ режиме (включен общий регулятор)
        //  и дозатор мокрого не загружен - перейти на шаг ЗАГРУЗКИ дз мокрого и ДВоды
        // (при работе общего регулятора режим загрузка-выгрузка не нужен
        //  выгрузка дозатора мокрого начинается сразу после набора мокрого)
        if (REG07GL__V==ON and RegPublicV==ON and DON211A1_V==0){ 
            // проверка включения ротора ВГБМ
            REG07SW__V =12;
            if(DISVGBMR_V==OFF){ return; }
            // проверка герметизатора
            REG07SW__V =14;
            if(DISVGBMG_V==OFF){ return; }
            STEP07=5;
            // если первый раз включили регулятор - набор воды на шаге=0,
            // после автоматического набора и выгрузки - на шаге=30
            if(STEP07v==0) STEP07v=22;
        }

        // обнуление отображения текущего веса ТОЛЬКО при наборе
        if((REG07GL__V==OFF and REG07ZV__V==ON) or DON211B1_V==0){
            CRVODD___V=0;
            CROTH____V=0;
            CRSLM____V=0;
            AIW252FV_V=0;
            AIW252NV_V=AIW252___V;           // начальный вес дозатора мокрого
            AIW252VD_V=AIW252___V;           // начальный вес дозатора мокрого
            AIW251FV_V=0;
            AIW251NV_V=AIW251___V;           // начальный вес дозатора воды
            AIW251VD_V=AIW251___V;           // начальный вес дозатора воды
        }
        return;
    }
    //-----------------------------------------------------------------------


    // ДОЗИРОВКА ОБР ШЛАМА
    //-----------------------------------------------------------------------
    // Открытие клапанов набора обр шлама
    if (STEP07== 5 ){
        if(STEP07P!=5){
           Clear_TO(71);                    // обнулить таймеры
           Clear_TO(72);                    //
           AIW252___O = AIW252___V;         // запомнить текущий вес дозатора
           AIW252NV_V = AIW252___V;         // запомнить текущий вес дозатора
           if(STEP07P!=70) Regul_07off_O(1);
        }; STEP07P =5;
        REG07SW__V =51;

        //  определить вес отсечки, задания и блокировки
        AIW252VO_V = TROTH__VIB-VSOT_OTH_W;
        AIW252VZ_V = TROTH__VIB;

        //  проверить вес набора обр шлама. если набран - на след шаг
        if(AIW252___V >= AIW252VO_V){ Regul_07off_O(1); STEP07=12; return; }

        //  вес обр шлама
        CROTH____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=5;

        if(RegRUN==OFF){ return; }

        // задание клапану дозировки и циркуляции
        if(CYROTH___V==0){ DON251F2_V = ON;; PO2512=100; DON251E2_V = OFF; DIS251x=DIS251F2_V; }  // цирк выкл
        else             { DON251F2_V = OFF; PO2512=0;   DON251E2_V = ON;; DIS251x=DIS251E2_V; }  // цирк вкл
        // т.к. циркуляция не работает (не исп технологами), задаем процент открытия явно = 100%
        AON2512_OV=AON2512_OM=PO2512=100;

        // проверить открытие клапана дозировки обр шлама ТОЧНО
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251x,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // если после передергивания клапан не открылся-
                        // сообщение, звонок, выключить регулятор
                        if(DONCN07>2){ Bell(1,1); Message(309,KVIT); DONCN07=0; return; }
                        if(CYROTH___V==0) Isp07PD(&DON251F2_V,3,TIME_ISPPW,70, STEP07P, 71);
                        else              Isp07PD(&DON251E2_V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }
        if(CYROTH___V==0){
        // проверить открытие клапана дозировки обр шлама ГРУБО
        Set_5xC(ON); Get_5xC();
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS05xC,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // если после передергивания клапан не открылся-
                        // сообщение, звонок, выключить регулятор
                        if(DONCN07>2){ Bell(1,1); Message(310,KVIT); DONCN07=0; return; }
                        if(OBJM56___V>0) Isp07PD(&DON056C__V,3,TIME_ISPPW,70, STEP07P, 72);
                        else             Isp07PD(&DON057C__V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }   }
        Clear_TO(71);
        Clear_TO(72);
        STEP07 = 6; 
        return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА ВЕСА набора обр шлама
    //-----------------------------------------------------------------------
    if (STEP07== 6 ){
        if(STEP07P!=6){
           TMST_OTH_C=0;                    // счетчик времени проверок
           VSST_OTH_C=0;                    // счетчик проверок веса
           AIW252___O=AIW252___V;           // запомнить текущий вес дозатора
        }; STEP07P =6;
        REG07SW__V =61;

        // определить вес отсечки, задания и блокировки
        AIW252VO_V = TROTH__VIB-VSOT_OTH_W;
        AIW252VZ_V = TROTH__VIB;

//      // задать % открытия клапану дозировки обр шлама
        if(AIW252___V > TROTH__VIB-AON2512VOW){
            PO2512=AON2512__W;
        }

//      // вес набора обр шлама ГРУБО - сбросить скорость насоса
        if(AIW252___V > TROTH__VIB-VSOT_OTG_W){ 
            if(CYROTH___V<1){ DON056C__V=OFF; DON057C__V=OFF; }
            else            { AON258A_OM=NASOTHGRUV; }
        }

        // если вес ТОЧНО обр шлама больше или равен заданному минус
        // вес отсечки- закрыть клапана регулятора и на след шаг
        if (AIW252___V>=TROTH__VIB-VSOT_OTH_W){ 
            if(CYROTH___V>0){ DON251C2_V=ON; }
            PO2512=0;
            AON258A_OM=NASOTHOSTV; Regul_07off_O(1); STEP07=7; return;
        }

        // вес набранных обр шлама 
        CROTH____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=6;

        if (RegRUN==OFF){ return; }

        // Переключение "на ходу" бункера для набора шлама
        Set_5xC(ON); Get_5xC();

//      // Если открыт клапан дозировки с циркуляции - закрыть клапан циркуляции и 
        // включить скорость насоса для загрузки:
        if(DON251E2_V==ON){ 
             DON251C2_V=OFF; AON258A_OM=NASOTHZAGV;
        }
        // иначе установить процент открытия клапана дозировки:
//      else { 
             AON2512_OM=AON2512_OV=PO2512;
//      }

        // увеличить счетчик времени проверки веса набора обр шлама
           TMST_OTH_C++;
        if(TMST_OTH_C>TMST_OTH_W){
           // если запомненный вес дозатора + заданный вес стабилизации больше
           // чем текущий вес дозатора (нет набора веса)
           if(AIW252___O+VSST_OTH_W>AIW252___V){
              // увеличить счетчик проверок веса стабилизации
              VSST_OTH_C++;
              // если счетчик проверок веса стабилизации >2 
              if(VSST_OTH_C>2){ Bell(1,1); Message(215,KVIT); VSST_OTH_C=0; return; }
           } else {
           // если вес набирается нормально- обнулить счетчик проверок веса
              VSST_OTH_C=0;
           }
           // запомнить текущий вес дозатора
           AIW252___O=AIW252___V;
           // обнулить счетчик времени стабилизации
           TMST_OTH_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА ЗАКРЫТИЯ ИСПОЛНИТЕЛЕЙ набора обр шлама и стабилизации веса
    //-----------------------------------------------------------------------
    if (STEP07== 7 ){
        if(STEP07P!=7){
           CNST_OTH_C=0;                    // счетчик проверок стабилизации
           TMST_OTH_C=0;                    // счетчик времени  стабилизации 
           AIW252___O=AIW252___V;           // запомнить текущий вес дозатора
        }; STEP07P =7;
        Regul_07off_O(1);                   // закрыть(выключить) исполнители регулятора
        AON2512_OM=AON2512_OV=PO2512=0;     // закрыть клап дозир обрат шлама
        REG07SW__V =71;

        if(RegRUN==OFF){ return; }

        // проверить закрытие клапана набора обр шлама ТОЧНО
        if(CYROTH___V==0){
        Get_5xC();
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS05xC,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(311,KVIT); DONCN07=0; return; }
                        if(OBJM56___V>0) Isp07PD(&DON056C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        else             Isp07PD(&DON057C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; AIW252___O=AIW252___V; break;; }
        }   }

        // проверить закрытие клапана набора обр шлама ГРУБО
        if(CYROTH___V==0){ DON251F2_V = OFF; DON251E2_V = OFF; DIS251x=DIS251F2_V; }  // цирк выкл
        else             { DON251F2_V = OFF; DON251E2_V = OFF; DIS251x=DIS251E2_V; }  // цирк вкл
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(312,KVIT); DONCN07=0; return; }
                        if(CYROTH___V==0) Isp07PD(&DON251F2_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E2_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; AIW252___O=AIW252___V; break;; }
        }

        // ждать время стабилизации веса
        REG07SW__V =72;
        switch ( Check_TO  (73, TMST_OTH_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_OTH_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);

        // проверка веса стабилизации:
        // если запомненный вес дозатора + вес стабилизации меньше текущего
        // веса дозатора (вес продолжает набираться(нет стабилизации веса))
        if(AIW252___O+VSST_OTH_W<AIW252___V){
           CNST_OTH_C++;
           // если счетчик проверок стабилизации больше заданного-
           // сообщение, звонок, выключить регулятор
           if(CNST_OTH_C>CNST_OTH_W){ 
              Bell(1,1); Message(313,KVIT); return;
           } else {
           // если счетчик проверок меньше заданного запомнить текущий вес
           // и еще раз проверить (выполнить этот же шаг)
              Set_5xC(ON); DON251F2_V=ON; AIW252___O=AIW252___V; return;
           }
        }

        STEP07 = 12;
        return;
    }
    //-----------------------------------------------------------------------
    if (STEP07>7 and STEP07<12){ STEP07=12; }
    //-----------------------------------------------------------------------



    //  ДОЗИРОВКА ШЛАМА
    //-----------------------------------------------------------------------
    //  Открытие клапанов набора шлама ГРУБО
    if (STEP07== 12 ){
        if(STEP07P!=12){
           if(STEP07P!=70){ Regul_07off_O(1); Regul_07off_S(1); }
           Clear_TO(71);
           Clear_TO(72);
           if(AIW252FV_V==5||AIW252FV_V==6){ CROTH____V=AIW252___V-AIW252NV_V; }
           AIW252___O = AIW252___V;         // запомнить текущий вес дозатора
           AIW252NV_V = AIW252___V;         // запомнить текущий вес дозатора
        }; STEP07P =12;
        REG07SW__V =121;

        //  определить вес отсечки, задания и блокировки
        //  если выбрана дозировка покомпонентно
        AIW252VO_V = TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
        AIW252VZ_V = TROTH__VIB+TRSLM__VIB;

        CRSLM____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=12;

        if(AIW252___V > TROTH__VIB+TRSLM__VIB-VSOT_SLT_W){ 
            if(CYRSLM___V>0){ DON251C1_V=ON; DON251E1_V=OFF; }
            AON266A_OM=NASSLMOSTV; Regul_07off_S(1); STEP07=15; return; 
        }

        if(RegRUN==OFF){ return; }

        // задание клапану дозировки и циркуляции
        if(CYRSLM___V==0){ DON251F1_V = ON;; PO2511=100; DON251E1_V = OFF; DIS251x=DIS251F1_V; }  // цирк выкл
        else             { DON251F1_V = OFF; PO2511=0;   DON251E1_V = ON;; DIS251x=DIS251E1_V; }  // цирк вкл
        // т.к. циркуляция не работает (не исп технологами), задаем процент открытия явно = 100%
        AON2511_OV=AON2511_OM=PO2511=100;

        // проверить открытие клапана дозировки прям шлама ТОЧНО
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(315,KVIT); DONCN07=0; return; }
                        if(CYRSLM___V==0) Isp07PD(&DON251F1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }  

        //  дать комманду на открытие клапана дозировки шлама ГРУБО
        if(CYRSLM___V==0){
        Set_6xC(ON); Get_6xC();
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS06xC,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(314,KVIT); DONCN07=0; return; }
                        if(OBJM64___V>0) Isp07PD(&DON064C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        else             Isp07PD(&DON065C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }   }

        Clear_TO(71);
        Clear_TO(72);
        STEP07 = 14; 
        return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА ВЕСА НАБОРА шлама
    //-----------------------------------------------------------------------
    if (STEP07== 14 ){
        if(STEP07P!=14){
           VSST_SLT_C = 0;
           TMST_SLT_C = 0;
           AIW252___O = AIW252___V;         // запомнить текущий вес дозатора
        }; STEP07P =14;
        REG07SW__V =141;

        //  определить вес отсечки, задания и блокировки
        //  если выбрана дозировка покомпонентно
        AIW252VO_V = TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
        AIW252VZ_V = TROTH__VIB+TRSLM__VIB;

        // если текущий вес больше рецептного минус вес отсечки ТОЧНО
        if (AIW252___V >= AIW252VO_V){ 
            PO2511=0;
            Regul_07off_S(1); STEP07=15; return;
        }

        CRSLM____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=14;

//      // задать % открытия клапану дозировки шлама
        if(AIW252___V > AIW252VZ_V-AON2511VOW){
            PO2511=AON2511__W;
        }

//      // вес набора шлама ГРУБО
        if(AIW252___V > AIW252VZ_V-VSOT_SLG_W){
            if(CYRSLM___V<1){ DON064C__V=OFF; DON065C__V=OFF; }
            else            { AON266A_OM=NASSLMGRUV; }
        }

        // проверить вес набора шлама ТОЧНО, набран - на выгрузку
        if(AIW252___V > AIW252VZ_V-VSOT_SLT_W){ 
            if(CYRSLM___V>0){ DON251C1_V=ON; }
            PO2511=0;
            AON266A_OM=NASSLMOSTV; Regul_07off_S(1); STEP07=15; return; 
        }

        if (RegRUN==OFF){ return; }

        // При наборе шлама можно переключить бункер с которого брать шлам
        Set_6xC(ON); Get_6xC();

//      // Если открыт клапан дозировки с циркуляции - закрыть клапан циркуляции и 
        // включить скорость насоса для загрузки
        if(DIS251E1_V==ON){ DON251C1_V=OFF; AON266A_OM=NASSLMZAGV; }
        // иначе установить процент открытия клапана дозировки:
//      else { 
             AON2511_OM=AON2511_OV=PO2511;
//      }

        // увеличить счетчик времени проверки веса набора шлама ГРУБО
           TMST_SLT_C++;
        if(TMST_SLT_C>TMST_SLT_W){
           // если запомненный вес дозатора + заданный вес стабилизации больше
           // чем текущий вес дозатора (нет набора веса)
           if(AIW252___O+VSST_SLT_W>AIW252___V){
              // увеличить счетчик проверок веса стабилизации
              VSST_SLT_C++;
              // если счетчик проверок веса стабилизации >2 
              if(VSST_SLT_C>2){ Bell(1,1); VSST_SLT_C=0; return; }
           } else {
           // если вес набирается нормально- обнулить счетчик проверок веса
              VSST_SLT_C=0;
           }
           // запомнить текущий вес дозатора
           AIW252___O=AIW252___V;
           // обнулить счетчик времени стабилизации
           TMST_SLT_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА ЗАКРЫТИЯ ИСПОЛНИТЕЛЕЙ набора шлама
    //-----------------------------------------------------------------------
    if (STEP07== 15 ){
        if(STEP07P!=15){
           Clear_TO(71);                    // обнулить таймеры
           Clear_TO(72);                    //
           Clear_TO(73);                    //
           TMST_SLT_C=0;                    //
           CNST_SL__C=0;
           AIW252___O=AIW252___V;           // запомнить текущий вес дозатора
        }; STEP07P =15;
        REG07SW__V =151;
        Regul_07off_O(1); Regul_07off_S(1);
        AON2511_OM=AON2511_OV=PO2511=0;     // закрыть клап дозир прям шлама

        if(AIW252FV_V==14){
           CRSLM____V=AIW252___V-AIW252NV_V; 
        }

        if (RegRUN==OFF){ return; }

        // проверить закрытие клапана набора шлама ТОЧНО
        if(CYRSLM___V==0){ DON251F1_V = OFF; DON251E1_V = OFF; DIS251x=DIS251F1_V; }  // цирк выкл
        else             { DON251F1_V = OFF; DON251E1_V = OFF; DIS251x=DIS251E1_V; }  // цирк вкл
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(317,KVIT); DONCN07=0; return; }
                        if(CYRSLM___V==0) Isp07PD(&DON251F1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }

        // ждать время стабилизации веса
        REG07SW__V =152;
        switch ( Check_TO  (73, TMST_SLT_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_SLT_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);

        // проверка веса стабилизации:
        // если запомненный вес дозатора + вес стабилизации меньше текущего
        // веса дозатора (вес продолжает набираться(нет стабилизации веса))
        if(AIW252___O+VSST_SLT_W<AIW252___V){
           CNST_SL__C++;
           // если счетчик проверок стабилизации больше заданного
           if(CNST_SL__C>CNST_SL__W){
              Bell(1,1); Message(148,KVIT); return;
           } else {
           // если счетчик проверок меньше заданного запомнить текущий вес
           // и еще раз проверить (выполнить этот же шаг)
              Set_6xC(ON); DON251F1_V=ON; AIW252___O=AIW252___V; return;
           }
        }

        // если регулятор в общем режиме - выгрузка 
        if(REG07GL__V==ON){ STEP07=51; STEP07_BACK=30; return; }
        STEP07=30;
        return;
    }
    //-----------------------------------------------------------------------

 
    //-----------------------------------------------------------------------
    // НАБОР ВОДЫ в регуляторе regul_07v
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ОПРЕДЕЛЕНИЕ ПЕРЕХОДА
    //-----------------------------------------------------------------------
    if (STEP07==30){
        if(STEP07P!=30){
        }; STEP07P =30;
        if(STEP07v!=30){ return; }
        Regul_07off_O(1); Regul_07off_S(1);
        if(RegRUN==OFF){ return; }
        // если регулятор в локальном режиме- выключить регулятор
        if(RegPublicV==OFF or REG07GL__V==OFF){
           Message(484,NOKV); Message(677,NOKV); Regul_07m(); REG07R___M=OFF;
        }; STEP07=0; /* STEP07v=30; */
        return;
    }
    //-----------------------------------------------------------------------



    // STEP07 > 40 - выгрузка


    //  ВЫГРУЗКА ИЗ ДОЗАТОРА МОКРОГО В ВГБМ
    //-----------------------------------------------------------------------
    //  проверка готовности ВГБМ:
    if (STEP07==51){
        if(STEP07P!=51){
           Clear_TO(71); Clear_TO(72);
        }; STEP07P =51;
        Regul_07off_O(1); Regul_07off_S(1);

        if (RegRUN==OFF){ return; }

        //  если ВГБМ не включена - звонок
        REG07SW__V=511;
        switch ( Check_TO  (71, 1*MIN, DISVGBMR_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(71); Message(386,NOKV); return;; }
        };  Clear_TO(71);

        //  если герметизатор не опущен - звонок
        REG07SW__V=512;
        switch ( Check_TO  (72, 1*MIN, DISVGBMG_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(72); Message(387,NOKV); return;; }
        }

        Clear_TO(71); Clear_TO(72);
        STEP07=52;
        return;
    }
    //-----------------------------------------------------------------------
    if (STEP07==52){
        if(STEP07P!=52){
        }; STEP07P =52;
        if (RegRUN==OFF){ return; }

        // если выгрузка воды в общем регуляторе - подождать его на этом шаге
        REG07SW__V=521;
        if (RegPublicV==ON and REG07GL__V==ON and STEP07v>0 and STEP07v<52) return;

        STEP07=53;
        return;
    }
    //-----------------------------------------------------------------------

    // ОТКРЫТИЕ КЛАПАНА ВЫГРУЗКИ в ВГБМ
    //-----------------------------------------------------------------------
    if (STEP07==53){
        if(STEP07P!=53){
           // если перед этим шагом набирали шлам- запомнить вес шлама
           if(AIW252FV_V>=14 and AIW252FV_V<=17){
              CRSLM____V=AIW252___V-AIW252NV_V;
           }
           if(STEP07P!=70){ Regul_07off_O(1); Regul_07off_S(1); }
        }; STEP07P =53;

        if (RegRUN==OFF){ return; }

        //  открыть клапан выгрузки в ВГБМ и клапан барботажа
        REG07SW__V =531;
        DON251H2_V = ON;
        DON251G2_V = ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251G2_V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(159,KVIT); DONCN07=0; return; }
                        Isp07PD(&DON251G2_V,3,TIME_ISPPW,70, STEP07P, 71); return;
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        MK_VG_KL_OPEN=0; 
        AIW252___O = AIW252___V;
        STEP07 = 54;
        return;
    }
    //-----------------------------------------------------------------------

    // ПРОВЕРКА ВЕСА ВЫГРУЗКИ дозатора мокрого
    //-----------------------------------------------------------------------
    if (STEP07== 54 ){
        if(STEP07P!=54){
           AIW252___O=AIW252___V;
           VSST_MKVIC=0;
           TMST_MKVIC=0;
           CNST_MKVIC=0;
        }; STEP07P =54;
        REG07SW__V =541;

        //  если текущий вес дозатора меньше или равен нулю- перейти на след шаг
        if (AIW252___V<=0 or CNST_MKVIC>=CNST_MKVIW){ STEP07=55; return; }

        if(RegRUN==OFF){ return; }

        //  если подошло время проверки стабилизации веса дозатора мокрого
        TMST_MKVIC++;
        if (TMST_MKVIC>TMST_MKVIW){
            //  если вес стабилизировался- увеличить счетчик стабилизац веса
            if (AIW252___V+VSST_MKVIW>AIW252___O){ CNST_MKVIC++; }
            else                                 { CNST_MKVIC=0; }
            AIW252___O=AIW252___V; TMST_MKVIC=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // ПЕРЕДЕРГИВАНИЕ КЛАПАНА ВЫГРУЗКИ
    //-----------------------------------------------------------------------
    // промывка бункера шлама
    if (STEP07== 55 ){
        if(STEP07P!=55){
           CNST_MKVIC=0;
        }; STEP07P =55;
        if (RegRUN==OFF){ return; }
        REG07SW__V =551;
        // после выгрузки дозатора мокрого (шлама) - ждать его промывки
        if(RegPublicV==ON and REG07GL__V==ON and STEP07v>0 and STEP07v<60) return;
        STEP07=60;
        return;
    }
    //-----------------------------------------------------------------------


    // ЗАКРЫТЬ КЛАПАН ВЫГРУЗКИ из дозатора мокрого в ВГБМ
    //-----------------------------------------------------------------------
    // Закрыть все клапана дозатора мокрого
    if (STEP07== 60 ){
        if(STEP07P!=60){
           ;;
        }; STEP07P =60;
        Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);
        if (RegRUN==OFF){ return; }

        REG07SW__V = 601;
        DON251G2_V = OFF;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251G2_V,'=',OFF, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(160,KVIT); DONCN07=0; return; }
                        Isp07PD(&DON251G2_V,3,TIME_ISPPW,70, STEP07P, 71); return;
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        //  если это конец выгрузки дозатора мокрого- сбросить флаг доз мокрого
        if (STEP07_BACK==0 or STEP07_BACK==30){ 
            DON211A1_V=2;
            //  если регулятор в локальном режиме- выключить его
            if (REG07GL__V==OFF){ 
                Message(485,NOKV); Message(677,NOKV); REG07R___M=OFF; 
            }
        }

        //  установить запомненный шаг текущим
        STEP07 = STEP07_BACK;
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
    //-----------------------------------------------------------------------
    if ( STEP07 ==70 ){
        if(STEP07P!=70){
           ;;
        }; STEP07P =70;
        if(DONCN07>=DONCH07){ STEP07 = STEP07_PRBK; return; }
        REG07SW__V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(207, DONTM07*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(207);
       *DONPR07=(*DONPR07!=ON)?ON:OFF;
        DONCN07++;
        STEP07 = STEP07_PRBK;
        return;
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
