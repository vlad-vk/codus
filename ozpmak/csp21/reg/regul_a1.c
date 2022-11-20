//---------------------------------------------------------------------------

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V1GNS1BS_V = 0;           // ���ﭨ� ������ ����祭�� ���஭���

_f  far  I1KR_TMP_V = 0;           // ⥪�� ����஫ ���祭�� ��࠭  ���誨
_f  far  I1KR1CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠1
_f  far  I1KR2CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠2
_f  far  I1KR1OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠1
_f  far  I1KR2OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠2

_f  far  A1TVACUM_R = 6000;        // �६� ����㬨஢���� (100 �����)
_f  far  I1MAXVCN_V = 0;           // ���稪 �ॢ�襭�� ���� ࠧ०����
_f  far  O1ZOPPO__Y = 0;           // ᨣ��� ��� ���� ���� ��� �� �� ��।��
_f  far  I1ZOPPO__Y = 0;           //
_f  far  A1RPZD___S = 0;           // 蠣 ������� ॣ���� "������ ��������"
_f  far  A1ISPST__C = 0;           // ���稪 ��஫� ��।������ 蠣�
_f  far  A1FLAG=0;                 // �������⥫�� ��६����
_f  far  A1FLGP=0;                 //
_f  far  A1TEMP=0;                 //
_f  far  A1PPRT=0;                 // ������ �� �㭪権 ��।������ 蠣� ���
_f  far  A1SBPT=0;                 // ���稪 ࠧ�����஢�� ���
_f  far  A1SBPC=0;                 // ���稪 �����஢�� ���
_f  far  A1SBPI=0;                 // ���稪 ������� �ᯮ���⥫�� ��� ���
_f  far  A1CISP=0;                 // ���稪 ����஫� ���ﭨ� �ᯮ���⥫��


