// coding=cp866
//---------------------------------------------------------------------------
#define   COMWS    COM1
#define   COMU1    COM2
//---------------------------------------------------------------------------
#define   PAINP    5                 // �६� ��砫� �⥭�� ���������� ᨣ���
int       PAINPC=  0;                // 
#define   PAMSG   (18*8)             // �६� ��� ����祭�� �뢮�� ᮮ�饭��
#define   PAMAX   (18*10)            // ���ᨬ��쭮� �६� ���稪� ����祭��
#define   WRITE_DAT_PERIOD 20        // ��ਮ� � ������ ����� ������ �� ���
//---------------------------------------------------------------------------
#define   MAXNV    70                // ������⢮ ���ᨢ�� ��।�����
#define   MAXCN    60                // ������⢮ �祥� � ���ᨢ�
//---------------------------------------------------------------------------
#define   BEGP     481               // ��砫� ���ᨢ ��।�� �� ���� �஢���
                                     // 1-� �祩��(1-� ��) 1-�� ��ࠬ���
//---------------------------------------------------------------------------
#define   RECL     30                // ࠧ��� ����� ��� ������ ��ࠬ����
#define   PARM     30                // �᫮ �����뢠���� ��ࠬ��஢ [0..30]
#define   HMWD      7                // ���-�� ���� �࠭���� ������ (1 ������)
//---------------------------------------------------------------------------
#define   DAYB     0                 // ��砫� ����ᥩ ������ ��ࠬ � DBA[]
#define   ACNT    (DAYB+RECL*PARM*7) // 3360 ��砫� ���ᨢ�� ��।����� 
#define   ACNA    (ACNT+MAXNV)       // 3430 7-������⢮ ���� ������
#define   AArr    (ACNT+MAXNV*2)     // 3500
// ����� ���ᨬ��쭮�� ����� ���ᨢ�:
// AArr + MAXCN*MAXNV + MAXNV =
// 3500 + 60   *70    + 70    = 3500 + 4200 + 70 = 7770
//---------------------------------------------------------------------------
struct{                              // 
  _f yeaC;                           // 4
  _f monC;                           // 4
  _f dayC;                           // 4
  struct{
    _f data[RECL];                   //
  } pr[PARM];                        //
} far DBA[HMWD];                     //
//---------------------------------------------
// ��� ��ண� ������⢠ ��ࠬ���஢ (PARM=24)
struct{                              // 
  _f yeaC;                           // 4
  _f monC;                           // 4
  _f dayC;                           // 4
  struct{
    _f data[RECL];                   //
  } pr[24];                          //
} far DBO[HMWD];                     //
//---------------------------------------------------------------------------
_f  far VAV[MAXNV][MAXCN+3];         // ���ᨢ ��।�����
//---------------------------------------------------------------------------
ui  far PARC=0;                      // ����� ⥪�饣� ��ࠬ��� (������)
ui  far HORC=0;                      // ⥪�騩 ��
_f  far smnC=0;
_f  far DAWP=0;

