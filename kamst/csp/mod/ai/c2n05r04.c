//----------------------------------------------------------------------------
//  COM2, 7018, N05
    rec=4;

    if(AILNS1SSDV<=0){ AILNS1SSDV=1; AILNS1SSZV=0; }
    AILNS1S__V=AISet(32,GetMODV(COMU1,rec,0),0,100,0,AILNS1SSDV,AILNS1S_AV,AILNS1S_FV)+AILNS1SSZV;

    if(AILFS1SSDV<=0){ AILFS1SSDV=1; AILFS1SSZV=0; }
    AILFS1S__V=AISet(33,GetMODV(COMU1,rec,1),0,100,0,AILFS1SSDV,AILFS1S_AV,AILFS1S_FV)+AILFS1SSZV;

    if(AILNS2SSDV<=0){ AILNS2SSDV=1; AILNS2SSZV=0; }
    AILNS2S__V=AISet(34,GetMODV(COMU1,rec,2),0,100,0,AILNS2SSDV,AILNS2S_AV,AILNS2S_FV)+AILNS2SSZV;
 
    if(AILZSS_SDV<=0){ AILZSS_SDV=1; AILZSS_SZV=0; }
    AILZSS___V=AISet(35,GetMODV(COMU1,rec,3),0,100,0,AILZSS_SDV,AILZSS__AV,AILZSS__FV)+AILZSS_SZV;

    if(AILZO2SSDV<=0){ AILZO2SSDV=1; AILZO2SSZV=0; }
    AILZO2S__V=AISet(36,GetMODV(COMU1,rec,4),0,100,0,AILZO2SSDV,AILZO2S_AV,AILZO2S_FV)+AILZO2SSZV;

    if(AILZSVFSDV<=0){ AILZSVFSDV=1; AILZSVFSZV=0; }
    AILZSVF__V=AISet(37,GetMODV(COMU1,rec,5),0,100,0,AILZSVFSDV,AILZSVF_AV,AILZSVF_FV)+AILZSVFSZV;

    if(AILZPR_SDV<=0){ AILZPR_SDV=1; AILZPR_SZV=0; }
    AILZPR___V=AISet(38,GetMODV(COMU1,rec,6),0,100,0,AILZPR_SDV,AILZPR__AV,AILZPR__FV)+AILZPR_SZV;

    if(AILZO1SSDV<=0){ AILZO1SSDV=1; AILZO1SSZV=0; }
    AILZO1S__V=AISet(39,GetMODV(COMU1,rec,7),0,100,0,AILZO1SSDV,AILZO1S_AV,AILZO1S_FV)+AILZO1SSZV;

//----------------------------------------------------------------------------
