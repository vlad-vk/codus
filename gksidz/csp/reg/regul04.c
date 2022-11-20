//---------------------------------------------------------------------------
// �����窠 ���饣�

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR04;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN04=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH04=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM04=2;               // ���-�� ᥪ㭤 ��� � ����
_i far  FBell04=0;               // 䫠� ������ ॣ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp04PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR04= IOPNT;
    DONCH04= hM;
    DONTM04= hS;
    STEP04 = Step; 
    STEP04_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Timer_04off(vd){
    TIME_LLVVCMin = 0;
    TIME_LLVVC    = 0;
    TIME_BVAJCMin = 0;
    TIME_BVAJC    = 0;
    TIME_PVASCMin = 0;
    TIME_PVASC    = 0;
    TIME_POASCMin = 0;
    TIME_POASC    = 0;
    TIME_GON_C    = 0;
    TIME_GOFFC    = 0;
    return;
}
//---------------------------------------------------------------------------
//  ��⠭���� ������� �� �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_04off(vd){
    DON111___V =  OFF;
    DON112___V =  OFF;
    DON121___V =  OFF;
    DON122___V =  OFF;
    DON131___V =  OFF;
    DON111     =  OFF;
    DON112     =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_04m(vd){
    //-----------------------------------------------------------------------
    if ( STEP04  == 101 ){
         if (RegRUN==OFF){ return; }
         REG04SW__V=1001;
         // �������� �� �����⨥ �������� ������஢ � ����� ������
         DON111___V=OFF; DON112___V=OFF; DON121___V=OFF; DON122___V=OFF;
         // ����� �६� �몫�祭�� �ᯨ�樨 ��᫥ �����窨
         switch ( Check_TO  (41, TIME_PVASV*MIN, ZERO,'=',ON,  1 )){
            case RUN: { TIME_PVASCMin++; TIME_PVASC=TIME_PVASCMin/MIN; return;; }
            default : { break;; }
         }; Clear_TO(41);
         // �������-�몫���� �� �ᯮ���⥫�
         Regul_04off();
         // ��� 䫠���
         COUN_VJDZC=COUN_VJDZW;
         // ��� ⠩��஢
         Clear_TO(41);
         Clear_TO(42);
         Clear_TO(43);
         Clear_TO(44);
         Clear_TO(45);
         Clear_TO(46);
         Clear_TO(47);
         Clear_TO(48);
         FBell04=  0;
         STEP04 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04 == 102 ){
         STEP04P = 102;
         REG04SW__V = 1002;
         REG04R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP04=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// ��⠭����� ���ﭨ� ��室��� ᨣ����� ॣ����
vd far SetGomGen(vd){
   if ( CHAN_GOM1V == ON ){
        DON111___V =  DON111;
        DON112___V =  DON112;
        DON121___V =  OFF;
        DON122___V =  OFF;
   }
   if ( CHAN_GOM2V == ON ){
        DON121___V =  DON111;
        DON122___V =  DON112;
        DON111___V =  OFF;
        DON112___V =  OFF;
   }
}
//---------------------------------------------------------------------------
// ������� ���ﭨ� �室��� ᨣ����� ��� ॣ����
vd far GetGomGen(vd){
   if ( CHAN_GOM1V == ON ){
        DIH110 =DIH110___V; 
        DIL110 =DIL110___V; 
        DIS111 =DIS111___V; 
        DIS112 =DIS112___V;
   }
   if ( CHAN_GOM2V == ON ){
        DIH110 =DIH120___V; 
        DIL110 =DIL120___V; 
        DIS111 =DIS121___V; 
        DIS112 =DIS122___V;
   }
}
//---------------------------------------------------------------------------
vd  far Regul_04(vd){
    // ��⠭���� ��� ࠡ��� ॣ����, ��।��塞� �����஬:
    // �६� ࠡ��� ������� ������ ������������ 
    if (TIME_GON_M <  0){ TIME_GON_M = 10; }
    if (TIME_GON_M != TIME_GON_V){ TIME_GON_V = TIME_GON_M; }    // 10 SEC
    // �६� ���� ����祭�� ������� ������ ������������
    if (TIME_GOFFM <  0){ TIME_GOFFM = 30; }
    if (TIME_GOFFM != TIME_GOFFV){ TIME_GOFFV = TIME_GOFFM; }    // 30 SEC
    // �६� �������� ᨣ���� ���孥�� �஢�� �㭪�� ���饣�
    if (TIME_BVAJM <  0){ TIME_BVAJM = 15; }
    if (TIME_BVAJM != TIME_BVAJV){ TIME_BVAJV = TIME_BVAJM; }    // 15 MIN
    // �६� �������� ᨣ���� ������� �஢�� �㭪�� ���饣�
    if (TIME_LLVVM <  0){ TIME_LLVVM =  4; }
    if (TIME_LLVVM != TIME_LLVVV){ TIME_LLVVV = TIME_LLVVM; }    // 4 MIN
    // �६� ���� ��� �몫�祭�� �ᯨ�樨 ���饣� ��᫥ �����窨
    if (TIME_PVASM <  0){ TIME_PVASM =  2; }
    if (TIME_PVASM != TIME_PVASV){ TIME_PVASV = TIME_PVASM; }    // 2 MIN
    // �६� ���� ��᫥ ����祭�� �ᯨ�樨 ��। ����⨥� ��������
    if (TIME_POASW <  0){ TIME_POASW =  1; }                     // 1 MIN
    //  �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_VJPKW <  0){ TIME_VJPKW = 5;  }                     // 5 SEC
    //  ���稪 ������⢠ ����஢��
    if (COUN_VJDZW <  0){ COUN_VJDZW = 4;  }                      // 4 DOZ
    //  ����஫� ������� �஢�� �㭪�� ���饣�
    if (CTRL_LLBVM <  0){ CTRL_LLBVV = ON; CTRL_LLBVM = OFF; }    // ON
    if (CTRL_LLBVM == SWITCH){ 
        CTRL_LLBVV = (CTRL_LLBVV!=ON) then_ ON else_ OFF; CTRL_LLBVM=OFF;
    }
    //  ����஫� ���孥�� �஢�� �㭪�� ���饣�
    if (CTRL_HLBVM <  0){ CTRL_HLBVV = ON; CTRL_HLBVM = OFF; }    // ON
    if (CTRL_HLBVM == SWITCH){ 
        CTRL_HLBVV = (CTRL_HLBVV!=ON) then_ ON else_ OFF; CTRL_HLBVM=OFF;
    }
    //  ����஫� ������� �஢�� ������������
    if (CTRL_LLGMM <  0){ CTRL_LLGMV = ON; CTRL_LLGMM = OFF; }    // ON
    if (CTRL_LLGMM == SWITCH){ 
        CTRL_LLGMV = (CTRL_LLGMV!=ON) then_ ON else_ OFF; CTRL_LLGMM=OFF;
    }

    // �롮� ������������ �����஬
    if ( CHAN_GOM1W == SWITCH ){ CHAN_GOM1W=ON; CHAN_GOM2W=OFF; }
    if ( CHAN_GOM2W == SWITCH ){ CHAN_GOM2W=ON; CHAN_GOM1W=OFF; }

    // ����祭��-�몫�祭�� ॣ����
    if ( REG04RS__M == SWITCH ){ 
         REG04R___M = (REG04R___M==ON) then_ OFF else_ ON; REG04RS__M=OFF;
    }
    if ( REG04R___M != REG04R___V ){ 
         REG04R___M  =(REG04R___M==ON) then_ ON else_ OFF;
         REG04R___V  = REG04R___M;
         if ( REG04R___V == ON ){ Message(350); STEP04=0; }
         else                   { Message(351); STEP04=101; }
    }
    //  �᫨ ॣ���� �몫�祭 - ���
    if ( REG04R___V == OFF ){ Regul_04m(); return; }

    // ����� 横� ��।��塞 ᮮ⢥��⢨� ��६�����
    GetGomGen(); SetGomGen();

    // �᫨ ॣ���� ����஢�� ��宣� � ०��� ����஢�� ���饣�-
    // ��३� �� 蠣 �������� ����砭�� ����஢�� ���饣�
    if(STEP04>0 and STEP04<5 and STEP06>=6 and STEP06<=12){ STEP04=20; }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ����஫� ������⢠ ����஢�� ���饣�
    if (RegRUN==ON){
        // �᫨ ��� ����� 700 �� � 䫠� ���稪�=0 㢥����� ���稪 ����㧪�
        if(AIW190___V>600 and FLAG_VJDZC==0)  { FLAG_VJDZZ++; }
        else                                  { FLAG_VJDZZ=0; }
        // �᫨ ��� ����� 50  �� � 䫠� ���稪�=1 㢥����� ���稪 ���㧪�
        if(AIW190___V<50  and FLAG_VJDZC==1)  { FLAG_VJDZV++; }
        else                                  { FLAG_VJDZV=0; }
        //---------
        // �᫨ ��� 㤥ন������ ����� 4 ᥪ - ��⠥�, �� ������ ����㦥�
        if(AIW190___V>600 and FLAG_VJDZC==0 and FLAG_VJDZZ== 4 ){
           FLAG_VJDZC=1;
        }
        // �᫨ ��� 㤥ন������ ����� 4 ᥪ - ��⠥�, �� ������ ���㦥�
        // (��諠 ���� ����஢�� ���饣�)
        if(AIW190___V<50  and FLAG_VJDZC==1 and FLAG_VJDZV== 4 ){
           FLAG_VJDZC=0;  COUN_VJDZC++;
        }
        //---------
        if(FLAG_VJDZZ>100){ FLAG_VJDZZ=100; }
        if(FLAG_VJDZV>100){ FLAG_VJDZV=100; }
    }
    //-----------------------------------------------------------------------

    // ��४��祭�� �����������஢ �/� ��᫥�������� 
    // �� �㭪樨 ����஫� �ᯮ���⥫��

    //-----------------------------------------------------------------------
    if ( STEP04 == 0 ){
       if(STEP04P!=0){
          ;;
       }; STEP04P =0;
       if (RegRUN==OFF){ return; }

       Regul_04off();
       //  ��砫쭮� ���ﭨ� �롮� ������������
       CHAN_GOM1V = OFF; 
       CHAN_GOM2V = OFF; CHANGE = OFF;
       //  䫠� �����窨 ���饣�
       FLAG_0406A = OFF;
       //  �᫨ �ࠢ����� ��४��祭� �� ��⮬�� � ��� ᨣ����
       //  ������� �஢��� 1-�� ������������- ����� 1-� ������������
       if ( DIR110___V == AUTO and 
            DIL110___V == OFF  and CHAN_GOM1W==ON ){
            CHAN_GOM1V =  ON; 
            CHAN_GOM2V =  OFF; CHANGE = ON;
       } 
       //  �᫨ �� ��࠭ 1-� ������������-  ����� 2-��
       if ( DIR120___V == AUTO and 
            DIL120___V == OFF  and CHAN_GOM1V == OFF){
            CHAN_GOM1V =  OFF;
            CHAN_GOM2V =  ON;  CHANGE = ON;
       }
       REG04SW__V=0;
       //  �᫨ �� ��࠭ ������ ������������- �����, ᮮ�饭�� �������
       switch ( Check_TO  (41, 5*MIN, CHANGE,'=',ON,  1 )){
           case RUN: { return;; }
           case BAD: { Message(200); Clear_TO(41); return;; }
       };  Clear_TO(41);
       //  �᫨ ���� ���孨� �஢��� � �㭪��- ������� �� ��稭���
       REG04SW__V=1;
       if (CTRL_HLBVV==ON and DIH140___V==ON){ return; }
       //  �᫨ ��� ᨣ���� ������� �஢��� �㭪�� ���饣�- 
       //  ��� �� ॣ����. ���� ����� �������.
       REG04SW__V=2;
       if (CTRL_LLBVV==ON){
          switch ( Check_TO (42, TIME_LSTBV*2*SEC, DIL140___V,'=',ON, TIME_LSTBV)){
              case RUN: { return;; }
              case BAD: { Clear_TO(42); return;; }
          }
       }  Clear_TO(42);
       //  �᫨ �� ⥪�騩 ������ �६��� ���� ����஢�� (����� ������
       //  ����� ���饣� �� 譥� � ����祭 譥�)- ������� ���� ����஢��
       //  ��᫥ 祣� ��稭��� �������
       REG04SW__V=3;
       switch ( Check_TO  (43,  4*SEC, DIS142___V,'=',OFF,  2)){
           case RUN: { return;; }
           case BAD: { Clear_TO(43); return;; }
       }  
       switch ( Check_TO  (44,  4*SEC, DIS150___V,'=',OFF,  2)){
           case RUN: { return;; }
           case BAD: { Clear_TO(44); return;; }
       }
       //  �஢�ઠ ��砫쭮�� ���ﭨ� ��� �ᯮ���⥫�� ॣ����
       REG04SW__V=4;
       if((DIR110___V==AUTO and (DIS111___V==ON or DIS112___V==ON)) or 
          (DIR120___V==AUTO and (DIS121___V==ON or DIS122___V==ON)) ){
           switch ( Check_TO (45,1*MIN, ZERO,'=',ON, 2)){
              case RUN: { return;; }
              case BAD: { Message(264); Bell(1); Clear_TO(45); return;; }
           }
       }
       //  �᫨ ������⢮ ����஢�� 諠�� ����� ���������- ���
       REG04SW__V=5;
       if (COUN_VJDZC<COUN_VJDZW){ return; }
       //  �᫨ ��蠫�� ��室�� �� ����- ����� �������
       REG04SW__V=6;
       if(REG04ZO1_W==END){ REG04ZO1_W=OFF; Clear_TO(46); }
       if(DIR140___V==OFF){
          switch ( Check_TO (46,60*SEC, REG04ZO1_W,'=', YES, 2)){
              case RUN: { return;; }
              case BAD: { 
                          REG04ZO1_W=REQ; Message(282); Bell(1); Clear_TO(46);
                          return;; 
                        }
          }
       }
       REG04SW__V=7;
       //  ����� ���稪�
       REG04ZO1_W=OFF;
       Timer_04off();
       //  ����� ⠩����
       Clear_TO(41);
       Clear_TO(42);
       Clear_TO(43);
       Clear_TO(44);
       Clear_TO(45);
       Clear_TO(46);
       Clear_TO(47);
       Clear_TO(48);
       //  ��砫쭮� ���ﭨ� ��������- �� ������
       Regul_04off();
       //
       FLAG_HLBVExit=OFF;
       STEP04 = 1;
       return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04 == 1 ){
       if(STEP04P!=1){
          TIME_POASCMin=0;
          TIME_POASC   =0;
       }; STEP04P =1;
       if(RegRUN==OFF){ return; }

       REG04SW__V=10;
       //  ������� ���⨫��� �ᯨ�樨 ���饣�
       //  �ᯨ���      �������
       DON131___V = ON;;  DON112 = OFF;
       switch ( Check_TO  (41, TIME_ISPRV*SEC, DIS131___V,'=',ON,  1 )){
           case RUN: { return;; }
           case BAD: { 
                       if(DONCN04>2){ REG04R___M=OFF; return;; }
                       Isp04PD(&DON131___V,3,TIME_ISPPW,70, 1, 41); return;; 
                     }
           case END: { DONCN04=0; break;; }
       };  DONCN04=0;
       REG04SW__V=11;
       //  ������� �६� ���� ��᫥ ���祭�� ���⨫��� �ᯨ�樨 ���饣�
       switch ( Check_TO  (42, TIME_POASW*MIN, ZERO,'=',ON,  1 )){
           case RUN:{ TIME_POASCMin++; TIME_POASC=TIME_POASCMin/MIN; return;; }
       }
       Clear_TO(41);
       Clear_TO(42);
       STEP04 = 2;
       return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04  ==2){
       if(STEP04P!=2){
          ;;
       }; STEP04P =2;
       if (RegRUN==OFF){ return; }

       REG04SW__V=20;
       //  ������ ������ ������ �� �������
       //  �ᯨ���      �������
       DON131___V = ON;;  DON112 = ON;;
       switch ( Check_TO  (41, TIME_ISPKV*SEC, DIS112,'=',ON,  1 )){
           case RUN: { return;; }
           case BAD: { 
                       if(DONCN04>2){ REG04R___M=OFF; return;; }
                       Isp04PD(&DON112,3,TIME_ISPPW,70, 2, 41); return;; 
                     }
       };  DONCN04=0;
       REG04SW__V=21;
       //  ������ ᨣ��� �� ����⨥ ������� ������
       DON111 = ON;
       switch ( Check_TO  (44, TIME_VJPKW*SEC, ZERO,'=',ON, 1)){
           case RUN: { return;; }
       }   
       Clear_TO(41);
       Clear_TO(42);
       Clear_TO(43);
       Clear_TO(44);
       //
       FLAG_0406A = ON;
       TIME_GG_CONTROL=TIME_GON_V; 
       TIME_GON_C=0; 
       TIME_GOFFC=0;
       GKV_POL= ON;
       STEP04 = 3;
       return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04 == 3){
       if(STEP04P!=3){
          Clear_TO(41);
          Clear_TO(42);
          Clear_TO(43);
          Clear_TO(44);
          FBell04 =0;
       }; STEP04P =3;
       if (RegRUN==OFF){ return; }

       //  �ᯨ���    �������
       DON131___V=ON;;  DON112 = ON;;
       REG04SW__V=30;
       //  ��८���᪨ ������-������� ������ ����� ������ �� ������������
       switch ( Check_TO  (41, (TIME_GG_CONTROL*SEC), OFF,'i',ON, 1 )){
           //  ���稪 �६��� ������-������� ������� ��� ������
           case RUN: {
                       if (GKV_POL== ON){ TIME_GON_C++; TIME_GOFFC=0; }
                       else             { TIME_GOFFC++; TIME_GON_C=0; }
                       break;;
                     }
           //  �᫨ ��諮 ��⠭�������� �६� - �������� ���ﭨ� �������
           //  ����� ������ �� ������������ � �६� ����஫� ⮦�
           case BAD: {
                       if (GKV_POL==ON){
                           DON111 = OFF; TIME_GG_CONTROL=TIME_GOFFV; 
                           GKV_POL= OFF;
                       } else {
                           DON111 = ON;  TIME_GG_CONTROL=TIME_GON_V; 
                           GKV_POL= ON;
                       }
                       Clear_TO(41); 
                       break;;
                     }
       }
       REG04SW__V=31;

       //-------------------------------------------------------------------
       // ���稪 �������� �몫�祭�� ᨣ���� ������� �஢�� �㭪�� ���饣�:
       switch ( Check_TO  (42, TIME_LLVVV*MIN, DIL140___V,'=',OFF, TIME_LSTBV )){
           case RUN:{ 
                      TIME_LLVVCMin++; TIME_LLVVC=TIME_LLVVCMin/MIN; break;; 
                    }
           // �᫨ �� �������� �६� ᨣ��� ������� �஢�� �㭪�� ���饣�
           // ��⠫�� �ࠡ�⠭��
           case BAD:{ 
                      if(FBell04==0){
                         if(TIME_LLVV1==ON){ Bell(1); }
                         if(TIME_LLVV3==ON){ Message(358); }
                         FBell04=1;
                      }
                      break;;
                    }
           // �� �������� �६� ᨣ��� ������� �஢�� �㭪�� ���饣� �ய��
           case END:{ 
                      // �᫨ �몫 ����� ��� �஢�� �㭪 ��- ����� �६�
                      if(CTRL_LLBVV==OFF){
                         TIME_LLVVCMin++; TIME_LLVVC=TIME_LLVVCMin/MIN;
                      }
                      break;; 
                    }
       } 
       //-------------------------------------------------------------------
       //  ��᫥ ��।�������� �६���, �᫨ ��� ᨣ���� ���孥�� �஢��
       //  �㭪�� ���饣�- ��᫠�� ᮮ�饭�� ������� � �� ᫥���騩 蠣
       //  �᫨ ���� ᨣ��� ���孥�� �஢��- 
       //  ��३� �� ᫥���騩 蠣 ��� ��������
       switch ( Check_TO  (43, TIME_BVAJV*MIN, DIH140___V,'=',ON, TIME_LSTBV)){
          case RUN:{ 
                     TIME_BVAJCMin++; TIME_BVAJC=TIME_BVAJCMin/MIN; return;;
                   }
          case BAD:{ 
                     if(TIME_BVAJ1==ON){ Bell(1); }
                     if(TIME_BVAJ3==ON){ Message(246); }
                     FLAG_HLBVExit=ON;
                     Clear_TO(43);
                     break;;
                   }
          case END:{ 
                     // �᫨ �몫 ����� ���� �஢�� �㭪 ��- ����� �६�
                     if(CTRL_HLBVV==OFF){
                        if(TIME_BVAJCMin>TIME_BVAJV){ 
                           Message(246); Bell(1);
                           Clear_TO(43);
                           FLAG_HLBVExit=ON; break;;
                        }
                        TIME_BVAJCMin++; TIME_BVAJC=TIME_BVAJCMin/MIN; return;; 
                     } else {
                        Clear_TO(43);
                        Message(202);
                     }
                     break;;
                   }
       } 
       //-------------------------------------------------------------------

       //  �᫨ ����㧪� ��諠 �� �஢��- ���㫨�� ⠩���� � �� ᫥� 蠣
       REG04SW__V=32;
       Clear_TO(41);
       Clear_TO(42);
       Clear_TO(43);
       STEP04 = 4;
       return;
    }
    //-----------------------------------------------------------------------
    if (STEP04 == 4){
        if(STEP04P!=4){
           TIME_PVASCMin=0;
           TIME_PVASC   =0;
        }; STEP04P =4;
        if (RegRUN==OFF){ return; }
        //  �������� �� �����⨥ �������� �����窨
        //  �ᯨ���    �������     �����
        DON131___V=ON;;  DON112=OFF;  DON111=OFF;
        switch ( Check_TO  (44, TIME_VJPKW*SEC, ZERO,'=',ON, 1)){
            case RUN: { return;; }
        }   
        REG04SW__V=40;
        //  ����� �६� �몫�祭�� �ᯨ�樨 ��᫥ �����窨
        switch ( Check_TO  (41, TIME_PVASV*MIN, ZERO,'=',ON,  1 )){
            case RUN: { TIME_PVASCMin++; TIME_PVASC=TIME_PVASCMin/MIN; return;; }
            default : { break;; }
        }
        Clear_TO(41);
        Clear_TO(44);
        REG04SW__V=41;
        STEP04 = 5;
        return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04 == 5 ){
         if(STEP04P!=5){
            ;;
         }; STEP04P =5;
         REG04SW__V=50;
         //  ������� �� ������� � ���㫨�� ⠩����
         Regul_04off();
         COUN_VJDZC =0;
         STEP04 = 0;
         return;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ������� ����砭�� ����஢�� ���饣�
    if ( STEP04 == 20 ){
         if(STEP04P!=20){
            Regul_04off();
            STEP04_BACK=STEP04P;
         }; STEP04P =20;
         if(RegRUN==OFF){ return; }
         if(STEP06>=6 and STEP06<=12){ return; }
         // �᫨ ����஢�� ���饣� �����稫���- �த������ ������� ���饣�
         STEP04=STEP04_BACK;
         return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP04 ==70 ){
         if(STEP04P!=70){
            ;;
         }; STEP04P =70;
         if(RegRUN==OFF){ return; }
         if(DONCN04>=DONCH04){ STEP04 = STEP04_PRBK; return; }
         REG04SW__V =700;
         if(Check_TO(204, DONTM04*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(204);
        *DONPR04=(*DONPR04!=ON)?ON:OFF;
         DONCN04++;
         STEP04 = STEP04_PRBK;
         return;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_04m();
    return;
}
//---------------------------------------------------------------------------
