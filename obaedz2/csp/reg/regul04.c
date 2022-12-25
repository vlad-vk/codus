// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// �����窠 ���饣�

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR04;                 // ⥪�騩 ᨣ��� (��������) ��室� �� �ᯮ��
_i far  DONCN04=0;               // ���稪 横�� ��।�ࣨ�����              
_i far  DONCH04=2;               // �������� ���-�� 横��� ��� ��।�ࣨ����� 
_i far  DONTM04=2;               // ���-�� ᥪ㭤 ��� � ����
_i far  FLGM=0;                  // 䫠� �롮� ������������
_f far  DISGMNV=0;               // ���ﭨ� ������� ������
_f far  DISGMNK=0;               // ���ﭨ� ������� �����
_i far  FLVB4=0;                 // 䫠� ����祭�� ������ �஬ �㭪��

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
//  �ࠢ����� �ᯮ���⥫ﬨ
vd  far Set_IS4(_f far VNT, _f far SHN, _f far PIT, _f far KLP){
    if(VNT!=ASIS) if(VNT==ON) DON043A__V=ON; else DON043A__V=OFF;
    if(SHN!=ASIS) if(SHN==ON) DON044A__V=ON; else DON044A__V=OFF;
    if(PIT!=ASIS) if(PIT==ON) DON045A__V=ON; else DON045A__V=OFF;
    if(KLP!=ASIS) if(KLP==ON) DON046A__V=ON; else DON046A__V=OFF;
    return;
}
//  �ᯮ���⥫� �����������஢ 
vd  far Set_GMN(_f far KVZ, _f far KPD, _f far VIB, _f far NAS, _f far KNS){
    if(DISGG1___V>0 and VIBGG1___V>0){
    if(KVZ!=ASIS) if(KVZ==ON) DON210P__V=ON; else DON210P__V=OFF;
    if(KPD!=ASIS) if(KPD==ON) DON210R__V=ON; else DON210R__V=OFF;
    }
    if(DISGG2___V>0 and VIBGG2___V>0){
    if(KVZ!=ASIS) if(KVZ==ON) DON210S__V=ON; else DON210S__V=OFF;
    if(KPD!=ASIS) if(KPD==ON) DON210T__V=ON; else DON210T__V=OFF;
    }
    if(VIB!=ASIS) if(VIB==ON) DON210W__V=ON; else DON210W__V=OFF;
    if(NAS!=ASIS) if(NAS==ON) DON210N__V=ON; else DON210N__V=OFF;
    if(KNS!=ASIS) if(KNS==ON) DON210O__V=ON; else DON210O__V=OFF;
    return;
}
vd  far Get_GMN(vd){
    FLGM=0;
    if(DISGG1___V>0 and VIBGG1___V>0){
    DISGMNV=DIS210P__V; DISGMNK=DIS210R__V; FLGM=1;
    }
    if(DISGG2___V>0 and VIBGG2___V>0){
    DISGMNV=DIS210S__V; DISGMNK=DIS210T__V; FLGM=2;
    }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  � ०��� [�] �ࠢ���� �ᯮ���⥫ﬨ ������ �����
vd  far ModeKO_04(vd){
    if (REG04R___V==ON){
        DON043A__M=OFF;
        DON044A__M=OFF;
        DON045A__M=OFF;
        DON046A__M=OFF;
        DON210S__M=OFF;
        DON210T__M=OFF;
        DON210W__M=OFF;
        DON210N__M=OFF;
        DON210O__M=OFF;
}   }   
//---------------------------------------------------------------------------
//  �몫�祭�� �ᯮ���⥫�� ॣ����
vd  far Regul_04off(vd){
    Set_IS4(OFF,OFF,OFF,OFF);
    Set_GMN(OFF,OFF,OFF,OFF,OFF);
    return;
}
//---------------------------------------------------------------------------
vd  far Clear_T4all(vd){
    Clear_TO(41); Clear_TO(42); Clear_TO(43); Clear_TO(44);
    Clear_TO(45); Clear_TO(46); Clear_TO(47); Clear_TO(48);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �믮������ ����⢨� �� �몫�祭�� � �몫�祭�� ॣ����
vd  far Regul_04m(vd){
    //-----------------------------------------------------------------------
    if ( STEP04  == 101 ){
         REG04SW__V=1001;
         Clear_T4all();
         if((STEP04P==2) or (STEP04P>=21 and STEP04P<=23)){
            STEP04=23; STEP04_BACK=102; return;
         } 
         STEP04=3;
         STEP04_BACK=102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP04    == 102 ){
         if(STEP04P!=102){ Regul_04off(); Clear_T4all(); }
         STEP04P    = 102;
         REG04SW__V = 1002;
         REG04R___M = OFF;
         STEP04_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP04=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//  ���-�몫 ॣ���� � ࠡ�� � ��⮬���᪮� ०���
vd  far Regul_04(vd){
    //  �६� ���� ����� ����祭�ﬨ �ᯮ���⥫��
    if (TIME_VJPKW <  0){ TIME_VJPKW = 5;  }                     // 5 SEC
    if (CTRL_LLBVW <  0){ CTRL_LLBVW = 1;  }                     // 1-��
    if (CTRL_HLBVW <  0){ CTRL_HLBVW = 1;  }                     // 1-��
    if (TIME_LMBVW <= 0){ TIME_LMBVW = 1800; }                   // 30 MIN
    if (TIME_LMPRW <= 0){ TIME_LMPRW = 10; }                     // 10 SEC
    if (TIME_LMPWW <= 0){ TIME_LMPWW = 30; }                     // 30 SEC
    if (TIME_VPRDW <= 0){ TIME_VPRDW = 40; }                     // 40 SEC
    //  ��।����� ���ﭨ� �ᯮ���⥫�� �����������஢
    Get_GMN();

    // ����祭��-�몫�祭�� ॣ����
    if ( REG04RS__M == SWITCH ){ 
         REG04R___M = (REG04R___M==ON) then_ OFF else_ ON; REG04RS__M=OFF;
    }
    if ( REG04R___M != REG04R___V ){ 
         REG04R___M  =(REG04R___M==ON) then_ ON else_ OFF;
         REG04R___V  = REG04R___M;
         if ( REG04R___V == ON ){ Message(350,NOKV); STEP04 =   0; }
         else                   { Message(351,NOKV); STEP04 = 101; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ��砫�� �஢�ન ��� ����祭��
    if ( STEP04 == 0 ){
       if(STEP04P!=0){
            Clear_TO(41);
       }; STEP04P =0;
       Regul_04off();
       // �᫨ ��� �맮�� ॣ���� ��� ॣ���� �몫�祭 - ���
       if ( RegRUN==OFF || REG04R___V==OFF ){ return; }
       // �᫨ ���� �����窨 ���饣� � ०��� ������� - ���
       REG04SW__V = 0;
       if ( DIS049A__V == 1 ){ return; }
       // �᫨ ���� ᨣ��� ���孥�� �஢�� �㭪�� ���饣� - ���
       REG04SW__V = 1;
       if (CTRL_HLBVW==ON){
          switch ( Check_TO (41,TIME_LSTBV*2*SEC, DIS031H__V,'=',OFF,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(41); return; }
          }   
       }
       // �᫨ ���� ����஢�� ���饣�- ���
       REG04SW__V = 3;
       if((STEP06c>7 and STEP06c<15) or (STEP06c==51)){ return; }

       Clear_TO(41);
       STEP04 = 1;
       return;
    }
    //------------------------------------------------------------------------
    if ( STEP04 ==1){
      if(STEP04P!=1){
         Clear_TO(41); Clear_TO(42); Clear_TO(43); Clear_TO(44); TIME_VJPKC=0;
      }; STEP04P =1;
      if(RegRUN==OFF){ return; }

      // ������� ���⨫��� �ᯨ�樨 ���饣�
      //      VNT SHN PIT KLP
      Set_IS4(ON ,OFF,OFF,OFF);
      REG04SW__V= 10;
      if(DIS043A__V==OFF){ CNTTO[41]=0; return; }
      if(Check_TO(41,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[41]; return; }

      // ������ ������ �ᯨ�樨 ���饣�
      Set_IS4(ON ,OFF,OFF,ON );
      REG04SW__V= 11;
      if(DIS046A__V==OFF){ CNTTO[42]=0; return; }
      if(Check_TO(42,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[42]; return; }

      // ������� 譥� �ᯨ�樨 ���饣�
      Set_IS4(ON ,ON ,OFF,ON );
      REG04SW__V= 12;
      if(DIS044A__V==OFF){ CNTTO[43]=0; return; }
      if(Check_TO(43,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[43]; return; }

      // ������� ���⥫� �ᯨ�樨 ���饣�
      Set_IS4(ON ,ON ,ON ,ON );
      REG04SW__V= 13;
      switch ( Check_TO  (44, TIME_ISPRV*SEC, DIS045A__V,'=',ON,  1 )){
          case RUN: { return;; }
          case BAD: { Clear_TO(44); return; }
      }

      Clear_TO(41); Clear_TO(42); Clear_TO(43); Clear_TO(44);
      if(FLGM>0) STEP04 = 21;

      REG04SW__V= 14;
      return;
    }
    //------------------------------------------------------------------------
    // �������� ����� ���孥�� �஢�� �㭪�� ���饣�
    // �᫨ �� �६� �������� ���孥�� �஢�� ��稭����� ����஢�� ���饣�-
    // �몫���� �ᯮ���⥫� � ����� ����砭�� ����஢�� (???)
    if( STEP04 == 2){
      if(STEP04P!=2){
         Clear_TO(41);
      }; STEP04P =2;
      if(RegRUN==OFF){ return; }
      REG04SW__V =20;
      if (CTRL_HLBVW==ON){
          switch ( Check_TO (41,TIME_LSTBV*2*SEC, DIS031H__V,'=',ON,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(41); return; }
          }   
      }
      Clear_TO(41);
      Clear_TO(45); Clear_TO(46); Clear_TO(47); TIME_VJPKC=0;
      STEP04=3;
      return;
    }
    //------------------------------------------------------------------------
    // �몫�祭�� �ᯮ���⥫�� �ᯨ�樨
    if( STEP04 == 3){
      Set_GMN(OFF,OFF,OFF,OFF,OFF);
      if(RegRUN==OFF){ return; }

      // �몫���� ���⥫� �ᯨ�樨 ���饣�
      //      VNT SHN PIT KLP
      Set_IS4(ON ,ON ,OFF,ON );
      REG04SW__V= 31;
      switch ( Check_TO  (41, TIME_ISPRV*SEC, DIS045A__V,'=',OFF,  1 )){ 
          case RUN: { return; }
          case BAD: { Clear_TO(41); return; }
      }
      if(Check_TO(45,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[45]; return; }

      // �몫���� 譥� �ᯨ�樨 ���饣�
      Set_IS4(ON ,OFF,OFF,ON );
      REG04SW__V= 32;
      switch ( Check_TO  (42, TIME_ISPRV*SEC, DIS044A__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(42); return; }
      }
      if(Check_TO(46,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[46]; return; }

      // ������� ������ �ᯨ�樨 ���饣�
      Set_IS4(ON ,OFF,OFF,OFF);
      REG04SW__V= 33;
      switch ( Check_TO  (43, TIME_ISPRV*SEC, DIS046A__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(43); return; }
      }
      if(Check_TO(47,TIME_VJPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_VJPKC=CNTTO[47]; return; }

      // �몫���� ���⨫��� �ᯨ�樨 ���饣�
      Set_IS4(OFF,OFF,OFF,OFF);
      REG04SW__V= 34;
      switch ( Check_TO  (44, TIME_ISPRV*SEC, DIS043A__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(44); return; }
      }

      Clear_T4all();
      if(STEP04P==2) STEP04=4;
      if(STEP04_BACK==102) STEP04=102;
      return;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // ����祭�� ����㧪�  � �����������஢
    //------------------------------------------------------------------------
    // ����⨥ �ᯮ���⥫�� �����������஢
    if(STEP04==21){
      if(STEP04P!=21){
         Clear_T4all(); TMO210NB_C=0; TMO210XB_C=0;
      }; STEP04P =21;
      Set_IS4(ON ,ON ,ON ,ON );
      if(RegRUN==OFF){ return; }
  
      // ������� ������ ����� ������ (DON210O) � ���� �࠭ᯮ�� 
      //      KVZ,KPD,VIB,NAS,KNS
      Set_GMN(OFF,OFF,OFF,OFF,ON );
      REG04SW__V= 211;
//    switch ( Check_TO(41,TIME_ISPRV*SEC,DIS210O__V,'=',ON,1)){
//        case RUN: { return; }
//        case BAD: { Clear_TO(41); return; }
//    };  if ( Check_TO(45,TIME_ISPRV*SEC,ZERO,'=',ON,1)==RUN) return;

      // ������� ������ ����� ������ �� ����� (DON210P,DON210S)
      //      KVZ,KPD,VIB,NAS,KNS
      Set_GMN(ON ,OFF,OFF,OFF,ON );
      REG04SW__V= 212;
//    switch ( Check_TO(42,TIME_ISPRV*SEC,DISGMNV,'=',ON,1)){
//        case RUN: { return; }
//        case BAD: { Clear_TO(42); return; }
//    };  if ( Check_TO(46,TIME_ISPRV*SEC,ZERO,'=',ON,1)==RUN) return;

      // ������� ������ ����� ������ � ��㡮�஢�� ������� (DON210R,DON210T)
      //      KVZ,KPD,VIB,NAS,KNS
      Set_GMN(ON ,ON ,OFF,OFF,ON );
      REG04SW__V= 213;
//    switch ( Check_TO(43,TIME_ISPRV*SEC,DISGMNK,'=',ON,1)){
//        case RUN: { return; }
//        case BAD: { Clear_TO(43); return; }
//    };  if ( Check_TO(47,12*SEC,ZERO,'=',ON,1)==RUN) return;

      // ����প� ��। ����祭��� ����
      REG04SW__V= 214;
//    TMO210NB_C++; if(TMO210NB_C<TMO210NB_W) return;

      // ������� ���� �࠭ᯮ�� ����� (DON210N)
      //      KVZ,KPD,VIB,NAS,KNS
      Set_GMN(ON ,ON ,OFF,ON ,ON );
      REG04SW__V= 215;
//    switch ( Check_TO  (44, TIME_ISPRV*SEC, DIS210N__V,'=',ON,1)){
//        case RUN: { return; }
//        case BAD: { Clear_TO(44); return; }
//    }

      // ����প� ��। ����⨥� ������� �����
      REG04SW__V= 216;
//    TMO210XB_C++; if(TMO210XB_C<TMO210XB_W) return;

      // ������ ������ ����� ����� �� ����
      DON210X__V=1;

      Clear_T4all(); TMO210NB_C=0; TMO210XB_C=0;
      STEP04=22;
      return;
    }
    //------------------------------------------------------------------------
    // �஢�ઠ �஢���
    if (STEP04==22){
        if(STEP04P!=22){
        Clear_TO(41); Clear_TO(42); Clear_TO(43); Clear_TO(44); 
        TIME_LMBVC=0; TIME_LMPRC=0; TIME_LMPWC=0; FLVB4=0; DON210W__V=OFF;
        }; STEP04P =22;
        Set_IS4(ON ,ON ,ON  ,ON );
        Set_GMN(ON ,ON ,ASIS,ON ,ON ); DON210X__V=1;
        if(RegRUN==OFF){ return; }

        REG04SW__V= 220;
        // �᫨ ��� �।���� � ���孥�� �஢�� ����� (DIS031M)
        if(DIS031M__V==OFF and DIS031H__V==OFF){
           // �᫨ �� �������� �६� (TIME_LMBVW) ��� �।���� �஢�� - 
           // ��⠭����� 䫠� ����祭�� (FLVB4) ������ (DIS210W) 
           switch (Check_TO(41,TIME_LMBVW*SEC,ZERO,'=',ON,1)){
               case RUN: { TIME_LMBVC++; }
               case BAD: { TIME_LMBVC=0; Clear_TO(41); if(FLVB4<1) FLVB4=1; }
           }
        }           

        // �᫨ ��⠭����� 䫠� ����祭�� ������, �������-�몫���� ������ (DON210W)
        // � �������� �த����⥫쭮���� (TIME_LMPRW) � ��㧮� (TIME_LMPWW)
        if(FLVB4==1){
           DON210W__V=ON;; 
           TIME_LMPRC++; if(TIME_LMPRC>=TIME_LMPRW){ FLVB4=2; TIME_LMPWC=0; TIME_LMPRC=0; }
        }
        if(FLVB4==2){
           DON210W__V=OFF;
           TIME_LMPWC++; if(TIME_LMPWC>=TIME_LMPWW){ FLVB4=0; TIME_LMPWC=0; TIME_LMPRC=0; }
        }

        // �᫨ �ࠡ�⠫ ���孨� �஢��� � �㭪�� �����窨 (DIS210U), 
        // ���. ��㪮��� ᨣ���, ������
        if(DIS210U__V==ON){ FLVB4=1; Message(230,KVIT); }

        // �᫨ �ࠡ�⠫ ���孨� �஢��� � �㭪��, �㤠 ��㧨� ���騥 (DIS031H)
        switch ( Check_TO  (43, TIME_LSTBV*2*SEC, DIS031H__V,'=',ON, 2)){
            case RUN: { return; }
            case BAD: { Clear_TO(43); return; }
        }
        
        Clear_TO(41); Clear_TO(42); Clear_TO(43); Clear_TO(44); 
        TIME_LMBVC=0; TIME_LMPRC=0; TIME_LMPWC=0; FLVB4=0; DON210W__V=OFF;
        STEP04=23;
        return;
    }
    //------------------------------------------------------------------------
    //  �����⨥ �ᯮ���⥫�� �����������஢
    if (STEP04==23){
        if(STEP04P!=23){
           Clear_T4all(); TMO210XE_C=0; TMO210NE_C=0;
        }; STEP04P =23;
        // �ᯨ��� ����祭�
        Set_IS4(ON ,ON ,ON ,ON );
        // ������ �몫�祭, ���� ����祭
        DON210W__V=OFF; DON210O__V=ON;
        if(RegRUN==OFF){ return; }

        // ������� ������ ����� ����� � ��㡮�஢�� (DON210R,DON210T)
        REG04SW__V=231;
        DON210R__V=OFF; DON210T__V=OFF;
//      switch ( Check_TO(41,TIME_ISPRV*SEC,DISGMNK,'=',OFF,1)){
//          case RUN: { return; }
//          case BAD: { Clear_TO(41); return; }
//      };  if ( Check_TO(45,TIME_ISPRV*SEC,ZERO,'=',ON,1)==RUN) return;

        // ������� ������ �� ����嫥��� � ����� (DON210P,DON210S)
        REG04SW__V=232;
        DON210P__V=OFF; DON210S__V=OFF;
//      switch ( Check_TO(42,TIME_ISPRV*SEC,DISGMNV,'=',OFF,1)){
//          case RUN: { return; }
//          case BAD: { Clear_TO(42); return; }
//      };  if ( Check_TO(46,TIME_ISPRV*SEC,ZERO,'=',ON,1)==RUN) return;

        // ������� ������ ����� ����� � ����
        DON210X__V=0;

        // ����প� ��। �몫�祭��� ����
//      TMO210XE_C++; if(TMO210XE_C<TMO210XE_W) return;

        // �몫���� ���� (DIS210N)
        REG04SW__V=233;
        DON210N__V=OFF;
//      switch ( Check_TO(43,TIME_ISPRV*SEC,DIS210N__V,'=',OFF,1)){
//          case RUN: { return; }
//          case BAD: { Clear_TO(43); return; }
//      };  if ( Check_TO(47,TIME_ISPRV*SEC,ZERO,'=',ON,1)==RUN) return;

        // ����প� ��᫥ �몫�祭�� ����
        // !!! ��饥 �६� �த㢪� = TMO210NE_W +  TIME_VPRDW !!!
//      TMO210NE_C++; if(TMO210NE_C<TMO210NE_W) return;

        Clear_T4all(); TMO210XE_C=0; TMO210NE_C=0;
        STEP04=24;
        return;
    }
    //------------------------------------------------------------------------
    //  �த㢪� ����� �࠭ᯮ�� �����窨 �����
    if (STEP04==24){
        if(STEP04P!=24){
           Clear_TO(41);
        }; STEP04P =24;
        // �ᯨ��� ����祭�
        Set_IS4(ON ,ON ,ON ,ON );
        // ���� �몫�祭, ������ ����� ������
        DON210N__V=OFF; DON210X__V=0;
        if(RegRUN==OFF){ return; }
        // ��㧠 ��। �����⨥� ������� ������
        REG04SW__V=240;
        if(Check_TO(41,TIME_VPRDW*SEC,ZERO,'=',ON,1)==RUN){ return; }
        Clear_TO(41);
        // ������� ������ ������ � ����
        DON210O__V=OFF;
        STEP04=2;
        if(STEP04_BACK==102) STEP04=3;
        return;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // �������� ������� �஢�� (���-�� ����஢��) � ᨣ���� � ᪫���
    if(STEP04==4){
      if(STEP04P!=4){
         ;;
      }; STEP04P =4;
      Set_IS4(OFF,OFF,OFF,OFF);
      Set_GMN(OFF,OFF,OFF,OFF,OFF);
      if(RegRUN==OFF){ return; }
      REG04SW__V=40;
      if(DIS031M__V==0 && DIS031L__V==0) STEP04=0;
      return;
    }
    //------------------------------------------------------------------------
    //  �������� ����砭�� ����஢�� ��宣� ��� �த������� �����窨
    if(STEP04==40){
      if(STEP04P!=40){
         ;;
      }; STEP04P =40;
      REG04SW__V =400;
      return;
    }
    //------------------------------------------------------------------------
    //  �������� ������� �������� ����஢�� ���饣� ��� �த�������
    //  �����祪
    if ( STEP04== 50){
      if(STEP04P!=50){
         ;;
      }; STEP04P =50;
      REG04SW__V =500;
      return;
    }
    //------------------------------------------------------------------------
    

    //------------------------------------------------------------------------
    // �������������� ��������
    //------------------------------------------------------------------------
    if( STEP04 ==70 ){
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
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // �᫨ ����� ���������騩 蠣 ॣ���� - ॣ���� � ��筮� ०��
    Regul_04m();
    return;
}
//---------------------------------------------------------------------------
