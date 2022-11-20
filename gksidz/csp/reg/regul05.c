//---------------------------------------------------------------------------
// �����窠 楬���

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR05;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN05=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH05=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM05=2;               // ���-�� ᥪ㭤 ��� � ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp05PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR05= IOPNT;
    DONCH05= hM;
    DONTM05= hS;
    STEP05 = Step; 
    STEP05_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  ���� ⠩��஢ ॣ����
vd  far Timer_05off(vd){
    TIME_OSC5Min  = 0;
    TIME_OSC5C    = 0;
    TIME_LEV5CMin = 0;
    TIME_LEV5C    = 0;
    TIME_NAS5CMin = 0;
    TIME_NAS5C    = 0;
    TIME_PRDCCMin = 0;
    TIME_PRDCC    = 0;
    TIME_PCASCMin = 0;
    TIME_PCASC    = 0;
    return;
}
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_05off(vd){
    DON101___V = OFF;
    DON102___V = OFF;
    DON161___V = OFF;
    //
    FLAG_05BGA = OFF;
    STEP05F    = OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� � �몫�祭�� ॣ����
vd  far Regul_05m(vd){
    //-----------------------------------------------------------------------
    if ( STEP05  == 101 ){
         REG05SW__V=1001;
         // �᫨ �몫�稫� ॣ���� ���-� ���।��� � ���� �� ��⮬��- 
         // ᤥ���� ���㧪�, �த㢪� � �������� �� ��� �� 蠣
         if (STEP05P> 1 and STEP05P< 30  and  STEP05P!=7 and 
             STEP05P!=4 and STEP05P!=5   and  DIR100___V==AUTO){ 
             STEP05=4;  STEP05_BACK=101; REG05R___V=REG05R___M=ON; return; 
         }
         if (STEP05P==4 or STEP05P==5 and STEP05P!=7 and DIR100___V==AUTO){ 
             STEP05=30; STEP05_BACK=101; REG05R___M=OFF; return; 
         }
         // �������� �� �몫�祭�� �ᯮ���⥫�� ॣ���஢
         Regul_05off();
         Timer_05off();
         // 䫠�� ��⠭���� �����窨 楬���
         FLAG_0605A=OFF;
         FLAG_05WTA=OFF;
         STEP05F   =0;
         // ��� ���稪��
         LOAD_NS10C=0;
         COUN_CMDZC=COUN_CMDZW;
         // ��� ⠩��஢
         Clear_TO(51);
         Clear_TO(52);
         Clear_TO(53);
         Clear_TO(54);
         Clear_TO(55);
         Clear_TO(56);
         Clear_TO(57);
         Clear_TO(58);
         //
         STEP05 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP05    == 102 ){
         STEP05P    = 102;
         REG05SW__V = 1002;
         REG05R___M = OFF;
         STEP05_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP05=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//  ���-�몫 ॣ���� � ࠡ�� � ��⮬���᪮� ०���
vd  far Regul_05(vd){
    //  ��⠭���� ��� ࠡ��� ॣ����, ��।��塞� �����஬:
    //  �६� �������� �ࠡ�⪨ �஢�� ��.���� 楬���
    if (TIME_LEV5M <  0){ TIME_LEV5M = 2; }
    if (TIME_LEV5M != TIME_LEV5V){ TIME_LEV5V = TIME_LEV5M; }    // 2 MIN
    //  �६� �������� ᨣ���� �� ������ ᪫��� 楬���
    if (TIME_OSC5M <  0){ TIME_OSC5M = 5; }
    if (TIME_OSC5M != TIME_OSC5V){ TIME_OSC5V = TIME_OSC5M; }    // 5 MIN
    //  �६� ���㧪� ��.���� 楬���
    if (TIME_NAS5M <  0){ TIME_NAS5M = 3; }
    if (TIME_NAS5M != TIME_NAS5V){ TIME_NAS5V = TIME_NAS5M; }    // 3 MIN
    //  ������⢮ ��.���ᮢ ����㦥���� � �㭪�� 楬���
    if (LOAD_NS10M <  0){ LOAD_NS10M = 2; }
    if (LOAD_NS10M != LOAD_NS10V){ LOAD_NS10V = LOAD_NS10M; }    // 2 NAS
    //  �६� �������� �몫�祭�� ᨣ���� ������� �஢�� �㭪�� 楬���
    if (TIME_LLVCM <  0){ TIME_LLVCM = 4; }
    if (TIME_LLVCM != TIME_LLVCV){ TIME_LLVCV = TIME_LLVCM; }    // 4 MIN
    //  �६� �������� �ࠡ�⪨ ᨣ���� ���孥�� �஢�� �㭪�� 楬���
    if (TIME_BCEMM <  0){ TIME_BCEMM = 20; }
    if (TIME_BCEMM != TIME_BCEMV){ TIME_BCEMV = TIME_BCEMM; }    // 20 MIN
    //  �६� �த㢪� ��.���� 楬���
    if (TIME_PRDCM <  0){ TIME_PRDCM = 2;  }
    if (TIME_PRDCM != TIME_PRDCV){ TIME_PRDCV = TIME_PRDCM; }    // 2 MIN
    //  �६� �몫�祭�� �ᯨ�� ��᫥ �த㢪�
    if (TIME_PCASM <  0){ TIME_PCASM = 1;  }
    if (TIME_PCASM != TIME_PCASV){ TIME_PCASV = TIME_PCASM; }    // 1 MIN
    //  �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_CMPKW <  0){ TIME_CMPKW = 5;  }                     // 5 SEC
    //  ���稪 ������⢠ ����஢��
    if (COUN_CMDZW <  0){ COUN_CMDZW = 4;  }                      // 4 DOZ
    //  ����஫� ������� �஢�� �㭪�� 楬���
    if (CTRL_LLBCM <  0){ CTRL_LLBCV = ON; CTRL_LLBCM = OFF; }    // ON
    if (CTRL_LLBCM == SWITCH){ 
        CTRL_LLBCV = (CTRL_LLBCV!=ON) then_ ON else_ OFF; CTRL_LLBCM=OFF;
    }
    //  ����஫� ���孥�� �஢�� �㭪�� 楬���
    if (CTRL_HLBCM <  0){ CTRL_HLBCV = ON; CTRL_HLBCM = OFF; }    // ON
    if (CTRL_HLBCM == SWITCH){ 
        CTRL_HLBCV = (CTRL_HLBCV!=ON) then_ ON else_ OFF; CTRL_HLBCM=OFF;
    }
    //  ����஫� �஢�� �� ���� 楬���
    if (CTRL_LPCMM <  0){ CTRL_LPCMV = ON; CTRL_LPCMM = OFF; }    // ON
    if (CTRL_LPCMM == SWITCH){ 
        CTRL_LPCMV = (CTRL_LPCMV!=ON) then_ ON else_ OFF; CTRL_LPCMM=OFF;
    }

    // ����祭��-�몫�祭�� ॣ����
    if ( REG05RS__M == SWITCH ){ 
         REG05R___M = (REG05R___M==ON) then_ OFF else_ ON; REG05RS__M=OFF;
    }
    if ( REG05R___M != REG05R___V ){ 
         REG05R___M  =(REG05R___M==ON) then_ ON else_ OFF;
         REG05R___V  = REG05R___M;
         if ( REG05R___V == ON ){ Message(360); STEP05 =   0; }
         else                   { Message(361); STEP05 = 101; }
    }
   // �᫨ ॣ���� �몫�祭 � 蠣 ॣ���� �� �த㢪�- ���
   if ((REG05R___V == OFF) and (STEP05<30 or STEP05>31)){ 
        Regul_05m(); return; 
   }
   //-----------------------------------------------------------------------


   //------------------------------------------------------------------------
   // ����஫� ������⢠ ����஢�� 楬���
   if (RegRUN==ON){
       // �᫨ ��� ����� 300 �� � 䫠� ���稪�=0 㢥����� ���稪 ����㧪�
       if(AIW190___V>300 and FLAG_CMDZC==0)  { FLAG_CMDZZ++; }
       else                                  { FLAG_CMDZZ=0; }
       // �᫨ ��� ����� 50  �� � 䫠� ���稪�=1 㢥����� ���稪 ���㧪�
       if(AIW190___V<50  and FLAG_CMDZC==1)  { FLAG_CMDZV++; }
       else                                  { FLAG_CMDZV=0; }
       //---------
       // �᫨ ��� 㤥ন������ ����� 7 ᥪ - ��⠥�, �� ������ ����㦥�
       if(AIW190___V>300 and FLAG_CMDZC==0 and FLAG_CMDZZ== 7 ){
          FLAG_CMDZC=1;
       }
       // �᫨ ��� 㤥ন������ ����� 7 ᥪ - ��⠥�, �� ������ ���㦥�
       // (��諠 ���� ����஢��)
       if(AIW190___V<50  and FLAG_CMDZC==1 and FLAG_CMDZV== 7 ){
          FLAG_CMDZC=0;  COUN_CMDZC++;
       }
       //---------
       if(FLAG_CMDZZ>100){ FLAG_CMDZZ=100; }
       if(FLAG_CMDZV>100){ FLAG_CMDZV=100; }
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   //  �᫨ �� ����� �� �६����� ��⠭���� �����窨 楬���
   if (FLAG_0605A==ON and FLAG_05WTA==OFF){
       FLAG_0605A= OFF;
       Regul_05off();     // �몫���� �ᯮ���⥫�
       Timer_05off();
       DON161___V=ON;     // ��⠢��� ����� ⮫쪮 ���⨫��� �ᯨ�樨
       STEP05=30;         // �த㢪�
       STEP05_BACK=40;    // �������� ᨣ���� ࠧ�襭 �� �த����� �����祪
   }
   //-----------------------------------------------------------------------


   //-----------------------------------------------------------------------
   if ( STEP05 == 0 ){
      if(STEP05P!=0){
         Timer_05off();
      }; STEP05P =0;
      if ( RegRUN==OFF ){ return; }

      Regul_05off();
      // �᫨ ���� �����窨 楬��� � ��筮� ०��� - ���
      REG05SW__V = 0;
      if ( DIR100___V == MANUAL ){ Message(224); return; }
      // �᫨ ���� ᨣ��� ���孥�� �஢�� �㭪�� 楬��� - ���
      REG05SW__V = 1;
      if (CTRL_HLBCV==ON){
         switch ( Check_TO (51,TIME_LSTBV*2*SEC, DIH170___V,'=',OFF,TIME_LSTBV)){
             case RUN: { return;; }
             case BAD: { Clear_TO(51); return;; }
         }   
      }
      // �᫨ ���� ᨣ��� �஢�� ���������� 楬��� - ���
      REG05SW__V = 2;
      if (CTRL_LPCMV==ON){
         switch ( Check_TO (52,TIME_LSTBV*2*SEC, DIH100___V,'=',OFF,TIME_LSTBV)){
             case RUN: { return;; }
             case BAD: { Clear_TO(52); return;; }
         }
      }
      // �᫨ ���� ����஢�� 楬��� - ���
      REG05SW__V = 3;
      if (DIS172___V==ON and DIS180___V==ON){ return; }
      // �᫨ �ࠡ�⠫ ᨣ��� ������� �஢��� �㭪�� 楬��� - 
      // ��᫠�� ������� ᪫��� 楬��� ᨣ���
      REG05SW__V = 4;
      if (CTRL_LLBCV==ON){
         switch ( Check_TO (53,TIME_LSTBV*2*SEC, DIL170___V,'=',ON, TIME_LSTBV)){
             case RUN: { return;; }
             case BAD: { Clear_TO(53); return;; }
         }
      }
      DON091___V = ON;
      // �᫨ ��� ᨣ���� �� ������ ᪫��� 楬��� �������� �६�-
      // �뢥�� ᮮ�饭�� � ����� ������ (��८���᪨ �뢮���� ᮮ�饭)
      REG05SW__V = 5;
      switch ( Check_TO  (54, TIME_OSC5V*MIN, DIS091___V,'=',ON, 1 )){
          case RUN: { TIME_OSC5Min++; TIME_OSC5C=TIME_OSC5Min/MIN; return;; }
          case BAD: {
                       if(TIME_OSC51==ON){ Bell(1); }
                       if(TIME_OSC53==ON){ Message(222); }
                       Clear_TO(54); 
                       TIME_OSC5Min=0; 
                       TIME_OSC5C  =0; 
                       return;;
                    }
          case END: {  break;; }
      }
      // �᫨ ���⨫��� �ᯨ�樨 楬��� � ��筮� ०���- ᮮ�饭�� �������
      REG05SW__V = 6;
      switch ( Check_TO (55,1*MIN, DIR161___V,'=',ON, 2)){
          case RUN: { return;; }
          case BAD: { Message(204); Bell(1); Clear_TO(55); return;; }
      }
       //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
       REG05SW__V=7;
       if((DIR100___V==AUTO and (DIS101___V==ON or DIS102___V==ON)) ){
           switch ( Check_TO (56,1*MIN, ZERO,'=',ON, 2)){
              case RUN: { return;; }
              case BAD: { Message(265); Bell(1); Clear_TO(56); return;; }
           }
       }
      //  �᫨ ������⢮ ����஢�� 楬��� ����� ���������- ���
      REG05SW__V = 8;
      if (COUN_CMDZC<COUN_CMDZW){ return; }
      // ����� ⠩����
      Clear_TO(51);
      Clear_TO(52);
      Clear_TO(53);
      Clear_TO(54);
      Clear_TO(55);
      Clear_TO(56);
      Clear_TO(57); 
      Clear_TO(58);
      // ����� ���稪�
      TIME_LLVCCMin=0;
      TIME_LLVCC   =0;
      TIME_BCEMCMin=0;
      TIME_BCEMC   =0;
      TIME_OSC5Min =0; 
      TIME_OSC5C   =0;
      LOAD_NS10C   =0;
      FLAG_HLCMExit=OFF;
      REG05SW__V   =9;
      // �᫨ ���� ᨣ��� �� ����� ᪫��� 楬��� ��� ��砫� ����㧪�
      Message(223); 
      // ����� 䫠� ���⢥ত���� �����
      STEP05F= 0;
      STEP05 = 1;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 1 ){
      if(STEP05P!=1){
         Regul_05off(); 
         Timer_05off();
         REG05ZO1_W=11;
      }; STEP05P =1;
      if(RegRUN==OFF){ return; }
      // ����� ���⢥ত���� �� ������ � ��砫� ����㧪�
      REG05SW__V= 10;
      if(REG05ZO1_W==END){ REG05ZO1_W=OFF; Clear_TO(51); }
      switch(Check_TO(51,1*MIN, REG05ZO1_W,'=',YES, 1)){
         case RUN:{ return;; }
         case BAD:{ 
                    if(TIME_SG011==ON){ Bell(1); }
                    if(TIME_SG013==ON){ Message(227); }
                    REG05ZO1_W=REQ;
                    Clear_TO(51); 
                    return;
                  }
      }; Clear_TO(51);
      REG05SW__V=11;
      REG05ZO1_W=OFF;
      STEP05 = 2;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 2 ){
      if(STEP05P!=2){
         Regul_05off(); 
         Timer_05off();
      }; STEP05P =2;
      // ���� ᨣ��� ������� ᪫��� 楬���
      DON091___V= OFF;
      STEP05=22; 
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 22 ){
      if(STEP05P!=22){
         ;;
      }; STEP05P =22;
      if(RegRUN==OFF){ return; }

      // ������� ���⨫��� �ᯨ�樨 楬���
      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = OFF;  DON101___V = OFF;
      REG05SW__V= 20;
      switch ( Check_TO  (51, TIME_ISPRV*SEC, DIS161___V,'=',ON,  1 )){
          case RUN: { return;; }
      };  Clear_TO(51);
      REG05SW__V = 21;
      // ������� ������ ������ ���������� 楬���
      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = OFF;  DON101___V = OFF;
      switch ( Check_TO  (52, TIME_ISPKV*SEC, DIS101___V,'=',OFF,  1 )){
          case RUN: { return;; }
          case BAD: { 
                      if(DONCN05>2){ REG05R___M=OFF; return;; }
                      Isp05PD(&DON101___V,3,TIME_ISPPW,70, 22, 52); return;; 
                    }
          case END: { DONCN05=0; break;; }
      };  Clear_TO(52);
      REG05SW__V = 22;
      // ������ ������ ����� 楬��� � ����������
      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = ON;;  DON101___V = OFF;
      switch ( Check_TO  (53, TIME_ISPKV*SEC, DIS102___V,'=',ON,  1 )){
          case RUN: { return;; }
          case BAD: { 
                      if(DONCN05>2){ REG05R___M=OFF; return;; }
                      Isp05PD(&DON102___V,3,TIME_ISPPW,70, 22, 53); return;; 
                    }
          case END: { DONCN05=0; break;; }
      }
      switch ( Check_TO  (54, TIME_CMPKW*SEC, ZERO,'=',ON, 1)){
          case RUN: { return;; }
      }
      Clear_TO(53);
      Clear_TO(54);
      REG05SW__V = 23;
      STEP05 = 3;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 3){
      if(STEP05P!=3){
         TIME_LEV5CMin=0;
         TIME_LEV5C   =0;
      }; STEP05P =3;
      if(RegRUN==OFF){ return; }

      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = ON;;  DON101___V = OFF;
      // ����� �ࠡ�⪨ ᨣ���� �஢�� ���������� ����� 楬���
      REG05SW__V = 30;
      switch ( Check_TO  (51, TIME_LEV5V*MIN, DIH100___V,'=',ON, TIME_LSTBV )){
          case RUN:{ 
                     TIME_LEV5CMin++; TIME_LEV5C=TIME_LEV5CMin/MIN; return;; 
                   }
          // ����㧪� ���������� 楬��� �����稫��� �� �६���
          case BAD:{ 
                     if(TIME_LEV51==ON){ Bell(1); }
                     if(TIME_LEV53==ON){ Message(225); }
                     break;;
                   }
          // ����㧪� ���������� 楬��� �����稫��� �� �஢��
          case END:{ 
                     // �᫨ �몫 ����� �� �஢�� ��.����- ����� �६�
                     if(CTRL_LPCMV==OFF){
                        if(TIME_LEV5CMin>TIME_LEV5V){ break; }
                        TIME_LEV5CMin++; TIME_LEV5C=TIME_LEV5CMin/MIN; return;; 
                     }
                     if(TIME_LEV53==ON ){ Message(226); }
                     break;; 
                   }
      }
      Clear_TO(51);
      REG05SW__V = 31;
      STEP05_BACK= 0;
      STEP05 = 4;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 4){
      if(STEP05P!=4){
         Clear_TO(57); 
         Clear_TO(58); 
      }; STEP05P =4;
      if(RegRUN==OFF){ return; }

      // ������� ������ ����� 楬��� � ����������
      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = OFF;  DON101___V = OFF;
      REG05SW__V = 40;
      switch ( Check_TO  (51, TIME_ISPKV*SEC, DIS102___V,'=',OFF, 1 )){
          case RUN: { return;; }
          case BAD: { 
                      if(DONCN05>2){ REG05R___M=OFF; return;; }
                      Isp05PD(&DON102___V,3,TIME_ISPPW,70, 4, 51); return;; 
                    }
          case END: { DONCN05=0; break;; }
      };  Clear_TO(51);
      switch ( Check_TO  (54, TIME_CMPKW*SEC, ZERO,'=',ON, 1)){
          case RUN: { return;; }
      }
      REG05SW__V = 41;
      // ������ ������ ������ ���������� 楬���
      // �ᯨ���       楬���             ������
      DON161___V = ON;;  DON102___V = OFF;  DON101___V = ON;;
      switch ( Check_TO  (52, TIME_ISPKV*SEC, DIS101___V,'=',ON,  1 )){
          case RUN: { return;; }
          case BAD: { 
                      if(DONCN05>2){ REG05R___M=OFF; return;; }
                      Isp05PD(&DON101___V,3,TIME_ISPPW,70, 4, 52); return;; 
                    }
          case END: { DONCN05=0; break;; }
      };  Clear_TO(52);
      REG05SW__V = 42;

      //---------------------------------------------------------------------
      // ���稪 �������� �몫�祭�� ᨣ���� ������� �஢�� �㭪�� 楬���:
      switch ( Check_TO  (58, TIME_LLVCV*MIN, DIL170___V,'=',OFF, TIME_LSTBV )){
          case RUN:{ 
                     TIME_LLVCCMin++; TIME_LLVCC=TIME_LLVCCMin/MIN; break;; 
                   }
          // �᫨ �� �������� �६� ᨣ��� ������� �஢�� �㭪�� 楬���
          // ��⠫�� �ࠡ�⠭��
          case BAD:{ 
                     if(TIME_LLVC1==ON){ Bell(1); }
                     if(TIME_LLVC3==ON){ Message(368); }
                     break;;
                   }
          case END:{ 
                     break;;
                   }
      }
      //-------------------------------------------------------------------
      // ���稪 �������� �ࠡ�⪨ ���孥�� �஢�� �㭪�� 楬���:
      switch ( Check_TO  (57, TIME_BCEMV*MIN, DIH170___V,'=',ON, TIME_LSTBV )){
          case RUN:{ 
                     TIME_BCEMCMin++; TIME_BCEMC=TIME_BCEMCMin/MIN; break;; 
                   }
          // �᫨ �� �������� �६� ᨣ��� ���孥�� �஢�� �㭪�� 楬���
          // �� �ࠡ�⠫- ������ � ᮮ�饭�� �������, �몫���� ॣ����
          case BAD:{ 
                     if(TIME_BCEM1==ON){ Bell(1); }
                     if(TIME_BCEM3==ON){ Message(367); }
                     FLAG_HLCMExit =ON;
                     return;;  
                   }
          // �� �������� �६� ᨣ��� ���� �஢�� �㭪�� 楬��� �ࠡ�⠫
          case END:{ 
                     // �᫨ �몫�祭 ����஫� ���� �஢��- ����� �६�
                     if(CTRL_HLBCV==OFF){
                        if(TIME_BCEMCMin>TIME_BCEMC){ FLAG_HLCMExit=ON; }
                        TIME_BCEMCMin++; TIME_BCEMC=TIME_BCEMCMin/MIN; break;; 
                     }
                     break;; 
                   }
      } 
      //---------------------------------------------------------------------


      //  ���㧨�� ���������� 楬��� �� �६���
      switch ( Check_TO  (53, TIME_NAS5V*MIN, ZERO,'=',ON,  1 )){
          case RUN: TIME_NAS5CMin++; TIME_NAS5C=TIME_NAS5CMin/MIN; return;;
      }
      Clear_TO(53);
      Clear_TO(54);
      REG05SW__V = 43;
      if( TIME_NAS51==ON ){ Bell(1); }
      if( TIME_NAS53==ON ){ Message(228); }
      //  �᫨ ᨣ��� �஢�� ���� ��⠫�� �ࠡ�⠭��- ᮮ�饭�� �������
      if( CTRL_LPCMV==ON && DIH100___V == ON ){ 
          Message(247); Bell(1); 
          REG05R___V = OFF;
      }
      STEP05 = 5;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 5 ){
      if(STEP05P!=5){
         ;;
      }; STEP05P =5;
      if(RegRUN==OFF){ return; }

      // ������� ������ ������ ���������� 楬���
      // �ᯨ���       楬���              ������
      DON161___V = ON;;  DON102___V = OFF;   DON101___V = OFF;
      REG05SW__V = 50;
      switch ( Check_TO  (51, TIME_ISPKV*SEC, DIS101___V,'=',OFF, 1 )){
          case RUN: { return;; }
          case BAD: { 
                      if(DONCN05>2){ REG05R___M=OFF; return;; }
                      Isp05PD(&DON101___V,3,TIME_ISPPW,70, 5, 51); return;; 
                    }
          case END: { DONCN05=0; break;; }
      };  Clear_TO(51);
      switch ( Check_TO  (54, TIME_CMPKW*SEC, ZERO,'=',ON, 1)){
          case RUN: { return;; }
      }   Clear_TO(54);
      REG05SW__V = 51;
      if(STEP05_BACK==101){ STEP05=101; }
      else                { STEP05=6; LOAD_NS10C++; }
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 6 ){
      if(STEP05P!=6){
         ;;
      }; STEP05P =6;
      Clear_TO(55);
      Clear_TO(56);
      REG05SW__V =60;
      //  �᫨ ���� ᨣ��� ���孥�� �஢�� �㭪�� 楬���,   ��३� �� ���0-
      //  ����� 横� ������ (����� �몫�祭�� ������� �஢�� �㭪�� 楬���)
      if ( CTRL_HLBCV == ON and DIH170___V == ON  ){
           if(LOAD_NS101==ON ){ Bell(1); }
           if(LOAD_NS103==ON ){ Message(248); }
           STEP05 = 7;   // �� �த㢪� � �� ��砫� 横�� ����㧪�
           return;
      }
      //  �᫨ ����㦥�� ������⢮ ���ᮢ ����� ���������, ��३� �� ���0-
      //  ����� 横� ������ (����� �몫�祭�� ������� �஢�� �㭪�� 楬���)
      if ( LOAD_NS10C >= LOAD_NS10V ){ 
           if(LOAD_NS101==ON ){ Bell(1); }
           if(LOAD_NS103==ON ){ Message(229); }
           STEP05 = 7;
           return;
      } 
      //  �᫨ ����㧪� �����稫��� �� �६���
      if ( FLAG_HLCMExit==ON ){ 
           Message(260); Bell(1);
           STEP05 = 7;
           return;
      }
      STEP05 = 2;        // �� ����⨥ ������� ������ � ᫥����� ����㧪�
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 7 ){
      if(STEP05P!=7){
         ;;
      }; STEP05P = 7;
      REG05SW__V = 70;
      // �ᯨ���       楬���              ������
      DON161___V = ON;;  DON102___V = OFF;   DON101___V = OFF;
      //  ����� 䫠� �����窨 楬��� ��� ॣ���� 06
      FLAG_05BGA = OFF;
      //
      COUN_CMDZC = 0;
      //  ��३� �� �த㢪� ��.����
      STEP05_BACK= 0;
      STEP05 = 30;  
      return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // �த㢪�
   if ( STEP05 == 30 ){
      if(STEP05P!=30){
         Regul_05off(); Timer_05off();
      }; STEP05P =30;
      if (RegRUN==OFF){ return; }

      REG05SW__V = 300;
      // �ᯨ���       楬���              ������
      DON161___V = ON;;  DON102___V = OFF;   DON101___V = ON;;
      // ����� �६� �த㢪�
      switch ( Check_TO  (51, TIME_PRDCV*MIN, ZERO,'=',ON,  1 )){
          case RUN: { TIME_PRDCCMin++; TIME_PRDCC=TIME_PRDCCMin/MIN; return;; }
      };  Clear_TO(51);
      REG05SW__V = 301;
      // ���� �������� �� �����⨥ ��� �ᯮ���⥫�� ॣ���� �஬� �ᯨ�
      // �ᯨ���       楬���              ������
      DON161___V = ON;;  DON102___V = OFF;   DON101___V = OFF;
      STEP05 = 31;
      return;
   }
   //------------------------------------------------------------------------
   if ( STEP05 == 31 ){
      if(STEP05P!=31){
         Clear_TO(51);
         TIME_PCASCMin=0;
      }; STEP05P =31;
      if (RegRUN==OFF){ return; }

      // ����� �६� �몫�祭�� �ᯨ�樨 ��᫥ �த㢪�
      REG05SW__V = 310;
      switch ( Check_TO  (51, TIME_PCASV*MIN, ZERO,'=',ON,  1 )){
          case RUN: { TIME_PCASCMin++; TIME_PCASC=TIME_PCASCMin/MIN; return;; }
      };  Clear_TO(51);
      REG05SW__V = 311;
      // ���� �������� �� �����⨥ ��� �ᯮ���⥫�� ॣ����
      // �ᯨ���       楬���              ������
      DON161___V = OFF;  DON102___V = OFF;   DON101___V = OFF; Regul_05off();
      STEP05=STEP05_BACK;
      return;
   }
   //------------------------------------------------------------------------

   //------------------------------------------------------------------------
   //   �������� ���� ����஢�� ��宣� ��� �த������� �����窨
   if ( STEP05 == 40 ){
      FLAG_05WTA=ON;
      STEP05 = 41;
   }
   if ( STEP05 == 41 ){
      if(STEP05P!=41){
         ;;
      }; STEP05P =41;
      if (FLAG_0605A == FLAG_05WTA){ 
          FLAG_0605A=OFF;
          FLAG_05WTA=OFF;
          STEP05=0; 
      }
      return;
   }
   //------------------------------------------------------------------------

   //------------------------------------------------------------------------
   //  �������� ������� �������� ����஢�� 楬��� ��� �த�������
   //  �����祪
   if ( STEP05 == 50 ){
      if(STEP05P!=50){
         ;;
      }; STEP05P =50;
      REG05SW__V =500;
      return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   // �������������� ��������
   //------------------------------------------------------------------------
   if ( STEP05 ==70 ){
        if(STEP05P!=70){
           ;;
        }; STEP05P =70;
        if(RegRUN==OFF){ return; }
        if(DONCN05>=DONCH05){ STEP05 = STEP05_PRBK; return; }
        REG05SW__V =700;
        if(Check_TO(205, DONTM05*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(205);
       *DONPR05=(*DONPR05!=ON)?ON:OFF;
        DONCN05++;
        STEP05 = STEP05_PRBK;
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
   Regul_05m();
   return;
}
//---------------------------------------------------------------------------
