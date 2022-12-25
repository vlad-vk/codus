// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 ����

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

vd  far Regul_08m(vd);

_f far *DONPR02;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN02=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH02=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM02=2;               // ���-�� ᥪ㭤 ��� � ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp02PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR02= IOPNT;
    DONCH02= hM;
    DONTM02= hS;
    STEP02 = Step; 
    STEP02_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_02(vd){
    if(REG02R___V==ON){
    DON091A__M =  OFF;
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_02off(vd){
    DON091A__V =  OFF;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_02m(vd){
    //-----------------------------------------------------------------------
    if ( STEP02 == 101 ){
         REG02SW__V = 1001;
         if(RegRUN==OFF){ return; }
         Regul_02off();
         switch ( Check_TO  (21, TIME_ISNSV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         };  Clear_TO (21);
         Regul_02off();
        if(STEP08<101){ STEP08=101; Regul_08m(); }
         //
         STEP02 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 == 102 ){
         STEP02P = 102;
         REG02SW__V = 1002;
         REG02R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP02=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_02(vd){
    // ⥬������ �몫�祭�� ����� �������� � ᡮ୨� ����
    if (TEMP_VODBM <  0){ TEMP_VODBM = 45; }
    if (TEMP_VODBM != TEMP_VODBV){ TEMP_VODBV = TEMP_VODBM; }     // 45 C
    // �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_VDPKW <  0){ TIME_VDPKW = 5;  }                      // 5 SEC
    //  ����஫� ������� �஢�� ���୨�� ����
    if (CTRL_LLSVM <  0){ CTRL_LLSVV = ON; CTRL_LLSVM = OFF; }    // ON
    if (CTRL_LLSVM == SWITCH){ 
        CTRL_LLSVV = (CTRL_LLSVV!=ON) then_ ON else_ OFF; CTRL_LLSVM=OFF;
    }
    //  ����஫� ���孥�� �஢�� ���୨�� ����
    if (CTRL_HLSVM <  0){ CTRL_HLSVV = ON; CTRL_HLSVM = OFF; }    // ON
    if (CTRL_HLSVM == SWITCH){ 
        CTRL_HLSVV = (CTRL_HLSVV!=ON) then_ ON else_ OFF; CTRL_HLSVM=OFF;
    }
    //  ����஫� ������� �஢�� ���୨�� ��� ����
    if (CTRL_LLSKM <  0){ CTRL_LLSKV = ON; CTRL_LLSKM = OFF; }    // ON
    if (CTRL_LLSKM == SWITCH){ 
        CTRL_LLSKV = (CTRL_LLSKV!=ON) then_ ON else_ OFF; CTRL_LLSKM=OFF;
    }
    if (DIS092A__V==OFF and DIS092K__V==OFF){
    if (OBJ092A__M>0){ OBJ092A__V=1; OBJ092A__M=0; OBJ092K__V=0; OBJ092K__M=0; }
    if (OBJ092K__M>0){ OBJ092K__V=1; OBJ092K__M=0; OBJ092A__V=0; OBJ092A__M=0; }
    }
    if (OBJ092A__V==0 and OBJ092K__V==0){ OBJ092A__V=1; OBJ092A__M=0; OBJ092K__V=0; OBJ092K__M=0; }

    // ����祭��-�몫�祭�� ॣ����
    if ( REG02RS__M == SWITCH ){ 
         REG02R___M = (REG02R___M==ON) then_ OFF else_ ON; REG02RS__M=OFF;
    }
    if ( REG02R___M != REG02R___V ){ 
         REG02R___M  =(REG02R___M==ON) then_ ON else_ OFF;
         REG02R___V  = REG02R___M;
         if ( REG02R___V == ON ){ Message(330,NOKV); STEP02=  0; STEP08=  0; }   // ��⮬��
         else                   { Message(331,NOKV); STEP02=101; STEP08=101; }   // ��筮�
    }
    // �᫨ ���� ������ ���ண� � ०��� "�"������ ��� 
    // ����祭 ��筮� ०�� ॣ���� - ���
    if ( DIR219___V == 1 or REG02R___V == OFF ){ Regul_02m(); return; }


    //-----------------------------------------------------------------------
    if ( STEP02 ==0 ){
         if(STEP02P!=0){
            Clear_TO(21);
            Clear_TO(22);
         }; STEP02P =0;
         if (RegRUN==OFF){ return; }
         Regul_02off();

         // �᫨ ��� ������� �஢��- ������ ᫥������ �஢���
         REG02SW__V = 2;
         switch ( Check_TO  (21, 5*MIN, DIS091L__V,'=',OFF, TIME_LSTBV )){
             case RUN: { return; }
             case BAD: { Clear_TO(21); return; }
         }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG02SW__V = 4;
         if(DIR219___V==1 and DIS091A__V==ON){
            switch ( Check_TO (22,1*MIN, ZERO,'=',ON, 2)){
                case RUN: { return; }
                case BAD: { Clear_TO(22); return; }
            }
         }

         Clear_TO(21);
         Clear_TO(22);
         STEP02 = 1;
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� ����
    if ( STEP02 ==1 ){
         if(STEP02P!=1){
            Clear_TO(21);
         }; STEP02P =1;
         DON091A__V=ON;
         if (RegRUN==OFF){ return; }

         REG02SW__V = 10;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS091A__V,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { 
                         Isp02PD(&DON091A__V,3,TIME_ISPPW,70,STEP02, 21); 
                         Clear_TO(21); return;
                       }
         } 

         Clear_TO(21);
         STEP02=2; 
         return;
    }
    //-----------------------------------------------------------------------
    // �������� ����� ���孥�� �஢�� ���� 宫 ����
    if( STEP02 == 2){
      if(STEP02P!=2){
         Clear_TO(21);
      }; STEP02P =2;
         DON091A__V=ON;
      if(RegRUN==OFF){ return; }

      REG02SW__V =20;
      // �᫨ �ࠡ�⠫ ���਩�� �஢���- �몫���� ॣ����
      if (DIS091H__V==ON){ Regul_02m(); return; }

      // �᫨ �ࠡ�⠫ �।���(���孨�) �஢���- ��३� �� ᫥���騩 蠣
      switch ( Check_TO (21,TIME_LSTBV*2*SEC, DIS091M__V,'=',ON,2)){
          case RUN: { return;; }
          case BAD: { Clear_TO(21); return; }
      }   
      Clear_TO(21);

      STEP02=3;
      return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� ����
    if ( STEP02 ==3 ){
         if(STEP02P!=3){
            Clear_TO(21);
         }; STEP02P =3;

         DON091A__V=OFF;
         if (RegRUN==OFF){ return; }

         REG02SW__V=30;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS091A__V,'=',OFF, 1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(21); return; }
         }

         Clear_TO(21);
         STEP02=4;
         return;
    }
    //-----------------------------------------------------------------------
    // �������� ������� �஢�� � ���� ����
    if ( STEP02 ==4 ){
         if(STEP02P!=4){
            Clear_TO(21);
         }; STEP02P =4;

         DON091A__V=OFF;
         if(RegRUN==OFF){ return; }

         REG02SW__V=40;
         switch ( Check_TO (21,TIME_LSTBV*2*SEC, DIS091L__V,'=',OFF,2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(21); return; }
         }   

         Clear_TO(21);
         STEP02=0; 
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP02 ==70 ){
         if(STEP02P!=70){
            ;;
         }; STEP02P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN02>=DONCH02){ STEP02 = STEP02_PRBK; return; }
         REG02SW__V =700;
         if(Check_TO(202, DONTM02*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(202);
        *DONPR02=(*DONPR02!=ON)?ON:OFF;
         DONCN02++;
         STEP02 = STEP02_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_02m();
    return;
}
//---------------------------------------------------------------------------
