//---------------------------------------------------------------------------

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V3GNS1BS_V = 0;           // ���ﭨ� ������ ����祭�� ���஭���

_f  far  I3KR_TMP_V = 0;           // ⥪�� ����஫ ���祭�� ��࠭  ���誨
_f  far  I3KR1CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠1
_f  far  I3KR1OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠1

_f  far  A3TVACUM_R = 6000;        // �६� ����㬨஢���� (100 �����)
_f  far  I3MAXVCN_V = 0;           // ���稪 �ॢ�襭�� ���� ࠧ०����
_f  far  O3ZOPPO__Y = 0;           // ᨣ��� ��� ���� ���� ��� �� �� ��।��
_f  far  I3ZOPPO__Y = 0;           //
_f  far  A3RPZD___S = 0;           // 蠣 ������� ॣ���� "������ ��������"
_f  far  A3ISPST__C = 0;           // ���稪 ��஫� ��।������ 蠣�
_f  far  A3FLAG=0;                 // �������⥫�� ��६����
_f  far  A3FLGP=0;                 //
_f  far  A3TEMP=0;                 //
_f  far  A3PPRT=0;                 // ������ �� �㭪権 ��।������ 蠣� ���
_f  far  A3SBPT=0;                 // ���稪 ࠧ�����஢�� ���
_f  far  A3SBPC=0;                 // ���稪 �����஢�� ���
_f  far  A3SBPI=0;                 // ���稪 ������� �ᯮ���⥫�� ��� ���
_f  far  A3CISP=0;                 // ���稪 ����஫� ���ﭨ� �ᯮ���⥫��


