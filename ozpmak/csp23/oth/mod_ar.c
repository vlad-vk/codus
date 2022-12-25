//---------------------------------------------------------------------------
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  Modify  after ready
//  Корректировки после чтения сигналов и после DebVal
vd  far Mod_AR(vd){

    //  N51
    //------------------------------------------------------------------------
    S3ZIOP___V = 3;                                        // оба сигнала
    if(I3ZIOPC__V== ON&& I3ZIOPO__V==OFF) S3ZIOP___V=0;    // закрыта
    if(I3ZIOPC__V==OFF&& I3ZIOPO__V==OFF) S3ZIOP___V=1;    // неопределенное
    if(I3ZIOPC__V==OFF&& I3ZIOPO__V== ON) S3ZIOP___V=2;    // открыта
    if(I3ZIOPC__E> OFF|| I3ZIOPO__E> OFF) S3ZIOP___V=3;    // время сработки

    S3ZIPP___V = 3;                                    
    if(I3ZIPPC__V== ON&& I3ZIPPO__V==OFF) S3ZIPP___V=0;
    if(I3ZIPPC__V==OFF&& I3ZIPPO__V==OFF) S3ZIPP___V=1;
    if(I3ZIPPC__V==OFF&& I3ZIPPO__V== ON) S3ZIPP___V=2;
    if(I3ZIPPC__E> OFF|| I3ZIPPO__E> OFF) S3ZIPP___V=3;

    S3KIP____V = 3;                                    
    if(I3KIPC___V== ON&& I3KIPO___V==OFF) S3KIP____V=0;
    if(I3KIPC___V==OFF&& I3KIPO___V==OFF) S3KIP____V=1;
    if(I3KIPC___V==OFF&& I3KIPO___V== ON) S3KIP____V=2;
    if(I3KIPC___E> OFF|| I3KIPO___E> OFF) S3KIP____V=3;

    S3ZOPP___V = 3;                                    
    if(I3ZOPPC__V== ON&& I3ZOPPO__V==OFF) S3ZOPP___V=0;
    if(I3ZOPPC__V==OFF&& I3ZOPPO__V==OFF) S3ZOPP___V=1;
    if(I3ZOPPC__V==OFF&& I3ZOPPO__V== ON) S3ZOPP___V=2;
    if(I3ZOPPC__E> OFF|| I3ZOPPO__E> OFF) S3ZOPP___V=3;

    S3ZOPA___V = 3;                                    
    if(I3ZOPAC__V== ON&& I3ZOPAO__V==OFF) S3ZOPA___V=0;
    if(I3ZOPAC__V==OFF&& I3ZOPAO__V==OFF) S3ZOPA___V=1;
    if(I3ZOPAC__V==OFF&& I3ZOPAO__V== ON) S3ZOPA___V=2;
    if(I3ZOPAC__E> OFF|| I3ZOPAO__E> OFF) S3ZOPA___V=3;

    S3KOP____V = 3;                                    
    if(I3KOPC___V== ON&& I3KOPO___V==OFF) S3KOP____V=0;
    if(I3KOPC___V==OFF&& I3KOPO___V==OFF) S3KOP____V=1;
    if(I3KOPC___V==OFF&& I3KOPO___V== ON) S3KOP____V=2;
    if(I3KOPC___E> OFF|| I3KOPO___E> OFF) S3KOP____V=3;

    S3MDU____V = 3;                                    
    if(I3MU_____V== ON&& I3DU_____V==OFF) S3MDU____V=0;
    if(I3MU_____V==OFF&& I3DU_____V==OFF) S3MDU____V=1;
    if(I3MU_____V==OFF&& I3DU_____V== ON) S3MDU____V=2;


    //  N52
    //------------------------------------------------------------------------
    S3VZ_____V = 3;                                        // оба сигнала
    if(I3VZC____V== ON&& I3VZO____V==OFF) S3VZ_____V=0;    // закрыта
    if(I3VZC____V==OFF&& I3VZO____V==OFF) S3VZ_____V=1;    // неопределенное
    if(I3VZC____V==OFF&& I3VZO____V== ON) S3VZ_____V=2;    // открыта
    if(I3VZC____E> OFF|| I3VZO____E> OFF) S3VZ_____V=3;    // контроль времени
    if(I3VZOE___V> OFF|| I3VZCE___V> OFF) S3VZ_____V=3;    // контроль муфты

//S3VN_____V

    //  N55
    //------------------------------------------------------------------------

//S3GNS____V

    S3LUCMD__V = 3;                                    
    if(I3LUCMU__V== ON&& I3LUCDU__V==OFF) S3LUCMD__V=0;
    if(I3LUCMU__V==OFF&& I3LUCDU__V==OFF) S3LUCMD__V=1;
    if(I3LUCMU__V==OFF&& I3LUCDU__V== ON) S3LUCMD__V=2;

    S3KOC____V = 3;                                    
    if(I3KOCC___V== ON&& I3KOCO___V==OFF) S3KOC____V=0;
    if(I3KOCC___V==OFF&& I3KOCO___V==OFF) S3KOC____V=1;
    if(I3KOCC___V==OFF&& I3KOCO___V== ON) S3KOC____V=2;
    if(I3KOCC___E> OFF|| I3KOCO___E> OFF) S3KOC____V=3;

    //  N57
    //------------------------------------------------------------------------

    S3HM1____V = 3;                                        
    if(I3HM1DN__V== ON&& I3HM1UP__V==OFF) S3HM1____V=0;    
    if(I3HM1DN__V==OFF&& I3HM1UP__V==OFF) S3HM1____V=1;    
    if(I3HM1DN__V==OFF&& I3HM1UP__V== ON) S3HM1____V=2;    
    if(I3HM1DN__E> OFF|| I3HM1UP__E> OFF) S3HM1____V=3;

    S3KR1____V = 3;                                    
    if(I3KR1C___V== ON&& I3KR1O___V==OFF) S3KR1____V=0;
    if(I3KR1C___V==OFF&& I3KR1O___V==OFF) S3KR1____V=1;
    if(I3KR1C___V==OFF&& I3KR1O___V== ON) S3KR1____V=2;
    if(I3KR1C___E> OFF|| I3KR1O___E> OFF) S3KR1____V=3;

    S3BY1____V = 3;                                    
    if(I3BY1C___V== ON&& I3BY1O___V==OFF) S3BY1____V=0;
    if(I3BY1C___V==OFF&& I3BY1O___V==OFF) S3BY1____V=1;
    if(I3BY1C___V==OFF&& I3BY1O___V== ON) S3BY1____V=2;
    if(I3BY1C___E> OFF|| I3BY1O___E> OFF) S3BY1____V=3;

    S3P1_____V = 3;                                    
    if(I3P1_N___V== ON&& I3P1_Y___V==OFF) S3P1_____V=0;
    if(I3P1_N___V==OFF&& I3P1_Y___V==OFF) S3P1_____V=1;
    if(I3P1_N___V==OFF&& I3P1_Y___V== ON) S3P1_____V=2;

    S3SBP1___V = 3;                                    
    if(I3SBP1Z__V== ON&& I3SBP1R__V==OFF) S3SBP1___V=0;
    if(I3SBP1Z__V==OFF&& I3SBP1R__V==OFF) S3SBP1___V=1;
    if(I3SBP1Z__V==OFF&& I3SBP1R__V== ON) S3SBP1___V=2;


    //  N61
    //------------------------------------------------------------------------

    S4ZIOP___V = 3;                                    
    if(I4ZIOPC__V== ON&& I4ZIOPO__V==OFF) S4ZIOP___V=0;
    if(I4ZIOPC__V==OFF&& I4ZIOPO__V==OFF) S4ZIOP___V=1;
    if(I4ZIOPC__V==OFF&& I4ZIOPO__V== ON) S4ZIOP___V=2;
    if(I4ZIOPC__E> OFF|| I4ZIOPO__E> OFF) S4ZIOP___V=3;

    S4ZIPP___V = 3;                                    
    if(I4ZIPPC__V== ON&& I4ZIPPO__V==OFF) S4ZIPP___V=0;
    if(I4ZIPPC__V==OFF&& I4ZIPPO__V==OFF) S4ZIPP___V=1;
    if(I4ZIPPC__V==OFF&& I4ZIPPO__V== ON) S4ZIPP___V=2;
    if(I4ZIPPC__E> OFF|| I4ZIPPO__E> OFF) S4ZIPP___V=3;

    S4KIP____V = 3;                                    
    if(I4KIPC___V== ON&& I4KIPO___V==OFF) S4KIP____V=0;
    if(I4KIPC___V==OFF&& I4KIPO___V==OFF) S4KIP____V=1;
    if(I4KIPC___V==OFF&& I4KIPO___V== ON) S4KIP____V=2;
    if(I4KIPC___E> OFF|| I4KIPO___E> OFF) S4KIP____V=3;

    S4ZOPP___V = 3;                                    
    if(I4ZOPPC__V== ON&& I4ZOPPO__V==OFF) S4ZOPP___V=0;
    if(I4ZOPPC__V==OFF&& I4ZOPPO__V==OFF) S4ZOPP___V=1;
    if(I4ZOPPC__V==OFF&& I4ZOPPO__V== ON) S4ZOPP___V=2;
    if(I4ZOPPC__E> OFF|| I4ZOPPO__E> OFF) S4ZOPP___V=3;

    S4ZOPA___V = 3;                                    
    if(I4ZOPAC__V== ON&& I4ZOPAO__V==OFF) S4ZOPA___V=0;
    if(I4ZOPAC__V==OFF&& I4ZOPAO__V==OFF) S4ZOPA___V=1;
    if(I4ZOPAC__V==OFF&& I4ZOPAO__V== ON) S4ZOPA___V=2;
    if(I4ZOPAC__E> OFF|| I4ZOPAO__E> OFF) S4ZOPA___V=3;

    S4KOP____V = 3;                                    
    if(I4KOPC___V== ON&& I4KOPO___V==OFF) S4KOP____V=0;
    if(I4KOPC___V==OFF&& I4KOPO___V==OFF) S4KOP____V=1;
    if(I4KOPC___V==OFF&& I4KOPO___V== ON) S4KOP____V=2;
    if(I4KOPC___E> OFF|| I4KOPO___E> OFF) S4KOP____V=3;

    S4MDU____V = 3;                                    
    if(I4MU_____V== ON&& I4DU_____V==OFF) S4MDU____V=0;
    if(I4MU_____V==OFF&& I4DU_____V==OFF) S4MDU____V=1;
    if(I4MU_____V==OFF&& I4DU_____V== ON) S4MDU____V=2;

    //  N62
    //------------------------------------------------------------------------

    S4VZ_____V = 3;                                        // оба сигнала
    if(I4VZC____V== ON&& I4VZO____V==OFF) S4VZ_____V=0;    // закрыта
    if(I4VZC____V==OFF&& I4VZO____V==OFF) S4VZ_____V=1;    // неопределенное
    if(I4VZC____V==OFF&& I4VZO____V== ON) S4VZ_____V=2;    // открыта
    if(I4VZC____E> OFF|| I4VZO____E> OFF) S4VZ_____V=3;    // контроль времени
    if(I4VZOE___V> OFF|| I4VZCE___V> OFF) S4VZ_____V=3;    // контроль муфты

//S4VN_____V


    //  N65
    //------------------------------------------------------------------------

//S4GNS____V

    S4LUCMD__V = 3;                                    
    if(I4LUCMU__V== ON&& I4LUCDU__V==OFF) S4LUCMD__V=0;
    if(I4LUCMU__V==OFF&& I4LUCDU__V==OFF) S4LUCMD__V=1;
    if(I4LUCMU__V==OFF&& I4LUCDU__V== ON) S4LUCMD__V=2;

    S4KOC____V = 3;                                    
    if(I4KOCC___V== ON&& I4KOCO___V==OFF) S4KOC____V=0;
    if(I4KOCC___V==OFF&& I4KOCO___V==OFF) S4KOC____V=1;
    if(I4KOCC___V==OFF&& I4KOCO___V== ON) S4KOC____V=2;
    if(I4KOCC___E> OFF|| I4KOCO___E> OFF) S4KOC____V=3;

    //  N67
    //------------------------------------------------------------------------

    S4HM1____V = 3;                                        // оба сигнала
    if(I4HM1DN__V== ON&& I4HM1UP__V==OFF) S4HM1____V=0;    // закрыта
    if(I4HM1DN__V==OFF&& I4HM1UP__V==OFF) S4HM1____V=1;    // неопределенное
    if(I4HM1DN__V==OFF&& I4HM1UP__V== ON) S4HM1____V=2;    // открыта
    if(I4HM1DN__E> OFF|| I4HM1UP__E> OFF) S4HM1____V=3;

    S4KR1____V = 3;                                    
    if(I4KR1C___V== ON&& I4KR1O___V==OFF) S4KR1____V=0;
    if(I4KR1C___V==OFF&& I4KR1O___V==OFF) S4KR1____V=1;
    if(I4KR1C___V==OFF&& I4KR1O___V== ON) S4KR1____V=2;
    if(I4KR1C___E> OFF|| I4KR1O___E> OFF) S4KR1____V=3;

    S4BY1____V = 3;                                    
    if(I4BY1C___V== ON&& I4BY1O___V==OFF) S4BY1____V=0;
    if(I4BY1C___V==OFF&& I4BY1O___V==OFF) S4BY1____V=1;
    if(I4BY1C___V==OFF&& I4BY1O___V== ON) S4BY1____V=2;
    if(I4BY1C___E> OFF|| I4BY1O___E> OFF) S4BY1____V=3;

    S4P1_____V = 3;                                    
    if(I4P1_N___V== ON&& I4P1_Y___V==OFF) S4P1_____V=0;
    if(I4P1_N___V==OFF&& I4P1_Y___V==OFF) S4P1_____V=1;
    if(I4P1_N___V==OFF&& I4P1_Y___V== ON) S4P1_____V=2;

    S4SBP1___V = 3;                                    
    if(I4SBP1Z__V== ON&& I4SBP1R__V==OFF) S4SBP1___V=0;
    if(I4SBP1Z__V==OFF&& I4SBP1R__V==OFF) S4SBP1___V=1;
    if(I4SBP1Z__V==OFF&& I4SBP1R__V== ON) S4SBP1___V=2;

    //  N68
    //------------------------------------------------------------------------

    S4HM2____V = 3;                                    
    if(I4HM2DN__V== ON&& I4HM2UP__V==OFF) S4HM2____V=0;
    if(I4HM2DN__V==OFF&& I4HM2UP__V==OFF) S4HM2____V=1;
    if(I4HM2DN__V==OFF&& I4HM2UP__V== ON) S4HM2____V=2;
    if(I4HM2DN__E> OFF|| I4HM2UP__E> OFF) S4HM2____V=3;

    S4KR2____V = 3;                                    
    if(I4KR2C___V== ON&& I4KR2O___V==OFF) S4KR2____V=0;
    if(I4KR2C___V==OFF&& I4KR2O___V==OFF) S4KR2____V=1;
    if(I4KR2C___V==OFF&& I4KR2O___V== ON) S4KR2____V=2;
    if(I4KR2C___E> OFF|| I4KR2O___E> OFF) S4KR2____V=3;

    S4BY2____V = 3;                                    
    if(I4BY2C___V== ON&& I4BY2O___V==OFF) S4BY2____V=0;
    if(I4BY2C___V==OFF&& I4BY2O___V==OFF) S4BY2____V=1;
    if(I4BY2C___V==OFF&& I4BY2O___V== ON) S4BY2____V=2;
    if(I4BY2C___E> OFF|| I4BY2O___E> OFF) S4BY2____V=3;

    S4P2_____V = 3;                                    
    if(I4P2_N___V== ON&& I4P2_Y___V==OFF) S4P2_____V=0;
    if(I4P2_N___V==OFF&& I4P2_Y___V==OFF) S4P2_____V=1;
    if(I4P2_N___V==OFF&& I4P2_Y___V== ON) S4P2_____V=2;

    S4SBP2___V = 3;                                    
    if(I4SBP2Z__V== ON&& I4SBP2R__V==OFF) S4SBP2___V=0;
    if(I4SBP2Z__V==OFF&& I4SBP2R__V==OFF) S4SBP2___V=1;
    if(I4SBP2Z__V==OFF&& I4SBP2R__V== ON) S4SBP2___V=2;

    //------------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
