// coding: cp866
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\kkbkkt.h"

#define   COMU2      COM2         // номер порта для работы с УСО

//----------------------------------------------------------------------------
vd  far Mod_DO(vd){
    _i rec=0;

    #include "do\c2n0er18.c"

    return;
}
//----------------------------------------------------------------------------
