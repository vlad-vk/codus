//----------------------------------------------------------------------------
// ��騥 �㭪樨 ॣ���஢

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far A1SPAT___S = 0;            // �।��� ���� ������ "��� � �⬮��"
_f  far A1SPAK___S = 0;            // �।��� ���� ������ "��� � ����"
_f  far A2SPAT___S = 0;            // 
_f  far A2SPAK___S = 0;            // 

//----------------------------------------------------------------------------
vd  far Regul_up(vd){

    // ��������� � �������� ���������� � ������� ��� ����������

    // �롮� ०���� ࠡ��� ��� 横��
    if(A1NAKPP_YM==SWITCH){ A1NAKPP_YV=(A1NAKPP_YV>OFF) then_ OFF else_ ON; }
    if(A1RAZVK_YM==SWITCH){ A1RAZVK_YV=(A1RAZVK_YV>OFF) then_ OFF else_ ON; }
    if(A1PPP___YM==SWITCH){ A1PPP___YV=(A1PPP___YV>OFF) then_ OFF else_ ON; }
    if(A1PVID__YM==SWITCH){ A1PVID__YV=(A1PVID__YV>OFF) then_ OFF else_ ON; }
    if(A1SP____YM==SWITCH){ A1SP____YV=(A1SP____YV>OFF) then_ OFF else_ ON; }
    A1NAKPP_YM=OFF; A1RAZVK_YM=OFF; A1PPP___YM=OFF; 
    A1PVID__YM=OFF; A1SP____YM=OFF;
    if(A2NAKPP_YM==SWITCH){ A2NAKPP_YV=(A2NAKPP_YV>OFF) then_ OFF else_ ON; }
    if(A2RAZVK_YM==SWITCH){ A2RAZVK_YV=(A2RAZVK_YV>OFF) then_ OFF else_ ON; }
    if(A2PPP___YM==SWITCH){ A2PPP___YV=(A2PPP___YV>OFF) then_ OFF else_ ON; }
    if(A2PVID__YM==SWITCH){ A2PVID__YV=(A2PVID__YV>OFF) then_ OFF else_ ON; }
    if(A2SP____YM==SWITCH){ A2SP____YV=(A2SP____YV>OFF) then_ OFF else_ ON; }
    A2NAKPP_YM=OFF; A2RAZVK_YM=OFF; A2PPP___YM=OFF; 
    A2PVID__YM=OFF; A2SP____YM=OFF;


    // �஢�ઠ ����� ����� ��⮪���� ��� ��९�᪠
    if(A1NAKPP__R==1 or  A1NAKPP__R> 6){ A1NAKPP__R=0; }
    if(A2NAKPP__R==2 or  A2NAKPP__R> 6){ A2NAKPP__R=0; }

    // �롮� �����祭�� ��� ���
    if(A1SPAT___R> 0 and A1SPAT___S==0){ A1SPAK___R=0; }
    if(A1SPAK___R> 0 and A1SPAK___S==0){ A1SPAT___R=0; }
    if(A1SPAT___R==0 and A1SPAK___R==0){ A1SPAT___R=1; }
    A1SPAT___S=A1SPAT___R;
    A1SPAK___S=A1SPAK___R;
    if(A2SPAT___R> 0 and A2SPAT___S==0){ A2SPAK___R=0; }
    if(A2SPAK___R> 0 and A2SPAK___S==0){ A2SPAT___R=0; }
    if(A2SPAT___R==0 and A2SPAK___R==0){ A2SPAT___R=1; }
    A2SPAT___S=A2SPAT___R;
    A2SPAK___S=A2SPAK___R;

    // ����஫� ���������� ⠡���� ०���� 
    //----------------------------------------------
    // ����� ��९�᪭� ��஬ �� � 
    if(A11NTPP01R>A11NTPP02R) A11NTPP02R=A11NTPP01R;
    if(A11NTPP02R>A11NTPP03R) A11NTPP03R=A11NTPP02R;
    if(A11NTPP03R>A11NTPP04R) A11NTPP04R=A11NTPP03R;
    if(A11NTPP04R>A11NTPP05R) A11NTPP05R=A11NTPP04R;
    // ����� �����  ��஬ �� �
    if(A11NTOP01R>A11NTOP02R) A11NTOP02R=A11NTOP01R;
    if(A11NTOP02R>A11NTOP03R) A11NTOP03R=A11NTOP02R;
    if(A11NTOP03R>A11NTOP04R) A11NTOP04R=A11NTOP03R;
    if(A11NTOP04R>A11NTOP05R) A11NTOP05R=A11NTOP04R;
    // ����� ��९�᪭� ��஬ �� P
    if(A11NPPP01R>A11NPPP02R) A11NPPP02R=A11NPPP01R;
    if(A11NPPP02R>A11NPPP03R) A11NPPP03R=A11NPPP02R;
    if(A11NPPP03R>A11NPPP04R) A11NPPP04R=A11NPPP03R;
    if(A11NPPP04R>A11NPPP05R) A11NPPP05R=A11NPPP04R;
    if(A11NPPP05R>A11NPPP06R) A11NPPP06R=A11NPPP05R;
    if(A11NPPP06R>A11NPPP07R) A11NPPP07R=A11NPPP06R;
    if(A11NPPP07R>A11NPPP08R) A11NPPP08R=A11NPPP07R;
    if(A11NPPP08R>A11NPPP09R) A11NPPP09R=A11NPPP08R;
    if(A11NPPP09R>A11NPPP10R) A11NPPP10R=A11NPPP09R;
    // ����� �����  ��஬ �� P
    if(A11NPOP01R>A11NPOP02R) A11NPOP02R=A11NPOP01R;
    if(A11NPOP02R>A11NPOP03R) A11NPOP03R=A11NPOP02R;
    if(A11NPOP03R>A11NPOP04R) A11NPOP04R=A11NPOP03R;
    if(A11NPOP04R>A11NPOP05R) A11NPOP05R=A11NPOP04R;
    if(A11NPOP05R>A11NPOP06R) A11NPOP06R=A11NPOP05R;
    if(A11NPOP06R>A11NPOP07R) A11NPOP07R=A11NPOP06R;
    if(A11NPOP07R>A11NPOP08R) A11NPOP08R=A11NPOP07R;
    if(A11NPOP08R>A11NPOP09R) A11NPOP09R=A11NPOP08R;
    if(A11NPOP09R>A11NPOP10R) A11NPOP10R=A11NPOP09R;
    // ��� �������� � �⬮����
    if(A11SPAP04R>A11SPAP05R) A11SPAP04R=A11SPAP05R;
    if(A11SPAP03R>A11SPAP04R) A11SPAP03R=A11SPAP04R;
    if(A11SPAP02R>A11SPAP03R) A11SPAP02R=A11SPAP03R;
    if(A11SPAP01R>A11SPAP02R) A11SPAP01R=A11SPAP02R;
    // ��� �������� � �������
    if(A11SPKP04R>A11SPKP05R) A11SPKP04R=A11SPKP05R;
    if(A11SPKP03R>A11SPKP04R) A11SPKP03R=A11SPKP04R;
    if(A11SPKP02R>A11SPKP03R) A11SPKP02R=A11SPKP03R;
    if(A11SPKP01R>A11SPKP02R) A11SPKP01R=A11SPKP02R;

    //----------------------------------------------
    // ����� ��९�᪭� ��஬ �� � 
    if(A21NTPP01R>A21NTPP02R) A21NTPP02R=A21NTPP01R;
    if(A21NTPP02R>A21NTPP03R) A21NTPP03R=A21NTPP02R;
    if(A21NTPP03R>A21NTPP04R) A21NTPP04R=A21NTPP03R;
    if(A21NTPP04R>A21NTPP05R) A21NTPP05R=A21NTPP04R;
    // ����� �����  ��஬ �� �
    if(A21NTOP01R>A21NTOP02R) A21NTOP02R=A21NTOP01R;
    if(A21NTOP02R>A21NTOP03R) A21NTOP03R=A21NTOP02R;
    if(A21NTOP03R>A21NTOP04R) A21NTOP04R=A21NTOP03R;
    if(A21NTOP04R>A21NTOP05R) A21NTOP05R=A21NTOP04R;
    // ����� ��९�᪭� ��஬ �� P
    if(A21NPPP01R>A21NPPP02R) A21NPPP02R=A21NPPP01R;
    if(A21NPPP02R>A21NPPP03R) A21NPPP03R=A21NPPP02R;
    if(A21NPPP03R>A21NPPP04R) A21NPPP04R=A21NPPP03R;
    if(A21NPPP04R>A21NPPP05R) A21NPPP05R=A21NPPP04R;
    if(A21NPPP05R>A21NPPP06R) A21NPPP06R=A21NPPP05R;
    if(A21NPPP06R>A21NPPP07R) A21NPPP07R=A21NPPP06R;
    if(A21NPPP07R>A21NPPP08R) A21NPPP08R=A21NPPP07R;
    if(A21NPPP08R>A21NPPP09R) A21NPPP09R=A21NPPP08R;
    if(A21NPPP09R>A21NPPP10R) A21NPPP10R=A21NPPP09R;
    // ����� �����  ��஬ �� P
    if(A21NPOP01R>A21NPOP02R) A21NPOP02R=A21NPOP01R;
    if(A21NPOP02R>A21NPOP03R) A21NPOP03R=A21NPOP02R;
    if(A21NPOP03R>A21NPOP04R) A21NPOP04R=A21NPOP03R;
    if(A21NPOP04R>A21NPOP05R) A21NPOP05R=A21NPOP04R;
    if(A21NPOP05R>A21NPOP06R) A21NPOP06R=A21NPOP05R;
    if(A21NPOP06R>A21NPOP07R) A21NPOP07R=A21NPOP06R;
    if(A21NPOP07R>A21NPOP08R) A21NPOP08R=A21NPOP07R;
    if(A21NPOP08R>A21NPOP09R) A21NPOP09R=A21NPOP08R;
    if(A21NPOP09R>A21NPOP10R) A21NPOP10R=A21NPOP09R;
    // ��� �������� � �⬮����
    if(A21SPAP04R>A21SPAP05R) A21SPAP04R=A21SPAP05R;
    if(A21SPAP03R>A21SPAP04R) A21SPAP03R=A21SPAP04R;
    if(A21SPAP02R>A21SPAP03R) A21SPAP02R=A21SPAP03R;
    if(A21SPAP01R>A21SPAP02R) A21SPAP01R=A21SPAP02R;
    // ��� �������� � �������
    if(A21SPKP04R>A21SPKP05R) A21SPKP04R=A21SPKP05R;
    if(A21SPKP03R>A21SPKP04R) A21SPKP03R=A21SPKP04R;
    if(A21SPKP02R>A21SPKP03R) A21SPKP02R=A21SPKP03R;
    if(A21SPKP01R>A21SPKP02R) A21SPKP01R=A21SPKP02R;
    //----------------------------------------------

    return;
}
//----------------------------------------------------------------------------
