//---------------------------------------------------------------------------
// ॣ���� �������� ��2 (���� ���)

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
vd  far Regul_2z(vd){

    //-----------------------------------------------------------------------
    ui RN2=10;                       // ����� ॣ����

    if (A2RPOUF2_M>OFF){
        A2RPOUF2_V=(A2RPOUF2_V>0) then_ OFF else_ ON; A2RPOUF2_M=OFF;
    }

    //-----------------------------------------------------------------------
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A2RPMO2__M < 0  ){ A2RPMO2__M =0;   }
    if (A2RPMO2__M > 100){ A2RPMO2__M =100; }

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
       OutX[RN2]=(A2RPMO2__M-AIS2PI___V)*(A2RPKP___R*0.02);

       if(A2RPRA___V==OFF){
          if(A2RPOUF2_V==ON){
             A2RPUU2__V =RegulDigit(RN2, A2RPKIML_R, A2RPKIMP_R, A2RPKM___R,
                                         A2RPRA___V, 5);
          } else {
             if(A2RPUU2__V!=A2RPUU2__M&&A2RPUU2__V==RSTOP){
                A2RPUU2__V =A2RPUU2__M;
             }
             if(A2RPUU2__V!=A2RPUU2__M&&A2RPUU2__V!=RSTOP){
                A2RPUU2__V =RSTOP;
             }; A2RPUU2__M =A2RPUU2__V;
          }
       } 
     
       //--------------------------------------------------------------------
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if(A2RPRA___V==OFF||A2STEPW__V<600){
          if(A2RPUU2__V==RPLUS ){ O2KOPO___M=1; O2KOPO___V=1; O2KOPC___M=0; O2KOPC___V=0; }
          if(A2RPUU2__V==RMINUS){ O2KOPO___M=0; O2KOPO___V=0; O2KOPC___M=1; O2KOPC___V=1; }
          if(A2RPUU2__V==RSTOP ){ O2KOPO___M=0; O2KOPO___V=0; O2KOPC___M=0; O2KOPC___V=0; }
       }
       // ���祭�� ��� ���㠫���樨 ࠡ��� ॣ���� ��� ������
       A2RPX2___V= OutO [RN2];
       A2RPCP2__V= ImpLC[RN2];
       A2RPCW2__V= ImpWC[RN2];
    }
    return;
}
//---------------------------------------------------------------------------
