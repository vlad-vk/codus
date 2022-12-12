//---------------------------------------------------------------------------
// ��������� �� �3

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
vd  far Regul_13(vd){
    //-----------------------------------------------------------------------
    ui  RN=3;                         // ����� ॣ����
    _f  IL=0;                         // �室��� 誠�� (������ �࠭��)
    _f  IH=100;                       // �室��� 誠�� (������ �࠭��)
    _f  OL=0.000;                     // ��室��� 誠�� (������),%, �.��.
    _f  OH=100.0;                     // ��室��� 誠�� (������),%, �.��.
    _f  DM=20.00;                     // ���� ���� ��� ॣ����
    _f  ZN=100*0.001;                 // ���� �����⢨⥫쭮��
    _f  PR=20.00;                     // ��業� ��ᮣ��ᮢ����
    _f  CC=20;                        // ����஫�� 横�
    ui  TP=1;                         // ��� ॣ����
    //-----------------------------------------------------------------------
    // �஢�ઠ ����������
    if ( REG13RS__M == SWITCH ){
         AOT030__RM = (AOT030__RM==ON) then_ OFF else_ ON; REG13RS__M=OFF;
    }
    if (AOT030__RM!=AOT030__RV){
        AOT030__RV =AOT030__RM;
        if(AOT030__RV>0){ Message(440); }
        else            { Message(441); AOT030__OM=AOT030__OV=WO_Skip[RN];  }
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOT030__ZM <  IL         ){ AOT030__ZM = IL; }
    if (AOT030__ZM >  AIT030_AMV ){ AOT030__ZM = AIT030_AMV; }
        AOT030__ZV =  AOT030__ZM;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOT030__OM < 0  ){ AOT030__OM =0;   }
    if (AOT030__OM > 100){ AOT030__OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOT030_LOV =AOT030_LOM;
    AOT030_HOV =AOT030_HOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOT030_LPV =AOT030_LPM;
    AOT030_HPV =AOT030_HPM;
    // �����樥��� ॣ����
    AOT030__PV =AOT030__PM;
    AOT030__IV =AOT030__IM;
    AOT030__DV =AOT030__DM;
    AOT030__MV =AOT030__MM;
    //-----------------------------------------------------------------------
    if (RegRUN==ON){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOT030__OV=Regulator(RN, AIT030___V,
                                AOT030__PV, AOT030__IV, AOT030__DV, AOT030__MV,
                                AOT030__OM, AOT030__RV,
                                AOT030__ZV, AOT030__ZV,
                                IL, IH, OL, OH,
                                DM, ZN, PR, CC, TP
       );
       //--------------------------------------------------------------------
       // ��࠭�祭�� ��室�, %
       if (AOT030__OV <  OL+AOT030_LOV){ AOT030__OV=OL+AOT030_LOV; }
       if (AOT030__OV >  OH-AOT030_HOV){ AOT030__OV=OH-AOT030_HOV; }
       if (AOT030__MV >= 0){ AOT030_OOV=100-AOT030__OV; }
       else                { AOT030_OOV=AOT030__OV; }
       //--------------------------------------------------------------------
       // ������ ॣ����
       AOT030__UV=RegulDigit(RN, AOT030_LPV, AOT030_HPV, AOT030__MV,
                                 AOT030__RV, AOT030__UM);
       //--------------------------------------------------------------------
       if(AOT030__MV< 0){
          if((AOT030__ZV-AIT030___V)*AOT030__PV>0){
              if(AOT030__UV==RPLUS){
                 AOT030__UV=RMINUS;
              } else {
                 if(AOT030__UV==RMINUS){ AOT030__UV=RPLUS; }
              }
          }
       }
       //--------------------------------------------------------------------
       // ��⠭����� ��室 �� ������� � ����ᨬ��� �� ��室� ॣ����
       if(AOT030__UV==RPLUS ){ DON033O__V=1; DON033C__V=0; }
       if(AOT030__UV==RMINUS){ DON033O__V=0; DON033C__V=1; }
       if(AOT030__UV==RSTOP ){ DON033O__V=0; DON033C__V=0; }
       // ����� ��筮� ��室 � ����।������� ���ﭨ�
       AOT030__UM= RNA;
       // ��ᮣ��ᮢ���� ��室� ॣ����
       AOT030__XV= OutX[RN];
       // ��㣨� ��ࠬ����� ����⭮�� ॣ���� ��� �⫠���
       AOT030_CPV= ImpPC[RN];
       AOT030_CWV= ImpWC[RN];
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------