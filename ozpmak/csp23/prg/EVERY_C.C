//---------------------------------------------------------------------------
vd  far EveryCyc(vd){
    // ?????? ?⢥?? ?? ???㫥? ???
    if(RunLocal>0){ ReadANS(COMU1); }
    // ?᫨ ??? ??裡 ?? ???? NetBIOS - ????砥? ????? ?? COM ?????
    if(RunLocal>0&&NBLiveT3_V> 3){ HCOMANS=ReadANS(COMWS); }
    // ??᫠?? ???????? ?????ᮢ ?? ???㫨 ???
    if(BusyTer==0){ SendCMD(COMU1); }
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
vd  far First_in_Cycle(vd){
    if (NBStat>0){ WS_NB__NetChange(); }
    return;
}
//---------------------------------------------------------------------------
vd  far Last__in_Cycle(vd){
    return;
}
//---------------------------------------------------------------------------
