//----------------------------------------------------------------------------
//  Получить значения с дискретных модулей
vd  far InpDataD(vd){
    _i  rec=0;

    #include "mod\di\c1n04r03.c"
    #include "mod\di\c1n05r04.c"
    #include "mod\di\c1n06r05.c"
    #include "mod\di\c1n07r06.c"
    #include "mod\di\c1n08r07.c"
    #include "mod\di\c1n09r08.c"
    #include "mod\di\c1n0ar09.c"
    #include "mod\di\c1n0br10.c"
    #include "mod\di\c1n0cr11.c"
    #include "mod\di\c1n0dr12.c"
    #include "mod\di\c1n0er13.c"
    #include "mod\di\c1n0fr14.c"

    DIR051___V = BFiltr(20, DIR051___V, 10);
    DIR020___V = BFiltr(21, DIR020___V, 10);
    DIR041___V = BFiltr(22, DIR041___V, 10);
    DIR010___V = BFiltr(23, DIR010___V, 10);
    DIR031___V = BFiltr(24, DIR031___V, 10);
    DIR100___V = BFiltr(25, DIR100___V, 10);
    DIR170___V = BFiltr(26, DIR170___V, 10);
    DIR160___V = BFiltr(27, DIR160___V, 10);
    DIR161___V = BFiltr(28, DIR161___V, 10);
    DIR140___V = BFiltr(29, DIR140___V, 10);
    DIR130___V = BFiltr(30, DIR130___V, 10);
    DIR131___V = BFiltr(31, DIR131___V, 10);
    DIR061___V = BFiltr(32, DIR061___V, 10);
    DIR200___V = BFiltr(33, DIR200___V, 10);
    DIR230___V = BFiltr(34, DIR230___V, 10);
    DIR190___V = BFiltr(35, DIR190___V, 10);
    DIR210___V = BFiltr(36, DIR210___V, 10);
    DIR070___V = BFiltr(37, DIR070___V, 10);
    DIR110___V = BFiltr(38, DIR110___V, 10);
    DIR120___V = BFiltr(39, DIR120___V, 10);
    DIR220___V = BFiltr(40, DIR220___V, 10);
    DIR270___V = BFiltr(41, DIR270___V, 10);
    DIR273___V = BFiltr(42, DIR273___V, 10);
    //
    DIR290___V = BFiltr(44, DIR290___V, 10);
    //
    DIR300___V = BFiltr(46, DIR300___V, 10);
    DIR280___V = BFiltr(47, DIR280___V, 10);
    DIR310___V = BFiltr(48, DIR310___V, 10);

    DIS31A___V = BFiltr(50, DIS31A___V, 10);

    return;
}
//----------------------------------------------------------------------------
