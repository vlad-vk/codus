//---------------------------------------------------------------------------
// ॣ���� �������� ��1 (���� ���)

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
vd  far Regul_1z(vd){

    //-----------------------------------------------------------------------
    ui RN2=5;                        // ����� ॣ����

    if (A1RPOUF2_M>OFF){
        A1RPOUF2_V=(A1RPOUF2_V>0) then_ OFF else_ ON; A1RPOUF2_M=OFF;
    }

    //-----------------------------------------------------------------------
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A1RPMO2__M < 0  ){ A1RPMO2__M =0;   }
    if (A1RPMO2__M > 100){ A1RPMO2__M =100; }

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
       OutX[RN2]=(A1RPMO2__M-AIS1PI___V)*(A1RPKP___R*0.02);

       if(A1RPRA___V==OFF){
          if(A1RPOUF2_V==ON){
             A1RPUU2__V =RegulDigit(RN2, A1RPKIML_R, A1RPKIMP_R, A1RPKM___R,
                                         A1RPRA___V, 5);
          } else {
             if(A1RPUU2__V!=A1RPUU2__M&&A1RPUU2__V==RSTOP){
                A1RPUU2__V =A1RPUU2__M;
             }
             if(A1RPUU2__V!=A1RPUU2__M&&A1RPUU2__V!=RSTOP){
                A1RPUU2__V =RSTOP;
             }; A1RPUU2__M =A1RPUU2__V;
          }
       } 
     
       //--------------------------------------------------------------------
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if(A1RPRA___V==OFF||A1STEPW__V<600){
          if(A1RPUU2__V==RPLUS ){ O1KOPO___M=1; O1KOPO___V=1; O1KOPC___M=0; O1KOPC___V=0; }
          if(A1RPUU2__V==RMINUS){ O1KOPO___M=0; O1KOPO___V=0; O1KOPC___M=1; O1KOPC___V=1; }
          if(A1RPUU2__V==RSTOP ){ O1KOPO___M=0; O1KOPO___V=0; O1KOPC___M=0; O1KOPC___V=0; }
       }
       // ���祭�� ��� ���㠫���樨 ࠡ��� ॣ���� ��� ������
       A1RPX2___V= OutO [RN2];
       A1RPCP2__V= ImpLC[RN2];
       A1RPCW2__V= ImpWC[RN2];
    }
    return;
}
//---------------------------------------------------------------------------
