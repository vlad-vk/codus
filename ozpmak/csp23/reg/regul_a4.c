//---------------------------------------------------------------------------

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V4GNS1BS_V = 0;           // ���ﭨ� ������ ����祭�� ���஭���

_f  far  I4KR_TMP_V = 0;           // ⥪�� ����஫ ���祭�� ��࠭  ���誨
_f  far  I4KR1CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠1
_f  far  I4KR1OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠1

_f  far  A4TVACUM_R = 6000;        // �६� ����㬨஢���� (100 �����)
_f  far  I4MAXVCN_V = 0;           // ���稪 �ॢ�襭�� ���� ࠧ०����
_f  far  O4ZOPPO__Y = 0;           // ᨣ��� ��� ���� ���� ��� �� �� ��।��
_f  far  I4ZOPPO__Y = 0;           //
_f  far  A4RPZD___S = 0;           // 蠣 ������� ॣ���� "������ ��������"
_f  far  A4ISPST__C = 0;           // ���稪 ��஫� ��।������ 蠣�
_f  far  A4FLAG=0;                 // �������⥫�� ��६����
_f  far  A4FLGP=0;                 //
_f  far  A4TEMP=0;                 //
_f  far  A4PPRT=0;                 // ������ �� �㭪権 ��।������ 蠣� ���
_f  far  A4SBPT=0;                 // ���稪 ࠧ�����஢�� ���
_f  far  A4SBPC=0;                 // ���稪 �����஢�� ���
_f  far  A4SBPI=0;                 // ���稪 ������� �ᯮ���⥫�� ��� ���
_f  far  A4CISP=0;                 // ���稪 ����஫� ���ﭨ� �ᯮ���⥫��


