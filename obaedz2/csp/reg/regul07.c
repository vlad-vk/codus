// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// ����஢�� ���ண�

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR07;
_i far  DONCN07=0;                // ���稪 横�� ��।�ࣨ�����             
_i far  DONCH07=2;                // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i far  DONTM07=2;                // ���-�� ᥪ㭤 ��� � ����

_i far  GERMDOWN=0;               // ���稪 �� ���᪠��� ��ଥ⨧���

_f far  CNTTEMP=0;                // �६���� ���稪
_f far  REG07ZO1_F=0;             // 䫠� �뢮�� �����

_f far  CYRSLMS=0;               // 蠣 ����祭�� ����樨 諠��
_f far  CYROTHS=0;               // 蠣 ����祭�� ����樨 ���⭮�� 諠��
_f far  DIS06xC=0;
_f far  DIS05xC=0;
_f far  DIS251x=0;

_f far  PO2511=0;                // ��業� ������ ������� ����� ��אַ�� 諠��
_f far  PO2512=0;                // ��業� ������ ������� ����� ���⭮�� 諠��

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp07PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR07= IOPNT;
    DONCH07= hM;
    DONTM07= hS;
    STEP07 = Step; 
    STEP07_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �᫨ ॣ���� ����祭 - �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_07(vd){
    if (REG07R___V==ON /*||REG07GL__V==ON*/ ){
    DON064C__M = OFF;
    DON065C__M = OFF;
    DON064E__M = OFF;
    DON065E__M = OFF;
    DON251E1_M = OFF;
    DON266E__M = OFF;
    DON251B1_M = OFF;
    DON251C1_M = OFF;
    DON251F1_M = OFF;
                     
    DON056C__M = OFF;
    DON057C__M = OFF;
    DON056E__M = OFF;
    DON057E__M = OFF;
    DON251E2_M = OFF;
    DON258E__M = OFF;
    DON251B2_M = OFF;
    DON251C2_M = OFF;
    DON251F2_M = OFF;

    DON251H1_M = OFF;
    DON251H2_M = OFF;
    DON251G1_M = OFF;
    DON251G2_M = OFF;
    DON2x07__M = OFF;
    DON2x01__M = OFF;
    DON2x02__M = OFF;
    DON2x03__M = OFF;
    DON2x04__M = OFF;
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫��
vd  far Regul_07off_V(vd){
    DON251H1_V = OFF; // � ����
    DON251H2_V = OFF; // ���
    DON251G1_V = OFF; // � ����
    DON251G2_V = OFF; // ��� �����
    DON2x07__V = OFF; // ��� �����
    DON2x01__V = OFF; // ���� �� ��
    DON2x02__V = OFF; // ���� �� ����
    DON2x03__V = OFF; // ���� �� ���.
    DON2x04__V = OFF; // ����
}
//-------------------------------
vd  far Regul_07off_S(int far m){
    // �ᯮ���⥫� ����஢��
    if(m<2){
    DON251F1_V = OFF; // �� � (�� ��)
    AON2511_OM = 0;   AON2511_OV = 0;
    DON251E1_V = OFF;
    }
    if(m==1&&CYRSLMS>0&&CYRSLMS<101) return;
    // �ᯮ���⥫� ����樨
    DON251B1_V = OFF;
    DON251C1_V = OFF;
    DON064C__V = OFF; // �� ���
    DON065C__V = OFF;
    DON064E__V = OFF; // � ���
    DON065E__V = OFF;
    DON266E__V = OFF; // ���
    AON266A_OM = 0;
}
//-------------------------------
vd  far Regul_07off_O(int far m){
    // �ᯮ���⥫� ����஢�� (=0,=1)
    if(m<2){
    DON251F2_V = OFF; // �� � (�� ��)
    AON2512_OM = 0;   AON2512_OV = 0;
    DON251E2_V = OFF;
    }
    if(m==1&&CYROTHS>0&&CYROTHS<101) return;
    // �ᯮ���⥫� ����樨 (=0,=2)
    DON251B2_V = OFF;
    DON251C2_V = OFF;
    DON056C__V = OFF;
    DON057C__V = OFF;
    DON056E__V = OFF;
    DON057E__V = OFF;
    DON258E__V = OFF;
    AON258A_OM = 0;
}
//-------------------------------
vd  far Regul_07off(vd){
    Regul_07off_V(); Regul_07off_S(0); Regul_07off_O(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Regul_07_Save(vd){
    if(STEP07 ==70) STEP07__SV=STEP07_PRBK;  else STEP07__SV=STEP07;
    if(STEP07v==70) STEP07v_SV=STEP07v_PRBK; else STEP07v_SV=STEP07v;
}
//---------------------------------------------------------------------------
vd  far Regul_07_Rest(vd){
    STEP07 =STEP07__SV;
    STEP07v=STEP07v_SV;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// ��⠭���� ��室�� "�������" �������� � ����祭�� �� ���ﭨ�
vd  far Set_5xC(_f far SV){
    if(OBJM56___V>0){ DON056C__V=SV;; DON057C__V=OFF; }
    if(OBJM57___V>0){ DON056C__V=OFF; DON057C__V=SV;; }
}
vd  far Set_6xC(_f far SV){
    if(OBJM64___V>0){ DON064C__V=SV;; DON065C__V=OFF; }
    if(OBJM65___V>0){ DON064C__V=OFF; DON065C__V=SV;; }
}
vd  far Get_5xC(vd){
    if(OBJM56___V>0){ DIS05xC=DIS056C__V; }
    else            { DIS05xC=DIS057C__V; }
}
vd  far Get_6xC(vd){
    if(OBJM64___V>0){ DIS06xC=DIS064C__V; }
    else            { DIS06xC=DIS065C__V; }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ���������� ����������
vd  far Regul_07m(vd){
    //-----------------------------------------------------------------------
    // �몫�祭�� ॣ����
    if ( STEP07 == 101 ){
         Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);
         REG07SW__V = 1001;
         STEP07 =  102;
         STEP07v=  102;
    }
    //-----------------------------------------------------------------------
    // ॣ���� �몫�祭
    if ( STEP07 == 102 ){
         STEP07P = 102;
         REG07SW__V = 1002;
         REG07R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP07 =101;
    STEP07v=101;
    VDFLAG___V=0;
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far Regul_07(vd){

    //  ���祭�� � ⠡���� ����஥� ��
    NASSLMOSTV=NASSLMOSTM;
    NASSLMCYRV=NASSLMCYRM;
    NASSLMZAGV=NASSLMZAGM;
    NASSLMGRUV=NASSLMGRUM;
    NASSLMMANV=NASSLMMANM;
    NASOTHOSTV=NASOTHOSTM;
    NASOTHCYRV=NASOTHCYRM;
    NASOTHZAGV=NASOTHZAGM;
    NASOTHGRUV=NASOTHGRUM;
    NASOTHMANV=NASOTHMANM;

    //  ����祭��-�몫�祭�� ॣ����
    if ( REG07RS__M == SWITCH ){ 
         REG07R___M = (REG07R___M==ON) then_ OFF else_ ON; REG07RS__M=OFF;
    }
    if (REG07R___M != REG07R___V){ 
        REG07R___M  =(REG07R___M==ON) then_ ON else_ OFF;
        REG07R___V  = REG07R___M; 
        if (REG07R___V>0){
            // �������
            Message(380,NOKV); STEP07=0; STEP07v=0;
            // �᫨ ����祭 ��騩 ॣ���� � ॣ���� � ࠡ�� - ����⠭����� ���ﭨ� ॣ����
            if (RegPublicV==ON and REG07GL__V==ON and STEP07__SV>1){
                Regul_07_Rest(); Message(236,NOKV); return;
            }
        } else { 
            // �᫨ ����祭 ��騩 ॣ���� � ॣ���� � ࠡ�� - ������� ���ﭨ� ॣ����
            if (RegPublicV==ON and REG07GL__V==ON and STEP07>1 and STEP07<70){ 
                Regul_07_Save(); Message(235,NOKV);
            }
            // �몫����
            Message(381,NOKV); Regul_07off(); STEP07=101; STEP07v=101; return;
        }
    }
    // �� �몫�祭�� ��饣� ॣ���� ���뢠���� ���祭�� ����ᠭ���� 蠣�
    if (RegPublicV==OFF or REG07GL__V==OFF){ STEP07__SV=0; STEP07v_SV=0; }

    //  ����㧪�-���㧪�
    if ( REG07ZV__M != REG07ZV__V ){ 
         REG07ZV__M  =(REG07ZV__M==ON) then_ ON else_ OFF;
         REG07ZV__V  = REG07ZV__M;
         if(REG07ZV__V>0){ Message(480,NOKV); }                      // ����㧪�
         else            { Message(481,NOKV); }                      // ���㧪�
    }

    //  ��騩-�������
    if ( REG07GL__M != REG07GL__V ){ 
         REG07GL__M  =(REG07GL__M==ON) then_ ON else_ OFF;
         REG07GL__V  = REG07GL__M;
         if(REG07GL__V>0){ Message(482,NOKV); }                      // ��騩
         else            { Message(483,NOKV); }                      // �������
    }

    //------------------------------
    //  ���-�몫 ����樨 諠��
    if ( CYRSLM___M != CYRSLM___V ){ 
         CYRSLM___V  = CYRSLM___M;
         if(CYRSLM___V>0){ Message(100,NOKV); CYRSLMS= 10; }         // ��� ������
         else            { Message(101,NOKV); CYRSLMS=101; }         // �몫
         // �᫨ �몫 ��� ० ॣ� (��४��� ⮫쪮 � ��� ०���)
         if(CYRSLMS<101&&REG07GL__V==1){ Message(101,NOKV); CYRSLMS=101; }
         // �몫���� �� �ᯮ���⥫�
         Regul_07off(); return;
    }
    // �� ࠡ�� ����樨 ������ ⮫쪮 ������� ����樨 � ��᫥ �⮣� ������� ����
    if ( CYRSLMS>0 && CYRSLMS<101 ){
         // �몫���� ������,� ��⮬ �������,�� ���� (���� ��-㬮�砭�� ����祭,���� �몫����)
         Regul_07off_S (2); DON266E__V=ON; if(DIS251C1_V>0) AON266A_OM=NASSLMCYRV;
         // ������ ������� ����樨
         if (OBJM64___V>0){ DON064C__V=ON; /*�� ���*/ DON064E__V=ON; /*� ���*/ }
         if (OBJM65___V>0){ DON065C__V=ON; /*�� ���*/ DON065E__V=ON; /*� ���*/ }
         DON251B1_V=ON; /*�� ���*/ DON251C1_V=ON; /*��᫥ ���*/
         // ������ ᥪ㭤� �஢�ઠ ���稪� ���ࠡ�⪨...
         if (RegRUN==ON){
             // �᫨ ������� ����樨 ������ - ����� ���稪 ���ࠡ�⪨ (�� ����� 10ᥪ)
             if((DIS064C__V==ON && DIS064E__V==ON)||(DIS065C__V==ON && DIS065E__V==ON)){
                 if(CYRSLMS>1) CYRSLMS--; if(CYRSLMS>10) CYRSLMS=10;
             } else {
             // �᫨ ��-� ������ - ������� ���稪 ���ࠡ�⪨ (ᥪ)
             // �⮡� �������� "�ॡ����" �� ����祭��-�몫�祭��, ��������� ���稪 ��⠭�����=3ᥪ
                 if(CYRSLMS<3) CYRSLMS=3; if(CYRSLMS<200) CYRSLMS++; // �� =101 �㤥� ��室 �� ����樨
         }   }
         // �᫨ ���稪 ���ࠡ�⪨ ����� 5ᥪ- �몫���� ���� (��-㬮�砭�� ����祭)
         if(CYRSLMS>7){ DON266E__V=OFF; AON266A_OM=0; }
    }    
    // �᫨ ���� �������� �� �몫�祭�� ����樨
    if ( CYRSLMS>=101 ){
         Regul_07off_S(0); Message(102,NOKV); CYRSLMS=0; CYRSLM___V=CYRSLM___M=OFF; return;
    }
    //------------------------------
    //  ���-�몫 ����樨 ��������� 諠��
    if ( CYROTH___M != CYROTH___V ){ 
         CYROTH___V  = CYROTH___M;
         if(CYROTH___V>0){ Message(103,NOKV); CYROTHS= 10; }         // ��� ������
         else            { Message(104,NOKV); CYROTHS=101; }         // �몫
         // �᫨ �몫 ��� ० ॣ� (��४��� ⮫쪮 � ��� ०���)
         if(CYROTHS<101&&REG07GL__V==1){ Message(104,NOKV); CYROTHS=101; }
         // �몫���� �� �ᯮ���⥫�
         Regul_07off(); return;
    }
    // �� ࠡ�� ����樨 ������ ⮫쪮 ������� ����樨 � ��᫥ �⮣� ������� ����
    if ( CYROTHS>0 && CYROTHS<101 ){
         // �몫���� ������,� ��⮬ �������,�� ���� (���� ��-㬮�砭�� ����祭,���� �몫����)
         Regul_07off_S (2); DON258E__V=ON; if(DIS251C2_V>0) AON258A_OM=NASOTHCYRV;
         // ������ ������� ����樨
         if (OBJM56___V>0){ DON056C__V=ON; /*�� ���*/ DON056E__V=ON; /*� ���*/ }
         if (OBJM57___V>0){ DON057C__V=ON; /*�� ���*/ DON057E__V=ON; /*� ���*/ }
         DON251B2_V=ON; /*�� ���*/ DON251C2_V=ON; /*��᫥ ���*/
         // ������ ᥪ㭤� �஢�ઠ ���稪� ���ࠡ�⪨...
         if (RegRUN==ON){
             // �᫨ ������� ����樨 ������ - ����� ���稪 ���ࠡ�⪨ (�� ����� 10ᥪ)
             if((DIS056C__V==ON && DIS056E__V==ON)||(DIS057C__V==ON && DIS057E__V==ON)){
                 if(CYROTHS>1) CYROTHS--; if(CYROTHS>10) CYROTHS=10;
             } else {
             // �᫨ ��-� ������ - ������� ���稪 ���ࠡ�⪨ (ᥪ)
             // �⮡� �������� "�ॡ����" �� ����祭��-�몫�祭��, ��������� ���稪 ��⠭�����=3ᥪ
                 if(CYROTHS<3) CYROTHS=3; if(CYROTHS<200) CYROTHS++; // �� =101 �㤥� ��室 �� ����樨
         }   }
         // �᫨ ���稪 ���ࠡ�⪨ ����� 5ᥪ- �몫���� ���� (��-㬮�砭�� ����祭)
         if(CYROTHS>7){ DON258E__V=OFF; AON258A_OM=0; }
    }    
    // �᫨ ���� �������� �� �몫�祭�� ����樨
    if ( CYROTHS>=101 ){
         Regul_07off_S(0); Message(105,NOKV); CYROTHS=0; CYROTH___V=CYROTH___M=OFF; return;
    }
    //------------------------------



    //  �᫨ ॣ���� �몫�祭 - ���
    if (REG07R___V == OFF && REG07GL__V == OFF){ Regul_07m(); return; }

    // !!!!
    // �᫨ �� �६� ����㧪�-���㧪� ���ண� ������� ��ଥ⨧��� -
    // ������� ������ ���㧪� � �몫���� ॣ����
    if (STEP07>=52 and STEP07<=60 and DISVGBMG_V==OFF and RegRUN==ON){
//  if (STEP07 >1  and STEP07< 60 and DISVGBMG_V==OFF and RegRUN==ON){
        GERMDOWN++;
        if (GERMDOWN>1){
            Bell(1,1); Message(116,NOKV); Message(677,NOKV); GERMDOWN=0; Regul_07m(); return;
        }
    } else { GERMDOWN=0; }
    // !!!!

    //  �᫨ �ࠡ�⠫ ���਩�� �஢��� ������ ���ண�-
    //  ���� �������� �� �����⨥ �������� � �몫�祭�� ॣ����
    if (DIH252A__V>0){
        Bell(1,1); Message(150,KVIT); // Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1); Regul_07m(); return;
    }

    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if (STEP07== 0 ){
        if(STEP07P!=0){
           Clear_TO(73);
        }; STEP07P =0;
        Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);

        if (RegRUN==OFF){ return; }

        //  ���� ������ ���ண� � ०��� ������� - ���
        REG07SW__V =2;
        if(DIR219___V==1){ return; }

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� ������ ���ண�
        REG07SW__V =6; Get_6xC(); Get_5xC();
        if (DIS251E1_V==ON or DIS251F1_V==ON or DIS251G1_V==ON or DIS251H1_V==ON or
            DIS251E2_V==ON or DIS251F2_V==ON or DIS251G2_V==ON){
            switch(Check_TO(73,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(268,KVIT); Bell(1,1); Clear_TO(73); return;; }
            }
        }

        REG07SW__V =2001;

        Clear_TO(71); Clear_TO(72); Clear_TO(73);

        STEP07=1;
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ������� � ��।������ ���ࠢ����� ࠡ��� ॣ����
    //-----------------------------------------------------------------------
    if (STEP07== 1 ){
        if(STEP07P!=1){
           ;;
        }; STEP07P =1;
        if (RegRUN==OFF){ return; }

        // �᫨ ॣ���� � ��������� ०��� �஢���� ��� ���� � ��ଥ⨧���
        if (REG07GL__V==OFF){ 
            //  ���� �� ����祭�
            REG07SW__V =12;
            switch ( Check_TO  (72, 2*MIN, DISVGBMR_V,'=',ON, 1 )){
                case RUN: { return;; }
                case BAD: { Clear_TO(72); Message(386,NOKV); Bell(1,1); return;; }
            };  Clear_TO(72);
            //  ��ଥ⨧��� �� ���饭
            REG07SW__V =14;
            switch ( Check_TO  (73, 2*MIN, DISVGBMG_V,'=',ON, 1 )){  
                case RUN: { return;; }
                case BAD: { Clear_TO(73); Message(387,NOKV); Bell(1,1); return;; }
            };  Clear_TO(73);
        }

        //  �᫨ ॣ���� � ��������� ०��� � ��࠭ ०�� ��������-
        //  ��३� �� 蠣 ���㧪�
        if (REG07GL__V==OFF and REG07ZV__V==OFF){ STEP07=51; STEP07v=51; STEP07_BACK=30; return; }

        //  �᫨ ॣ���� � ��������� ०��� � ��࠭ ०�� �����
        if (REG07GL__V==OFF){ STEP07=5; STEP07v=22; DON211A1_V=0; }

        //  �᫨ ॣ���� � ����� ०��� (����祭 ��騩 ॣ����)
        //  � ������ ���ண� �� ����㦥� - ��३� �� 蠣 �������� �� ���ண� � �����
        // (�� ࠡ�� ��饣� ॣ���� ०�� ����㧪�-���㧪� �� �㦥�
        //  ���㧪� ������ ���ண� ��稭����� �ࠧ� ��᫥ ����� ���ண�)
        if (REG07GL__V==ON and RegPublicV==ON and DON211A1_V==0){ 
            // �஢�ઠ ����祭�� ��� ����
            REG07SW__V =12;
            if(DISVGBMR_V==OFF){ return; }
            // �஢�ઠ ��ଥ⨧���
            REG07SW__V =14;
            if(DISVGBMG_V==OFF){ return; }
            STEP07=5;
            // �᫨ ���� ࠧ ����稫� ॣ���� - ����� ���� �� 蠣�=0,
            // ��᫥ ��⮬���᪮�� ����� � ���㧪� - �� 蠣�=30
            if(STEP07v==0) STEP07v=22;
        }

        // ���㫥��� �⮡ࠦ���� ⥪�饣� ��� ������ �� �����
        if((REG07GL__V==OFF and REG07ZV__V==ON) or DON211B1_V==0){
            CRVODD___V=0;
            CROTH____V=0;
            CRSLM____V=0;
            AIW252FV_V=0;
            AIW252NV_V=AIW252___V;           // ��砫�� ��� ������ ���ண�
            AIW252VD_V=AIW252___V;           // ��砫�� ��� ������ ���ண�
            AIW251FV_V=0;
            AIW251NV_V=AIW251___V;           // ��砫�� ��� ������ ����
            AIW251VD_V=AIW251___V;           // ��砫�� ��� ������ ����
        }
        return;
    }
    //-----------------------------------------------------------------------


    // ��������� ��� �����
    //-----------------------------------------------------------------------
    // ����⨥ �������� ����� ��� 諠��
    if (STEP07== 5 ){
        if(STEP07P!=5){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           AIW252___O = AIW252___V;         // ��������� ⥪�騩 ��� ������
           AIW252NV_V = AIW252___V;         // ��������� ⥪�騩 ��� ������
           if(STEP07P!=70) Regul_07off_O(1);
        }; STEP07P =5;
        REG07SW__V =51;

        //  ��।����� ��� ���窨, ������� � �����஢��
        AIW252VO_V = TROTH__VIB-VSOT_OTH_W;
        AIW252VZ_V = TROTH__VIB;

        //  �஢���� ��� ����� ��� 諠��. �᫨ ���࠭ - �� ᫥� 蠣
        if(AIW252___V >= AIW252VO_V){ Regul_07off_O(1); STEP07=12; return; }

        //  ��� ��� 諠��
        CROTH____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=5;

        if(RegRUN==OFF){ return; }

        // ������� ������� ����஢�� � ����樨
        if(CYROTH___V==0){ DON251F2_V = ON;; PO2512=100; DON251E2_V = OFF; DIS251x=DIS251F2_V; }  // �� �몫
        else             { DON251F2_V = OFF; PO2512=0;   DON251E2_V = ON;; DIS251x=DIS251E2_V; }  // �� ���
        // �.�. ������ �� ࠡ�⠥� (�� �� �孮������), ������ ��業� ������ � = 100%
        AON2512_OV=AON2512_OM=PO2512=100;

        // �஢���� ����⨥ ������� ����஢�� ��� 諠�� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251x,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� ������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ Bell(1,1); Message(309,KVIT); DONCN07=0; return; }
                        if(CYROTH___V==0) Isp07PD(&DON251F2_V,3,TIME_ISPPW,70, STEP07P, 71);
                        else              Isp07PD(&DON251E2_V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }
        if(CYROTH___V==0){
        // �஢���� ����⨥ ������� ����஢�� ��� 諠�� �����
        Set_5xC(ON); Get_5xC();
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS05xC,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� ������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ Bell(1,1); Message(310,KVIT); DONCN07=0; return; }
                        if(OBJM56___V>0) Isp07PD(&DON056C__V,3,TIME_ISPPW,70, STEP07P, 72);
                        else             Isp07PD(&DON057C__V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }   }
        Clear_TO(71);
        Clear_TO(72);
        STEP07 = 6; 
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ����� ��� 諠��
    //-----------------------------------------------------------------------
    if (STEP07== 6 ){
        if(STEP07P!=6){
           TMST_OTH_C=0;                    // ���稪 �६��� �஢�ப
           VSST_OTH_C=0;                    // ���稪 �஢�ப ���
           AIW252___O=AIW252___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =6;
        REG07SW__V =61;

        // ��।����� ��� ���窨, ������� � �����஢��
        AIW252VO_V = TROTH__VIB-VSOT_OTH_W;
        AIW252VZ_V = TROTH__VIB;

//      // ������ % ������ ������� ����஢�� ��� 諠��
        if(AIW252___V > TROTH__VIB-AON2512VOW){
            PO2512=AON2512__W;
        }

//      // ��� ����� ��� 諠�� ����� - ����� ᪮���� ����
        if(AIW252___V > TROTH__VIB-VSOT_OTG_W){ 
            if(CYROTH___V<1){ DON056C__V=OFF; DON057C__V=OFF; }
            else            { AON258A_OM=NASOTHGRUV; }
        }

        // �᫨ ��� ����� ��� 諠�� ����� ��� ࠢ�� ��������� �����
        // ��� ���窨- ������� ������� ॣ���� � �� ᫥� 蠣
        if (AIW252___V>=TROTH__VIB-VSOT_OTH_W){ 
            if(CYROTH___V>0){ DON251C2_V=ON; }
            PO2512=0;
            AON258A_OM=NASOTHOSTV; Regul_07off_O(1); STEP07=7; return;
        }

        // ��� ���࠭��� ��� 諠�� 
        CROTH____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=6;

        if (RegRUN==OFF){ return; }

        // ��४��祭�� "�� 室�" �㭪�� ��� ����� 諠��
        Set_5xC(ON); Get_5xC();

//      // �᫨ ����� ������ ����஢�� � ����樨 - ������� ������ ����樨 � 
        // ������� ᪮���� ���� ��� ����㧪�:
        if(DON251E2_V==ON){ 
             DON251C2_V=OFF; AON258A_OM=NASOTHZAGV;
        }
        // ���� ��⠭����� ��業� ������ ������� ����஢��:
//      else { 
             AON2512_OM=AON2512_OV=PO2512;
//      }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� ��� 諠��
           TMST_OTH_C++;
        if(TMST_OTH_C>TMST_OTH_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW252___O+VSST_OTH_W>AIW252___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_OTH_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              if(VSST_OTH_C>2){ Bell(1,1); Message(215,KVIT); VSST_OTH_C=0; return; }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_OTH_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW252___O=AIW252___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_OTH_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ������������ ����� ��� 諠�� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07== 7 ){
        if(STEP07P!=7){
           CNST_OTH_C=0;                    // ���稪 �஢�ப �⠡�����樨
           TMST_OTH_C=0;                    // ���稪 �६���  �⠡�����樨 
           AIW252___O=AIW252___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =7;
        Regul_07off_O(1);                   // �������(�몫����) �ᯮ���⥫� ॣ����
        AON2512_OM=AON2512_OV=PO2512=0;     // ������� ���� ����� ���� 諠��
        REG07SW__V =71;

        if(RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� ����� ��� 諠�� �����
        if(CYROTH___V==0){
        Get_5xC();
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS05xC,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(311,KVIT); DONCN07=0; return; }
                        if(OBJM56___V>0) Isp07PD(&DON056C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        else             Isp07PD(&DON057C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; AIW252___O=AIW252___V; break;; }
        }   }

        // �஢���� �����⨥ ������� ����� ��� 諠�� �����
        if(CYROTH___V==0){ DON251F2_V = OFF; DON251E2_V = OFF; DIS251x=DIS251F2_V; }  // �� �몫
        else             { DON251F2_V = OFF; DON251E2_V = OFF; DIS251x=DIS251E2_V; }  // �� ���
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(312,KVIT); DONCN07=0; return; }
                        if(CYROTH___V==0) Isp07PD(&DON251F2_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E2_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; AIW252___O=AIW252___V; break;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG07SW__V =72;
        switch ( Check_TO  (73, TMST_OTH_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_OTH_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);

        // �஢�ઠ ��� �⠡�����樨:
        // �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        // ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW252___O+VSST_OTH_W<AIW252___V){
           CNST_OTH_C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           // ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_OTH_C>CNST_OTH_W){ 
              Bell(1,1); Message(313,KVIT); return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              Set_5xC(ON); DON251F2_V=ON; AIW252___O=AIW252___V; return;
           }
        }

        STEP07 = 12;
        return;
    }
    //-----------------------------------------------------------------------
    if (STEP07>7 and STEP07<12){ STEP07=12; }
    //-----------------------------------------------------------------------



    //  ��������� �����
    //-----------------------------------------------------------------------
    //  ����⨥ �������� ����� 諠�� �����
    if (STEP07== 12 ){
        if(STEP07P!=12){
           if(STEP07P!=70){ Regul_07off_O(1); Regul_07off_S(1); }
           Clear_TO(71);
           Clear_TO(72);
           if(AIW252FV_V==5||AIW252FV_V==6){ CROTH____V=AIW252___V-AIW252NV_V; }
           AIW252___O = AIW252___V;         // ��������� ⥪�騩 ��� ������
           AIW252NV_V = AIW252___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07P =12;
        REG07SW__V =121;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        AIW252VO_V = TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
        AIW252VZ_V = TROTH__VIB+TRSLM__VIB;

        CRSLM____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=12;

        if(AIW252___V > TROTH__VIB+TRSLM__VIB-VSOT_SLT_W){ 
            if(CYRSLM___V>0){ DON251C1_V=ON; DON251E1_V=OFF; }
            AON266A_OM=NASSLMOSTV; Regul_07off_S(1); STEP07=15; return; 
        }

        if(RegRUN==OFF){ return; }

        // ������� ������� ����஢�� � ����樨
        if(CYRSLM___V==0){ DON251F1_V = ON;; PO2511=100; DON251E1_V = OFF; DIS251x=DIS251F1_V; }  // �� �몫
        else             { DON251F1_V = OFF; PO2511=0;   DON251E1_V = ON;; DIS251x=DIS251E1_V; }  // �� ���
        // �.�. ������ �� ࠡ�⠥� (�� �� �孮������), ������ ��業� ������ � = 100%
        AON2511_OV=AON2511_OM=PO2511=100;

        // �஢���� ����⨥ ������� ����஢�� ��� 諠�� �����
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(315,KVIT); DONCN07=0; return; }
                        if(CYRSLM___V==0) Isp07PD(&DON251F1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }  

        //  ���� �������� �� ����⨥ ������� ����஢�� 諠�� �����
        if(CYRSLM___V==0){
        Set_6xC(ON); Get_6xC();
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS06xC,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(314,KVIT); DONCN07=0; return; }
                        if(OBJM64___V>0) Isp07PD(&DON064C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        else             Isp07PD(&DON065C__V,3,TIME_ISPPW,70, STEP07P, 71);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }   }

        Clear_TO(71);
        Clear_TO(72);
        STEP07 = 14; 
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ������ 諠��
    //-----------------------------------------------------------------------
    if (STEP07== 14 ){
        if(STEP07P!=14){
           VSST_SLT_C = 0;
           TMST_SLT_C = 0;
           AIW252___O = AIW252___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07P =14;
        REG07SW__V =141;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        AIW252VO_V = TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
        AIW252VZ_V = TROTH__VIB+TRSLM__VIB;

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨 �����
        if (AIW252___V >= AIW252VO_V){ 
            PO2511=0;
            Regul_07off_S(1); STEP07=15; return;
        }

        CRSLM____V=AIW252___V-AIW252NV_V;
        AIW252FV_V=14;

//      // ������ % ������ ������� ����஢�� 諠��
        if(AIW252___V > AIW252VZ_V-AON2511VOW){
            PO2511=AON2511__W;
        }

//      // ��� ����� 諠�� �����
        if(AIW252___V > AIW252VZ_V-VSOT_SLG_W){
            if(CYRSLM___V<1){ DON064C__V=OFF; DON065C__V=OFF; }
            else            { AON266A_OM=NASSLMGRUV; }
        }

        // �஢���� ��� ����� 諠�� �����, ���࠭ - �� ���㧪�
        if(AIW252___V > AIW252VZ_V-VSOT_SLT_W){ 
            if(CYRSLM___V>0){ DON251C1_V=ON; }
            PO2511=0;
            AON266A_OM=NASSLMOSTV; Regul_07off_S(1); STEP07=15; return; 
        }

        if (RegRUN==OFF){ return; }

        // �� ����� 諠�� ����� ��४����� �㭪�� � ���ண� ���� 諠�
        Set_6xC(ON); Get_6xC();

//      // �᫨ ����� ������ ����஢�� � ����樨 - ������� ������ ����樨 � 
        // ������� ᪮���� ���� ��� ����㧪�
        if(DIS251E1_V==ON){ DON251C1_V=OFF; AON266A_OM=NASSLMZAGV; }
        // ���� ��⠭����� ��業� ������ ������� ����஢��:
//      else { 
             AON2511_OM=AON2511_OV=PO2511;
//      }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� 諠�� �����
           TMST_SLT_C++;
        if(TMST_SLT_C>TMST_SLT_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW252___O+VSST_SLT_W>AIW252___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_SLT_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              if(VSST_SLT_C>2){ Bell(1,1); VSST_SLT_C=0; return; }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_SLT_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW252___O=AIW252___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_SLT_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ������������ ����� 諠��
    //-----------------------------------------------------------------------
    if (STEP07== 15 ){
        if(STEP07P!=15){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           Clear_TO(73);                    //
           TMST_SLT_C=0;                    //
           CNST_SL__C=0;
           AIW252___O=AIW252___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =15;
        REG07SW__V =151;
        Regul_07off_O(1); Regul_07off_S(1);
        AON2511_OM=AON2511_OV=PO2511=0;     // ������� ���� ����� ��� 諠��

        if(AIW252FV_V==14){
           CRSLM____V=AIW252___V-AIW252NV_V; 
        }

        if (RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� ����� 諠�� �����
        if(CYRSLM___V==0){ DON251F1_V = OFF; DON251E1_V = OFF; DIS251x=DIS251F1_V; }  // �� �몫
        else             { DON251F1_V = OFF; DON251E1_V = OFF; DIS251x=DIS251E1_V; }  // �� ���
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS251x,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(317,KVIT); DONCN07=0; return; }
                        if(CYRSLM___V==0) Isp07PD(&DON251F1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        else              Isp07PD(&DON251E1_V,3,TIME_ISPPW,70, STEP07P, 72);
                        return;
                      }
            case END: { DONCN07=0; break;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG07SW__V =152;
        switch ( Check_TO  (73, TMST_SLT_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_SLT_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);

        // �஢�ઠ ��� �⠡�����樨:
        // �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        // ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW252___O+VSST_SLT_W<AIW252___V){
           CNST_SL__C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������
           if(CNST_SL__C>CNST_SL__W){
              Bell(1,1); Message(148,KVIT); return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              Set_6xC(ON); DON251F1_V=ON; AIW252___O=AIW252___V; return;
           }
        }

        // �᫨ ॣ���� � ��饬 ०��� - ���㧪� 
        if(REG07GL__V==ON){ STEP07=51; STEP07_BACK=30; return; }
        STEP07=30;
        return;
    }
    //-----------------------------------------------------------------------

 
    //-----------------------------------------------------------------------
    // ����� ���� � ॣ���� regul_07v
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ����������� ��������
    //-----------------------------------------------------------------------
    if (STEP07==30){
        if(STEP07P!=30){
        }; STEP07P =30;
        if(STEP07v!=30){ return; }
        Regul_07off_O(1); Regul_07off_S(1);
        if(RegRUN==OFF){ return; }
        // �᫨ ॣ���� � �����쭮� ०���- �몫���� ॣ����
        if(RegPublicV==OFF or REG07GL__V==OFF){
           Message(484,NOKV); Message(677,NOKV); Regul_07m(); REG07R___M=OFF;
        }; STEP07=0; /* STEP07v=30; */
        return;
    }
    //-----------------------------------------------------------------------



    // STEP07 > 40 - ���㧪�


    //  �������� �� �������� ������� � ����
    //-----------------------------------------------------------------------
    //  �஢�ઠ ��⮢���� ����:
    if (STEP07==51){
        if(STEP07P!=51){
           Clear_TO(71); Clear_TO(72);
        }; STEP07P =51;
        Regul_07off_O(1); Regul_07off_S(1);

        if (RegRUN==OFF){ return; }

        //  �᫨ ���� �� ����祭� - ������
        REG07SW__V=511;
        switch ( Check_TO  (71, 1*MIN, DISVGBMR_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(71); Message(386,NOKV); return;; }
        };  Clear_TO(71);

        //  �᫨ ��ଥ⨧��� �� ���饭 - ������
        REG07SW__V=512;
        switch ( Check_TO  (72, 1*MIN, DISVGBMG_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(72); Message(387,NOKV); return;; }
        }

        Clear_TO(71); Clear_TO(72);
        STEP07=52;
        return;
    }
    //-----------------------------------------------------------------------
    if (STEP07==52){
        if(STEP07P!=52){
        }; STEP07P =52;
        if (RegRUN==OFF){ return; }

        // �᫨ ���㧪� ���� � ��饬 ॣ���� - ��������� ��� �� �⮬ 蠣�
        REG07SW__V=521;
        if (RegPublicV==ON and REG07GL__V==ON and STEP07v>0 and STEP07v<52) return;

        STEP07=53;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ������� �������� � ����
    //-----------------------------------------------------------------------
    if (STEP07==53){
        if(STEP07P!=53){
           // �᫨ ��। �⨬ 蠣�� ����ࠫ� 諠�- ��������� ��� 諠��
           if(AIW252FV_V>=14 and AIW252FV_V<=17){
              CRSLM____V=AIW252___V-AIW252NV_V;
           }
           if(STEP07P!=70){ Regul_07off_O(1); Regul_07off_S(1); }
        }; STEP07P =53;

        if (RegRUN==OFF){ return; }

        //  ������ ������ ���㧪� � ���� � ������ ��࡮⠦�
        REG07SW__V =531;
        DON251H2_V = ON;
        DON251G2_V = ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251G2_V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(159,KVIT); DONCN07=0; return; }
                        Isp07PD(&DON251G2_V,3,TIME_ISPPW,70, STEP07P, 71); return;
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        MK_VG_KL_OPEN=0; 
        AIW252___O = AIW252___V;
        STEP07 = 54;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ���� �������� ������ ���ண�
    //-----------------------------------------------------------------------
    if (STEP07== 54 ){
        if(STEP07P!=54){
           AIW252___O=AIW252___V;
           VSST_MKVIC=0;
           TMST_MKVIC=0;
           CNST_MKVIC=0;
        }; STEP07P =54;
        REG07SW__V =541;

        //  �᫨ ⥪�騩 ��� ������ ����� ��� ࠢ�� ���- ��३� �� ᫥� 蠣
        if (AIW252___V<=0 or CNST_MKVIC>=CNST_MKVIW){ STEP07=55; return; }

        if(RegRUN==OFF){ return; }

        //  �᫨ ����諮 �६� �஢�ન �⠡�����樨 ��� ������ ���ண�
        TMST_MKVIC++;
        if (TMST_MKVIC>TMST_MKVIW){
            //  �᫨ ��� �⠡�����஢����- 㢥����� ���稪 �⠡������ ���
            if (AIW252___V+VSST_MKVIW>AIW252___O){ CNST_MKVIC++; }
            else                                 { CNST_MKVIC=0; }
            AIW252___O=AIW252___V; TMST_MKVIC=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������������� ������� ��������
    //-----------------------------------------------------------------------
    // �஬뢪� �㭪�� 諠��
    if (STEP07== 55 ){
        if(STEP07P!=55){
           CNST_MKVIC=0;
        }; STEP07P =55;
        if (RegRUN==OFF){ return; }
        REG07SW__V =551;
        // ��᫥ ���㧪� ������ ���ண� (諠��) - ����� ��� �஬뢪�
        if(RegPublicV==ON and REG07GL__V==ON and STEP07v>0 and STEP07v<60) return;
        STEP07=60;
        return;
    }
    //-----------------------------------------------------------------------


    // ������� ������ �������� �� ������ ���ண� � ����
    //-----------------------------------------------------------------------
    // ������� �� ������� ������ ���ண�
    if (STEP07== 60 ){
        if(STEP07P!=60){
           ;;
        }; STEP07P =60;
        Regul_07off_V(); Regul_07off_O(1); Regul_07off_S(1);
        if (RegRUN==OFF){ return; }

        REG07SW__V = 601;
        DON251G2_V = OFF;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS251G2_V,'=',OFF, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ Bell(1,1); Message(160,KVIT); DONCN07=0; return; }
                        Isp07PD(&DON251G2_V,3,TIME_ISPPW,70, STEP07P, 71); return;
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        //  �᫨ �� ����� ���㧪� ������ ���ண�- ����� 䫠� ��� ���ண�
        if (STEP07_BACK==0 or STEP07_BACK==30){ 
            DON211A1_V=2;
            //  �᫨ ॣ���� � �����쭮� ०���- �몫���� ���
            if (REG07GL__V==OFF){ 
                Message(485,NOKV); Message(677,NOKV); REG07R___M=OFF; 
            }
        }

        //  ��⠭����� ���������� 蠣 ⥪�騬
        STEP07 = STEP07_BACK;
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP07 ==70 ){
        if(STEP07P!=70){
           ;;
        }; STEP07P =70;
        if(DONCN07>=DONCH07){ STEP07 = STEP07_PRBK; return; }
        REG07SW__V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(207, DONTM07*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(207);
       *DONPR07=(*DONPR07!=ON)?ON:OFF;
        DONCN07++;
        STEP07 = STEP07_PRBK;
        return;
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
