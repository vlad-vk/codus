//---------------------------------------------------------------------------
vd  far Start(vd){
    _i  a=0;                      // временная переменная
    _i  WStart=5;                 // пауза перед запуском программы
    _i  FSound=OFF;               // флаг включения звука

    Print("\nStart:\n");
    CRCF [COMU1] = 1;             // флаг контрольной суммы для УСО1
    HEXF [COMU1] = 0;             // флаг HEX ответа  от УСО1
    COMTO[COMU1] = 5;             // переопределение таймаута ответа модулей

    WS_NB_SetNumber("01");        // номер рабочей станции в сети NetBIOS
    WS_SP_SetNumber("01");        // номер рабочей станции в сети RS485

    DTR_RTS_OUT2=1;               // включить сигнал DTR, RTS, OUT2
    strcpy(FNDat,"cp_kamst.dat"); // имя файла данных
    //-----------------------------------------------------------------------
    // звуковой сигнал запуска программы
    if(FSound!=OFF){
       sound(500); delay(200); nosound(); delay(100);
       sound(700); delay(200); nosound();
    }
    //-----------------------------------------------------------------------
    Print("Initialize COM%d.\n",COMWS); delay(100);
    sprintf(StatCP[COMWS],"COM%d connected with Operator Station.",COMWS);
    COM_Baud[COMWS]=115200;                     // скорость порта обмена с WS
    COMCH[COMWS]=WST;                           // флаг обмена порта с WS
    InstallCom(COMWS,COM_Baud[COMWS],8,0,1);    // инициализация порта WS

    Print("Initialize COM%d.\n",COMU1); delay(100);
    sprintf(StatCP[COMU1],"COM%d connected with modules I7000.",COMU1);
    COM_Baud[COMU1]=115200;                     // скорость порта обмена с УСО1
    COMCH[COMU1]=USO;                           // флаг обмена порта с УСО1
    InstallCom(COMU1,COM_Baud[COMU1],8,0,1);    // инициализация порта УСО1

    //-----------------------------------------------------------------------
    // конфигурирование модулей для группы УСО1:
    HMCF[COMU1]=25;                             // кол-во записей для порта
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       17,          "#01",       3,  8);
       SetMODC(COMU1,      1,       17,          "#02",       3,  8);
       SetMODC(COMU1,      2,       17,          "#03",       3,  8);
       SetMODC(COMU1,      3,       17,          "#04",       3,  8);
       SetMODC(COMU1,      4,       17,          "#05",       3,  8);
       SetMODC(COMU1,      5,       17,          "#06",       3,  8);

       SetMODC(COMU1,      6,       24,  "#070+00.000",      11,  1);
       SetMODC(COMU1,      7,       24,  "#071+00.000",      11,  1);
       SetMODC(COMU1,      8,       24,  "#072+00.000",      11,  1);
       SetMODC(COMU1,      9,       24,  "#073+00.000",      11,  1);

       SetMODC(COMU1,     10,       24,  "#080+00.000",      11,  1);
       SetMODC(COMU1,     11,       24,  "#081+00.000",      11,  1);
       SetMODC(COMU1,     12,       24,  "#082+00.000",      11,  1);
       SetMODC(COMU1,     13,       24,  "#083+00.000",      11,  1);

       SetMODC(COMU1,     14,       24,  "#090+00.000",      11,  1);
       SetMODC(COMU1,     15,       24,  "#091+00.000",      11,  1);
       SetMODC(COMU1,     16,       24,  "#092+00.000",      11,  1);
       SetMODC(COMU1,     17,       24,  "#093+00.000",      11,  1);

       SetMODC(COMU1,     18,       24,  "#0A0+00.000",      11,  1);
       SetMODC(COMU1,     19,       24,  "#0A1+00.000",      11,  1);
       SetMODC(COMU1,     20,       24,  "#0A2+00.000",      11,  1);
       SetMODC(COMU1,     21,       24,  "#0A3+00.000",      11,  1);

       SetMODC(COMU1,     22,       41,         "$0B6",       4, 14);
       SetMODC(COMU1,     23,       41,         "$0C6",       4, 14);
       SetMODC(COMU1,     24,       42,      "@0D0000",       7, 13);
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // Предварительная настройка модулей:
       // модули 7018: 06=0..20mA, 0A-115200 b/sec, 41=проверка CRC, вывод в %
       ToComStr( COMU1,      "%0101060A41");
          Print("COM%d: 7018: %0101060A41\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0202060A41");
          Print("COM%d: 7018: %0202060A41\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0303060A41");
          Print("COM%d: 7018: %0303060A41\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0404060A41");
          Print("COM%d: 7018: %0404060A41\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0505060A41");
          Print("COM%d: 7018: %0505060A41\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0606060A41");
          Print("COM%d: 7018: %0606060A41\n",COMU1); delay(100);
       // модули 7024: 30=0..20mA, 0A-115200 b/sec, 40=проверка CRC, вывод в mA
       ToComStr( COMU1,      "%0707300A40");
          Print("COM%d: 7024: %0707300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0808300A40");
          Print("COM%d: 7024: %0808300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0909300A40");
          Print("COM%d: 7024: %0909300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0A0A300A40");
          Print("COM%d: 7024: %0A0A300A40\n",COMU1); delay(100);
       // модули 7041:
       ToComStr( COMU1,      "%0B0B400A40");
          Print("COM%d: 7041: %0B0B400A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0C0C400A40");
          Print("COM%d: 7041: %0C0C400A40\n",COMU1); delay(100);
       // модули 7042:
       ToComStr( COMU1,      "%0D0D400A40");
          Print("COM%d: 7042: %0D0D400A40\n",COMU1); delay(100);
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
    sprintf(pVERSION,"Kam***a sugar plant. [Compiled: %s]\n\r",nVERSION);
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
    printf( "End program !\n\n\n" );
}
//---------------------------------------------------------------------------

