// #define  OFFICE     1
// #define  TESTVAGI   1
//---------------------------------------------------------------------------
#ifndef   OFFICE
  #define   COMU1      COM1         // ����� ���� ��� ࠡ��� � ��� 1-�� ��㯯�
  #define   COMU2      COM2         // ����� ���� ��� ࠡ��� � ��� 2-�� ��㯯�
  #define   COMWS      COM3         // ����� ���� ��� ������ � ࠡ�祩 �⠭�
#endif

#ifdef    OFFICE
  #define   COMWS      COM2         // ����� ���� ��� ������ � ࠡ�祩 �⠭�
  #ifndef TESTVAGI
    #define COMU2      0            // ����  �� ࠡ�稩
    #define COMU1      COM1         // ����� ���� ��� ࠡ��� � ��� 1-�� ��㯯�
  #else
    #define COMU1      0            // ����  �� ࠡ�稩
    #define COMU2      COM1         // ����� ���� ��� ࠡ��� � ��� 2-�� ��㯯�
  #endif
  ul  far   vg_cnt=0;               // ����� ⥪�饣� �����
  ul  far   vg_erq=0;               // ����� ��ࢮ��  �訡�筮�� �⢥�
  ui  far   vg_flg=0;               // 䫠� ���������� ���
  ui  far   vg_err=0;               // 䫠� �訡�� ���஢���� �ਡ��
#endif

#define   NUWS       0              // �� �ᯮ�짮���� ��� �� COM �����
#define   USWS       1              // �ᯮ�짮���� ...

