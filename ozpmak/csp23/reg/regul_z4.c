//---------------------------------------------------------------------------
// ॣ���� �������� ��4 (���� ���)

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
vd  far Regul_4z(vd){

    //-----------------------------------------------------------------------
    ui RN2=10;                       // ����� ॣ����

    if (A4RPOUF2_M>OFF){
        A4RPOUF2_V=(A4RPOUF2_V>0) then_ OFF else_ ON; A4RPOUF2_M=OFF;
    }

    //-----------------------------------------------------------------------
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A4RPMO2__M < 0  ){ A4RPMO2__M =0;   }
    if (A4RPMO2__M > 100){ A4RPMO2__M =100; }

    //-----------------------------------------------------------------------
    if (RegRUN==ON){
       // ������ ॣ����
       // P01 - ����� ॣ����
       // P02 - �����樥�� ������ ������
       // P03 - �����樥�� ������ ����
       // P04 - �����樥�� ����⠡�
       // P05 - ०�� ࠡ��� ॣ���� (��筮�-��⮬��)
       // P06 - ��室 ��筮�� �ࠢ����� ॣ����
       // RET - ������ ��室 (RMINUS=0; RSTOP=1; RPLUS=2;)
       OutX[RN2]=(A4RPMO2__M-AIS4PI___V)*(A4RPKP___R*0.02);

       if(A4RPRA___V==OFF){
          if(A4RPOUF2_V==ON){
             A4RPUU2__V =RegulDigit(RN2, A4RPKIML_R, A4RPKIMP_R, A4RPKM___R,
                                         A4RPRA___V, 5);
          } else {
             if(A4RPUU2__V!=A4RPUU2__M&&A4RPUU2__V==RSTOP){
                A4RPUU2__V =A4RPUU2__M;
             }
             if(A4RPUU2__V!=A4RPUU2__M&&A4RPUU2__V!=RSTOP){
                A4RPUU2__V =RSTOP;
             }; A4RPUU2__M =A4RPUU2__V;
          }
       } 
     
       //--------------------------------------------------------------------
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if(A4RPRA___V==OFF||A4STEPW__V<600){
          if(A4RPUU2__V==RPLUS ){ O4KOPO___M=1; O4KOPO___V=1; O4KOPC___M=0; O4KOPC___V=0; }
          if(A4RPUU2__V==RMINUS){ O4KOPO___M=0; O4KOPO___V=0; O4KOPC___M=1; O4KOPC___V=1; }
          if(A4RPUU2__V==RSTOP ){ O4KOPO___M=0; O4KOPO___V=0; O4KOPC___M=0; O4KOPC___V=0; }
       }
       // ���祭�� ��� ���㠫���樨 ࠡ��� ॣ���� ��� ������
       A4RPX2___V= OutO [RN2];
       A4RPCP2__V= ImpLC[RN2];
       A4RPCW2__V= ImpWC[RN2];
    }
    return;
}
//---------------------------------------------------------------------------
