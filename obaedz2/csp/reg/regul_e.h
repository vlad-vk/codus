//  coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
//  䫠�� � ���稪� ���㫥��� ��� �����஢
ex  _i  far DSWZero, DSCZero, DSCEnab;
ex  _i  far DMWZero, DMCZero, DMCEnab;
ex  _i  far DPWZero, DPCZero, DPCEnab;
//---------------------------------------------------------------------------
//  䫠�� ����᪠ ॣ���஢
ex  _i  far Reg11F, Reg12F;
ex  _i  far Reg13F, Reg14F;
//---------------------------------------------------------------------------
ex  _i  far STEP01, STEP01_BACK, STEP02, STEP02_BACK, STEP03, STEP03_BACK;
ex  _i  far STEP04, STEP04_BACK, STEP05, STEP05_BACK;
ex  _i  far STEP06v,STEP06v_BACK,STEP06v_PRBK,STEP06vP;
ex  _i  far STEP06c,STEP06c_BACK,STEP06c_PRBK,STEP06cP;
ex  _i  far STEP07, STEP07_BACK;
ex  _i  far STEP07v,STEP07v_BACK,STEP07vP,STEP07v_PRBK;
ex  _i  far STEP07, STEP07_BACK, STEP08, STEP08_BACK, STEP09, STEP09_BACK;
ex  _i  far STEP10, STEP10_BACK;
ex  _i  far STEP14, STEP14_BACK;
ex  _i  far STEP15, STEP15_BACK;
ex  _i  far STEP01_PRBK, STEP02_PRBK, STEP03_PRBK;
ex  _i  far STEP04_PRBK, STEP05_PRBK;
ex  _i  far STEP06c_PRBK;
ex  _i  far STEP07_PRBK, STEP08_PRBK, STEP09_PRBK;
ex  _i  far STEP10_PRBK;
ex  _i  far STEP14_PRBK;
ex  _i  far STEP15_PRBK;
ex  _i  far STEP01P,STEP02P,STEP03P;
ex  _i  far STEP04P,STEP05P;
ex  _i  far STEP07P,STEP08P,STEP09P, STEP10P, STEP09D;
ex  _i  far STEP14P,STEP15P;
//  蠣� ॣ���஢
//---------------------------------------------------------------------------
ex  _f  far DIH110,DIL110,DIS111,DIS112,DON111,DON112;
//  ᨣ���� ��� �����������஢
//---------------------------------------------------------------------------
ex  _i  far TIME_GG_CONTROL;
//  ����஫� �६��� ࠡ��� �������� ������������
//---------------------------------------------------------------------------
ex  _i  far GKV_POL;
//  ����祭��-�몫�祭�� ������� ������
//---------------------------------------------------------------------------
ex  _i  far FLAG_0406A_v;
ex  _i  far FLAG_05WTA_v;
ex  _i  far FLAG_05BGA_v;
ex  _i  far FLAG_0605A_v;
ex  _i  far FLAG_0406A_c;
ex  _i  far FLAG_05WTA_c;
ex  _i  far FLAG_05BGA_c;
ex  _i  far FLAG_0605A_c;
//  䫠�� ��।������ ����� ॣ���ࠬ�
//---------------------------------------------------------------------------
ex  _f  far AIW218___O;
ex  _f  far AIW218___S;
ex  _f  far AIW219___O;
ex  _f  far AIW219___S;
//  ���������� ��� ������ ��宣�
ex  _f  far AIW218___C;
ex  _f  far AIW219___C;
//  ���稪 横��� ���� ���
//---------------------------------------------------------------------------
ex  _f  far AIW252___O;
ex  _f  far AIW252___S;
ex  _f  far AIW252___D;
//  ��� ������ ���ண� � �।��饣� ����訢����
//---------------------------------------------------------------------------
ex  _f  far AIW251___O;
ex  _f  far AIW251___S;
ex  _f  far AIW251___P;
//  ��� ������ ���� � �।��饣� ����訢����
//---------------------------------------------------------------------------
ex  _i  far LOAD_PUOSC;
//  ���稪 ��।�ࣨ����� ������� ���㧪� ���� �� ������ ����
//---------------------------------------------------------------------------
ex  _f  far AIW216___O;
ex  _f  far AIW216___S;
//  ��� ������ ����� � �।��饣� ����訢����
//---------------------------------------------------------------------------
ex  _i  far CCTM_VSDM;
//  ���稪 ⥪�饣� �६��� �⠡�����樨 ����஢�� ���ண�
//---------------------------------------------------------------------------
ex  _i  far MK_VG_KL_OPEN;
//  䫠� ������ ������� ���㧪� ���ண�
//---------------------------------------------------------------------------
ex  _f  far CNT_SHVBON;
//  ���稪 ����祭�� ������ ��宣�
//---------------------------------------------------------------------------
ex  _i  far LSA_VAJV;
ex  _i  far LSA_VAJS;
ex  _i  far LSA_CEMV;
ex  _i  far LSA_CEMS;
//  ��᫥���� ���ﭨ� �ᯨ�権
//---------------------------------------------------------------------------
//  ������ �室��-��室�� ॣ���� �����窨 諠��
ex  _f  far DIRR01___V;
ex  _f  far DISR01P1_V;
ex  _f  far DISR01PK_V;
ex  _f  far DISR01MS_V;
ex  _f  far DIHR01___V;
ex  _f  far DILR01___V;
ex  _f  far DIRR01PN_V;
ex  _f  far DISR01PKSV;
ex  _f  far DISR01PKVV;
ex  _f  far DIHR01PN_V;
ex  _f  far DONR01P1_V;
ex  _f  far DONR01PK_V;
ex  _f  far DONR01PKSV;
ex  _f  far DONR01PKVV;
//---------------------------------------------------------------------------
//  ���稪� ����� ��� ��������

