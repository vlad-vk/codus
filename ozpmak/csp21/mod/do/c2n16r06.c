//----------------------------------------------------------------------------
//  COM2, 7042, N16

    rec= 6;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A1STEP___V==0){
        O1GNS____M=(O1GNS____M>OFF) then_ ON else_ OFF; 
        //
        if (O1HM1UP__M> OFF){
            O1HM1UP__M=(O1HM1DN__M>OFF) then_ OFF else_ ON; O1HM1DN__M= OFF;
        }
        if (O1HM1DN__M> OFF){
            O1HM1DN__M=(O1HM1UP__M>OFF) then_ OFF else_ ON; O1HM1UP__M= OFF;
        }
        //
        if (O1KR1O___M==ON){
            O1KR1O___M=(O1KR1C___M>OFF) then_ OFF else_ ON; O1KR1C___M= OFF;
        }
        if (O1KR1C___M==ON){
            O1KR1C___M=(O1KR1O___M>OFF) then_ OFF else_ ON; O1KR1O___M= OFF;
        }
        //
        if (O1BY1O___M==ON){
            O1BY1O___M=(O1BY1C___M>OFF) then_ OFF else_ ON; O1BY1C___M= OFF;
        }
        if (O1BY1C___M==ON){
            O1BY1C___M=(O1BY1O___M>OFF) then_ OFF else_ ON; O1BY1O___M= OFF;
        }
        //
        if (O1HM2UP__M==ON){
            O1HM2UP__M=(O1HM2DN__M>OFF) then_ OFF else_ ON; O1HM2DN__M= OFF;
        }
        if (O1HM2DN__M==ON){
            O1HM2DN__M=(O1HM2UP__M>OFF) then_ OFF else_ ON; O1HM2UP__M= OFF;
        }
        //
        if (O1KR2O___M==ON){
            O1KR2O___M=(O1KR2C___M>OFF) then_ OFF else_ ON; O1KR2C___M= OFF;
        }
        if (O1KR2C___M==ON){
            O1KR2C___M=(O1KR2O___M>OFF) then_ OFF else_ ON; O1KR2O___M= OFF;
        }
        //
        if (O1BY2O___M==ON){
            O1BY2O___M=(O1BY2C___M>OFF) then_ OFF else_ ON; O1BY2C___M= OFF;
        }
        if (O1BY2C___M==ON){
            O1BY2C___M=(O1BY2O___M>OFF) then_ OFF else_ ON; O1BY2O___M= OFF;
        }
    }
    //------------------------------------------------------------------------
    O1GNS____V= O1GNS____M;

    O1HM1UP__V= O1HM1UP__M;
    O1HM1DN__V= O1HM1DN__M;
    U1HM1____V=3;
    if(O1HM1UP__V==OFF&&O1HM1DN__V==OFF) U1HM1____V=0;
    if(O1HM1UP__V==ON &&O1HM1DN__V==OFF) U1HM1____V=1;
    if(O1HM1UP__V==OFF&&O1HM1DN__V==ON ) U1HM1____V=2;

    O1KR1O___V= O1KR1O___M;
    O1KR1C___V= O1KR1C___M;
    U1KR1____V=3;
    if(O1KR1O___V==OFF&&O1KR1C___V==OFF) U1KR1____V=0;
    if(O1KR1O___V==ON &&O1KR1C___V==OFF) U1KR1____V=1;
    if(O1KR1O___V==OFF&&O1KR1C___V==ON ) U1KR1____V=2;

    O1BY1O___V= O1BY1O___M;
    O1BY1C___V= O1BY1C___M;
    U1BY1____V=3;
    if(O1BY1O___V==OFF&&O1BY1C___V==OFF) U1BY1____V=0;
    if(O1BY1O___V==ON &&O1BY1C___V==OFF) U1BY1____V=1;
    if(O1BY1O___V==OFF&&O1BY1C___V==ON ) U1BY1____V=2;

    O1HM2UP__V= O1HM2UP__M;
    O1HM2DN__V= O1HM2DN__M;
    U1HM2____V=3;
    if(O1HM2UP__V==OFF&&O1HM2DN__V==OFF) U1HM2____V=0;
    if(O1HM2UP__V==ON &&O1HM2DN__V==OFF) U1HM2____V=1;
    if(O1HM2UP__V==OFF&&O1HM2DN__V==ON ) U1HM2____V=2;

    O1KR2O___V= O1KR2O___M;
    O1KR2C___V= O1KR2C___M;
    U1KR2____V=3;
    if(O1KR2O___V==OFF&&O1KR2C___V==OFF) U1KR2____V=0;
    if(O1KR2O___V==ON &&O1KR2C___V==OFF) U1KR2____V=1;
    if(O1KR2O___V==OFF&&O1KR2C___V==ON ) U1KR2____V=2;

    O1BY2O___V= O1BY2O___M;
    O1BY2C___V= O1BY2C___M;
    U1BY2____V=3;
    if(O1BY2O___V==OFF&&O1BY2C___V==OFF) U1BY2____V=0;
    if(O1BY2O___V==ON &&O1BY2C___V==OFF) U1BY2____V=1;
    if(O1BY2O___V==OFF&&O1BY2C___V==ON ) U1BY2____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O1GNS____V,  0, 0);

    SetMODV (COMU1,rec, 1, O1HM1UP__V,  0, 0);
    SetMODV (COMU1,rec, 2, O1HM1DN__V,  0, 0);

    SetMODV (COMU1,rec, 3, O1KR1O___V,  0, 0);
    SetMODV (COMU1,rec, 4, O1KR1C___V,  0, 0);

    SetMODV (COMU1,rec, 5, O1BY1O___V,  0, 0);
    SetMODV (COMU1,rec, 6, O1BY1C___V,  0, 0);

    SetMODV (COMU1,rec, 7, O1HM2UP__V,  0, 0);
    SetMODV (COMU1,rec, 8, O1HM2DN__V,  0, 0);

    SetMODV (COMU1,rec, 9, O1KR2O___V,  0, 0);
    SetMODV (COMU1,rec,10, O1KR2C___V,  0, 0);

    SetMODV (COMU1,rec,11, O1BY2O___V,  0, 0);
    SetMODV (COMU1,rec,12, O1BY2C___V,  0, 0);

//----------------------------------------------------------------------------
