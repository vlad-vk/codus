// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7080, N0B
    
    rec=12;

    // ��2 ���室 ���� ��। ���2
    AIF34V_R0V=GetMODV(COMU1,rec+0,0);
//  AIF34V_R0V=modcnt;
    if(AIF34V_R0V>0){ 
       AIF34VVC=AIF34V_R0V; if(AIF34VFS>0){ AIF34VVO=AIF34VVC; AIF34VFS=0; }
    }

    // ��2 ���室 ���� ��᫥ ���2 �� ��� ��⫠ N2
    AIF35V_R0V=GetMODV(COMU1,rec+1,0);
//  AIF35V_R0V=modcnt;
    if(AIF34V_R0V>0){ 
       AIF35VVC=AIF34V_R0V; if(AIF35VFS>0){ AIF35VVO=AIF35VVC; AIF35VFS=0; }
    }

//----------------------------------------------------------------------------
