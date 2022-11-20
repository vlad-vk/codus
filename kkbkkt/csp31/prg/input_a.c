// coding=cp866
//----------------------------------------------------------------------------
//  Получить значения с аналоговых модулей (i7017,i7033)
vd  far InpDataS(vd){
    _i  rec=0;

    #include "mod\ai\c2n01r00.c"
    #include "mod\ai\c2n02r01.c"
    #include "mod\ai\c2n03r02.c"
    #include "mod\ai\c2n04r03.c"
    #include "mod\ai\c2n05r04.c"
    #include "mod\ai\c2n06r05.c"
    #include "mod\ai\c2n07r06.c"
    #include "mod\ai\c2n08r07.c"

    #include "mod\cn\c2n09r08.c"
    #include "mod\cn\c2n0ar10.c"
    #include "mod\cn\c2n0br12.c"
    #include "mod\cn\c2n0cr14.c"
    #include "mod\cn\c2n0dr16.c"

    return;
}
//----------------------------------------------------------------------------
