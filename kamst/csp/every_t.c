//---------------------------------------------------------------------------
//  �맮� �㭪権, ����� �믮������� ����� ⨪ (18 ࠧ/ᥪ)
vd  far EveryTic(vd){
    if(FirstCall<PAMAX){ if(FirstCall==PAMSG){ Message(17); }; FirstCall++; }

    InpDataA();
    InpDataD();

    Monitor();
    if (RunLocal==0){ return; }

    UpdDataT();

    OutDataA();
    OutDataD();

    return;
}
//---------------------------------------------------------------------------
