// coding: cp866
//---------------------------------------------------------------------------
// ����஢�� �����

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR09;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN09=0;               // ⥪�騩 ���稪 横�� ��।�ࣨ�����              
_i far  DONCH09=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM09=2;               // ���-�� ᥪ㭤 ��� � ����

_i far  PA_VSTB=0;               // 䫠� �⠡�����樨 ��� ���㧪�
_f far  CYRPASS=0;               // 蠣 ����祭�� ����樨 �� ���
_f far  DIS06XX=0;               // ���ﭨ� ������� ����� �� ��� �� ��蠫��
_f far  PO216=0;                 // ��業� ������ ������� ����� �� ��ᯥ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp09PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR09= IOPNT;
    DONCH09= hM;
    DONTM09= hS;
    STEP09 = Step; 
    STEP09_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_09(vd){
    if(REG09R___V==ON||REG09GL__V==ON){
    DON068B__M=OFF;
    DON068C__M=OFF;
    DON068E__M=OFF;
    DON068D__M=OFF;
    DON069B__M=OFF;
    DON069C__M=OFF;
    DON069E__M=OFF;
    DON069D__M=OFF;
    DON216F__M=OFF;
    DON216G__M=OFF;
}   }
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_09off(int m){
    // �ᯮ���⥫� ����஢��
    if(m<2){
    DON068B__V=OFF;     // �� ����� �1
    DON069B__V=OFF;     // �� ����� �2
    DON068D__V=OFF;     // �� �����
    DON216G__V=OFF;     // ���㧪� ���
    DON216F__V=OFF;     // ����㧪� ��� (�� �ᯮ������)
    AON216F_OM=0;       // ����㧪� ��� (������)
    AON216F_OV=0;       //
    }
    if(m==1&&CYRPASS>0&&CYRPASS<101) return;
    // �ᯮ���⥫� ����樨
    DON068C__V=OFF;     // �� ��� N1
    DON069C__V=OFF;     // �� ��� N2
    DON068E__V=OFF;     // �  ��� N1
    DON069E__V=OFF;     // �  ��� N2
    DON069D__V=OFF;     // ����
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_09m(vd){
    //-----------------------------------------------------------------------
    if ( STEP09 == 101 ){
         REG09SW__V=1001;
         Regul_09off(1);
         STEP09 = 102;
    }
    //-----------------------------------------------------------------------
    if ( STEP09 == 102 ){
         REG09SW__V=1002;
         REG09R___M=OFF;
         return;
    }
    // ����� ������ � ��饬 ॣ����
    SetPubCycStat(PASTA,0);
    //-----------------------------------------------------------------------
    STEP09=101;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
vd  far Regul_09_Save(vd){
    if(STEP09==70) STEP09__SV=STEP09_PRBK; else STEP09__SV=STEP09;
}
//---------------------------------------------------------------------------
vd  far Regul_09_Rest(vd){ STEP09=STEP09__SV; }
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_09(vd){
    // ��� ���窨 ����� ����� ����� �� ��� �������
    if (LOAD_PAVOW <  0){ LOAD_PAVOW =  3; }                     // 3 KG
    // ��� ���窨 ����� ����� ����� �� ��� �������
    if (LOAD_PATTW <  0){ LOAD_PATTW = 0.5; }                    // 0.5 KG
    // ��� �⠡�����樨 ����� �����
    if (LOAD_PAVSW <  0){ LOAD_PAVSW =  1; }                     //  1 KG 
    // �६� �⠡�����樨 ����� �����
    if (TIME_PAVSW <  0){ TIME_PAVSW =  7; }                     //  7 SEC
    // ���稪 �⠡�����樨 ����� �����
    if (CNST_PAN_W <  0){ CNST_PAN_W =  2; }                     //  2 CYC
    // ��� �⠡�����樨 ���㧪� �����
    if (VSST_PAVIW <  0){ VSST_PAVIW =  1; }                     //  1 KG 
    // �६� �⠡�����樨 ���㧪� �����
    if (TMST_PAVIW <  0){ TMST_PAVIW = 15; }                     // 15 SEC
    // ���稪 �⠡�����樨 ���㧪� �����
    if (CNST_PAVIW <  0){ CNST_PAVIW =  2; }                     //  2 CYC
    // �����⨬� ��� ���⪠ � ������
    if (VSOS_PAVIW <  0){ VSOS_PAVIW =  2; }                     // 0.2 KG
    // ��� ���窨 ���㧪� ��.�����
    if (VIGR_PVOTW <0.5){ VIGR_PVOTW =0.5; }                     // 0.5 KG
    // ��業� ������ ������� ����஢�� �� ��ᯥ���� �����
    if (AON216PO_W <= 0){ AON216PO_W=50; }                       // 50%
    // ���㫥��� ���稪� ����஢�� ������ ��.��ᯥ����
    if (VDCOUNT__W==777){ VDCOUNT__C=0; VDCOUNT__W=0; }          // ���㫥��� ���稪� �஬뢮�

    // �᫨ ॣ���� �� � ��筮� ०���, �ࠢ���� �������� ����� �� ��ᯥ���� �����
    if (STEP09<101){ AON216F_OM=AON216F_OV; }
    else           { AON216F_OV=AON216F_OM; }
    if(AON216F_OV<0) AON216F_OV=0; if(AON216F_OV>100) AON216F_OV=100; AON216FOOV=AON216F_OV;

    // ����祭��-�몫�祭�� ॣ����
    if ( REG09RS__M == SWITCH ){ 
         REG09R___M = (REG09R___M==ON) then_ OFF else_ ON; REG09RS__M=OFF;
    }
    if (REG09R___M != REG09R___V){ 
        REG09R___M  =(REG09R___M==ON) then_ ON else_ OFF;
        REG09R___V  = REG09R___M; 
        if (REG09R___V>0){
            // �������
            Message(400,NOKV); STEP09=0;
            // �᫨ ����祭 ��騩 ॣ���� � ॣ���� � ࠡ�� - ����⠭����� ���ﭨ� ॣ����
            if (RegPublicV==ON and REG09GL__V==ON and STEP09__SV>1){
                Regul_09_Rest(); Message(240,NOKV); return;
            }
        } else {
            // �᫨ ����祭 ��騩 ॣ���� � ॣ���� � ࠡ�� - ������� ���ﭨ� ॣ����
            if (RegPublicV==ON and REG09GL__V==ON and STEP09>1 and STEP09<70){ 
                Regul_09_Save(); Message(239,NOKV);
            }
            // �몫����
            Message(401,NOKV); Regul_09off(0); STEP09=101; return;
        }
    }
    // �� �몫�祭�� ��饣� ॣ���� ���뢠���� ���祭�� ����ᠭ���� 蠣�
    if (RegPublicV==OFF or REG09GL__V==OFF){ STEP09__SV=0; }
    
    //  ����㧪�-���㧪�
    if ( REG09ZV__M != REG09ZV__V ){ 
         REG09ZV__M  =(REG09ZV__M==ON) then_ ON else_ OFF;
         REG09ZV__V  = REG09ZV__M;
         if(REG09ZV__V>0){ Message(402,NOKV); }                      // ����㧪�
         else            { Message(403,NOKV); }                      // ���㧪�
    }
    
    //  ��騩-�������
    if ( REG09GL__M != REG09GL__V ){ 
         REG09GL__M  =(REG09GL__M==ON) then_ ON else_ OFF;
         REG09GL__V  = REG09GL__M;
         if(REG09GL__V>0){ Message(404,NOKV); }                      // ��騩
         else            { Message(405,NOKV); }                      // �������
    }


    //------------------------------
    //  ���-�몫 ����樨 �����
    if ( CYRPAS___M != CYRPAS___V ){ 
         CYRPAS___V  = CYRPAS___M;
         if(CYRPAS___V>0){ Message(100,NOKV); CYRPASS= 10; }         // ��� ������
         else            { Message(101,NOKV); CYRPASS=101; }         // �몫
         // �᫨ �몫 ��� ० ॣ� (��४��� ⮫쪮 � ��� ०���)
         if(CYRPASS<101&&REG09GL__V==1){ Message(101,NOKV); CYRPASS=101; } 
         Regul_09off(0); return;
    }
    // �� ࠡ�� ����樨 ������ ⮫쪮 ������� ����樨 � ��᫥ �⮣� ������� ����
    if ( CYRPASS>0 && CYRPASS<101 ){
         // �몫���� ��,� ��⮬ �������,�� ���� (���� ��-㬮�砭�� ����祭,���� �몫����)
         Regul_09off(2); DON069D__V=ON;
         if (OBJAS1___V>0){ DON068C__V=ON; DON068E__V=ON; }
         if (OBJAS2___V>0){ DON069C__V=ON; DON069E__V=ON; }
         // ������ ᥪ㭤� �஢�ઠ ���稪� ���ࠡ�⪨...
         if (RegRUN==ON){
             // �᫨ ������� ����樨 ������ - ����� ���稪 ���ࠡ�⪨ (�� ����� 10ᥪ)
             if((DIS068C__V==ON && DIS068E__V==ON)||(DIS069C__V==ON && DIS069E__V==ON)){
                 if(CYRPASS>1) CYRPASS--; if(CYRPASS>10) CYRPASS=10;
             } else {
             // �᫨ ��-� ������ - ������� ���稪 ���ࠡ�⪨ (ᥪ)
             // �⮡� �������� "�ॡ����" �� ����祭��-�몫�祭��, ��������� ���稪 ��⠭�����=3ᥪ
                 if(CYRPASS<3) CYRPASS=3; if(CYRPASS<200) CYRPASS++; // �� =101 �㤥� ��室 �� ����樨
         }   }
         // �᫨ ���稪 ���ࠡ�⪨ ����� 5ᥪ- �몫���� ���� (��-㬮�砭�� ����祭)
         if(CYRPASS>7) DON069D__V=OFF;
    }    
    // �᫨ ���� �������� �� �몫�祭�� ����樨
    if ( CYRPASS>=101 ){
         Regul_09off(0); Message(102,NOKV); CYRPASS=0; CYRPAS___V=CYRPAS___M=OFF; return;
    }
    //------------------------------

    // �᫨ ॣ���� �몫�祭
    if (REG09R___V == OFF && REG09GL__V == OFF){ Regul_09m(); return; }

    // �᫨ ��祣� ��㧨��- ������� �� �ᯮ���⥫� ॣ���� � ���
    if (TRPAS__VIB <= 0  ){ Regul_09off(1); return; }

    // �᫨ �� �६� ���㧪� ����� ������� ��ଥ⨧���-
    // ������� ������ ���㧪� � �몫���� ॣ����
    if (STEP09>10 and STEP09<=12 and DISVGBMG_V==OFF){
        Bell(1,1); Message(118,NOKV); Message(679,NOKV); Regul_09off(1); 
        REG09R___M=OFF; return;
    }
    //------------------------------------------------------------------------



    // �������� ��砫쭮�� ��������� ����������
    //------------------------------------------------------------------------
    if (STEP09 == 0){
        if(STEP09P!=0){
           ;;
        }; STEP09P =0;
        Regul_09off(1);
        if(RegRUN==OFF){ return; }

        // �᫨ ��蠫�� ����� � ०��� ������� - ���
        REG09SW__V =1;
        if(DIR251___V==1){ return; }

        // �᫨ ����� ������ ���㧪� �� ������- ���
        REG09SW__V =5;
        if(DIS216G__V==ON){ return; }

        CRPAS____V=0;
        AIW216FV_V=0;

        // ����� ������ � ��饬 ॣ����
        SetPubCycStat(PASTA,0);

        // ��������� ��� ������ �����
        AIW216___O=AIW216___V;
        AIW216NV_V=AIW216___V;
        CRPAS____V=AIW216___V-AIW216NV_V;

        // �������� �롮� ०��� ����㧪�-���㧪�
        REG09SW__V =6;

        // ���㫨�� ���稪 �஢�ન ��� �⠡�����樨 ����� �����
        TIME_PAVSC=0;

        //  �������� �����쭠�
        //  �᫨ ॣ���� � �����쭮� ०��� � ��࠭ ०�� ����㧪�-
        //  ��३� �� 蠣 ����� ��.��ᯥ����
        if (REG09GL__V==OFF and REG09ZV__V==ON ){ 
            DON211C1_V =0;
            STEP09=1;  
        }
        //  �������� �����쭠�
        //  �᫨ ॣ���� � �����쭮� ०��� � ��࠭ ०�� ���㧪� �
        //  ������ ��宣� � ���ண� 㦥 ���㦥�� � ��.���� ���࠭� -
        //  ��३� �� 蠣 ���㧪�
        if (REG09GL__V==OFF and REG09ZV__V==OFF and DON211C1_V==1){
            STEP09=10;
        }

        //  �������� ����
        //  �᫨ ॣ���� � ��饬 ०��� � ����祭 ��騩 ॣ����,
        //  ������ ��宣� ����㦥� � � ������ ���ண� �㤥� ����㦠���� ����- 
        //  ��३� �� 蠣 ����㧪� �����
        if (REG09GL__V==ON and RegPublicV==ON and
            DON211B1_V>0   and DON211A1_V>0 and DON211C1_V==0){
            STEP09=1;
        }
        //  �������� ����
        //  �᫨ ॣ���� � ��饬 ०��� � ����祭 ��騩 ॣ����,
        //  ������ ��宣� ���㦥� � ������ ���ண� ���㦥�
        //  � ������ ����� ����㦥�- ��३� �� 蠣  ���㧪�
        if (REG09GL__V==ON and RegPublicV==ON and
           // �� ���㦥�,�� ���㦥�,�� ����㦥�
           (DON211B1_V==0.2 or DON211B1_V==2) and DON211A1_V==2  and DON211C1_V==1){
            STEP09=10;
        }

        return;
    }
    //------------------------------------------------------------------------

    // ����� ��.���������
    //------------------------------------------------------------------------
    if (STEP09 == 1){
        if(STEP09P!=1){
           Clear_TO (91); Clear_TO(92);
           Regul_09off(1);
        }; STEP09P =1;
        REG09SW__V =11;
        STEP09=2;
        return;
    }
    //------------------------------------------------------------------------
    if (STEP09 == 2){
        if(STEP09P!=2){
           Clear_TO (91); Clear_TO (92);
           Regul_09off(1);
        }; STEP09P =2;
        REG09SW__V =21;
        if(RegRUN==OFF){ return; }
        // ����� ������ � ��饬 ॣ����
        SetPubCycStat(PASTA,1);
        // ��㧠 ��। ��砫�� ����� �����
        if(PASSTWT__C<PASSTWT__W){ PASSTWT__C++; return; }
        PASSTWT__C=0;
        STEP09=3;
        return;
    }
    //------------------------------------------------------------------------
    if (STEP09 == 3){
        if(STEP09P!=3){
           Clear_TO(91);
        }; STEP09P =3;
        REG09SW__V =31;
        if(RegRUN==OFF){ return; }
        switch ( Check_TO  (91, TIME_ISPKV*SEC, DIS216G__V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Bell(1,1); Message(408,NOKV); Message(679,NOKV); Clear_TO(91);
                        REG09R___M=OFF; Regul_09off(1); return;
                      }
            case END: { break;; }
        }
        Clear_TO(91);
        STEP09=4;
        return;
    }
    //------------------------------------------------------------------------


    // �������� ��.��� � ������
    //------------------------------------------------------------------------
    if (STEP09 == 4){
        if(STEP09P!=4){
           if(STEP09P!=70) Regul_09off(1);
           Clear_TO(91);
           Clear_TO(92);
           Clear_TO(93);
           AIW216___O=AIW216___V;           // ��������� ⥪�騩 ��� ������
           TIME_PAVSC=0;                    // ���㫨�� ���稪 �६��� �⠡��
           LOAD_PAVSC=0;                    // ���㫨�� ���稪 ��� �⠡��
           PO216=100;
        }; STEP09P =4;
        REG09SW__V =41;

        // ��।����� ��� ���窨, �������
        AIW216VO_V = TRPAS__VIB-LOAD_PATTW;
        AIW216VZ_V = TRPAS__VIB;

        // �஢���� ��� ������:
        // �᫨ ���ࠫ� ��� �����
        if(AIW216___V > TRPAS__VIB-LOAD_PAVOW){ 
           DON068B__V=OFF; DON069B__V=OFF; DON068D__V=OFF; PO216=AON216PO_W;
        }
        
        // �᫨ ���ࠫ� ��� ����� - ��३� �� ᫥� 蠣
        if(AIW216___V > TRPAS__VIB-LOAD_PATTW){ Regul_09off(1); PO216=0; STEP09=5; return; }

        if(RegRUN==OFF){ return; }

        CRPAS____V=AIW216___V-AIW216NV_V;
        AIW216FV_V=1;
        
        //---------------------------------------------------
        // �������� ��������� ���� ������
        // �᫨ ����� ������ �����-㢥����� ���稪 ⥪�饣� �६���
        if(DIS068B__V==ON){ TIME_PAVSC++; }
        // �᫨ ���稪 ����� ���������
        if(TIME_PAVSC>TIME_PAVSW){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW216___O+LOAD_PAVSW>AIW216___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              LOAD_PAVSC++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 (��� ����� ���)
              if(LOAD_PAVSC>CNST_PAN_W){ Bell(1,1); Message(245,KVIT); LOAD_PAVSC=0; return; }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              LOAD_PAVSC=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW216___O=AIW216___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TIME_PAVSC=0;
        }
        //---------------------------------------------------

        //---------------------------------------------------
        // �᫨ ⥪�騩 ��� ������ ����� ��� �������
        if(AIW216___V<AIW216VO_V){
           // � ����ᨬ��� �� ��࠭��� ��蠫�� ��।��塞 ������ ��� �஢�ન
           DIS06XX=DIS068B__V; if(OBJAS2___V>0) DIS06XX=DIS069B__V;
           // �᫨ ������ �몫�祭�
           if(CYRPAS___V==0){
               // � ����� �� ��� ��蠫��- ������ ������ ����� �� ��� �� ��蠫��
               if(OBJAS1___V>0){ DON068B__V=ON;; DON069B__V=OFF;  }
               else            { DON068B__V=OFF; DON069B__V=ON;;  }
               DON068D__V = ON;
               switch ( Check_TO  (91, TIME_ISPKV*SEC, DIS06XX,'=',ON, 1 )){
                   case RUN: { return;; }
                   case BAD: { 
                               if(DONCN09>2){ Bell(1,1); Message(299,KVIT); DONCN09=0; return; }
                             }
                   case END: { Clear_TO(91); DONCN09=0; break;; }
               }
               switch ( Check_TO  (92, TIME_ISPKV*SEC, DIS068D__V,'=',ON, 1 )){
                   case RUN: { return;; }
                   case BAD: { 
                               if(DONCN09>2){ Bell(1,1); Message(299,KVIT); DONCN09=0; return; }
                               Isp09PD(&DON068D__V,3,TIME_ISPPW,70, STEP09P, 92); return;;
                             }
                   case END: { Clear_TO(92); DONCN09=0; break;; }
               }
           }  
           // ������ ����� �� ��� � ������
           // DON216F__V = ON;
           AON216F_OV = AON216F_OM = PO216;
           switch ( Check_TO  (93, TIME_ISPKV*SEC, DIS216F__V,'=',ON, 1 )){
               case RUN: { return;; }
               case BAD: { 
                           if(DONCN09>2){ Bell(1,1); Message(299,KVIT); DONCN09=0; return; }
                           // ��।�ࣨ����� ��� - �ᯮ������ ��������� ������
                           /* Isp09PD(&DON216F__V,3,TIME_ISPPW,70, STEP09P, 93); */ return;
                         }
               case END: { Clear_TO(93); DONCN09=0; break;; }
           }
        }
        //---------------------------------------------------
        return;
    }
    //------------------------------------------------------------------------


    // �������� ������������ ���� ������ ��.����� ��᫥ ����㧪�
    //------------------------------------------------------------------------
    // �஢�ઠ ������� ������� ����� ������� �����
    if (STEP09== 5){
        if(STEP09P!=5){
           Clear_TO(91);
           Clear_TO(92);
           Clear_TO(93);
           CNST_PAN_C=0;                    // ���㫨�� ���稪 �஢�ப �⠡��
           TIME_PAVSC=0;
           AIW216___O=AIW216___V;           // ��������� ⥪�騩 ��� ������
        }; STEP09P =5;
        Regul_09off(1);
        REG09SW__V =51;
        if(RegRUN==OFF){ return; }

        // ���࠭�� ��� ��.��ᯥ����
        CRPAS____V=AIW216___V-AIW216NV_V;
        AIW216FV_V=1;

        // �஢���� �����⨥ ������� ����� ������� ����� � ������
        switch ( Check_TO  (91, TIME_ISPKV, DIS216F__V,'=',OFF, 1 )){
            case RUN: { return; }
            case BAD: { 
                        if(DONCN09>2){ Bell(1,1); Message(297,KVIT); DONCN09=0; return; }
                        // ��।�ࣨ����� ��� - �ᯮ������ ��������� ������
                        /* Isp09PD(&DON216F__V,3,TIME_ISPPW,70, STEP09P, 91); */ return;
                      }
            case END: { DONCN09=0; AIW216___O=AIW216___V; break;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG09SW__V =22;
        switch ( Check_TO  (92, TIME_PAVSW, ZERO,'=',ON, 2)){
            case RUN: { TIME_PAVSC++; return; }
            case BAD: { break;  }
        }
        Clear_TO(91);
        Clear_TO(92);

        // �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        // ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW216___O+LOAD_PAVSW<AIW216___V){
           CNST_PAN_C++;
           // �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           // ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_PAN_C>CNST_PAN_W){
              Bell(1,1); Message(296,NOKV); Message(679,NOKV); REG09R___M=OFF; return;
           } else {
           // �᫨ ���稪 �஢�ப ����� ��������� ��������� ⥪�騩 ���
           // � �� ࠧ �஢���� (�믮����� ��� �� 蠣)
              DON068B__V=ON;  AIW216___O=AIW216___V; return;
           }
        }

        // 䫠� ����� ��� ������ �����
        DON211C1_V=1;

        CRPAS____V=AIW216___V-AIW216NV_V;

        // �᫨ ॣ���� � ��饬 ०���- ��३� �� 蠣 �������� ���㧪�
        if(REG09GL__V==ON and RegPublicV==ON){ 
           STEP09=0;
           return;
        }
        // �᫨ ॣ���� � �����쭮� ०���- �몫���� ॣ����
        Message(390,NOKV); REG09R___M=OFF;
        return;
    }
    //------------------------------------------------------------------------



    // �������� �� �������� ���������� ��������� � ����:

    // �������� ������� ���㧪� (��⮢���� ����)
    //-----------------------------------------------------------------------
    if (STEP09== 10 ){
        if(STEP09P!=10){
           Clear_TO(91);
           Clear_TO(92);
           Clear_TO(93);
           TMPS_PVI_C=0;
        }; STEP09P =10;
        Regul_09off(1);

        if (RegRUN==OFF){ return; }

        //  �᫨ ���� �� ����祭� - ���
        REG09SW__V =102;
        switch ( Check_TO  (91, 1*MIN, DISVGBMR_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(91); Message(386,NOKV); Bell(1,1); return;; }
        }

        //  �᫨ ��ଥ⨧��� �� ���饭 - ���
        REG09SW__V =103;
        switch ( Check_TO  (92, 1*MIN, DISVGBMG_V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(92); Message(387,NOKV); Bell(1,1); return;; }
        }

        // ����� �६� �⠡�����樨 ���
        REG09SW__V =104;
        switch ( Check_TO  (93, TMPS_PVI_W, ZERO,'=',ON, 2)){
            case RUN: { TMPS_PVI_C++; return; }
            case BAD: { break;  }
        }

        // ����� ������ � ��饬 ॣ����
        SetPubCycStat(PASTA,2);

        Clear_TO(91);
        Clear_TO(92);
        Clear_TO(93);

        AIW216___S=AIW216___V;         // ��������� ��� ������ �����
        PA_VSTB=  0;                   // ���㫨�� 䫠� �⠡�����樨 ��� ���
        STEP09 = 11;
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ������� ���㧪� � ����
    //-----------------------------------------------------------------------
    if (STEP09== 11 ){
        if(STEP09P!=11){
           Regul_09off(1);
           AIW216___O=AIW216___V;           // ��������� ��� ������
        }; STEP09P =11;
        if (RegRUN==OFF){ return; }

        // ������ ������ ���㧪� � ����
        REG09SW__V =111;
        DON216G__V = ON;
        switch ( Check_TO  (91, TIME_ISPKV*SEC, DIS216G__V,'=',ON, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN09>2){ Bell(1,1); Message(161,KVIT); DONCN09=0; return; }
                        Isp09PD(&DON216G__V,3,TIME_ISPPW,70, STEP09P, 91); return;
                      }
            case END: { DONCN09=0; break;; }
        };  Clear_TO(91);

        STEP09 = 12;
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ��������
    //-----------------------------------------------------------------------
    if (STEP09==12){
        if(STEP09P!=12){
           VSST_PAVIC=0;                    // ⥪�騩 ���   �⠡�����樨
           TMST_PAVIC=0;                    // ⥪�饥 �६� �⠡�����樨
           CNST_PAVIC=0;                    // ⥪�騩 ���� �⠡�����樨
           TIME_PIVVC=0;                    // ���⥫쭮��� ������ ���㧪�
           TIME_PIVPC=0;                    // ���⥫쭮��� ������ ����
        }; STEP09P =12;
        REG09SW__V =121;
        // �᫨ ⥪�騩 ��� ������ ����� ��� ࠢ�� ��� ��� 
        // ���稪 �⠡�����樨 ����� ���������- ��३� �� ᫥� 蠣
        if(AIW216___V<=0 or CNST_PAVIC>=CNST_PAVIW){ STEP09=13; return; }
        if(RegRUN==OFF){ return; }
        // �஢�ઠ �⠡�����樨 ��� ������
        TMST_PAVIC++;
        if (TMST_PAVIC>TMST_PAVIW){
            // �᫨ ⥪ ��� ������ + ��� �⠡�����樨 ����� ������������
            // ���- ����� ��� �⠡�����஢���� ("�� ���������"(� �।����)) 
            // 㢥����� ���稪 �⠡������ ���
            if (AIW216___V+VSST_PAVIW>AIW216___O){ CNST_PAVIC++; }
            else                                 { CNST_PAVIC=0; }
            // ��������� ⥪�騩 ��� ������ � ���㫨�� ���稪 �६���
            AIW216___O=AIW216___V; TMST_PAVIC=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    //  �஬뢪� ������ �����
    if (STEP09==13){
        if (STEP09P!=13){
            VDPRALUM_C=0;
            WAITBSIG_C=0;
        };  STEP09P=13;
        
        if (RegRUN==OFF){ return; }
        
        //  ������ ������ �஬뢪� ���� ��.��ᯥ����
        DON2x03__V=ON;
        //  �᫨ ���稪 (�६�) �஬뢪� ����� ��������� -
        //  㢥����� ���稪 (����� ����砭�� �஬뢪�)
        if (VDPRALUM_C<VDPRALUM_W){ VDPRALUM_C++; return; }
        //  ������� ������ �஬뢪�
        DON2x03__V=OFF;
        //  ���稪 �������� ��᫥ ���㧪� �� ᨣ���� ����砭�� ���㧪�
        if (WAITBSIG_C<WAITBSIG_W){ WAITBSIG_C++; return; }
        //  ���㫨�� ���稪�
        VDPRALUM_C=0; WAITBSIG_C=0;
        STEP09=14;
        return;
    }
    //-----------------------------------------------------------------------


    // �몫�祭�� ॣ���� ��᫥ ���㧪�
    //-----------------------------------------------------------------------
    if (STEP09==14){
        if (STEP09P!=14){
            VDCOUNT__C++;
            CNTTO[91]=0;
        };  STEP09P =14;
        Regul_09off(1); DON2x03__M=0; DON2x03__V=0;
        if(RegRUN==OFF){ return; }
        // 䫠� ���㧪� ������ �����
        DON211C1_V=2;
        // ����� ��㪮���� ᨣ���� �� ����砭�� ���㧪�, �᫨ � ��饬 ०���
        if (RegPublicV==ON){
            DON090___V=1; M16C12___V=1; CNTTO[91]++; if(CNTTO[91]<3) return; DON090___V=0; M16C12___V=0;
        }
        // �᫨ ॣ���� � �����쭮� ०���- �몫���� ���
        if (REG09GL__V==OFF){ REG09R___M= OFF; }
        // ������ ���ண� ���㦠���� 1-�, ��宣� 2-� ��⥬ ����.
        // ��᫥���� ������ 横� ��饣� ॣ����.
        if (RegPublicV==ON and REG09GL__V==ON and REG09R___V==ON){
            DON211A1_V=0;                       // ��
            if(DON211B1_V==2) DON211B1_V=0;     // ��
            DON211C1_V=0;                       // ��
            // ����� ������ � ��饬 ॣ����
            SetPubCycStat(PSTAT,3);
        }
        //
        STEP09=0; CNTTO[91]=0;
        return;
    }
    //-----------------------------------------------------------------------



    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if ( STEP09 ==70 ){
         if(STEP09P!=70){
            ;;
         }; STEP09P =70;
         if(DONCN09>=DONCH09){ STEP09 = STEP09_PRBK; return; }
         REG09SW__V = 700;
         if(RegRUN==OFF){ return; }
         if(Check_TO(209, DONTM09*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
            Clear_TO(209);
        *DONPR09=(*DONPR09!=ON)?ON:OFF;
         DONCN09++;
         STEP09 = STEP09_PRBK;
         return;
    }
    //-----------------------------------------------------------------------

    //------------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_09m();
    return;
}
//---------------------------------------------------------------------------
