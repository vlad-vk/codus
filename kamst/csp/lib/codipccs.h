//---------------------------------------------------------------------------
//  IPCCSCOM.H:
//---------------------------------------------------------------------------
ex  us  far THR;
ex  us  far RDR;
ex  us  far BRDL;
ex  us  far BRDH;
ex  us  far IER;
ex  us  far IIR;
ex  us  far FCR;
ex  us  far LCR;
ex  us  far MCR;
ex  us  far LSR;
ex  us  far MSR;
ex  us  far SCR;
//---------------------------------------------------------------------------
ex  ui  far DTR_RTS_OUT2;
//  DTR,RTS,OUT2 signal enable flag
//---------------------------------------------------------------------------
ex  uc  far EnableIRQ ;
ex  uc  far DisableIRQ;
//---------------------------------------------------------------------------
ex  uc  far ICTStat[MCOM];
//  Byte of the status register when sending data to the port
//---------------------------------------------------------------------------
ex  uc  far OutChar[MCOM];
//  Current byte sent to COM port
//---------------------------------------------------------------------------
ex  uc  far TempB  [MCOM];
ex  uc  far SaveB  [MCOM];
//  Temporary variables
//---------------------------------------------------------------------------
ex  uc  far COM_ReadBuff[MCOM][RBFSZ];
//  Receive Buffer
//---------------------------------------------------------------------------
ex  uc  far COM_SendBuff[MCOM][RBFSZ];
//  Transfer Buffer
//---------------------------------------------------------------------------
ex  ui  far COM_HRB [MCOM];
ex  ui  far COM_TRB [MCOM];
//  Pointer in the receive buffer
//---------------------------------------------------------------------------
ex  ui  far COM_HSB [MCOM];
//  Pointer in the transmit buffer
//---------------------------------------------------------------------------
ex  ui  far COM_CSB[MCOM];
//  Total number of characters to send in the buffer
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  IPCCSCOM.C:
//---------------------------------------------------------------------------
ex  ui  far InstallCom(ui p, ui Baud, ui Data, ui Chet, ui Stop);
//  Set a new interrupt vector for the specified COM port
//  nPort - COM port number for which the interrupt is set (1-COM1)
//---------------------------------------------------------------------------
ex  vd  far RestoreCom(ui Port);
//  Setting the old interrupt vector for COM ports
//  Port - COM port number for which the interrupt is set (1-COM1)
//---------------------------------------------------------------------------
ex  _i  far IsCom(ui Port);
//  Checking for the presence of received characters in the receive buffer
//  Return: 1 - there is data in the buffer, 0 - there is no data in the buffer
//---------------------------------------------------------------------------
ex  uc  far ReadCom(ui Port);
//  Reading data from the receive buffer
//  Return: Current character from buffer
//---------------------------------------------------------------------------
ex  vd  far COMOut(ui Port);
//  Sending characters through the specified COM port
//---------------------------------------------------------------------------
ex  int far ToComStr(ui Port, uc *Str);
//  Sending a string through the specified COM port
//  Port - COM port number for sending data (1-COM1...)
//  Str  - string to send
//  Return value:
//         1 - function completed successfully
//---------------------------------------------------------------------------
ex  int far ToComBufn(ui Port, uc Buf[RBFSZ], ui Num);
//  Sending a specified number of bytes through the specified COM port
//  Port - COM port number for sending data (1-COM1...)
//  Buf  - send buffer
//  Num  - a certain number of characters to send
//  Retun value:
//         1 - function completed successfully
//---------------------------------------------------------------------------
ex  uc  far COM_BitSelect(uc BS_Byte, ui BS_Num);
//  Extracting a specified bit from a byte
//  BS_Byte - byte value from which to extract a bit
//  BS_Num  - bit number to extract from the specified byte value
//---------------------------------------------------------------------------
ex  int far ClearCom (int Port);
//  Clearing the receive buffer for the specified COM port
//  Port - COM port number for which the receive buffer is being cleared (1-COM1)
//---------------------------------------------------------------------------
ex  vd  far COM_ClearSendBuff(ui Port);
//  Clearing the transmit buffer for the specified COM port
//  Port - COM port number for which the receive buffer is being cleared (1-COM1)
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  IPCCSTIM.C:
//---------------------------------------------------------------------------
ex  vd  far GetTime(int *hour, int *min, int *sec);
//  ������� � ��६���� �� 㪠����� ���ᠬ ⥪�饥 �६�
//---------------------------------------------------------------------------
ex  vd  far GetDate(int *year, int *mon, int *day);
//  ������� � ��६���� �� 㪠����� ���ᠬ ⥪�饥 �६�
//---------------------------------------------------------------------------
ex  vd  far SetTime(int hour, int min, int sec);
//  ��⠭����� � ��⥬� �६� �� ��।������� ��६�����
//---------------------------------------------------------------------------
ex  vd  far SetDate(int year, int mon, int day);
//  ��⠭����� � ��⥬� ���� �� ��।������� ��६�����
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  NBFN.H:
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  NBFN.C:
//---------------------------------------------------------------------------
ex  vd  far PrintNCB(ui ncb);
//  �뢮� �� ��࠭ �������� NCB
//---------------------------------------------------------------------------
ex  ui  far WS_NB__Init(vd);
//  �஢�ઠ ��⠭���� NETBIOS
//  Retun value:
//           0 - NetBIOS ��⠭�����
//           1 - NetBIOS �� ��⠭�����
//---------------------------------------------------------------------------
ex  vd  far WS_NB__ZeroNCB(ui WS_CurNCB);
//  ���������� ���祭�� ⥪�饣� NCB ��ﬨ
//  WS_CurNCB- ⥪�騩  NCB (NetBIOS Control Block)
//---------------------------------------------------------------------------
ex  vd  far WS_NB__NetBios(ui WS_CurNCB);
//  �맮� �믮������ �㭪権 NETBIOS
//  WS_CurNCB- ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  ui  far WS_NB__AddName(_c far *WS_name,ui WS_CurNCB);
//  ���������� ����� �⠭樨 � ᯨ᮪ �� NetBIOS
//  WS_name  - ��� �⠭樨 (�� 15 ᨬ�����)
//  WS_CurNCB- ⥪�騩 NCB
//  Retun value:
//               0 - �ᯥ譮� �����襭�� �㭪樨
//             100 - �訡�� ⥪�饣� NCB
//          ��㣮� - ��� �訡�� NetBIOS
//---------------------------------------------------------------------------
ex  ui  far WS_NB__DeleteName( _c far *WS_name,ui WS_CurNCB );
//  �������� ����� �⠭樨 �� ᯨ᪠ �� NetBIOS
//  WS_name  - ��� �⠭樨 (�� 15 ᨬ�����)
//  WS_CurNCB- ⥪�騩 NCB
//  Retun value:
//               0 - �ᯥ譮� �����襭�� �㭪樨
//             100 - �訡�� ⥪�饣� NCB
//          ��㣮� - ��� �訡�� NetBIOS
//---------------------------------------------------------------------------
ex  ui  far WS_NB__GetError(vd);
//  ������ ���� �訡��
//---------------------------------------------------------------------------
ex  ui  far WS_NB__GetFinalCCode(ui WS_CurNCB);
//  ������ �������饣� ���� �믮������ �㭪樨 NetBIOS �� ⥪�饣� NCB
//  WS_CurNCB- ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  ui  far WS_NB__GetRetCCode(ui WS_CurNCB);
ex  ui  far WS_NB__GetNCBSize(ui WS_CurNCB);
//  ������ ࠧ��� ���� ������ �� ⥪�饣� NCB
//  WS_CurNCB- ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  ui  far WS_NB__GetNetworkN(ui WS_CurNCB);
//  ������ ����� ����� �⠭樨 � �� �� ⥪�饣� NCB
//  WS_CurNCB- ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  _c  far *WS_NB__GetCallName(ui WS_CurNCB);
//  ������ ����� ��뢠����� ���⭥� �� ⥪�饣� NCB
//  WS_CurNCB- ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  _c  far *WS_NB__GetOurName(ui WS_CurNCB);
ex  vd  far WS_NB__SetBuffer(_c far *WS_Buf, ui WS_BufSize, ui WS_CurNCB);
//  ��⠭���� ���� � ࠧ��� ���� �ਥ��|��।�� � ⥪�饬 NCB
//  WS_Buf    - 㪠��⥫� �� ���� ������
//  WS_BufSize- ࠧ��� ����
//  WS_CurNCB - ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__SetCallName(_c far *WS_name, ui WS_CurNCB);
//  ��⠭���� ����� ��뢠���� �⠭樨 � ⥪�饬 NCB
//  WS_name   - ��� ��뢠���� �⠭樨
//  WS_CurNCB - ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__ReceiveDatagram(ui far WS_NetwrkNameNumber, ui WS_CurNCB);
//  �ਥ� ��⠣ࠬ��
//  WS_NetwrkNameNumber - ����� ����� � ��
//  WS_CurNCB - ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__SendDatagram(ui far WS_NetwrkNameNumber, ui WS_CurNCB);
//  ���뫪� ��⠣ࠬ��
//  WS_NetwrkNameNumber - ����� ����� � ��
//  WS_CurNCB - ⥪�騩 NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__Receive(_c far *WS_Buffer_Name, ui WS_Buffer_Size,ui WS_NetworkNameNumber, ui WS_CurNCB);
//  �ਥ� ������ �� �� NetBIOS
//  WS_Buffer_Name - ���� ������ ��� ⥪�饣� NCB
//  WS_Buffer_Size - ࠧ��� ���� ������
//  WS_NetworkNameNumber -  ����� ����� �⠭樨 � ��
//  WS_CurNCB      - ����� ⥪�饣� NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__Send(_c far *WS_Buffer_Name, ui WS_Buffer_Size,_c far *WS_Station, ui WS_NetworkNameNumber, ui WS_CurNCB);
//  ���뫪� ������ � �� NetBIOS
//  WS_Buffer_Name - ���� ������ ��� ⥪�饣� NCB
//  WS_Buffer_Size - ࠧ��� ���� ������
//  WS_Station     - ��� ��뢠���� �⠭樨
//  WS_NetworkNameNumber -  ����� ����� �⠭樨 � ��
//  WS_CurNCB      - ����� ⥪�饣� NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__Reset(ui WS_Adapter, ui WS_CurNCB);
//  ���� ��⠭���� NetBIOS
//  WS_Adapter - ����� �⥢��� ������ ��� ���ண� ���뢠���� ��⠭����
//  WS_CurNCB  - ����� ⥪�饣� NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__Cancel(ui WS_CurNCB);
//  �⬥�� ��᫥���� ������� Send__ NetBIOS
//  WS_CurNCB  - ����� ⥪�饣� NCB
//---------------------------------------------------------------------------
ex  _i  far WS_NB__AvNCB(vd);
//  �����頥� ����� ᢮������� NCB ��� -1, �᫨ ᢮������� NCB ���
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  NBWS.H:
//---------------------------------------------------------------------------
ex  ui  far NBStat;
//---------------------------------------------------------------------------
ex  _c  far WS_LocalS[LNAM];
ex  _c  far WS_NBName[LNAM];
//---------------------------------------------------------------------------
ex  _l far CNTANS;


