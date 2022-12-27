//---------------------------------------------------------------------------
vd  far Start(vd){
    _i  a=0;                      // �६����� ��६�����
    _i  WStart=5;                 // ��㧠 ��। ����᪮� �ணࠬ��
    _i  FSound=OFF;               // 䫠� ����祭�� ��㪠

    Print("\nStart:\n");
    CRCF [COMU1] = 1;             // 䫠� ����஫쭮� �㬬� ��� ���1
    HEXF [COMU1] = 0;             // 䫠� HEX �⢥�  �� ���1
    COMTO[COMU1] = 5;             // ��८�।������ ⠩���� �⢥� ���㫥�

    WS_NB_SetNumber("01");        // ����� ࠡ�祩 �⠭樨 � �� NetBIOS
    WS_SP_SetNumber("01");        // ����� ࠡ�祩 �⠭樨 � �� RS485

    DTR_RTS_OUT2=1;               // ������� ᨣ��� DTR, RTS, OUT2
    strcpy(FNDat,"cp_kamst.dat"); // ��� 䠩�� ������
    //-----------------------------------------------------------------------
    // ��㪮��� ᨣ��� ����᪠ �ணࠬ��
    if(FSound!=OFF){
       sound(500); delay(200); nosound(); delay(100);
       sound(700); delay(200); nosound();
    }
    //-----------------------------------------------------------------------
    Print("Initialize COM%d.\n",COMWS); delay(100);
    sprintf(StatCP[COMWS],"COM%d connected with Operator Station.",COMWS);
    COM_Baud[COMWS]=115200;                     // ᪮���� ���� ������ � WS
    COMCH[COMWS]=WST;                           // 䫠� ������ ���� � WS
    InstallCom(COMWS,COM_Baud[COMWS],8,0,1);    // ���樠������ ���� WS

    Print("Initialize COM%d.\n",COMU1); delay(100);
    sprintf(StatCP[COMU1],"COM%d connected with modules I7000.",COMU1);
    COM_Baud[COMU1]=115200;                     // ᪮���� ���� ������ � ���1
    COMCH[COMU1]=USO;                           // 䫠� ������ ���� � ���1
    InstallCom(COMU1,COM_Baud[COMU1],8,0,1);    // ���樠������ ���� ���1

    //-----------------------------------------------------------------------
    // ���䨣��஢���� ���㫥� ��� ��㯯� ���1:
    HMCF[COMU1]=25;                             // ���-�� ����ᥩ ��� ����
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
    // �।���⥫쭠� ����ன�� ���㫥�:
       // ���㫨 7018: 06=0..20mA, 0A-115200 b/sec, 41=�஢�ઠ CRC, �뢮� � %
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
       // ���㫨 7024: 30=0..20mA, 0A-115200 b/sec, 40=�஢�ઠ CRC, �뢮� � mA
       ToComStr( COMU1,      "%0707300A40");
          Print("COM%d: 7024: %0707300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0808300A40");
          Print("COM%d: 7024: %0808300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0909300A40");
          Print("COM%d: 7024: %0909300A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0A0A300A40");
          Print("COM%d: 7024: %0A0A300A40\n",COMU1); delay(100);
       // ���㫨 7041:
       ToComStr( COMU1,      "%0B0B400A40");
          Print("COM%d: 7041: %0B0B400A40\n",COMU1); delay(100);
       ToComStr( COMU1,      "%0C0C400A40");
          Print("COM%d: 7041: %0C0C400A40\n",COMU1); delay(100);
       // ���㫨 7042:
       ToComStr( COMU1,      "%0D0D400A40");
          Print("COM%d: 7042: %0D0D400A40\n",COMU1); delay(100);
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
    sprintf(pVERSION,"Kam***a sugar plant. [Compiled: %s]\n\r",nVERSION);
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

