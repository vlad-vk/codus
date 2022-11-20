//----------------------------------------------------------------------------
//  COM2, 7033, N39

    rec=9;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIT3TOPSDV==0){ AIT3TOPSDM=100.2; AIT3TOPSZM=-0.2; }
    if(AIT3BOTSDV==0){ AIT3BOTSDM=100.2; AIT3BOTSZM=-0.2; }
    if(AIT3P__SDV==0){ AIT3P__SDM=100.2; AIT3P__SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIT3TOP__V=AISet( 8,GetMODV(COMU1,rec,0),0,32768,0,
               AIT3TOPSDV,AIT3TOP_AV,AIT3TOP_FV)+AIT3TOPSZV;

    AIT3BOT__V=AISet( 9,GetMODV(COMU1,rec,1),0,32768,0,
               AIT3BOTSDV,AIT3BOT_AV,AIT3BOT_FV)+AIT3BOTSZV;

    AIT3P____V=AISet(10,GetMODV(COMU1,rec,2),0,32768,0,
               AIT3P__SDV,AIT3P___AV,AIT3P___FV)+AIT3P__SZV;

    A3TTTB___V=AIT3TOP__V-AIT3BOT__V;

//----------------------------------------------------------------------------
