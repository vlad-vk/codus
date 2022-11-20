//----------------------------------------------------------------------------
//  COM1, 7042, N10

    rec=15;

    // ручное переключение с компьютера выходов на исполнители
    if(DON053O__M==SWITCH and AOT050__RV==MANUAL){ 
       DON053O__V=(DON053O__V==ON) then_ OFF else_ ON;
    }; DON053O__M= OFF;

    if(DON053C__M==SWITCH and AOT050__RV==MANUAL){ 
       DON053C__V=(DON053C__V==ON) then_ OFF else_ ON;
    }; DON053C__M= OFF;

    if(DON043O__M==SWITCH and AOT040__RV==MANUAL){ 
       DON043O__V=(DON043O__V==ON) then_ OFF else_ ON;
    }; DON043O__M= OFF;

    if(DON043C__M==SWITCH and AOT040__RV==MANUAL){ 
       DON043C__V=(DON043C__V==ON) then_ OFF else_ ON;
    }; DON043C__M= OFF;

    if(DON033O__M==SWITCH and AOT030__RV==MANUAL){ 
       DON033O__V=(DON033O__V==ON) then_ OFF else_ ON;
    }; DON033O__M= OFF;

    if(DON033C__M==SWITCH and AOT030__RV==MANUAL){ 
       DON033C__V=(DON033C__V==OFF) then_ ON else_ OFF; 
    }; DON033C__M= OFF;

    // блокировка одновременного включения пневмонасосов
    if(DON021___M==SWITCH and REG01R___V==OFF 
                          and DIS022___V==OFF and DON022___V==OFF){ 
       DON021___V=(DON021___V==OFF) then_ ON else_ OFF; 
    }; DON021___M= OFF;

    // блокировка одновременного включения пневмонасосов
    if(DON011___M==SWITCH and REG01R___V==OFF and 
                              DIS012___V==OFF and DON012___V==OFF){ 
       DON011___V=(DON011___V==OFF) then_ ON else_ OFF; 
    }; DON011___M= OFF;

    if(DON052___M==SWITCH and REG01R___V==OFF){ 
       DON052___V=(DON052___V==OFF) then_ ON else_ OFF; 
    }; DON052___M= OFF; 

    if(DON051___M==SWITCH and REG01R___V==OFF){ 
       DON051___V=(DON051___V==OFF) then_ ON else_ OFF; 
    }; DON051___M= OFF; 

    if(DON051___M==SWITCH and REG01R___V==OFF){ 
       DON051___V=(DON051___V==OFF) then_ ON else_ OFF; 
    }; DON051___M= OFF; 

    // блокировка одновременного включения пневмонасосов
    if(DON022___M==SWITCH and REG01R___V==OFF 
                          and DIS021___V==OFF and DON021___V==OFF){ 
       DON022___V=(DON022___V==OFF) then_ ON else_ OFF; 
    }; DON022___M= OFF; 

    if(DON042___M==SWITCH and REG01R___V==OFF){ 
       DON042___V=(DON042___V==OFF) then_ ON else_ OFF; 
    }; DON042___M= OFF; 

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON053O__V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON053C__V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON043O__V,  0, 0);
    SetMODV (COMU1,rec, 3,  DON043C__V,  0, 0);
    SetMODV (COMU1,rec, 4,  DON033O__V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON033C__V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON021___V,  0, 0);
    SetMODV (COMU1,rec, 7,  DON011___V,  0, 0);
    SetMODV (COMU1,rec, 8,  DON052___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DON051___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON051___V,  0, 0);       // Резерв
    SetMODV (COMU1,rec,11,  DON022___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON042___V,  0, 0);

//----------------------------------------------------------------------------
