//----------------------------------------------------------------------------
//  COM2, 7017, N38

    rec=8;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AITPO__SDV==0){ AITPO__SDM=100.2; AITPO__SZM=-0.2; }
    if(AIFPO__SDV==0){ AIFPO__SDM=100.2; AIFPO__SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AITPO____V=AISet(22,GetMODV(COMU1,rec,0),0,32768,0,
               AITPO__SDV,AITPO___AV,AITPO___FV)+AITPO__SZV;

    AIFPO____V=AISet(23,GetMODV(COMU1,rec,1),0,32768,0,
               AIFPO__SDV,AIFPO___AV,AIFPO___FV)+AIFPO__SZV;
    if(AIFPO____V<0){ AIFPO____V=0; }
    AIFPO____V= (_f)sqrt((double)AIFPO____V);

//----------------------------------------------------------------------------

