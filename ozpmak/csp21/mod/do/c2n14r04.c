//----------------------------------------------------------------------------
//  COM2, 7042, N14

    rec= 4;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A1STEP___V==0){
        if (O1KOCO___M> OFF){
            O1KOCO___M=(O1KOCC___M>OFF) then_ OFF else_ ON; O1KOCC___M= OFF;
        }
        if (O1KOCC___M> OFF){
            O1KOCC___M=(O1KOCO___M>OFF) then_ OFF else_ ON; O1KOCO___M= OFF;
        }
        if (O1VZO____M> OFF){
            O1VZO____M=(O1VZC____M>OFF) then_ OFF else_ ON; O1VZC____M= OFF;
        }
        if (O1VZC____M> OFF){
            O1VZC____M=(O1VZO____M>OFF) then_ OFF else_ ON; O1VZO____M= OFF;
        }
        if(O1AZVO___M>OFF){
           O1AZVO___V=(O1AZVO___V>OFF) then_ OFF else_  ON; O1AZVO___M=OFF;
        }
        if(O1VN_1___M>OFF){
           O1VN_1___V=(O1VN_1___V>OFF) then_ OFF else_  ON; O1VN_1___M=OFF;
        }
    }
    //------------------------------------------------------------------------
    O1KOCO___V= O1KOCO___M;
    O1KOCC___V= O1KOCC___M;
    U1KOC____V= 3;
    if(O1KOCO___V==OFF&&O1KOCC___V==OFF) U1KOC____V=0;
    if(O1KOCO___V==ON &&O1KOCC___V==OFF) U1KOC____V=1;
    if(O1KOCO___V==OFF&&O1KOCC___V==ON ) U1KOC____V=2;

    O1VZO____V= O1VZO____M;
    O1VZC____V= O1VZC____M;
    U1VZ_____V= 3;
    if(O1VZO____V==OFF&&O1VZC____V==OFF) U1VZ_____V=0;
    if(O1VZO____V==ON &&O1VZC____V==OFF) U1VZ_____V=1;
    if(O1VZO____V==OFF&&O1VZC____V==ON ) U1VZ_____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O1KOCO___V,  0, 0);
    SetMODV (COMU1,rec, 1, O1KOCC___V,  0, 0);

    SetMODV (COMU1,rec, 2, O1VZO____V,  0, 0);
    SetMODV (COMU1,rec, 3, O1VZC____V,  0, 0);

    SetMODV (COMU1,rec, 4, O1AZVO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O1VN_1___V,  0, 0);

    SetMODV (COMU1,rec, 6, N14C06___V,  0, 0);
    SetMODV (COMU1,rec, 7, N14C07___V,  0, 0);
    SetMODV (COMU1,rec, 8, N14C08___V,  0, 0);
    SetMODV (COMU1,rec, 9, N14C09___V,  0, 0);
    SetMODV (COMU1,rec,10, N14C10___V,  0, 0);
    SetMODV (COMU1,rec,11, N14C11___V,  0, 0);
    SetMODV (COMU1,rec,12, PCCS1WR__V,  0, 0);

//----------------------------------------------------------------------------
