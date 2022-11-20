// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7080, N0C
    
    rec=14;

    // КТ2 Расход воды после ХВО2 на бак котла N2
    AIF36V_R0V=GetMODV(COMU1,rec+0,0);
//  AIF36V_R0V=modcnt;
    if(AIF36V_R0V>0){ 
       AIF36VVC=AIF36V_R0V; if(AIF36VFS>0){ AIF36VVO=AIF36VVC; AIF36VFS=0; }
    }

    // КТ2 Расход воды после ХВО2 на бак котла N2
    AIX0C1_R0V=GetMODV(COMU1,rec+1,0);
//  AIX0C1_R0V=modcnt;
    if(AIX0C1_R0V>0){ 
       AIX0C1VC=AIX0C1_R0V; if(AIX0C1FS>0){ AIX0C1VO=AIX0C1VC; AIX0C1FS=0; }
    }

//----------------------------------------------------------------------------
