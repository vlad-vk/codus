// coding=cp866
//---------------------------------------------------------------------------
//  ��।������ ⥪�饣� �६���
vd  far GetMTM(vd)
{
    GetTime(&houC, &minC, &secC);
    GetDate(&yeaC, &monC, &dayC);
    DAWC=WeekDay((int)yeaC, (int)(monC), (int)dayC);
//  printf("Y=%d M=%d D=%d\n", (int)yeaC,(int)monC,(int)dayC);
    smnC=GetCurSmn();
    HORC=houC;
    HMSmnC=(yeaC  *100+monC)*100+dayC+smnC; // ����� ⥪��� ��⮪
    HMDayC=(yeaC  *100+monC)*100+dayC;      // ����� ⥪�饣� ���
    HMHouC= HMDayC*100+houC;                // ����� ⥪�饣� ��
    DAWC1 = DAWC;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  ������ �㬬���� ���祭��
vd  far Time_01(vd)
{
    _i  a=0,b=0;                            // �६����� ��६�����
    _f  wd=DAWC;                            // ���� ������

    GetMTM();                               // ������� ⥪�饥 �६� � ����

    //-----------------------------------------------------------------------
    //  ������ ����� ᥪ㭤� 
    if (secC!=secO){

    //  ������ �।��� ���祭�� �� ������ ��� ���������� �������:

        // ��1 �������� ��� �� ��室� �� ��⥫쭨
        AIP201AVM =AAVerLoc( 1,AIP201___V,60,1);
        // ��1 �������� �������� �� �室� ⥯��������
        AIP202AVM =AAVerLoc( 2,AIP202___V,60,1);      
        // ��1 �������� ���� �� �室� ���
        AIP202AVM =AAVerLoc( 3,AIP202___V,60,1);      
        // ��1 ��室 ��� �� ��室� �� ��⥫쭨
        AIF301AVM =AAVerLoc( 4,AIF301___V,60,1);

        // ��1 ��室 �������� 1 �� �室� ⥯�����������
        AIF302AVM =AAVerLoc( 5,AIF302___V,60,1);
        // ��2 ��室 ��� �� ��室� �� ��⥫쭨
        AIF311AVM =AAVerLoc( 6,AIF311___V,60,1);
        // ��2 ��室 ��� �� ���஠�ॣ�� 2
        AIF321AVM =AAVerLoc( 7,AIF321___V,60,1);
        // ��2 ��室 �������� �� ��室� ⥯�������
        AIF322AVM =AAVerLoc( 8,AIF322___V,60,1);

        // ��2 �������� ��� �� ��室� �� ��⥫쭨
        AIP311AVM =AAVerLoc( 9,AIP311___V,60,1);
        // ��2 �������� ��� �� ���஠�ॣ�� 2
        AIP321AVM =AAVerLoc(10,AIP321___V,60,1);
        // ��2 �������� �������� �� �室� ⥯�������
        AIP322AVM =AAVerLoc(11,AIP322___V,60,1);
        // ��2 �������� ���� ��। ⥯�������
        AIP331AVM =AAVerLoc(12,AIP331___V,60,1);
        // ��2 �������� ���� ��। ���
        AIP34BAVM =AAVerLoc(13,AIP34B___V,60,1);
        // ��2 �������� ���� ��। ��⫮� 2
        AIP37BAVM =AAVerLoc(14,AIP37B___V,60,1);
        // ��1 �������� ���� ��। ��⫮� 1
        AIP38BAVM =AAVerLoc(15,AIP38B___V,60,1);
        // �� �������� ��� �� ⥯���㭪� 4
        AIP40BAVM =AAVerLoc(16,AIP40B___V,60,1);

        // �� ��室 ��� �� ⥯���㭪� 4
        AIF40VAVM =AAVerLoc(17,AIF40V___V,60,1);

        // ��1 � ��� �� ��室� �� ��⥫쭨
        AIT101AVM =AAVerLoc(18,AIT101___V,60,1);      
        // ��1 � �������� ��। ⥯�������
        AIT102AVM =AAVerLoc(19,AIT102___V,60,1);      
        // ��1 � ���� ��। ��������஬
        AIT103AVM =AAVerLoc(20,AIT103___V,60,1);      

        // ��1 � 宫 ���� ��। ⥯�������
        AIT104AVM =AAVerLoc(21,AIT104___V,60,1);      
        // ��1 � ��� ���� ��᫥ ⥯�������
        AIT105AVM =AAVerLoc(22,AIT105___V,60,1);
        // ��1 � ���� ��᫥ ���������
        AIT106AVM =AAVerLoc(23,AIT106___V,60,1);

        // ��2 � ��� �� ��室� �� ��⥫쭨
        AIT311AVM =AAVerLoc(24,AIT311___V,60,1);
        // ��2 � ��� �� ���஠�ॣ�� 2
        AIT321AVM =AAVerLoc(25,AIT321___V,60,1);
        // ��2 � �������� ��। ⥯�������
        AIT322AVM =AAVerLoc(26,AIT322___V,60,1);

        // ��2 � ���� ��। ⥯�������
        AIT331AVM =AAVerLoc(27,AIT331___V,60,1);
        // ��2 � ���� ��। ��⫮� 2
        AIT37AAVM =AAVerLoc(28,AIT37A___V,60,1);
        // ��1 � ���� ��। ��⫮� 1
        AIT38AAVM =AAVerLoc(29,AIT38A___V,60,1);

        // ��2 � ��� ���� �� ��4
        AIT332AVM =AAVerLoc(30,AIT332___V,60,1);
        // ��2 � ���� ��। ��������஬
        AIT421AVM =AAVerLoc(31,AIT421___V,60,1);
        // ��2 � ���� ��᫥ ���������
        AIT422AVM =AAVerLoc(32,AIT422___V,60,1);

    // ������ ᥪ㭤� ������ �ᮢ�� ���祭�� ��� �������� �������
    // (������� ���稪� ��室�)
    // � ��६����� AIFxxxHC___V ������������� ���祭�� ��室� �� ��

        // ��1 ��室 ���� �� ���
        if(AIF303_SZV<1){ AIF303_SZV=1; }
        //          ࠧ��� �����ᮢ /���.���.  * ���. ��� ���.���.
        AIF303___V=(AIF303VC-AIF303VO)/AIF303_SZV*AIF303_SDV;
        if(AIF303___V <0){ AIF303___V=0; }; AIF303HC_V=AIF303___V;
        // ��1 ��室 ����祩 ���� �� ��4
        if(AIF304_SZV<1){ AIF304_SZV=1; }
        AIF304___V=(AIF304VC-AIF304VO)/AIF304_SZV*AIF304_SDV;    
        if(AIF304___V <0){ AIF304___V=0; }; AIF304HC_V=AIF304___V;

        // ��2 ��室 ���� �� ⥯������� (��)
        if(AIF331_SZV<1){ AIF331_SZV=1; }
        AIF331___V=(AIF331VC-AIF331VO)/AIF331_SZV*AIF331_SDV;
        if(AIF331___V <0){ AIF331___V=0; }; AIF331HC_V=AIF331___V;
        // ��2 ��室 ��� ���� ��᫥ �� �� ��4
        if(AIF332_SZV<1){ AIF332_SZV=1; }
        AIF332___V=(AIF332VC-AIF332VO)/AIF332_SZV*AIF332_SDV;
        if(AIF332___V <0){ AIF332___V=0; }; AIF332HC_V=AIF332___V;

        // ��2 ��室 ���� ��। ���2
        if(AIF34V_SZV<1){ AIF34V_SZV=1; }
        AIF34V___V=(AIF34VVC-AIF34VVO)/AIF34V_SZV*AIF34V_SDV;
        if(AIF34V___V <0){ AIF34V___V=0; }; AIF34VHC_V=AIF34V___V;
        // ��2 ��室 ���� ��᫥ ���2 �� ��� ��⥫� 1
        if(AIF35V_SZV<1){ AIF35V_SZV=1; }
        AIF35V___V=(AIF35VVC-AIF35VVO)/AIF35V_SZV*AIF35V_SDV;
        if(AIF35V___V <0){ AIF35V___V=0; }; AIF35VHC_V=AIF35V___V;

        // ��2 ��室 ���� ��᫥ ���2 �� ��� ��⥫� 2
        if(AIF36V_SZV<1){ AIF36V_SZV=1; }
        AIF36V___V=(AIF36VVC-AIF36VVO)/AIF36V_SZV*AIF36V_SDV;
        if(AIF36V___V <0){ AIF36V___V=0; }; AIF36VHC_V=AIF36V___V;
        // �����
        AIX0C1___V=0;

        // ��2 ��室 ���� �� ��⥫ 2
        if(AIF37V_SZV<1){ AIF37V_SZV=1; }
        AIF37V___V=(AIF37VVC-AIF37VVO)/AIF37V_SZV*AIF37V_SDV;
        if(AIF37V___V <0){ AIF37V___V=0; }; AIF37VHC_V=AIF37V___V;
        // ��2 ��室 ���� �� ��⥫ 1
        if(AIF38V_SZV<1){ AIF38V_SZV=1; }
        AIF38V___V=(AIF38VVC-AIF38VVO)/AIF38V_SZV*AIF38V_SDV;
        if(AIF38V___V <0){ AIF38V___V=0; }; AIF38VHC_V=AIF38V___V;

        // ��1 ���� ⥯�� �� 4 �� (����뢠���� �� �ନ� ����)
        AIQ4TP_HCV=0;

        // ������� � ���ᨢ DBA[] ���� ��� ������� ��� ������ 
        DBA[wd].yeaC=(_f)yeaC;
        DBA[wd].monC=(_f)monC;
        DBA[wd].dayC=(_f)dayC;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    //  ������ ����� ������
    if (minC!=minO){

    //  ������ �।��� ���祭�� �� �� ��� ���������� �������:

        AIP201HC_V=AAVerLoc(33,AIP201AVM,60,1);  // K�1 P ��� �� ��� ��⥫
        AIP202HC_V=AAVerLoc(34,AIP202AVM,60,1);  // K�1 � ������� ��᫥ ⥯ ��
        AIP203HC_V=AAVerLoc(35,AIP203AVM,60,1);  // ��1 � ���� �� ���1
        AIF301HC_V=AAVerLoc(36,AIF301AVM,60,1);  // ��1 F ��� �� ��� ��⥫

//      ��� �஢�ન ���������� ���ᨢ�
//      for(x=0;x<63;x++) printf("[%2.2f]",VAV[36][x]); printf("\n");

        AIF302HC_V=AAVerLoc(37,AIF302AVM,60,1);  // ��1 F ������� ��। ⥯ ��
        AIF311HC_V=AAVerLoc(38,AIF311AVM,60,1);  // ��2 F ��� �� ��� ��⥫
        AIF321HC_V=AAVerLoc(39,AIF321AVM,60,1);  // ��2 F ��� �� ��� ��� 2
        AIF322HC_V=AAVerLoc(40,AIF322AVM,60,1);  // ��2 F ������� ��। ⥯ ��

        AIP311HC_V=AAVerLoc(41,AIP311AVM,60,1);  // K�2 P ��� �� ��� ��⥫
        AIP321HC_V=AAVerLoc(42,AIP321AVM,60,1);  // K�2 � ��� �� ��� ��� 2
        AIP322HC_V=AAVerLoc(43,AIP322AVM,60,1);  // K�2 � ������� ��। ⥯ ��
        AIP331HC_V=AAVerLoc(44,AIP331AVM,60,1);  // K�2 � ���� ��। ⥯ ��
        AIP34BHC_V=AAVerLoc(45,AIP34BAVM,60,1);  // K�2 � ���� ��। ���2  
        AIP37BHC_V=AAVerLoc(46,AIP37BAVM,60,1);  // K�2 � ���� ��। ��⫮� 2
        AIP38BHC_V=AAVerLoc(47,AIP38BAVM,60,1);  // K�1 � ���� ��। ��⫮� 1
        AIP40BHC_V=AAVerLoc(48,AIP40BAVM,60,1);  // K�: � ��� �� ��4

        AIF40VHC_V=AAVerLoc(49,AIF40VAVM,60,1);  // K�: F ��� �� ��4

        AIT101HC_V=AAVerLoc(50,AIT101AVM,60,1);  // ��1 � ��� �� ��室� �� ���
        AIT102HC_V=AAVerLoc(51,AIT102AVM,60,1);  // ��1 � ������� ��। ⥯ ��
        AIT103HC_V=AAVerLoc(52,AIT103AVM,60,1);  // ��1 � ���� ��। �������

        AIT104HC_V=AAVerLoc(53,AIT104AVM,60,1);  // ��1 � � ���� ��। ⥯ ��
        AIT105HC_V=AAVerLoc(54,AIT105AVM,60,1);  // ��1 � � ���� ��᫥ ⥯ ��
        AIT106HC_V=AAVerLoc(55,AIT106AVM,60,1);  // ��1 � ���� ��᫥ �������

        AIT311HC_V=AAVerLoc(56,AIT311AVM,60,1);  // ��2 � ��� �� ��室� �� ���
        AIT321HC_V=AAVerLoc(57,AIT321AVM,60,1);  // ��2 � ��� �� ��� ��� 2
        AIT322HC_V=AAVerLoc(58,AIT322AVM,60,1);  // ��2 � ������� ��। ⥯ ��

        AIT331HC_V=AAVerLoc(59,AIT331AVM,60,1);  // ��2 � ���� ��। ⥯ ���
        AIT37AHC_V=AAVerLoc(60,AIT37AAVM,60,1);  // ��2 � ���� ��। ��⫮� 2
        AIT38AHC_V=AAVerLoc(61,AIT38AAVM,60,1);  // ��1 � ���� ��। ��⫮� 1
        if(AIT38AHC_V>100) AIT38AHC_V=100;

        AIT332HC_V=AAVerLoc(62,AIT332AVM,60,1);  // ��2 � ��� ���� �� ��4
        AIT421HC_V=AAVerLoc(63,AIT421AVM,60,1);  // ��2 � ���� ��। �������
        AIT422HC_V=AAVerLoc(64,AIT422AVM,60,1);  // ��2 � ���� ��᫥ �������

        // ��1 ���� ⥯�� �� 4 �� (����뢠���� �� �ନ஢���� ����)
        AIQ4TP_HCV=0;

        //-------------------------------------------------------------------
        // ����� WRITE_DAT_PERIOD ����� �����뢠�� ����� 
        WriteFL++; if(WriteFL>=WRITE_DAT_PERIOD){ WriteDT1_M=1; WriteFL=0; }
        WriteFL__V=WriteFL;
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    //  ����� ���� ��
    if (houC!=houO){

        // 㢥����� ���祭�� ���稪�� ��室� �� ᬥ��, �� ��⪨ � �� �����
        // (��� ��室��):

        // 01. ��1 F ��� �� ��� ��⥫
        AIF301SC_V =AIF301SC_V+AIF301HC_V;       
        AIF301DC_V =AIF301DC_V+AIF301HC_V;          
        AIF301MC_V =AIF301MC_V+AIF301HC_V;          
        // 02. ��1 F ������� ��। ⥯ ��
        AIF302SC_V =AIF302SC_V+AIF302HC_V;       
        AIF302DC_V =AIF302DC_V+AIF302HC_V;
        AIF302MC_V =AIF302MC_V+AIF302HC_V;
        // 03. ��2 F ��� �� ��� ��⥫
        AIF311SC_V =AIF311SC_V+AIF311HC_V;
        AIF311DC_V =AIF311DC_V+AIF311HC_V;
        AIF311MC_V =AIF311MC_V+AIF311HC_V;
        // 04. ��2 F ��� �� ��� ��� 2
        AIF321SC_V =AIF321SC_V+AIF321HC_V;
        AIF321DC_V =AIF321DC_V+AIF321HC_V;
        AIF321MC_V =AIF321MC_V+AIF321HC_V;
        // 05. ��2 F ������� ��। ⥯ ��
        AIF322SC_V =AIF322SC_V+AIF322HC_V;
        AIF322DC_V =AIF322DC_V+AIF322HC_V;
        AIF322MC_V =AIF322MC_V+AIF322HC_V;

        // 06. ��1 F 宫 ���� �� ���1
        AIF303SC_V =AIF303SC_V+AIF303HC_V;       
        AIF303DC_V =AIF303DC_V+AIF303HC_V;
        AIF303MC_V =AIF303MC_V+AIF303HC_V;          
        // 07. ��1 F ��� ���� �� ��4
        AIF304SC_V =AIF304SC_V+AIF304HC_V;       
        AIF304DC_V =AIF304DC_V+AIF304HC_V;
        AIF304MC_V =AIF304MC_V+AIF304HC_V;

        // 08. ��2 F 宫 ���� �� ⥯ ���
        AIF331SC_V =AIF331SC_V+AIF331HC_V;       
        AIF331DC_V =AIF331DC_V+AIF331HC_V;
        AIF331MC_V =AIF331MC_V+AIF331HC_V;          
        // 09. ��2 F ��� ���� �� ��4
        AIF332SC_V =AIF332SC_V+AIF332HC_V;       
        AIF332DC_V =AIF332DC_V+AIF332HC_V;
        AIF332MC_V =AIF332MC_V+AIF332HC_V;

        // 10. ��2 F ���� ��। ���2
        AIF34VSC_V =AIF34VSC_V+AIF34VHC_V;       
        AIF34VDC_V =AIF34VDC_V+AIF34VHC_V;
        AIF34VMC_V =AIF34VMC_V+AIF34VHC_V;
        // 11. ��2 F ���� ��᫥ ���2 �� ��� ��⫠ 1
        AIF35VSC_V =AIF35VSC_V+AIF35VHC_V;       
        AIF35VDC_V =AIF35VDC_V+AIF35VHC_V;
        AIF35VMC_V =AIF35VMC_V+AIF35VHC_V;

        // 12. ��2 F ���� ��᫥ ���2 �� ��� ��⫠ 2
        AIF36VSC_V =AIF36VSC_V+AIF36VHC_V;       
        AIF36VDC_V =AIF36VDC_V+AIF36VHC_V;
        AIF36VMC_V =AIF36VMC_V+AIF36VHC_V;
        // 13. �����
        AIX0C1SC_V =0;
        AIX0C1DC_V =0;
        AIX0C1MC_V =0;
         
        // 14. ��2 F ���� �� ��⥫ 2
        AIF37VSC_V =AIF37VSC_V+AIF37VHC_V;       
        AIF37VDC_V =AIF37VDC_V+AIF37VHC_V;
        AIF37VMC_V =AIF37VMC_V+AIF37VHC_V;
        // 15. ��2 F ���� �� ��⥫ 1
        AIF38VSC_V =AIF38VSC_V+AIF38VHC_V;       
        AIF38VDC_V =AIF38VDC_V+AIF38VHC_V;
        AIF38VMC_V =AIF38VMC_V+AIF38VHC_V;

        // 16. ����� �� ��4 (����뢠���� �� �ନ஢���� ����)
        AIQ4TP_SCV =0;
        AIQ4TP_DCV =0;
        AIQ4TP_MCV =0;

        // �����  ���� ������ (wd-WeekDay)
        // �����뢠�� � �������� DBA[] ���祭�� ����஫��㥬�� ��ଥ�஢ ��� ������� ��(HORC)
        if(HORC==0){ HORC=24; wd=DAWP; }; HORC=HORC-1;

        //-------------------------------------------------------------------- 
        // ���冷� ᫥������� ��६����� ⠪�� ��, ��� � 䠩�� codus_cl.ini
        // (���ᨢ DBB[ BEGP + RECL + 0..<PARM(24) + 1..<HORC(24) ])

        DBA[wd].pr[ 0].data[HORC]=AIF301HC_V;    // 00. ��1 F ��� �� ��� ��⥫
        DBA[wd].pr[ 1].data[HORC]=AIF302HC_V;    // 01. ��1 F ������� ��। ⥯ ��
        DBA[wd].pr[ 2].data[HORC]=AIF311HC_V;    // 02. ��2 F ��� �� ��� ��⥫
        DBA[wd].pr[ 3].data[HORC]=AIF321HC_V;    // 03. ��2 F ��� �� ��� ��� 2
        DBA[wd].pr[ 4].data[HORC]=AIF322HC_V;    // 04. ��2 F ������� ��। ⥯ ��
        DBA[wd].pr[ 5].data[HORC]=AIF303HC_V;    // 05. ��1 F 宫 ���� �� ���1
        DBA[wd].pr[ 6].data[HORC]=AIF304HC_V;    // 06. ��1 F ��� ���� �� ��4
        DBA[wd].pr[ 7].data[HORC]=AIF331HC_V;    // 07. ��2 F 宫 ���� �� ⥯ ���
        DBA[wd].pr[ 8].data[HORC]=AIF332HC_V;    // 08. ��2 F ��� ���� �� ��4
        DBA[wd].pr[ 9].data[HORC]=AIF34VHC_V;    // 09. ��2 F ���� ��। ���2
        DBA[wd].pr[10].data[HORC]=AIF35VHC_V;    // 10. ��2 F ���� ��᫥ ���2 �� ��� ��⫠ 1
        DBA[wd].pr[11].data[HORC]=AIF36VHC_V;    // 11. ��2 F ���� ��᫥ ���2 �� ��� ��⫠ 2
        DBA[wd].pr[12].data[HORC]=AIX0C1HC_V;    // 12. ��2 ����� �� ��4 (��� �� �� ����)
        DBA[wd].pr[13].data[HORC]=AIF37VHC_V;    // 13. ��2 F ���� �� ��⥫ 2
        DBA[wd].pr[14].data[HORC]=AIF38VHC_V;    // 14. ��2 F ���� �� ��⥫ 1
        DBA[wd].pr[15].data[HORC]=AIQ4TP_HCV;    // 15. ��1 ����� �� ��4 (��� �� �� ����)

        // 16. K�1 �����⠭�� ��室 ���� 
        // (��� ��ॢ��� �� � ��� ⥪�饥 ���祭�� P 㬭����� �� 0.1,
        //  0.101325 - ��ଠ�쭮�(����⠭�) �⬮��୮� �������� � ���)
        DBA[wd].pr[16].data[HORC]=
                MDivF(AIF38VHC_V*(AIP38BHC_V*0.1+0.101325)*293.15,((273.15+AIT38AHC_V)*0.101325*0.985));
        DBA[wd].pr[17].data[HORC]=AIP38BHC_V;    // 17. ��1 P ����
        DBA[wd].pr[18].data[HORC]=AIT38AHC_V;    // 18. ��1 � ����
        DBA[wd].pr[19].data[HORC]=0;             // 19. K�1 F ���� 㤥��� ��⠥��� �� �ନ� ����

        // 20. K�2 �����⠭�� ��室 ����
        DBA[wd].pr[20].data[HORC]=
                MDivF(AIF37VHC_V*(AIP37BHC_V*0.1+0.101325)*293.15,((273.15+AIT37AHC_V)*0.101325*0.985));
        DBA[wd].pr[21].data[HORC]=AIP37BHC_V;    // 21. ��1 P ����
        DBA[wd].pr[22].data[HORC]=AIT37AHC_V;    // 22. ��1 � ����
        DBA[wd].pr[23].data[HORC]=0;             // 23. K�2 F ���� 㤥��� ��⠥��� �� �ନ� ����
        
        DBA[wd].pr[24].data[HORC]=AIT102HC_V;    // 24. ��1 � ��������
        DBA[wd].pr[25].data[HORC]=AIT104HC_V;    // 25. ��1 � ���� ��    ⥯�����������
        DBA[wd].pr[26].data[HORC]=AIT105HC_V;    // 26. ��1 � ���� ��᫥ ⥯�����������
        DBA[wd].pr[27].data[HORC]=AIT322HC_V;    // 27. ��2 � ��������
        DBA[wd].pr[28].data[HORC]=AIT331HC_V;    // 28. ��2 � ���� ��    ⥯�����������
        DBA[wd].pr[29].data[HORC]=AIT332HC_V;    // 29. ��2 � ���� ��᫥ ⥯�����������

        //-------------------------------------------------------------------- 

        // ���㫥��� �ᮢ�� ���祭�� �������� ���稪��
        AIF303VO=AIF303VC; AIF303___V=0; AIF303HC_V=0;
        AIF304VO=AIF304VC; AIF304___V=0; AIF304HC_V=0;

        AIF331VO=AIF331VC; AIF331___V=0; AIF331HC_V=0;
        AIF332VO=AIF332VC; AIF332___V=0; AIF332HC_V=0;

        AIF34VVO=AIF34VVC; AIF34V___V=0; AIF34VHC_V=0;
        AIF35VVO=AIF35VVC; AIF35V___V=0; AIF35VHC_V=0;

        AIF36VVO=AIF36VVC; AIF36V___V=0; AIF36VHC_V=0;
        AIX0C1VO=AIX0C1VC; AIX0C1___V=0; AIX0C1HC_V=0;

        AIF37VVO=AIF37VVC; AIF37V___V=0; AIF37VHC_V=0;
        AIF38VVO=AIF38VVC; AIF38V___V=0; AIF38VHC_V=0;

        // ��������� ���� ������ ��� ��� ��������� �� ��᫥���� �� ��⮪
        // (����� 0 �ᮢ-�� 㦥 ᫥���騩 ���� ������,� �㦥� �� �।��騩)
        DAWP=DAWC;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ������ ����� ᬥ��
    if (smnC!=smnO){
       // ��।��� ���祭�� � ��६���� �।��饩 ᬥ�� � ���㫨�� ⥪�騥
       AIF301SO_V=AIF301SC_V; AIF301SC_V=0;
       AIF302SO_V=AIF302SC_V; AIF302SC_V=0;
       AIF311SO_V=AIF311SC_V; AIF311SC_V=0;
       AIF321SO_V=AIF321SC_V; AIF321SC_V=0;
       AIF322SO_V=AIF322SC_V; AIF322SC_V=0;
       AIF303SO_V=AIF303SC_V; AIF303SC_V=0;
       AIF304SO_V=AIF304SC_V; AIF304SC_V=0;
       AIF331SO_V=AIF331SC_V; AIF331SC_V=0;
       AIF332SO_V=AIF332SC_V; AIF332SC_V=0;
       AIF34VSO_V=AIF34VSC_V; AIF34VSC_V=0;
       AIF35VSO_V=AIF35VSC_V; AIF35VSC_V=0;
       AIF36VSO_V=AIF36VSC_V; AIF36VSC_V=0;
       AIX0C1SO_V=AIX0C1SC_V; AIX0C1SC_V=0;
       AIF37VSO_V=AIF37VSC_V; AIF37VSC_V=0;
       AIF38VSO_V=AIF38VSC_V; AIF38VSC_V=0;
       AIQ4TP_SOV=AIQ4TP_SCV; AIQ4TP_SCV=0;
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //  ����� ���� ��⪨
    if (dayC!=dayO){
        //--------------------------------------------------------------------
        // ��७��� ����� ��� ��� ��襤�� ��⮪ �
        // ���㫨�� ���稪� ⥪��� ��⮪
        AIF301DO_V=AIF301DC_V; AIF301DC_V=0;
        AIF302DO_V=AIF302DC_V; AIF302DC_V=0;
        AIF311DO_V=AIF311DC_V; AIF311DC_V=0;
        AIF321DO_V=AIF321DC_V; AIF321DC_V=0;
        AIF322DO_V=AIF322DC_V; AIF322DC_V=0;
        AIF303DO_V=AIF303DC_V; AIF303DC_V=0;
        AIF304DO_V=AIF304DC_V; AIF304DC_V=0;
        AIF331DO_V=AIF331DC_V; AIF331DC_V=0;
        AIF332DO_V=AIF332DC_V; AIF332DC_V=0;
        AIF34VDO_V=AIF34VDC_V; AIF34VDC_V=0;
        AIF35VDO_V=AIF35VDC_V; AIF35VDC_V=0;
        AIF36VDO_V=AIF36VDC_V; AIF36VDC_V=0;
        AIX0C1DO_V=AIX0C1DC_V; AIX0C1DC_V=0;
        AIF37VDO_V=AIF37VDC_V; AIF37VDC_V=0;
        AIF38VDO_V=AIF38VDC_V; AIF38VDC_V=0;
        AIQ4TP_DOV=AIQ4TP_DCV; AIQ4TP_DCV=0;
        // ���㫨�� �� ������� ��⭮�� ��ࠬ���� �ᮢ� ����� �� ��⪨
        //(����塞 ����� �������� DBA[] ��� ����� ��⮪)
        // DAWC ����� ���� != wd
        for(a=0;a<PARM;a++){
            for(b=0;b<RECL;b++){ DBA[DAWC].pr[a].data[b]=0; }
        }
    }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //  ����� ���� �����
    if (monC!=monO){
        // ��७��� ����� ��� ��� ��襤襣� ����� �
        // ���㫨�� ���稪� ⥪�饣� �����
        AIF301MO_V=AIF301MC_V; AIF301MC_V=0;
        AIF302MO_V=AIF302MC_V; AIF302MC_V=0;
        AIF311MO_V=AIF311MC_V; AIF311MC_V=0;
        AIF321MO_V=AIF321MC_V; AIF321MC_V=0;
        AIF322MO_V=AIF322MC_V; AIF322MC_V=0;
        AIF303MO_V=AIF303MC_V; AIF303MC_V=0;
        AIF304MO_V=AIF304MC_V; AIF304MC_V=0;
        AIF331MO_V=AIF331MC_V; AIF331MC_V=0;
        AIF332MO_V=AIF332MC_V; AIF332MC_V=0;
        AIF34VMO_V=AIF34VMC_V; AIF34VMC_V=0;
        AIF35VMO_V=AIF35VMC_V; AIF35VMC_V=0;
        AIF36VMO_V=AIF36VMC_V; AIF36VMC_V=0;
        AIX0C1MO_V=AIX0C1MC_V; AIX0C1MC_V=0;
        AIF37VMO_V=AIF37VMC_V; AIF37VMC_V=0;
        AIF38VMO_V=AIF38VMC_V; AIF38VMC_V=0;
        AIQ4TP_MOV=AIQ4TP_MCV; AIQ4TP_MCV=0;
    }
    //-----------------------------------------------------------------------

    secO=secC; minO=minC; houO=houC; smnO=smnC;
    dayO=dayC; monO=monC; yeaO=yeaC;
    DAWO=DAWC;
    HMDayO=HMDayC; HMHouO=HMHouC; HMSmnO=HMSmnC;

    //-----------------------------------------------------------------------
    // �뢮� � ��⠭���� �६��� � ����
       TimeCSS1_V=secC; TimeCSM1_V=minC; TimeCSH1_V=houC;
       DateCSD1_V=dayC; DateCSM1_V=monC; DateCSY1_V=yeaC;
    if(TMDTSet1_M>0){
       secC=TimeCSS1_M; 
       minC=TimeCSM1_M; 
       houC=TimeCSH1_M;
       dayC=DateCSD1_M; 
       monC=DateCSM1_M; 
       yeaC=DateCSY1_M;
       SetTime(houC, minC, secC);
       SetDate(yeaC, monC, dayC); 
       Message(12,0); TMDTSet1_M=0;
    }
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// ��।����� ���祭��
// NV - ����� ��६����� � ���ᨢ� ��।�����
// CV - ⥪�饥 ���祭��
// TF - ������⢮ �祥� ��।�����
// md - ०�� �㭪樨 (2-���� ������ ���祭�� �� ���ᨢ� ��� ��ࠡ�⪨ ⥪�饣�,0-���㫨��)
// VAV[NV][MAXCN+0]-⥪�饥 ��।������ ���祭��, VAV[NV][MAXCN+1]-����� ��᫥���� �祩��
_f far AAVerLoc(_i NV, _f CV, _i TF, _i md){
   _i  a=0,b=0;
   // �᫨ ����� ��६����� ����� ���� ��।��������- ������ ⥪ ���祭��
   if (NV>MAXNV||NV<0){ 
       return (CV); 
   }
   // � ०��� 0- ���㫨�� �祩�� ��।����� ⥪�饩 ��६�����
   if (md==0){ 
       VAV[NV][MAXCN]=0; VAV[NV][MAXCN+1]=0; VAV[NV][MAXCN+2]=0;
       for(b=0; b<MAXCN; b++){ VAV[NV][b]=0; }
       return (CV);
   }
   // � ०��� 2- ������ ���祭�� �� ���ᨢ�
   if (md==2){ return(VAV[NV][MAXCN]); }
   // � ०��� 1- �뢥�� ⥪�饥 �।��� ���祭��
   // �᫨ �� ���室 �१ ���ᨬ����� �祩��, � �।��� ��⠥��� �� �ᥬ �祩���,
   // �᫨ ���室� �� �뫮, � ⮫쪮 �� ⥪�饩
   if (VAV[NV][MAXCN+2]>0) a=TF; else  a=VAV[NV][MAXCN+1]+1;
   // �᫨ ⥪ ���� ��ࠬ��� ����� 0 - ��⠭����� ���= 0
   if (CV<0){ CV=0; }
   // ��������� ⥪�饥 ���祭�� � �祩�� ���ᨢ� ��।�����
   VAV[NV][ VAV[NV][MAXCN+1] ]= CV;
   // ������� �㬬�୮� ���祭�� � �祩��� ���ᨢ� ��।�����
   VAV[NV][MAXCN]=0;
   for(b=0; b<a; b++){ VAV[NV][MAXCN]=VAV[NV][MAXCN]+VAV[NV][b]; }
   // ������� �।��� ���祭�� �� �㬬�୮��
   VAV[NV][MAXCN]=MDivF(VAV[NV][MAXCN],a);
   // �஢�ઠ �࠭�� ��� � ���� ���祭��
   if(VAV[NV][MAXCN]<0) VAV[NV][MAXCN]=0; if(VAV[NV][MAXCN]>200000000) VAV[NV][MAXCN]=200000000;
   // ����� ��᫥���� ���ᨬ��쭮� �祩��, ���� �� ��諨 �� ���ᨬ��쭮���������
   if (VAV[NV][MAXCN+1]< TF-1){ VAV[NV][MAXCN+1]++; }
   // �᫨ ��������� ���ᨢ(��諨 �� ���ᨬ��쭮� �祩��) - �����頥��� � �㫥���
   // �த������ ��������� ���ᨢ �  �㫥��� �祩��
   else { VAV[NV][MAXCN+1]=0; VAV[NV][MAXCN+2]=1; }
   // ������ � �ணࠬ�� �।��� ���祭�� 㪠������� ��ࠬ���
   return(VAV[NV][MAXCN]);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  ������� ����� ⥪�饩 ᬥ��
_i  far GetCurSmn(vd){
    _i  s=0;
    if (houC>= 0){ s=1; }
    if (houC>= 8){ s=2; }
    if (houC>=16){ s=3; }
    return(s);
}
//---------------------------------------------------------------------------

