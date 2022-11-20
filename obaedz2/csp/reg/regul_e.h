//  coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
//  флаги и счетчики обнуления веса дозаторов
ex  _i  far DSWZero, DSCZero, DSCEnab;
ex  _i  far DMWZero, DMCZero, DMCEnab;
ex  _i  far DPWZero, DPCZero, DPCEnab;
//---------------------------------------------------------------------------
//  флаги запуска регуляторов
ex  _i  far Reg11F, Reg12F;
ex  _i  far Reg13F, Reg14F;
//---------------------------------------------------------------------------
ex  _i  far STEP01, STEP01_BACK, STEP02, STEP02_BACK, STEP03, STEP03_BACK;
ex  _i  far STEP04, STEP04_BACK, STEP05, STEP05_BACK;
ex  _i  far STEP06v,STEP06v_BACK,STEP06v_PRBK,STEP06vP;
ex  _i  far STEP06c,STEP06c_BACK,STEP06c_PRBK,STEP06cP;
ex  _i  far STEP07, STEP07_BACK;
ex  _i  far STEP07v,STEP07v_BACK,STEP07vP,STEP07v_PRBK;
ex  _i  far STEP07, STEP07_BACK, STEP08, STEP08_BACK, STEP09, STEP09_BACK;
ex  _i  far STEP10, STEP10_BACK;
ex  _i  far STEP14, STEP14_BACK;
ex  _i  far STEP15, STEP15_BACK;
ex  _i  far STEP01_PRBK, STEP02_PRBK, STEP03_PRBK;
ex  _i  far STEP04_PRBK, STEP05_PRBK;
ex  _i  far STEP06c_PRBK;
ex  _i  far STEP07_PRBK, STEP08_PRBK, STEP09_PRBK;
ex  _i  far STEP10_PRBK;
ex  _i  far STEP14_PRBK;
ex  _i  far STEP15_PRBK;
ex  _i  far STEP01P,STEP02P,STEP03P;
ex  _i  far STEP04P,STEP05P;
ex  _i  far STEP07P,STEP08P,STEP09P, STEP10P, STEP09D;
ex  _i  far STEP14P,STEP15P;
//  шаги регуляторов
//---------------------------------------------------------------------------
ex  _f  far DIH110,DIL110,DIS111,DIS112,DON111,DON112;
//  сигналы для гомогенизаторов
//---------------------------------------------------------------------------
ex  _i  far TIME_GG_CONTROL;
//  контроль времени работы клапанов гомогенизатора
//---------------------------------------------------------------------------
ex  _i  far GKV_POL;
//  включение-выключение клапана воздуха
//---------------------------------------------------------------------------
ex  _i  far FLAG_0406A_v;
ex  _i  far FLAG_05WTA_v;
ex  _i  far FLAG_05BGA_v;
ex  _i  far FLAG_0605A_v;
ex  _i  far FLAG_0406A_c;
ex  _i  far FLAG_05WTA_c;
ex  _i  far FLAG_05BGA_c;
ex  _i  far FLAG_0605A_c;
//  флаги передаваемые между регуляторами
//---------------------------------------------------------------------------
ex  _f  far AIW218___O;
ex  _f  far AIW218___S;
ex  _f  far AIW219___O;
ex  _f  far AIW219___S;
//  запомненный вес дозатора сухого
ex  _f  far AIW218___C;
ex  _f  far AIW219___C;
//  счетчик циклов опроса веса
//---------------------------------------------------------------------------
ex  _f  far AIW252___O;
ex  _f  far AIW252___S;
ex  _f  far AIW252___D;
//  вес дозатора мокрого с предыдущего взвешивания
//---------------------------------------------------------------------------
ex  _f  far AIW251___O;
ex  _f  far AIW251___S;
ex  _f  far AIW251___P;
//  вес дозатора пудры с предыдущего взвешивания
//---------------------------------------------------------------------------
ex  _i  far LOAD_PUOSC;
//  счетчик передергиваний клапана выгрузки пудры из дозатора пудры
//---------------------------------------------------------------------------
ex  _f  far AIW216___O;
ex  _f  far AIW216___S;
//  вес дозатора пасты с предыдущего взвешивания
//---------------------------------------------------------------------------
ex  _i  far CCTM_VSDM;
//  счетчик текущего времени стабилизации дозировки мокрого
//---------------------------------------------------------------------------
ex  _i  far MK_VG_KL_OPEN;
//  флаг открытия клапана выгрузки мокрого
//---------------------------------------------------------------------------
ex  _f  far CNT_SHVBON;
//  счетчик включения вибратора сухого
//---------------------------------------------------------------------------
ex  _i  far LSA_VAJV;
ex  _i  far LSA_VAJS;
ex  _i  far LSA_CEMV;
ex  _i  far LSA_CEMS;
//  последнее состояние аспираций
//---------------------------------------------------------------------------
//  каналы входов-выходов регулятора подкачки шлама
ex  _f  far DIRR01___V;
ex  _f  far DISR01P1_V;
ex  _f  far DISR01PK_V;
ex  _f  far DISR01MS_V;
ex  _f  far DIHR01___V;
ex  _f  far DILR01___V;
ex  _f  far DIRR01PN_V;
ex  _f  far DISR01PKSV;
ex  _f  far DISR01PKVV;
ex  _f  far DIHR01PN_V;
ex  _f  far DONR01P1_V;
ex  _f  far DONR01PK_V;
ex  _f  far DONR01PKSV;
ex  _f  far DONR01PKVV;
//---------------------------------------------------------------------------
//  Счетчики минут для ожидания

