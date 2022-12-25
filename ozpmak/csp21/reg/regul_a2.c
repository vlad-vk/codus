//---------------------------------------------------------------------------

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V2GNS1BS_V = 0;           // ���ﭨ� ������ ����祭�� ���஭���

_f  far  I2KR_TMP_V = 0;           // ⥪�� ����஫ ���祭�� ��࠭  ���誨
_f  far  I2KR1CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠1
_f  far  I2KR2CBS_V = 0;           // ��� ������ "������� ��⮪���" ���誠2
_f  far  I2KR1OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠1
_f  far  I2KR2OBS_V = 0;           // ��� ������ "������ ��⮪���" ���誠2

_f  far  A2TVACUM_R = 6000;        // �६� ����㬨஢���� (100 �����)
_f  far  I2MAXVCN_V = 0;           // ���稪 �ॢ�襭�� ���� ࠧ०����
_f  far  O2ZOPPO__Y = 0;           // ᨣ��� ��� ���� ���� ��� �� �� ��।��
_f  far  I2ZOPPO__Y = 0;           //
_f  far  A2RPZD___S = 0;           // 蠣 ������� ॣ���� "������ ��������"
_f  far  A2ISPST__C = 0;           // ���稪 ��஫� ��।������ 蠣�
_f  far  A2FLAG=0;                 // �������⥫�� ��६����
_f  far  A2FLGP=0;                 //
_f  far  A2TEMP=0;                 //
_f  far  A2PPRT=0;                 // ������ �� �㭪権 ��।������ 蠣� ���
_f  far  A2SBPT=0;                 // ���稪 ࠧ�����஢�� ���
_f  far  A2SBPC=0;                 // ���稪 �����஢�� ���
_f  far  A2SBPI=0;                 // ���稪 ������� �ᯮ���⥫�� ��� ���
_f  far  A2CISP=0;                 // ���稪 ����஫� ���ﭨ� �ᯮ���⥫��


