// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7080, N09
    
    rec=8;

    // КТ1 Расход воды на ХВО
    AIF303_R0V=GetMODV(COMU1,rec+0,0);
//  AIF303_R0V=modcnt;
//  printf("AIF303_R0V=%f ",AIF303_R0V);
    if(AIF303_R0V>0){ 
       AIF303VC=AIF303_R0V; if(AIF303FS>0){ AIF303VO=AIF303VC; AIF303FS=0; }
    }

    // КТ1 Расход гор воды на ТП4
    AIF304_R0V=GetMODV(COMU1,rec+1,0);
//  printf("AIF304_R0V=%f ",AIF304_R0V);
//  AIF304_R0V=modcnt;
    if(AIF304_R0V>0){ 
       AIF304VC=AIF304_R0V; if(AIF304FS>0){ AIF304VO=AIF304VC; AIF304FS=0; }
    }

//----------------------------------------------------------------------------