ex  _f  far TIME_SLNZCMin;                 // �६� ����㧪� ��.���� 諠��
ex  _f  far TIME_SLNVCMin;                 // �६� ���㧪� ��.���� 諠��
ex  _f  far TIME_PRDSCMin;                 // �६� �த㢪� ��.���� 諠��
ex  _i  far DSB;                           // 䫠� ��८�।������ �.���ᥩ��
ex  _i  far FLAG_HLVSExit;                 // 䫠� ��室� �� �६ ���� �஢��
ex  _i  far FLAG_HLMOExit;                 // 䫠� ��室� �� �६ ���� �஢��
ex  _i  far FLAG_HLBVExit;                 // 䫠� ��室� �� �६ ���� �஢��
ex  _i  far FLAG_HLCMExit;                 // 䫠� ��室� �� �६ ���� �஢��

ex  _f  far TIME_VODMCMin;                 // ����
ex  _f  far TIME_VODHCMin;                 // ����
ex  _f  far TIME_CONDCMin;                 // ��������

ex  _f  far TIME_OTHVCMin;                 // ����� ���� � ��蠫�� ��室�� ��
ex  _f  far TIME_NS31CMin;                 // �६� ����㧪� ��.���� ��室��
ex  _f  far TIME_NS32CMin;                 // �६� ���㧪� ��.���� ��室��
ex  _f  far TIME_PRDOCMin;                 // �த㢪� ��.���� ��室��

