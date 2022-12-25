// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 ���⭮�� 諠�� 1 (204)

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR03;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN03=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH03=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM03=2;               // ���-�� ᥪ㭤 ��� � ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp03PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR03= IOPNT;
    DONCH03= hM;
    DONTM03= hS;
    STEP03 = Step; 
    STEP03_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_03(vd){
    if (REG03R___V==ON){
    DON204A__M=OFF;
    DON204B__M=OFF;
    DON204D__M=OFF;
}   }   
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_03off(vd){
    DON204A__V=OFF; DON204A__M=OFF;
    DON204B__V=OFF; DON204B__M=OFF;
    DON204D__V=OFF; DON204D__M=OFF;
    return;
}
//---------------------------------------------------------------------------
vd  far Clear_T3all(vd){
    Clear_TO(31);   Clear_TO(32);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� � �몫�祭�� ॣ����
vd  far Regul_03m(vd){
    //-----------------------------------------------------------------------
    if ( STEP03 == 101 ){
         Clear_T3all();
         REG03SW__V = 1001;
         if(STEP03P>=3 and STEP03P<=6 ){ STEP03=5; STEP03_BACK=101; return; }
         if(STEP03P!=  101){ Regul_03off(); }
         STEP03P=101;
         STEP03 =102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP03 == 102 ){
         Clear_T3all();
         if(STEP03P!= 102){ Regul_03off(); }
         STEP03P    = 102;;
         REG03SW__V = 1002;
         REG03R___M = OFF;;
         STEP03_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP03=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_03(vd){
    // �६� �������� ����� ���孥�� �஢�� ��蠫�� ��室��
    if (TIME_HLVOW <  0){ TIME_HLVOW = 10; }                     // 10 MIN
    // �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_OTPKW <  0){ TIME_OTPKW = 5;  }                     // 5 SEC

    // ����祭��-�몫�祭�� ॣ����
    if ( REG03RS__M == SWITCH ){ 
         REG03R___M = (REG03R___M==ON) then_ OFF else_ ON; REG03RS__M=OFF;
    }
    if ( REG03R___M != REG03R___V ){ 
         REG03R___M  =(REG03R___M==ON) then_ ON else_ OFF;
         REG03R___V  = REG03R___M;
         if ( REG03R___V == ON ){ Message(340,NOKV); STEP03 =   0; }
         else                   { Message(341,NOKV); STEP03 = 101; }
    }

    //-----------------------------------------------------------------------
    if ( STEP03 ==0 ){
         if(STEP03P!=0){
         }; STEP03P =0;
         if(RegRUN==OFF){ return; }
         Regul_03off();
         // �᫨ ���� � ०��� ������� - ���
         REG03SW__V = 1;
         if (DIR204___V == 1){ return; }
         // �᫨ ��� ᨣ���� ������� �஢�� � ��蠫�� ��室�� - ���
         // (� ������ ������ ���� �� ����� �� ����)
         REG03SW__V = 2;
         if (AIL003A__V < AIL003AL_W){ return; }
         // �᫨ ���� ᨣ��� ������� �஢�� � �� ��室�� - ���
         // (� ���� ������ �஢��� ���� - ����� �� ����)
         REG03SW__V = 3;
         if (AIL006A__V > AIL006AL_W){ return; }
         // �᫨ ��蠫�� ��� �� ��室�� �� ����祭� - ���
         REG03SW__V = 5;
         if (DIS203N__V == OFF or DIS206N__V == OFF){ return; }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG03SW__V = 6;
         if (REG03R___V==AUTO  and 
            (DIS204A__V==ON or DIS204D__V==ON)){
             switch ( Check_TO (31,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(263,KVIT); Bell(1,1); Clear_TO(31); return;; }
             }
         };
         //  �᫨ ������⢮ ����஢�� ��室�� ����� ���������- ���
         REG03SW__V = 7;
//       if (COUN_OTDZC<COUN_OTDZW){ return; }
         Clear_TO(31);
         Clear_TO(32);
         STEP03=1;
         return;
    }
    //-----------------------------------------------------------------------
    // ����� ��㪮���� ᨣ���� ��। ����祭��� ॣ���� (����)
    if ( STEP03 ==1 ){
         if(STEP03P!=1){
            Regul_03off();
         }; STEP03P =1;
         if (RegRUN==OFF){ return; }
         REG03SW__V=11;
         DON290N__M=1;
         if(Check_TO(31,8*SEC,ZERO,'=',ON, 1)==RUN) return;
         DON290N__M=0; // ������
         DON203N__V=1; // ��� �� 諠��
         Clear_TO(31);
         STEP03 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    // ����祭�� ����
    if ( STEP03 ==2 ){
         if(STEP03P!=2){
            Regul_03off();
         }; STEP03P =2;
         if(RegRUN==OFF){ return; }
         // �᫨ ��� �㦭�� �஢��� ��� ��砫� �����窨- ��३� �� ���0
         if(AIL006A__V > AIL006AH_W){ STEP03=0; return; }
         if(AIL003A__V < AIL003AL_W){ STEP03=0; return; }
         // ������� ����
         DON204D__V=ON;
         REG03SW__V=21;
         switch ( Check_TO  (31, TIME_ISPKV*SEC, DIS204D__V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { Isp03PD(&DON204D__V,3,TIME_ISPPW,70,STEP03P, 31); return;; }
         }
         switch ( Check_TO  (32, 5*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(31);
         Clear_TO(32);
         STEP03 = 3; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� 諠�� � ����
    if ( STEP03 ==3 ){
         if(STEP03P!=3){
         }; STEP03P =3;
         if (RegRUN==OFF){ return; }
         // ����        ������ �
         DON204D__V=ON;  DON204A__V=ON;
         REG03SW__V=31;
         switch ( Check_TO  (31, 5*SEC, DON204A__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN03>1){ DONCN03=0; Clear_TO(31); return;; }
                         Isp03PD(&DON204A__V,3,TIME_ISPPW,70,STEP03P,31); return;;
                       }
         }
         switch ( Check_TO  (32, 5*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(31);
         Clear_TO(32);
         DON204V__V=1;
         STEP03 = 4;
         return;
    }
    //-----------------------------------------------------------------------
    // ����� ���孨� �஢��� � �� ��� 諠��
    if ( STEP03 ==4 ){
         if(STEP03P!=4){
            ;;
         }; STEP03P =4;
         if (RegRUN==OFF){ return; }
         REG03SW__V =41;
         // ����        ������ �       ᪮����2       ����           
         DON204D__V=ON;  DON204A__V=ON;  DON204V__V=ON;  DON204B__V=OFF;
         // ��⠭����� �������, �᫨:
         // � ���孥� ������ ���� ���孨� �஢��� (��� �㤠 �����)
         if(AIL006A__V>AIL006AH_W){ STEP03=5; }
         // � ������ ������ ��� ������� �஢�� (��祣� �����)
         if(AIL003A__V<AIL003AL_W){ STEP03=5; }
         return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� 諠�� � ����, �몫���� ᪮����2
    if ( STEP03 ==5 ){
         if(STEP03P!=5){
            ;;
         }; STEP03P =5;
         if (RegRUN==OFF){ return; }
         REG03SW__V=51;
         // ����        ������ �        ᪮����2        ����
         DON204D__V=ON;  DON204A__V=OFF;  DON204V__V=OFF;  DON204B__V=OFF;
         // 
         switch ( Check_TO  (31, 5*SEC, DIS204A__V,'=',OFF, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN03>1){ DONCN03=0; Clear_TO(31); return;; }
                         Isp03PD(&DON204A__V,3,TIME_ISPPW,70,STEP03P,31); return;;
                       }
         }
         Clear_TO(31);
         STEP03 = 6; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� ���� � ���� ��� �஬뢪�
    if ( STEP03 ==6 ){
         if(STEP03P!=6){
            ;;
         }; STEP03P =6;
         if (RegRUN==OFF){ return; }
         REG03SW__V=61;
         // ����        ������ �        ᪮����2        ����
         DON204D__V=ON;  DON204A__V=OFF;  DON204V__V=OFF;  DON204B__V=ON;
         switch ( Check_TO  (31, 5*SEC, DIS204B__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN03>1){ DONCN03=0; Clear_TO(31); return;; }
                         Isp03PD(&DON204B__V,3,TIME_ISPPW,70,STEP03P,31); return;;
                       }
         }
         Clear_TO(31);
         STEP03 = 7; 
         return;
    }
    //-----------------------------------------------------------------------
    // ����� �������� �६� �஬뢪�
    if ( STEP03 ==7 ){
         if(STEP03P!=7){
            DON204BTMC=0;
         }; STEP03P =7;
         if (RegRUN==OFF){ return; }
         DON204BTMC++;
         REG03SW__V=71;
         // ����        ������ �        ᪮����2        ����
         DON204D__V=ON;  DON204A__V=OFF;  DON204V__V=OFF;  DON204B__V=ON;
         switch ( Check_TO  (31, DON204BTMW*SEC, ZERO,'=', ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(31);
         STEP03 = 8; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� ���� � ����, �몫���� ����
    if ( STEP03 ==8 ){
         if(STEP03P!=8){
            ;;
         }; STEP03P =8;
         if (RegRUN==OFF){ return; }
         REG03SW__V=81;
         // ������ �     ᪮����2        ����
         DON204A__V=OFF;  DON204V__V=OFF;  DON204B__V=OFF;
         switch ( Check_TO  (31, 5*SEC, DIS204B__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN03>1){ DONCN03=0; Clear_TO(31); return;; }
                         Isp03PD(&DON204B__V,3,TIME_ISPPW,70,STEP03P,31); return;;
                       }
         }
         DON204D__V=OFF; // ����
         Clear_TO(31);
         STEP03 = 9;
         return;
    }
    //-----------------------------------------------------------------------
    // 
    if ( STEP03 ==9 ){
         if(STEP03P!=9){
            ;;
         }; STEP03P =9;
         if (RegRUN==OFF){ return; }
         REG03SW__V=91;

         STEP03 = 0;
         if(STEP03_BACK==101) STEP03=101;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP03 ==70 ){
         if(STEP03P!=70){
            ;;
         }; STEP03P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN03>=DONCH03){ STEP03 = STEP03_PRBK; return; }
         REG03SW__V =700;
         if(Check_TO(203, DONTM03*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(203);
        *DONPR03=(*DONPR03!=ON)?ON:OFF;
         DONCN03++;
         STEP03 = STEP03_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_03m();
    return;
}
//---------------------------------------------------------------------------
