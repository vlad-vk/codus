// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7017, N01
    rec=0;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIP201_SDV==0){ AIP201_SDM=100.2; AIP201_SZM=-0.2; }
    if(AIP202_SDV==0){ AIP202_SDM=100.2; AIP202_SZM=-0.2; }
    if(AIP203_SDV==0){ AIP203_SDM=100.2; AIP203_SZM=-0.2; }
    if(AIF301_SDV==0){ AIF301_SDM=100.2; AIF301_SZM=-0.2; }
    if(AIF302_SDV==0){ AIF302_SDM=100.2; AIF302_SZM=-0.2; }
    if(AIF311_SDV==0){ AIF311_SDM=100.2; AIF311_SZM=-0.2; }
    if(AIF321_SDV==0){ AIF321_SDM=100.2; AIF321_SZM=-0.2; }
    if(AIF322_SDV==0){ AIF322_SDM=100.2; AIF322_SZM=-0.2; }

    // Первые N секунд берем значения с датчиков с макс фильтром скачков,
    // чтобы  сразу выйти на реальные значения параметров
    if(PAINPC<PAINP ){
       AIP201__FV=AIP201_SDV;       AIP202__FV=AIP202_SDV;
       AIP203__FV=AIP203_SDV;       AIF301__FV=AIF301_SDV;
       AIF302__FV=AIF302_SDV;       AIF311__FV=AIF311_SDV;
       AIF321__FV=AIF321_SDV;       AIF322__FV=AIF322_SDV;
    }

    // Получить преобразованные значения с каналов модуля
    AIP201___V=AISet( 0,GetMODV(COMU1,rec,0),0,32768,0,AIP201_SDV,AIP201__AV,AIP201__FV)+AIP201_SZV;
    AIP202___V=AISet( 1,GetMODV(COMU1,rec,1),0,32768,0,AIP202_SDV,AIP202__AV,AIP202__FV)+AIP202_SZV;
    AIP203___V=AISet( 2,GetMODV(COMU1,rec,2),0,32768,0,AIP203_SDV,AIP203__AV,AIP203__FV)+AIP203_SZV;
    AIF301___V=AISet( 3,GetMODV(COMU1,rec,3),0,32768,0,AIF301_SDV,AIF301__AV,AIF301__FV)+AIF301_SZV;
//  if(AIF301___V<0){ AIF301___V=0; }
//  AIF301___V= (_f)sqrt((double)AIF301___V);
//  MAX расход м.б 6.3 м3, sqrt(40)=6.3
//  значит в  таблице диапазонов за шкалу прибора надо брать значение 40
//  тогда для таблицы НОЛЬ = -40/4 = -10, а ДИАПАЗОН = 40+(40/4) = 50
    AIF302___V=AISet( 4,GetMODV(COMU1,rec,4),0,32768,0,AIF302_SDV,AIF302__AV,AIF302__FV)+AIF302_SZV;
    AIF311___V=AISet( 5,GetMODV(COMU1,rec,5),0,32768,0,AIF311_SDV,AIF311__AV,AIF311__FV)+AIF311_SZV;
    AIF321___V=AISet( 6,GetMODV(COMU1,rec,6),0,32768,0,AIF321_SDV,AIF321__AV,AIF321__FV)+AIF321_SZV;
    AIF322___V=AISet( 7,GetMODV(COMU1,rec,7),0,32768,0,AIF322_SDV,AIF322__AV,AIF322__FV)+AIF322_SZV;

//----------------------------------------------------------------------------
