// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 ��������

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

vd  far Regul_02m(vd);

_f far *DONPR08;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN08=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH08=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM08=2;               // ���-�� ᥪ㭤 ��� � ����
_f far  DIS092x=0;               // ��� ������� ����� � �㭪�� ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp08PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR08= IOPNT;
    DONCH08= hM;
    DONTM08= hS;
    STEP08 = Step; 
    STEP08_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_08(vd){
    if(REG08R___V==ON){
    DON092A__M =  OFF;
    DON092K__M =  OFF;
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_08off(vd){
    DON092A__V =  OFF;
    DON092K__V =  OFF;
}
//---------------------------------------------------------------------------
vd  far Set_092(_i far VAL){
    DON092A__V=VAL; DON092K__V=0; 
    if(OBJ092K__V==ON){ DON092K__V=VAL; DON092A__V=0; }
}
//---------------------------------------------------------------------------
vd  far Get_092(vd){
    if(OBJ092K__V==ON) DIS092x=DIS092K__V; 
    if(OBJ092A__V==ON) DIS092x=DIS092A__V;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_08m(vd){
    //-----------------------------------------------------------------------
    if ( STEP08 == 101 ){
         REG08SW__V = 1001;
         if(RegRUN==OFF){ return; }
         Regul_08off();
         switch ( Check_TO  (81, TIME_ISNSV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         };  Clear_TO (81);
         Regul_08off();
         if(STEP02<101){ STEP02=101; Regul_02m(); }
         STEP08=102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP08 == 102 ){
         STEP08P = 102;
         REG08SW__V = 1002;
         REG08R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP08=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_08(vd){

    REG08R___V=REG02R___V;
    Get_092();

    // �᫨ ���� ������ ���ண� � ०��� "�"������ ��� 
    // ����祭 ��筮� ०�� ॣ���� - ���
    if ( DIR219___V == 1 or REG08R___V == OFF ){ Regul_08m(); return; }

    //-----------------------------------------------------------------------
    if ( STEP08 ==0 ){
         if(STEP08P!=0){
            Clear_TO(81);
            Clear_TO(82);
         }; STEP08P =0;
         if (RegRUN==OFF){ return; }
         Regul_08off();

         // �᫨ ��� ������� �஢��- ������ ᫥������ �஢���
         REG08SW__V = 2;
         switch ( Check_TO  (81, 5*MIN, DIS092L__V,'=',OFF, TIME_LSTBV )){
             case RUN: { return; }
             case BAD: { Clear_TO(81); return; }
         }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG08SW__V = 4;
         if(DIR219___V==1 and (DIS092A__V==ON or  DIS092K__V==ON)){
            switch ( Check_TO (82,1*MIN, ZERO,'=',ON, 2)){
                case RUN: { return; }
                case BAD: { Clear_TO(82); return; }
            }
         }

         Clear_TO(81);
         Clear_TO(82);
         STEP08 = 1;
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� ���� (��������)
    if ( STEP08 ==1 ){
         if(STEP08P!=1){
            Clear_TO(81);
         }; STEP08P =1;
         if (RegRUN==OFF){ return; }

         REG08SW__V = 10;
         Set_092(ON);
         switch ( Check_TO  (81, TIME_ISPKV*SEC, DIS092x,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN08>2){ REG08R___M=OFF; return; }
                         if(OBJ092A__V>0) Isp08PD(&DON092A__V,3,TIME_ISPPW,70,STEP08,81);
                         if(OBJ092K__V>0) Isp08PD(&DON092K__V,3,TIME_ISPPW,70,STEP08,81);
                         Clear_TO(81); return;
                       }
             case END: { DONCN08=0; break;; }
         } 

         Clear_TO(81);
         STEP08=2; 
         return;
    }
    //-----------------------------------------------------------------------
    // �������� ����� ���孥�� �஢�� ���� ��� ����
    if( STEP08 == 2){
      if(STEP08P!=2){
         Clear_TO(81);
      }; STEP08P =2;
      Set_092(ON);
      if(RegRUN==OFF){ return; }

      REG08SW__V =20;
      // �᫨ �ࠡ�⠫ ���਩�� �஢���- �몫���� ॣ����
      if (DIS092H__V==ON){ Regul_08m(); return; }

      // �᫨ �ࠡ�⠫ �।���(���孨�) �஢���- ��३� �� ᫥���騩 蠣
      switch ( Check_TO (81,TIME_LSTBV*2*SEC, DIS092M__V,'=',ON,2)){
          case RUN: { return;; }
          case BAD: { Clear_TO(81); return; }
      }   
      Clear_TO(81);

      STEP08=3;
      return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� ���� (��������)
    if ( STEP08 ==3 ){
         if(STEP08P!=3){
            Clear_TO(81);
         }; STEP08P =3;

         Set_092(OFF);
         if (RegRUN==OFF){ return; }

         REG08SW__V=30;
         switch ( Check_TO  (81, TIME_ISPKV*SEC, DIS092x,'=',OFF, 1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(81); return; }
         }

         Clear_TO(81);
         STEP08=4;
         return;
    }
    //-----------------------------------------------------------------------
    // �������� ������� �஢�� � ���� ����
    if ( STEP08 ==4 ){
         if(STEP08P!=4){
            Clear_TO(81);
         }; STEP08P =4;

         Regul_08off();
         if(RegRUN==OFF){ return; }

         REG08SW__V=40;
         switch ( Check_TO (81,TIME_LSTBV*2*SEC, DIS092L__V,'=',OFF,2)){
             case RUN: { return; }
             case BAD: { Clear_TO(81); return; }
         }   

         Clear_TO(81);
         STEP08=0; 
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP08 ==70 ){
         if(STEP08P!=70){
            ;;
         }; STEP08P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN08>=DONCH08){ STEP08 = STEP08_PRBK; return; }
         REG08SW__V =700;
         if(Check_TO(208, DONTM08*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(208);
        *DONPR08=(*DONPR08!=ON)?ON:OFF;
         DONCN08++;
         STEP08 = STEP08_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_08m();
    return;
}
//---------------------------------------------------------------------------
