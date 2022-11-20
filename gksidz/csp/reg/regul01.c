//---------------------------------------------------------------------------
//  �����窠 諠��

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f  far  DIH220___C=0;            // ���孨� �஢��� ��蠫�� 諠�� ��� ����஫�
_f  far *DONPR01;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i  far  DONCN01=0;               // ���稪 横�� ��।�ࣨ�����
_i  far  DONCH01=2;               // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i  far  DONTM01=2;               // ���-�� ᥪ㭤 ��� � ����

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
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_01off(vd){
    DON011___V =  OFF;
    DON012___V =  OFF;
    DON021___V =  OFF;
    DON022___V =  OFF;
    DON031___V =  OFF;
    DON032___V =  OFF;
    DON041___V =  OFF;
    DON042___V =  OFF;
    DON051___V =  OFF;
    DON052___V =  OFF;
    DONR01P1_V =  OFF;
    DONR01PK_V =  OFF;
    DONR01PKSV =  OFF;
    DONR01PKVV =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_01m(vd){
    //-----------------------------------------------------------------------
    if ( STEP01 == 101 ){
         REG01SW__V = 1001;
         // �᫨ �몫�稫� ॣ���� ���-� ���।���-
         // ᤥ���� ���㧪�, �த㢪� � �������� �� ��� �� 蠣
         if(STEP01P>1 and STEP01P<5 and DIRR01PN_V==AUTO){ 
            STEP01=4; STEP01_BACK=101;  REG01R___V =REG01R___M=ON;
            return; 
         }
         if(STEP01P==6 and DIRR01PN_V==AUTO){ 
            STEP01=15; STEP01_BACK=101; REG01R___M=OFF; 
            return; 
         }
         if(RegRUN==OFF){ return; }
         // �������� �� �����⨥ �������� � 諠�����ᥩ���
         DON032___V=OFF; DON042___V=OFF; DON052___V=OFF;
         switch ( Check_TO  (11, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         }
         // �������� �� �����⨥ �������� �� 諠�����ᥩ���
         // � �������� ����� 諠�� � ��.�����
         DON031___V=OFF; DON041___V=OFF; DON051___V=OFF;
         DON012___V=OFF; DON022___V=OFF;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         } 
         // �������� �� �����⨥ �������� ����� ������ � ��.�����
         DON011___V=OFF; DON021___V=OFF;
         switch ( Check_TO  (14, TIME_ISPKV*SEC, ZERO,'=',ON,  1 )){
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
         // ����ୠ� �������� �� �����⨥ ��� �ᯮ���⥫�� ॣ����
         Regul_01off();
         // ���㫥��� ���稪�� � ⠩��஢
         LOAD_SLCNC=0;
         COUN_SLDZC=COUN_SLDZW;
         STEP01 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 == 102 ){
         STEP01P = 102;
         REG01SW__V = 1002;
         REG01R___M = OFF;
         STEP01_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP01=101;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ��।������ ᮮ⢥��⢨� �室��-��室�� ��� ������� ��������ᥩ��
vd  far RegNSET(vd){
    if ( DIR031SETV == ON ){
         DIRR01___V =  DIR031SETV;               // ��࠭�� 諠�����ᥩ�
         DISR01P1_V =  DIS031___V;               // ������ �� ������
         DISR01PK_V =  DIS032___V;               // ��.������ ��
         DISR01MS_V =  DIS030___V;               // ��蠫�� ��
         DIHR01___V =  DIH030___V;               // ���孨� �஢��� ��
         DILR01___V =  DIL030___V;               // ������  �஢��� ��
         DIRR01PN_V =  DIR010___V;               // ���� �� ��.���� 
         DISR01PKSV =  DIS012___V;               // ��.������ 諠��   ��.����
         DISR01PKVV =  DIS011___V;               // ��.������ ������ ��.����
         DIHR01PN_V =  DIH010___V;               // �஢��� ��.����          

         DON031___V =  DONR01P1_V;               // ������ �  ��
         DON032___V =  DONR01PK_V;               // ������ �� ��       
         DON012___V =  DONR01PKSV;               // ������ 諠��   � ��.����
         DON011___V =  DONR01PKVV;               // ������ ������ � ��.����
         // �᫨ ��2 �� ��⮬��- �� ࠡ�⠥� ��ࠫ���쭮 ��3
         if(DIR041___V==ON){
            DON041___V =  DONR01P1_V;            //
            DON042___V =  DONR01PK_V;            //
         }
    }
    if ( DIR041SETV == ON ){
         DIRR01___V =  DIR041SETV;
         DISR01P1_V =  DIS041___V;
         DISR01PK_V =  DIS042___V;
         DISR01MS_V =  DIS040___V;
         DIHR01___V =  DIH040___V;
         DILR01___V =  DIL040___V;
         DIRR01PN_V =  DIR010___V;
         DISR01PKSV =  DIS012___V;
         DISR01PKVV =  DIS011___V;
         DIHR01PN_V =  DIH010___V;
         DON041___V =  DONR01P1_V;
         DON042___V =  DONR01PK_V;
         DON012___V =  DONR01PKSV;
         DON011___V =  DONR01PKVV;
         if(DIR031___V==ON){
            DON031___V =  DONR01P1_V;
            DON032___V =  DONR01PK_V;
         }
    }
    if ( DIR051SETV == ON ){
         DIRR01___V =  DIR051SETV;
         DISR01P1_V =  DIS051___V;
         DISR01PK_V =  DIS052___V;
         DISR01MS_V =  DIS050___V;
         DIHR01___V =  DIH050___V;
         DILR01___V =  DIL050___V;
         DIRR01PN_V =  DIR020___V;
         DISR01PKSV =  DIS022___V;
         DISR01PKVV =  DIS021___V;
         DIHR01PN_V =  DIH020___V;
         DON051___V =  DONR01P1_V;
         DON052___V =  DONR01PK_V;
         DON022___V =  DONR01PKSV;
         DON021___V =  DONR01PKVV;
    }
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  ��।����� ����� ⥪�饣� ��������ᥩ�� ��� �����窨 諠��
vd  far DefineSLBAS(vd){
    if (STEP01==0 or STEP01>100 or DSB>0){
       //  �᫨ ��࠭ ��3 � � ��� ��� ᨣ���� ���� �஢�� � ���� �� ��⮬��
       if (DIR031SETM == ON and DIL030___V == OFF and DIR031___V == AUTO){ 
           DIR031NEXV =  ON;
           DIR031SETV =  ON;
           DIR031SETM =  OFF;
           DIR041SETV =  DIR041SETM = OFF;
           DIR051SETV =  DIR051SETM = OFF;
           DIR041NEXV =  DIR051NEXV = OFF;
       }
       //  �᫨ ��࠭ ��2 � � ��� ��� ᨣ���� ���� �஢�� � ���� �� ��⮬��
       if (DIR041SETM == ON and DIL040___V == OFF and DIR041___V == AUTO){ 
           DIR031SETV =  DIR031SETM = OFF;
           DIR041NEXV =  ON;
           DIR041SETV =  ON;
           DIR041SETM =  OFF;
           DIR051SETV =  DIR051SETM = OFF;
           DIR031NEXV =  DIR051NEXV = OFF;
       }
       //  �᫨ ��࠭ ��1 � � ��� ��� ᨣ���� ���� �஢�� � ���� �� ��⮬��
       if (DIR051SETM == ON and DIL050___V == OFF and DIR051___V == AUTO){ 
           DIR031SETV =  DIR031SETM = OFF;
           DIR041SETV =  DIR041SETM = OFF;
           DIR051NEXV =  ON;
           DIR051SETV =  ON;
           DIR051SETM =  OFF; 
           DIR031NEXV =  DIR041NEXV = OFF;
       };  DSB=0;
    }
    //  �롮� ���������� ��� ᫥����� �����祪 諠��
    if (DIR031SETM == ON and DIL030___V == OFF and DIR031___V == AUTO){
        DIR031NEXV =  ON;    DIR041NEXV =  OFF;    DIR051NEXV =  OFF;
    }
    if (DIR041SETM == ON and DIL040___V == OFF and DIR041___V == AUTO){
        DIR031NEXV =  OFF;   DIR041NEXV =  ON;     DIR051NEXV =  OFF;
    }
    if (DIR051SETM == ON and DIL050___V == OFF and DIR051___V == AUTO){
        DIR031NEXV =  OFF;   DIR041NEXV =  OFF;    DIR051NEXV =  ON; 
    }
    DIR031SETM = DIR041SETM = DIR051SETM = OFF;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_01(vd){
    //  ��⠭���� ��� ࠡ��� ॣ����, ��।��塞� �����஬:
    //  �६� ����㧪� ��.���� 諠��
    if (TIME_SLNZM <  0){ TIME_SLNZM = 2; }
    if (TIME_SLNZM != TIME_SLNZV){ TIME_SLNZV = TIME_SLNZM; }     // 2 MIN
    //  �६� ���㧪� ��.���� 諠��
    if (TIME_SLNVM <  0){ TIME_SLNVM = 4; }
    if (TIME_SLNVM != TIME_SLNVV){ TIME_SLNVV = TIME_SLNVM; }     // 4 MIN
    //  ������⢮ ����㦥���� ��.���ᮢ 諠��
    if (LOAD_SLCNM <  0){ LOAD_SLCNM = 2; }
    if (LOAD_SLCNM != LOAD_SLCNV){ LOAD_SLCNV = LOAD_SLCNM; }     // 2 NAS
    //  �६� �������� �몫�祭�� ᨣ���� ������� �஢�� ��蠫�� 諠��
    if (TIME_LLVSM <  0){ TIME_LLVSM = 7; }
    if (TIME_LLVSM != TIME_LLVSV){ TIME_LLVSV = TIME_LLVSM; }     // 7 MIN
    //  �६� �������� ����祭�� ᨣ���� ���孥�� �஢�� ��蠫�� 諠��
    if (TIME_HLVSW <  0){ TIME_HLVSW =30; }                       // 30 MIN
    //  �६� �த㢪� ��.���� 諠��
    if (TIME_PRDSM <  0){ TIME_PRDSM = 5; }
    if (TIME_PRDSM != TIME_PRDSV){ TIME_PRDSV = TIME_PRDSM; }     // 5 MIN
    //  �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_SLPKW <  0){ TIME_SLPKW = 5;  }                      // 5 SEC
    //  ���稪 ������⢠ ����஢�� 諠��
    if (COUN_SLDZW <  0){ COUN_SLDZW = 4;  }                      // 4 DOZ
    //  ����஫� ������� �஢�� ��蠫�� 諠��
    if (CTRL_LLMSM <  0){ CTRL_LLMSV = ON; CTRL_LLMSM = OFF; }    // ON
    if (CTRL_LLMSM == SWITCH){ 
        CTRL_LLMSV = (CTRL_LLMSV!=ON) then_ ON else_ OFF; CTRL_LLMSM=OFF;
    }
    //  ����஫� ���孥�� �஢�� ��蠫�� 諠��
    if (CTRL_HLMSM <  0){ CTRL_HLMSV = ON; CTRL_HLMSM = OFF; }    // ON
    if (CTRL_HLMSM == SWITCH){ 
        CTRL_HLMSV = (CTRL_HLMSV!=ON) then_ ON else_ OFF; CTRL_HLMSM=OFF;
    }
    //  ����஫� �஢�� �� ���� ��蠫�� 諠��
    if (CTRL_LPSLM <  0){ CTRL_LPSLV = ON; CTRL_LPSLM = OFF; }    // ON
    if (CTRL_LPSLM == SWITCH){ 
        CTRL_LPSLV = (CTRL_LPSLV!=ON) then_ ON else_ OFF; CTRL_LPSLM=OFF;
    }

    //  ��।����� ᮮ⢥��⢨� �������� ��� 諠�����ᥩ��
    DefineSLBAS();
    //  ����祭��-�몫�祭�� ॣ����
    if ( REG01RS__M == SWITCH ){ 
         REG01R___M = (REG01R___M==ON) then_ OFF else_ ON; REG01RS__M=OFF;
    }
    if ( REG01R___M != REG01R___V ){ 
         REG01R___M  =(REG01R___M==ON) then_ ON else_ OFF;
         REG01R___V  = REG01R___M;
         if(REG01R___V>0){ Message(320); STEP01 =   0; }          // ��⮬��
         else            { Message(321); STEP01 = 101; }          // ��筮�
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //  �᫨ ॣ���� �몫�祭 � ⥪�騩 蠣 �� �த㢪�- ���
    //  ��� �믮������ �த㢪� ࠧ�襭 ���室 �� ��� 15..25
    if (REG01R___V == OFF and (STEP01<15 or STEP01>25)){ 
        Regul_01m(); return; 
    }
    //  �᫨ ��.����� 諠�� � ��筮� ०��� - ���
    if (DIR010___V == MANUAL and DIR020___V == MANUAL){ 
        REG01SW__V = 106;
        Regul_01m(); return; 
    }
    //  �᫨ �� 諠�����ᥩ�� � ��筮� ०��� - ���
    if (DIR031___V == MANUAL and DIR041___V == MANUAL and DIR051___V== MANUAL){
        REG01SW__V = 107;
        Regul_01m(); return; 
    }
    //-----------------------------------------------------------------------

    //  ��।����� ᮮ⢥��⢨� ������� �室��-��室�� ��� ��࠭���� ����.���.
    RegNSET();

    //-----------------------------------------------------------------------
    // ����஫� ������⢠ ����஢�� 諠��
    if (RegRUN==ON){
        // �᫨ ��� ����� 700 �� � 䫠� ���稪�=0 㢥����� ���稪 ����㧪�
        if(AIW230___V>700 and FLAG_SLDZC==0)  { FLAG_SLDZZ++; }
        else                                  { FLAG_SLDZZ=0; }
        // �᫨ ��� ����� 50  �� � 䫠� ���稪�=1 㢥����� ���稪 ���㧪�
        if(AIW230___V<50  and FLAG_SLDZC==1)  { FLAG_SLDZV++; }
        else                                  { FLAG_SLDZV=0; }
        //---------
        // �᫨ ��� 㤥ন������ ����� 7 ᥪ - ��⠥�, �� ������ ����㦥�
        if(AIW230___V>700 and FLAG_SLDZC==0 and FLAG_SLDZZ== 7 ){
           FLAG_SLDZC=1;
        }
        // �᫨ ��� 㤥ন������ ����� 7 ᥪ - ��⠥�, �� ������ ���㦥�
        // (��諠 ���� ����஢�� ���ண�)
        if(AIW230___V<50  and FLAG_SLDZC==1 and FLAG_SLDZV== 7 ){
           FLAG_SLDZC=0;  COUN_SLDZC++;
        }
        //---------
        if(FLAG_SLDZZ>100){ FLAG_SLDZZ=100; }
        if(FLAG_SLDZV>100){ FLAG_SLDZV=100; }
    }
    //-----------------------------------------------------------------------


    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if ( STEP01 ==0 ){
         if(STEP01P!=0){
            ;;
         }; STEP01P =0;
         if(RegRUN==OFF){ return; }

         Regul_01off();
         //  ��८�।������ ��࠭���� ��� �����窨 諠�����ᥩ��
         if(DIR031NEXV==ON){ DIR031SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR041NEXV==ON){ DIR041SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR051NEXV==ON){ DIR051SETM=ON; DSB=1; DefineSLBAS(); }
         //  �᫨ ���� ᨣ��� ��� �஢�� � 諠�����ᥩ��- ��� �� ॣ����
         REG01SW__V = 0;
         switch ( Check_TO (11,4*SEC, DILR01___V,'=',OFF, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(11); return;; }
         }
         //  �᫨ ���� ᨣ��� ���� �஢�� ��蠫�� 諠��- ��� �� ॣ����
         if(CTRL_HLMSV==ON){
            REG01SW__V = 1;
            switch ( Check_TO (12,4*SEC, DIH220___V,'=',OFF, 2)){
                case RUN: { return;; }
                case BAD: { Clear_TO(12); return;; }
            }
         }
         //  �᫨ ��� ᨣ���� ������� �஢�� ��蠫�� 諠��- ��� �� ॣ����
         if(CTRL_LLMSV==ON){
            REG01SW__V = 2;
            switch ( Check_TO (13,4*SEC, DIL220___V,'=',ON, 2)){
                case RUN: { return;; }
                case BAD: { Clear_TO(13); return;; }
            }
         }
         //  �᫨ ���� �஢��� � �� ���� 諠��- ��� �� ॣ����
         REG01SW__V = 3;
         if(CTRL_LPSLV==ON){
            if(DIHR01PN_V==ON){ return; }
         }
         //  �᫨ ��蠫�� 諠�����ᥩ�� �몫�祭�- ��� �� ॣ����
         REG01SW__V = 4;
         switch ( Check_TO (14,4*SEC, DISR01MS_V,'=',ON, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(14); return;; }
         }
         //  �᫨ ��蠫�� 諠�� �몫�祭�- ��� �� ॣ����
         REG01SW__V = 5;
         switch ( Check_TO (15,4*SEC, DIS220___V,'=',ON, 2)){
             case RUN: { return;; }
             case BAD: { Clear_TO(15); return;; }
         }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG01SW__V = 6;
         if((DIR031___V==AUTO and (DIS031___V==ON or DIS032___V==ON)) or
            (DIR041___V==AUTO and (DIS041___V==ON or DIS042___V==ON)) or
            (DIR051___V==AUTO and (DIS051___V==ON or DIS052___V==ON)) or
            (DIR010___V==AUTO and (DIS011___V==ON or DIS012___V==ON)) or
            (DIR020___V==AUTO and (DIS021___V==ON or DIS022___V==ON)) ){
             switch ( Check_TO (16,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(261); Bell(1); Clear_TO(16); return;; }
             }
         };  Clear_TO(16);
         //  �᫨ ������⢮ ����஢�� 諠�� ����� ���������- ���
         REG01SW__V = 7;
         if (COUN_SLDZC<COUN_SLDZW){ return; }
         //  �᫨ ��蠫�� 諠�� �� ����- ����� �������
         REG01SW__V = 8;
         if(REG01ZO1_W==END){ REG01ZO1_W=OFF; Clear_TO(17); }
         if(DIR220___V==OFF){
            switch ( Check_TO (17,60*SEC, REG01ZO1_W,'=', YES, 2)){
                case RUN: { return;; }
                case BAD: { 
                            REG01ZO1_W=REQ; Message(280); Bell(1); Clear_TO(17);
                            return;; 
                          }
            }
         }
         //  ���㫨�� ⠩���� � ���稪�
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         Clear_TO(15);
         Clear_TO(16);
         Clear_TO(17);
         REG01ZO1_W    = OFF;
         TIME_LLVSCMin = 0;                      // ������ �஢���
         TIME_LLVSC    = 0;
         TIME_HLVSCMin = 0;                      // ���孨� �஢���
         TIME_HLVSC    = 0;
         TIME_SLNZCMin = 0;                      // ����㧪� ��
         TIME_SLNZC    = 0;
         TIME_SLNVCMin = 0;                      // ���㧪� ��
         TIME_SLNVC    = 0;
         TIME_PRDSCMin = 0;                      // �த㢪�
         TIME_PRDSC    = 0;
         STEP01 = 10;
         return;
    }
    //-----------------------------------------------------------------------


    // ��������� ���������� ��������� �ᯮ���⥫�� ॣ����
    //-----------------------------------------------------------------------
    if ( STEP01 ==10 ){
         if(STEP01P!=10){
            ;;
         }; STEP01P =10;
         REG01SW__V = 6;
         //  ��砫쭮� ���ﭨ� ��� �ᯮ���⥫�� � ⠩��஢
         Regul_01off();
         //  ��८�।������ ��࠭���� ��� �����窨 諠�����ᥩ��
         if(DIR031NEXV==ON){ DIR031SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR041NEXV==ON){ DIR041SETM=ON; DSB=1; DefineSLBAS(); }
         if(DIR051NEXV==ON){ DIR051SETM=ON; DSB=1; DefineSLBAS(); }
         //  ����� ���稪� � ⠩����
         LOAD_SLCNC = 0;
         FLAG_HLVSExit = OFF;
         STEP01 =  1;
         return;
    }
    //-----------------------------------------------------------------------


    // �������� ����� � ��.����
    //-----------------------------------------------------------------------
    if ( STEP01 ==1 ){
         if(STEP01P!=1){
            ;;
         }; STEP01P =1;
         if(RegRUN==OFF){ return; }

         //  ������ ������ ����� 諠�� � ��.����
         REG01SW__V = 10;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=ON;   DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  1, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11); 
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  ������ ������ ����� 諠�� �� 諠�����ᥩ��
         REG01SW__V = 11;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;   DONR01PK_V=OFF;  DONR01PKSV=ON;   DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01P1_V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01P1_V,3,TIME_ISPPW,70,  1, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         switch ( Check_TO  (14, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         REG01SW__V = 12;
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==2 ){
         if(STEP01P!=2){
            ;;
         }; STEP01P =2;
         if(RegRUN==OFF){ return; }

         //  ������ ������ 諠�� � ��.����
         REG01SW__V = 20;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  2, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  ������ ������ � 諠�����ᥩ��
         REG01SW__V = 21;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=ON;;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01PK_V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70,  2, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         REG01SW__V = 21;
         STEP01 = 3;
         return;
    }
    //-----------------------------------------------------------------------


    // �������� ������ ��.����
    //-----------------------------------------------------------------------
    if ( STEP01 ==3 ){
         if(STEP01P!=3){
            TIME_SLNZCMin=0;
            TIME_SLNZC   =0;
         }; STEP01P =3;
         if (RegRUN==OFF){ return; }

         REG01SW__V = 30;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=ON;;  DONR01PKSV=ON;;  DONR01PKVV=OFF;
         // �᫨ �몫�祭 ����஫� �஢�� ����������- �᪫���� ᨣ��� �஢��
         if(CTRL_LPSLV==OFF){ DIHR01PN_V=OFF; }
         // ����� ᨣ��� �஢�� ��.����, ����� �६� ����� ��.���� 諠��
         switch ( Check_TO  (11, TIME_SLNZV*MIN, DIHR01PN_V,'=',ON, TIME_LSTBV )){
            case RUN:{ TIME_SLNZCMin++; TIME_SLNZC=TIME_SLNZCMin/MIN; return;; }
            case BAD:{ 
                        if(TIME_SLNZ1==ON){ Bell(1); }
                        if(TIME_SLNZ3==ON){ Message(210); }  // �� �६���
                        break;;
                     }
            case END:{ 
                        if(TIME_SLNZ1==ON){ Bell(1); }
                        if(TIME_SLNZ3==ON){ Message(211); }  // �� �஢��
                        break;;
                     }
         }
         Clear_TO(11);

         REG01SW__V = 31;
         STEP01_BACK= 0;
         STEP01 = 4;
         return;
    }
    //-----------------------------------------------------------------------


    // ��������� �������� ��.����
    //-----------------------------------------------------------------------
    if ( STEP01 ==4 ){
         if(STEP01P!=4){
            ;;
         }; STEP01P =4;
         if (RegRUN==OFF){ return; }

         //  ������� ������ � 諠�����ᥩ��
         REG01SW__V = 40;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PK_V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70,  4, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         //  ������� ������ ����� 諠�� � ��.����
         REG01SW__V = 41;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (13, TIME_ISPKV*SEC, DISR01PKSV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70,  4, 13); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(13);
         switch ( Check_TO  (14, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         Clear_TO(13);
         Clear_TO(14);
         REG01SW__V = 41;
         STEP01 = 5;
         return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ��.���� (��� ������ ������ � ��.����)
    //-----------------------------------------------------------------------
    if ( STEP01 ==5 ){
         if(STEP01P!=5){
            ;;
         }; STEP01P =5;
         if (RegRUN==OFF){ return; }

         //  ������ ��.������ ����� ������ � ��.����
         REG01SW__V = 50;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70,  5, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         REG01SW__V   = 51;
         STEP01 = 6;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==6 ){
         if(STEP01P!=6){
            TIME_SLNVCMin= 0;
            TIME_SLNVC   = 0;
         }; STEP01P =6;
         if (RegRUN==OFF){ return; }

         //  ����� �६� ���㧪� �� ��.���� 諠��
         REG01SW__V = 60;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_SLNVV*MIN, ZERO,'=',ON,  1 )){
            case RUN:{ 
                        TIME_SLNVCMin++; TIME_SLNVC=TIME_SLNVCMin/MIN; break;; 
                     }
            case BAD:{ 
                        if(TIME_SLNV1==ON){ Bell(1); }
                        if(TIME_SLNV3==ON){ Message(212); }
                        Clear_TO(11);
                        Clear_TO(12);
                        Clear_TO(14);
                        if(STEP01_BACK==101){ STEP01=101; }
                        else                { STEP01=7;   }
                        return;;
                     }
         }

         //------------------------------------------------------------------
         // ���稪 �������� �몫�祭 ᨣ���� ������� �஢�� ��蠫�� 諠��:
         switch ( Check_TO (18, TIME_LLVSV*MIN,DIL220___V,'=',OFF,TIME_LSTBV )){
             case RUN:{ 
                         if(CTRL_LLBCV==ON and DIL220___V==ON){
                            TIME_LLVSCMin++; TIME_LLVSC=TIME_LLVSCMin/MIN; 
                         }
                         break;; 
                      }
             // �᫨ �� �������� �६� ᨣ��� ������� �஢�� ��蠫�� 諠��
             // ��⠫�� �ࠡ�⠭��
             case BAD:{ 
                         if(TIME_LLVS1==ON){ Bell(1); }
                         if(TIME_LLVS3==ON){ Message(328); }
                         Clear_TO(18);
                         break;;  
                      }
             // �� �������� �६� ᨣ��� ������� �஢�� ��蠫�� 諠�� �ய��
             case END:{ 
                         Clear_TO(18);
                         break;;
                      }
         }

         //------------------------------------------------------------------
         // ���稪 �������� ����祭 ᨣ���� ���孥�� �஢�� ��蠫�� 諠��:
         if(CTRL_HLMSV==OFF){ DIH220___C=OFF; }
         else               { DIH220___C=DIH220___V; }
         switch ( Check_TO (17, TIME_HLVSW*MIN,DIH220___C,'=',ON, TIME_LSTBV)){
             case RUN:{ 
                         if(CTRL_HLMSV==ON and DIH220___C==OFF){
                            TIME_HLVSCMin++; TIME_HLVSC=TIME_HLVSCMin/MIN;
                         }
                         break;; 
                      }
             // �᫨ �� �������� �६� ��� ᨣ���� ���� �஢�� ��蠫�� 諠��
             case BAD:{ 
                         Bell(1); Message(252);
                         FLAG_HLVSExit=ON;
                         Clear_TO(17);
                         break;;  
                      }
             // �� �������� �६� ����� ᨣ��� ���孥�� �஢�� ��蠫�� 諠��
             case END:{ 
                         // �᫨ �몫 ����� ���� �஢��- ����� �६�
                         if(CTRL_HLMSV==OFF){
                            if(TIME_HLVSCMin>TIME_HLVSW){ FLAG_HLVSExit=ON; }
                            TIME_HLVSCMin++; TIME_HLVSC=TIME_HLVSCMin/MIN;
                         }
                         Clear_TO(17);
                         break;;
                      }
         }
         //------------------------------------------------------------------
         return;
    }
    //-----------------------------------------------------------------------


    // ��������� �������� ��.���� (�몫 ������ ������ � ��.����)
    //-----------------------------------------------------------------------
    if ( STEP01 ==7 ){
         if(STEP01P!=7){
            ;;
         }; STEP01P =7;
         if (RegRUN==OFF){ return; }

         //  ������� ��.������ ����� ������ � ��.����
         REG01SW__V = 70;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70,  7, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }
         Clear_TO(11);
         Clear_TO(12);
         REG01SW__V = 71;
         STEP01 = 8;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==8 ){
         if(STEP01P!=8){
            ;;
         }; STEP01P =8;
         REG01SW__V = 80;

         //  㢥����� ���稪 ����㦥���� ���ᮢ
         LOAD_SLCNC++;
         //  �᫨ ⥪�騩 ���稪 ����㦥���� ���ᮢ > ��� = ���������-
         //  ��३� �� ��� 15 (������� �ᯮ���⥫� ॣ���� � �� ���0)
         if (LOAD_SLCNC >= LOAD_SLCNV){ 
             STEP01=15; 
             COUN_SLDZC =0;
             Message(253);
             STEP01_BACK=0; 
             return; 
         }
         //  �᫨ ���� ᨣ��� ���孥�� �஢�� � ��蠫�� 諠��- 
         //  ��३� �� ��� 15
         if (DIH220___V == ON && CTRL_HLMSV == ON){ 
             STEP01=15; 
             COUN_SLDZC   =0;
             Message(254);
             STEP01_BACK  =0;
             return; 
         }
         //  �᫨ ��蠫�� 諠�� �몫�祭�- ��३� �� ��� 15
         if (DISR01MS_V == OFF){ 
             STEP01=15; 
             Message(255);
             STEP01_BACK=0;
             return; 
         }
         //  �᫨ ��諮 �६� ����� ���孥�� �஢�� ��蠫�� 諠��-
         //  �몫���� ॣ����
         if (FLAG_HLVSExit == ON){
             STEP01=15; 
             Message(256); Bell(1);
             COUN_SLDZC   =0;
             STEP01_BACK  =0;
             return; 
         }
         //  ��३� �� ������� ����㧪�
         STEP01 = 2;
         return;
    }
    //-----------------------------------------------------------------------




    //-----------------------------------------------------------------------
    // ��������
    //-----------------------------------------------------------------------
    if ( STEP01 ==15 ){
         if(STEP01P!=15){
            ;;
         }; STEP01P =15;
         if(RegRUN==OFF){ return; }

         // ������� ������ � 諠�����ᥩ�� � ������ ������ � ��.����
         REG01SW__V = 150;
         // ����          �_��             �_��             �_��
         DONR01P1_V=ON;;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PK_V,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PK_V,3,TIME_ISPPW,70, 15, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);

         REG01SW__V = 151;
         switch ( Check_TO  (12, TIME_ISPKV*SEC, DISR01PKSV,'=',ON, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70, 15, 12); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(12);
         switch ( Check_TO  (13, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(13);
         STEP01 = 16;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==16 ){
         if(STEP01P!=16){
            ;;
         }; STEP01P =16;
         if(RegRUN==OFF){ return; }

         // ������� ������ �� 諠�����ᥩ��
         REG01SW__V = 160;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=ON;;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01P1_V,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01P1_V,3,TIME_ISPPW,70, 16, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 17;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==17 ){
         if(STEP01P!=17){
            ;;
         }; STEP01P =17;
         if(RegRUN==OFF){ return; }

         // ������� ������ 諠�� � ��.����
         REG01SW__V = 170;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKSV,'=',OFF, 1)){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKSV,3,TIME_ISPPW,70, 17, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         switch ( Check_TO  (12, TIME_SLPKW*3*SEC, ZERO,'=',ON, 1)){
             case RUN: { return;; }
         }

         Clear_TO(11);
         Clear_TO(12);
         STEP01 = 21;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==21 ){
         if(STEP01P!=21){
            ;;
         }; STEP01P =21;
         if (RegRUN==OFF){ return; }

         //  ������ ������ ����� ������ � ��.���� ��� �த㢪�
         REG01SW__V = 210;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70, 21, 11); return;; 
                       }
         };  Clear_TO(11); DONCN01=0;
         REG01SW__V = 211;
         STEP01 = 22;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==22 ){
         if(STEP01P!=22){
            TIME_PRDSC = 0;
            TIME_PRDSCMin = 0;
         }; STEP01P =22;
         if (RegRUN==OFF){ return; }

         //  ����� �६� ����� ������ � ��.���� 諠�� (�த㢪�)
         REG01SW__V = 220;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=ON;; 

         switch ( Check_TO  (11, TIME_SLNVV*MIN, ZERO,'=',ON,  1 )){
            case RUN:{ TIME_PRDSCMin++; TIME_PRDSC=TIME_PRDSCMin/MIN; return; }
            case BAD:{ 
                        if(TIME_PRDS1==ON){ Bell(1); }
                        if(TIME_PRDS3==ON){ Message(212); }
                        break;;
                     }
         }
         Clear_TO(11);

         REG01SW__V = 221;
         STEP01 = 23;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==23 ){
         if(STEP01P!=23){
            ;;
         }; STEP01P =23;
         if (RegRUN==OFF){ return; }

         //  ������� ��.������ ����� ������ � ��.����
         REG01SW__V = 230;
         // ����          �_��             �_��             �_��
         DONR01P1_V=OFF;  DONR01PK_V=OFF;  DONR01PKSV=OFF;  DONR01PKVV=OFF;;

         switch ( Check_TO  (11, TIME_ISPKV*SEC, DISR01PKVV,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN01>2){ REG01R___M=OFF; return;; }
                         Isp01PD(&DONR01PKVV,3,TIME_ISPPW,70, 23, 11); return;; 
                       }
             case END: { DONCN01=0; break;; }
         };  Clear_TO(11);
         REG01SW__V = 231;
         STEP01 = 25;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP01 ==25 ){
         if(STEP01P!=25){
            ;;
         }; STEP01P =25;
         //  ���� ������� �������� �� �����⨥ ��� �ᯮ���⥫�� ॣ����
         Regul_01off();
         STEP01 = STEP01_BACK;
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
