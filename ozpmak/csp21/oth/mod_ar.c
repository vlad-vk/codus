//---------------------------------------------------------------------------
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  Modify  after ready
//  Корректировки после чтения сигналов и после DebVal
vd  far Mod_AR(vd){

    //  N11
    //------------------------------------------------------------------------
    S1ZIOP___V = 3;                                        // оба сигнала
    if(I1ZIOPC__V== ON&& I1ZIOPO__V==OFF) S1ZIOP___V=0;    // закрыта
    if(I1ZIOPC__V==OFF&& I1ZIOPO__V==OFF) S1ZIOP___V=1;    // неопределенное
    if(I1ZIOPC__V==OFF&& I1ZIOPO__V== ON) S1ZIOP___V=2;    // открыта
    if(I1ZIOPC__E> OFF|| I1ZIOPO__E> OFF) S1ZIOP___V=3;    // время сработки

    S1ZIPP___V = 3;                                    
    if(I1ZIPPC__V== ON&& I1ZIPPO__V==OFF) S1ZIPP___V=0;
    if(I1ZIPPC__V==OFF&& I1ZIPPO__V==OFF) S1ZIPP___V=1;
    if(I1ZIPPC__V==OFF&& I1ZIPPO__V== ON) S1ZIPP___V=2;
    if(I1ZIPPC__E> OFF|| I1ZIPPO__E> OFF) S1ZIPP___V=3;

    S1KIP____V = 3;                                    
    if(I1KIPC___V== ON&& I1KIPO___V==OFF) S1KIP____V=0;
    if(I1KIPC___V==OFF&& I1KIPO___V==OFF) S1KIP____V=1;
    if(I1KIPC___V==OFF&& I1KIPO___V== ON) S1KIP____V=2;
    if(I1KIPC___E> OFF|| I1KIPO___E> OFF) S1KIP____V=3;

    S1ZOPP___V = 3;                                    
    if(I1ZOPPC__V== ON&& I1ZOPPO__V==OFF) S1ZOPP___V=0;
    if(I1ZOPPC__V==OFF&& I1ZOPPO__V==OFF) S1ZOPP___V=1;
    if(I1ZOPPC__V==OFF&& I1ZOPPO__V== ON) S1ZOPP___V=2;
    if(I1ZOPPC__E> OFF|| I1ZOPPO__E> OFF) S1ZOPP___V=3;

    S1ZOPA___V = 3;                                    
    if(I1ZOPAC__V== ON&& I1ZOPAO__V==OFF) S1ZOPA___V=0;
    if(I1ZOPAC__V==OFF&& I1ZOPAO__V==OFF) S1ZOPA___V=1;
    if(I1ZOPAC__V==OFF&& I1ZOPAO__V== ON) S1ZOPA___V=2;
    if(I1ZOPAC__E> OFF|| I1ZOPAO__E> OFF) S1ZOPA___V=3;

    S1KOP____V = 3;                                    
    if(I1KOPC___V== ON&& I1KOPO___V==OFF) S1KOP____V=0;
    if(I1KOPC___V==OFF&& I1KOPO___V==OFF) S1KOP____V=1;
    if(I1KOPC___V==OFF&& I1KOPO___V== ON) S1KOP____V=2;
    if(I1KOPC___E> OFF|| I1KOPO___E> OFF) S1KOP____V=3;

    S1MDU____V = 3;                                    
    if(I1MU_____V== ON&& I1DU_____V==OFF) S1MDU____V=0;
    if(I1MU_____V==OFF&& I1DU_____V==OFF) S1MDU____V=1;
    if(I1MU_____V==OFF&& I1DU_____V== ON) S1MDU____V=2;


    //  N12
    //------------------------------------------------------------------------
    S1VZ_____V = 3;                                        // оба сигнала
    if(I1VZC____V== ON&& I1VZO____V==OFF) S1VZ_____V=0;    // закрыта
    if(I1VZC____V==OFF&& I1VZO____V==OFF) S1VZ_____V=1;    // неопределенное
    if(I1VZC____V==OFF&& I1VZO____V== ON) S1VZ_____V=2;    // открыта
    if(I1VZC____E> OFF|| I1VZO____E> OFF) S1VZ_____V=3;    // контроль времени
    if(I1VZOE___V> OFF|| I1VZCE___V> OFF) S1VZ_____V=3;    // контроль муфты

//S1VN_____V

    //  N15
    //------------------------------------------------------------------------

//S1GNS____V

    S1LUCMD__V = 3;                                    
    if(I1LUCMU__V== ON&& I1LUCDU__V==OFF) S1LUCMD__V=0;
    if(I1LUCMU__V==OFF&& I1LUCDU__V==OFF) S1LUCMD__V=1;
    if(I1LUCMU__V==OFF&& I1LUCDU__V== ON) S1LUCMD__V=2;

    S1KOC____V = 3;                                    
    if(I1KOCC___V== ON&& I1KOCO___V==OFF) S1KOC____V=0;
    if(I1KOCC___V==OFF&& I1KOCO___V==OFF) S1KOC____V=1;
    if(I1KOCC___V==OFF&& I1KOCO___V== ON) S1KOC____V=2;
    if(I1KOCC___E> OFF|| I1KOCO___E> OFF) S1KOC____V=3;

    //  N17
    //------------------------------------------------------------------------

    S1HM1____V = 3;                                        
    if(I1HM1DN__V== ON&& I1HM1UP__V==OFF) S1HM1____V=0;    
    if(I1HM1DN__V==OFF&& I1HM1UP__V==OFF) S1HM1____V=1;    
    if(I1HM1DN__V==OFF&& I1HM1UP__V== ON) S1HM1____V=2;    
    if(I1HM1DN__E> OFF|| I1HM1UP__E> OFF) S1HM1____V=3;

    S1KR1____V = 3;                                    
    if(I1KR1C___V== ON&& I1KR1O___V==OFF) S1KR1____V=0;
    if(I1KR1C___V==OFF&& I1KR1O___V==OFF) S1KR1____V=1;
    if(I1KR1C___V==OFF&& I1KR1O___V== ON) S1KR1____V=2;
    if(I1KR1C___E> OFF|| I1KR1O___E> OFF) S1KR1____V=3;

    S1BY1____V = 3;                                    
    if(I1BY1C___V== ON&& I1BY1O___V==OFF) S1BY1____V=0;
    if(I1BY1C___V==OFF&& I1BY1O___V==OFF) S1BY1____V=1;
    if(I1BY1C___V==OFF&& I1BY1O___V== ON) S1BY1____V=2;
    if(I1BY1C___E> OFF|| I1BY1O___E> OFF) S1BY1____V=3;

    S1P1_____V = 3;                                    
    if(I1P1_N___V== ON&& I1P1_Y___V==OFF) S1P1_____V=0;
    if(I1P1_N___V==OFF&& I1P1_Y___V==OFF) S1P1_____V=1;
    if(I1P1_N___V==OFF&& I1P1_Y___V== ON) S1P1_____V=2;

    S1SBP1___V = 3;                                    
    if(I1SBP1Z__V== ON&& I1SBP1R__V==OFF) S1SBP1___V=0;
    if(I1SBP1Z__V==OFF&& I1SBP1R__V==OFF) S1SBP1___V=1;
    if(I1SBP1Z__V==OFF&& I1SBP1R__V== ON) S1SBP1___V=2;

    //  N18
    //------------------------------------------------------------------------

    S1HM2____V = 3;                                    
    if(I1HM2DN__V== ON&& I1HM2UP__V==OFF) S1HM2____V=0;
    if(I1HM2DN__V==OFF&& I1HM2UP__V==OFF) S1HM2____V=1;
    if(I1HM2DN__V==OFF&& I1HM2UP__V== ON) S1HM2____V=2;
    if(I1HM2DN__E> OFF|| I1HM2UP__E> OFF) S1HM2____V=3;

    S1KR2____V = 3;                                    
    if(I1KR2C___V== ON&& I1KR2O___V==OFF) S1KR2____V=0;
    if(I1KR2C___V==OFF&& I1KR2O___V==OFF) S1KR2____V=1;
    if(I1KR2C___V==OFF&& I1KR2O___V== ON) S1KR2____V=2;
    if(I1KR2C___E> OFF|| I1KR2O___E> OFF) S1KR2____V=3;

    S1BY2____V = 3;                                    
    if(I1BY2C___V== ON&& I1BY2O___V==OFF) S1BY2____V=0;
    if(I1BY2C___V==OFF&& I1BY2O___V==OFF) S1BY2____V=1;
    if(I1BY2C___V==OFF&& I1BY2O___V== ON) S1BY2____V=2;
    if(I1BY2C___E> OFF|| I1BY2O___E> OFF) S1BY2____V=3;

    S1P2_____V = 3;                                    
    if(I1P2_N___V== ON&& I1P2_Y___V==OFF) S1P2_____V=0;
    if(I1P2_N___V==OFF&& I1P2_Y___V==OFF) S1P2_____V=1;
    if(I1P2_N___V==OFF&& I1P2_Y___V== ON) S1P2_____V=2;

    S1SBP2___V = 3;                                    
    if(I1SBP2Z__V== ON&& I1SBP2R__V==OFF) S1SBP2___V=0;
    if(I1SBP2Z__V==OFF&& I1SBP2R__V==OFF) S1SBP2___V=1;
    if(I1SBP2Z__V==OFF&& I1SBP2R__V== ON) S1SBP2___V=2;

    //------------------------------------------------------------------------




    //  N21
    //------------------------------------------------------------------------

    S2ZIOP___V = 3;                                    
    if(I2ZIOPC__V== ON&& I2ZIOPO__V==OFF) S2ZIOP___V=0;
    if(I2ZIOPC__V==OFF&& I2ZIOPO__V==OFF) S2ZIOP___V=1;
    if(I2ZIOPC__V==OFF&& I2ZIOPO__V== ON) S2ZIOP___V=2;
    if(I2ZIOPC__E> OFF|| I2ZIOPO__E> OFF) S2ZIOP___V=3;

    S2ZIPP___V = 3;                                    
    if(I2ZIPPC__V== ON&& I2ZIPPO__V==OFF) S2ZIPP___V=0;
    if(I2ZIPPC__V==OFF&& I2ZIPPO__V==OFF) S2ZIPP___V=1;
    if(I2ZIPPC__V==OFF&& I2ZIPPO__V== ON) S2ZIPP___V=2;
    if(I2ZIPPC__E> OFF|| I2ZIPPO__E> OFF) S2ZIPP___V=3;

    S2KIP____V = 3;                                    
    if(I2KIPC___V== ON&& I2KIPO___V==OFF) S2KIP____V=0;
    if(I2KIPC___V==OFF&& I2KIPO___V==OFF) S2KIP____V=1;
    if(I2KIPC___V==OFF&& I2KIPO___V== ON) S2KIP____V=2;
    if(I2KIPC___E> OFF|| I2KIPO___E> OFF) S2KIP____V=3;

    S2ZOPP___V = 3;                                    
    if(I2ZOPPC__V== ON&& I2ZOPPO__V==OFF) S2ZOPP___V=0;
    if(I2ZOPPC__V==OFF&& I2ZOPPO__V==OFF) S2ZOPP___V=1;
    if(I2ZOPPC__V==OFF&& I2ZOPPO__V== ON) S2ZOPP___V=2;
    if(I2ZOPPC__E> OFF|| I2ZOPPO__E> OFF) S2ZOPP___V=3;

    S2ZOPA___V = 3;                                    
    if(I2ZOPAC__V== ON&& I2ZOPAO__V==OFF) S2ZOPA___V=0;
    if(I2ZOPAC__V==OFF&& I2ZOPAO__V==OFF) S2ZOPA___V=1;
    if(I2ZOPAC__V==OFF&& I2ZOPAO__V== ON) S2ZOPA___V=2;
    if(I2ZOPAC__E> OFF|| I2ZOPAO__E> OFF) S2ZOPA___V=3;

    S2KOP____V = 3;                                    
    if(I2KOPC___V== ON&& I2KOPO___V==OFF) S2KOP____V=0;
    if(I2KOPC___V==OFF&& I2KOPO___V==OFF) S2KOP____V=1;
    if(I2KOPC___V==OFF&& I2KOPO___V== ON) S2KOP____V=2;
    if(I2KOPC___E> OFF|| I2KOPO___E> OFF) S2KOP____V=3;

    S2MDU____V = 3;                                    
    if(I2MU_____V== ON&& I2DU_____V==OFF) S2MDU____V=0;
    if(I2MU_____V==OFF&& I2DU_____V==OFF) S2MDU____V=1;
    if(I2MU_____V==OFF&& I2DU_____V== ON) S2MDU____V=2;

    //  N22
    //------------------------------------------------------------------------

    S2VZ_____V = 3;                                        // оба сигнала
    if(I2VZC____V== ON&& I2VZO____V==OFF) S2VZ_____V=0;    // закрыта
    if(I2VZC____V==OFF&& I2VZO____V==OFF) S2VZ_____V=1;    // неопределенное
    if(I2VZC____V==OFF&& I2VZO____V== ON) S2VZ_____V=2;    // открыта
    if(I2VZC____E> OFF|| I2VZO____E> OFF) S2VZ_____V=3;    // контроль времени
    if(I2VZOE___V> OFF|| I2VZCE___V> OFF) S2VZ_____V=3;    // контроль муфты

//S2VN_____V


    //  N25
    //------------------------------------------------------------------------

//S2GNS____V

    S2LUCMD__V = 3;                                    
    if(I2LUCMU__V== ON&& I2LUCDU__V==OFF) S2LUCMD__V=0;
    if(I2LUCMU__V==OFF&& I2LUCDU__V==OFF) S2LUCMD__V=1;
    if(I2LUCMU__V==OFF&& I2LUCDU__V== ON) S2LUCMD__V=2;

    S2KOC____V = 3;                                    
    if(I2KOCC___V== ON&& I2KOCO___V==OFF) S2KOC____V=0;
    if(I2KOCC___V==OFF&& I2KOCO___V==OFF) S2KOC____V=1;
    if(I2KOCC___V==OFF&& I2KOCO___V== ON) S2KOC____V=2;
    if(I2KOCC___E> OFF|| I2KOCO___E> OFF) S2KOC____V=3;

    //  N27
    //------------------------------------------------------------------------

    S2HM1____V = 3;                                        // оба сигнала
    if(I2HM1DN__V== ON&& I2HM1UP__V==OFF) S2HM1____V=0;    // закрыта
    if(I2HM1DN__V==OFF&& I2HM1UP__V==OFF) S2HM1____V=1;    // неопределенное
    if(I2HM1DN__V==OFF&& I2HM1UP__V== ON) S2HM1____V=2;    // открыта
    if(I2HM1DN__E> OFF|| I2HM1UP__E> OFF) S2HM1____V=3;

    S2KR1____V = 3;                                    
    if(I2KR1C___V== ON&& I2KR1O___V==OFF) S2KR1____V=0;
    if(I2KR1C___V==OFF&& I2KR1O___V==OFF) S2KR1____V=1;
    if(I2KR1C___V==OFF&& I2KR1O___V== ON) S2KR1____V=2;
    if(I2KR1C___E> OFF|| I2KR1O___E> OFF) S2KR1____V=3;

    S2BY1____V = 3;                                    
    if(I2BY1C___V== ON&& I2BY1O___V==OFF) S2BY1____V=0;
    if(I2BY1C___V==OFF&& I2BY1O___V==OFF) S2BY1____V=1;
    if(I2BY1C___V==OFF&& I2BY1O___V== ON) S2BY1____V=2;
    if(I2BY1C___E> OFF|| I2BY1O___E> OFF) S2BY1____V=3;

    S2P1_____V = 3;                                    
    if(I2P1_N___V== ON&& I2P1_Y___V==OFF) S2P1_____V=0;
    if(I2P1_N___V==OFF&& I2P1_Y___V==OFF) S2P1_____V=1;
    if(I2P1_N___V==OFF&& I2P1_Y___V== ON) S2P1_____V=2;

    S2SBP1___V = 3;                                    
    if(I2SBP1Z__V== ON&& I2SBP1R__V==OFF) S2SBP1___V=0;
    if(I2SBP1Z__V==OFF&& I2SBP1R__V==OFF) S2SBP1___V=1;
    if(I2SBP1Z__V==OFF&& I2SBP1R__V== ON) S2SBP1___V=2;

    //  N28
    //------------------------------------------------------------------------

    S2HM2____V = 3;                                    
    if(I2HM2DN__V== ON&& I2HM2UP__V==OFF) S2HM2____V=0;
    if(I2HM2DN__V==OFF&& I2HM2UP__V==OFF) S2HM2____V=1;
    if(I2HM2DN__V==OFF&& I2HM2UP__V== ON) S2HM2____V=2;
    if(I2HM2DN__E> OFF|| I2HM2UP__E> OFF) S2HM2____V=3;

    S2KR2____V = 3;                                    
    if(I2KR2C___V== ON&& I2KR2O___V==OFF) S2KR2____V=0;
    if(I2KR2C___V==OFF&& I2KR2O___V==OFF) S2KR2____V=1;
    if(I2KR2C___V==OFF&& I2KR2O___V== ON) S2KR2____V=2;
    if(I2KR2C___E> OFF|| I2KR2O___E> OFF) S2KR2____V=3;

    S2BY2____V = 3;                                    
    if(I2BY2C___V== ON&& I2BY2O___V==OFF) S2BY2____V=0;
    if(I2BY2C___V==OFF&& I2BY2O___V==OFF) S2BY2____V=1;
    if(I2BY2C___V==OFF&& I2BY2O___V== ON) S2BY2____V=2;
    if(I2BY2C___E> OFF|| I2BY2O___E> OFF) S2BY2____V=3;

    S2P2_____V = 3;                                    
    if(I2P2_N___V== ON&& I2P2_Y___V==OFF) S2P2_____V=0;
    if(I2P2_N___V==OFF&& I2P2_Y___V==OFF) S2P2_____V=1;
    if(I2P2_N___V==OFF&& I2P2_Y___V== ON) S2P2_____V=2;

    S2SBP2___V = 3;                                    
    if(I2SBP2Z__V== ON&& I2SBP2R__V==OFF) S2SBP2___V=0;
    if(I2SBP2Z__V==OFF&& I2SBP2R__V==OFF) S2SBP2___V=1;
    if(I2SBP2Z__V==OFF&& I2SBP2R__V== ON) S2SBP2___V=2;

    //------------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
