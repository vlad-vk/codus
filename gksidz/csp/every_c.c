//---------------------------------------------------------------------------
vd  far EveryCyc(vd){
    // ���� �⢥�� �� ���㫥� ���
    if(RunLocal>0){ ReadANS(COMU1); }
    if(RunLocal>0){ ReadANS(COMU2); }
    // �᫨ ��� �裡 �� �� NetBIOS - ����砥� ��� �� COM �����
    if(RunLocal>0&&NBLiveTO_V>50){ ReadANS(COMWS); }
    // ��᫠�� �������� ����ᮢ �� ���㫨 ���
#ifndef TESTVAGI
    if(BusyTer==0){ SendCMD(COMU1); }
    if(BusyTer==0){ SendCMD(COMU2); }
#endif
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
vd  far First_in_Cycle(vd){
    if (NBStat>0){
        WS_NB__NetChange();
    }
    return;
}
//---------------------------------------------------------------------------
vd  far Last__in_Cycle(vd){
    return;
}
//---------------------------------------------------------------------------
