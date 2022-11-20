//----------------------------------------------------------------------------
//  COM2, 7042, N44

    rec= 14;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A4STEP___V==0){
        if (O4KOCO___M> OFF){
            O4KOCO___M=(O4KOCC___M>OFF) then_ OFF else_ ON; O4KOCC___M= OFF;
        }
        if (O4KOCC___M> OFF){
            O4KOCC___M=(O4KOCO___M>OFF) then_ OFF else_ ON; O4KOCO___M= OFF;
        }
        //
        if (O4VZO____M> OFF){
            O4VZO____M=(O4VZC____M>OFF) then_ OFF else_ ON; O4VZC____M= OFF;
        }
        if (O4VZC____M> OFF){
            O4VZC____M=(O4VZO____M>OFF) then_ OFF else_ ON; O4VZO____M= OFF;
        }
        //
        if(O4AZVO___M>OFF){
           O4AZVO___V=(O4AZVO___V>OFF) then_ OFF else_ ON; O4AZVO___M=OFF;
        }
        if(O4VN_1___M>OFF){
           O4VN_1___V=(O4VN_1___V>OFF) then_ OFF else_ ON; O4VN_1___M=OFF;
        }
    }

    //------------------------------------------------------------------------
    O4KOCO___V= O4KOCO___M;
    O4KOCC___V= O4KOCC___M;
    U4KOC____V=3;
    if(O4KOCO___V==OFF&&O4KOCC___V==OFF) U4KOC____V=0;
    if(O4KOCO___V==ON &&O4KOCC___V==OFF) U4KOC____V=1;
    if(O4KOCO___V==OFF&&O4KOCC___V==ON ) U4KOC____V=2;

    O4VZO____V= O4VZO____M;
    O4VZC____V= O4VZC____M;
    U4VZ_____V=3;
    if(O4VZO____V==OFF&&O4VZC____V==OFF) U4VZ_____V=0;
    if(O4VZO____V==ON &&O4VZC____V==OFF) U4VZ_____V=1;
    if(O4VZO____V==OFF&&O4VZC____V==ON ) U4VZ_____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O4KOCO___V,  0, 0);
    SetMODV (COMU1,rec, 1, O4KOCC___V,  0, 0);

    SetMODV (COMU1,rec, 2, O4VZO____V,  0, 0);
    SetMODV (COMU1,rec, 3, O4VZC____V,  0, 0);

    SetMODV (COMU1,rec, 4, O4AZVO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O4VN_1___V,  0, 0);

    SetMODV (COMU1,rec, 6, N44C06___V,  0, 0);
    SetMODV (COMU1,rec, 7, N44C07___V,  0, 0);
    SetMODV (COMU1,rec, 8, N44C08___V,  0, 0);
    SetMODV (COMU1,rec, 9, N44C09___V,  0, 0);
    SetMODV (COMU1,rec,10, N44C10___V,  0, 0);
    SetMODV (COMU1,rec,11, N44C11___V,  0, 0);

    SetMODV (COMU1,rec,12, PCCS4WR__V,  0, 0);

//----------------------------------------------------------------------------
