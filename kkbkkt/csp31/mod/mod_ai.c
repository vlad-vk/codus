// coding: cp866
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\kkbkkt.h"

#define   COMU2      COM2         // номер порта для работы с УСО

//----------------------------------------------------------------------------
vd  far Mod_AI(vd){
    _i rec=0;

    #include "ai\c2n01r00.c"
    #include "ai\c2n03r02.c"
    #include "ai\c2n05r04.c"
    #include "ai\c2n07r06.c"
    #include "ai\c2n02r01.c"
    #include "ai\c2n04r03.c"
    #include "ai\c2n06r05.c"
    #include "ai\c2n08r07.c"

    return;
}
//----------------------------------------------------------------------------

