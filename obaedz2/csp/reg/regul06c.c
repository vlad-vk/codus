// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------


#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"


_f far *DONPR06c;
_i far  DONCN06c=0;
_i far  DONCH06c=2;
_i far  DONTM06c=2;

_i far  FLVB_ONc=0;
_i far  IS06cERR=0;


//---------------------------------------------------------------------------
vd  Isp06cPD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR06c= IOPNT;
    DONCH06c= hM;
    DONTM06c= hS;
    STEP06c = Step;
    STEP06c_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far ModeKO_06c(vd){
    if(REG06cR__V==ON){
    DON221C__M =  OFF; // вибратор бунк
    DON2293__M =  OFF; // клапан
    DON228C__M =  OFF; // шнек 
    DON2294__M =  OFF; // клапан
    //
    DON221D__M =  OFF; // вибратор бунк
    DON229D1_M =  OFF; // клапан
    DON228D__M =  OFF; // шнек
    DON229D2_M =  OFF; // клапан
    //
    DON221F__M =  OFF; // вибратор ДЦ
    DON280S__M =  OFF; // вентилятор
    DON220F__M =  OFF; // клапан выгрузки ДЦ
}   }
//---------------------------------------------------------------------------
vd  far Regul_06c_off(vd){
    DON221C__V =  OFF; //
    DON2293__V =  OFF; // 
    DON228C__V =  OFF; //
    DON2294__V =  OFF; //
    //
    DON221D__V =  OFF; //
    DON229D1_V =  OFF; // 
    DON228D__V =  OFF; //
    DON229D2_V =  OFF; //
    //
    DON221F__V =  OFF; // вибратор выгрузки ДЦ
    DON280S__V =  OFF; // вентилятор выгрузки
    DON220F__V =  OFF; // клапан выгрузки ДЦ
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Regul_06_Save(vd){
    if(STEP06c==70) STEP06c_SV=STEP06c_PRBK; else STEP06c_SV=STEP06c;
    if(STEP06v==70) STEP06v_SV=STEP06v_PRBK; else STEP06v_SV=STEP06v;
}
//---------------------------------------------------------------------------
vd  far Regul_06_Rest(vd){
    STEP06c=STEP06c_SV;
    STEP06v=STEP06v_SV;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

vd  far Regul_06c_manual(vd){
    //-----------------------------------------------------------------------
    if ( STEP06c == 101 ){
         REG06cSW_V=1001;
         if(RegRUN==OFF){ return; }
         Regul_06c_off();
         FLAG_0605A_c=OFF;
         FLAG_05WTA_c=OFF;
         STEP06c = 102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP06c == 102 ){
         STEP06cP = 102;
         REG06cSW_V=1002;
         REG06cR__M=OFF;
         AIW218FV_V=0;
         return;
    }
    //-----------------------------------------------------------------------
    SetPubCycStat(SUHOE,0);
    STEP06c=101;
    return;
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_06c(vd){

    ex vd far Regul_06v_manual(vd);
    ex vd far Regul_06v_off(vd);

    //----------------------------------
    //  передача значения контроля ВГБМ для загрузки ДС    
    if( CRVGBM___M>0){
        if(CRVGBM___V>0 && CRVGBM___M>0){ CRVGBM___V=0; Message(363,NOKV); CRVGBM___M=0; }
        if(CRVGBM___V<1 && CRVGBM___M>0){ CRVGBM___V=1; Message(362,NOKV); CRVGBM___M=0; }
        CRVGBM___M=0;
    }


    //----------------------------------
    //  включение-выключение регулятора
    if ( REG06cRS_M == SWITCH ){
         REG06cR__M = (REG06cR__M==ON) then_ OFF else_ ON; REG06cRS_M=OFF;
    }
    if ( REG06cR__M != REG06cR__V ){
         REG06cR__M  =(REG06cR__M==ON) then_ ON else_ OFF;
         REG06cR__V  = REG06cR__M;
         if ( REG06cR__V == ON ){ 
            Message(370,NOKV); STEP06c=0; STEP06v=0;
            // если включен общий регулятор и регулятор в работе - восстановить состояние регулятора
            if (RegPublicV==ON and REG06cGL_V==ON and STEP06c_SV>1){ 
                Regul_06_Rest(); Message(238,NOKV); return;
            }
        } else {
            // если включен общий регулятор и регулятор в работе - записать состояние регулятора
            if (RegPublicV==ON and REG06cGL_V==ON and STEP06c>1 and STEP06c<70){ 
                Regul_06_Save(); Message(237,NOKV);
            }
            Message(371,NOKV); Regul_06c_off(); STEP06c=101; STEP06v=101;
        }
    }
    // при выключении общего регулятора сбрасываются значения записанного шага
    if (RegPublicV==OFF or REG06cGL_V==OFF){ STEP06c_SV=0; STEP06v_SV=0; }
    
    //----------------------------------
    //  загрузка-выгрузка
     if (REG06cZV_M != REG06cZV_V ){
         REG06cZV_M  =(REG06cZV_M>=ON) then_ ON else_ OFF;
         REG06cZV_V  = REG06cZV_M;
         if(REG06cZV_V>0){ Message(372,NOKV); } // загрузка
         else            { Message(373,NOKV); } // выгрузка
    }
    
    
    //----------------------------------
    //  общий-локальный
    if ( REG06cGL_M != REG06cGL_V ){
         REG06cGL_M  =(REG06cGL_M==ON) then_ ON else_ OFF;
         REG06cGL_V  = REG06cGL_M;
         if(REG06cGL_V>0){ Message(374,NOKV); } // общий
         else            { Message(375,NOKV); } // локальный
    }

    
    //----------------------------------
    // если регулятор выключен - выйти
    if ( REG06cR__V == OFF && REG06cGL_V == OFF ){ Regul_06c_manual(); Regul_06v_manual(); return; }


    //----------------------------------
    // если во время выгрузки сухого поднялся герметизатор
    if (STEP06c>=32 and STEP06c<=33 and DISVGBMG_V==OFF){ Bell(1,1); Message(115,NOKV); return; }

    //--------------------------------------------------------------------------




    //--------------------------------------------------------------------------
    //
    //  ОПРЕДЕЛЕНИЕ СОСТОЯНИЯ РЕГУЛЯТОРА
    //
    //--------------------------------------------------------------------------

    if ( STEP06c == 0 ){

        if(STEP06cP!=0){
           ;;
        }; STEP06cP =0;
        if (RegRUN==OFF){ return; }

        Regul_06c_off();
        Regul_06v_off();

        // статус сухого в общем регуляторе
        SetPubCycStat(SUHOE,0);

        //-------------------------------
        //  ключ дозатора сухого (если в режиме наладки(=1)- выйти)

        REG06cSW_V =2;
        if(DIR216___V==1){ return; }

        //-------------------------------
        //  ЗАГРУЗКА :        
        REG06cSW_V =9;

        //  регулятор включен на загрузку для ЛОКАЛЬНОЙ работы
        if( REG06cZV_V == ON and REG06cGL_V == OFF){
            if(CRVGBM___V>0){
               // проверка включения ротора ВГБМ
               if(DISVGBMR_V==ON){ return; }
               // проверка герметизатора
               if(DISVGBMG_V==ON){ return; }
            }
            DON211B1_V=0;
            STEP06c = 1;
            STEP06v = 7;
        }

        //  регулятор включен для ОБЩЕЙ работы и дозатор сухого выгружен и
        //  и у оператора нажата кнопка для загрузки
        if( RegPublicV == ON  and REG06cGL_V == ON and (DON211B1_V==0 or DON211B1_V==2) and 
            DIS211S__V == 1){
//          DIS211S__V == 1 and DON211C1_V == 0){
            if(CRVGBM___V>0){
               if(DISVGBMR_V==ON){ return; }
               if(DISVGBMG_V==ON){ return; }
            }
            STEP06c = 1;
            STEP06v = 7;
        }
        //-------------------------------



        //-------------------------------
        //  ВЫГРУЗКА общая
        //  Если дозатор сухого загружен и дозатор мокрого выгружен
        //  и включен общий регулятор и -  перейти на шаг выгрузки
        if( DON211A1_V==2 and AIW218___V>100 and RegPublicV==ON and REG06cGL_V==ON ){
            STEP06c=31;
            STEP06v=31;
        }
        //-------------------------------
        //  ВЫГРУЗКА локальная
        //  Если включен локальный регулятор и включена выгрузка
        //  и дозатор мокрого выгружен или регулятор 07 выключен -
        //  перейти на шаг выгрузки
        if( REG06cGL_V==OFF and REG06cZV_V==OFF and ( DON211A1_V==2 or REG07R___V==OFF )){
            STEP06c=31;
            STEP06v=31;
        }
        //-------------------------------


        Clear_TO(61);

        if(STEP06c==1){
           CRCEMS___V=0;
           AIW218FV_V=0;
           AIW218NV_V=AIW218___V;
        }
        return;
    }
    //-----------------------------------------------------------------------






   //------------------------------------------------------------------------
   if ( STEP06c == 1 ){
       if(STEP06cP!=1){ Regul_06c_off(); }
       STEP06cP=1;


       STEP06c=2;
       return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // НАБОР ЦЕМЕНТА 1

   //------------------------------------------------------------------------
   // Проверки перед включением регулятора (исполнителей)
   if ( STEP06c == 2){
        if(STEP06cP!=2){ Regul_06c_off(); }
        STEP06cP=2;
        if(RegRUN==OFF){ return; }
        //
        AIW218VO_V=TRCM1B_VIB-LOAD_C1GRW;
        AIW218VZ_V=TRCM1B_VIB;

        // Если ключ режима в положении НАЛАДКА (1) - выйти, 
        // в положении ПРОЦЕСС (0) - работает программа
        REG06cSW_V = 200;
        if (DIR216___V==1){ STEP06c=3; return; }

        // Если вес бункера цемента больше задания набора цемента- 
        // перейти на набор вяжущих
        REG06cSW_V = 201;
        if (AIW218___V>=AIW218VZ_V){ STEP06c=3; return; }

        // Если открыт клапан выгрузки из дозатора сухого- выйти
        REG06cSW_V = 202;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS220F__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(61); Message(638,NOKV); Bell(1,1); return;; }
        }
        
        STEP06c=21;
        return;
   }
   //------------------------------------------------------------------------
   // Включение исполнителей
   if ( STEP06c == 21){
        if(STEP06cP!=21){
        Clear_TO(61); Clear_TO(62); Clear_TO(63); Clear_TO(64); Clear_TO(65);
        }
        STEP06cP=21;
        if(RegRUN==OFF){ return; }


        // Открыть клапан после шнека цемента
        REG06cSW_V = 211;
        DON2294__V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS2294__V,'=',ON,  1 )){
/*1*/       case RUN: { return; }
/*3*/       case NOS: { return; }
/*0*/       case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;
                        }; Isp06cPD(&DON2294__V,3,TIME_ISPPW,70, STEP06c,61); return;
                      }
/*2*/       case END: { DONCN06c=0; break; }
        }
        // Время ожидания включения
        switch ( Check_TO  (62, TMISPCEM_W*SEC, ZERO,'=',ON, 1 )){ case RUN: { return; } }


        // Включить шнек
        REG06cSW_V = 212;
        DON228C__V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS228C__V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;;
                        }; Isp06cPD(&DON228C__V,2,TIME_ISPPW,70, STEP06c,63); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }
        // Время ожидания включения
        switch ( Check_TO  (64, TMISPCEM_W*SEC, ZERO,'=',ON, 1 )){ case RUN: { return; } }


        // Открыть клапан на шнек
        REG06cSW_V = 213;
        DON2293__V = ON;
        switch ( Check_TO  (65, TIME_ISPKV*SEC, DIS2293__V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;;
                        }; Isp06cPD(&DON2293__V,3,TIME_ISPPW,70, STEP06c,65); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }

        Clear_TO(61); Clear_TO(62); Clear_TO(63); Clear_TO(64); Clear_TO(65);

        // статус сухого в общем регуляторе
        SetPubCycStat(SUHOE,1);

        STEP06c=22;
        return;
   }
   //------------------------------------------------------------------------
   // Набор цемента, проверка веса набора
   if ( STEP06c == 22){
        if(STEP06cP!=22){
           AIW218___O=AIW218___V;   // Перед началом набора запомнить вес бункера цемента
           AIW218___C=0;            // Обнулить счетчики
           TMVB_CB1_C=0;            // 
           TIME_VC1OC=0;            // 
           FLVB_ONc=0;              // Обнулить флаг
        }; STEP06cP=22;

        REG06cSW_V=221;
        CNST_CB__C=0;
        //
        AIW218VO_V=TRCM1B_VIB-LOAD_C1GRW;
        AIW218VZ_V=TRCM1B_VIB;

        // Клапан перед шнеком цемента
        if( AIW218___V>=AIW218VZ_V-VSOTSCEM1W ){
            DON2293__V=OFF;
        }
        
        // Проверка набора веса
        if( AIW218___V>=TRCM1B_VIB-LOAD_C1GRW ){
            AIW218VO_V =TRCM1B_VIB-VSOT_SSC1W;
            DON2293__V=OFF;
            DON2294__V=OFF;
            DON228C__V=OFF;
            STEP06c=23; return;
        }

        //-------------------------------------------------------------------
        // Включение-выключение вибратора
        if (RegRUN==ON){

            if(FLVB_ONc>0){
                TIME_VC1OC++;
                if(TIME_VC1OC>=TIME_VC1OW){
                   DON221C__V=OFF; FLVB_ONc=0; TIME_VC1OC=0;
                }; TMVB_CB1_C=0;
            }
            VSVB_CB__C=AIW218___V-AIW218___O;

            TMVB_CB1_C++;
            if (TMVB_CB1_C>=TMVB_CB1_W){
                if(AIW218___O+VSVB_CB__W>AIW218___V){
                   DON221C__V=ON; FLVB_ONc=1; TIME_VC1OC=0;
                   REG06cSW_V=222;
                 }
                 TMVB_CB1_C=0;
                 AIW218___O=AIW218___V;
            }
        }
        //-------------------------------------------------------------------
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   // Выключение исполнителей
   if ( STEP06c == 23){
        if(STEP06cP!=23){ 
           Clear_TO(61);
           TMST_CBV_C=0;
           IS06cERR=0;
           AIW218___C=0;
        }; STEP06cP=23;
        Regul_06c_off();
        if(RegRUN==OFF){ return; }

        AIW218___O=AIW218___V;

        REG06cSW_V=231;
        DON2293__V=OFF;
        DON2294__V=OFF;
        DON228C__V=OFF;

        REG06cSW_V = 232;
        switch ( Check_TO  (61, TMST_CBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_CBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);

        STEP06c=3;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // НАБОР ЦЕМЕНТА 2

   //------------------------------------------------------------------------
   if ( STEP06c == 3 ){
        if(STEP06cP!=3){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06c_off();
        }; STEP06cP =3;
        if(RegRUN==OFF){ return; }
        //
        AIW218VO_V=TRCM1S_VIB-LOAD_CCGRW;
        AIW218VZ_V=TRCM1S_VIB;

        REG06cSW_V = 30;
        // Если ключ режима в положении НАЛАДКА (1) - выйти, 
        // в положении ПРОЦЕСС (0) - работает программа
        if (DIR216___V==1){ STEP06c=6; return; }

        // Если вес бункера цемента больше задания набора цемента- 
        // перейти на набор вяжущих
        if (AIW218___V>=AIW218VZ_V){ STEP06c=6; return; }
        
        // Если открыт клапан выгрузки из дозатора сухого- выйти
        REG06cSW_V = 31;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS220F__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(61); Message(638,NOKV); Bell(1,1); return;; }
        }

        Clear_TO(61);
        STEP06c = 4;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   if ( STEP06c == 4 ){
        if(STEP06cP!=4){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
        }; STEP06cP =4;
        if(RegRUN==OFF){ return; }

        // Открыть клапан после шнека цемента
        REG06cSW_V = 41;
        DON229D2_V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS229D2_V,'=',ON,  1 )){
/*1*/       case RUN: { return; }
/*3*/       case NOS: { return; }
/*0*/       case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;
                        }; Isp06cPD(&DON229D2_V,3,TIME_ISPPW,70, STEP06c,61); return;
                      }
