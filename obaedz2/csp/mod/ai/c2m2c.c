//----------------------------------------------------------------------------
//  COM2, 7017, N2C

    rec=15;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIT056_SDV==0){ AIT056_SDM=100.2; AIT056_SZM=-0.2; }     //
    if(AIT057_SDV==0){ AIT057_SDM=100.2; AIT057_SZM=-0.2; }     //
    if(AIT064_SDV==0){ AIT064_SDM=100.2; AIT064_SZM=-0.2; }     //
    if(AIT065_SDV==0){ AIT065_SDM=100.2; AIT065_SZM=-0.2; }     //
    if(AIT068_SDV==0){ AIT068_SDM=100.2; AIT068_SZM=-0.2; }     //
    if(AIT069_SDV==0){ AIT069_SDM=100.2; AIT069_SZM=-0.2; }     //
    if(AIT091_SDV==0){ AIT091_SDM=100.2; AIT091_SZM=-0.2; }     //
    if(AIT092_SDV==0){ AIT092_SDM=100.2; AIT092_SZM=-0.2; }     //
       
    // Получить преобразованные значения с каналов модуля
    AIT056___V=AISet( 8,GetMODV(COMU2,rec,0),0,32768,0,AIT056_SDV,AIT056__AV,AIT056__FV)+AIT056_SZV;
    AIT057___V=AISet( 9,GetMODV(COMU2,rec,1),0,32768,0,AIT057_SDV,AIT057__AV,AIT057__FV)+AIT057_SZV;
    AIT064___V=AISet(10,GetMODV(COMU2,rec,2),0,32768,0,AIT064_SDV,AIT064__AV,AIT064__FV)+AIT064_SZV;
    AIT065___V=AISet(11,GetMODV(COMU2,rec,3),0,32768,0,AIT065_SDV,AIT065__AV,AIT065__FV)+AIT065_SZV;
    AIT068___V=AISet(12,GetMODV(COMU2,rec,4),0,32768,0,AIT068_SDV,AIT068__AV,AIT068__FV)+AIT068_SZV;
    AIT069___V=AISet(13,GetMODV(COMU2,rec,5),0,32768,0,AIT069_SDV,AIT069__AV,AIT069__FV)+AIT069_SZV;
    AIT091___V=AISet(14,GetMODV(COMU2,rec,6),0,32768,0,AIT091_SDV,AIT091__AV,AIT091__FV)+AIT091_SZV;
    AIT092___V=AISet(15,GetMODV(COMU2,rec,7),0,32768,0,AIT092_SDV,AIT092__AV,AIT092__FV)+AIT092_SZV;

//----------------------------------------------------------------------------
