#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#define   COMU1      COM1         // номер порта для работы с УСО 1-ой группы
#define   COMU2      COM2         // номер порта для работы с УСО 2-ой группы

//----------------------------------------------------------------------------
vd  far Mod_AI(vd){
    _i rec=0;

    #include "ai\c1m12.c"
    #include "ai\c2m26.c"
    #include "ai\c2m2c.c"
    #include "ai\c2m46.c"

    return;
}
//----------------------------------------------------------------------------