//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ �������� � �������� ��3
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS1(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  ���ண� ���
    if (i1==  ON){ O1ZIOPO__M= ON; O1ZIOPC__M=OFF; }   //  ������
    if (i1== OFF){ O1ZIOPO__M=OFF; O1ZIOPC__M= ON; }   //  �������
    if (i1==STOP){ O1ZIOPO__M=OFF; O1ZIOPC__M=OFF; }   //  ��⠭�����
    // ��९�᪭��� ��� �室�饣�
    if (i2==  ON){ O1ZIPPO__M= ON; O1ZIPPC__M=OFF; }
    if (i2== OFF){ O1ZIPPO__M=OFF; O1ZIPPC__M= ON; }
    if (i2==STOP){ O1ZIPPO__M=OFF; O1ZIPPC__M=OFF; }
    // ��९�᪭��� ��� ��室�饣�
    if (i3==  ON){ O1ZOPPO__M= ON; O1ZOPPC__M=OFF; }
    if (i3== OFF){ O1ZOPPO__M=OFF; O1ZOPPC__M= ON; }
    if (i3==STOP){ O1ZOPPO__M=OFF; O1ZOPPC__M=OFF; }
    // ��� � �⬮����
    if (i4==  ON){ O1ZOPAO__M= ON; O1ZOPAC__M=OFF; }
    if (i4== OFF){ O1ZOPAO__M=OFF; O1ZOPAC__M= ON; }
    if (i4==STOP){ O1ZOPAO__M=OFF; O1ZOPAC__M=OFF; }
    // ����㬭�� ��������
    if (i5==  ON){ O1VZO____M= ON; O1VZC____M=OFF; }
    if (i5== OFF){ O1VZO____M=OFF; O1VZC____M= ON; }
    if (i5==STOP){ O1VZO____M=OFF; O1VZC____M=OFF; }
    // ������ ���᪠ ���
    if (i6==  ON){ O1KIPO___M= ON; O1KIPO___V= ON; O1KIPC___M=OFF; O1KIPC___V=OFF; }
    if (i6== OFF){ O1KIPO___M=OFF; O1KIPO___V=OFF; O1KIPC___M= ON; O1KIPC___V= ON; }
    if (i6==STOP){ O1KIPO___M=OFF; O1KIPO___V=OFF; O1KIPC___M=OFF; O1KIPC___V=OFF; }
    // ������ ���᪠ ���
    if (i7==  ON){ O1KOPO___M= ON; O1KOPO___V= ON; O1KOPC___M=OFF; O1KOPC___V=OFF; }
    if (i7== OFF){ O1KOPO___M=OFF; O1KOPO___V=OFF; O1KOPC___M= ON; O1KOPC___V= ON; }
    if (i7==STOP){ O1KOPO___M=OFF; O1KOPO___V=OFF; O1KOPC___M=OFF; O1KOPC___V=OFF; }
    // ������ ��� ��������
    if (i8==  ON){ O1KOCO___M= ON; O1KOCO___V= ON; O1KOCC___M=OFF; O1KOCC___V=OFF; }
    if (i8== OFF){ O1KOCO___M=OFF; O1KOCO___V=OFF; O1KOCC___M= ON; O1KOCC___V= ON; }
    if (i8==STOP){ O1KOCO___M=OFF; O1KOCO___V=OFF; O1KOCC___M=OFF; O1KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ ���襪 ��3
//              NUM       BY        HM        KR 
vd  far Set_KR1(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // �������
       if (b==  ON){ O1BY1O___M= ON; O1BY1C___M=OFF; }   //  ������
       if (b== OFF){ O1BY1O___M=OFF; O1BY1C___M= ON; }   //  �������
       if (b==STOP){ O1BY1O___M=OFF; O1BY1C___M=OFF; }   //  ��⠭�����
       // 宬��
       if (h==  ON){ O1HM1UP__M= ON; O1HM1DN__M=OFF; }
       if (h== OFF){ O1HM1UP__M=OFF; O1HM1DN__M= ON; }
       if (h==STOP){ O1HM1UP__M=OFF; O1HM1DN__M=OFF; }
       // ���誠
       if (k==  ON){ O1KR1O___M= ON; O1KR1C___M=OFF; }
       if (k== OFF){ O1KR1O___M=OFF; O1KR1C___M= ON; }
       if (k==STOP){ O1KR1O___M=OFF; O1KR1C___M=OFF; }
    }
    if(n==2){
       // �������
       if (b==  ON){ O1BY2O___M= ON; O1BY2C___M=OFF; }
       if (b== OFF){ O1BY2O___M=OFF; O1BY2C___M= ON; }
       if (b==STOP){ O1BY2O___M=OFF; O1BY2C___M=OFF; }
       // 宬��
       if (h==  ON){ O1HM2UP__M= ON; O1HM2DN__M=OFF; }
       if (h== OFF){ O1HM2UP__M=OFF; O1HM2DN__M= ON; }
       if (h==STOP){ O1HM2UP__M=OFF; O1HM2DN__M=OFF; }
       // ���誠
       if (k==  ON){ O1KR2O___M= ON; O1KR2C___M=OFF; }
       if (k== OFF){ O1KR2O___M=OFF; O1KR2C___M= ON; }
       if (k==STOP){ O1KR2O___M=OFF; O1KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// ���⪠ ��� ⠩��஢ � ���稪�
vd  far Clear_TA1(vd){
    Clear_TO(A1BTM+ 1); Clear_TO(A1BTM+ 2); 
    Clear_TO(A1BTM+ 3); Clear_TO(A1BTM+ 4); 
    Clear_TO(A1BTM+ 5); Clear_TO(A1BTM+ 6);
    Clear_TO(A1BTM+ 7); Clear_TO(A1BTM+ 8); 
    Clear_TO(A1BTM+ 9); Clear_TO(A1BTM+10);
    Clear_TO(A1BTM+11); Clear_TO(A1BTM+12);
    Clear_TO(A1BTM+13); Clear_TO(A1BTM+14);
    Clear_TO(A1BTM+15); Clear_TO(A1BTM+16);
    Clear_TO(A1BTM+17); Clear_TO(A1BTM+18);
    Clear_TO(A1BTM+19);
    A1STEPZ__V=0; A1STEPC__V=0;
}
//---------------------------------------------------------------------------
//  ��⠭���� ��砫��� ���祭�� �� ᬥ�� ०��� ࠡ��� ��⮪����
vd  far Set_BV1(_f far A1STEPWPRV){
    // ��������� ����� �।��饣� 蠣�
    A1STEPP__V =A1STEP___V;
    A1STEPWP_V =A1STEPWPRV;
    // �����  䫠�� ��஫��
    A1CYCRN__V =OFF; A1CYCRN__M=OFF;
    A1CYCST__V =OFF; A1CYCST__M=OFF;
    A1ISPST__V =OFF; A1ISPST__M=OFF;
    // ���㫨�� ���稪� ०���� � ⠩��஢
    A1STEPH__V =0;   A1STEPM__V=0; A1STEPS__V=0; 
    // ����� 䫠�� �롮� ���襪 ��� ������ � �������
    I1KR1OBS_V =0;   I1KR2OBS_V =0;
    I1KR1CBS_V =0;   I1KR2CBS_V =0; 
    I1KR_TMP_V=-1;
    // ���� ������� � ��� �ᯮ���⥫�� ���襪
    Set_KR1(1,STOP,STOP,STOP);
    Set_KR1(2,STOP,STOP,STOP);
    //  ���㫥��� ���祭�� ⠩��஢
    Clear_TA1();
    // ���� ������� �� 宬���
    O1HM1UP__M=OFF; O1HM1DN__M=OFF;
    O1HM2UP__M=OFF; O1HM2DN__M=OFF;
    // ���� ������� �� ��������
    O1BY1O___M=OFF; O1BY1C___M=OFF;
    O1BY2O___M=OFF; O1BY2C___M=OFF;
    // ���� ������� �� ���誨
    O1KR1O___M=OFF; O1KR1C___M=OFF;
    O1KR2O___M=OFF; O1KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  ��⠭���� ⥪�饣� 蠣� ०��� ࠡ��� ��⮪����
vd  far Set_ST1(int SS){
    A1STEPW__V=SS;
    A1STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  ����祭�� ���祭�� �� ��६����� 㤠������ ����஫��஢
//  A1PPSTEP_V - ����� 蠣� �ணࠬ�� ⥪�� ��
//  A1RPPSTEPV - �ਭ������� � ��-��� ���祭��,ᨣ���������饥 � �믮������ ��
//               ��-��� ⥪�饣� 蠣�
_f  far Get_RV1(vd){
    // �᫨ ��࠭ ����� 0- ����� ��� �������� � ������ࠫ�
    if(A1NAKPPREM==0){ return(0); }
    A1RPPSTEPV=0;
    if(A1NAKPPREM==2){ A1RPPSTEPV=A2PPSTEP_V; AIPRP1___V=AIP2P____V; }
    if(A1NAKPPREM==3){ A1RPPSTEPV=A3PPSTEP_V; AIPRP1___V=AIP3P____V; }
    if(A1NAKPPREM==4){ A1RPPSTEPV=A4PPSTEP_V; AIPRP1___V=AIP4P____V; }
    if(A1NAKPPREM==5){ A1RPPSTEPV=A5PPSTEP_V; AIPRP1___V=AIP5P____V; }
    if(A1NAKPPREM==6){ A1RPPSTEPV=A6PPSTEP_V; AIPRP1___V=AIP6P____V; }
    if(A1RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // �᫨ ⥪�騩 �� ��室���� � ०��� ������ ���.��஬
    if(A1PPSTEP_V==420){
       // �᫨ ��-��� ���襫 � ०�� ��������� � ���� �������� �� ���.���
       if(A1RPPSTEPV==700) return(1); return(0);
    }
    // ⥪�騩 �� ������� ������ ������� �� ���.��� �� ��-���
    if(A1PPSTEP_V==425){
       if(A1RPPSTEPV==704) return(2); return(0);
    }
    // ⥪�騩 �� ������� ������� �ᯮ���⥫�� ���᪠ ��� �� ��-���
    if(A1PPSTEP_V==480){
       // �᫨ �� ��-��� �ᯮ���⥫� ����뫨��
       if(A1RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  ����祭�� ⥪�饣� 蠣� ��-���樠�� (��-��) �� �⤠� ���
_f  far Get_RA1(int mode){
    // �஢���� �� ��㣨� ��⮪���� �� ��室���� � ०��� ��ॡ��
    // ��।����� �� ���ﭨ� ��९�᪭�� �������� (����,����)
    if(mode==0){
       if(A2PPSTEP_V>=700 or A3PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // ��।����� ����� ��, ����� ����訢��� ⥪�騩 ��� �⤠� ���
    if(mode==1){
       if(A2PPSTEP_V==420 and A2NAKPP__R==1){ A1IPPNUM_V=2; return(2); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==1){ A1IPPNUM_V=3; return(3); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==1){ A1IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==1){ A1IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==1){ A1IPPNUM_V=6; return(6); }
       return(0);
    }
    // ��।����� ⥪�騩 蠣 �� ��-���樠�� (��-��)
    if(mode==2){
       if(A1IPPNUM_V==2){ A1IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A1IPPNUM_V==3){ A1IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A1IPPNUM_V==4){ A1IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A1IPPNUM_V==5){ A1IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A1IPPNUM_V==6){ A1IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �����஢�� ���
int Chk_SBP1(vd){
    //-------------------------------------------
    // �᫨ �ணࠬ�� �� �� 蠣� ࠡ��� � ���誠��
    if(A1STEPW__V<100||(A1STEPW__V>290&&A1STEPW__V<800)||A1STEPW__V>890){
      // �᫨ ࠧ�����஢��� ���� �� ��� - �뤠�� ������� �� �����⨥
      // ��� �������� � ��३� � ०�� ��������
      if(I1SBP1R__V>0||I1SBP2R__V>0){
        // c����� ���稪 �����஢�� ��� (���� �� �ॡ����)
        A1SBPC=0;
        // �᫨ �� ������ ��� ���� �� �஢��塞�� �ᯮ���⥫��
        if(I1ZIOPC__V!=ON|| I1ZIPPC__V!=ON||I1ZOPPC__V!=ON||I1ZOPAC__V!=ON||
           I1VZC____V!=ON||(I1KOCC___V!=ON&&(A1STEPP__V==3||A1STEP___V==3))){
////��� ��������������.���-�� �������.        
           // c����� ���稪 �⠡��쭮�� ���ﭨ� ������� �ᯮ���⥫��
           A1SBPI=0;
           //-----------
           // �᫨ �ணࠬ� � ��諠 � 蠣� �����, 祬 910(��㣮� ०��)
           if(A1STEPW__V<910){
              // 㢥����� ���稪 �ࠡ�⪨ ��� (��⠥� 5ᥪ) � ���
              if(A1SBPT <5){ A1SBPT++; return(1); }
              // ��᫥���� ࠧ ��᫥ �஢�ન ���稪� ��। �஢�મ�
              // �ᯮ���⥫��- ���㫨�� ���稪� � ⠩���� (����� ��諮 5ᥪ)
              A1STEPZ__V=0; A1STEPC__V=0; Set_BV1(A1STEPW__V);
              Message(107+A1BNM);
           }
           //-----------
           // ��⠭����� ०�� ������� �ᯮ���⥫�� �� ࠧ�����஢�� ���
           Set_ST1(910);
           // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // �������� ���᪠ ���ண� ��� ������?
           Set_ST1(911);
           switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return(1); }
             case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������? 
           Set_ST1(912);
           switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return(1); }
             case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������?
           Set_ST1(913);
           switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return(1); }
             case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return(1); }
           }
           // �������� ���᪠ ��� � �⬮���� ������?
           Set_ST1(914);
           switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return(1); }
             case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return(1); }
           }
           // �������� ����㬠 ������?
           Set_ST1(915);
           switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return(1); }
             case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return(1); }
           }
           // �᫨ ��� �뫮 ࠧ�����஢��� � ०��� ��������������
           if(A1STEPP__V==3){
           // ������ ���᪠ �������� ������?
           Set_ST1(916);
           switch ( Check_TO(A1BTM+6, A1RCHKF__R* SEC, I1KOCC___V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1RCHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return(1); }
             case BAD: { Clear_TO(A1BTM+6); Message(146+A1BNM); Bell(1,1); return(1); }
           } }
           // �᫨ �� ������- ��३� � ०�� �������� ࠧ�����஢�� ���
           Set_ST1(917); return(1);
        } else {
////��� ��������������.��� �������.        
           // �᫨ �� �஢��塞� �ᯮ���⥫� �������- 㬥����� ���稪 �
           // ����� �� 蠣� 900, ���� ����������� ���
           if(A1SBPI<5){ A1SBPI++; return(1); }
           // ��᫥ ���稪� �⠡��쭮�� ������� �ᯮ���⥫��-
           // ����� ���稪 ��������  ������� �ᯮ���⥫��
           A1SBPT=0;
           // �᫨ ࠧ�����஢��� ��� � �����-� ०���,�� �� �ᯮ���⥫�
           // �������- �뤠�� ᮮ�饭�� � 㪠������ ०��� �� ���஬ 
           // �������஢��� ���
           if(A1STEPW__V<900){ Set_BV1(A1STEPW__V); Message(106+A1BNM); }
           // �᫨ �ᯮ���⥫� �뫨 ������� ��᫥ ࠧ�����஢�� ���-
           // �뤠�� ᮮ�饭�� � ⮬, �� �ᯮ���⥫� ����뫨
           if(A1STEPW__V>900){ Message(108+A1BNM ); }
           Set_ST1(900);
        }
      } else {
////��� �������������.
        // �᫨ ��� �������஢��� � ��᫥���� �믮��塞� 蠣 �� �����⨥
        // �������� �� ࠧ�����஢�� ���
        if(A1STEPW__V>=900){
           // ������� 5ᥪ �⠡��쭮� �����஢�� ���
           if(A1SBPC<5){ A1SBPC++; return(1); }
           // ��३� � ०�� ��������
           Message(109+A1BNM); Set_BV1(910); Set_ST1(50); return(1);
        }
        // ����� ��� �������஢���- ����� ���稪� �����஢�� ��� � ���
        A1SBPT=0;
        A1SBPC=0;
        A1SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �ᯮ���⥫�� �� ࠡ�� � ���誠��
int Chk_IF1(int mode){
    // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
    if(I1ZIOPC__V!=ON){ Message(141+A1BNM); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
    if(I1ZIPPC__V!=ON){ Message(142+A1BNM); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
    if(I1ZOPPC__V!=ON){ Message(143+A1BNM); return(0); }
    // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
    if(I1ZOPAC__V!=ON){ Message(144+A1BNM); return(0); }
    // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
    if(I1VZC____V!=ON){ Message(145+A1BNM); return(0); }
    // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
    if(I1KOCC___V!=ON){ Message(146+A1BNM); return(0); }
    // ��� ࠧ�����஢��?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I1SBP1R__V==0||I1SBP2R__V==0){ Message(149+A1BNM); return(0); }
    }
    // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I1P1_N___V==0||I1P2_N___V==0){ Message(156+A1BNM); return(0); }
    }
    // ���� ����殮��� �� �� �ࠢ� ���஭��ᮬ? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I1VACKR__V!=ON){ Message(157+A1BNM); return(0); }
    }
    // ०�� �ࠢ����� ���誠�� ��⮪���� ���⠭�? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I1LUCDU__V!=ON){ Message(158+A1BNM); return(0); }
    }
    // ०�� �ࠢ����� ��⮪����� ���⠭��(��)?
    if(mode==0 or mode==1){
      if(I1DU_____V!=ON){ Message(188+A1BNM); return(0); }
    }
    // �஢�ઠ ࠡ��� (����祭���� ���ﭨ�) ���஭��� 
    // �������� ����祭�� ���஭���               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I1GNS_1__V!=ON){ Message(160+A1BNM); return(0); }
    }
    // �᫨ ����� ������ ����
    if(mode>0){
       // �᫨ �� - ���室�� � ०�� ����������
       if(I1KR1SB__V==ON||I1KR2SB__V==ON||I1GNS0B__V>0){
          A1CISP=0; Message(168+A1BNM); Set_BV1(870); Set_ST1(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_01(vd){

    // ��⠭����� 䫠� ����� ��஫� ����᪠ 横�� � ��३�
    // �� ०��  "��������������"
    if (A1CYCRN__M>OFF){ A1CYCRN__V=ON; A1CYCRN__M=OFF; Set_ST1(300); }
    // ��⠭����� 䫠� ����� ��஫� ��⠭���� 横��
    if (A1CYCST__M>OFF){ A1CYCST__V=ON; A1CYCST__M=OFF; Set_ST1(50);  }
    // ��⠭����� 䫠� ����� ��஫� ���室� �� ������� 蠣
    if (A1ISPST__M>OFF){ A1ISPST__V=ON; A1ISPST__M=OFF; }

    // ��।������ ����� ०��� �� 蠣�
    A1STEP___V=floor( A1STEPW__V*0.01);
    // �஢�ઠ �࠭�筮�� ���祭�� ���������� 蠣�
    if (A1STEPW__M<0  or A1STEPW__M>900){ A1STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  �᫨ �� ������� 蠣 ࠡ��� ��⮪���� � ������ ��஫� ��������� 蠣�
    if (A1STEPW__M!=A1STEPW__V and A1ISPST__V==ON){
        //  �᫨ ��࠭ ������ ����� �ࠢ����� � ������ ��஫�
        //  ����᪠ ��� ��⠭��� 横��
        if((A1STEPW__M<=10)){
            A1STEPW__V =A1STEPW__M; Message(130+A1BNM);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=100) and (A1STEPW__M< 200) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(131+A1BNM);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=200) and (A1STEPW__M< 300) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(132+A1BNM);
        }
        //  �᫨ ��࠭ ०�� "��������������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=300) and (A1STEPW__M< 400) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(133+A1BNM);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=400) and (A1STEPW__M< 500) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(134+A1BNM); A1NAKPPREM=A1NAKPP__R;
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=500) and (A1STEPW__M< 600) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(135+A1BNM);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A1STEPW__M>=600) and (A1STEPW__M< 700) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(136+A1BNM);
        }
        //-------------------------------------------------------------------
        //  ��⠭���� ����� ��।�������� ०��� ࠡ��� 
        if (A1STEPW__M == A1STEPW__V){ Set_BV1(0); }
        else                         { A1STEPW__M=A1STEPW__V; }
    }
//  // ----------------------------------------------------------------------







//  // ----------------------------------------------------------------------
//  // �஢�ન � ����஫� ��� ������ ����� ᥪ㭤�
    if(NewSEC>0){ 
       //-------------------------------------------
       // ������ �६��� ࠡ��� � ⥪�饬 ०���
       // ����� ᥪ㭤�
       A1STEPS__V++;
       // ����� ������
       if(A1STEPS__V>59){ A1STEPM__V++; A1STEPS__V=0; }
       // ����� ���
       if(A1STEPM__V>59){ A1STEPH__V++; A1STEPM__V=0; }
       // �१ 99 �ᮢ �६� ��⠥��� ᭠砫� (4,5 ��⮪)
       if(A1STEPH__V>99){ A1STEPH__V=0; A1STEPM__V=0; A1STEPS__V=0; }
       //-------------------------------------------
       // �᫨ �� ������ ��஫�- ��⠭���������� 䫠� ����� ��஫�, �����
       // ����⢨⥫�� 10 ᥪ㭤
       if(A1ISPST__V==ON or A1CYCST__V==ON or A1CYCRN__V==ON){ A1ISPST__C++; }
       // �᫨ ��諮 ����� 10 ᥪ ��᫥ ����� ��஫�- ����� 䫠� ����� 
       // ��஫�  � ���稪 ᥪ㭤 (��஫� �㦭� ������� ������)
       if(A1ISPST__C >10){ 
          A1ISPST__C=0; A1ISPST__V=OFF; A1CYCST__V=OFF; A1CYCRN__V=OFF;
       }
       //-------------------------------------------
       // �᫨ �� ������� ०�� �ࠢ����� ࠡ�⮩ ��⮪���� (��/��)
       if(S1MDUP___V!=S1MDU____V){
          // ��ॢ����� �� ��� - ��ॢ��� �ணࠬ�� � ०�� "��������"
          if(S1MDU____V==0){
             Message(137+A1BNM); Set_BV1(0); Set_ST1(50);
          }
          // ��ॢ����� �� ��  - �뤠�� ᮮ�饭��  � � ०�� "��������"
          if(S1MDU____V==1){
             Message(138+A1BNM); Set_BV1(0); Set_ST1(50);
          }
       }; S1MDUP___V=S1MDU____V;
       //-------------------------------------------
       if(Chk_SBP1()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �������� ������ ������ ������-������� ��⮪���� �� ०��� "��������"
    if (A1STEPW__V<=10||A1STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // �������� ������ ������ ����祭�� ���஭���
        // �᫨ �����- ��३� �� 蠣 870
        if(V1GNS1BS_V<1){
           if(I1GNS1B__V>0){
              Message(183+A1BNM); O1GNS____M=ON; A1CISP=0;
              Set_BV1(50); V1GNS1BS_V=1; Set_ST1(870); return;
           }
        }
        // ����� ������ �몫�祭�� ���஭���
        if(I1GNS0B__V>0){ V1GNS1BS_V=0; O1GNS____M=OFF; }
        //-----------
        // ����஫� ��⮢���� ��⮪���� ��३� � ०�� "���������"
        //(�������� � ��⮪���� �.�.  >1 � ������� �� ��������, ������� �
        // �ᯮ���⥫� ���襪, �� �� ���⠭樨).
        if(AIP1P____V>1 and I1ZIOPC__V>0 and I1ZIPPC__V>0 and I1ZOPPC__V>0 and
           I1VZC____V>0 and I1ZOPAC__V>0 and I1KIPC___V>0 and I1KOPC___V>0 and
           I1DU_____V>0 and
           I1SBP1Z__V>0 and I1SBP2Z__V>0){
           // ��।�����, �� ��㣨� �� �� ��室���� � ०��� ��९�᪠
           if(Get_RA1(0)>0){
              // �᫨ �����-� �� ����訢��� ����� ��� ��������� -
              // ��।����� ��� �����
              if(Get_RA1(1)>0){
                 // ��३� �� ०�� ��������
                 Message(129+A1BNM); Set_BV1(0); Set_ST1(700);
              }
           }
        }
        return;
    }
//  // ----------------------------------------------------------------------







//  // ��������� ०���� ࠡ���. �᫨ �� ��࠭ �㭪� ���� "��⠭���� 横��"
//  // ��� ����� ������ "����"  ���  �४�饭� ࠡ�� �ணࠬ�� ��-��
//  // ����-� ����襭�� (� �����-�  �� ०���� �� �ࠡ�⠫ ���楢�� � �.�.).
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=50 and A1STEPW__V<70){
       // �᫨ �諨 � 蠣� 232:- ������� 宬�� 
       if(A1STEPWP_V==232){

       }
       // ���� ������� � ��� �ᯮ���⥫��
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS1(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR1(1,STOP,STOP,STOP);
       Set_KR1(2,STOP,STOP,STOP);
       // �몫���� ���஭���
       O1GNS____M=OFF;
       // ����� ������� ����祭�� ���஭���
       V1GNS1BS_V=0;
       // ���� ����窨 � �롮� ०���� 横��
       A1NAKPP_YM=OFF;  A1NAKPP_YV=A1NAKPP_YM;
       A1RAZVK_YM=OFF;  A1RAZVK_YV=A1RAZVK_YM;
       A1PPP___YM=OFF;  A1PPP___YV=A1PPP___YM;
       A1PVID__YM=OFF;  A1PVID__YV=A1PVID__YM;
       A1SP____YM=OFF;  A1SP____YV=A1SP____YM;
       // ������ ⥪�騥 ⠩���� � ���稪�
       Clear_TA1();
       A1PPSTEP_V=0;
       // ��३� � ०�� ��������
       Message(189+A1BNM); Set_BV1(50); Set_ST1(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  ����祭�� �����������
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=870 and A1STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST1(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        //-----------
        // �᫨ ����� ������ �몫�祭�� ���஭���- �뤠�� �������� �� 
        // �몫�祭�� ���஭���
        if(I1GNS0B__V==ON){ 
           Message(184+A1BNM);
           // �뤠�� ������� �� �몫�祭�� ���஭���
           O1GNS____M=OFF;
           // ����� 䫠� ���ﭨ� ������ ����祭�� ���஭���
           V1GNS1BS_V=0; 
        }
        // �᫨ ����㯨�� ������� �� �몫�祭�� ���஭���
        if(V1GNS1BS_V==0&&O1GNS____M==OFF){
           // ���� ������� � �ᯮ���⥫�� ��堭����� ���誨
           //      N BY   HM   KR
           Set_KR1(1,STOP,STOP,STOP);
           Set_KR1(2,STOP,STOP,STOP);
           // ���� ������� � �ᯮ���⥫�� ��������
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ����� �몫�祭�� ���஭���
           switch( Check_TO(A1BTM+1,60*SEC, I1GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A1BNM); Bell(1,1); break; }
              case END: { Message(185+A1BNM); break; }
           }
           // ��३� � ०�� ��������
           Set_BV1(870); Set_ST1(50); return;
        }
        // �஢�ઠ ���ﭨ� �ᯮ���⥫��
        if(Chk_IF1(0)==0){
           A1CISP++; 
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(50); 
           }
           return; 
        }; A1CISP=0;
        //-----------
        // �뤠�� �������� �� ����祭�� ���஭���:
        O1GNS____M= ON;
        //-----------
        // �������� ������ ������ "������ ��⮪���"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR1OB__V>0){
              Message(174+A1BNM); A1CISP=0;
              Set_BV1(50); I1KR1OBS_V=1; V1GNS1BS_V=1; Set_ST1(100); return;
           }
        }
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR2OB__V>0){
              Message(175+A1BNM); A1CISP=0;
              Set_BV1(50); I1KR2OBS_V=1; V1GNS1BS_V=1; Set_ST1(100); return;
           }
        }
        //-----------
        // �������� ������ ������ "������� ��⮪���"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR1CB__V>0){
              Message(176+A1BNM);  A1CISP=0;
              Set_BV1(50); I1KR1CBS_V=1; V1GNS1BS_V=1; Set_ST1(200); return;
           }
        }
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR2CB__V>0){
              Message(177+A1BNM);  A1CISP=0;
              Set_BV1(50); I1KR2CBS_V=1; V1GNS1BS_V=1; Set_ST1(200); return;
           }
        }
        //-----------
        Clear_TA1();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������" ��3
