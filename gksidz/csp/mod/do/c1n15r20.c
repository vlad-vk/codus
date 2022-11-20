//----------------------------------------------------------------------------
//  COM1, 7042, N15

    rec=20;

    // ручное переключение с компьютера выходов на исполнители
    if(DON316___M==SWITCH and REG10R___V==OFF and DIS315___V==OFF){ 
       DON316___V=(DON316___V==OFF) then_ ON else_ OFF; 
    }; DON316___M= OFF; 

    if(DON317___M==SWITCH and REG10R___V==OFF and DIS315___V==OFF){ 
       DON317___V=(DON317___V==OFF) then_ ON else_ OFF; 
    }; DON317___M= OFF; 

    if(DON31A___M==SWITCH and REG10R___V==OFF){ 
       DON31A___V=(DON31A___V==OFF) then_ ON else_ OFF; 
    }; DON31A___M= OFF; 

    if(DON310___M==SWITCH and REG10R___V==OFF){ 
       DON310___V=(DON310___V==OFF) then_ ON else_ OFF; 
    }; DON310___M= OFF; 

    if(DON192___M==SWITCH and REG06R___V==OFF){ 
       DON192___V=(DON192___V==OFF) then_ ON else_ OFF; 
    }; DON192___M= OFF; 

    if(DON191___M==SWITCH and REG06R___V==OFF){ 
       DON191___V=(DON191___V==OFF) then_ ON else_ OFF; 
    }; DON191___M= OFF; 

    if(DON143___M==SWITCH and REG06R___V==OFF){ 
       DON143___V=(DON143___V==OFF) then_ ON else_ OFF; 
    }; DON143___M= OFF; 

    if(DON173___M==SWITCH and REG06R___V==OFF){ 
       DON173___V=(DON173___V==OFF) then_ ON else_ OFF; 
    }; DON173___M= OFF; 

    if(DON311___M==SWITCH and REG10R___V==OFF){ 
       DON311___V=(DON311___V==OFF) then_ ON else_ OFF; 
       DON312___V=DON313___V=DON314___V=DON311___V;
    }; DON311___M= OFF; 

    if(DON091___M==SWITCH){ 
       DON091___V=(DON091___V==OFF) then_ ON else_ OFF; 
    }; DON091___M= OFF; 

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON316___V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON317___V,  0, 0);
    SetMODV (COMU1,rec, 2,  DON31A___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DON310___V,  0, 0);
    SetMODV (COMU1,rec, 4,  DON192___V,  0, 0);
    SetMODV (COMU1,rec, 5,  DON191___V,  0, 0);
    SetMODV (COMU1,rec, 6,  DON143___V,  0, 0);
    SetMODV (COMU1,rec, 7,  DON173___V,  0, 0);
    SetMODV (COMU1,rec, 8,  DON311___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DON091___V,  0, 0);
    SetMODV (COMU1,rec,10,  DON091___V,  0, 0);
    SetMODV (COMU1,rec,11,  DON091___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON091___V,  0, 0);

//----------------------------------------------------------------------------