_i  far houC=0, minC=0, secC=0, yeaC=0, monC=0, dayC=0;
//---------------------------------------------------------------------------
_f  far HMSmnC=0;                        // 㭨����� ����� ⥪�饩 ᬥ��
_f  far HMDayC=0;                        // 㭨����� ����� ⥪�饣� ���
_f  far HMHouC=0;                        // 㭨����� ����� ⥪�饣� ��
//---------------------------------------------------------------------------
vd  far InpDataA(vd);
vd  far InpDataD(vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far InpDataS(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far Signal (vd);
vd  far Time_01(vd);
vd  far Time_ZZ(vd);
_f  far AAVerLoc(_i,_f,_i,_i);
_i  far WeekDay(_i,_i,_i);
_f  far GetLastH(_i);
_i  far GetCurSmn(vd);
vd  far Sbros(vd);
vd  far RepGen(vd);
vd  far GetMTM(vd);
vd  far CPInit(vd){ SYSTEMAF=2; AUTHCNTZ=255; return; }
//---------------------------------------------------------------------------
vd  far LCheckVAL (vd);
vd  far SetDefVL  (vd);
vd  far SetZerVL  (vd);
_i  far WriteDataP(vd);
_i  far ReadDataP (vd);
_i  far RunLocal=0;
_f  far rpDC=0;
_f  far rpTC=0;
_i  far WriteFL=0;
//---------------------------------------------------------------------------
uc  far CMP_Mon[12][3]={"Jan","Feb","Mar","Apr","May","Jun",
                        "Jul","Aug","Sep","Oct","Nov","Dec"};
_i  far CMP_MNb[12]   ={ 81  , 82  , 83  , 84  , 85  , 86  ,
                         87  , 88  , 89  , 10  , 11  , 12  };
_i  far CMP_h=0;
_i  far CMP_m=0;
_i  far CMP_s=0;
//---------------------------------------------------------------------------
_i  far COM2HSMD_C=0;            // ���稪 横��� ������ ��� ���㫥�
//----------------------------------------------------------------------------
//  䫠�� ࠡ��� �� NetBIOS � �� COM �����
_i  far HNBWANS=0;
_i  far HNBWCNT=0;
_i  far HCOMANS=0;
_i  far HCOMCNT=0;
ui  far UDP=0;                          // 䫠� ࠡ��� �� UDP
ui  far IPPORT=1234;                    // ����� ���� TCP ��� �ਥ�� ����⮢
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
_f  far AIF303VC=0;
_f  far AIF303FS=0;
_f  far AIF304VC=0; 
_f  far AIF304FS=0;
_f  far AIF331VC=0; 
_f  far AIF331FS=0;
_f  far AIF332VC=0; 
_f  far AIF332FS=0;
_f  far AIF34VVC=0; 
_f  far AIF34VFS=0;
_f  far AIF35VVC=0; 
_f  far AIF35VFS=0;
_f  far AIF36VVC=0; 
_f  far AIF36VFS=0;
_f  far AIX0C1VC=0; 
_f  far AIX0C1FS=0;
_f  far AIF37VVC=0; 
_f  far AIF37VFS=0;
_f  far AIF38VVC=0; 
_f  far AIF38VFS=0;
//---------------------------------------------------------------------------
_i  far SecCall=0;
_i  far MinCall=0;
//
_f  far AIP201AVM=0;
_f  far AIP202AVM=0;
_f  far AIP203AVM=0;
_f  far AIF301AVM=0;
_f  far AIF302AVM=0;
_f  far AIF311AVM=0;
_f  far AIF321AVM=0;
_f  far AIF322AVM=0;
//
_f  far AIP311AVM=0;
_f  far AIP321AVM=0;
_f  far AIP322AVM=0;
_f  far AIP331AVM=0;
_f  far AIP34BAVM=0;
_f  far AIP37BAVM=0;
_f  far AIP38BAVM=0;
_f  far AIP40BAVM=0;
//
_f  far AIF40VAVM=0;
//
_f  far AIT101AVM=0;
_f  far AIT102AVM=0;
_f  far AIT103AVM=0;
//
_f  far AIT104AVM=0;
_f  far AIT105AVM=0;
_f  far AIT106AVM=0;
//
_f  far AIT311AVM=0;
_f  far AIT321AVM=0;
_f  far AIT322AVM=0;
//
_f  far AIT331AVM=0;
_f  far AIT37AAVM=0;
_f  far AIT38AAVM=0;
//
_f  far AIT332AVM=0;
_f  far AIT421AVM=0;
_f  far AIT422AVM=0;
//
//---------------------------------------------------------------------------
ui  far AIP201___S=0;
ui  far AIP202___S=0;
ui  far AIP203___S=0;
ui  far AIF301___S=0;
ui  far AIF302___S=0;
ui  far AIF311___S=0;
ui  far AIF321___S=0;
ui  far AIF322___S=0;

ui  far AIP311___S=0;
ui  far AIP321___S=0;
ui  far AIP322___S=0;
ui  far AIP331___S=0;
ui  far AIP34B___S=0;
ui  far AIP37B___S=0;
ui  far AIP38B___S=0;
ui  far AIP40B___S=0;
ui  far AIF40V___S=0;

ui  far AIT101___S=0;
ui  far AIT102___S=0;
ui  far AIT103___S=0;

ui  far AIT104___S=0;
ui  far AIT105___S=0;
ui  far AIT106___S=0;

ui  far AIT311___S=0;
ui  far AIT321___S=0;
ui  far AIT322___S=0;

ui  far AIT331___S=0;
ui  far AIT37A___S=0;
ui  far AIT38A___S=0;

ui  far AIT332___S=0;
ui  far AIT421___S=0;
ui  far AIT422___S=0;

ui  far AIT455___S=0;

//------------------------------------------------------------------------------
