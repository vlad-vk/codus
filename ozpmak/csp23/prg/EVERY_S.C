//---------------------------------------------------------------------------
vd  far EverySec(vd){

    COM1HSMD_V=3;                 // секунды для подсчета состояния модулей
    COM2HSMD_V=3;                 //

    UpdDataS();

    InpDataS();

    //-----------------------------------------------------------------------
    // Получить текущее время и дату
    GetTime(&houC, &minC, &secC);
    GetDate(&yeaC, &monC, &dayC);
    DAWC3=WeekDay(yeaC, (monC-1), dayC);
    //-----------------------------------------------------------------------
    // Подсчет времени для автоматической записи данных
    // CDATP++; if(CDATP>=WDATP){ CDATP=0; WriteDT3_M=1; }
    //-----------------------------------------------------------------------
    // Определение установок по-умолчанию
    if (xDefault>0){ SetDefVL(); xDefault=0; }
    if (RunLocal  ==0){ return; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // Передача правильных-ошибочных ответов от модулей
    COM2HSMD_C++; if (COM2HSMD_V<1){ COM2HSMD_V=10; }
    if (COM2HSMD_C>=COM2HSMD_V){
        COM2OK30_V=GetMODF(COMU1, 0,'o'); COM2ER30_V=GetMODF(COMU1, 0,'e');
        COM2OK31_V=GetMODF(COMU1, 1,'o'); COM2ER31_V=GetMODF(COMU1, 1,'e');
        COM2OK32_V=GetMODF(COMU1, 2,'o'); COM2ER32_V=GetMODF(COMU1, 2,'e');
        COM2OK33_V=GetMODF(COMU1, 3,'o'); COM2ER33_V=GetMODF(COMU1, 3,'e');
        COM2OK34_V=GetMODF(COMU1, 4,'o'); COM2ER34_V=GetMODF(COMU1, 4,'e');
        COM2OK35_V=GetMODF(COMU1, 5,'o'); COM2ER35_V=GetMODF(COMU1, 5,'e');
        COM2OK36_V=GetMODF(COMU1, 6,'o'); COM2ER36_V=GetMODF(COMU1, 6,'e');
        COM2OK37_V=GetMODF(COMU1, 7,'o'); COM2ER37_V=GetMODF(COMU1, 7,'e');
        COM2OK38_V=GetMODF(COMU1, 8,'o'); COM2ER38_V=GetMODF(COMU1, 8,'e');
        COM2OK39_V=GetMODF(COMU1, 9,'o'); COM2ER39_V=GetMODF(COMU1, 9,'e');
        COM2OK3A_V=GetMODF(COMU1,10,'o'); COM2ER3A_V=GetMODF(COMU1,10,'e');
        COM2OK41_V=GetMODF(COMU1,11,'o'); COM2ER41_V=GetMODF(COMU1,11,'e');
        COM2OK42_V=GetMODF(COMU1,12,'o'); COM2ER42_V=GetMODF(COMU1,12,'e');
        COM2OK43_V=GetMODF(COMU1,13,'o'); COM2ER43_V=GetMODF(COMU1,13,'e');
        COM2OK44_V=GetMODF(COMU1,14,'o'); COM2ER44_V=GetMODF(COMU1,14,'e');
        COM2OK45_V=GetMODF(COMU1,15,'o'); COM2ER45_V=GetMODF(COMU1,15,'e');
        COM2OK46_V=GetMODF(COMU1,16,'o'); COM2ER46_V=GetMODF(COMU1,16,'e');
        COM2OK47_V=GetMODF(COMU1,17,'o'); COM2ER47_V=GetMODF(COMU1,17,'e');
        COM2OK48_V=GetMODF(COMU1,18,'o'); COM2ER48_V=GetMODF(COMU1,18,'e');
        COM2OK49_V=GetMODF(COMU1,19,'o'); COM2ER49_V=GetMODF(COMU1,19,'e');

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
        SetMODF(COMU1,21,'o',0);  SetMODF(COMU1,21,'e',0);
        COM2HSMD_C=0;
    }
    //-----------------------------------------------------------------------

    nosound(); pSOUND=(pSOUND>0)?0:1;
    DBB[51]=AUTHCNTZ;
    DBB[52]=AUTHCURC;

    return;
}
//---------------------------------------------------------------------------
