// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 ���⭮�� 諠�� 2 (207)

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR14;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN14=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH14=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM14=2;               // ���-�� ᥪ㭤 ��� � ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp14PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR14= IOPNT;
    DONCH14= hM;
    DONTM14= hS;
    STEP14 = Step; 
    STEP14_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_14(vd){
    if (REG14R___V==ON){
    DON2071__M=OFF;
    DON2072__M=OFF;
    DON207N__M=OFF;
    DON056A__M=OFF; 
    DON057A__M=OFF;
}   }   
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_14off(vd){
    DON2071__V=OFF; DON2071__M=OFF;
    DON2072__V=OFF; DON2072__M=OFF;
    DON207N__V=OFF; DON207N__M=OFF;
    DON056A__V=OFF; DON056A__M=OFF;
    DON057A__V=OFF; DON057A__M=OFF;
    return;
}
//---------------------------------------------------------------------------
vd  far Clear_T33ll(vd){
    Clear_TO(33);   Clear_TO(34);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� � �몫�祭�� ॣ����
vd  far Regul_14m(vd){
    //-----------------------------------------------------------------------
    if ( STEP14 == 101 ){
         Clear_T33ll();
         REG14SW__V = 1001;
         if(STEP14P>=3 and STEP14P<=6 ){ STEP14=5; STEP14_BACK=101; return; }
         if(STEP14P!=  101){ Regul_14off(); }
         STEP14P=101;
         STEP14 =102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP14 == 102 ){
         Clear_T33ll();
         if(STEP14P!= 102){ Regul_14off(); }
         STEP14P    = 102;;
         REG14SW__V = 1002;
         REG14R___M = OFF;;
         STEP14_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP14=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_14(vd){
    // ����祭��-�몫�祭�� ॣ����
    if ( REG14RS__M == SWITCH ){ 
         REG14R___M = (REG14R___M==ON) then_ OFF else_ ON; REG14RS__M=OFF;
    }
    if ( REG14R___M != REG14R___V ){ 
         REG14R___M  =(REG14R___M==ON) then_ ON else_ OFF;
         REG14R___V  = REG14R___M;
         if ( REG14R___V == ON ){ Message(342,NOKV); STEP14 =   0; }
         else                   { Message(343,NOKV); STEP14 = 101; }
    }

    //-----------------------------------------------------------------------
    if ( STEP14 ==0 ){
         if(STEP14P!=0){
         }; STEP14P =0;
         if(RegRUN==OFF){ return; }
         Regul_14off();
         // �᫨ ���� � ०��� ������� - ���
         REG14SW__V = 1;
         if (DIR207___V == 1){ return; }
         // �᫨ ���� ᨣ��� ������� �஢�� � ��蠫�� ��室�� - ���
         // (��蠫�� ������, ����� �� ����)
         REG14SW__V = 2;
         if (OBJS56___V > 0 and AIL056A__V > AIL056AL_W){ return; }
         if (OBJS57___V > 0 and AIL057A__V > AIL056AL_W){ return; }
         // �᫨ ��� ᨣ���� ������� �஢�� � �� ��室�� - ���
         // (���ᥩ� ���⮩ ����� ��祣�)
         REG14SW__V = 3;
         if (AIL006A__V < AIL006AL_W){ return; }
         // �᫨ ��蠫�� �� ����祭� - ���
         REG14SW__V = 5;
         if (DIS206N__V == OFF){ return; }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG14SW__V = 6;
         if (REG14R___V==AUTO  and 
            (DIS2071__V==ON or DIS207N__V==ON)){
             switch ( Check_TO (33,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(263,NOKV); Bell(1,1); Clear_TO(33); return;; }
             }
         };
         //  �᫨ ������⢮ ����஢�� ��室�� ����� ���������- ���
         REG14SW__V = 7;
//       if (COUN_OTDZC<COUN_OTDZW){ return; }
         Clear_TO(33);
         Clear_TO(34);
         STEP14=1;
         return;
    }
    //-----------------------------------------------------------------------
    // ����� ��㪮���� ᨣ���� ��। ����祭��� ॣ���� (����)
    if ( STEP14 ==1 ){
         if(STEP14P!=1){
            Regul_14off();
         }; STEP14P =1;
         if (RegRUN==OFF){ return; }
         REG14SW__V=11;
         DON290N__M=1;
         if(Check_TO(33,8*SEC,ZERO,'=',ON, 1)==RUN) return;
         DON290N__M=0; // ������
         DON214N__V=1; // ��� �� 諠��
         // ������ ������ � ��蠫�� (�㭪��) ���� 諠��
         if(OBJS56___V>0){ DON056A__V=1; DON057A__V=0; }
         if(OBJS57___V>0){ DON056A__V=0; DON057A__V=1; }
         Clear_TO(33);
         STEP14 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    // ����祭�� ����
    if ( STEP14 ==2 ){
         if(STEP14P!=2){
            Regul_14off();
         }; STEP14P =2;
         // ���⢥न�� ����⨥ ������� � ��蠫�� (�㭪��) ���� 諠��
         if(OBJS56___V>0){ DON056A__V=1; DON057A__V=0; }
         if(OBJS57___V>0){ DON056A__V=0; DON057A__V=1; }
         if(RegRUN==OFF){ return; }
         REG14SW__V=22;
         // �᫨ ��� �㦭�� �஢��� ��� ��砫� �����窨- ��३� �� ���0
         if(AIL006A__V < AIL006AL_W){ STEP14=0; return; }
         REG14SW__V=23;
         if(AIL056A__V > AIL056AH_W){ STEP14=0; return; }
         REG14SW__V=24;
         if(OBJS56___V > 0 and DIS056G__V > 0){ STEP14=0; return; }
         REG14SW__V=25;
         if(OBJS57___V > 0 and DIS057G__V > 0){ STEP14=0; return; }
         // �᫨ ������� � �㭪�� ���� 諠�� ������� - ���
         REG14SW__V=26;
         if(OBJS56___V > 0 and DIS056A__V < 1){ return; }
         REG14SW__V=27;
         if(OBJS57___V > 0 and DIS057A__V < 1){ return; }
         // ������� ����
         DON207N__V=ON;
         REG14SW__V=28;
         switch ( Check_TO  (33, TIME_ISPKV*SEC, DIS207N__V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { Isp14PD(&DON207N__V,3,TIME_ISPPW,70,STEP14P, 33); return;; }
         }
         switch ( Check_TO  (34, 5*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(33);
         Clear_TO(34);
         STEP14 = 3; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� 諠�� � ����
    if ( STEP14 ==3 ){
         if(STEP14P!=3){
         }; STEP14P =3;
         if (RegRUN==OFF){ return; }
         // ����        ������ �
         DON207N__V=ON;  DON2071__V=ON;
         REG14SW__V=31;
         switch ( Check_TO  (33, 5*SEC, DIS2071__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN14>1){ DONCN14=0; Clear_TO(33); return;; }
                         Isp14PD(&DON2071__V,3,TIME_ISPPW,70,STEP14P,33); return;;
                       }
         }
         switch ( Check_TO  (34, 5*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(33);
         Clear_TO(34);
         DON207P__V=1;
         STEP14 = 4;
         return;
    }
    //-----------------------------------------------------------------------
    // ����� ���孨� �஢��� � �� ��� 諠��
    if ( STEP14 ==4 ){
         if(STEP14P!=4){
            ;;
         }; STEP14P =4;
         if (RegRUN==OFF){ return; }
         REG14SW__V =41;
         // ����        ������ �       ᪮����2       ����           
         DON207N__V=ON;  DON2071__V=ON;  DON207P__V=ON;  DON2072__V=OFF;
         // �஢�ઠ �஢���, ��⠭����� ������ �᫨:
         // ��� ������� �஢�� � �� ��� 諠�� (��� �� �����)
         if(AIL006A__V < AIL006AL_W){ STEP14=5; }
         // ���� ���孨� �஢��� � ��蠫�� ��� 諠��
         if(AIL056A__V > AIL056AH_W){ STEP14=5; }
         // �᫨ �ࠡ�⠫ ���਩�� �஢��� � ��蠫�� ��� 諠��
         if(OBJS56___V > 0 and DIS056G__V > 0){ STEP14=5; }
         if(OBJS57___V > 0 and DIS057G__V > 0){ STEP14=5; }
         return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� 諠�� � ����, �몫���� ᪮����2
    if ( STEP14 ==5 ){
         if(STEP14P!=5){
            ;;
         }; STEP14P =5;
         if (RegRUN==OFF){ return; }
         REG14SW__V=51;
         // ����        ������ �        ᪮����2        ����
         DON207N__V=ON;  DON2071__V=OFF;  DON207P__V=OFF;  DON2072__V=OFF;
         // 
         switch ( Check_TO  (33, 5*SEC, DIS2071__V,'=',OFF, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN14>1){ DONCN14=0; Clear_TO(33); return;; }
                         Isp14PD(&DON2071__V,3,TIME_ISPPW,70,STEP14P,33); return;;
                       }
         }
         Clear_TO(33);
         STEP14 = 6; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������ ������ ����� ���� � ���� ��� �஬뢪�
    if ( STEP14 ==6 ){
         if(STEP14P!=6){
            ;;
         }; STEP14P =6;
         if (RegRUN==OFF){ return; }
         REG14SW__V=61;
         // ����        ������ �        ᪮����2        ����
         DON207N__V=ON;  DON2071__V=OFF;  DON207P__V=OFF;  DON2072__V=ON;
         switch ( Check_TO  (33, 5*SEC, DIS2072__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN14>1){ DONCN14=0; Clear_TO(33); return;; }
                         Isp14PD(&DON2072__V,3,TIME_ISPPW,70,STEP14P,33); return;;
                       }
         }
         Clear_TO(33);
         STEP14 = 7; 
         return;
    }
    //-----------------------------------------------------------------------
    // ����� �������� �६� �஬뢪�
    if ( STEP14 ==7 ){
         if(STEP14P!=7){
            DON2072TMC=0;
         }; STEP14P =7;
         if (RegRUN==OFF){ return; }
         DON2072TMC++;
         REG14SW__V=71;
         // ����        ������ �        ᪮����2        ����
         DON207N__V=ON;  DON2071__V=OFF;  DON207P__V=OFF;  DON2072__V=ON;
         switch ( Check_TO  (33, DON2072TMW*SEC, ZERO,'=', ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(33);
         STEP14 = 8; 
         return;
    }
    //-----------------------------------------------------------------------
    // ������� ������ ����� ���� � ����, �몫���� ����
    if ( STEP14 ==8 ){
         if(STEP14P!=8){
            ;;
         }; STEP14P =8;
         if (RegRUN==OFF){ return; }
         REG14SW__V=81;
         // ������ �     ᪮����2        ����
         DON2071__V=OFF;  DON207P__V=OFF;  DON2072__V=OFF;
         switch ( Check_TO  (33, 5*SEC, DIS2072__V,'=',ON, 1 )){
             case RUN: { return; }
             case BAD: { 
                         if(DONCN14>1){ DONCN14=0; Clear_TO(33); return;; }
                         Isp14PD(&DON2072__V,3,TIME_ISPPW,70,STEP14P,33); return;;
                       }
         }
         DON207N__V=OFF; // ����
         Clear_TO(33);
         STEP14 = 9;
         return;
    }
    //-----------------------------------------------------------------------
    // 
    if ( STEP14 ==9 ){
         if(STEP14P!=9){
            ;;
         }; STEP14P =9;
         if (RegRUN==OFF){ return; }
         REG14SW__V=91;
         // ������� ������� � �㭪�� ��� 諠��
         DON056A__V=0; DON057A__V=0;
         STEP14 = 0;
         if(STEP14_BACK==101) STEP14=101;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP14 ==70 ){
         if(STEP14P!=70){
            ;;
         }; STEP14P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN14>=DONCH14){ STEP14 = STEP14_PRBK; return; }
         REG14SW__V =700;
         if(Check_TO(214, DONTM14*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(214);
        *DONPR14=(*DONPR14!=ON)?ON:OFF;
         DONCN14++;
         STEP14 = STEP14_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_14m();
    return;
}
//---------------------------------------------------------------------------
