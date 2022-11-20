//----------------------------------------------------------------------------
//  COM2, 7042, N24

    rec= 14;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A2STEP___V==0){
        if (O2KOCO___M> OFF){
            O2KOCO___M=(O2KOCC___M>OFF) then_ OFF else_ ON; O2KOCC___M= OFF;
        }
        if (O2KOCC___M> OFF){
            O2KOCC___M=(O2KOCO___M>OFF) then_ OFF else_ ON; O2KOCO___M= OFF;
        }
        //
        if (O2VZO____M> OFF){
            O2VZO____M=(O2VZC____M>OFF) then_ OFF else_ ON; O2VZC____M= OFF;
        }
        if (O2VZC____M> OFF){
            O2VZC____M=(O2VZO____M>OFF) then_ OFF else_ ON; O2VZO____M= OFF;
        }
        //
        if(O2AZVO___M>OFF){
           O2AZVO___V=(O2AZVO___V>OFF) then_ OFF else_ ON; O2AZVO___M=OFF;
        }
        if(O2VN_1___M>OFF){
           O2VN_1___V=(O2VN_1___V>OFF) then_ OFF else_ ON; O2VN_1___M=OFF;
        }
    }

    //------------------------------------------------------------------------
    O2KOCO___V= O2KOCO___M;
    O2KOCC___V= O2KOCC___M;
    U2KOC____V=3;
    if(O2KOCO___V==OFF&&O2KOCC___V==OFF) U2KOC____V=0;
    if(O2KOCO___V==ON &&O2KOCC___V==OFF) U2KOC____V=1;
    if(O2KOCO___V==OFF&&O2KOCC___V==ON ) U2KOC____V=2;

    O2VZO____V= O2VZO____M;
    O2VZC____V= O2VZC____M;
    U2VZ_____V=3;
    if(O2VZO____V==OFF&&O2VZC____V==OFF) U2VZ_____V=0;
    if(O2VZO____V==ON &&O2VZC____V==OFF) U2VZ_____V=1;
    if(O2VZO____V==OFF&&O2VZC____V==ON ) U2VZ_____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O2KOCO___V,  0, 0);
    SetMODV (COMU1,rec, 1, O2KOCC___V,  0, 0);

    SetMODV (COMU1,rec, 2, O2VZO____V,  0, 0);
    SetMODV (COMU1,rec, 3, O2VZC____V,  0, 0);

    SetMODV (COMU1,rec, 4, O2AZVO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O2VN_1___V,  0, 0);

    SetMODV (COMU1,rec, 6, N24C06___V,  0, 0);
    SetMODV (COMU1,rec, 7, N24C07___V,  0, 0);
    SetMODV (COMU1,rec, 8, N24C08___V,  0, 0);
    SetMODV (COMU1,rec, 9, N24C09___V,  0, 0);
    SetMODV (COMU1,rec,10, N24C10___V,  0, 0);
    SetMODV (COMU1,rec,11, N24C11___V,  0, 0);

    SetMODV (COMU1,rec,12, PCCS2WR__V,  0, 0);

//----------------------------------------------------------------------------