ex  _f  far TIME_OSC5Min ;
ex  _f  far TIME_LEV5CMin;
ex  _f  far TIME_NAS5CMin;
ex  _f  far TIME_BVAJCMin;
ex  _f  far TIME_BCEMCMin;
ex  _f  far TIME_PRDCCMin;                 // �६� �த㢪� ��.���� 楬���
ex  _f  far TIME_PCASCMin;                 // �६� �몫 �ᯨ� 楬��� ��᫥ �த�
ex  _f  far TIME_SHDZCMin;                 // �६� ����஢�� ��宣�
ex  _f  far TIME_MKDZCMin;                 // �६� ����஢�� ���ண�
ex  _f  far TIME_PUDZCMin;                 // �६� ����஢�� ����
ex  _f  far TIME_PADZCMin;                 // �६� ����஢�� �����
//
ex  _f  far CNT_VIGRUZ_S ;                 // ���稪 ���㧪� �⠡�� ��� ��宣�
ex  _f  far TIME_PVASCMin;                 // �६� �몫 �ᯨ� ���饣� ��᫥ ������
ex  _f  far TIME_POASCMin;                 // �६� ���� ��᫥ ����� �ᯨ� ����
ex  uc  far FLAG_ONVBC   ;                 // 䫠� �몫�祭�� ������� ������
ex  _f  far DON101P;                       // �।��饥 ���ﭨ� ᨣ����� ��
ex  _f  far DON102P;                       // �������
ex  uc  far STEP05F;                       // 䫠� ��宦����� �몫�祭� ॣ����
//
ex  _f  far TIME_LLVCCMin;                 // �६ ������ ���� �஢�� �㭪 楬���
ex  _f  far TIME_LLVVCMin;                 // �६ ������ ���� �஢�� �㭪 ���饣�
ex  _f  far TIME_LLVSCMin;                 // �६ ������ ���� �஢�� ��蠫�� 諠��
ex  _f  far TIME_HLVSCMin;                 // �६ ������ ���� �஢�� ��蠫�� 諠��
ex  _f  far TIME_LLVOCMin;                 // �६ ������ ���� �஢�� ��蠫�� ��室
ex  _f  far TIME_HLVOCMin;                 // �६ ������ ���� �஢�� ��蠫�� ��室
//
ex  _f  far CNT_ZAGRUZ_M;                  // ���稪 ������ �⠡������ ��� �����
ex  _f  far CNT_VIGRUZ_M;                  // ���稪 ������ �⠡������ ��� ����
//
ex  _f  far TIME_PLLVCMin;                 // �६� �������� ���� �஢�� ����-���
ex  _f  far TIME_PHLVCMin;                 // �६� �������� ���� �஢�� ����-���
ex  uc  far PAV_OK;                        // 䫠� ���믪� ��� �ணࠬ��
//
ex  _f  far TIME_PULLCMin;                 // �६� ����� ��� �� ��� ��� ��.����
ex  _f  far TIME_PUHLCMin;                 // �६� ����� ��� �� ��� ��� ��.����
ex  _f  far TIME_PUVZCMin;                 // �६� ���㧪� ��蠫�� ��� ��.����
//
ex  _f  far TIME_PALNCMin;                 // �६� ����� ��� �� ��� ��� ��.�����
ex  _f  far TIME_PANNCMin;                 // �६� ����� ��� �� ��� ��� ��.�����
ex  _f  far TIME_PAMSCMin;                 // �६� ������ ᨣ���� �� ���� ��� ���
ex  _f  far TIME_PALVCMin;                 // �६� ����� ��� �� ��� ��� ��.�����
ex  _f  far TIME_PANVCMin;                 // �६� ����� ��� �� ��� ��� ��.�����
ex  _f  far TIME_PAVGCMin;                 // �६� ���㧪� ������ ��.�����
ex  _f  far TIME_PPM1CMin;                 // �६� ��६�� ��� � ��� ��� ��.�����
ex  _f  far TIME_PNOFCMin;                 // �६� ��⠭���� ���� ��� ��� ��.�����
ex  _f  far FLAG09_NS301;                  // 䫠� ����祭�� ����
//---------------------------------------------------------------------------
ex  _f  far SigPubZagS;                    // �ࠢ���騩 ᨣ��� ����� ��饣� ॣ
ex  _f  far SigPubVigS;                    // �ࠢ���騩 ᨣ��� ���� ��饣� ॣ
//
ex  _i  far PubCycStat;                    // ����� ��饣� 横��
ex  _i  far GetPubCycStat(int);            // ����祭�� ����� ��饣� 横�� 
ex  _i  far SetPubCycStat(int,int);        // ��⠭���� ����� ��饣� 横��
#define PSTAT 1
#define SUHOE 10
#define MOKRE 100
#define PASTA 1000
//---------------------------------------------------------------------------
ex  _i far NewSmena;                       // 䫠� �����  ᬥ��
ex  _i far NewMonth;                       // 䫠� ������ �����
ex  _i far FLSHPZ;                         // 䫠�� ��।�� ���祭��
ex  _i far FLMKPZ;
ex  _i far FLPAPZ;
ex  _i far FLPUPZ;
//---------------------------------------------------------------------------
ex  _i far DON803___F;            // 䫠� ���㧪� �����஢ ��宣� � ���ண�
//---------------------------------------------------------------------------
//  ����� ��६����� ��� �६����� 横���
ex  _f  far ZERO;
//---------------------------------------------------------------------------
//  ���� ��६����� �롮�
ex  _f  far CHANGE;
//---------------------------------------------------------------------------
//  䫠� ࠡ��� ॣ����
ex  _i  far RegRUN;
//---------------------------------------------------------------------------
//  ����� ��࠭���� �楯� ����㧮�
ex  _i  far RECEPT_VIB;
//---------------------------------------------------------------------------
ex  _i  far dayC;
ex  _i  far houC;
ex  _i  far minC;
ex  _i  far secC;
//---------------------------------------------------------------------------
