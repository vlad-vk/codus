//----------------------------------------------------------------------------
//  COM2, 7018, N01
    rec=0;

    if(AITHDF_SDV<=0){ AITHDF_SDV=1; AITHDF_SZV=0; }
    AITHDF___V=AISet( 0,GetMODV(COMU1,rec,0),0,100,0,AITHDF_SDV,AITHDF__AV,AITHDF__FV)+AITHDF_SZV;

    if(AITGDF_SDV<=0){ AITGDF_SDV=1; AITGDF_SZV=0; }
    AITGDF___V=AISet( 1,GetMODV(COMU1,rec,1),0,100,0,AITGDF_SDV,AITGDF__AV,AITGDF__FV)+AITGDF_SZV;

    if(AIT1ST_SDV<=0){ AIT1ST_SDV=1; AIT1ST_SZV=0; }
    AIT1ST___V=AISet( 2,GetMODV(COMU1,rec,2),0,100,0,AIT1ST_SDV,AIT1ST__AV,AIT1ST__FV)+AIT1ST_SZV;

    if(AITF1D_SDV<=0){ AITF1D_SDV=1; AITF1D_SZV=0; }
    AITF1D___V=AISet( 3,GetMODV(COMU1,rec,3),0,100,0,AITF1D_SDV,AITF1D__AV,AITF1D__FV)+AITF1D_SZV;

    if(AIT2ST_SDV<=0){ AIT2ST_SDV=1; AIT2ST_SZV=0; }
    AIT2ST___V=AISet( 4,GetMODV(COMU1,rec,4),0,100,0,AIT2ST_SDV,AIT2ST__AV,AIT2ST__FV)+AIT2ST_SZV;

    if(AIT1GR_SDV<=0){ AIT1GR_SDV=1; AIT1GR_SZV=0; }
    AIT1GR___V=AISet( 5,GetMODV(COMU1,rec,5),0,100,0,AIT1GR_SDV,AIT1GR__AV,AIT1GR__FV)+AIT1GR_SZV;

    if(AIT2GR_SDV<=0){ AIT2GR_SDV=1; AIT2GR_SZV=0; }
    AIT2GR___V=AISet( 6,GetMODV(COMU1,rec,6),0,100,0,AIT2GR_SDV,AIT2GR__AV,AIT2GR__FV)+AIT2GR_SZV;

    if(AITNS1_SDV<=0){ AITNS1_SDV=1; AITNS1_SZV=0; }
    AITNS1___V=AISet( 7,GetMODV(COMU1,rec,7),0,100,0,AITNS1_SDV,AITNS1__AV,AITNS1__FV)+AITNS1_SZV;

//----------------------------------------------------------------------------
