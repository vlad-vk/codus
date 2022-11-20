//----------------------------------------------------------------------------
// Общие функции регуляторов

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

vd  far UchetCMP(vd);

//----------------------------------------------------------------------------
vd  far Regul_up(vd){

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
            Message(89); DON801___V=0; DON802___V=0; DON803___V=0;
         // общий регул выключен
         } else { 
            Message(90); DON801___V=0; DON802___V=0; DON803___V=0;
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

    UchetCMP();

    return;
}
//----------------------------------------------------------------------------
