#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#define   COMU1      COM1         // ����� ���� ��� ࠡ��� � ��� 1-�� ��㯯�
#define   COMU2      COM2         // ����� ���� ��� ࠡ��� � ��� 2-�� ��㯯�

//----------------------------------------------------------------------------
vd  far Mod_DI(vd){
    _i rec=0;

    #include "di\c1m01.c"
    #include "di\c1m03.c"
    #include "di\c1m05.c"
    #include "di\c1m07.c"
    #include "di\c1m08.c"
    #include "di\c1m09.c"
    #include "di\c1m10.c"
    #include "di\c1m13.c"
    #include "di\c1m14.c"
    #include "di\c1m17.c"
    #include "di\c2m20.c"
    #include "di\c2m21.c"
    #include "di\c2m22.c"
    #include "di\c2m28.c"
    #include "di\c2m29.c"
    #include "di\c2m40.c"
    #include "di\c2m41.c"

    return;
}
//----------------------------------------------------------------------------

