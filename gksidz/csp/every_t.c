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

#ifdef TESTVAGI
    if(vg_flg>1){
       if(BusyTer==0){ SendCMD(COMU1); }
       if(BusyTer==0){ SendCMD(COMU2); }
       vg_flg=0;
       vg_cnt++;
       Print("VG:  REQ_NUM=%ld  CUR_VAG=%6.1f\n",vg_cnt,AIW251___V);
    }
    vg_flg++;
#endif

    return;
}
//---------------------------------------------------------------------------
