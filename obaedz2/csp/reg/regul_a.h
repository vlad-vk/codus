//  coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
//  䫠�� ����᪠ ॣ���஢
_i  far Reg11F=0, Reg12F=0;
_i  far Reg13F=0, Reg14F=0;
//---------------------------------------------------------------------------
_i  far STEP01=0, STEP01_BACK=0, STEP02=0, STEP02_BACK=0, STEP03=0, STEP03_BACK=0;
_i  far STEP04=0, STEP04_BACK=0, STEP05=0, STEP05_BACK=0;
_i  far STEP06v=0,STEP06v_BACK=0,STEP06v_PRBK=0,STEP06vP=0;
_i  far STEP06c=0,STEP06c_BACK=0,STEP06c_PRBK=0,STEP06cP=0;
_i  far STEP07=0, STEP07_BACK=0;
_i  far STEP07v=0, STEP07v_BACK=0, STEP07vP=0, STEP07v_PRBK=0;
_i  far STEP08=0, STEP08_BACK=0, STEP09=0, STEP09_BACK=0;
_i  far STEP10=0, STEP10_BACK=0;
_i  far STEP14=0, STEP14_BACK=0;
_i  far STEP15=0, STEP15_BACK=0;
_i  far STEP01_PRBK=0, STEP02_PRBK=0, STEP03_PRBK=0;
_i  far STEP04_PRBK=0, STEP05_PRBK=0; 
_i  far STEP07_PRBK=0, STEP08_PRBK=0, STEP09_PRBK=0;
_i  far STEP10_PRBK=0;
_i  far STEP14_PRBK=0;
_i  far STEP15_PRBK=0;
_i  far STEP01P=0,STEP02P=0,STEP03P=0;
_i  far STEP04P=0,STEP05P=0;
_i  far STEP07P=0,STEP08P=0,STEP09P=0, STEP10P=0, STEP09D=0;
_i  far STEP14P=0,STEP15P=0;
//  蠣� ॣ���஢
//---------------------------------------------------------------------------
_f  far DIH110=0,DIL110=0,DIS111=0,DIS112=0,DON111=0,DON112=0;
//  ᨣ���� ��� �����������஢
//---------------------------------------------------------------------------
_i  far TIME_GG_CONTROL=0;
//  ����஫� �६��� ࠡ��� �������� ������������
//---------------------------------------------------------------------------
_i  far GKV_POL=0;
//  ����祭��-�몫�祭�� ������� ������
//---------------------------------------------------------------------------
_i  far FLAG_0406A_v=0;
_i  far FLAG_05WTA_v=0;
_i  far FLAG_05BGA_v=0;
_i  far FLAG_0605A_v=0;
_i  far FLAG_0406A_c=0;
_i  far FLAG_05WTA_c=0;
_i  far FLAG_05BGA_c=0;
_i  far FLAG_0605A_c=0;
//  䫠�� ��।������ ����� ॣ���ࠬ�
//---------------------------------------------------------------------------
_f  far AIW218___O=0;
_f  far AIW218___S=0;
_f  far AIW219___O=0;
_f  far AIW219___S=0;
//  ���������� ��� ������ ��宣�
_f  far AIW218___C=0;
_f  far AIW219___C=0;
//  ���稪 横��� �⠡�����樨 ���
//---------------------------------------------------------------------------
_f  far AIW251___O=0;
_f  far AIW251___P=0;
_f  far AIW252___O=0;
//  ��� ������ ���ண� � �।��饣� ����訢����
_f  far AIW252___S=0;
//  ���������� ��� ������ ��। ��砫�� ���㧪�
_f  far AIW252___D=0;
//  �����⨬� ��� ���⪠
//---------------------------------------------------------------------------
_f  far AIW216___O=0;
_f  far AIW216___S=0;
//  ��� ������ ����� � �।��饣� ����訢����
//---------------------------------------------------------------------------
_i  far CCTM_VSDM=0;
//  ���稪 ⥪�饣� �६��� �⠡�����樨 ����஢�� ���ண�
//---------------------------------------------------------------------------
_i  far MK_VG_KL_OPEN=0;
//  䫠� ������ ������� ���㧪� ���ண�
//---------------------------------------------------------------------------
_f  far CNT_SHVBON=0;
//  ���稪 ����祭�� ������ ��宣�
//---------------------------------------------------------------------------
_i  far LSA_VAJV=0;
_i  far LSA_VAJS=0;
_i  far LSA_CEMV=0;
_i  far LSA_CEMS=0;
//  ��᫥���� ���ﭨ� �ᯨ�権
//---------------------------------------------------------------------------
//  ������ �室��-��室�� ॣ���� �����窨 諠��
_f  far DIRR01___V = 0;
_f  far DISR01P1_V = 0;
_f  far DISR01PK_V = 0;
_f  far DISR01MS_V = 0;
_f  far DIHR01___V = 0;
_f  far DILR01___V = 0;
_f  far DIRR01PN_V = 0;
_f  far DISR01PKSV = 0;
_f  far DISR01PKVV = 0;
_f  far DIHR01PN_V = 0;
_f  far DONR01P1_V = 0;
_f  far DONR01PK_V = 0;
_f  far DONR01PKSV = 0;
_f  far DONR01PKVV = 0;
//---------------------------------------------------------------------------
//  ���稪� ����� ��� ��������

_f  far TIME_SLNZCMin = 0;                 // �६� ����㧪� ��.���� 諠��
_f  far TIME_SLNVCMin = 0;                 // �६� ���㧪� ��.���� 諠��
_f  far TIME_PRDSCMin = 0;                 // �६� �த㢪� ��.���� 諠��
_i  far DSB = 0;                           // 䫠� ��८�।������ �.���ᥩ��
_i  far FLAG_HLVSExit = 0;                 // 䫠� ��室� �� �६ ���� �஢��
_i  far FLAG_HLMOExit = 0;                 // 䫠� ��室� �� �६ ���� �஢��
_i  far FLAG_HLBVExit = 0;                 // 䫠� ��室� �� �६ ���� �஢��
_i  far FLAG_HLCMExit = 0;                 // 䫠� ��室� �� �६ ���� �஢��

_f  far TIME_VODMCMin = 0;                 // ����
_f  far TIME_VODHCMin = 0;                 // ����
_f  far TIME_CONDCMin = 0;                 // ��������

_f  far TIME_OTHVCMin = 0;                 // ����� ���� � ��蠫�� ��室�� ��
_f  far TIME_NS31CMin = 0;                 // �६� ����㧪� ��.���� ��室��
_f  far TIME_NS32CMin = 0;                 // �६� ���㧪� ��.���� ��室��
_f  far TIME_PRDOCMin = 0;                 // �த㢪� ��.���� ��室��

_f  far TIME_OSC5Min  = 0;
_f  far TIME_LEV5CMin = 0;
_f  far TIME_NAS5CMin = 0;
_f  far TIME_BVAJCMin = 0;
_f  far TIME_BCEMCMin = 0;
_f  far TIME_PRDCCMin = 0;                 // �६� �த㢪� ��.���� 楬���
_f  far TIME_PCASCMin = 0;                 // �६� �몫 �ᯨ� 楬��� ��᫥ �த�
_f  far TIME_SHDZCMin = 0;                 // �६� ����஢�� ��宣�
_f  far TIME_MKDZCMin = 0;                 // �६� ����஢�� ���ண�
_f  far TIME_PUDZCMin = 0;                 // �६� ����஢�� ����
_f  far TIME_PADZCMin = 0;                 // �६� ����஢�� �����
//
_f  far CNT_VIGRUZ_S  = 0;                 // ���稪 ���㧪� �⠡�� ��� ��宣�
_f  far TIME_PVASCMin = 0;                 // �६� �몫 �ᯨ� ���饣� ��᫥ ������
_f  far TIME_POASCMin = 0;                 // �६� ���� ��᫥ ����� �ᯨ� ����
uc  far FLAG_ONVBC    = 0;                 // 䫠� �몫�祭�� ������� ������
_f  far DON101P=0;                         // �।��饥 ���ﭨ� ᨣ����� ��
_f  far DON102P=0;                         // �������
uc  far STEP05F=0;                         // 䫠� ��宦����� �몫�祭� ॣ����
//
_f  far TIME_LLVCCMin = 0;                 // �६ ������ ���� �஢�� �㭪 楬���
_f  far TIME_LLVVCMin = 0;                 // �६ ������ ���� �஢�� �㭪 ���饣�
_f  far TIME_LLVSCMin = 0;                 // �६ ������ ���� �஢�� ��蠫�� 諠��
_f  far TIME_HLVSCMin = 0;                 // �६ ������ ���� �஢�� ��蠫�� 諠��
_f  far TIME_LLVOCMin = 0;                 // �६ ������ ���� �஢�� ��蠫�� ��室
_f  far TIME_HLVOCMin = 0;                 // �६ ������ ���� �஢�� ��蠫�� ��室
//
_f  far CNT_ZAGRUZ_M  = 0;                 // ���稪 ������ �⠡������ ��� �����
_f  far CNT_VIGRUZ_M  = 0;                 // ���稪 ������ �⠡������ ��� ����
//
_f  far TIME_PLLVCMin = 0;                 // �६� �������� ���� �஢�� ����-���
_f  far TIME_PHLVCMin = 0;                 // �६� �������� ���� �஢�� ����-���
uc  far PAV_OK = OFF;                      // 䫠� ���믪� ��� �ணࠬ��
//
_f  far TIME_PULLCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.����
_f  far TIME_PUHLCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.����
_f  far TIME_PUVZCMin = 0;                 // �६� ���㧪� ��蠫�� ��� ��.����
//
_f  far TIME_PALNCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.�����
_f  far TIME_PANNCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.�����
_f  far TIME_PAMSCMin = 0;                 // �६� ������ ᨣ���� �� ���� ��� ���
_f  far TIME_PALVCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.�����
_f  far TIME_PANVCMin = 0;                 // �६� ����� ��� �� ��� ��� ��.�����
_f  far TIME_PAVGCMin = 0;                 // �६� ���㧪� ������ ��.�����
_f  far TIME_PPM1CMin = 0;                 // �६� ��६�� ��� � ��� ��� ��.�����
_f  far TIME_PNOFCMin = 0;                 // �६� ��⠭���� ���� ��� ��� ��.�����
_f  far FLAG09_NS301  = 0;                 // 䫠� ����祭�� ����
//---------------------------------------------------------------------------
_f  far SigPubZagS = 0;                    // �ࠢ���騩 ᨣ��� ����� ��饣� ॣ
_f  far SigPubVigS = 0;                    // �ࠢ���騩 ᨣ��� ���� ��饣� ॣ
//---------------------
_i  far PubCycStat = 0;                    // ����� ��饣� 横��
_i  far GetPubCycStat(int OBJECT){ 
    if (OBJECT>0) return PubCycStat-(PubCycStat/OBJECT%10*OBJECT); else return -1;
}
_i  far SetPubCycStat(int OBJECT,int VALUE){ 
    if (OBJECT>0) PubCycStat=PubCycStat-(PubCycStat/OBJECT%10*OBJECT)+(OBJECT)*VALUE; return PubCycStat;
}
//  PubCycStat =
//  PubCycStat=PubCycStat-(PubCycStat/1000%10*1000)+(1000* 1) // ����  (1000..9999)
//  PubCycStat=PubCycStat-(PubCycStat/100 %10* 100)+(100 * 0) // ���஥ (100..999)
//  PubCycStat=PubCycStat-(PubCycStat/10  %10*  10)+(10  * 5) // ��宥  (10..99)
//  PubCycStat=PubCycStat-(PubCycStat/1   %10*   1)+(1   * 2) // ��饥  (0..9)


//---------------------------------------------------------------------------
_i  far NewSmena=0;                        // 䫠� �����  ᬥ��
_i  far NewMonth=0;                        // 䫠� ������ �����
_i  far FLSHPZ=0;                          // 䫠�� ��।�� ���祭��
_i  far FLMKPZ=0;
_i  far FLPAPZ=0;
_i  far FLPUPZ=0;
//---------------------------------------------------------------------------
_i  far DON803___F=0;             // 䫠� ���㧪� �����஢ ��宣� � ���ண�
//---------------------------------------------------------------------------
