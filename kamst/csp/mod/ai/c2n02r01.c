//----------------------------------------------------------------------------
//  COM2, 7018, N02
    rec=1;

    if(AITNS2_SDV<=0){ AITNS2_SDV=1; AITNS2_SZV=0; }
    AITNS2___V=AISet( 8,GetMODV(COMU1,rec,0),0,100,0,AITNS2_SDV,AITNS2__AV,AITNS2__FV)+AITNS2_SZV;

    if(AITPBM_SDV<=0){ AITPBM_SDV=1; AITPBM_SZV=0; }
    AITPBM___V=AISet( 9,GetMODV(COMU1,rec,1),0,100,0,AITPBM_SDV,AITPBM__AV,AITPBM__FV)+AITPBM_SZV;

    if(AITF1P_SDV<=0){ AITF1P_SDV=1; AITF1P_SZV=0; }
    AITF1P___V=AISet(10,GetMODV(COMU1,rec,2),0,100,0,AITF1P_SDV,AITF1P__AV,AITF1P__FV)+AITF1P_SZV;

    if(AITDVP_SDV<=0){ AITDVP_SDV=1; AITDVP_SZV=0; }
    AITDVP___V=AISet(11,GetMODV(COMU1,rec,3),0,100,0,AITDVP_SDV,AITDVP__AV,AITDVP__FV)+AITDVP_SZV;

    if(AIX0204SDV<=0){ AIX0204SDV=1; AIX0204SZV=0; }
    AIX0204__V=AISet(12,GetMODV(COMU1,rec,4),0,100,0,AIX0204SDV,AIX0204_AV,AIX0204_FV)+AIX0204SZV;

    if(AIX0205SDV<=0){ AIX0205SDV=1; AIX0205SZV=0; }
    AIX0205__V=AISet(13,GetMODV(COMU1,rec,5),0,100,0,AIX0205SDV,AIX0205_AV,AIX0205_FV)+AIX0205SZV;

    if(AIX0206SDV<=0){ AIX0206SDV=1; AIX0206SZV=0; }
    AIX0206__V=AISet(14,GetMODV(COMU1,rec,6),0,100,0,AIX0206SDV,AIX0206_AV,AIX0206_FV)+AIX0206SZV;

    if(AIX0207SDV<=0){ AIX0207SDV=1; AIX0207SZV=0; }
    AIX0207__V=AISet(15,GetMODV(COMU1,rec,7),0,100,0,AIX0207SDV,AIX0207_AV,AIX0207_FV)+AIX0207SZV;

//----------------------------------------------------------------------------
