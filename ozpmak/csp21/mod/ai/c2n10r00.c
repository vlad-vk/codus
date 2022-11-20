//----------------------------------------------------------------------------
//  COM2, 7017, N10

    rec=0;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIF1P__SDV==0){ AIF1P__SDM=100.2; AIF1P__SZM=-0.2; }
    if(AIF2P__SDV==0){ AIF2P__SDM=100.2; AIF2P__SZM=-0.2; }
    if(AIL1C__SDV==0){ AIL1C__SDM=100.2; AIL1C__SZM=-0.2; }
    if(AIL2C__SDV==0){ AIL2C__SDM=100.2; AIL2C__SZM=-0.2; }
    if(AIP1P__SDV==0){ AIP1P__SDM=100.2; AIP1P__SZM=-0.2; }
    if(AIP2P__SDV==0){ AIP2P__SDM=100.2; AIP2P__SZM=-0.2; }
    if(AIP12V_SDV==0){ AIP12V_SDM=100.2; AIP12V_SZM=-0.2; }
    if(AIP12M_SDV==0){ AIP12M_SDM=100.2; AIP12M_SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIF1P____V=AISet( 0,GetMODV(COMU1,rec,0),0,32768,0,
               AIF1P__SDV,AIF1P___AV,AIF1P___FV)+AIF1P__SZV;
    if(AIF1P____V<0){ AIF1P____V=0; }
    AIF1P____V= (_f)sqrt((double)AIF1P____V);


    AIF2P____V=AISet( 1,GetMODV(COMU1,rec,1),0,32768,0,
               AIF2P__SDV,AIF2P___AV,AIF2P___FV)+AIF2P__SZV;
    if(AIF2P____V<0){ AIF2P____V=0; }
    AIF2P____V= (_f)sqrt((double)AIF2P____V);

    AIL1C____V=AISet( 2,GetMODV(COMU1,rec,2),0,32768,0,
               AIL1C__SDV,AIL1C___AV,AIL1C___FV)+AIL1C__SZV;

    AIL2C____V=AISet( 3,GetMODV(COMU1,rec,3),0,32768,0,
               AIL2C__SDV,AIL2C___AV,AIL2C___FV)+AIL2C__SZV;

    AIP1P____V=AISet( 4,GetMODV(COMU1,rec,4),0,32768,0,
               AIP1P__SDV,AIP1P___AV,AIP1P___FV)+AIP1P__SZV;

    AIP2P____V=AISet( 5,GetMODV(COMU1,rec,5),0,32768,0,
               AIP2P__SDV,AIP2P___AV,AIP2P___FV)+AIP2P__SZV;

    AIP12V___V=AISet( 6,GetMODV(COMU1,rec,6),0,32768,0,
               AIP12V_SDV,AIP12V__AV,AIP12V__FV)+AIP12V_SZV;

    AIP12M___V=AISet( 7,GetMODV(COMU1,rec,7),0,32768,0,
               AIP12M_SDV,AIP12M__AV,AIP12M__FV)+AIP12M_SZV;

//----------------------------------------------------------------------------
