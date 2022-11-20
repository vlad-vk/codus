//----------------------------------------------------------------------------
//  COM1, 7042, N14

    rec=19;

    // ручное переключение с компьютера выходов на исполнители
    if(DON273O__M==SWITCH and AOT270__RV==MANUAL){ 
       DON273O__V=(DON273O__V==OFF) then_ ON else_ OFF; 
    }; DON273O__M= OFF; 

    if(DON273C__M==SWITCH and AOT270__RV==MANUAL){ 
       DON273C__V=(DON273C__V==OFF) then_ ON else_ OFF; 
    }; DON273C__M= OFF; 

    if(DON272___M==SWITCH and REG10R___V==OFF){ 
       DON272___V=(DON272___V==OFF) then_ ON else_ OFF; 
    }; DON272___M= OFF; 


    if(DON274___M==SWITCH and REG10R___V==OFF){ 
       DON274___V=(DON274___V==OFF) then_ ON else_ OFF; 
    }; DON274___M= OFF; 

    if(DON285___M==SWITCH and REG09R___V==OFF){ 
       DON285___V=(DON285___V==OFF) then_ ON else_ OFF; 
    }; DON285___M= OFF; 

    if(DON286___M==SWITCH and REG09R___V==OFF){ 
       DON286___V=(DON286___V==OFF) then_ ON else_ OFF; 
    }; DON286___M= OFF; 


    if(DON301___M==SWITCH and REG10R___V==OFF){ 
       DON301___V=(DON301___V==OFF) then_ ON else_ OFF; 
    }; DON301___M= OFF; 

    if(DON291___M==SWITCH and REG09R___V==OFF){ 
       DON291___V=(DON291___V==OFF) then_ ON else_ OFF; 
    }; DON291___M= OFF; 

    if(DON193___M==SWITCH and REG06R___V==OFF){ 
       DON193___V=(DON193___V==OFF) then_ ON else_ OFF; 
    }; DON193___M= OFF; 

    if(DON231___M==SWITCH and REG07R___V==OFF){ 
       DON231___V=(DON231___V==OFF) then_ ON else_ OFF; 
    }; DON231___M= OFF; 


    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON273O__V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON273C__V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON272___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DOX1403__V,  0, 0);

    SetMODV (COMU1,rec, 4,  DON274___V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON285___V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON286___V,  0, 0);

    SetMODV (COMU1,rec, 7,  DOX1407__V,  0, 0);
    SetMODV (COMU1,rec, 8,  DOX1408__V,  0, 0);

    SetMODV (COMU1,rec, 9,  DON301___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON291___V,  0, 0);
    SetMODV (COMU1,rec,11,  DON193___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON231___V,  0, 0);

//----------------------------------------------------------------------------
