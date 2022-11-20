// coding=cp866; version=2013013112; title="";
//----------------------------------------------------------------------------
// Общие функции регуляторов

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

vd  far UchetCMP(vd);
_f  far TEMPS=0;
_f  far TEMPO=0;
_f  far TEMPP=0;

//----------------------------------------------------------------------------
vd  far Regul_up(vd){
    _f  temp=0;
    _f  Ps=0, Po=0, Valum=0;
  
    // Установка флага новой смены
    if((houC==8 or houC==20) and minC==0 and secC==1){
        if(NewSmena==0){ NewSmena=1; }
    } else {
        NewSmena=0;
    }
    // Установка флага нового месяца
    if(dayC==1 and houC==8 and minC==0 and secC==1){
        if(NewMonth==0){ NewMonth=1; }
    } else {
        NewMonth=0;
    }
  
    //-----------------------------------------------------------------------
    // Включение- выключение общего регулятора
    if ( RegPublicM != RegPublicV ){ 
         RegPublicM  =(RegPublicM==ON) then_ ON else_ OFF;
         RegPublicV  = RegPublicM;
         // общий регул включен
         if(RegPublicV==ON){
              Message(89,NOKV); DON211A1_V=0; DON211B1_V=0; DON211C1_V=0; PubCycStat=1;
         // общий регул выключен
         } else { 
              Message(90,NOKV); DON211A1_V=0; DON211B1_V=0; DON211C1_V=0; PubCycStat=0;
         }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Передача и определение значений времени сработки для типов исполнителей
    // время сработки пневмо клапанов
    TIME_ISPKV = TIME_ISPKM;
    if ( TIME_ISPKV < 1 ){ TIME_ISPKV = 2; }
    // время сработки насосов
    TIME_ISNSV = TIME_ISNSM;
    if ( TIME_ISNSV < 1 ){ TIME_ISNSV = 3; }
    // время сработки приводов
    TIME_ISPRV = TIME_ISPRM;
    if ( TIME_ISPRV < 1 ){ TIME_ISPRV = 3; }
    // время сработки вибраторов
    TIME_ISVBV = TIME_ISVBM;
    if ( TIME_ISVBV < 1 ){ TIME_ISVBV = 3; }
    // время стабилизации уровней
    TIME_LSTBV = TIME_LSTBM;
    if ( TIME_LSTBV < 1 ){ TIME_LSTBV = 4; }
    //------------------------------------------------------------------------

    //------------------------------------------------------------------------
    // Подсчет веса дозаторов и счетчиков загрузок (дозировок)
    UchetCMP();

    //------------------------------------------------------------------------
    // Сброс веса ДС (вызывается каждый тик. 10,20,30,40- кол-во тиков)
    // После нажатия на кнопку "НОЛЬ" - 10сек она не активна (DxCEnab)
    if ( DSCEnab>10){
        if ( DONDS1K__M==1  ){ DSWZero=1; DSCZero=0; DONDS1K__M=0; DONDS1K__V=1; DSCEnab=0; }
    };  if ( DSCEnab<20 && RegRUN>0 ) DSCEnab++;
        if ( DSWZero   ==1  ){ DSCZero++; }
        if ( DSCZero   ==10 ){ DONDS1K__V=0; }
        if ( DSCZero   ==20 ){ DONDS1K__V=1; }
        if ( DSCZero   ==30 ){ DONDS1K__V=0; DONDS2K__V=1; }
        if ( DSCZero   ==40 ){ DONDS2K__V=0; DSWZero=0; DSCZero=0; 
                               AIW218_SZV=AIW218_SZV-AIW218___V; AIW218_SZM=AIW218_SZV; }
    // Сброс веса ДМ
    if ( DMCEnab>10){
        if ( DONDM1K__M==1  ){ DMWZero=1; DMCZero=0; DONDM1K__M=0; DONDM1K__V=1; DMCEnab=0; }
    };  if ( DMCEnab<20 && RegRUN>0 ) DMCEnab++;
        if ( DMWZero   ==1  ){ DMCZero++; }
        if ( DMCZero   ==10 ){ DONDM1K__V=0; }
        if ( DMCZero   ==20 ){ DONDM1K__V=1; }
        if ( DMCZero   ==30 ){ DONDM1K__V=0; DONDM2K__V=1; }
        if ( DMCZero   ==40 ){ DONDM2K__V=0; DMWZero=0; DMCZero=0; 
                               AIW252_SZV=AIW252_SZV-AIW252___V; AIW252_SZM=AIW252_SZV; }
    // Сброс веса ДП
    if ( DPCEnab>10){
        if ( DONDP1K__M==1  ){ DPWZero=1; DPCZero=0; DONDP1K__M=0; DONDP1K__V=1; DPCEnab=0; }
    };  if ( DPCEnab<20 && RegRUN>0 ) DPCEnab++;
        if ( DPWZero   ==1  ){ DPCZero++; }
        if ( DPCZero   ==10 ){ DONDP1K__V=0; }
        if ( DPCZero   ==20 ){ DONDP1K__V=1; }
        if ( DPCZero   ==30 ){ DONDP1K__V=0; DONDP2K__V=1; }
        if ( DPCZero   ==40 ){ DONDP2K__V=0; DPWZero=0; DPCZero=0; 
                               AIW216_SZV=AIW216_SZV-AIW216___V; AIW216_SZM=AIW216_SZV; }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Расчет температуры и количества набираемой воды
    KQ_ON____V=KQ_ON____M;
    AITSM____V=AITSM____M;
    AIQSK____V=AIQSK____M;
    AIQSH____V=AIQSH____M;
    AIQOT____V=AIQOT____M;
    AIQPS____V=AIQPS____M;
    AIQVD____V=AIQVD____M;
    KF_KT____V=KF_KT____M;
    KF_k_____V=KF_k_____M;
    KF_L_____V=KF_L_____M;
    KF_T_____V=KF_T_____M;
    // общий заданный вес загружаемой смеси
    AIWALL___V=TRSLM__VIB+TROTH__VIB+TRCM1S_VIB+TRVYGS_VIB+TRPAS__VIB+TRVODD_VIB;
    if(AIWALL___V==0) AIWALL___V=1;
    // общая теплоемкость смеси
    AIQSM____V=(AIQSK____V*(TRCM1S_VIB+TRVYGS_VIB) + AIQSH____V*TRSLM__VIB + AIQOT____V*TROTH__VIB +
                AIQPS____V* TRPAS__VIB             + AIQVD____V*TRVODD_VIB)/ AIWALL___V;
    // расчетная температура воды
    temp=AIQVD____V*TRVODD_VIB;
    if(temp==0) temp=1;
    // температуры от выбранных емкостей
    if(OBJM64___V>0) TEMPS=AIT064___V; else TEMPS=AIT065___V;   // шлам
    if(OBJM56___V>0) TEMPO=AIT056___V; else TEMPO=AIT057___V;   // об шлам
    if(OBJAS1___V>0) TEMPP=AIT068___V; else TEMPP=AIT069___V;   // ал сусп
    //
    AITRAS___V= AITSM____V+ 
               (AIQSK____V*TRCM1S_VIB * (AITSM____V-AIT233___V)+ 
                AIQSK____V*TRVYGS_VIB * (AITSM____V-AIT231___V)+
                AIQSH____V*TRSLM__VIB * (AITSM____V-TEMPS)+ 
                AIQOT____V*TROTH__VIB * (AITSM____V-TEMPO)+ 
                AIQPS____V*TRPAS__VIB * (AITSM____V-TEMPP))/ temp + KF_KT____V;
    // количество горячей воды
    temp=AIT092___V-AIT091___V;
    if(temp==0) temp=1;
    AIWVDG___V=(TRVODD_VIB*(AITRAS___V-AIT091___V))/temp;
    if(AIWVDG___V>TRVODD_VIB) AIWVDG___V=TRVODD_VIB;
    if(AIWVDG___V<         0) AIWVDG___V=0;
    // если задание количества набора горячей воды установлено оператором, 
    // определяем набор горячей воды по этому заданию
    AIWVDGM__V=AIWVDGM__M;
    if(AIWVDGM__V>0.1) AIWVDG___V=AIWVDGM__V;
    // количество холодной воды
    AIWVDH___V=TRVODD_VIB-AIWVDG___V;
    //--------
    // выбор очередности загрузки хол-гор воды
    if(AIWVDGQ__M>0){ AIWVDGQ__V=1; AIWVDHQ__V=2; }
    if(AIWVDHQ__M>0){ AIWVDHQ__V=1; AIWVDGQ__V=2; }
    AIWVDHQ__M=0; AIWVDGQ__M=0;
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Управления частотными приводами шнеков по таблице
    FPCM1SP1_V=FPCM1SP1_M;
    FPCM1SP2_V=FPCM1SP2_M;
    FPCM1SP3_V=FPCM1SP3_M;
    FPCM1SP4_V=FPCM1SP4_M;
    FPCM1ZD2_V=FPCM1ZD2_M;
    FPCM1ZD3_V=FPCM1ZD3_M; if(FPCM1ZD3_V<FPCM1ZD2_V) FPCM1ZD3_V=FPCM1ZD2_V;
    FPCM1ZD4_V=FPCM1ZD4_M; if(FPCM1ZD4_V<FPCM1ZD3_V) FPCM1ZD4_V=FPCM1ZD3_V;
    //
    FPCEMSP1_V=FPCEMSP1_M;
    FPCEMSP2_V=FPCEMSP2_M;
    FPCEMSP3_V=FPCEMSP3_M;
    FPCEMSP4_V=FPCEMSP4_M;
    FPCEMZD2_V=FPCEMZD2_M;
    FPCEMZD3_V=FPCEMZD3_M; if(FPCEMZD3_V<FPCEMZD2_V) FPCEMZD3_V=FPCEMZD2_V;
    FPCEMZD4_V=FPCEMZD4_M; if(FPCEMZD4_V<FPCEMZD3_V) FPCEMZD4_V=FPCEMZD3_V;
    //
    FPVYGSP1_V=FPVYGSP1_M;
    FPVYGSP2_V=FPVYGSP2_M;
    FPVYGSP3_V=FPVYGSP3_M;
    FPVYGSP4_V=FPVYGSP4_M;
    FPVYGZD2_V=FPVYGZD2_M;
    FPVYGZD3_V=FPVYGZD3_M; if(FPVYGZD3_V<FPVYGZD2_V) FPVYGZD3_V=FPVYGZD2_V;
    FPVYGZD4_V=FPVYGZD4_M; if(FPVYGZD4_V<FPVYGZD3_V) FPVYGZD4_V=FPVYGZD3_V;
    //---------  
    FPCM1MAN_V=FPCM1MAN_M;
    FPCEMMAN_V=FPCEMMAN_M;
    FPVYGMAN_V=FPVYGMAN_M;
    // Если управление в режиме 'П' - 
    // берем данные из таблицы в зависимости от текущего веса дозатора
    if(DIR216___V==0){
      if(DON228C__V==1){
        FPCM1MAN_V=FPCM1SP1_V;
        if(AIW218___V > TRCM1B_VIB * FPCM1ZD2_V*0.01) FPCM1MAN_V=FPCM1SP2_V;
        if(AIW218___V > TRCM1B_VIB * FPCM1ZD3_V*0.01) FPCM1MAN_V=FPCM1SP3_V;
        if(AIW218___V > TRCM1B_VIB * FPCM1ZD4_V*0.01) FPCM1MAN_V=FPCM1SP4_V;
      }
      if(DON228D__V==1){
        FPCEMMAN_V=FPCEMSP1_V;
        if(AIW218___V - TRCM1B_VIB > TRCEMS_VIB * FPCEMZD2_V*0.01) FPCEMMAN_V=FPCEMSP2_V;
        if(AIW218___V - TRCM1B_VIB > TRCEMS_VIB * FPCEMZD3_V*0.01) FPCEMMAN_V=FPCEMSP3_V;
        if(AIW218___V - TRCM1B_VIB > TRCEMS_VIB * FPCEMZD4_V*0.01) FPCEMMAN_V=FPCEMSP4_V;
      }
      if(DON228B__V==1){
        FPVYGMAN_V=FPVYGSP1_V;
        if(AIW219___V > TRVYGS_VIB * FPVYGZD2_V*0.01) FPVYGMAN_V=FPVYGSP2_V;
        if(AIW219___V > TRVYGS_VIB * FPVYGZD3_V*0.01) FPVYGMAN_V=FPVYGSP3_V;
        if(AIW219___V > TRVYGS_VIB * FPVYGZD4_V*0.01) FPVYGMAN_V=FPVYGSP4_V;
      }
    } else {
    // Если управление в режиме 'Н' -
    // берем данные(задание) скорости из ячейки ручного режима таблицы
    // if(DON228D__V==1){ FPCEMMAN_V=FPCEMMAN_V; }
    // if(DON228B__V==1){ FPVYGMAN_V=FPVYGMAN_V; }
    }
    //---------
    if(FPCM1MAN_V< 0) FPCM1MAN_V=0; if(FPCM1MAN_V>100) FPCM1MAN_V=100;
    if(FPCEMMAN_V< 0) FPCEMMAN_V=0; if(FPCEMMAN_V>100) FPCEMMAN_V=100;
    if(FPVYGMAN_V< 0) FPVYGMAN_V=0; if(FPVYGMAN_V>100) FPVYGMAN_V=100;
//  if(DON228D__V==0) FPCEMMAN_V=0; 
//  if(DON228B__V==0) FPVYGMAN_V=0; 
    FPCM1MAN_M=FPCM1MAN_V;
    FPCEMMAN_M=FPCEMMAN_V;
    FPVYGMAN_M=FPVYGMAN_V;
    AON228C_OM=FPCM1MAN_V;
    AON228D_OM=FPCEMMAN_V;
    AON228B_OM=FPVYGMAN_V;
    //------------------------------------------------------------------------

    // Управление частотными приводами циркуляции шлама и обратного шлама в
    // регуляторе дозировки  мокрого


    //------------------------------------------------------------------------
    // Расчет кол-ва загрузки воды из плотности сухих компонентов
    temp=0;
    if(PVib1xM>0||PVib2xM>0||PVib3xM>0){
       PVib14V=PVib16V=PVib24V=PVib26V=PVib34V=PVib36V=0;
     if(PVib1xM==1&&temp==0){ PVib14V=1; temp=1; };
     if(PVib1xM==2&&temp==0){ PVib16V=1; temp=2; };
     if(PVib2xM==1&&temp==0){ PVib24V=1; temp=3; };
     if(PVib2xM==2&&temp==0){ PVib26V=1; temp=4; };
     if(PVib3xM==1&&temp==0){ PVib34V=1; temp=5; };
     if(PVib3xM==2&&temp==0){ PVib36V=1; temp=6; };
     PVib1xM=PVib2xM=PVib3xM=0;
     if(temp==0){ PVib14V=1; }; temp=0;
    }

    RECEPT_01V=RECEPT_02V=RECEPT_03V=RECEPT_04V=RECEPT_05V=RECEPT_06V=0;
    if (PVib14V>0){ RECEPT_01V=1; }
    if (PVib16V>0){ RECEPT_02V=1; }
    if (PVib24V>0){ RECEPT_03V=1; }
    if (PVib26V>0){ RECEPT_04V=1; }
    if (PVib34V>0){ RECEPT_05V=1; }
    if (PVib36V>0){ RECEPT_06V=1; }

    if (P6BT1V != P6BT1M) P6BT1V = P6BT1M;
    if (P4BT1V != P4BT1M) P4BT1V = P4BT1M;
    if (P6PS1V != P6PS1M) P6PS1V = P6PS1M;
    if (P4PS1V != P4PS1M) P4PS1V = P4PS1M;
    if (P6OS1V != P6OS1M) P6OS1V = P6OS1M;
    if (P4OS1V != P4OS1M) P4OS1V = P4OS1M;

    if (P6BT2V != P6BT2M) P6BT2V = P6BT2M;
    if (P4BT2V != P4BT2M) P4BT2V = P4BT2M;
    if (P6PS2V != P6PS2M) P6PS2V = P6PS2M;
    if (P4PS2V != P4PS2M) P4PS2V = P4PS2M;
    if (P6OS2V != P6OS2M) P6OS2V = P6OS2M;
    if (P4OS2V != P4OS2M) P4OS2V = P4OS2M;

    if (P6BT3V != P6BT3M) P6BT3V = P6BT3M;
    if (P4BT3V != P4BT3M) P4BT3V = P4BT3M;
    if (P6PS3V != P6PS3M) P6PS3V = P6PS3M;
    if (P4PS3V != P4PS3M) P4PS3V = P4PS3M;
    if (P6OS3V != P6OS3M) P6OS3V = P6OS3M;
    if (P4OS3V != P4OS3M) P4OS3V = P4OS3M;

    // Если плотность вводится вручную
    if (PsM_V != PsM_M) PsM_V=PsM_M;
    if (PoM_V != PoM_M) PoM_V=PoM_M;
    if (PsM_V > 0) Ps=PsM_V;
    if (PoM_V > 0) Po=PoM_V;
    if (PinVGV != PinVGM) PinVGV = PinVGM;
    if (PinASV != PinASM) PinASV = PinASM;

    // Количество песка в шламе (расчет по весу задания для загрузки)
    Pesok14=P4PS1V-P4OS1V-(TRCM1S_01V+TRVYGS_01V);
    Pesok16=P6PS1V-P6OS1V-(TRCM1S_02V+TRVYGS_02V);
    Pesok24=P4PS2V-P4OS2V-(TRCM1S_03V+TRVYGS_03V);
    Pesok26=P6PS2V-P6OS2V-(TRCM1S_04V+TRVYGS_04V);
    Pesok34=P4PS3V-P4OS3V-(TRCM1S_05V+TRVYGS_05V);
    Pesok36=P6PS3V-P6OS3V-(TRCM1S_06V+TRVYGS_06V);

    // Количество шлама
    HSL41V=0; HSL61V=0; HSL42V=0; HSL62V=0; HSL43V=0; HSL63V=0;
    if(Ps>1){ 
       HSL41V=(Pesok14*Ps)/(1.606*(Ps-1));
       HSL61V=(Pesok16*Ps)/(1.606*(Ps-1));
       HSL42V=(Pesok24*Ps)/(1.606*(Ps-1));
       HSL62V=(Pesok26*Ps)/(1.606*(Ps-1));
       HSL43V=(Pesok34*Ps)/(1.606*(Ps-1));
       HSL63V=(Pesok36*Ps)/(1.606*(Ps-1));
    }

    // Количество обр шлама
    HOT41V=0; HOT61V=0; HOT42V=0; HOT62V=0; HOT43V=0; HOT63V=0;
    if(Po>1){
       HOT41V=(P4OS1V*Po)/(1.606*(Po-1));
       HOT61V=(P6OS1V*Po)/(1.606*(Po-1));
       HOT42V=(P4OS2V*Po)/(1.606*(Po-1));
       HOT62V=(P6OS2V*Po)/(1.606*(Po-1));
       HOT43V=(P4OS3V*Po)/(1.606*(Po-1));
       HOT63V=(P6OS3V*Po)/(1.606*(Po-1));
    }  

    // Алюминевая вода в суспензии (%)
    Valum=0.7;
    if(PinASV>0){
       if(PinASV>95) PinASV=95;
       if(PinASV< 5) PinASV= 5;
       Valum=(100-PinASV)*0.01;
    }

    // Количество воды
    HVD41V=(P4PS1V*P4BT1V)-(HSL41V-Pesok14)-(HOT41V-P4OS1V)-TRPAS__01V*Valum;
    HVD61V=(P6PS1V*P6BT1V)-(HSL61V-Pesok16)-(HOT61V-P6OS1V)-TRPAS__02V*Valum;
    HVD42V=(P4PS2V*P4BT2V)-(HSL42V-Pesok24)-(HOT42V-P4OS2V)-TRPAS__03V*Valum;
    HVD62V=(P6PS2V*P6BT2V)-(HSL62V-Pesok26)-(HOT62V-P6OS2V)-TRPAS__04V*Valum;
    HVD43V=(P4PS3V*P4BT3V)-(HSL43V-Pesok34)-(HOT43V-P4OS3V)-TRPAS__05V*Valum;
    HVD63V=(P6PS3V*P6BT3V)-(HSL63V-Pesok36)-(HOT63V-P6OS3V)-TRPAS__06V*Valum;

    //------------------------------------------------------------------------

    return;
}
//----------------------------------------------------------------------------
