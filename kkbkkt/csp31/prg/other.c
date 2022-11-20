// coding=cp866
//---------------------------------------------------------------------------
//  ���㫥��� ���ᨢ� ��ଥ���� DBB[]
vd  far SetZerVL(vd){
    _i  a=0;    
    for(a=0; a<MAXDBB; a++){ DBB[a]=0; }
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ������ ���ᨢ� ��६����� �� ���
_i  far WriteDataP(vd){
    int f=0;
    WriteData(0);
    // ������� ���祭�� ��ன � ����� ��������
    f=open("cp_dba1.dat",O_BINARY|O_WRONLY|O_CREAT|O_TRUNC,S_IWRITE|S_IREAD);
    if(f>=0) write(f,&DBO,sizeof(DBO)); close(f);
    f=open("cp_dba2.dat",O_BINARY|O_WRONLY|O_CREAT|O_TRUNC,S_IWRITE|S_IREAD);
    if(f>=0) write(f,&DBA,sizeof(DBA)); close(f);
    Message(3,0);
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  �⥭�� ���ᨢ� ������ � ��᪠
_i  far ReadDataP(vd){
    int a=0,f=0,b=0;
    ReadData(0);
    // �᫨ ���� ����� � ��஬� 䠩�� ������ ���ᨢ� ��।�����- ����� ��
    // � ����� �������� (���-�� ��ࠬ��஢ PARM=24)
    if(access("cp_dba1.dat",4)==0){
       f=open("cp_dba1.dat",O_BINARY|O_RDONLY);
       if(f>=0) read(f,&DBO,sizeof(DBO)); close(f);
       printf("r1 ");
    }
    // �᫨ ���� ����� � ������ 䠩�� ������ ���ᨢ� ��।�����- ����� ��
    // � �����  �������� (���-�� ��ࠬ��஢ PARM=30)
    if(access("cp_dba2.dat",4)==0){
       f=open("cp_dba2.dat",O_BINARY|O_RDONLY);
       if(f>=0) read(f,&DBA,sizeof(DBA)); close(f);
       printf("r2 s2 ");
    } else {
       // �᫨ ��� ����㯠 � ����� �������- ��।��� �� ��ன 
       // ���祭�� � ����� (⮫쪮 24���祭��)
       for(a=0;a<HMWD;a++){
           DBA[a].yeaC=DBO[a].yeaC;
           DBA[a].monC=DBO[a].monC;
           DBA[a].dayC=DBO[a].dayC;
           for(b=0;b<24;b++){
               for(f=0;f<24;f++){
                   DBA[a].pr[b].data[f]=DBO[a].pr[b].data[f];
               }
           }
       }
       printf("s2 ");
    }
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


//---------------------------------------------------------------------------
vd  mCheckData(vd){
    _i  a=0;    
    for(a=0;a<MAXDBB;a++){
        DBB[a]=CheckVal(DBB[a],-100,1000000);
        if(CheckValER!=0){ Print("DBB[%d]=%f  ",a,DBB[a]); }
    }
    return;
}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------