//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ �������� � �������� ��4
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS4(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  ���ண� ���
    if (i1==  ON){ O4ZIOPO__M= ON; O4ZIOPC__M=OFF; }   //  ������
    if (i1== OFF){ O4ZIOPO__M=OFF; O4ZIOPC__M= ON; }   //  �������
    if (i1==STOP){ O4ZIOPO__M=OFF; O4ZIOPC__M=OFF; }   //  ��⠭�����
    // ��९�᪭��� ��� �室�饣�
    if (i2==  ON){ O4ZIPPO__M= ON; O4ZIPPC__M=OFF; }
    if (i2== OFF){ O4ZIPPO__M=OFF; O4ZIPPC__M= ON; }
    if (i2==STOP){ O4ZIPPO__M=OFF; O4ZIPPC__M=OFF; }
    // ��९�᪭��� ��� ��室�饣�
    if (i3==  ON){ O4ZOPPO__M= ON; O4ZOPPC__M=OFF; }
    if (i3== OFF){ O4ZOPPO__M=OFF; O4ZOPPC__M= ON; }
    if (i3==STOP){ O4ZOPPO__M=OFF; O4ZOPPC__M=OFF; }
    // ��� � �⬮����
    if (i4==  ON){ O4ZOPAO__M= ON; O4ZOPAC__M=OFF; }
    if (i4== OFF){ O4ZOPAO__M=OFF; O4ZOPAC__M= ON; }
    if (i4==STOP){ O4ZOPAO__M=OFF; O4ZOPAC__M=OFF; }
    // ����㬭�� ��������
    if (i5==  ON){ O4VZO____M= ON; O4VZC____M=OFF; }
    if (i5== OFF){ O4VZO____M=OFF; O4VZC____M= ON; }
    if (i5==STOP){ O4VZO____M=OFF; O4VZC____M=OFF; }
    // ������ ���᪠ ���
    if (i6==  ON){ O4KIPO___M= ON; O4KIPO___V= ON; O4KIPC___M=OFF; O4KIPC___V=OFF; }
    if (i6== OFF){ O4KIPO___M=OFF; O4KIPO___V=OFF; O4KIPC___M= ON; O4KIPC___V= ON; }
    if (i6==STOP){ O4KIPO___M=OFF; O4KIPO___V=OFF; O4KIPC___M=OFF; O4KIPC___V=OFF; }
    // ������ ���᪠ ���
    if (i7==  ON){ O4KOPO___M= ON; O4KOPO___V= ON; O4KOPC___M=OFF; O4KOPC___V=OFF; }
    if (i7== OFF){ O4KOPO___M=OFF; O4KOPO___V=OFF; O4KOPC___M= ON; O4KOPC___V= ON; }
    if (i7==STOP){ O4KOPO___M=OFF; O4KOPO___V=OFF; O4KOPC___M=OFF; O4KOPC___V=OFF; }
    // ������ ��� ��������
    if (i8==  ON){ O4KOCO___M= ON; O4KOCO___V= ON; O4KOCC___M=OFF; O4KOCC___V=OFF; }
    if (i8== OFF){ O4KOCO___M=OFF; O4KOCO___V=OFF; O4KOCC___M= ON; O4KOCC___V= ON; }
    if (i8==STOP){ O4KOCO___M=OFF; O4KOCO___V=OFF; O4KOCC___M=OFF; O4KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ ���襪 ��5
//              NUM       BY        HM        KR 
vd  far Set_KR4(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // �������
       if (b==  ON){ O4BY1O___M= ON; O4BY1C___M=OFF; }   //  ������
       if (b== OFF){ O4BY1O___M=OFF; O4BY1C___M= ON; }   //  �������
       if (b==STOP){ O4BY1O___M=OFF; O4BY1C___M=OFF; }   //  ��⠭�����
       // 宬��
       if (h==  ON){ O4HM1UP__M= ON; O4HM1DN__M=OFF; }
       if (h== OFF){ O4HM1UP__M=OFF; O4HM1DN__M= ON; }
       if (h==STOP){ O4HM1UP__M=OFF; O4HM1DN__M=OFF; }
       // ���誠
       if (k==  ON){ O4KR1O___M= ON; O4KR1C___M=OFF; }
       if (k== OFF){ O4KR1O___M=OFF; O4KR1C___M= ON; }
       if (k==STOP){ O4KR1O___M=OFF; O4KR1C___M=OFF; }
    }
    if(n==2){
       // �������
       if (b==  ON){ O4BY2O___M= ON; O4BY2C___M=OFF; }
       if (b== OFF){ O4BY2O___M=OFF; O4BY2C___M= ON; }
       if (b==STOP){ O4BY2O___M=OFF; O4BY2C___M=OFF; }
       // 宬��
       if (h==  ON){ O4HM2UP__M= ON; O4HM2DN__M=OFF; }
       if (h== OFF){ O4HM2UP__M=OFF; O4HM2DN__M= ON; }
       if (h==STOP){ O4HM2UP__M=OFF; O4HM2DN__M=OFF; }
       // ���誠
       if (k==  ON){ O4KR2O___M= ON; O4KR2C___M=OFF; }
       if (k== OFF){ O4KR2O___M=OFF; O4KR2C___M= ON; }
       if (k==STOP){ O4KR2O___M=OFF; O4KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// ���⪠ ��� ⠩��஢ � ���稪�
vd  far Clear_TA4(vd){
    Clear_TO(A4BTM+ 1); Clear_TO(A4BTM+ 2); 
    Clear_TO(A4BTM+ 3); Clear_TO(A4BTM+ 4); 
    Clear_TO(A4BTM+ 5); Clear_TO(A4BTM+ 6);
    Clear_TO(A4BTM+ 7); Clear_TO(A4BTM+ 8); 
    Clear_TO(A4BTM+ 9); Clear_TO(A4BTM+10);
    Clear_TO(A4BTM+11); Clear_TO(A4BTM+12);
    Clear_TO(A4BTM+13); Clear_TO(A4BTM+14);
    Clear_TO(A4BTM+15); Clear_TO(A4BTM+16);
    Clear_TO(A4BTM+17); Clear_TO(A4BTM+18);
    Clear_TO(A4BTM+19);
    A4STEPZ__V=0; A4STEPC__V=0;
}
//---------------------------------------------------------------------------
//  ��⠭���� ��砫��� ���祭�� �� ᬥ�� ०��� ࠡ��� ��⮪����
vd  far Set_BV4(_f far A4STEPWPRV){
    // ��������� ����� �।��饣� 蠣�
    A4STEPP__V =A4STEP___V;
    A4STEPWP_V =A4STEPWPRV;
    // �����  䫠�� ��஫��
    A4CYCRN__V =OFF; A4CYCRN__M=OFF;
    A4CYCST__V =OFF; A4CYCST__M=OFF;
    A4ISPST__V =OFF; A4ISPST__M=OFF;
    // ���㫨�� ���稪� ०���� � ⠩��஢
    A4STEPH__V =0;   A4STEPM__V=0; A4STEPS__V=0; 
    // ����� 䫠�� �롮� ���襪 ��� ������ � �������
    I4KR1OBS_V =0;
    I4KR1CBS_V =0;
    I4KR_TMP_V=-1;
    // ���� ������� � ��� �ᯮ���⥫�� ���襪
    Set_KR4(1,STOP,STOP,STOP);
    Set_KR4(2,STOP,STOP,STOP);
    //  ���㫥��� ���祭�� ⠩��஢
    Clear_TA4();
    // ���� ������� �� 宬���
    O4HM1UP__M=OFF; O4HM1DN__M=OFF;
    O4HM2UP__M=OFF; O4HM2DN__M=OFF;
    // ���� ������� �� ��������
    O4BY1O___M=OFF; O4BY1C___M=OFF;
    O4BY2O___M=OFF; O4BY2C___M=OFF;
    // ���� ������� �� ���誨
    O4KR1O___M=OFF; O4KR1C___M=OFF;
    O4KR2O___M=OFF; O4KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  ��⠭���� ⥪�饣� 蠣� ०��� ࠡ��� ��⮪����
vd  far Set_ST4(int SS){
    A4STEPW__V=SS;
    A4STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  ����祭�� ���祭�� �� ��६����� 㤠������ ����஫��஢
//  A3PPSTEP_V - ����� 蠣� �ணࠬ�� ⥪�� ��
//  A3RPPSTEPV - �ਭ������� � ��-��� ���祭��,ᨣ���������饥 � �믮������ ��
//               ��-��� ⥪�饣� 蠣�
_f  far Get_RV4(vd){
    // �᫨ ��࠭ ����� 0- ����� ��� �������� � ������ࠫ�
    if(A4NAKPPREM==0){ return(0); }
    A4RPPSTEPV=0;
    if(A4NAKPPREM==1){ A4RPPSTEPV=A1PPSTEP_V; AIPRP4___V=AIP1P____V; }
    if(A4NAKPPREM==2){ A4RPPSTEPV=A2PPSTEP_V; AIPRP4___V=AIP2P____V; }
    if(A4NAKPPREM==3){ A4RPPSTEPV=A3PPSTEP_V; AIPRP4___V=AIP3P____V; }
    if(A4NAKPPREM==5){ A4RPPSTEPV=A5PPSTEP_V; AIPRP4___V=AIP5P____V; }
    if(A4NAKPPREM==6){ A4RPPSTEPV=A6PPSTEP_V; AIPRP4___V=AIP6P____V; }
    if(A4RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // �᫨ ⥪�騩 �� ��室���� � ०��� ������ ���.��஬
    if(A4PPSTEP_V==420){
       // �᫨ ��-��� ���襫 � ०�� ��������� � ���� �������� �� ���.���
       if(A4RPPSTEPV==700) return(1); return(0);
    }
    // ⥪�騩 �� ������� ������ ������� �� ���.��� �� ��-���
    if(A4PPSTEP_V==425){
       if(A4RPPSTEPV==704) return(2); return(0);
    }
    // ⥪�騩 �� ������� ������� �ᯮ���⥫�� ���᪠ ��� �� ��-���
    if(A4PPSTEP_V==480){
       // �᫨ �� ��-��� �ᯮ���⥫� ����뫨��
       if(A4RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  ����祭�� ⥪�饣� 蠣� ��-���樠�� (��-��) �� �⤠� ���
_f  far Get_RA4(int mode){
    // �஢���� �� ��㣨� ��⮪���� �� ��室���� � ०��� ��ॡ��
    // ��।����� �� ���ﭨ� ��९�᪭�� �������� (����,����)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A2PPSTEP_V>=700 or 
          A3PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // ��।����� ����� ��, ����� ����訢��� ⥪�騩 ��� �⤠� ���
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==4){ A4IPPNUM_V=1; return(1); }
       if(A2PPSTEP_V==420 and A2NAKPP__R==4){ A4IPPNUM_V=2; return(2); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==4){ A4IPPNUM_V=3; return(3); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==4){ A4IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==4){ A4IPPNUM_V=6; return(6); }
       return(0);
    }
    // ��।����� ⥪�騩 蠣 �� ��-���樠�� (��-��)
    if(mode==2){
       if(A4IPPNUM_V==1){ A4IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A4IPPNUM_V==2){ A4IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A4IPPNUM_V==3){ A4IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A4IPPNUM_V==5){ A4IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A4IPPNUM_V==6){ A4IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �����஢�� ���
int Chk_SBP4(vd){
    //-------------------------------------------
    // �᫨ �ணࠬ�� �� �� 蠣� ࠡ��� � ���誠��
    if(A4STEPW__V<100||(A4STEPW__V>290&&A4STEPW__V<800)||A4STEPW__V>890){
      // �᫨ ࠧ�����஢��� ��� - �뤠�� ������� �� �����⨥
      // ��� �������� � ��३� � ०�� ��������
      if(I4SBP1R__V>0){
        // c����� ���稪 �����஢�� ��� (���� �� �ॡ����)
        A4SBPC=0;
        // �᫨ �� ������ ��� ���� �� �஢��塞�� �ᯮ���⥫��
        if(I4ZIOPC__V!=ON|| I4ZIPPC__V!=ON||I4ZOPPC__V!=ON||I4ZOPAC__V!=ON||
           I4VZC____V!=ON||(I4KOCC___V!=ON&&(A4STEPP__V==3||A4STEP___V==3))){
////��� ��������������.���-�� �������.        
           // c����� ���稪 �⠡��쭮�� ���ﭨ� ������� �ᯮ���⥫��
           A4SBPI=0;
           //-----------
           // �᫨ �ணࠬ� � ��諠 � 蠣� �����, 祬 910(��㣮� ०��)
           if(A4STEPW__V<910){
              // 㢥����� ���稪 �ࠡ�⪨ ��� (��⠥� 5ᥪ) � ���
              if(A4SBPT <5){ A4SBPT++; return(1); }
              // ��᫥���� ࠧ ��᫥ �஢�ન ���稪� ��। �஢�મ�
              // �ᯮ���⥫��- ���㫨�� ���稪� � ⠩���� (����� ��諮 5ᥪ)
              A4STEPZ__V=0; A4STEPC__V=0; Set_BV4(A4STEPW__V);
              Message(107+A4BNM,0);
           }
           //-----------
           // ��⠭����� ०�� ������� �ᯮ���⥫�� �� ࠧ�����஢�� ���
           Set_ST4(910);
           // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // �������� ���᪠ ���ண� ��� ������?
           Set_ST4(911);
           switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return(1); }
             case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������? 
           Set_ST4(912);
           switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return(1); }
             case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM,0); Bell(4,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������?
           Set_ST4(913);
           switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return(1); }
             case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM,0); Bell(4,1); return(1); }
           }
           // �������� ���᪠ ��� � �⬮���� ������?
           Set_ST4(914);
           switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return(1); }
             case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM,0); Bell(4,1); return(1); }
           }
           // �������� ����㬠 ������?
           Set_ST4(915);
           switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return(1); }
             case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM,0); Bell(4,1); return(1); }
           }
           // �᫨ ��� �뫮 ࠧ�����஢��� � ०��� ��������������
           if(A4STEPP__V==3){
           // ������ ���᪠ �������� ������?
           Set_ST4(916);
           switch ( Check_TO(A4BTM+6, A4RCHKF__R* SEC, I4KOCC___V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4RCHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return(1); }
             case BAD: { Clear_TO(A4BTM+6); Message(146+A4BNM,0); Bell(4,1); return(1); }
           } }
           // �᫨ �� ������- ��३� � ०�� �������� ࠧ�����஢�� ���
           Set_ST4(917); return(1);
        } else {
////��� ��������������.��� �������.        
           // �᫨ �� �஢��塞� �ᯮ���⥫� �������- 㬥����� ���稪 �
           // ����� �� 蠣� 900, ���� ����������� ���
           if(A4SBPI<5){ A4SBPI++; return(1); }
           // ��᫥ ���稪� �⠡��쭮�� ������� �ᯮ���⥫��-
           // ����� ���稪 ��������  ������� �ᯮ���⥫��
           A4SBPT=0;
           // �᫨ ࠧ�����஢��� ��� � �����-� ०���,�� �� �ᯮ���⥫�
           // �������- �뤠�� ᮮ�饭�� � 㪠������ ०��� �� ���஬ 
           // �������஢��� ���
           if(A4STEPW__V<900){ Set_BV4(A4STEPW__V); Message(106+A4BNM,0); }
           // �᫨ �ᯮ���⥫� �뫨 ������� ��᫥ ࠧ�����஢�� ���-
           // �뤠�� ᮮ�饭�� � ⮬, �� �ᯮ���⥫� ����뫨
           if(A4STEPW__V>900){ Message(108+A4BNM,0); }
           Set_ST4(900);
        }
      } else {
////��� �������������.
        // �᫨ ��� �������஢��� � ��᫥���� �믮��塞� 蠣 �� �����⨥
        // �������� �� ࠧ�����஢�� ���
        if(A4STEPW__V>=900){
           // ������� 5ᥪ �⠡��쭮� �����஢�� ���
           if(A4SBPC<5){ A4SBPC++; return(1); }
           // ��३� � ०�� ��������
           Message(109+A4BNM,0); Set_BV4(910); Set_ST4(50); return(1);
        }
        // ����� ��� �������஢���- ����� ���稪� �����஢�� ��� � ���
        A4SBPT=0;
        A4SBPC=0;
        A4SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �ᯮ���⥫�� �� ࠡ�� � ���誠��
int Chk_IF4(int mode){
    // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
    if(I4ZIOPC__V!=ON){ Message(141+A4BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
    if(I4ZIPPC__V!=ON){ Message(142+A4BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
    if(I4ZOPPC__V!=ON){ Message(143+A4BNM,0); return(0); }
    // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
    if(I4ZOPAC__V!=ON){ Message(144+A4BNM,0); return(0); }
    // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
    if(I4VZC____V!=ON){ Message(145+A4BNM,0); return(0); }
    // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
    if(I4KOCC___V!=ON){ Message(146+A4BNM,0); return(0); }
    // ��� ࠧ�����஢��?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I4SBP1R__V==0){ Message(149+A4BNM,0); return(0); }
    }
    // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I4P1_N___V==0){ Message(156+A4BNM,0); return(0); }
    }
    // ���� ����殮��� �� �� �ࠢ� ���஭��ᮬ? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I4VACKR__V!=ON){ Message(157+A4BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ���誠�� ��⮪���� ���⠭�? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I4LUCDU__V!=ON){ Message(158+A4BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ��⮪����� ���⠭��(��)?
    if(mode==0 or mode==1){
      if(I4DU_____V!=ON){ Message(188+A4BNM,0); return(0); }
    }
    // �஢�ઠ ࠡ��� (����祭���� ���ﭨ�) ���஭��� 
    // �������� ����祭�� ���஭���               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I4GNS_1__V!=ON){ Message(160+A4BNM,0); return(0); }
    }
    // �᫨ ����� ������ ����
    if(mode>0){
       // �᫨ �� - ���室�� � ०�� ����������
       if(I4KR1SB__V==ON || I4GNS0B__V==ON){
          A4CISP=0; Message(168+A4BNM,0); Set_BV4(870); Set_ST4(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_04(vd){

    // ��⠭����� 䫠� ����� ��஫� ����᪠ 横�� � ��३�
    // �� ०��  "��������������"
    if (A4CYCRN__M>OFF){ A4CYCRN__V=ON; A4CYCRN__M=OFF; Set_ST4(300); }
    // ��⠭����� 䫠� ����� ��஫� ��⠭���� 横��
    if (A4CYCST__M>OFF){ A4CYCST__V=ON; A4CYCST__M=OFF; Set_ST4(50);  }
    // ��⠭����� 䫠� ����� ��஫� ���室� �� ������� 蠣
    if (A4ISPST__M>OFF){ A4ISPST__V=ON; A4ISPST__M=OFF; }

    // ��।������ ����� ०��� �� 蠣�
    A4STEP___V=floor( A4STEPW__V*0.01);
    // �஢�ઠ �࠭�筮�� ���祭�� ���������� 蠣�
    if (A4STEPW__M<0  or A4STEPW__M>900){ A4STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  �᫨ �� ������� 蠣 ࠡ��� ��⮪���� � ������ ��஫� ��������� 蠣�
    if (A4STEPW__M!=A4STEPW__V and A4ISPST__V==ON){
        //  �᫨ ��࠭ ������ ����� �ࠢ����� � ������ ��஫�
        //  ����᪠ ��� ��⠭��� 横��
        if((A4STEPW__M<=10)){
            A4STEPW__V =A4STEPW__M; Message(130+A4BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=100) and (A4STEPW__M< 200) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(131+A4BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=200) and (A4STEPW__M< 300) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(132+A4BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=300) and (A4STEPW__M< 400) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(133+A4BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=400) and (A4STEPW__M< 500) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(134+A4BNM,0); A4NAKPPREM=A4NAKPP__R;
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=500) and (A4STEPW__M< 600) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(135+A4BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A4STEPW__M>=600) and (A4STEPW__M< 700) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(136+A4BNM,0);
        }
        //-------------------------------------------------------------------
        //  ��⠭���� ����� ��।�������� ०��� ࠡ��� 
        if (A4STEPW__M == A4STEPW__V){ Set_BV4(0); }
        else                         { A4STEPW__M=A4STEPW__V; }
    }
//  // ----------------------------------------------------------------------





         

//  // ----------------------------------------------------------------------
//  // �஢�ન � ����஫� ��� ������ ����� ᥪ㭤�
    if(NewSEC>0){ 
       //-------------------------------------------
       // ������ �६��� ࠡ��� � ⥪�饬 ०���
       // ����� ᥪ㭤�
       A4STEPS__V++;
       // ����� ������
       if(A4STEPS__V>59){ A4STEPM__V++; A4STEPS__V=0; }
       // ����� ���
       if(A4STEPM__V>59){ A4STEPH__V++; A4STEPM__V=0; }
       // �१ 99 �ᮢ �६� ��⠥��� ᭠砫� (4,5 ��⮪)
       if(A4STEPH__V>99){ A4STEPH__V=0; A4STEPM__V=0; A4STEPS__V=0; }
       //-------------------------------------------
       // �᫨ �� ������ ��஫�- ��⠭���������� 䫠� ����� ��஫�, �����
       // ����⢨⥫�� 10 ᥪ㭤
       if(A4ISPST__V==ON or A4CYCST__V==ON or A4CYCRN__V==ON){ A4ISPST__C++; }
       // �᫨ ��諮 ����� 10 ᥪ ��᫥ ����� ��஫�- ����� 䫠� ����� 
       // ��஫�  � ���稪 ᥪ㭤 (��஫� �㦭� ������� ������)
       if(A4ISPST__C >10){ 
          A4ISPST__C=0; A4ISPST__V=OFF; A4CYCST__V=OFF; A4CYCRN__V=OFF;
       }
       //-------------------------------------------
       // �᫨ �� ������� ०�� �ࠢ����� ࠡ�⮩ ��⮪���� (��/��)
       if(S4MDUP___V!=S4MDU____V){
          // ��ॢ����� �� ��� - ��ॢ��� �ணࠬ�� � ०�� "��������"
          if(S4MDU____V==0){
             Message(137+A4BNM,0); Set_BV4(0); Set_ST4(50);
          }
          // ��ॢ����� �� ��  - �뤠�� ᮮ�饭��  � � ०�� "��������"
          if(S4MDU____V==1){
             Message(138+A4BNM,0); Set_BV4(0); Set_ST4(50);
          }
       }; S4MDUP___V=S4MDU____V;
       //-------------------------------------------
       if(Chk_SBP4()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �������� ������ ������ ������-������� ��⮪���� �� ०��� "��������"
    if (A4STEPW__V<=10||A4STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // �������� ������ ������ ����祭�� ���஭���
        // �᫨ �����- ��३� �� 蠣 870
        if(V4GNS1BS_V<1){
           if(I4GNS1B__V>0){
              Message(183+A4BNM,0); O4GNS____M=ON; A4CISP=0;
              Set_BV4(50); V4GNS1BS_V=1; Set_ST4(870); return;
           }
        }
        // �몫�祭�� ���஭���
        if(I4GNS0B__V>0){ 
           V4GNS1BS_V=0; O4GNS____M=OFF; 
        }
        //-----------
        // ����஫� ��⮢���� ��⮪���� ��३� � ०�� "���������"
        //(�������� � ��⮪���� �.�.  >1 � ������� �� ��������, ������� �
        // �ᯮ���⥫� ���襪, �� �� ���⠭樨).
        if(AIP4P____V>1 and I4ZIOPC__V>0 and I4ZIPPC__V>0 and I4ZOPPC__V>0 and
           I4VZC____V>0 and I4ZOPAC__V>0 and I4KIPC___V>0 and I4KOPC___V>0 and
           I4DU_____V>0 and
           I4SBP1Z__V>0 ){
           // ��।�����, �� ��㣨� �� �� ��室���� � ०��� ��९�᪠
           if(Get_RA4(0)>0){
              // �᫨ �����-� �� ����訢��� ����� ��� ���������-
              // ��।����� ��� �����
              if(Get_RA4(1)>0){
                 // ��३� �� ०�� ��������
                 Message(129+A4BNM,0); Set_BV4(0); Set_ST4(700);
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
    if (A4STEPW__V>=50 and A4STEPW__V<70){
       // �᫨ �諨 � 蠣� 232:- ������� 宬��
       if(A4STEPWP_V==232){

       }
       // ���� ������� � ��� �ᯮ���⥫��
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS4(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR4(1,STOP,STOP,STOP);
       Set_KR4(2,STOP,STOP,STOP);
       // �몫���� ���஭���
       O4GNS____M=OFF;
       // ����� ������� ����祭�� ���஭���
       V4GNS1BS_V=0;
       // ���� ����窨 � �롮� ०���� 横��
       A4NAKPP_YM=OFF;  A4NAKPP_YV=A4NAKPP_YM;
       A4RAZVK_YM=OFF;  A4RAZVK_YV=A4RAZVK_YM;
       A4PPP___YM=OFF;  A4PPP___YV=A4PPP___YM;
       A4PVID__YM=OFF;  A4PVID__YV=A4PVID__YM;
       A4SP____YM=OFF;  A4SP____YV=A4SP____YM;
       // ������ ⥪�騥 ⠩���� � ���稪�
       Clear_TA4();
       A4PPSTEP_V=0;
       // ��३� � ०�� ��������
       Message(189+A4BNM,0); Set_BV4(50); Set_ST4(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  ����祭�� �����������
//  // ----------------------------------------------------------------------
    if (A4STEPW__V>=870 and A4STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST4(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        //-----------
        // �᫨ ����� ������ �몫�祭�� ���஭���- �뤠�� �������� �� 
        // �몫�祭�� ���஭���
        if(I4GNS0B__V==ON){ 
           Message(184+A4BNM,0);
           // �뤠�� ������� �� �몫�祭�� ���஭���
           O4GNS____M=OFF;
           // ����� 䫠� ���ﭨ� ������ ����祭�� ���஭���
           V4GNS1BS_V=0; 
        }
        // �᫨ ����㯨�� ������� �� �몫�祭�� ���஭���
        if(V4GNS1BS_V==0&&O4GNS____M==OFF){
           // ���� ������� � �ᯮ���⥫�� ��堭����� ���誨
           //      N BY   HM   KR
           Set_KR4(1,STOP,STOP,STOP);
           Set_KR4(2,STOP,STOP,STOP);
           // ���� ������� � �ᯮ���⥫�� ��������
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ����� �몫�祭�� ���஭���
           switch( Check_TO(A4BTM+1,60*SEC, I4GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A4BNM,0); Bell(4,1); break; }
              case END: { Message(185+A4BNM,0); break; }
           }
           // ��३� � ०�� ��������
           Set_BV4(870); Set_ST4(50); return;
        }
        // �஢�ઠ ���ﭨ� �ᯮ���⥫��
        if(Chk_IF4(0)==0){
           A4CISP++; 
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(50); 
           }
           return; 
        }; A4CISP=0;
        //-----------
        // �뤠�� �������� �� ����祭�� ���஭���:
        O4GNS____M= ON;
        //-----------
        // �������� ������ ������ "������ ��⮪���"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I4KR1OBS_V<1 and I4KR1CBS_V<1){
           if(I4KR1OB__V>0){
              Message(174+A4BNM,0); A4CISP=0;
              Set_BV4(50); I4KR1OBS_V=1; V4GNS1BS_V=1; Set_ST4(100); return;
           }
        }
        //-----------
        // �������� ������ ������ "������� ��⮪���"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I4KR1OBS_V<1 and I4KR1CBS_V<1){
           if(I4KR1CB__V>0){
              Message(176+A4BNM,0);  A4CISP=0;
              Set_BV4(50); I4KR1CBS_V=1; V4GNS1BS_V=1; Set_ST4(200); return;
           }
        }
        //-----------
        Clear_TA4();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������" ��4
//  // ----------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A4STEPW__V>=100 and A4STEPW__V< 130){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O4GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V!=126){ Message(195+A4BNM,0); }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST4(126);
        I4KR_TMP_V=-1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(126); Set_ST4(870); return;}
        switch ( Check_TO(A4BTM+14,A4THMUP__R*SEC, I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R;A4STEPC__V =CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(151+A4BNM,0);
                        // �᫨ �� ���� 蠣 ����஫�- 㢥����� ���稪 
                        // ����஫� � ���� ������� �� �����⨥ 宬��
                        if(A4TEMP<1){ 
                           if(I4KR1OBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
                           A4TEMP++;
                        }
                        // �᫨ �� ��ன 蠣 ����஫�- ������ � ���室 �
                        // ०�� ��������
                        else        { Bell(4,1); Set_BV4(126); Set_ST4(870); }
                        return;
                      }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15);
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        Clear_TO(A4BTM+18); Clear_TO(A4BTM+19);
        A4STEPZ__V=0; A4STEPC__V=0;
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        Set_ST4(130);  A4TEMP=0;
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������":
    if (A4STEPW__V>=130 and A4STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O4GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST4(132);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4BY1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(132); Set_ST4(870); return;}
        // �᫨ ������� �� �����
        if(I4KR_TMP_V==OFF){
//         // ������� �� ����⨥ �������              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // �������� �����ᠬ�: 2ᥪ ������, 2ᥪ ��㧠
           if(A4TEMP<2){
             // ������ �� ����⨥
             if(I4KR1OBS_V>0){ O4BY1O___M=ON; O4BY1C___M=OFF; }
             A4TEMP++;
           } else {
             // ��㧠
             if(A4TEMP<4){
                O4BY1O___M=OFF; O4BY1C___M=OFF;
                O4BY2O___M=OFF; O4BY2C___M=OFF;
                A4TEMP++;
             } else {
             // ���室 ��᫥ ���� �� ������
                if(A4TEMP<7) A4TEMP=0;
             }
           }  
        }
        switch (Check_TO( A4BTM+16,A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(154+A4BNM,0); Bell(4,1); 
                        Set_BV4(132); Set_ST4(870);
                        return; 
                      }
        }
        // ��� 䫠�� ����� �����᭮�� ᨣ���� �� �������
        A4TEMP=10;
        // ���� ������� �� ����⨥ ������⮢          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O4BY1O___M=OFF; O4BY1C___M=OFF;
        O4BY2O___M=OFF; O4BY2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A4BTM+17,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+17]; return; }
        }
//      // ������� �� �����⨥ 宬��                   [x6.o01 (OxHM1UP) = 1]
        if(I4KR1OBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        Set_ST4(131);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(131); Set_ST4(870); return;}
        switch (Check_TO( A4BTM+14,A4THMUP__R*SEC,I4KR_TMP_V, '=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(151+A4BNM,0); Bell(4,1);
                        Set_BV4(131); Set_ST4(870);    return;
                      }
        }
        // ���� ������� �� �����⨥ 宬��             [x6.o01 (OxHM1UP) = 0]
        O4HM1UP__M=OFF; O4HM1DN__M=OFF;
        O4HM2UP__M=OFF; O4HM2DN__M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        //--------
//      // ������� �� ����⨥ ���誨                   [x6.o03 (OxKR1O_) = 1]
        if(I4KR1OBS_V>0){ O4KR1O___M=ON; O4KR1C___M=OFF; }
        // ���誨 ������?                              [x7.i02 (IxKR1O_) = 1]
        Set_ST4(133);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4KR1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(133); Set_ST4(870);  return;}
        switch (Check_TO( A4BTM+18,A4TKRO___R*SEC, I4KR_TMP_V, '=',ON,1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+18); Message(152+A4BNM,0); Bell(4,1); 
                        Set_BV4(133); Set_ST4(870);
                        return; 
                      }
        }
        // ������� � ���襪 ᭨��� ��᫥ ���᪠��� 宬��

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO(A4BTM+19,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+19]; return; }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15);
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        Clear_TO(A4BTM+18); Clear_TO(A4BTM+19);
        A4STEPZ__V=0; A4STEPC__V=0;
        //
        Set_ST4(134); A4TEMP=0; return;
    }
//  // ----------------------
//  //  ���᪠��� 宬��
    if (A4STEPW__V>=134 and A4STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O4GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
//      // ������� �� ���᪠��� 宬�⮢                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I4KR1OBS_V>0){ O4HM1DN__M=ON; O4HM1UP__M=OFF; }
        // 宬��� ���饭�?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST4(134);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1DN__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(134); Set_ST4(870);  return;}
        switch (Check_TO( A4BTM+14,A4THMUP__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(150+A4BNM,0); Bell(4,1); 
                        Set_BV4(134); Set_ST4(870);
                        return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        Message(191+A4BNM,0);
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"->"��������"|"���"
        Message(197+A4BNM,0); Set_BV4(141); Set_ST4(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A4STEPW__V>=200 and A4STEPW__V< 230){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O4GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V==200){ Message(196+A4BNM,0); }
        //--------
        // 宬�� ���饭?                                [x7.i01 (IxHM1DN) = 1]
        Set_ST4(226);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4HM1DN__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(226);  Set_ST4(870); return;}
        switch ( Check_TO (A4BTM+14, A4THMUP__R*SEC,   I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V = CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(150+A4BNM,0); Bell(4,1); 
                        Set_BV4(226); Set_ST4(870);   return; 
                      }
        }
        // �뤠�� �������� �� ����⨥ �������
        if(I4KR1CBS_V>0){ O4BY1O___M=ON; O4BY1C___M=OFF; }
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        // �᫨ ������� �� ������- ���
        Set_ST4(228);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4BY1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(228); Set_ST4(870); return;}
        switch ( Check_TO (A4BTM+15, A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+15); Message(154+A4BNM,0); Bell(4,1);
                        Set_BV4(228); Set_ST4(870);   return; 
                      }
        }
        // ���� ������� � �������
        O4BY1O___M=OFF; O4BY1C___M=OFF;
        O4BY2O___M=OFF; O4BY2C___M=OFF;
        //
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15); 
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(230);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": �ਯ������ ��। �����⨥�
    if (A4STEPW__V>=230 and A4STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O4GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // ������� �� �ਯ����⨥ ���誨                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I4KR1CBS_V>0){ O4KR1O___M=ON; O4KR1C___M=OFF; }
        // ���誠 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST4(231);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4KR1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(231); Set_ST4(870); return;}
        switch (Check_TO(A4BTM+14,A4TKRO___R*SEC, I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(152+A4BNM,0); Bell(4,1);
                        Set_BV4(231); Set_ST4(870);   return; 
                      }
        }
        // ���� ������� �� �����⨥ ���誨             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O4KR1O___M=OFF; O4KR1C___M=OFF;
        O4KR2O___M=OFF; O4KR2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        // ������ ������� �� �����⨥ 宬��            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I4KR1CBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
        Set_ST4(232);
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(232); Set_ST4(870); return;}
        switch (Check_TO(A4BTM+16,A4THMUP__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(151+A4BNM,0); Bell(4,1);
                        Set_BV4(232); Set_ST4(870);   return; 
                      }
        }
        // ��᫥ ������� 宬�� ������� �� ᭨������

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A4BTM+17,A4TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+17]; return; }
        }
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15); 
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(235);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": ������� ���誨
    if (A4STEPW__V>=235 and A4STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O4GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM,0); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // ������� �� �����⨥ ���襪                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I4KR1CBS_V>0){ O4KR1C___M=ON; O4KR1O___M=OFF; }
        // ���誠 ������?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST4(236);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4KR1C___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(236); Set_ST4(870); return;}
        switch (Check_TO (A4BTM+14,A4TKRO___R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(153+A4BNM,0); Bell(4,1);
                        Set_BV4(236); Set_ST4(870); return; 
                      }
        }
        // ���� ������� �� �����⨥ ���襪             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O4KR1C___M=OFF; O4KR1O___M=OFF;
        O4KR2C___M=OFF; O4KR2O___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        // ������� �� �����⨥ ������⮢                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I4KR1CBS_V>0){ O4BY1C___M=ON; O4BY1O___M=OFF; }
        // �������� �������?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST4(237);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4BY1C___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(237); Set_ST4(870); return;}
        switch (Check_TO (A4BTM+16,A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(155+A4BNM,0); Bell(4,1);
                        Set_BV4(237); Set_ST4(870);   return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        Message(193+A4BNM,0);
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"
        Message(198+A4BNM,0); Set_BV4(235); Set_ST4(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A4STEPW__V>=300 and A4STEPW__V<320){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "��������������"- ��३� �� � ०��
        if(A4RAZVK_YV==OFF){ Set_BV4(300); Set_ST4(400); return; }
        // �஢�ઠ  ����㬨஢���� ��㣨� ��⮪�����
        // (�� ����㬨஢���� ����� ��室����  ������ ���� ��⮪���)
        if(A1PPSTEP_V==300||A2PPSTEP_V==300||A3PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV4(300); Set_ST4(50); return; 
        }
        A4PPSTEP_V=300;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V==300){ Message(200+A4BNM,0); }
        //
        Set_ST4(311);
        // ��ॢ��� ॣ���� �������� � ��� ०��, �⮡� ������� ������
        A4RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST4(301);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST4(302);
        switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST4(303);
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST4(304);
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST4(305);
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM,0); Bell(4,1); return; }
        }
        // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
        Set_ST4(306);
        switch ( Check_TO(A4BTM+6, A4RCHKF__R* SEC, I4KOCC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4RCHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(146+A4BNM,0); Bell(4,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST4(307);
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM,0); Bell(4,1); return; }
        }
        // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST4(308);
        switch ( Check_TO(A4BTM+8, 60*SEC,I4P1_N___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+8]; return; }
            case BAD: { Clear_TO(A4BTM+8); Message(156+A4BNM,0); Bell(4,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST4(309);
        switch ( Check_TO(A4BTM+9, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+9]; return; }
            case BAD: { Clear_TO(A4BTM+9); Message(147+A4BNM,0); Bell(4,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ����㬭���      [x2.i08 (IxVNMD_) = 1]
        Set_ST4(310);
        switch ( Check_TO(A4BTM+10, 60*SEC, I4VNMD___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+10]; return; }
            case BAD: { Clear_TO(A4BTM+10); Message(162+A4BNM,0); Bell(4,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ��������          [x2.i07 (IxVZMD_) = 1]
        Set_ST4(311);
        switch ( Check_TO(A4BTM+11, 60*SEC, I4VZMD___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+11]; return; }
            case BAD: { Clear_TO(A4BTM+11); Message(182+A4BNM,0); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6);
        Clear_TO(A4BTM+7); Clear_TO(A4BTM+8); Clear_TO(A4BTM+9);
        Clear_TO(A4BTM+10); 
        Clear_TO(A4BTM+11);
        A4STEPZ__V=0; A4STEPC__V=0;
        I4MAXVCN_V=0;
        Set_ST4(320);
        return;
    }
//  // ----------------------
//  //  ����祭�� ����㬨஢����
    if (A4STEPW__V>=320 and A4STEPW__V<325){
        if(!NewSEC){ return; }
        // ������� �� ����⨥ ����㬭�� ��������       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // ����㬭�� �������� �����?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST4(321);
        switch ( Check_TO(A4BTM+1, A4TVZO___R* SEC, I4VZO____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(163+A4BNM,0); return; }
        }
        // ���� ������� �� ����⨥ ����㬭�� �������� [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // ����뢠���� ������ �� ����㬭�� ����       [x4.o04 (OxAZVO_) = 1]
        O4AZVO___V=ON; O4AZVO___M=OFF;
        // ������� �� ����祭�� ����㬭��� ����       [x4.o05 (OxVN_1_) = 1]
        O4VN_1___V=ON; O4VN_1___M=OFF;
        Set_ST4(322);
        // ����㬭� ���� ����祭?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A4BTM+2, 60*SEC, I4VN_1___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(164+A4BNM,0); Bell(4,1); return; }
        }
        // �஢�ઠ ������ ���ᨬ��쭮�� ࠧ०���� �   [x2.i06 (IxMAXV_) = 1]
        // �.���⠪⭮�� ��������
        if(I4MAXV___V>0){ I4MAXVCN_V++; }
        else            { I4MAXVCN_V=0; }
        if(I4MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
           Set_ST4(325);
           return;
        }
        // �஢�ઠ ����稭� ࠧ०���� � ��⮪����     [x0.06 (AIPxyV__) = ?]
        // (����� ��� ��� ��� ���)
        Set_ST4(323);
        switch ( Check_TO(A4BTM+3, A4TVACUM_R* SEC, AIP34V___V,'<',A4RAZVK__R, 3)){
            case RUN: { A4STEPZ__V=A4TVACUM_R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Message(165+A4BNM,0); break; }
        }
        // ���� �������� �� �����⨥ ����㬭�� �������� [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(325);
        return;
    }
//  // ----------------------
//  //  �몫�祭�� ����㬨஢����
    if (A4STEPW__V>=325 and A4STEPW__V<330){
        if(!NewSEC){ return; }
        // ������� �� �����⨥ ����㬭�� ��������       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ����㬭�� �������� ������?                  [x2.i02 (IxVZC__) = 1]
        Set_ST4(326);
        switch ( Check_TO(A4BTM+1, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(166+A4BNM,0); return; }
        }
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        Set_ST4(327);
        switch (Check_TO (A4BTM+3,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
        }
        // ������ ������ �⬮���� �� ����㬭�� ���� [x4.o04 (OxAZVO_) = 1]
        O4AZVO___V=OFF; O4AZVO___M=OFF;
        // �몫���� ����㬭� ����                    [x4.o05 (OxVN_1_) = 0]
        O4VN_1___V=OFF; O4VN_1___M=OFF;
        Set_ST4(328);
        // ����㬭� ���� �몫�祭?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A4BTM+4,  120*SEC, I4VN_1___V,'=',OFF, 1)){
            case RUN: { A4STEPZ__V=120; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(167+A4BNM,0); return; }
        }
        //
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); 
        Clear_TO(A4BTM+3); Clear_TO(A4BTM+4);
        A4STEPZ__V=0; A4STEPC__V=0;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(190+A4BNM,0); Set_ST4(330);
        return;
    }
//  // ----------------------
//  //  �������������� ���������
    if (A4STEPW__V>=330 and A4STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ��ॢ�� �ࠢ����� ��⮪����� � ��筮� ०��
        Set_BV4(330); Set_ST4(400);
        A4RAZVK_YM=OFF; A4RAZVK_YV=A4RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  ����� "����� ��������"
//  // -----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A4STEPW__V>=400 and A4STEPW__V<420){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� � ०��
        if(A4PPP___YV==OFF){ Set_BV4 (400); Set_ST4(500); return; }
        A4PPSTEP_V=400;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V==400){ 
           Message(201+A4BNM,0); 
           A4RPRA___M=OFF; A4RPUU1__M=RMINUS; Set_ST4(401); return; 
        }
        //
        A4NAKPPREM=A4NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST4(401);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST4(402);
        switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST4(403);
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST4(404);
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM,0); Bell(4,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST4(405);
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM,0); Bell(4,1); return; }
        }
        // ������ ���᪠ ��� ������?
        Set_ST4(406);
        switch ( Check_TO(A4BTM+6, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(128+A4BNM,0); Bell(4,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST4(407);
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM,0); Bell(4,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST4(409);
        switch ( Check_TO(A4BTM+9, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+9]; return; }
            case BAD: { Clear_TO(A4BTM+9); Message(147+A4BNM,0); Bell(4,1); return; }
        }
        // ०�� �ࠢ����� ��⮪����� "���⠭��"?     [x1.i13 (IxDU___) = 1]
        Set_ST4(410);
        switch ( Check_TO(A4BTM+10, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+10]; return; }
            case BAD: { Clear_TO(A4BTM+10); Message(159+A4BNM,0); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6); 
        Clear_TO(A4BTM+7); Clear_TO(A4BTM+8); Clear_TO(A4BTM+9); 
        Clear_TO(A4BTM+10);
        A4STEPZ__V=0; A4STEPC__V=0;
        // ��࠭ ०�� ����� �������� ������ࠫ�� ��஬?
        if(A4NAKPPREM==0) Set_ST4(430);
        else              Set_ST4(420);
        A4TEMP=0; A4FLAG=0; A4PPRT=0; A4RPRA___M=ON; A4RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  �஢�ઠ ��⮢���� ��⮪����-��।��稪� (����⨥ �� ��� ��������)
    if (A4STEPW__V>=420 and A4STEPW__V<422){
        if(!NewSEC){ return; }
        A4PPSTEP_V=420;
        Set_ST4(421);
        // ����� ���⢥ত���� � ��⮢���� � ��९��� � ��⮪����
        // ��।��稪�
        if(A4PPRT<1){
           A4PPRT=Get_RV4(); 
           return;
        }
        Set_ST4(422);
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  ����⨥ �ᯮ���⥫��:
    if (A4STEPW__V>=422 and A4STEPW__V<425){
        if(!NewSEC){ return; }
        A4PPSTEP_V=422;
        // ���� ������� �� ����⨥ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� �����?   [x3.o02 (OxZIPPO) = 1]
        Set_ST4(423);
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZIPPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(161+A4BNM,0); Bell(4,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���.���
        switch (Check_TO (A4BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        // ��३� �� ᫥���騩 蠣
        Set_ST4(425);
        return;
    }
//  // ----------------------
//  // �������� ������ �� ��-��� ������� ���᪠ ���
    if (A4STEPW__V>=425 and A4STEPW__V<427){
        if(!NewSEC){ return; }
        A4PPSTEP_V=425;
        // ����� ���⢥ত���� �� ��� ������� ���᪠ ��� �� ��⮪����
        // ��।��稪�
        if(A4PPRT<2){
           A4PPRT=Get_RV4(); 
           return;
        }
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST4(440); A4RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  � ������ࠫ�
    if (A4STEPW__V>=430 and A4STEPW__V<435){
        if(!NewSEC){ return; }
        // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ쭮�� ��� �����? [x1.i00 (IxZIOPO) = 1]
        Set_ST4(431);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(171+A4BNM,0); Bell(4,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���ண� ���
        switch (Check_TO (A4BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ���ண� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST4(440); A4RPZD___S=0; A4RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  ��ନ஢���� ������� ��室� ��� ॣ���� "������ ��������"
    if (A4STEPW__V>=440 and A4STEPW__V<445){
        if(!NewSEC){ return; }
        // ��।��塞 ������� ��室� ��� ��� ॣ���� �� ⠡���� 
        // "����� �����������"
        Set_ST4(441);
        //-----------
        // ��� ����� ⥬������� ����� ��஬:
        if(A4NAKPPREM==0){
            // �᫨ ⥪��� � ��⮪���� ����� ��।��� ������� � ⠡���-
            // ��⠭����� ������� ��室� ��� ��� ॣ���� ����� ��������
            if(A4RPZD___S==0){ 
               A4RPZD___M =A41NTOF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=1;
            }
            if(AIT4P____V>=A41NTOP02R  and A4RPZD___S<=2){ 
               A4RPZD___M =A41NTOF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=2;
            }
            if(AIT4P____V>=A41NTOP03R  and A4RPZD___S<=3){ 
               A4RPZD___M =A41NTOF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=3;
            }
            if(AIT4P____V>=A41NTOP04R  and A4RPZD___S<=4){ 
               A4RPZD___M =A41NTOF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=4;
            }
            if(AIT4P____V>=A41NTOP05R  and A4RPZD___S<=5){ 
               A4RPZD___M =A41NTOF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=5;
            }
        } else {
        // ��� ����� ⥬������� ��९�᪭� ��஬:
            if(A4RPZD___S==0){
               A4RPZD___M =A41NTPF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=1;
            }
            if(AIT4P____V>=A41NTPP02R  and A4RPZD___S<=2){
               A4RPZD___M =A41NTPF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=2;
            }
            if(AIT4P____V>=A41NTPP03R  and A4RPZD___S<=3){
               A4RPZD___M =A41NTPF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=3;
            }
            if(AIT4P____V>=A41NTPP04R  and A4RPZD___S<=4){
               A4RPZD___M =A41NTPF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=4;
            }
            if(AIT4P____V>=A41NTPP05R  and A4RPZD___S<=5){
               A4RPZD___M =A41NTPF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=5;
            }
        }
        //-----------
        // �᫨ �������� � ��⮪���� ����� ⮣�, �� ��।�����
        // � ��ࢮ� ��ப� ⠡���� "����� ��������" - ��।��塞 �������
        // ��室�  ��� ��� ॣ���� �� ⠡���� "����� ��������"
        // ��� ����� �������� ����� ��஬:
        if(A4NAKPPREM==0){
            if(AIP4P____V>=A41NPOP01R  and A4RPZD___S<=6){ 
               A4RPZD___M =A41NPOF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=6;
            }
            if(AIP4P____V>=A41NPOP02R  and A4RPZD___S<=7){ 
               A4RPZD___M =A41NPOF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=7;
            }
            if(AIP4P____V>=A41NPOP03R  and A4RPZD___S<=8){ 
               A4RPZD___M =A41NPOF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=8;
            }
            if(AIP4P____V>=A41NPOP04R  and A4RPZD___S<=9){ 
               A4RPZD___M =A41NPOF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=9; 
            }
            if(AIP4P____V>=A41NPOP05R  and A4RPZD___S<=10){ 
               A4RPZD___M =A41NPOF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=10;
            }
            if(AIP4P____V>=A41NPOP06R  and A4RPZD___S<=11){ 
               A4RPZD___M =A41NPOF06R; A4RPZD___V=A4RPZD___M; A4RPZD___S=11;
            }
            if(AIP4P____V>=A41NPOP07R  and A4RPZD___S<=12){ 
               A4RPZD___M =A41NPOF07R; A4RPZD___V=A4RPZD___M; A4RPZD___S=12;
            }
            if(AIP4P____V>=A41NPOP08R  and A4RPZD___S<=13){ 
               A4RPZD___M =A41NPOF08R; A4RPZD___V=A4RPZD___M; A4RPZD___S=13;
            }
            if(AIP4P____V>=A41NPOP09R  and A4RPZD___S<=14){ 
               A4RPZD___M =A41NPOF09R; A4RPZD___V=A4RPZD___M; A4RPZD___S=14;
            }
            if(AIP4P____V>=A41NPOP10R  and A4RPZD___S<=15){ 
               A4RPZD___M =A41NPOF10R; A4RPZD___V=A4RPZD___M; A4RPZD___S=15;
            }
        } else {
        // ��� ����� �������� ��९�᪭� ��஬:
            if(AIP4P____V>=A41NPPP01R  and A4RPZD___S<=6){ 
               A4RPZD___M =A41NPPF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=6;
            }
            if(AIP4P____V>=A41NPPP02R  and A4RPZD___S<=7){ 
               A4RPZD___M =A41NPPF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=7;
            }
            if(AIP4P____V>=A41NPPP03R  and A4RPZD___S<=8){ 
               A4RPZD___M =A41NPPF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=8;
            }
            if(AIP4P____V>=A41NPPP04R  and A4RPZD___S<=9){ 
               A4RPZD___M =A41NPPF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=9;
            }
            if(AIP4P____V>=A41NPPP05R  and A4RPZD___S<=10){ 
               A4RPZD___M =A41NPPF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=10;
            }
            if(AIP4P____V>=A41NPPP06R  and A4RPZD___S<=11){ 
               A4RPZD___M =A41NPPF06R; A4RPZD___V=A4RPZD___M; A4RPZD___S=11;
            }
            if(AIP4P____V>=A41NPPP07R  and A4RPZD___S<=12){ 
               A4RPZD___M =A41NPPF07R; A4RPZD___V=A4RPZD___M; A4RPZD___S=12;
            }
            if(AIP4P____V>=A41NPPP08R  and A4RPZD___S<=13){ 
               A4RPZD___M =A41NPPF08R; A4RPZD___V=A4RPZD___M; A4RPZD___S=13;
            }
            if(AIP4P____V>=A41NPPP09R  and A4RPZD___S<=14){ 
               A4RPZD___M =A41NPPF09R; A4RPZD___V=A4RPZD___M; A4RPZD___S=14;
            }
            if(AIP4P____V>=A41NPPP10R  and A4RPZD___S<=15){ 
               A4RPZD___M =A41NPPF10R; A4RPZD___V=A4RPZD___M; A4RPZD___S=15;
            }
        }
        //-----------
        // �᫨ ��⮪��� � ०��� ����� �������� ��९�᪭�  ��஬ �
        // �᫨ ࠧ��� �������� ����� ��-��।��稪�� � ��-�ਥ������
        // ����� ��������� (AxZPPRE__R) -��३� �� 蠣
        // ������� �ᯮ���⥫�� ����� ��९�᪭��� ��� � �ନ஢����
        // ������� ��室� ��� ॣ���� "������ ��������" �� ���஬� ����
        A4PPSTEP_V=440; Get_RV4();
        if(A4NAKPPREM>0 and AIPRP4___V-AIP4P____V < A4ZPPRE__R){
           Set_ST4(480); A4PPRT=0; return;
        }

        //-----------
        // �᫨ �������� � ��⮪���� ����� ��������� � "���������� �����"-
        // ��३� �� 蠣 ������� �ᯮ���⥫�� ������ࠫ쭮�� ���
        if(A4NAKPPREM==0 and A4PPP____R>0 and AIP4P____V>=A4PPP____R){
           if(A4TEMP <7){ 
              A4TEMP++;     
           } else { 
              Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
              Set_ST4 (450);
           }
           return;
        } else {
           A4TEMP=0;
        }
        //-----------
        // �᫨ ����� �������� ���� � ������ࠫ� � �������� � ��⮪���� 
        // �����,祬 �������� � ������ࠫ�- ������� �������� ���᪠ ���� ���
        if(A4NAKPPREM==0 and AIP4P____V>=AIP34M___V){
           Set_ST4(442);
           // ���� ������� �� �����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // �᫨ ��९�� �������� ����� �� � ������ࠫ�� �⠡�����஢����
        if(A4NAKPPREM==0 and AIP4P____V< AIP34M___V-A4ZNPM___R){
           Set_ST4(443);
           // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS4(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ࠫ쭮�� ��� � ���室 �� "��������"
    if (A4STEPW__V>=450 and A4STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A4BTM+2, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(128+A4BNM,0); Bell(4,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_BV4(440); Set_ST4(500);
        A4PPP___YM=OFF;  A4PPP___YV=A4PPP___YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(202+A4BNM,0);
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ��९�᪭��� ��� �� ��-���
    if (A4STEPW__V>=480 and A4STEPW__V<482){
        if(!NewSEC){ return; }
        A4PPSTEP_V=480;
        Set_ST4(481);
        // ����� ���⢥ত���� � �����⨨ �ᯮ���⥫�� ���᪠ ��� ��
        // ��⮪���� ��।��稪�
        if(A4PPRT<3){
           A4PPRT=Get_RV4(); return;
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(482);
        return;
    }
//  // ----------------------
    if (A4STEPW__V>=482 and A4STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST4(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� ������?
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(142+A4BNM,0); Bell(4,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A4BTM+2, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(128+A4BNM,0); Bell(4,1); return; }
        }
        // �� �����⨨ ���  �ᯮ���⥫�� ��९�᪭��� ���, �����頥���
        // �� �ନ஢���� ������� ��室� ��� ॣ���� ������ ��������
        // �� ���஬� ����
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(440);
        A4NAKPPREM=0; A4RPZD___S=0; A4RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  ����� "��������"
//  // ----------------------------------------------------------------------
    if ((A4STEPW__V==500)||(A4STEPW__V>510&&A4STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST4(500);
        // �᫨ � 横� �� ����祭 ०�� "��������"- ��३� �� � ०��
        if(A4PVID__YV==OFF){ Set_BV4(500); Set_ST4(600); return; }
        A4PPSTEP_V=500;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V==500){ Message(203+A4BNM,0); }
        // �뤥প� ��⮪���� ��� ��������� �஢������ ������ࠫ�� ��஬
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST4(511);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(512);
        // ������ ���᪠ ��� ������?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A4BTM+2, A4RPHKF__R, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(169+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(513);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(514);
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(515);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(516);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A4BTM+6, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(142+A4BNM,0); Bell(4,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6);
        A4STEPZ__V=0; A4STEPC__V=0;
        //
        Set_ST4(501);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A4TEMP=0.3;
        A4RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A4STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST4(501);
        //-----------
        // �᫨ �������� � ��⮪���� ����� ���������-
        // ��३� ��  蠣 ������� ������� ���᪠ ���
        if(AIP4P____V>=A4PPP____R){
           Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=0; 
           return;
        }
        //-----------
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ��३� �� 蠣 ������� �������� � ������� ���᪠ ���ண� ���
        if(AIP4P____V> A4ZPAKX__R or AIP4P____V>AIP34M___V){
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=1;
           return;
        }
        //-----------
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A4STEPH__V>=A4PVIDH__R and A4STEPM__V>=A4PVIDM__R){
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=2;
           return;
        }
        //-----------

        //-----------
        // �뤥প� ��⮪���� ��� ���������  �஢������ ������ࠫ�� ��஬
        // ������  ��������  ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� �����?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPO__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(171+A4BNM,0); Bell(4,1); return; }
        }
        //-----------
        // ����  ������� �  �������� ���᪠  ���ண� ���  �
        // �뤠�� ������� �� ����⨥ ������� ���᪠  ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A4BTM+3]==0) Set_IS4(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A4BTM+3]==1) Set_IS4(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ����� A4TEMP %  ᥪ㭤 �� �������  室� ������� ���᪠ ���
        // ��� ���� �� �ࠡ�⠥� ���楢�� ������ �������
        if(I4KIPO___V<1){
           switch ( Check_TO(A4BTM+2,A4RPHKF__R*A4TEMP,ZERO,'=',ON, 1)){
               case RUN: { A4STEPZ__V=A4RPHKF__R*A4TEMP; A4STEPC__V=CNTTO[A4BTM+2]; 
                           return;
                         }
           }
        }
        // ���� ������� � ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // ����প� 30 ᥪ㭤
        switch ( Check_TO(A4BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=30; A4STEPC__V=CNTTO[A4BTM+3]; return; }
        }
        if(AIP4P____V< A4PPP____R){
        // �᫨ �������� � ��⮪���� �� ����﫮�� �� ��������� � ������
        // ����� �� ���������- 㢥����� �६� ������ ������� � �������
        // ⥪�騩 蠣 
        //(��ਭ樯�,⠪ ����� ���뢠�� ������ ����� ������ +0.3,+0.3...)
           if(A4TEMP<0.8){
              A4TEMP=0.3;
              Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
              A4STEPZ__V=0; A4STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A4STEPW__V>=502 and A4STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST4(502);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A4TEMP=0.3;
        // �᫨ ⥪�饥 �������� � ��⮪���� ����� ���������-
        // ��३� ����� ��  蠣 ������  �������� � ������� ���᪠ ���
        if(AIP4P____V<A4PPP____R-A4ZNVD___R and 
           AIP4P____V<AIP34M___V-A4ZNPM___R and A4FLAG<2){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(501); return;
        }
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ������� �������� ���᪠ ���ண� ���
        if(AIP4P____V> A4ZPAKX__R or AIP4P____V>AIP34M___V){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); 
           A4STEPZ__V=0; A4STEPC__V=0; A4FLAG=1;
        }
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A4STEPH__V>=A4PVIDH__R and A4STEPM__V>=A4PVIDM__R){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); 
           A4STEPZ__V=0; A4STEPC__V=0; A4FLAG=2;
        }
        // �᫨ �� ����஫� ���ᨬ��쭮 �����⨬��� �������� ��� ࠧ���� ���
        // ��室 �� ०��� - ������� �������� ���᪠ ���ண� ���
        if(A4FLAG>0){
          // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // �������� ���᪠ ���ண� ��� ������?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A4BTM+5, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(141+A4BNM,0); Bell(4,1); return; }
          }
        }
        // ���� ������� �� �����⨥ ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢����  ���� ������� ���᪠ ���       [x1.i05 (IxKIPC_) = 1]
        // ������ ���᪠ ��� ������?            
        switch ( Check_TO(A4BTM+4, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,  1 )){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(170+A4BNM,0); Bell(4,1); return; }
        }
        // �᫨ �� ��⠭����� 䫠� ��室�- ��३� �� ०�� "����� ��������"
        if(A4FLAG==2){ 
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_BV4(502); Set_ST4(600);
           A4PVID__YM=OFF;  A4PVID__YV=A4PVID__YM;
           // ᮮ�饭�� �� ����砭�� ०���
           Message(204+A4BNM,0);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  ����� "����� ��������"
    // ----------------------------------------------------------------------
    if ((A4STEPW__V==600)||(A4STEPW__V>610&&A4STEPW__V<620)){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� ���.०��
        if(A4SP____YV==OFF){ Set_BV4(600); Set_ST4(50); return; }
        // �஢�ઠ ������ �������� ��㣨� ��⮪�����
        // (�� ������ �������� ����� ��室���� ������ ���� ��⮪���)
        if(A1PPSTEP_V==600||A2PPSTEP_V==600||A3PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV4(600); Set_ST4(50); Message(110+A4BNM,0); return; 
        }
        A4PPSTEP_V=600;
        // ᮮ�饭�� � ��砫� ०���
        if(A4STEPW__V==600){ Message(205+A4BNM,0); }
        //
        A4RPRA___M=ON;
        //-----------
        // ��।������ ��ࢮ��砫쭮�� ��業� ������ ������� ��� ���
        A4FLAG=0; A4FLGP=0; if(A4TKLO___R==0) A4TKLO___R=100;
        A4FLAG=5; A4TEMP=A41SPKK05R; 
        if(A4SPAT___R>0) A4TEMP=A41SPAK05R; if(A4TEMP==0) A4TEMP=20;
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A4SPAT___R>0){ A4TEMP=A4TKLO___R*0.01*A4TEMP; }
        // �᫨ ��।���� ��� ��� � �������
        else            { A4TEMP=A4TKLO___R*0.01*A4TEMP; }
        // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
        if(A4SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST4(611);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(613);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(615);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(616);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A4BTM+6, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(142+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(617);
        // ��� �������஢��?                            [x7.i08 (IxSBP1Z) = 1]
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM,0); Bell(4,1); return; }
        }
        Set_ST4(618);
        // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
        // �⬮����
        if(A4SPAT___R>0){
          // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
          // �⬮����
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A4BTM+8, A4TZSPA__R* SEC, I4ZOPAO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+8]; return; }
            case BAD: { Clear_TO(A4BTM+8); Message(173+A4BNM,0); Bell(4,1); return; }
          }
        }
        Clear_TO(A4BTM+1);  Clear_TO(A4BTM+2);  Clear_TO(A4BTM+3);  
        Clear_TO(A4BTM+4);  Clear_TO(A4BTM+5);  Clear_TO(A4BTM+6);  
        Clear_TO(A4BTM+7);  Clear_TO(A4BTM+8);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(602);
        return;
    }
//  // ----------------------
//  //  ��� ��� �� ⠡���
    if (A4STEPW__V>=602 and A4STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST4(602);
        // ��᢮��� ��६����� ��業�(�६� � ᥪ㭤��) ������ ������� 
        // (�� �������  �६��� 室� �������) �� ⠡���  ᮮ⢥��⢥���
        // ⥪�饣� ��������  � ��⮪����
        // ⠡��� ��ᬠ�ਢ����� �� ����襣� � ����襬� (᭨�� �����)
        // ��� ������ �� �।��騩 蠣

        // �᫨ ⥪�饥 �������� �����-1 ��� ⥪�饥 ��������
        // ����� ��᫥����� 㪠������� � ⠡��� "����� ��������"(᭨��-�����)
        // ��� ࠧ�����஢�� ���� �� ���- ��३� �� ᫥� ०��
        if(AIP4P____V<-1 or A4FLAG==1 or I4SBP1R__V>0){
           Set_ST4(605); Clear_TO(A4BTM+2); A4STEPZ__V=0; A4STEPC__V=0; A4FLGP=0;
           return;
        }
        
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A4SPAT___R>0){
           Set_ST4(603);
           if(AIP4P____V<A41SPAP04R and A4FLAG>=5){
              // ��⠥��� ࠧ��� ��業� ������ ������� �����
              // �।��騬 � ⥪�騬 蠣��
              A4TEMP=A4TKLO___R*0.01*(A41SPAK04R-A41SPAK05R); A4FLAG=4;
           }
           if(AIP4P____V<A41SPAP03R and A4FLAG>=4){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK03R-A41SPAK04R); A4FLAG=3;
           }
           if(AIP4P____V<A41SPAP02R and A4FLAG>=3){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK02R-A41SPAK03R); A4FLAG=2;
           }
           if(AIP4P____V<A41SPAP01R and A4FLAG>=2){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK01R-A41SPAK02R); A4FLAG=1;
           }
        } else {
           Set_ST4(604);
        // �᫨ ��࠭ ��� ��� � �������
           if(AIP4P____V<A41SPKP04R and A4FLAG>=5){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK04R-A41SPKK05R); A4FLAG=4;
           }
           if(AIP4P____V<A41SPKP03R and A4FLAG>=4){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK03R-A41SPKK04R); A4FLAG=3;
           }
           if(AIP4P____V<A41SPKP02R and A4FLAG>=3){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK02R-A41SPKK03R); A4FLAG=2;
           }
           if(AIP4P____V<A41SPKP01R and A4FLAG>=2){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK01R-A41SPKK02R); A4FLAG=1;
           }
        }
        // �᫨ �� ���室 �� ���� 蠣
        if(A4FLGP!=A4FLAG){
           // �᫨ ���祭�� A4TEMP > 0 - ���뢠�� ������ ���᪠ ���,
           // ���� - ����뢠��
           if(A4TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // �������� ���祭��
           A4TEMP=fabs(A4TEMP);  
           A4FLGP=A4FLAG;
           // ���㫨�� ⠩��� � ���稪� ��� ��ࠡ�⪨ ����� ���祭��
           Clear_TO(A4BTM+1); A4STEPZ__V=0;  A4STEPC__V=0;
        }
        // ��⠥� �६� �������⢨� ᨣ���� �� ������
        switch ( Check_TO(A4BTM+1, A4TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TEMP; A4STEPC__V=CNTTO[A4BTM+1]; return; }
        }
        // ��᫥ ��ࠡ�⪨ ⠩���- ���� ᨣ���� � �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  ����ୠ� �஢�ઠ � ��室 �� ⥪�饣� ०��� � ०�� "��������"
    if (A4STEPW__V>=605 and A4STEPW__V<607){
        if(!NewSEC){ return; }
        // �᫨ ⥪�饥  �������� ����� ��� ࠢ��  ��� 
        // ���  ����襬� ���祭�� � ⠡���- 㢥��� ���稪
        if(AIP4P____V<=0 or A4FLAG==1 or I4SBP1R__V>0){
           A4FLGP++;
        // ���� - 㬥�����
        } else { 
           A4FLGP--; 
        }
        // 10 ᥪ �������� 
        switch ( Check_TO(A4BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // �᫨ ���稪 ������⥫�� - 
        // ��३� �� 蠣 ������� �ᯮ���⥫��
        if(A4FLGP>2){
           Set_ST4(607); Clear_TO(A4BTM+1);
        } else {
        // �᫨ ���稪 ����⥫�� - �������� �� ����� ��������
           Set_ST4(603); A4FLGP=A4FLAG;
        }; Clear_TO(A4BTM+2); A4STEPZ__V =0; A4STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ �������� � ��室 �� ०���
    if (A4STEPW__V>=607 and A4STEPW__V<609){
        if(!NewSEC){ return; }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ��� ��� � �⬮����
        switch ( Check_TO(A4BTM+1, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(144+A4BNM,0); Bell(4,1); return; }
        }
        // �஢�ઠ ������� ������� ���᪠ ���
        switch ( Check_TO(A4BTM+2, A4TKLO___R* SEC, I4KOPC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(139+A4BNM,0); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_BV4(602); Set_ST4(50);
        A4SP____YM=OFF; A4SP____YV=A4SP____YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(206+A4BNM,0);
        return;
    }
//  // ----------------------







    //  ����� "�������� ��������" ��5
    //  �᫨ ��⮪��� ���� �� ��ॡ��, ������ �� �⠢�� � ���� ������
    //  "����� ��������".  ����� ��᫥ "��������" ��⮪��� ���室�� � ०��
    //  "��������". � �⮬ ०��� �� ����� ��室���� ᪮�� 㣮��� �����.
    //  � ��� ������ ������ ����� �ࠢ���� ��⮪����� ������ ��� � ��.
    //  �� ��� ࠡ��� � ०��� "��������" ��⮪��� ������ ��室���� � ०���
    //  �� � ������묨 ���������� � ���������.
    //  ��� ⮫쪮 ��襫  ����� �� ��ॡ�� � �⮣� ��⮪���� - ��⮪���
    //  ���室�� � ०�� "��������"
//  // ----------------------------------------------------------------------
    if (A4STEPW__V>=700 and A4STEPW__V<702){
        if(!NewSEC){ return; }
        A4RPRA___M=ON;
        // ������ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������ �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZOPPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(179+A4BNM,0); Bell(4,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A4PPSTEP_V=700;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_ST4(702);
        return;
    }
//  // ----------------------
//  //  ����⨥ ������� ���᪠ ���
    if (A4STEPW__V>=702 and A4STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA4(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A4IPPSTEPV>=400&&A4IPPSTEPV<500){
           // ������� ������ �������� �� ��-��
           if(A4IPPSTEPV!=425){ return; }
        } else {
        // �᫨ ��-�� ���襫 �� ०��� ������ �������� � ��㣮� ०��-
        // ��३�  �� �����⨥ �ᯮ���⥫�� (���⠭���⭠� �����)
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(704); return;
        }
        // ������ ������ ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // �஢�ઠ ������ ������� ���᪠ ���
        switch ( Check_TO(A4BTM+1, A4TKLO___R* SEC, I4KOPO___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(181+A4BNM,0); Bell(4,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A4PPSTEP_V=704;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A4BTM+1);  Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_ST4(704);
        return;
    }
//  // ----------------------
//  // �����⨥ �ᯮ���⥫�� ���᪠ ��९�᪭��� ���
    if (A4STEPW__V>=704 and A4STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA4(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A4IPPSTEPV>=400&&A4IPPSTEPV<500){
           // ������� ���� ��-�� �� ������ �㦭��� �������� � ��
           // ��३���  �� 蠣 ������� �ᯮ���⥫��
           if(A4IPPSTEPV!=480){ return; }
           // �᫨ ��-���樠�� �襫 �� ०��� ����� ��������- ����뢠��
           // �ᯮ���⥫� � ���室�� � ०��  ��������
           //(���⠭���⭠� �����)
        }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(143+A4BNM,0); Bell(4,1); return; }
        }
        // ������� ������ ���᪠ ���
        switch ( Check_TO(A4BTM+2, A4TKLO___R* SEC, I4KOPC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(139+A4BNM,0); Bell(4,1); return; }
        }
        // ��᫥ ������� ��⠭����� 䫠� ���⢥ত���� ������� �ᯮ���⥫��
        A4PPSTEP_V=705;
        // ��᫥ ����砭�� ��९�᪠ ��� ��⮪��� ��४��砥��� � ०��
        // "����� ��������"
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_BV4(704);  Set_ST4(600);
        // �᫨ ��-�� �� � ०��� ������ �������� (���⠭���⭠� �����)
        // ��ॢ��� ��� �� � ०�� ��������
        if(A4IPPSTEPV<400||A4IPPSTEPV>500){ Set_ST4(50); }
        A4SP____YM=OFF; A4SP____YV=ON;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(207+A4BNM,0);
        return;
    }
//  // ----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
