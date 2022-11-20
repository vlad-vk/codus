// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7042, N0E

    rec= 18;

    //------------------------------------------------------------------------
    // Ручное переключение канала
    if(DON50____M==5){
       if(DON50____V>0) DON50____V=0; else DON50____V=1; DON50____M=0;
    }   

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:

    SetMODV (COMU1,rec, 0, DON50____V,  0, 0);

    SetMODV (COMU1,rec, 1, DOX0E1___V,  0, 0);
    SetMODV (COMU1,rec, 2, DOX0E2___V,  0, 0);
    SetMODV (COMU1,rec, 3, DOX0E3___V,  0, 0);
    SetMODV (COMU1,rec, 4, DOX0E4___V,  0, 0);
    SetMODV (COMU1,rec, 5, DOX0E5___V,  0, 0);
    SetMODV (COMU1,rec, 6, DOX0E6___V,  0, 0);
    SetMODV (COMU1,rec, 7, DOX0E7___V,  0, 0);
    SetMODV (COMU1,rec, 8, DOX0E8___V,  0, 0);
    SetMODV (COMU1,rec, 9, DOX0E9___V,  0, 0);
    SetMODV (COMU1,rec,10, DOX0EA___V,  0, 0);
    SetMODV (COMU1,rec,11, DOX0EB___V,  0, 0);

    SetMODV (COMU1,rec,12, DON70____V,  0, 0);

//----------------------------------------------------------------------------