//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ �������� � �������� ��4
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS2(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  ���ண� ���
    if (i1==  ON){ O2ZIOPO__M= ON; O2ZIOPC__M=OFF; }   //  ������
    if (i1== OFF){ O2ZIOPO__M=OFF; O2ZIOPC__M= ON; }   //  �������
    if (i1==STOP){ O2ZIOPO__M=OFF; O2ZIOPC__M=OFF; }   //  ��⠭�����
    // ��९�᪭��� ��� �室�饣�
    if (i2==  ON){ O2ZIPPO__M= ON; O2ZIPPC__M=OFF; }
    if (i2== OFF){ O2ZIPPO__M=OFF; O2ZIPPC__M= ON; }
    if (i2==STOP){ O2ZIPPO__M=OFF; O2ZIPPC__M=OFF; }
    // ��९�᪭��� ��� ��室�饣�
    if (i3==  ON){ O2ZOPPO__M= ON; O2ZOPPC__M=OFF; }
    if (i3== OFF){ O2ZOPPO__M=OFF; O2ZOPPC__M= ON; }
    if (i3==STOP){ O2ZOPPO__M=OFF; O2ZOPPC__M=OFF; }
    // ��� � �⬮����
    if (i4==  ON){ O2ZOPAO__M= ON; O2ZOPAC__M=OFF; }
    if (i4== OFF){ O2ZOPAO__M=OFF; O2ZOPAC__M= ON; }
    if (i4==STOP){ O2ZOPAO__M=OFF; O2ZOPAC__M=OFF; }
    // ����㬭�� ��������
    if (i5==  ON){ O2VZO____M= ON; O2VZC____M=OFF; }
    if (i5== OFF){ O2VZO____M=OFF; O2VZC____M= ON; }
    if (i5==STOP){ O2VZO____M=OFF; O2VZC____M=OFF; }
    // ������ ���᪠ ���
    if (i6==  ON){ O2KIPO___M= ON; O2KIPO___V= ON; O2KIPC___M=OFF; O2KIPC___V=OFF; }
    if (i6== OFF){ O2KIPO___M=OFF; O2KIPO___V=OFF; O2KIPC___M= ON; O2KIPC___V= ON; }
    if (i6==STOP){ O2KIPO___M=OFF; O2KIPO___V=OFF; O2KIPC___M=OFF; O2KIPC___V=OFF; }
    // ������ ���᪠ ���
    if (i7==  ON){ O2KOPO___M= ON; O2KOPO___V= ON; O2KOPC___M=OFF; O2KOPC___V=OFF; }
    if (i7== OFF){ O2KOPO___M=OFF; O2KOPO___V=OFF; O2KOPC___M= ON; O2KOPC___V= ON; }
    if (i7==STOP){ O2KOPO___M=OFF; O2KOPO___V=OFF; O2KOPC___M=OFF; O2KOPC___V=OFF; }
    // ������ ��� ��������
    if (i8==  ON){ O2KOCO___M= ON; O2KOCO___V= ON; O2KOCC___M=OFF; O2KOCC___V=OFF; }
    if (i8== OFF){ O2KOCO___M=OFF; O2KOCO___V=OFF; O2KOCC___M= ON; O2KOCC___V= ON; }
    if (i8==STOP){ O2KOCO___M=OFF; O2KOCO___V=OFF; O2KOCC___M=OFF; O2KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ ���襪 ��5
//              NUM       BY        HM        KR 
vd  far Set_KR2(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // �������
       if (b==  ON){ O2BY1O___M= ON; O2BY1C___M=OFF; }   //  ������
       if (b== OFF){ O2BY1O___M=OFF; O2BY1C___M= ON; }   //  �������
       if (b==STOP){ O2BY1O___M=OFF; O2BY1C___M=OFF; }   //  ��⠭�����
       // 宬��
       if (h==  ON){ O2HM1UP__M= ON; O2HM1DN__M=OFF; }
       if (h== OFF){ O2HM1UP__M=OFF; O2HM1DN__M= ON; }
       if (h==STOP){ O2HM1UP__M=OFF; O2HM1DN__M=OFF; }
       // ���誠
       if (k==  ON){ O2KR1O___M= ON; O2KR1C___M=OFF; }
       if (k== OFF){ O2KR1O___M=OFF; O2KR1C___M= ON; }
       if (k==STOP){ O2KR1O___M=OFF; O2KR1C___M=OFF; }
    }
    if(n==2){
       // �������
       if (b==  ON){ O2BY2O___M= ON; O2BY2C___M=OFF; }
       if (b== OFF){ O2BY2O___M=OFF; O2BY2C___M= ON; }
       if (b==STOP){ O2BY2O___M=OFF; O2BY2C___M=OFF; }
       // 宬��
       if (h==  ON){ O2HM2UP__M= ON; O2HM2DN__M=OFF; }
       if (h== OFF){ O2HM2UP__M=OFF; O2HM2DN__M= ON; }
       if (h==STOP){ O2HM2UP__M=OFF; O2HM2DN__M=OFF; }
       // ���誠
       if (k==  ON){ O2KR2O___M= ON; O2KR2C___M=OFF; }
       if (k== OFF){ O2KR2O___M=OFF; O2KR2C___M= ON; }
       if (k==STOP){ O2KR2O___M=OFF; O2KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// ���⪠ ��� ⠩��஢ � ���稪�
vd  far Clear_TA2(vd){
    Clear_TO(A2BTM+ 1); Clear_TO(A2BTM+ 2); 
    Clear_TO(A2BTM+ 3); Clear_TO(A2BTM+ 4); 
    Clear_TO(A2BTM+ 5); Clear_TO(A2BTM+ 6);
    Clear_TO(A2BTM+ 7); Clear_TO(A2BTM+ 8); 
    Clear_TO(A2BTM+ 9); Clear_TO(A2BTM+10);
    Clear_TO(A2BTM+11); Clear_TO(A2BTM+12);
    Clear_TO(A2BTM+13); Clear_TO(A2BTM+14);
    Clear_TO(A2BTM+15); Clear_TO(A2BTM+16);
    Clear_TO(A2BTM+17); Clear_TO(A2BTM+18);
    Clear_TO(A2BTM+19);
    A2STEPZ__V=0; A2STEPC__V=0;
}
//---------------------------------------------------------------------------
//  ��⠭���� ��砫��� ���祭�� �� ᬥ�� ०��� ࠡ��� ��⮪����
vd  far Set_BV2(_f far A2STEPWPRV){
    // ��������� ����� �।��饣� 蠣�
    A2STEPP__V =A2STEP___V;
    A2STEPWP_V =A2STEPWPRV;
    // �����  䫠�� ��஫��
    A2CYCRN__V =OFF; A2CYCRN__M=OFF;
    A2CYCST__V =OFF; A2CYCST__M=OFF;
    A2ISPST__V =OFF; A2ISPST__M=OFF;
    // ���㫨�� ���稪� ०���� � ⠩��஢
    A2STEPH__V =0;   A2STEPM__V=0; A2STEPS__V=0; 
    // ����� 䫠�� �롮� ���襪 ��� ������ � �������
    I2KR1OBS_V =0;   I2KR2OBS_V =0;
    I2KR1CBS_V =0;   I2KR2CBS_V =0;
    I2KR_TMP_V=-1;
    // ���� ������� � ��� �ᯮ���⥫�� ���襪
    Set_KR2(1,STOP,STOP,STOP);
    Set_KR2(2,STOP,STOP,STOP);
    //  ���㫥��� ���祭�� ⠩��஢
    Clear_TA2();
    // ���� ������� �� 宬���
    O2HM1UP__M=OFF; O2HM1DN__M=OFF;
    O2HM2UP__M=OFF; O2HM2DN__M=OFF;
    // ���� ������� �� ��������
    O2BY1O___M=OFF; O2BY1C___M=OFF;
    O2BY2O___M=OFF; O2BY2C___M=OFF;
    // ���� ������� �� ���誨
    O2KR1O___M=OFF; O2KR1C___M=OFF;
    O2KR2O___M=OFF; O2KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  ��⠭���� ⥪�饣� 蠣� ०��� ࠡ��� ��⮪����
vd  far Set_ST2(int SS){
    A2STEPW__V=SS;
    A2STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  ����祭�� ���祭�� �� ��६����� 㤠������ ����஫��஢
//  A2PPSTEP_V - ����� 蠣� �ணࠬ�� ⥪�� ��
//  A2RPPSTEPV - �ਭ������� � ��-��� ���祭��,ᨣ���������饥 � �믮������ ��
//               ��-��� ⥪�饣� 蠣�
_f  far Get_RV2(vd){
    // �᫨ ��࠭ ����� 0- ����� ��� �������� � ������ࠫ�
    if(A2NAKPPREM==0){ return(0); }
    A2RPPSTEPV=0;
    if(A2NAKPPREM==1){ A2RPPSTEPV=A1PPSTEP_V; AIPRP2___V=AIP1P____V; }
    if(A2NAKPPREM==3){ A2RPPSTEPV=A3PPSTEP_V; AIPRP2___V=AIP3P____V; }
    if(A2NAKPPREM==4){ A2RPPSTEPV=A4PPSTEP_V; AIPRP2___V=AIP4P____V; }
    if(A2NAKPPREM==5){ A2RPPSTEPV=A5PPSTEP_V; AIPRP2___V=AIP5P____V; }
    if(A2NAKPPREM==6){ A2RPPSTEPV=A6PPSTEP_V; AIPRP2___V=AIP6P____V; }
    if(A2RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // �᫨ ⥪�騩 �� ��室���� � ०��� ������ ���.��஬
    if(A2PPSTEP_V==420){
       // �᫨ ��-��� ���襫 � ०�� ��������� � ���� �������� �� ���.���
       if(A2RPPSTEPV==700) return(1); return(0);
    }
    // ⥪�騩 �� ������� ������ ������� �� ���.��� �� ��-���
    if(A2PPSTEP_V==425){
       if(A2RPPSTEPV==704) return(2); return(0);
    }
    // ⥪�騩 �� ������� ������� �ᯮ���⥫�� ���᪠ ��� �� ��-���
    if(A2PPSTEP_V==480){
       // �᫨ �� ��-��� �ᯮ���⥫� ����뫨��
       if(A2RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  ����祭�� ⥪�饣� 蠣� ��-���樠�� (��-��) �� �⤠� ���
_f  far Get_RA2(int mode){
    // �஢���� �� ��㣨� ��⮪���� �� ��室���� � ०��� ��ॡ��
    // ��।����� �� ���ﭨ� ��९�᪭�� �������� (����,����)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A3PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // ��।����� ����� ��, ����� ����訢��� ⥪�騩 ��� �⤠� ���
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==2){ A2IPPNUM_V=1; return(1); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==2){ A2IPPNUM_V=3; return(3); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==2){ A2IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==2){ A2IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==2){ A2IPPNUM_V=6; return(6); }
       return(0);
    }
    // ��।����� ⥪�騩 蠣 �� ��-���樠�� (��-��)
    if(mode==2){
       if(A2IPPNUM_V==1){ A2IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A2IPPNUM_V==3){ A2IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A2IPPNUM_V==4){ A2IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A2IPPNUM_V==5){ A2IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A2IPPNUM_V==6){ A2IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �����஢�� ���
int Chk_SBP2(vd){
    //-------------------------------------------
    // �᫨ �ணࠬ�� �� �� 蠣� ࠡ��� � ���誠��
    if(A2STEPW__V<100||(A2STEPW__V>290&&A2STEPW__V<800)||A2STEPW__V>890){
      // �᫨ ࠧ�����஢��� ���� �� ��� - �뤠�� ������� �� �����⨥
      // ��� �������� � ��३� � ०�� ��������
      if(I2SBP1R__V>0||I2SBP2R__V>0){
        // c����� ���稪 �����஢�� ��� (���� �� �ॡ����)
        A2SBPC=0;
        // �᫨ �� ������ ��� ���� �� �஢��塞�� �ᯮ���⥫��
        if(I2ZIOPC__V!=ON|| I2ZIPPC__V!=ON||I2ZOPPC__V!=ON||I2ZOPAC__V!=ON||
           I2VZC____V!=ON||(I2KOCC___V!=ON&&(A2STEPP__V==3||A2STEP___V==3))){
////��� ��������������.���-�� �������.        
           // c����� ���稪 �⠡��쭮�� ���ﭨ� ������� �ᯮ���⥫��
           A2SBPI=0;
           //-----------
           // �᫨ �ணࠬ� � ��諠 � 蠣� �����, 祬 910(��㣮� ०��)
           if(A2STEPW__V<910){
              // 㢥����� ���稪 �ࠡ�⪨ ��� (��⠥� 5ᥪ) � ���
              if(A2SBPT <5){ A2SBPT++; return(1); }
              // ��᫥���� ࠧ ��᫥ �஢�ન ���稪� ��। �஢�મ�
              // �ᯮ���⥫��- ���㫨�� ���稪� � ⠩���� (����� ��諮 5ᥪ)
              A2STEPZ__V=0; A2STEPC__V=0; Set_BV2(A2STEPW__V);
              Message(107+A2BNM,0);
           }
           //-----------
           // ��⠭����� ०�� ������� �ᯮ���⥫�� �� ࠧ�����஢�� ���
           Set_ST2(910);
           // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // �������� ���᪠ ���ண� ��� ������?
           Set_ST2(911);
           switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return(1); }
             case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������? 
           Set_ST2(912);
           switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return(1); }
             case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return(1); }
           }
           // �������� ���᪠ ��९�᪭��� ��� ������?
           Set_ST2(913);
           switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return(1); }
             case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return(1); }
           }
           // �������� ���᪠ ��� � �⬮���� ������?
           Set_ST2(914);
           switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return(1); }
             case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return(1); }
           }
           // �������� ����㬠 ������?
           Set_ST2(915);
           switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return(1); }
             case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return(1); }
           }
           // �᫨ ��� �뫮 ࠧ�����஢��� � ०��� ��������������
           if(A2STEPP__V==3){
           // ������ ���᪠ �������� ������?
           Set_ST2(916);
           switch ( Check_TO(A2BTM+6, A2RCHKF__R* SEC, I2KOCC___V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2RCHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return(1); }
             case BAD: { Clear_TO(A2BTM+6); Message(146+A2BNM,0); Bell(2,1); return(1); }
           } }
           // �᫨ �� ������- ��३� � ०�� �������� ࠧ�����஢�� ���
           Set_ST2(917); return(1);
        } else {
////��� ��������������.��� �������.        
           // �᫨ �� �஢��塞� �ᯮ���⥫� �������- 㬥����� ���稪 �
           // ����� �� 蠣� 900, ���� ����������� ���
           if(A2SBPI<5){ A2SBPI++; return(1); }
           // ��᫥ ���稪� �⠡��쭮�� ������� �ᯮ���⥫��-
           // ����� ���稪 ��������  ������� �ᯮ���⥫��
           A2SBPT=0;
           // �᫨ ࠧ�����஢��� ��� � �����-� ०���,�� �� �ᯮ���⥫�
           // �������- �뤠�� ᮮ�饭�� � 㪠������ ०��� �� ���஬ 
           // �������஢��� ���
           if(A2STEPW__V<900){ Set_BV2(A2STEPW__V); Message(106+A2BNM,0); }
           // �᫨ �ᯮ���⥫� �뫨 ������� ��᫥ ࠧ�����஢�� ���-
           // �뤠�� ᮮ�饭�� � ⮬, �� �ᯮ���⥫� ����뫨
           if(A2STEPW__V>900){ Message(108+A2BNM,0); }
           Set_ST2(900);
        }
      } else {
////��� �������������.
        // �᫨ ��� �������஢��� � ��᫥���� �믮��塞� 蠣 �� �����⨥
        // �������� �� ࠧ�����஢�� ���
        if(A2STEPW__V>=900){
           // ������� 5ᥪ �⠡��쭮� �����஢�� ���
           if(A2SBPC<5){ A2SBPC++; return(1); }
           // ��३� � ०�� ��������
           Message(109+A2BNM,0); Set_BV2(910); Set_ST2(50); return(1);
        }
        // ����� ��� �������஢���- ����� ���稪� �����஢�� ��� � ���
        A2SBPT=0;
        A2SBPC=0;
        A2SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  �஢�ઠ �ᯮ���⥫�� �� ࠡ�� � ���誠��
int Chk_IF2(int mode){
    // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
    if(I2ZIOPC__V!=ON){ Message(141+A2BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
    if(I2ZIPPC__V!=ON){ Message(142+A2BNM,0); return(0); }
    // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
    if(I2ZOPPC__V!=ON){ Message(143+A2BNM,0); return(0); }
    // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
    if(I2ZOPAC__V!=ON){ Message(144+A2BNM,0); return(0); }
    // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
    if(I2VZC____V!=ON){ Message(145+A2BNM,0); return(0); }
    // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
    if(I2KOCC___V!=ON){ Message(146+A2BNM,0); return(0); }
    // ��� ࠧ�����஢��?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I2SBP1R__V==0||I2SBP2R__V==0){ Message(149+A2BNM,0); return(0); }
    }
    // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I2P1_N___V==0||I2P2_N___V==0){ Message(156+A2BNM,0); return(0); }
    }
    // ���� ����殮��� �� �� �ࠢ� ���஭��ᮬ? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I2VACKR__V!=ON){ Message(157+A2BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ���誠�� ��⮪���� ���⠭�? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I2LUCDU__V!=ON){ Message(158+A2BNM,0); return(0); }
    }
    // ०�� �ࠢ����� ��⮪����� ���⠭��(��)?
    if(mode==0 or mode==1){
      if(I2DU_____V!=ON){ Message(188+A2BNM,0); return(0); }
    }
    // �஢�ઠ ࠡ��� (����祭���� ���ﭨ�) ���஭��� 
    // �������� ����祭�� ���஭���               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I2GNS_1__V!=ON){ Message(160+A2BNM,0); return(0); }
    }
    // �᫨ ����� ������ ����
    if(mode>0){
       // �᫨ �� - ���室�� � ०�� ����������
       if(I2KR1SB__V==ON||I2KR2SB__V==ON||I2GNS0B__V>0){
          A2CISP=0; Message(168+A2BNM,0); Set_BV2(870); Set_ST2(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_02(vd){

    // ��⠭����� 䫠� ����� ��஫� ����᪠ 横�� � ��३�
    // �� ०��  "��������������"
    if (A2CYCRN__M>OFF){ A2CYCRN__V=ON; A2CYCRN__M=OFF; Set_ST2(300); }
    // ��⠭����� 䫠� ����� ��஫� ��⠭���� 横��
    if (A2CYCST__M>OFF){ A2CYCST__V=ON; A2CYCST__M=OFF; Set_ST2(50);  }
    // ��⠭����� 䫠� ����� ��஫� ���室� �� ������� 蠣
    if (A2ISPST__M>OFF){ A2ISPST__V=ON; A2ISPST__M=OFF; }

    // ��।������ ����� ०��� �� 蠣�
    A2STEP___V=floor( A2STEPW__V*0.01);
    // �஢�ઠ �࠭�筮�� ���祭�� ���������� 蠣�
    if (A2STEPW__M<0  or A2STEPW__M>900){ A2STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  �᫨ �� ������� 蠣 ࠡ��� ��⮪���� � ������ ��஫� ��������� 蠣�
    if (A2STEPW__M!=A2STEPW__V and A2ISPST__V==ON){
        //  �᫨ ��࠭ ������ ����� �ࠢ����� � ������ ��஫�
        //  ����᪠ ��� ��⠭��� 横��
        if((A2STEPW__M<=10)){
            A2STEPW__V =A2STEPW__M; Message(130+A2BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=100) and (A2STEPW__M< 200) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(131+A2BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=200) and (A2STEPW__M< 300) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(132+A2BNM,0);
        }
        //  �᫨ ��࠭ ०�� "��������������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=300) and (A2STEPW__M< 400) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(133+A2BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=400) and (A2STEPW__M< 500) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(134+A2BNM,0); A2NAKPPREM=A2NAKPP__R;
        }
        //  �᫨ ��࠭ ०�� "��������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=500) and (A2STEPW__M< 600) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(135+A2BNM,0);
        }
        //  �᫨ ��࠭ ०�� "����� ��������" � ⥪�騩 ०�� "��������"
        if((A2STEPW__M>=600) and (A2STEPW__M< 700) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(136+A2BNM,0);
        }
        //-------------------------------------------------------------------
        //  ��⠭���� ����� ��।�������� ०��� ࠡ��� 
        if (A2STEPW__M == A2STEPW__V){ Set_BV2(0); }
        else                         { A2STEPW__M=A2STEPW__V; }
    }
//  // ----------------------------------------------------------------------





         

//  // ----------------------------------------------------------------------
//  // �஢�ન � ����஫� ��� ������ ����� ᥪ㭤�
    if(NewSEC>0){ 
       //-------------------------------------------
       // ������ �६��� ࠡ��� � ⥪�饬 ०���
       // ����� ᥪ㭤�
       A2STEPS__V++;
       // ����� ������
       if(A2STEPS__V>59){ A2STEPM__V++; A2STEPS__V=0; }
       // ����� ���
       if(A2STEPM__V>59){ A2STEPH__V++; A2STEPM__V=0; }
       // �१ 99 �ᮢ �६� ��⠥��� ᭠砫� (4,5 ��⮪)
       if(A2STEPH__V>99){ A2STEPH__V=0; A2STEPM__V=0; A2STEPS__V=0; }
       //-------------------------------------------
       // �᫨ �� ������ ��஫�- ��⠭���������� 䫠� ����� ��஫�, �����
       // ����⢨⥫�� 10 ᥪ㭤
       if(A2ISPST__V==ON or A2CYCST__V==ON or A2CYCRN__V==ON){ A2ISPST__C++; }
       // �᫨ ��諮 ����� 10 ᥪ ��᫥ ����� ��஫�- ����� 䫠� ����� 
       // ��஫�  � ���稪 ᥪ㭤 (��஫� �㦭� ������� ������)
       if(A2ISPST__C >10){ 
          A2ISPST__C=0; A2ISPST__V=OFF; A2CYCST__V=OFF; A2CYCRN__V=OFF;
       }
       //-------------------------------------------
       // �᫨ �� ������� ०�� �ࠢ����� ࠡ�⮩ ��⮪���� (��/��)
       if(S2MDUP___V!=S2MDU____V){
          // ��ॢ����� �� ��� - ��ॢ��� �ணࠬ�� � ०�� "��������"
          if(S2MDU____V==0){
             Message(137+A2BNM,0); Set_BV2(0); Set_ST2(50);
          }
          // ��ॢ����� �� ��  - �뤠�� ᮮ�饭��  � � ०�� "��������"
          if(S2MDU____V==1){
             Message(138+A2BNM,0); Set_BV2(0); Set_ST2(50);
          }
       }; S2MDUP___V=S2MDU____V;
       //-------------------------------------------
       if(Chk_SBP2()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �������� ������ ������ ������-������� ��⮪���� �� ०��� "��������"
    if (A2STEPW__V<=10||A2STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // �������� ������ ������ ����祭�� ���஭���
        // �᫨ �����- ��३� �� 蠣 870
        if(V2GNS1BS_V<1){
           if(I2GNS1B__V>0){
              Message(183+A2BNM,0); O2GNS____M=ON; A2CISP=0;
              Set_BV2(50); V2GNS1BS_V=1; Set_ST2(870); return;
           }
        }
        // ����� ������ �몫�祭�� ���஭���
        if(I2GNS0B__V>0){ V2GNS1BS_V=0; O2GNS____M=OFF; }
        //-----------
        // ����஫� ��⮢���� ��⮪���� ��३� � ०�� "���������"
        //(�������� � ��⮪���� �.�.  >1 � ������� �� ��������, ������� �
        // �ᯮ���⥫� ���襪, �� �� ���⠭樨).
        if(AIP2P____V>1 and I2ZIOPC__V>0 and I2ZIPPC__V>0 and I2ZOPPC__V>0 and
           I2VZC____V>0 and I2ZOPAC__V>0 and I2KIPC___V>0 and I2KOPC___V>0 and
           I2DU_____V>0 and
           I2SBP1Z__V>0 and I2SBP2Z__V>0){
           // ��।�����, �� ��㣨� �� �� ��室���� � ०��� ��९�᪠
           if(Get_RA2(0)>0){
              // �᫨ �����-� �� ����訢��� ����� ��� ���������-
              // ��।����� ��� �����
              if(Get_RA2(1)>0){
                 // ��३� �� ०�� ��������
                 Message(129+A2BNM,0); Set_BV2(0); Set_ST2(700);
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
    if (A2STEPW__V>=50 and A2STEPW__V<70){
       // �᫨ �諨 � 蠣� 232:- ������� 宬��
       if(A2STEPWP_V==232){

       }
       // ���� ������� � ��� �ᯮ���⥫��
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS2(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR2(1,STOP,STOP,STOP);
       Set_KR2(2,STOP,STOP,STOP);
       // �몫���� ���஭���
       O2GNS____M=OFF;
       // ����� ������� ����祭�� ���஭���
       V2GNS1BS_V=0;
       // ���� ����窨 � �롮� ०���� 横��
       A2NAKPP_YM=OFF;  A2NAKPP_YV=A2NAKPP_YM;
       A2RAZVK_YM=OFF;  A2RAZVK_YV=A2RAZVK_YM;
       A2PPP___YM=OFF;  A2PPP___YV=A2PPP___YM;
       A2PVID__YM=OFF;  A2PVID__YV=A2PVID__YM;
       A2SP____YM=OFF;  A2SP____YV=A2SP____YM;
       // ������ ⥪�騥 ⠩���� � ���稪�
       Clear_TA2();
       A2PPSTEP_V=0;
       // ��३� � ०�� ��������
       Message(189+A2BNM,0); Set_BV2(50); Set_ST2(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  ����祭�� �����������
//  // ----------------------------------------------------------------------
    if (A2STEPW__V>=870 and A2STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST2(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        //-----------
        // �᫨ ����� ������ �몫�祭�� ���஭���- �뤠�� �������� �� 
        // �몫�祭�� ���஭���
        if(I2GNS0B__V==ON){ 
           Message(184+A2BNM,0);
           // �뤠�� ������� �� �몫�祭�� ���஭���
           O2GNS____M=OFF;
           // ����� 䫠� ���ﭨ� ������ ����祭�� ���஭���
           V2GNS1BS_V=0; 
        }
        // �᫨ ����㯨�� ������� �� �몫�祭�� ���஭���
        if(V2GNS1BS_V==0&&O2GNS____M==OFF){
           // ���� ������� � �ᯮ���⥫�� ��堭����� ���誨
           //      N BY   HM   KR
           Set_KR2(1,STOP,STOP,STOP);
           Set_KR2(2,STOP,STOP,STOP);
           // ���� ������� � �ᯮ���⥫�� ��������
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ����� �몫�祭�� ���஭���
           switch( Check_TO(A2BTM+1,60*SEC, I2GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A2BNM,0); Bell(2,1); break; }
              case END: { Message(185+A2BNM,0); break; }
           }
           // ��३� � ०�� ��������
           Set_BV2(870); Set_ST2(50); return;
        }
        // �஢�ઠ ���ﭨ� �ᯮ���⥫��
        if(Chk_IF2(0)==0){
           A2CISP++; 
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(50); 
           }
           return; 
        }; A2CISP=0;
        //-----------
        // �뤠�� �������� �� ����祭�� ���஭���:
        O2GNS____M= ON;
        //-----------
        // �������� ������ ������ "������ ��⮪���"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR1OB__V>0){
              Message(174+A2BNM,0); A2CISP=0;
              Set_BV2(50); I2KR1OBS_V=1; V2GNS1BS_V=1; Set_ST2(100); return;
           }
        }
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR2OB__V>0){
              Message(175+A2BNM,0); A2CISP=0;
              Set_BV2(50); I2KR2OBS_V=1; V2GNS1BS_V=1; Set_ST2(100); return;
           }
        }
        //-----------
        // �������� ������ ������ "������� ��⮪���"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR1CB__V>0){
              Message(176+A2BNM,0);  A2CISP=0;
              Set_BV2(50); I2KR1CBS_V=1; V2GNS1BS_V=1; Set_ST2(200); return;
           }
        }
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR2CB__V>0){
              Message(177+A2BNM,0);  A2CISP=0;
              Set_BV2(50); I2KR2CBS_V=1; V2GNS1BS_V=1; Set_ST2(200); return;
           }
        }
        //-----------
        Clear_TA2();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������" ��4
//  // ----------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A2STEPW__V>=100 and A2STEPW__V< 130){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O2GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V!=126){ Message(195+A2BNM,0); }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST2(126);
        I2KR_TMP_V=-1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(126); Set_ST2(870); return;}
        switch ( Check_TO(A2BTM+14,A2THMUP__R*SEC, I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R;A2STEPC__V =CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(151+A2BNM,0);
                        // �᫨ �� ���� 蠣 ����஫�- 㢥����� ���稪 
                        // ����஫� � ���� ������� �� �����⨥ 宬��
                        if(A2TEMP<1){ 
                           if(I2KR1OBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
                           if(I2KR2OBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
                           A2TEMP++;
                        }
                        // �᫨ �� ��ன 蠣 ����஫�- ������ � ���室 �
                        // ०�� ��������
                        else        { Bell(2,1); Set_BV2(126); Set_ST2(870); }
                        return;
                      }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15);
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        Clear_TO(A2BTM+18); Clear_TO(A2BTM+19);
        A2STEPZ__V=0; A2STEPC__V=0;
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        Set_ST2(130);  A2TEMP=0;
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������":
    if (A2STEPW__V>=130 and A2STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O2GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST2(132);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2BY1O___V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2BY2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(132); Set_ST2(870); return;}
        // �᫨ ������� �� �����
        if(I2KR_TMP_V==OFF){
//         // ������� �� ����⨥ �������              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // �������� �����ᠬ�: 2ᥪ ������, 2ᥪ ��㧠
           if(A2TEMP<2){
             // ������ �� ����⨥
             if(I2KR1OBS_V>0){ O2BY1O___M=ON; O2BY1C___M=OFF; }
             if(I2KR2OBS_V>0){ O2BY2O___M=ON; O2BY2C___M=OFF; }
             A2TEMP++;
           } else {
             // ��㧠
             if(A2TEMP<4){
                O2BY1O___M=OFF; O2BY1C___M=OFF;
                O2BY2O___M=OFF; O2BY2C___M=OFF;
                A2TEMP++;
             } else {
             // ���室 ��᫥ ���� �� ������
                if(A2TEMP<7) A2TEMP=0;
             }
           }  
        }
        switch (Check_TO( A2BTM+16,A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(154+A2BNM,0); Bell(2,1); 
                        Set_BV2(132); Set_ST2(870);
                        return; 
                      }
        }
        // ��� 䫠�� ����� �����᭮�� ᨣ���� �� �������
        A2TEMP=10;
        // ���� ������� �� ����⨥ ������⮢          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O2BY1O___M=OFF; O2BY1C___M=OFF;
        O2BY2O___M=OFF; O2BY2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A2BTM+17,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+17]; return; }
        }
//      // ������� �� �����⨥ 宬��                   [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I2KR1OBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
        if(I2KR2OBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST2(131);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(131); Set_ST2(870); return;}
        switch (Check_TO( A2BTM+14,A2THMUP__R*SEC,I2KR_TMP_V, '=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(151+A2BNM,0); Bell(2,1);
                        Set_BV2(131); Set_ST2(870);    return;
                      }
        }
        // ���� ������� �� �����⨥ 宬��             [x6.o01 (OxHM1UP) = 0]
        //                                              [x6.o07 (OxHM2UP) = 0]
        O2HM1UP__M=OFF; O2HM1DN__M=OFF;
        O2HM2UP__M=OFF; O2HM2DN__M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        //--------
//      // ������� �� ����⨥ ���誨                   [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I2KR1OBS_V>0){ O2KR1O___M=ON; O2KR1C___M=OFF; }
        if(I2KR2OBS_V>0){ O2KR2O___M=ON; O2KR2C___M=OFF; }
        // ���誨 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST2(133);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2KR1O___V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2KR2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(133); Set_ST2(870);  return;}
        switch (Check_TO( A2BTM+18,A2TKRO___R*SEC, I2KR_TMP_V, '=',ON,1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+18); Message(152+A2BNM,0); Bell(2,1); 
                        Set_BV2(133); Set_ST2(870);
                        return; 
                      }
        }
        // ������� � ���襪 ᭨��� ��᫥ ���᪠��� 宬��

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO(A2BTM+19,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+19]; return; }
        }
        // ������ ⠩���� � ���稪�
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15);
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        Clear_TO(A2BTM+18); Clear_TO(A2BTM+19);
        A2STEPZ__V=0; A2STEPC__V=0;
        //
        Set_ST2(134); A2TEMP=0; return;
    }
