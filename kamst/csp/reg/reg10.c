//---------------------------------------------------------------------------
// ???????? ??????樮????? ????

//---------------------------------------------------------------------------
vd  far Reg_10(vd){
    //-----------------------------------------------------------------------
    ui RN=10;                              // ????? ॣ???????                
    _f IL=0;                               // ?室??? 誠?? (?????? ?࠭???)  
    _f IH=1;                               // ?室??? 誠?? (??????? ?࠭???) 
    _f OL=0.000;                           // ??室??? 誠?? (??????),%, ?.??.
    _f OH=100.0;                           // ??室??? 誠?? (??????),%, ?.??.
    _f DM=10.00;                           // ???? ?????? ??? ॣ???????      
    _f ZN=IH*0.001;                        // ???? ?????⢨⥫쭮???          
    _f PR=20.00;                           // ???業? ???ᮣ??ᮢ????         
    ui CC=20;                              // ????஫???? 横?                
    ui TP=1;                               // ??? ॣ???????                  
    //-----------------------------------------------------------------------
    // ?஢?ઠ ??????????
    if (AOPGOK__RM!=AOPGOK__RV){ 
        AOPGOK__RV =AOPGOK__RM; 
        if(AOPGOK__RV>0){ Message(118); }
        else            { Message(119); AOPGOK__OM=AOPGOK__OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ??⠭???? ???????
    if (AOPGOK__ZM <  IL         ){ AOPGOK__ZM = IL; }
    if (AOPGOK__ZM >  AIPGOK_AMV ){ AOPGOK__ZM = AIPGOK_AMV; }
        AOPGOK__ZV =  AOPGOK__ZM;
    // ??室 ?? ?????? ??筮?? ??ࠢ?????
    if (AOPGOK__OM < 0  ){ AOPGOK__OM =0;   }
    if (AOPGOK__OM > 100){ AOPGOK__OM =100; }
    //-----------------------------------------------------------------------
    // ??࠭?祭?? ??室? ॣ??????? ᭨?? ? ᢥ???
    AOPGOK_LOV =AOPGOK_LOM;
    AOPGOK_HOV =AOPGOK_HOM;
    // ??࠭?祭?? ??室? ?? ?ਡ??? ᭨?? ? ᢥ???
    AOPGOK_LPV =AOPGOK_LPM;
    AOPGOK_HPV =AOPGOK_HPM;
    // ??????樥??? ॣ???????
    AOPGOK__PV =AOPGOK__PM;
    AOPGOK__IV =AOPGOK__IM;
    AOPGOK__DV =AOPGOK__DM;
    AOPGOK__MV =AOPGOK__MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ?????????? ॣ??????
       AOPGOK__OV=Regulator(RN, AIPGOK___V,
                              AOPGOK__PV, AOPGOK__IV, AOPGOK__DV, AOPGOK__MV,
                              AOPGOK__OM, AOPGOK__RV,
                              AOPGOK__ZV, AOPGOK__ZV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ??࠭?祭?? ??室?, %
       if (AOPGOK__OV <  OL+AOPGOK_LOV){ AOPGOK__OV=OL+AOPGOK_LOV; }
       if (AOPGOK__OV >  OH-AOPGOK_HOV){ AOPGOK__OV=OH-AOPGOK_HOV; }
       if (AOPGOK__MV >= 0){ AOPGOK_OOV=100-AOPGOK__OV; }
       else                { AOPGOK_OOV=AOPGOK__OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