#define   DONLC      50             // ��㧠 �� �ਥ�� ���祭�� � ��६�����
#define   PAINP      18*5           // ��㧠 ��� ��砫� ��ࠡ�⪨ AI ᨣ�����
#define   PAMSG      18*8           // ��㧠 ��� ��砫� ��ࠡ�⪨ ᮮ�饭��
#define   PAMAX      18*10          // ���ᨬ��쭮� ���祭�� ����
#define   WRITE_DAT_PERIOD  120     // ��ਮ� � ������ ����� ������ �� ���
//---------------------------------------------------------------------------
_i  far houC=0, minC=0, secC=0, yeaC=0, monC=0, dayC=0;
_i  far RunLocal=0;                     // 䫠� ����᪠ �ணࠬ�� � ����� ०���
_i  far WriteFL=0;                      // 䫠� ����� ������ �� ���
_f  far rpDC=0;                         // ���  �������樨
_f  far rpTC=0;                         // �६� �������樨
_i  far COM1HSMD_C=0;                   // ���稪 横��� ������ ��� ���㫥�
_i  far COM2HSMD_C=0;                   // ���稪 横��� ������ ��� ���㫥�
_i  far PCCSWork=0;                     // 䫠� ࠡ��� ����஫���
const ui far WDATP=(60*60*12);          // ��ਮ�  ��� ��⮬���᪮� ����� ������
ui  far CDATP=0;                        // ���稪 ��� ��८���᪮�  ����� ������
_i  far RegRUN=0;                       // 䫠� �믮������ �㭪権 ॣ���஢
_f  far ZERO=0;                         // ����� ��६����� ��� �६����� 横���
_f  far CHANGE=0;                       // ���� ��६����� �롮�
//---------------------------------------------------------------------------
//  ���ᠭ�� �맮�� �㭪権
vd  far InpDataA(vd);
vd  far InpDataS(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far Signal  (vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far SetDefVL(vd);
vd  far InpDataD(vd);
vd  far CPInit(vd){ SYSTEMAF=1; return; }
//---------------------------------------------------------------------------
ex  vd  far  Regul_up(vd);
ex  vd  far  Regul_01(vd);
ex  vd  far  Regul_02(vd);
ex  vd  far  Regul_03(vd);
ex  vd  far  Regul_04(vd);
ex  vd  far  Regul_05(vd);
ex  vd  far  Regul_06(vd);
ex  vd  far  Regul_07(vd);
ex  vd  far  Regul_08(vd);
ex  vd  far  Regul_09(vd);
ex  vd  far  Regul_10(vd);
ex  vd  far  Regul_11(vd);
ex  vd  far  Regul_12(vd);
ex  vd  far  Regul_13(vd);
ex  vd  far  Regul_14(vd);
ex  vd  far  DebugVal(vd);
ex  vd  far  SetStepReg(vd);
ex  vd  far  SetVal(vd);
ex  vd  far  CheckIsp(vd);
ex  vd  far  DefRecept(vd);
ex  vd  far  Check_Regul_Manual(vd);
ex  vd  far  Reg_ZvMs(vd);
ex  vd  far  AutoManM(vd);
ex  vd  far  Meshalki(vd);
//---------------------------------------------------------------------------
//  䫠�� ࠡ��� �� NetBIOS � �� COM �����
_i  far NBLF=0;
_i  far CPLF=0;
//---------------------------------------------------------------------------
//  䫠�� �ࠡ�⪨ �ᯮ���⥫��
_f  far DIS011W =0;
_f  far DIS012W =0;
_f  far DIS021W =0;
_f  far DIS022W =0;
_f  far DIS032W =0;
_f  far DIS042W =0;
_f  far DIS052W =0;
_f  far DIS031W =0;
_f  far DIS041W =0;
_f  far DIS051W =0;
_f  far DIS061W =0;
_f  far DIS071W =0;
_f  far DIS081W =0;
_f  far DIS082W =0;
_f  far DIS111W =0;
_f  far DIS112W =0;
_f  far DIS121W =0;
_f  far DIS122W =0;
_f  far DIS101W =0;
_f  far DIS102W =0;
_f  far DIS131W =0;
_f  far DIS132W =0;
_f  far DIS141W =0;
_f  far DIS142W =0;
_f  far DIS143W =0;
_f  far DIS285W =0;
_f  far DIS286W =0;
_f  far DIS152W =0;
_f  far DIS161W =0;
_f  far DIS162W =0;
_f  far DIS171W =0;
_f  far DIS172W =0;
_f  far DIS173W =0;
_f  far DIS180W =0;
_f  far DIS181W =0;
_f  far DIS182W =0;
_f  far DIS191W =0;
_f  far DIS192W =0;
_f  far DIS193W =0;
_f  far DIS201W =0;
_f  far DIS202W =0;
_f  far DIS211W =0;
_f  far DIS212W =0;
_f  far DIS221W =0;
_f  far DIS222W =0;
_f  far DIS231W =0;
_f  far DIS232W =0;
_f  far DIS241W =0;
_f  far DIS250W =0;
_f  far DIS251W =0;
_f  far DIS252W =0;
_f  far DIS261W =0;
_f  far DIS271W =0;
_f  far DIS272W =0;
_f  far DIS274W =0;
_f  far DIS281W =0;
_f  far DIS291W =0;
_f  far DIS301W =0;
_f  far DIS311W =0;
_f  far DIS312W =0;
_f  far DIS313W =0;
_f  far DIS314W =0;
_f  far DIS316W =0;
_f  far DIS317W =0;
_f  far DIS31AW =0;
_f  far DIS203W =0;
_f  far DIS223W =0;
//---------------------------------------------------------------------------
//  蠣� ॣ���஢
ex _i far STEP01, STEP02, STEP03, STEP04, STEP05;
ex _i far STEP06, STEP07, STEP08, STEP09, STEP10;
//---------------------------------------------------------------------------
//  ��࠭�� �楯� ����㧪�
_i  far RECEPT_VIB = 1;
//---------------------------------------------------------------------------
_f  far DIL140___L=0;
_f  far DIH140___L=0;

_f  far DIL170___L=0;
_f  far DIH170___L=0;

_f  far DIL200___L=0;
_f  far DIM200___L=0;

_f  far DIL210___L=0;
_f  far DIH210___L=0;

_f  far DIL220___L=0;
_f  far DIH220___L=0;

_f  far DIL060___L=0;

_f  far DIL240___L=0;

_f  far DIL260___L=0;
_f  far DIH260___L=0;

_f  far DIL270___L=0;
_f  far DIH270___L=0;

_f  far DIL280___L=0;
_f  far DIH280___L=0;

_f  far DIL300___L=0;
_f  far DIH300___L=0;
//---------------------------------------------------------------------------