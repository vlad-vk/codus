//---------------------------------------------------------------------------
// ॣ���� ����� �������� ��3

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//  ����騩 ���稪 室� ������� (⥪�饥 �����᪮� ���ﭨ�)
_f  far  A3RPHKF__C = 0;
//  ����騩 ���稪 �������쭮�� 室� �������
_f  far  A3RPHKN__C = 0;
//  ����騩 ���稪 �������쭮� ���� ����� �����ᠬ�
_f  far  A3RPHKP__C = 0;
//  �।��騩 ᨣ��� ��室� �� ������
_f  far  A3RPUU1__P = 0;


//---------------------------------------------------------------------------
vd  far Regul_3p(vd){
    //-----------------------------------------------------------------------
    ui RN1=3;                        // ����� ॣ����
    ui RN2=4;                        // ����� ॣ����
    _f IL=0;                         // �室��� 誠�� (������ �࠭��)
    _f IH=8;                         // �室��� 誠�� (������ �࠭��)
    _f OL=0.000;                     // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                     // ��室��� 誠�� (������),%, �.��.
    _f DM=20.00;                     // ���� ���� ��� ॣ����
    _f ZN=A3RPKZN__R;                // ���� �����⢨⥫쭮��
    _f PR=20.00;                     // ��業� ��ᮣ��ᮢ����
    _f CC=20;                        // ����஫�� 横�
    ui TP=1;                         // ��� ॣ����
    _f DP=0;                         // �ਢ������ � ��������� � %
    _f IN=0;                         // �室��� ���祭��
    _f CCMGK=-1;                     // ��������� 室 �������
    ui AMAN=0;

    //-----------------------------------------------------------------------
    // ��� �ਢ������ �室���� ��ࠬ���� � 誠�� 100% (��������஢��� DP=1)
    // 20: ���� ���������; -20: ��� ���������
    DP=(IH-(IL))*0.01; 
    DP=1;
    IN=MDivF(AIF3P____V,DP);
    // �஢�ઠ ���祭�� �室���� ��ࠬ��� ॣ����
    if(IN<IL) IN=IL; if(IN>IH) IN=IH;
    //-----------------------------------------------------------------------
    if (A3RPRA___M!=A3RPRA___V){
        if(A3RPRA___M==SWITCH) A3RPRA___M=(A3RPRA___V>0) then_ OFF else_ AUTO;
        A3RPRA___V =A3RPRA___M;
        if(A3RPRA___V==AUTO){ 
           Message(122+A3BNM); A3RPUU1__M=RMINUS;
        } else { 
           Message(123+A3BNM); A3RPMO1__M=A3RPMO1__V=WO_Skip[RN1];
           if(A3RPUU1__P==RPLUS ) A3RPUU1__M=RMINUS;
           if(A3RPUU1__P==RMINUS) A3RPUU1__M=RPLUS;
           AMAN=1;
        }
    }
    if (A3RPOUF1_M>OFF){
        A3RPOUF1_V=(A3RPOUF1_V>0) then_ OFF else_ ON; A3RPOUF1_M=OFF;
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (A3RPZD___M < IL ){ A3RPZD___M = IL; }
    if (A3RPZD___M > IH ){ A3RPZD___M = IH; }
    A3RPZD___V = A3RPZD___M;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A3RPMO1__M < 0  ){ A3RPMO1__M =0;   }
    if (A3RPMO1__M > 100){ A3RPMO1__M =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    A3RPLO___V = A3RPLO___M;
    A3RPHO___V = A3RPHO___M;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    A3RPLP___V = A3RPLP___M;
    A3RPHP___V = A3RPHP___M;
    // �᫨ ��।���� ����� 室 ������� � ᥪ㭤�� � ��� 室 ������� � %
    if(A3RPHKF__R>0  and  A3RPHKN__R>0){
       if(fabs(A3RPHKN__R)>20) A3RPHKN__R=20;
       // ��।����� ��������� 室 ������� � ᥪ㭤��
       CCMGK=fabs(A3RPHKF__R*0.01*A3RPHKN__R);
    }

    //-----------------------------------------------------------------------
    // �᫨ ��⠭����� 䫠� �믮������ ॣ���஢ (ࠧ � ᥪ㭤�) � ���稪
    // �������쭮�� 室� ������� ����� ���������
//  if (RegRUN==ON and A3RPHKN__C>CCMGK){
    if (RegRUN==ON){
       //--------------------------------------------------------------------
       // ���㫨�� ���稪 �������쭮�� 室� �������
       A3RPHKN__C=0;
       //--------------------------------------------------------------------
       // ��������� ॣ����
       A3RPMO1__V=Regulator(RN1,IN,
                                A3RPKP___R, A3RPKI___R, 
                                A3RPKD___R, A3RPKM___R,
                                A3RPMO1__M, A3RPRA___V,
                                A3RPZD___V, A3RPZD___V,
                                IL, IH, OL, OH,
                                DM, ZN, PR, CC, TP
       );
       // ��࠭�祭�� ��室�, %
       if (A3RPMO1__V <  OL+ A3RPLO___V){ A3RPMO1__V=OL+A3RPLO___V; }
       if (A3RPMO1__V >  OH- A3RPHO___V){ A3RPMO1__V=OH-A3RPHO___V; }
       if (A3RPKM___R >= 0){ A3RPOO___V=100-A3RPMO1__V; }
       else                { A3RPOO___V=A3RPMO1__V;     }
       //--------------------------------------------------------------------
       // ������ ॣ����
       // P01 - ����� ॣ����
       // P02 - �����樥�� ������ ������
       // P03 - �����樥�� ������ ����
       // P04 - �����樥�� ����⠡�
       // P05 - ०�� ࠡ��� ॣ���� (��筮�-��⮬��)
       // P06 - ��室 ��筮�� �ࠢ����� ॣ����
       // RET - ������ ��室 (RMINUS=0; RSTOP=1; RPLUS=2;)
       A3RPUU1__V=RegulDigit(RN1,A3RPKIML_R, A3RPKIMP_R, A3RPKM___R, 
                                 A3RPRA___V, A3RPUU1__M);
       AITEMP=(A3RPZD___V-AIP3P____V)*A3RPKP___R;
       //--------------------------------------------------------------------
       // �᫨ � ��筮� � ����祭� �ࠢ����� � ���������� ���祭��
       if(A3RPRA___V==OFF and A3RPOUF1_V==ON and AMAN==0){
          OutX[RN2]=(A3RPMO1__M-AIS3PI___V)*(A3RPKP___R*0.02);
          A3RPUU1__V =RegulDigit(RN2, A3RPKIML_R, A3RPKIMP_R, A3RPKM___R,
                                      A3RPRA___V, 5);
          AITEMP=(A3RPMO1__V-AIS3PI___V) *A3RPKP___R;
       } 
       //--------------------------------------------------------------------
       // ��ॢ����� ᨣ���, �᫨ �����樥�� ����⠡�஢���� ����⥫��
       if(A3RPKM___R<0){
//        if(AITEMP>0){
             if(A3RPUU1__V==RPLUS){
                A3RPUU1__V=RMINUS;
             } else {
                if(A3RPUU1__V==RMINUS){ A3RPUU1__V=RPLUS; }
             }
//        } 
       }
       //--------------------------------------------------------------------
//     // �ࠧ� ����� ᨣ���(������) �뤠���� ����� (⮫쪮 �१ ��⠭��)
//     if((A3RPUU1__V==RPLUS  and A3RPUU1__P==RMINUS)||
//        (A3RPUU1__V==RMINUS and A3RPUU1__P==RPLUS )){ A3RPUU1__V=RSTOP; }
//     //--------------------------------------------------------------------
       // �᫨ ॣ���� � ��筮� ०��� ��� �᫨ � ��⮬��, �� �� ��। 蠣�-
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       A3RPOUT__V=0;
       if((A3RPRA___V==OFF)|| 
          (A3RPRA___V==ON&&A3STEPW__V>440&&A3STEPW__V<445&&A3STEPW__V!=442)){
           if(A3RPUU1__V==RPLUS ){ O3KIPO___M=1; O3KIPO___V=1; O3KIPC___M=0; O3KIPC___V=0; }
           if(A3RPUU1__V==RMINUS){ O3KIPO___M=0; O3KIPO___V=0; O3KIPC___M=1; O3KIPC___V=1; }
           if(A3RPUU1__V==RSTOP ){ O3KIPO___M=0; O3KIPO___V=0; O3KIPC___M=0; O3KIPC___V=0; }
           A3RPOUT__V=1;
       }
       A3RPUU1__P= A3RPUU1__V;
       // ����� ��筮� ��室 � ����।������� ���ﭨ�
       A3RPUU1__M= RNA;
       // �뢥�� ���祭�� ࠡ��� ॣ���� ������� �� ��࠭
       if(A3RPRA___V>OFF){
          A3RPX1___V= OutO [RN1];
          A3RPCP1__V= ImpLC[RN1];
          A3RPCW1__V= ImpWC[RN1];
       } else {
          A3RPX1___V= OutO [RN2];
          A3RPCP1__V= ImpLC[RN2];
          A3RPCW1__V= ImpWC[RN2];
       }
    }
    //-----------------------------------------------------------------------
    // ����஫� �����ᮢ ॣ���� � ���稪��
    // ࠧ � ᥪ㭤�
    if (NewSEC==ON){
       // �᫨  ���� ᨣ���  �� ����⨥ ��� ᨣ��� � ���楢��� ���.���������
       if(A3RPUU1__V==RPLUS  or O3KIPO___V>0 or I3KIPO___V>0){
          // �������� ⥪�騥 ���稪�
          if(A3RPHKF__C<A3RPHKF__R) A3RPHKF__C++;  // ������� ������
          if(A3RPHKN__C<A3RPHKF__R) A3RPHKN__C++;  // ��� 室� �ᯮ���⥫�
       }
       // �᫨  ���� ᨣ���  �� �����⨥ ��� ᨣ��� � ���楢��� ����.���������
       if(A3RPUU1__V==RMINUS or O3KIPC___V>0 or I3KIPC___V>0){
          // �������� ⥪�騥 ���稪�
          if(A3RPHKF__C>         0) A3RPHKF__C--;  // ������� ������
          if(A3RPHKN__C<A3RPHKF__R) A3RPHKN__C++;  // ��� 室� �ᯮ���⥫�
       }
       // �᫨ �ࠡ�⠫ ���楢�� ����⮣� ���������- ��������� ���稪 �
       // ��������� ���祭��
       if(I3KIPO___V>0){ A3RPHKF__C=A3RPHKF__R; }
       // �᫨ �ࠡ�⠫ ���楢�� �����⮣� ���������- ����� ���稪 �� ����
       if(I3KIPC___V>0){ A3RPHKF__C=0; }
    }
    //-----------------------------------------------------------------------
    // ���祭�� ��� �७�� �ணࠬ�� ������:
    // ��������� ��室 ॣ����
    A3RPAOTR_V= A3RPMO1__V * 0.08;
    // ��������� �������
    A3RPPKTR_V= AIS3PI___V * 0.08;
    // ⥬������ ��⮪����
    A3RPTATR_V= AIT3P____V * 0.04;

    return;
}
//---------------------------------------------------------------------------
