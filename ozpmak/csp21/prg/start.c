ui far desSND1=0;
ui far desSND2=0;
struct ptADDR ptSND1;
struct ptADDR ptSND2;
//---------------------------------------------------------------------------
vd  far Start(vd){
    _i a=0;                       // временная переменная
    _i WStart=5;                  // пауза перед запуском программы
    _i FSound=ON;                 // флаг включения звука
    ui x=0;

    //-----------------------------------------------------------------------
    //  Чтение данных из файла конфигурации
    //--- Пауза перед запуском программы -----------------------
    a=Config('r',CFGFile,"Common","WTRUNP",TmpStr);
    TmpStr[4]=0; a=atoi(TmpStr); if(a>0&&a<9999)WStart=a;
    //--- Файл для записи-восстановления массива DBB -----------
    a=Config('r',CFGFile,"Common","DATAFL",TmpStr);
    TmpStr[80]=0; if(strlen(TmpStr)>4) strcpy(FNDat,TmpStr);
    //--- Номер рабочей станции в сети -------------------------
    a=Config('r',CFGFile,"Network","NWS",TmpStr);
    if(strlen(TmpStr)<2){ TmpStr[1]=TmpStr[0]; TmpStr[0]='0'; }
    if((atoi (TmpStr))==0){ TmpStr[0]='0'; TmpStr[1]='2'; } ; TmpStr[2]=0;
    WS_NB_SetNumber(TmpStr);        // номер рабочей станции в сети NetBIOS
    WS_SP_SetNumber(TmpStr);        // номер рабочей станции в сети RS485
    //--- Флаг работы по UDP -----------------------------------
    a=Config('r',CFGFile,"Network","UDP",TmpStr);
    if(strcmpi(TmpStr,"ON")==0||strcmpi(TmpStr,"YES")==0||TmpStr[0]=='1'){
       UDP=1;
    }; TmpStr[0]=0;
    //--- IP PORT для прослушивания интерфейса
    a=Config('r',CFGFile,"Network","PORT",TmpStr);
    TmpStr[5]=0; x=atoi(TmpStr); if(x>0&&x<65535) IPPORT=x;
    //--- IP адрес для отдельной посылки данных об этой станции (состоянии рег)
    a=Config('r',CFGFile,"Network","IPTOS1",TmpStr);
    TmpStr[15]=0; strcpy(IPTOS1,TmpStr);
    a=Config('r',CFGFile,"Network","IPTOS2",TmpStr);
    TmpStr[15]=0; strcpy(IPTOS2,TmpStr);

    //-----------------------------------------------------------------------
    CRCF [COMU1] = 1;             // флаг контрольной суммы для УСО1
    HEXF [COMU1] = 1;             // флаг HEX ответа  от УСО1
    COMTO[COMU1] = 3;             // переопределение таймаута ответа модулей
    COMWT[COMU1] = 2;             // переопределение паузы между посылками

    WS_NB_SetNumber("21");        // номер рабочей станции в сети NetBIOS
    WS_SP_SetNumber("21");        // номер рабочей станции в сети RS485

    //-----------------------------------------------------------------------
    // Установка сигналов линий COM портов
    COM_FIFO[COMU1]=OFF;
    COM_FIFO[COMWS]=OFF;

    COM_DTR [COMU1]=ON;;    COM_RTS [COMU1]=ON;;
    COM_DTR [COMWS]=ON;;    COM_RTS [COMWS]=ON;;

    COM_OUT1[COMU1]=ON;;    COM_OUT2[COMU1]=ON;;
    COM_OUT1[COMWS]=ON;;    COM_OUT2[COMWS]=ON;;

    //-----------------------------------------------------------------------
    // звуковой сигнал запуска программы
    if(FSound!=OFF){
       sound(500); delay(200); nosound(); delay(100);
       sound(700); delay(200); nosound();
    }
    //-----------------------------------------------------------------------
    sprintf(StatCP[COMWS],"COM%d connected with Operator Station.",COMWS);
    COM_Baud[COMWS]=115200;                     // скорость порта обмена с WS
    COMCH[COMWS]=WST;                           // флаг обмена порта с WS
    InstallCom(COMWS,COM_Baud[COMWS],8,0,1);    // инициализация порта WS

    sprintf(StatCP[COMU1],"COM%d connected with modules I7000.",COMU1);
    COM_Baud[COMU1]=115200;                     // скорость порта обмена с УСО1
    COMCH[COMU1]=USO;                           // флаг обмена порта с УСО1
    InstallCom(COMU1,COM_Baud[COMU1],8,0,1);    // инициализация порта УСО1

    //-----------------------------------------------------------------------
    // конфигурирование модулей для группы УСО1:
    HMCF[COMU1]=21;
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       17,          "#10",       3,  8);
       SetMODC(COMU1,      1,       41,         "$116",       4, 14);
       SetMODC(COMU1,      2,       41,         "$126",       4, 14);
       SetMODC(COMU1,      3,       42,      "@130000",       7, 13);
       SetMODC(COMU1,      4,       42,      "@140000",       7, 13);
       SetMODC(COMU1,      5,       41,         "$156",       4, 14);
       SetMODC(COMU1,      6,       42,      "@160000",       7, 13);
       SetMODC(COMU1,      7,       41,         "$176",       4, 14);
       SetMODC(COMU1,      8,       41,         "$186",       4, 14);
       SetMODC(COMU1,      9,       33,          "#19",       3,  3);
       SetMODC(COMU1,     10,       17,          "#1A",       3,  8);

       SetMODC(COMU1,     11,       41,         "$216",       4, 14);
       SetMODC(COMU1,     12,       41,         "$226",       4, 14);
       SetMODC(COMU1,     13,       42,      "@230000",       7, 13);
       SetMODC(COMU1,     14,       42,      "@240000",       7, 13);
       SetMODC(COMU1,     15,       41,         "$256",       4, 14);
       SetMODC(COMU1,     16,       42,      "@260000",       7, 13);
       SetMODC(COMU1,     17,       41,         "$276",       4, 14);
       SetMODC(COMU1,     18,       41,         "$286",       4, 14);
       SetMODC(COMU1,     19,       33,          "#29",       3,  3);
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Предварительная настройка модулей:
       Print("Initialize modules:\n");

       // модуль 7017: 06=0..20mA, 09=-5..+5V, 0C=-150..+150mV
       // 0x42(1000010): (bit7=1):проверка CRC, (bit0..1=10):вывод в HEX формате
       ToComStr( COMU1,"%1010090A42");
          Print("COM%d: %1010090A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%1A1A0C0A42");
          Print("COM%d: %1A1A0C0A42\n",COMU1); delay(100);

       // модули 7033 должны быть настроены только для работы в HEX режиме
       // 23= pt100, 0..600C, a=0,00385
       // 0x42(1000010): (bit7=1):проверка CRC, (bit0..1=10):вывод в HEX формате
       ToComStr( COMU1,"%1919230A42");
          Print("COM%d: %1919230A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%2929230A42");
          Print("COM%d: %2929230A42\n",COMU1); delay(100);

       // модули 7041:
       // 40 - DIO mode
       // 40 - Enable CRC
       ToComStr( COMU1,"%1111400A40");
       ToComStr( COMU1,"%1212400A40");
       ToComStr( COMU1,"%1515400A40");
       ToComStr( COMU1,"%1717400A40");
       ToComStr( COMU1,"%1818400A40");

       ToComStr( COMU1,"%2121400A40");
       ToComStr( COMU1,"%2222400A40");
       ToComStr( COMU1,"%2525400A40");
       ToComStr( COMU1,"%2727400A40");
       ToComStr( COMU1,"%2828400A40");

       // модули 7042:
       ToComStr( COMU1,"%1313400A40");
       ToComStr( COMU1,"%1414400A40");
       ToComStr( COMU1,"%1616400A40");

       ToComStr( COMU1,"%2323400A40");
       ToComStr( COMU1,"%2424400A40");
       ToComStr( COMU1,"%2626400A40");
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // инициализация сети NetBIOS
    LocalInitNB(1);
    WS_NB__ClearReqArr();
    NBW_SetValForReq();
    a=ptInit(IPPORT);
    if(a==1){ printf("TCP driver NOT initialized.\n"); }
    if(a==2){ printf("TCP driver descriptor error.\n"); }
    if(a==3){ printf("TCP network listen error.\n"); }
    get_addr(Descriptor);
    if(a==0){ printf("TCP driver initialized with ip=%d.%d.%d.%d\n",ptIP.a,ptIP.b,ptIP.c,ptIP.d); }
    desSND1=net_connect(0xffff,protocol_datagram,&ptSND1);
    desSND2=net_connect(0xffff,protocol_datagram,&ptSND2);
    //-----------------------------------------------------------------------
    // чтение сохраненных данных
    WriteDT1_M=0; ReadDataP(); GetVER();
    // дата и время компиляции
    rpDC=DateCMP1_V; rpTC=TimeCMP1_V;
    // вывод информации о программе
    sprintf(pVERSION,"Obukhov honeycomb concrete plant. Autoclaves N1,2. [%s]\n\r",nVERSION);
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
    Bell(1,OFF);
    Bell(2,OFF);
    DBB[11]=1;
    DBB[24]=0;
    for(a=131;a<150;a++) DBB[a]=0;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far End(vd){
    if(ExitForLoad>4){ WriteDataP(); }
    RestoreCom(COMU1);
    RestoreCom(COMWS);
    printf("\n");
    InitNB(0);
    net_eof(desSND1);
    net_eof(desSND2);
    net_eof(Descriptor);
    net_releaseall();
    printf( "End program !\n\n\n" );
}
//---------------------------------------------------------------------------
