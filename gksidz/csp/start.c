//---------------------------------------------------------------------------
vd  far Start(vd){
    _i a=0;                       // временная переменная
    _i WStart=5;                  // пауза перед запуском программы
    _i FSound=ON;                 // флаг включения звука

    CRCF [COMU1] = 1;             // флаг контрольной суммы для УСО1
    CRCF [COMU2] = 0;             // флаг контрольной суммы для УСО2

    HEXF [COMU1] = 1;             // флаг HEX ответа  от УСО1
    HEXF [COMU2] = 0;             // флаг HEX ответа  от УСО2

    COMTO[COMU1] = 3;             // переопределение таймаута ответа модулей
    COMTO[COMU2] = 10;            // (по умолчанию 10(циклов программы))

    COMWT[COMU1] = 2;             // переопределение паузы между посылками
    COMWT[COMU2] = 10;            // комманд в порт (10 циклов вызывов)

    WS_NB_SetNumber("01");        // номер рабочей станции в сети NetBIOS
    WS_SP_SetNumber("01");        // номер рабочей станции в сети RS485

    //-----------------------------------------------------------------------
    // Установка сигналов линий COM портов
    COM_FIFO[COMU1]=OFF;
    COM_FIFO[COMU2]=OFF;
    COM_FIFO[COMWS]=OFF;
#ifndef OFFICE
    COM_FIFO[COMU2]=ON;;
#endif
    COM_DTR [COMU1]=ON;;    COM_RTS [COMU1]=ON;;
    COM_DTR [COMU2]=ON;;    COM_RTS [COMU2]=ON;;
    COM_DTR [COMWS]=ON;;    COM_RTS [COMWS]=ON;;

    COM_OUT1[COMU1]=ON;;    COM_OUT2[COMU1]=ON;;
    COM_OUT1[COMU2]=ON;;    COM_OUT2[COMU2]=ON;;
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

    sprintf(StatCP[COMU2],"COM%d connected with TP-0001.",COMU2);
    COM_Baud[COMU2]=4800;                       // скорость порта обмена с УСО2
    COMCH[COMU2]=USO;                           // флаг обмена порта с УСО2
    InstallCom(COMU2,COM_Baud[COMU2],8,0,1);    // инициализация порта УСО2
    //-----------------------------------------------------------------------
    // конфигурирование модулей для группы УСО1:
    HMCF[COMU1]=22;                             // кол-во записей для порта
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       33,          "#01",       3,  3);
       SetMODC(COMU1,      1,       33,          "#02",       3,  3);
       SetMODC(COMU1,      2,       00,             "",       0,  0);

       SetMODC(COMU1,      3,       41,         "$046",       4, 14);
       SetMODC(COMU1,      4,       41,         "$056",       4, 14);
       SetMODC(COMU1,      5,       41,         "$066",       4, 14);
       SetMODC(COMU1,      6,       41,         "$076",       4, 14);
       SetMODC(COMU1,      7,       41,         "$086",       4, 14);
       SetMODC(COMU1,      8,       41,         "$096",       4, 14);
       SetMODC(COMU1,      9,       41,         "$0A6",       4, 14);
       SetMODC(COMU1,     10,       41,         "$0B6",       4, 14);
       SetMODC(COMU1,     11,       41,         "$0C6",       4, 14);
       SetMODC(COMU1,     12,       41,         "$0D6",       4, 14);
       SetMODC(COMU1,     13,       41,         "$0E6",       4, 14);
       SetMODC(COMU1,     14,       41,         "$0F6",       4, 14);

       SetMODC(COMU1,     15,       42,      "@100000",       7, 13);
       SetMODC(COMU1,     16,       42,      "@110000",       7, 13);
       SetMODC(COMU1,     17,       42,      "@120000",       7, 13);
       SetMODC(COMU1,     18,       42,      "@130000",       7, 13);
       SetMODC(COMU1,     19,       42,      "@140000",       7, 13);
       SetMODC(COMU1,     20,       42,      "@150000",       7, 13);
       SetMODC(COMU1,     21,       42,      "@160000",       7, 13);
    //-----------------------------------------------------------------------
    // конфигурирование модулей для группы УСО2:
    HMCF[COMU2]=4;                              // кол-во записей для порта
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU2,      0,        1,        "#\01W",       3,  1);
       SetMODC(COMU2,      1,        1,        "#\02W",       3,  1);
       SetMODC(COMU2,      2,        1,        "#\03W",       3,  1);
       SetMODC(COMU2,      3,        1,        "#\04W",       3,  1);
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Предварительная настройка некоторых модулей:
       Print("Initialize modules:\n");
       // модули 7033 должны быть настроены только для работы в HEX режиме
       ToComStr( COMU1,"%0101210A42");
          Print("COM%d: %0101210A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%0202210A42");
          Print("COM%d: %0202210A42\n",COMU1); delay(100);
       // модуль 7018: 00=-15+15mV 06=0..20mA, 41=проверка CRC и вывод в %
       ToComStr( COMU1,"%0303000A41");
          Print("COM%d: %0303000A41\n",COMU1); delay(100);
       // модули 7041:
       ToComStr( COMU1,"%0404400A40");
       ToComStr( COMU1,"%0505400A40");
       ToComStr( COMU1,"%0606400A40");
       ToComStr( COMU1,"%0707400A40");
       ToComStr( COMU1,"%0808400A40");
       ToComStr( COMU1,"%0909400A40");
       ToComStr( COMU1,"%0A0A400A40");
       ToComStr( COMU1,"%0B0B400A40");
       ToComStr( COMU1,"%0C0C400A40");
       ToComStr( COMU1,"%0D0D400A40");
       ToComStr( COMU1,"%0E0E400A40");
       ToComStr( COMU1,"%0F0F400A40");
       ToComStr( COMU1,"%0F0F400A40");
       // модули 7042:
       ToComStr( COMU1,"%1010400A40");
       ToComStr( COMU1,"%1111400A40");
       ToComStr( COMU1,"%1212400A40");
       ToComStr( COMU1,"%1313400A40");
       ToComStr( COMU1,"%1414400A40");
       ToComStr( COMU1,"%1515400A40");
       ToComStr( COMU1,"%1616400A40");
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // инициализация сети NetBIOS
    InitNB(1);
    //-----------------------------------------------------------------------
    // чтение сохраненных данных
    WriteDataM=0; if(ReadDataP()>0){ Message(146); }; GetVER();
    // дата и время компиляции
    rpDC=DateCompil; rpTC=TimeCompil;
    // вывод информации о программе
    sprintf(pVERSION,"Gitomir cell workshop. [Compiled: %s]\n\r",nVERSION);
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
    // Проверка включения приборов дозаторов
    if(DZT01ON__V==OFF){
       SetMODC(COMU2,      0,        0,             "",       0,  0);
    }
    if(DZT02ON__V==OFF){
       SetMODC(COMU2,      1,        0,             "",       0,  0);
    }
    if(DZT03ON__V==OFF){
       SetMODC(COMU2,      2,        0,             "",       0,  0);
    }
    if(DZT04ON__V==OFF){
       SetMODC(COMU2,      3,        0,             "",       0,  0);
    }
    //-----------------------------------------------------------------------
    DBB[13]=12;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far End(vd){
    if(ExitForLoad>4){ WriteDataP(); }
    RestoreCom(COMU2);
    RestoreCom(COMU1);
    RestoreCom(COMWS);
    printf("\n");
    InitNB(0);
    printf( "End program !\n\n\n" );
}
//---------------------------------------------------------------------------
