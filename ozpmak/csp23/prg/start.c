ui far desSND1=0;
ui far desSND2=0;
struct ptADDR ptSND1;
struct ptADDR ptSND2;
//---------------------------------------------------------------------------
vd  far Start(vd){
    _i a=0;                       // �६����� ��६�����
    _i WStart=5;                  // ��㧠 ��। ����᪮� �ணࠬ��
    _i FSound=ON;                 // 䫠� ����祭�� ��㪠
    ui x=0;

    //-----------------------------------------------------------------------
    //  �⥭�� ������ �� 䠩�� ���䨣��樨
    //--- ��㧠 ��। ����᪮� �ணࠬ�� -----------------------
    a=Config('r',CFGFile,"Common","WTRUNP");
    TmpStr[4]=0; a=atoi(TmpStr); if(a>0&&a<9999)WStart=a;
    //--- ���� ��� �����-����⠭������� ���ᨢ� DBB -----------
    a=Config('r',CFGFile,"Common","DATAFL");
    TmpStr[80]=0; if(strlen(TmpStr)>4) strcpy(FNDat,TmpStr);
    //--- ����� ࠡ�祩 �⠭樨 � �� -------------------------
    a=Config('r',CFGFile,"Network","NWS");
    if(strlen(TmpStr)<2){ TmpStr[1]=TmpStr[0]; TmpStr[0]='0'; }
    if((atoi (TmpStr))==0){ TmpStr[0]='0'; TmpStr[1]='2'; } ; TmpStr[2]=0;
    WS_NB_SetNumber(TmpStr);        // ����� ࠡ�祩 �⠭樨 � �� NetBIOS
    WS_SP_SetNumber(TmpStr);        // ����� ࠡ�祩 �⠭樨 � �� RS485
    //--- ���� ࠡ��� �� UDP -----------------------------------
    a=Config('r',CFGFile,"Network","UDP");
    if(strcmpi(TmpStr,"ON")==0||strcmpi(TmpStr,"YES")==0||TmpStr[0]=='1'){
       UDP=1;
    }; TmpStr[0]=0;
    //--- IP PORT ��� ����訢���� ����䥩�
    a=Config('r',CFGFile,"Network","PORT");
    TmpStr[5]=0; x=atoi(TmpStr); if(x>0&&x<65535) IPPORT=x;
    //--- IP ���� ��� �⤥�쭮� ���뫪� ������ �� �⮩ �⠭樨 (���ﭨ� ॣ)
    a=Config('r',CFGFile,"Network","IPTOS1");
    TmpStr[15]=0; strcpy(IPTOS1,TmpStr);
    a=Config('r',CFGFile,"Network","IPTOS2");
    TmpStr[15]=0; strcpy(IPTOS2,TmpStr);


    //-----------------------------------------------------------------------
    CRCF [COMU1] = 1;             // 䫠� ����஫쭮� �㬬� ��� ���1
    HEXF [COMU1] = 1;             // 䫠� HEX �⢥�  �� ���1
    COMTO[COMU1] = 3;             // ��८�।������ ⠩���� �⢥� ���㫥�
    COMWT[COMU1] = 2;             // ��८�।������ ���� ����� ���뫪���

    WS_NB_SetNumber("23");        // ����� ࠡ�祩 �⠭樨 � �� NetBIOS
    WS_SP_SetNumber("23");        // ����� ࠡ�祩 �⠭樨 � �� RS485

    //-----------------------------------------------------------------------
    // ��⠭���� ᨣ����� ����� COM ���⮢
    COM_FIFO[COMU1]=OFF;
    COM_FIFO[COMWS]=OFF;

    COM_DTR [COMU1]=ON;;    COM_RTS [COMU1]=ON;;
    COM_DTR [COMWS]=ON;;    COM_RTS [COMWS]=ON;;

    COM_OUT1[COMU1]=ON;;    COM_OUT2[COMU1]=ON;;
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

    //-----------------------------------------------------------------------
    // ���䨣��஢���� ���㫥� ��� ��㯯� ���1:
    HMCF[COMU1]=21;
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       17,          "#30",       3,  8);
       SetMODC(COMU1,      1,       41,         "$316",       4, 14);
       SetMODC(COMU1,      2,       41,         "$326",       4, 14);
       SetMODC(COMU1,      3,       42,      "@330000",       7, 13);
       SetMODC(COMU1,      4,       42,      "@340000",       7, 13);
       SetMODC(COMU1,      5,       41,         "$356",       4, 14);
       SetMODC(COMU1,      6,       42,      "@360000",       7, 13);
       SetMODC(COMU1,      7,       41,         "$376",       4, 14);
       SetMODC(COMU1,      8,       17,          "#01",       3,  8);
       SetMODC(COMU1,      9,       33,          "#39",       3,  3);
       SetMODC(COMU1,     10,       17,          "#3A",       3,  8);

       SetMODC(COMU1,     11,       41,         "$416",       4, 14);
       SetMODC(COMU1,     12,       41,         "$426",       4, 14);
       SetMODC(COMU1,     13,       42,      "@430000",       7, 13);
       SetMODC(COMU1,     14,       42,      "@440000",       7, 13);
       SetMODC(COMU1,     15,       41,         "$456",       4, 14);
       SetMODC(COMU1,     16,       42,      "@460000",       7, 13);
       SetMODC(COMU1,     17,       41,         "$476",       4, 14);
       SetMODC(COMU1,     18,        0,         "$486",       4, 14);
       SetMODC(COMU1,     19,       33,          "#49",       3,  3);
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �।���⥫쭠� ����ன�� ���㫥�:
       Print("Initialize modules:\n");

       // ����� 7017: 06=0..20mA, 09=-5..+5V, 0C=-150..+150mV
       // 0x42(1000010): (bit7=1):�஢�ઠ CRC, (bit0..1=10):�뢮� � HEX �ଠ�
       ToComStr( COMU1,"%3030090A42");
          Print("COM%d: %3030090A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%0101090A42");
          Print("COM%d: %0101090A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%3A3A0C0A42");
          Print("COM%d: %3A3A0C0A42\n",COMU1); delay(100);

       // ���㫨 7033 ������ ���� ����஥�� ⮫쪮 ��� ࠡ��� � HEX ०���
       // 23= pt100, 0..600C, a=0,00385
       // 0x42(1000010): (bit7=1):�஢�ઠ CRC, (bit0..1=10):�뢮� � HEX �ଠ�
       ToComStr( COMU1,"%3939230A42");
          Print("COM%d: %3939230A42\n",COMU1); delay(100);
       ToComStr( COMU1,"%4949230A42");
          Print("COM%d: %4949230A42\n",COMU1); delay(100);

       // ���㫨 7041:
       // 40 - DIO mode
       // 40 - Enable CRC
       ToComStr( COMU1,"%3131400A40");
       ToComStr( COMU1,"%3232400A40");
       ToComStr( COMU1,"%3535400A40");
       ToComStr( COMU1,"%3737400A40");

       ToComStr( COMU1,"%4141400A40");
       ToComStr( COMU1,"%4242400A40");
       ToComStr( COMU1,"%4545400A40");
       ToComStr( COMU1,"%4747400A40");

       // ���㫨 7042:
       ToComStr( COMU1,"%3333400A40");
       ToComStr( COMU1,"%3434400A40");
       ToComStr( COMU1,"%3636400A40");

       ToComStr( COMU1,"%4343400A40");
       ToComStr( COMU1,"%4444400A40");
       ToComStr( COMU1,"%4646400A40");
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ���樠������ �� NetBIOS
    LocalInitNB(1);
    WS_NB__ClearReqArr();
    NBW_SetValForReq();
    a=ptInit(IPPORT); 
    if(a==1){ printf("TCP driver NOT initialized. \n"); }
    if(a==2){ printf("TCP driver descriptor error.\n"); }
    if(a==3){ printf("TCP network listen error.\n"); }
    get_addr(Descriptor);
    if(a==0){ printf("TCP driver initialized with ip=%d.%d.%d.%d\n",ptIP.a,ptIP.b,ptIP.c,ptIP.d); }
    desSND1=net_connect(0xffff,protocol_datagram,&ptSND1);
    desSND2=net_connect(0xffff,protocol_datagram,&ptSND2);
    //-----------------------------------------------------------------------
    // �⥭�� ��࠭����� ������
    WriteDT3_M=0; ReadDataP(); GetVER();
    // ��� � �६� �������樨
    rpDC=DateCMP3_V; rpTC=TimeCMP3_V;
    // �뢮� ���ଠ樨 � �ணࠬ��
    sprintf(pVERSION,"Program for honeycomb concrete plant. Autoclaves N3,4. [%s]\n\r",nVERSION);
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
    Bell(3,OFF);
    Bell(4,OFF);
    DBB[11]=1;
    DBB[51]=1;
    DBB[64]=0;
    for(a=161;a<180;a++) DBB[a]=0;
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
