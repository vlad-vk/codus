//----------------------------------------------------------------------------
//  COM2, 7042, N36

    rec= 6;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A3STEP___V==0){
        O3GNS____M=(O3GNS____M>OFF) then_ ON else_ OFF; 
        //
        if (O3HM1UP__M> OFF){
            O3HM1UP__M=(O3HM1DN__M>OFF) then_ OFF else_ ON; O3HM1DN__M= OFF;
        }
        if (O3HM1DN__M> OFF){
            O3HM1DN__M=(O3HM1UP__M>OFF) then_ OFF else_ ON; O3HM1UP__M= OFF;
        }
        //
        if (O3KR1O___M==ON){
            O3KR1O___M=(O3KR1C___M>OFF) then_ OFF else_ ON; O3KR1C___M= OFF;
        }
        if (O3KR1C___M==ON){
            O3KR1C___M=(O3KR1O___M>OFF) then_ OFF else_ ON; O3KR1O___M= OFF;
        }
        //
        if (O3BY1O___M==ON){
            O3BY1O___M=(O3BY1C___M>OFF) then_ OFF else_ ON; O3BY1C___M= OFF;
        }
        if (O3BY1C___M==ON){
            O3BY1C___M=(O3BY1O___M>OFF) then_ OFF else_ ON; O3BY1O___M= OFF;
        }
        //
        if (O3HM2UP__M==ON){
            O3HM2UP__M=(O3HM2DN__M>OFF) then_ OFF else_ ON; O3HM2DN__M= OFF;
        }
        if (O3HM2DN__M==ON){
            O3HM2DN__M=(O3HM2UP__M>OFF) then_ OFF else_ ON; O3HM2UP__M= OFF;
        }
        //
        if (O3KR2O___M==ON){
            O3KR2O___M=(O3KR2C___M>OFF) then_ OFF else_ ON; O3KR2C___M= OFF;
        }
        if (O3KR2C___M==ON){
            O3KR2C___M=(O3KR2O___M>OFF) then_ OFF else_ ON; O3KR2O___M= OFF;
        }
        //
        if (O3BY2O___M==ON){
            O3BY2O___M=(O3BY2C___M>OFF) then_ OFF else_ ON; O3BY2C___M= OFF;
        }
        if (O3BY2C___M==ON){
            O3BY2C___M=(O3BY2O___M>OFF) then_ OFF else_ ON; O3BY2O___M= OFF;
        }
    }
    //------------------------------------------------------------------------
    O3GNS____V= O3GNS____M;

    O3HM1UP__V= O3HM1UP__M;
    O3HM1DN__V= O3HM1DN__M;
    U3HM1____V=3;
    if(O3HM1UP__V==OFF&&O3HM1DN__V==OFF) U3HM1____V=0;
    if(O3HM1UP__V==ON &&O3HM1DN__V==OFF) U3HM1____V=1;
    if(O3HM1UP__V==OFF&&O3HM1DN__V==ON ) U3HM1____V=2;

    O3KR1O___V= O3KR1O___M;
    O3KR1C___V= O3KR1C___M;
    U3KR1____V=3;
    if(O3KR1O___V==OFF&&O3KR1C___V==OFF) U3KR1____V=0;
    if(O3KR1O___V==ON &&O3KR1C___V==OFF) U3KR1____V=1;
    if(O3KR1O___V==OFF&&O3KR1C___V==ON ) U3KR1____V=2;

    O3BY1O___V= O3BY1O___M;
    O3BY1C___V= O3BY1C___M;
    U3BY1____V=3;
    if(O3BY1O___V==OFF&&O3BY1C___V==OFF) U3BY1____V=0;
    if(O3BY1O___V==ON &&O3BY1C___V==OFF) U3BY1____V=1;
    if(O3BY1O___V==OFF&&O3BY1C___V==ON ) U3BY1____V=2;

    O3HM2UP__V= O3HM2UP__M;
    O3HM2DN__V= O3HM2DN__M;
    U3HM2____V=3;
    if(O3HM2UP__V==OFF&&O3HM2DN__V==OFF) U3HM2____V=0;
    if(O3HM2UP__V==ON &&O3HM2DN__V==OFF) U3HM2____V=1;
    if(O3HM2UP__V==OFF&&O3HM2DN__V==ON ) U3HM2____V=2;

    O3KR2O___V= O3KR2O___M;
    O3KR2C___V= O3KR2C___M;
    U3KR2____V=3;
    if(O3KR2O___V==OFF&&O3KR2C___V==OFF) U3KR2____V=0;
    if(O3KR2O___V==ON &&O3KR2C___V==OFF) U3KR2____V=1;
    if(O3KR2O___V==OFF&&O3KR2C___V==ON ) U3KR2____V=2;

    O3BY2O___V= O3BY2O___M;
    O3BY2C___V= O3BY2C___M;
    U3BY2____V=3;
    if(O3BY2O___V==OFF&&O3BY2C___V==OFF) U3BY2____V=0;
    if(O3BY2O___V==ON &&O3BY2C___V==OFF) U3BY2____V=1;
    if(O3BY2O___V==OFF&&O3BY2C___V==ON ) U3BY2____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O3GNS____V,  0, 0);

    SetMODV (COMU1,rec, 1, O3HM1UP__V,  0, 0);
    SetMODV (COMU1,rec, 2, O3HM1DN__V,  0, 0);

    SetMODV (COMU1,rec, 3, O3KR1O___V,  0, 0);
    SetMODV (COMU1,rec, 4, O3KR1C___V,  0, 0);

    SetMODV (COMU1,rec, 5, O3BY1O___V,  0, 0);
    SetMODV (COMU1,rec, 6, O3BY1C___V,  0, 0);

    SetMODV (COMU1,rec, 7, O3HM2UP__V,  0, 0);
    SetMODV (COMU1,rec, 8, O3HM2DN__V,  0, 0);

    SetMODV (COMU1,rec, 9, O3KR2O___V,  0, 0);
    SetMODV (COMU1,rec,10, O3KR2C___V,  0, 0);

    SetMODV (COMU1,rec,11, O3BY2O___V,  0, 0);
    SetMODV (COMU1,rec,12, O3BY2C___V,  0, 0);

//----------------------------------------------------------------------------
