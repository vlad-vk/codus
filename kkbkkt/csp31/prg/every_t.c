// coding=cp866
//---------------------------------------------------------------------------
vd  far EveryTic(vd){

    if (FirstCall<PAMAX){ 
        if(FirstCall==PAMSG){
           if(access("run_prg.fln",4)==0) unlink("run_prg.fln");
           if(access("run_prg.fls",4)==0) unlink("run_prg.fls");
           Message(17,0); 
        }
        FirstCall++; 
    }

    Monitor();
    if (RunLocal==0){ return; }

    OutDataD();

    return;
}
//---------------------------------------------------------------------------
