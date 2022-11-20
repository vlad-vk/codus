// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7080, N0D
    
    rec=16;

    // КТ2 Расход на котел N2
    AIF37V_R0V=GetMODV(COMU1,rec+0,0);
//  AIF37V_R0V=modcnt;
    if(AIF37V_R0V>0){ 
       AIF37VVC=AIF37V_R0V; if(AIF37VFS>0){ AIF37VVO=AIF37VVC; AIF37VFS=0; }
    }

    // КТ2 Расход на котел N1
    AIF38V_R0V=GetMODV(COMU1,rec+1,0);
//  AIF38V_R0V=modcnt;
    if(AIF38V_R0V>0){ 
       AIF38VVC=AIF38V_R0V; if(AIF38VFS>0){ AIF38VVO=AIF38VVC; AIF38VFS=0; }
    }

//----------------------------------------------------------------------------
