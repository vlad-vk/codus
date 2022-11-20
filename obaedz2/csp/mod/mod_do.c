#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#define   COMU1      COM1         // номер порта для работы с УСО 1-ой группы
#define   COMU2      COM2         // номер порта для работы с УСО 2-ой группы

//----------------------------------------------------------------------------
vd  far Mod_DO(vd){
    _i rec=0;

    #include "do\c1m02.c"
    #include "do\c1m04.c"
    #include "do\c1m06.c"
    #include "do\c1m0a.c"
    #include "do\c1m0b.c"
    #include "do\c1m11.c"
    #include "do\c1m15.c"
    #include "do\c1m16.c"
    #include "do\c1m18.c"

    #include "do\c2m23.c"
    #include "do\c2m24.c"
    #include "do\c2m25.c"
    #include "do\c2m2a.c"
    #include "do\c2m2b.c"
    #include "do\c2m43.c"
    #include "do\c2m44.c"
    #include "do\c2m45.c"

    return;
}
//----------------------------------------------------------------------------

