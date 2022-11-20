//----------------------------------------------------------------------------
//  COM2, 7042, N46

    rec= 16;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A4STEP___V==0){
        O4GNS____M=(O4GNS____M>OFF) then_ ON else_ OFF;
        //
        if (O4HM1UP__M> OFF){
            O4HM1UP__M=(O4HM1DN__M>OFF) then_ OFF else_ ON; O4HM1DN__M= OFF;
        }
        if (O4HM1DN__M> OFF){
            O4HM1DN__M=(O4HM1UP__M>OFF) then_ OFF else_ ON; O4HM1UP__M= OFF;
        }
        //
        if (O4KR1O___M==ON){
            O4KR1O___M=(O4KR1C___M>OFF) then_ OFF else_ ON; O4KR1C___M= OFF;
        }
        if (O4KR1C___M==ON){
            O4KR1C___M=(O4KR1O___M>OFF) then_ OFF else_ ON; O4KR1O___M= OFF;
        }
        //
        if (O4BY1O___M==ON){
            O4BY1O___M=(O4BY1C___M>OFF) then_ OFF else_ ON; O4BY1C___M= OFF;
        }
        if (O4BY1C___M==ON){
            O4BY1C___M=(O4BY1O___M>OFF) then_ OFF else_ ON; O4BY1O___M= OFF;
        }
        //
        if (O4HM2UP__M==ON){
            O4HM2UP__M=(O4HM2DN__M>OFF) then_ OFF else_ ON; O4HM2DN__M= OFF;
        }
        if (O4HM2DN__M==ON){
            O4HM2DN__M=(O4HM2UP__M>OFF) then_ OFF else_ ON; O4HM2UP__M= OFF;
        }
        //
        if (O4KR2O___M==ON){
            O4KR2O___M=(O4KR2C___M>OFF) then_ OFF else_ ON; O4KR2C___M= OFF;
        }
        if (O4KR2C___M==ON){
            O4KR2C___M=(O4KR2O___M>OFF) then_ OFF else_ ON; O4KR2O___M= OFF;
        }
        //
        if (O4BY2O___M==ON){
            O4BY2O___M=(O4BY2C___M>OFF) then_ OFF else_ ON; O4BY2C___M= OFF;
        }
        if (O4BY2C___M==ON){
            O4BY2C___M=(O4BY2O___M>OFF) then_ OFF else_ ON; O4BY2O___M= OFF;
        }
    }

    //------------------------------------------------------------------------
    O4GNS____V= O4GNS____M;

    O4HM1UP__V= O4HM1UP__M;
    O4HM1DN__V= O4HM1DN__M;
    U4HM1____V=3;
    if(O4HM1UP__V==OFF&&O4HM1DN__V==OFF) U4HM1____V=0;
    if(O4HM1UP__V==ON &&O4HM1DN__V==OFF) U4HM1____V=1;
    if(O4HM1UP__V==OFF&&O4HM1DN__V==ON ) U4HM1____V=2;

    O4KR1O___V= O4KR1O___M;
    O4KR1C___V= O4KR1C___M;
    U4KR1____V=3;
    if(O4KR1O___V==OFF&&O4KR1C___V==OFF) U4KR1____V=0;
    if(O4KR1O___V==ON &&O4KR1C___V==OFF) U4KR1____V=1;
    if(O4KR1O___V==OFF&&O4KR1C___V==ON ) U4KR1____V=2;

    O4BY1O___V= O4BY1O___M;
    O4BY1C___V= O4BY1C___M;
    U4BY1____V=3;
    if(O4BY1O___V==OFF&&O4BY1C___V==OFF) U4BY1____V=0;
    if(O4BY1O___V==ON &&O4BY1C___V==OFF) U4BY1____V=1;
    if(O4BY1O___V==OFF&&O4BY1C___V==ON ) U4BY1____V=2;

    O4HM2UP__V= O4HM2UP__M;
    O4HM2DN__V= O4HM2DN__M;
    U4HM2____V=3;
    if(O4HM2UP__V==OFF&&O4HM2DN__V==OFF) U4HM2____V=0;
    if(O4HM2UP__V==ON &&O4HM2DN__V==OFF) U4HM2____V=1;
    if(O4HM2UP__V==OFF&&O4HM2DN__V==ON ) U4HM2____V=2;

    O4KR2O___V= O4KR2O___M;
    O4KR2C___V= O4KR2C___M;
    U4KR2____V=3;
    if(O4KR2O___V==OFF&&O4KR2C___V==OFF) U4KR2____V=0;
    if(O4KR2O___V==ON &&O4KR2C___V==OFF) U4KR2____V=1;
    if(O4KR2O___V==OFF&&O4KR2C___V==ON ) U4KR2____V=2;

    O4BY2O___V= O4BY2O___M;
    O4BY2C___V= O4BY2C___M;
    U4BY2____V=3;
    if(O4BY2O___V==OFF&&O4BY2C___V==OFF) U4BY2____V=0;
    if(O4BY2O___V==ON &&O4BY2C___V==OFF) U4BY2____V=1;
    if(O4BY2O___V==OFF&&O4BY2C___V==ON ) U4BY2____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O4GNS____V,  0, 0);
    SetMODV (COMU1,rec, 1, O4HM1UP__V,  0, 0);
    SetMODV (COMU1,rec, 2, O4HM1DN__V,  0, 0);
    SetMODV (COMU1,rec, 3, O4KR1O___V,  0, 0);
    SetMODV (COMU1,rec, 4, O4KR1C___V,  0, 0);
    SetMODV (COMU1,rec, 5, O4BY1O___V,  0, 0);
    SetMODV (COMU1,rec, 6, O4BY1C___V,  0, 0);
    SetMODV (COMU1,rec, 7, O4HM2UP__V,  0, 0);
    SetMODV (COMU1,rec, 8, O4HM2DN__V,  0, 0);
    SetMODV (COMU1,rec, 9, O4KR2O___V,  0, 0);
    SetMODV (COMU1,rec,10, O4KR2C___V,  0, 0);
    SetMODV (COMU1,rec,11, O4BY2O___V,  0, 0);
    SetMODV (COMU1,rec,12, O4BY2C___V,  0, 0);

//----------------------------------------------------------------------------
