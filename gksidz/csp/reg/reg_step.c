//----------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
//  Определение оператором текущего шага регулятора
vd  far SetStepReg(vd){

    // подкачка шлама
    if(REG01S___M != REG01S___V){
       REG01S___V  = REG01S___M; STEP01=REG01S___M;
    }; REG01S1__V  = STEP01;
    // подкачка воды
    if(REG02S___M != REG02S___V){
       REG02S___V  = REG02S___M; STEP02=REG02S___M;
    }; REG02S1__V  = STEP02;
    // подкачка отходов
    if(REG03S___M != REG03S___V){
       REG03S___V  = REG03S___M; STEP03=REG03S___M;
    }; REG03S1__V  = STEP03;
    // подкачка вяжущего
    if(REG04S___M != REG04S___V){
       REG04S___V  = REG04S___M; STEP04=REG04S___M;
    }; REG04S1__V  = STEP04;
    // подкачка цемента
    if(REG05S___M != REG05S___V){
       REG05S___V  = REG05S___M; STEP05=REG05S___M;
    }; REG05S1__V  = STEP05;
    // дозировка сухого
    if(REG06S___M != REG06S___V){
       REG06S___V  = REG06S___M; STEP06=REG06S___M;
    }; REG06S1__V  = STEP06;
    // дозировка мокрого
    if(REG07S___M != REG07S___V){
       REG07S___V  = REG07S___M; STEP07=REG07S___M;
    }; REG07S1__V  = STEP07;
    // дозировка пасты
    if(REG09S___M != REG09S___V){
       REG09S___V  = REG09S___M; STEP09=REG09S___M;
    }; REG09S1__V  = STEP09;
    // управление ВГБМ
    if(REG10S___M != REG10S___V){
       REG10S___V  = REG10S___M; STEP10=REG10S___M;
    }; REG10S1__V  = STEP10;

    return;
}
//---------------------------------------------------------------------------
