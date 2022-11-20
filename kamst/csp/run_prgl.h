//---------------------------------------------------------------------------
#define   COMWS      COM1           // ����� ���� ��� ������ � ࠡ�祩 �⠭�
#define   COMU1      COM2           // ����� ���� ��� ࠡ��� � ���

#define   NUWS       0              // �� �ᯮ�짮���� ��� �� COM �����
#define   USWS       1              // �ᯮ�짮���� ...

#define   DONLC      50             // ��㧠 �� �ਥ�� ���祭�� � ��६�����
#define   PAINP      18*5           // ��㧠 ��� ��砫� ��ࠡ�⪨ AI ᨣ�����
#define   PAMSG      18*8           // ��㧠 ��� ��砫� ��ࠡ�⪨ ᮮ�饭��
#define   PAMAX      18*10          // ���ᨬ��쭮� ���祭�� ����
#define   WRITE_DAT_PERIOD  240     // ��ਮ� � ������ ����� ������ �� ���
//---------------------------------------------------------------------------
_i  far houC=0;
_i  far minC=0;
_i  far secC=0;
_i  far yeaC=0;
_i  far monC=0;
_i  far dayC=0;
_i  far RunLocal=0;                 // 䫠� ����᪠ �ணࠬ�� � ����� ०���
_i  far WriteFL=0;                  // 䫠� ����� ������ �� ���
_f  far rpDC=0;                     // ���  �������樨
_f  far rpTC=0;                     // �६� �������樨
_i  far COM1HSMD_C=0;               // ���稪 横��� ������ ��� ���㫥�
_i  far COM2HSMD_C=0;               // ���稪 横��� ������ ��� ���㫥�
_i  far PCCSWork=0;                 // 䫠� ࠡ��� ����஫���
const ui far WDATP=(60*60*12);      // ��ਮ�  ��� ��⮬���᪮� ����� ������
ui  far CDATP=0;                    // ���稪 ��� ��८���᪮�  ����� ������
_i  far RegRUN=0;                   // 䫠� �믮������ �㭪権 ॣ���஢
//---------------------------------------------------------------------------
_f  far ZERO=0;                     // ����� ��६����� ��� �६����� 横���
_f  far CHANGE=0;                   // ���� ��६����� �롮�
//---------------------------------------------------------------------------
//  ���ᠭ�� �맮�� �㭪権
vd  far InpDataA(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far Signal  (vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far SetDefVL(vd);
vd  far InpDataD(vd);
vd  far CPInit(vd){ return; }
//---------------------------------------------------------------------------
ex  vd  far Reg_00(vd);
ex  vd  far Reg_01(vd);
ex  vd  far Reg_02(vd);
ex  vd  far Reg_03(vd);
ex  vd  far Reg_04(vd);
ex  vd  far Reg_05(vd);
ex  vd  far Reg_06(vd);
ex  vd  far Reg_07(vd);
ex  vd  far Reg_08(vd);
ex  vd  far Reg_09(vd);
ex  vd  far Reg_10(vd);
ex  vd  far Reg_11(vd);
ex  vd  far Reg_12(vd);
ex  vd  far Reg_13(vd);
ex  vd  far Reg_14(vd);
ex  vd  far Reg_15(vd);
//---------------------------------------------------------------------------
//  䫠�� ࠡ��� �� NetBIOS � �� COM �����
_i  far NBLF=0;
_i  far CPLF=0;
//---------------------------------------------------------------------------
//  䫠�� ᨣ������樨
_f  far DISPBM3__S=0;
_f  far DISPBM6__S=0;
_f  far DISPHD___S=0;
_f  far DISPGD___S=0;
_f  far DISPP1___S=0;
_f  far DISP1ST__S=0;
_f  far DISPD2S__S=0;
_f  far DISP2ST__S=0;
_f  far DILDBM___S=0;
_f  far DILMIM___S=0;
_f  far DISMIM___S=0;
_f  far DISMSVF__S=0;
_f  far DISSHZP__S=0;
_f  far DIX0B13__S=0;
//
_f  far DIPSBM___S=0;
_f  far DIPSHD___S=0;
_f  far DIPS1ST__S=0;
_f  far DIPSVF___S=0;
_f  far DIPSD2S__S=0;
_f  far DIPNS1F__S=0;
_f  far DIPS2S1__S=0;
_f  far DIPSSVP__S=0;
_f  far DIPGDZP__S=0;
_f  far DIX0C09__S=0;
_f  far DIX0C10__S=0;
_f  far DIS24VK__S=0;
_f  far DIS24VA__S=0;
_f  far DISZVS___S=0;
// 
_f  far AITHDF___S=0;
_f  far AITGDF___S=0;
_f  far AIT1ST___S=0;
_f  far AITF1D___S=0;
_f  far AIT2ST___S=0;
_f  far AIT1GR___S=0;
_f  far AIT2GR___S=0;
_f  far AITNS1___S=0;
// 
_f  far AITNS2___S=0;
_f  far AITPBM___S=0;
_f  far AITF1P___S=0;
_f  far AITDVP___S=0;
_f  far AIX0204__S=0;
_f  far AIX0205__S=0;
_f  far AIX0206__S=0;
_f  far AIX0207__S=0;
// 
_f  far AIPGOK___S=0;
_f  far AIPZNS1__S=0;
_f  far AIPZNS2__S=0;
_f  far AIPNZKF__S=0;
_f  far AIPVKIP__S=0;
_f  far AIX0305__S=0;
_f  far AIX0306__S=0;
_f  far AIX0307__S=0;
// 
_f  far AIFDFS___S=0;
_f  far AIFIMBM__S=0;
_f  far AIFSHDF__S=0;
_f  far AIFSVZ___S=0;
_f  far AIFIM2S__S=0;
_f  far AIFSD2S__S=0;
_f  far AIFSP2S__S=0;
_f  far AIX0407__S=0;
// 
_f  far AILNS1S__S=0;
_f  far AILFS1S__S=0;
_f  far AILNS2S__S=0;
_f  far AILZSS___S=0;
_f  far AILZO2S__S=0;
_f  far AILZSVF__S=0;
_f  far AILZPR___S=0;
_f  far AILZO1S__S=0;
// 
_f  far AIHBM3___S=0;
_f  far AIHBM6___S=0;
_f  far AIX0602__S=0;
_f  far AIHP1ST__S=0;
_f  far AIH1ST___S=0;
_f  far AIH2ST___S=0;
_f  far AIX0606__S=0;
_f  far AIX0607__S=0;
//---------------------------------------------------------------------------

