//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
//  �맮� �㭪権, ����� �믮������� ����� ⨪ (18 ࠧ/ᥪ)
vd  far EveryTic(vd){
    if(FirstCall<PAMAX){ if(FirstCall==PAMSG){ Message(17,NOKV); }; FirstCall++; }

    ptLocalExchange();

    InpDataD();
    InpDataS();

    DebugVal();

    Monitor();
    if (RunLocal==0){ return; }

    UpdDataT();

    OutDataA();
    OutDataD();

    return;
}
//---------------------------------------------------------------------------
