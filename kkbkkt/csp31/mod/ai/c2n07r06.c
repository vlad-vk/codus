// coding: cp866
//----------------------------------------------------------------------------
//  COM2, 7033, N07

    rec=6;

    // ���祭�� ���� � ��������� �� 㬮�砭��, �᫨ ��� �� ������
    if(AIT331_SDV==0){ AIT331_SDM=100.2; AIT331_SZV=-0.2; }
    if(AIT37A_SDV==0){ AIT37A_SDM=100.2; AIT37A_SZV=-0.2; }
    if(AIT38A_SDV==0){ AIT38A_SDM=100.2; AIT38A_SZV=-0.2; }

    // ���� N ᥪ㭤 ��६ ���祭�� � ���稪�� � ���� 䨫��஬ ᪠窮�,
    // �⮡�  �ࠧ� ��� �� ॠ��� ���祭�� ��ࠬ��஢
    if(PAINPC<PAINP ){
       AIT331__FV=AIT331_SDV;
       AIT37A__FV=AIT37A_SDV;
       AIT38A__FV=AIT38A_SDV;
    }

    // ������� �८�ࠧ������ ���祭�� � ������� �����
    AIT331___V=AISet(33,GetMODV(COMU1,rec,0),0,32768,0,AIT331_SDV,AIT331__AV,AIT331__FV)+AIT331_SZV;
    if(AIT331___V<-1) AIT331___V=-1;

    AIT37A___V=AISet(34,GetMODV(COMU1,rec,1),0,32768,0,AIT37A_SDV,AIT37A__AV,AIT37A__FV)+AIT37A_SZV;
    if(AIT37A___V<-1) AIT37A___V=-1;

    AIT38A___V=AISet(35,GetMODV(COMU1,rec,2),0,32768,0,AIT38A_SDV,AIT38A__AV,AIT38A__FV)+AIT38A_SZV;
    if(AIT38A___V<-1) AIT38A___V=-1;

//----------------------------------------------------------------------------