//---------------------------------------------------------------------------
//  NBWS.C:
//---------------------------------------------------------------------------
ex  vd  far WS_NB_SetNumber(_c far * WSNBNS);
ex  vd  far WS_NB__NetChange(vd);
//  ����� ����묨 � �� NetBIOS
//--------------------------------------------------------------------------
ex  vd  far WS_NB__Answer(ui inncb, ui ouncb);
//  ��ନ஢���� �⢥⭮�� ����� ��� �⥢��� �⢥�
//  n - ����� ⥪�饣� NCB
//---------------------------------------------------------------------------
ex  vd  far WS_NB__GetFromNet(ui n);
//  ��।�� �ਭ���� �� �� ������ � ���ᨢ ������ DBB[]
//  n - ����� ⥪�饣� NCB
//--------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  REGUL.H:
//---------------------------------------------------------------------------
ex  _f  far WO_Skip[NREGUL];
// �����頥��� ॣ���஬ ���祭�� ��� ��।�� � �ணࠬ�� ���짮��⥫�
// (��� '���㤠୮��' ���室� ॣ���� � ��筮� � ��⮬���᪨�  ०���)
//---------------------------------------------------------------------------
ex  _f  far OutX[NREGUL];
ex  _f  far OutO[NREGUL];
// ��室 ॣ���� �� ���������� ���
//---------------------------------------------------------------------------
ex  _f  far OutR[NREGUL];
// ࠧ��� ����� �।��騬 � ⥪�騬 ��室�� ॣ����
//---------------------------------------------------------------------------
ex  _f  far ImpPC[NREGUL];
// ���稪 ������ ������
//---------------------------------------------------------------------------
ex  _f  far ImpWC[NREGUL];
// ���稪 ������ ���� ����� �����ᠬ�
//---------------------------------------------------------------------------
ex  _i  far RetO[NREGUL];
// ������ ��室 ॣ���� � ��諮�� 蠣�
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  REGUL.C:
//---------------------------------------------------------------------------
ex  vd  far RegulatorInit(vd);
//  ���㫥��� 䫠��� ॣ���஢
//---------------------------------------------------------------------------
ex  _f  far Regulator(ui n,_f Inp,_f KP,_f KI,_f KD,_f TI,_f KO,ui KA,_f ZL,_f ZH,_f IL,_f IH,_f OL,_f OH,_f DM,_f ZN,_f PR,ui CC,ui FL);
//  n       ����� ॣ����
//  Inp     ⥪�饥 ���祭�� ॣ㫨�㥬��� ��ࠬ���
//  KP,KI,KD,TI   ����.ॣ� KP-�ய���,KI-��⥣�,KD-����७�,TI-�६� ����஬�
//  KO      ��筮� �ࠢ�����
//  KA      ��४��祭�� ��筮�-��⮬�� (1-��⮬��,0-��筮�)
//  ZL,ZH   ������� ॣ����
//  IL,IH   �室��� 誠�� ॣ����  (誠�� ॣ㫨�㥬��� ��ࠬ���)
//  OL,OH   ��室��� 誠�� ॣ����
//  DM      MAX ���饭�� ॣ����
//  ZN      ���� �����⢨⥫쭮��
//  PR      ��業� ��ᮣ��ᮢ���� ��� ����祭�� ����஫쭮�� 横��
//  CC      ����஫�� 横� (�/� ᪮�쪮 横��� �㤥� ��������� �����.横�)
//  FL      ⨯ ॣ����
//          5 - ⮫쪮 ⥪�騩 蠣 ॣ���� (��ᮣ��ᮢ���� ��� ���饭��)
//  Retun value:
//          ��室 ॣ����
//---------------------------------------------------------------------------
ex  _i  far RegulDigit(ui n, _f KDP, _f KDW, _f KMas, _i ModRA, _i OutM);
//  �८�ࠧ������ ����������� ��室� � ������
//  n    - ����� ॣ����
//  KDP  - �����樥�� ������ ������
//  KDW  - �����樥�� ������ ����
//  KMas - �����樥�� ����⠡�
//  ModRA- ०�� ࠡ��� ॣ���� (��筮�-��⮬��)
//  OutM - ��室 ��筮�� �ࠢ����� ॣ����
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  IMOD.H:
//---------------------------------------------------------------------------
ex  ui  far HMCF[MCOM];
//  ������⢮ ����ᥩ ���ᠭ�� ���㫥�
//---------------------------------------------------------------------------
ex  uc  far PCCA[4];
//  ���� ����஫��� � ��
//---------------------------------------------------------------------------
ex  ui  far RecvTO [MCOM];
ex  ui  far RecvCmd[MCOM];
//  䫠� �ਥ�� ������ �� ���� (����� ���� �ਥ� ������ �� ���⮢
//  COM1|COM2|COM3|COM4 ���浪��� ����� 䫠�� ��⠭���������� � 1 � �����)
//---------------------------------------------------------------------------
ex  ui  far SendTO [MCOM];
ex  ui  far COMWT  [MCOM];
//  ����饥 ���祭�� ���� (横���) ����� ���뫪��� � ����
//---------------------------------------------------------------------------
ex  ui  far COMTO  [MCOM];
//  ������⢮ 横��� ⠩���� ���� ���㫥�
//---------------------------------------------------------------------------
ex  ui  far COMCH  [MCOM];
//  䫠�� �ᯮ�짮����� ���⮢
//  0-���� �� �ᯮ������ (NOU)
//  1-���� �ᯮ������ ��� ������ � ����ﬨ ��� (USO)
//  2-���� �ᯮ������ ��� ������ � ࠡ�稬� �⠭�ﬨ � ०��� SLAVE (WST)
//---------------------------------------------------------------------------
ex  ui  far HEXF[MCOM];
//  䫠� �ਥ�� �� AI ���㫥� �⢥⮢ HEX ��� % �ଠ� (1=HEX)
//---------------------------------------------------------------------------
ex  uc  far ReadBF [MCOM][RBFSZ];
ex  uc  far SendBT [MCOM][RBFSZ];
ex  uc  far TempBF [MCOM][14];
//  ���� ��� �ਥ�� ������ (����ᮢ)
//---------------------------------------------------------------------------
ex  ui  far ReadCB [MCOM];
ex  ui  far SendCB [MCOM];
//  ����� ⥪�饣� ���� � ���� �⥭��
//---------------------------------------------------------------------------
ex  ui  far ReadED [MCOM];
//  䫠� ����砭�� �⥭�� ������ �� ����
//---------------------------------------------------------------------------
ex  ui  far VAGIFLG[MCOM];
//  䫠� ࠡ��� � �ਡ�஬ ����
//---------------------------------------------------------------------------
ex  ui  far VAGICNT[MCOM];
//  ���稪 ⥪�饣� ᨬ���� �⢥� �� �ਡ�� ����
//---------------------------------------------------------------------------
ex  uc  far VAGISTR[MCOM][VAGSLEN];
//  ��ப� �⢥⮢ �� �ਡ�஢
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  IMOD.C:
//---------------------------------------------------------------------------
ex  vd  far WS_SP_SetNumber(_c * WSSPNS);
//  ��⠭���� ����� ࠡ�祩 �⠭樨 ��� �� RS485
//--------------------------------------------------------------------------
ex  vd  far CheckTimeOut(ui p);
//  �஢�ઠ ⠩���� �⢥� �� COM ����
//---------------------------------------------------------------------------
ex  ui  far CheckCRC(ui p);
//  �஢�ઠ CRC (1-ᮢ������, 0-���)
//---------------------------------------------------------------------------
ex  vd  far ConvertRead(ui p);
//  �८�ࠧ������ �⢥⮢ �� ���㫥� ���
//---------------------------------------------------------------------------
ex  vd  far SendCMD(ui p);
//  ���뫪� ������� �� ���㫨 ���
//---------------------------------------------------------------------------
ex  vd  far ClearR(_i p);
ex  vd  far ClearS(_i p);
ex  vd  far ReadANS(ui p);
//  �ਥ� �⢥⮢ �� ���㫥� ��� � ����ᮢ �� ࠡ��� �⠭権
//---------------------------------------------------------------------------
ex  ui  far TestREQ(ui p);
//  �ਥ� ������ �� ࠡ�祩 �⠭樨 � �⢥� �� ����� (�᫨ �� �����)
//---------------------------------------------------------------------------
ex  _i  far SetMODV(uc p, uc r, uc c,  _f v,  _f ld, _f hd);
//  ��⠭����� ���祭�� �� 㪠������ ������:
//  p     - ����� COM-����
//  r     - ����� ����� � ���ᨢ� ��।������ ���㫥�
//  c     - ����� �祩�� � �����
//  v     - ��⠭���������� ���祭�� (0-100%)
//  ld,hd - ������ � ������ �࠭��� ��������� ��室� � %
//          (0..25% - 0..5mA, 20..100% - 4..20mA, 0..100% - 0..20mA)
//---------------------------------------------------------------------------
ex  _i  far SetMODC(ui p, ui r, ui t, uc *c, ui l, ui a);
//  p  - ����� COM ����
//  r  - ����� ����� ��� ���ᨢ� ��।������ ���㫥�
//  t  - ⨯ �����
//  c  - �������� ��� �����
//  l  - ������ ��������
//  a  - ������⢮ ��६����� �⢥⮢
//  ������: 0-��� �訡�� � ��⠭����, ����� 0- ���� �訡��...
//---------------------------------------------------------------------------
ex  _i  far SetMODF(ui p, ui r, uc f, _i v);
//  p  - COM ����
//  r  - ����� ����� � ���ᨢ� ��।������ ���㫥�
//  f  - ��⠭���������� ���� 'e'-�訡��, 'o'-�ࠢ����� �⢥⮢
//  v  - ���祭�� ��� ��⠭����������� ����
//  �����頥� 0, �᫨ ���祭�� ��⠭������� ��� -1, �᫨
//  ��⠭���� ��।����� ����୮
//---------------------------------------------------------------------------
ex  _i  far GetMODF(ui p, ui r, uc f);
//  p  - COM ����
//  r  - ����� ����� � ���ᨢ� ��।������ ���㫥�
//  f  - ����訢����� ���� 'e'-�訡��, 'o'-�ࠢ���� �⢥��
//  �����頥� ���祭�� ����訢������ ���� 㪠������  ����� ��� -1,
//  �᫨ ��⠭���� ��।����� ����୮
//---------------------------------------------------------------------------
ex  _f  far GetMODV(ui p, ui r, uc n);
//  p  - COM ����
//  r  - ����� ����� � ���ᨢ� ��।������ ���㫥�
//  n  - ����� ��६����� �� ���ᨢ� ��।������ ���㫥� (����� ������ �����)
//  �����頥� ���祭�� ����訢������ ������ �����
//---------------------------------------------------------------------------
ex  _i  far PrnMODC(ui p, ui r, ui m);
//  p  - COM ����
//  r  - ����� ����� � ���ᨢ� ��।������ ���㫥�
//  m  - ०�� �뢮�� ���ଠ樨
//  �뢮��� ���ଠ�� � ���䨣��樨 ����� 㪠������ �����
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  MONITOR.H:
//---------------------------------------------------------------------------
ex  _i  far MonCHN[20];
//  ����� ������� ��� �⮡ࠦ����
//---------------------------------------------------------------------------
ex  _i  far MonFirst;
//  ���� ��ࢮ�� �맮�� ������
//---------------------------------------------------------------------------
ex  _i  far MonCPos;
//  ������ ������ � ���� ����� ��������
//---------------------------------------------------------------------------
ex  uc  far SCMD[MAXSTRE];
ex  _c  far pVERSION[MAXSTRE];
ex  _c  far nVERSION[MAXSTRE];
//---------------------------------------------------------------------------
ex  ui  far BusyTer;
//  䫠� ������� ����
//---------------------------------------------------------------------------
ex  ui  far AddrrBeg;
ex  ui  far AddrrEnd;
//  ���� ���㫥� ��� ���᪠
//---------------------------------------------------------------------------
ex  ui  far CRCF[5];
//  䫠�� ࠧ�襭�� ��� ����஫��� �㬬 � �ନ������ �������
//---------------------------------------------------------------------------
ex  uc  far CRCS[5];
//  ��ப� ����祭���� CRC
//---------------------------------------------------------------------------
ex  ui  far tport;
ex  ul  far tbaud;
ex  ui  far tdata;
ex  ui  far tpart;
ex  ui  far tstop;
//  ��⠭���� COM ����
//---------------------------------------------------------------------------
ex  uc  far StatCP[5][MAXSTRE];
//  ��ப� ���ᠭ�� ���⮢
//---------------------------------------------------------------------------
ex  ui  far uCMD[10];
//---------------------------------------------------------------------------
ex  _i  far xDefault;
//  䫠� ��⠭���� ������ �� 㬮�砭��
//---------------------------------------------------------------------------
ex  _i  far xRead;
//  䫠� �⥭�� ������ � ���� �����
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  MONITOR.C:
//---------------------------------------------------------------------------
ex  _i  far Monitor(vd);
//  �뢮� ���ଠ樨 � �ணࠬ�� � ���᪠��� �ணࠬ�� �� ��࠭
//  Retun value:
//               1 - �뫮 �������� ���祭�� � ���ᨢ� DBB[]
//               0 - ��㣮� �����襭��
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  UTIL.H:
//---------------------------------------------------------------------------
ex  ui  far FBell;
//  ���� ������
//---------------------------------------------------------------------------
ex  ui  far HM;
//  �����⥫� ���� ᮮ�饭�� MBuf[] �㭪樨 Message()
//---------------------------------------------------------------------------
ex  ui  far TM;
//  �����⥫� ���� ᮮ�饭�� MBuf[] �㭪樨 MessageOut()
//---------------------------------------------------------------------------
ex  ui  far MBuf[MBS];
//  ���� ᮮ�饭��
//---------------------------------------------------------------------------
ex  ui  far nMESSAGE;
//  ��।������ �� �㭪樨 MessageOut() ����� ᮮ�饭��
//---------------------------------------------------------------------------
ex  uc  far FDI [HFI][MDI];
//  ���ᨢ 䨫���樨 DI ᨣ�����
//---------------------------------------------------------------------------
ex  uc  far FDC [HFI];
//  �����⥫� ⥪�饩 �祩�� 䨫���
//---------------------------------------------------------------------------
ex  uc  far FDIO[HFI];
//  ���ᨢ �।���� ���祭�� 䨫���樨
//---------------------------------------------------------------------------
ex  uc  far FNDat[40];
//  ��� 䠩�� ������
//---------------------------------------------------------------------------
ex  uc  far FLBuf[SIZDBB+8];
//  ���� �⥭��-����� ������ ���ᨢ� DBB[]
//---------------------------------------------------------------------------
ex  _i  far ReadDataER;
//  ���� �訡�� �⥭�� ������ �  ���
//---------------------------------------------------------------------------
ex  _i  far WritDataER;
//  ���� �訡�� ����� ������ �� ���
//---------------------------------------------------------------------------
ex  _i  far CheckValER;
//  ���� ��⠭���������� �� ���室� �࠭��� �� �஢�થ ���祭��
//  �㭪樥� CheckVal();
//---------------------------------------------------------------------------
ex  _i  far NoCheck[MNOCHECK];
//  ���ᨢ ����஢ ��६����� DBB[], ����� �� �������� �஢�થ xCheck()
//---------------------------------------------------------------------------
ex  ui  far FDAddr[3];
//  ���� flash ��� ����� ������
//---------------------------------------------------------------------------
ex  _f  far AAVL[NVMAX+1][CVMAX+1];
//  ���ᨢ ��।����� ���祭��
//---------------------------------------------------------------------------
ex  ui  far AAMC[NVMAX+1];
//  ����� ⥪�饣� ������� ���ᨢ�
//---------------------------------------------------------------------------
ex  ui  far nSOUND;
ex  ui  far pSOUND;
//  ����� �ந��뢠��� ��㪮�
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  UTIL.C:
//---------------------------------------------------------------------------
ex  ui  far Bell(ui VB);
//  ��⠭���� 䫠�� ������
//  VB - ���祭�� 䫠�� ������
//       0- ��� 䫠�� ������
//       1- ��⠭���� 䫠�� ������
//       2- ����� ���祭�� 䫠�� ������
//  Retun value:
//       0|1- ⥪�饥 ���祭�� 䫠�� ������
//---------------------------------------------------------------------------
ex  vd  far Message(ui n);
//  ������� ����� ᮮ�饭�� ��� ��।�� � �ணࠬ�� ������.
//  ����� ������㥬�� ᮮ�饭�� ��������� � ���� MBuf[], ��㤠 �㭪樥�
//  MessageOut() �१ ��६����� nMESSAGE ��।����� � �ணࠬ�� ���짮���.
//  n - ����� ᮮ�饭��
//---------------------------------------------------------------------------
ex  vd  far MessageOut(vd);
//  ��।�� ����� ᮮ�饭�� �� ���� ����஢ ᮮ�饭�� MBuf[]
//  � ��६����� ������ � �ணࠬ��� ���짮��⥫� nMESSAGE.
//  ������ �㭪�� ��뢠���� �� �㭪樨 main() ࠧ � ��� ᥪ㭤�
//--------------------------------------------------------------------------
ex  vd  far MessageCLS(vd);
//  ���⪠ ���� ᮮ�饭�� MBuf[]
//--------------------------------------------------------------------------
ex  ui  far Control_AI(_f Val,_f VMin,_f VMax,ui VF,ui VMinMes,ui VNorMes,ui VMaxMes,ui BN);
//  ����஫� AI ��ࠬ���஢ �� ��⠭������� MIN-MAX �।����
//  Val    - ⥪�饥 ���祭��
//  VMin   - �������쭠� �࠭��
//  VMax   - ���ᨬ��쭠� �࠭��
//  VF     - 䫠� ���ﭨ� (0-Min,1-Nor,2-Max)
//  VMinMes, VNorMes, VMaxMes - ����� ᮮ�饭�� ��� ᮮ⢥������� ���ﭨ�
//  BN     - ���祭�� 䫠�� ������
//  Retun value: 䫠� ���ﭨ�:
//      0  - ��室 �� ����������  �࠭���
//      1  - ���祭�� � ���������  ����
//      2  - ��室 �� ���ᨬ����� �࠭���
//---------------------------------------------------------------------------
ex  ui  far Control_DI(ui CurDI, ui LstDI, ui Mess_ON, ui Mess_OFF);
//  ����஫� DI ��ࠬ���஢
//  CurDI    -  ⥪�騩 ᨣ���
//  LstDI    -  ᨣ���  � �।��饣� 横��
//  Mess_ON  -  ����� ᮮ�饭�� �᫨ 1 (����祭�)
//  Mess_OFF -  ����� ᮮ�饭�� �᫨ 0 (�몫�祭�)
//  MesLev   -  �஢��� �뢮�� ᮮ�饭��
//  Retun value: ⥪�饥 ���ﭨ� ��।�������� DI ��ࠬ���
//---------------------------------------------------------------------------
ex  ui  far BFiltr(ui NF, ui CVal, ui HCell);
//  �������� ������� �室��� ᨣ����� (DI)
//  NF    - ����� 䨫���
//  CVal  - ⥪�饥 ���祭�� ᨣ����
//  HCell - ������⢮ �祥� �ᯮ��㥬�� ��� 䨫���樨 (max=MDI (70))
//  Retun value:
//---------------------------------------------------------------------------
ex  _f  far AISet(ui NV,_f CV,_f LW,_f HW,_f LD,_f HD,_f TF,_f SF);
//  �८�ࠧ������ ��室��� 誠�� � �㦭��� ���������
//  NV  - ����� ��६����� �८�ࠧ������
//  CV  - ⥪�饥 ��������� � �८�ࠧ���⥫�
//  LW  - ������  �࠭�� �室���� ���������
//  HW  - ������ �࠭�� �室���� ���������
//  LD  - ������  �࠭�� �����頥���� ���������
//  HD  - ������ �࠭�� �����頥���� ���������
//  TF  - �६� 䨫���樨 (ᥪ)
//  SF  - �������쭮� ���祭�� 䨫��� �� १��� ���������� ⥪�饣� ���祭
//  Retun value:
//        ���祭�� �ਢ������� � 㪠������� ���������
//---------------------------------------------------------------------------
ex  _f  far MDivF(_f MDF1,_f MDF2);
//  ������� ��६����� ⨯� float
//---------------------------------------------------------------------------
ex  _i  far MDivI(_i MDI1,_i MDI2);
//  ������� ��६����� ⨯� int
//---------------------------------------------------------------------------
ex  _c  far *ftostrx(_f Value);
//  �८�ࠧ������ ��६����� ⨯� float � 16-����� ��ப� ᨬ�����
//  Retun value: ��ப� ᨬ�����
//---------------------------------------------------------------------------
ex  _f  far CheckVal(_f Value, _f LVal, _f HVal);
//  �஢�ઠ ⥪�饣� ���祭�� �� ��室 �� ������ � ������ �࠭���
//  �����頥� ⥪�饥 ���祭��
//---------------------------------------------------------------------------
ex  _i  far EraseData(ui addr);
//  ��࠭�� � flash ������ �ணࠬ��
//  �����頥�� ����:
//     =0: �訡� ���
//     >0: �訡�� ��࠭�� flash
//---------------------------------------------------------------------------
ex  _i  far WriteData(ui addr);
//  ������ ������ �� ���ᨢ� ������ DBB[] �� 䫥� 7188 ��� � 䠩� �� ���
//  �����頥�� ����:
//     = 0: ����� ����ᠭ�, �訡�� ���
//     = 1: �訡�� �� ����� 1�� ����� ������ �� flash
//     = 2: �訡�� �� ����� 2�� ����� ������ �� flash
//     = 3: �訡�� �� ����� 䠩��
//---------------------------------------------------------------------------
ex  _i  far ReadData(ui addr);
//  �⥭�� ������ � ���ᨢ ������ DBB[]
//---------------------------------------------------------------------------
ex  vd  far xCheckData(vd);
//  �஢�ઠ ������ � ���ᨢ� DBB[]
//---------------------------------------------------------------------------
ex  vd  far xReadData(_i md);
//---------------------------------------------------------------------------
ex  _i  far  RADATA(uc dsk_num, uc hed_num, uc cyl_num, uc beg_sec);
//---------------------------------------------------------------------------
ex  _i  far  WADATA(uc dsk_num, uc hed_num, uc cyl_num, uc beg_sec);
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  MAIN.H:
//---------------------------------------------------------------------------
ex  _f  far DBB[MAXDBB+2];
//  �᭮���� ���ᨢ ��६����� ������
//---------------------------------------------------------------------------
ex  _f  far TLoop;
//  ������⢮ '������' 横��� �ணࠬ�� �� ���� ⨪
//---------------------------------------------------------------------------
ex  _f  far TickLoops;
//  ����騩 ���稪 '������' 横��� �� ���� ⨪
//---------------------------------------------------------------------------
ex  _f  far SLoop;
//  ������⢮ '������' 横��� �ணࠬ�� �� ����� ᥪ㭤�
//---------------------------------------------------------------------------
ex  _f  far SecnLoops;
//  ����騩 ���稪 '������' 横��� �� ����� ᥪ㭤�
//---------------------------------------------------------------------------
ex  ul  far CS_in_Tic;
//  ������⢮ '������' 横��� (��� �믮������ �ணࠬ��) �� ⨪
//---------------------------------------------------------------------------
ex  ul  far CS_in_mS;
//  ������⢮ '������' 横��� (��� �믮������ �ணࠬ��) �� ���� �����ᥪ.
//---------------------------------------------------------------------------
ex  _i  far LKey_;
ex  _i  far LastKey;
//  ��� ��᫥���� ����⮩ ������
//---------------------------------------------------------------------------
ex  _i  far ExitCode;
ex  ui  far ExitForLoad;
//  ��� ��室� �� �ணࠬ��
//---------------------------------------------------------------------------
ex  _c  far Param[10];
//  ��ࠬ��� ����᪠ �ணࠬ��
//---------------------------------------------------------------------------
ex  _i  far FirstCall;
//  ���稪 横��� ��뢮� ॣ���஢
//---------------------------------------------------------------------------
ex  _i  far PrintDBG;
//---------------------------------------------------------------------------
ex  _f  far DateCmpLIB;
ex  _f  far TimeCmpLIB;
//  ��� � �६� �������樨
//---------------------------------------------------------------------------
ex  ui  far COM_Addr[MCOM];
//  ���� COM ���⮢
//---------------------------------------------------------------------------
ex  ul  far COM_Baud[MCOM];
//  ������� ��� ࠡ��� COM ���⮢
//---------------------------------------------------------------------------
ex  int      far jmpret;
//  ���室 �� �㭪樨 ��ࠡ�⪨ ᨣ����� �᪫��⥫��� ���権
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  MAIN.C:
//---------------------------------------------------------------------------
ex  vd  far main(vd);
//  � �ணࠬ�� ���짮��⥫� ������ ���� ���ᠭ� ᫥���騥 �㭪樨:
//  vd far Start(vd)           - ��뢠���� � ��砫� �ணࠬ��
//  vd far First_in_Cycle(vd)  - ��뢠���� � ��砫� ������� 横�� �ணࠬ��
//  vd far EveryCyc(vd)        - ��뢠���� ����� 横� �ணࠬ��
//  vd far EveryTic(vd)        - ��뢠���� ����� ⨪
//  vd far EverySec(vd)        - ��뢠���� ������ ᥪ㭤�
//  vd far Last__in_Cycle(vd)  - ��뢠���� � ���� ������� 横�� �ணࠬ��
//  vd far End(vd)             - ��뢠���� � ���� �ணࠬ��
//---------------------------------------------------------------------------
ex  _i  far LKey(ui Mode);
//  ��।������ ���� ��᫥���� ����⮩ ������
//  Mode=  0-���㫥��� ��६����� �����
//         1-�������  ���祭�� ���� ��᫥���� ����⮩ ������
//  Retun value: ASCII ��� ��᫥���� ����⮩ ������
//---------------------------------------------------------------------------
ex  _i  cdecl matherr(struct exception *a);
ex  vd  far i_SIGNAL(_i sig, _i type);
ex  vd  far SetSIGF(vd);
ex  vd  far MainExt(vd);


