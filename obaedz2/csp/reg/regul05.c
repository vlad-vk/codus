// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 楬���

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

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
//  �ࠢ����� �ᯮ���⥫ﬨ
vd  far Set_IS5(_f far VNT, _f far SHN, _f far PIT, _f far KLP){
    if(VNT!=ASIS) if(VNT==ON) DON043B__V=ON; else DON043B__V=OFF;
    if(SHN!=ASIS) if(SHN==ON) DON044B__V=ON; else DON044B__V=OFF;
    if(PIT!=ASIS) if(PIT==ON) DON045B__V=ON; else DON045B__V=OFF;
    if(KLP!=ASIS) if(KLP==ON) DON046B__V=ON; else DON046B__V=OFF;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_05(vd){
    if(REG05R___V==ON){
        DON043B__M=OFF;
        DON044B__M=OFF;
        DON045B__M=OFF;
        DON046B__M=OFF;
}   }
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_05off(vd){
    Set_IS5(OFF,OFF,OFF,OFF);
    STEP05F=OFF;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� � �몫�祭�� ॣ����
vd  far Regul_05m(vd){
    //-----------------------------------------------------------------------
    if ( STEP05  == 101 ){
         REG05SW__V=1001;
         // �������� �� �몫�祭�� �ᯮ���⥫�� ॣ���஢
         Regul_05off();
         STEP05F   =0;
         // ��� ⠩��஢
         Clear_TO(51);
         Clear_TO(52);
         Clear_TO(53);
         Clear_TO(54);
         Clear_TO(55);
         Clear_TO(56);
         Clear_TO(57);
         Clear_TO(58);
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
    //  �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_CMPKW <  0){ TIME_CMPKW = 5;  }                     // 5 SEC
    if (CTRL_LLBCW <  0){ CTRL_LLBCW = 1;  }                     // 1-��
    if (CTRL_HLBCW <  0){ CTRL_HLBCW = 1;  }                     // 1-��

    // ����祭��-�몫�祭�� ॣ����
    if ( REG05RS__M == SWITCH ){ 
         REG05R___M = (REG05R___M==ON) then_ OFF else_ ON; REG05RS__M=OFF;
    }
    if ( REG05R___M != REG05R___V ){ 
         REG05R___M  =(REG05R___M==ON) then_ ON else_ OFF;
         REG05R___V  = REG05R___M;
         if ( REG05R___V == ON ){ Message(360,NOKV); STEP05 =   0; }
         else                   { Message(361,NOKV); STEP05 = 101; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ��砫�� �஢�ન ��� ����祭��
    if ( STEP05 == 0 ){
       if(STEP05P!=0){
            Clear_TO(51);
       }; STEP05P =0;
       Regul_05off();
       // �᫨ ��� �맮�� ॣ���� ��� ॣ���� �몫�祭 - ���
       if ( RegRUN==OFF || REG05R___V==OFF ){ return; }
       // �᫨ ���� �����窨 楬��� � ०��� ������� - ���
       REG05SW__V = 0;
       if ( DIS049B__V == 1 ){ return; }
       // �᫨ ���� ᨣ��� ���孥�� �஢�� �㭪�� 楬��� - ���
       REG05SW__V = 1;
       if (CTRL_HLBCW==ON){
          switch ( Check_TO (51,TIME_LSTBV*2*SEC, DIS033H__V,'=',OFF,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(51); return; }
          }   
       }
       // �᫨ ���� ����஢�� 楬��� - ���
       REG05SW__V = 3;
       if((STEP06c>0 and STEP06c<6) or (STEP06c==51)){ return; }

       Clear_TO(51);
       STEP05 = 1;
       return;
    }
    //------------------------------------------------------------------------
    if ( STEP05 ==1){
      if(STEP05P!=1){
         Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54); TIME_CMPKC=0;
      }; STEP05P =1;
      if(RegRUN==OFF){ return; }

      // ������� ���⨫��� �ᯨ�樨 楬���
      //      VNT SHN PIT KLP
      Set_IS5(ON ,OFF,OFF,OFF);
      REG05SW__V= 10;
      if(DIS043B__V==OFF){ CNTTO[51]=0; return; }
      if(Check_TO(51,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[51]; return; }

      // ������ ������ �ᯨ�樨 楬���
      Set_IS5(ON ,OFF,OFF,ON );
      REG05SW__V= 11;
      if(DIS046B__V==OFF){ CNTTO[52]=0; return; }
      if(Check_TO(52,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[52]; return; }

      // ������� 譥� �ᯨ�樨 楬���
      Set_IS5(ON ,ON ,OFF,ON );
      REG05SW__V= 12;
      if(DIS044B__V==OFF){ CNTTO[53]=0; return; }
      if(Check_TO(53,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[53]; return; }

      // ������� ���⥫� �ᯨ�樨 楬���
      Set_IS5(ON ,ON ,ON ,ON );
      REG05SW__V= 13;
      switch ( Check_TO  (54, TIME_ISPRV*SEC, DIS045B__V,'=',ON,  1 )){
          case RUN: { return;; }
          case BAD: { Clear_TO(54); return; }
      }

      Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54);
      STEP05 = 2;
      return;
    }
    //------------------------------------------------------------------------
    // �������� ����� ���孥�� �஢�� �㭪�� 楬���
    // �᫨ �� �६� �������� ���孥�� �஢�� ��稭����� ����஢�� 楬��� -
    // �몫���� �ᯮ���⥫� � ����� ����砭�� ����஢�� (???)
    if( STEP05 == 2){
      if(STEP05P!=2){
         Clear_TO(51);
      }; STEP05P =2;
      if(RegRUN==OFF){ return; }
      REG05SW__V =20;
      if (CTRL_HLBCW==ON){
          switch ( Check_TO (51,TIME_LSTBV*2*SEC, DIS033H__V,'=',ON,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(51); return; }
          }   
      }
      Clear_TO(51);
      Clear_TO(55); Clear_TO(56); Clear_TO(57); TIME_CMPKC=0;
      STEP05=3;
      return;
    }
    //------------------------------------------------------------------------
    // �몫�祭�� �ᯮ���⥫�� �ᯨ�樨
    if( STEP05 == 3){
      if(RegRUN==OFF){ return; }

      // �몫���� ���⥫� �ᯨ�樨 楬���
      //      VNT SHN PIT KLP
      Set_IS5(ON ,ON ,OFF,ON );
      REG05SW__V= 31;
      switch ( Check_TO  (51, TIME_ISPRV*SEC, DIS045B__V,'=',OFF,  1 )){ 
          case RUN: { return; }
          case BAD: { Clear_TO(51); return; }
      }
      if(Check_TO(55,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[55]; return; }

      // �몫���� 譥� �ᯨ�樨 楬���
      Set_IS5(ON ,OFF,OFF,ON );
      REG05SW__V= 32;
      switch ( Check_TO  (52, TIME_ISPRV*SEC, DIS044B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(52); return; }
      }
      if(Check_TO(56,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[56]; return; }

      // ������� ������ �ᯨ�樨 楬���
      Set_IS5(ON ,OFF,OFF,OFF);
      REG05SW__V= 33;
      switch ( Check_TO  (53, TIME_ISPRV*SEC, DIS046B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(53); return; }
      }
      if(Check_TO(57,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[57]; return; }

      // �몫���� ���⨫��� �ᯨ�樨 楬���
      Set_IS5(OFF,OFF,OFF,OFF);
      REG05SW__V= 34;
      switch ( Check_TO  (54, TIME_ISPRV*SEC, DIS043B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(54); return; }
      }

      Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54);
      Clear_TO(55); Clear_TO(56); Clear_TO(57);
      if(STEP05P==2) STEP05=4;
      return;
    }
    //------------------------------------------------------------------------
    // �������� ������� �஢�� (���-�� ����஢��) � ᨣ���� � ᪫���
    if(STEP05==4){
      if(STEP05P!=4){
         ;;
      }; STEP05P =4;
      Set_IS5(OFF,OFF,OFF,OFF);
      if(RegRUN==OFF){ return; }
      REG05SW__V=40;
      if(DIS033M__V==0 && DIS033L__V==0) STEP05=0;
      return;
    }
    //------------------------------------------------------------------------
    //  �������� ����砭�� ����஢�� ��宣� ��� �த������� �����窨
    if(STEP05==40){
      if(STEP05P!=40){
         ;;
      }; STEP05P =40;
      REG05SW__V =400;
      return;
    }
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
    if( STEP05 ==70 ){
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
