// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7017, N02

    rec=1;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIP311_SDV==0){ AIP311_SDM=100.2; AIP311_SZM=-0.2; }
    if(AIP321_SDV==0){ AIP321_SDM=100.2; AIP321_SZM=-0.2; }
    if(AIP322_SDV==0){ AIP322_SDM=100.2; AIP322_SZM=-0.2; }
    if(AIP331_SDV==0){ AIP331_SDM=100.2; AIP331_SZM=-0.2; }
    if(AIP34B_SDV==0){ AIP34B_SDM=100.2; AIP34B_SZM=-0.2; }
    if(AIP37B_SDV==0){ AIP37B_SDM=100.2; AIP37B_SZM=-0.2; }
    if(AIP38B_SDV==0){ AIP38B_SDM=100.2; AIP38B_SZM=-0.2; }
    if(AIP40B_SDV==0){ AIP40B_SDM=100.2; AIP40B_SZM=-0.2; }

    // Первые N секунд берем значения с датчиков с макс фильтром скачков,
    // чтобы  сразу выйти на реальные значения параметров
    if(PAINPC<PAINP ){
       AIP311__FV=AIP311_SDV;       AIP321__FV=AIP321_SDV;
       AIP322__FV=AIP322_SDV;       AIP331__FV=AIP331_SDV;
       AIP34B__FV=AIP34B_SDV;       AIP37B__FV=AIP37B_SDV;
       AIP38B__FV=AIP38B_SDV;       AIP40B__FV=AIP40B_SDV;
    }

    // Получить преобразованные значения с каналов модуля
    AIP311___V=AISet( 8,GetMODV(COMU1,rec,0),0,32768,0,AIP311_SDV,AIP311__AV,AIP311__FV)+AIP311_SZV;
    AIP321___V=AISet( 9,GetMODV(COMU1,rec,1),0,32768,0,AIP321_SDV,AIP321__AV,AIP321__FV)+AIP321_SZV;
    AIP322___V=AISet(10,GetMODV(COMU1,rec,2),0,32768,0,AIP322_SDV,AIP322__AV,AIP322__FV)+AIP322_SZV;
    AIP331___V=AISet(11,GetMODV(COMU1,rec,3),0,32768,0,AIP331_SDV,AIP331__AV,AIP331__FV)+AIP331_SZV;
    AIP34B___V=AISet(12,GetMODV(COMU1,rec,4),0,32768,0,AIP34B_SDV,AIP34B__AV,AIP34B__FV)+AIP34B_SZV;
    AIP37B___V=AISet(13,GetMODV(COMU1,rec,5),0,32768,0,AIP37B_SDV,AIP37B__AV,AIP37B__FV)+AIP37B_SZV;
    AIP38B___V=AISet(14,GetMODV(COMU1,rec,6),0,32768,0,AIP38B_SDV,AIP38B__AV,AIP38B__FV)+AIP38B_SZV;
    AIP40B___V=AISet(15,GetMODV(COMU1,rec,7),0,32768,0,AIP40B_SDV,AIP40B__AV,AIP40B__FV)+AIP40B_SZV;

//----------------------------------------------------------------------------
