// coding=cp866
//---------------------------------------------------------------------------
vd  far Start(vd){
    _i a=0;                       // �६����� ��६�����
    _i WStart=5;                  // ��㧠 ��। ����᪮� �ணࠬ��
    _i FSound=ON;                 // 䫠� ����祭�� ��㪠
    ui x=0;

    //-----------------------------------------------------------------------
    // �⥭�� ������ �� 䠩�� ���䨣��樨:

    //--- ��㧠 ��। ����᪮� �ணࠬ�� -----------------------
    a=Config('r',CFGFile,"Common","WTRUNP");
    CfgSTR[4]=0; a=atoi(CfgSTR); if(a>0&&a<9999)WStart=a;

    //--- ���� ��� �����-����⠭������� ���ᨢ� DBB -----------
    a=Config('r',CFGFile,"Common","DATAFL");
    CfgSTR[80]=0; if(strlen(CfgSTR)>4) strcpy(FNDat,CfgSTR);

    //--- ����� ࠡ�祩 �⠭樨 � �� -------------------------
    a=Config('r',CFGFile,"Network","NWS");
    if(strlen(CfgSTR)  <2){ CfgSTR[1]=CfgSTR[0]; CfgSTR[0]='0'; }
    if((atoi (CfgSTR))==0){ CfgSTR[0]='0'; CfgSTR[1]='2'; } ; CfgSTR[2]=0;
    WS_NB_SetNumber(CfgSTR);        // ����� ࠡ�祩 �⠭樨 � �� NetBIOS
    WS_SP_SetNumber(CfgSTR);        // ����� ࠡ�祩 �⠭樨 � �� RS485

    //--- ���� ࠡ��� �� UDP -----------------------------------
    a=Config('r',CFGFile,"Network","UDP");
    if(strcmpi(CfgSTR,"ON")==0||strcmpi(CfgSTR,"YES")==0||CfgSTR[0]=='1'){
       UDP=1;
    }; CfgSTR[0]=0;

    //--- IP PORT ��� ����訢���� ����䥩�
    a=Config('r',CFGFile,"Network","PORT");
    CfgSTR[5]=0; x=atoi(CfgSTR); if(x>0&&x<65535) IPPORT=x;


    CRCF [COMU1] = 1;             // 䫠� ����஫쭮� �㬬� ��� ���1
    HEXF [COMU1] = 1;             // 䫠� HEX �⢥�  �� ���1
    COMTO[COMU1] = 3;             // ��८�।������ ⠩���� �⢥� ���㫥�
    COMWT[COMU1] = 2;             // ��८�।������ ���� ����� ���뫪���

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
    if(FSound!=OFF)
    {
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
    HMCF[COMU1]=19;
    // SetMOD (port, rec_num, mod_type, "send_cmd_str", len_cmd, how_val_ans);
       SetMODC(COMU1,      0,       17,          "#01",       3,  8);
       SetMODC(COMU1,      1,       17,          "#02",       3,  8);
       SetMODC(COMU1,      2,       17,          "#03",       3,  8);
       SetMODC(COMU1,      3,       33,          "#04",       3,  3);
       SetMODC(COMU1,      4,       33,          "#05",       3,  3);
       SetMODC(COMU1,      5,       33,          "#06",       3,  3);
       SetMODC(COMU1,      6,       33,          "#07",       3,  3);
       SetMODC(COMU1,      7,       33,          "#08",       3,  3);
       SetMODC(COMU1,      8,       80,          "#090",      4,  1);
       SetMODC(COMU1,      9,       80,          "#091",      4,  1);
       SetMODC(COMU1,     10,       80,          "#0A0",      4,  1);
       SetMODC(COMU1,     11,       80,          "#0A1",      4,  1);
       SetMODC(COMU1,     12,       80,          "#0B0",      4,  1);
       SetMODC(COMU1,     13,       80,          "#0B1",      4,  1);
       SetMODC(COMU1,     14,       80,          "#0C0",      4,  1);
       SetMODC(COMU1,     15,       80,          "#0C1",      4,  1);
       SetMODC(COMU1,     16,       80,          "#0D0",      4,  1);
       SetMODC(COMU1,     17,       80,          "#0D1",      4,  1);
       SetMODC(COMU1,     18,       42,       "@0E0000",      7, 13);

    //-----------------------------------------------------------------------
    // �।���⥫쭠� ����ன�� ���㫥� (��᫥���� 2� ᨬ���� - CRC):
       Print("Initialize modules:\n");

       // ����� 7017: 06=0..20mA, 08=-10..+10V, 09=-5..+5V, 0C=-150..+150mV
       // 0x42(1000010): (bit7=1):�஢�ઠ CRC, (bit0..1=10):�뢮� � HEX �ଠ�
       ToComStr( COMU1,"%0101080A4226");         delay(100);
          Print("COM%d: %0101080A4226\n",COMU1); delay(100);

       ToComStr( COMU1,"%0202080A4228");         delay(100);
          Print("COM%d: %0202080A4228\n",COMU1); delay(100);

       ToComStr( COMU1,"%0303080A422A");         delay(100);
          Print("COM%d: %0303080A422A\n",COMU1); delay(100);

       // ���㫨 7033 ������ ���� ����஥�� ⮫쪮 ��� ࠡ��� � HEX ०���
       // 23= pt100, 0..600C, a=0,00385
       // 0x42(1000010): (bit7=1):�஢�ઠ CRC, (bit0..1=10):�뢮� � HEX �ଠ�
       ToComStr( COMU1,"%0404270A422D");         delay(100);
          Print("COM%d: %0404270A422D\n",COMU1); delay(100);

       ToComStr( COMU1,"%0505260A422E");         delay(100);
          Print("COM%d: %0505260A422E\n",COMU1); delay(100);

       ToComStr( COMU1,"%0606270A4231");         delay(100);
          Print("COM%d: %0606270A4231\n",COMU1); delay(100);

       ToComStr( COMU1,"%0707260A4232");         delay(100);
          Print("COM%d: %0707260A4232\n",COMU1); delay(100);

       ToComStr( COMU1,"%0808260A4234");         delay(100);
          Print("COM%d: %0808260A4234\n",COMU1); delay(100);

       // 50-०�� COUNTER(!), 51-०�� FREQUENCY 
       // 0x40(1000000):�஢�ઠ CRC(!)
       // In0,In1-������砥�� �����(!)
       // � ��஭� ��⠭��-��� �������஢����� �室�
       // �  ��⨢���������-��� �����஢�����(!)
       // ����� ���� �ᯮ�짮������ �롨ࠥ��� ��������: $09Bx
       // $09B0 - ��� �� �����஢����, $09B1 - ��� �����஢����(!)
       ToComStr( COMU1,"%0909500A4031");         delay(100);
          Print("COM%d: %0909500A4031\n",COMU1); delay(100);
       // ��⠭����� ���뢠���  ���祭�� � �����஢����� �室��
       ToComStr( COMU1,"$09B100");               delay(100);
       // ��⠭����� ���������  �஢��� TTL ᨣ���� 0.8 �����
       ToComStr( COMU1,"$091L0872");             delay(100);
       // ��⠭����� ���ᨬ���� �஢��� TTL ᨣ���� 9.0 �����
       ToComStr( COMU1,"$091H906F");             delay(100);
       // ��⠭����� �ਭ� �������  �஢�� TTL= 900 us (0.9ms)
       ToComStr( COMU1,"$090L0090002");          delay(100);
       // ��⠭����� �ਭ� ���孥�� �஢�� TTL= 900 us (0.9ms)
       ToComStr( COMU1,"$090H00900FE");          delay(100);

       ToComStr( COMU1,"%0A0A500A4041");         delay(100);
          Print("COM%d: %0A0A500A4041\n",COMU1); delay(100);
       ToComStr( COMU1,"$0AB108");               delay(100);
       ToComStr( COMU1,"$0A1L087A");             delay(100);
       ToComStr( COMU1,"$0A1H9077");             delay(100);
       ToComStr( COMU1,"$0A0L009000A");          delay(100);
       ToComStr( COMU1,"$0A0H0090006");          delay(100);

       ToComStr( COMU1,"%0B0B500A4043");         delay(100);
          Print("COM%d: %0B0B500A4043\n",COMU1); delay(100);
       ToComStr( COMU1,"$0BB109");               delay(100);
       ToComStr( COMU1,"$0B1L087B");             delay(100);
       ToComStr( COMU1,"$0B1H9078");             delay(100);
       ToComStr( COMU1,"$0B0L009000B");          delay(100);
       ToComStr( COMU1,"$0B0H0090007");          delay(100);

       ToComStr( COMU1,"%0C0C500A4045");         delay(100);
          Print("COM%d: %0C0C500A4045\n",COMU1); delay(100);
       ToComStr( COMU1,"$0CB10A");               delay(100);
       ToComStr( COMU1,"$0C1L087C");             delay(100);
       ToComStr( COMU1,"$0C1H9079");             delay(100);
       ToComStr( COMU1,"$0C0L0200005");          delay(100);
       ToComStr( COMU1,"$0C0H0090008");          delay(100);

       ToComStr( COMU1,"%0D0D500A4047");         delay(100);
          Print("COM%d: %0D0D500A4047\n",COMU1); delay(100);
       ToComStr( COMU1,"$0DB10B");               delay(100);
       ToComStr( COMU1,"$0D1L087D");             delay(100);
       ToComStr( COMU1,"$0D1H907A");             delay(100);
       ToComStr( COMU1,"$0D0L009000D");          delay(100);
       ToComStr( COMU1,"$0D0H0090009");          delay(100);

       // ���㫨 7041,7042:
       // 40 - DIO mode
       // 40 - Enable CRC
       ToComStr( COMU1,"%0E0E400A4048");

    //-----------------------------------------------------------------------
    // ���樠������ �� NetBIOS
    LocalInitNB(1);
    WS_NB__ClearReqArr();

    //-----------------------------------------------------------------------
    // �⥭�� ��࠭����� ������
    WriteDT1_M=0; ReadDataP(); GetVER();
    // ��� � �६� �������樨
    rpDC=DateCMP1_V; rpTC=TimeCMP1_V;
    // �뢮� ���ଠ樨 � �ணࠬ��
    sprintf(pVERSION,"Kiev Karton Paper Combine. Gofrotar. [Compiled: %s]\n\r",nVERSION);
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
    // ��砫�� ��⠭����

    AIF301HC_M=-1;  // ���������
    AIF302HC_M=-1;
    AIF311HC_M=-1;
    AIF312HC_M=-1;
    AIF322HC_M=-1;
    AIF40VHC_M=-1;

    AIF303HC_M=-1;  // ���稪�
    AIF304HC_M=-1;
    AIF331HC_M=-1;
    AIF332HC_M=-1;
    AIF34VHC_M=-1;
    AIF35VHC_M=-1;
    AIF36VHC_M=-1;
    AIX0C1HC_M=-1;
    AIF37VHC_M=-1;
    AIF38VHC_M=-1;

    AIF301SC_M=-1;
    AIF302SC_M=-1;
    AIF311SC_M=-1;
    AIF312SC_M=-1;
    AIF322SC_M=-1;
    AIF40VSC_M=-1;
    AIF303SC_M=-1;
    AIF304SC_M=-1;
    AIF331SC_M=-1;
    AIF332SC_M=-1;
    AIF34VSC_M=-1;
    AIF35VSC_M=-1;
    AIF36VSC_M=-1;
    AIX0C1SC_M=-1;
    AIF37VSC_M=-1;
    AIF38VSC_M=-1;

    AIF301SO_M=-1;
    AIF302SO_M=-1;
    AIF311SO_M=-1;
    AIF312SO_M=-1;
    AIF322SO_M=-1;
    AIF40VSO_M=-1;
    AIF303SO_M=-1;
    AIF304SO_M=-1;
    AIF331SO_M=-1;
    AIF332SO_M=-1;
    AIF34VSO_M=-1;
    AIF35VSO_M=-1;
    AIF36VSO_M=-1;
    AIX0C1SO_M=-1;
    AIF37VSO_M=-1;
    AIF38VSO_M=-1;

    AIF301DC_M=-1;
    AIF302DC_M=-1;
    AIF311DC_M=-1;
    AIF312DC_M=-1;
    AIF322DC_M=-1;
    AIF40VDC_M=-1;
    AIF303DC_M=-1;
    AIF304DC_M=-1;
    AIF331DC_M=-1;
    AIF332DC_M=-1;
    AIF34VDC_M=-1;
    AIF35VDC_M=-1;
    AIF36VDC_M=-1;
    AIX0C1DC_M=-1;
    AIF37VDC_M=-1;
    AIF38VDC_M=-1;

    AIF301DO_M=-1;
    AIF302DO_M=-1;
    AIF311DO_M=-1;
    AIF312DO_M=-1;
    AIF322DO_M=-1;
    AIF40VDO_M=-1;
    AIF303DO_M=-1;
    AIF304DO_M=-1;
    AIF331DO_M=-1;
    AIF332DO_M=-1;
    AIF34VDO_M=-1;
    AIF35VDO_M=-1;
    AIF36VDO_M=-1;
    AIX0C1DO_M=-1;
    AIF37VDO_M=-1;
    AIF38VDO_M=-1;

    AIF301MC_M=-1;
    AIF302MC_M=-1;
    AIF311MC_M=-1;
    AIF312MC_M=-1;
    AIF322MC_M=-1;
    AIF40VMC_M=-1;
    AIF303MC_M=-1;
    AIF304MC_M=-1;
    AIF331MC_M=-1;
    AIF332MC_M=-1;
    AIF34VMC_M=-1;
    AIF35VMC_M=-1;
    AIF36VMC_M=-1;
    AIX0C1MC_M=-1;
    AIF37VMC_M=-1;
    AIF38VMC_M=-1;

    AIF301MO_M=-1;
    AIF302MO_M=-1;
    AIF311MO_M=-1;
    AIF312MO_M=-1;
    AIF322MO_M=-1;
    AIF40VMO_M=-1;
    AIF303MO_M=-1;
    AIF304MO_M=-1;
    AIF331MO_M=-1;
    AIF332MO_M=-1;
    AIF34VMO_M=-1;
    AIF35VMO_M=-1;
    AIF36VMO_M=-1;
    AIX0C1MO_M=-1;
    AIF37VMO_M=-1;
    AIF38VMO_M=-1;

    // ��⠭���� 䫠��� �ࠢ������� ��������� �������� ���稪��
    AIF303FS=1;
    AIF304FS=1;
    AIF331FS=1;
    AIF332FS=1;
    AIF34VFS=1;
    AIF35VFS=1;
    AIF36VFS=1;
    AIX0C1FS=1;
    AIF37VFS=1;
    AIF38VFS=1;

    //-----------------------------------------------------------------------
    Bell(1,OFF); DBB[11]=1; DBB[24]=0;

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
    printf("End program !\n\n\n");
    return;
}
//---------------------------------------------------------------------------
