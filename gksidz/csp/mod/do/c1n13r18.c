//----------------------------------------------------------------------------
//  COM1, 7042, N13

    rec=18;

    // ручное переключение с компьютера выходов на исполнители

    // блокировка одновременного включения пневмонасосов
    if(DON102___M==SWITCH and REG05R___V==OFF 
                          and DIS101___V==OFF and DON101___V==OFF){ 
       DON102___V=(DON102___V==OFF) then_ ON else_ OFF; 
    }; DON102___M= OFF;

    if(DON161___M==SWITCH and REG05R___V==OFF){ 
       DON161___V=(DON161___V==OFF) then_ ON else_ OFF; 
    }; DON161___M= OFF;

    if(DON171___M==SWITCH and REG06R___V==OFF){ 
       DON171___V=(DON171___V==OFF) then_ ON else_ OFF; 
    }; DON171___M= OFF; 

    if(DON131___M==SWITCH and REG04R___V==OFF){ 
       DON131___V=(DON131___V==OFF) then_ ON else_ OFF; 
    }; DON131___M= OFF;

    if(DON141___M==SWITCH and REG06R___V==OFF){ 
       DON141___V=(DON141___V==OFF) then_ ON else_ OFF; 
    }; DON141___M= OFF;

    if(DON142___M==SWITCH and REG06R___V==OFF){ 
       DON142___V=(DON142___V==OFF) then_ ON else_ OFF; 
    }; DON142___M= OFF;

    if(DON071___M==SWITCH and REG03R___V==OFF){ 
       DON071___V=(DON071___V==OFF) then_ ON else_ OFF; 
    }; DON071___M= OFF;

    // блокировка одновременного включения пневмонасосов
    if(DON082___M==SWITCH and REG03R___V==OFF 
                          and DIS081___V==OFF and DON081___V==OFF){ 
       DON082___V=(DON082___V==OFF) then_ ON else_ OFF; 
    }; DON082___M= OFF;

    // блокировка одновременного включения пневмонасосов
    if(DON081___M==SWITCH and REG03R___V==OFF 
                          and DIS082___V==OFF and DON082___V==OFF){ 
       DON081___V=(DON081___V==OFF) then_ ON else_ OFF; 
    }; DON081___M= OFF;

    if(DON111___M==SWITCH and REG04R___V==OFF){ 
       DON111___V=(DON111___V==OFF) then_ ON else_ OFF; 
    }; DON111___M= OFF;

    if(DON112___M==SWITCH and REG04R___V==OFF){ 
       DON112___V=(DON112___V==OFF) then_ ON else_ OFF; 
    }; DON112___M= OFF;

    if(DON121___M==SWITCH and REG04R___V==OFF){ 
       DON121___V=(DON121___V==OFF) then_ ON else_ OFF; 
    }; DON121___M= OFF;

    if(DON122___M==SWITCH and REG04R___V==OFF){ 
       DON122___V=(DON122___V==OFF) then_ ON else_ OFF; 
    }; DON122___M= OFF;


    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON102___V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON161___V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON171___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DON131___V,  0, 0);
    SetMODV (COMU1,rec, 4,  DON141___V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON142___V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON071___V,  0, 0);
    SetMODV (COMU1,rec, 7,  DON082___V,  0, 0);
    SetMODV (COMU1,rec, 8,  DON081___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DON111___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON112___V,  0, 0);
    SetMODV (COMU1,rec,11,  DON121___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON122___V,  0, 0);

//----------------------------------------------------------------------------
