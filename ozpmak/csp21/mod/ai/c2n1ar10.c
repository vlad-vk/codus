//----------------------------------------------------------------------------
//  COM2, 7017, N1A

    rec=10;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIS1PI_SDV==0){ AIS1PI_SDM=100.2; AIS1PI_SZM=-0.2; }
    if(AIS1PO_SDV==0){ AIS1PO_SDM=100.2; AIS1PO_SZM=-0.2; }
    if(AIS1CO_SDV==0){ AIS1CO_SDM=100.2; AIS1CO_SZM=-0.2; }
    if(AIS2PI_SDV==0){ AIS2PI_SDM=100.2; AIS2PI_SZM=-0.2; }
    if(AIS2PO_SDV==0){ AIS2PO_SDM=100.2; AIS2PO_SZM=-0.2; }
    if(AIS2CO_SDV==0){ AIS2CO_SDM=100.2; AIS2CO_SZM=-0.2; }
    if(N1AC06_SDV==0){ N1AC06_SDM=100.2; N1AC06_SZM=-0.2; }
    if(N1AC07_SDV==0){ N1AC07_SDM=100.2; N1AC07_SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIS1PI___V=AISet(11,GetMODV(COMU1,rec,0),0,32768,0,
               AIS1PI_SDV,AIS1PI__AV,AIS1PI__FV)+AIS1PI_SZV;

    AIS1PO___V=AISet(12,GetMODV(COMU1,rec,1),0,32768,0,
               AIS1PO_SDV,AIS1PO__AV,AIS1PO__FV)+AIS1PO_SZV;

    AIS1CO___V=AISet(13,GetMODV(COMU1,rec,2),0,32768,0,
               AIS1CO_SDV,AIS1CO__AV,AIS1CO__FV)+AIS1CO_SZV;

    AIS2PI___V=AISet(14,GetMODV(COMU1,rec,3),0,32768,0,
               AIS2PI_SDV,AIS2PI__AV,AIS2PI__FV)+AIS2PI_SZV;

    AIS2PO___V=AISet(15,GetMODV(COMU1,rec,4),0,32768,0,
               AIS2PO_SDV,AIS2PO__AV,AIS2PO__FV)+AIS2PO_SZV;

    AIS2CO___V=AISet(16,GetMODV(COMU1,rec,5),0,32768,0,
               AIS2CO_SDV,AIS2CO__AV,AIS2CO__FV)+AIS2CO_SZV;

    N1AC06___V=AISet(17,GetMODV(COMU1,rec,6),0,32768,0,
               N1AC06_SDV,N1AC06__AV,N1AC06__FV)+N1AC06_SZV;

    N1AC07___V=AISet(18,GetMODV(COMU1,rec,7),0,32768,0,
               N1AC07_SDV,N1AC07__AV,N1AC07__FV)+N1AC07_SZV;

//----------------------------------------------------------------------------
