//---------------------------------------------------------------------------
vd  far EverySec(vd){
    _i  FLDZ_ERR=0;
    //-----------------------------------------------------------------------
    COM1HSMD_V=3;                 // секунды для подсчета состояния модулей
    COM2HSMD_V=3;                 //
    //-----------------------------------------------------------------------
    InpDataS();
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
    COM1HSMD_C++; if (COM1HSMD_V<1){ COM1HSMD_V=10; }
    if (COM1HSMD_C>=COM1HSMD_V){
        COM1OK01_V=GetMODF(COMU1, 0,'o'); COM1ER01_V=GetMODF(COMU1, 0,'e');
        COM1OK02_V=GetMODF(COMU1, 1,'o'); COM1ER02_V=GetMODF(COMU1, 1,'e');
        COM1OK03_V=GetMODF(COMU1, 2,'o'); COM1ER03_V=GetMODF(COMU1, 2,'e');
        COM1OK04_V=GetMODF(COMU1, 3,'o'); COM1ER04_V=GetMODF(COMU1, 3,'e');
        COM1OK05_V=GetMODF(COMU1, 4,'o'); COM1ER05_V=GetMODF(COMU1, 4,'e');
        COM1OK06_V=GetMODF(COMU1, 5,'o'); COM1ER06_V=GetMODF(COMU1, 5,'e');
        COM1OK07_V=GetMODF(COMU1, 6,'o'); COM1ER07_V=GetMODF(COMU1, 6,'e');
        COM1OK08_V=GetMODF(COMU1, 7,'o'); COM1ER08_V=GetMODF(COMU1, 7,'e');
        COM1OK09_V=GetMODF(COMU1, 8,'o'); COM1ER09_V=GetMODF(COMU1, 8,'e');
        COM1OK0A_V=GetMODF(COMU1, 9,'o'); COM1ER0A_V=GetMODF(COMU1, 9,'e');
        COM1OK0B_V=GetMODF(COMU1,10,'o'); COM1ER0B_V=GetMODF(COMU1,10,'e');
        COM1OK0C_V=GetMODF(COMU1,11,'o'); COM1ER0C_V=GetMODF(COMU1,11,'e');
        COM1OK0D_V=GetMODF(COMU1,12,'o'); COM1ER0D_V=GetMODF(COMU1,12,'e');
        COM1OK0E_V=GetMODF(COMU1,13,'o'); COM1ER0E_V=GetMODF(COMU1,13,'e');
        COM1OK0F_V=GetMODF(COMU1,14,'o'); COM1ER0F_V=GetMODF(COMU1,14,'e');
        COM1OK10_V=GetMODF(COMU1,15,'o'); COM1ER10_V=GetMODF(COMU1,15,'e');
        COM1OK11_V=GetMODF(COMU1,16,'o'); COM1ER11_V=GetMODF(COMU1,16,'e');
        COM1OK12_V=GetMODF(COMU1,17,'o'); COM1ER12_V=GetMODF(COMU1,17,'e');
        COM1OK13_V=GetMODF(COMU1,18,'o'); COM1ER13_V=GetMODF(COMU1,18,'e');
        COM1OK14_V=GetMODF(COMU1,19,'o'); COM1ER14_V=GetMODF(COMU1,19,'e');
        COM1OK15_V=GetMODF(COMU1,20,'o'); COM1ER15_V=GetMODF(COMU1,20,'e');
        COM1OK16_V=GetMODF(COMU1,21,'o'); COM1ER16_V=GetMODF(COMU1,21,'e');
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
        COM1HSMD_C=0;
    }
    //-----------------------------------------------------------------------
    COM2HSMD_C++; if (COM2HSMD_V<1){ COM2HSMD_V=10; }
    if (COM2HSMD_C>=COM2HSMD_V){
        COM2OK01_V=GetMODF(COMU2, 0,'o'); COM2ER01_V=GetMODF(COMU2, 0,'e');
        COM2OK02_V=GetMODF(COMU2, 1,'o'); COM2ER02_V=GetMODF(COMU2, 1,'e');
        COM2OK03_V=GetMODF(COMU2, 2,'o'); COM2ER03_V=GetMODF(COMU2, 2,'e');
        SetMODF(COMU2,0,'o',0);  SetMODF(COMU2,0,'e',0);
        SetMODF(COMU2,1,'o',0);  SetMODF(COMU2,1,'e',0);
        SetMODF(COMU2,2,'o',0);  SetMODF(COMU2,2,'e',0);
        COM2HSMD_C=0;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Проверка состояния модулей:

    // Дозатор сухого:
    if(COM2OK01_V<1 and COM2ER01_V>0 and COM2ER01FL==OFF){ 
       Message(70); Bell(1); FLDZ_ERR=1;
       REG06R___M=OFF; COM2ER01FL=ON;
       DON141___V=OFF; DON141___M=OFF; 
       DON142___V=OFF; DON142___M=OFF; 
       DON143___V=OFF; DON143___M=OFF;
       DON150___V=OFF; DON150___M=OFF; 
       DON151___V=OFF; DON151___M=OFF; 
       DON152___V=OFF; DON152___M=OFF;
       DON171___V=OFF; DON171___M=OFF; 
       DON172___V=OFF; DON172___M=OFF; 
       DON173___V=OFF; DON173___M=OFF; 
       DON180___V=OFF; DON180___M=OFF; 
       DON181___V=OFF; DON181___M=OFF; 
       DON182___V=OFF; DON182___M=OFF;
       DON191___V=OFF; DON191___M=OFF; 
       DON192___V=OFF; DON192___M=OFF; 
       DON193___V=OFF; DON193___M=OFF;
    } else {
       if(COM2OK01_V>3 and COM2ER01FL==ON){
          Message(71); COM2ER01FL=OFF;
       }
    }

    // Дозатор мокрого:
    if(COM2OK02_V<1 and COM2ER02_V>0 and COM2ER02FL==OFF){ 
       Message(72); Bell(1); FLDZ_ERR=1;
       REG07R___M=OFF; COM2ER02FL=ON;
       DON202___V=OFF; DON202___M=OFF;
       DON203___V=OFF; DON203___M=OFF;
       DON211___V=OFF; DON211___M=OFF;
       DON212___V=OFF; DON212___M=OFF;
       DON221___V=OFF; DON221___M=OFF;
       DON222___V=OFF; DON222___M=OFF;
       DON231___V=OFF; DON231___M=OFF;
       DON232___V=OFF; DON232___M=OFF;
    } else {
       if(COM2OK02_V>3 and COM2ER02FL==ON){
          Message(73); COM2ER02FL=OFF;
       }
    }

    // Дозатор пасты:
    if(COM2OK03_V<1 and COM2ER03_V>0 and COM2ER03FL==OFF){ 
       Message(74); Bell(1); FLDZ_ERR=1;
       REG09R___M=OFF; COM2ER03FL=ON;
       DON281___V=OFF; DON281___M=OFF;
       DON291___V=OFF; DON291___M=OFF;
    } else {
       if(COM2OK03_V>3 and COM2ER03FL==ON){
          Message(75); COM2ER03FL=OFF;
       }
    }

    //-----------------------------------------------------------------------
    // Если была ошибка опроса приборов дозаторов
    if(FLDZ_ERR>0){
       RestoreCom(COMU2);
       COM_Baud[COMU2]=4800;                   
       COMCH[COMU2]=USO;                       
       InstallCom(COMU2,COM_Baud[COMU2],8,0,1);
       Message(80);
       Print("[%d:%d:%d] Reinitialize COM2: 4800, 8N1.\n",houC,minC,secC);
    }
    //-----------------------------------------------------------------------

    PCCSWork=(PCCSWork>0)?0:1;
    nosound(); pSOUND=(pSOUND>0)?0:1;

    //-----------------------------------------------------------------------
#ifdef TESTVAGI
    Print("VG:  REQ_IN_%#3.0f_SEC=%#3.0f   ER_ANSWER=%#3.0f\n",
                COM2HSMD_V,   COM2OK01_V,  COM2ER01_V);
    if(COM2ER01_V>COM2OK01_V-2){ 
       vg_err=1; 
    } else { 
       if(vg_err>0){ vg_cnt=0; }
          vg_err=0;  vg_erq=0;
    }
    if(vg_erq==0){
       vg_erq=vg_cnt; 
    }
    if(vg_err>0){
       Print("VG:  ----- NO ANSWERS FROM TP-001 (VAGI) [ERQ=%ld] ------\n\n",
              vg_erq);
    } else {   
       Print("VG:  ----------------------------------------------------\n\n");
    }
#endif
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
