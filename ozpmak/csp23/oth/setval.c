//---------------------------------------------------------------------------
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  ???᢮???? ???祭?? ??६?????
vd  far SetVal(vd){

    AITPO__SZV=AITPO__SZM; AITPO__SDV=AITPO__SDM;
    AITPO___FV=AITPO___FM; AITPO___AV=AITPO___AM;
    AITPO__AZV=AITPO__AZM; AITPO__AMV=AITPO__AMM;

    AIFPO__SZV=AIFPO__SZM; AIFPO__SDV=AIFPO__SDM;
    AIFPO___FV=AIFPO___FM; AIFPO___AV=AIFPO___AM;
    AIFPO__AZV=AIFPO__AZM; AIFPO__AMV=AIFPO__AMM;

    //-----------------------------------------------------------------------
    // ?????????? ???祭?? ?????????? ? ᨣ??????樨
    AIF3P__SZV=AIF3P__SZM; AIF3P__SDV=AIF3P__SDM;
    AIF3P___FV=AIF3P___FM; AIF3P___AV=AIF3P___AM;
    AIF3P__AZV=AIF3P__AZM; AIF3P__AMV=AIF3P__AMM;

    AIF4P__SZV=AIF4P__SZM; AIF4P__SDV=AIF4P__SDM;
    AIF4P___FV=AIF4P___FM; AIF4P___AV=AIF4P___AM;
    AIF4P__AZV=AIF4P__AZM; AIF4P__AMV=AIF4P__AMM;

    AIL3C__SZV=AIL3C__SZM; AIL3C__SDV=AIL3C__SDM;
    AIL3C___FV=AIL3C___FM; AIL3C___AV=AIL3C___AM;
    AIL3C__AZV=AIL3C__AZM; AIL3C__AMV=AIL3C__AMM;

    AIL4C__SZV=AIL4C__SZM; AIL4C__SDV=AIL4C__SDM;
    AIL4C___FV=AIL4C___FM; AIL4C___AV=AIL4C___AM;
    AIL4C__AZV=AIL4C__AZM; AIL4C__AMV=AIL4C__AMM;

    AIP3P__SZV=AIP3P__SZM; AIP3P__SDV=AIP3P__SDM;
    AIP3P___FV=AIP3P___FM; AIP3P___AV=AIP3P___AM;
    AIP3P__AZV=AIP3P__AZM; AIP3P__AMV=AIP3P__AMM;

    AIP4P__SZV=AIP4P__SZM; AIP4P__SDV=AIP4P__SDM;
    AIP4P___FV=AIP4P___FM; AIP4P___AV=AIP4P___AM;
    AIP4P__AZV=AIP4P__AZM; AIP4P__AMV=AIP4P__AMM;

    AIP34V_SZV=AIP34V_SZM; AIP34V_SDV=AIP34V_SDM;
    AIP34V__FV=AIP34V__FM; AIP34V__AV=AIP34V__AM;
    AIP34V_AZV=AIP34V_AZM; AIP34V_AMV=AIP34V_AMM;

    AIP34M_SZV=AIP34M_SZM; AIP34M_SDV=AIP34M_SDM;
    AIP34M__FV=AIP34M__FM; AIP34M__AV=AIP34M__AM;
    AIP34M_AZV=AIP34M_AZM; AIP34M_AMV=AIP34M_AMM;

    AIT3TOPSZV=AIT3TOPSZM; AIT3TOPSDV=AIT3TOPSDM;
    AIT3TOP_FV=AIT3TOP_FM; AIT3TOP_AV=AIT3TOP_AM;
    AIT3TOPAZV=AIT3TOPAZM; AIT3TOPAMV=AIT3TOPAMM;

    AIT3BOTSZV=AIT3BOTSZM; AIT3BOTSDV=AIT3BOTSDM;
    AIT3BOT_FV=AIT3BOT_FM; AIT3BOT_AV=AIT3BOT_AM;
    AIT3BOTAZV=AIT3BOTAZM; AIT3BOTAMV=AIT3BOTAMM;

    AIT3P__SZV=AIT3P__SZM; AIT3P__SDV=AIT3P__SDM;
    AIT3P___FV=AIT3P___FM; AIT3P___AV=AIT3P___AM;
    AIT3P__AZV=AIT3P__AZM; AIT3P__AMV=AIT3P__AMM;

    AIS3PI_SZV=AIS3PI_SZM; AIS3PI_SDV=AIS3PI_SDM;
    AIS3PI__FV=AIS3PI__FM; AIS3PI__AV=AIS3PI__AM;
    AIS3PI_AZV=AIS3PI_AZM; AIS3PI_AMV=AIS3PI_AMM;

    AIS3PO_SZV=AIS3PO_SZM; AIS3PO_SDV=AIS3PO_SDM;
    AIS3PO__FV=AIS3PO__FM; AIS3PO__AV=AIS3PO__AM;
    AIS3PO_AZV=AIS3PO_AZM; AIS3PO_AMV=AIS3PO_AMM;

    AIS3CO_SZV=AIS3CO_SZM; AIS3CO_SDV=AIS3CO_SDM;
    AIS3CO__FV=AIS3CO__FM; AIS3CO__AV=AIS3CO__AM;
    AIS3CO_AZV=AIS3CO_AZM; AIS3CO_AMV=AIS3CO_AMM;

    AIS4PI_SZV=AIS4PI_SZM; AIS4PI_SDV=AIS4PI_SDM;
    AIS4PI__FV=AIS4PI__FM; AIS4PI__AV=AIS4PI__AM;
    AIS4PI_AZV=AIS4PI_AZM; AIS4PI_AMV=AIS4PI_AMM;

    AIS4PO_SZV=AIS4PO_SZM; AIS4PO_SDV=AIS4PO_SDM;
    AIS4PO__FV=AIS4PO__FM; AIS4PO__AV=AIS4PO__AM;
    AIS4PO_AZV=AIS4PO_AZM; AIS4PO_AMV=AIS4PO_AMM;

    AIS4CO_SZV=AIS4CO_SZM; AIS4CO_SDV=AIS4CO_SDM;
    AIS4CO__FV=AIS4CO__FM; AIS4CO__AV=AIS4CO__AM;
    AIS4CO_AZV=AIS4CO_AZM; AIS4CO_AMV=AIS4CO_AMM;

    N3AC06_SZV=N3AC06_SZM; N3AC06_SDV=N3AC06_SDM;
    N3AC06__FV=N3AC06__FM; N3AC06__AV=N3AC06__AM;
    N3AC06_AZV=N3AC06_AZM; N3AC06_AMV=N3AC06_AMM;

    N3AC07_SZV=N3AC07_SZM; N3AC07_SDV=N3AC07_SDM;
    N3AC07__FV=N3AC07__FM; N3AC07__AV=N3AC07__AM;
    N3AC07_AZV=N3AC07_AZM; N3AC07_AMV=N3AC07_AMM;

    AIT4TOPSZV=AIT4TOPSZM; AIT4TOPSDV=AIT4TOPSDM;
    AIT4TOP_FV=AIT4TOP_FM; AIT4TOP_AV=AIT4TOP_AM;
    AIT4TOPAZV=AIT4TOPAZM; AIT4TOPAMV=AIT4TOPAMM;

    AIT4BOTSZV=AIT4BOTSZM; AIT4BOTSDV=AIT4BOTSDM;
    AIT4BOT_FV=AIT4BOT_FM; AIT4BOT_AV=AIT4BOT_AM;
    AIT4BOTAZV=AIT4BOTAZM; AIT4BOTAMV=AIT4BOTAMM;

    AIT4P__SZV=AIT4P__SZM; AIT4P__SDV=AIT4P__SDM;
    AIT4P___FV=AIT4P___FM; AIT4P___AV=AIT4P___AM;
    AIT4P__AZV=AIT4P__AZM; AIT4P__AMV=AIT4P__AMM;

    return;
}
//---------------------------------------------------------------------------
