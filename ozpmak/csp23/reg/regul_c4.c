//---------------------------------------------------------------------------
// ॣ���� �������� ��4

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//  ����騩 ���稪 室� ������� (⥪�饥 �����᪮� ���ﭨ�)
_f  far  A4RCHKF__C = 0;
//  ����騩 ���稪 �������쭮�� 室� �������
_f  far  A4RCHKN__C = 0;
//  ����騩 ���稪 �������쭮� ���� ����� �����ᠬ�
_f  far  A4RCHKP__C = 0;
//  �।��騩 ᨣ��� ��室� �� ������
_f  far  A4RCUU___P = 0;


//---------------------------------------------------------------------------
vd  far Regul_4c(vd){
    //-----------------------------------------------------------------------
    ui RN1=6;                        // ����� ॣ����
    ui RN2=7;                        // ����� ॣ����
    _f IL=-20;                       // �室��� 誠�� (������ �࠭��)
    _f IH= 20;                       // �室��� 誠�� (������ �࠭��)
    _f OL=0.000;                     // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                     // ��室��� 誠�� (������),%, �.��.
    _f DM=20.00;                     // ���� ���� ��� ॣ����
    _f ZN=A4RCKZN__R;                // ���� �����⢨⥫쭮��
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
    IN=MDivF(AIL4C____V,DP);
    // �஢�ઠ ���祭�� �室���� ��ࠬ��� ॣ����
    if(IN<IL) IN=IL; if(IN>IH) IN=IH;

    //-----------------------------------------------------------------------
    // ��४��祭�� ��筮�-��⮬��
    if (A4RCRA___M!=A4RCRA___V){
        if(A4RCRA___M==SWITCH) A4RCRA___M=(A4RCRA___V>0) then_ OFF else_ AUTO;
        A4RCRA___V =A4RCRA___M;
        if(A4RCRA___V==AUTO){ 
           Message(120+A4BNM); 
        } else { 
           Message(121+A4BNM); A4RCMO___M=A4RCMO___V=WO_Skip[RN1];
           if(A4RCUU___P==RPLUS ) A4RCUU___M=RMINUS;
           if(A4RCUU___P==RMINUS) A4RCUU___M=RPLUS;
           AMAN=1;
        }
    }
    if (A4RCOUF__M>OFF){
        A4RCOUF__V=(A4RCOUF__V>0) then_ OFF else_ ON; A4RCOUF__M=OFF;
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (A4RCZD___M < IL ){ A4RCZD___M = IL; }
    if (A4RCZD___M > IH ){ A4RCZD___M = IH; }
    A4RCZD___V =  A4RCZD___M;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A4RCMO___M < 0  ){ A4RCMO___M =0;   }
    if (A4RCMO___M > 100){ A4RCMO___M =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    A4RCLO___V =A4RCLO___M;
    A4RCHO___V =A4RCHO___M;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    A4RCLP___V =A4RCLP___M;
    A4RCHP___V =A4RCHP___M;
    // �᫨ ��।���� ����� 室 ������� � ᥪ㭤�� � ��� 室 ������� � %
    if(A4RCHKF__R>0  and  A4RCHKN__R>0){
       if(fabs(A4RCHKN__R)>20) A4RCHKN__R=20;
       // ��।����� ��������� 室 ������� � ᥪ㭤��
       CCMGK=fabs(A4RCHKF__R*0.01*A4RCHKN__R);
    }

    //-----------------------------------------------------------------------
    // �᫨ ��⠭����� 䫠� �믮������ ॣ���஢ (ࠧ � ᥪ㭤�) � ���稪
    // �������쭮�� 室� ������� ����� ��������� � �� ����祭 ०�� ��������.
//  if (RegRUN==ON and A4RCHKN__C>CCMGK and A4STEP___V!=3){
    if (RegRUN==ON and A4STEP___V!=3){
       //--------------------------------------------------------------------
       // ���㫨�� ���稪 �������쭮�� 室� �������
       A4RCHKN__C=0;
       // ��������� ॣ����
       A4RCMO___V=Regulator(RN1,IN,
                                A4RCKP___R, A4RCKI___R, 
                                A4RCKD___R, A4RCKM___R,
                                A4RCMO___M, A4RCRA___V,
                                A4RCZD___V, A4RCZD___V,
                                IL, IH, OL, OH,
                                DM, ZN, PR, CC, TP
       );
       // ��࠭�祭�� ��室�, %
       if (A4RCMO___V <  OL+ A4RCLO___V){ A4RCMO___V=OL+A4RCLO___V; }
       if (A4RCMO___V >  OH- A4RCHO___V){ A4RCMO___V=OH-A4RCHO___V; }
       if (A4RCKM___R >= 0){ A4RCOO___V=100-A4RCMO___V; }
       else                { A4RCOO___V=A4RCMO___V;     }
       //--------------------------------------------------------------------
       // ������ ॣ����
       // P01 - ����� ॣ����
       // P02 - �����樥�� ������ ������
       // P03 - �����樥�� ������ ����
       // P04 - �����樥�� ����⠡�
       // P05 - ०�� ࠡ��� ॣ���� (��筮�-��⮬��)
       // P06 - ��室 ��筮�� �ࠢ����� ॣ����
       // RET - ������ ��室 (RMINUS=0; RSTOP=1; RPLUS=2;)
       A4RCUU___V=RegulDigit(RN1,A4RCKIML_R, A4RCKIMP_R, A4RCKM___R, 
                                 A4RCRA___V, A4RCUU___M);
       AITEMP=(A4RCZD___V-IN)*A4RCKP___R;
       //--------------------------------------------------------------------
       // �᫨ ॣ���� � ��筮� ०��� � ������� �� �����樥���-
       // ��� ������ �������  �������� % ��� ���������.
       // �᫨ ���� �� �����樥�⮢  �� ������(����.����७�஢����=0)
       // ������ �ࠢ����� ����⨥� �� ��࠭� ������ "����" � "�����".
       // �᫨ � ��筮� � ����祭� �ࠢ����� � ���������� ���祭��
       if(A4RCRA___V==OFF and A4RCOUF__V==ON and AMAN==0){
          OutX[RN2]=(A4RCMO___M-AIS4CO___V)*(A4RCKP___R*0.02);
          A4RCUU___V =RegulDigit(RN2, A4RCKIML_R, A4RCKIMP_R, A4RCKM___R,
                                      A4RCRA___V, 5);
          AITEMP=(A4RCMO___V-AIS4CO___V) *A4RCKP___R;
       } 
       //--------------------------------------------------------------------
       // ��ॢ����� ᨣ���, �᫨ �����樥�� ����⠡�஢���� ����⥫��
       if(A4RCKM___R<0){
//        if(AITEMP>0){
             if(A4RCUU___V==RPLUS){
                A4RCUU___V=RMINUS;
             } else {
                if(A4RCUU___V==RMINUS){ A4RCUU___V=RPLUS; }
             }
//        } 
       }
       //--------------------------------------------------------------------
//     // �ࠧ� ����� ᨣ���(������) �뤠���� ����� (⮫쪮 �१ ��⠭��)
//     if((A4RCUU___V==RPLUS  and A4RCUU___P==RMINUS)||
//        (A4RCUU___V==RMINUS and A4RCUU___P==RPLUS )){ A4RCUU___V=RSTOP; }
//     //--------------------------------------------------------------------
       // � ��筮� ०���
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if((A4RCRA___V==OFF)||(A4RCRA___V==ON&&A4STEP___V!=3)){
          if(A4RCUU___V==RPLUS ){ O4KOCO___M=1; O4KOCO___V=1; O4KOCC___M=0; O4KOCC___V=0; }
          if(A4RCUU___V==RMINUS){ O4KOCO___M=0; O4KOCO___V=0; O4KOCC___M=1; O4KOCC___V=1; }
          if(A4RCUU___V==RSTOP ){ O4KOCO___M=0; O4KOCO___V=0; O4KOCC___M=0; O4KOCC___V=0; }
       }
       A4RCUU___P= A4RCUU___V;
       // ����� ��筮� ��室 � ����।������� ���ﭨ�
       A4RCUU___M= RNA;
       // �뢥�� ���祭�� ࠡ��� ॣ���� ������� �� ��࠭
       if(A4RCRA___V>OFF){
          A4RCX____V= OutO [RN1];
          A4RCCP___V= ImpLC[RN1];
          A4RCCW___V= ImpWC[RN1];
       } else {
          A4RCX____V= OutO [RN2];
          A4RCCP___V= ImpLC[RN2];
          A4RCCW___V= ImpWC[RN2];
       }
    }
    //-----------------------------------------------------------------------
    // ����஫� �����ᮢ ॣ���� � ���稪��
    // ࠧ � ᥪ㭤�
    if (NewSEC==ON and A4STEP___V!=3){
       // �᫨  ���� ᨣ���  �� ����⨥ ��� ᨣ��� � ���楢��� ���.���������
       if(A4RCUU___V==RPLUS  or O4KOCO___V>0 or I4KOCO___V>0){
          // �������� ⥪�騥 ���稪�
          if(A4RCHKF__C<A4RCHKF__R) A4RCHKF__C++;  // ������� ������
          if(A4RCHKN__C<A4RCHKF__R) A4RCHKN__C++;  // ��� 室� �ᯮ���⥫�
       }
       // �᫨  ���� ᨣ���  �� �����⨥ ��� ᨣ��� � ���楢��� ����.���������
       if(A4RCUU___V==RMINUS or O4KOCC___V>0 or I4KOCC___V>0){
          // �������� ⥪�騥 ���稪�
          if(A4RCHKF__C>         0) A4RCHKF__C--;  // ������� ������
          if(A4RCHKN__C<A4RCHKF__R) A4RCHKN__C++;  // ��� 室� �ᯮ���⥫�
       }
       // �᫨ �ࠡ�⠫ ���楢�� ����⮣� ���������- ��������� ���稪 �
       // ��������� ���祭��
       if(I4KOCO___V>0){ A4RCHKF__C=A4RCHKF__R; }
       // �᫨ �ࠡ�⠫ ���楢�� �����⮣� ���������- ����� ���稪 �� ����
       if(I4KOCC___V>0){ A4RCHKF__C=0; }
    }
    //-----------------------------------------------------------------------
    // �᫨ ��।���� ०�� ����㬨஢����- ���� ������ � ��⠭����� ॣ����

    //-----------------------------------------------------------------------
    // ���祭�� ��� �७�� �ணࠬ�� ������:
    // ��������� ��室 ॣ����
    A4RCAOTR_V= A4RCMO___V * 0.4 - 20;
    // ��������� ������� ��� �७��
    A4RCPKTR_V= AIS4CO___V * 0.4 - 20;

    return;
}
//---------------------------------------------------------------------------

