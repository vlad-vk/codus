//---------------------------------------------------------------------------
//  ���㫥��� ���ᨢ� ��ଥ���� DBB[]
vd  far SetZerVL(vd){
    _i  a=0;    
    for(a=0; a<MAXDBB; a++){ DBB[a]=0; }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ��⠭���� ���祭�� �� 㬮�砭��
vd  far SetDefVL(vd){
    Print("\n\rSet default values for ALL variables.\n\r>\n\r"); LKey(0);
    DateCompil=rpDC;                  // ���  �������樨
    TimeCompil=rpTC;                  // �६� �������樨
    COM1HSMD_M=2;                     // ᥪ㭤 ��� ������ ���ﭨ� ���㫥�
    COM2HSMD_M=2;                     //
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ������ ���ᨢ� ��६����� �� ���
_i  far WriteDataP(vd){
    WriteData(0);
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �⥭�� ���ᨢ� ������ � ��᪠
_i  far ReadDataP(vd){
    ReadData(0);
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ���樠������ NetBIOS
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