//  // ----------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A1STEPW__V>=100 and A1STEPW__V< 130){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O1GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V!=126){ Message(195+A1BNM); }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST1(126);
        I1KR_TMP_V=-1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(126); Set_ST1(870); return;}
        switch ( Check_TO(A1BTM+14,A1THMUP__R*SEC, I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R;A1STEPC__V =CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(151+A1BNM);
                        // �᫨ �� ���� 蠣 ����஫�- 㢥����� ���稪 
                        // ����஫� � ���� ������� �� �����⨥ 宬��
                        if(A1TEMP<1){ 
                           if(I1KR1OBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
                           if(I1KR2OBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
                           A1TEMP++;
                        }
                        // �᫨ �� ��ன 蠣 ����஫�- ������ � ���室 �
                        // ०�� ��������
                        else        { Bell(1,1); Set_BV1(126); Set_ST1(870); }
                        return;
                      }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15);
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        Clear_TO(A1BTM+18); Clear_TO(A1BTM+19);
        A1STEPZ__V=0; A1STEPC__V=0;
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        Set_ST1(130);  A1TEMP=0;
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������":
    if (A1STEPW__V>=130 and A1STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O1GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST1(132);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1BY1O___V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1BY2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(132); Set_ST1(870); return;}
        // �᫨ ������� �� �����
        if(I1KR_TMP_V==OFF){
//         // ������� �� ����⨥ �������              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // �������� �����ᠬ�: 2ᥪ ������, 2ᥪ ��㧠
           if(A1TEMP<2){
             // ������ �� ����⨥
             if(I1KR1OBS_V>0){ O1BY1O___M=ON; O1BY1C___M=OFF; }
             if(I1KR2OBS_V>0){ O1BY2O___M=ON; O1BY2C___M=OFF; }
             A1TEMP++;
           } else {
             // ��㧠
             if(A1TEMP<4){
                O1BY1O___M=OFF; O1BY1C___M=OFF;
                O1BY2O___M=OFF; O1BY2C___M=OFF;
                A1TEMP++;
             } else {
             // ���室 ��᫥ ���� �� ������
                if(A1TEMP<7) A1TEMP=0;
             }
           }  
        }
        switch (Check_TO( A1BTM+16,A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(154+A1BNM); Bell(1,1); 
                        Set_BV1(132); Set_ST1(870);
                        return; 
                      }
        }
        // ��� 䫠�� ����� �����᭮�� ᨣ���� �� �������
        A1TEMP=10;
        // ���� ������� �� ����⨥ ������⮢          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O1BY1O___M=OFF; O1BY1C___M=OFF;
        O1BY2O___M=OFF; O1BY2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A1BTM+17,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+17]; return; }
        }