//---------------------------------------------------------------------------
//  TIMER.H:
//---------------------------------------------------------------------------
ex  ul  far PubTimer;
//  ��騩 ���稪 ⨪��
//---------------------------------------------------------------------------
ex  ul  far PubTimerS;
//  ���ᨬ��쭮� ���祭�� ���稪�
//---------------------------------------------------------------------------
ex  ul  far TA[MaxTT+10];
//  ���ᨢ ⠩��஢
//---------------------------------------------------------------------------
ex  ul  far TimeDs;
ex  ul  far TimerTemp;
//  ��६���� �८�ࠧ������
//---------------------------------------------------------------------------
ex  ui  far YEAR[12];
ex  ui  far DAYR[12];
ex  ui  far MONR[12];
//  ������� ��� ���᫥��� ��� ������
//---------------------------------------------------------------------------
ex  _l  far CNTTO[MAXCNTTO+1];
//  ���稪 ��ࠡ�⪨ ⠩���⮢
//---------------------------------------------------------------------------
ex  _i  far CNTCU[MAXCNTTO+1];
//  ���稪 ����室���� ��᫥����⥫��� �ࠡ��뢠��� ⠩��� ���
//  ��⠭���� ᨣ���� "⠩��� �ࠡ�⠫"
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  TIMER.C:
//---------------------------------------------------------------------------
ex  ui  far Timer(ui TN, ul TT, ui TE);
//  �㭪�� ⠩��� ⨪�� ��� �ணࠬ�� ���짮��⥫�
//  �㭪�� ������ ��������� � ����� 横� �ணࠬ��
//  TN  - ����� ⠩���
//  TT  - �६� ��ࠡ�⪨ ⠩��� (���-�� ���)
//  TE  - ������ ��� ⠩��� 1=tick, 2=sec, 3=min, 4=hour, 0=clear(set)
//  Retun value:
//        0 - ��砫쭠� ��⠭���� ���稪�
//        2 - ���稪 ��ࠡ�⠫
//        9 - ����।������� ������ ��� ⠩���
//---------------------------------------------------------------------------
ex  _i  far WeekDay(_i y, _i m, _i d);
//  ��।������ ⥪�饣� ��� ������ ��� 㪠������ ����: Y-���,m-�����,d-����
//  �����頥� ���� ������: 0-�������쭨�,...
//---------------------------------------------------------------------------
ex  _i  far Plus__TO(_i n);
//  �������� ���祭�� 㪠������� ���稪� �� �������
//---------------------------------------------------------------------------
ex  _i  far Minus_TO(_i n);
//  �������� ���祭�� 㪠������� ���稪� �� �������
//---------------------------------------------------------------------------
ex  vd  far Clear_TO(_i n);
//  ������ 㪠����� ���稪
//---------------------------------------------------------------------------
ex  _i  far Check_TO(_i n, _l t, _f p, uc z, _f v, _i c);
//  �㭪�� �஢�ન ��⠭���� ���������� ���祭�� � 㪠������ ��६�����
//  n  - ����� ���稪�
//  t  - �������� �६� ��� ��⠭���� ���祭�� ��६�����
//  p  - �஢��塞�� ���祭��
//  z  - ���� �⠢�����: '<' '=' '>' '!' (�� ࠢ��) 'i' (integer=)
//  v  - ��������� ���祭��
//  c  - ���稪 㤥ঠ��� ���祭�� (᪮�쪮 ࠧ �.�. �믮����� ��������
//       �᫮��� �ࠡ�⪨ ��稪� ��� ��⠭���� 䫠�� "���������")
//  Retun value:
//     0 - �� 㪠������ �६� ���祭�� �� ��⠭�������
//     1 - ���� �६� ��⠭���� ���祭�� ��६�����
//     2 - ���祭�� ��६����� ��⠭������� (���稪 �ࠡ�⠫)
//     3 - ���� 㤥ঠ��� ���祭��
//---------------------------------------------------------------------------


