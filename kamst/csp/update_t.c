//---------------------------------------------------------------------------
//  ���������� ���祭�� ����� ⨪ ��⥬� (18 ࠧ/ᥪ)
vd  far UpdDataT(vd){

    //-----------------------------------------------------------------------
    // �맮� ����ணࠬ� ॣ���஢
    if( (Timer(1,18,1))==2 ){ RegRUN=1; }
    Reg_00();
    Reg_01();
    Reg_02();
    Reg_03();
    Reg_04();
    Reg_05();
    Reg_06();
    Reg_07();
    Reg_08();
    Reg_09();
    Reg_10();
    Reg_11();
    Reg_12();
    Reg_13();
    Reg_14();
    Reg_15();
    Signal();
    RegRUN=0;
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ����஫� ������ �� �� NetBIOS
    if(NBLive___M >0){
       NBLive___M =0; NBLive___V++; if(NBLive___V>8){ NBLive___V=1; }
       NBLiveTO_V =0; NBLF=1;CPLF=0;
    }
    //-----------------------------------
    // ����஫� ������ �� �� COM ����
    if(CPLive___M >0){
       CPLive___M =0; CPLive___V++; if(CPLive___V>8){ CPLive___V=1; }
       CPLiveTO_V =0; CPLF=1;NBLF=0;
    }
    NBLiveTO_V++; if(NBLiveTO_V>100){ NBLiveTO_V=100; }
    CPLiveTO_V++; if(CPLiveTO_V>100){ CPLiveTO_V=100; }
    //-----------------------------------------------------------------------
    // ��।�� ��६����� 横��� ࠡ��� �ணࠬ�� ����஫���
    TickLoop_V=TLoop;
    SecnLoop_V=SLoop;
    //-----------------------------------------------------------------------
    // ������ ������ �� ���
    if (WriteDataM>0){ WriteDataM=0; WriteData(0); Message(3); }
    //-----------------------------------------------------------------------
    // �஢�ઠ 䫠�� ������
    if (Bell(2)>0){ ErrBell__V=1; DONZVS___V=1; }
    // ��� 䫠�� ������
    if (ErrBell__M>0){ Bell(0); ErrBell__V=0; ErrBell__M=0; DONZVS___V=0; }
    //-----------------------------------------------------------------------
    // �뢮� � ��⠭���� �६��� � ����
    TimeCSS__V=secC; TimeCSM__V=minC; TimeCSH__V=houC;
    DateCSD__V=dayC; DateCSM__V=monC; DateCSY__V=yeaC;
    if(TMDTSet__M>0){
       secC=TimeCSS__M; minC=TimeCSM__M; houC=TimeCSH__M;
       dayC=DateCSD__M; monC=DateCSM__M; yeaC=DateCSY__M;
       SetTime(houC, minC, secC);
       SetDate(yeaC, monC, dayC); Message(12); TMDTSet__M=0;
    }
    //-----------------------------------------------------------------------
    // ��।�� ����� ⥪�饣� ᮮ�饭��
    if (FirstCall>PAMSG){
       if (CurMESSAGE!=nMESSAGE){ CurMESSAGE=nMESSAGE; }
    } else {
       MessageCLS();
    }
    //-----------------------------------------------------------------------
    // �᫨ ��।�� 䫠� ��室� �� �ணࠬ��
    if (ExitFlag_M>0){ ExitForLoad=ExitFlag_M; ExitFlag_M=0; }
    //-----------------------------------------------------------------------



    return;
}
//---------------------------------------------------------------------------
