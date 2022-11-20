// coding=cp866
//---------------------------------------------------------------------------
_f  far modcnt=0;
vd  far EverySec(vd){

    modcnt++; if(modcnt>268435455) modcnt=0;

    COM1HSMD_V=3;                 // секунды для подсчета состояния модулей
    COM2HSMD_V=3;                 //

    GetMTM();                     // получить текущее воемя и дату

    InpDataS();
    if(PAINPC<PAINP) PAINPC++;    // счетчик для вклю фильтра аналоговых сиг

    UpdDataS();
    Signal();

    //-----------------------------------------------------------------------
    // Определение установок по-умолчанию
    if (xDefault>0){ SetDefVL(); xDefault=0; }
    if (RunLocal  ==0){ return; }
    //-----------------------------------------------------------------------

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
        COM2OK08_V=GetMODF(COMU1, 7,'o'); COM2ER08_V=GetMODF(COMU1, 7,'e');
        COM2OK09_V=GetMODF(COMU1, 8,'o'); COM2ER09_V=GetMODF(COMU1, 8,'e');
        COM2OK0A_V=GetMODF(COMU1,10,'o'); COM2ER0A_V=GetMODF(COMU1,10,'e');
        COM2OK0B_V=GetMODF(COMU1,12,'o'); COM2ER0B_V=GetMODF(COMU1,12,'e');
        COM2OK0C_V=GetMODF(COMU1,14,'o'); COM2ER0C_V=GetMODF(COMU1,14,'e');
        COM2OK0D_V=GetMODF(COMU1,16,'o'); COM2ER0D_V=GetMODF(COMU1,16,'e');
        COM2OK0E_V=GetMODF(COMU1,18,'o'); COM2ER0E_V=GetMODF(COMU1,18,'e');

        SetMODF(COMU1, 0,'o',0);  SetMODF(COMU1, 0,'e',0);
        SetMODF(COMU1, 1,'o',0);  SetMODF(COMU1, 1,'e',0);
        SetMODF(COMU1, 2,'o',0);  SetMODF(COMU1, 2,'e',0);
        SetMODF(COMU1, 3,'o',0);  SetMODF(COMU1, 3,'e',0);
        SetMODF(COMU1, 4,'o',0);  SetMODF(COMU1, 4,'e',0);
        SetMODF(COMU1, 5,'o',0);  SetMODF(COMU1, 5,'e',0);
        SetMODF(COMU1, 6,'o',0);  SetMODF(COMU1, 6,'e',0);
        SetMODF(COMU1, 7,'o',0);  SetMODF(COMU1, 7,'e',0);
        SetMODF(COMU1, 8,'o',0);  SetMODF(COMU1, 8,'e',0);
        SetMODF(COMU1,10,'o',0);  SetMODF(COMU1,10,'e',0);
        SetMODF(COMU1,12,'o',0);  SetMODF(COMU1,12,'e',0);
        SetMODF(COMU1,14,'o',0);  SetMODF(COMU1,14,'e',0);
        SetMODF(COMU1,16,'o',0);  SetMODF(COMU1,16,'e',0);
        SetMODF(COMU1,18,'o',0);  SetMODF(COMU1,18,'e',0);

        COM2HSMD_C=0;
    }
    //-----------------------------------------------------------------------

    if(PAINPC>=PAINP){ Time_01(); }
    RepGen ();

    nosound(); pSOUND=(pSOUND>0)?0:1;

    if(DON70____V>0) DON70____V=0; else DON70____V=1;

    DBB[11]=AUTHCNTZ;
    DBB[12]=AUTHCURC;

    return;
}
//---------------------------------------------------------------------------
