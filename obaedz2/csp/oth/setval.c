//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

//---------------------------------------------------------------------------
//  ��᢮���� ���祭�� ��६����
vd  far SetVal(vd){

    //-----------------------------------------------------------------------
    // ���������� ���祭�� ���������� AI �������

    AIL003ASZV=AIL003ASZM; AIL003ASDV=AIL003ASDM;
    AIL003A_FV=AIL003A_FM; AIL003A_AV=AIL003A_AM;
    AIL006ASZV=AIL006ASZM; AIL006ASDV=AIL006ASDM;
    AIL006A_FV=AIL006A_FM; AIL006A_AV=AIL006A_AM;
    AIL056ASZV=AIL056ASZM; AIL056ASDV=AIL056ASDM;
    AIL056A_FV=AIL056A_FM; AIL056A_AV=AIL056A_AM;
    AIL057ASZV=AIL057ASZM; AIL057ASDV=AIL057ASDM;
    AIL057A_FV=AIL057A_FM; AIL057A_AV=AIL057A_AM;
    AIL064ASZV=AIL064ASZM; AIL064ASDV=AIL064ASDM;
    AIL064A_FV=AIL064A_FM; AIL064A_AV=AIL064A_AM;
    AIL065ASZV=AIL065ASZM; AIL065ASDV=AIL065ASDM;
    AIL065A_FV=AIL065A_FM; AIL065A_AV=AIL065A_AM;
    M12C06_SZV=M12C06_SZM; M12C06_SDV=M12C06_SDM;
    M12C06__FV=M12C06__FM; M12C06__AV=M12C06__AM;
    M12C07_SZV=M12C07_SZM; M12C07_SDV=M12C07_SDM;
    M12C07__FV=M12C07__FM; M12C07__AV=M12C07__AM;

    //------------

    AIW219_SZV=AIW219_SZM; AIW219_SDV=AIW219_SDM;
    AIW219__FV=AIW219__FM; AIW219__AV=AIW219__AM;
    AIW251_SZV=AIW251_SZM; AIW251_SDV=AIW251_SDM;
    AIW251__FV=AIW251__FM; AIW251__AV=AIW251__AM;
    AIW215_SZV=AIW215_SZM; AIW215_SDV=AIW215_SDM;
    AIW215__FV=AIW215__FM; AIW215__AV=AIW215__AM;
    AIT230_SZV=AIT230_SZM; AIT230_SDV=AIT230_SDM;
    AIT230__FV=AIT230__FM; AIT230__AV=AIT230__AM;
    AIT232_SZV=AIT232_SZM; AIT232_SDV=AIT232_SDM;
    AIT232__FV=AIT232__FM; AIT232__AV=AIT232__AM;
    M26C05_SZV=M26C05_SZM; M26C05_SDV=M26C05_SDM;
    M26C05__FV=M26C05__FM; M26C05__AV=M26C05__AM;
    M26C06_SZV=M26C06_SZM; M26C06_SDV=M26C06_SDM;
    M26C06__FV=M26C06__FM; M26C06__AV=M26C06__AM;
    M26C07_SZV=M26C07_SZM; M26C07_SDV=M26C07_SDM;
    M26C07__FV=M26C07__FM; M26C07__AV=M26C07__AM;

    //------------

    AIT056_SZV=AIT056_SZM; AIT056_SDV=AIT056_SDM;
    AIT056__FV=AIT056__FM; AIT056__AV=AIT056__AM;
    AIT057_SZV=AIT057_SZM; AIT057_SDV=AIT057_SDM;
    AIT057__FV=AIT057__FM; AIT057__AV=AIT057__AM;
    AIT064_SZV=AIT064_SZM; AIT064_SDV=AIT064_SDM;
    AIT064__FV=AIT064__FM; AIT064__AV=AIT064__AM;
    AIT065_SZV=AIT065_SZM; AIT065_SDV=AIT065_SDM;
    AIT065__FV=AIT065__FM; AIT065__AV=AIT065__AM;
    AIT068_SZV=AIT068_SZM; AIT068_SDV=AIT068_SDM;
    AIT068__FV=AIT068__FM; AIT068__AV=AIT068__AM;
    AIT069_SZV=AIT069_SZM; AIT069_SDV=AIT069_SDM;
    AIT069__FV=AIT069__FM; AIT069__AV=AIT069__AM;
    AIT091_SZV=AIT091_SZM; AIT091_SDV=AIT091_SDM;
    AIT091__FV=AIT091__FM; AIT091__AV=AIT091__AM;
    AIT092_SZV=AIT092_SZM; AIT092_SDV=AIT092_SDM;
    AIT092__FV=AIT092__FM; AIT092__AV=AIT092__AM;

    //------------

    AIW218_SZV=AIW218_SZM; AIW218_SDV=AIW218_SDM;
    AIW218__FV=AIW218__FM; AIW218__AV=AIW218__AM;
    AIW252_SZV=AIW252_SZM; AIW252_SDV=AIW252_SDM;
    AIW252__FV=AIW252__FM; AIW252__AV=AIW252__AM;
    AIW216_SZV=AIW216_SZM; AIW216_SDV=AIW216_SDM;
    AIW216__FV=AIW216__FM; AIW216__AV=AIW216__AM;
    AIT231_SZV=AIT231_SZM; AIT231_SDV=AIT231_SDM;
    AIT231__FV=AIT231__FM; AIT231__AV=AIT231__AM;
    AIT233_SZV=AIT233_SZM; AIT233_SDV=AIT233_SDM;
    AIT233__FV=AIT233__FM; AIT233__AV=AIT233__AM;
    AIT202_SZV=AIT202_SZM; AIT202_SDV=AIT202_SDM;
    AIT202__FV=AIT202__FM; AIT202__AV=AIT202__AM;
    M46C06_SZV=M46C06_SZM; M46C06_SDV=M46C06_SDM;
    M46C06__FV=M46C06__FM; M46C06__AV=M46C06__AM;
    M46C07_SZV=M46C07_SZM; M46C07_SDV=M46C07_SDM;
    M46C07__FV=M46C07__FM; M46C07__AV=M46C07__AM;

    //------------
    // ���������� ���祭�� ᨣ������樨 AI �������

    AIL003AAZV=AIL003AAZM; AIL003AAMV=AIL003AAMM;
    AIL006AAZV=AIL006AAZM; AIL006AAMV=AIL006AAMM;
    AIL056AAZV=AIL056AAZM; AIL056AAMV=AIL056AAMM;
    AIL057AAZV=AIL057AAZM; AIL057AAMV=AIL057AAMM;
    AIL064AAZV=AIL064AAZM; AIL064AAMV=AIL064AAMM;
    AIL065AAZV=AIL065AAZM; AIL065AAMV=AIL065AAMM;
    M12C06_AZV=M12C06_AZM; M12C06_AMV=M12C06_AMM;
    M12C07_AZV=M12C07_AZM; M12C07_AMV=M12C07_AMM;

    AIW219_AZV=AIW219_AZM; AIW219_AMV=AIW219_AMM;
    AIW251_AZV=AIW251_AZM; AIW251_AMV=AIW251_AMM;
    AIW215_AZV=AIW215_AZM; AIW215_AMV=AIW215_AMM;
    AIT230_AZV=AIT230_AZM; AIT230_AMV=AIT230_AMM;
    AIT232_AZV=AIT232_AZM; AIT232_AMV=AIT232_AMM;
    M26C05_AZV=M26C05_AZM; M26C05_AMV=M26C05_AMM;
    M26C06_AZV=M26C06_AZM; M26C06_AMV=M26C06_AMM;
    M26C07_AZV=M26C07_AZM; M26C07_AMV=M26C07_AMM;

    AIT056_AZV=AIT056_AZM; AIT056_AMV=AIT056_AMM;
    AIT057_AZV=AIT057_AZM; AIT057_AMV=AIT057_AMM;
    AIT064_AZV=AIT064_AZM; AIT064_AMV=AIT064_AMM;
    AIT065_AZV=AIT065_AZM; AIT065_AMV=AIT065_AMM;
    AIT068_AZV=AIT068_AZM; AIT068_AMV=AIT068_AMM;
    AIT069_AZV=AIT069_AZM; AIT069_AMV=AIT069_AMM;
    AIT091_AZV=AIT091_AZM; AIT091_AMV=AIT091_AMM;
    AIT092_AZV=AIT092_AZM; AIT092_AMV=AIT092_AMM;

    AIW218_AZV=AIW218_AZM; AIW218_AMV=AIW218_AMM;
    AIW252_AZV=AIW252_AZM; AIW252_AMV=AIW252_AMM;
    AIW216_AZV=AIW216_AZM; AIW216_AMV=AIW216_AMM;
    AIT231_AZV=AIT231_AZM; AIT231_AMV=AIT231_AMM;
    AIT233_AZV=AIT233_AZM; AIT233_AMV=AIT233_AMM;
    AIT202_AZV=AIT202_AZM; AIT202_AMV=AIT202_AMM;
    M46C06_AZV=M46C06_AZM; M46C06_AMV=M46C06_AMM;
    M46C07_AZV=M46C07_AZM; M46C07_AMV=M46C07_AMM;

    //------------
    // ��������� AO �������

    AON228ALPV=AON228ALPM; AON228AHPV=AON228AHPM; 
    AON228ALOV=AON228ALOM; AON228AHOV=AON228AHOM;
    AON228CLPV=AON228CLPM; AON228CHPV=AON228CHPM; 
    AON228CLOV=AON228CLOM; AON228CHOV=AON228CHOM;
    AON2511LPV=AON2511LPM; AON2511HPV=AON2511HPM;
    AON2511LOV=AON2511LOM; AON2511HOV=AON2511HOM;
    AON216FLPV=AON216FLPM; AON216FHPV=AON216FHPM; 
    AON216FLOV=AON216FLOM; AON216FHOV=AON216FHOM;

    AON2512LPV=AON2512LPM; AON2512HPV=AON2512HPM; 
    AON2512LOV=AON2512LOM; AON2512HOV=AON2512HOM;
    AON228DLPV=AON228DLPM; AON228DHPV=AON228DHPM; 
    AON228DLOV=AON228DLOM; AON228DHOV=AON228DHOM;
    AON228BLPV=AON228BLPM; AON228BHPV=AON228BHPM; 
    AON228BLOV=AON228BLOM; AON228BHOV=AON228BHOM;
    M47C03_LPV=M47C03_LPM; M47C03_HPV=M47C03_HPM; 
    M47C03_LOV=M47C03_LOM; M47C03_HOV=M47C03_HOM;

    // ��室� AO ������� 
    if(AON228A_OM>100) AON228A_OM=100; AON228A_OV=AON228A_OM; AON228AOOV=AON228A_OV;
    if(AON228C_OM>100) AON228C_OM=100; AON228C_OV=AON228C_OM; AON228COOV=AON228C_OV;
    if(AON2511_OM>100) AON2511_OM=100; AON2511_OV=AON2511_OM; AON2511OOV=AON2511_OV;
    // ����� 3 ��७�ᥭ � ॣ���� ����஢�� �����

    if(AON2512_OM>100) AON2512_OM=100; AON2512_OV=AON2512_OM; AON2512OOV=AON2512_OV;
    if(AON228D_OM>100) AON228D_OM=100; AON228D_OV=AON228D_OM; AON228DOOV=AON228D_OV;
    if(AON228B_OM>100) AON228B_OM=100; AON228B_OV=AON228B_OM; AON228BOOV=AON228B_OV;
    if(M47C03__OM>100) M47C03__OM=100; M47C03__OV=M47C03__OM; M47C03_OOV=M47C03__OV;


    //----------------------------
    // ���������� ⠡���� ����㧮�
    TRCM1B_01V=TRCM1B_01M;
    TRCM1B_02V=TRCM1B_02M;
    TRCM1B_03V=TRCM1B_03M;
    TRCM1B_04V=TRCM1B_04M;
    TRCM1B_05V=TRCM1B_05M; 
    TRCM1B_06V=TRCM1B_06M; 

    TRCEMS_01V=TRCEMS_01M;
    TRCEMS_02V=TRCEMS_02M;
    TRCEMS_03V=TRCEMS_03M;
    TRCEMS_04V=TRCEMS_04M;
    TRCEMS_05V=TRCEMS_05M; 
    TRCEMS_06V=TRCEMS_06M; 

    TRVYGS_01V=TRVYGS_01M;
    TRVYGS_02V=TRVYGS_02M;
    TRVYGS_03V=TRVYGS_03M;
    TRVYGS_04V=TRVYGS_04M;
    TRVYGS_05V=TRVYGS_05M;
    TRVYGS_06V=TRVYGS_06M;

    TROTH__01V=TROTH__01M;
    TROTH__02V=TROTH__02M;
    TROTH__03V=TROTH__03M;
    TROTH__04V=TROTH__04M;
    TROTH__05V=TROTH__05M;
    TROTH__06V=TROTH__06M;

    TRSLM__01V=TRSLM__01M;
    TRSLM__02V=TRSLM__02M;
    TRSLM__03V=TRSLM__03M;
    TRSLM__04V=TRSLM__04M;
    TRSLM__05V=TRSLM__05M;
    TRSLM__06V=TRSLM__06M;

    TRVODD_01V=TRVODD_01M;
    TRVODD_02V=TRVODD_02M;
    TRVODD_03V=TRVODD_03M;
    TRVODD_04V=TRVODD_04M;
    TRVODD_05V=TRVODD_05M;
    TRVODD_06V=TRVODD_06M;

    TRPAS__01V=TRPAS__01M;
    TRPAS__02V=TRPAS__02M;
    TRPAS__03V=TRPAS__03M;
    TRPAS__04V=TRPAS__04M;
    TRPAS__05V=TRPAS__05M;
    TRPAS__06V=TRPAS__06M;


    //------------------------------------------------------------------------
    // ������� �⮡ࠦ���� ���ﭨ� ����㧪� �����஢
    // ���ﭨ� ����㧪� �����஢ ����� ���������� �����஬ ⮫쪮 �᫨
    // ॣ���� ������ �몫�祭

    // ������ ���ண�
    if(DON211A1_M==SWITCH){
       if(REG06cR__V==OFF){
              if(DON211A1_V==0  ){ DON211A1_V=1; }
         else if(DON211A1_V==0.2){ DON211A1_V=1; }
         else if(DON211A1_V==1  ){ DON211A1_V=2; }
         else if(DON211A1_V==2  ){ DON211A1_V=0; }
         else                    { DON211A1_V=0; }
       } else {
          // �᫨ ���஥ ����㦥�� � ���㦥�� � ������ ��宣� ��� 
          // ����� ���࠭
          if(DON211A1_V==1 and 
            (DON211B1_V==1 or DON211C1_V==1)){
             DON211A1_V = (DON211A1_V==1) then_ 2 else_ 1;
          }
       }
    }

    // ������ ��宣�
    if(DON211B1_M==SWITCH){
       if(REG07R___V==OFF){
              if(DON211B1_V==0  ){ DON211B1_V=1; }
         else if(DON211B1_V==0.2){ DON211B1_V=1; }
         else if(DON211B1_V==1  ){ DON211B1_V=2; }
         else if(DON211B1_V==2  ){ DON211B1_V=0; }
         else                    { DON211B1_V=0; }
       }
    }

    // ������ �����
    if(DON211C1_M==SWITCH){
       if(REG09R___V==OFF){
          DON211C1_V++; if(DON211C1_V>2){ DON211C1_V=0; }
       }
    }

    // �������⥫쭠� ����
    if(VDFLAG___M==SWITCH){
       VDFLAG___V++; if(VDFLAG___V>2){ VDFLAG___V=0; }
    }

    DON211A1_M=OFF; DON211B1_M=OFF; DON211C1_M=OFF; VDFLAG___M=OFF;


    //------------------------------------------------------------------------
    // �롮� ࠡ�祣� ���� �������� ��ᯥ����
    if(OBJAS1___M>0){ OBJAS1___V=1; OBJAS2___V=0; }
    if(OBJAS2___M>0){ OBJAS1___V=0; OBJAS2___V=1; }
    if(OBJAS1___V==0&&OBJAS2___V==0){ OBJAS1___V=1; }
    OBJAS1___M=0; OBJAS2___M=0;

    if(REG01R___V==0){
    // �롮� ࠡ�祣� ��
    if(OBJSB1___M>0){ OBJSB1___V=1; OBJSB2___V=0; OBJSB3___V=0; OBJSB4___V=0; }
    if(OBJSB2___M>0){ OBJSB1___V=0; OBJSB2___V=1; OBJSB3___V=0; OBJSB4___V=0; }
    if(OBJSB3___M>0){ OBJSB1___V=0; OBJSB2___V=0; OBJSB3___V=1; OBJSB4___V=0; }
    if(OBJSB4___M>0){ OBJSB1___V=0; OBJSB2___V=0; OBJSB3___V=0; OBJSB4___V=1; }
    if(OBJSB1___V==0&&OBJSB2___V==0&&OBJSB3___V==0&&OBJSB4___V==0){ OBJSB1___V=0; }
    OBJSB1___M=0; OBJSB2___M=0; OBJSB3___M=0; OBJSB4___M=0;

    // �롮� ࠡ�祣� ���� ����㧪� 諠��
    if(OBJS64___M>0){ OBJS64___V=1; OBJS65___V=0; }
    if(OBJS65___M>0){ OBJS64___V=0; OBJS65___V=1; }
    if(OBJS64___V==0&&OBJS65___V==0){ OBJS64___V=1; }
    OBJS64___M=0; OBJS65___M=0;
    // �롮� ࠡ�祣� ���� ����㧪� ���� 諠��
    if(OBJS56___M>0){ OBJS56___V=1; OBJS57___V=0; }
    if(OBJS57___M>0){ OBJS56___V=0; OBJS57___V=1; }
    if(OBJS56___V==0&&OBJS57___V==0){ OBJS56___V=1; }
    OBJS56___M=0; OBJS57___M=0;
    }

//  if(REG07R___V==0){  // ��४����� ⮫쪮 �᫨ ॣ���� �몫�祭
    // �롮� ࠡ�祣� ���� ���㧪� 諠��
    if(OBJM64___M>0){ OBJM64___V=1; OBJM65___V=0; }
    if(OBJM65___M>0){ OBJM64___V=0; OBJM65___V=1; }
    if(OBJM64___V==0&&OBJM65___V==0){ OBJM64___V=1; }
    OBJM64___M=0; OBJM65___M=0;
    // �롮� ࠡ�祣� ���� ���㧪� ���� 諠��
    if(OBJM56___M>0){ OBJM56___V=1; OBJM57___V=0; }
    if(OBJM57___M>0){ OBJM56___V=0; OBJM57___V=1; }
    if(OBJM56___V==0&&OBJM57___V==0){ OBJM56___V=1; }
    OBJM56___M=0; OBJM57___M=0;
//  }

    // �롮� ������������
    if(VIBGG1___M==SWITCH){ VIBGG1___V=(VIBGG1___V==OFF) then_ ON else_ OFF; }; VIBGG1___M=OFF; 
    if(VIBGG2___M==SWITCH){ VIBGG2___V=(VIBGG2___V==OFF) then_ ON else_ OFF; }; VIBGG2___M=OFF; 

    if(OBJS6xH__W<=OBJS6xL__W){ OBJS6xH__W=OBJS6xL__W+ 5; }
    if(OBJS6xL__W>=  95){ OBJS6xH__W=100;  OBJS6xL__W=95; }
    if(OBJS6xH__W<=   0){ OBJS6xH__W=  5;  OBJS6xL__W= 0; }

    // ���� �� ����㧪� � �஬뢪�
    VDPRDSL__V=VDPRDSL__M;
    VDPRVGBM_V=VDPRVGBM_M;
    VDZGVGBM_V=VDZGVGBM_M;
    // VDPRALUM_W VDPRALUM_C
    // VDCOUNT__W VDCOUNT__C

    return;
}
//---------------------------------------------------------------------------
