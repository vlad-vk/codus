//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
vd  far EverySec(vd){
    //-----------------------------------------------------------------------
    COM1HSMD_V=5;                 // секунды для подсчета состояния модулей
    COM2HSMD_V=5;                 //
    //-----------------------------------------------------------------------
    // Получить текущее время и дату
    GetTime(&houC, &minC, &secC);
    GetDate(&yeaC, &monC, &dayC);
    DAWC=WeekDay(yeaC, (monC-1), dayC);
    //-----------------------------------------------------------------------
    CDATP++; if(CDATP>=WDATP){ CDATP=0; WriteDataM=1; }

    if (xDefault>0){ SetDefVL(); xDefault=0; }
    if (RunLocal  ==0){ return; }
    //-----------------------------------------------------------------------
    // Обработка переменных и проверка сигнализации
    UpdDataS();

    //-----------------------------------------------------------------------
    // Передача правильных-ошибочных ответов от модулей
    COM1HSMD_C++; if (COM1HSMD_V<1){ COM1HSMD_V=5; }
    if (COM1HSMD_C>=COM1HSMD_V){
        COM1OK01_V=GetMODF(COMU1, 1,'o'); COM1ER01_V=GetMODF(COMU1, 1,'e');
        COM1OK02_V=GetMODF(COMU1, 2,'o'); COM1ER02_V=GetMODF(COMU1, 2,'e');
        COM1OK03_V=GetMODF(COMU1, 3,'o'); COM1ER03_V=GetMODF(COMU1, 3,'e');
        COM1OK04_V=GetMODF(COMU1, 4,'o'); COM1ER04_V=GetMODF(COMU1, 4,'e');
        COM1OK05_V=GetMODF(COMU1, 5,'o'); COM1ER05_V=GetMODF(COMU1, 5,'e');
        COM1OK06_V=GetMODF(COMU1, 6,'o'); COM1ER06_V=GetMODF(COMU1, 6,'e');
        COM1OK07_V=GetMODF(COMU1, 7,'o'); COM1ER07_V=GetMODF(COMU1, 7,'e');
        COM1OK08_V=GetMODF(COMU1, 8,'o'); COM1ER08_V=GetMODF(COMU1, 8,'e');
        COM1OK09_V=GetMODF(COMU1, 9,'o'); COM1ER09_V=GetMODF(COMU1, 9,'e');
        COM1OK0A_V=GetMODF(COMU1,10,'o'); COM1ER0A_V=GetMODF(COMU1,10,'e');
        COM1OK0B_V=GetMODF(COMU1,11,'o'); COM1ER0B_V=GetMODF(COMU1,11,'e');
        COM1OK10_V=GetMODF(COMU1,12,'o'); COM1ER10_V=GetMODF(COMU1,12,'e');
        COM1OK11_V=GetMODF(COMU1,13,'o'); COM1ER11_V=GetMODF(COMU1,13,'e');
        COM1OK12_V=GetMODF(COMU1,14,'o'); COM1ER12_V=GetMODF(COMU1,14,'e');
        COM1OK13_V=GetMODF(COMU1,15,'o'); COM1ER13_V=GetMODF(COMU1,15,'e');
        COM1OK14_V=GetMODF(COMU1,16,'o'); COM1ER14_V=GetMODF(COMU1,16,'e');
        COM1OK15_V=GetMODF(COMU1,17,'o'); COM1ER15_V=GetMODF(COMU1,17,'e');
        COM1OK16_V=GetMODF(COMU1,18,'o'); COM1ER16_V=GetMODF(COMU1,18,'e');
        COM1OK17_V=GetMODF(COMU1,19,'o'); COM1ER17_V=GetMODF(COMU1,19,'e');
        COM1OK18_V=GetMODF(COMU1,20,'o'); COM1ER18_V=GetMODF(COMU1,20,'e');
        SetMODF(COMU1, 0,'o',0);  SetMODF(COMU1, 0,'e',0);
        SetMODF(COMU1, 1,'o',0);  SetMODF(COMU1, 1,'e',0);
        SetMODF(COMU1, 2,'o',0);  SetMODF(COMU1, 2,'e',0);
        SetMODF(COMU1, 3,'o',0);  SetMODF(COMU1, 3,'e',0);
        SetMODF(COMU1, 4,'o',0);  SetMODF(COMU1, 4,'e',0);
        SetMODF(COMU1, 5,'o',0);  SetMODF(COMU1, 5,'e',0);
        SetMODF(COMU1, 6,'o',0);  SetMODF(COMU1, 6,'e',0);
        SetMODF(COMU1, 7,'o',0);  SetMODF(COMU1, 7,'e',0);
        SetMODF(COMU1, 8,'o',0);  SetMODF(COMU1, 8,'e',0);
        SetMODF(COMU1, 9,'o',0);  SetMODF(COMU1, 9,'e',0);
        SetMODF(COMU1,10,'o',0);  SetMODF(COMU1,10,'e',0);
        SetMODF(COMU1,11,'o',0);  SetMODF(COMU1,11,'e',0);
        SetMODF(COMU1,12,'o',0);  SetMODF(COMU1,12,'e',0);
        SetMODF(COMU1,13,'o',0);  SetMODF(COMU1,13,'e',0);
        SetMODF(COMU1,14,'o',0);  SetMODF(COMU1,14,'e',0);
        SetMODF(COMU1,15,'o',0);  SetMODF(COMU1,15,'e',0);
        SetMODF(COMU1,16,'o',0);  SetMODF(COMU1,16,'e',0);
        SetMODF(COMU1,17,'o',0);  SetMODF(COMU1,17,'e',0);
        SetMODF(COMU1,18,'o',0);  SetMODF(COMU1,18,'e',0);
        SetMODF(COMU1,19,'o',0);  SetMODF(COMU1,19,'e',0);
        SetMODF(COMU1,20,'o',0);  SetMODF(COMU1,20,'e',0);
        COM1HSMD_C=0;
    }
    //-----------------------------------------------------------------------
    COM2HSMD_C++; if (COM2HSMD_V<1){ COM2HSMD_V=5; }
    if (COM2HSMD_C>=COM2HSMD_V){
        COM2OK20_V=GetMODF(COMU2, 0,'o'); COM2ER20_V=GetMODF(COMU2, 0,'e');
        COM2OK21_V=GetMODF(COMU2, 1,'o'); COM2ER21_V=GetMODF(COMU2, 1,'e');
        COM2OK22_V=GetMODF(COMU2, 2,'o'); COM2ER22_V=GetMODF(COMU2, 2,'e');
        COM2OK23_V=GetMODF(COMU2, 3,'o'); COM2ER23_V=GetMODF(COMU2, 3,'e');
        COM2OK24_V=GetMODF(COMU2, 4,'o'); COM2ER24_V=GetMODF(COMU2, 4,'e');
        COM2OK25_V=GetMODF(COMU2, 5,'o'); COM2ER25_V=GetMODF(COMU2, 5,'e');
        COM2OK26_V=GetMODF(COMU2, 6,'o'); COM2ER26_V=GetMODF(COMU2, 6,'e');
        COM2OK27_V=GetMODF(COMU2, 7,'o'); COM2ER27_V=GetMODF(COMU2, 7,'e');
        COM2OK28_V=GetMODF(COMU2,11,'o'); COM2ER28_V=GetMODF(COMU2,11,'e');
        COM2OK29_V=GetMODF(COMU2,12,'o'); COM2ER29_V=GetMODF(COMU2,12,'e');
        COM2OK2A_V=GetMODF(COMU2,13,'o'); COM2ER2A_V=GetMODF(COMU2,13,'e');
        COM2OK2B_V=GetMODF(COMU2,14,'o'); COM2ER2B_V=GetMODF(COMU2,14,'e');
        COM2OK2C_V=GetMODF(COMU2,15,'o'); COM2ER2C_V=GetMODF(COMU2,15,'e');
        COM2OK40_V=GetMODF(COMU2,16,'o'); COM2ER40_V=GetMODF(COMU2,16,'e');
        COM2OK41_V=GetMODF(COMU2,17,'o'); COM2ER41_V=GetMODF(COMU2,17,'e');
        COM2OK43_V=GetMODF(COMU2,18,'o'); COM2ER43_V=GetMODF(COMU2,18,'e');
        COM2OK44_V=GetMODF(COMU2,19,'o'); COM2ER44_V=GetMODF(COMU2,19,'e');
        COM2OK46_V=GetMODF(COMU2,20,'o'); COM2ER46_V=GetMODF(COMU2,20,'e');
        COM2OK47_V=GetMODF(COMU2,21,'o'); COM2ER47_V=GetMODF(COMU2,21,'e');
        COM2OK45_V=GetMODF(COMU2,25,'o'); COM2ER45_V=GetMODF(COMU2,25,'e');
        SetMODF(COMU2, 0,'o',0);  SetMODF(COMU2, 0,'e',0);
        SetMODF(COMU2, 1,'o',0);  SetMODF(COMU2, 1,'e',0);
        SetMODF(COMU2, 2,'o',0);  SetMODF(COMU2, 2,'e',0);
        SetMODF(COMU2, 3,'o',0);  SetMODF(COMU2, 3,'e',0);
        SetMODF(COMU2, 4,'o',0);  SetMODF(COMU2, 4,'e',0);
        SetMODF(COMU2, 5,'o',0);  SetMODF(COMU2, 5,'e',0);
        SetMODF(COMU2, 6,'o',0);  SetMODF(COMU2, 6,'e',0);
        SetMODF(COMU2, 7,'o',0);  SetMODF(COMU2, 7,'e',0);
        SetMODF(COMU2,11,'o',0);  SetMODF(COMU2,11,'e',0);
        SetMODF(COMU2,12,'o',0);  SetMODF(COMU2,12,'e',0);
        SetMODF(COMU2,13,'o',0);  SetMODF(COMU2,13,'e',0);
        SetMODF(COMU2,14,'o',0);  SetMODF(COMU2,14,'e',0);
        SetMODF(COMU2,15,'o',0);  SetMODF(COMU2,15,'e',0);
        SetMODF(COMU2,16,'o',0);  SetMODF(COMU2,16,'e',0);
        SetMODF(COMU2,17,'o',0);  SetMODF(COMU2,17,'e',0);
        SetMODF(COMU2,18,'o',0);  SetMODF(COMU2,18,'e',0);
        SetMODF(COMU2,19,'o',0);  SetMODF(COMU2,19,'e',0);
        SetMODF(COMU2,20,'o',0);  SetMODF(COMU2,20,'e',0);
        SetMODF(COMU2,21,'o',0);  SetMODF(COMU2,21,'e',0);
        SetMODF(COMU2,25,'o',0);  SetMODF(COMU2,25,'e',0);
        COM2HSMD_C=0;
    }
    //-----------------------------------------------------------------------

    PCCSWork=(PCCSWork>0)?0:1;
    nosound(); pSOUND=(pSOUND>0)?0:1;

    return;
}
//---------------------------------------------------------------------------
