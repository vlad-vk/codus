//---------------------------------------------------------------------------
//  ?맮? ?㭪権, ??????? ?믮??????? ?????? ⨪ (18 ࠧ/ᥪ)
vd  far EveryTic(vd){

    if (FirstCall<PAMAX){ 
        if(FirstCall==PAMSG){
           if(access("run_prg.fln",4)==0) unlink("run_prg.fln");
           if(access("run_prg.fls",4)==0) unlink("run_prg.fls");
           Message(18,0); 
        }
        FirstCall++; 
    }

    ptLocalExchange();

    blocking();

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
