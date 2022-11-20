//----------------------------------------------------------------------------
//  COM1, 7017, N12

    rec=14;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIL003ASDV==0){ AIL003ASDM=100.2; AIL003ASZM=-0.2; }     //
    if(AIL006ASDV==0){ AIL006ASDM=100.2; AIL006ASZM=-0.2; }     //

    if(AIL056ASDV==0){ AIL056ASDM=100.2; AIL056ASZM=-0.2; }     //
    if(AIL057ASDV==0){ AIL057ASDM=100.2; AIL057ASZM=-0.2; }     //

    if(AIL064ASDV==0){ AIL064ASDM=100.2; AIL064ASZM=-0.2; }     //
    if(AIL065ASDV==0){ AIL065ASDM=100.2; AIL065ASZM=-0.2; }     //

    if(M12C06_SDV==0){ M12C06_SDM=100.2; M12C06_SZM=-0.2; }     //
    if(M12C07_SDV==0){ M12C07_SDM=100.2; M12C07_SZM=-0.2; }     //
       

    // Получить преобразованные значения с каналов модуля
    AIL003A__V=AISet( 0,GetMODV(COMU1,rec,0),0,32768,0,AIL003ASDV,AIL003A_AV,AIL003A_FV)+AIL003ASZV;
    AIL006A__V=AISet( 1,GetMODV(COMU1,rec,1),0,32768,0,AIL006ASDV,AIL006A_AV,AIL006A_FV)+AIL006ASZV;
    AIL056A__V=AISet( 2,GetMODV(COMU1,rec,2),0,32768,0,AIL056ASDV,AIL056A_AV,AIL056A_FV)+AIL056ASZV;
    AIL057A__V=AISet( 3,GetMODV(COMU1,rec,3),0,32768,0,AIL057ASDV,AIL057A_AV,AIL057A_FV)+AIL057ASZV;
    AIL064A__V=AISet( 4,GetMODV(COMU1,rec,4),0,32768,0,AIL064ASDV,AIL064A_AV,AIL064A_FV)+AIL064ASZV;
    AIL065A__V=AISet( 5,GetMODV(COMU1,rec,5),0,32768,0,AIL065ASDV,AIL065A_AV,AIL065A_FV)+AIL065ASZV;
    M12C06___V=AISet( 6,GetMODV(COMU1,rec,6),0,32768,0,M12C06_SDV,M12C06__AV,M12C06__FV)+M12C06_SZV;
    M12C07___V=AISet( 7,GetMODV(COMU1,rec,7),0,32768,0,M12C07_SDV,M12C07__AV,M12C07__FV)+M12C07_SZV;


//----------------------------------------------------------------------------