//      // ������� �� �����⨥ 宬��                   [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I1KR1OBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
        if(I1KR2OBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST1(131);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(131); Set_ST1(870); return;}
        switch (Check_TO( A1BTM+14,A1THMUP__R*SEC,I1KR_TMP_V, '=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(151+A1BNM); Bell(1,1);
                        Set_BV1(131); Set_ST1(870);    return;
                      }
        }
        // ���� ������� �� �����⨥ 宬��             [x6.o01 (OxHM1UP) = 0]
        //                                              [x6.o07 (OxHM2UP) = 0]
        O1HM1UP__M=OFF; O1HM1DN__M=OFF;
        O1HM2UP__M=OFF; O1HM2DN__M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        //--------
//      // ������� �� ����⨥ ���誨                   [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I1KR1OBS_V>0){ O1KR1O___M=ON; O1KR1C___M=OFF; }
        if(I1KR2OBS_V>0){ O1KR2O___M=ON; O1KR2C___M=OFF; }
        // ���誨 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST1(133);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1KR1O___V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1KR2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(133); Set_ST1(870);  return;}
        switch (Check_TO( A1BTM+18,A1TKRO___R*SEC, I1KR_TMP_V, '=',ON,1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+18); Message(152+A1BNM); Bell(1,1); 
                        Set_BV1(133); Set_ST1(870);
                        return; 
                      }
        }
        // ������� � ���襪 ᭨��� ��᫥ ���᪠��� 宬��

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO(A1BTM+19,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+19]; return; }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15);
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        Clear_TO(A1BTM+18); Clear_TO(A1BTM+19);
        A1STEPZ__V=0; A1STEPC__V=0;
        //
        Set_ST1(134); A1TEMP=0; return;
    }
