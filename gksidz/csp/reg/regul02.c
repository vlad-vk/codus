//---------------------------------------------------------------------------
// �����窠 ����

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

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
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_02off(vd){
    DON201___V =  OFF;
    DON061___V =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_02m(vd){
    //-----------------------------------------------------------------------
    if ( STEP02 == 101 ){
         REG02SW__V = 1001;
         if(RegRUN==OFF){ return; }
         // �������� �� �몫�祭��-�����⨥ �ᯮ���⥫�� ॣ����
         DON061___V=OFF; DON201___V=OFF;
         switch ( Check_TO  (21, TIME_ISNSV*SEC, ZERO,'=',ON,  1 )){
             case RUN: { return;; }
         };  Clear_TO (21);
         // ����ୠ� �������� �� �����⨥ �ᯮ���⥫��
         Regul_02off();
         //
         COUN_VDDZC=COUN_VDDZW;
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
    // ��⠭���� ��� ࠡ��� ॣ����, ��।��塞� �����஬
    // �६� �������� �। �஢�� ᡮ୨�� ���� 
    if (TIME_VODMM <  0){ TIME_VODMM = 10; }
    if (TIME_VODMM != TIME_VODMV){ TIME_VODMV = TIME_VODMM; }     // 10 MIN
    // �६� �������� ���� �஢�� ᡮ୨�� ���� 
    if (TIME_VODHM <  0){ TIME_VODHM = 10; }
    if (TIME_VODHM != TIME_VODHV){ TIME_VODHV = TIME_VODHM; }     // 10 MIN
    // ⥬������ �몫�祭�� ����� �������� � ᡮ୨� ����
    if (TEMP_VODBM <  0){ TEMP_VODBM = 45; }
    if (TEMP_VODBM != TEMP_VODBV){ TEMP_VODBV = TEMP_VODBM; }     // 45 C
    // �६� �⢥������ ��� ����窨 ��������
    if (TIME_CONDM <  0){ TIME_CONDM =  7; }
    if (TIME_CONDM != TIME_CONDV){ TIME_CONDV = TIME_CONDM; }     //  7 MIN
    // �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_VDPKW <  0){ TIME_VDPKW = 5;  }                      // 5 SEC
    //  ���稪 ������⢠ ����஢��
    if (COUN_VDDZW <  0){ COUN_VDDZW = 4;  }                      // 4 DOZ
    //  ����஫� ������� �஢�� ���୨�� ����
    if (CTRL_LLSVM <  0){ CTRL_LLSVV = ON; CTRL_LLSVM = OFF; }    // ON
    if (CTRL_LLSVM == SWITCH){ 
        CTRL_LLSVV = (CTRL_LLSVV!=ON) then_ ON else_ OFF; CTRL_LLSVM=OFF;
    }
    //  ����஫� �।���� �஢�� ���୨�� ����
    if (CTRL_MLSVM <  0){ CTRL_MLSVV = ON; CTRL_MLSVM = OFF; }    // ON
    if (CTRL_MLSVM == SWITCH){ 
        CTRL_MLSVV = (CTRL_MLSVV!=ON) then_ ON else_ OFF; CTRL_MLSVM=OFF;
    }
    //  ����஫� ���孥�� �஢�� ���୨�� ����
    if (CTRL_HLSVM <  0){ CTRL_HLSVV = ON; CTRL_HLSVM = OFF; }    // ON
    if (CTRL_HLSVM == SWITCH){ 
        CTRL_HLSVV = (CTRL_HLSVV!=ON) then_ ON else_ OFF; CTRL_HLSVM=OFF;
    }
    //  ����஫� ������� �஢�� ���୨�� ��������
    if (CTRL_LLSKM <  0){ CTRL_LLSKV = ON; CTRL_LLSKM = OFF; }    // ON
    if (CTRL_LLSKM == SWITCH){ 
        CTRL_LLSKV = (CTRL_LLSKV!=ON) then_ ON else_ OFF; CTRL_LLSKM=OFF;
    }

    // ����祭��-�몫�祭�� ॣ����
    if ( REG02RS__M == SWITCH ){ 
         REG02R___M = (REG02R___M==ON) then_ OFF else_ ON; REG02RS__M=OFF;
    }
    if ( REG02R___M != REG02R___V ){ 
         REG02R___M  =(REG02R___M==ON) then_ ON else_ OFF;
         REG02R___V  = REG02R___M;
         if ( REG02R___V == ON ){ Message(330); STEP02 =   0; }   // ��⮬��
         else                   { Message(331); STEP02 = 101; }   // ��筮�
    }
    // �᫨ ���� ᡮ୨�� ���� �� �㪥 ��� 
    // ����祭 ��筮� ०�� ॣ���� - ���
    if ( DIR200___V == MANUAL or REG02R___V == OFF ){ Regul_02m(); return; }

    //-----------------------------------------------------------------------
    // ����஫� ������⢠ ����஢�� ����
    if (RegRUN==ON){
        // �᫨ ��� ����� 70 �� � 䫠� ���稪�=0 㢥����� ���稪 ����㧪�
        if(AIW230___V>70  and FLAG_VDDZC==0)  { FLAG_VDDZZ++; }
        else                                  { FLAG_VDDZZ=0; }
        // �᫨ ��� ����� 50  �� � 䫠� ���稪�=1 㢥����� ���稪 ���㧪�
        if(AIW230___V<30  and FLAG_VDDZC==1)  { FLAG_VDDZV++; }
        else                                  { FLAG_VDDZV=0; }
        //---------
        // �᫨ ��� 㤥ন������ ����� 3 ᥪ - ��⠥�, �� ������ ����㦥�
        if(AIW230___V>70  and FLAG_VDDZC==0 and FLAG_VDDZZ== 3 ){
           FLAG_VDDZC=1;
        }
        // �᫨ ��� 㤥ন������ ����� 3 ᥪ - ��⠥�, �� ������ ���㦥�
        // (��諠 ���� ����஢�� ����)
        if(AIW230___V<50  and FLAG_VDDZC==1 and FLAG_VDDZV== 3 ){
           FLAG_VDDZC=0;  COUN_VDDZC++;
        }
        //---------
        if(FLAG_VDDZZ>100){ FLAG_VDDZZ=100; }
        if(FLAG_VDDZV>100){ FLAG_VDDZV=100; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    if ( STEP02 ==0 ){
         if(STEP02P!=0){
            ;;
         }; STEP02P =0;
         if (RegRUN==OFF){ return; }

         Regul_02off();
         // �����, �ய������ ᨣ���� ���孥�� �஢�� ᡮ୨�� ����
         REG02SW__V = 0;
         if(CTRL_HLSVV==ON){
            switch ( Check_TO  (21, 5*MIN, DIH200___V,'=',OFF, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(21); return;; }
            }
         }
         // �����, �ய������ ᨣ���� �।���� �஢�� ᡮ୨�� ����
         REG02SW__V = 1;
         if(CTRL_MLSVV==ON){
            switch ( Check_TO  (22, 5*MIN, DIM200___V,'=',OFF, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(22); return;; }
            }
         }
         // �����, ������ ᨣ���� ������� �஢�� ᡮ୨�� ����
         REG02SW__V = 2;
         if(CTRL_LLSVV==ON){
            switch ( Check_TO  (23, 5*MIN, DIL200___V,'=',ON, TIME_LSTBV )){
                case RUN: { return;; }
                case BAD: { Clear_TO(23); return;; }
            }
         }
         // �஢�ઠ ������� ���㧪� ���� �� ᡮ୨�� (㡥����� �� ������)
         REG02SW__V = 3;
         switch ( Check_TO  (24, TIME_ISPKV*SEC, DIS202___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { Clear_TO(24); return;; }
         }
         //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
         REG01SW__V = 4;
         if((DIR200___V==AUTO and (DIS201___V==ON)) or
            (DIR061___V==AUTO and (DIS061___V==ON)) ){
             switch ( Check_TO (25,1*MIN, ZERO,'=',ON, 2)){
                 case RUN: { return;; }
                 case BAD: { Message(262); Bell(1); Clear_TO(25); return;; }
             }
         };  Clear_TO(25);
         //  �᫨ ������⢮ ����஢�� ���� ����� ���������- ���
         REG02SW__V = 5;
         if (COUN_VDDZC<COUN_VDDZW){ return; }
         // ���㫨�� ⠩���� � ���稪�
         Clear_TO(21);
         Clear_TO(22);
         Clear_TO(23);
         Clear_TO(24);
         Clear_TO(25);
         TIME_VODMCMin=0;
         TIME_VODMC   =0;
         TIME_VODHCMin=0;
         TIME_VODHC   =0;
         TIME_CONDCMin=0;
         TIME_CONDC   =0;
         //
         DONCN02= 0;
         STEP02 = 1;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==1 ){
         if(STEP02P!=1){
            TIME_VODHCMin = 0;
            TIME_VODMCMin = 0;
            TIME_CONDCMin = 0;
         }; STEP02P =1;
         if (RegRUN==OFF){ return; }

         // ������ ������ ����� �孨�᪮� ����
         REG02SW__V = 10;
         DON201___V = ON;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS201___V,'=',ON,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN02>2){ REG02R___M=OFF; return;; }
                         Isp02PD(&DON201___V,3,TIME_ISPPW,70, 1, 21); return;; }
             case END: { DONCN02=0; break;; }
         };  Clear_TO(21);

         REG02SW__V = 11;
         //--------------------------------------------------------------------
         // �஢�ઠ �।���� �஢�� ᡮ୨�� ����.
         // �᫨ �� ��।������� �६� �஢��� �� �����-ᮮ�饭�� �������.
         // ���室 �� ��砫� 横�� (蠣 0).
         switch ( Check_TO (22, TIME_VODMV*MIN, DIH200___V,'=',ON, TIME_LSTBV)){
             case RUN: { 
                          // ����� �६� ����� �।���� � ���孥�� �஢���
                          TIME_VODHCMin++; 
                          TIME_VODHC=TIME_VODHCMin/MIN; 
                          TIME_VODMCMin++; 
                          TIME_VODMC=TIME_VODMCMin/MIN; 
                          // �᫨ ���� ᨣ��� ���孥�� �஢��
                          if(DIH200___V==ON){ STEP02=4; }
                          return;; 
                       }
             case BAD: {
                          if(TIME_VODL1==ON){ Bell(1); }
                          if(TIME_VODL3==ON){ Message(203); }
                          Clear_TO(22);
                          // �᫨ ���� ᨣ��� ���孥�� �஢��
                          if(DIH200___V==ON){ STEP02=4; return;; }
                          // �᫨ ��� ����஫� �। �஢��- �� ��砫� 横��
                          if(CTRL_MLSVV==ON){
                             COUN_VDDZC=0; 
                             DON201___V=OFF; DON061___V=OFF; STEP02=0;
                             return;;
                          } 
                          // �᫨ ����஫� �।���� �஢�� �몫- �த��� �����
                          break;;
                       }
             case END: {
                          // �᫨ �몫�祭 ����஫� �।���� �஢��-
                          // ����� �������� ����� �।���� � ���孥��
                          // �஢��
                          if(CTRL_MLSVV==OFF){
                             TIME_VODMCMin++; 
                             TIME_VODMC=TIME_VODMCMin/MIN; 
                             TIME_VODHCMin++; 
                             TIME_VODHC=TIME_VODHCMin/MIN; 
                          }
                          break;;
                       }
         }
         // �᫨ ���� ᨣ��� ���孥�� �஢��
         if(DIH200___V==ON){ STEP02=4; return;; }
         Clear_TO(21);
         Clear_TO(22);
         REG02SW__V = 12;
         STEP02 = 2; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==2 ){
         if(STEP02P!=2){
            ;;
         }; STEP02P =2;
         if (RegRUN==OFF){ return; }

         // �᫨ ᡮ୨� �������� �� �㪥 ��� �᫨ �몫 ����஫� ��� �஢��
         // ᡮ୨�� �������� ��� �᫨ ���� ᨣ ���� �஢�� � ����祭 �����-
         // ������ ᡮ୨� �� ����� �� ���孥�� �஢��
         if (DIR061___V==OFF or CTRL_LLSKV==OFF or
            (DIL060___V==ON and CTRL_LLSKV==ON )){ 
             STEP02=4; return; 
         }
         // ������� ������ ����� �孨�᪮� ����
         DON201___V = OFF;
         REG02SW__V = 20;
         switch ( Check_TO  (21, TIME_ISPKV*SEC, DIS201___V,'=',OFF,  1 )){
             case RUN: { return;; }
             case BAD: { 
                         if(DONCN02>2){ REG02R___M=OFF; return;; }
                         Isp02PD(&DON201___V,3,TIME_ISPPW,70, 2, 21); return;; 
                       }
             case END: { DONCN02=0; break;; }
         };  Clear_TO(21);
         REG02SW__V = 21;

         // �᫨ ��� ᨣ���� ������� �஢�� � ᡮ୨�� �������� 
         // � ���� ��४��祭 �� ��⮬���᪨� ०�� �
         // ⥬������ � ᡮ୨�� ���� ����� ��������- 
         // ������� ���� �����窨 �������� � ᡮ୨� ����
         if((CTRL_LLSKV==ON and DIL060___V==OFF) and (DIR061___V==AUTO) and
            (AIT200___V <TEMP_VODBV)){
             STEP02 = 3;
             return;
         }
         REG02SW__V = 22;
         // �᫨ �����-� �᫮��� ��� ����祭�� ���� �� �믮������� - 
         // ��३� �� 蠣 0
         COUN_VDDZC = 0;
         STEP02 = 0;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==3 ){
         if(STEP02P!=3){
            TIME_CONDCMin=0;
         }; STEP02P =3;
         if (RegRUN==OFF){ return; }

         // ������� ���� ����� �������� � ᡮ୨� ����
         DON061___V = ON;
         REG02SW__V = 30;
         switch ( Check_TO  (21, TIME_ISNSV*SEC, DIS061___V,'=',ON, 1 )){
             case RUN: { return;; }
         };  Clear_TO(21);
         REG02SW__V = 31;
         // �᫨ �ࠡ�⠫ ᨣ��� ���孥�� �஢�� ᡮ୨�� ���� ��� ⥬������
         // ����ᨫ��� ����� ��������- �몫���� ����
         if((CTRL_HLSVV==ON and DIH200___V==ON) or (AIT200___V>TEMP_VODBV)){
             DON061___V =OFF;
             COUN_VDDZC =0;
             Message(300);
             STEP02 =0;  
             return;
         }
         // �᫨ ��諮 �����⨬�� �६� ����窨 ��������- �몫���� ����
         switch ( Check_TO  (22, TIME_CONDV*MIN, ZERO,'=',ON,  1 )){
             case RUN: { 
                          TIME_CONDCMin++; 
                          TIME_CONDC=TIME_CONDCMin/MIN;
                          return;; 
                       }
             case BAD: {
                          if(TIME_COND1==ON){ Bell(1); }
                          if(TIME_COND3==ON){ Message(206); }
                          Clear_TO(22); 
                          break;
                       }
         }  
         REG02SW__V = 32;
         Clear_TO(22);
         DON061___V = OFF;
         COUN_VDDZC = 0;
         STEP02 = 0; 
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP02 ==4 ){
         if(STEP02P!=4){
            ;;
         }; STEP02P =4;
         if (RegRUN==OFF){ return; }

         // �஢�ઠ ���孥�� �஢�� ᡮ୨�� ����.
         // �᫨ �� ��।������� �६� �஢��� �� �����-ᮮ�饭�� �������.
         // ���室 �� ��砫� 横�� (蠣 0).
         REG02SW__V = 40;
         switch ( Check_TO(21, TIME_VODHV*MIN, DIH200___V,'=',ON, TIME_LSTBV)){
             case RUN: {
                          TIME_VODHCMin++; 
                          TIME_VODHC=TIME_VODHCMin/MIN; 
                          return;; 
                       }
             case BAD: {
                          if(TIME_VODL1==ON){ Bell(1); }
                          if(TIME_VODL3==ON){ Message(257); }
                          Clear_TO(21);
                          COUN_VDDZC=0;
                          DON201___V=OFF;  DON061___V=OFF;
                          STEP02=0;
                          return;;
                       }
             case END: {
                          // �᫨ �몫 ����� ���� �஢�� ᡮ� ����- ����� ��
                          if(CTRL_HLSVV==OFF){
                             TIME_VODHCMin++; 
                             TIME_VODHC=TIME_VODHCMin/MIN; 
                             return;; 
                          }
                          Message(301);
                          break;;
                       }
         }
         Clear_TO(21);
         COUN_VDDZC=0;
         DON201___V=OFF;  DON061___V=OFF;
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