//  // ----------------------
//  //  ���᪠��� 宬��
    if (A2STEPW__V>=134 and A2STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ������� �� ����祭�� ���஭���
        O2GNS____M=ON;
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
//      // ������� �� ���᪠��� 宬�⮢                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I2KR1OBS_V>0){ O2HM1DN__M=ON; O2HM1UP__M=OFF; }
        if(I2KR2OBS_V>0){ O2HM2DN__M=ON; O2HM2UP__M=OFF; }
        // 宬��� ���饭�?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST2(134);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1DN__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2DN__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(134); Set_ST2(870);  return;}
        switch (Check_TO( A2BTM+14,A2THMUP__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(150+A2BNM,0); Bell(2,1); 
                        Set_BV2(134); Set_ST2(870);
                        return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        if(I2KR1OBS_V>0){ Message(191+A2BNM,0); }
        if(I2KR2OBS_V>0){ Message(192+A2BNM,0); }
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"->"��������"|"���"
        Message(197+A2BNM,0); Set_BV2(134); Set_ST2(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A2STEPW__V>=200 and A2STEPW__V< 230){
        if(!NewSEC){ return; }
        // ������� �� ����祭�� ���஭���
        O2GNS____M=ON;
        // ������� �� �����⨥ �ᯮ���⥫�� ��������
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V==200){ Message(196+A2BNM,0); }
        //--------
        // 宬�� ���饭?                                [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST2(226);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2HM1DN__V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2HM2DN__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(226);  Set_ST2(870); return;}
        switch ( Check_TO (A2BTM+14, A2THMUP__R*SEC,   I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(150+A2BNM,0); Bell(2,1); 
                        Set_BV2(226); Set_ST2(870);   return; 
                      }
        }
        // �뤠�� �������� �� ����⨥ �������
        if(I2KR1CBS_V>0){ O2BY1O___M=ON; O2BY1C___M=OFF; }
        if(I2KR2CBS_V>0){ O2BY2O___M=ON; O2BY2C___M=OFF; }
        // ������� �����?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        // �᫨ ������� �� ������- ���
        Set_ST2(228);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2BY1O___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2BY2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(228); Set_ST2(870); return;}
        switch ( Check_TO (A2BTM+15, A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+15); Message(154+A2BNM,0); Bell(2,1);
                        Set_BV2(228); Set_ST2(870);   return; 
                      }
        }
        // ���� ������� � �������
        O2BY1O___M=OFF; O2BY1C___M=OFF;
        O2BY2O___M=OFF; O2BY2C___M=OFF;
        //
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15); 
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(230);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": �ਯ������ ��। �����⨥�
    if (A2STEPW__V>=230 and A2STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O2GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // ������� �� �ਯ����⨥ ���誨                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I2KR1CBS_V>0){ O2KR1O___M=ON; O2KR1C___M=OFF; }
        if(I2KR2CBS_V>0){ O2KR2O___M=ON; O2KR2C___M=OFF; }
        // ���誠 ������?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST2(231);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2KR1O___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2KR2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(231); Set_ST2(870); return;}
        switch (Check_TO(A2BTM+14,A2TKRO___R*SEC, I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(152+A2BNM,0); Bell(2,1);
                        Set_BV2(231); Set_ST2(870);   return; 
                      }
        }
        // ���� ������� �� �����⨥ ���誨             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O2KR1O___M=OFF; O2KR1C___M=OFF;
        O2KR2O___M=OFF; O2KR2C___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        // ������ ������� �� �����⨥ 宬��            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I2KR1CBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
        if(I2KR2CBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
        Set_ST2(232);
        // 宬�� ������?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(232); Set_ST2(870); return;}
        switch (Check_TO(A2BTM+16,A2THMUP__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(151+A2BNM,0); Bell(2,1);
                        Set_BV2(232); Set_ST2(870);   return; 
                      }
        }
        // ��᫥ ������� 宬�� ������� �� ᭨������

        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A2BTM+17,A2TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+17]; return; }
        }
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15); 
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(235);
        return;
    }
