// coding: cp866
//----------------------------------------------------------------------------
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
//  Включение-выключение звонков и сообщений регуляторов. Блокировки исполнителей
vd  far Reg_ZvMs(vd){

    //  Блокировка  исполнителей дозатора цемента при привышении веса дозатора
    //  или при открытом клапане выгрузки
    if((AIW218___V>=TRCM1S_VIB)||(DIS220F__V==ON)){
        DON2293__M=0; DON2293__V=0; 
        DON228C__M=0; DON228C__V=0;
        DON2294__M=0; DON2294__V=0;
        DON221C__M=0; DON221C__V=0;
        DON229D1_M=0; DON229D1_V=0;
        DON228D__M=0; DON228D__V=0;
        DON229D2_M=0; DON229D2_V=0;
        DON221D__M=0; DON221D__V=0;
        REG06cSW_V=1005;
    }
    //  Блокировка  исполнителей дозатора вяжущих при привышении веса дозатора
    //  или при открытом клапане выгрузки
    if((AIW219___V>=TRVYGS_VIB)||(DIS220E__V==ON)){
        DON229B1_M=0; DON229B1_V=0;
        DON229B2_M=0; DON229B2_V=0;
        DON228B__M=0; DON228B__V=0;
        DON221B__M=0; DON221B__V=0;
        REG06vSW_V=1006;
    }
    //  Блокировка  исполнителей дозатора мокрого при привышении веса дозатора
    //  или при открытом клапане выгрузки
    if((AIW252___V>=TROTH__VIB+TRSLM__VIB)||(DIS251G2_V==ON)){
        AON2511_OM=0; AON2511_OV=0; // вместо DON251F1_V=0; 
        AON2512_OM=0; AON2512_OV=0; // вместо DON251F2_V=0;
        DON251E1_V=0; DON251E2_V=0;
        REG07SW__V=1007;
    }
    //  Блокировка  исполнителей дозатора ал суспензии при привышении веса
    //  дозатора или при открытом клапане выгрузки
    if((AIW216___V>=TRPAS__VIB)||(DIS216G__V==ON)){
        DON068B__V=0; DON069B__V=0; DON068D__V=0; 
        AON216F_OM=0; AON216F_OV=0; // вместо DON216F__V=0;
        REG09SW__V=1008;
    }

    //------------------------------------------------------------------------
    // Подкачка шлама
    if (TIME_SLNZ2 != OFF){
        TIME_SLNZ1  =(TIME_SLNZ1 == ON) then_ OFF else_ ON; TIME_SLNZ2  = OFF;
    }
    if (TIME_SLNZ4 != OFF){
        TIME_SLNZ3  =(TIME_SLNZ3 == ON) then_ OFF else_ ON; TIME_SLNZ4  = OFF;
    }
    if (TIME_SLNV2 != OFF){
        TIME_SLNV1  =(TIME_SLNV1 == ON) then_ OFF else_ ON; TIME_SLNV2  = OFF;
    }
    if (TIME_SLNV4 != OFF){
        TIME_SLNV3  =(TIME_SLNV3 == ON) then_ OFF else_ ON; TIME_SLNV4  = OFF;
    }
    if (LOAD_SLCN2 != OFF){
        LOAD_SLCN1  =(LOAD_SLCN1 == ON) then_ OFF else_ ON; LOAD_SLCN2  = OFF;
    }
    if (LOAD_SLCN4 != OFF){
        LOAD_SLCN3  =(LOAD_SLCN3 == ON) then_ OFF else_ ON; LOAD_SLCN4  = OFF;
    }
    //------------------------------------------------------------------------
    // Подкачка отходов
    if (TIME_OTHV2 != OFF){
        TIME_OTHV1  =(TIME_OTHV1 == ON) then_ OFF else_ ON; TIME_OTHV2  = OFF;
    }
    if (TIME_OTHV4 != OFF){
        TIME_OTHV3  =(TIME_OTHV3 == ON) then_ OFF else_ ON; TIME_OTHV4  = OFF;
    }
    if (TIME_NS312 != OFF){
        TIME_NS311  =(TIME_NS311 == ON) then_ OFF else_ ON; TIME_NS312  = OFF;
    }
    if (TIME_NS314 != OFF){
        TIME_NS313  =(TIME_NS313 == ON) then_ OFF else_ ON; TIME_NS314  = OFF;
    }
    if (TIME_NS322 != OFF){
        TIME_NS321  =(TIME_NS321 == ON) then_ OFF else_ ON; TIME_NS322  = OFF;
    }
    if (TIME_NS324 != OFF){
        TIME_NS323  =(TIME_NS323 == ON) then_ OFF else_ ON; TIME_NS324  = OFF;
    }
    if (LOAD_NS082 != OFF){
        LOAD_NS081  =(LOAD_NS081 == ON) then_ OFF else_ ON; LOAD_NS082  = OFF;
    }
    if (LOAD_NS084 != OFF){
        LOAD_NS083  =(LOAD_NS083 == ON) then_ OFF else_ ON; LOAD_NS084  = OFF;
    }
    if (TIME_PRDO2 != OFF){
        TIME_PRDO1  =(TIME_PRDO1 == ON) then_ OFF else_ ON; TIME_PRDO2  = OFF;
    }
    if (TIME_PRDO4 != OFF){
        TIME_PRDO3  =(TIME_PRDO3 == ON) then_ OFF else_ ON; TIME_PRDO4  = OFF;
    }
    //------------------------------------------------------------------------
    // Дозировка сухого
    if (LOAD_VGGR2 != OFF){
        LOAD_VGGR1  =(LOAD_VGGR1 == ON) then_ OFF else_ ON; LOAD_VGGR2  = OFF;
    }
    if (LOAD_VGGR4 != OFF){
        LOAD_VGGR3  =(LOAD_VGGR3 == ON) then_ OFF else_ ON; LOAD_VGGR4  = OFF;
    }
    if (LOAD_VGTC2 != OFF){
        LOAD_VGTC1  =(LOAD_VGTC1 == ON) then_ OFF else_ ON; LOAD_VGTC2  = OFF;
    }
    if (LOAD_VGTC4 != OFF){
        LOAD_VGTC3  =(LOAD_VGTC3 == ON) then_ OFF else_ ON; LOAD_VGTC4  = OFF;
    }
    //------------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------
