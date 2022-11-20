//----------------------------------------------------------------------------
//  COM1, 7042, N12

    rec=17;

    // ручное переключение с компьютера выходов на исполнители
    if(DON172___M==SWITCH && REG06R___V==OFF){ 
       DON172___V=(DON172___V==OFF) then_ ON else_ OFF; 
    }; DON172___M= OFF; 

    if(DON181___M==SWITCH && REG06R___V==OFF){ 
       DON181___V=(DON181___V==OFF) then_ ON else_ OFF; 
    }; DON181___M= OFF; 

    if(DON182___M==SWITCH && REG06R___V==OFF){ 
       DON182___V=(DON182___V==OFF) then_ ON else_ OFF; 
    }; DON182___M= OFF; 

    if(DON162___M==SWITCH && REG06R___V==OFF){ 
       DON162___V=(DON162___V==OFF) then_ ON else_ OFF; 
    }; DON162___M= OFF; 

    if(DON180___M==SWITCH && REG06R___V==OFF){ 
       DON180___V=(DON180___V==OFF) then_ ON else_ OFF; 
    }; DON180___M= OFF; 

    if(DON150___M==SWITCH && REG06R___V==OFF){ 
       DON150___V=(DON150___V==OFF) then_ ON else_ OFF; 
    }; DON150___M= OFF; 

    if(DON151___M==SWITCH && REG06R___V==OFF){ 
       DON151___V=(DON151___V==OFF) then_ ON else_ OFF; 
    }; DON151___M= OFF; 

    if(DON152___M==SWITCH && REG06R___V==OFF){ 
       DON152___V=(DON152___V==OFF) then_ ON else_ OFF; 
    }; DON152___M= OFF; 

    if(DON132___M==SWITCH && REG06R___V==OFF){ 
       DON132___V=(DON132___V==OFF) then_ ON else_ OFF; 
    }; DON132___M= OFF; 

    if(DON211___M==SWITCH && REG07R___V==OFF){ 
       DON211___V=(DON211___V==OFF) then_ ON else_ OFF; 
    }; DON211___M= OFF; 

    if(DON212___M==SWITCH && REG07R___V==OFF){ 
       DON212___V=(DON212___V==OFF) then_ ON else_ OFF; 
    }; DON212___M= OFF; 

    if(DON281___M==SWITCH && REG09R___V==OFF){ 
       DON281___V=(DON281___V==OFF) then_ ON else_ OFF; 
    }; DON281___M= OFF; 


    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON172___V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON181___V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON182___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DON162___V,  0, 0);
    SetMODV (COMU1,rec, 4,  DON180___V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON150___V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON151___V,  0, 0);
    SetMODV (COMU1,rec, 7,  DON152___V,  0, 0);
    SetMODV (COMU1,rec, 8,  DON132___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DON211___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON212___V,  0, 0);
    SetMODV (COMU1,rec,11,  DOX1211__V,  0, 0);
    SetMODV (COMU1,rec,12,  DON281___V,  0, 0);

//----------------------------------------------------------------------------
