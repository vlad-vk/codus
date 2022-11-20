// coding: cp866
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\kkbkkt.h"

#define   COMU2      COM2         // номер порта для работы с УСО

//----------------------------------------------------------------------------
vd  far Mod_DI(vd){
    _i rec=0;

    #include "cn\c2n09r08.c"
    #include "cn\c2n0ar10.c"
    #include "cn\c2n0br12.c"
    #include "cn\c2n0cr14.c"
    #include "cn\c2n0dr16.c"

    return;
}
//----------------------------------------------------------------------------