//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ �������� � �������� ��3
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS3(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  ���ண� ���
    if (i1==  ON){ O3ZIOPO__M= ON; O3ZIOPC__M=OFF; }   //  ������
    if (i1== OFF){ O3ZIOPO__M=OFF; O3ZIOPC__M= ON; }   //  �������
    if (i1==STOP){ O3ZIOPO__M=OFF; O3ZIOPC__M=OFF; }   //  ��⠭�����
    // ��९�᪭��� ��� �室�饣�
    if (i2==  ON){ O3ZIPPO__M= ON; O3ZIPPC__M=OFF; }
    if (i2== OFF){ O3ZIPPO__M=OFF; O3ZIPPC__M= ON; }
    if (i2==STOP){ O3ZIPPO__M=OFF; O3ZIPPC__M=OFF; }
    // ��९�᪭��� ��� ��室�饣�
    if (i3==  ON){ O3ZOPPO__M= ON; O3ZOPPC__M=OFF; }
    if (i3== OFF){ O3ZOPPO__M=OFF; O3ZOPPC__M= ON; }
    if (i3==STOP){ O3ZOPPO__M=OFF; O3ZOPPC__M=OFF; }
    // ��� � �⬮����
    if (i4==  ON){ O3ZOPAO__M= ON; O3ZOPAC__M=OFF; }
    if (i4== OFF){ O3ZOPAO__M=OFF; O3ZOPAC__M= ON; }
    if (i4==STOP){ O3ZOPAO__M=OFF; O3ZOPAC__M=OFF; }
    // ����㬭�� ��������
    if (i5==  ON){ O3VZO____M= ON; O3VZC____M=OFF; }
    if (i5== OFF){ O3VZO____M=OFF; O3VZC____M= ON; }
    if (i5==STOP){ O3VZO____M=OFF; O3VZC____M=OFF; }
    // ������ ���᪠ ���
    if (i6==  ON){ O3KIPO___M= ON; O3KIPO___V= ON; O3KIPC___M=OFF; O3KIPC___V=OFF; }
    if (i6== OFF){ O3KIPO___M=OFF; O3KIPO___V=OFF; O3KIPC___M= ON; O3KIPC___V= ON; }
    if (i6==STOP){ O3KIPO___M=OFF; O3KIPO___V=OFF; O3KIPC___M=OFF; O3KIPC___V=OFF; }
    // ������ ���᪠ ���
    if (i7==  ON){ O3KOPO___M= ON; O3KOPO___V= ON; O3KOPC___M=OFF; O3KOPC___V=OFF; }
    if (i7== OFF){ O3KOPO___M=OFF; O3KOPO___V=OFF; O3KOPC___M= ON; O3KOPC___V= ON; }
    if (i7==STOP){ O3KOPO___M=OFF; O3KOPO___V=OFF; O3KOPC___M=OFF; O3KOPC___V=OFF; }
    // ������ ��� ��������
    if (i8==  ON){ O3KOCO___M= ON; O3KOCO___V= ON; O3KOCC___M=OFF; O3KOCC___V=OFF; }
    if (i8== OFF){ O3KOCO___M=OFF; O3KOCO___V=OFF; O3KOCC___M= ON; O3KOCC___V= ON; }
    if (i8==STOP){ O3KOCO___M=OFF; O3KOCO___V=OFF; O3KOCC___M=OFF; O3KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ ���襪 ��3
//              NUM       BY        HM        KR 
vd  far Set_KR3(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // �������
       if (b==  ON){ O3BY1O___M= ON; O3BY1C___M=OFF; }   //  ������
       if (b== OFF){ O3BY1O___M=OFF; O3BY1C___M= ON; }   //  �������
       if (b==STOP){ O3BY1O___M=OFF; O3BY1C___M=OFF; }   //  ��⠭�����
       // 宬��
       if (h==  ON){ O3HM1UP__M= ON; O3HM1DN__M=OFF; }
       if (h== OFF){ O3HM1UP__M=OFF; O3HM1DN__M= ON; }
       if (h==STOP){ O3HM1UP__M=OFF; O3HM1DN__M=OFF; }
       // ���誠
       if (k==  ON){ O3KR1O___M= ON; O3KR1C___M=OFF; }
       if (k== OFF){ O3KR1O___M=OFF; O3KR1C___M= ON; }
       if (k==STOP){ O3KR1O___M=OFF; O3KR1C___M=OFF; }
    }
    if(n==2){
       // �������
       if (b==  ON){ O3BY2O___M= ON; O3BY2C___M=OFF; }
       if (b== OFF){ O3BY2O___M=OFF; O3BY2C___M= ON; }
       if (b==STOP){ O3BY2O___M=OFF; O3BY2C___M=OFF; }
       // 宬��
       if (h==  ON){ O3HM2UP__M= ON; O3HM2DN__M=OFF; }
       if (h== OFF){ O3HM2UP__M=OFF; O3HM2DN__M= ON; }
       if (h==STOP){ O3HM2UP__M=OFF; O3HM2DN__M=OFF; }
       // ���誠
       if (k==  ON){ O3KR2O___M= ON; O3KR2C___M=OFF; }
       if (k== OFF){ O3KR2O___M=OFF; O3KR2C___M= ON; }
       if (k==STOP){ O3KR2O___M=OFF; O3KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// ���⪠ ��� ⠩��஢ � ���稪�
vd  far Clear_TA3(vd){
    Clear_TO(A3BTM+ 1); Clear_TO(A3BTM+ 2); 
    Clear_TO(A3BTM+ 3); Clear_TO(A3BTM+ 4); 
    Clear_TO(A3BTM+ 5); Clear_TO(A3BTM+ 6);
    Clear_TO(A3BTM+ 7); Clear_TO(A3BTM+ 8); 
    Clear_TO(A3BTM+ 9); Clear_TO(A3BTM+10);
    Clear_TO(A3BTM+11); Clear_TO(A3BTM+12);
    Clear_TO(A3BTM+13); Clear_TO(A3BTM+14);
    Clear_TO(A3BTM+15); Clear_TO(A3BTM+16);
    Clear_TO(A3BTM+17); Clear_TO(A3BTM+18);
    Clear_TO(A3BTM+19);
    A3STEPZ__V=0; A3STEPC__V=0;
}
//---------------------------------------------------------------------------
//  ��⠭���� ��砫��� ���祭�� �� ᬥ�� ०��� ࠡ��� ��⮪����
vd  far Set_BV3(_f far A3STEPWPRV){
    // ��������� ����� �।��饣� 蠣�
    A3STEPP__V =A3STEP___V;
    A3STEPWP_V =A3STEPWPRV;
    // �����  䫠�� ��஫��
    A3CYCRN__V =OFF; A3CYCRN__M=OFF;
    A3CYCST__V =OFF; A3CYCST__M=OFF;
    A3ISPST__V =OFF; A3ISPST__M=OFF;
    // ���㫨�� ���稪� ०���� � ⠩��஢
    A3STEPH__V =0;   A3STEPM__V=0; A3STEPS__V=0; 
    // ����� 䫠�� �롮� ���襪 ��� ������ � �������
    I3KR1OBS_V =0;
    I3KR1CBS_V =0; 
    I3KR_TMP_V=-1;
    // ���� ������� � ��� �ᯮ���⥫�� ���襪
    Set_KR3(1,STOP,STOP,STOP);
    Set_KR3(2,STOP,STOP,STOP);
    //  ���㫥��� ���祭�� ⠩��஢
    Clear_TA3();
    // ���� ������� �� 宬���
    O3HM1UP__M=OFF; O3HM1DN__M=OFF;
    O3HM2UP__M=OFF; O3HM2DN__M=OFF;
    // ���� ������� �� ��������
    O3BY1O___M=OFF; O3BY1C___M=OFF;
    O3BY2O___M=OFF; O3BY2C___M=OFF;
    // ���� ������� �� ���誨
    O3KR1O___M=OFF; O3KR1C___M=OFF;
    O3KR2O___M=OFF; O3KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  ��⠭���� ⥪�饣� 蠣� ०��� ࠡ��� ��⮪����
vd  far Set_ST3(int SS){
    A3STEPW__V=SS;
    A3STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  ����祭�� ���祭�� �� ��६����� 㤠������ ����஫��஢
//  A3PPSTEP_V - ����� 蠣� �ணࠬ�� ⥪�� ��
//  A3RPPSTEPV - �ਭ������� � ��-��� ���祭��,ᨣ���������饥 � �믮������ ��
//               ��-��� ⥪�饣� 蠣�
_f  far Get_RV3(vd){
    // �᫨ ��࠭ ����� 0- ����� ��� �������� � ������ࠫ�
    if(A3NAKPPREM==0){ return(0); }
    A3RPPSTEPV=0;
    if(A3NAKPPREM==1){ A3RPPSTEPV=A1PPSTEP_V; AIPRP3___V=AIP1P____V; }
    if(A3NAKPPREM==2){ A3RPPSTEPV=A2PPSTEP_V; AIPRP3___V=AIP2P____V; }
    if(A3NAKPPREM==4){ A3RPPSTEPV=A4PPSTEP_V; AIPRP3___V=AIP4P____V; }
    if(A3NAKPPREM==5){ A3RPPSTEPV=A5PPSTEP_V; AIPRP3___V=AIP5P____V; }
    if(A3NAKPPREM==6){ A3RPPSTEPV=A6PPSTEP_V; AIPRP3___V=AIP6P____V; }
    if(A3RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // �᫨ ⥪�騩 �� ��室���� � ०��� ������ ���.��஬
    if(A3PPSTEP_V==420){
       // �᫨ ��-��� ���襫 � ०�� ��������� � ���� �������� �� ���.���
       if(A3RPPSTEPV==700) return(1); return(0);
    }
    // ⥪�騩 �� ������� ������ ������� �� ���.��� �� ��-���
    if(A3PPSTEP_V==425){
       if(A3RPPSTEPV==704) return(2); return(0);
    }
    // ⥪�騩 �� ������� ������� �ᯮ���⥫�� ���᪠ ��� �� ��-���
    if(A3PPSTEP_V==480){
       // �᫨ �� ��-��� �ᯮ���⥫� ����뫨��
       if(A3RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  ����祭�� ⥪�饣� 蠣� ��-���樠�� (��-��) �� �⤠� ���
_f  far Get_RA3(int mode){
    // �஢���� �� ��㣨� ��⮪���� �� ��室���� � ०��� ��ॡ��
    // ��।����� �� ���ﭨ� ��९�᪭�� �������� (����,����)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A2PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // ��।����� ����� ��, ����� ����訢��� ⥪�騩 ��� �⤠� ���
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==3){ A3IPPNUM_V=1; return(1); }
       if(A2PPSTEP_V==420 and A2NAKPP__R==3){ A3IPPNUM_V=2; return(2); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==3){ A3IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==3){ A3IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==3){ A3IPPNUM_V=6; return(6); }
       return(0);
    }
    // ��।����� ⥪�騩 蠣 �� ��-���樠�� (��-��)
    if(mode==2){
       if(A3IPPNUM_V==1){ A3IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A3IPPNUM_V==2){ A3IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A3IPPNUM_V==4){ A3IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A3IPPNUM_V==5){ A3IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A3IPPNUM_V==6){ A3IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �����஢�� ���
int Chk_SBP3(vd){
    //-------------------------------------------
    // �᫨ �ணࠬ�� �� �� 蠣� ࠡ��� � ���誠��
    if(A3STEPW__V<100||(A3STEPW__V>290&&A3STEPW__V<800)||A3STEPW__V>890){
      // �᫨ ࠧ�����஢��� ��� - �뤠�� ������� �� �����⨥
      // ��� �������� � ��३� � ०�� ��������
      if(I3SBP1R__V>0){
        // c����� ���稪 �����஢�� ��� (���� �� �ॡ����)
        A3SBPC=0;
        // �᫨ �� ������ ��� ���� �� �஢��塞�� �ᯮ���⥫��
        if(I3ZIOPC__V!=ON|| I3ZIPPC__V!=ON||I3ZOPPC__V!=ON||I3ZOPAC__V!=ON||
           I3VZC____V!=ON||(I3KOCC___V!=ON&&(A3STEPP__V==3||A3STEP___V==3))){
////��� ��������������.���-�� �������.        
           // c����� ���稪 �⠡��쭮�� ���ﭨ� ������� �ᯮ���⥫��
           A3SBPI=0;
           //-----------
           // �᫨ �ணࠬ� � ��諠 � 蠣� �����, 祬 910(��㣮� ०��)
           if(A3STEPW__V<910){
              // 㢥����� ���稪 �ࠡ�⪨ ��� (��⠥� 5ᥪ) � ���
              if(A3SBPT <5){ A3SBPT++; return(1); }
              // ��᫥���� ࠧ ��᫥ �஢�ન ���稪� ��। �஢�મ�
              // �ᯮ���⥫��- ���㫨�� ���稪� � ⠩���� (����� ��諮 5ᥪ)
              A3STEPZ__V=0; A3STEPC__V=0; Set_BV3(A3STEPW__V);
              Message(107+A3BNM,0);
           }
           //-----------
           // ��⠭����� ०�� ������� �ᯮ���⥫�� �� ࠧ�����஢�� ���
           Set_ST3(910);
           // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // �������� ���᪠ ���ண� ��� ������?
           Set_ST3(911);
           switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return(1); }
             case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������? 
           Set_ST3(912);
           switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return(1); }
             case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM,0); Bell(3,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������?
           Set_ST3(913);
           switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return(1); }
             case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM,0); Bell(3,1); return(1); }
           }
           // �������� ���᪠ ��� � �⬮���� ������?
           Set_ST3(914);
           switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return(1); }
             case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM,0); Bell(3,1); return(1); }
           }
           // �������� ����㬠 ������?
           Set_ST3(915);
           switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return(1); }
             case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM,0); Bell(3,1); return(1); }
           }
           // �᫨ ��� �뫮 ࠧ�����஢��� � ०��� ��������������
           if(A3STEPP__V==3){
           // ������ ���᪠ �������� ������?
           Set_ST3(916);
           switch ( Check_TO(A3BTM+6, A3RCHKF__R* SEC, I3KOCC___V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3RCHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return(1); }
             case BAD: { Clear_TO(A3BTM+6); Message(146+A3BNM,0); Bell(3,1); return(1); }
           } }
           // �᫨ �� ������- ��३� � ०�� �������� ࠧ�����஢�� ���
           Set_ST3(917); return(1);
        } else {
////��� ��������������.��� �������.        
           // �᫨ �� �஢��塞� �ᯮ���⥫� �������- 㬥����� ���稪 �
           // ����� �� 蠣� 900, ���� ����������� ���
           if(A3SBPI<5){ A3SBPI++; return(1); }
           // ��᫥ ���稪� �⠡��쭮�� ������� �ᯮ���⥫��-
           // ����� ���稪 ��������  ������� �ᯮ���⥫��
           A3SBPT=0;
           // �᫨ ࠧ�����஢��� ��� � �����-� ०���,�� �� �ᯮ���⥫�
           // �������- �뤠�� ᮮ�饭�� � 㪠������ ०��� �� ���஬ 
           // �������஢��� ���
           if(A3STEPW__V<900){ Set_BV3(A3STEPW__V); Message(106+A3BNM,0); }
           // �᫨ �ᯮ���⥫� �뫨 ������� ��᫥ ࠧ�����஢�� ���-
           // �뤠�� ᮮ�饭�� � ⮬, �� �ᯮ���⥫� ����뫨
           if(A3STEPW__V>900){ Message(108+A3BNM,0); }
           Set_ST3(900);
        }
      } else {
////��� �������������.
        // �᫨ ��� �������஢��� � ��᫥���� �믮��塞� 蠣 �� �����⨥
        // �������� �� ࠧ�����஢�� ���
        if(A3STEPW__V>=900){
           // ������� 5ᥪ �⠡��쭮� �����஢�� ���
           if(A3SBPC<5){ A3SBPC++; return(1); }
           // ��३� � ०�� ��������
           Message(109+A3BNM,0); Set_BV3(910); Set_ST3(50); return(1);
        }
        // ����� ��� �������஢���- ����� ���稪� �����஢�� ��� � ���
        A3SBPT=0;
        A3SBPC=0;
        A3SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �ᯮ���⥫�� �� ࠡ�� � ���誠��
int Chk_IF3(int mode){
    // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
    if(I3ZIOPC__V!=ON){ Message(141+A3BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
    if(I3ZIPPC__V!=ON){ Message(142+A3BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
    if(I3ZOPPC__V!=ON){ Message(143+A3BNM,0); return(0); }
    // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
    if(I3ZOPAC__V!=ON){ Message(144+A3BNM,0); return(0); }
    // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
    if(I3VZC____V!=ON){ Message(145+A3BNM,0); return(0); }
    // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
    if(I3KOCC___V!=ON){ Message(146+A3BNM,0); return(0); }
    // ��� ࠧ�����஢��?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I3SBP1R__V==0){ Message(149+A3BNM,0); return(0); }
    }
    // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I3P1_N___V==0){ Message(156+A3BNM,0); return(0); }
    }
    // ���� ����殮��� �� �� �ࠢ� ���஭��ᮬ? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I3VACKR__V!=ON){ Message(157+A3BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ���誠�� ��⮪���� ���⠭�? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I3LUCDU__V!=ON){ Message(158+A3BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ��⮪����� ���⠭��(��)?
    if(mode==0 or mode==1){
      if(I3DU_____V!=ON){ Message(188+A3BNM,0); return(0); }
    }
    // �஢�ઠ ࠡ��� (����祭���� ���ﭨ�) ���஭��� 
    // �������� ����祭�� ���஭���               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I3GNS_1__V!=ON){ Message(160+A3BNM,0); return(0); }
    }
    // �᫨ ����� ������ ����
    if(mode>0){
       // �᫨ �� - ���室�� � ०�� ����������
       if(I3KR1SB__V==ON || I3GNS0B__V==ON){
          A3CISP=0; Message(168+A3BNM,0); Set_BV3(870); Set_ST3(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_03(vd){

    // ��⠭����� 䫠� ����� ��஫� ����᪠ 横�� � ��३�
    // �� ०��  "��������������"
    if (A3CYCRN__M>OFF){ A3CYCRN__V=ON; A3CYCRN__M=OFF; Set_ST3(300); }
    // ��⠭����� 䫠� ����� ��஫� ��⠭���� 横��
    if (A3CYCST__M>OFF){ A3CYCST__V=ON; A3CYCST__M=OFF; Set_ST3(50);  }
    // ��⠭����� 䫠� ����� ��஫� ���室� �� ������� 蠣
    if (A3ISPST__M>OFF){ A3ISPST__V=ON; A3ISPST__M=OFF; }

    // ��।������ ����� ०��� �� 蠣�
    A3STEP___V=floor( A3STEPW__V*0.01);
    // �஢�ઠ �࠭�筮�� ���祭�� ���������� 蠣�
    if (A3STEPW__M<0  or A3STEPW__M>900){ A3STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  �᫨ �� ������� 蠣 ࠡ��� ��⮪���� � ������ ��஫� ��������� 蠣�
    if (A3STEPW__M!=A3STEPW__V and A3ISPST__V==ON){
        //  �᫨ ��࠭ ������ ����� �ࠢ����� � ������ ��஫�
        //  ����᪠ ��� ��⠭��� 横��
        if((A3STEPW__M<=10)){
            A3STEPW__V =A3STEPW__M; Message(130+A3BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=100) and (A3STEPW__M< 200) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(131+A3BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=200) and (A3STEPW__M< 300) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(132+A3BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=300) and (A3STEPW__M< 400) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(133+A3BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=400) and (A3STEPW__M< 500) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(134+A3BNM,0); A3NAKPPREM=A3NAKPP__R;
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=500) and (A3STEPW__M< 600) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(135+A3BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A3STEPW__M>=600) and (A3STEPW__M< 700) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(136+A3BNM,0);
        }
        //-------------------------------------------------------------------
        //  ��⠭���� ����� ��।�������� ०��� ࠡ��� 
        if (A3STEPW__M == A3STEPW__V){ Set_BV3(0); }
        else                         { A3STEPW__M=A3STEPW__V; }
    }
//  // ----------------------------------------------------------------------







//  // ----------------------------------------------------------------------
//  // �஢�ન � ����஫� ��� ������ ����� ᥪ㭤�
    if(NewSEC>0){ 
       //-------------------------------------------
       // ������ �६��� ࠡ��� � ⥪�饬 ०���
       // ����� ᥪ㭤�
       A3STEPS__V++;
       // ����� ������
       if(A3STEPS__V>59){ A3STEPM__V++; A3STEPS__V=0; }
       // ����� ���
       if(A3STEPM__V>59){ A3STEPH__V++; A3STEPM__V=0; }
       // �१ 99 �ᮢ �६� ��⠥��� ᭠砫� (4,5 ��⮪)
       if(A3STEPH__V>99){ A3STEPH__V=0; A3STEPM__V=0; A3STEPS__V=0; }
       //-------------------------------------------
       // �᫨ �� ������ ��஫�- ��⠭���������� 䫠� ����� ��஫�, �����
       // ����⢨⥫�� 10 ᥪ㭤
       if(A3ISPST__V==ON or A3CYCST__V==ON or A3CYCRN__V==ON){ A3ISPST__C++; }
       // �᫨ ��諮 ����� 10 ᥪ ��᫥ ����� ��஫�- ����� 䫠� ����� 
       // ��஫�  � ���稪 ᥪ㭤 (��஫� �㦭� ������� ������)
       if(A3ISPST__C >10){ 
          A3ISPST__C=0; A3ISPST__V=OFF; A3CYCST__V=OFF; A3CYCRN__V=OFF;
       }
       //-------------------------------------------
       // �᫨ �� ������� ०�� �ࠢ����� ࠡ�⮩ ��⮪���� (��/��)
       if(S3MDUP___V!=S3MDU____V){
          // ��ॢ����� �� ��� - ��ॢ��� �ணࠬ�� � ०�� "��������"
          if(S3MDU____V==0){
             Message(137+A3BNM,0); Set_BV3(0); Set_ST3(50);
          }
          // ��ॢ����� �� ��  - �뤠�� ᮮ�饭��  � � ०�� "��������"
          if(S3MDU____V==1){
             Message(138+A3BNM,0); Set_BV3(0); Set_ST3(50);
          }
       }; S3MDUP___V=S3MDU____V;
       //-------------------------------------------
       if(Chk_SBP3()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �������� ������ ������ ������-������� ��⮪���� �� ०��� "��������"
    if (A3STEPW__V<=10||A3STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // �������� ������ ������ ����祭�� ���஭���
        // �᫨ �����- ��३� �� 蠣 870
        if(V3GNS1BS_V<1){
           if(I3GNS1B__V>0){
              Message(183+A3BNM,0); O3GNS____M=ON; A3CISP=0;
              Set_BV3(50); V3GNS1BS_V=1; Set_ST3(870); return;
           }
        }
        // �몫�祭�� ���஭���
        if(I3GNS0B__V>0){
           V3GNS1BS_V=0; O3GNS____M=OFF;
        }
        //-----------
        // ����஫� ��⮢���� ��⮪���� ��३� � ०�� "���������"
        //(�������� � ��⮪���� �.�.  >1 � ������� �� ��������, ������� �
        // �ᯮ���⥫� ���襪, �� �� ���⠭樨).
        if(AIP3P____V>1 and I3ZIOPC__V>0 and I3ZIPPC__V>0 and I3ZOPPC__V>0 and
           I3VZC____V>0 and I3ZOPAC__V>0 and I3KIPC___V>0 and I3KOPC___V>0 and
           I3DU_____V>0 and
           I3SBP1Z__V>0 ){
           // ��।�����, �� ��㣨� �� �� ��室���� � ०��� ��९�᪠
           if(Get_RA3(0)>0){
              // �᫨ �����-� �� ����訢��� ����� ��� ���������-
              // ��।����� ��� �����
              if(Get_RA3(1)>0){
                 // ��३� �� ०�� ��������
                 Message(129+A3BNM,0); Set_BV3(0); Set_ST3(700);
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
    if (A3STEPW__V>=50 and A3STEPW__V<70){
       // �᫨ �諨 � 蠣� 232:- ������� 宬�� 
       if(A3STEPWP_V==232){

       }
       // ���� ������� � ��� �ᯮ���⥫��
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS3(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR3(1,STOP,STOP,STOP);
       Set_KR3(2,STOP,STOP,STOP);
       // �몫���� ���஭���
       O3GNS____M=OFF;
       // ����� ������� ����祭�� ���஭���
       V3GNS1BS_V=0;
       // ���� ����窨 � �롮� ०���� 横��
       A3NAKPP_YM=OFF;  A3NAKPP_YV=A3NAKPP_YM;
       A3RAZVK_YM=OFF;  A3RAZVK_YV=A3RAZVK_YM;
       A3PPP___YM=OFF;  A3PPP___YV=A3PPP___YM;
       A3PVID__YM=OFF;  A3PVID__YV=A3PVID__YM;
       A3SP____YM=OFF;  A3SP____YV=A3SP____YM;
       // ������ ⥪�騥 ⠩���� � ���稪�
       Clear_TA3();
       A3PPSTEP_V=0;
       // ��३� � ०�� ��������
       Message(189+A3BNM,0); Set_BV3(50); Set_ST3(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  ����祭�� �����������
//  // ----------------------------------------------------------------------
    if (A3STEPW__V>=870 and A3STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST3(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        //-----------
        // �᫨ ����� ������ �몫�祭�� ���஭���- �뤠�� �������� �� 
        // �몫�祭�� ���஭���
        if(I3GNS0B__V==ON){ 
           Message(184+A3BNM,0);
           // �뤠�� ������� �� �몫�祭�� ���஭���
           O3GNS____M=OFF;
           // ����� 䫠� ���ﭨ� ������ ����祭�� ���஭���
           V3GNS1BS_V=0; 
        }
        // �᫨ ����㯨�� ������� �� �몫�祭�� ���஭���
        if(V3GNS1BS_V==0&&O3GNS____M==OFF){
           // ���� ������� � �ᯮ���⥫�� ��堭����� ���誨
           //      N BY   HM   KR
           Set_KR3(1,STOP,STOP,STOP);
           Set_KR3(2,STOP,STOP,STOP);
           // ���� ������� � �ᯮ���⥫�� ��������
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ����� �몫�祭�� ���஭���
           switch( Check_TO(A3BTM+1,60*SEC, I3GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A3BNM,0); Bell(3,1); break; }
              case END: { Message(185+A3BNM,0); break; }
           }
           // ��३� � ०�� ��������
           Set_BV3(870); Set_ST3(50); return;
        }
        // �஢�ઠ ���ﭨ� �ᯮ���⥫��
        if(Chk_IF3(0)==0){
           A3CISP++; 
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(50); 
           }
           return; 
        }; A3CISP=0;
        //-----------
        // �뤠�� �������� �� ����祭�� ���஭���:
        O3GNS____M= ON;
        //-----------
        // �������� ������ ������ "������ ��⮪���"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I3KR1OBS_V<1 and I3KR1CBS_V<1){
           if(I3KR1OB__V>0){
              Message(174+A3BNM,0); A3CISP=0;
              Set_BV3(50); I3KR1OBS_V=1; V3GNS1BS_V=1; Set_ST3(100); return;
           }
        }
        //-----------
        // �������� ������ ������ "������� ��⮪���"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I3KR1OBS_V<1 and I3KR1CBS_V<1){
           if(I3KR1CB__V>0){
              Message(176+A3BNM,0);  A3CISP=0;
              Set_BV3(50); I3KR1CBS_V=1; V3GNS1BS_V=1; Set_ST3(200); return;
           }
        }
        //-----------
        Clear_TA3();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������" ��3
//  // ----------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A3STEPW__V>=100 and A3STEPW__V< 130){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O3GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V!=126){ Message(195+A3BNM,0); }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST3(126);
        I3KR_TMP_V=-1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(126); Set_ST3(870); return;}
        switch ( Check_TO(A3BTM+14,A3THMUP__R*SEC, I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R;A3STEPC__V =CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(151+A3BNM,0);
                        // �᫨ �� ���� 蠣 ����஫�- 㢥����� ���稪 
                        // ����஫� � ���� ������� �� �����⨥ 宬��
                        if(A3TEMP<1){ 
                           if(I3KR1OBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
                           A3TEMP++;
                        }
                        // �᫨ �� ��ன 蠣 ����஫�- ������ � ���室 �
                        // ०�� ��������
                        else        { Bell(3,1); Set_BV3(126); Set_ST3(870); }
                        return;
                      }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15);
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        Clear_TO(A3BTM+18); Clear_TO(A3BTM+19);
        A3STEPZ__V=0; A3STEPC__V=0;
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        Set_ST3(130);  A3TEMP=0;
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������":
    if (A3STEPW__V>=130 and A3STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O3GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST3(132);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3BY1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(132); Set_ST3(870); return;}
        // �᫨ ������� �� �����
        if(I3KR_TMP_V==OFF){
//         // ������� �� ����⨥ �������              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // �������� �����ᠬ�: 2ᥪ ������, 2ᥪ ��㧠
           if(A3TEMP<2){
             // ������ �� ����⨥
             if(I3KR1OBS_V>0){ O3BY1O___M=ON; O3BY1C___M=OFF; }
             A3TEMP++;
           } else {
             // ��㧠
             if(A3TEMP<4){
                O3BY1O___M=OFF; O3BY1C___M=OFF;
                O3BY2O___M=OFF; O3BY2C___M=OFF;
                A3TEMP++;
             } else {
             // ���室 ��᫥ ���� �� ������
                if(A3TEMP<7) A3TEMP=0;
             }
           }  
        }
        switch (Check_TO( A3BTM+16,A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(154+A3BNM,0); Bell(3,1); 
                        Set_BV3(132); Set_ST3(870);
                        return; 
                      }
        }
        // ��� 䫠�� ����� �����᭮�� ᨣ���� �� �������
        A3TEMP=10;
        // ���� ������� �� ����⨥ ������⮢          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O3BY1O___M=OFF; O3BY1C___M=OFF;
        O3BY2O___M=OFF; O3BY2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A3BTM+17,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+17]; return; }
        }
//      // ������� �� �����⨥ 宬��                   [x6.o01 (OxHM1UP) = 1]
        if(I3KR1OBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        Set_ST3(131);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(131); Set_ST3(870); return;}
        switch (Check_TO( A3BTM+14,A3THMUP__R*SEC,I3KR_TMP_V, '=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(151+A3BNM,0); Bell(3,1);
                        Set_BV3(131); Set_ST3(870);    return;
                      }
        }
        // ���� ������� �� �����⨥ 宬��             [x6.o01 (OxHM1UP) = 0]
        O3HM1UP__M=OFF; O3HM1DN__M=OFF;
        O3HM2UP__M=OFF; O3HM2DN__M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        //--------
//      // ������� �� ����⨥ ���誨                   [x6.o03 (OxKR1O_) = 1]
        if(I3KR1OBS_V>0){ O3KR1O___M=ON; O3KR1C___M=OFF; }
        // ���誨 ������?                              [x7.i02 (IxKR1O_) = 1]
        Set_ST3(133);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3KR1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(133); Set_ST3(870);  return;}
        switch (Check_TO( A3BTM+18,A3TKRO___R*SEC, I3KR_TMP_V, '=',ON,1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+18); Message(152+A3BNM,0); Bell(3,1); 
                        Set_BV3(133); Set_ST3(870);
                        return; 
                      }
        }
        // ������� � ���襪 ᭨��� ��᫥ ���᪠��� 宬��

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO(A3BTM+19,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+19]; return; }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15);
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        Clear_TO(A3BTM+18); Clear_TO(A3BTM+19);
        A3STEPZ__V=0; A3STEPC__V=0;
        //
        Set_ST3(134); A3TEMP=0; return;
    }
//  // ----------------------
//  //  ���᪠��� 宬��
    if (A3STEPW__V>=134 and A3STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O3GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
//      // ������� �� ���᪠��� 宬�⮢                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I3KR1OBS_V>0){ O3HM1DN__M=ON; O3HM1UP__M=OFF; }
        // 宬��� ���饭�?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST3(134);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1DN__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(134); Set_ST3(870);  return;}
        switch (Check_TO( A3BTM+14,A3THMUP__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(150+A3BNM,0); Bell(3,1); 
                        Set_BV3(134); Set_ST3(870);
                        return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        Message(191+A3BNM,0);
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"->"��������"|"���"
        Message(197+A3BNM,0); Set_BV3(141); Set_ST3(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A3STEPW__V>=200 and A3STEPW__V< 230){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O3GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V==200){ Message(196+A3BNM,0); }
        //--------
        // 宬�� ���饭?                                [x7.i01 (IxHM1DN) = 1]
        Set_ST3(226);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3HM1DN__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(226);  Set_ST3(870); return;}
        switch ( Check_TO (A3BTM+14, A3THMUP__R*SEC,   I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V = CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(150+A3BNM,0); Bell(3,1); 
                        Set_BV3(226); Set_ST3(870);   return; 
                      }
        }
        // �뤠�� �������� �� ����⨥ �������
        if(I3KR1CBS_V>0){ O3BY1O___M=ON; O3BY1C___M=OFF; }
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        // �᫨ ������� �� ������- ���
        Set_ST3(228);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3BY1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(228); Set_ST3(870); return;}
        switch ( Check_TO (A3BTM+15, A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+15); Message(154+A3BNM,0); Bell(3,1);
                        Set_BV3(228); Set_ST3(870);   return; 
                      }
        }
        // ���� ������� � �������
        O3BY1O___M=OFF; O3BY1C___M=OFF;
        O3BY2O___M=OFF; O3BY2C___M=OFF;
        //
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15); 
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(230);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": �ਯ������ ��। �����⨥�
    if (A3STEPW__V>=230 and A3STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O3GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // ������� �� �ਯ����⨥ ���誨                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I3KR1CBS_V>0){ O3KR1O___M=ON; O3KR1C___M=OFF; }
        // ���誠 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST3(231);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3KR1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(231); Set_ST3(870); return;}
        switch (Check_TO(A3BTM+14,A3TKRO___R*SEC, I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(152+A3BNM,0); Bell(3,1);
                        Set_BV3(231); Set_ST3(870);   return; 
                      }
        }
        // ���� ������� �� �����⨥ ���誨             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O3KR1O___M=OFF; O3KR1C___M=OFF;
        O3KR2O___M=OFF; O3KR2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        // ������ ������� �� �����⨥ 宬��            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I3KR1CBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
        Set_ST3(232);
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(232); Set_ST3(870); return;}
        switch (Check_TO(A3BTM+16,A3THMUP__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(151+A3BNM,0); Bell(3,1);
                        Set_BV3(232); Set_ST3(870);   return; 
                      }
        }
        // ��᫥ ������� 宬�� ������� �� ᭨������

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A3BTM+17,A3TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+17]; return; }
        }
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15); 
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(235);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": ������� ���誨
    if (A3STEPW__V>=235 and A3STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O3GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM,0); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // ������� �� �����⨥ ���襪                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I3KR1CBS_V>0){ O3KR1C___M=ON; O3KR1O___M=OFF; }
        // ���誠 ������?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST3(236);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3KR1C___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(236); Set_ST3(870); return;}
        switch (Check_TO (A3BTM+14,A3TKRO___R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(153+A3BNM,0); Bell(3,1);
                        Set_BV3(236); Set_ST3(870); return; 
                      }
        }
        // ���� ������� �� �����⨥ ���襪             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O3KR1C___M=OFF; O3KR1O___M=OFF;
        O3KR2C___M=OFF; O3KR2O___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        // ������� �� �����⨥ ������⮢                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I3KR1CBS_V>0){ O3BY1C___M=ON; O3BY1O___M=OFF; }
        // �������� �������?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST3(237);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3BY1C___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(237); Set_ST3(870); return;}
        switch (Check_TO (A3BTM+16,A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(155+A3BNM,0); Bell(3,1);
                        Set_BV3(237); Set_ST3(870);   return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        Message(193+A3BNM,0);
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"
        Message(198+A3BNM,0); Set_BV3(235); Set_ST3(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A3STEPW__V>=300 and A3STEPW__V<320){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "��������������"- ��३� �� � ०��
        if(A3RAZVK_YV==OFF){ Set_BV3(300); Set_ST3(400); return; }
        // �஢�ઠ  ����㬨஢���� ��㣨� ��⮪�����
        // (�� ����㬨஢���� ����� ��室����  ������ ���� ��⮪���)
        if(A1PPSTEP_V==300||A2PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV3(300); Set_ST3(50); return; 
        }
        A3PPSTEP_V=300;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V==300){ Message(200+A3BNM,0); }
        //
        Set_ST3(311);
        // ��ॢ��� ॣ���� �������� � ��� ०��, �⮡� ������� ������
        A3RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST3(301);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST3(302);
        switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST3(303);
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST3(304);
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST3(305);
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM,0); Bell(3,1); return; }
        }
        // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
        Set_ST3(306);
        switch ( Check_TO(A3BTM+6, A3RCHKF__R* SEC, I3KOCC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3RCHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(146+A3BNM,0); Bell(3,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST3(307);
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM,0); Bell(3,1); return; }
        }
        // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST3(308);
        switch ( Check_TO(A3BTM+8, 60*SEC,I3P1_N___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+8]; return; }
            case BAD: { Clear_TO(A3BTM+8); Message(156+A3BNM,0); Bell(3,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST3(309);
        switch ( Check_TO(A3BTM+9, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+9]; return; }
            case BAD: { Clear_TO(A3BTM+9); Message(147+A3BNM,0); Bell(3,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ����㬭���      [x2.i08 (IxVNMD_) = 1]
        Set_ST3(310);
        switch ( Check_TO(A3BTM+10, 60*SEC, I3VNMD___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+10]; return; }
            case BAD: { Clear_TO(A3BTM+10); Message(162+A3BNM,0); Bell(3,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ��������          [x2.i07 (IxVZMD_) = 1]
        Set_ST3(311);
        switch ( Check_TO(A3BTM+11, 60*SEC, I3VZMD___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+11]; return; }
            case BAD: { Clear_TO(A3BTM+11); Message(182+A3BNM,0); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6); 
        Clear_TO(A3BTM+7); Clear_TO(A3BTM+8); Clear_TO(A3BTM+9); 
        Clear_TO(A3BTM+10);
        Clear_TO(A3BTM+11);
        A3STEPZ__V=0; A3STEPC__V=0;
        I3MAXVCN_V=0;
        Set_ST3(320);
        return;
    }
//  // ----------------------
//  //  ����祭�� ����㬨஢����
    if (A3STEPW__V>=320 and A3STEPW__V<325){
        if(!NewSEC){ return; }
        // ������� �� ����⨥ ����㬭�� ��������       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // ����㬭�� �������� �����?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST3(321);
        switch ( Check_TO(A3BTM+1, A3TVZO___R* SEC, I3VZO____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(163+A3BNM,0); return; }
        }
        // ���� ������� �� ����⨥ ����㬭�� �������� [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // ����뢠���� ������ �� ����㬭�� ����       [x4.o04 (OxAZVO_) = 1]
        O3AZVO___V=ON; O3AZVO___M=OFF;
        // ������� �� ����祭�� ����㬭��� ����       [x4.o05 (OxVN_1_) = 1]
        O3VN_1___V=ON; O3VN_1___M=OFF;
        Set_ST3(322);
        // ����㬭� ���� ����祭?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A3BTM+2, 60*SEC, I3VN_1___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(164+A3BNM,0); Bell(3,1); return; }
        }
        // �஢�ઠ ������ ���ᨬ��쭮�� ࠧ०���� �   [x2.i06 (IxMAXV_) = 1]
        // �.���⠪⭮�� ��������
        if(I3MAXV___V>0){ I3MAXVCN_V++; }
        else            { I3MAXVCN_V=0; }
        if(I3MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
           Set_ST3(325);
           return;
        }
        // �஢�ઠ ����稭� ࠧ०���� � ��⮪����     [x0.06 (AIPxyV__) = ?]
        // (����� ��� ��� ��� ���)
        Set_ST3(323);
        switch ( Check_TO(A3BTM+3, A3TVACUM_R* SEC, AIP34V___V,'<',A3RAZVK__R, 3)){
            case RUN: { A3STEPZ__V=A3TVACUM_R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Message(165+A3BNM,0); break; }
        }
        // ���� �������� �� �����⨥ ����㬭�� �������� [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(325);
        return;
    }
//  // ----------------------
//  //  �몫�祭�� ����㬨஢����
    if (A3STEPW__V>=325 and A3STEPW__V<330){
        if(!NewSEC){ return; }
        // ������� �� �����⨥ ����㬭�� ��������       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ����㬭�� �������� ������?                  [x2.i02 (IxVZC__) = 1]
        Set_ST3(326);
        switch ( Check_TO(A3BTM+1, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(166+A3BNM,0); return; }
        }
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        Set_ST3(327);
        switch (Check_TO (A3BTM+3,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
        }
        // ������ ������ �⬮���� �� ����㬭�� ���� [x4.o04 (OxAZVO_) = 1]
        O3AZVO___V=OFF; O3AZVO___M=OFF;
        // �몫���� ����㬭� ����                    [x4.o05 (OxVN_1_) = 0]
        O3VN_1___V=OFF; O3VN_1___M=OFF;
        Set_ST3(328);
        // ����㬭� ���� �몫�祭?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A3BTM+4,  120*SEC, I3VN_1___V,'=',OFF, 1)){
            case RUN: { A3STEPZ__V=120; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(167+A3BNM,0); return; }
        }
        //
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); 
        Clear_TO(A3BTM+3); Clear_TO(A3BTM+4);
        A3STEPZ__V=0; A3STEPC__V=0;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(190+A3BNM,0); Set_ST3(330);
        return;
    }
//  // ----------------------
//  //  �������������� ���������
    if (A3STEPW__V>=330 and A3STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ��ॢ�� �ࠢ����� ��⮪����� � ��筮� ०��
        Set_BV3(330); Set_ST3(400);
        A3RAZVK_YM=OFF; A3RAZVK_YV=A3RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  ����� "����� ��������"
//  // -----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A3STEPW__V>=400 and A3STEPW__V<420){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� � ०��
        if(A3PPP___YV==OFF){ Set_BV3 (400); Set_ST3(500); return; }
        A3PPSTEP_V=400;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V==400){ 
           Message(201+A3BNM,0); 
           A3RPRA___M=OFF; A3RPUU1__M=RMINUS; Set_ST3(401); return; 
        }
        //
        A3NAKPPREM=A3NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST3(401);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST3(402);
        switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST3(403);
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST3(404);
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM,0); Bell(3,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST3(405);
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM,0); Bell(3,1); return; }
        }
        // ������ ���᪠ ��� ������?
        Set_ST3(406);
        switch ( Check_TO(A3BTM+6, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(128+A3BNM,0); Bell(3,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST3(407);
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM,0); Bell(3,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST3(409);
        switch ( Check_TO(A3BTM+9, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+9]; return; }
            case BAD: { Clear_TO(A3BTM+9); Message(147+A3BNM,0); Bell(3,1); return; }
        }
        // ०�� �ࠢ����� ��⮪����� "���⠭��"?     [x1.i13 (IxDU___) = 1]
        Set_ST3(410);
        switch ( Check_TO(A3BTM+10, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+10]; return; }
            case BAD: { Clear_TO(A3BTM+10); Message(159+A3BNM,0); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6); 
        Clear_TO(A3BTM+7); Clear_TO(A3BTM+8); Clear_TO(A3BTM+9); 
        Clear_TO(A3BTM+10);
        A3STEPZ__V=0; A3STEPC__V=0;
        // ��࠭ ०�� ����� �������� ������ࠫ�� ��஬?
        if(A3NAKPPREM==0) Set_ST3(430);
        else              Set_ST3(420);
        A3TEMP=0; A3FLAG=0; A3PPRT=0; A3RPRA___M=ON; A3RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  �஢�ઠ ��⮢���� ��⮪����-��।��稪� (����⨥ �� ��� ��������)
    if (A3STEPW__V>=420 and A3STEPW__V<422){
        if(!NewSEC){ return; }
        A3PPSTEP_V=420;
        Set_ST3(421);
        // ����� ���⢥ত���� � ��⮢���� � ��९��� � ��⮪����
        // ��।��稪�
        if(A3PPRT<1){
           A3PPRT=Get_RV3(); 
           return;
        }
        Set_ST3(422);
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  ����⨥ �ᯮ���⥫��:
    if (A3STEPW__V>=422 and A3STEPW__V<425){
        if(!NewSEC){ return; }
        A3PPSTEP_V=422;
        // ���� ������� �� ����⨥ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� �����?   [x3.o02 (OxZIPPO) = 1]
        Set_ST3(423);
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZIPPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(161+A3BNM,0); Bell(3,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���.���
        switch (Check_TO (A3BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        // ��३� �� ᫥���騩 蠣
        Set_ST3(425);
        return;
    }
//  // ----------------------
//  // �������� ������ �� ��-��� ������� ���᪠ ���
    if (A3STEPW__V>=425 and A3STEPW__V<427){
        if(!NewSEC){ return; }
        A3PPSTEP_V=425;
        // ����� ���⢥ত���� �� ��� ������� ���᪠ ��� �� ��⮪����
        // ��।��稪�
        if(A3PPRT<2){
           A3PPRT=Get_RV3(); 
           return;
        }
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST3(440); A3RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  � ������ࠫ�
    if (A3STEPW__V>=430 and A3STEPW__V<435){
        if(!NewSEC){ return; }
        // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ쭮�� ��� �����? [x1.i00 (IxZIOPO) = 1]
        Set_ST3(431);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(171+A3BNM,0); Bell(3,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���ண� ���
        switch (Check_TO (A3BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ���ண� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST3(440); A3RPZD___S=0; A3RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  ��ନ஢���� ������� ��室� ��� ॣ���� "������ ��������"
    if (A3STEPW__V>=440 and A3STEPW__V<445){
        if(!NewSEC){ return; }
        // ��।��塞 ������� ��室� ��� ��� ॣ���� �� ⠡���� 
        // "����� �����������"
        Set_ST3(441);
        //-----------
        // ��� ����� ⥬������� ����� ��஬:
        if(A3NAKPPREM==0){
            // �᫨ ⥪��� � ��⮪���� ����� ��।��� ������� � ⠡���-
            // ��⠭����� ������� ��室� ��� ��� ॣ���� ����� ��������
            if(A3RPZD___S==0){ 
               A3RPZD___M =A31NTOF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=1;
            }
            if(AIT3P____V>=A31NTOP02R  and A3RPZD___S<=2){ 
               A3RPZD___M =A31NTOF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=2;
            }
            if(AIT3P____V>=A31NTOP03R  and A3RPZD___S<=3){ 
               A3RPZD___M =A31NTOF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=3;
            }
            if(AIT3P____V>=A31NTOP04R  and A3RPZD___S<=4){ 
               A3RPZD___M =A31NTOF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=4;
            }
            if(AIT3P____V>=A31NTOP05R  and A3RPZD___S<=5){ 
               A3RPZD___M =A31NTOF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=5;
            }
        } else {
        // ��� ����� ⥬������� ��९�᪭� ��஬:
            if(A3RPZD___S==0){
               A3RPZD___M =A31NTPF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=1;
            }
            if(AIT3P____V>=A31NTPP02R  and A3RPZD___S<=2){
               A3RPZD___M =A31NTPF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=2;
            }
            if(AIT3P____V>=A31NTPP03R  and A3RPZD___S<=3){
               A3RPZD___M =A31NTPF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=3;
            }
            if(AIT3P____V>=A31NTPP04R  and A3RPZD___S<=4){
               A3RPZD___M =A31NTPF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=4;
            }
            if(AIT3P____V>=A31NTPP05R  and A3RPZD___S<=5){
               A3RPZD___M =A31NTPF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=5;
            }
        }
        //-----------
        // �᫨ �������� � ��⮪���� ����� ⮣�, �� ��।�����
        // � ��ࢮ� ��ப� ⠡���� "����� ��������" - ��।��塞 �������
        // ��室�  ��� ��� ॣ���� �� ⠡���� "����� ��������"
        // ��� ����� �������� ����� ��஬:
        if(A3NAKPPREM==0){
            if(AIP3P____V>=A31NPOP01R  and A3RPZD___S<=6){ 
               A3RPZD___M =A31NPOF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=6;
            }
            if(AIP3P____V>=A31NPOP02R  and A3RPZD___S<=7){ 
               A3RPZD___M =A31NPOF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=7;
            }
            if(AIP3P____V>=A31NPOP03R  and A3RPZD___S<=8){ 
               A3RPZD___M =A31NPOF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=8;
            }
            if(AIP3P____V>=A31NPOP04R  and A3RPZD___S<=9){ 
               A3RPZD___M =A31NPOF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=9; 
            }
            if(AIP3P____V>=A31NPOP05R  and A3RPZD___S<=10){ 
               A3RPZD___M =A31NPOF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=10;
            }
            if(AIP3P____V>=A31NPOP06R  and A3RPZD___S<=11){ 
               A3RPZD___M =A31NPOF06R; A3RPZD___V=A3RPZD___M; A3RPZD___S=11;
            }
            if(AIP3P____V>=A31NPOP07R  and A3RPZD___S<=12){ 
               A3RPZD___M =A31NPOF07R; A3RPZD___V=A3RPZD___M; A3RPZD___S=12;
            }
            if(AIP3P____V>=A31NPOP08R  and A3RPZD___S<=13){ 
               A3RPZD___M =A31NPOF08R; A3RPZD___V=A3RPZD___M; A3RPZD___S=13;
            }
            if(AIP3P____V>=A31NPOP09R  and A3RPZD___S<=14){ 
               A3RPZD___M =A31NPOF09R; A3RPZD___V=A3RPZD___M; A3RPZD___S=14;
            }
            if(AIP3P____V>=A31NPOP10R  and A3RPZD___S<=15){ 
               A3RPZD___M =A31NPOF10R; A3RPZD___V=A3RPZD___M; A3RPZD___S=15;
            }
        } else {
        // ��� ����� �������� ��९�᪭� ��஬:
            if(AIP3P____V>=A31NPPP01R  and A3RPZD___S<=6){ 
               A3RPZD___M =A31NPPF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=6;
            }
            if(AIP3P____V>=A31NPPP02R  and A3RPZD___S<=7){ 
               A3RPZD___M =A31NPPF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=7;
            }
            if(AIP3P____V>=A31NPPP03R  and A3RPZD___S<=8){ 
               A3RPZD___M =A31NPPF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=8;
            }
            if(AIP3P____V>=A31NPPP04R  and A3RPZD___S<=9){ 
               A3RPZD___M =A31NPPF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=9;
            }
            if(AIP3P____V>=A31NPPP05R  and A3RPZD___S<=10){ 
               A3RPZD___M =A31NPPF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=10;
            }
            if(AIP3P____V>=A31NPPP06R  and A3RPZD___S<=11){ 
               A3RPZD___M =A31NPPF06R; A3RPZD___V=A3RPZD___M; A3RPZD___S=11;
            }
            if(AIP3P____V>=A31NPPP07R  and A3RPZD___S<=12){ 
               A3RPZD___M =A31NPPF07R; A3RPZD___V=A3RPZD___M; A3RPZD___S=12;
            }
            if(AIP3P____V>=A31NPPP08R  and A3RPZD___S<=13){ 
               A3RPZD___M =A31NPPF08R; A3RPZD___V=A3RPZD___M; A3RPZD___S=13;
            }
            if(AIP3P____V>=A31NPPP09R  and A3RPZD___S<=14){ 
               A3RPZD___M =A31NPPF09R; A3RPZD___V=A3RPZD___M; A3RPZD___S=14;
            }
            if(AIP3P____V>=A31NPPP10R  and A3RPZD___S<=15){ 
               A3RPZD___M =A31NPPF10R; A3RPZD___V=A3RPZD___M; A3RPZD___S=15;
            }
        }
        //-----------
        // �᫨ ��⮪��� � ०��� ����� �������� ��९�᪭�  ��஬ �
        // �᫨ ࠧ��� �������� ����� ��-��।��稪�� � ��-�ਥ������
        // ����� ��������� (AxZPPRE__R) -��३� �� 蠣
        // ������� �ᯮ���⥫�� ����� ��९�᪭��� ��� � �ନ஢����
        // ������� ��室� ��� ॣ���� "������ ��������" �� ���஬� ����
        A3PPSTEP_V=440; Get_RV3();
        if(A3NAKPPREM>0 and AIPRP3___V-AIP3P____V < A3ZPPRE__R){
           Set_ST3(480); A3PPRT=0; return;
        }

        //-----------
        // �᫨ �������� � ��⮪���� ����� ��������� � "���������� �����"-
        // ��३� �� 蠣 ������� �ᯮ���⥫�� ������ࠫ쭮�� ���
        if(A3NAKPPREM==0 and A3PPP____R>0 and AIP3P____V>=A3PPP____R){
           if(A3TEMP <7){ 
              A3TEMP++;     
           } else { 
              Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
              Set_ST3 (450);
           }
           return;
        } else {
           A3TEMP=0;
        }
        //-----------
        // �᫨ ����� �������� ���� � ������ࠫ� � �������� � ��⮪���� 
        // �����,祬 �������� � ������ࠫ�- ������� �������� ���᪠ ���� ���
        if(A3NAKPPREM==0 and AIP3P____V>=AIP34M___V){
           Set_ST3(442);
           // ���� ������� �� �����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // �᫨ ��९�� �������� ����� �� � ������ࠫ�� �⠡�����஢����
        if(A3NAKPPREM==0 and AIP3P____V< AIP34M___V-A3ZNPM___R){
           Set_ST3(443);
           // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS3(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ࠫ쭮�� ��� � ���室 �� "��������"
    if (A3STEPW__V>=450 and A3STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A3BTM+2, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(128+A3BNM,0); Bell(3,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_BV3(440); Set_ST3(500);
        A3PPP___YM=OFF;  A3PPP___YV=A3PPP___YM;  
        // ᮮ�饭�� �� ����砭�� ०���
        Message(202+A3BNM,0);
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ��९�᪭��� ��� �� ��-���
    if (A3STEPW__V>=480 and A3STEPW__V<482){
        if(!NewSEC){ return; }
        A3PPSTEP_V=480;
        Set_ST3(481);
        // ����� ���⢥ত���� � �����⨨ �ᯮ���⥫�� ���᪠ ��� ��
        // ��⮪���� ��।��稪�
        if(A3PPRT<3){
           A3PPRT=Get_RV3(); return;
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(482);
        return;
    }
//  // ----------------------
    if (A3STEPW__V>=482 and A3STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST3(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� ������?
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(142+A3BNM,0); Bell(3,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A3BTM+2, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(128+A3BNM,0); Bell(3,1); return; }
        }
        // �� �����⨨ ���  �ᯮ���⥫�� ��९�᪭��� ���, �����頥���
        // �� �ନ஢���� ������� ��室� ��� ॣ���� ������ ��������
        // �� ���஬� ����
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(440);
        A3NAKPPREM=0; A3RPZD___S=0; A3RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  ����� "��������"
//  // ----------------------------------------------------------------------
    if ((A3STEPW__V==500)||(A3STEPW__V>510&&A3STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST3(500);
        // �᫨ � 横� �� ����祭 ०�� "��������"- ��३� �� � ०��
        if(A3PVID__YV==OFF){ Set_BV3(500); Set_ST3(600); return; }
        A3PPSTEP_V=500;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V==500){ Message(203+A3BNM,0); }
        // �뤥প� ��⮪���� ��� ��������� �஢������ ������ࠫ�� ��஬
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST3(511);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(512);
        // ������ ���᪠ ��� ������?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A3BTM+2, A3RPHKF__R, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(169+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(513);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(514);
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(515);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(516);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A3BTM+6, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(142+A3BNM,0); Bell(3,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6);
        A3STEPZ__V=0; A3STEPC__V=0;
        //
        Set_ST3(501);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A3TEMP=0.3;
        A3RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A3STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST3(501);
        //-----------
        // �᫨ �������� � ��⮪���� ����� ���������-
        // ��३� ��  蠣 ������� ������� ���᪠ ���
        if(AIP3P____V>=A3PPP____R){
           Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=0; 
           return;
        }
        //-----------
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ��३� �� 蠣 ������� �������� � ������� ���᪠ ���ண� ���
        if(AIP3P____V> A3ZPAKX__R or AIP3P____V>AIP34M___V){
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=1;
           return;
        }
        //-----------
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A3STEPH__V>=A3PVIDH__R and A3STEPM__V>=A3PVIDM__R){
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=2;
           return;
        }
        //-----------

        //-----------
        // �뤥প� ��⮪���� ��� ���������  �஢������ ������ࠫ�� ��஬
        // ������  ��������  ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� �����?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPO__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(171+A3BNM,0); Bell(3,1); return; }
        }
        //-----------
        // ����  ������� �  �������� ���᪠  ���ண� ���  �
        // �뤠�� ������� �� ����⨥ ������� ���᪠  ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A3BTM+3]==0) Set_IS3(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A3BTM+3]==1) Set_IS3(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ����� A3TEMP %  ᥪ㭤 �� �������  室� ������� ���᪠ ���
        // ��� ���� �� �ࠡ�⠥� ���楢�� ������ �������
        if(I3KIPO___V<1){
           switch ( Check_TO(A3BTM+2,A3RPHKF__R*A3TEMP,ZERO,'=',ON, 1)){
               case RUN: { A3STEPZ__V=A3RPHKF__R*A3TEMP; A3STEPC__V=CNTTO[A3BTM+2]; 
                           return; 
                         }
           }
        }
        // ���� ������� � ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // ����প� 30 ᥪ㭤
        switch ( Check_TO(A3BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=30; A3STEPC__V=CNTTO[A3BTM+3]; return; }
        }
        if(AIP3P____V< A3PPP____R){
        // �᫨ �������� � ��⮪���� �� ����﫮�� �� ��������� � ������
        // ����� �� ���������- 㢥����� �६� ������ ������� � �������
        // ⥪�騩 蠣 
        //(��ਭ樯�,⠪ ����� ���뢠�� ������ ����� ������ +0.3,+0.3...)
           if(A3TEMP<0.8){
              A3TEMP=0.3;
              Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
              A3STEPZ__V=0; A3STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A3STEPW__V>=502 and A3STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST3(502);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A3TEMP=0.3;
        // �᫨ ⥪�饥 �������� � ��⮪���� ����� ���������-
        // ��३� ����� ��  蠣 ������  �������� � ������� ���᪠ ���
        if(AIP3P____V<A3PPP____R-A3ZNVD___R and 
           AIP3P____V<AIP34M___V-A3ZNPM___R and A3FLAG<2){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(501); return;
        }
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ������� �������� ���᪠ ���ண� ���
        if(AIP3P____V> A3ZPAKX__R or AIP3P____V>AIP34M___V){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); 
           A3STEPZ__V=0; A3STEPC__V=0; A3FLAG=1;
        }
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A3STEPH__V>=A3PVIDH__R and A3STEPM__V>=A3PVIDM__R){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); 
           A3STEPZ__V=0; A3STEPC__V=0; A3FLAG=2;
        }
        // �᫨ �� ����஫� ���ᨬ��쭮 �����⨬��� �������� ��� ࠧ���� ���
        // ��室 �� ०��� - ������� �������� ���᪠ ���ண� ���
        if(A3FLAG>0){
          // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // �������� ���᪠ ���ண� ��� ������?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A3BTM+5, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(141+A3BNM,0); Bell(3,1); return; }
          }
        }
        // ���� ������� �� �����⨥ ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢����  ���� ������� ���᪠ ���       [x1.i05 (IxKIPC_) = 1]
        // ������ ���᪠ ��� ������?            
        switch ( Check_TO(A3BTM+4, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,  1 )){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(170+A3BNM,0); Bell(3,1); return; }
        }
        // �᫨ �� ��⠭����� 䫠� ��室�- ��३� �� ०�� "����� ��������"
        if(A3FLAG==2){ 
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_BV3(502); Set_ST3(600);
           A3PVID__YM=OFF;  A3PVID__YV=A3PVID__YM;
           // ᮮ�饭�� �� ����砭�� ०���
           Message(204+A3BNM,0);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  ����� "����� ��������"
    // ----------------------------------------------------------------------
    if ((A3STEPW__V==600)||(A3STEPW__V>610&&A3STEPW__V<620)){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� ���.०��
        if(A3SP____YV==OFF){ Set_BV3(600); Set_ST3(50); return; }
        // �஢�ઠ ������ �������� ��㣨� ��⮪�����
        // (�� ������ �������� ����� ��室���� ������ ���� ��⮪���)
        if(A1PPSTEP_V==600||A2PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV3(600); Set_ST3(50); Message(110+A3BNM,0); return; 
        }
        A3PPSTEP_V=600;
        // ᮮ�饭�� � ��砫� ०���
        if(A3STEPW__V==600){ Message(205+A3BNM,0); }
        //
        A3RPRA___M=ON;
        //-----------
        // ��।������ ��ࢮ��砫쭮�� ��業� ������ ������� ��� ���
        A3FLAG=0; A3FLGP=0; if(A3TKLO___R==0) A3TKLO___R=100;
        A3FLAG=5; A3TEMP=A31SPKK05R; 
        if(A3SPAT___R>0) A3TEMP=A31SPAK05R; if(A3TEMP==0) A3TEMP=20;
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A3SPAT___R>0){ A3TEMP=A3TKLO___R*0.01*A3TEMP; }
        // �᫨ ��।���� ��� ��� � �������
        else            { A3TEMP=A3TKLO___R*0.01*A3TEMP; }
        // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
        if(A3SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST3(611);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(613);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(615);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(616);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A3BTM+6, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(142+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(617);
        // ��� �������஢��?                            [x7.i08 (IxSBP1Z) = 1]
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM,0); Bell(3,1); return; }
        }
        Set_ST3(618);
        // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
        // �⬮����
        if(A3SPAT___R>0){
          // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
          // �⬮����
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A3BTM+8, A3TZSPA__R* SEC, I3ZOPAO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+8]; return; }
            case BAD: { Clear_TO(A3BTM+8); Message(173+A3BNM,0); Bell(3,1); return; }
          }
        }
        Clear_TO(A3BTM+1);  Clear_TO(A3BTM+2);  Clear_TO(A3BTM+3);  
        Clear_TO(A3BTM+4);  Clear_TO(A3BTM+5);  Clear_TO(A3BTM+6);  
        Clear_TO(A3BTM+7);  Clear_TO(A3BTM+8);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(602);
        return;
    }
//  // ----------------------
//  //  ��� ��� �� ⠡���
    if (A3STEPW__V>=602 and A3STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST3(602);
        // ��᢮��� ��६����� ��業�(�६� � ᥪ㭤��) ������ ������� 
        // (�� �������  �६��� 室� �������) �� ⠡���  ᮮ⢥��⢥���
        // ⥪�饣� ��������  � ��⮪����
        // ⠡��� ��ᬠ�ਢ����� �� ����襣� � ����襬� (᭨�� �����)
        // ��� ������ �� �।��騩 蠣

        // �᫨ ⥪�饥 �������� �����-1 ��� ⥪�饥 ��������
        // ����� ��᫥����� 㪠������� � ⠡��� "����� ��������"(᭨��-�����)
        // ��� ࠧ�����஢�� ���� �� ���- ��३� �� ᫥� ०��
        if(AIP3P____V<-1 or A3FLAG==1 or I3SBP1R__V>0){
           Set_ST3(605); Clear_TO(A3BTM+2); A3STEPZ__V=0; A3STEPC__V=0; A3FLGP=0;
           return;
        }
        
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A3SPAT___R>0){
           Set_ST3(603);
           if(AIP3P____V<A31SPAP04R and A3FLAG>=5){
              // ��⠥��� ࠧ��� ��業� ������ ������� ����� 
              // �।��騬 � ⥪�騬 蠣��
              A3TEMP=A3TKLO___R*0.01*(A31SPAK04R-A31SPAK05R); A3FLAG=4;
           }
           if(AIP3P____V<A31SPAP03R and A3FLAG>=4){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK03R-A31SPAK04R); A3FLAG=3;
           }
           if(AIP3P____V<A31SPAP02R and A3FLAG>=3){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK02R-A31SPAK03R); A3FLAG=2;
           }
           if(AIP3P____V<A31SPAP01R and A3FLAG>=2){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK01R-A31SPAK02R); A3FLAG=1;
           }
        } else {
           Set_ST3(604);
        // �᫨ ��࠭ ��� ��� � �������
           if(AIP3P____V<A31SPKP04R and A3FLAG>=5){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK04R-A31SPKK05R); A3FLAG=4;
           }
           if(AIP3P____V<A31SPKP03R and A3FLAG>=4){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK03R-A31SPKK04R); A3FLAG=3;
           }
           if(AIP3P____V<A31SPKP02R and A3FLAG>=3){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK02R-A31SPKK03R); A3FLAG=2;
           }
           if(AIP3P____V<A31SPKP01R and A3FLAG>=2){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK01R-A31SPKK02R); A3FLAG=1;
           }
        }
        // �᫨ �� ���室 �� ���� 蠣
        if(A3FLGP!=A3FLAG){
           // �᫨ ���祭�� A3TEMP > 0 - ���뢠�� ������ ���᪠ ���,
           // ���� - ����뢠��
           if(A3TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // �������� ���祭��
           A3TEMP=fabs(A3TEMP);  
           A3FLGP=A3FLAG;
           // ���㫨�� ⠩��� � ���稪� ��� ��ࠡ�⪨ ����� ���祭��
           Clear_TO(A3BTM+1); A3STEPZ__V=0;  A3STEPC__V=0;
        }
        // ��⠥� �६� �������⢨� ᨣ���� �� ������
        switch ( Check_TO(A3BTM+1, A3TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TEMP; A3STEPC__V=CNTTO[A3BTM+1]; return; }
        }
        // ��᫥ ��ࠡ�⪨ ⠩���- ���� ᨣ���� � �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  ����ୠ� �஢�ઠ � ��室 �� ⥪�饣� ०��� � ०�� "��������"
    if (A3STEPW__V>=605 and A3STEPW__V<607){
        if(!NewSEC){ return; }
        // �᫨ ⥪�饥  �������� ����� ��� ࠢ��  ��� 
        // ���  ����襬� ���祭�� � ⠡���- 㢥��� ���稪
        if(AIP3P____V<=0 or A3FLAG==1 or I3SBP1R__V>0){
           A3FLGP++; 
        // ���� - 㬥�����
        } else { 
           A3FLGP--; 
        }
        // 10 ᥪ �������� 
        switch ( Check_TO(A3BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // �᫨ ���稪 ������⥫�� - 
        // ��३� �� 蠣 ������� �ᯮ���⥫��
        if(A3FLGP>2){
           Set_ST3(607); Clear_TO(A3BTM+1);
        } else {
        // �᫨ ���稪 ����⥫�� - �������� �� ����� ��������
           Set_ST3(603); A3FLGP=A3FLAG;
        }; Clear_TO(A3BTM+2); A3STEPZ__V =0; A3STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ �������� � ��室 �� ०���
    if (A3STEPW__V>=607 and A3STEPW__V<609){
        if(!NewSEC){ return; }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ��� ��� � �⬮����
        switch ( Check_TO(A3BTM+1, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(144+A3BNM,0); Bell(3,1); return; }
        }
        // �஢�ઠ ������� ������� ���᪠ ���
        switch ( Check_TO(A3BTM+2, A3TKLO___R* SEC, I3KOPC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(139+A3BNM,0); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_BV3(602); Set_ST3(50);
        A3SP____YM=OFF; A3SP____YV=A3SP____YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(206+A3BNM,0);
        return;
    }
//  // ----------------------







    //  ����� "�������� ��������" ��3
    //  �᫨ ��⮪��� ���� �� ��ॡ��, ������ �� �⠢�� � ���� ������
    //  "����� ��������".  ����� ��᫥ "��������" ��⮪��� ���室�� � ०��
    //  "��������". � �⮬ ०��� �� ����� ��室���� ᪮�� 㣮��� �����.
    //  � ��� ������ ������ ����� �ࠢ���� ��⮪����� ������ ��� � ��.
    //  �� ��� ࠡ��� � ०��� "��������" ��⮪��� ������ ��室���� � ०���
    //  �� � ������묨 ���������� � ���������.
    //  ��� ⮫쪮 ��襫  ����� �� ��ॡ�� � �⮣� ��⮪���� - ��⮪���
    //  ���室�� � ०�� "��������"
//  // ----------------------------------------------------------------------
    if (A3STEPW__V>=700 and A3STEPW__V<702){
        if(!NewSEC){ return; }
        A3RPRA___M=ON;
        // ������ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������ �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZOPPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(179+A3BNM,0); Bell(3,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A3PPSTEP_V=700;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_ST3(702);
        return;
    }
//  // ----------------------
//  //  ����⨥ ������� ���᪠ ���
    if (A3STEPW__V>=702 and A3STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA3(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A3IPPSTEPV>=400&&A3IPPSTEPV<500){
           // ������� ������ �������� �� ��-��
           if(A3IPPSTEPV!=425){ return; }
        } else {
        // �᫨ ��-�� ���襫 �� ०��� ������ �������� � ��㣮� ०��-
        // ��३�  �� �����⨥ �ᯮ���⥫�� (���⠭���⭠� �����)
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(704); return;
        }
        // ������ ������ ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // �஢�ઠ ������ ������� ���᪠ ���
        switch ( Check_TO(A3BTM+1, A3TKLO___R* SEC, I3KOPO___V,'=',ON, 2 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(181+A3BNM,0); Bell(3,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A3PPSTEP_V=704;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A3BTM+1);  Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_ST3(704);
        return;
    }
//  // ----------------------
//  // �����⨥ �ᯮ���⥫�� ���᪠ ��९�᪭��� ���
    if (A3STEPW__V>=704 and A3STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA3(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A3IPPSTEPV>=400&&A3IPPSTEPV<500){
           // ������� ���� ��-�� �� ������ �㦭��� �������� � ��
           // ��३���  �� 蠣 ������� �ᯮ���⥫��
           if(A3IPPSTEPV!=480){ return; }
           // �᫨ ��-���樠�� �襫 �� ०��� ����� ��������- ����뢠��
           // �ᯮ���⥫� � ���室�� � ०��  ��������
           //(���⠭���⭠� �����)
        }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(143+A3BNM,0); Bell(3,1); return; }
        }
        // ������� ������ ���᪠ ���
        switch ( Check_TO(A3BTM+2, A3TKLO___R* SEC, I3KOPC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(139+A3BNM,0); Bell(3,1); return; }
        }
        // ��᫥ ������� ��⠭����� 䫠� ���⢥ত���� ������� �ᯮ���⥫��
        A3PPSTEP_V=705;
        // ��᫥ ����砭�� ��९�᪠ ��� ��⮪��� ��४��砥��� � ०��
        // "����� ��������"
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_BV3(704);  Set_ST3(600);
        // �᫨ ��-�� �� � ०��� ������ �������� (���⠭���⭠� �����)
        // ��ॢ��� ��� �� � ०�� ��������
        if(A3IPPSTEPV<400||A3IPPSTEPV>500){ Set_ST3(50); }
        A3SP____YM=OFF; A3SP____YV=ON;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(207+A3BNM,0);
        return;
    }
//  // ----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
