//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
vd  far Start(vd){
    _i    a=0;                      // временная переменная
    _i    WStart=5;                 // пауза перед запуском программы
    _i    FSound=ON;                // флаг включения звука
    ui    x=0;

    //-----------------------------------------------------------------------
    // Чтение данных из файла конфигурации
    //--- Пауза перед запуском программы -----------------------
    a=Config('r',CFGFile,"Common","WTRUNP");
    CfgSTR[4]=0; a=atoi(CfgSTR); if(a>0&&a<9999)WStart=a;
    //--- Файл для записи-восстановления массива DBB -----------
    a=Config('r',CFGFile,"Common","DATAFL");
    CfgSTR[80]=0; if(strlen(CfgSTR)>4) strcpy(FNDat,CfgSTR);
    //--- Номер рабочей станции в сети -------------------------
    a=Config('r',CFGFile,"Network","NWS");
    if(strlen(CfgSTR)  <2){ CfgSTR[1]=CfgSTR[0]; CfgSTR[0]='0'; }
    if((atoi (CfgSTR))==0){ CfgSTR[0]='0'; CfgSTR[1]='2'; } ; CfgSTR[2]=0;
    WS_NB_SetNumber(CfgSTR);        // номер рабочей станции в сети NetBIOS
    WS_SP_SetNumber(CfgSTR);        // номер рабочей станции в сети RS485
    //--- Флаг работы по UDP -----------------------------------
    a=Config('r',CFGFile,"Network","UDP");
    if(strcmpi(CfgSTR,"ON")==0||strcmpi(CfgSTR,"YES")==0||CfgSTR[0]=='1'){
       UDP=1;
    }; CfgSTR[0]=0;
    //--- IP PORT для прослушивания интерфейса
    a=Config('r',CFGFile,"Network","PORT");
    CfgSTR[5]=0; x=atoi(CfgSTR); if(x>0&&x<65535) IPPORT=x;
    //--- IP адрес для отдельной посылки данных об этой станции (состоянии рег)
    a=Config('r',CFGFile,"Network","IPTOS1");
    CfgSTR[15]=0; strcpy(IPTOS1,CfgSTR);


    //-----------------------------------------------------------------------
    // Общие установки для COM-порта
    CRCF [COMU1] = 1;             // флаг контрольной суммы для УСО1
    CRCF [COMU2] = 1;             // флаг контрольной суммы для УСО2

    HEXF [COMU1] = 1;             // флаг HEX ответа  от УСО1
    HEXF [COMU2] = 1;             // флаг HEX ответа  от УСО2

    COMTO[COMU1] = 3;             // переопределение таймаута ответа модулей
    COMTO[COMU2] = 10;            // (по умолчанию 10(циклов программы))

    COMWT[COMU1] = 3;             // переопределение паузы между посылками
    COMWT[COMU2] = 10;            // комманд в порт (10 циклов вызывов)

    //-----------------------------------------------------------------------
    // Установка сигналов линий COM портов
    COM_FIFO[COMU1]=OFF;
    COM_FIFO[COMU2]=OFF;

    COM_DTR [COMU1]=ON;;    COM_RTS [COMU1]=ON;;
    COM_DTR [COMU2]=ON;;    COM_RTS [COMU2]=ON;;

    COM_OUT1[COMU1]=ON;;    COM_OUT2[COMU1]=ON;;
    COM_OUT1[COMU2]=ON;;    COM_OUT2[COMU2]=ON;;

    //-----------------------------------------------------------------------
    // звуковой сигнал запуска программы
    if(FSound!=OFF){
       sound(500); delay(200); nosound(); delay(100);
       sound(700); delay(200); nosound();
    }
    //-----------------------------------------------------------------------
    sprintf(StatCP[COMU1],"COM%d connected with modules I7000.",COMU1);
    COM_Baud[COMU1]=115200;                     // скорость порта обмена с УСО1
    COMCH[COMU1]=USO;                           // флаг обмена порта с УСО1
    InstallCom(COMU1,COM_Baud[COMU1],8,0,1);    // инициализация порта УСО1

    sprintf(StatCP[COMU2],"COM%d connected with modules I7000.",COMU2);
    COM_Baud[COMU2]=115200;                     // скорость порта обмена с УСО2
    COMCH[COMU2]=USO;                           // флаг обмена порта с УСО2
    InstallCom(COMU2,COM_Baud[COMU2],8,0,1);    // инициализация порта УСО2
    //-----------------------------------------------------------------------
    // конфигурирование модулей для группы УСО1:
    HMCF[COMU1]=21;                             // кол-во записей для порта
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       41,         "$016",       4, 14);
       SetMODC(COMU1,      1,       41,         "$016",       4, 14);
       SetMODC(COMU1,      2,       42,      "@020000",       7, 13);
       SetMODC(COMU1,      3,       41,         "$036",       4, 14);
       SetMODC(COMU1,      4,       42,      "@040000",       7, 13);
       SetMODC(COMU1,      5,       41,         "$056",       4, 14);
       SetMODC(COMU1,      6,       42,      "@060000",       7, 13);
       SetMODC(COMU1,      7,       41,         "$076",       4, 14);
       SetMODC(COMU1,      8,       41,         "$086",       4, 14);
       SetMODC(COMU1,      9,       41,         "$096",       4, 14);
       SetMODC(COMU1,     10,       42,      "@0A0000",       7, 13);
       SetMODC(COMU1,     11,       42,      "@0B0000",       7, 13);
       SetMODC(COMU1,     12,       41,         "$106",       4, 14);
       SetMODC(COMU1,     13,       42,      "@110000",       7, 13);
       SetMODC(COMU1,     14,       17,          "#12",       3,  8);
       SetMODC(COMU1,     15,       41,         "$136",       4, 14);
       SetMODC(COMU1,     16,       41,         "$146",       4, 14);
       SetMODC(COMU1,     17,       42,      "@150000",       7, 13);
       SetMODC(COMU1,     18,       42,      "@160000",       7, 13);
       SetMODC(COMU1,     19,       41,         "$176",       4, 14);
       SetMODC(COMU1,     20,       42,      "@180000",       7, 13);
    //-----------------------------------------------------------------------
    HMCF[COMU2]=26;                             // кол-во записей для порта
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU2,      0,       41,         "$206",       4, 14);
       SetMODC(COMU2,      1,       41,         "$216",       4, 14);
       SetMODC(COMU2,      2,       41,         "$226",       4, 14);
       SetMODC(COMU2,      3,       42,      "@230000",       7, 13);
       SetMODC(COMU2,      4,       42,      "@240000",       7, 13);
       SetMODC(COMU2,      5,       42,      "@250000",       7, 13);
       SetMODC(COMU2,      6,       17,          "#26",       3,  8);
       SetMODC(COMU2,      7,       24,  "#270+00.000",      11,  1);
       SetMODC(COMU2,      8,       24,  "#271+00.000",      11,  1);
       SetMODC(COMU2,      9,       24,  "#272+00.000",      11,  1);
       SetMODC(COMU2,     10,       24,  "#273+00.000",      11,  1);
       SetMODC(COMU2,     11,       41,         "$286",       4, 14);
       SetMODC(COMU2,     12,       41,         "$296",       4, 14);
       SetMODC(COMU2,     13,       42,      "@2A0000",       7, 13);
       SetMODC(COMU2,     14,       42,      "@2B0000",       7, 13);
       SetMODC(COMU2,     15,       17,          "#2C",       3,  8);
       SetMODC(COMU2,     16,       41,         "$406",       4, 14);
       SetMODC(COMU2,     17,       41,         "$416",       4, 14);
       SetMODC(COMU2,     18,       42,      "@430000",       7, 13);
       SetMODC(COMU2,     19,       42,      "@440000",       7, 13);
       SetMODC(COMU2,     20,       17,          "#46",       3,  8);
       SetMODC(COMU2,     21,       24,  "#470+00.000",      11,  1);
       SetMODC(COMU2,     22,       24,  "#471+00.000",      11,  1);
       SetMODC(COMU2,     23,       24,  "#472+00.000",      11,  1);
       SetMODC(COMU2,     24,       24,  "#473+00.000",      11,  1);
       SetMODC(COMU2,     25,       42,      "@450000",       7, 13);
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // инициализация сети NetBIOS
    InitNB(1);
    a=ptInit(IPPORT);
    if(a==1){ printf("TCP driver NOT initialized. \n"); }
    if(a==2){ printf("TCP driver descriptor error.\n"); }
    if(a==3){ printf("TCP network listen error.\n"); }
    get_addr(Descriptor);
    if(a==0){ printf("TCP driver initialized with ip=%d.%d.%d.%d:%d [%d]\n",ptIP.a,ptIP.b,ptIP.c,ptIP.d,IPPORT,UDP); }
    //-----------------------------------------------------------------------
    // чтение сохраненных данных
    WriteDataM=0; if(ReadDataP()>0){ Message(146,NOKV); }; GetVER();
    // дата и время компиляции
    rpDC=DateCMP1_V; rpTC=TimeCMP1_V;
    // вывод информации о программе
    sprintf(pVERSION,"Obukhov AEROC cell workshop. [Compiled: %s]\n\r",nVERSION);
    Print  ("%s",pVERSION);
    // обнуление первых десяти переменных
    for(a=0;a<10;a++){ DBB[a]=0; }
    //-----------------------------------------------------------------------
    // ждать WStart секунд нажатия клавиши
    for(RunLocal=0;RunLocal< WStart;){
        //-------------------------------------------------------------------
        // счетчик секунд
        if(Timer(0,1,2)==2){
           if(RunLocal==0){
              Print("Wait %dsec for choice run mode: [L]ocal,[Z]ero,[D]efault,[C]heck",
                     WStart);
           }; Print("."); RunLocal++;
        }
        //-------------------------------------------------------------------
        // ожидание нажатия клавиш
        if(LKey(1)>0){
           // обнуление массива DBB[] и установка значений по умолчанию
           if(LKey_=='Z'||LKey_=='z'){ SetZerVL  (); SetDefVL(); RunLocal=0; LKey(0); continue; }
           // установка значений по умолчанию
           if(LKey_=='D'||LKey_=='d'){ SetDefVL  (); RunLocal=0; LKey(0); continue; }
           // проверка граничных значений в массиве DBB[]
           if(LKey_=='C'||LKey_=='c'){ xCheckData(); RunLocal=0; LKey(0); continue; }
           // запуск программы в локальном режиме (без обмена)
           if(LKey_=='L'||LKey_=='l'){ RunLocal=0; }; break;
        }; LKey(0);
    };  LKey(0);
    //-----------------------------------------------------------------------
    if(RunLocal>0){
       Print("\n\rProgramm run in FULL mode.\n\r");
    } else {
       Print("\n\rProgramm run in LOCAL mode (Not poll modules).\n\r");
    }
    //-----------------------------------------------------------------------
    DBB[14]=17;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far End(vd){
    if(ExitForLoad>4){ WriteDataP(); }
    RestoreCom(COMU2);
    RestoreCom(COMU1);
    printf("\n");
    InitNB(0);
    ptDel ( );
    printf("End program !\n\n\n" );
}
//---------------------------------------------------------------------------

