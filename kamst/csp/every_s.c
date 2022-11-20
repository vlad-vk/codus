//---------------------------------------------------------------------------
vd  far EverySec(vd){
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
    COM2HSMD_C++; if (COM2HSMD_V<1){ COM2HSMD_V=10; }
    if (COM2HSMD_C>=COM2HSMD_V){
        COM2OK01_V=GetMODF(COMU1, 0,'o'); COM2ER01_V=GetMODF(COMU1, 0,'e');
        COM2OK02_V=GetMODF(COMU1, 1,'o'); COM2ER02_V=GetMODF(COMU1, 1,'e');
        COM2OK03_V=GetMODF(COMU1, 2,'o'); COM2ER03_V=GetMODF(COMU1, 2,'e');
        COM2OK04_V=GetMODF(COMU1, 3,'o'); COM2ER04_V=GetMODF(COMU1, 3,'e');
        COM2OK05_V=GetMODF(COMU1, 4,'o'); COM2ER05_V=GetMODF(COMU1, 4,'e');
        COM2OK06_V=GetMODF(COMU1, 5,'o'); COM2ER06_V=GetMODF(COMU1, 5,'e');
        COM2OK07_V=GetMODF(COMU1, 6,'o'); COM2ER07_V=GetMODF(COMU1, 6,'e');
        COM2OK08_V=GetMODF(COMU1,10,'o'); COM2ER08_V=GetMODF(COMU1,10,'e');
        COM2OK09_V=GetMODF(COMU1,14,'o'); COM2ER09_V=GetMODF(COMU1,14,'e');
        COM2OK0A_V=GetMODF(COMU1,18,'o'); COM2ER0A_V=GetMODF(COMU1,18,'e');
        COM2OK0B_V=GetMODF(COMU1,22,'o'); COM2ER0B_V=GetMODF(COMU1,22,'e');
        COM2OK0C_V=GetMODF(COMU1,23,'o'); COM2ER0C_V=GetMODF(COMU1,23,'e');
        COM2OK0D_V=GetMODF(COMU1,24,'o'); COM2ER0D_V=GetMODF(COMU1,24,'e');
        SetMODF(COMU1, 0,'o',0);  SetMODF(COMU1, 0,'e',0);
        SetMODF(COMU1, 1,'o',0);  SetMODF(COMU1, 1,'e',0);
        SetMODF(COMU1, 2,'o',0);  SetMODF(COMU1, 2,'e',0);
        SetMODF(COMU1, 3,'o',0);  SetMODF(COMU1, 3,'e',0);
        SetMODF(COMU1, 4,'o',0);  SetMODF(COMU1, 4,'e',0);
        SetMODF(COMU1, 5,'o',0);  SetMODF(COMU1, 5,'e',0);
        SetMODF(COMU1, 6,'o',0);  SetMODF(COMU1, 6,'e',0);
        SetMODF(COMU1,10,'o',0);  SetMODF(COMU1,10,'e',0);
        SetMODF(COMU1,14,'o',0);  SetMODF(COMU1,14,'e',0);
        SetMODF(COMU1,18,'o',0);  SetMODF(COMU1,18,'e',0);
        SetMODF(COMU1,22,'o',0);  SetMODF(COMU1,22,'e',0);
        SetMODF(COMU1,23,'o',0);  SetMODF(COMU1,23,'e',0);
        SetMODF(COMU1,24,'o',0);  SetMODF(COMU1,24,'e',0);
        COM2HSMD_C=0;
    }
    //-----------------------------------------------------------------------
    PCCSWork=(PCCSWork>0)?0:1;
    nosound(); pSOUND=(pSOUND>0)?0:1;

    return;
}
//---------------------------------------------------------------------------
