//----------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
//  Включение-выключение звонков и сообщений регуляторов
vd  far Reg_ZvMs(vd){

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
    if (TIME_LLVS2 != OFF){
        TIME_LLVS1  =(TIME_LLVS1 == ON) then_ OFF else_ ON; TIME_LLVS2  = OFF;
    }
    if (TIME_LLVS4 != OFF){
        TIME_LLVS3  =(TIME_LLVS3 == ON) then_ OFF else_ ON; TIME_LLVS4  = OFF;
    }
    if (TIME_PRDS2 != OFF){
        TIME_PRDS1  =(TIME_PRDS1 == ON) then_ OFF else_ ON; TIME_PRDS2  = OFF;
    }
    if (TIME_PRDS4 != OFF){
        TIME_PRDS3  =(TIME_PRDS3 == ON) then_ OFF else_ ON; TIME_PRDS4  = OFF;
    }
    //------------------------------------------------------------------------
    // Подкачка воды
    if (TIME_VODL2 != OFF){
        TIME_VODL1  =(TIME_VODL1 == ON) then_ OFF else_ ON; TIME_VODL2  = OFF;
    }
    if (TIME_VODL4 != OFF){
        TIME_VODL3  =(TIME_VODL3 == ON) then_ OFF else_ ON; TIME_VODL4  = OFF;
    }
    if (TEMP_VODB2 != OFF){
        TEMP_VODB1  =(TEMP_VODB1 == ON) then_ OFF else_ ON; TEMP_VODB2  = OFF;
    }
    if (TEMP_VODB4 != OFF){
        TEMP_VODB3  =(TEMP_VODB3 == ON) then_ OFF else_ ON; TEMP_VODB4  = OFF;
    }
    if (TIME_COND2 != OFF){
        TIME_COND1  =(TIME_COND1 == ON) then_ OFF else_ ON; TIME_COND2  = OFF;
    }
    if (TIME_COND4 != OFF){
        TIME_COND3  =(TIME_COND3 == ON) then_ OFF else_ ON; TIME_COND4  = OFF;
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
    if (TIME_LLVO2 != OFF){
        TIME_LLVO1  =(TIME_LLVO1 == ON) then_ OFF else_ ON; TIME_LLVO2  = OFF;
    }
    if (TIME_LLVO4 != OFF){
        TIME_LLVO3  =(TIME_LLVO3 == ON) then_ OFF else_ ON; TIME_LLVO4  = OFF;
    }
    //------------------------------------------------------------------------
    // Подкачка вяжущего
    if (TIME_GON_2 != OFF){
        TIME_GON_1  =(TIME_GON_1 == ON) then_ OFF else_ ON; TIME_GON_2  = OFF;
    }
    if (TIME_GON_4 != OFF){
        TIME_GON_3  =(TIME_GON_3 == ON) then_ OFF else_ ON; TIME_GON_4  = OFF;
    }
    if (TIME_GOFF2 != OFF){
        TIME_GOFF1  =(TIME_GOFF1 == ON) then_ OFF else_ ON; TIME_GOFF2  = OFF;
    }
    if (TIME_GOFF4 != OFF){
        TIME_GOFF3  =(TIME_GOFF3 == ON) then_ OFF else_ ON; TIME_GOFF4  = OFF;
    }
    if (TIME_BVAJ2 != OFF){
        TIME_BVAJ1  =(TIME_BVAJ1 == ON) then_ OFF else_ ON; TIME_BVAJ2  = OFF;
    }
    if (TIME_BVAJ4 != OFF){
        TIME_BVAJ3  =(TIME_BVAJ3 == ON) then_ OFF else_ ON; TIME_BVAJ4  = OFF;
    }
    if (TIME_LLVV2 != OFF){
        TIME_LLVV1  =(TIME_LLVV1 == ON) then_ OFF else_ ON; TIME_LLVV2  = OFF;
    }
    if (TIME_LLVV4 != OFF){
        TIME_LLVV3  =(TIME_LLVV3 == ON) then_ OFF else_ ON; TIME_LLVV4  = OFF;
    }
    //------------------------------------------------------------------------
    // Подкачка цемента:
    if (TIME_LEV52 != OFF){
        TIME_LEV51  =(TIME_LEV51 == ON) then_ OFF else_ ON; TIME_LEV52  = OFF;
    }
    if (TIME_LEV54 != OFF){
        TIME_LEV53  =(TIME_LEV53 == ON) then_ OFF else_ ON; TIME_LEV54  = OFF;
    }
    if (TIME_OSC52 != OFF){
        TIME_OSC51  =(TIME_OSC51 == ON) then_ OFF else_ ON; TIME_OSC52  = OFF;
    }
    if (TIME_OSC54 != OFF){
        TIME_OSC53  =(TIME_OSC53 == ON) then_ OFF else_ ON; TIME_OSC54  = OFF;
    }
    if (TIME_NAS52 != OFF){
        TIME_NAS51  =(TIME_NAS51 == ON) then_ OFF else_ ON; TIME_NAS52  = OFF;
    }
    if (TIME_NAS54 != OFF){
        TIME_NAS53  =(TIME_NAS53 == ON) then_ OFF else_ ON; TIME_NAS54  = OFF;
    }
    if (LOAD_NS102 != OFF){
        LOAD_NS101  =(LOAD_NS101 == ON) then_ OFF else_ ON; LOAD_NS102  = OFF;
    }
    if (LOAD_NS104 != OFF){
        LOAD_NS103  =(LOAD_NS103 == ON) then_ OFF else_ ON; LOAD_NS104  = OFF;
    }
    if (TIME_SG012 != OFF){
        TIME_SG011  =(TIME_SG011 == ON) then_ OFF else_ ON; TIME_SG012  = OFF;
    }
    if (TIME_SG014 != OFF){
        TIME_SG013  =(TIME_SG013 == ON) then_ OFF else_ ON; TIME_SG014  = OFF;
    }
    if (TIME_LLVC2 != OFF){
        TIME_LLVC1  =(TIME_LLVC1 == ON) then_ OFF else_ ON; TIME_LLVC2  = OFF;
    }
    if (TIME_LLVC4 != OFF){
        TIME_LLVC3  =(TIME_LLVC3 == ON) then_ OFF else_ ON; TIME_LLVC4  = OFF;
    }
    if (TIME_BCEM2 != OFF){
        TIME_BCEM1  =(TIME_BCEM1 == ON) then_ OFF else_ ON; TIME_BCEM2  = OFF;
    }
    if (TIME_BCEM4 != OFF){
        TIME_BCEM3  =(TIME_BCEM3 == ON) then_ OFF else_ ON; TIME_BCEM4  = OFF;
    }
    if (TIME_PRDC2 != OFF){
        TIME_PRDC1  =(TIME_PRDC1 == ON) then_ OFF else_ ON; TIME_PRDC2  = OFF;
    }
    if (TIME_PRDC4 != OFF){
        TIME_PRDC3  =(TIME_PRDC3 == ON) then_ OFF else_ ON; TIME_PRDC4  = OFF;
    }
    if (TIME_PCAS2 != OFF){
        TIME_PCAS1  =(TIME_PCAS1 == ON) then_ OFF else_ ON; TIME_PCAS2  = OFF;
    }
    if (TIME_PCAS4 != OFF){
        TIME_PCAS3  =(TIME_PCAS3 == ON) then_ OFF else_ ON; TIME_PCAS4  = OFF;
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
