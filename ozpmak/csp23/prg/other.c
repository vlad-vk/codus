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
    DateCMP3_V=rpDC;                  // ���  �������樨
    TimeCMP3_V=rpTC;                  // �६� �������樨
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
ui  far LocalInitNB(ui Mode){
    ui  a=0,b=0;
    if (Mode==1){
       if ( (WS_NB__Init())==1 ){
           printf("NETBIOS not present! \n"); return(0);
       }
       NBStat=1;
       printf("NETBIOS present! \n");
       printf("Add WS name [%s] in NetBIOS Network...\n",WS_LocalS);
       for(a=0;a<MNCB+2;a++){
           if ((WS_NB__AddName(WS_LocalS,a))<100){ printf("%d ",a); b++; }
       };  printf("\n");
       if (b==0){ printf("Can't activization NetWork! \n"); return(0); }
       printf("Added  NetBIOS Name:[%s]\n",WS_NB__GetOurName(0));
    } else {
       printf("Deleted WS name from NCB: " ); b=0;
       for(a=0;a<MNCB+2;a++){
          if ((WS_NB__DeleteName(WS_LocalS,a))<100){ b=0; printf("%d ",a); }
          else  {
             if (b==0){ WS_NB__Cancel(a); b=1; a--; continue; }
          }; b=0;
       }; printf("\n"); NBStat=0;
    }
    return(NBStat);
}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------
vd far NBW_SetValForReq(vd){
   // ����� ����訢����� ������� � ���ᨢ� DBB[]
   // AIP                    
   DBN[ 0]=504;  DBN[ 1]=505;  DBN[ 2]=744; 
   DBN[ 3]=745;  DBN[ 4]=984;  DBN[ 5]=985;
   // PPSTEP
   DBN[ 6]=3729; DBN[ 7]=3779; DBN[ 8]=3829; 
   DBN[ 9]=3879; DBN[10]=3929; DBN[11]=3979;
   // NAKPP
   DBN[12]=3121; DBN[13]=3221; DBN[14]=3321;
   DBN[15]=3421; DBN[16]=3521; DBN[17]=3621;

// ����� ����஫��஢(PCCS) ��� ����訢����� �������
   // AIP                    
   DBC[ 0]= 0;   DBC[ 1]= 0;   DBC[ 2]=23;
   DBC[ 3]=23;   DBC[ 4]= 0;   DBC[ 5]= 0;
   // PPSTEP
   DBC[ 6]= 0;   DBC[ 7]= 0;   DBC[ 8]=23;
   DBC[ 9]=23;   DBC[10]= 0;   DBC[11]= 0;
   // NAKPP
   DBC[12]= 0;   DBC[13]= 0;   DBC[14]=23;
   DBC[15]=23;   DBC[16]= 0;   DBC[17]= 0;

   return;
}
//----------------------------------------------------------------------------
