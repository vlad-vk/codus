//----------------------------------------------------------------------------
//  COM2, 7042, N33

    rec= 3;

    //  в ручном режиме переключение с компьютера выходов на исполнители
    //------------------------------------------------------------------------
    if (A3STEP___V==0){
        if(O3ZIOPO__M> OFF){
           O3ZIOPO__M=(O3ZIOPC__M>OFF) then_ OFF else_ ON; O3ZIOPC__M= OFF;
        }
        if(O3ZIOPC__M> OFF){
           O3ZIOPC__M=(O3ZIOPO__M>OFF) then_ OFF else_ ON; O3ZIOPO__M= OFF;
        }
        //
        if(O3ZIPPO__M> OFF){
           O3ZIPPO__M=(O3ZIPPC__M>OFF) then_ OFF else_ ON; O3ZIPPC__M= OFF;
        }
        if(O3ZIPPC__M> OFF){
           O3ZIPPC__M=(O3ZIPPO__M>OFF) then_ OFF else_ ON; O3ZIPPO__M= OFF;
        }
        //
        if(O3KIPO___M> OFF){
           O3KIPO___M=(O3KIPC___M>OFF) then_ OFF else_ ON; O3KIPC___M= OFF;
        }
        if(O3KIPC___M> OFF){
           O3KIPC___M=(O3KIPO___M>OFF) then_ OFF else_ ON; O3KIPO___M= OFF;
        }
        //
        if(O3ZOPPO__M> OFF){
           O3ZOPPO__M=(O3ZOPPC__M>OFF) then_ OFF else_ ON; O3ZOPPC__M= OFF;
        }
        if(O3ZOPPC__M> OFF){
           O3ZOPPC__M=(O3ZOPPO__M>OFF) then_ OFF else_ ON; O3ZOPPO__M= OFF;
        }
        //
        if(O3ZOPAO__M> OFF){
           O3ZOPAO__M=(O3ZOPAC__M>OFF) then_ OFF else_ ON; O3ZOPAC__M= OFF;
        }
        if(O3ZOPAC__M> OFF){
           O3ZOPAC__M=(O3ZOPAO__M>OFF) then_ OFF else_ ON; O3ZOPAO__M= OFF;
        }
        //
        if(O3KOPO___M> OFF){
           O3KOPO___M=(O3KOPC___M>OFF) then_ OFF else_ ON; O3KOPC___M= OFF;
        }
        if(O3KOPC___M> OFF){
           O3KOPC___M=(O3KOPO___M>OFF) then_ OFF else_ ON; O3KOPO___M= OFF;
        }
    }
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    O3ZIOPO__V= O3ZIOPO__M;
    O3ZIOPC__V= O3ZIOPC__M;           
    U3ZIOP___V= 3;                                      // оба сигнала (error)
    if(O3ZIOPO__V==OFF&&O3ZIOPC__V==OFF) U3ZIOP___V=0;  // нет сигнала
    if(O3ZIOPO__V==ON &&O3ZIOPC__V==OFF) U3ZIOP___V=1;  // на  открытие
    if(O3ZIOPO__V==OFF&&O3ZIOPC__V==ON ) U3ZIOP___V=2;  // на  закрытие
    //
    O3ZIPPO__V= O3ZIPPO__M;
    O3ZIPPC__V= O3ZIPPC__M;
    U3ZIPP___V= 3;
    if(O3ZIPPO__V==OFF&&O3ZIPPC__V==OFF) U3ZIPP___V=0;
    if(O3ZIPPO__V==ON &&O3ZIPPC__V==OFF) U3ZIPP___V=1;
    if(O3ZIPPO__V==OFF&&O3ZIPPC__V==ON ) U3ZIPP___V=2;
    //
    O3KIPO___V= O3KIPO___M;
    O3KIPC___V= O3KIPC___M;
    U3KIP____V= 3;
    if(O3KIPO___V==OFF&&O3KIPC___V==OFF) U3KIP____V=0;
    if(O3KIPO___V==ON &&O3KIPC___V==OFF) U3KIP____V=1;
    if(O3KIPO___V==OFF&&O3KIPC___V==ON ) U3KIP____V=2;
    //
    O3ZOPPO__V= O3ZOPPO__M;
    O3ZOPPC__V= O3ZOPPC__M;
    U3ZOPP___V= 3;
    if(O3ZOPPO__V==OFF&&O3ZOPPC__V==OFF) U3ZOPP___V=0;
    if(O3ZOPPO__V==ON &&O3ZOPPC__V==OFF) U3ZOPP___V=1;
    if(O3ZOPPO__V==OFF&&O3ZOPPC__V==ON ) U3ZOPP___V=2;

    O3ZOPAO__V= O3ZOPAO__M;
    O3ZOPAC__V= O3ZOPAC__M;
    U3ZOPA___V= 3;
    if(O3ZOPAO__V==OFF&&O3ZOPAC__V==OFF) U3ZOPA___V=0;
    if(O3ZOPAO__V==ON &&O3ZOPAC__V==OFF) U3ZOPA___V=1;
    if(O3ZOPAO__V==OFF&&O3ZOPAC__V==ON ) U3ZOPA___V=2;

    O3KOPO___V= O3KOPO___M;
    O3KOPC___V= O3KOPC___M;
    U3KOP____V= 3;
    if(O3KOPO___V==OFF&&O3KOPC___V==OFF) U3KOP____V=0;
    if(O3KOPO___V==ON &&O3KOPC___V==OFF) U3KOP____V=1;
    if(O3KOPO___V==OFF&&O3KOPC___V==ON ) U3KOP____V=2;
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    // выход на каналы модулей УСО:

    SetMODV (COMU1,rec, 0, O3ZIOPO__V,  0, 0);
    SetMODV (COMU1,rec, 1, O3ZIOPC__V,  0, 0);

    SetMODV (COMU1,rec, 2, O3ZIPPO__V,  0, 0);
    SetMODV (COMU1,rec, 3, O3ZIPPC__V,  0, 0);

    SetMODV (COMU1,rec, 4, O3KIPO___V,  0, 0);
    SetMODV (COMU1,rec, 5, O3KIPC___V,  0, 0);

    SetMODV (COMU1,rec, 6, O3ZOPPO__V,  0, 0);
    SetMODV (COMU1,rec, 7, O3ZOPPC__V,  0, 0);

    SetMODV (COMU1,rec, 8, O3ZOPAO__V,  0, 0);
    SetMODV (COMU1,rec, 9, O3ZOPAC__V,  0, 0);

    SetMODV (COMU1,rec,10, O3KOPO___V,  0, 0);
    SetMODV (COMU1,rec,11, O3KOPC___V,  0, 0);

    SetMODV (COMU1,rec,12, O3BELL___V,  0, 0);

//----------------------------------------------------------------------------
