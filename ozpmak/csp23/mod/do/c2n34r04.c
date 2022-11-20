//----------------------------------------------------------------------------
//  COM2, 7042, N34

    rec= 4;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A3STEP___V==0){
        if (O3KOCO___M> OFF){
            O3KOCO___M=(O3KOCC___M>OFF) then_ OFF else_ ON; O3KOCC___M= OFF;
        }
        if (O3KOCC___M> OFF){
            O3KOCC___M=(O3KOCO___M>OFF) then_ OFF else_ ON; O3KOCO___M= OFF;
        }
        if (O3VZO____M> OFF){
            O3VZO____M=(O3VZC____M>OFF) then_ OFF else_ ON; O3VZC____M= OFF;
        }
        if (O3VZC____M> OFF){
            O3VZC____M=(O3VZO____M>OFF) then_ OFF else_ ON; O3VZO____M= OFF;
        }
        if(O3AZVO___M>OFF){
           O3AZVO___V=(O3AZVO___V>OFF) then_ OFF else_  ON; O3AZVO___M=OFF;
        }
        if(O3VN_1___M>OFF){
           O3VN_1___V=(O3VN_1___V>OFF) then_ OFF else_  ON; O3VN_1___M=OFF;
        }
    }
    //------------------------------------------------------------------------
    O3KOCO___V= O3KOCO___M;
    O3KOCC___V= O3KOCC___M;
    U3KOC____V= 3;
    if(O3KOCO___V==OFF&&O3KOCC___V==OFF) U3KOC____V=0;
    if(O3KOCO___V==ON &&O3KOCC___V==OFF) U3KOC____V=1;
    if(O3KOCO___V==OFF&&O3KOCC___V==ON ) U3KOC____V=2;

    O3VZO____V= O3VZO____M;
    O3VZC____V= O3VZC____M;
    U3VZ_____V= 3;
    if(O3VZO____V==OFF&&O3VZC____V==OFF) U3VZ_____V=0;
    if(O3VZO____V==ON &&O3VZC____V==OFF) U3VZ_____V=1;
    if(O3VZO____V==OFF&&O3VZC____V==ON ) U3VZ_____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O3KOCO___V,  0, 0);
    SetMODV (COMU1,rec, 1, O3KOCC___V,  0, 0);

    SetMODV (COMU1,rec, 2, O3VZO____V,  0, 0);
    SetMODV (COMU1,rec, 3, O3VZC____V,  0, 0);

    SetMODV (COMU1,rec, 4, O3AZVO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O3VN_1___V,  0, 0);

    SetMODV (COMU1,rec, 6, N34C06___V,  0, 0);
    SetMODV (COMU1,rec, 7, N34C07___V,  0, 0);
    SetMODV (COMU1,rec, 8, N34C08___V,  0, 0);
    SetMODV (COMU1,rec, 9, N34C09___V,  0, 0);
    SetMODV (COMU1,rec,10, N34C10___V,  0, 0);
    SetMODV (COMU1,rec,11, N34C11___V,  0, 0);
    SetMODV (COMU1,rec,12, PCCS3WR__V,  0, 0);

//----------------------------------------------------------------------------