//  // ----------------------
//  //  �믮������ ������� "�������� ���������": ������� ���誨
    if (A2STEPW__V>=235 and A2STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O2GNS____M=ON;
        //--------
        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� �������� � ࠡ��
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // ������� �� �����⨥ ���襪                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I2KR1CBS_V>0){ O2KR1C___M=ON; O2KR1O___M=OFF; }
        if(I2KR2CBS_V>0){ O2KR2C___M=ON; O2KR2O___M=OFF; }
        // ���誠 ������?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST2(236);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2KR1C___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2KR2C___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(236); Set_ST2(870); return;}
        switch (Check_TO (A2BTM+14,A2TKRO___R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(153+A2BNM,0); Bell(2,1);
                        Set_BV2(236); Set_ST2(870); return; 
                      }
        }
        // ���� ������� �� �����⨥ ���襪             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O2KR1C___M=OFF; O2KR1O___M=OFF;
        O2KR2C___M=OFF; O2KR2O___M=OFF;
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        // ������� �� �����⨥ ������⮢                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I2KR1CBS_V>0){ O2BY1C___M=ON; O2BY1O___M=OFF; }
        if(I2KR2CBS_V>0){ O2BY2C___M=ON; O2BY2O___M=OFF; }
        // �������� �������?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST2(237);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2BY1C___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2BY2C___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(237); Set_ST2(870); return;}
        switch (Check_TO (A2BTM+16,A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(155+A2BNM,0); Bell(2,1);
                        Set_BV2(237); Set_ST2(870);   return; 
                      }
        }
        // ���� ������� � �ᯮ���⥫�� ���襪
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        // ᮮ�饭�� �� ����砭�� ०���
        if(I2KR1OBS_V>0){ Message(193+A2BNM,0); }
        if(I2KR2OBS_V>0){ Message(194+A2BNM,0); }
        // ��ॢ�� �ࠢ����� ��⮪����� � ०�� "����������"
        Message(198+A2BNM,0); Set_BV2(235); Set_ST2(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  ����� "��������������"
//  // ----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A2STEPW__V>=300 and A2STEPW__V<320){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "��������������"- ��३� �� � ०��
        if(A2RAZVK_YV==OFF){ Set_BV2(300); Set_ST2(400); return; }
        // �஢�ઠ  ����㬨஢���� ��㣨� ��⮪�����
        // (�� ����㬨஢���� ����� ��室����  ������ ���� ��⮪���)
        if(A1PPSTEP_V==300||A3PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV2(300); Set_ST2(50); return; 
        }
        A2PPSTEP_V=300;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V==300){ Message(200+A2BNM,0); }
        //
        Set_ST2(311);
        // ��ॢ��� ॣ���� �������� � ��� ०��, �⮡� ������� ������
        A2RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST2(301);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST2(302);
        switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST2(303);
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST2(304);
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST2(305);
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        // ������ ���᪠ �������� ������?            [x5.i07 (IxKOCC_) = 1]
        Set_ST2(306);
        switch ( Check_TO(A2BTM+6, A2RCHKF__R* SEC, I2KOCC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2RCHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(146+A2BNM,0); Bell(2,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST2(307);
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        // ��� �������� � ��⮪����?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST2(308);
        switch ( Check_TO(A2BTM+8, 60*SEC,(I2P1_N___V and I2P2_N___V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+8]; return; }
            case BAD: { Clear_TO(A2BTM+8); Message(156+A2BNM,0); Bell(2,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST2(309);
        switch ( Check_TO(A2BTM+9, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+9]; return; }
            case BAD: { Clear_TO(A2BTM+9); Message(147+A2BNM,0); Bell(2,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ����㬭���      [x2.i08 (IxVNMD_) = 1]
        Set_ST2(310);
        switch ( Check_TO(A2BTM+10, 60*SEC, I2VNMD___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+10]; return; }
            case BAD: { Clear_TO(A2BTM+10); Message(162+A2BNM,0); Bell(2,1); return; }
        }
        // ���⠭樮��� ०�� ࠡ��� ��������          [x2.i07 (IxVZMD_) = 1]
        Set_ST2(311);
        switch ( Check_TO(A2BTM+11, 60*SEC, I2VZMD___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+11]; return; }
            case BAD: { Clear_TO(A2BTM+11); Message(182+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6);
        Clear_TO(A2BTM+7); Clear_TO(A2BTM+8); Clear_TO(A2BTM+9);
        Clear_TO(A2BTM+10); 
        Clear_TO(A2BTM+11);
        A2STEPZ__V=0; A2STEPC__V=0;
        I2MAXVCN_V=0;
        Set_ST2(320);
        return;
    }
//  // ----------------------
//  //  ����祭�� ����㬨஢����
    if (A2STEPW__V>=320 and A2STEPW__V<325){
        if(!NewSEC){ return; }
        // ������� �� ����⨥ ����㬭�� ��������       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // ����㬭�� �������� �����?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST2(321);
        switch ( Check_TO(A2BTM+1, A2TVZO___R* SEC, I2VZO____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(163+A2BNM,0); return; }
        }
        // ���� ������� �� ����⨥ ����㬭�� �������� [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // ����뢠���� ������ �� ����㬭�� ����       [x4.o04 (OxAZVO_) = 1]
        O2AZVO___V=ON; O2AZVO___M=OFF;
        // ������� �� ����祭�� ����㬭��� ����       [x4.o05 (OxVN_1_) = 1]
        O2VN_1___V=ON; O2VN_1___M=OFF;
        Set_ST2(322);
        // ����㬭� ���� ����祭?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A2BTM+2, 60*SEC, I2VN_1___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(164+A2BNM,0); Bell(2,1); return; }
        }
        // �஢�ઠ ������ ���ᨬ��쭮�� ࠧ०���� �   [x2.i06 (IxMAXV_) = 1]
        // �.���⠪⭮�� ��������
        if(I2MAXV___V>0){ I2MAXVCN_V++; }
        else            { I2MAXVCN_V=0; }
        if(I2MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
           Set_ST2(325);
           return;
        }
        // �஢�ઠ ����稭� ࠧ०���� � ��⮪����     [x0.06 (AIPxyV__) = ?]
        // (����� ��� ��� ��� ���)
        Set_ST2(323);
        switch ( Check_TO(A2BTM+3, A2TVACUM_R* SEC, AIP12V___V,'<',A2RAZVK__R, 3)){
            case RUN: { A2STEPZ__V=A2TVACUM_R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Message(165+A2BNM,0); break; }
        }
        // ���� �������� �� �����⨥ ����㬭�� �������� [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(325);
        return;
    }
//  // ----------------------
//  //  �몫�祭�� ����㬨஢����
    if (A2STEPW__V>=325 and A2STEPW__V<330){
        if(!NewSEC){ return; }
        // ������� �� �����⨥ ����㬭�� ��������       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ����㬭�� �������� ������?                  [x2.i02 (IxVZC__) = 1]
        Set_ST2(326);
        switch ( Check_TO(A2BTM+1, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(166+A2BNM,0); return; }
        }
        // ����� �����஥ �६� ��। ����祭��� ᫥���饣� �ᯮ���⥫�
        Set_ST2(327);
        switch (Check_TO (A2BTM+3,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
        }
        // ������ ������ �⬮���� �� ����㬭�� ���� [x4.o04 (OxAZVO_) = 1]
        O2AZVO___V=OFF; O2AZVO___M=OFF;
        // �몫���� ����㬭� ����                    [x4.o05 (OxVN_1_) = 0]
        O2VN_1___V=OFF; O2VN_1___M=OFF;
        Set_ST2(328);
        // ����㬭� ���� �몫�祭?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A2BTM+4,  120*SEC, I2VN_1___V,'=',OFF, 1)){
            case RUN: { A2STEPZ__V=120; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(167+A2BNM,0); return; }
        }
        //
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); 
        Clear_TO(A2BTM+3); Clear_TO(A2BTM+4);
        A2STEPZ__V=0; A2STEPC__V=0;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(190+A2BNM,0); Set_ST2(330);
        return;
    }
//  // ----------------------
//  //  �������������� ���������
    if (A2STEPW__V>=330 and A2STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // ��ॢ�� �ࠢ����� ��⮪����� � ��筮� ०��
        Set_BV2(330); Set_ST2(400);
        A2RAZVK_YM=OFF;  A2RAZVK_YV=A2RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  ����� "����� ��������"
//  // -----------------------------------------------------------------------
//  //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫��:
    if (A2STEPW__V>=400 and A2STEPW__V<420){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� � ०��
        if(A2PPP___YV==OFF){ Set_BV2 (400); Set_ST2(500); return; }
        A2PPSTEP_V=400;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V==400){ 
           Message(201+A2BNM,0); 
           A2RPRA___M=OFF; A2RPUU1__M=RMINUS; Set_ST2(401); return;
        }
        //
        A2NAKPPREM=A2NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ���ண� ��� ������?        [x1.i01 (IxZIOPC) = 1]
        Set_ST2(401);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        Set_ST2(402);
        switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        Set_ST2(403);
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        Set_ST2(404);
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        Set_ST2(405);
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        // ������ ���᪠ ��� ������?
        Set_ST2(406);
        switch ( Check_TO(A2BTM+6, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST2(407);
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        // ����稥 ����殮��� �� �� ���᪠ ���       [x2.i00 (IxVAC__) = 1]
        Set_ST2(409);
        switch ( Check_TO(A2BTM+9, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+9]; return; }
            case BAD: { Clear_TO(A2BTM+9); Message(147+A2BNM,0); Bell(2,1); return; }
        }
        // ०�� �ࠢ����� ��⮪����� "���⠭��"?     [x1.i13 (IxDU___) = 1]
        Set_ST2(410);
        switch ( Check_TO(A2BTM+10, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+10]; return; }
            case BAD: { Clear_TO(A2BTM+10); Message(159+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6); 
        Clear_TO(A2BTM+7); Clear_TO(A2BTM+8); Clear_TO(A2BTM+9); 
        Clear_TO(A2BTM+10);
        A2STEPZ__V=0; A2STEPC__V=0;
        // ��࠭ ०�� ����� �������� ������ࠫ�� ��஬?
        if(A2NAKPPREM==0) Set_ST2(430);
        else              Set_ST2(420);
        A2TEMP=0; A2FLAG=0; A2PPRT=0; A2RPRA___M=ON; A2RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  �஢�ઠ ��⮢���� ��⮪����-��।��稪� (����⨥ �� ��� ��������)
    if (A2STEPW__V>=420 and A2STEPW__V<422){
        if(!NewSEC){ return; }
        A2PPSTEP_V=420;
        Set_ST2(421);
        // ����� ���⢥ত���� � ��⮢���� � ��९��� � ��⮪����
        // ��।��稪�
        if(A2PPRT<1){
           A2PPRT=Get_RV2(); 
           return;
        }
        Set_ST2(422);
        return;
    }
//  // ----------------------
//  //  � ��९�᪮�
//  //  ����⨥ �ᯮ���⥫��:
    if (A2STEPW__V>=422 and A2STEPW__V<425){
        if(!NewSEC){ return; }
        A2PPSTEP_V=422;
        // ���� ������� �� ����⨥ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� �����?   [x3.o02 (OxZIPPO) = 1]
        Set_ST2(423);
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZIPPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(161+A2BNM,0); Bell(2,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���.���
        switch (Check_TO (A2BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        // ��३� �� ᫥���騩 蠣
        Set_ST2(425);
        return;
    }
//  // ----------------------
//  // �������� ������ �� ��-��� ������� ���᪠ ���
    if (A2STEPW__V>=425 and A2STEPW__V<427){
        if(!NewSEC){ return; }
        // �᫨ ��-��� ���襫 �� ०��� �������� � ��㣮� - ������� ��
        // ��������  � ��३� �  ०��  �������� (���⠭���⭠� �����) 
//!!!   if(A2RPPSTEPV<700||A2RPPSTEPV>710){ Set_ST2(50); return; }
        A2PPSTEP_V=425;
        // ����� ���⢥ত���� �� ��� ������� ���᪠ ��� �� ��⮪����
        // ��।��稪�
        if(A2PPRT<2){
           A2PPRT=Get_RV2(); 
           return;
        }
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST2(440); A2RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  � ������ࠫ�
    if (A2STEPW__V>=430 and A2STEPW__V<435){
        if(!NewSEC){ return; }
        // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ쭮�� ��� �����? [x1.i00 (IxZIOPO) = 1]
        Set_ST2(431);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(171+A2BNM,0); Bell(2,1); return; }
        }
        // ����প� 10 ᥪ ��। ��⨥� �������� � �������� ���ண� ���
        switch (Check_TO (A2BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // ���� ������� � �������� ���᪠ ���ண� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        // ��३� �� �ࠢ����� �������� (�� ॣ����)
        Set_ST2(440); A2RPZD___S=0; A2RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  ��ନ஢���� ������� ��室� ��� ॣ���� "������ ��������"
    if (A2STEPW__V>=440 and A2STEPW__V<445){
        if(!NewSEC){ return; }
        // ��।��塞 ������� ��室� ��� ��� ॣ���� �� ⠡���� 
        // "����� �����������"
        Set_ST2(441);
        //-----------
        // ��� ����� ⥬������� ����� ��஬:
        if(A2NAKPPREM==0){
            // �᫨ ⥪��� � ��⮪���� ����� ��।��� ������� � ⠡���-
            // ��⠭����� ������� ��室� ��� ��� ॣ���� ����� ��������
            if(A2RPZD___S==0){ 
               A2RPZD___M =A21NTOF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=1;
            }
            if(AIT2P____V>=A21NTOP02R  and A2RPZD___S<=2){ 
               A2RPZD___M =A21NTOF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=2;
            }
            if(AIT2P____V>=A21NTOP03R  and A2RPZD___S<=3){ 
               A2RPZD___M =A21NTOF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=3;
            }
            if(AIT2P____V>=A21NTOP04R  and A2RPZD___S<=4){ 
               A2RPZD___M =A21NTOF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=4;
            }
            if(AIT2P____V>=A21NTOP05R  and A2RPZD___S<=5){ 
               A2RPZD___M =A21NTOF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=5;
            }
        } else {
        // ��� ����� ⥬������� ��९�᪭� ��஬:
            if(A2RPZD___S==0){
               A2RPZD___M =A21NTPF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=1;
            }
            if(AIT2P____V>=A21NTPP02R  and A2RPZD___S<=2){
               A2RPZD___M =A21NTPF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=2;
            }
            if(AIT2P____V>=A21NTPP03R  and A2RPZD___S<=3){
               A2RPZD___M =A21NTPF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=3;
            }
            if(AIT2P____V>=A21NTPP04R  and A2RPZD___S<=4){
               A2RPZD___M =A21NTPF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=4;
            }
            if(AIT2P____V>=A21NTPP05R  and A2RPZD___S<=5){
               A2RPZD___M =A21NTPF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=5;
            }
        }
        //-----------
        // �᫨ �������� � ��⮪���� ����� ⮣�, �� ��।�����
        // � ��ࢮ� ��ப� ⠡���� "����� ��������" - ��।��塞 �������
        // ��室�  ��� ��� ॣ���� �� ⠡���� "����� ��������"
        // ��� ����� �������� ����� ��஬:
        if(A2NAKPPREM==0){
            if(AIP2P____V>=A21NPOP01R  and A2RPZD___S<=6){ 
               A2RPZD___M =A21NPOF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=6;
            }
            if(AIP2P____V>=A21NPOP02R  and A2RPZD___S<=7){ 
               A2RPZD___M =A21NPOF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=7;
            }
            if(AIP2P____V>=A21NPOP03R  and A2RPZD___S<=8){ 
               A2RPZD___M =A21NPOF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=8;
            }
            if(AIP2P____V>=A21NPOP04R  and A2RPZD___S<=9){ 
               A2RPZD___M =A21NPOF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=9; 
            }
            if(AIP2P____V>=A21NPOP05R  and A2RPZD___S<=10){ 
               A2RPZD___M =A21NPOF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=10;
            }
            if(AIP2P____V>=A21NPOP06R  and A2RPZD___S<=11){ 
               A2RPZD___M =A21NPOF06R; A2RPZD___V=A2RPZD___M; A2RPZD___S=11;
            }
            if(AIP2P____V>=A21NPOP07R  and A2RPZD___S<=12){ 
               A2RPZD___M =A21NPOF07R; A2RPZD___V=A2RPZD___M; A2RPZD___S=12;
            }
            if(AIP2P____V>=A21NPOP08R  and A2RPZD___S<=13){ 
               A2RPZD___M =A21NPOF08R; A2RPZD___V=A2RPZD___M; A2RPZD___S=13;
            }
            if(AIP2P____V>=A21NPOP09R  and A2RPZD___S<=14){ 
               A2RPZD___M =A21NPOF09R; A2RPZD___V=A2RPZD___M; A2RPZD___S=14;
            }
            if(AIP2P____V>=A21NPOP10R  and A2RPZD___S<=15){ 
               A2RPZD___M =A21NPOF10R; A2RPZD___V=A2RPZD___M; A2RPZD___S=15;
            }
        } else {
        // ��� ����� �������� ��९�᪭� ��஬:
            if(AIP2P____V>=A21NPPP01R  and A2RPZD___S<=6){ 
               A2RPZD___M =A21NPPF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=6;
            }
            if(AIP2P____V>=A21NPPP02R  and A2RPZD___S<=7){ 
               A2RPZD___M =A21NPPF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=7;
            }
            if(AIP2P____V>=A21NPPP03R  and A2RPZD___S<=8){ 
               A2RPZD___M =A21NPPF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=8;
            }
            if(AIP2P____V>=A21NPPP04R  and A2RPZD___S<=9){ 
               A2RPZD___M =A21NPPF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=9;
            }
            if(AIP2P____V>=A21NPPP05R  and A2RPZD___S<=10){ 
               A2RPZD___M =A21NPPF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=10;
            }
            if(AIP2P____V>=A21NPPP06R  and A2RPZD___S<=11){ 
               A2RPZD___M =A21NPPF06R; A2RPZD___V=A2RPZD___M; A2RPZD___S=11;
            }
            if(AIP2P____V>=A21NPPP07R  and A2RPZD___S<=12){ 
               A2RPZD___M =A21NPPF07R; A2RPZD___V=A2RPZD___M; A2RPZD___S=12;
            }
            if(AIP2P____V>=A21NPPP08R  and A2RPZD___S<=13){ 
               A2RPZD___M =A21NPPF08R; A2RPZD___V=A2RPZD___M; A2RPZD___S=13;
            }
            if(AIP2P____V>=A21NPPP09R  and A2RPZD___S<=14){ 
               A2RPZD___M =A21NPPF09R; A2RPZD___V=A2RPZD___M; A2RPZD___S=14;
            }
            if(AIP2P____V>=A21NPPP10R  and A2RPZD___S<=15){ 
               A2RPZD___M =A21NPPF10R; A2RPZD___V=A2RPZD___M; A2RPZD___S=15;
            }
        }
        //-----------
        // �᫨ ��⮪��� � ०��� ����� �������� ��९�᪭�  ��஬ �
        // �᫨ ࠧ��� �������� ����� ��-��।��稪�� � ��-�ਥ������
        // ����� ��������� (AxZPPRE__R) -��३� �� 蠣
        // ������� �ᯮ���⥫�� ����� ��९�᪭��� ��� � �ନ஢����
        // ������� ��室� ��� ॣ���� "������ ��������" �� ���஬� ����
        A2PPSTEP_V=440; Get_RV2();
        if(A2NAKPPREM>0 and AIPRP2___V-AIP2P____V < A2ZPPRE__R){
           Set_ST2(480); A2PPRT=0; return;
        }

        //-----------
        // �᫨ �������� � ��⮪���� ����� ��������� � "���������� �����"-
        // ��३� �� 蠣 ������� �ᯮ���⥫�� ������ࠫ쭮�� ���
        if(A2NAKPPREM==0 and A2PPP____R>0 and AIP2P____V>=A2PPP____R){
           if(A2TEMP <7){ 
              A2TEMP++;     
           } else { 
              Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
              Set_ST2 (450);
           }
           return;
        } else {
           A2TEMP=0;
        }
        //-----------
        // �᫨ ����� �������� ���� � ������ࠫ� � �������� � ��⮪���� 
        // �����,祬 �������� � ������ࠫ�- ������� �������� ���᪠ ���� ���
        if(A2NAKPPREM==0 and AIP2P____V>=AIP12M___V){
           Set_ST2(442);
           // ���� ������� �� �����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // �᫨ ��९�� �������� ����� �� � ������ࠫ�� �⠡�����஢����
        if(A2NAKPPREM==0 and AIP2P____V< AIP12M___V-A2ZNPM___R){
           Set_ST2(443);
           // ���� ������� �� ����⨥ �������� ������ࠫ쭮�� ���
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS2(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ࠫ쭮�� ��� � ���室 �� "��������"
    if (A2STEPW__V>=450 and A2STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A2BTM+2, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(440); Set_ST2(500);
        A2PPP___YM=OFF;  A2PPP___YV=A2PPP___YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(202+A2BNM,0);
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ��९�᪭��� ��� �� ��-���
    if (A2STEPW__V>=480 and A2STEPW__V<482){
        if(!NewSEC){ return; }
        A2PPSTEP_V=480;
        Set_ST2(481);
        // ����� ���⢥ত���� � �����⨨ �ᯮ���⥫�� ���᪠ ��� ��
        // ��⮪���� ��।��稪�
        if(A2PPRT<3){
           A2PPRT=Get_RV2(); return;
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(482);
        return;
    }
//  // ----------------------
    if (A2STEPW__V>=482 and A2STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST2(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �������� ���᪠ ��९�᪭��� ��� ������?
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // ������ ���᪠ ��� ������?
        switch ( Check_TO(A2BTM+2, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // �� �����⨨ ���  �ᯮ���⥫�� ��९�᪭��� ���, �����頥���
        // �� �ନ஢���� ������� ��室� ��� ॣ���� ������ ��������
        // �� ���஬� ����
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(440);
        A2NAKPPREM=0; A2RPZD___S=0; A2RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  ����� "��������"
//  // ----------------------------------------------------------------------
    if ((A2STEPW__V==500)||(A2STEPW__V>510&&A2STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST2(500);
        // �᫨ � 横� �� ����祭 ०�� "��������"- ��३� �� � ०��
        if(A2PVID__YV==OFF){ Set_BV2(500); Set_ST2(600); return; }
        A2PPSTEP_V=500;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V==500){ Message(203+A2BNM,0); }
        // �뤥প� ��⮪���� ��� ��������� �஢������ ������ࠫ�� ��஬
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST2(511);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(512);
        // ������ ���᪠ ��� ������?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A2BTM+2, A2RPHKF__R, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(169+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(513);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(514);
        // �������� ���᪠ ��� � �⬮���� ������?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(515);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(516);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A2BTM+6, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // ���㫥��� ⠩��஢ � ���稪��
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6);
        A2STEPZ__V=0; A2STEPC__V=0;
        //
        Set_ST2(501);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A2TEMP=0.3;
        A2RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A2STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST2(501);
        //-----------
        // �᫨ �������� � ��⮪���� ����� ���������-
        // ��३� ��  蠣 ������� ������� ���᪠ ���
        if(AIP2P____V>=A2PPP____R){
           Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=0; 
           return;
        }
        //-----------
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ��३� �� 蠣 ������� �������� � ������� ���᪠ ���ண� ���
        if(AIP2P____V> A2ZPAKX__R or AIP2P____V>AIP12M___V){
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=1;
           return;
        }
        //-----------
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A2STEPH__V>=A2PVIDH__R and A2STEPM__V>=A2PVIDM__R){
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=2;
           return;
        }
        //-----------

        //-----------
        // �뤥প� ��⮪���� ��� ���������  �஢������ ������ࠫ�� ��஬
        // ������  ��������  ������ࠫ쭮�� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // �������� ���᪠ ������ࠫ� ��� �����?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPO__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(171+A2BNM,0); Bell(2,1); return; }
        }
        //-----------
        // ����  ������� �  �������� ���᪠  ���ண� ���  �
        // �뤠�� ������� �� ����⨥ ������� ���᪠  ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A2BTM+3]==0) Set_IS2(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A2BTM+3]==1) Set_IS2(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ����� A2TEMP %  ᥪ㭤 �� �������  室� ������� ���᪠ ���
        // ��� ���� �� �ࠡ�⠥� ���楢�� ������ �������
        if(I2KIPO___V<1){
           switch ( Check_TO(A2BTM+2,A2RPHKF__R*A2TEMP,ZERO,'=',ON, 1)){
               case RUN: { A2STEPZ__V=A2RPHKF__R*A2TEMP; A2STEPC__V=CNTTO[A2BTM+2]; 
                           return;
                         }
           }
        }
        // ���� ������� � ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // ����প� 30 ᥪ㭤
        switch ( Check_TO(A2BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=30; A2STEPC__V=CNTTO[A2BTM+3]; return; }
        }
        if(AIP2P____V< A2PPP____R){
        // �᫨ �������� � ��⮪���� �� ����﫮�� �� ��������� � ������
        // ����� �� ���������- 㢥����� �६� ������ ������� � �������
        // ⥪�騩 蠣 
        //(��ਭ樯�,⠪ ����� ���뢠�� ������ ����� ������ +0.3,+0.3...)
           if(A2TEMP<0.8){
              A2TEMP=0.3;
              Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
              A2STEPZ__V=0; A2STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A2STEPW__V>=502 and A2STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST2(502);
        // ��⠭����� ��業� ��砫쭮�� ������ ������� ���᪠ ��� (30%)
        A2TEMP=0.3;
        // �᫨ ⥪�饥 �������� � ��⮪���� ����� ���������-
        // ��३� ����� ��  蠣 ������  �������� � ������� ���᪠ ���
        if(AIP2P____V<A2PPP____R-A2ZNVD___R and 
           AIP2P____V<AIP12M___V-A2ZNPM___R and A2FLAG<2){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(501); return;
        }
        // �᫨ ⥪�饥 �������� ��⮪���� ����� ���ᨬ��쭮 ����㯭��� �
        // ��⮪���� ��� �����, 祬 �������� � �������� -
        // ������� �������� ���᪠ ���ண� ���
        if(AIP2P____V> A2ZPAKX__R or AIP2P____V>AIP12M___V){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); 
           A2STEPZ__V=0; A2STEPC__V=0; A2FLAG=1;
        }
        // ����஫� �६��� ��宦����� ��⮪���� � ०��� "��������"
        // �᫨ �६� ��宦����� ��⮪���� � ⥪�饬 ०��� ����� ��� ࠢ�� 
        // ���������- ��३� �� �����⨥  � ��  ०�� "����� ��������"
        if(A2STEPH__V>=A2PVIDH__R and A2STEPM__V>=A2PVIDM__R){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); 
           A2STEPZ__V=0; A2STEPC__V=0; A2FLAG=2;
        }
        // �᫨ �� ����஫� ���ᨬ��쭮 �����⨬��� �������� ��� ࠧ���� ���
        // ��室 �� ०��� - ������� �������� ���᪠ ���ண� ���
        if(A2FLAG>0){
          // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // �������� ���᪠ ���ண� ��� ������?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A2BTM+5, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(141+A2BNM,0); Bell(2,1); return; }
          }
        }
        // ���� ������� �� �����⨥ ������� ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢����  ���� ������� ���᪠ ���       [x1.i05 (IxKIPC_) = 1]
        // ������ ���᪠ ��� ������?            
        switch ( Check_TO(A2BTM+4, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,  1 )){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(170+A2BNM,0); Bell(2,1); return; }
        }
        // �᫨ �� ��⠭����� 䫠� ��室�- ��३� �� ०�� "����� ��������"
        if(A2FLAG==2){ 
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_BV2(502); Set_ST2(600);
           A2PVID__YM=OFF;  A2PVID__YV=A2PVID__YM;
           // ᮮ�饭�� �� ����砭�� ०���
           Message(204+A2BNM,0);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  ����� "����� ��������"
    // ----------------------------------------------------------------------
    if ((A2STEPW__V==600)||(A2STEPW__V>610&&A2STEPW__V<620)){
        if(!NewSEC){ return; }
        // �᫨ � 横� �� ����祭 ०�� "����� ��������"- ��३� �� ���.०��
        if(A2SP____YV==OFF){ Set_BV2(600); Set_ST2(50); return; }
        // �஢�ઠ ������ �������� ��㣨� ��⮪�����
        // (�� ������ �������� ����� ��室���� ������ ���� ��⮪���)
        if(A1PPSTEP_V==600||A3PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV2(600); Set_ST2(50); Message(110+A2BNM,0); return;
        }
        A2PPSTEP_V=600;
        // ᮮ�饭�� � ��砫� ०���
        if(A2STEPW__V==600){ Message(205+A2BNM,0); }
        //
        A2RPRA___M=ON;
        //-----------
        // ��।������ ��ࢮ��砫쭮�� ��業� ������ ������� ��� ���
        A2FLAG=0; A2FLGP=0; if(A2TKLO___R==0) A2TKLO___R=100;
        A2FLAG=5; A2TEMP=A21SPKK05R; 
        if(A2SPAT___R>0) A2TEMP=A21SPAK05R; if(A2TEMP==0) A2TEMP=20;
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A2SPAT___R>0){ A2TEMP=A2TKLO___R*0.01*A2TEMP; }
        // �᫨ ��।���� ��� ��� � �������
        else            { A2TEMP=A2TKLO___R*0.01*A2TEMP; }
        // ���� ������� �� �����⨥ ��� �ᯮ���⥫��
        if(A2SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST2(611);
        // �������� ���᪠ ������ࠫ� ��� ������?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(613);
        // �������� ���᪠ ��९�᪭��� ��� ������?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(615);
        // �������� ����㬠 ������?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(616);
        // �������� ���᪠ ��९�᪭��� ��� ������?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A2BTM+6, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(617);
        // ��� �������஢���?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(618);
        // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
        // �⬮����
        if(A2SPAT___R>0){
          // �᫨ ��࠭ ��� � �⬮����- ������ �������� ��� ��� � 
          // �⬮����
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A2BTM+8, A2TZSPA__R* SEC, I2ZOPAO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+8]; return; }
            case BAD: { Clear_TO(A2BTM+8); Message(173+A2BNM,0); Bell(2,1); return; }
          }
        }
        Clear_TO(A2BTM+1);  Clear_TO(A2BTM+2);  Clear_TO(A2BTM+3);  
        Clear_TO(A2BTM+4);  Clear_TO(A2BTM+5);  Clear_TO(A2BTM+6);  
        Clear_TO(A2BTM+7);  Clear_TO(A2BTM+8);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(602);
        return;
    }
//  // ----------------------
//  //  ��� ��� �� ⠡���
    if (A2STEPW__V>=602 and A2STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST2(602);
        // ��᢮��� ��६����� ��業�(�६� � ᥪ㭤��) ������ ������� 
        // (�� �������  �६��� 室� �������) �� ⠡���  ᮮ⢥��⢥���
        // ⥪�饣� ��������  � ��⮪����
        // ⠡��� ��ᬠ�ਢ����� �� ����襣� � ����襬� (᭨�� �����)
        // ��� ������ �� �।��騩 蠣

        // �᫨ ⥪�饥 �������� �����-1 ��� ⥪�饥 ��������
        // ����� ��᫥����� 㪠������� � ⠡��� "����� ��������"(᭨��-�����)
        // ��� ࠧ�����஢�� ���� �� ���- ��३� �� ᫥� ०��
        if(AIP2P____V<-1 or A2FLAG==1 or I2SBP1R__V>0  or I2SBP2R__V>0){
           Set_ST2(605); Clear_TO(A2BTM+2); A2STEPZ__V=0; A2STEPC__V=0; A2FLGP=0;
           return;
        }
        
        // �᫨ ��।���� ��� ��� � �⬮����
        if(A2SPAT___R>0){
           Set_ST2(603);
           if(AIP2P____V<A21SPAP04R and A2FLAG>=5){
              // ��⠥��� ࠧ��� ��業� ������ ������� �����
              // �।��騬 � ⥪�騬 蠣��
              A2TEMP=A2TKLO___R*0.01*(A21SPAK04R-A21SPAK05R); A2FLAG=4;
           }
           if(AIP2P____V<A21SPAP03R and A2FLAG>=4){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK03R-A21SPAK04R); A2FLAG=3;
           }
           if(AIP2P____V<A21SPAP02R and A2FLAG>=3){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK02R-A21SPAK03R); A2FLAG=2;
           }
           if(AIP2P____V<A21SPAP01R and A2FLAG>=2){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK01R-A21SPAK02R); A2FLAG=1;
           }
        } else {
           Set_ST2(604);
        // �᫨ ��࠭ ��� ��� � �������
           if(AIP2P____V<A21SPKP04R and A2FLAG>=5){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK04R-A21SPKK05R); A2FLAG=4;
           }
           if(AIP2P____V<A21SPKP03R and A2FLAG>=4){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK03R-A21SPKK04R); A2FLAG=3;
           }
           if(AIP2P____V<A21SPKP02R and A2FLAG>=3){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK02R-A21SPKK03R); A2FLAG=2;
           }
           if(AIP2P____V<A21SPKP01R and A2FLAG>=2){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK01R-A21SPKK02R); A2FLAG=1;
           }
        }
        // �᫨ �� ���室 �� ���� 蠣
        if(A2FLGP!=A2FLAG){
           // �᫨ ���祭�� A2TEMP > 0 - ���뢠�� ������ ���᪠ ���,
           // ���� - ����뢠��
           if(A2TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // �������� ���祭��
           A2TEMP=fabs(A2TEMP);  
           A2FLGP=A2FLAG;
           // ���㫨�� ⠩��� � ���稪� ��� ��ࠡ�⪨ ����� ���祭��
           Clear_TO(A2BTM+1); A2STEPZ__V=0;  A2STEPC__V=0;
        }
        // ��⠥� �६� �������⢨� ᨣ���� �� ������
        switch ( Check_TO(A2BTM+1, A2TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TEMP; A2STEPC__V=CNTTO[A2BTM+1]; return; }
        }
        // ��᫥ ��ࠡ�⪨ ⠩���- ���� ᨣ���� � �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  ����ୠ� �஢�ઠ � ��室 �� ⥪�饣� ०��� � ०�� "��������"
    if (A2STEPW__V>=605 and A2STEPW__V<607){
        if(!NewSEC){ return; }
        // �᫨ ⥪�饥  �������� ����� ��� ࠢ��  ��� 
        // ���  ����襬� ���祭�� � ⠡���- 㢥��� ���稪
        if(AIP2P____V<=0 or A2FLAG==1 or I2SBP1R__V>0  or I2SBP2R__V>0){
           A2FLGP++;
        // ���� - 㬥�����
        } else { 
           A2FLGP--; 
        }
        // 10 ᥪ �������� 
        switch ( Check_TO(A2BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // �᫨ ���稪 ������⥫�� - 
        // ��३� �� 蠣 ������� �ᯮ���⥫��
        if(A2FLGP>2){
           Set_ST2(607); Clear_TO(A2BTM+1);
        } else {
        // �᫨ ���稪 ����⥫�� - �������� �� ����� ��������
           Set_ST2(603); A2FLGP=A2FLAG;
        }; Clear_TO(A2BTM+2); A2STEPZ__V =0; A2STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  �����⨥ �ᯮ���⥫�� ������ �������� � ��室 �� ०���
    if (A2STEPW__V>=607 and A2STEPW__V<609){
        if(!NewSEC){ return; }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ��� ��� � �⬮����
        switch ( Check_TO(A2BTM+1, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // �஢�ઠ ������� ������� ���᪠ ���
        switch ( Check_TO(A2BTM+2, A2TKLO___R* SEC, I2KOPC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(139+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(602); Set_ST2(50);
        A2SP____YM=OFF; A2SP____YV=A2SP____YM;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(206+A2BNM,0);
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
    if (A2STEPW__V>=700 and A2STEPW__V<702){
        if(!NewSEC){ return; }
        A2RPRA___M=ON;
        // ������ �������� ���᪠ ��९�᪭��� ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������ �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZOPPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(179+A2BNM,0); Bell(2,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A2PPSTEP_V=700;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0;  A2STEPC__V=0;
        Set_ST2(702);
        return;
    }
//  // ----------------------
//  //  ����⨥ ������� ���᪠ ���
    if (A2STEPW__V>=702 and A2STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA2(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A2IPPSTEPV>=400&&A2IPPSTEPV<500){
           // ������� ������ �������� �� ��-��
           if(A2IPPSTEPV!=425){ return; }
        } else {
        // �᫨ ��-�� ���襫 �� ०��� ������ �������� � ��㣮� ०��-
        // ��३�  �� �����⨥ �ᯮ���⥫�� (���⠭���⭠� �����)
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(704); return;
        }
        // ������ ������ ���᪠ ���
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // �஢�ઠ ������ ������� ���᪠ ���
        switch ( Check_TO(A2BTM+1, A2TKLO___R* SEC, I2KOPO___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(181+A2BNM,0); Bell(2,1); return; }
        }
        // ��᫥ ������ ��⠭����� 䫠� ���⢥ত���� ������ ��� ��-��
        A2PPSTEP_V=704;
        // ��३� �� ᫥���騩 蠣
        Clear_TO(A2BTM+1);  Clear_TO(A2BTM+2);
        A2STEPZ__V=0;  A2STEPC__V=0;
        Set_ST2(704);
        return;
    }
//  // ----------------------
//  // �����⨥ �ᯮ���⥫�� ���᪠ ��९�᪭��� ���
    if (A2STEPW__V>=704 and A2STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA2(2);
        // �᫨ ��-���樠��(��-��) ��室���� �� 蠣� ����� ���
        if(A2IPPSTEPV>=400&&A2IPPSTEPV<500){
           // ������� ���� ��-�� �� ������ �㦭��� �������� � ��
           // ��३���  �� 蠣 ������� �ᯮ���⥫��
           if(A2IPPSTEPV!=480){ return; }
           // �᫨ ��-���樠�� �襫 �� ०��� ����� ��������- ����뢠��
           // �ᯮ���⥫� � ���室�� � ०��  ��������
           //(���⠭���⭠� �����)
        }
        // �뤠�� ������� �� �����⨥ ��� �ᯮ���⥫��
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // �஢�ઠ ������� �������� ���᪠ ��९�᪭��� ���
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // ������� ������ ���᪠ ���
        switch ( Check_TO(A2BTM+2, A2TKLO___R* SEC, I2KOPC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(139+A2BNM,0); Bell(2,1); return; }
        }
        // ��᫥ ������� ��⠭����� 䫠� ���⢥ত���� ������� �ᯮ���⥫��
        A2PPSTEP_V=705;
        // ��᫥ ����砭�� ��९�᪠ ��� ��⮪��� ��४��砥��� � ०��
        // "����� ��������"
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(704); Set_ST2(600);
        // �᫨ ��-�� �� � ०��� ������ �������� (���⠭���⭠� �����)
        // ��ॢ��� ��� �� � ०�� ��������
        if(A2IPPSTEPV<400||A2IPPSTEPV>500){ Set_ST2(50); }
        A2SP____YM=OFF; A2SP____YV=ON;
        // ᮮ�饭�� �� ����砭�� ०���
        Message(207+A2BNM,0);
        return;
    }
//  // ----------------------------------------------------------------------


    return;
}
//---------------------------------------------------------------------------
