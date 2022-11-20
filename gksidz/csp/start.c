//---------------------------------------------------------------------------
vd  far Start(vd){
    _i a=0;                       // �६����� ��६�����
    _i WStart=5;                  // ��㧠 ��। ����᪮� �ணࠬ��
    _i FSound=ON;                 // 䫠� ����祭�� ��㪠

    CRCF [COMU1] = 1;             // 䫠� ����஫쭮� �㬬� ��� ���1
    CRCF [COMU2] = 0;             // 䫠� ����஫쭮� �㬬� ��� ���2

    HEXF [COMU1] = 1;             // 䫠� HEX �⢥�  �� ���1
    HEXF [COMU2] = 0;             // 䫠� HEX �⢥�  �� ���2

    COMTO[COMU1] = 3;             // ��८�।������ ⠩���� �⢥� ���㫥�
    COMTO[COMU2] = 10;            // (�� 㬮�砭�� 10(横��� �ணࠬ��))

    COMWT[COMU1] = 2;             // ��८�।������ ���� ����� ���뫪���
    COMWT[COMU2] = 10;            // ������� � ���� (10 横��� ��뢮�)

    WS_NB_SetNumber("01");        // ����� ࠡ�祩 �⠭樨 � �� NetBIOS
    WS_SP_SetNumber("01");        // ����� ࠡ�祩 �⠭樨 � �� RS485

    //-----------------------------------------------------------------------
    // ��⠭���� ᨣ����� ����� COM ���⮢
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
    // ��㪮��� ᨣ��� ����᪠ �ணࠬ��
    if(FSound!=OFF){
       sound(500); delay(200); nosound(); delay(100);
       sound(700); delay(200); nosound();
    }
    //-----------------------------------------------------------------------
    sprintf(StatCP[COMWS],"COM%d connected with Operator Station.",COMWS);
    COM_Baud[COMWS]=115200;                     // ᪮���� ���� ������ � WS
    COMCH[COMWS]=WST;                           // 䫠� ������ ���� � WS
    InstallCom(COMWS,COM_Baud[COMWS],8,0,1);    // ���樠������ ���� WS

    sprintf(StatCP[COMU1],"COM%d connected with modules I7000.",COMU1);
    COM_Baud[COMU1]=115200;                     // ᪮���� ���� ������ � ���1
    COMCH[COMU1]=USO;                           // 䫠� ������ ���� � ���1
    InstallCom(COMU1,COM_Baud[COMU1],8,0,1);    // ���樠������ ���� ���1

    sprintf(StatCP[COMU2],"COM%d connected with TP-0001.",COMU2);
    COM_Baud[COMU2]=4800;                       // ᪮���� ���� ������ � ���2
    COMCH[COMU2]=USO;                           // 䫠� ������ ���� � ���2
    InstallCom(COMU2,COM_Baud[COMU2],8,0,1);    // ���樠������ ���� ���2
    //-----------------------------------------------------------------------
    // ���䨣��஢���� ���㫥� ��� ��㯯� ���1:
    HMCF[COMU1]=22;                             // ���-�� ����ᥩ ��� ����
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
    // ���䨣��஢���� ���㫥� ��� ��㯯� ���2:
    HMCF[COMU2]=4;                              // ���-�� ����ᥩ ��� ����
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU2,      0,        1,        "#\01W",       3,  1);
       SetMODC(COMU2,      1,        1,        "#\02W",       3,  1);
       SetMODC(COMU2,      2,        1,        "#\03W",       3,  1);
       SetMODC(COMU2,      3,        1,        "#\04W",       3,  1);
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �।���⥫쭠� ����ன�� �������� ���㫥�:
       Print("Initialize modules:\n");
       // ���㫨 7033 ������ ���� ����஥�� ⮫쪮 ��� ࠡ��� � HEX ०���
       ToComStr( COMU1,"%0101210A42");
          Print("COM%d: %0101210A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%0202210A42");
          Print("COM%d: %0202210A42\n",COMU1); delay(100);
       // ����� 7018: 00=-15+15mV 06=0..20mA, 41=�஢�ઠ CRC � �뢮� � %
       ToComStr( COMU1,"%0303000A41");
          Print("COM%d: %0303000A41\n",COMU1); delay(100);
       // ���㫨 7041:
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
       // ���㫨 7042:
       ToComStr( COMU1,"%1010400A40");
       ToComStr( COMU1,"%1111400A40");
       ToComStr( COMU1,"%1212400A40");
       ToComStr( COMU1,"%1313400A40");
       ToComStr( COMU1,"%1414400A40");
       ToComStr( COMU1,"%1515400A40");
       ToComStr( COMU1,"%1616400A40");
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ���樠������ �� NetBIOS
    InitNB(1);
    //-----------------------------------------------------------------------
    // �⥭�� ��࠭����� ������
    WriteDataM=0; if(ReadDataP()>0){ Message(146); }; GetVER();
    // ��� � �६� �������樨
    rpDC=DateCompil; rpTC=TimeCompil;
    // �뢮� ���ଠ樨 � �ணࠬ��
    sprintf(pVERSION,"Gitomir cell workshop. [Compiled: %s]\n\r",nVERSION);
    Print  ("%s",pVERSION);
    // ���㫥��� ����� ����� ��६�����
    for(a=0;a<10;a++){ DBB[a]=0; }
    //-----------------------------------------------------------------------
    // ����� WStart ᥪ㭤 ������ ������
    for(RunLocal=0;RunLocal< WStart;){
        //-------------------------------------------------------------------
        // ���稪 ᥪ㭤
        if(Timer(0,1,2)==2){
           if(RunLocal==0){
              Print("Wait %dsec for choice run mode: [L]ocal,[Z]ero,[D]efault,[C]heck",
                     WStart);
           }; Print("."); RunLocal++;
        }
        //-------------------------------------------------------------------
        // �������� ������ ������
        if(LKey(1)>0){
           // ���㫥��� ���ᨢ� DBB[] � ��⠭���� ���祭�� �� 㬮�砭��
           if(LKey_=='Z'||LKey_=='z'){ SetZerVL  (); SetDefVL(); RunLocal=0; LKey(0); continue; }
           // ��⠭���� ���祭�� �� 㬮�砭��
           if(LKey_=='D'||LKey_=='d'){ SetDefVL  (); RunLocal=0; LKey(0); continue; }
           // �஢�ઠ �࠭���� ���祭�� � ���ᨢ� DBB[]
           if(LKey_=='C'||LKey_=='c'){ xCheckData(); RunLocal=0; LKey(0); continue; }
           // ����� �ணࠬ�� � �����쭮� ०��� (��� ������)
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
    // �஢�ઠ ����祭�� �ਡ�஢ �����஢
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
