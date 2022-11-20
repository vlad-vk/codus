//----------------------------------------------------------------------------
//  COM2, 7042, N23

    rec= 13;

    // в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A2STEP___V==0){
        if (O2ZIOPO__M> OFF){
            O2ZIOPO__M=(O2ZIOPC__M>OFF) then_ OFF else_ ON; O2ZIOPC__M= OFF;
        }
        if (O2ZIOPC__M> OFF){
            O2ZIOPC__M=(O2ZIOPO__M>OFF) then_ OFF else_ ON; O2ZIOPO__M= OFF;
        }
        //
        if (O2ZIPPO__M> OFF){
            O2ZIPPO__M=(O2ZIPPC__M>OFF) then_ OFF else_ ON; O2ZIPPC__M= OFF;
        }
        if (O2ZIPPC__M> OFF){
            O2ZIPPC__M=(O2ZIPPO__M>OFF) then_ OFF else_ ON; O2ZIPPO__M= OFF;
        }
        //
        if (O2KIPO___M> OFF){
            O2KIPO___M=(O2KIPC___M>OFF) then_ OFF else_ ON; O2KIPC___M= OFF;
        }
        if (O2KIPC___M> OFF){
            O2KIPC___M=(O2KIPO___M>OFF) then_ OFF else_ ON; O2KIPO___M= OFF;
        }
        //
        if (O2ZOPPO__M> OFF){
            O2ZOPPO__M=(O2ZOPPC__M>OFF) then_ OFF else_ ON; O2ZOPPC__M= OFF;
        }
        if (O2ZOPPC__M> OFF){
            O2ZOPPC__M=(O2ZOPPO__M>OFF) then_ OFF else_ ON; O2ZOPPO__M= OFF;
        }
        //
        if (O2ZOPAO__M> OFF){
            O2ZOPAO__M=(O2ZOPAC__M>OFF) then_ OFF else_ ON; O2ZOPAC__M= OFF;
        }
        if (O2ZOPAC__M> OFF){
            O2ZOPAC__M=(O2ZOPAO__M>OFF) then_ OFF else_ ON; O2ZOPAO__M= OFF;
        }
        //
        if (O2KOPO___M> OFF){
            O2KOPO___M=(O2KOPC___M>OFF) then_ OFF else_ ON; O2KOPC___M= OFF;
        }
        if (O2KOPC___M> OFF){
            O2KOPC___M=(O2KOPO___M>OFF) then_ OFF else_ ON; O2KOPO___M= OFF;
        }
    }

    //------------------------------------------------------------------------
    O2ZIOPO__V= O2ZIOPO__M;
    O2ZIOPC__V= O2ZIOPC__M;
    U2ZIOP___V=3;                                       // оба сигнала
    if(O2ZIOPO__V==OFF&&O2ZIOPC__V==OFF) U2ZIOP___V=0;  // нет сигнала
    if(O2ZIOPO__V==ON &&O2ZIOPC__V==OFF) U2ZIOP___V=1;  // на  открытие
    if(O2ZIOPO__V==OFF&&O2ZIOPC__V==ON ) U2ZIOP___V=2;  // на  закрытие

    O2ZIPPO__V= O2ZIPPO__M;
    O2ZIPPC__V= O2ZIPPC__M;
    U2ZIPP___V=3;
    if(O2ZIPPO__V==OFF&&O2ZIPPC__V==OFF) U2ZIPP___V=0;
    if(O2ZIPPO__V==ON &&O2ZIPPC__V==OFF) U2ZIPP___V=1;
    if(O2ZIPPO__V==OFF&&O2ZIPPC__V==ON ) U2ZIPP___V=2;

    O2KIPO___V= O2KIPO___M;
    O2KIPC___V= O2KIPC___M;
    U2KIP____V=3;
    if(O2KIPO___V==OFF&&O2KIPC___V==OFF) U2KIP____V=0;
    if(O2KIPO___V==ON &&O2KIPC___V==OFF) U2KIP____V=1;
    if(O2KIPO___V==OFF&&O2KIPC___V==ON ) U2KIP____V=2;

    O2ZOPPO__V= O2ZOPPO__M;
    O2ZOPPC__V= O2ZOPPC__M;
    U2ZOPP___V=3;
    if(O2ZOPPO__V==OFF&&O2ZOPPC__V==OFF) U2ZOPP___V=0;
    if(O2ZOPPO__V==ON &&O2ZOPPC__V==OFF) U2ZOPP___V=1;
    if(O2ZOPPO__V==OFF&&O2ZOPPC__V==ON ) U2ZOPP___V=2;

    O2ZOPAO__V= O2ZOPAO__M;
    O2ZOPAC__V= O2ZOPAC__M;
    U2ZOPA___V=3;
    if(O2ZOPAO__V==OFF&&O2ZOPAC__V==OFF) U2ZOPA___V=0;
    if(O2ZOPAO__V==ON &&O2ZOPAC__V==OFF) U2ZOPA___V=1;
    if(O2ZOPAO__V==OFF&&O2ZOPAC__V==ON ) U2ZOPA___V=2;

    O2KOPO___V= O2KOPO___M;
    O2KOPC___V= O2KOPC___M;
    U2KOP____V=3;
    if(O2KOPO___V==OFF&&O2KOPC___V==OFF) U2KOP____V=0;
    if(O2KOPO___V==ON &&O2KOPC___V==OFF) U2KOP____V=1;
    if(O2KOPO___V==OFF&&O2KOPC___V==ON ) U2KOP____V=2;

    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0, O2ZIOPO__V,  0, 0);
    SetMODV (COMU1,rec, 1, O2ZIOPC__V,  0, 0);

    SetMODV (COMU1,rec, 2, O2ZIPPO__V,  0, 0);
    SetMODV (COMU1,rec, 3, O2ZIPPC__V,  0, 0);

    SetMODV (COMU1,rec, 4, O2KIPO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O2KIPC___V,  0, 0);

    SetMODV (COMU1,rec, 6, O2ZOPPO__V,  0, 0);
    SetMODV (COMU1,rec, 7, O2ZOPPC__V,  0, 0);

    SetMODV (COMU1,rec, 8, O2ZOPAO__V,  0, 0);
    SetMODV (COMU1,rec, 9, O2ZOPAC__V,  0, 0);

    SetMODV (COMU1,rec,10, O2KOPO___V,  0, 0);
    SetMODV (COMU1,rec,11, O2KOPC___V,  0, 0);

    SetMODV (COMU1,rec,12, O2BELL___V,  0, 0);

//----------------------------------------------------------------------------
