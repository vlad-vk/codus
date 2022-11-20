//----------------------------------------------------------------------------
//  COM2, 7042, N26

    rec= 16;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A2STEP___V==0){
        O2GNS____M=(O2GNS____M>OFF) then_ ON else_ OFF;
        //
        if (O2HM1UP__M> OFF){
            O2HM1UP__M=(O2HM1DN__M>OFF) then_ OFF else_ ON; O2HM1DN__M= OFF;
        }
        if (O2HM1DN__M> OFF){
            O2HM1DN__M=(O2HM1UP__M>OFF) then_ OFF else_ ON; O2HM1UP__M= OFF;
        }
        //
        if (O2KR1O___M==ON){
            O2KR1O___M=(O2KR1C___M>OFF) then_ OFF else_ ON; O2KR1C___M= OFF;
        }
        if (O2KR1C___M==ON){
            O2KR1C___M=(O2KR1O___M>OFF) then_ OFF else_ ON; O2KR1O___M= OFF;
        }
        //
        if (O2BY1O___M==ON){
            O2BY1O___M=(O2BY1C___M>OFF) then_ OFF else_ ON; O2BY1C___M= OFF;
        }
        if (O2BY1C___M==ON){
            O2BY1C___M=(O2BY1O___M>OFF) then_ OFF else_ ON; O2BY1O___M= OFF;
        }
        //
        if (O2HM2UP__M==ON){
            O2HM2UP__M=(O2HM2DN__M>OFF) then_ OFF else_ ON; O2HM2DN__M= OFF;
        }
        if (O2HM2DN__M==ON){
            O2HM2DN__M=(O2HM2UP__M>OFF) then_ OFF else_ ON; O2HM2UP__M= OFF;
        }
        //
        if (O2KR2O___M==ON){
            O2KR2O___M=(O2KR2C___M>OFF) then_ OFF else_ ON; O2KR2C___M= OFF;
        }
        if (O2KR2C___M==ON){
            O2KR2C___M=(O2KR2O___M>OFF) then_ OFF else_ ON; O2KR2O___M= OFF;
        }
        //
        if (O2BY2O___M==ON){
            O2BY2O___M=(O2BY2C___M>OFF) then_ OFF else_ ON; O2BY2C___M= OFF;
        }
        if (O2BY2C___M==ON){
            O2BY2C___M=(O2BY2O___M>OFF) then_ OFF else_ ON; O2BY2O___M= OFF;
        }
    }

    //------------------------------------------------------------------------
    O2GNS____V= O2GNS____M;

    O2HM1UP__V= O2HM1UP__M;
    O2HM1DN__V= O2HM1DN__M;
    U2HM1____V=3;
    if(O2HM1UP__V==OFF&&O2HM1DN__V==OFF) U2HM1____V=0;
    if(O2HM1UP__V==ON &&O2HM1DN__V==OFF) U2HM1____V=1;
    if(O2HM1UP__V==OFF&&O2HM1DN__V==ON ) U2HM1____V=2;

    O2KR1O___V= O2KR1O___M;
    O2KR1C___V= O2KR1C___M;
    U2KR1____V=3;
    if(O2KR1O___V==OFF&&O2KR1C___V==OFF) U2KR1____V=0;
    if(O2KR1O___V==ON &&O2KR1C___V==OFF) U2KR1____V=1;
    if(O2KR1O___V==OFF&&O2KR1C___V==ON ) U2KR1____V=2;

    O2BY1O___V= O2BY1O___M;
    O2BY1C___V= O2BY1C___M;
    U2BY1____V=3;
    if(O2BY1O___V==OFF&&O2BY1C___V==OFF) U2BY1____V=0;
    if(O2BY1O___V==ON &&O2BY1C___V==OFF) U2BY1____V=1;
    if(O2BY1O___V==OFF&&O2BY1C___V==ON ) U2BY1____V=2;

    O2HM2UP__V= O2HM2UP__M;
    O2HM2DN__V= O2HM2DN__M;
    U2HM2____V=3;
    if(O2HM2UP__V==OFF&&O2HM2DN__V==OFF) U2HM2____V=0;
    if(O2HM2UP__V==ON &&O2HM2DN__V==OFF) U2HM2____V=1;
    if(O2HM2UP__V==OFF&&O2HM2DN__V==ON ) U2HM2____V=2;

    O2KR2O___V= O2KR2O___M;
    O2KR2C___V= O2KR2C___M;
    U2KR2____V=3;
    if(O2KR2O___V==OFF&&O2KR2C___V==OFF) U2KR2____V=0;
    if(O2KR2O___V==ON &&O2KR2C___V==OFF) U2KR2____V=1;
    if(O2KR2O___V==OFF&&O2KR2C___V==ON ) U2KR2____V=2;

    O2BY2O___V= O2BY2O___M;
    O2BY2C___V= O2BY2C___M;
    U2BY2____V=3;
    if(O2BY2O___V==OFF&&O2BY2C___V==OFF) U2BY2____V=0;
    if(O2BY2O___V==ON &&O2BY2C___V==OFF) U2BY2____V=1;
    if(O2BY2O___V==OFF&&O2BY2C___V==ON ) U2BY2____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O2GNS____V,  0, 0);
    SetMODV (COMU1,rec, 1, O2HM1UP__V,  0, 0);
    SetMODV (COMU1,rec, 2, O2HM1DN__V,  0, 0);
    SetMODV (COMU1,rec, 3, O2KR1O___V,  0, 0);
    SetMODV (COMU1,rec, 4, O2KR1C___V,  0, 0);
    SetMODV (COMU1,rec, 5, O2BY1O___V,  0, 0);
    SetMODV (COMU1,rec, 6, O2BY1C___V,  0, 0);
    SetMODV (COMU1,rec, 7, O2HM2UP__V,  0, 0);
    SetMODV (COMU1,rec, 8, O2HM2DN__V,  0, 0);
    SetMODV (COMU1,rec, 9, O2KR2O___V,  0, 0);
    SetMODV (COMU1,rec,10, O2KR2C___V,  0, 0);
    SetMODV (COMU1,rec,11, O2BY2O___V,  0, 0);
    SetMODV (COMU1,rec,12, O2BY2C___V,  0, 0);

//----------------------------------------------------------------------------
