//----------------------------------------------------------------------------
//  COM1, 7042, N16

    rec=21;

    // ручное переключение с компьютера выходов на исполнители
    if(DON203___M==SWITCH){ 
       DON203___V=(DON203___V==OFF) then_ ON else_ OFF; 
    }; DON203___M= OFF; 

    if(DON223___M==SWITCH){ 
       DON223___V=(DON223___V==OFF) then_ ON else_ OFF; 
    }; DON223___M= OFF; 

    if(DOX1602__M==SWITCH){ 
       DOX1602__V=(DOX1602__V==OFF) then_ ON else_ OFF; 
    }; DOX1602__M= OFF; 

    if(DOX1603__M==SWITCH){ 
       DOX1603__V=(DOX1603__V==OFF) then_ ON else_ OFF; 
    }; DOX1603__M= OFF; 

    if(DOX1604__M==SWITCH){ 
       DOX1604__V=(DOX1604__V==OFF) then_ ON else_ OFF; 
    }; DOX1604__M= OFF; 

    if(DOX1605__M==SWITCH){ 
       DOX1605__V=(DOX1605__V==OFF) then_ ON else_ OFF; 
    }; DOX1605__M= OFF; 

    if(DOX1606__M==SWITCH){ 
       DOX1606__V=(DOX1606__V==OFF) then_ ON else_ OFF; 
    }; DOX1606__M= OFF; 

    if(DOX1607__M==SWITCH){ 
       DOX1607__V=(DOX1607__V==OFF) then_ ON else_ OFF; 
    }; DOX1607__M= OFF; 

    if(DOX1608__M==SWITCH){ 
       DOX1608__V=(DOX1608__V==OFF) then_ ON else_ OFF; 
    }; DOX1608__M= OFF; 

    if(DOX1609__M==SWITCH){ 
       DOX1609__V=(DOX1609__V==OFF) then_ ON else_ OFF; 
    }; DOX1609__M= OFF; 

    if(DOX1610__M==SWITCH){ 
       DOX1610__V=(DOX1610__V==OFF) then_ ON else_ OFF; 
    }; DOX1610__M= OFF; 

    if(DON900___M==SWITCH){ 
       DON900___V=(DON900___V==OFF) then_ ON else_ OFF; 
    }; DON900___M= OFF; 

    if(DON702___M==SWITCH){ 
       DON702___V=(DON702___V==OFF) then_ ON else_ OFF; 
    }; DON702___M= OFF; 

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DON203___V,  0, 0);
    SetMODV (COMU1,rec, 1,  DON223___V,  0, 0);
    SetMODV (COMU1,rec, 2,  DOX1602__V,  0, 0);
    SetMODV (COMU1,rec, 3,  DOX1603__V,  0, 0);
    SetMODV (COMU1,rec, 4,  DOX1604__V,  0, 0);
    SetMODV (COMU1,rec, 5,  DOX1605__V,  0, 0);
    SetMODV (COMU1,rec, 6,  DOX1606__V,  0, 0);
    SetMODV (COMU1,rec, 7,  DOX1607__V,  0, 0);
    SetMODV (COMU1,rec, 8,  DOX1608__V,  0, 0);
    SetMODV (COMU1,rec, 9,  DOX1609__V,  0, 0);
    SetMODV (COMU1,rec,10,  DOX1610__V,  0, 0);
    SetMODV (COMU1,rec,11,  DON900___V,  0, 0);
    SetMODV (COMU1,rec,12,  DON702___V,  0, 0);

//----------------------------------------------------------------------------
