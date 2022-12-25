//---------------------------------------------------------------------------
//  Подкачка шлама

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f  far *DONPR01;                 // текущий сигнал (комманда) выхода на исполн
_i  far  DONCN01=0;               // счетчик цикла передергивания
_i  far  DONCH01=2;               // заданное кол-во циклов для передергивания
_i  far  DONTM01=2;               // кол-во секунд вкл и паузы
_f  far  AILSL1=0;                // уровень в мешалке шлама
_f  far  DISKM1=0;                // сост клап в мешалку шлама
_f  far  DISKN1=0;                // сост клап шлама на насос
_f  far  DISNS1=0;                // сост насоса подачи шлама в мешалку
_i  far  AILFL1=0;                // флаг уровня в мешалке шлама
_f  far  DISVD1=0;                // сост клап воды на насос

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
//  В режиме [К] управлять исполнителями вручную нельзя
vd  far ModeKO_01(vd){
    if(REG01R___V==ON){
    DON211NV_M=0;
    DON211KA_M=0;
    DON211KB_M=0;
    DON211KC_M=0;
    DON213V__M=0;
    DON213A__M=0;
    DON213B__M=0;
    DON213C__M=0;
    DON064B__M=0;
    DON065B__M=0;
    DON064A__M=0;
    DON065A__M=0;
}   }
//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_01off(vd){
    DON211NV_V=0;
    DON211KA_V=0;
    DON211KB_V=0;
    DON211KC_V=0;
    DON213V__V=0;
    DON213A__V=0;
    DON213B__V=0;
    DON213C__V=0;
    DON064B__V=0;
    DON065B__V=0;
    DON064A__V=0;
    DON065A__V=0;
    return;
}
//---------------------------------------------------------------------------
//  управление исполнителями
vd  far Set_IS1(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, _f far i6, _f far i7, _f far i8){
    if (i1== ON) DON211NV_V= ON; else DON211NV_V=OFF;  // 211NV
    if (i2== ON) DON211KA_V= ON; else DON211KA_V=OFF;  // 211KA
    if (i3== ON) DON211KB_V= ON; else DON211KB_V=OFF;  // 211KB
    if (i4== ON) DON213V__V= ON; else DON213V__V=OFF;  // 213V
    if (i5== ON) DON213A__V= ON; else DON213A__V=OFF;  // 213A
    if (i6== ON) DON213B__V= ON; else DON213B__V=OFF;  // 213B
    if (i7== ON) DON064A__V= ON; else DON064A__V=OFF;  // 064A
    if (i8== ON) DON065B__V= ON; else DON065B__V=OFF;  // 064B
    return;
}
//---------------------------------------------------------------------------
vd  far Set_VR1(_f far KLNAS, _f far NASOS, _f far KLMES, _f far KLVOD, _f far SPEED){
    if(KLMES!=ASIS){
        // Если выбрана загрузка в бак шлама N2 (65)
        if(OBJS65___V>0){
            // определение клапана мешалки, учитывая с какого ШБ забираем
            if(OBJSB1___V>0||OBJSB2___V>0) DON065A__V=KLMES; else DON065B__V=KLMES;
        } else {
        // Если выбрана загрузка в бак шлама N1 (64)
            // определение клапана мешалки, учитывая с какого ШБ забираем
            if(OBJSB1___V>0||OBJSB2___V>0) DON064A__V=KLMES; else DON064B__V=KLMES;
    }   }
    // определение клапана ШБ и насоса, учитывая с какого ШБ забираем
    if(KLNAS !=ASIS){
        if(OBJSB1___V>0){ DON211KA_V=KLNAS; }
        if(OBJSB2___V>0){ DON211KB_V=KLNAS; }
        if(OBJSB3___V>0){ DON213A__V=KLNAS; }
        if(OBJSB4___V>0){ DON213B__V=KLNAS; }
    }
    if(NASOS !=ASIS){
        if(OBJSB1___V>0){ DON211NV_V=NASOS; }
        if(OBJSB2___V>0){ DON211NV_V=NASOS; }
        if(OBJSB3___V>0){ DON213V__V=NASOS; }
        if(OBJSB4___V>0){ DON213V__V=NASOS; }
    }
    if(SPEED !=ASIS){
        if(OBJSB1___V>0){ DON211W__V=SPEED; }
        if(OBJSB2___V>0){ DON211W__V=SPEED; }
        if(OBJSB3___V>0){ DON213W__V=SPEED; }
        if(OBJSB4___V>0){ DON213W__V=SPEED; }
    }
    if(KLVOD !=ASIS){
        if(OBJSB1___V>0||OBJSB2___V>0){ DON211KC_V=KLVOD; DON213C__V=OFF; }
        if(OBJSB3___V>0||OBJSB4___V>0){ DON213C__V=KLVOD; DON211KC_V=OFF; }
    }
    return;
}
//---------------------------------------------------------------------------
// Определение состояния исполнительных механизмов и уровня для регулятора
// в зависимости от выбранного ШБ и бака загрузки: AILSL1-уровень шлама в мешалке,
// DISKN1-клапан на насос, DISNS1-насос шлама, DISKM1-клапан в мешалку, DISVD1-клапан воды в насос
vd  far Get_VR1(vd){
    // Если выбрана загрузка в бак шлама N2 (65)
    if(OBJS65___V>0){
        AILSL1=AIL065A__V;
        // определение клапана мешалки, учитывая с какого ШБ забираем
        if(OBJSB1___V>0||OBJSB2___V>0) DISKM1=DIS065A__V; else DISKM1=DIS065B__V;
    } else {
    // Если выбрана загрузка в бак шлама N1 (64)
        AILSL1=AIL064A__V;
        // определение клапана мешалки, учитывая с какого ШБ забираем
        if(OBJSB1___V>0||OBJSB2___V>0) DISKM1=DIS064A__V; else DISKM1=DIS064B__V;
    }
    // определение клапана ШБ и насоса, учитывая с какого ШБ забираем
    if(OBJSB1___V>0){ DISKN1=DIS211KA_V; DISNS1=DIS211NV_V; DISVD1=DIS211KC_V; }
    if(OBJSB2___V>0){ DISKN1=DIS211KB_V; DISNS1=DIS211NV_V; DISVD1=DIS211KC_V; }
    if(OBJSB3___V>0){ DISKN1=DIS213A__V; DISNS1=DIS213V__V; DISVD1=DIS213C__V; }
    if(OBJSB4___V>0){ DISKN1=DIS213B__V; DISNS1=DIS213V__V; DISVD1=DIS213C__V; }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  Выполнение действий при выключеном регуляторе
vd  far Regul_01m(vd){
    //-----------------------------------------------------------------------
    if ( STEP01 == 101 ){
         REG01SW__V = 1001;
         if(RegRUN==OFF){ return; }
         switch ( Check_TO  (12, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
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
         Regul_01off();
         STEP01 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 == 102 ){
         STEP01P = 102;
         REG01SW__V = 1002;
         REG01R___M = OFF;
         AILFL1=0;
         STEP01_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP01=101;
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far Regul_01(vd){

    Get_VR1();

    //-----------------------------------------------------------------------
    //  включение-выключение регулятора
    if ( REG01RS__M == SWITCH ){ 
         REG01R___M = (REG01R___M==ON) then_ OFF else_ ON; REG01RS__M=OFF;
    }
    if ( REG01R___M != REG01R___V ){ 
         REG01R___M  =(REG01R___M==ON) then_ ON else_ OFF;
         REG01R___V  = REG01R___M;
         if(REG01R___V>0){ Message(320,NOKV); STEP01 = 0; return; }
         else            { Message(321,NOKV); STEP01 = 3; STEP01_BACK = 101; return; }
    }
    //  если все шламобассейны в режиме Наладка - выйти
    if (DIR211___V ==  1 and DIR213___V == 1){
        REG01SW__V = 107;
        Regul_01m(); return; 
    }
    //  контроль уровня мешалки шлама
    if(AILSL1<=OBJS6xL__W&&AILFL1==2&&STEP01>2){ STEP01=0; }
    if(AILSL1>=OBJS6xH__W&&AILFL1==1&&STEP01<3){ STEP01=3; }
    //-----------------------------------------------------------------------


    // ПРОВЕРКА УСЛОВИЙ включения регулятора
    //-----------------------------------------------------------------------
    if ( STEP01 ==0 ){
         if(STEP01P!=0){
            ;;
         }; STEP01P =0;
            AILFL1  =0;
         if(REG01R___V==0){ return; } 
         Regul_01off();
         if(RegRUN==OFF){ return; }
         REG01SW__V =1;
         if(AILSL1>=OBJS6xH__W){ STEP01= 3; }
         else                  { STEP01=10; }
         return;
    }
    //-----------------------------------------------------------------------


    // УСТАНОВКА НАЧАЛЬНОГО СОСТОЯНИЯ исполнителей регулятора
    //-----------------------------------------------------------------------
    if ( STEP01 ==10 ){
         if(STEP01P!=10){
            ;;
         }; STEP01P =10;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         REG01SW__V = 6;
         if(DISKM1==ON||DISKN1==ON||DISNS1==ON){ return; }
         STEP01 = 1;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Открытие клапана в мешалку
    if ( STEP01 ==1 ){
         if(STEP01P!=1){
            Clear_TO(11);
            Clear_TO(12);
         }; STEP01P =1;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         Set_VR1(OFF,OFF,ON,OFF,0);
         REG01SW__V = 11;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISKM1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(12); return; }
         }
         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    // Включение насоса и открытие клапана после насоса
    if ( STEP01 ==2 ){
         if(STEP01P!=2){
            Clear_TO(11);
            Clear_TO(12);
         }; STEP01P =2;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         Set_VR1(ASIS,ON,ON,OFF,0);
         REG01SW__V = 20;
         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISNS1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(11); return; }
         }
         Set_VR1(ON,ON,ON,OFF,0);
         REG01SW__V = 21;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISKN1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(12); return; }
         }
         REG01SW__V = 22;
         switch ( Check_TO  (13, TIME_ISPKV*SEC*4, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         Set_VR1(ON,ON,ON,OFF,1);
         Clear_TO(11);
         REG01SW__V = 23;
         AILFL1 = 1;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Выключение исполнителей
    if ( STEP01 ==3 ){
         if(STEP01P!=3){
            Clear_TO(11);
            Clear_TO(12);
            Clear_TO(13);
            REG01SW__V =30;
         }; STEP01P =3;
         if(RegRUN==OFF){ return; }
         // закрыть клапан шлама на насос
         REG01SW__V = 30;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISKN1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         // подождать некоторое время (8сек)
         REG01SW__V = 31;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (12, TIME_ISPKV*SEC*2, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         // открыть клапан воды в насос
         REG01SW__V = 32;
         Set_VR1(OFF,ON,ON,ON,0);
         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISVD1,'=',ON,  1 )){
             case RUN: { return; }
         }
         Set_VR1(OFF,ON,ON,ON,0);
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         STEP01=4;
         return;
    }
    //-----------------------------------------------------------------------
    // Выключение исполнителей
    if ( STEP01 ==4 ){
         if(STEP01P!=4){
            Clear_TO(11);
            Clear_TO(12);
            Clear_TO(13);
            Clear_TO(14);
            TMSL_VDP_C=0;
            REG01SW__V=40;
         }; STEP01P =4;
         if(RegRUN==OFF){ return; }
         // ждать время ожидания (время промывки)
         REG01SW__V = 41;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (11, TMSL_VDP_W*SEC, ZERO,'=',ON,  1 )){
             case RUN: { 
                         if(TMSL_VDP_C<TMSL_VDP_W) TMSL_VDP_C++; return;;
                       }
         }
         // закрыть клапан подачи воды на насос
         REG01SW__V = 42;
         Set_VR1(OFF,ASIS,ASIS,OFF,0);
         // выключить насос
         REG01SW__V = 43;
         Set_VR1(OFF,OFF,ASIS,OFF,0);
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISNS1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         // закрыть клапан в мешалку шлама
         REG01SW__V = 44;
         Set_VR1(OFF,OFF,OFF,OFF,0);
         switch ( Check_TO  (14, TIME_ISPKV*SEC, DISKM1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         //
         REG01SW__V = 45;
         if(STEP01_BACK==101){ AILFL1=0; STEP01=101; }
         else                { AILFL1=2; }
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