ex  _f  far TIME_SLNZCMin;                 // время загрузки пн.насоса шлама
ex  _f  far TIME_SLNVCMin;                 // время выгрузки пн.насоса шлама
ex  _f  far TIME_PRDSCMin;                 // время продувки пн.насоса шлама
ex  _i  far DSB;                           // флаг переопределения шл.бассейна
ex  _i  far FLAG_HLVSExit;                 // флаг выхода по врем верх уровня
ex  _i  far FLAG_HLMOExit;                 // флаг выхода по врем верх уровня
ex  _i  far FLAG_HLBVExit;                 // флаг выхода по врем верх уровня
ex  _i  far FLAG_HLCMExit;                 // флаг выхода по врем верх уровня

ex  _f  far TIME_VODMCMin;                 // вода
ex  _f  far TIME_VODHCMin;                 // вода
ex  _f  far TIME_CONDCMin;                 // конденсат

ex  _f  far TIME_OTHVCMin;                 // набор воды в мешалку отходов РК
ex  _f  far TIME_NS31CMin;                 // время загрузки пн.насоса отходов
ex  _f  far TIME_NS32CMin;                 // время выгрузки пн.насоса отходов
ex  _f  far TIME_PRDOCMin;                 // продувка пн.насоса отходов

ex  _f  far TIME_OSC5Min ;
ex  _f  far TIME_LEV5CMin;
ex  _f  far TIME_NAS5CMin;
ex  _f  far TIME_BVAJCMin;
ex  _f  far TIME_BCEMCMin;
ex  _f  far TIME_PRDCCMin;                 // время продувки пн.насоса цемента
ex  _f  far TIME_PCASCMin;                 // время выкл аспир цемента после продув
ex  _f  far TIME_SHDZCMin;                 // время дозировки сухого
ex  _f  far TIME_MKDZCMin;                 // время дозировки мокрого
ex  _f  far TIME_PUDZCMin;                 // время дозировки пудры
ex  _f  far TIME_PADZCMin;                 // время дозировки пасты
//
ex  _f  far CNT_VIGRUZ_S ;                 // счетчик выгрузки стабил веса сухого
ex  _f  far TIME_PVASCMin;                 // время выкл аспир вяжущего после подкач
ex  _f  far TIME_POASCMin;                 // время паузы после включ аспир вяжущ
ex  uc  far FLAG_ONVBC   ;                 // флаг выключения клапана воздуха
ex  _f  far DON101P;                       // предыдущее состояние сигналов на
ex  _f  far DON102P;                       // клапана
ex  uc  far STEP05F;                       // флаг прохождения выключеня регулятора
//
ex  _f  far TIME_LLVCCMin;                 // врем ожидан нижн уровня бунк цемента
ex  _f  far TIME_LLVVCMin;                 // врем ожидан нижн уровня бунк вяжущего
ex  _f  far TIME_LLVSCMin;                 // врем ожидан нижн уровня мешалки шлама
ex  _f  far TIME_HLVSCMin;                 // врем ожидан верх уровня мешалки шлама
ex  _f  far TIME_LLVOCMin;                 // врем ожидан нижн уровня мешалки отход
ex  _f  far TIME_HLVOCMin;                 // врем ожидан верх уровня мешалки отход
//
ex  _f  far CNT_ZAGRUZ_M;                  // счетчик ожидан стабилизац веса загруз
ex  _f  far CNT_VIGRUZ_M;                  // счетчик ожидан стабилизац веса выгруз
//
ex  _f  far TIME_PLLVCMin;                 // время ожидания нижн уровня вода-ПАВ
ex  _f  far TIME_PHLVCMin;                 // время ожидания верх уровня вода-ПАВ
ex  uc  far PAV_OK;                        // флаг засыпки ПАВ программы
//
ex  _f  far TIME_PULLCMin;                 // время набора ниж ур меш сусп ал.пудры
ex  _f  far TIME_PUHLCMin;                 // время набора вер ур меш сусп ал.пудры
ex  _f  far TIME_PUVZCMin;                 // время выгрузки мешалки сус ал.пудры
//
ex  _f  far TIME_PALNCMin;                 // время набора ниж ур ниж меш ал.пасты
ex  _f  far TIME_PANNCMin;                 // время набора вер ур ниж меш ал.пасты
ex  _f  far TIME_PAMSCMin;                 // время ожидан сигнала от опер ниж меш
ex  _f  far TIME_PALVCMin;                 // время набора ниж ур вер меш ал.пасты
ex  _f  far TIME_PANVCMin;                 // время набора вер ур вер меш ал.пасты
ex  _f  far TIME_PAVGCMin;                 // время выгрузки дозатора ал.пасты
ex  _f  far TIME_PPM1CMin;                 // время перемеш ПАВ в ниж меш ал.пасты
ex  _f  far TIME_PNOFCMin;                 // время остановки насоса ниж меш ал.пасты
ex  _f  far FLAG09_NS301;                  // флаг включения насоса
//---------------------------------------------------------------------------
ex  _f  far SigPubZagS;                    // управляющий сигнал загруз общего рег
ex  _f  far SigPubVigS;                    // управляющий сигнал выгруз общего рег
//
ex  _i  far PubCycStat;                    // статус общего цикла
ex  _i  far GetPubCycStat(int);            // получение статуса общего цикла 
ex  _i  far SetPubCycStat(int,int);        // установка статуса общего цикла
#define PSTAT 1
#define SUHOE 10
#define MOKRE 100
#define PASTA 1000
//---------------------------------------------------------------------------
ex  _i far NewSmena;                       // флаг новой  смены
ex  _i far NewMonth;                       // флаг нового месяца
ex  _i far FLSHPZ;                         // флаги передачи значений
ex  _i far FLMKPZ;
ex  _i far FLPAPZ;
ex  _i far FLPUPZ;
//---------------------------------------------------------------------------
ex  _i far DON803___F;            // флаг выгрузки дозаторов сухого и мокрого
//---------------------------------------------------------------------------
//  пустая переменная для временных циклов
ex  _f  far ZERO;
//---------------------------------------------------------------------------
//  общая переменная выбора
ex  _f  far CHANGE;
//---------------------------------------------------------------------------
//  флаг работы регулятора
ex  _i  far RegRUN;
//---------------------------------------------------------------------------
//  номер выбранного рецепта загрузок
ex  _i  far RECEPT_VIB;
//---------------------------------------------------------------------------
ex  _i  far dayC;
ex  _i  far houC;
ex  _i  far minC;
ex  _i  far secC;
//---------------------------------------------------------------------------
