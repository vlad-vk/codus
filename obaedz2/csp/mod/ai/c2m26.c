// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7017, N26

    rec=6;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIW219_SDV==0){ AIW219_SDM=100.2; AIW219_SZM=-0.2; }     //
    if(AIW251_SDV==0){ AIW251_SDM=100.2; AIW251_SZM=-0.2; }     //
    if(AIW215_SDV==0){ AIW215_SDM=100.2; AIW215_SZM=-0.2; }     //

    if(AIT230_SDV==0){ AIT230_SDM=100.2; AIT230_SZM=-0.2; }     //
    if(AIT232_SDV==0){ AIT232_SDM=100.2; AIT232_SZM=-0.2; }     //

    if(M26C05_SDV==0){ M26C05_SDM=100.2; M26C05_SZM=-0.2; }     //
    if(M26C06_SDV==0){ M26C06_SDM=100.2; M26C06_SZM=-0.2; }     //
    if(M26C07_SDV==0){ M26C07_SDM=100.2; M26C07_SZM=-0.2; }     //
       

    // Получить преобразованные значения с каналов модуля
    AIW219___V=AISet(16,GetMODV(COMU2,rec,0),0,32768,0,AIW219_SDV,AIW219__AV,AIW219__FV)+AIW219_SZV;
    AIW251___V=AISet(17,GetMODV(COMU2,rec,1),0,32768,0,AIW251_SDV,AIW251__AV,AIW251__FV)+AIW251_SZV;
    AIW215___V=AISet(18,GetMODV(COMU2,rec,2),0,32768,0,AIW215_SDV,AIW215__AV,AIW215__FV)+AIW215_SZV;
    AIT230___V=AISet(19,GetMODV(COMU2,rec,3),0,32768,0,AIT230_SDV,AIT230__AV,AIT230__FV)+AIT230_SZV;
    AIT232___V=AISet(20,GetMODV(COMU2,rec,4),0,32768,0,AIT232_SDV,AIT232__AV,AIT232__FV)+AIT232_SZV;
    M26C05___V=AISet(21,GetMODV(COMU2,rec,5),0,32768,0,M26C05_SDV,M26C05__AV,M26C05__FV)+M26C05_SZV;
    M26C06___V=AISet(22,GetMODV(COMU2,rec,6),0,32768,0,M26C06_SDV,M26C06__AV,M26C06__FV)+M26C06_SZV;
    M26C07___V=AISet(23,GetMODV(COMU2,rec,7),0,32768,0,M26C07_SDV,M26C07__AV,M26C07__FV)+M26C07_SZV;
    

//----------------------------------------------------------------------------
