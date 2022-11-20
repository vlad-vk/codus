//---------------------------------------------------------------------------
// ����஢�� ��宣�

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR06;
_i far  DONCN06=0;                // ���稪 横�� ��।�ࣨ�����
_i far  DONCH06=2;                // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i far  DONTM06=2;                // ���-�� ᥪ㭤 ��� � ����

_i far  FLVB_ON=0;                // 䫠� ��।���� ����祭�� ����-����
_i far  IS06ERR=0;                // 䫠� �訡�� �ࠡ�⪨ �ᯮ���⥫��
_f far  TMVIBRUN=0;               // �६� ����祭�� ������|������

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp06PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR06= IOPNT;
    DONCH06= hM;
    DONTM06= hS;
    STEP06 = Step;
    STEP06_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_06off(vd){
    DON132___V =  OFF;
    DON141___V =  OFF;
    DON142___V =  OFF;
    DON143___V =  OFF;
    DON150___V =  OFF;
    DON151___V =  OFF;
    DON152___V =  OFF;

    DON162___V =  OFF;
    DON171___V =  OFF;
    DON172___V =  OFF;
    DON173___V =  OFF;
    DON180___V =  OFF;
    DON181___V =  OFF;
    DON182___V =  OFF;

    DON191___V =  OFF;
    DON192___V =  OFF;
    DON193___V =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_06m(vd){
    //-----------------------------------------------------------------------
    if ( STEP06 == 101 ){
         REG06SW__V=1001;
         if(RegRUN==OFF){ return; }
         Regul_06off();
         FLAG_0605A=OFF;
         FLAG_05WTA=OFF;
         STEP06 = 102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP06 == 102 ){
         STEP06P = 102;
         REG06SW__V=1002;
         REG06R___M=OFF;
         AIW190FV_V=0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP06=101;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Regul_06(vd){

    //  �롮� ०��� ���㧪� �� ������ ��宣�
    if (VGR_SHALLM==SWITCH){
        VGR_SHALLV=ON;; VGR_SHRECV=OFF; VGR_SHIZLV=OFF;
    }
    if (VGR_SHRECM==SWITCH){
        VGR_SHALLV=OFF; VGR_SHRECV=ON;; VGR_SHIZLV=OFF;
    }
    if (VGR_SHIZLM==SWITCH){
        VGR_SHALLV=OFF; VGR_SHRECV=OFF; VGR_SHIZLV=ON;;
    };  VGR_SHALLM=OFF; VGR_SHRECM=OFF; VGR_SHIZLM=OFF;

    if (BLCEMP___M== SWITCH){
        BLCEMP___V =(BLCEMP___V==ON) then_ OFF else_ ON; BLCEMP___M=OFF;
    }
    if (BLVYGP___M== SWITCH){
        BLVYGP___V =(BLVYGP___V==ON) then_ OFF else_ ON; BLVYGP___M=OFF;
    }
    if (BLNSUH___M== SWITCH){
        BLNSUH___V =(BLNSUH___V==ON) then_ OFF else_ ON; BLNSUH___M=OFF;
    }

    //  ����祭��-�몫�祭�� ॣ����
    if ( REG06RS__M == SWITCH ){
         REG06R___M = (REG06R___M==ON) then_ OFF else_ ON; REG06RS__M=OFF;
    }
    if ( REG06R___M != REG06R___V ){
         REG06R___M  =(REG06R___M==ON) then_ ON else_ OFF;
         REG06R___V  = REG06R___M;
         if ( REG06R___V == ON ){ Message(370); STEP06 =   0; }   // ��⮬��
         else                   { Message(371); STEP06 = 101; }   // ��筮�
    }
    //  ����㧪�-���㧪�
    if ( REG06ZV__M != REG06ZV__V ){
         REG06ZV__M  =(REG06ZV__M>=ON) then_ ON else_ OFF;
         REG06ZV__V  = REG06ZV__M;
         if(REG06ZV__V>0){ Message(372); }                        // ����㧪�
         else            { Message(373); }                        // ���㧪�
    }
    //  ��騩-�������
    if ( REG06GL__M != REG06GL__V ){
         REG06GL__M  =(REG06GL__M==ON) then_ ON else_ OFF;
         REG06GL__V  = REG06GL__M;
         if(REG06GL__V>0){ Message(374); }                        // ��騩
         else            { Message(375); }                        // �������
    }
    //  �᫨ ॣ���� �몫�祭 - ���
    if ( REG06R___V == OFF ){ Regul_06m(); return; }

    //  �᫨ �� �६� ���㧪� ��宣� ������� ��ଥ⨧���-
    //  ������� ������ ���㧪� � �몫���� ॣ����
    if (STEP06>=32 and STEP06<=33 and DIS31A___V==OFF){
        Bell(1); Message(115); Message(676); Regul_06off(); 
        REG06R___M=OFF; return;
    }


    //  �������� ��������� ����������:
    //-----------------------------------------------------------------------
    if ( STEP06 == 0 ){
        if(STEP06P!=0){
           ;;
        }; STEP06P =0;
        if (RegRUN==OFF){ return; }

        Regul_06off();

        //-------------------------------
        //  ���� �㭪�� 楬���
        REG06SW__V =0;
        if(DIR170___V==MANUAL and (REG06ZV__V==ON or DON801___V==0)){ return; }

        //  ���� �㭪�� ���饣�
        REG06SW__V =1;
        if(DIR140___V==MANUAL and (REG06ZV__V==ON or DON801___V==0)){ return; }

        //  ���� ������ ��宣�
        REG06SW__V =2;
        if(DIR190___V==MANUAL){ return; }

        //-------------------------------
        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� �㭪�� 楬���
        REG06SW__V =3;
        if (DIR170___V==AUTO and
           (DIS171___V==ON or DIS172___V==ON or DIS173___V==ON or
            DIS180___V==ON or DIS181___V==ON or DIS182___V==ON)){
            switch(Check_TO(61,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(61); return;; }
            }
        };  Clear_TO(61);

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� �㭪�� ���饣�
        REG06SW__V =4;
        if (DIR140___V==AUTO and
           (DIS141___V==ON or DIS142___V==ON or DIS143___V==ON or
            DIS150___V==ON or DIS151___V==ON or DIS152___V==ON)){
            switch(Check_TO(62,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(62); return;; }
            }
        };  Clear_TO(62);

        //  �஢�ઠ ��砫쭮�� ���ﭨ� �ᯮ���⥫�� ������ ��宣�
        REG06SW__V =5;
        if (DIR190___V==AUTO and
           (DIS191___V==ON or DIS192___V==ON or DIS193___V==ON)){
            switch(Check_TO(63,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(63); return;; }
            }
        };  Clear_TO(63);

        //  �஢�ઠ ��砫쭮�� ���ﭨ� 譥���
        REG06SW__V =6;
        if((DIR130___V==AUTO and DIS132___V==ON) or
           (DIR160___V==AUTO and DIS162___V==ON) ){
            switch(Check_TO(64,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(64); return;; }
            }
        };  Clear_TO(64);

        //  �஢�ઠ ������� �஢�� �㭪�� 楬���
        REG06SW__V =7;
        if(DIL170___V==ON and CTRL_LLBCV==ON){
           // ������ �஢��� �᫨ ॣ���� � ��饬 ०��� ��� �᫨
           // ॣ���� � �����쭮� ०��� � ����祭� ����㧪�
           if(REG06GL__V==ON  and DON801___V==0 ){ return; }
           if(REG06GL__V==OFF and REG06ZV__V==ON){ return; }
        };

        //  �஢�ઠ ������� �஢�� �㭪�� ���饣�
        if(DIL140___V==ON and CTRL_LLBVV==ON){
           // ������ �஢��� �᫨ ॣ���� � ��饬 ०��� ��� �᫨
           // ॣ���� � �����쭮� ०��� � ����祭� ����㧪�
           if(REG06GL__V==ON  and DON801___V==0 ){ return; }
           if(REG06GL__V==OFF and REG06ZV__V==ON){ return; }
        };

        //  �஢�ઠ 䫠�� ࠡ��ᯮᮡ���� �ਡ�� ������ ��宣�
        REG06SW__V =8;
        if( COM2ER01FL==ON ){ return; }

        REG06SW__V =9;
        //-------------------------------
        //  ��������:
        //  ॣ���� ����祭 �� ����㧪� ��� ��������� ࠡ���
        if( REG06ZV__V == ON and REG06GL__V == OFF){
            // �஢�ઠ ��������� ���� (�� OFF)
            if(DIS315___V==ON){ return; }
            // �஢�ઠ ��ଥ⨧���  (�� OFF)
            if(DIS31A___V==ON){ return; }
            DON801___V=0;
            STEP06 = 1;
        }

        //  ॣ���� ����祭 ��� ����� ࠡ��� � ������ ��宣� ���㦥�
        if( RegPublicV == ON  and REG06GL__V == ON and DON801___V == 0 ){
            // �஢�ઠ ��������� ���� (�� OFF)
            if(DIS315___V==ON){ return; }
            // �஢�ઠ ��ଥ⨧���  (�� OFF)
            if(DIS31A___V==ON){ return; }
            STEP06 = 1;
        }
        //-------------------------------

        //-------------------------------
        //  �������� ����
        //  �᫨ ������ ��宣� ����㦥� � ������ ���ண� ���㦥�
        //  � ����祭 ��騩 ॣ���� � ��� ������ ���ண� ����� �����⨬-
        //  ��३� �� 蠣 ���㧪�
        if( DON801___V==1 and DON802___V==2 and RegPublicV==ON and
            REG06GL__V==ON ){
            STEP06=31;
        }

        //  �������� �����쭠�
        //  �᫨ ����祭 ������� ॣ���� � ����祭� ���㧪�
        //  � ������ ���ண� ���㦥� ��� ॣ���� 07 �몫�祭
        //  � ��� ������ ���ண� ����� ����筮�� -
        //  ��३� �� 蠣 ���㧪�
        if( REG06GL__V==OFF and REG06ZV__V==OFF and
          ( DON802___V==2   or  REG07R___V==OFF )){
            STEP06=31;
        }
        //-------------------------------

        Clear_TO(61);

        // ������� ����� ����� ⮫쪮 ���砫� ����㧪�
        if(STEP06==1){
           CRCEMA___V=0;
           CRCEMB___V=0;
           CRCEMS___V=0;
           CRVYGA___V=0;
           CRVYGB___V=0;
           CRVYGS___V=0;
           AIW190FV_V=0;
           AIW190NV_V=AIW190___V;           // ��砫�� ��� ������ ��宣�
        }

        return;
    }
    //-----------------------------------------------------------------------


   // ��������� ������� �� ���������:
   //------------------------------------------------------------------------
   if ( STEP06 == 1 ){
       if(STEP06P!=1){
          Regul_06off();
       }; STEP06P =1;
       if(RegRUN==OFF){ return; }
       KRCEM____F = 0;                 // 䫠� ���४�஢�� ���� ��� 楬���
       AIW190VO_V = TRCEMA_VIB+KRVYGS___V-DPCEMA___V;
       AIW190VZ_V = TRCEMA_VIB+KRVYGS___V;
       AIW190VB_V = TRCEMA_VIB+KRVYGS___V+BLCEMA___V;

       REG06SW__V =10;

       //  �᫨ 譥� ������ 楬��� � ��� ०���- ��३� �� ����� �� �㭪��
       if (DIR160___V == MANUAL){ STEP06 = 3; return; }

       //  �᫨ �楯�� ��� 楬��� �ᯨ�樨 ࠢ�� 0- ��३� �� 蠣 3
       if (TRCEMA_VIB == 0){ STEP06 = 3; return; }

       //  �᫨ ��� ������ ����� �楯⭮�� ��� 楬��� �ᯨ�樨 �����
       //  ��� ����᪠ ����� 楬��� �ᯨ�樨- ��३� �� 蠣 3
       if (AIW190___V>=TRCEMA_VIB){ STEP06 = 3; return; }

       //  ��� 楬��� �� �ᯨ�樨
       CRCEMA___V = AIW190___V-AIW190NV_V; AIW190FV_V=1;

       //  ������� 譥� �ᯨ�樨 楬���
       REG06SW__V = 11;
       DON162___V = ON;
       switch ( Check_TO  (61, TIME_ISPRV*SEC, DIS162___V,'=',ON,  1 )){
           case RUN: { return;; }
           case BAD: {
                        if(DONCN06 > 1){ break;; }
                        Isp06PD(&DON162___V,3,TIME_ISPPW,70,  1, 61);
                        return;;
                     }
       }; DONCN06=0;
       Clear_TO(61);
       STEP06=2;
       return;
   }
   //------------------------------------------------------------------------
   if ( STEP06 == 2 ){
        if(STEP06P!=2){
           AIW190___O=AIW190___V;
           AIW190___C=0;
           TMST_CAV_C=0;
        }; STEP06P =2;
        AIW190VO_V = TRCEMA_VIB+KRVYGS___V-DPCEMA___V;
        AIW190VZ_V = TRCEMA_VIB+KRVYGS___V;
        AIW190VB_V = TRCEMA_VIB+KRVYGS___V+BLCEMA___V;

        REG06SW__V = 20;

        //  �᫨ ⥪�騩 ��� ����� �楯⭮�� ��� ����� 楬��� �� �ᯨ�樨
        //  ����� ��� ����᪠ 楬��� �ᯨ�樨- ��३� �� 蠣 3.
        if (AIW190___V>=AIW190VO_V){ STEP06=3; return; }

        //  ��� 楬��� �� �ᯨ�樨
        CRCEMA___V = AIW190___V - AIW190NV_V; AIW190FV_V=2;

        //  �஢�ઠ �⠡�����樨 ���
        if (RegRUN==ON){ TMST_CAV_C++; }
        if (TMST_CAV_C>= TMST_CAV_W){
            if(AIW190___V-AIW190___O<VSST_CA__W){ AIW190___C++; }
            else                                { AIW190___C=0; }
            TMST_CAV_C=0;
            AIW190___O=AIW190___V;
        }

        //  �᫨ ��� �⠡�����஢���� (��� ����� ���)- �� ᫥���騩 蠣
        if (AIW190___C>2){ STEP06=3; return; }
        return;
   }
   //------------------------------------------------------------------------


   // ��������� ������� �� �������
   //------------------------------------------------------------------------
   if ( STEP06 == 3 ){
        if(STEP06P!=3){
           // �᫨ ����ࠫ� 楬��� �� �ᯨ�樨- ��������� ���
           if(AIW190FV_V==2){ CRCEMA___V=AIW190___V-AIW190NV_V; }
           KRCEM____F=0;               // 䫠� ���४�஢�� ���� ��� 楬���
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06off();
        }; STEP06P =3;
        if(RegRUN==OFF){ return; }
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        REG06SW__V = 30;

        //  �몫���� 譥� �ᯨ�樨 楬���
        DON162___V = OFF;

        //  �᫨ ����஢�� 楬��� � ��筮� ०���
        if (DIR170___V == MANUAL){ STEP06 = 7; return; }

        //  �᫨ ��� ������ ����� �楯⭮�� ��� 楬��� �����
        //  ��� ����᪠ ����� 楬���- ��३� �� 蠣 7
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-DPCEMS___V){ STEP06=7; return; }

        //  �᫨ �� ���ࠫ� ��� �� ��������� �����
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  ������ ������ ������ � �㭪��
           REG06SW__V = 31;
           DON171___V = ON;
           switch ( Check_TO  (61, TMKV_PDC_W*SEC, ZERO,'=',ON,  1 )){
               case RUN: { return;; }
           }
        }

        //  ������� ������ ������ � �㭪��
        DON171___V = OFF;
        Clear_TO(61);
        STEP06 =  4;
        return;
   }
   //------------------------------------------------------------------------

   // �������� �ᯮ���⥫�� ����� 楬��� �� �㭪�� 楬���
   //------------------------------------------------------------------------
   if ( STEP06 == 4 ){
        if(STEP06P!=4){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
        }; STEP06P =4;
        if(RegRUN==OFF){ return; }
        DONCM_FR_V=0;
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        //  ������ ������ ����஢�� 楬��� �����
        REG06SW__V = 41;
        DON182___V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS182___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON182___V,3,TIME_ISPPW,70, 4, 61); return;;
                      }
            case END: { DONCN06=0; break;; }
        }

        // �᫨ ⥪�騩 ��� ������ ����� �楯⭮�� ��� 楬��� ���� ���
        // ���४樨 �� ���饬� � ����� ��� ���窨 �����
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  ������ ������ ����஢�� 楬��� �����
           REG06SW__V = 42;
           DON181___V = ON;
           switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS181___V,'=',ON,  1 )){
               case RUN: { return;; }
               case BAD: {
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; return;; 
                           }
                           Isp06PD(&DON181___V,3,TIME_ISPPW,70, 4, 62); return;;
                         }
               case END: { DONCN06=0; break;; }
           }
        }
        //  ������� 譥� ����஢�� 楬���
        REG06SW__V = 43;
        DON180___V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS180___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON180___V,2,TIME_ISPPW,70, 4, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  ������ ������ ����� 楬��� �� 譥�
           REG06SW__V = 44;
           DON172___V = ON;
           switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS172___V,'=',ON,  1 )){
               case RUN: { return;; }
               case BAD: {
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; return;; 
                           }
                           Isp06PD(&DON172___V,3,TIME_ISPPW,70, 4, 64); return;;
                         }
               case END: { DONCN06=0; break;; }
           }
        }
        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        STEP06 = 5;
        return;
   }
   //------------------------------------------------------------------------


   // �������� ������ ���� ������� �� �������
   //------------------------------------------------------------------------
   if ( STEP06 == 5 ){
        if(STEP06P!=5){
           AIW190___O=AIW190___V;      // ��������� ⥪�騩 ���
           AIW190___C=0;               // ���稪 横��� ����஢
           TMVB_CB__C=0;               // ��� �६ �஢�� ��� ����� �����
           TMVIBRUN=TIME_VCONW;        // ������� �६��� ࠡ��� ����|����
           TIME_VCONC=0;               // ��� �६ ����� ������
           FLVB_ON=8;                  // 䫠� ����祭�� ������|������
        }; STEP06P=5;
        REG06SW__V=50;
        CNST_CB__C=0;
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� 楬��� �����
        //  ������� ��� ���窨 �����- ���� ������ ������ ����� 楬 �� 譥�
        //  ��⠭���� 譥�� � ������� ������� �����
        if( AIW190___V>=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW ){
            AIW190VO_V =TRCEMS_VIB+KRVYGS___V-VSOT_SSC_W;  // ��� ���� �����
            if (DONCM_FR_V<1){
                DON172___V=OFF;
                DON180___V=ON;;
                DON181___V=OFF;
            }
        }

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� 楬��� �����
        //  ������� ��� �몫�祭�� 譥��- ��������  �� �몫�祭�� 譥��
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-VSOT_SSC_W){
            AIW190VO_V =TRCEMS_VIB+KRVYGS___V-LOAD_CCTCW;  // ��� ���� �����
            if (DONCM_FR_V<1){ DON180___V=OFF; }
        }

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� 楬��� �����
        //  ������� ��� ���窨 �����- ������� �� �����⨥ ������� �����
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-LOAD_CCTCW){
            DON172___V =OFF; DON180___V=OFF; DON181___V=OFF; DON182___V=OFF;
            STEP06=51; return;
        }

        //  �⮡ࠦ���� ��� ���窨 ��� ������ � ⠡��� (� �뢠����)
        if (DIS181___V==ON){ LOAD_CCGRC=TRCEMS_VIB+KRVYGS___V-AIW190___V; }
        if (DIS182___V==ON){ LOAD_CCTCC=TRCEMS_VIB+KRVYGS___V-AIW190___V; }

        //  ��� 楬��� �� �㭪�� � ��騩
        CRCEMB___V=AIW190___V-CRCEMA___V-AIW190NV_V;
        CRCEMS___V=CRCEMA___V+CRCEMB___V;
        AIW190FV_V=5;

        //-------------------------------------------------------------------
        //  �६���� ���稪�
        if (RegRUN==ON){
            // ���稪 �६��� ����祭�� ������
            TIME_VCONC++;
            if(TIME_VCONC>= TMVIBRUN){
               // �᫨ ����砫�� ������
               if(FLVB_ON==7){
                  DON173___V=OFF; DON172___V=ON; DON171___V=OFF;
                  FLVB_ON=8; TMVB_CB__C=0; AIW190___O=AIW190___V;
               }
               // �᫨ ����砫�� ������
               if(FLVB_ON==1){
                  DON173___V=OFF; DON171___V=OFF;
                  FLVB_ON=9; TMVB_CB__C=0; AIW190___O=AIW190___V;
               }
               // �᫨ ����砥��� ������
               if(FLVB_ON==2){
                  if(BLCEMP___V==YES){ DON172___V=OFF; }
                  else               { DON172___V=ON;; }
                  DON173___V=OFF; 
                  DON171___V=ON;
                  FLVB_ON=7; TIME_VCONC=0;
               }
            }
            //  �஢�ઠ ��� ��� ����祭�� ������
            VSVB_CB__C=AIW190___V-AIW190___O;
            // ���稪 �६��� �஢�ન ��� ����� ��� ����祭�� ������
            TMVB_CB__C++;
            if (TMVB_CB__C>= TMVB_CB__W){
                // �᫨ ���������� ��� + ��� ����祭�� ������ �����
                // ⥪�饣� ��� ������ ��宣� (��� �����)
                if(AIW190___O+VSVB_CB__W>AIW190___V){
                   // �᫨ ������� ����� �������- ������ �������,
                   // ���㫨�� ���稪� � �� ��砫� 蠣� (������ � 譥��)
                   if(DON171___V==OFF and  DON172___V==OFF and DON173___V==OFF){
                      DON180___V=ON;;
                      DON181___V=OFF;
                      DON182___V=ON;;
                      TMVB_CB__C=0;
                      AIW190___O=AIW190___V;  AIW190___C=0; DONCM_FR_V=2;
                      return;
                   }
                   // ������� ������
                   if(FLVB_ON==8){
                      DON173___V=ON;; FLVB_ON=1; TIME_VCONC=0;
                      TMVIBRUN=TIME_VCONW;       // �६� ��� ������
                   }
                   // ������� ������
                   if(FLVB_ON==9){
                      if(BLCEMP___V==YES){ DON172___V=OFF; }
                      else               { DON172___V=ON;; }
                      FLVB_ON=2; 
                      TIME_VCONC=0;
                      TMVIBRUN=TMKV_RDC_W;       // �६� ��� ������
                   }
                   // 㢥����� ���稪 ������� ���
                   AIW190___C++;
                   REG06SW__V = 51;
                // �᫨ ����� ��� ���� ��ଠ�쭮- ����� ���稪 �������
                } else {
                   AIW190___C=0;
                }
                TMVB_CB__C=0;               // ����� ��� �஢�ન ���
                AIW190___O=AIW190___V;      // ��������� ⥪�騩 ��� ������
            }
            //  �᫨ ����祭� �����஢�� ������� ���� �
            //  �᫨ ��᫥ 5 横��� ����祭�� ������|������ ��� �����
            //  ��� - ������� �� ������� ����஢�� � �몫���� ॣ����
            if (BLNSUH___V==ON){
               if (AIW190___C>5){
                   DON171___V=OFF; DON173___V=OFF; DON172___V=OFF;
                   DON180___V=OFF; DON181___V=OFF; DON182___V=OFF;
                   REG06R___M=OFF; Message(146); Message(676); Bell(1); return;
               }
            }
        }
        //-------------------------------------------------------------------

        return;
   }
   //------------------------------------------------------------------------

   // �������� �������� ������������ ����� 楬��� �
   // �⠡�����樨 ��� ����� 楬���
   //------------------------------------------------------------------------
   if ( STEP06 == 51 ){
        if(STEP06P!=51){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           TMST_CBV_C =0;
           IS06ERR =0;
           AIW190___C=0;
        }; STEP06P =51;
        if(RegRUN==OFF){ return; }
        Regul_06off();

        //  �஢�ઠ ������� �ᯮ���⥫�� ����஢�� 楬���
        REG06SW__V = 52;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS182___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=4; DONCN06=0; break;; }
                        Isp06PD(&DON182___V,3,TIME_ISPPW,70, 51, 61); return;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS181___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=3; DONCN06=0; break;; }
                        Isp06PD(&DON181___V,3,TIME_ISPPW,70, 51, 62); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (63, TIME_ISPKV*SEC, DIS180___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=2; DONCN06=0; break;; }
                        Isp06PD(&DON180___V,3,TIME_ISPPW,70, 51, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS172___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=1; DONCN06=0; break;; }
                        Isp06PD(&DON172___V,3,TIME_ISPPW,70, 51, 64); return;;
                      }
            case END: { DONCN06=0; break;; }
        }

        //  ����� �६� �⠡�����樨 ���
        AIW190___O=AIW190___V;
        REG06SW__V = 53;
        switch ( Check_TO  (65, TMST_CBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_CBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);

        //  �᫨ ��᫥ ��।�ࣨ����� ������� ����஢�� �� ����- �몫 ॣ����
        if(AIW190___C>1){
           AIW190___C=0; REG06R___M=OFF; Message(141); Message(676); Bell(1); 
           return; 
        }
        if(IS06ERR   >0){
           AIW190___C++; return;
        }

        //  �᫨ ��� �� �⠡�����஢���� ��᫥ ��������� ���-�� �஢�ப-
        //  �몫���� ॣ����
        if(CNST_CB__C>=CNST_CB__W){
           STEP06=0; REG06R___M=OFF; Message(144); Message(676); Bell(1); 
           return;
        }

        //  �᫨ ��� �⠡�����樨 ���- �஢���� �� ࠧ (��� 51)
        if(AIW190___V+VSST_CB__W<AIW190___O){
           STEP06P=5; STEP06=51; CNST_CB__C++; return;
        } else {
           CNST_CB__C=0;
        }

        //  �᫨ ⥪�騩 ��� ࠢ�� �楯⭮�� ��� ����� 楬��� �����
        //  ��� ���� ������� ��� ����᪠- ��३� �� ᫥���騩 蠣
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-DPCEMS___V or
            AIW190___V<=TRCEMS_VIB+KRVYGS___V+DPCEMS___V ){
            STEP06=6; return;
        }

        //  �᫨ ⥪�騩 ��� ����� �楯⭮�� ���� ��� ����᪠ �
        //  ����� ��� �����஢�� ��� ����� 楬��� 
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V+DPCEMS___V and
            AIW190___V<=TRCEMS_VIB+KRVYGS___V+BLCEMS___V){
            // ��⠭����� 䫠� ���४�஢�� ���� ��� 楬���
            KRCEM____F=1;
            // ᮮ�饭�� � ���४�஢�� ����, ������ � ���室 �� ᫥� 蠣
            Message(140); Bell(1); STEP06=6; return;
        }

        //  �᫨ ⥪�騩 ��� ����� ��� �����஢��- �몫���� ॣ����
        if (AIW190___V>TRCEMS_VIB+KRVYGS___V+BLCEMS___V){ 
            Message(376); Message(676); REG06R___M=OFF; return; 
        }
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   //  ����� ����� ������� �����������
   if ( STEP06 == 6 ){
        if(STEP06P!=6){
           TIME_CVPSC=0;
           Clear_TO(61);
        }; STEP06P =6;
        if (RegRUN==OFF){ return; }
        Regul_06off();
        DON801___V=0.2;
        //  ��㧠 ����� ����㧪�� 楬��� � ���饣�
        REG06SW__V = 60;
        switch ( Check_TO  (61, TIME_CVPSW*SEC, ZERO,'=',ON,  1 )){
            case RUN: { TIME_CVPSC++; return;; }
        };  Clear_TO(61);
        STEP06 = 7;
        return;
   }
   //------------------------------------------------------------------------



   // ��������� �������� �� ���������:
   //------------------------------------------------------------------------
   if ( STEP06 == 7 ){
       if(STEP06P!=7){
          // �᫨ ��। �⨬ �뫠 ����஢�� 楬���- ��������� ��� 楬���
          if(AIW190FV_V==5){
             CRCEMB___V=AIW190___V-CRCEMA___V-AIW190NV_V;
             CRCEMS___V=CRCEMA___V+CRCEMB___V;
          }
          Regul_06off();
       }; STEP06P =7;
       if(RegRUN==OFF){ return; }
       KRVYG____F = 0;                 // ��� 䫠�� ���४�� ���� ��� ����
       REG06SW__V = 70;                // ⥪�� ���蠣 ॣ����

       //  �᫨ 譥� ������ ���饣� � ��� ०���- ��३� �� ����� �� �㭪��
       if (DIR130___V == MANUAL){ STEP06= 9; return; }

       //  �᫨ �楯�� ��� ���饣� �ᯨ�樨 ࠢ�� 0- ��३� �� 蠣 9
       if (TRVYGA_VIB == 0){ STEP06= 9; return; }

       //  �᫨ ��� ������ ����� �楯⭮�� ��� ���饣� �ᯨ�樨 ����� 
       //  ��� ����᪠ ����� ���饣� �ᯨ�樨- ��३� �� 蠣 9
       if (AIW190___V>=TRCEMS_VIB+TRVYGA_VIB-DPVYGA___V){ 
           STEP06=9; return; 
       }

       //  ��� ���饣� �� �ᯨ�樨
       CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
       AIW190FV_V=7;

       //  ������� 譥� �ᯨ�樨 ���饣�
       REG06SW__V = 71;
       DON132___V = ON;
       switch ( Check_TO  (61, TIME_ISPRV*SEC, DIS132___V,'=',ON,  1 )){
           case RUN: {  return;; }
           case BAD: { 
                        if(DONCN06>1){ break;; }
                        Isp06PD(&DON132___V,3,TIME_ISPPW,70, 7, 61); return;; 
                     }
       }; DONCN06=0;
       Clear_TO(61);
       STEP06=8;
       return;
   }
   //------------------------------------------------------------------------

   // �������� ����� ��� ���饣� �� �ᯨ�樨 ���饣�
   //------------------------------------------------------------------------
   if ( STEP06 == 8 ){
        if(STEP06P!=8){
           AIW190___O=AIW190___V;
           AIW190___C=0;
           TMST_VAV_C=0;
        }; STEP06P =8;
        AIW190VO_V =TRCEMS_VIB+TRVYGA_VIB-DPVYGA___V;
        AIW190VZ_V =TRCEMS_VIB+TRVYGA_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGA_VIB+BLVYGA___V;

        REG06SW__V = 80;
        //  �᫨ ⥪�騩 ��� ����� �楯⭮�� ��� ����� ���饣� �ᯨ�樨
        //  ����� ��� ����᪠ ���饣� �ᯨ�樨- ��३� �� ��� 9
        if (AIW190___V>=AIW190VO_V){ STEP06=9; return; }

        //  ��� ���饣� �� �ᯨ�樨
        CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
        AIW190FV_V=8;

        //  �஢�ઠ �⠡�����樨 ���
        if (RegRUN==ON){ TMST_VAV_C++; }
        if (TMST_VAV_C>= TMST_VAV_W){
            if(AIW190___V-AIW190___O<VSST_VA__W){ AIW190___C++; }
            else                                { AIW190___C=0; }
            TMST_VAV_C=0;
            AIW190___O=AIW190___V;
        }

        //  �᫨ ��� �⠡�����஢���� (��� ����� ���)- �� ᫥���騩 蠣
        if (AIW190___C>2){ STEP06=9; return; }
        return;
   }
   //------------------------------------------------------------------------


   //  ��������� �������� �� �������
   //------------------------------------------------------------------------
   if ( STEP06 == 9 ){
        if(STEP06P!=9){
           //  ��� ���饣� �� �ᯨ�樨
           if(AIW190FV_V==8){
              CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
           }
           Clear_TO(61);
           Regul_06off();
        }; STEP06P =9;
        if(RegRUN==OFF){ return; }

        REG06SW__V = 90;

        //  �몫���� 譥� �ᯨ�樨 ���饣�
        DON132___V = OFF; 

        //  �᫨ ����஢�� ���饣� � ��筮� ०���
        if (DIR140___V == MANUAL){ STEP06 = 15; return; }

        //  �᫨ ��� ������ ����� �楯⭮�� ��� ���饣� ����� 
        //  ��� ����᪠ ����� ���饣�- ��३� �� 蠣 15
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-DPVYGS___V and
            AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW){ 
            STEP06= 15; return;
        }

        //  �᫨ �� ���ࠫ� ��� �� ��������� �����
        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  ������ ������ ������ � �㭪�� ���饣�
           //  (����� ��। ��砫�� ����஢��)
           REG06SW__V = 91;
           DON141___V = ON;
           switch ( Check_TO  (61, TMKV_PDV_W*SEC, ZERO,'=',ON,  1 )){
               case RUN: { return;; }
           }
        }

        //  ������� ������ ������ � �㭪�� ���饣�
        DON141___V = OFF;
        Clear_TO(61);
        STEP06 = 10;
        return;
   }
   //------------------------------------------------------------------------

   // �������� �ᯮ���⥫�� ����� ���饣� �� �㭪�� ���饣�
   //------------------------------------------------------------------------
   if ( STEP06 ==10 ){
        if(STEP06P!=10){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
        }; STEP06P =10;
        if(RegRUN==OFF){ return; }
        DONVG_FR_V =0;
        AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW;
        AIW190VZ_V =TRCEMS_VIB+TRVYGS_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V;

        //  ������ ������� ����஢�� ���饣� �����
        REG06SW__V = 101;
        DON152___V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS152___V,'=',ON,  2 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON152___V,3,TIME_ISPPW,70, 9, 61); return;; 
                      }
            case END: { DONCN06=0; break;; }
        }

        // �᫨ ⥪�騩 ��� ������ ����� �楯⭮�� ��� 楬��� ���� ���
        // ���४樨 �� ���饬� � ����� ��� ���窨 �����
        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  ������ ������� ����஢�� ���饣� �����
           REG06SW__V = 102;
           DON151___V = ON;
           switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS151___V,'=',ON,  2 )){
               case RUN: { return;; }
               case BAD: { 
                           if(DONCN06>2){ 
                              Message(670); Message(6767); REG06R___M=OFF; 
                              return;; 
                           }
                           Isp06PD(&DON151___V,3,TIME_ISPPW,70, 9, 62); return;; 
                         }
               case END: { DONCN06=0; break;; }
           }
        }

        //  ������� 譥� ����஢�� ���饣�
        REG06SW__V = 103;
        DON150___V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS150___V,'=',ON,  2 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON150___V,3,TIME_ISPPW,70, 10, 63); return;; 
                      }
            case END: { DONCN06=0; break;; }
        }

        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  ������ ������ ����� ���饣� �� 譥�
           REG06SW__V = 104;
           DON142___V = ON;
           switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS142___V,'=',ON,  2 )){
               case RUN: { return;; }
               case BAD: { 
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; 
                              return;; 
                           }
                           Isp06PD(&DON142___V,3,TIME_ISPPW,70, 10, 64); return;; 
                         }
               case END: { DONCN06=0; break;; }
           }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);

        STEP06 = 11;
        return;
   }
   //------------------------------------------------------------------------


   // �������� ������ ���� �������� �� �������:
   //------------------------------------------------------------------------
   if ( STEP06 == 11 ){
        if(STEP06P!=11){
           AIW190___O=AIW190___V;      // ��������� ⥪�騩 ���
           AIW190___C=0;               // ���稪 横��� ����஢
           TMVB_VB__C=0;               // ��� �६ �஢�� ��� ����� �����
           TIME_VVONC=0;               // ��� �६ ����� ������
           FLVB_ON=8;                  // 䫠� ����祭�� ������|������
        }; STEP06P=11;
        REG06SW__V = 110;
        CNST_VB__C = 0;

        AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW;
        AIW190VZ_V =TRCEMS_VIB+TRVYGS_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V;

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� ���饣� �����
        //  ������� ��� ���窨 �����- ���� ������ ������ ����� ���� �� 譥�
        //  ������� ������� �����
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
            AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-VSOT_SSV_W;  // ��� ���� �����
            if(DONVG_FR_V<1){
               DON142___V=OFF; 
               DON150___V=ON;;
               DON151___V=OFF;
            }
        }

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� ���饣� �����
        //  ������� ��� �몫�祭�� 譥��- ��������  �� �몫�祭�� 譥��
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-VSOT_SSV_W){
            AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW;  // ��� ���� �����
            if(DONVG_FR_V<1){ DON150___V =OFF; }
        }

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� ���饣� �����
        //  ������� ��� ���窨 �����- ������� �� �����⨥ ������� �����
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW){
            DON142___V =OFF; DON150___V =OFF; DON151___V=OFF; DON152___V =OFF; 
            STEP06=12; return;
        }

        //  �⮡ࠦ���� ��� �� ���஬ �ࠡ�⠫ ������ ���窨
        if (DIS151___V==ON){ LOAD_VGGRC=TRCEMS_VIB+TRVYGS_VIB-AIW190___V; }
        if (DIS152___V==ON){ LOAD_VGTCC=TRCEMS_VIB+TRVYGS_VIB-AIW190___V; }

        //  ��� ���饣� �� �㭪��
        CRVYGB___V=AIW190___V-CRCEMS___V-CRVYGA___V-AIW190NV_V;
        CRVYGS___V=CRVYGB___V+CRVYGA___V;
        AIW190FV_V=11;

        //-------------------------------------------------------------------
        //  �६���� ���稪�
        if (RegRUN==ON){
            // ���稪 �६��� ����祭�� ������
            TIME_VVONC++;
            if(TIME_VVONC>= TIME_VVONW){
               // �᫨ ����砫�� ������
               if(FLVB_ON==7){ 
                  DON143___V=OFF; DON142___V=ON; DON141___V=OFF; 
                  FLVB_ON=8; TMVB_VB__C=0; AIW190___O=AIW190___V;
               }
               // �᫨ ����砫�� ������
               if(FLVB_ON==1){ 
                  DON143___V=OFF; DON141___V=OFF; 
                  FLVB_ON=9; TMVB_VB__C=0; AIW190___O=AIW190___V;
               }
               // �᫨ ����砥��� ������
               if(FLVB_ON==2){ 
                     DON143___V=OFF; 
                     if(BLVYGP___V==YES){ DON142___V=OFF; }
                     else               { DON142___V=ON;  }
                     DON141___V=ON; 
                     FLVB_ON=7; TIME_VVONC=0; 
               }
            }
            //  �஢�ઠ ��� ��� ����祭�� ������
            VSVB_VB__C=AIW190___V-AIW190___O;
            // ���稪 �६��� �஢�ન ��� ����� ��� ����祭�� ������
            TMVB_VB__C++;
            if (TMVB_VB__C>= TMVB_VB__W){
                // �᫨ ���������� ��� + ��� ����祭�� ������ �����
                // ⥪�饣� ��� ������ (��� �����)
                if(AIW190___O+VSVB_VB__W>AIW190___V){ 
                   // �᫨ ������� ����� �������- ������ �������,
                   // ���㫨�� ���稪� � �� ��砫� 蠣� (������ � 譥��)
                   if(DON141___V==OFF and  DON142___V==OFF and DON143___V==OFF){
                      DON150___V=ON;; 
                      DON151___V=OFF; 
                      DON152___V=ON;; 
                      TMVB_VB__C=0;
                      AIW190___O=AIW190___V;  AIW190___C=0; DONVG_FR_V=2;
                      return;
                   }
                   // ������� ������
                   if(FLVB_ON==8){ 
                      DON143___V=ON;; 
                      FLVB_ON=1; 
                      TIME_VVONC=0; 
                   }
                   // ������� ������
                   if(FLVB_ON==9){ 
                      // �᫨ � ����ன��� ����祭� �����⨥ ���饣� �� 譥�
                      // �� ����뢥- �������� �� ���� ������� �� 譥�
                      if(BLVYGP___V==YES){ DON142___V=OFF; }
                      else               { DON142___V=ON;; }
                      FLVB_ON=2; 
                      TIME_VVONC=0; 
                   }
                   // 㢥����� ���稪 ������� ���
                   AIW190___C++;
                // �᫨ ����� ��� ���� ��ଠ�쭮- ����� ���稪 �������
                } else {
                   AIW190___C=0;
                }
                TMVB_VB__C=0;               // ����� ��� �஢�ન ���
                AIW190___O=AIW190___V;      // ��������� ⥪�騩 ��� ������
            }
            //  �᫨ ����祭� �����஢�� ������㯫���� ���� �
            //  �᫨ ��᫥ 5 横��� ����祭�� ������|������ ��� �����
            //  ��� - ������� �� ������� ����஢�� � �몫���� ॣ����
            if (BLNSUH___V==ON){
               if (AIW190___C>5){
                   DON141___V=OFF; DON143___V=OFF; DON142___V=OFF;
                   DON150___V=OFF; DON151___V=OFF; DON152___V=OFF;
                   REG06R___M=OFF; Message(147); Message(676); Bell(1); return;
               }
            }
        }
        //-------------------------------------------------------------------
        return;
   }
   //------------------------------------------------------------------------

   // �������� ������� �ᯮ���⥫�� ����� ���饣� �� �㭪�� ���饣� �
   // �⠡������� ��� ����� ���饣�
   //------------------------------------------------------------------------
   if ( STEP06 == 12 ){
        if(STEP06P!=12){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           IS06ERR =0;
           TMST_VBV_C=0;
           AIW190___C=0;
           AIW190___O=AIW190___V;
        }; STEP06P =12;
        if(RegRUN==OFF){ return; }
        Regul_06off();

        //  ��� ���饣� �� �㭪��
        CRVYGB___V=AIW190___V-CRCEMS___V-CRVYGA___V-AIW190NV_V;
        CRVYGS___V=CRVYGB___V+CRVYGA___V;
        AIW190FV_V=12;

        //  �஢�ઠ ������� �������� ����� ���饣�
        REG06SW__V = 120;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS152___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=1; DONCN06=0; break;; }
                        Isp06PD(&DON152___V,3,TIME_ISPPW,70, 12, 61); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS151___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=2; DONCN06=0; break;; }
                        Isp06PD(&DON151___V,3,TIME_ISPPW,70, 12, 62); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (63, TIME_ISPKV*SEC, DIS150___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=3; DONCN06=0; break;; }
                        Isp06PD(&DON150___V,3,TIME_ISPPW,70, 12, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS142___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=4; DONCN06=0; break;; }
                        Isp06PD(&DON142___V,3,TIME_ISPPW,70, 12, 64); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        DONCN06=0;

        //  ����� �६� �⠡�����樨 ���
        REG06SW__V=121;
        AIW190___O=AIW190___V;
        switch ( Check_TO  (65, TMST_VBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);

        //  ��᫥ 横�� ����㧪� ���㫨�� ���४�� �� ���饬�
        KRVYGS___M=0; KRVYGS___V=0;

        //  �᫨ ��� �� �⠡�����஢���� ��᫥ ��������� ���-�� �஢�ப-
        //  �몫���� ॣ����
        if(CNST_VB__C>=CNST_VB__W){
           Bell(1); Message(145); Message(676); 
           REG06R___M=OFF; STEP06=0; return;
        }

        //  �᫨ ��� �⠡�����樨 ���- ������� �஢��� (��� 12) �� ࠧ
        if(AIW190___V+VSST_VB__W<AIW190___O){
           STEP06P=5; STEP06=12; CNST_VB__C++; return;
        } else {
           CNST_VB__C=0;
        }

        //  �᫨ ��᫥ ��।�ࣨ����� ������� ����஢�� �� ����- �몫 ॣ����
        if(AIW190___C>1){ 
           AIW190___C=0; Bell(1); Message(142); Message(676);
           REG06R___M=OFF; return; 
        }
        if(IS06ERR   >0){ 
           AIW190___C++; return; 
        }

        //  �᫨ ⥪�騩 ��� ࠢ�� �楯⭮�� ��� ����� ���饣� �����
        //  ��� ���� ������� ��� ����᪠- ��३� �� ᫥���騩 蠣
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-DPVYGS___V or
            AIW190___V<=TRCEMS_VIB+TRVYGS_VIB+DPVYGS___V ){
            STEP06=15; return;
        }

        //  �᫨ ⥪�騩 ��� ����� �楯⭮�� ���� ��� ����᪠ �
        //  ����� ��� �����஢�� ��� ����� ���饣� 
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB+DPVYGS___V and
            AIW190___V<=TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V){
            // ��⠭����� 䫠� ����� �� ���४�஢�� ���� ��� ���饣�
            KRVYG____F=1;
            // ᮮ�饭��, ������ � ���室 �� ᫥���騩 蠣
            Message(143); Bell(1); STEP06=15; return;
        }

        //  �᫨ ⥪�騩 ��� ����� ��� �����஢��- �몫���� ॣ����
        if (AIW190___V>TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V){ 
            Message(376); Message(676); REG06R___M=OFF; return; 
        }
        return;
   }
   //------------------------------------------------------------------------

   // ��������� �������� ������
   //------------------------------------------------------------------------
   if ( STEP06 == 15 ){
        if(STEP06P!=15){
           ;;
        }; STEP06P =15;
        AIW190VO_V =0;
        //  ��⠭����� 䫠� ����㧪� ��宣�
        DON801___V =1;
        //  �᫨ ॣ���� � �����쭮� ०���- �몫���� ���
        if (REG06GL__V==OFF){
            Message(486); Message(676); REG06R___M= OFF;
        }
        //  ��३� �� 蠣 0
        STEP06 =  0;
        return;
   }
   //------------------------------------------------------------------------



   //  �������� �� �������� ������
   //------------------------------------------------------------------------
   if ( STEP06 == 31 ){
        _f RUKAVA=OFF;
        if(STEP06P!=31){
           Regul_06off();              // �������� �� �����⨥ ��� ��������
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           Clear_TO(66);
        }; STEP06P =31;
        if(RegRUN==OFF){ return; }
        AIW190PVZV =AIW190___V;

        //  �᫨ ���� ��� �� ���� - ���
        REG06SW__V =311;
        switch ( Check_TO  (61, 1*MIN, DIS315___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(61); Message(385); Bell(1); return;; }
        }

        //  �᫨ ���� �� ����祭� - ���
        REG06SW__V =312;
        switch ( Check_TO  (62, 1*MIN, DIS310___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(62); Message(386); Bell(1); return;; }
        }

        //  �᫨ ��ଥ⨧��� �� ���饭 - ���
        REG06SW__V =313;
        switch ( Check_TO  (63, 1*MIN, DIS31A___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(63); Message(387); Bell(1); return;; }
        }

        //  �᫨ �㪠�� �� ������� - ���
        REG06SW__V =314;
        if(DIS316___V==ON or DIS317___V==ON){ RUKAVA=ON; }
        switch ( Check_TO  (64, 1*MIN, RUKAVA,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(64); Message(295); Bell(1); return;; }
        }

        //  ���� �������� �� ����祭�� ���⨫��� ���㧪�
        REG06SW__V= 315;
        DON192___V= ON;
        switch ( Check_TO  (65, TIME_ISPKV*SEC, DIS192___V,'=',ON, 1 )){
            case RUN: { return;; }
        } 
        //  �������� �� ����⨥ ������� ���㧪�
        REG06SW__V= 316;
        DON193___V= ON;
        switch ( Check_TO  (66, TIME_ISPKV*SEC, DIS193___V,'=',ON, 1 )){
            case RUN: { return;; }
        }
        //  ����� � ����⨥� ������� �ࠧ� ������� ������
        DON191___V= ON;
        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);
        Clear_TO(66);

        CNT_VIGRUZ_S=0;

        STEP06 =  32;
        return;
   }
   //------------------------------------------------------------------------


   //  �������� ���� �������� �������� ������
   //------------------------------------------------------------------------
   if ( STEP06 == 32 ){
        if(STEP06P!=32){
           AIW190___O =AIW190___V;
           AIW190___S =AIW190___V;
           AIW190___C =0;
        }; STEP06P =32;
        REG06SW__V =320;
        AIW190VZ_V =0;
        AIW190VB_V =0;

        //  �᫨ ���������� ��� ����� ⥪�騩 ��� ������ ����� ���
        //  ���樨 ���㧪�- �몫���� ������ � ������� ������ ���㧪�
        if( AIW190___O-AIW190___V>=LOAD_SVPVW){
            DON191___V=OFF; DON193___V=OFF;
        }
        //  �������� �������
        //  �᫨ ⥪�騩 ��� ����� ��� ���窨 ���㧪�- 
        //  �몫���� ������ � ������� ������  ���㧪� 
        //  ���㧨�� �楯�� ���
        if( VGR_SHRECV==ON){
            AIW190VO_V =AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB-VSOT_SHV_W);
            AIW190VZ_V =AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB);
            if(AIW190VO_V > AIW190___V){
               DON191___V=OFF; 
               DON193___V=OFF;
               Message(302);
               STEP06=33; 
               return;
            }
        }
        //  �������� ������� ���� (�� �楯�)
        if( VGR_SHIZLV==ON){
            AIW190VO_V =AIW190PVZV-(AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB-VSOT_SHV_W));
            AIW190VZ_V =AIW190PVZV-(AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB));
            if(AIW190VO_V > AIW190___V){
               DON191___V=OFF; 
               DON193___V=OFF; 
               Message(303);
               STEP06=33; 
               return;
            }
        }
        //  ��� �⮡ࠦ���� �������
        LOAD_SVPVC=AIW190___O-AIW190___V;

        if(RegRUN==OFF){ return; }

        //  �᫨ ������ ������: 
        if(DIS193___V==OFF){
           // �몫���� ������
           DON191___V = OFF;
           // ����� �६� ����
           switch ( Check_TO  (61, TIME_PONVW*SEC, ZERO,'=',ON, 1 )){
               case RUN: { TIME_PONVC++; return;; }
           };  Clear_TO(61);
           TIME_PONVC=0;
           // ����� �६� ���� ��諮:
           // ��������� ⥪�騩 ��� ������ ��宣�
           AIW190___O = AIW190___V;
           // ������ ������ ���㧪�
           DON193___V = ON;
           // ����� � �������� ������� ������
           DON191___V = ON; TIME_VIONC=0;
        }
        //  ���稪 �஢�ન �⠡�����樨 ��� ������ ��宣� �� ���㧪�
        TMST_VIS_C++;
        if (TMST_VIS_C>= TMST_VIS_W){
            // �᫨ ���������� ��� ������ ����� ⥪�騩 ��� �����
            // ��������� ��� �⠡�����樨 (��� ������ �� �������
            // ��� ������� ��������)- ������� ������(�᫨ ����� ������)
            if(AIW190___V+VSST_VIS_W>AIW190___O){
               AIW190___C++;
            } else {
            // �᫨ ��� ������� ��ଠ�쭮- ���㫨�� ���稪 横��� �஢�ન
               AIW190___C=0;
            }
            TMST_VIS_C=0;
            AIW190___O=AIW190___V;
        }
        // �᫨ ��᫥ ��।�������� ���-�� 横��� �஢�ન ��� ������ 
        // �� �室��- ᫥� 蠣
        if(AIW190___V<50){
           if(AIW190___C> CNST_VVS_W){ 
              DON193___V=OFF;  
              DON191___V=OFF; 
              STEP06=33; 
              return; 
           }
        }
        return;
   }
   //------------------------------------------------------------------------
   if ( STEP06 == 33 ){
        if(STEP06P!=33){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06off(); TIME_SHVVC=0;
           TMST_VIS_C=0;
        }; STEP06P =33;
        if(RegRUN==OFF){ return; }
        REG06SW__V =331;

        // 䫠� ���㧪� ������
        DON801___V=2;

        // �������� �६��� �⠡�����樨 ��᫥ ���㧪�
        switch ( Check_TO  (62, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
            case BAD: { AIW190___O=AIW190___V; break;; }
        }

        // �������� �६��� �⠡�����樨 ��᫥ ���㧪�
        switch ( Check_TO  (62, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
        }

        // �஢�ઠ ��� �⠡�����樨 ���㧪�
        // �᫨ ��� �⠡�����樨 (��� �室��)- ��३� �� 蠣 ��砫� ���㧪�
        if(AIW190___V+VSST_VIS_W<AIW190___O){
           Message(304);
        }

        // �������� ��। �몫�祭��� ���⨫��� ���㧪� ��宣�
        REG06SW__V =332;
        switch ( Check_TO  (63, TIME_SHVVW*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TIME_SHVVC++; return;; }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Regul_06off();

        //  �᫨ ॣ���� � �����쭮� ०���- �몫���� ॣ����
        if (REG06GL__V==OFF){ 
            Message(487); Message(676); REG06R___M=OFF; 
        }

        //  ������ ���ண� ���㦠���� 1-�, ��宣� 2-� ��⥬ ����
        //  ��᫥���� �몫�砥� 横� ��饣� ॣ����
        //  �᫨ ॣ���� ����� �� ����祭 ��� ��饩 ࠡ��� ���
        //  �몫�祭- �몫���� ��騩 ॣ����
        if (RegPublicV==ON and (REG09GL__V==OFF or REG09R___V==OFF)){ 
            RegPublicM =OFF; 
        }

        STEP06= 0;
        return;
   }
   //------------------------------------------------------------------------


   //-----------------------------------------------------------------------
   // �������������� ��������
   //-----------------------------------------------------------------------
   if ( STEP06 ==70 ){
        if(STEP06P!=70){
           ;;
        }; STEP06P =70;
        if(DONCN06>=DONCH06){ STEP06 = STEP06_PRBK; return; }
        REG06SW__V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(206, DONTM06*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(206);
       *DONPR06=(*DONPR06!=ON)?ON:OFF;
        DONCN06++;
        STEP06 = STEP06_PRBK;
        return;
   }
   //-----------------------------------------------------------------------


   //------------------------------------------------------------------------
   // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
   Regul_06m();
   return;
}
//---------------------------------------------------------------------------
