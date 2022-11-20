//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
//  обнуление массива перменных DBB[]
vd  far SetZerVL(vd){
    _i  a=0;    
    for(a=0; a<MAXDBB; a++){ DBB[a]=0; }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  установка значений по умолчанию
vd  far SetDefVL(vd){
    Print("\n\rSet default values for ALL variables.\n\r>\n\r"); LKey(0);
    DateCMP1_V=rpDC;                  // дата  компиляции
    TimeCMP1_V=rpTC;                  // время компиляции
    COM1HSMD_M=2;                     // секунд для подсчета состояния модулей
    COM2HSMD_M=2;                     //
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  запись массива переменных на диск
_i  far WriteDataP(vd){
    WriteData(0);
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  чтение массива данных с диска
_i  far ReadDataP(vd){
    ReadData(0);
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  инициализация NetBIOS
ui  far InitNB(ui Mode){
    ui  a=0,b=0;
    if (Mode==1){
       if ( (WS_NB__Init())==1 ){
           printf("NETBIOS not present! \n"); return(0);
       }
       NBStat=1;
       printf("NETBIOS present! \n");
       printf("Add WS name [%s] in NetBIOS Network...\n",WS_LocalS);
       for(a=0;a<MNCB;a++){
           if ((WS_NB__AddName(WS_LocalS,a))<100){ printf("%d ",a); b++; }
       };  printf("\n");
       if (b==0){ printf("Can't activization NetWork! \n"); return(0); }
       printf("Added  NetBIOS Name:[%s]\n",WS_NB__GetOurName(0));
    } else {
       printf("Deleted WS name from NCB: " ); b=0;
       for(a=0;a<MNCB;a++){
          if ((WS_NB__DeleteName(WS_LocalS,a))<100){ b=0; printf("%d ",a); }
          else  {
             if (b==0){ WS_NB__Cancel(a); b=1; a--; continue; }
          }; b=0;
       }; printf("\n"); NBStat=0;
    }
    return(NBStat);
}
//---------------------------------------------------------------------------