/*2*/       case END: { DONCN06c=0; break; }
        }
        // Время ожидания включения
        REG06cSW_V = 42;
        switch ( Check_TO  (62, TMISPCEM_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { return; }
        }
        // Включить шнек
        DON228D__V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS228D__V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;;
                        }; Isp06cPD(&DON228D__V,2,TIME_ISPPW,70, STEP06c,63); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }
        // Время ожидания включения
        REG06cSW_V = 43;
        switch ( Check_TO  (64, TMISPCEM_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { return; }
        }
        // Открыть клапан на шнек
        DON229D1_V = ON;
        switch ( Check_TO  (65, TIME_ISPKV*SEC, DIS229D1_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>2){
                           Message(670,KVIT); DONCN06c=0; return;;
                        }; Isp06cPD(&DON229D1_V,3,TIME_ISPPW,70, STEP06c,65); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }

        Clear_TO(61); Clear_TO(62); Clear_TO(63); Clear_TO(64); Clear_TO(65);
        
        // статус сухого в общем регуляторе
        SetPubCycStat(SUHOE,2);
        
        STEP06c = 5;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // Набор цемента, проверка веса набора
   if ( STEP06c == 5 ){
        if(STEP06cP!=5){
           AIW218___O=AIW218___V;
           AIW218___C=0;
           TMVB_CB__C=0;
           TIME_VCONC=0;
           FLVB_ONc=0;
        }; STEP06cP=5;
        REG06cSW_V=50;
        CNST_CB__C=0;
        //
        AIW218VO_V=TRCM1S_VIB-LOAD_CCGRW;
        AIW218VZ_V=TRCM1S_VIB;

        if( AIW218___V>=AIW218VZ_V-VSOTSCEM_W ){
                DON229D1_V=OFF;
        }
        if( AIW218___V>=TRCM1S_VIB-LOAD_CCGRW ){
            AIW218VO_V =TRCM1S_VIB-VSOT_SSC_W;
            DON229D1_V=OFF;
            DON229D2_V=OFF;
            DON228D__V=OFF;
            STEP06c=51; return;
        }
        AIW218FV_V=5;

        //-------------------------------------------------------------------
        if (RegRUN==ON){
            if(FLVB_ONc>0){
                TIME_VCONC++;
                if(TIME_VCONC>=TIME_VCONW){
                   DON221D__V=OFF; FLVB_ONc=0; TIME_VCONC=0;
                }; TMVB_CB__C=0;
            }
            VSVB_CB__C=AIW218___V-AIW218___O;

            TMVB_CB__C++;
            if (TMVB_CB__C>= TMVB_CB__W){
                if(AIW218___O+VSVB_CB__W>AIW218___V){
                   DON221D__V=ON;; FLVB_ONc=1; TIME_VCONC=0;
                   AIW218___C++;
                   REG06cSW_V = 51;
                 } else {
                    AIW218___C=0;
                 }
                 TMVB_CB__C=0;
                 AIW218___O=AIW218___V;
            }
        }
        //-------------------------------------------------------------------

        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // Выключение исполнителей
   if ( STEP06c == 51 ){
        if(STEP06cP!=51){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           TMST_CBV_C=0;
           IS06cERR=0;
           AIW218___C=0;
        }; STEP06cP =51;
        if(RegRUN==OFF){ return; }
        Regul_06c_off();

        REG06cSW_V = 52;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS229D1_V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>1){ IS06cERR=4; DONCN06c=0; break;; }
                        Isp06cPD(&DON229D1_V,3,TIME_ISPPW,70, 51, 61); return;
                      }
            case END: { DONCN06c=0; break;; }
        }

        switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS229D2_V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>1){ IS06cERR=3; DONCN06c=0; break;; }
                        Isp06cPD(&DON229D2_V,3,TIME_ISPPW,70, 51, 62); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }

        switch ( Check_TO  (63, TIME_ISPKV*SEC, DIS228D__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>1){ IS06cERR=2; DONCN06c=0; break;; }
                        Isp06cPD(&DON228D__V,3,TIME_ISPPW,70, 51, 63); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }

        switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS220F__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06c>1){ IS06cERR=1; DONCN06c=0; break;; }
                        Isp06cPD(&DON220F__V,3,TIME_ISPPW,70, 51, 64); return;;
                      }
            case END: { DONCN06c=0; break;; }
        }

        AIW218___O=AIW218___V;
        REG06cSW_V = 53;
        switch ( Check_TO  (65, TMST_CBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_CBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);

        if(AIW218___C>1){
           AIW218___C=0; REG06cR__M=OFF; Message(141,NOKV); Message(676,NOKV); Bell(1,1);
           return;
        }
        if(IS06cERR   >0){ AIW218___C++; return; }

        if(CNST_CB__C>=CNST_CB__W){
           STEP06c=0; REG06cR__M=OFF; Message(144,NOKV); Message(676,NOKV); Bell(1,1);
           return;
        }

        if(AIW218___V+VSST_CB__W<AIW218___O){
           STEP06cP=5; STEP06c=51; CNST_CB__C++; return;
        } else {
           CNST_CB__C=0;
        }

        if (AIW218___V>=TRCM1S_VIB-7){ STEP06c=6; return; }

        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   if ( STEP06c == 6 ){
        if(STEP06cP!=6){
           TIME_CVPSC=0;
           Clear_TO(61);
        }; STEP06cP =6;
        if (RegRUN==OFF){ return; }
        Regul_06c_off();

        REG06cSW_V = 60;
        switch ( Check_TO  (61, TIME_CVPSW*SEC, ZERO,'=',ON,  1 )){
            case RUN: { TIME_CVPSC++; return;; }
        };  Clear_TO(61);

        STEP06c = 15;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // ВЫКЛЮЧЕНИЕ РЕГУЛЯТОРА
   if ( STEP06c == 15 ){
        if(STEP06cP!=15){
        }; STEP06cP =15;
        AIW218VO_V =0;
        // Если еще не закончен набор вяжущих - ждать...
        if (STEP06v<15) return;
        // Выключение регулятора для локального режима
        if (REG06cGL_V==OFF){ Message(486,NOKV); Message(676,NOKV); REG06cR__M=OFF; }
        // или переход на шаг N0 для общего
        STEP06c=0;
        STEP06v=0;
        return;
   }
   //------------------------------------------------------------------------




   //------------------------------------------------------------------------
   //  ВЫГРУЗКА
   if ( STEP06c == 31 ){
        if(STEP06cP!=31){
           Regul_06c_off();
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           Clear_TO(66);
        }; STEP06cP =31;
        if(RegRUN==OFF){ return; }
        AIW218PVZV =AIW218___V;

        REG06cSW_V =312;
        switch ( Check_TO  (62, 1*MIN, DISVGBMR_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(62); Message(386,KVIT); Bell(1,1); return;; }
        }

        REG06cSW_V =313;
        switch ( Check_TO  (63, 1*MIN, DISVGBMG_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(63); Message(387,KVIT); Bell(1,1); return;; }
        }

        REG06cSW_V= 315;
        DON280S__V= ON;
        switch ( Check_TO  (65, TIME_ISPKV*SEC, DIS280S__V,'=',ON, 1 )){
            case RUN: { return;; }
        }

        REG06cSW_V= 316;
        DON220F__V= ON;
        switch ( Check_TO  (66, TIME_ISPKV*SEC, DIS220F__V,'=',ON, 1 )){
            case RUN: { return;; }
        }

        DON221F__V= ON;
        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);
        Clear_TO(66);

        CNT_VIGRUZ_S=0;

        STEP06c =  32;
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   if ( STEP06c == 32 ){
        if(STEP06cP!=32){
           Clear_TO(61);
           AIW218___O=AIW218___V;
           AIW218___S=AIW218___V;
           AIW218___C=0;
           TIME_PONVC=0;
        }; STEP06cP =32;
        REG06cSW_V =320;

        if(AIW218___O-AIW218___V>=LOAD_SVPVW){
           DON221F__V=OFF; DON220F__V=OFF;
        }

        AIW218VO_V =AIW218PVZV-TRCM1S_VIB;
        if(AIW218VO_V > AIW218___V && AIW218___V < 5 ){
           DON221F__V=OFF;
           DON220F__V=OFF;
           Message(302,NOKV);
           STEP06c=33;
           return;
        }

        LOAD_SVPVC=AIW218___O-AIW218___V;

        if(RegRUN==OFF){ return; }

        if(DIS220F__V==OFF||DON220F__V==OFF){
           DON221F__V =OFF;
           TIME_PONVC++; if(TIME_PONVC>10000){ TIME_PONVC=0; }
           switch ( Check_TO  (61, TIME_PONVW*SEC, ZERO,'=',ON, 1 )){
               case RUN: { return; }
           };  Clear_TO(61);
           TIME_PONVC=0;
           AIW218___O = AIW218___V;
           DON221F__V = ON;
           DON220F__V = ON;
        }

        TMST_VIS_C++;
        if (TMST_VIS_C>= TMST_VIS_W){
            if(AIW218___V+VSST_VIS_W>AIW218___O){
               AIW218___C++; DON220F__V=ON; DON221F__V=ON;
            } else {
               AIW218___C=0;
            }
            TMST_VIS_C=0;
            AIW218___O=AIW218___V;
        }

        if(AIW218___V<10&&AIW218___C>1){
           if(AIW218___C>2){
              DON221F__V=OFF;
              DON220F__V=OFF;
              STEP06c=33;
              return;
           }
        }
        return;
   }
   //------------------------------------------------------------------------
   if ( STEP06c == 33 ){
        if(STEP06cP!=33){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06c_off(); TIME_SHVVC=0;
           TMST_VIS_C=0;
        }; STEP06cP =33;
        if(RegRUN==OFF){ return; }
        REG06cSW_V =331;

        // статус сухого в общем регуляторе
        DON211B1_V=2; SetPubCycStat(SUHOE,3);

        switch ( Check_TO  (62, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
            case BAD: { AIW218___O=AIW218___V; break;; }
        }

        if(AIW218___V+VSST_VIS_W<AIW218___O){ Message(304,KVIT); }

        REG06cSW_V =332;
        switch ( Check_TO  (63, TIME_SHVVW*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TIME_SHVVC++; return;; }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Regul_06c_off();

        STEP06c=34;
        return;
   }
   //------------------------------------------------------------------------
   if ( STEP06c == 34 ){
        if(STEP06cP!=34){
        }; STEP06cP =34;
        if(RegRUN==OFF){ return; }
        if(STEP06v!=34){ return; }
        // Если включен локальный регулятор
        if(REG06cGL_V==OFF){
           Message(487,NOKV); Message(676,NOKV); REG06cR__M=OFF;
        }
        STEP06c=0;
   }
   //-----------------------------------------------------------------------
   
   
   
   //-----------------------------------------------------------------------
   if ( STEP06c ==70 ){
        if(STEP06cP!=70){
           ;;
        }; STEP06cP =70;
        if(DONCN06c>=DONCH06c){ STEP06c = STEP06c_PRBK; return; }
        REG06cSW_V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(206, DONTM06c*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(206);
       *DONPR06c=(*DONPR06c!=ON)?ON:OFF;
        DONCN06c++;
        STEP06c = STEP06c_PRBK;
        return;
   }
   //-----------------------------------------------------------------------


   return;
}
//---------------------------------------------------------------------------
