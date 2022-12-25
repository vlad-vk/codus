//  coding=cp866; version=2013013112; title="";
//----------------------------------------------------------------------------
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

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
    if(REG14S___M != REG14S___V){
       REG14S___V  = REG14S___M; STEP14=REG14S___M;
    }; REG14S1__V  = STEP14;

    // подкачка вяжущего
    if(REG04S___M != REG04S___V){
       REG04S___V  = REG04S___M; STEP04=REG04S___M;
    }; REG04S1__V  = STEP04;

    // подкачка цемента
    if(REG05S___M != REG05S___V){
       REG05S___V  = REG05S___M; STEP05=REG05S___M;
    }; REG05S1__V  = STEP05;

    // дозировка сухого
    if(REG06cS__M != REG06cS__V){
       REG06cS__V  = REG06cS__M; STEP06c=REG06cS__M;
    }; REG06cS1_V  = STEP06c;

    // дозировка мокрого
    if(REG07S___M != REG07S___V){
       REG07S___V  = REG07S___M; STEP07=REG07S___M;
    }; REG07S1__V  = STEP07;

    // дозировка пасты
    if(REG09S___M != REG09S___V){
       REG09S___V  = REG09S___M; STEP09=REG09S___M;
    }; REG09S1__V  = STEP09;


    return;
}
//---------------------------------------------------------------------------
