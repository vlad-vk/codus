//----------------------------------------------------------------------------
//  COM2, 7041, N41

    rec=17;

    DIS251E1_V = GetMODV(COMU2,rec, 0);
//  DIS251F1_V = GetMODV(COMU2,rec, 1); // вместо этого клапана установлен аналоговый M27:02 AON2511
    DIS251H1_V = GetMODV(COMU2,rec, 2);
    DIS251G1_V = GetMODV(COMU2,rec, 3);
    DIS251E2_V = GetMODV(COMU2,rec, 4);
//  DIS251F2_V = GetMODV(COMU2,rec, 5); // вместо этого клапана установлен аналоговый M47:00 AON2512
    DIS251H2_V = GetMODV(COMU2,rec, 6);
    DIS251G2_V = GetMODV(COMU2,rec, 7);
    DISVGBMG_V = GetMODV(COMU2,rec, 8);
    DISVGBMR_V = GetMODV(COMU2,rec, 9);
//  DIS216F__V = GetMODV(COMU2,rec,10); // вместо этого клапана установлен аналоговый M27:03 AON216F
    DIS216G__V = GetMODV(COMU2,rec,11);
    DIR216___V = GetMODV(COMU2,rec,12);
    DIR251___V = GetMODV(COMU2,rec,13);

// эмитация дискретных сигналов с аналоговых клапанов
DIS216F__V=0; DON216F__V=0; if(AON216F_OV>0){ DIS216F__V=1; DON216F__V=1; }
DIS251F1_V=0; DON251F1_V=0; if(AON2511_OV>0){ DIS251F1_V=1; DON251F1_V=1; }
DIS251F2_V=0; DON251F2_V=0; if(AON2512_OV>0){ DIS251F2_V=1; DON251F2_V=1; }

//----------------------------------------------------------------------------
