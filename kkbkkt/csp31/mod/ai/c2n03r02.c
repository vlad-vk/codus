// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7017, N02

    rec=2;

    // Значения НУЛЯ и ДИАПАЗОНА по умолчанию, если они не заданы
    if(AIF40V_SDV==0){ AIF40V_SDM=100.2; AIF40V_SZM=-0.2; }
    if(AIX031_SDV==0){ AIX031_SDM=100.2; AIX031_SZM=-0.2; }
    if(AIX032_SDV==0){ AIX032_SDM=100.2; AIX032_SZM=-0.2; }
    if(AIX033_SDV==0){ AIX033_SDM=100.2; AIX033_SZM=-0.2; }
    if(AIX034_SDV==0){ AIX034_SDM=100.2; AIX034_SZM=-0.2; }
    if(AIX035_SDV==0){ AIX035_SDM=100.2; AIX035_SZM=-0.2; }
    if(AIX036_SDV==0){ AIX036_SDM=100.2; AIX036_SZM=-0.2; }
    if(AIX037_SDV==0){ AIX037_SDM=100.2; AIX037_SZM=-0.2; }

    // Первые N секунд берем значения с датчиков с макс фильтром скачков,
    // чтобы  сразу выйти на реальные значения параметров
    if(PAINPC<PAINP ){
       AIF40V__FV=AIF40V_SDV;
    }

    // Получить преобразованные значения с каналов модуля
    AIF40V___V=AISet(16,GetMODV(COMU1,rec,0),0,32768,0,AIF40V_SDV,AIF40V__AV,AIF40V__FV)+AIF40V_SZV;
    AIX031___V=AISet(17,GetMODV(COMU1,rec,1),0,32768,0,AIX031_SDV,AIX031__AV,AIX031__FV)+AIX031_SZV;
    AIX032___V=AISet(18,GetMODV(COMU1,rec,2),0,32768,0,AIX032_SDV,AIX032__AV,AIX032__FV)+AIX032_SZV;
    AIX033___V=AISet(19,GetMODV(COMU1,rec,3),0,32768,0,AIX033_SDV,AIX033__AV,AIX033__FV)+AIX033_SZV;
    AIX034___V=AISet(20,GetMODV(COMU1,rec,4),0,32768,0,AIX034_SDV,AIX034__AV,AIX034__FV)+AIX034_SZV;
    AIX035___V=AISet(21,GetMODV(COMU1,rec,5),0,32768,0,AIX035_SDV,AIX035__AV,AIX035__FV)+AIX035_SZV;
    AIX036___V=AISet(22,GetMODV(COMU1,rec,6),0,32768,0,AIX036_SDV,AIX036__AV,AIX036__FV)+AIX036_SZV;
    AIX037___V=AISet(23,GetMODV(COMU1,rec,7),0,32768,0,AIX037_SDV,AIX037__AV,AIX037__FV)+AIX037_SZV;

//----------------------------------------------------------------------------
