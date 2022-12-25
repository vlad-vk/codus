//---------------------------------------------------------------------------
//  �����窠 諠��

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f  far *DONPR01;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i  far  DONCN01=0;               // ���稪 横�� ��।�ࣨ�����
_i  far  DONCH01=2;               // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i  far  DONTM01=2;               // ���-�� ᥪ㭤 ��� � ����
_f  far  AILSL1=0;                // �஢��� � ��蠫�� 諠��
_f  far  DISKM1=0;                // ��� ���� � ��蠫�� 諠��
_f  far  DISKN1=0;                // ��� ���� 諠�� �� ����
_f  far  DISNS1=0;                // ��� ���� ����� 諠�� � ��蠫��
_i  far  AILFL1=0;                // 䫠� �஢�� � ��蠫�� 諠��
_f  far  DISVD1=0;                // ��� ���� ���� �� ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp01PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR01= IOPNT;
    DONCH01= hM;
    DONTM01= hS;
    STEP01 = Step; 
    STEP01_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_01(vd){
    if(REG01R___V==ON){
    DON211NV_M=0;
    DON211KA_M=0;
    DON211KB_M=0;
    DON211KC_M=0;
    DON213V__M=0;
    DON213A__M=0;
    DON213B__M=0;
    DON213C__M=0;
    DON064B__M=0;
    DON065B__M=0;
    DON064A__M=0;
    DON065A__M=0;
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_01off(vd){
    DON211NV_V=0;
    DON211KA_V=0;
    DON211KB_V=0;
    DON211KC_V=0;
    DON213V__V=0;
    DON213A__V=0;
    DON213B__V=0;
    DON213C__V=0;
    DON064B__V=0;
    DON065B__V=0;
    DON064A__V=0;
    DON065A__V=0;
    return;
}
//---------------------------------------------------------------------------
//  �ࠢ����� �ᯮ���⥫ﬨ
vd  far Set_IS1(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, _f far i6, _f far i7, _f far i8){
    if (i1== ON) DON211NV_V= ON; else DON211NV_V=OFF;  // 211NV
    if (i2== ON) DON211KA_V= ON; else DON211KA_V=OFF;  // 211KA
    if (i3== ON) DON211KB_V= ON; else DON211KB_V=OFF;  // 211KB
    if (i4== ON) DON213V__V= ON; else DON213V__V=OFF;  // 213V
    if (i5== ON) DON213A__V= ON; else DON213A__V=OFF;  // 213A
    if (i6== ON) DON213B__V= ON; else DON213B__V=OFF;  // 213B
    if (i7== ON) DON064A__V= ON; else DON064A__V=OFF;  // 064A
    if (i8== ON) DON065B__V= ON; else DON065B__V=OFF;  // 064B
    return;
}
//---------------------------------------------------------------------------
vd  far Set_VR1(_f far KLNAS, _f far NASOS, _f far KLMES, _f far KLVOD, _f far SPEED){
    if(KLMES!=ASIS){
        // �᫨ ��࠭� ����㧪� � ��� 諠�� N2 (65)
        if(OBJS65___V>0){
            // ��।������ ������� ��蠫��, ���뢠� � ������ �� ����ࠥ�
            if(OBJSB1___V>0||OBJSB2___V>0) DON065A__V=KLMES; else DON065B__V=KLMES;
        } else {
        // �᫨ ��࠭� ����㧪� � ��� 諠�� N1 (64)
            // ��।������ ������� ��蠫��, ���뢠� � ������ �� ����ࠥ�
            if(OBJSB1___V>0||OBJSB2___V>0) DON064A__V=KLMES; else DON064B__V=KLMES;
    }   }
    // ��।������ ������� �� � ����, ���뢠� � ������ �� ����ࠥ�
    if(KLNAS !=ASIS){
        if(OBJSB1___V>0){ DON211KA_V=KLNAS; }
        if(OBJSB2___V>0){ DON211KB_V=KLNAS; }
        if(OBJSB3___V>0){ DON213A__V=KLNAS; }
        if(OBJSB4___V>0){ DON213B__V=KLNAS; }
    }
    if(NASOS !=ASIS){
        if(OBJSB1___V>0){ DON211NV_V=NASOS; }
        if(OBJSB2___V>0){ DON211NV_V=NASOS; }
        if(OBJSB3___V>0){ DON213V__V=NASOS; }
        if(OBJSB4___V>0){ DON213V__V=NASOS; }
    }
    if(SPEED !=ASIS){
        if(OBJSB1___V>0){ DON211W__V=SPEED; }
        if(OBJSB2___V>0){ DON211W__V=SPEED; }
        if(OBJSB3___V>0){ DON213W__V=SPEED; }
        if(OBJSB4___V>0){ DON213W__V=SPEED; }
    }
    if(KLVOD !=ASIS){
        if(OBJSB1___V>0||OBJSB2___V>0){ DON211KC_V=KLVOD; DON213C__V=OFF; }
        if(OBJSB3___V>0||OBJSB4___V>0){ DON213C__V=KLVOD; DON211KC_V=OFF; }
    }
    return;
}
//---------------------------------------------------------------------------
// ��।������ ���ﭨ� �ᯮ���⥫��� ��堭����� � �஢�� ��� ॣ����
// � ����ᨬ��� �� ��࠭���� �� � ���� ����㧪�: AILSL1-�஢��� 諠�� � ��蠫��,
// DISKN1-������ �� ����, DISNS1-���� 諠��, DISKM1-������ � ��蠫��, DISVD1-������ ���� � ����
vd  far Get_VR1(vd){
    // �᫨ ��࠭� ����㧪� � ��� 諠�� N2 (65)
    if(OBJS65___V>0){
        AILSL1=AIL065A__V;
        // ��।������ ������� ��蠫��, ���뢠� � ������ �� ����ࠥ�
        if(OBJSB1___V>0||OBJSB2___V>0) DISKM1=DIS065A__V; else DISKM1=DIS065B__V;
    } else {
    // �᫨ ��࠭� ����㧪� � ��� 諠�� N1 (64)
        AILSL1=AIL064A__V;
        // ��।������ ������� ��蠫��, ���뢠� � ������ �� ����ࠥ�
        if(OBJSB1___V>0||OBJSB2___V>0) DISKM1=DIS064A__V; else DISKM1=DIS064B__V;
    }
    // ��।������ ������� �� � ����, ���뢠� � ������ �� ����ࠥ�
    if(OBJSB1___V>0){ DISKN1=DIS211KA_V; DISNS1=DIS211NV_V; DISVD1=DIS211KC_V; }
    if(OBJSB2___V>0){ DISKN1=DIS211KB_V; DISNS1=DIS211NV_V; DISVD1=DIS211KC_V; }
    if(OBJSB3___V>0){ DISKN1=DIS213A__V; DISNS1=DIS213V__V; DISVD1=DIS213C__V; }
    if(OBJSB4___V>0){ DISKN1=DIS213B__V; DISNS1=DIS213V__V; DISVD1=DIS213C__V; }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_01m(vd){
    //-----------------------------------------------------------------------
    if ( STEP01 == 101 ){
         REG01SW__V = 1001;
         if(RegRUN==OFF){ return; }
         switch ( Check_TO  (12, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         Clear_TO(15);
         Clear_TO(16);
         Clear_TO(17);
         Clear_TO(18);
         Regul_01off();
         STEP01 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 == 102 ){
         STEP01P = 102;
         REG01SW__V = 1002;
         REG01R___M = OFF;
         AILFL1=0;
         STEP01_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP01=101;
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far Regul_01(vd){

    Get_VR1();

    //-----------------------------------------------------------------------
    //  ����祭��-�몫�祭�� ॣ����
    if ( REG01RS__M == SWITCH ){ 
         REG01R___M = (REG01R___M==ON) then_ OFF else_ ON; REG01RS__M=OFF;
    }
    if ( REG01R___M != REG01R___V ){ 
         REG01R___M  =(REG01R___M==ON) then_ ON else_ OFF;
         REG01R___V  = REG01R___M;
         if(REG01R___V>0){ Message(320,NOKV); STEP01 = 0; return; }
         else            { Message(321,NOKV); STEP01 = 3; STEP01_BACK = 101; return; }
    }
    //  �᫨ �� 諠�����ᥩ�� � ०��� ������� - ���
    if (DIR211___V ==  1 and DIR213___V == 1){
        REG01SW__V = 107;
        Regul_01m(); return; 
    }
    //  ����஫� �஢�� ��蠫�� 諠��
    if(AILSL1<=OBJS6xL__W&&AILFL1==2&&STEP01>2){ STEP01=0; }
    if(AILSL1>=OBJS6xH__W&&AILFL1==1&&STEP01<3){ STEP01=3; }
    //-----------------------------------------------------------------------


    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if ( STEP01 ==0 ){
         if(STEP01P!=0){
            ;;
         }; STEP01P =0;
            AILFL1  =0;
         if(REG01R___V==0){ return; } 
         Regul_01off();
         if(RegRUN==OFF){ return; }
         REG01SW__V =1;
         if(AILSL1>=OBJS6xH__W){ STEP01= 3; }
         else                  { STEP01=10; }
         return;
    }
    //-----------------------------------------------------------------------


    // ��������� ���������� ��������� �ᯮ���⥫�� ॣ����
    //-----------------------------------------------------------------------
    if ( STEP01 ==10 ){
         if(STEP01P!=10){
            ;;
         }; STEP01P =10;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         REG01SW__V = 6;
         if(DISKM1==ON||DISKN1==ON||DISNS1==ON){ return; }
         STEP01 = 1;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ����⨥ ������� � ��蠫��
    if ( STEP01 ==1 ){
         if(STEP01P!=1){
            Clear_TO(11);
            Clear_TO(12);
         }; STEP01P =1;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         Set_VR1(OFF,OFF,ON,OFF,0);
         REG01SW__V = 11;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISKM1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(12); return; }
         }
         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    // ����祭�� ���� � ����⨥ ������� ��᫥ ����
    if ( STEP01 ==2 ){
         if(STEP01P!=2){
            Clear_TO(11);
            Clear_TO(12);
         }; STEP01P =2;
         if(RegRUN==OFF){ return; }
         Regul_01off();
         Set_VR1(ASIS,ON,ON,OFF,0);
         REG01SW__V = 20;
         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISNS1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(11); return; }
         }
         Set_VR1(ON,ON,ON,OFF,0);
         REG01SW__V = 21;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISKN1,'=',ON,  1 )){
             case RUN: { return; }
             case BAD: { Clear_TO(12); return; }
         }
         REG01SW__V = 22;
         switch ( Check_TO  (13, TIME_ISPKV*SEC*4, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         Set_VR1(ON,ON,ON,OFF,1);
         Clear_TO(11);
         REG01SW__V = 23;
         AILFL1 = 1;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �몫�祭�� �ᯮ���⥫��
    if ( STEP01 ==3 ){
         if(STEP01P!=3){
            Clear_TO(11);
            Clear_TO(12);
            Clear_TO(13);
            REG01SW__V =30;
         }; STEP01P =3;
         if(RegRUN==OFF){ return; }
         // ������� ������ 諠�� �� ����
         REG01SW__V = 30;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISKN1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         // ��������� �����஥ �६� (8ᥪ)
         REG01SW__V = 31;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (12, TIME_ISPKV*SEC*2, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         // ������ ������ ���� � ����
         REG01SW__V = 32;
         Set_VR1(OFF,ON,ON,ON,0);
         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISVD1,'=',ON,  1 )){
             case RUN: { return; }
         }
         Set_VR1(OFF,ON,ON,ON,0);
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         STEP01=4;
         return;
    }
    //-----------------------------------------------------------------------
    // �몫�祭�� �ᯮ���⥫��
    if ( STEP01 ==4 ){
         if(STEP01P!=4){
            Clear_TO(11);
            Clear_TO(12);
            Clear_TO(13);
            Clear_TO(14);
            TMSL_VDP_C=0;
            REG01SW__V=40;
         }; STEP01P =4;
         if(RegRUN==OFF){ return; }
         // ����� �६� �������� (�६� �஬뢪�)
         REG01SW__V = 41;
         Set_VR1(OFF,ASIS,ASIS,ASIS,0);
         switch ( Check_TO  (11, TMSL_VDP_W*SEC, ZERO,'=',ON,  1 )){
             case RUN: { 
                         if(TMSL_VDP_C<TMSL_VDP_W) TMSL_VDP_C++; return;;
                       }
         }
         // ������� ������ ����� ���� �� ����
         REG01SW__V = 42;
         Set_VR1(OFF,ASIS,ASIS,OFF,0);
         // �몫���� ����
         REG01SW__V = 43;
         Set_VR1(OFF,OFF,ASIS,OFF,0);
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISNS1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         // ������� ������ � ��蠫�� 諠��
         REG01SW__V = 44;
         Set_VR1(OFF,OFF,OFF,OFF,0);
         switch ( Check_TO  (14, TIME_ISPKV*SEC, DISKM1,'=',OFF,  1 )){
             case RUN: { return; }
         }
         //
         REG01SW__V = 45;
         if(STEP01_BACK==101){ AILFL1=0; STEP01=101; }
         else                { AILFL1=2; }
         return;        
    }
    //-----------------------------------------------------------------------



    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP01 ==70 ){
         if(STEP01P!=70){
            ;;
         }; STEP01P =70;
         if(DONCN01>=DONCH01){ STEP01 = STEP01_PRBK; return; }
         REG01SW__V = 700;
         if(RegRUN==OFF){ return; }
         if(Check_TO(201, DONTM01*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(201);
        *DONPR01=(*DONPR01!=ON)?ON:OFF;
         DONCN01++;
         STEP01 = STEP01_PRBK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_01m();
    return;
}
//---------------------------------------------------------------------------
