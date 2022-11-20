//----------------------------------------------------------------------------
//  COM2, 7033, N29

    rec=19;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIT2TOPSDV==0){ AIT2TOPSDM=100.2; AIT2TOPSZV=-0.2; }
    if(AIT2BOTSDV==0){ AIT2BOTSDM=100.2; AIT2BOTSZV=-0.2; }
    if(AIT2P__SDV==0){ AIT2P__SDM=100.2; AIT2P__SZV=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIT2TOP__V=AISet(19,GetMODV(COMU1,rec,0),0,32768,0,
               AIT2TOPSDV,AIT2TOP_AV,AIT2TOP_FV)+AIT2TOPSZV;

    AIT2BOT__V=AISet(20,GetMODV(COMU1,rec,1),0,32768,0,
               AIT2BOTSDV,AIT2BOT_AV,AIT2BOT_FV)+AIT2BOTSZV;

    AIT2P____V=AISet(21,GetMODV(COMU1,rec,2),0,32768,0,
               AIT2P__SDV,AIT2P___AV,AIT2P___FV)+AIT2P__SZV;

    A2TTTB___V=AIT2TOP__V-AIT2BOT__V;

//----------------------------------------------------------------------------
