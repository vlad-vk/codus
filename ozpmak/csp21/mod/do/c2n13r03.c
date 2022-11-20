//----------------------------------------------------------------------------
//  COM2, 7042, N13

    rec= 3;

    //  в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A1STEP___V==0){
        if(O1ZIOPO__M> OFF){
           O1ZIOPO__M=(O1ZIOPC__M>OFF) then_ OFF else_ ON; O1ZIOPC__M= OFF;
        }
        if(O1ZIOPC__M> OFF){
           O1ZIOPC__M=(O1ZIOPO__M>OFF) then_ OFF else_ ON; O1ZIOPO__M= OFF;
        }
        //
        if(O1ZIPPO__M> OFF){
           O1ZIPPO__M=(O1ZIPPC__M>OFF) then_ OFF else_ ON; O1ZIPPC__M= OFF;
        }
        if(O1ZIPPC__M> OFF){
           O1ZIPPC__M=(O1ZIPPO__M>OFF) then_ OFF else_ ON; O1ZIPPO__M= OFF;
        }
        //
        if(O1KIPO___M> OFF){
           O1KIPO___M=(O1KIPC___M>OFF) then_ OFF else_ ON; O1KIPC___M= OFF;
        }
        if(O1KIPC___M> OFF){
           O1KIPC___M=(O1KIPO___M>OFF) then_ OFF else_ ON; O1KIPO___M= OFF;
        }
        //
        if(O1ZOPPO__M> OFF){
           O1ZOPPO__M=(O1ZOPPC__M>OFF) then_ OFF else_ ON; O1ZOPPC__M= OFF;
        }
        if(O1ZOPPC__M> OFF){
           O1ZOPPC__M=(O1ZOPPO__M>OFF) then_ OFF else_ ON; O1ZOPPO__M= OFF;
        }
        //
        if(O1ZOPAO__M> OFF){
           O1ZOPAO__M=(O1ZOPAC__M>OFF) then_ OFF else_ ON; O1ZOPAC__M= OFF;
        }
        if(O1ZOPAC__M> OFF){
           O1ZOPAC__M=(O1ZOPAO__M>OFF) then_ OFF else_ ON; O1ZOPAO__M= OFF;
        }
        //
        if(O1KOPO___M> OFF){
           O1KOPO___M=(O1KOPC___M>OFF) then_ OFF else_ ON; O1KOPC___M= OFF;
        }
        if(O1KOPC___M> OFF){
           O1KOPC___M=(O1KOPO___M>OFF) then_ OFF else_ ON; O1KOPO___M= OFF;
        }
    }
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    O1ZIOPO__V= O1ZIOPO__M;
    O1ZIOPC__V= O1ZIOPC__M;           
    U1ZIOP___V= 3;                                      // оба сигнала (error)
    if(O1ZIOPO__V==OFF&&O1ZIOPC__V==OFF) U1ZIOP___V=0;  // нет сигнала
    if(O1ZIOPO__V==ON &&O1ZIOPC__V==OFF) U1ZIOP___V=1;  // на  открытие
    if(O1ZIOPO__V==OFF&&O1ZIOPC__V==ON ) U1ZIOP___V=2;  // на  закрытие
    //
    O1ZIPPO__V= O1ZIPPO__M;
    O1ZIPPC__V= O1ZIPPC__M;
    U1ZIPP___V= 3;
    if(O1ZIPPO__V==OFF&&O1ZIPPC__V==OFF) U1ZIPP___V=0;
    if(O1ZIPPO__V==ON &&O1ZIPPC__V==OFF) U1ZIPP___V=1;
    if(O1ZIPPO__V==OFF&&O1ZIPPC__V==ON ) U1ZIPP___V=2;
    //
    O1KIPO___V= O1KIPO___M;
    O1KIPC___V= O1KIPC___M;
    U1KIP____V= 3;
    if(O1KIPO___V==OFF&&O1KIPC___V==OFF) U1KIP____V=0;
    if(O1KIPO___V==ON &&O1KIPC___V==OFF) U1KIP____V=1;
    if(O1KIPO___V==OFF&&O1KIPC___V==ON ) U1KIP____V=2;
    //
    O1ZOPPO__V= O1ZOPPO__M;
    O1ZOPPC__V= O1ZOPPC__M;
    U1ZOPP___V= 3;
    if(O1ZOPPO__V==OFF&&O1ZOPPC__V==OFF) U1ZOPP___V=0;
    if(O1ZOPPO__V==ON &&O1ZOPPC__V==OFF) U1ZOPP___V=1;
    if(O1ZOPPO__V==OFF&&O1ZOPPC__V==ON ) U1ZOPP___V=2;

    O1ZOPAO__V= O1ZOPAO__M;
    O1ZOPAC__V= O1ZOPAC__M;
    U1ZOPA___V= 3;
    if(O1ZOPAO__V==OFF&&O1ZOPAC__V==OFF) U1ZOPA___V=0;
    if(O1ZOPAO__V==ON &&O1ZOPAC__V==OFF) U1ZOPA___V=1;
    if(O1ZOPAO__V==OFF&&O1ZOPAC__V==ON ) U1ZOPA___V=2;

    O1KOPO___V= O1KOPO___M;
    O1KOPC___V= O1KOPC___M;
    U1KOP____V= 3;
    if(O1KOPO___V==OFF&&O1KOPC___V==OFF) U1KOP____V=0;
    if(O1KOPO___V==ON &&O1KOPC___V==OFF) U1KOP____V=1;
    if(O1KOPO___V==OFF&&O1KOPC___V==ON ) U1KOP____V=2;
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:

    SetMODV (COMU1,rec, 0, O1ZIOPO__V,  0, 0);
    SetMODV (COMU1,rec, 1, O1ZIOPC__V,  0, 0);

    SetMODV (COMU1,rec, 2, O1ZIPPO__V,  0, 0);
    SetMODV (COMU1,rec, 3, O1ZIPPC__V,  0, 0);

    SetMODV (COMU1,rec, 4, O1KIPO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O1KIPC___V,  0, 0);

    SetMODV (COMU1,rec, 6, O1ZOPPO__V,  0, 0);
    SetMODV (COMU1,rec, 7, O1ZOPPC__V,  0, 0);

    SetMODV (COMU1,rec, 8, O1ZOPAO__V,  0, 0);
    SetMODV (COMU1,rec, 9, O1ZOPAC__V,  0, 0);

    SetMODV (COMU1,rec,10, O1KOPO___V,  0, 0);
    SetMODV (COMU1,rec,11, O1KOPC___V,  0, 0);

    SetMODV (COMU1,rec,12, O1BELL___V,  0, 0);

//----------------------------------------------------------------------------
