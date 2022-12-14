//---------------------------------------------------------------------------
#define   COMWS      COM1           // ????? ????? ??? ?????? ? ࠡ?祩 ?⠭?
#define   COMU1      COM2           // ????? ????? ??? ࠡ??? ? ??? 1-?? ??㯯?

#define   NUWS       0              // ?? ?ᯮ?짮???? ????? ?? COM ?????
#define   USWS       1              // ?ᯮ?짮???? ...

#define   DONLC      50             // ??㧠 ??? ?ਥ?? ???祭?? ? ??६?????
#define   PAINP      18*5           // ??㧠 ??? ??砫? ??ࠡ?⪨ AI ᨣ?????
#define   PAMSG      18*8           // ??㧠 ??? ??砫? ??ࠡ?⪨ ᮮ?饭??
#define   PAMAX      18*10          // ???ᨬ??쭮? ???祭?? ?????
#define   WRITE_DAT_PERIOD  120     // ??ਮ? ? ??????? ?????? ?????? ?? ????
//---------------------------------------------------------------------------
_i  far houC=0, minC=0, secC=0, yeaC=0, monC=0, dayC=0;
_i  far RunLocal=0;                     // 䫠? ????᪠ ?ணࠬ?? ? ????? ०???
_i  far WriteFL=0;                      // 䫠? ?????? ?????? ?? ????
_f  far rpDC=0;                         // ????  ???????樨
_f  far rpTC=0;                         // ?६? ???????樨
_i  far COM1HSMD_C=0;                   // ????稪 横??? ???????? ???? ???㫥?
_i  far COM2HSMD_C=0;                   // ????稪 横??? ???????? ???? ???㫥?
const ui far WDATP=(60*30);             // ??ਮ?  ??? ??⮬?????᪮? ?????? ??????
ui  far CDATP=0;                        // ????稪 ??? ??८????᪮?  ?????? ??????
_i  far RegRUN=0;                       // 䫠? ?믮?????? ?㭪権 ॣ?????஢
_i  far NewSEC=0;                       // 䫠? ????? ᥪ㭤?
_f  far ZERO=0;                         // ?????? ??६????? ??? ?६????? 横???
_f  far CHANGE=0;                       // ????? ??६????? ?롮??
_f  far AITEMP=0;
_f  far A1NAKPPREM = 0;                 // N ??-??।??稪? ???? ??? ??९?᪥
_f  far A2NAKPPREM = 0;                 // N ??-??।??稪? ???? ??? ??९?᪥
ui  far UDP=0;                          // 䫠? ࠡ??? ?? UDP
uc  far IPTOS1[20];                     // IP ????? 1?? 㧫? ??? ???뫪?
uc  far IPTOS2[20];                     // IP ????? 2?? 㧫? ??? ???뫪?
ui  far IPPORT=1234;
//---------------------------------------------------------------------------
//  ???ᠭ?? ?맮?? ?㭪権
vd  far blocking(vd);
vd  far InpDataA(vd);
vd  far InpDataS(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far L_Signal(vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far SetDefVL(vd);
vd  far InpDataD(vd);
vd  far CPInit(vd){ SYSTEMAF=2; AUTHCNTZ=255; return; }
//---------------------------------------------------------------------------
ex  vd  far  Regul_up(vd);
ex  vd  far  Regul_01(vd);
ex  vd  far  Regul_02(vd);
ex  vd  far  Regul_1c(vd);
ex  vd  far  Regul_1p(vd);
ex  vd  far  Regul_1z(vd);
ex  vd  far  Regul_2c(vd);
ex  vd  far  Regul_2p(vd);
ex  vd  far  Regul_2z(vd);
ex  vd  far  DebugVal(vd);
ex  vd  far  Mod_AR  (vd);
ex  vd  far  Mod_BS  (vd);
ex  vd  far  SetVal(vd);
ex  vd  far  CheckIsp(vd);
ex  _i  far  Get_NetVal(_i);
ex  vd  far  NBW_SetValForReq(vd);
//---------------------------------------------------------------------------
//  䫠?? ࠡ??? ???? NetBIOS ? ?? COM ?????
_i  far HNBWANS=0;
_i  far HNBWCNT=0;
_i  far HCOMANS=0;
_i  far HCOMCNT=0;
//----------------------------------------------------------------------------


//  ??६????? ?஢?ન ?ࠡ?⪨ ?ᯮ???⥫??
//----------------------------------------------------------------------------
_f  far I1ZIOPO__T=0;   // ????稪 ?ࠡ?⪨ ???楢???
_f  far I1ZIOPO__W=0;   // 䫠? ?⠡??쭮? ?ࠡ?⪨ ???楢???
_f  far I1ZIOPO__C=0;   // ????稪 ?६??? ???????? ?ࠡ?⪨ ???楢???
_f  far I1ZIOPO__E=0;   // 䫠? ?訡?? ?६??? ???????? ?ࠡ?⪨ ???楢???

_f  far I1ZIOPC__T=0;   _f  far I1ZIOPC__W=0;   
_f  far I1ZIOPC__C=0;   _f  far I1ZIOPC__E=0;
                                                                                             
_f  far I1ZIPPO__T=0;   _f  far I1ZIPPO__W=0;   
_f  far I1ZIPPO__C=0;   _f  far I1ZIPPO__E=0;
_f  far I1ZIPPC__T=0;   _f  far I1ZIPPC__W=0;   
_f  far I1ZIPPC__C=0;   _f  far I1ZIPPC__E=0;
                                                                                             
_f  far I1ZOPPO__T=0;   _f  far I1ZOPPO__W=0;   
_f  far I1ZOPPO__C=0;   _f  far I1ZOPPO__E=0;
_f  far I1ZOPPC__T=0;   _f  far I1ZOPPC__W=0;   
_f  far I1ZOPPC__C=0;   _f  far I1ZOPPC__E=0;
                                                                                             
_f  far I1ZOPAO__T=0;   _f  far I1ZOPAO__W=0;   
_f  far I1ZOPAO__C=0;   _f  far I1ZOPAO__E=0;
_f  far I1ZOPAC__T=0;   _f  far I1ZOPAC__W=0;   
_f  far I1ZOPAC__C=0;   _f  far I1ZOPAC__E=0;
                                                                                             
_f  far I1VZO____T=0;   _f  far I1VZO____W=0;   
_f  far I1VZO____C=0;   _f  far I1VZO____E=0;
_f  far I1VZC____T=0;   _f  far I1VZC____W=0;   
_f  far I1VZC____C=0;   _f  far I1VZC____E=0;
                                                                                             
_f  far I1KIPO___T=0;   _f  far I1KIPO___W=0;   
_f  far I1KIPO___C=0;   _f  far I1KIPO___E=0;
_f  far I1KIPC___T=0;   _f  far I1KIPC___W=0;   
_f  far I1KIPC___C=0;   _f  far I1KIPC___E=0;
                                                                                             
_f  far I1KOPO___T=0;   _f  far I1KOPO___W=0;   
_f  far I1KOPO___C=0;   _f  far I1KOPO___E=0;
_f  far I1KOPC___T=0;   _f  far I1KOPC___W=0;   
_f  far I1KOPC___C=0;   _f  far I1KOPC___E=0;
                                                                                             
_f  far I1KOCO___T=0;   _f  far I1KOCO___W=0;   
_f  far I1KOCO___C=0;   _f  far I1KOCO___E=0;
_f  far I1KOCC___T=0;   _f  far I1KOCC___W=0;   
_f  far I1KOCC___C=0;   _f  far I1KOCC___E=0;
                                                                                             
_f  far I1HM1UP__T=0;   _f  far I1HM1UP__W=0;   
_f  far I1HM1UP__C=0;   _f  far I1HM1UP__E=0;
_f  far I1HM1DN__T=0;   _f  far I1HM1DN__W=0;   
_f  far I1HM1DN__C=0;   _f  far I1HM1DN__E=0;
                                                                                             
_f  far I1KR1O___T=0;   _f  far I1KR1O___W=0;   
_f  far I1KR1O___C=0;   _f  far I1KR1O___E=0;
_f  far I1KR1C___T=0;   _f  far I1KR1C___W=0;   
_f  far I1KR1C___C=0;   _f  far I1KR1C___E=0;
                                                                                             
_f  far I1BY1O___T=0;   _f  far I1BY1O___W=0;   
_f  far I1BY1O___C=0;   _f  far I1BY1O___E=0;
_f  far I1BY1C___T=0;   _f  far I1BY1C___W=0;   
_f  far I1BY1C___C=0;   _f  far I1BY1C___E=0;
                                                                                             
_f  far I1HM2UP__T=0;   _f  far I1HM2UP__W=0;   
_f  far I1HM2UP__C=0;   _f  far I1HM2UP__E=0;
_f  far I1HM2DN__T=0;   _f  far I1HM2DN__W=0;   
_f  far I1HM2DN__C=0;   _f  far I1HM2DN__E=0;
                                                                                             
_f  far I1KR2O___T=0;   _f  far I1KR2O___W=0;   
_f  far I1KR2O___C=0;   _f  far I1KR2O___E=0;
_f  far I1KR2C___T=0;   _f  far I1KR2C___W=0;   
_f  far I1KR2C___C=0;   _f  far I1KR2C___E=0;
                                                                                             
_f  far I1BY2O___T=0;   _f  far I1BY2O___W=0;   
_f  far I1BY2O___C=0;   _f  far I1BY2O___E=0;
_f  far I1BY2C___T=0;   _f  far I1BY2C___W=0;   
_f  far I1BY2C___C=0;   _f  far I1BY2C___E=0;
                                                                                             
//-------------------------------------------
                                                                                             
_f  far I2ZIOPO__T=0;   _f  far I2ZIOPO__W=0;   
_f  far I2ZIOPO__C=0;   _f  far I2ZIOPO__E=0;
_f  far I2ZIOPC__T=0;   _f  far I2ZIOPC__W=0;   
_f  far I2ZIOPC__C=0;   _f  far I2ZIOPC__E=0;
                                                                                             
_f  far I2ZIPPO__T=0;   _f  far I2ZIPPO__W=0;   
_f  far I2ZIPPO__C=0;   _f  far I2ZIPPO__E=0;
_f  far I2ZIPPC__T=0;   _f  far I2ZIPPC__W=0;   
_f  far I2ZIPPC__C=0;   _f  far I2ZIPPC__E=0;
                                                                                             
_f  far I2ZOPPO__T=0;   _f  far I2ZOPPO__W=0;   
_f  far I2ZOPPO__C=0;   _f  far I2ZOPPO__E=0;
_f  far I2ZOPPC__T=0;   _f  far I2ZOPPC__W=0;   
_f  far I2ZOPPC__C=0;   _f  far I2ZOPPC__E=0;
                                                                                             
_f  far I2ZOPAO__T=0;   _f  far I2ZOPAO__W=0;   
_f  far I2ZOPAO__C=0;   _f  far I2ZOPAO__E=0;
_f  far I2ZOPAC__T=0;   _f  far I2ZOPAC__W=0;   
_f  far I2ZOPAC__C=0;   _f  far I2ZOPAC__E=0;
                                                                                             
_f  far I2VZO____T=0;   _f  far I2VZO____W=0;   
_f  far I2VZO____C=0;   _f  far I2VZO____E=0;
_f  far I2VZC____T=0;   _f  far I2VZC____W=0;   
_f  far I2VZC____C=0;   _f  far I2VZC____E=0;
                                                                                             
_f  far I2KIPO___T=0;   _f  far I2KIPO___W=0;   
_f  far I2KIPO___C=0;   _f  far I2KIPO___E=0;
_f  far I2KIPC___T=0;   _f  far I2KIPC___W=0;   
_f  far I2KIPC___C=0;   _f  far I2KIPC___E=0;
                                                                                             
_f  far I2KOPO___T=0;   _f  far I2KOPO___W=0;   
_f  far I2KOPO___C=0;   _f  far I2KOPO___E=0;
_f  far I2KOPC___T=0;   _f  far I2KOPC___W=0;   
_f  far I2KOPC___C=0;   _f  far I2KOPC___E=0;
                                                                                             
_f  far I2KOCO___T=0;   _f  far I2KOCO___W=0;   
_f  far I2KOCO___C=0;   _f  far I2KOCO___E=0;
_f  far I2KOCC___T=0;   _f  far I2KOCC___W=0;   
_f  far I2KOCC___C=0;   _f  far I2KOCC___E=0;
                                                                                             
_f  far I2HM1UP__T=0;   _f  far I2HM1UP__W=0;   
_f  far I2HM1UP__C=0;   _f  far I2HM1UP__E=0;
_f  far I2HM1DN__T=0;   _f  far I2HM1DN__W=0;   
_f  far I2HM1DN__C=0;   _f  far I2HM1DN__E=0;
                                                                                             
_f  far I2KR1O___T=0;   _f  far I2KR1O___W=0;   
_f  far I2KR1O___C=0;   _f  far I2KR1O___E=0;
_f  far I2KR1C___T=0;   _f  far I2KR1C___W=0;   
_f  far I2KR1C___C=0;   _f  far I2KR1C___E=0;
                                                                                             
_f  far I2BY1O___T=0;   _f  far I2BY1O___W=0;   
_f  far I2BY1O___C=0;   _f  far I2BY1O___E=0;
_f  far I2BY1C___T=0;   _f  far I2BY1C___W=0;   
_f  far I2BY1C___C=0;   _f  far I2BY1C___E=0;
                                                                                             
_f  far I2HM2UP__T=0;   _f  far I2HM2UP__W=0;   
_f  far I2HM2UP__C=0;   _f  far I2HM2UP__E=0;
_f  far I2HM2DN__T=0;   _f  far I2HM2DN__W=0;   
_f  far I2HM2DN__C=0;   _f  far I2HM2DN__E=0;
                                                                                             
_f  far I2KR2O___T=0;   _f  far I2KR2O___W=0;   
_f  far I2KR2O___C=0;   _f  far I2KR2O___E=0;
_f  far I2KR2C___T=0;   _f  far I2KR2C___W=0;   
_f  far I2KR2C___C=0;   _f  far I2KR2C___E=0;
                                                                                             
_f  far I2BY2O___T=0;   _f  far I2BY2O___W=0;   
_f  far I2BY2O___C=0;   _f  far I2BY2O___E=0;
_f  far I2BY2C___T=0;   _f  far I2BY2C___W=0;   
_f  far I2BY2C___C=0;   _f  far I2BY2C___E=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//  ????? ᨣ??????樨
ui  far AIP12M1__S=0;
ui  far AIP12M2__S=0;
ui  far A1TTTB___S=0;
ui  far A2TTTB___S=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
_f  far AIPRP1___V=0;
_f  far AIPRP2___V=0;
//----------------------------------------------------------------------------
