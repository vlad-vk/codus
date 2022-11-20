//----------------------------------------------------------------------------
//  COM2, 7017, N30

    rec=0;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIF3P__SDV==0){ AIF3P__SDM=100.2; AIF3P__SZM=-0.2; }
    if(AIF4P__SDV==0){ AIF4P__SDM=100.2; AIF4P__SZM=-0.2; }
    if(AIL3C__SDV==0){ AIL3C__SDM=100.2; AIL3C__SZM=-0.2; }
    if(AIL4C__SDV==0){ AIL4C__SDM=100.2; AIL4C__SZM=-0.2; }
    if(AIP3P__SDV==0){ AIP3P__SDM=100.2; AIP3P__SZM=-0.2; }
    if(AIP4P__SDV==0){ AIP4P__SDM=100.2; AIP4P__SZM=-0.2; }
    if(AIP34V_SDV==0){ AIP34V_SDM=100.2; AIP34V_SZM=-0.2; }
    if(AIP34M_SDV==0){ AIP34M_SDM=100.2; AIP34M_SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIF3P____V=AISet( 0,GetMODV(COMU1,rec,0),0,32768,0,
               AIF3P__SDV,AIF3P___AV,AIF3P___FV)+AIF3P__SZV;
    if(AIF3P____V<0){ AIF3P____V=0; }
    AIF3P____V= (_f)sqrt((double)AIF3P____V);


    AIF4P____V=AISet( 1,GetMODV(COMU1,rec,1),0,32768,0,
               AIF4P__SDV,AIF4P___AV,AIF4P___FV)+AIF4P__SZV;
    if(AIF4P____V<0){ AIF4P____V=0; }
    AIF4P____V= (_f)sqrt((double)AIF4P____V);

    AIL3C____V=AISet( 2,GetMODV(COMU1,rec,2),0,32768,0,
               AIL3C__SDV,AIL3C___AV,AIL3C___FV)+AIL3C__SZV;

    AIL4C____V=AISet( 3,GetMODV(COMU1,rec,3),0,32768,0,
               AIL4C__SDV,AIL4C___AV,AIL4C___FV)+AIL4C__SZV;

    AIP3P____V=AISet( 4,GetMODV(COMU1,rec,4),0,32768,0,
               AIP3P__SDV,AIP3P___AV,AIP3P___FV)+AIP3P__SZV;

    AIP4P____V=AISet( 5,GetMODV(COMU1,rec,5),0,32768,0,
               AIP4P__SDV,AIP4P___AV,AIP4P___FV)+AIP4P__SZV;

    AIP34V___V=AISet( 6,GetMODV(COMU1,rec,6),0,32768,0,
               AIP34V_SDV,AIP34V__AV,AIP34V__FV)+AIP34V_SZV;

    AIP34M___V=AISet( 7,GetMODV(COMU1,rec,7),0,32768,0,
               AIP34M_SDV,AIP34M__AV,AIP34M__FV)+AIP34M_SZV;

//----------------------------------------------------------------------------
