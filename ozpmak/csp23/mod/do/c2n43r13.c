//----------------------------------------------------------------------------
//  COM2, 7042, N43

    rec= 13;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A4STEP___V==0){
        if (O4ZIOPO__M> OFF){
            O4ZIOPO__M=(O4ZIOPC__M>OFF) then_ OFF else_ ON; O4ZIOPC__M= OFF;
        }
        if (O4ZIOPC__M> OFF){
            O4ZIOPC__M=(O4ZIOPO__M>OFF) then_ OFF else_ ON; O4ZIOPO__M= OFF;
        }
        //
        if (O4ZIPPO__M> OFF){
            O4ZIPPO__M=(O4ZIPPC__M>OFF) then_ OFF else_ ON; O4ZIPPC__M= OFF;
        }
        if (O4ZIPPC__M> OFF){
            O4ZIPPC__M=(O4ZIPPO__M>OFF) then_ OFF else_ ON; O4ZIPPO__M= OFF;
        }
        //
        if (O4KIPO___M> OFF){
            O4KIPO___M=(O4KIPC___M>OFF) then_ OFF else_ ON; O4KIPC___M= OFF;
        }
        if (O4KIPC___M> OFF){
            O4KIPC___M=(O4KIPO___M>OFF) then_ OFF else_ ON; O4KIPO___M= OFF;
        }
        //
        if (O4ZOPPO__M> OFF){
            O4ZOPPO__M=(O4ZOPPC__M>OFF) then_ OFF else_ ON; O4ZOPPC__M= OFF;
        }
        if (O4ZOPPC__M> OFF){
            O4ZOPPC__M=(O4ZOPPO__M>OFF) then_ OFF else_ ON; O4ZOPPO__M= OFF;
        }
        //
        if (O4ZOPAO__M> OFF){
            O4ZOPAO__M=(O4ZOPAC__M>OFF) then_ OFF else_ ON; O4ZOPAC__M= OFF;
        }
        if (O4ZOPAC__M> OFF){
            O4ZOPAC__M=(O4ZOPAO__M>OFF) then_ OFF else_ ON; O4ZOPAO__M= OFF;
        }
        //
        if (O4KOPO___M> OFF){
            O4KOPO___M=(O4KOPC___M>OFF) then_ OFF else_ ON; O4KOPC___M= OFF;
        }
        if (O4KOPC___M> OFF){
            O4KOPC___M=(O4KOPO___M>OFF) then_ OFF else_ ON; O4KOPO___M= OFF;
        }
    }

    //------------------------------------------------------------------------
    O4ZIOPO__V= O4ZIOPO__M;
    O4ZIOPC__V= O4ZIOPC__M;
    U4ZIOP___V=3;                                       // оба сигнала
    if(O4ZIOPO__V==OFF&&O4ZIOPC__V==OFF) U4ZIOP___V=0;  // нет сигнала
    if(O4ZIOPO__V==ON &&O4ZIOPC__V==OFF) U4ZIOP___V=1;  // на  открытие
    if(O4ZIOPO__V==OFF&&O4ZIOPC__V==ON ) U4ZIOP___V=2;  // на  закрытие

    O4ZIPPO__V= O4ZIPPO__M;
    O4ZIPPC__V= O4ZIPPC__M;
    U4ZIPP___V=3;
    if(O4ZIPPO__V==OFF&&O4ZIPPC__V==OFF) U4ZIPP___V=0;
    if(O4ZIPPO__V==ON &&O4ZIPPC__V==OFF) U4ZIPP___V=1;
    if(O4ZIPPO__V==OFF&&O4ZIPPC__V==ON ) U4ZIPP___V=2;

    O4KIPO___V= O4KIPO___M;
    O4KIPC___V= O4KIPC___M;
    U4KIP____V=3;
    if(O4KIPO___V==OFF&&O4KIPC___V==OFF) U4KIP____V=0;
    if(O4KIPO___V==ON &&O4KIPC___V==OFF) U4KIP____V=1;
    if(O4KIPO___V==OFF&&O4KIPC___V==ON ) U4KIP____V=2;

    O4ZOPPO__V= O4ZOPPO__M;
    O4ZOPPC__V= O4ZOPPC__M;
    U4ZOPP___V=3;
    if(O4ZOPPO__V==OFF&&O4ZOPPC__V==OFF) U4ZOPP___V=0;
    if(O4ZOPPO__V==ON &&O4ZOPPC__V==OFF) U4ZOPP___V=1;
    if(O4ZOPPO__V==OFF&&O4ZOPPC__V==ON ) U4ZOPP___V=2;

    O4ZOPAO__V= O4ZOPAO__M;
    O4ZOPAC__V= O4ZOPAC__M;
    U4ZOPA___V=3;
    if(O4ZOPAO__V==OFF&&O4ZOPAC__V==OFF) U4ZOPA___V=0;
    if(O4ZOPAO__V==ON &&O4ZOPAC__V==OFF) U4ZOPA___V=1;
    if(O4ZOPAO__V==OFF&&O4ZOPAC__V==ON ) U4ZOPA___V=2;

    O4KOPO___V= O4KOPO___M;
    O4KOPC___V= O4KOPC___M;
    U4KOP____V=3;
    if(O4KOPO___V==OFF&&O4KOPC___V==OFF) U4KOP____V=0;
    if(O4KOPO___V==ON &&O4KOPC___V==OFF) U4KOP____V=1;
    if(O4KOPO___V==OFF&&O4KOPC___V==ON ) U4KOP____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O4ZIOPO__V,  0, 0);
    SetMODV (COMU1,rec, 1, O4ZIOPC__V,  0, 0);

    SetMODV (COMU1,rec, 2, O4ZIPPO__V,  0, 0);
    SetMODV (COMU1,rec, 3, O4ZIPPC__V,  0, 0);

    SetMODV (COMU1,rec, 4, O4KIPO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O4KIPC___V,  0, 0);

    SetMODV (COMU1,rec, 6, O4ZOPPO__V,  0, 0);
    SetMODV (COMU1,rec, 7, O4ZOPPC__V,  0, 0);

    SetMODV (COMU1,rec, 8, O4ZOPAO__V,  0, 0);
    SetMODV (COMU1,rec, 9, O4ZOPAC__V,  0, 0);

    SetMODV (COMU1,rec,10, O4KOPO___V,  0, 0);
    SetMODV (COMU1,rec,11, O4KOPC___V,  0, 0);

    SetMODV (COMU1,rec,12, O4BELL___V,  0, 0);

//----------------------------------------------------------------------------
