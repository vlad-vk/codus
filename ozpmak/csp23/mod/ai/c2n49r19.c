//----------------------------------------------------------------------------
//  COM2, 7033, N49

    rec=19;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIT4TOPSDV==0){ AIT4TOPSDM=100.2; AIT4TOPSZV=-0.2; }
    if(AIT4BOTSDV==0){ AIT4BOTSDM=100.2; AIT4BOTSZV=-0.2; }
    if(AIT4P__SDV==0){ AIT4P__SDM=100.2; AIT4P__SZV=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIT4TOP__V=AISet(19,GetMODV(COMU1,rec,0),0,32768,0,
               AIT4TOPSDV,AIT4TOP_AV,AIT4TOP_FV)+AIT4TOPSZV;

    AIT4BOT__V=AISet(20,GetMODV(COMU1,rec,1),0,32768,0,
               AIT4BOTSDV,AIT4BOT_AV,AIT4BOT_FV)+AIT4BOTSZV;

    AIT4P____V=AISet(21,GetMODV(COMU1,rec,2),0,32768,0,
               AIT4P__SDV,AIT4P___AV,AIT4P___FV)+AIT4P__SZV;

    A4TTTB___V=AIT4TOP__V-AIT4BOT__V;

//----------------------------------------------------------------------------
