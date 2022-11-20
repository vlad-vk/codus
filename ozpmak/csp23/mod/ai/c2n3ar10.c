//----------------------------------------------------------------------------
//  COM2, 7017, N3A

    rec=10;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIS3PI_SDV==0){ AIS3PI_SDM=100.2; AIS3PI_SZM=-0.2; }
    if(AIS3PO_SDV==0){ AIS3PO_SDM=100.2; AIS3PO_SZM=-0.2; }
    if(AIS3CO_SDV==0){ AIS3CO_SDM=100.2; AIS3CO_SZM=-0.2; }
    if(AIS4PI_SDV==0){ AIS4PI_SDM=100.2; AIS4PI_SZM=-0.2; }
    if(AIS4PO_SDV==0){ AIS4PO_SDM=100.2; AIS4PO_SZM=-0.2; }
    if(AIS4CO_SDV==0){ AIS4CO_SDM=100.2; AIS4CO_SZM=-0.2; }
    if(N3AC06_SDV==0){ N3AC06_SDM=100.2; N3AC06_SZM=-0.2; }
    if(N3AC07_SDV==0){ N3AC07_SDM=100.2; N3AC07_SZM=-0.2; }

    // Получить преобразованные значения с каналов модуля
    AIS3PI___V=AISet(11,GetMODV(COMU1,rec,0),0,32768,0,
               AIS3PI_SDV,AIS3PI__AV,AIS3PI__FV)+AIS3PI_SZV;

    AIS3PO___V=AISet(12,GetMODV(COMU1,rec,1),0,32768,0,
               AIS3PO_SDV,AIS3PO__AV,AIS3PO__FV)+AIS3PO_SZV;

    AIS3CO___V=AISet(13,GetMODV(COMU1,rec,2),0,32768,0,
               AIS3CO_SDV,AIS3CO__AV,AIS3CO__FV)+AIS3CO_SZV;

    AIS4PI___V=AISet(14,GetMODV(COMU1,rec,3),0,32768,0,
               AIS4PI_SDV,AIS4PI__AV,AIS4PI__FV)+AIS4PI_SZV;

    AIS4PO___V=AISet(15,GetMODV(COMU1,rec,4),0,32768,0,
               AIS4PO_SDV,AIS4PO__AV,AIS4PO__FV)+AIS4PO_SZV;

    AIS4CO___V=AISet(16,GetMODV(COMU1,rec,5),0,32768,0,
               AIS4CO_SDV,AIS4CO__AV,AIS4CO__FV)+AIS4CO_SZV;

    N3AC06___V=AISet(17,GetMODV(COMU1,rec,6),0,32768,0,
               N3AC06_SDV,N3AC06__AV,N3AC06__FV)+N3AC06_SZV;

    N3AC07___V=AISet(18,GetMODV(COMU1,rec,7),0,32768,0,
               N3AC07_SDV,N3AC07__AV,N3AC07__FV)+N3AC07_SZV;

//----------------------------------------------------------------------------
