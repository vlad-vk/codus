// coding: cp1251
//---------------------------------------------------------------------------
//  установка значений по умолчанию
vd  far SetDefVL(vd){

    Print("\n\rSet default values for ALL variables.\n\r>\n\r"); LKey(0);
    DateCMP1_V=rpDC;                  // дата  компиляции
    TimeCMP1_V=rpTC;                  // время компиляции
    COM1HSMD_M=2;                     // секунд для подсчета состояния модулей
    COM2HSMD_M=2;                     //

    //  давление пара
    AIP201_SZM=AIP201_SZV=-6.25;
    AIP201_SDM=AIP201_SDV=30;
    AIP201_AZM=AIP201_AZV=1;
    AIP201_AMM=AIP201_AMV=16;
    AIP201__FM=AIP201__FV=1;
    AIP201__AM=AIP201__AV=5;

    //  давление конденсата
    AIP202_SZM=AIP202_SZV=-0.25;
    AIP202_SDM=AIP202_SDV=1.2;
    AIP202_AZM=AIP202_AZV=0.05;
    AIP202_AMM=AIP202_AMV=1.2;
    AIP202__FM=AIP202__FV=0.1;
    AIP202__AM=AIP202__AV=5;

    //  расход пара
    AIF301_SZM=AIF301_SZV=-1.575;
    AIF301_SDM=AIF301_SDV=7.56;
    AIF301_AZM=AIF301_AZV=0.1;
    AIF301_AMM=AIF301_AMV=7.5;
    AIF301__FM=AIF301__FV=0.5;
    AIF301__AM=AIF301__AV=5;

    //  расход конденсата
    AIF302_SZM=AIF302_SZV=-1.575;
    AIF302_SDM=AIF302_SDV=7.56;
    AIF302_AZM=AIF302_AZV=-0.2;
    AIF302_AMM=AIF302_AMV=7.5;
    AIF302__FM=AIF302__FV=0.5;
    AIF302__AM=AIF302__AV=5;

    //  температура пара
    AIT101_SDM=AIT101_SDV=600;
    AIT101_AZM=AIT101_AZV=10;
    AIT101_AMM=AIT101_AMV=300;
    AIT101__FM=AIT101__FV=50;
    AIT101__AM=AIT101__AV=5;

    //  температура конденсата
    AIT102_SDM=AIT102_SDV=600;
    AIT102_AZM=AIT102_AZV=10;
    AIT102_AMM=AIT102_AMV=300;
    AIT102__FM=AIT102__FV=50;
    AIT102__AM=AIT102__AV=5;

    //  температура воды на входе
    AIT104_SDM=AIT104_SDV=100;
    AIT104_AZM=AIT104_AZV=5;
    AIT104_AMM=AIT104_AMV=100;
    AIT104__FM=AIT104__FV=5;
    AIT104__AM=AIT104__AV=5;

    //  температура горячей воды
    AIT105_SDM=AIT105_SDV=100;
    AIT105_AZM=AIT105_AZV=5;
    AIT105_AMM=AIT105_AMV=100;
    AIT105__FM=AIT105__FV=5;
    AIT105__AM=AIT105__AV=5;

    //  расход воды на входе
    AIF303_SDM=AIF303_SDV=0.01;
    AIF303__FM=AIF303__FV=5.00;
    AIF303FS=1;                      // уст флага уравнив показаний счетчика

    //  расход горячей воды на входе
    AIF304_SDM=AIF304_SDV=0.01;
    AIF304__FM=AIF304__FV=5.00;
    AIF304FS=1;                      // уст флага уравнив показаний счетчика

    //  расход газа
    AIF38V_SDM=AIF38V_SDV=1;
    AIF38V__FM=AIF38V__FV=250.0;
    AIF38VFS=1;                      // уст флага уравнив показаний счетчика

    //
    ReadDataER=0;

    return;
}
//---------------------------------------------------------------------------
