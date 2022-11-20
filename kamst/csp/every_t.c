//---------------------------------------------------------------------------
//  Вызов функций, которые выполняются каждый тик (18 раз/сек)
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
