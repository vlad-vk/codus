//----------------------------------------------------------------------------
//  COM1, 7042, N11

    rec=16;

    // ручное переключение с компьютера выходов на исполнители
    if(DON041___M==SWITCH and REG01R___V==OFF){ 
       DON041___V=(DON041___V==OFF) then_ ON else_ OFF; 
    }; DON041___M= OFF; 

    if(DOX1101__M==SWITCH){ 
       DOX1101__V=(DOX1101__V==OFF) then_ ON else_ OFF; 
    }; DOX1101__M= OFF; 

    if(DON032___M==SWITCH and REG01R___V==OFF){ 
       DON032___V=(DON032___V==OFF) then_ ON else_ OFF; 
    }; DON032___M= OFF; 

    if(DON031___M==SWITCH and REG01R___V==OFF){ 
       DON031___V=(DON031___V==OFF) then_ ON else_ OFF; 
    }; DON031___M= OFF; 

    if(DOX1104__M==SWITCH){ 
       DOX1104__V=(DOX1104__V==OFF) then_ ON else_ OFF; 
    }; DOX1104__M= OFF; 

    // блокировка одновременного включения пневмонасосов
    if(DON012___M==SWITCH and REG01R___V==OFF 
                          and DIS011___V==OFF and DON011___V==OFF){ 
       DON012___V=(DON012___V==OFF) then_ ON else_ OFF; 
    }; DON012___M= OFF; 

    if(DON221___M==SWITCH and REG01R___V==OFF){ 
       DON221___V=(DON221___V==OFF) then_ ON else_ OFF; 
    }; DON221___M= OFF; 

    if(DON222___M==SWITCH and REG07R___V==OFF){ 
       DON222___V=(DON222___V==OFF) then_ ON else_ OFF; 
    }; DON222___M= OFF; 

    if(DON061___M==SWITCH and REG02R___V==OFF){ 
       DON061___V=(DON061___V==OFF) then_ ON else_ OFF; 
    }; DON061___M= OFF; 

    if(DON202___M==SWITCH and REG07R___V==OFF){ 
       DON202___V=(DON202___V==OFF) then_ ON else_ OFF; 
    }; DON202___M= OFF; 

    if(DON201___M==SWITCH and REG07R___V==OFF){ 
       DON201___V=(DON201___V==OFF) then_ ON else_ OFF; 
    }; DON201___M= OFF; 

    if(DON232___M==SWITCH and REG07R___V==OFF){ 
       DON232___V=(DON232___V==OFF) then_ ON else_ OFF; 
    }; DON232___M= OFF; 

    // блокировка одновременного включения пневмонасосов
    if(DON101___M==SWITCH and REG05R___V==OFF 
                          and DIS102___V==OFF and DON102___V==OFF){ 
       DON101___V=(DON101___V==OFF) then_ ON else_ OFF; 
    }; DON101___M= OFF;

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON041___V,  0, 0);
    SetMODV (COMU1,rec, 1,  DOX1101__V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON032___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DON031___V,  0, 0);
    SetMODV (COMU1,rec, 4,  DOX1101__V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON012___V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON221___V,  0, 0);
    SetMODV (COMU1,rec, 7,  DON222___V,  0, 0);
    SetMODV (COMU1,rec, 8,  DON061___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DON202___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON201___V,  0, 0);
    SetMODV (COMU1,rec,11,  DON232___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON101___V,  0, 0);

//----------------------------------------------------------------------------
