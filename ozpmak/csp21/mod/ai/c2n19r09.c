//----------------------------------------------------------------------------
//  COM2, 7033, N19

    rec=9;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIT1TOPSDV==0){ AIT1TOPSDM=100.2; AIT1TOPSZM=-0.2; }
    if(AIT1BOTSDV==0){ AIT1BOTSDM=100.2; AIT1BOTSZM=-0.2; }
    if(AIT1P__SDV==0){ AIT1P__SDM=100.2; AIT1P__SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIT1TOP__V=AISet( 8,GetMODV(COMU1,rec,0),0,32768,0,
               AIT1TOPSDV,AIT1TOP_AV,AIT1TOP_FV)+AIT1TOPSZV;

    AIT1BOT__V=AISet( 9,GetMODV(COMU1,rec,1),0,32768,0,
               AIT1BOTSDV,AIT1BOT_AV,AIT1BOT_FV)+AIT1BOTSZV;

    AIT1P____V=AISet(10,GetMODV(COMU1,rec,2),0,32768,0,
               AIT1P__SDV,AIT1P___AV,AIT1P___FV)+AIT1P__SZV;

    A1TTTB___V=AIT1TOP__V-AIT1BOT__V;

//----------------------------------------------------------------------------
