// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// ����஢�� ����

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR07v;
_i far  DONCN07v=0;                 // ���稪 横�� ��।�ࣨ�����             
_i far  DONCH07v=2;                 // �������� ���-�� 横��� ��� ��।�ࣨ�����
_i far  DONTM07v=2;                 // ���-�� ᥪ㭤 ��� � ����

_f far  CNTTEMPv=0;                 // �६���� ���稪

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp07vPD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR07v= IOPNT;
    DONCH07v= hM;
    DONTM07v= hS;
    STEP07v = Step; 
    STEP07v_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_07v(vd){

    ex vd far Regul_07off_V(vd);
    ex vd far Regul_07off_O(int);
    ex vd far Regul_07off_S(int);

    //  ��� ��६���� ��� ������� ����
    _f  DISKLVD=0;

    REG07vS1_V=STEP07v;
    if (REG07vS1_M>0){
        REG07vS1_V=REG07vS1_M; REG07vS1_M=0; STEP07v=REG07vS1_V;
    }

    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if (STEP07v==0){
        if(STEP07vP!=0){
        }; STEP07vP =0;
        if (RegRUN==OFF){ return; }
        return;
    }
    //-----------------------------------------------------------------------


    // ��।������ ���ࠢ����� (����㧪�-���㧪�) ࠡ��� ॣ����
    //-----------------------------------------------------------------------
    if (STEP07v==1){
        if(STEP07vP!=1){
        }; STEP07vP =1;
        if (RegRUN==OFF){ return; }
        return;
    }
    //-----------------------------------------------------------------------



    //-----------------------------------------------------------------------
    // ����� ���� 
    //-----------------------------------------------------------------------

    if (STEP07v==22){
        if(STEP07vP!=22){
           Clear_TO(75); Regul_07off_V();
           AIW251___O = AIW251___V;         // ��������� ⥪�騩 ��� ������
           AIW251NV_V = AIW251___V;         // ��������� ⥪�騩 ��� ������
           AIW251VD_V = AIW251___V;
        }; STEP07vP =22;
        REG07SW__V =221;

        // ��।����� ��� ���窨, ������� � �����஢��
        // �᫨ ��࠭� ����஢�� ����������⭮
        AIW251VO_V = TRVODD_VIB-VSOT_VDDGW;
        AIW251VZ_V = TRVODD_VIB;

        // �஢���� ��� ����� ����:
        // �᫨ ��� ������ ����� ��� ���窨- ��३� �� ����� ᫥� ����
        if(AIW251___V > AIW251VO_V){ Regul_07off_V(); STEP07v=24; return; }

        if(RegRUN==OFF){ return; }

        // ���� �������� �� ����⨥ ������� ����
        DON251H1_V=ON; DON251G1_V=OFF; DISKLVD=DIS251H1_V;
        // �᫨ ��� ���� ��࠭� ��ࢮ� ��� ����� � ����祭 ०�� ⥬������
        if(AIWVDGQ__V==1&&KQ_ON____V==1){ DON251G1_V=ON; DON251H1_V=OFF; DISKLVD=DIS251G1_V; }
        // �஢�ઠ ������ �������
        switch ( Check_TO  (75, TIME_ISPKV*SEC, DISKLVD,'=',ON, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07v>2){ Bell(1,1); Message(151,KVIT); DONCN07v=0; return; }
                      }
            case END: { DONCN07v=0; break;; }
        }
        Clear_TO(75);

        STEP07v=23;
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� ������ ���� 
    //-----------------------------------------------------------------------
    if (STEP07v==23){
        if(STEP07vP!=23){
           TMST_VD__C = 0;
           VSST_VD__C = 0;
           AIW251___O = AIW251___V;         // ��������� ⥪�騩 ��� ������
        }; STEP07vP =23;
        REG07SW__V =231;

        //  ��।����� ��� ���窨, ������� � �����஢��
        //  �᫨ ��࠭� ����஢�� ����������⭮
        AIW251VO_V = TRVODD_VIB-VSOT_VDDGW;
        AIW251VZ_V = TRVODD_VIB;

        // �᫨ ⥪�騩 ��� ����� �楯⭮�� ����� ��� ���窨
        if (AIW251___V >= AIW251VO_V){ Regul_07off_V(); STEP07v=24; return; }

        if (RegRUN==OFF){ return; }

        // �᫨ ����祭 ०�� ����஢�� � ��⮬ ⥬������
        if(KQ_ON____V==1){
           // ��४��祭�� �������� ��� ����� ��㣮� ����
           if(AIWVDGQ__V==1){
              if(AIW251___V>AIWVDG___V){   // �� ��࠭� ��ࢮ�, �-�몫,�-���
                 DON251G1_V=0;
                 DON251H1_V=1;
              }
           } else {
              if(AIW251___V>AIWVDH___V){   // � ��࠭� ��ࢮ�, �-�몫,�-���
                 DON251G1_V=1;
                 DON251H1_V=0;
              }
        }  }

        // 㢥����� ���稪 �६��� �஢�ન ��� ����� ����
           TMST_VD__C++;
        if(TMST_VD__C>TMST_VD__W){
           // �᫨ ���������� ��� ������ + ������� ��� �⠡�����樨 �����
           // 祬 ⥪�騩 ��� ������ (��� ����� ���)
           if(AIW251___O+VSST_VD__W>AIW251___V){
              // 㢥����� ���稪 �஢�ப ��� �⠡�����樨
              VSST_VD__C++;
              // �᫨ ���稪 �஢�ப ��� �⠡�����樨 >2 
              if(VSST_VD__C>2){ Bell(1,1); Message(152,KVIT); VSST_VD__C=0; return; }
           } else {
           // �᫨ ��� ����ࠥ��� ��ଠ�쭮- ���㫨�� ���稪 �஢�ப ���
              VSST_VD__C=0;
           }
           // ��������� ⥪�騩 ��� ������
           AIW251___O=AIW251___V;
           // ���㫨�� ���稪 �६��� �⠡�����樨
           TMST_VD__C=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    // �������� �������� ������� ����� ���� � �⠡�����樨 ���
    //-----------------------------------------------------------------------
    if (STEP07v==24){
        if(STEP07vP!=24){
           Clear_TO(75); Clear_TO(76); Clear_TO(77);
           TMST_VD__C=0;
           CNST_VDD_C=0;
           AIW251___O=AIW251___V;           // ��������� ⥪�騩 ��� ������
        }; STEP07vP =24;
        REG07SW__V =241;
        Regul_07off_V();

        if (RegRUN==OFF){ return; }

        //  �஢���� �����⨥ ������� ����� ����
        switch ( Check_TO  (75, TIME_ISPKV*SEC, DIS251H1_V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07v>2){ Bell(1,1); Message(153,KVIT); DONCN07v=0; return; }
                        Isp07vPD(&DON251H1_V,3,TIME_ISPPW,70, STEP07vP, 75); return;
                      }
            case END: { DONCN07v=0; AIW251___O=AIW251___V; break;; }
        }
        switch ( Check_TO  (76, TIME_ISPKV*SEC, DIS251G1_V,'=',OFF, 1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07v>2){ Bell(1,1); Message(153,KVIT); DONCN07v=0; return; }
                        Isp07vPD(&DON251G1_V,3,TIME_ISPPW,70, STEP07vP, 76); return;
                      }
            case END: { DONCN07v=0; AIW251___O=AIW251___V; break;; }
        }
        Regul_07off_V();

        //  ����� �६� �⠡�����樨 ���
        REG07SW__V =242;
        switch ( Check_TO  (77, TMST_VD__W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VD__C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(75); Clear_TO(76); Clear_TO(77);

        //  �஢�ઠ ��� �⠡�����樨:
        //  �᫨ ���������� ��� ������ + ��� �⠡�����樨 ����� ⥪�饣�
        //  ��� ������ (��� �த������ ���������(��� �⠡�����樨 ���))
        if(AIW251___O+VSST_VD__W<AIW251___V){
           CNST_VDD_C++;
           //  �᫨ ���稪 �஢�ப �⠡�����樨 ����� ���������-
           //  ᮮ�饭��, ������, �몫���� ॣ����
           if(CNST_VDD_C>CNST_VDD_W){
              Bell(1,1); Message(154,KVIT); Message(677,KVIT); REG07R___M=OFF; return;
           }
        }
        STEP07v=30;
        return;
    }
    //-----------------------------------------------------------------------




    // ����������� �������� ��᫥ ����砭�� ���㧪� ��� ����㧪�
    //-----------------------------------------------------------------------
    if (STEP07v==30){
        if(STEP07vP!=30){
        }; STEP07vP =30;

        // �᫨ ����祭 ��騩 ॣ���� � � ������ ���� ����� 20�� - 
        // ��३� �� ���㧪� ����
        if (RegPublicV==ON and REG07GL__V==ON and AIW251___V>20){ STEP07v=51; }

        // �᫨ ����祭 ��騩 ॣ���� � ���㧪� ���饣� �����祭�
        if (RegPublicV==ON and REG07GL__V==ON and (STEP06v>=33 and STEP06v<=34)){
            // ����� ����� ����
            STEP07v=22; return;
        }

        return;
    }
    //-----------------------------------------------------------------------



    // STEP07v > 40 - ���㧪�


    //  �������� �� �������� ���� � ����
    //-----------------------------------------------------------------------
    //  �஢�ઠ ��⮢���� ����
    if (STEP07v==51){
        if(STEP07vP!=51){
           Clear_TO(75); Clear_TO(76);
        }; STEP07vP =51;
        Regul_07off_V();

        if (RegRUN==OFF){ return; }

        //  �᫨ ���� �� ����祭� - ������
        REG07SW__V=511;
        switch ( Check_TO  (75, 1*MIN, DISVGBMR_V,'=',ON, 1 )){
            case RUN: { return; }
            case BAD: { Clear_TO(75); Message(386,NOKV); return; }
        };  Clear_TO(75);

        //  �᫨ ��ଥ⨧��� �� ���饭 - ������
        REG07SW__V=512;
        switch ( Check_TO  (76, 1*MIN, DISVGBMG_V,'=',ON, 1 )){
            case RUN: { return; }
            case BAD: { Clear_TO(76); Message(387,NOKV); return; }
        }

        Clear_TO(75); Clear_TO(76);
        STEP07v=52;

        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �஬뢪� ����
    if (STEP07v==52){
        if (STEP07vP!=52){
            AIW251___O = AIW251___V;                        // ��� ������ ����
            VDPRVGBM_R = AIW251___V * 0.01 * VDPRVGBM_V;    // ��� �஬뢪� ����
            VDPRDSL__R = AIW251___V * 0.01 * VDPRDSL__V;    // ��� �஬뢪� ������
            VDZGVGBM_R = AIW251___V * 0.01 * VDZGVGBM_V;    // ��� ��� ����
        };  STEP07vP=52; REG07SW__V = 521;

        // �᫨ ���� �� ����祭� - ��३� �� 蠣 �஢�ન ����
        if (DISVGBMR_V==OFF){ STEP07v=51; return; }
        // �᫨ ��ଥ⨧��� �� ���饭 - ��३� �� 蠣 �஢�ન ����
        if (DISVGBMG_V==OFF){ STEP07v=51; return; }

        // �᫨ ���㧮�� ������ ���� �� ������ (����� =1) � �ଠ �� ������ (=1)
        if (DIS2x12__V<1 or DIS2x13__V<1){
            // ������� ������ �஬뢪� ����
            // ������ ��� �஬뢪� ���� ��������� � �������⥫쭮� ����
            // ������� ������ �஬뢪� � ��३� �� ᫥���騩 蠣
            // DON2x02__V=OFF; STEP07v=53;
            
            // ����� �����⨥ ������� � ����砭�� ������� ��� (����� ������)
            return;
        }
        
        // �������� 蠣� ����㧪� ��� ���㧪� ॣ���� ������ ���ண� (諠��)
        // �᫨ ���㧪� ����� �� �����祭� - ����� ���㧪� ����� (!!!???)
        REG07SW__V=521;
        if (RegPublicV==ON and REG07GL__V==ON and STEP07<5) return;

        // ������ ������ �஬뢪� ���� � ������� ���� �஬뢪�
        DON2x02__V=ON; DON2x04__V=ON;
        
        // �᫨ ��� ������ �����, 祬 ���������� ��� ����� ��� �஬뢪� ����
        // ������� ������ �஬뢪� � ��३� �� ᫥���騩 蠣
        if (AIW251___V < AIW251___O-VDPRVGBM_R){ DON2x02__V=OFF; STEP07v=53; }
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ���㧪� �������⥫쭮� ���� � ����
    if (STEP07v==53){
        if(STEP07vP!=53){
        }; STEP07vP =53;

        // �������� 蠣� ���㧪� ॣ���� ������ ���ண� (諠��)
        REG07SW__V=531;
        if (RegPublicV==ON and REG07GL__V==ON and STEP07>0 and STEP07<52) return;

        if (RegRUN==OFF){ return; }

        //  ������ ������ ���㧪� � ���� � ������� ����
        REG07SW__V =532;
        DON2x07__V = ON;
        DON2x04__V = ON;
        switch ( Check_TO  (75, TIME_ISPKV*SEC, DIS2x07__V,'=',ON, 1)){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN07v>2){ Bell(1,1); Message(159,KVIT); DONCN07v=0; return; }
                        Isp07vPD(&DON2x07__V,3,TIME_ISPPW,70, STEP07vP, 75); return;
                      }
            case END: { DONCN07v=0; break;; }
        };  Clear_TO(75);
        
        MK_VG_KL_OPEN=0; 
        AIW251___P=AIW251___V;
        STEP07v=54;
        return;
    }
    //-----------------------------------------------------------------------


    // �������� ���� �������� ������ ����
    //-----------------------------------------------------------------------
    if (STEP07v==54){
        if (STEP07vP!=54){
            AIW251___P=AIW251___V;
            VSST_MKVIC=0;
            TMST_MKVIC=0;
            CNST_MKVIC=0;
        };  STEP07vP =54;
        REG07SW__V =541;

        //  �᫨ ⥪�騩 ��� ������ ����� ��� ࠢ�� ���- ��३� �� ᫥� 蠣
        if (AIW251___V<=0 or CNST_MKVIC>=CNST_MKVIW){ DON2x02__V=OFF; STEP07v=55; return; }

        //  �᫨ ��� ������ �����, 祬 ���������� ��� ������ ����� (��� �஬뢪� + ��� ��� ����),
        //  ������� ������ ����஢�� � ��३� �� ᫥���騩 蠣
        if (AIW251___V < AIW251___O - (VDPRVGBM_R+VDZGVGBM_R) ){ DON2x02__V=OFF; STEP07v=55; }

        if (RegRUN==OFF){ return; }

        //  �᫨ ����諮 �६� �஢�ન �⠡�����樨 ��� ������ ���ண�
        TMST_MKVIC++;
        if (TMST_MKVIC>TMST_MKVIW){
            //  �᫨ ��� �⠡�����஢����- 㢥����� ���稪 �⠡������ ���
            if (AIW251___V+VSST_MKVIW>AIW251___P){ CNST_MKVIC++; }
            else                                 { CNST_MKVIC=0; }
            AIW251___P=AIW251___V; TMST_MKVIC=0;
        }
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �������� ���㧪� 諠��
    if (STEP07v==55){
        if (STEP07vP!=55){
            DON2x07__V=OFF; // ������� ������ ���㧪� � ����
        };  STEP07vP =55;
        if (RegRUN==OFF){ return; }
        REG07SW__V =551;
        // �᫨ ����祭 ��騩 ॣ���� - ����� ���㧪� 諠��
        if(RegPublicV==ON and REG07GL__V==ON and STEP07>=52 and STEP07<55) return;
        STEP07v=56;
        return;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // �஬뢪� ������ 諠��
    if (STEP07v==56){
        if(STEP07vP!=56){
           Clear_TO(75); Clear_TO(76);
        }; STEP07vP =56;

        // ������ ������ ���� � ������ 諠��, ������� ���� �஬뢪�
        DON2x01__V=ON;
        DON2x04__V=ON;

        if (RegRUN==OFF){ return; }
 
        REG07SW__V =561;

        //  �᫨ ��� ������ ����� ��� - 㢥����� ���稪
        if (AIW251___V>0){ CNTTO[75]++; }
        else             { STEP07v=59;  }
        //  �᫨ ���稪 > ??ᥪ (���ᨬ��쭮� �६� �஬뢪�) - ��३� �� ᫥� 蠣
        if (CNTTO[75]>30){ STEP07v=59;  }
        return;
    }
    //-----------------------------------------------------------------------

    // १��
    if (STEP07v==57 or STEP07v==58){ STEP07v=59; return; }


    // �������������� ������� ��������
    //-----------------------------------------------------------------------
    if (STEP07v==59){
        if(STEP07vP!=59){
           CNST_MKVIC=0;
           Clear_TO(75); Clear_TO(76);
        }; STEP07vP =59;
        
        if (RegRUN==OFF){ return; }

        REG07SW__V =591;
        MK_VG_KL_OPEN++;

        if(DON2x07__V ==ON & MK_VG_KL_OPEN%3==0){
           DON2x07__V = OFF;
           switch ( Check_TO  (75, 2, DON2x07__V,'=',OFF, 1 )){
               case RUN: return;;
           };  Clear_TO(75);
        }

        if(DIS2x07__V ==OFF & MK_VG_KL_OPEN%3==0){
           DON2x07__V = ON;
           switch ( Check_TO  (76, 5, DIS2x07__V,'=',ON, 1 )){
               case RUN: return;;
           };  Clear_TO(76);
        }

        if (MK_VG_KL_OPEN>7){ STEP07v=60; }
        return;
    }
    //-----------------------------------------------------------------------


    // ������� �� ������� ������ ����
    //-----------------------------------------------------------------------
    if (STEP07v==60){
        if(STEP07vP!=60){
           ;;
        }; STEP07vP =60;
        // ������� � �몫���� �� �ᯮ���⥫� ������ ����
        Regul_07off_V();
        if (RegRUN==OFF){ return; }
        // �஢�ઠ ������� ������� ���㧪�
        REG07SW__V = 601;
        switch ( Check_TO  (75, TIME_ISPKV*SEC, DIS2x07__V,'=',OFF, 1 )){
            case RUN: return;;
            case BAD: { 
                        if(DONCN07v>2){ Bell(1,1); Message(160,KVIT); DONCN07v=0; return; }
                        Isp07vPD(&DON2x07__V,3,TIME_ISPPW,70, STEP07vP, 75); return;
                      }
            case END: { DONCN07v=0; break;; }
        };  Clear_TO(75);

        STEP07v=30;
        return;
    }
    //-----------------------------------------------------------------------

    // १��
    if (STEP07v>60 and STEP07v<70){ STEP07v=60; return; }


    //-----------------------------------------------------------------------
    // �������������� ��������
    //-----------------------------------------------------------------------
    if (STEP07v==70){
        if(STEP07vP!=70){
           ;;
        }; STEP07vP =70;
        if(DONCN07v>=DONCH07v){ STEP07v=STEP07v_PRBK; return; }
        REG07SW__V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(207, DONTM07v*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(207);
       *DONPR07v=(*DONPR07v!=ON)?ON:OFF;
        DONCN07v++;
        STEP07v=STEP07v_PRBK;
        return;
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
