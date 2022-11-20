//---------------------------------------------------------------------------
// �����窠 ����-���

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR10;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN10=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH10=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM10=2;               // ���-�� ᥪ㭤 ��� � ����
_i far  STEP10X=0;               // ���������� 蠣 �� �몫�祭�� ॣ����

//---------------------------------------------------------------------------
//  ��।������ ��� ��।�ࣨ����� �ᯮ���⥫�� ॣ���� �� ���ࠡ�⪥
vd  Isp10PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR10= IOPNT;
    DONCH10= hM;
    DONTM10= hS;
    STEP10 = Step; 
    STEP10_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_10off(vd){
    DON272___V = OFF;
    DON274___V = OFF;
    DON301___V = OFF;
    DIS275___W = OFF;
    DIS275___S = OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� ॣ����
vd  far Regul_10m(vd){
    //-----------------------------------------------------------------------
    if ( STEP10 == 101 ){
         REG10SW__V=1001;
         Regul_10off();
         COUN_PADZC=COUN_PADZW;
         STEP10 =  102;
    }
    //-----------------------------------------------------------------------
    if ( STEP10 == 102 ){
         REG10SW__V = 1002;
         REG10R___M = OFF;
         return;
    }
    //-----------------------------------------------------------------------
    STEP10=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
vd  far Regul_10(vd){
    // ��⠭���� ��� ࠡ��� ॣ����, ��।��塞� �����஬ 

    // �६� �������� ���믪� ���
    if (TIME_PAVZM <  0){ TIME_PAVZM =10; }
    if (TIME_PAVZM != TIME_PAVZV){ TIME_PAVZV = TIME_PAVZM; }    // 10 MIN
    // �६� ��६�訢���� ���
    if (TIME_PPM1M <  0){ TIME_PPM1M =20; }
    if (TIME_PPM1M != TIME_PPM1V){ TIME_PPM1V = TIME_PPM1M; }    // 20 MIN

    // ⥬������ ����-���
    if (TEMP_PAVDM <  0){ TEMP_PAVDM =30; }
    if (TEMP_PAVDM != TEMP_PAVDV){ TEMP_PAVDV = TEMP_PAVDM; }    // 30 C

    // �६� ����� ���� �஢�� ������ ����-���
    if (TIME_PLLVW <  0){ TIME_PLLVW = 2; }                      // 2 MIN
    // �६� ����� ���� �஢�� ������ ����-���
    if (TIME_PHLVW <  0){ TIME_PHLVW = 5; }                      // 5 MIN

    // �६� ����� ���� �஢�� ����. ��蠫�� ��.�����
    if (TIME_PALNW <  0){ TIME_PALNW = 2; }                      // 2 MIN
    // �६� ����� ���� �஢�� ����. ��蠫�� ��.�����
    if (TIME_PANNW <  0){ TIME_PANNW = 5; }                      // 5 MIN

    // �६� ����� ���� �஢�� ����. ��蠫�� ��.�����
    if (TIME_PALVW <  0){ TIME_PALVW = 2; }                      // 2 MIN
    // �६� ����� ���� �஢�� ����. ��蠫�� ��.�����
    if (TIME_PANVW <  0){ TIME_PANVW = 5; }                      // 5 MIN

    // �६� �몫�祭�� ����
    if (TIME_PNOFM <  0){ TIME_PNOFM = 2; }                      // 2 MIN
    if (TIME_PNOFM != TIME_PNOFV){ TIME_PNOFV = TIME_PNOFM; }    // 10 MIN

    //  ����஫� ������� �஢�� ������ ����-���
    if (CTRL_LLVPM <  0){ CTRL_LLVPV = ON; CTRL_LLVPM = OFF; }   // ON
    if (CTRL_LLVPM == SWITCH){ 
        CTRL_LLVPV = (CTRL_LLVPV!=ON) then_ ON else_ OFF; CTRL_LLVPM=OFF;
    }
    //  ����஫� ���孥�� �஢�� ������ ����-���
    if (CTRL_HLVPM <  0){ CTRL_HLVPV = ON; CTRL_HLVPM = OFF; }   // ON
    if (CTRL_HLVPM == SWITCH){ 
        CTRL_HLVPV = (CTRL_HLVPV!=ON) then_ ON else_ OFF; CTRL_HLVPM=OFF;
    }
    //  ����஫� ������� �஢�� ���� ��蠫�� ��.�����
    if (CTRL_LLM1M <  0){ CTRL_LLM1V = ON; CTRL_LLM1M = OFF; }   // ON
    if (CTRL_LLM1M == SWITCH){ 
        CTRL_LLM1V = (CTRL_LLM1V!=ON) then_ ON else_ OFF; CTRL_LLM1M=OFF;
    }
    //  ����஫� ���孥�� �஢�� ���� ��蠫�� ��.�����
    if (CTRL_HLM1M <  0){ CTRL_HLM1V = ON; CTRL_HLM1M = OFF; }   // ON
    if (CTRL_HLM1M == SWITCH){ 
        CTRL_HLM1V = (CTRL_HLM1V!=ON) then_ ON else_ OFF; CTRL_HLM1M=OFF;
    }
    //  ����஫� ������� �஢�� ���� ��蠫�� ��.�����
    if (CTRL_LLM2M <  0){ CTRL_LLM2V = ON; CTRL_LLM2M = OFF; }   // ON
    if (CTRL_LLM2M == SWITCH){ 
        CTRL_LLM2V = (CTRL_LLM2V!=ON) then_ ON else_ OFF; CTRL_LLM2M=OFF;
    }
    //  ����஫� ���孥�� �஢�� ���� ��蠫�� ��.�����
    if (CTRL_HLM2M <  0){ CTRL_HLM2V = ON; CTRL_HLM2M = OFF; }   // ON
    if (CTRL_HLM2M == SWITCH){ 
        CTRL_HLM2V = (CTRL_HLM2V!=ON) then_ ON else_ OFF; CTRL_HLM2M=OFF;
    }

    // ���稪 ������⢠ ����஢�� �����
    if (COUN_PADZW <  0){ COUN_PADZW = 4;  }                     // 4 DOZ
    // ��।������ ���ﭨ� 䫠�� ���믪� ��� (�� ������)
    if(DIS275___W==SWITCH){
       DIS275___W=(DIS275___W==ON) then_ OFF else_ ON;
    }

    // ����祭��-�몫�祭�� ॣ����
    if ( REG10RS__M == SWITCH ){ 
         REG10R___M = (REG10R___M==ON) then_ OFF else_ ON; REG10RS__M=OFF;
    }
    if (REG10R___M!= REG10R___V){ 
        REG10R___M =(REG10R___M==ON) then_ ON else_ OFF;
        REG10R___V = REG10R___M; 
        if(REG10R___V>0){
           if(STEP10P==15){ Message(413); STEP10=STEP10X; }   // ���� ����
           else           { Message(410); STEP10=   0; }      // ���  ॣ����
        } else {
           if(STEP10P==11){ Message(411); STEP10= 101; }      // �몫 ॣ����
           else           { Message(412); STEP10= 15;  }      // ��㧠
        }
    }
    // �᫨ ॣ���� �몫�祭
    if ( REG10R___V == OFF ){ Regul_10m(); return; }
    //-----------------------------------------------------------------------



    // ���������� ��������� �����
    //-----------------------------------------------------------------------
    if (RegRUN==ON){
       // �᫨ ��� ����� 10 �� � 䫠� ���稪�=0 㢥����� ���稪 ����㧪�
       if(AIW290___V>10  and FLAG_PADZC==0)  { FLAG_PADZZ++; }
       else                                  { FLAG_PADZZ=0; }
       // �᫨ ��� ����� 2 �� � 䫠� ���稪�=1 㢥����� ���稪 ���㧪�
       if(AIW290___V<2   and FLAG_PADZC==1)  { FLAG_PADZV++; }
       else                                  { FLAG_PADZV=0; }
       //---------
       // �᫨ ��� 㤥ন������ ����� 5 ᥪ - ��⠥�, �� ������ ����㦥�
       if(AIW290___V>10  and FLAG_PADZC==0 and FLAG_PADZZ== 5 ){
          FLAG_PADZC=1;
       }
       // �᫨ ��� 㤥ন������ ����� 5 ᥪ - ��⠥�, �� ������ ���㦥�
       // (��諠 ���� ����஢�� �����)
       if(AIW290___V<2   and FLAG_PADZC==1 and FLAG_PADZV== 5 ){
          FLAG_PADZC=0;  COUN_PADZC++;
       }
       //---------
       if(FLAG_PADZZ>100){ FLAG_PADZZ=100; }
       if(FLAG_PADZV>100){ FLAG_PADZV=100; }
    }
    //-----------------------------------------------------------------------



    // �������� ������� ����祭�� ॣ����
    //-----------------------------------------------------------------------
    if ( STEP10 == 0 ){
        if(STEP10P!=0){
           Clear_TO(191);
           Clear_TO(192);
           Clear_TO(193);
           Clear_TO(194);
           Clear_TO(195);
           Clear_TO(196);
           Clear_TO(197);
           Clear_TO(198);
           Clear_TO(199);
        }; STEP10P =0;
        Regul_10off();
        // �᫨ ��� ᨣ���� ������� �஢�� � ������ ����-���
        // � ����祭 ����஫� �஢�� - ���
        REG10SW__V=1;
        if(DIL270___V==OFF and CTRL_LLVPV==ON){ return;  }
        // �᫨ ��� ᨣ���� ������� �஢�� � ����.��蠫�� ��.�����
        // � ����祭 ����஫� �஢�� - ���
        REG10SW__V=2;
        if(DIL300___V==OFF and CTRL_LLM1V==ON){ return;  }
        // �᫨ ������� ����-��� ��ॢ����� �� ��筮� �ࠢ�����- ���
        REG10SW__V=3;
        if(DIR270___V==MANUAL){ return;  }
        // �᫨ ����. ��蠫�� ��.����� ��ॢ����� �� ��筮� �ࠢ�����- ���
        REG10SW__V=4;
        if(DIR300___V==MANUAL){ return;  }

        // �஢�ઠ ���ﭨ� �ᯮ���⥫�� ॣ����:
        REG10SW__V=5;
        // �ᯮ���⥫� ������ ����-���
        if (DIS272___V==ON or DIS274___V==ON){ 
            switch(Check_TO(191,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(269); Bell(1); Clear_TO(191); return;; }
            }
        };  Clear_TO(191);
        // �ᯮ���⥫� ���� ��蠫�� ��.�����
        if (DIS301___V==ON){ 
            switch(Check_TO(192,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(269); Bell(1); Clear_TO(192); return;; }
            }
        };  Clear_TO(192);
        TIME_PHLVCMin=0;            // ���㫨�� ���稪� �६��� ����� 
        TIME_PHLVC   =0;            // � ������� ����-���
        TIME_PLLVCMin=0;
        TIME_PLLVC   =0;
        COUN_PADZC   =0;            // ���㫨�� ���-�� ����஢��
        STEP10=1;
        return;
    }
    //------------------------------------------------------------------------



    // ����� ���� � ������� ����-���
    //------------------------------------------------------------------------
    if (STEP10 == 1 ){
        if(STEP10P!=1){
            ;;
        }; STEP10P =1;
        if(RegRUN==OFF){ return; }
        REG10SW__V=10;

        // ������ ������ ����� ����
        // ����           ��� ����         ����             ���
        DON272___V=ON;;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;

        //-------------------------------------------------------------------
        // ���稪 �������� �몫�祭�� ᨣ���� ������� �஢�� ������ ����-���:
        switch ( Check_TO(199, TIME_PLLVW*MIN, DIL270___V,'=',OFF, TIME_LSTBV )){
            case RUN:{ TIME_PLLVCMin++; TIME_PLLVC=TIME_PLLVCMin/MIN; break;; }
            // �᫨ �� �������� �६� ᨣ��� ������� �஢�� ������ ����-���
            // ��⠫�� �ࠡ�⠭��
            case BAD:{ 
                        Bell(1); Message (234); Clear_TO(199); break;;  
                     }
            // �� �������� �६� ᨣ��� ������� �஢�� ��� ����-��� �ய��
            case END:{ 
                        if(CTRL_LLVPV==OFF){
                           TIME_PLLVCMin++; TIME_PLLVC=TIME_PLLVCMin/MIN;
                        } else {
                           Clear_TO(199);
                        }; break;;
                     }
        } 
        //--------------------------------------------------------------------

        //--------------------------------------------------------------------
        // ���稪 �������� ����祭�� ᨣ���� ���� �஢�� ������ ����-���:
        switch ( Check_TO(198, TIME_PHLVW*MIN, DIH270___V,'=',ON, TIME_LSTBV )){
            case RUN:{ TIME_PHLVCMin++; TIME_PHLVC=TIME_PHLVCMin/MIN; break;; }
            // �᫨ �� �������� �६� ᨣ��� ���� �஢�� ������ ����-���
            // ��⠫�� �ࠡ�⠭��
            case BAD:{ 
                        Bell(1); Message(235); Message(680); Clear_TO(198); 
                        REG10R___M=OFF; break;
                     }
            // �� �������� �६� ᨣ��� ������� �஢�� ��� ����-��� �ய��
            case END:{ 
                        // �᫨ �몫 ����� ��� �� ��� ��室��- ����� �६�
                        if(CTRL_HLVPV==OFF){
                           TIME_PHLVCMin++; TIME_PHLVC=TIME_PHLVCMin/MIN;
                        }; break;;
                     }
        };  Clear_TO(198);
        //--------------------------------------------------------------------

        // ������� ������ ᨣ���� ���孥�� �஢�� ������ ����-���
        switch ( Check_TO(191, TIME_PHLVW*MIN, DIH270___V,'=',ON, TIME_LSTBV )){
            case RUN:{ return;; }
        };  Clear_TO(191);

        // ������� ������ ����� ���� � ��� ����-���
        // ����           ��� ����         ����             ���              
        DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;

        // ���ࠫ� ���� � ������� ����-��� - ��३� �� ᫥���騩 蠣
        STEP10 = 2;
        return;
    }
    //------------------------------------------------------------------------



    // ������ ���������: ������ ��� � ������� ����-���? (��/���)
    //------------------------------------------------------------------------
    if ( STEP10 == 2 ){
         if(STEP10P!=2){
           ;;
         }; STEP10P =2;
         if(RegRUN==OFF){ return; }
         REG10SW__V=20;
         // ����           ��� ����         ����             ���              
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         //
         if(REG10ZO1_W==END){ REG10ZO1_W=OFF; Clear_TO(191); }
         switch(Check_TO(191,1*MIN, REG10ZO1_W,'=',YES, 1)){
            case RUN:{ return;; }
            case BAD:{ 
                       Bell(1); Message(236); Clear_TO(191); REG10ZO1_W=REQ;
                       return;
                     }
         }; Clear_TO(191);
         REG10SW__V=21;
         REG10ZO1_W=OFF;
         // �᫨ ���� ᨣ��� �� ������ � ���믪� ��� ��३� �� ᫥� 蠣
         DIS275___S=ON;      // ��⠭����� 䫠� ��� ॣ���� ⥬�������(14)
         DIS275___W=OFF;
         STEP10 = 3;
         return;
    }
    //------------------------------------------------------------------------



    // �������� �������� ����������� � ������ ����-���
    //------------------------------------------------------------------------
    if ( STEP10 == 3 ){
         if(STEP10P!=3){
            ;;
         }; STEP10P =3;
         if(RegRUN==OFF){ return; }
         // ����           ��� ����         ����             ���              
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=ON;
         // �஢�ઠ ⥬������� ������ ����-���
         REG10SW__V=30;
         switch ( Check_TO(191, 20*MIN, AIT270___V,'>',TEMP_PAVDV, 5)){
             case RUN:{ return;; }
             case BAD:{ Clear_TO(191); return;; }
         };  Clear_TO(191);
         // �᫨ ��� ������ ��蠫�� ��.����� ����祭 ����஫� �� � ��� 
         // ᨣ���� ��- ����� ���� �� ����� ᨣ��� ��� �� �몫. ����஫�.
         REG10SW__V=31;
         if(CTRL_LLM1V==ON && DIL300___V==OFF){ return; }
         // �᫨ ��蠫�� �� ��筮� �ࠢ�����- �����...
         REG10SW__V=32;
         if(DIR300___V==MANUAL){ return; }
         // �᫨ �� ࠡ�⠥� �ਢ�� ��蠫��- �����...
         REG10SW__V=33;
         if(DIS300___V==OFF){ return; }
         // ���室 �� ����� �������
         STEP10  = 4;
    }
    //------------------------------------------------------------------------



    // ������ ���������: ����� ����� ��� � ������ ��蠫�� ��.�����?
    //------------------------------------------------------------------------
    if ( STEP10 == 4 ){
         if(STEP10P!=4){
           ;;
         }; STEP10P =4;
         if(RegRUN==OFF){ return; }
         REG10SW__V=40;
         // ����           ��� ����         ����             ���              
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=ON;
         //                                                                   
         if(REG10ZO2_W==END){ REG10ZO2_W=OFF; Clear_TO(191); }
         switch(Check_TO(191,1*MIN, REG10ZO2_W,'=',YES, 1)){
            case RUN:{ return;; }
            case BAD:{ 
                       Bell(1); Message(239); Clear_TO(191); REG10ZO2_W=REQ;
                       return;
                     }
         }; Clear_TO(191);
         REG10SW__V=41;
         REG10ZO2_W=OFF;
         // ������� ������ ����� ���
         DIS275___S=OFF;
         STEP10 = 5;
         return;
    }
    //------------------------------------------------------------------------



    // ����� ��� � ������ ��蠫�� ��.�����
    //------------------------------------------------------------------------
    if ( STEP10 == 5 ){
         if(STEP10P!=5){
            Clear_TO(198);
            Clear_TO(199);
            TIME_PALNC=0;
            TIME_PALNCMin=0;
            TIME_PANNC=0;
            TIME_PANNCMin=0;
         }; STEP10P=5;
         if(RegRUN==OFF){ return; }
         REG10SW__V=50;
         // ������� ������ ����� ���
         DIS275___S=OFF;
         // ������ ������ ����� ��� � ������ ��蠫�� ��.�����
         // ����           ��� ����         ����             ���            
         DON272___V=OFF;   DON274___V=ON;;   DON301___V=OFF;   DIS275___S=OFF;
         // �᫨ �� �६� ����� ��� � ���� ��蠫�� ��.��ᯥ����, 
         // �몫�稫�� �ਢ�� ��蠫��- �몫 ॣ����
         if(DIS300___V==OFF){
            Bell(1); Message(490); Message(680); Regul_10off(); 
            REG10R___M=OFF; return;
         }
         // �᫨ �� �६� ����� ��� � ���� ��蠫�� ��.��ᯥ����, 
         // ��ॢ��� ���� � ����. "��筮�"- �몫 ॣ����
         if(DIR300___V==MANUAL){
            Bell(1); Message(491); Message(680); Regul_10off(); 
            REG10R___M=OFF; return;
         }
         //-------------------------------------------------------------------
         // ���稪 �������� �몫�祭�� ᨣ���� ������� �஢�� ���� ��蠫��:
         switch ( Check_TO(199, TIME_PALNW*MIN, DIL300___V,'=',OFF, TIME_LSTBV )){
             case RUN:{ TIME_PALNCMin++; TIME_PALNC=TIME_PALNCMin/MIN; break;; }
             // �᫨ �� �������� �६� ᨣ��� ������� �஢�� ���� ��蠫��
             // ��⠫�� �ࠡ�⠭��
             case BAD:{ 
                         Bell(1); Message (240); Clear_TO(199); break;;  
                      }
             // �� �������� �६� ᨣ��� ������� �஢�� ���� ��蠫�� �ய��
             case END:{ 
                         if(CTRL_LLM1V==OFF){
                            TIME_PALNCMin++; TIME_PALNC=TIME_PALNCMin/MIN;
                         } else {
                            Clear_TO(199);
                         }; break;;
                      }
         } 
         //-------------------------------------------------------------------

         //-------------------------------------------------------------------
         // ���稪 �������� ����祭�� ᨣ���� ���� �஢�� ���� ��蠫�� ��.���:
         switch ( Check_TO(198, TIME_PANNW*MIN, DIH300___V,'=',ON, TIME_LSTBV )){
             case RUN:{ TIME_PANNCMin++; TIME_PANNC=TIME_PANNCMin/MIN; return; }
             // �᫨ �� �������� �६� ᨣ��� ���� �஢�� ���� ��蠫�� ��.�����
             // ��⠫�� �ࠡ�⠭��- �몫���� ॣ����
             case BAD:{ 
                         Bell(1); Message(235); Message(680); Clear_TO(241); 
                         REG10R___M=OFF; break;;  
                      }
             // �� �������� �६� ᨣ��� ������� �஢�� ��� ����-��� �ய��
             case END:{ 
                         if(CTRL_HLM1V==OFF){
                            TIME_PANNCMin++; TIME_PANNC=TIME_PANNCMin/MIN;
                         }; break;;
                      }
         };  Clear_TO(198);
         //-------------------------------------------------------------------
         // ������� ������ ����� ���
         // ����           ��� ����         ����             ���              
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         STEP10 = 6;
         return;
    }
    //------------------------------------------------------------------------



    // ������ ���������: ����� ��६�訢���� ���?
    //------------------------------------------------------------------------
    if ( STEP10 == 6 ){
         if(STEP10P!=6){
           ;;
         }; STEP10P =6;
         if(RegRUN==OFF){ return; }
         REG10SW__V=60;
         // ����           ��� ����         ����             ���
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         //
         if(REG10ZO3_W==END){ REG10ZO3_W=OFF; Clear_TO(191); }
         switch(Check_TO(191,1*MIN, REG10ZO3_W,'=',YES, 1)){
            case RUN:{ return;; }
            case BAD:{ 
                       Bell(1); Message(242); Clear_TO(191); REG10ZO3_W=REQ;
                       return;
                     }
         }; Clear_TO(191);
         REG10SW__V=61;
         REG10ZO3_W=OFF;
         STEP10 = 7;
         return;
    }
    //------------------------------------------------------------------------



    // ������������� ���
    //------------------------------------------------------------------------
    if ( STEP10 == 7 ){
         if(STEP10P!=7){
            TIME_PPM1C=0;
            TIME_PPM1CMin=0;
            Clear_TO(191);
            Clear_TO(192);
         }; STEP10P =7;
         if(RegRUN==OFF){ return; }
         REG10SW__V=70;
         // ����           ��� ����         ����             ���
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         // �᫨ ��蠫�� ��⠭�������- ���㫨�� �६� ��६�訢����
         switch ( Check_TO(191, 30*SEC, DIS300___V,'=',OFF, 1)){
             case RUN:{ break; }
             case END:{ TIME_PPM1C=0; TIME_PPM1CMin=0; Clear_TO(191); break; }
         }
         // ����� �६� ��६�訢���� ���
         switch ( Check_TO(192, TIME_PPM1V*MIN, ZERO,'=',ON, 1)){
             case RUN:{ TIME_PPM1CMin++; TIME_PPM1C=TIME_PPM1CMin/MIN; return; }
             case BAD:{ break;; }
         }
         // �᫨ ����祭 ����஫� ������� �஢�� ���� ��蠫�� ��.�����
         // � ��� ᨣ���� ������� �஢��  ����.��蠫�� ��.�����- �����
         // (� ��蠫�� ��-� ����, ����� �� ����)
         REG10SW__V=71;
         if(CTRL_LLM2V==ON and DIL280___V==OFF){ return; }
         // �᫨ ����祭 ����஫� ���孥�� �஢�� ���� ��蠫�� ��.�����
         // � ���� ᨣ��� ���孥�� �஢��  ����.��蠫�� ��.�����- �����
         // (� ������ ��蠫�� ����� �� ����)
         REG10SW__V=72;
         if(CTRL_HLM2V==ON and DIH280___V==ON){ return; }
         // �᫨ ����祭 ����஫� ������� �஢�� ������ ��蠫�� ��.�����
         // � ���� ᨣ��� ������� �஢��- �����
         // (�� ���⮩ ��蠫�� ����� ��祣�)
         REG10SW__V=73;
         if(CTRL_LLM1V==ON and DIL300___V==ON){ return; }
         // �᫨ �� ࠡ�⠥� �ਢ�� ������ ��蠫�� ��.�����- �����
         REG10SW__V=74;
         if(DIS300___V==OFF){ return; }
         // �᫨ �� ࠡ�⠥� �ਢ�� ���孥� ��蠫�� ��.�����- �����
         REG10SW__V=75;
         if(DIS280___V==OFF){ return; }
         // �᫨ ������ ��蠫�� ��.����� �� ������ ०���- �����
         REG10SW__V=76;
         if(DIR300___V==OFF){ return; }
         // �᫨ � ���孥� ��蠫�� ��.����� ���� ���㧪� ����� 
         // � �஬������� �������- �����
         REG10SW__V=77;
         if(DIS281___V==ON ){ return; }
         // �᫨ ������ ��蠫�� �� ��筮� �ࠢ�����- ����� (ᤥ���� �����)
         REG10SW__V=78;
         if(DIR280___V==OFF){ return; }
         // �� ����砭�� ��६�訢���� ��३� �� ᫥���騩 蠣
         REG10SW__V=79;
         STEP10 = 8;
         return;
    }
    //------------------------------------------------------------------------



    // ������ ���������: ��蠫�� ��� ������: ������ ����������. ����������?
    //------------------------------------------------------------------------
    if ( STEP10 == 8 ){
         if(STEP10P!=8){
           ;;
         }; STEP10P =8;
         if(RegRUN==OFF){ return; }
         REG10SW__V=80;
         // ����           ��� ����         ����             ���
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         // �᫨ ������ ��蠫�� ��.����� �� ��⮬���. �ࠢ�����-
         // ��३� �� ᫥���騩 蠣
         if(DIR280___V==AUTO){ STEP10=9; REG10ZO4_W=OFF; return; }
         // ������� �⢥� �� ������
         REG10SW__V=81;
         if(REG10ZO4_W==END){ REG10ZO4_W=OFF; Clear_TO(191); }
         switch(Check_TO(191,1*MIN, REG10ZO4_W,'=',YES, 1)){
            case RUN:{ return;; }
            case BAD:{ 
                       Bell(1); Message(150); Clear_TO(191); REG10ZO3_W=REQ;
                       return;
                     }
         }; Clear_TO(191);
         REG10SW__V=82;
         REG10ZO4_W=OFF;
         STEP10 = 9;
         return;
    }
    //------------------------------------------------------------------------



    // ��������� ��.����� � ������ ��蠫�� ��.�����
    //------------------------------------------------------------------------
    if ( STEP10 == 9 ){
         if(STEP10P!=9){
            Clear_TO(191);
            Clear_TO(192);
            Clear_TO(193);
            Clear_TO(194);
            Clear_TO(195);
            Clear_TO(198);
            Clear_TO(199);
            TIME_PALVC=0;
            TIME_PALVCMin=0;
            TIME_PANVC=0;
            TIME_PANVCMin=0;
         }; STEP10P=9;
         if(RegRUN==OFF){ return; }
         REG10SW__V=90;
         // ������� ���� ������ ��蠫�� ��.�����
         // ����           ��� ����         ����             ���            
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=ON;;   DIS275___S=OFF;

         //-------------------------------------------------------------------
         // �᫨ �� �६� ��४�窨 ��� � ���� ��蠫�� ��.��ᯥ����, 
         // �몫�稫�� �ਢ�� ��蠫��- �몫 ॣ����
         switch ( Check_TO(191, 5*SEC, DIS280___V,'=',ON, 2)){
             case RUN:{ break;; }
             case END:{ Clear_TO(191); break;; }
             case BAD:{ 
                        Bell(1); Message(492); Message(680); Regul_10off(); 
                        REG10R___M=OFF; Clear_TO(191); return; 
                      }
         }
         //-------------------------------------------------------------------
         // �᫨ �� �६� ��४�窨 ��� � ���� ��蠫�� ��.��ᯥ����, 
         // ���� ���� ��蠫�� ��ॢ��� � ����. "��筮�"- �몫 ॣ����
         switch ( Check_TO(192, 5*SEC, DIR300___V,'=',ON, 2)){
             case RUN:{ break;; }
             case END:{ Clear_TO(192); break;; }
             case BAD:{ 
                        Bell(1); Message(493); Message(680); Regul_10off(); 
                        REG10R___M=OFF; Clear_TO(192); return; 
                      }
         }
         //-------------------------------------------------------------------
         // �᫨ �� �६� ��४�窨 ��� � ���� ��蠫�� ��.��ᯥ����, 
         // ����稫�� ᨣ��� ������� �஢�� ������ ��蠫�� ��.����� ��� 
         // �몫�稫� ����஫� �⮣� �஢��-��३� �� �������� �몫��. ����
         if(CTRL_LLM2V==OFF){ Message(494); STEP10=10; return; }
         switch ( Check_TO(193, 5*SEC, DIL300___V,'=',OFF, 2)){
             case RUN:{ break;; }
             case END:{ Clear_TO(193); break;; }
             case BAD:{ Message (495); Clear_TO(193); STEP10=10; return; }
         }
         //-------------------------------------------------------------------
         // �᫨ ���� ॣ���� ����஢�� � ��������� AUTO � ����稫�� ������
         // ����窨 ��.����� � �஬������� �������- �ਮ�⠭����� ��४���,
         // ��३� �� 蠣 �������� ������� �������
         if(DIR280___V==OFF){
            switch ( Check_TO(194, 5*SEC, DIS281___V,'=',ON, 1)){
                case RUN:{ break;; }
                case END:{ Clear_TO(194); break;; }
                case BAD:{ Message (496); Clear_TO(194); STEP10=12; return; }
            }
         }
         //-------------------------------------------------------------------

         //-------------------------------------------------------------------
         // ���稪 �������� �몫�祭�� ᨣ���� ������� �஢�� ���� ��蠫��:
         switch ( Check_TO(199, TIME_PALVW*MIN, DIL280___V,'=',OFF, TIME_LSTBV )){
             case RUN:{ TIME_PALVCMin++; TIME_PALVC=TIME_PALVCMin/MIN; break;; }
             // �᫨ �� �������� �६� ᨣ��� ������� �஢�� ���� ��蠫��
             // ��⠫�� �ࠡ�⠭��
             case BAD:{ 
                         Bell(1); Message (294); Clear_TO(199); break;;  
                      }
             // �� �������� �६� ᨣ��� ������� �஢�� ���� ��蠫�� �ய��
             case END:{ 
                         if(CTRL_LLM2V==OFF){
                            TIME_PALVCMin++; TIME_PALVC=TIME_PALNCMin/MIN;
                         } else {
                            Clear_TO(199);
                         }; break;;
                      }
         } 
         //-------------------------------------------------------------------

         //-------------------------------------------------------------------
         // ���稪 �������� ����祭�� ᨣ���� ���� �஢�� ���� ��蠫�� ��.���:
         switch ( Check_TO(198, TIME_PANVW*MIN, DIH280___V,'=',ON, TIME_LSTBV )){
             case RUN:{ TIME_PANVCMin++; TIME_PANVC=TIME_PANVCMin/MIN; return; }
             // �᫨ �� �������� �६� ᨣ��� ���� �஢�� ���� ��蠫�� �����
             // ��⠫�� �ࠡ�⠭��- �몫���� ॣ����
             case BAD:{ 
                         Bell(1); Message(293); Message(680); Clear_TO(241); 
                         REG10R___M=OFF; break;;  
                      }
             // �� �������� �६� ᨣ��� ������� �஢�� ��� ����-��� �ய��
             case END:{ 
                         if(CTRL_HLM2V==OFF){
                            TIME_PANVCMin++; TIME_PANVC=TIME_PANVCMin/MIN;
                         }; break;;
                      }
         };  Clear_TO(198);
         //-------------------------------------------------------------------
         // �᫨ �����稫��� �����⨬�� �६� ��४�窨 ��� �ࠡ�⠫ ���孨�
         // �஢��� ���孥� ��蠫�� ��.�����- ��३� �� 蠣 �몫�祭�� ����
         STEP10 = 11;
         return;
    }
    //------------------------------------------------------------------------



    // ������ �몫�祭�� ���� ��� ��蠫�� ��.����� �� ��४�窨 ��.�����
    //------------------------------------------------------------------------
    if ( STEP10 == 10 ){
         if(STEP10P!=10){
            Clear_TO(191);
            TIME_PNOFC=0;
            TIME_PNOFCMin=0;
         }; STEP10P=10;
         if(RegRUN==OFF){ return; }
         REG10SW__V=100;
         //-------------------------------------------------------------------
         // ���稪 �������� �몫�祭�� ���� ���� ��蠫�� ��.�����:
         switch ( Check_TO(191, TIME_PNOFV*MIN, ZERO,'=',ON, TIME_LSTBV )){
             case RUN:{ TIME_PNOFCMin++; TIME_PNOFC=TIME_PNOFCMin/MIN; return; }
             case BAD:{ Clear_TO(191); break;; }
         } 
         //-------------------------------------------------------------------
         STEP10 = 11;
         return;
    }
    //------------------------------------------------------------------------



    // ���������� ������ ��४�窨 ��.����� �� ������ ��蠫�� ��.�����
    //------------------------------------------------------------------------
    if ( STEP10 == 11 ){
         if(STEP10P!=11){
            ;;
         }; STEP10P=11;
         if(RegRUN==OFF){ return; }
         REG10SW__V=110;
         // �몫���� ���� ������ ��蠫�� ��.�����
         // ����           ��� ����         ����             ���            
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         // �����窠 ��.����� �����祭�- �몫���� ॣ����
         REG10R___M=OFF;
         return;
    }
    //------------------------------------------------------------------------



    // �������� ����砭�� ����㧪� ����� ��.����� �� ��४�窥
    //------------------------------------------------------------------------
    if ( STEP10 == 12 ){
         if(RegRUN==OFF){ return; }
         REG10SW__V=120;
         //-------------------------------------------------------------------
         // �몫���� ���� ������ ��蠫�� ��.�����
         // ����           ��� ����         ����             ���            
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         //-------------------------------------------------------------------
         // ���稪 �������� ������� ������� ����㧪� ����� ��.�����
         switch ( Check_TO(195, 5*SEC, DIS281___V,'=',OFF, 2 )){
             case RUN:{ return; }
             case BAD:{ Clear_TO(195); return; }
         };  Clear_TO(195);
         //-------------------------------------------------------------------
         // �᫨ ������ �������- �������� �� 蠣 ��४�窨 (�����������)
         STEP10=9;
         return;
    }
    //------------------------------------------------------------------------



    // ����� ࠡ��� ॣ����
    //------------------------------------------------------------------------
    if ( STEP10 == 15 ){
         if(STEP10P!=15){
            STEP10X =STEP10P;
         }; STEP10P =15;
         if(RegRUN==OFF){ return; }
         REG10SW__V=150;
         //-------------------------------------------------------------------
         // �몫���� ���� ������ ��蠫�� ��.�����
         // ����           ��� ����         ����             ���            
         DON272___V=OFF;   DON274___V=OFF;   DON301___V=OFF;   DIS275___S=OFF;
         return;
    }
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    // �������������� ��������
    //------------------------------------------------------------------------
    if ( STEP10 ==70 ){
        if(STEP10P!=70){
           ;;
        }; STEP10P =70;
        if(DONCN10>=DONCH10){ STEP10 = STEP10_PRBK; return; }
        REG10SW__V = 700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(210, DONTM10*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(210);
       *DONPR10=(*DONPR10!=ON)?ON:OFF;
        DONCN10++;
        STEP10 = STEP10_PRBK;
        return;
    }
    //------------------------------------------------------------------------

    //------------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_10m();
    return;
}
//----------------------------------------------------------------------------
