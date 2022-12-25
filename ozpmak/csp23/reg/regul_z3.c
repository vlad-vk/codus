//---------------------------------------------------------------------------
// ॣ���� �������� ��3 (���� ���)

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
vd  far Regul_3z(vd){

    //-----------------------------------------------------------------------
    ui RN2=5;                        // ����� ॣ����

    if (A3RPOUF2_M>OFF){
        A3RPOUF2_V=(A3RPOUF2_V>0) then_ OFF else_ ON; A3RPOUF2_M=OFF;
    }

    //-----------------------------------------------------------------------
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (A3RPMO2__M < 0  ){ A3RPMO2__M =0;   }
    if (A3RPMO2__M > 100){ A3RPMO2__M =100; }

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
       OutX[RN2]=(A3RPMO2__M-AIS3PI___V)*(A3RPKP___R*0.02);

       if(A3RPRA___V==OFF){
          if(A3RPOUF2_V==ON){
             A3RPUU2__V =RegulDigit(RN2, A3RPKIML_R, A3RPKIMP_R, A3RPKM___R,
                                         A3RPRA___V, 5);
          } else {
             if(A3RPUU2__V!=A3RPUU2__M&&A3RPUU2__V==RSTOP){
                A3RPUU2__V =A3RPUU2__M;
             }
             if(A3RPUU2__V!=A3RPUU2__M&&A3RPUU2__V!=RSTOP){
                A3RPUU2__V =RSTOP;
             }; A3RPUU2__M =A3RPUU2__V;
          }
       } 
     
       //--------------------------------------------------------------------
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if(A3RPRA___V==OFF||A3STEPW__V<600){
          if(A3RPUU2__V==RPLUS ){ O3KOPO___M=1; O3KOPO___V=1; O3KOPC___M=0; O3KOPC___V=0; }
          if(A3RPUU2__V==RMINUS){ O3KOPO___M=0; O3KOPO___V=0; O3KOPC___M=1; O3KOPC___V=1; }
          if(A3RPUU2__V==RSTOP ){ O3KOPO___M=0; O3KOPO___V=0; O3KOPC___M=0; O3KOPC___V=0; }
       }
       // ���祭�� ��� ���㠫���樨 ࠡ��� ॣ���� ��� ������
       A3RPX2___V= OutO [RN2];
       A3RPCP2__V= ImpLC[RN2];
       A3RPCW2__V= ImpWC[RN2];
    }
    return;
}
//---------------------------------------------------------------------------
