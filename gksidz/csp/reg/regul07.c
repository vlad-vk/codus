//---------------------------------------------------------------------------
// ����஢�� ���ண�

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR07;
_i far  DONCN07=0;                // ���稪 横�� ��।�ࣨ�����             
_i far  DONCH07=2;                // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i far  DONTM07=2;                // ���-�� ᥪ㭤 ��� � ����

_f far  CNTTEMP=0;                // �६���� ���稪
_f far  REG07ZO1_F=0;             // 䫠� �뢮�� �����


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
//  ���������� ������������ ॣ����
vd  far Regul_07off(vd){
    DON202___V = OFF;
    DON203___V = OFF;

    DON211___V = OFF;
    DON212___V = OFF;

    DON221___V = OFF;
    DON222___V = OFF;
    DON223___V = OFF;

    DON232___V = OFF;

    DON231___V = OFF;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ���������� ����������
vd  far Regul_07m(vd){
    //-----------------------------------------------------------------------
    // �몫�祭�� ॣ����
    if ( STEP07 == 101 ){
         Regul_07off();
         REG07SW__V = 1001;
         // ��⠭����� 䫠�� ����� ��������⮢
         FNOTH____V = ON;
         FNSLM____V = ON;
         FNVODP___V = ON;
         FNVODD___V = ON;
         STEP07 =  102;
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
    STEP07=101;
    return;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
vd  far Regul_07(vd){

    //  ��४��祭�� 䫠��� ����㧮� ��������⮢
    if ( FNOTH____W == SWITCH){
         FNOTH____V = (FNOTH____V==ON) then_ OFF else_ ON; FNOTH____W=OFF;
    }
    if ( FNSLM____W == SWITCH){
         FNSLM____V = (FNSLM____V==ON) then_ OFF else_ ON; FNSLM____W=OFF;
    }
    if ( FNVODP___W == SWITCH){
         FNVODP___V = (FNVODP___V==ON) then_ OFF else_ ON; FNVODP___W=OFF;
    }
    if ( FNVODD___W == SWITCH){
         FNVODD___V = (FNVODD___V==ON) then_ OFF else_ ON; FNVODD___W=OFF;
    }
    //  ��४��祭�� ��ਠ�⮢ ���㧪�
    if ( MKVG_REC_W == SWITCH){
         MKVG_REC_V = (MKVG_REC_V==ON) then_ OFF else_ ON; MKVG_REC_W=OFF;
    }
    if ( MKVG_IZS_W == SWITCH){
         MKVG_IZS_V = (MKVG_IZS_V==ON) then_ OFF else_ ON; MKVG_IZS_W=OFF;
    }
    if ( FNSLMVOD_W == SWITCH){
         FNSLMVOD_V = (FNSLMVOD_V==ON) then_ OFF else_ ON; FNSLMVOD_W=OFF;
    }

    //  ������ ��� ᤮��஢������ 諠�� + ᤮��஢���� ��室�
    CRSLO____V=CRSLM____V+CROTH____V;

    //  ����祭��-�몫�祭�� ॣ����
    if ( REG07RS__M == SWITCH ){ 
         REG07R___M = (REG07R___M==ON) then_ OFF else_ ON; REG07RS__M=OFF;
    }
    if (REG07R___M != REG07R___V){ 
        REG07R___M  =(REG07R___M==ON) then_ ON else_ OFF;
        REG07R___V  = REG07R___M; 
        if(REG07R___V>0){ Message(380); STEP07 =   0; }         // �������
        else            { Message(381); STEP07 = 101; }         // �몫����
    }
    //  ����㧪�-���㧪�
    if ( REG07ZV__M != REG07ZV__V ){ 
         REG07ZV__M  =(REG07ZV__M==ON) then_ ON else_ OFF;
         REG07ZV__V  = REG07ZV__M;
         if(REG07ZV__V>0){ Message(480); }                      // ����㧪�
         else            { Message(481); }                      // ���㧪�
    }
    //  ��騩-�������
    if ( REG07GL__M != REG07GL__V ){ 
         REG07GL__M  =(REG07GL__M==ON) then_ ON else_ OFF;
         REG07GL__V  = REG07GL__M;
         if(REG07GL__V>0){ Message(482); }                      // ��騩
         else            { Message(483); }                      // �������
    }
    //  �᫨ ॣ���� �몫�祭 - ���
    if (REG07R___V == OFF){ Regul_07m(); return; }

    //  �᫨ �� �६� ���㧪� ���ண� ������� ��ଥ⨧���-
    //  ������� ������ ���㧪� � �몫���� ॣ����
    if (STEP07>=52 and STEP07<=56 and DIS31A___V==OFF){
        Bell(1); Message(116); Message(677); Regul_07off(); 
        REG07R___M=OFF; return;
    }


    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if (STEP07== 0 ){
        if(STEP07P!=0){
           ;;
        }; STEP07P =0;
        if (RegRUN==OFF){ return; }

        Regul_07off();                      // ������� �� �ᯮ���� ॣ����

        //  ���� ��蠫�� 諠��
        REG07SW__V =1;
        if(DIR220___V==MANUAL){ return; }

        //  ���� ������ ���ண�
        REG07SW__V =2;
        if(DIR230___V==MANUAL){ return; }

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� ��蠫�� ��室��
        REG07SW__V =4;
        if (DIS211___V==ON or DIS212___V==ON){ 
            switch(Check_TO(71,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(268); Bell(1); Clear_TO(71); return;; }
            }
        };  Clear_TO(71);

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� ��蠫�� 諠��
        REG07SW__V =5;
        if (DIS221___V==ON or DIS222___V==ON){ 
            switch(Check_TO(72,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(268); Bell(1); Clear_TO(72); return;; }
            }
        };  Clear_TO(72);

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� ������ ���ண�
        REG07SW__V =6;
        if (DIS202___V==ON or DIS203___V==ON or
            DIS231___V==ON or DIS232___V==ON){
            switch(Check_TO(73,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(268); Bell(1); Clear_TO(73); return;; }
            }
        };  Clear_TO(73);

        //  �᫨ ���� ᨣ��� ������� �஢�� � ��蠫�� ��室��- �।�०�����
        // (��� ��室�� ����� ࠡ����- ��㧨�� �� 諠���)
        REG07SW__V =7;
        if(CTRL_LLMOV==ON){
           // ������ �஢��� �᫨ ॣ���� � ��饬 ०��� ��� �᫨
           // ॣ���� � �����쭮� ०��� � ����祭� ����㧪�
           if((REG07GL__V==ON) or (REG07GL__V==OFF and REG07ZV__V==ON)){
              switch ( Check_TO  (75, 1*MIN, DIL210___V,'=',OFF, TIME_LSTBV )){
                  case RUN: { return;; }
                  case BAD: { Clear_TO(75); Message(382); Bell(1); break;; }
              }
           }
        }

        //  �᫨ ���� ᨣ��� ������� �஢�� � ��蠫�� 諠�� - ���
        REG07SW__V =8;
        if(CTRL_LLMSV==ON){
           // ������ �஢��� �᫨ ॣ���� � ��饬 ०��� ��� �᫨
           // ॣ���� � �����쭮� ०��� � ����祭� ����㧪�
           if((REG07GL__V==ON) or (REG07GL__V==OFF and REG07ZV__V==ON)){
              switch ( Check_TO  (76, 1*MIN, DIL220___V,'=',OFF, TIME_LSTBV )){
                  case RUN: { return;; }
                  case BAD: { Clear_TO(76); Message(383); Bell(1); return;; }
              }
           }
        }

        //  �᫨ ���� ᨣ��� ������� �஢�� � ᡮ୨�� ���� - ���
        REG07SW__V =9;
        if(CTRL_LLSVV==ON){
           // ������ �஢��� �᫨ ॣ���� � ��饬 ०��� ��� �᫨
           // ॣ���� � �����쭮� ०��� � ����祭� ����㧪�
           if((REG07GL__V==ON) or (REG07GL__V==OFF and REG07ZV__V==ON)){
              switch ( Check_TO  (77, 1*MIN, DIL200___V,'=',OFF, TIME_LSTBV )){
                 case RUN: { return;; }
                 case BAD: { Clear_TO(77); Message(384); Bell(1); return;; }
              }  
           }
        }

        //  �஢�ઠ 䫠�� ࠡ��ᯮᮡ���� �ਡ�� ������ ���ண�
        REG07SW__V =10;
        if( COM2ER02FL==ON ){ return; }

        REG07SW__V =2001;
        //  �᫨ ����祭 ��騩 ॣ���� � ������ ��宣� �� ���࠭
        //  � ॣ���� ����஢�� ��宣� ����祭- ���
        if (REG07GL__V==ON and RegPublicV==ON and 
            DON802___V< 1  and DON801___V==0  and REG06R___V==ON){
            switch ( Check_TO  (74, 3*MIN, ZERO,'=',ON,  1 )){
                case RUN: { return;; }
                case BAD: { Clear_TO(74); Message(214); Bell(1); return;; }
            }
            return; 
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);
        Clear_TO(74);
        Clear_TO(75);
        Clear_TO(76);
        Clear_TO(77);

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

        //  �᫨ ���� ��� �� ���� - ���
        REG07SW__V =11;
        switch ( Check_TO  (71, 2*MIN, DIS315___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(71); Message(385); Bell(1); return;; }
        };  Clear_TO(71);

        //  �᫨ ���� �� ����祭� - ���
        REG07SW__V =12;
        switch ( Check_TO  (72, 2*MIN, DIS310___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(72); Message(386); Bell(1); return;; }
        };  Clear_TO(72);

        //  �᫨ ��ଥ⨧��� �� ���饭 - ���
        REG07SW__V =14;
        switch ( Check_TO  (73, 2*MIN, DIS31A___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(73); Message(387); Bell(1); return;; }
        };  Clear_TO(73);

        //  ��蠫�� ��室�� �� ����-ࠡ�⠥� ��� ��室��. ᮮ�饭��, ������
        if(DIR210___V==MANUAL){ Message(298); Bell(1); }


        //  �᫨ ॣ���� � ��������� ०��� � ��࠭ ०�� ��������-
        //  ��३� �� 蠣 ���㧪�
        if (REG07GL__V==OFF and REG07ZV__V==OFF){ STEP07=52; }

        //  �᫨ ॣ���� � ��������� ०��� � ��࠭ ०�� ��������
        //  ���� ��������⮢ ��३� �� 蠣 ����㧪� �஬뢮筮� ����
        if (REG07GL__V==OFF and REG07ZV__V==ON and CHAN_MODEW>0){ 
            STEP07= 2; DON802___V=0;
        }
        //  �᫨ ॣ���� � ��������� ०��� � ��࠭ ०�� �����
        //  ������������� ��३� �� 蠣 ����� ��室��
        //  (�� ����� ����������⭮ ०�� ����㧪�-���㧪� �� �㦥�)
        if (REG07GL__V==OFF and CHAN_MODEW==0){ 
            STEP07= 5; DON802___V=0;
        }

        //  �᫨ ॣ���� � ����� ०��� � ����祭 ��騩 ॣ����
        //  � ������ ��宣� ����㦥�- ��३� �� 蠣 �������� �� ���ண�
        //  (�� ࠡ�� ��饣� ॣ���� ०�� ����㧪�-���㧪� �� �㦥�
        //   ���㧪� ������ ���ண� ��稭����� �ࠧ� ��᫥ ����� ���ண�)
        if (REG07GL__V==ON and RegPublicV==ON and 
            DON802___V==0  and DON801___V >0  and DON801___V<2){ 
            // ����� ����������⭮ (��室�)
            if (CHAN_MODEW==0){ STEP07= 5; }
            // ����� �ᥣ� ����� (���� �஬뢪�)
            else              { STEP07= 2; }     
        }

        // ���㫥��� �⮡ࠦ���� ⥪�饣� ��� ������ �� �����
        if((REG07GL__V==OFF and REG07ZV__V==ON) or DON802___V==0){
            CRVODP___V=0;
            CRVODD___V=0;
            CRVODV___V=0;
            CROTH____V=0;
            CRSLM____V=0;
            AIW230FV_V=0;
            AIW230NV_V=AIW230___V;           // ��砫�� ��� ������ ���ண�
            AIW230VD_V=AIW230___V;           // ��砫�� ��� ������ ���ண�
            KRSLM____M=AIW230VD_V-KRVODD___V;// ��� 諠�� � ������
            KRSLM____V=KRSLM____M;
        }
        return;
    }
    //-----------------------------------------------------------------------


    //  ��������� ���� ��������
    //-----------------------------------------------------------------------
    //  ����⨥ ������� ����� �஬뢮筮� ���� � �஢�ઠ �����
    if (STEP07== 2 ){
        if(STEP07P!=2){
           Regul_07off();                   // �� �ᯮ���� � ��室 ���ﭨ�
           Clear_TO(71);                    // ���㫨�� ⠩��� 71
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
           AIW230NV_V=AIW230___V;           // ⥪�騩 ��� ������
           AIW230VD_V=AIW230___V;           // ��砫�� ��� ������ ���ண�
           TMST_VDP_C=0;                    // ���㫨�� ���稪 �६��� �⠡��
           VSST_VDP_C=0;                    // ���㫨�� ���稪 ��� �⠡��
        }; STEP07P =2;
        REG07SW__V =21;

        // �᫨ ����� 蠣 �믮������ � ������� ����(��㧨� �� �����)-
        // ����� ���४�஢�� �� 諠��
        // �᫨ ��㧨� ����������⭮, ����� ��������� �㤥� ���쨬
        // (1-��室�,2-諠�,3-���� �஬뢪�,4-���� �������)-
        // ���४�஢�� �� 諠�� ������ �� ���� ��᫥ ����㧪� 諠�� 
        // ���४�� �� 諠�� ��������
        AIW230VO_V = TRVODP_VIB+KRSLM____V-VSOT_VDP_W;
        AIW230VZ_V = TRVODP_VIB+KRSLM____V;
        AIW230VB_V = TRVODP_VIB+KRSLM____V+BLVODP___V;

        // ��᫥ ����㧪� �஬뢮筮� ���� ���㫨�� ���४�� �� ����,
        // ����� �ᯮ������ �� ����㧪� ��室�� � 諠��, �᫨ ���
        // ������� ���묨 (����㧪� ����������⭮)
        KRVODD___M=0; KRVODD___V=0;

        // �᫨ �� ��࠭ ����� ���� �஬뢪�
        if(FNVODP___V==OFF){ STEP07=3; return; }

        // �஢���� ��� ������:
        // �᫨ ���ࠫ� ��� ���� �஬뢪�- ��३� �� ᫥� 蠣
        if(AIW230___V > AIW230VO_V){ DON232___V=OFF; STEP07=3; return; }

        CRVODP___V=AIW230___V-AIW230NV_V;
        AIW230FV_V=2;

        if(RegRUN==OFF){ return; }

        // �᫨ ����� ������ ���� �஬뢪�-㢥����� ���稪 ⥪�饣� �६���
        if(DIS232___V==ON){ TMST_VDP_C++; }
        // �᫨ ���稪 ����� ���������
        if(TMST_VDP_C>TMST_VDP_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_VDP_W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_VDP_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������ ����� �஬뢮筮� ���� � ��३� �� ᫥� 蠣
              if(VSST_VDP_C>2){ DON232___V=OFF; STEP07=3; return; }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_VDP_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_VDP_C=0;
        }

        // ������ ������ ���� �஬뢪�
        REG07SW__V = 20;
        DON232___V = ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS232___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� ������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(305); Message(677); REG07R___M=OFF;
                           break;; 
                        }
                        // �᫨ ������ �� ������- ��।����� ���
                        Isp07PD(&DON232___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }
        Clear_TO(71);
        return;
    }
    //-----------------------------------------------------------------------

    // �������� �������� ������� ���� �������� � �⠡�����樨 ��� ������
    //-----------------------------------------------------------------------
    if (STEP07== 3){
        if(STEP07P!=3){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);
           CNST_VDP_C=0;                    // ���㫨�� ���稪 �஢�ப �⠡��
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =3;
        Regul_07off();                      // ������� �� ������� ॣ����
        REG07SW__V =31;

        if(RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� �஬뢮筮� ����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS232___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� �������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(306); Message(677);
                           REG07R___M=OFF; return;; 
                        }
                        // �᫨ ������ �� �������- ��।����� ���
                        Isp07PD(&DON232___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
        }

        //  ����� �६� �⠡�����樨 ���
        REG07SW__V =32;
        switch ( Check_TO  (72, TMST_VDP_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { return;; }
            case BAD: { break;;  }
        }
        Clear_TO(71);
        Clear_TO(72);

        //  �஢�ઠ ��� �⠡�����樨 ����� ���� �஬뢪�:
        //  �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        //  ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW230___O+VSST_VDP_W<AIW230___V){
           CNST_VDP_C++;
           //  �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           //  ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_VDP_C>CNST_VDP_W){
              Bell(1); Message(308); Message(677); REG07R___M=OFF; return;
           } else {
           //  �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           //  � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON232___V=ON;  AIW230___O=AIW230___V; return;
           }
        }

        if(AIW230FV_V==2){ CRVODP___V=AIW230___V-AIW230NV_V; }

        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            STEP07      = 21;      // ���室 �� 蠣 ����஢�� ᫥� ���������
            return;
        }
        //  �᫨ ��࠭� ����஢�� ��� ��������⮢ �ࠧ�
            STEP07      = 5;       // ���室 �� 蠣 ����஢�� ᫥� ���������
            return;
    }
    //-----------------------------------------------------------------------



    // ��������� �������
    //-----------------------------------------------------------------------
    // ����⨥ �������� ����� ��室��
    if (STEP07== 5 ){
        if(STEP07P!=5){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
           AIW230NV_V = AIW230___V;         // ��������� ⥪�騩 ��� ������
           Regul_07off();                   // ������� �� �������
        }; STEP07P =5;
        REG07SW__V =51;
        KROTH____F =0;                      // 䫠� ���� ���� ����� ��室��

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮(����� ��ࢮ�� ���������)
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+KRVODD___V-VSOT_OTH_W;
            AIW230VZ_V = TROTH__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+KRVODD___V+BLOTH____V;
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB-VSOT_OTH_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+BLVODP___V;
        }

        // �᫨ �� ��࠭ ����� ��室��
        if(FNOTH____V==OFF){ STEP07=12; return; }

        //  �஢���� ��� ����� ��室��:
        //  �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW230___V > AIW230VO_V){ Regul_07off(); STEP07=12; return; }

        //  �᫨ ��室� �� ��筮� �ࠢ�����- ��३� �� ����� 諠��
        if(DIR210___V== MANUAL    ){ Regul_07off(); STEP07=12; return; }

        //  ��� ���࠭��� ��室��
        CROTH____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=5;

        if(RegRUN==OFF){ return; }

        //  ���� �������� �� ����⨥ �������� ����஢�� ��室��
        DON211___V = ON;
        DON212___V = ON;
        // �஢���� ����⨥ ������� ����஢�� ��室�� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS212___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� ������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(309); Message(677); 
                           REG07R___M=OFF; return;; 
                        }
                        // �᫨ ������ �� ������- ��।����� ���
                        Isp07PD(&DON212___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }

        // �஢���� ����⨥ ������� ����஢�� ��室�� �����
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS211___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� ������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(310); Message(677);
                           REG07R___M=OFF; return;; 
                        }
                        // �᫨ ������ �� ������- ��।����� ���
                        Isp07PD(&DON211___V,3,TIME_ISPPW,70, STEP07P, 72); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }
        Clear_TO(71);                       // ���㫨�� ⠩����
        Clear_TO(72);                       //
        STEP07 = 6; 
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ����� ��室��
    //-----------------------------------------------------------------------
    if (STEP07== 6 ){
        if(STEP07P!=6){
           TMST_OTH_C=0;                    // ���稪 �६��� �஢�ப
           VSST_OTH_C=0;                    // ���稪 �஢�ப ���
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =6;
        REG07SW__V =61;

        // ��।����� ��� ���窨, ������� � �����஢��
        // �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+KRVODD___V-VSOT_OTH_W;
            AIW230VZ_V = TROTH__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+KRVODD___V+BLOTH____V;
        } else {
        // �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB-VSOT_OTH_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+BLOTH____V;
        }

        // �᫨ ��� ᤮��஢����� ��室�� ����� ��� ࠢ�� ��������� �����
        // ��� ���窨- ������� ������� ॣ���� � �� ᫥� 蠣
        if (AIW230___V>= AIW230VO_V){ Regul_07off(); STEP07=7; return; }

        // ��� ���࠭��� ��室�� 
        CROTH____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=6;

        if (RegRUN==OFF){ return; }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� ��室��
           TMST_OTH_C++;
        if(TMST_OTH_C>TMST_OTH_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_OTH_W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_OTH_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������� ॣ����, ������, ᮮ�饭�� �
              // ��३� �� ᫥� 蠣
              if(VSST_OTH_C>2){ 
                 Bell(1);
                 if(DIL210___V==ON){ Message(215); }
                 else              { Message(216); }
                 Regul_07off(); STEP07=7; return; 
              }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_OTH_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_OTH_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ������������ ����� ��室�� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07== 7 ){
        if(STEP07P!=7){
           CNST_OTH_C=0;                    // ���稪 �஢�ப �⠡�����樨
           TMST_OTH_C=0;                    // ���稪 �६���  �⠡�����樨 
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =7;
        Regul_07off();                      // ������� �� ������� ॣ����
        REG07SW__V =71;

        if(RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� ����� ��室�� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS212___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� �������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(311); Message(677); 
                           REG07R___M=OFF; return;; 
                        }
                        // �᫨ ������ �� �������- ��।����� ���
                        Isp07PD(&DON212___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
        }

        // �஢���� �����⨥ ������� ����� ��室�� �����
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS211___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        // �᫨ ��᫥ ��।�ࣨ����� ������ �� �������-
                        // ᮮ�饭��, ������, �몫���� ॣ����
                        if(DONCN07>2){ 
                           Bell(1); Message(312); Message(677); 
                           REG07R___M=OFF; return;; 
                        }
                        // �᫨ ������ �� �������- ��।����� ���
                        Isp07PD(&DON211___V,3,TIME_ISPPW,70, STEP07P, 72); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
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
        if(AIW230___O+VSST_OTH_W<AIW230___V){
           CNST_OTH_C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           // ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_OTH_C>CNST_OTH_W){
              Bell(1); Message(313); Message(677); REG07R___M=OFF; return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
             DON211___V=ON; DON212___V=ON; AIW230___O=AIW230___V; return;
           }
        }

        //  �᫨ ⥪�騩 ��� ����� �楯⭮�� ���� ��� ����᪠ �
        //  ����� ��� �����஢��
        if (AIW230___V>=AIW230VZ_V+DPOTH____V and AIW230___V<=AIW230VB_V){
            // ��⠭����� 䫠� ���४�஢�� ���� ��� ��室��
            KROTH____F=1;
            // ᮮ�饭�� � ���४�஢�� ���� � ������
            Message(149); Bell(1);
        }

        //  �᫨ ⥪�騩 ��� ����� ��� �����஢��- �몫���� ॣ����
        if (AIW230___V>AIW230VB_V){ 
            Message(397); Message(677); REG07R___M=OFF; 
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
           Clear_TO(71);                    // ���㫥��� ⠩��஢
           Clear_TO(72);                    //
           if(AIW230FV_V==5||AIW230FV_V==6){
              CROTH____V=AIW230___V-AIW230NV_V;
           }
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
           AIW230NV_V = AIW230___V;         // ��������� ⥪�騩 ��� ������
           Regul_07off();                   // ������� �� �������
        }; STEP07P =12;
        REG07SW__V =121;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+KRVODD___V-VSOT_SLG_W;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+KRVODD___V+BLSLM____V;
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB-VSOT_SLG_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V;
        }

        // �᫨ �� ��࠭ ����� 諠��
        if(FNSLM____V==OFF){ STEP07=20; return; }

        //  �஢���� ��� ����� 諠�� �����:
        //  �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW230___V > AIW230VO_V){ Regul_07off(); STEP07=16; return; }

        CRSLM____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=12;

        if(RegRUN==OFF){ return; }

        //  ���� �������� �� ����⨥ ������� ����஢�� 諠�� ����� �������
        DON222___V = ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS222___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(314); Message(677); REG07R___M=OFF; 
                           return;; 
                        }
                        Isp07PD(&DON222___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }  
        //  ���� �������� �� ����⨥ ������� ����஢�� 諠�� ����� ��������
        DON221___V = ON;
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS221___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(315); Message(677); REG07R___M=OFF; 
                           return;; 
                        }
                        Isp07PD(&DON221___V,3,TIME_ISPPW,70, STEP07P, 72); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }  

        Clear_TO(71);
        Clear_TO(72);
        STEP07 = 14; 
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ������ 諠�� �����
    //-----------------------------------------------------------------------
    if (STEP07== 14 ){
        if(STEP07P!=14){
           VSST_SLG_C = 0;
           TMST_SLG_C = 0;
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07P =14;
        REG07SW__V =141;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+KRVODD___V-VSOT_SLG_W;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+KRVODD___V+BLSLM____V;
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB-VSOT_SLG_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V;
        }

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨
        if (AIW230___V >= AIW230VO_V){ Regul_07off(); STEP07=15; return; }

        CRSLM____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=14;

        if (RegRUN==OFF){ return; }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� 諠�� �����
           TMST_SLG_C++;
        if(TMST_SLG_C>TMST_SLG_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_SLG_W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_SLG_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������� ॣ����, ������, ᮮ�饭�� �
              // ��३� �� ᫥� 蠣
              if(VSST_SLG_C>2){ 
                 Bell(1);
                 if(DIL220___V==ON){ Message(217); }
                 else              { Message(218); }
                 Regul_07off(); STEP07=15; return; 
              }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_SLG_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_SLG_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ������������ ����� 諠�� ����� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07== 15 ){
        if(STEP07P!=15){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           Clear_TO(73);                    //
           TMST_SLG_C=0;                    //
           CNST_SL__C=0;
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =15;
        REG07SW__V =151;
        Regul_07off();                      // ������� �� ������� ॣ����

        if(AIW230FV_V==14){
           CRSLM____V=AIW230___V-AIW230NV_V; 
        }

        if (RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� ����� 諠�� ����� �������
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS222___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(316); Message(677); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON222___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        // �஢���� �����⨥ ������� ����� 諠�� ����� ��������
        switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS221___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(317); Message(677); REG07R___M=OFF; 
                           return;; 
                        }
                        Isp07PD(&DON221___V,3,TIME_ISPPW,70, STEP07P, 72); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG07SW__V =152;
        switch ( Check_TO  (73, TMST_SLG_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_SLG_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);
        Clear_TO(73);

        // �஢�ઠ ��� �⠡�����樨:
        // �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        // ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW230___O+VSST_SLG_W<AIW230___V){
           CNST_SL__C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           // ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_SL__C>CNST_SL__W){
              Bell(1); Message(148); Message(677); REG07R___M=OFF; return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON221___V=ON; DON222___V=ON; AIW230___O=AIW230___V; return;
           }
        }

        STEP07 = 16;
        return;
    }
    //-----------------------------------------------------------------------


    // ����� ���� ����� �����
    //-----------------------------------------------------------------------
    // ����⨥ ������� ����� 諠�� �����
    if (STEP07== 16 ){
        if(STEP07P!=16){
           Clear_TO(71);                    // ���㫨�� ⠩���
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
           Regul_07off();                   // ������� �� �������
        }; STEP07P =16;
        REG07SW__V =161;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+KRVODD___V-VSOT_SLT_W;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+KRVODD___V+BLSLM____V;
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V;
        }

        //  �஢���� ��� ����� 諠�� �����:
        //  �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW230___V > AIW230VO_V){ Regul_07off(); STEP07=18; return; }

        CRSLM____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=16;

        if(RegRUN==OFF){ return; }

        //  ���� �������� �� ����⨥ ������� ����஢�� 諠�� �����
        DON223___V=ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS223___V,'=',ON, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(318); Message(677); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON223___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }
        Clear_TO(71);

        STEP07=17;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ���� ����� 諠�� �����
    //-----------------------------------------------------------------------
    if (STEP07==17){
        if(STEP07P!=17){
           VSST_SLT_C = 0;
           TMST_SLT_C = 0;
           AIW230___O = AIW230___V;
        }; STEP07P =17;
        REG07SW__V =171;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+KRVODD___V-VSOT_SLT_W;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+KRVODD___V+BLSLM____V;
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB-VSOT_SLT_W;
            AIW230VZ_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB;
            AIW230VB_V = TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V;
        }

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨
        if (AIW230___V >= AIW230VO_V){ Regul_07off(); STEP07=18; return; }

        CRSLM____V=AIW230___V-AIW230NV_V;
        AIW230FV_V=17;

        if (RegRUN==OFF){ return; }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� 諠�� �����
           TMST_SLT_C++;
        if(TMST_SLT_C>TMST_SLT_W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_SLT_W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_SLT_C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������� ॣ����, ᮮ�饭��, ������ �
              // �몫���� ॣ����
              if(VSST_SLT_C>2){ 
                 Bell(1); Message(307); Message(677); Regul_07off(); 
                 REG07R___M=OFF; return;
              }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_SLT_C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_SLT_C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------

    // �������� �������� ������� ����� 諠�� ����� � �६��� �⠡�����樨
    //-----------------------------------------------------------------------
    if (STEP07== 18 ){
        if(STEP07P!=18){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           TMST_SLT_C=0;                    //
           CNST_SL__C=0;
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =18;
        REG07SW__V =181;
        Regul_07off();                      // ������� �� ������� ॣ����

        if(AIW230FV_V>=14 and AIW230FV_V<=17){
           CRSLM____V=AIW230___V-AIW230NV_V;
        }

        if (RegRUN==OFF){ return; }

        // �஢���� �����⨥ ������� ����� 諠�� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS223___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(319); Message(677); REG07R___M=OFF; 
                           return;; 
                        }
                        Isp07PD(&DON223___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG07SW__V =182;
        switch ( Check_TO  (72, TMST_SLT_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_SLT_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);

        // �஢�ઠ ��� �⠡�����樨:
        // �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        // ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW230___O+VSST_SLT_W<AIW230___V){
           CNST_SL__C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           // ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_SL__C>CNST_SL__W){
              Bell(1); Message(148); Message(677); REG07R___M=OFF; return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON223___V=ON; AIW230___O=AIW230___V; return;
           }
        }

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ���� ��� ����᪠ �
        // ����� ��� �����஢��
        if (AIW230___V>=AIW230VZ_V+DPSLM____V and AIW230___V<=AIW230VB_V){
            // ��⠭����� 䫠� ���४�஢�� ���� ��� 諠��
            KRSLM____F=1;
            // ᮮ�饭�� � ���४�஢�� ���� � ������
            Message(163); Bell(1);
        }

        // �᫨ ⥪�騩 ��� ����� ��� �����஢��- �몫���� ॣ����
        if (AIW230___V>AIW230VB_V){ 
            Message(397); Message(677); REG07R___M=OFF; return; 
        }

        // �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            STEP07      = 52;      // ���室 �� ���㧪� ���࠭���� ���������
            STEP07_BACK = 20;      // ���室 �� 蠣 �� ������ � ���㧪�
            return;
        }
        // �᫨ ��࠭� ����஢�� ��� ��������⮢ �ࠧ�
            STEP07      = 20;      // ���室 �� 蠣 ����஢�� ᫥� ���������
            return;
    }
    //-----------------------------------------------------------------------


    // ����� ����� ������� ����
    //-----------------------------------------------------------------------
    if (STEP07== 20 ){
        if(STEP07P!=20){
           Clear_TO(71);                    // ���㫨�� ⠩���
           Regul_07off();                   // ������� �� �������
           TMWT_VODDC=0;                    // ����� ���稪 ����
        }; STEP07P =20;
        // ��⠭����� 䫠� ����� ��室��-諠�� (>0 <0.5)
        // ��ॢ������ � 1 ������ �� ᫨�� ���� � ������
        // �᫨ �� ᫨�� ���� � ������ ॣ���� �몫�稫��, � ���쭥�訩
        // ��� ����� �������� ⮫쪮 � �����쭮� ०��� ��� �� �몫�祭��-
        // ����祭�� ��饣� ॣ���� ��� �� �몫�祭�� ॣ���� ��४��-
        // 祭�� ���ﭨ� ��饣� ॣ���� (�����⨪ ᫥��-������ ������奬)
        DON802___V =0.2;
        // �६� ��������
        REG07SW__V =201;
        switch ( Check_TO  (71, TMWT_VODDW, ZERO,'=',ON, 1 )){
            case RUN: { TMWT_VODDC++; return;; }
        }
        Clear_TO(71);
        // ��᫥ ����㧪� ��室�� � 諠�� ���㫨�� ���४�� �� 諠��,
        // ����� �ᯮ������ �� ����㧪� �஬뢮筮� ����, �᫨ ���
        // ��㧨��� ���� ��������⮬
        KRSLM____M=0; KRSLM____V=0;
        // �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            STEP07= 2;                      // ��३� �� ����� ���� �஬뢪�
            return;
        }
        // �᫨ ��࠭� ����஢�� ��� ��������⮢ �ࠧ�
            STEP07= 21;                     // ��३� �� ����� ���� �������
            return;
    }
    //-----------------------------------------------------------------------
    // �� �⮣� 蠣� ���४�� �� ���� �ᯮ�짮������ ��� ��।������
    // ���⪠ � ������ ���ண� �� ���� � ��室�-諠�
    // ������ ���४�� �� ���� �㤥� �ᯮ�짮������ ������ ��� ���쭥�襣�
    // ����� ���� (��᫥ ����� �� ���४�஢�� ����)
    if (STEP07== 21 ){
        if(STEP07P!=21){
           KROTH____M=0, KROTH____V=0;      // ���㫨�� ���४樨 �� ���஬�
           KRSLM____M=0, KRSLM____V=0;
           KRVODP___M=0, KRVODP___V=0;
           KRVODD___M=0, KRVODD___V=0;
           Regul_07off();
           Clear_TO(71);
           REG07ZO1_F=0;
           REG07ZO1_W=OFF;
        }; STEP07P =21;
        REG07SW__V =211;

        // �᫨ ��⠭����� ���� �� 䫠��� ���४�஢�� ����-
        // �뢥�� ������� ����� � ���४�஢�� ���� � ������� 
        // ���⢥ত����: "������ ���४�� �� ����. �த������? (��/���)"
        // �- �����  ����� ���� � ��⮬ ����� ������� ���४ REG07ZO1_W=1
        // ��㣠� ������ (OTHER)                              REG07ZO1_W=3
        if(KRCEM____F>0 or KRVYG____F>0 or KROTH____F>0 or KRSLM____F>0){
           // �뤠�� ����� ������� (���祭�� REQ � ��६����� ������)
           if(REG07ZO1_F==0    ){ REG07ZO1_W=REQ; REG07ZO1_F=1; return; }
           // �᫨ ��᫥���� ������ ������ �� ��㣠� (� ������ ��砥 ESC)
           // �஬� ��������� (�/�)- ������� 30 ᥪ ��� �뤠� ����� �����
           REG07SW__V =212;
           if(REG07ZO1_W==OTHER){
              switch ( Check_TO (71,30*SEC, REG07ZO1_W,'=', YES, 2)){
                  case RUN: { return;; }
                  case BAD: { REG07ZO1_W=REQ; Bell(1); Clear_TO(71); return;; }
              }
           }
           REG07SW__V =213;
           if(REG07ZO1_W!=YES){ return; }
        }
        // ���㫨�� 䫠�� ���४樨 ����
        KRCEM____F=0;                       
        KRVYG____F=0;
        KROTH____F=0;                       
        KRSLM____F=0;

        Clear_TO(71);
        STEP07=22;
        return;
    }
    //-----------------------------------------------------------------------



    // ����� ���� ������� ����� (����� �⮣� ��������� �믮������ ��᫥����)
    //-----------------------------------------------------------------------
    if (STEP07== 22 ){
        if(STEP07P!=22){
           Clear_TO(71);                    // ���㫨�� ⠩���
           Regul_07off();                   // ������� �� �������
           // �᫨ ��। �⨬ 蠣�� ����ࠫ� 諠�- ��������� ��� 諠��
           if(AIW230FV_V>=14 and AIW230FV_V<=17){
              CRSLM____V=AIW230___V-AIW230NV_V;
           }
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
           AIW230NV_V = AIW230___V;         // ��������� ⥪�騩 ��� ������
           // �᫨ ���� �஬뢪� �� �ࠫ�- ��������� ��砫�� ��� ������
           if(FNSLMVOD_V==ON and CHAN_MODEW==0 and FNVODP___V==OFF){
              AIW230VD_V=AIW230___V;
           }
        }; STEP07P =22;
        REG07SW__V =221;

        // ��।����� ��� ���窨, ������� � �����஢��
        // �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
            AIW230VZ_V = TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TRVODD_VIB+KRVODD___V+BLVODD___V;
            // �᫨ ��⠭����� 䫠� ����� ��� ���⪠ + ���� �������
            if(FNSLMVOD_V==ON){
               AIW230VO_V = AIW230VD_V+TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
               AIW230VZ_V = AIW230VD_V+TRVODD_VIB+KRVODD___V;
               AIW230VB_V = AIW230VD_V+TRVODD_VIB+KRVODD___V+BLVODD___V;
            }
        } else {
        // �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V+BLVODD___V;
        }

        // �᫨ �� ��࠭ ����� ���� �������
        if(FNVODD___V==OFF){ STEP07=30; return; }

        // �஢���� ��� ����� ���� ������� �����:
        // �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW230___V > AIW230VO_V){ 
           Regul_07off(); STEP07=25; return; 
        }

        CRVODV___V=AIW230___V-AIW230NV_V;
        CRVODD___V=CRVODP___V+CRVODV___V;
        AIW230FV_V=22;

        if(RegRUN==OFF){ return; }

        // ���� �������� �� ����⨥ ������� ����஢�� ���� �����
        DON202___V=ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS202___V,'=',ON, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(151); Message(677); REG07R___M=OFF; 
                           return;; 
                        }
                        Isp07PD(&DON202___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }
        Clear_TO(71);

        STEP07=23;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ���� ������ ���� ������� ����� 
    //-----------------------------------------------------------------------
    if (STEP07==23){
        if(STEP07P!=23){
           TMST_VD__C = 0;
           VSST_VD__C = 0;
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07P =23;
        REG07SW__V =231;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
            AIW230VZ_V = TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TRVODD_VIB+KRVODD___V+BLVODD___V;
            // �᫨ ��⠭����� 䫠� ����� ��� ���⪠ + ���� �������
            if(FNSLMVOD_V==ON){
               AIW230VO_V = AIW230VD_V+TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
               AIW230VZ_V = AIW230VD_V+TRVODD_VIB+KRVODD___V;
               AIW230VB_V = AIW230VD_V+TRVODD_VIB+KRVODD___V+BLVODD___V;
            }
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V-VSOT_VDDGW;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V+BLVODD___V;
        }

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨
        if (AIW230___V >= AIW230VO_V){ Regul_07off(); STEP07=24; return; }
        // �᫨ ⥪�騩 ��� ����� �楯⭮��
        DON202___V=ON;

        CRVODV___V=AIW230___V-AIW230NV_V;
        CRVODD___V=CRVODP___V+CRVODV___V;
        AIW230FV_V=23;

        if (RegRUN==OFF){ return; }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� ���� �����
           TMST_VD__C++;
        if(TMST_VD__C>TMST_VD__W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_VD__W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_VD__C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������� ॣ����, ᮮ�饭��, ������ �
              // �몫���� ॣ����
              if(VSST_VD__C>2){ 
                 Bell(1); Message(152); Message(677); Regul_07off(); 
                 REG07R___M=OFF; return;
              }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_VD__C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_VD__C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------

    // �������� �������� ������� ����� ���� ������� ����� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07== 24 ){
        if(STEP07P!=24){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           TMST_VD__C=0;                    //
           CNST_VDD_C=0;
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =24;
        REG07SW__V =241;
        Regul_07off();                      // ������� �� ������� ॣ����

        if(AIW230FV_V==22||AIW230FV_V==23){
           CRVODV___V=AIW230___V-AIW230NV_V;
           CRVODD___V=CRVODP___V+CRVODV___V;
           AIW230FV_V=24;
        }

        if (RegRUN==OFF){ return; }

        //  �஢���� �����⨥ ������� ����� ���� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS202___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(153); Message(677); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON202___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
        }

        //  ����� �६� �⠡�����樨 ���
        REG07SW__V =242;
        switch ( Check_TO  (72, TMST_VD__W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VD__C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);

        //  �஢�ઠ ��� �⠡�����樨:
        //  �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        //  ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW230___O+VSST_VD__W<AIW230___V){
           CNST_VDD_C++;
           //  �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           //  ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_VDD_C>CNST_VDD_W){
              Bell(1); Message(154); Message(677); REG07R___M=OFF; return;
           } else {
           //  �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           //  � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON202___V=ON; AIW230___O=AIW230___V; return;
           }
        }
        STEP07 = 25;
        return;
    }
    //-----------------------------------------------------------------------

    // ����� ���� ���� ������� �����
    //-----------------------------------------------------------------------
    if (STEP07== 25 ){
        if(STEP07P!=25){
           Clear_TO(71);                    // ���㫨�� ⠩���
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
           Regul_07off();                   // ������� �� �������
        }; STEP07P =25;
        REG07SW__V =251;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
            AIW230VZ_V = TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TRVODD_VIB+KRVODD___V+BLVODD___V;
            // �᫨ ��⠭����� 䫠� ����� ��� ���⪠ + ���� �������
            if(FNSLMVOD_V==ON){
               AIW230VO_V = AIW230VD_V+TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
               AIW230VZ_V = AIW230VD_V+TRVODD_VIB+KRVODD___V;
               AIW230VB_V = AIW230VD_V+TRVODD_VIB+KRVODD___V+BLVODD___V;
            }
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V+BLVODD___V;
        }

        //  �஢���� ��� ����� ���� ������� �����:
        //  �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW230___V > AIW230VO_V){ Regul_07off(); STEP07=30; return; }

        CRVODV___V=AIW230___V-AIW230NV_V;
        CRVODD___V=CRVODP___V+CRVODV___V;
        AIW230FV_V=25;

        if(RegRUN==OFF){ return; }

        //  ���� �������� �� ����⨥ ������� ����஢�� ���� �����
        DON203___V=ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS203___V,'=',ON, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(155); Message(677); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON203___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        }
        Clear_TO(71);

        STEP07=26;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ���� ������ ���� ������� �����
    //-----------------------------------------------------------------------
    if (STEP07==26){
        if(STEP07P!=26){
           TMST_VD__C = 0;
           VSST_VD__C = 0;
           AIW230___O = AIW230___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07P =26;
        REG07SW__V =261;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            AIW230VO_V = TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
            AIW230VZ_V = TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TRVODD_VIB+KRVODD___V+BLVODD___V;
            // �᫨ ��⠭����� 䫠� ����� ��� ���⪠ + ���� �������
            if(FNSLMVOD_V==ON){
               AIW230VO_V = AIW230VD_V+TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
               AIW230VZ_V = AIW230VD_V+TRVODD_VIB+KRVODD___V;
               AIW230VB_V = AIW230VD_V+TRVODD_VIB+KRVODD___V+BLVODD___V;
            }
        } else {
        //  �᫨ ��࠭� ����஢�� �ᥣ� �����
            AIW230VO_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V-VSOT_VDDTW;
            AIW230VZ_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V;
            AIW230VB_V = TROTH__VIB+TRSLM__VIB+TRVODD_VIB+KRVODD___V+BLVODD___V;
        }

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨
        if (AIW230___V >= AIW230VO_V){ Regul_07off(); STEP07=27; return; }

        CRVODV___V=AIW230___V-AIW230NV_V;
        CRVODD___V=CRVODP___V+CRVODV___V;
        AIW230FV_V=26;

        if (RegRUN==OFF){ return; }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� ���� �����
           TMST_VD__C++;
        if(TMST_VD__C>TMST_VD__W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW230___O+VSST_VD__W>AIW230___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_VD__C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              // (2-� �஢�ન ����� ��� ����� ���)-
              // ������� ������� ॣ����, ᮮ�饭��, ������ �
              // �몫���� ॣ����
              if(VSST_VD__C>2){ 
                 Bell(1); Message(156); Message(677); Regul_07off();
                 REG07R___M=OFF; return;
              }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_VD__C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW230___O=AIW230___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_VD__C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------

    // �������� �������� ������� ����� ���� ������� ����� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07== 27 ){
        if(STEP07P!=27){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);                    //
           TMST_VD__C=0;                    //
           CNST_VDD_C=0;
           AIW230___O=AIW230___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07P =27;
        REG07SW__V =271;
        Regul_07off();                      // ������� �� ������� ॣ����

        // ��� ����� ����
        if(AIW230FV_V>=22||AIW230FV_V<=26){
           CRVODV___V=AIW230___V-AIW230NV_V;
           CRVODD___V=CRVODP___V+CRVODV___V;
        }

        if (RegRUN==OFF){ return; }

        // ���㫨�� ���४�� �� ����
        KRVODD___M=0; KRVODD___V=0;

        // �஢���� �����⨥ ������� ����� ���� �����
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS203___V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Message(157); Message(677); Bell(1); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON203___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; AIW230___O=AIW230___V; break;; }
        }

        //  ����� �६� �⠡�����樨 ���
        REG07SW__V =272;
        switch ( Check_TO  (72, TMST_VD__W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VD__C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(71);
        Clear_TO(72);

        //  �஢�ઠ ��� �⠡�����樨:
        //  �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        //  ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW230___O+VSST_VD__W<AIW230___V){
           CNST_VDD_C++;
           //  �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           //  ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_VDD_C>CNST_VDD_W){
              Bell(1); Message(158); Message(677); REG07R___M=OFF; return;
           } else {
           //  �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           //  � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON203___V=ON; AIW230___O=AIW230___V; return;
           }
        }

        // �᫨ ��࠭� ����஢�� ����������⭮
        if (CHAN_MODEW==0){ 
            STEP07      = 52;      // ���室 �� ���㧪� ���࠭���� ���������
            STEP07_BACK = 30;      // ���室 �� 蠣 �� ������ � ���㧪�
        } else {
        // �᫨ ��࠭� ����஢�� ��� ��������⮢ �ࠧ�
            STEP07      = 30;      // ���室 �� 蠣 ����஢�� ᫥� ���������
        }

        return;
    }
    //-----------------------------------------------------------------------


    // ����������� ��������
    //-----------------------------------------------------------------------
    if (STEP07== 30 ){
        if(STEP07P!=30){
           ;;
        }; STEP07P =30;
        Regul_07off();                      // ������� �� ������� ॣ����

        if (RegRUN==OFF){ return; }

        // �᫨ ��࠭� ����஢�� ��� ��������⮢
        if (CHAN_MODEW!=0){ 
           // �६� ���� ����� ����㧪�� � ���㧪��
           switch ( Check_TO  (71, TMPZ_ZGR_W*SEC, ZERO,'=',ON, 1 )){
               case RUN: return;;
           };  Clear_TO(71);
        }

        // ��⠭����� 䫠�� ����� ��������⮢
        FNOTH____V = ON;
        FNSLM____V = ON;
        FNVODP___V = ON;
        FNVODD___V = ON;

        // �᫨ ॣ���� � ��饬 ०���
        if(RegPublicV==ON and REG07GL__V==ON){
           // �᫨ ����ࠫ� �� �����- ���室 �� ���㧪�
           if(CHAN_MODEW!=0){ STEP07 = 31; }
           // �᫨ ���ࠫ� ����������⭮- ���室 �� ��砫� �஢�ப
           // ���ﭨ� ॣ���� � ��।������ ०��� ����㧪�-���㧪�
           else             { STEP07 = 0; DON802___V=1; }
        } else {
        // �᫨ ॣ���� � �����쭮� ०���- �몫���� ॣ����
           Message(484);  Message(677); REG07R___M=OFF;
           DON802___V=1; 
           STEP07 = 0; 
        }
        return;
    }
    //-----------------------------------------------------------------------


    //  ����� ����� ��������� � ��������� ������ ���ண� �� ����� ���
    //  ��������⮢ �����
    //-----------------------------------------------------------------------
    if (STEP07== 31 ){
        if(STEP07P!=31){
           Clear_TO(71);
        }; STEP07P =31;
        Regul_07off();                      // ������� �� ������� ॣ����

        if (RegRUN==OFF){ return; }

        switch ( Check_TO  (71, TMPZ_ZGR_W*SEC, ZERO,'=',ON,  1 )){
            case RUN: { return;; }
        };  Clear_TO(71);

        STEP07=52;
        STEP07_BACK=0;
        return;
    }
    //-----------------------------------------------------------------------




    //  �������� �� �������� ������� � ����
    //-----------------------------------------------------------------------
    //  �஢�ઠ ��⮢���� ����:
    if (STEP07== 52 ){
        _f RUKAVA=OFF;
        if(STEP07P!=52){
           Clear_TO(71);                    // ���㫨�� ⠩����
           Clear_TO(72);
           Clear_TO(73);
           Clear_TO(74);
        }; STEP07P =52;
        Regul_07off();                      // ������� �� ������� ॣ����

        if (RegRUN==OFF){ return; }

        //  �᫨ ���� ��� �� ���� - ���
        REG07SW__V =521;
        switch ( Check_TO  (71, 1*MIN, DIS315___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(71); Message(385); Bell(1); return;; }
        };  Clear_TO(71);

        //  �᫨ ���� �� ����祭� - ���
        REG07SW__V =522;
        switch ( Check_TO  (72, 1*MIN, DIS310___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(72); Message(386); Bell(1); return;; }
        };  Clear_TO(72);

        //  �᫨ ��ଥ⨧��� �� ���饭 - ���
        REG07SW__V =523;
        switch ( Check_TO  (73, 1*MIN, DIS31A___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(73); Message(387); Bell(1); return;; }
        }

        //  �᫨ �㪠�� �� ������� - ���
        REG07SW__V =524;
        if(DIS316___V==ON or DIS317___V==ON){ RUKAVA=ON; }
        switch ( Check_TO  (74, 1*MIN, RUKAVA,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(74); Message(295); Bell(1); return;; }
        }

        Clear_TO(71);                       // ���㫨�� ⠩����
        Clear_TO(72);
        Clear_TO(73);
        Clear_TO(74);
        STEP07 = 53;

        return;
    }
    //-----------------------------------------------------------------------

    // �������� ������� �������� � ����
    //-----------------------------------------------------------------------
    if (STEP07== 53 ){
        if(STEP07P!=53){
           // �᫨ ��। �⨬ 蠣�� ����ࠫ� 諠�- ��������� ��� 諠��
           if(AIW230FV_V>=14 and AIW230FV_V<=17){
              CRSLM____V=AIW230___V-AIW230NV_V;
           }
           Regul_07off();
        }; STEP07P =53;

        if (RegRUN==OFF){ return; }

        //  ������ ������ ���㧪� � ����
        REG07SW__V =531;
        DON231___V = ON;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS231___V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(159); Message(677); REG07R___M=OFF;
                           return;; 
                        }
                        Isp07PD(&DON231___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        MK_VG_KL_OPEN=0; 
        AIW230___O = AIW230___V;
        STEP07 = 54;
        return;
    }
    //-----------------------------------------------------------------------

    // �������� ���� �������� ������ ���ண�
    //-----------------------------------------------------------------------
    if (STEP07== 54 ){
        if(STEP07P!=54){
           AIW230___O=AIW230___V;
           VSST_MKVIC=0;
           TMST_MKVIC=0;
           CNST_MKVIC=0;
        }; STEP07P =54;
        REG07SW__V =541;

        //  �᫨ ⥪�騩 ��� ������ ����� ��� ࠢ�� ���-
        //  ��३� �� ᫥� 蠣
        if (AIW230___V<=0 or CNST_MKVIC>=CNST_MKVIW){ STEP07=55; return; }

        if(RegRUN==OFF){ return; }

        //  �᫨ ����諮 �६� �஢�ન �⠡�����樨 ��� ������ ���ண�
        TMST_MKVIC++;
        if (TMST_MKVIC>TMST_MKVIW){
            //  �᫨ ��� �⠡�����஢����- 㢥����� ���稪 �⠡������ ���
            if (AIW230___V+VSST_MKVIW>AIW230___O){ CNST_MKVIC++; }
            else                                 { CNST_MKVIC=0; }
            AIW230___O=AIW230___V; TMST_MKVIC=0;
        }
        return;
    }
    //-----------------------------------------------------------------------

    // �������������� ������� ��������
    //-----------------------------------------------------------------------
    if (STEP07== 55 ){
        if(STEP07P!=55){
           CNST_MKVIC=0;
        }; STEP07P =55;

        if (RegRUN==OFF){ return; }

        REG07SW__V =551;
        MK_VG_KL_OPEN++;

        if(DIS231___V ==ON & MK_VG_KL_OPEN%3==0){
           DON231___V = OFF;
           switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS231___V,'=',OFF, 1 )){
               case RUN: return;;
           };  Clear_TO(71);
        }

        if(DIS231___V ==OFF & MK_VG_KL_OPEN%3==0){
           DON231___V = ON;
           switch ( Check_TO  (72, TIME_ISPKV*SEC, DIS231___V,'=',ON, 1 )){
               case RUN: return;;
           };  Clear_TO(72);
        }

        if (MK_VG_KL_OPEN>7){ STEP07 = 56; }
        return;
    }
    //-----------------------------------------------------------------------

    // ������� ������ �������� �� ������ ���ண� � ����
    //-----------------------------------------------------------------------
    if (STEP07== 56 ){
        if(STEP07P!=56){
           ;;
        }; STEP07P =56;
        Regul_07off();                      // ������� �� ������� ॣ����

        if (RegRUN==OFF){ return; }

        REG07SW__V = 561;
        DON231___V = OFF;
        switch ( Check_TO  (71, TIME_ISPKV*SEC, DIS231___V,'=',OFF, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07>2){ 
                           Bell(1); Message(160); Message(677); REG07R___M=OFF;
                           return;;
                        }
                        Isp07PD(&DON231___V,3,TIME_ISPPW,70, STEP07P, 71); 
                        return;; 
                      }
            case END: { DONCN07=0; break;; }
        };  Clear_TO(71);

        //  �᫨ �� ����� ���㧪� ������ ���ண�- ����� 䫠� ��� ���ண�
        //  STEP07_BACK==0 - ��� ����� ��� ��������⮢ �����
        //  STEP07_BACK==30- ��� ����� ����������⭮
        if (STEP07_BACK==0 or STEP07_BACK==30){ 
            DON802___V=1;
            //  �᫨ ॣ���� � �����쭮� ०���- �몫���� ���
            if (REG07GL__V==OFF){ 
                Message(485); Message(677); REG07R___M= OFF; 
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


    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_07m();
    return;
}
//---------------------------------------------------------------------------