//  // ----------------------
//  //  ���᪠��� 宬��
    if (A1STEPW__V>=134 and A1STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O1GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
//      // ������� �� ���᪠��� 宬�⮢                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I1KR1OBS_V>0){ O1HM1DN__M=ON; O1HM1UP__M=OFF; }
        if(I1KR2OBS_V>0){ O1HM2DN__M=ON; O1HM2UP__M=OFF; }
        // 宬��� ���饭�?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST1(134);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1DN__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2DN__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(134); Set_ST1(870);  return;}
        switch (Check_TO( A1BTM+14,A1THMUP__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(150+A1BNM); Bell(1,1); 
                        Set_BV1(134); Set_ST1(870);
                        return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        if(I1KR1OBS_V>0){ Message(191+A1BNM); }
        if(I1KR2OBS_V>0){ Message(192+A1BNM); }
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"->"��������"|"���"
        Message(197+A1BNM); Set_BV1(134); Set_ST1(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A1STEPW__V>=200 and A1STEPW__V< 230){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O1GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V==200){ Message(196+A1BNM); }
        //--------
        // 宬�� ���饭?                                [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST1(226);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1HM1DN__V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1HM2DN__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(226);  Set_ST1(870); return;}
        switch ( Check_TO (A1BTM+14, A1THMUP__R*SEC,   I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(150+A1BNM); Bell(1,1); 
                        Set_BV1(226); Set_ST1(870);   return; 
                      }
        }
        // �뤠�� �������� �� ����⨥ �������
        if(I1KR1CBS_V>0){ O1BY1O___M=ON; O1BY1C___M=OFF; }
        if(I1KR2CBS_V>0){ O1BY2O___M=ON; O1BY2C___M=OFF; }
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        // �᫨ ������� �� ������- ���
        Set_ST1(228);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1BY1O___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1BY2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(228); Set_ST1(870); return;}
        switch ( Check_TO (A1BTM+15, A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+15); Message(154+A1BNM); Bell(1,1);
                        Set_BV1(228); Set_ST1(870);   return; 
                      }
        }
        // ���� ������� � �������
        O1BY1O___M=OFF; O1BY1C___M=OFF;
        O1BY2O___M=OFF; O1BY2C___M=OFF;
        //
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15); 
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(230);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": �ਯ������ ��। �����⨥�
    if (A1STEPW__V>=230 and A1STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O1GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // ������� �� �ਯ����⨥ ���誨                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I1KR1CBS_V>0){ O1KR1O___M=ON; O1KR1C___M=OFF; }
        if(I1KR2CBS_V>0){ O1KR2O___M=ON; O1KR2C___M=OFF; }
        // ���誠 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST1(231);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1KR1O___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1KR2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(231); Set_ST1(870); return;}
        switch (Check_TO(A1BTM+14,A1TKRO___R*SEC, I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(152+A1BNM); Bell(1,1);
                        Set_BV1(231); Set_ST1(870);   return; 
                      }
        }
        // ���� ������� �� �����⨥ ���誨             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O1KR1O___M=OFF; O1KR1C___M=OFF;
        O1KR2O___M=OFF; O1KR2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        // ������ ������� �� �����⨥ 宬��            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I1KR1CBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
        if(I1KR2CBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
        Set_ST1(232);
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(232); Set_ST1(870); return;}
        switch (Check_TO(A1BTM+16,A1THMUP__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(151+A1BNM); Bell(1,1);
                        Set_BV1(232); Set_ST1(870);   return; 
                      }
        }
        // ��᫥ ������� 宬�� ������� �� ᭨������

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A1BTM+17,A1TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+17]; return; }
        }
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15); 
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(235);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": ������� ���誨
    if (A1STEPW__V>=235 and A1STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O1GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(235); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // ������� �� �����⨥ ���襪                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I1KR1CBS_V>0){ O1KR1C___M=ON; O1KR1O___M=OFF; }
        if(I1KR2CBS_V>0){ O1KR2C___M=ON; O1KR2O___M=OFF; }
        // ���誠 ������?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST1(236);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1KR1C___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1KR2C___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(236); Set_ST1(870); return;}
        switch (Check_TO (A1BTM+14,A1TKRO___R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(153+A1BNM); Bell(1,1);
                        Set_BV1(236); Set_ST1(870); return; 
                      }
        }
        // ���� ������� �� �����⨥ ���襪             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O1KR1C___M=OFF; O1KR1O___M=OFF;
        O1KR2C___M=OFF; O1KR2O___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        // ������� �� �����⨥ ������⮢                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I1KR1CBS_V>0){ O1BY1C___M=ON; O1BY1O___M=OFF; }
        if(I1KR2CBS_V>0){ O1BY2C___M=ON; O1BY2O___M=OFF; }
        // �������� �������?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST1(237);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1BY1C___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1BY2C___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(237); Set_ST1(870); return;}
        switch (Check_TO (A1BTM+16,A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(155+A1BNM); Bell(1,1);
                        Set_BV1(237); Set_ST1(870);   return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        if(I1KR1OBS_V>0){ Message(193+A1BNM); }
        if(I1KR2OBS_V>0){ Message(194+A1BNM); }
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"
        Message(198+A1BNM); Set_BV1(235); Set_ST1(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A1STEPW__V>=300 and A1STEPW__V<320){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "��������������"- ��३� �� � ०��
        if(A1RAZVK_YV==OFF){ Set_BV1(300); Set_ST1(400); return; }
        // �஢�ઠ  ����㬨஢���� ��㣨� ��⮪�����
        // (�� ����㬨஢���� ����� ��室����  ������ ���� ��⮪���)
        if(A2PPSTEP_V==300||A3PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV1(300); Set_ST1(50); return; 
        }
        A1PPSTEP_V=300;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V==300){ Message(200+A1BNM); }
        //
        Set_ST1(311);
        // ��ॢ��� ॣ���� �������� � ��� ०��, �⮡� ������� ������
        A1RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST1(301);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST1(302);
        switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST1(303);
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST1(304);
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST1(305);
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
        Set_ST1(306);
        switch ( Check_TO(A1BTM+6, A1RCHKF__R* SEC, I1KOCC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1RCHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(146+A1BNM); Bell(1,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST1(307);
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST1(308);
        switch ( Check_TO(A1BTM+8, 60*SEC,(I1P1_N___V and I1P2_N___V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+8]; return; }
            case BAD: { Clear_TO(A1BTM+8); Message(156+A1BNM); Bell(1,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST1(309);
        switch ( Check_TO(A1BTM+9, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+9]; return; }
            case BAD: { Clear_TO(A1BTM+9); Message(147+A1BNM); Bell(1,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ����㬭���      [x2.i08 (IxVNMD_) = 1]
        Set_ST1(310);
        switch ( Check_TO(A1BTM+10, 60*SEC, I1VNMD___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+10]; return; }
            case BAD: { Clear_TO(A1BTM+10); Message(162+A1BNM); Bell(1,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ��������          [x2.i07 (IxVZMD_) = 1]
        Set_ST1(311);
        switch ( Check_TO(A1BTM+11, 60*SEC, I1VZMD___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+11]; return; }
            case BAD: { Clear_TO(A1BTM+11); Message(182+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6); 
        Clear_TO(A1BTM+7); Clear_TO(A1BTM+8); Clear_TO(A1BTM+9); 
        Clear_TO(A1BTM+10);
        Clear_TO(A1BTM+11);
        A1STEPZ__V=0; A1STEPC__V=0;
        I1MAXVCN_V=0;
        Set_ST1(320);
        return;
    }
//  // ----------------------
//  //  ����祭�� ����㬨஢����
    if (A1STEPW__V>=320 and A1STEPW__V<325){
        if(!NewSEC){ return; }
        // ������� �� ����⨥ ����㬭�� ��������       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // ����㬭�� �������� �����?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST1(321);
        switch ( Check_TO(A1BTM+1, A1TVZO___R* SEC, I1VZO____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(163+A1BNM); return; }
        }
        // ���� ������� �� ����⨥ ����㬭�� �������� [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // ����뢠���� ������ �� ����㬭�� ����       [x4.o04 (OxAZVO_) = 1]
        O1AZVO___V=ON; O1AZVO___M=OFF;
        // ������� �� ����祭�� ����㬭��� ����       [x4.o05 (OxVN_1_) = 1]
        O1VN_1___V=ON; O1VN_1___M=OFF;
        Set_ST1(322);
        // ����㬭� ���� ����祭?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A1BTM+2, 60*SEC, I1VN_1___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(164+A1BNM); Bell(1,1); return; }
        }
        // �஢�ઠ ������ ���ᨬ��쭮�� ࠧ०���� �   [x2.i06 (IxMAXV_) = 1]
        // �.���⠪⭮�� ��������
        if(I1MAXV___V>0){ I1MAXVCN_V++; }
        else            { I1MAXVCN_V=0; }
        if(I1MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
           Set_ST1(325);
           return;
        }
        // �஢�ઠ ����稭� ࠧ०���� � ��⮪����     [x0.06 (AIPxyV__) = ?]
        // (����� ��� ��� ��� ���)
        Set_ST1(323);
        switch ( Check_TO(A1BTM+3, A1TVACUM_R* SEC, AIP12V___V,'<',A1RAZVK__R, 3)){
            case RUN: { A1STEPZ__V=A1TVACUM_R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Message(165+A1BNM); break; }
        }
        // ���� �������� �� �����⨥ ����㬭�� �������� [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(325);
        return;
    }
//  // ----------------------
//  //  �몫�祭�� ����㬨஢����
    if (A1STEPW__V>=325 and A1STEPW__V<330){
        if(!NewSEC){ return; }
        // ������� �� �����⨥ ����㬭�� ��������       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ����㬭�� �������� ������?                  [x2.i02 (IxVZC__) = 1]
        Set_ST1(326);
        switch ( Check_TO(A1BTM+1, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(166+A1BNM); return; }
        }
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        Set_ST1(327);
        switch (Check_TO (A1BTM+3,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
        }
        // ������ ������ �⬮���� �� ����㬭�� ���� [x4.o04 (OxAZVO_) = 1]
        O1AZVO___V=OFF; O1AZVO___M=OFF;
        // �몫���� ����㬭� ����                    [x4.o05 (OxVN_1_) = 0]
        O1VN_1___V=OFF; O1VN_1___M=OFF;
        Set_ST1(328);
        // ����㬭� ���� �몫�祭?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A1BTM+4,  120*SEC, I1VN_1___V,'=',OFF, 1)){
            case RUN: { A1STEPZ__V=120; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(167+A1BNM); return; }
        }
        //
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); 
        Clear_TO(A1BTM+3); Clear_TO(A1BTM+4);
        A1STEPZ__V=0; A1STEPC__V=0;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(190+A1BNM); Set_ST1(330);
        return;
    }
//  // ----------------------
//  //  �������������� ���������
    if (A1STEPW__V>=330 and A1STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ��ॢ�� �ࠢ����� ��⮪����� � ��筮� ०��
        Set_BV1(330); Set_ST1(400);
        A1RAZVK_YM=OFF;  A1RAZVK_YV=A1RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  ����� "����� ��������"
//  // -----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A1STEPW__V>=400 and A1STEPW__V<420){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� � ०��
        if(A1PPP___YV==OFF){ Set_BV1 (400); Set_ST1(500); return; }
        A1PPSTEP_V=400;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V==400){ 
           Message(201+A1BNM); 
           A1RPRA___M=OFF; A1RPUU1__M=RMINUS; Set_ST1(401); return;
        }
        //
        A1NAKPPREM=A1NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST1(401);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST1(402);
        switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST1(403);
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST1(404);
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST1(405);
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        // ������ ���᪠ ��� ������?
        Set_ST1(406);
        switch ( Check_TO(A1BTM+6, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(128+A1BNM); Bell(1,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST1(407);
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST1(409);
        switch ( Check_TO(A1BTM+9, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+9]; return; }
            case BAD: { Clear_TO(A1BTM+9); Message(147+A1BNM); Bell(1,1); return; }
        }
        // ०�� �ࠢ����� ��⮪����� "���⠭��"?     [x1.i13 (IxDU___) = 1]
        Set_ST1(410);
        switch ( Check_TO(A1BTM+10, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+10]; return; }
            case BAD: { Clear_TO(A1BTM+10); Message(159+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6); 
        Clear_TO(A1BTM+7); Clear_TO(A1BTM+8); Clear_TO(A1BTM+9); 
        Clear_TO(A1BTM+10);
        A1STEPZ__V=0; A1STEPC__V=0;
        // ��࠭ ०�� ����� �������� ������ࠫ�� ��஬?
        if(A1NAKPPREM==0) Set_ST1(430);
        else              Set_ST1(420);
        A1TEMP=0; A1FLAG=0; A1PPRT=0; A1RPRA___M=ON; A1RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  �஢�ઠ ��⮢���� ��⮪����-��।��稪� (����⨥ �� ��� ��������)
    if (A1STEPW__V>=420 and A1STEPW__V<422){
        if(!NewSEC){ return; }
        A1PPSTEP_V=420;
        Set_ST1(421);
        // ����� ���⢥ত���� � ��⮢���� � ��९��� � ��⮪����
        // ��।��稪�
        if(A1PPRT<1){
           A1PPRT=Get_RV1(); 
           return;
        }
        Set_ST1(422);
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  ����⨥ �ᯮ���⥫��:
    if (A1STEPW__V>=422 and A1STEPW__V<425){
        if(!NewSEC){ return; }
        A1PPSTEP_V=422;
        // ���� ������� �� ����⨥ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� �����?   [x3.o02 (OxZIPPO) = 1]
        Set_ST1(423);
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZIPPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(161+A1BNM); Bell(1,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���.���
        switch (Check_TO (A1BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        // ��३� �� ᫥���騩 蠣
        Set_ST1(425);
        return;
    }
//  // ----------------------
//  // �������� ������ �� ��-��� ������� ���᪠ ���
    if (A1STEPW__V>=425 and A1STEPW__V<427){
        if(!NewSEC){ return; }
        // �᫨ ��-��� ���襫 �� ०��� �������� � ��㣮� - ������� ��
        // ��������  � ��३� �  ०��  �������� (���⠭���⭠� �����) 
//!!!   if(A1RPPSTEPV<700||A1RPPSTEPV>710){ Set_ST1(50); return; }
        A1PPSTEP_V=425;
        // ����� ���⢥ত���� �� ��� ������� ���᪠ ��� �� ��⮪����
        // ��।��稪�
        if(A1PPRT<2){
           A1PPRT=Get_RV1(); 
           return;
        }
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST1(440); A1RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  � ������ࠫ�
    if (A1STEPW__V>=430 and A1STEPW__V<435){
        if(!NewSEC){ return; }
        // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ쭮�� ��� �����? [x1.i00 (IxZIOPO) = 1]
        Set_ST1(431);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(171+A1BNM); Bell(1,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���ண� ���
        switch (Check_TO (A1BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ���ண� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST1(440); A1RPZD___S=0; A1RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  ��ନ஢���� ������� ��室� ��� ॣ���� "������ ��������"
    if (A1STEPW__V>=440 and A1STEPW__V<445){
        if(!NewSEC){ return; }
        // ��।��塞 ������� ��室� ��� ��� ॣ���� �� ⠡���� 
        // "����� �����������"
        Set_ST1(441);
        //-----------
        // ��� ����� ⥬������� ����� ��஬:
        if(A1NAKPPREM==0){
            // �᫨ ⥪��� � ��⮪���� ����� ��।��� ������� � ⠡���-
            // ��⠭����� ������� ��室� ��� ��� ॣ���� ����� ��������
            if(A1RPZD___S==0){ 
               A1RPZD___M =A11NTOF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=1;
            }
            if(AIT1P____V>=A11NTOP02R  and A1RPZD___S<=2){ 
               A1RPZD___M =A11NTOF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=2;
            }
            if(AIT1P____V>=A11NTOP03R  and A1RPZD___S<=3){ 
               A1RPZD___M =A11NTOF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=3;
            }
            if(AIT1P____V>=A11NTOP04R  and A1RPZD___S<=4){ 
               A1RPZD___M =A11NTOF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=4;
            }
            if(AIT1P____V>=A11NTOP05R  and A1RPZD___S<=5){ 
               A1RPZD___M =A11NTOF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=5;
            }
        } else {
        // ��� ����� ⥬������� ��९�᪭� ��஬:
            if(A1RPZD___S==0){
               A1RPZD___M =A11NTPF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=1;
            }
            if(AIT1P____V>=A11NTPP02R  and A1RPZD___S<=2){
               A1RPZD___M =A11NTPF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=2;
            }
            if(AIT1P____V>=A11NTPP03R  and A1RPZD___S<=3){
               A1RPZD___M =A11NTPF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=3;
            }
            if(AIT1P____V>=A11NTPP04R  and A1RPZD___S<=4){
               A1RPZD___M =A11NTPF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=4;
            }
            if(AIT1P____V>=A11NTPP05R  and A1RPZD___S<=5){
               A1RPZD___M =A11NTPF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=5;
            }
        }
        //-----------
        // �᫨ �������� � ��⮪���� ����� ⮣�, �� ��।�����
        // � ��ࢮ� ��ப� ⠡���� "����� ��������" - ��।��塞 �������
        // ��室�  ��� ��� ॣ���� �� ⠡���� "����� ��������"
        // ��� ����� �������� ����� ��஬:
        if(A1NAKPPREM==0){
            if(AIP1P____V>=A11NPOP01R  and A1RPZD___S<=6){ 
               A1RPZD___M =A11NPOF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=6;
            }
            if(AIP1P____V>=A11NPOP02R  and A1RPZD___S<=7){ 
               A1RPZD___M =A11NPOF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=7;
            }
            if(AIP1P____V>=A11NPOP03R  and A1RPZD___S<=8){ 
               A1RPZD___M =A11NPOF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=8;
            }
            if(AIP1P____V>=A11NPOP04R  and A1RPZD___S<=9){ 
               A1RPZD___M =A11NPOF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=9; 
            }
            if(AIP1P____V>=A11NPOP05R  and A1RPZD___S<=10){ 
               A1RPZD___M =A11NPOF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=10;
            }
            if(AIP1P____V>=A11NPOP06R  and A1RPZD___S<=11){ 
               A1RPZD___M =A11NPOF06R; A1RPZD___V=A1RPZD___M; A1RPZD___S=11;
            }
            if(AIP1P____V>=A11NPOP07R  and A1RPZD___S<=12){ 
               A1RPZD___M =A11NPOF07R; A1RPZD___V=A1RPZD___M; A1RPZD___S=12;
            }
            if(AIP1P____V>=A11NPOP08R  and A1RPZD___S<=13){ 
               A1RPZD___M =A11NPOF08R; A1RPZD___V=A1RPZD___M; A1RPZD___S=13;
            }
            if(AIP1P____V>=A11NPOP09R  and A1RPZD___S<=14){ 
               A1RPZD___M =A11NPOF09R; A1RPZD___V=A1RPZD___M; A1RPZD___S=14;
            }
            if(AIP1P____V>=A11NPOP10R  and A1RPZD___S<=15){ 
               A1RPZD___M =A11NPOF10R; A1RPZD___V=A1RPZD___M; A1RPZD___S=15;
            }
        } else {
        // ��� ����� �������� ��९�᪭� ��஬:
            if(AIP1P____V>=A11NPPP01R  and A1RPZD___S<=6){ 
               A1RPZD___M =A11NPPF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=6;
            }
            if(AIP1P____V>=A11NPPP02R  and A1RPZD___S<=7){ 
               A1RPZD___M =A11NPPF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=7;
            }
            if(AIP1P____V>=A11NPPP03R  and A1RPZD___S<=8){ 
               A1RPZD___M =A11NPPF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=8;
            }
            if(AIP1P____V>=A11NPPP04R  and A1RPZD___S<=9){ 
               A1RPZD___M =A11NPPF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=9;
            }
            if(AIP1P____V>=A11NPPP05R  and A1RPZD___S<=10){ 
               A1RPZD___M =A11NPPF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=10;
            }
            if(AIP1P____V>=A11NPPP06R  and A1RPZD___S<=11){ 
               A1RPZD___M =A11NPPF06R; A1RPZD___V=A1RPZD___M; A1RPZD___S=11;
            }
            if(AIP1P____V>=A11NPPP07R  and A1RPZD___S<=12){ 
               A1RPZD___M =A11NPPF07R; A1RPZD___V=A1RPZD___M; A1RPZD___S=12;
            }
            if(AIP1P____V>=A11NPPP08R  and A1RPZD___S<=13){ 
               A1RPZD___M =A11NPPF08R; A1RPZD___V=A1RPZD___M; A1RPZD___S=13;
            }
            if(AIP1P____V>=A11NPPP09R  and A1RPZD___S<=14){ 
               A1RPZD___M =A11NPPF09R; A1RPZD___V=A1RPZD___M; A1RPZD___S=14;
            }
            if(AIP1P____V>=A11NPPP10R  and A1RPZD___S<=15){ 
               A1RPZD___M =A11NPPF10R; A1RPZD___V=A1RPZD___M; A1RPZD___S=15;
            }
        }
        //-----------
        // �᫨ ��⮪��� � ०��� ����� �������� ��९�᪭�  ��஬ �
        // �᫨ ࠧ��� �������� ����� ��-��।��稪�� � ��-�ਥ������
        // ����� ��������� (AxZPPRE__R) -��३� �� 蠣
        // ������� �ᯮ���⥫�� ����� ��९�᪭��� ��� � �ନ஢����
        // ������� ��室� ��� ॣ���� "������ ��������" �� ���஬� ����
        A1PPSTEP_V=440; Get_RV1();
        if(A1NAKPPREM>0 and AIPRP1___V-AIP1P____V < A1ZPPRE__R){
           Set_ST1(480); A1PPRT=0; return;
        }

        //-----------
        // �᫨ �������� � ��⮪���� ����� ��������� � "���������� �����"-
        // ��३� �� 蠣 ������� �ᯮ���⥫�� ������ࠫ쭮�� ���
        if(A1NAKPPREM==0 and A1PPP____R>0 and AIP1P____V>=A1PPP____R){
           if(A1TEMP <7){ 
              A1TEMP++;     
           } else { 
              Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); 
              Set_ST1 (450); 
           }
           return;
        } else {
           A1TEMP=0;
        }
        //-----------
        // �᫨ ����� �������� ���� � ������ࠫ� � �������� � ��⮪���� 
        // �����,祬 �������� � ������ࠫ�- ������� �������� ���᪠ ���� ���
        if(A1NAKPPREM==0 and AIP1P____V>=AIP12M___V){
           Set_ST1(442);
           // ���� ������� �� �����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // �᫨ ��९�� �������� ����� �� � ������ࠫ�� �⠡�����஢����
        if(A1NAKPPREM==0 and AIP1P____V< AIP12M___V-A1ZNPM___R){
           Set_ST1(443);
           // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS1(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ࠫ쭮�� ��� � ���室 �� "��������"
    if (A1STEPW__V>=450 and A1STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A1BTM+2, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(128+A1BNM); Bell(1,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(440); Set_ST1(500);
        A1PPP___YM=OFF;  A1PPP___YV=A1PPP___YM;  
        // ᮮ�饭�� �� ����砭�� ०���
        Message(202+A1BNM);
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ��९�᪭��� ��� �� ��-���
    if (A1STEPW__V>=480 and A1STEPW__V<482){
        if(!NewSEC){ return; }
        A1PPSTEP_V=480;
        Set_ST1(481);
        // ����� ���⢥ত���� � �����⨨ �ᯮ���⥫�� ���᪠ ��� ��
        // ��⮪���� ��।��稪�
        if(A1PPRT<3){
           A1PPRT=Get_RV1(); return;
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(482);
        return;
    }
//  // ----------------------
    if (A1STEPW__V>=482 and A1STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST1(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� ������?
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(142+A1BNM); Bell(1,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A1BTM+2, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(128+A1BNM); Bell(1,1); return; }
        }
        // �� �����⨨ ���  �ᯮ���⥫�� ��९�᪭��� ���, �����頥���
        // �� �ନ஢���� ������� ��室� ��� ॣ���� ������ ��������
        // �� ���஬� ����
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(440);
        A1NAKPPREM=0; A1RPZD___S=0; A1RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  ����� "��������"
//  // ----------------------------------------------------------------------
    if ((A1STEPW__V==500)||(A1STEPW__V>510&&A1STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST1(500);
        // �᫨ � 横� �� ����祭 ०�� "��������"- ��३� �� � ०��
        if(A1PVID__YV==OFF){ Set_BV1(500); Set_ST1(600); return; }
        A1PPSTEP_V=500;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V==500){ Message(203+A1BNM); }
        // �뤥প� ��⮪���� ��� ��������� �஢������ ������ࠫ�� ��஬
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST1(511);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(512);
        // ������ ���᪠ ��� ������?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A1BTM+2, A1RPHKF__R, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(169+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(513);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(514);
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(515);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(516);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A1BTM+6, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(142+A1BNM); Bell(1,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6);
        A1STEPZ__V=0; A1STEPC__V=0;
        //
        Set_ST1(501);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A1TEMP=0.3;
        A1RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A1STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST1(501);
        //-----------
        // �᫨ �������� � ��⮪���� ����� ���������-
        // ��३� ��  蠣 ������� ������� ���᪠ ���
        if(AIP1P____V>=A1PPP____R){
           Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=0; 
           return;
        }
        //-----------
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ��३� �� 蠣 ������� �������� � ������� ���᪠ ���ண� ���
        if(AIP1P____V> A1ZPAKX__R or AIP1P____V>AIP12M___V){
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=1;
           return;
        }
        //-----------
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A1STEPH__V>=A1PVIDH__R and A1STEPM__V>=A1PVIDM__R){
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=2;
           return;
        }
        //-----------

        //-----------
        // �뤥প� ��⮪���� ��� ���������  �஢������ ������ࠫ�� ��஬
        // ������  ��������  ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� �����?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPO__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(171+A1BNM); Bell(1,1); return; }
        }
        //-----------
        // ����  ������� �  �������� ���᪠  ���ண� ���  �
        // �뤠�� ������� �� ����⨥ ������� ���᪠  ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A1BTM+3]==0) Set_IS1(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A1BTM+3]==1) Set_IS1(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ����� A1TEMP %  ᥪ㭤 �� �������  室� ������� ���᪠ ���
        // ��� ���� �� �ࠡ�⠥� ���楢�� ������ �������
        if(I1KIPO___V<1){
           switch ( Check_TO(A1BTM+2,A1RPHKF__R*A1TEMP,ZERO,'=',ON, 1)){
               case RUN: { A1STEPZ__V=A1RPHKF__R*A1TEMP; A1STEPC__V=CNTTO[A1BTM+2]; 
                           return; 
                         }
           }
        }
        // ���� ������� � ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // ����প� 30 ᥪ㭤
        switch ( Check_TO(A1BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=30; A1STEPC__V=CNTTO[A1BTM+3]; return; }
        }
        if(AIP1P____V< A1PPP____R){
        // �᫨ �������� � ��⮪���� �� ����﫮�� �� ��������� � ������
        // ����� �� ���������- 㢥����� �६� ������ ������� � �������
        // ⥪�騩 蠣 
        //(��ਭ樯�,⠪ ����� ���뢠�� ������ ����� ������ +0.3,+0.3...)
           if(A1TEMP<0.8){
              A1TEMP=0.3;
              Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
              A1STEPZ__V=0; A1STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A1STEPW__V>=502 and A1STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST1(502);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A1TEMP=0.3;
        // �᫨ ⥪�饥 �������� � ��⮪���� ����� ���������-
        // ��३� ����� ��  蠣 ������  �������� � ������� ���᪠ ���
        if(AIP1P____V<A1PPP____R-A1ZNVD___R and 
           AIP1P____V<AIP12M___V-A1ZNPM___R and A1FLAG<2){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(501); return;
        }
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ������� �������� ���᪠ ���ண� ���
        if(AIP1P____V> A1ZPAKX__R or AIP1P____V>AIP12M___V){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); 
           A1STEPZ__V=0; A1STEPC__V=0; A1FLAG=1;
        }
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A1STEPH__V>=A1PVIDH__R and A1STEPM__V>=A1PVIDM__R){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); 
           A1STEPZ__V=0; A1STEPC__V=0; A1FLAG=2;
        }
        // �᫨ �� ����஫� ���ᨬ��쭮 �����⨬��� �������� ��� ࠧ���� ���
        // ��室 �� ०��� - ������� �������� ���᪠ ���ண� ���
        if(A1FLAG>0){
          // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // �������� ���᪠ ���ண� ��� ������?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A1BTM+5, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(141+A1BNM); Bell(1,1); return; }
          }
        }
        // ���� ������� �� �����⨥ ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢����  ���� ������� ���᪠ ���       [x1.i05 (IxKIPC_) = 1]
        // ������ ���᪠ ��� ������?            
        switch ( Check_TO(A1BTM+4, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,  1 )){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(170+A1BNM); Bell(1,1); return; }
        }
        // �᫨ �� ��⠭����� 䫠� ��室�- ��३� �� ०�� "����� ��������"
        if(A1FLAG==2){ 
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_BV1(502); Set_ST1(600);
           A1PVID__YM=OFF;  A1PVID__YV=A1PVID__YM;
           // ᮮ�饭�� �� ����砭�� ०���
           Message(204+A1BNM);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  ����� "����� ��������"
    // ----------------------------------------------------------------------
    if ((A1STEPW__V==600)||(A1STEPW__V>610&&A1STEPW__V<620)){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� ���.०��
        if(A1SP____YV==OFF){ Set_BV1(600); Set_ST1(50); return; }
        // �஢�ઠ ������ �������� ��㣨� ��⮪�����
        // (�� ������ �������� ����� ��室���� ������ ���� ��⮪���)
        if(A2PPSTEP_V==600||A3PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV1(600); Set_ST1(50); Message(110+A1BNM); return;
        }
        A1PPSTEP_V=600;
        // ᮮ�饭�� � ��砫� ०���
        if(A1STEPW__V==600){ Message(205+A1BNM); }
        //
        A1RPRA___M=ON;
        //-----------
        // ��।������ ��ࢮ��砫쭮�� ��業� ������ ������� ��� ���
        A1FLAG=0; A1FLGP=0; if(A1TKLO___R==0) A1TKLO___R=100;
        A1FLAG=5; A1TEMP=A11SPKK05R; 
        if(A1SPAT___R>0) A1TEMP=A11SPAK05R; if(A1TEMP==0) A1TEMP=20;
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A1SPAT___R>0){ A1TEMP=A1TKLO___R*0.01*A1TEMP; }
        // �᫨ ��।���� ��� ��� � �������
        else            { A1TEMP=A1TKLO___R*0.01*A1TEMP; }
        // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
        if(A1SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST1(611);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(613);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(615);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(616);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A1BTM+6, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(142+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(617);
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(618);
        // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
        // �⬮����
        if(A1SPAT___R>0){
          // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
          // �⬮����
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A1BTM+8, A1TZSPA__R* SEC, I1ZOPAO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+8]; return; }
            case BAD: { Clear_TO(A1BTM+8); Message(173+A1BNM); Bell(1,1); return; }
          }
        }
        Clear_TO(A1BTM+1);  Clear_TO(A1BTM+2);  Clear_TO(A1BTM+3);  
        Clear_TO(A1BTM+4);  Clear_TO(A1BTM+5);  Clear_TO(A1BTM+6);  
        Clear_TO(A1BTM+7);  Clear_TO(A1BTM+8);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(602);
        return;
    }
//  // ----------------------
//  //  ��� ��� �� ⠡���
    if (A1STEPW__V>=602 and A1STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST1(602);
        // ��᢮��� ��६����� ��業�(�६� � ᥪ㭤��) ������ ������� 
        // (�� �������  �६��� 室� �������) �� ⠡���  ᮮ⢥��⢥���
        // ⥪�饣� ��������  � ��⮪����
        // ⠡��� ��ᬠ�ਢ����� �� ����襣� � ����襬� (᭨�� �����)
        // ��� ������ �� �।��騩 蠣

        // �᫨ ⥪�饥 �������� �����-1 ��� ⥪�饥 ��������
        // ����� ��᫥����� 㪠������� � ⠡��� "����� ��������"(᭨��-�����)
        // ��� ࠧ�����஢�� ���� �� ���- ��३� �� ᫥� ०��
        if(AIP1P____V<-1 or A1FLAG==1 or I1SBP1R__V>0  or I1SBP2R__V>0){
           Set_ST1(605); Clear_TO(A1BTM+2); A1STEPZ__V=0; A1STEPC__V=0; A1FLGP=0;
           return;
        }
        
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A1SPAT___R>0){
           Set_ST1(603);
           if(AIP1P____V<A11SPAP04R and A1FLAG>=5){
              // ��⠥��� ࠧ��� ��業� ������ ������� ����� 
              // �।��騬 � ⥪�騬 蠣��
              A1TEMP=A1TKLO___R*0.01*(A11SPAK04R-A11SPAK05R); A1FLAG=4;
           }
           if(AIP1P____V<A11SPAP03R and A1FLAG>=4){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK03R-A11SPAK04R); A1FLAG=3;
           }
           if(AIP1P____V<A11SPAP02R and A1FLAG>=3){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK02R-A11SPAK03R); A1FLAG=2;
           }
           if(AIP1P____V<A11SPAP01R and A1FLAG>=2){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK01R-A11SPAK02R); A1FLAG=1;
           }
        } else {
           Set_ST1(604);
        // �᫨ ��࠭ ��� ��� � �������
           if(AIP1P____V<A11SPKP04R and A1FLAG>=5){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK04R-A11SPKK05R); A1FLAG=4;
           }
           if(AIP1P____V<A11SPKP03R and A1FLAG>=4){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK03R-A11SPKK04R); A1FLAG=3;
           }
           if(AIP1P____V<A11SPKP02R and A1FLAG>=3){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK02R-A11SPKK03R); A1FLAG=2;
           }
           if(AIP1P____V<A11SPKP01R and A1FLAG>=2){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK01R-A11SPKK02R); A1FLAG=1;
           }
        }
        // �᫨ �� ���室 �� ���� 蠣
        if(A1FLGP!=A1FLAG){
           // �᫨ ���祭�� A1TEMP > 0 - ���뢠�� ������ ���᪠ ���,
           // ���� - ����뢠��
           if(A1TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // �������� ���祭��
           A1TEMP=fabs(A1TEMP);  
           A1FLGP=A1FLAG;
           // ���㫨�� ⠩��� � ���稪� ��� ��ࠡ�⪨ ����� ���祭��
           Clear_TO(A1BTM+1); A1STEPZ__V=0;  A1STEPC__V=0;
        }
        // ��⠥� �६� �������⢨� ᨣ���� �� ������
        switch ( Check_TO(A1BTM+1, A1TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TEMP; A1STEPC__V=CNTTO[A1BTM+1]; return; }
        }
        // ��᫥ ��ࠡ�⪨ ⠩���- ���� ᨣ���� � �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  ����ୠ� �஢�ઠ � ��室 �� ⥪�饣� ०��� � ०�� "��������"
    if (A1STEPW__V>=605 and A1STEPW__V<607){
        if(!NewSEC){ return; }
        // �᫨ ⥪�饥  �������� ����� ��� ࠢ��  ��� 
        // ���  ����襬� ���祭�� � ⠡���- 㢥��� ���稪
        if(AIP1P____V<=0 or A1FLAG==1 or I1SBP1R__V>0  or I1SBP2R__V>0){
           A1FLGP++; 
        // ���� - 㬥�����
        } else { 
           A1FLGP--; 
        }
        // 10 ᥪ �������� 
        switch ( Check_TO(A1BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // �᫨ ���稪 ������⥫�� - 
        // ��३� �� 蠣 ������� �ᯮ���⥫��
        if(A1FLGP>2){
           Set_ST1(607); Clear_TO(A1BTM+1);
        } else {
        // �᫨ ���稪 ����⥫�� - �������� �� ����� ��������
           Set_ST1(603); A1FLGP=A1FLAG;
        }; Clear_TO(A1BTM+2); A1STEPZ__V =0; A1STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ �������� � ��室 �� ०���
    if (A1STEPW__V>=607 and A1STEPW__V<609){
        if(!NewSEC){ return; }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ��� ��� � �⬮����
        switch ( Check_TO(A1BTM+1, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(144+A1BNM); Bell(1,1); return; }
        }
        // �஢�ઠ ������� ������� ���᪠ ���
        switch ( Check_TO(A1BTM+2, A1TKLO___R* SEC, I1KOPC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(139+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(602); Set_ST1(50);
        A1SP____YM=OFF; A1SP____YV=A1SP____YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(206+A1BNM);
        return;
    }
//  // ----------------------







    //  ����� "�������� ��������"
    //  �᫨ ��⮪��� ���� �� ��ॡ��, ������ �� �⠢�� � ���� ������
    //  "����� ��������".  ����� ��᫥ "��������" ��⮪��� ���室�� � ०��
    //  "��������". � �⮬ ०��� �� ����� ��室���� ᪮�� 㣮��� �����.
    //  � ��� ������ ������ ����� �ࠢ���� ��⮪����� ������ ��� � ��.
    //  �� ��� ࠡ��� � ०��� "��������" ��⮪��� ������ ��室���� � ०���
    //  �� � ������묨 ���������� � ���������.
    //  ��� ⮫쪮 ��襫  ����� �� ��ॡ�� � �⮣� ��⮪���� - ��⮪���
    //  ���室�� � ०�� "��������"
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=700 and A1STEPW__V<702){
        if(!NewSEC){ return; }
        A1RPRA___M=ON;
        // ������ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������ �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZOPPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(179+A1BNM); Bell(1,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A1PPSTEP_V=700;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0;  A1STEPC__V=0;
        Set_ST1(702);
        return;
    }
//  // ----------------------
//  //  ����⨥ ������� ���᪠ ���
    if (A1STEPW__V>=702 and A1STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA1(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A1IPPSTEPV>=400&&A1IPPSTEPV<500){
           // ������� ������ �������� �� ��-��
           if(A1IPPSTEPV!=425){ return; }
        } else {
        // �᫨ ��-�� ���襫 �� ०��� ������ �������� � ��㣮� ०��-
        // ��३�  �� �����⨥ �ᯮ���⥫�� (���⠭���⭠� �����)
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(704); return;
        }
        // ������ ������ ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // �஢�ઠ ������ ������� ���᪠ ���
        switch ( Check_TO(A1BTM+1, A1TKLO___R* SEC, I1KOPO___V,'=',ON, 2 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(181+A1BNM); Bell(1,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A1PPSTEP_V=704;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A1BTM+1);  Clear_TO(A1BTM+2);
        A1STEPZ__V=0;  A1STEPC__V=0;
        Set_ST1(704);
        return;
    }
//  // ----------------------
//  // �����⨥ �ᯮ���⥫�� ���᪠ ��९�᪭��� ���
    if (A1STEPW__V>=704 and A1STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA1(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A1IPPSTEPV>=400&&A1IPPSTEPV<500){
           // ������� ���� ��-�� �� ������ �㦭��� �������� � ��
           // ��३���  �� 蠣 ������� �ᯮ���⥫��
           if(A1IPPSTEPV!=480){ return; }
           // �᫨ ��-���樠�� �襫 �� ०��� ����� ��������- ����뢠��
           // �ᯮ���⥫� � ���室�� � ०��  ��������
           //(���⠭���⭠� �����)
        }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(143+A1BNM); Bell(1,1); return; }
        }
        // ������� ������ ���᪠ ���
        switch ( Check_TO(A1BTM+2, A1TKLO___R* SEC, I1KOPC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(139+A1BNM); Bell(1,1); return; }
        }
        // ��᫥ ������� ��⠭����� 䫠� ���⢥ত���� ������� �ᯮ���⥫��
        A1PPSTEP_V=705;
        // ��᫥ ����砭�� ��९�᪠ ��� ��⮪��� ��४��砥��� � ०��
        // "����� ��������"
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(704); Set_ST1(600);
        // �᫨ ��-�� �� � ०��� ������ �������� (���⠭���⭠� �����)
        // ��ॢ��� ��� �� � ०�� ��������
        if(A1IPPSTEPV<400||A1IPPSTEPV>500){ Set_ST1(50); }
        A1SP____YM=OFF; A1SP____YV=ON;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(207+A1BNM);
        return;
    }
//  // ----------------------------------------------------------------------


    return;
}
//---------------------------------------------------------------------------
