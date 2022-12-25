// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// ����஢�� ��宣�


#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"


_f far *DONPR06v;
_i far  DONCN06v=0;                // ���稪 横�� ��।�ࣨ�����
_i far  DONCH06v=2;                // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i far  DONTM06v=2;                // ���-�� ᥪ㭤 ��� � ����

_i far  FLVB_ON_v=0;               // 䫠� ��।���� ����祭�� ����-����
_i far  IS06vERR=0;                // 䫠� �訡�� �ࠡ�⪨ �ᯮ���⥫��




//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp06vPD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR06v= IOPNT;             // ����� ������ �ᯮ���⥫� ��� ��।�ࣨ�����
    DONCH06v= hM;                // ᪮�쪮  ࠧ ��࣠��
    DONTM06v= hS;                // ���-�� ᥪ㭤 �த������� �믮������ �������
    STEP06v = Step;              // 蠣 ॣ���� ��� ��楤��� ��।�ࣨ�����
    STEP06v_PRBK = Step_Back;    // 蠣 ������ �� ��楤��� ��।�ࣨ�����
    Clear_TO(ClearTON);          // ���㫨�� ⠩��� � ������� ����஬
    return;
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����

vd  far ModeKO_06v(vd){
    if(REG06cR__V==ON){
    DON221B__M =  OFF; // ������
    DON229B1_M =  OFF; // ������ ���騥
    DON228B__M =  OFF; // 譥�
    DON229B2_M =  OFF; // ������
    //
    DON221E__M =  OFF; // ������ ���㧪� ��
    DON220E__M =  OFF; // ������ ���㧪� ���
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_06v_off(vd){
    DON221B__V =  OFF; // ������
    DON229B1_V =  OFF; // ������ ���騥
    DON228B__V =  OFF; // 譥�
    DON229B2_V =  OFF; // ������
    //
    DON221E__V =  OFF; // ������ ���㧪� ��
    DON220E__V =  OFF; // ������ ���㧪� ���
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

//  �믮������ ����⢨� �� �몫�祭�� ॣ����

vd  far Regul_06v_manual(vd){
    //-----------------------------------------------------------------------
    if ( STEP06v == 101 ){
         REG06cSW_V=1001;
         if(RegRUN==OFF){ return; }
         Regul_06v_off();
         FLAG_0605A_v=OFF;
         FLAG_05WTA_v=OFF;
         STEP06v = 102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP06v == 102 ){
         STEP06vP = 102;
         REG06cSW_V=1002;
         REG06vR__M=OFF;
         AIW219FV_V=0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP06v=101;
    return;
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
//  ��।������ 蠣� ����᪠ ॣ����
vd  far Regul_06v(vd){

    ex vd far Regul_06c_manual(vd);
    ex vd far Regul_06c_off(vd);

    //------------------------------------------
    //  �롮� ०��� ���㧪� �� ������ ��宣�
    VGR_SHALLV=ON;; VGR_SHRECV=OFF; VGR_SHIZLV=OFF;

    //----------------------------------
    //  ��।�� ���祭�� ����஫� ���� ��� ����㧪� ��
    if( CRVGBM___M>0){
        if(CRVGBM___V>0 && CRVGBM___M>0){ CRVGBM___V=0; Message(363,NOKV); CRVGBM___M=0; }
        if(CRVGBM___V<1 && CRVGBM___M>0){ CRVGBM___V=1; Message(362,NOKV); CRVGBM___M=0; }
        CRVGBM___M=0;
    }
    
    //----------------------------------
    // ����㧪�-���㧪� (�� ॣ���� ����㧪� 楬���)
        
    //----------------------------------
    // ��騩-������� (�� ॣ���� ����㧪� 楬���)
    
    //----------------------------------
    // �᫨ ॣ���� �몫�祭 - ��� (�஢�ઠ � ॣ���� ����㧪� 楬���)

    //----------------------------------
    // �᫨ �� �६� ���㧪� ��宣� ������� ��ଥ⨧���
    if (STEP06v>=32 and STEP06v<=33 and DISVGBMG_V==OFF){ Bell(1,1); Message(115,NOKV); return; }





    //--------------------------------------------------------------------------
    //
    //  ����������� ��������� ����������
    //
    //--------------------------------------------------------------------------

    if ( STEP06v == 0 ){

        if(STEP06vP!=0){
           ;;
        }; STEP06vP =0;
        if (RegRUN==OFF){ return; }

        Regul_06v_off();


        //-------------------------------
        //  ���� ������ ��宣� (�᫨ � ०��� �������(=1)- ���)
        REG06cSW_V =2;
        if(DIR216___V==1){ return; }

        // �������⥫�� ᨣ��� �� �����⨥ ��� �ᯮ���⥫��
        // ���ﭨ� �஢����� �� ���� (�㤥� ᬮ���� �� ����)
        Regul_06v_off();




        //-------------------------------
        //  �������� :
        
        REG06cSW_V =9;

        //-------------------------------
        //  ॣ���� ����祭 �� ����㧪� ��� ��������� ࠡ���
        //  (��।������ 蠣� � ॣ���� ����஢�� 楬���)

        //-------------------------------
        //  ॣ���� ����祭 ��� ����� ࠡ��� � ������ ��宣� ���㦥�
        //  � � ������ ����� ������ ��� ����㧪�
        //  (��।������ 蠣� � ॣ���� ����஢�� 楬���)

        //-------------------------------


        //-------------------------------
        //  �������� ����
        //  �᫨ ������ ��宣� ����㦥� � ������ ���ண� ���㦥� � ���� ���࠭�
        //  � ����祭 ��騩 ॣ���� � -  ��३� �� 蠣 ���㧪�
        //  (��।������ 蠣� � ॣ���� ����஢�� 楬���)

        //-------------------------------
        //  �������� �����쭠�
        //  �᫨ ����祭 ������� ॣ���� � ����祭� ���㧪�
        //  � ������ ���ண� ���㦥� ��� ॣ���� 07 �몫�祭 -
        //  ��३� �� 蠣 ���㧪�
        //  (��।������ 蠣� � ॣ���� ����஢�� 楬���)

        //-------------------------------


        Clear_TO(24);

        return;
    }
    //-----------------------------------------------------------------------




   // ��������� ��������

   //------------------------------------------------------------------------
   if ( STEP06v == 7 ){
       if(STEP06vP!=7){
          Regul_06v_off();
          CRVYGS___V=0;
          AIW219FV_V=0;
          AIW219NV_V=AIW219___V;
       }; STEP06vP =7;
       if(RegRUN==OFF){ return; }
       REG06cSW_V = 70;                // ⥪�� ���蠣 ॣ����
       Clear_TO(24);
       STEP06v=8;
       return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   if ( STEP06v == 8 ){
        if(STEP06vP!=8){
           Regul_06v_off();
           AIW219___O=AIW219___V;
           AIW219___C=0;
        }; STEP06vP =8;
        REG06cSW_V = 80;
        STEP06v=9;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   if ( STEP06v == 9 ){
        if(STEP06vP!=9){
           Regul_06v_off();
           Clear_TO(24);
        }; STEP06vP =9;
        if(RegRUN==OFF){ return; }
        REG06cSW_V = 90;

        //  �᫨ ����஢�� � ०��� �������- �� 蠣 15 (����砭�� ����㧪�)
        if (DIR216___V ==  1){ STEP06v = 15; return; }

        //  �᫨ ��� ������ ����� �楯⭮�� ��� ���饣� - ��३� �� 蠣 15
        if (AIW219___V>=TRVYGS_VIB-LOAD_VGGRW){ STEP06v= 15; return; }

        REG06cSW_V = 91;
        //  �஢�ઠ ������� ������� ���㧪�
        switch ( Check_TO  (24, TIME_ISPKV*SEC, DIS220F__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(24); Message(638,KVIT); Bell(1,1); return;; }
        }

        Clear_TO(24);
        STEP06v = 10;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // �������� �ᯮ���⥫�� ����� ���饣�
   if ( STEP06v ==10 ){
        if(STEP06vP!=10){
           Clear_TO(24);
           Clear_TO(25);
           Clear_TO(26);
           Clear_TO(27);
           Clear_TO(28);
        }; STEP06vP =10;
        if(RegRUN==OFF){ return; }
        DONVG_FR_V =0;
        AIW219VO_V =TRVYGS_VIB-LOAD_VGGRW;
        AIW219VZ_V =TRVYGS_VIB;

        // ������ ������ ���饣� ��᫥ 譥��
        REG06cSW_V = 101;
        DON229B2_V = ON;
        // �� ��᫥ 譥��
        switch ( Check_TO  (24, TIME_ISPKV*SEC, DIS229B2_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>2){
                           Message(670,KVIT); DONCN06v=0; return;;
                        }; Isp06vPD(&DON229B2_V,3,TIME_ISPPW,70, 10, 24); return;;
                      }
            case END: { DONCN06v=0; break;; }
        }

        //  ������� 譥� ����஢�� ���饣�
        REG06cSW_V = 102;
        switch ( Check_TO  (25, TMISPVYG_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { return; }
        }
        DON228B__V = ON;
        switch ( Check_TO  (26, TIME_ISPRV*SEC, DIS228B__V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>2){
                           Message(670,KVIT); DONCN06v=0; return;
                        }; Isp06vPD(&DON228B__V,3,TIME_ISPPW,70, 10, 26); return;
                      }
            case END: { DONCN06v=0; break;; }
        }

        //  ������ ������ ���饣� �� 譥�
        REG06cSW_V = 103;
        switch ( Check_TO  (27, TMISPVYG_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { return; }
        }
        DON229B1_V = ON;
        switch ( Check_TO  (28, TIME_ISPKV*SEC, DIS229B1_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>2){
                           Message(670,KVIT); DONCN06v=0; return;
                        }; Isp06vPD(&DON229B1_V,3,TIME_ISPPW,70, 10, 28); return;;
                      }
            case END: { DONCN06v=0; break;; }
        }

        Clear_TO(24);
        Clear_TO(25);
        Clear_TO(26);
        Clear_TO(27);
        Clear_TO(28);

        STEP06v = 11;
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // �������� ������ ���� ��������
   //------------------------------------------------------------------------
   if ( STEP06v == 11 ){
        if(STEP06vP!=11){
           AIW219___O=AIW219___V;      // ��������� ⥪�騩 ���
           AIW219___C=0;               // ���稪 横��� ����஢
           TMVB_VB__C=0;               // ��� �६ �஢�� ��� ����� �����
           TIME_VVONC=0;               // ��� �६ ����� ������
           FLVB_ON_v=0;                // 䫠� ����祭�� ������|������
        }; STEP06vP=11;
        REG06cSW_V=110;
        CNST_VB__C=0;

        AIW219VO_V =TRVYGS_VIB-LOAD_VGGRW;
        AIW219VZ_V =TRVYGS_VIB;

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� ���饣� �����
        //  ������� ��� ���窨 ��� ������� �� 譥�(�����) - ������� �� �����⨥
        //  ������� ����� ���饣� �� 譥�
        if( AIW219___V>=TRVYGS_VIB-VSOTSVYG_W ){ DON229B1_V=OFF; }

        //  �᫨ ⥪�騩 ��� ����� ��饣� ��������� ��� ����� ���饣� �����
        //  ������� ��� ���窨 - ���� ������ ������ ����� ���� �� 譥�
        if (AIW219___V>=TRVYGS_VIB-LOAD_VGGRW){
             DON229B1_V=OFF;
             DON229B2_V=ON;;
             DON228B__V=OFF;
             STEP06v=12; return;
        }


        //-------------------------------------------------------------------
        //  ������ �����
        if (RegRUN==ON){
            // ���稪 �६��� ����祭�� ������
            if(FLVB_ON_v>0){
                TIME_VVONC++;
                if(TIME_VVONC>=TIME_VVONW){ DON221B__V=OFF; FLVB_ON_v=0; TIME_VVONC=0; }
                TMVB_VB__C=0;
            }

            //  �஢�ઠ ��� ��� ����祭�� ������
            VSVB_VB__C=AIW219___V-AIW219___O;

            // ���稪 �६��� �஢�ન ��� ����� ��� ����祭�� ������
            TMVB_VB__C++;
            if (TMVB_VB__C>= TMVB_VB__W){
                // �᫨ ���������� ��� + ��� ����祭�� ������ �����
                // ⥪�饣� ��� ������ (��� �����)
                if(AIW219___O+VSVB_VB__W>AIW219___V){
                      DON221B__V=ON;;
                      FLVB_ON_v=1;
                      TIME_VVONC=0;
                      // 㢥����� ���稪 ������� ���
                      AIW219___C++;
                } else {
                // �᫨ ����� ��� ���� ��ଠ�쭮- ����� ���稪 �������
                   AIW219___C=0;
                }
                TMVB_VB__C=0;               // ����� ��� �஢�ન ���
                AIW219___O=AIW219___V;      // ��������� ⥪�騩 ��� ������
            }
        }
        //-------------------------------------------------------------------
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // �������� ������� �ᯮ���⥫�� ����� ���饣�
   //------------------------------------------------------------------------
   if ( STEP06v == 12 ){
        if(STEP06vP!=12){
           Clear_TO(24);
           Clear_TO(25);
           Clear_TO(26);
           Clear_TO(27);
           Clear_TO(28);
           IS06vERR =0;
           TMST_VBV_C=0;
           AIW219___C=0;
           AIW219___O=AIW219___V;
        }; STEP06vP =12;
        if(RegRUN==OFF){ return; }
        Regul_06v_off();

        AIW219FV_V=12;

        //  ������ ���饣� �� 譥�
        REG06cSW_V = 120;
        switch ( Check_TO  (24, TIME_ISPKV*SEC, DIS229B1_V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>1){ IS06vERR=1; DONCN06v=0; break;; }
                        Isp06vPD(&DON229B1_V,3,TIME_ISPPW,70, 12, 24); return;;
                      }
            case END: { DONCN06v=0; break;; }
        }
        //  ������ ���饣� ��᫥ 譥��
        switch ( Check_TO  (25, TIME_ISPKV*SEC, DIS229B2_V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>1){ IS06vERR=2; DONCN06v=0; break;; }
                        Isp06vPD(&DON229B2_V,3,TIME_ISPPW,70, 12, 25); return;;
                      }
            case END: { DONCN06v=0; break;; }
        }
        //  譥� �����
        switch ( Check_TO  (26, TIME_ISPKV*SEC, DIS228B__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06v>1){ IS06vERR=3; DONCN06v=0; break;; }
                        Isp06vPD(&DON228B__V,3,TIME_ISPPW,70, 12, 26); return;;
                      }
            case END: { DONCN06v=0; break;; }
        }
        DONCN06v=0;

        //  ����� �६� �⠡�����樨 ���
        REG06cSW_V=121;
        AIW219___O=AIW219___V;
        switch ( Check_TO  (27, TMST_VBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(24);
        Clear_TO(25);
        Clear_TO(26);
        Clear_TO(27);
        Clear_TO(28);

        //  �᫨ ��� �� �⠡�����஢���� ��᫥ ��������� ���-�� �஢�ப
        if(CNST_VB__C>=CNST_VB__W){ Bell(1,1); Message(145,NOKV); return; }

        //  �᫨ ��᫥ 2�� �஢�ન ��।�ࣨ�����, ������� ����஢�� �� ����
        if(AIW219___C>1){ AIW219___C=0; Bell(1,1); Message(142,NOKV); return; }
        //  ࠧ���� 2� �஢���, �᫨ �뫨 �訡�� ������� �ᯮ���⥫��
        if(IS06vERR  >0){ AIW219___C++; return; }

        //  �᫨ ⥪�騩 ��� ࠢ�� �楯⭮�� ��� ����� ���饣� ����� 10
        //  - ��३� �� ᫥���騩 蠣 (����砭�� ����㧪�)
        if (AIW219___V>=TRVYGS_VIB-10){
            STEP06v=15; return;
        }

        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   // ���������� ����������
   if ( STEP06v == 15 ){
        if(STEP06vP!=15){
           ;;
        }; STEP06vP =15;
        AIW219VO_V =0;
        // ��४��祭�� 蠣� � ॣ���� ����஢�� 楬��� (regul06c.c)
        return;
   }
   //------------------------------------------------------------------------



   //------------------------------------------------------------------------
   //  ��������
   if ( STEP06v == 31 ){
        if(STEP06vP!=31){
           Regul_06v_off();

           Clear_TO(24);
           Clear_TO(25);
           Clear_TO(26);
           Clear_TO(27);
           Clear_TO(28);
           Clear_TO(29);
        }; STEP06vP =31;
        if(RegRUN==OFF){ return; }
        AIW219PVZV =AIW219___V;

        if (STEP06c!=34) return;

        // ��� ����祭?
        REG06cSW_V= 312;
        switch ( Check_TO  (24, 1*MIN, DISVGBMR_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(24); Message(386,KVIT); Bell(1,1); return;; }
        }

        // ��ଥ⨧��� ���饭?
        REG06cSW_V= 313;
        switch ( Check_TO  (25, 1*MIN, DISVGBMG_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(25); Message(387,KVIT); Bell(1,1); return;; }
        }

        // ������ ������ ���㧪� �����
        REG06cSW_V= 316;
        DON220E__V= ON;
        switch ( Check_TO  (26, TIME_ISPKV*SEC, DIS220E__V,'=',ON, 1 )){
            case RUN: { return;; }
        }

        Clear_TO(24);
        Clear_TO(25);
        Clear_TO(26);

        CNT_VIGRUZ_S=0;

        STEP06v =  32;
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   // �஢�ઠ ���㧪� ������ �����
   if ( STEP06v == 32 ){
        if(STEP06vP!=32){
           Clear_TO(24);
           AIW219___O=AIW219___V;
           AIW219___S=AIW219___V;
           AIW219___C=0;
           TIME_PONVC=0;
           // ������� ������
           DON221E__V= ON;
        }; STEP06vP =32;
        REG06cSW_V =320;

        // �१ ������� � ����ன��� ��� -
        // �몫���� ������, ������� ������ ���㧪�
        if(AIW219___O-AIW219___V>=LOAD_SVPVW){
           DON221E__V=OFF; DON220E__V=OFF;
        }

        AIW219VO_V =AIW219PVZV-TRVYGS_VIB;

        // �᫨ ���㧪� ������ ��諠 -
        // �몫���� ������, ������� ������ ���㧪� � ��३� �� ᫥���騩 蠣
        if(AIW219VO_V > AIW219___V && AIW219___V < 5 ){
           DON221E__V=OFF;
           DON220E__V=OFF;
           Message(302,NOKV);
           STEP06v=33;
           return;
        }

        LOAD_SVPVC=AIW219___O-AIW219___V;

        if(RegRUN==OFF){ return; }

        if(DIS220E__V==OFF||DON220F__V==OFF){
           DON221E__V =OFF;
           TIME_PONVC++; if(TIME_PONVC>10000){ TIME_PONVC=0; }
           switch ( Check_TO  (24, TIME_PONVW*SEC, ZERO,'=',ON, 1 )){
               case RUN: { return; }
           };  Clear_TO(24);
           TIME_PONVC=0;
           AIW219___O = AIW219___V;
           DON221E__V = ON;
           DON220E__V = ON;
        }

        TMST_VIS_C++;
        if (TMST_VIS_C>= TMST_VIS_W){
            if(AIW219___V+VSST_VIS_W>AIW219___O){
               AIW219___C++; DON220E__V=ON; DON221E__V=ON;
            } else {
               AIW219___C=0;
            }
            TMST_VIS_C=0;
            AIW219___O=AIW219___V;
        }

        // �᫨ � ������ ���� �����-� ������让 ��� � �� �⠡���� -
        // �몫���� ������, ������� ������ ���㧪� � ��३� �� ᫥���騩 蠣
        if(AIW219___V<10&&AIW219___C>1){
           if(AIW219___C>2){
              DON221E__V=OFF;
              DON220E__V=OFF;
              STEP06v=33;
              return;
           }
        }
        return;
   }
   //------------------------------------------------------------------------
   // �����⨥ ��� �ᯮ���⥫�� � �஢�ઠ �⠡�����樨 ���
   if ( STEP06v == 33 ){
        if(STEP06vP!=33){
           Clear_TO(24); Clear_TO(25); Clear_TO(26);
           Regul_06c_off();
           TIME_SHVVC=0;
           TMST_VIS_C=0;
        }; STEP06vP =33;
        if(RegRUN==OFF){ return; }
        REG06cSW_V =331;

        DON211B1_V=2;

        switch ( Check_TO  (24, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
            case BAD: { AIW219___O=AIW219___V; break;; }
        }

        if(AIW219___V+VSST_VIS_W<AIW219___O){ Message(304,KVIT); }

        REG06cSW_V =332;
        switch ( Check_TO  (25, TIME_SHVVW*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TIME_SHVVC++; return;; }
        }

        Clear_TO(24); Clear_TO(25); Clear_TO(26);
        Regul_06c_off();

        STEP06v=34;
        return;
   }
   //------------------------------------------------------------------------
   // �������� ����⢨� (蠣�) �� ॣ���� ����㧪� 楬���
   if ( STEP06v == 34 ){
        if(STEP06vP!=34){
        }; STEP06vP =34;
        if(RegRUN==OFF){ return; }
   }
   //-----------------------------------------------------------------------



   //-----------------------------------------------------------------------
   // �������������� ��������
   //-----------------------------------------------------------------------
   if ( STEP06v ==70 ){
        if(STEP06vP!=70){
           ;;
        }; STEP06vP =70;
        if(DONCN06v>=DONCH06v){ STEP06v = STEP06v_PRBK; return; }
        REG06cSW_V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(206, DONTM06v*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(206);
       *DONPR06v=(*DONPR06v!=ON)?ON:OFF;
        DONCN06v++;
        STEP06v = STEP06v_PRBK;
        return;
   }
   //-----------------------------------------------------------------------

   return;
}
//---------------------------------------------------------------------------
