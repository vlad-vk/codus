//---------------------------------------------------------------------------
// � 䨫��஢������ ᮪� 1 ����樨

//---------------------------------------------------------------------------
vd  far Reg_08(vd){
    //-----------------------------------------------------------------------
    ui RN=8;                               // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=100;                             // �室��� 誠�� (������ �࠭��) 
    _f OL=0.000;                           // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                           // ��室��� 誠�� (������),%, �.��.
    _f DM=10.00;                           // ���� ���� ��� ॣ����      
    _f ZN=IH*0.001;                        // ���� �����⢨⥫쭮��          
    _f PR=20.00;                           // ��業� ��ᮣ��ᮢ����         
    ui CC=20;                              // ����஫�� 横�                
    ui TP=1;                               // ��� ॣ����                  
    //-----------------------------------------------------------------------
    // �஢�ઠ ����������
    if (AOTFS1S_RM!=AOTFS1S_RV){ 
        AOTFS1S_RV =AOTFS1S_RM; 
        if(AOTFS1S_RV>0){ Message(114); }
        else            { Message(115); AOTFS1S_OM=AOTFS1S_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOTFS1S_ZM <  IL         ){ AOTFS1S_ZM = IL; }
    if (AOTFS1S_ZM >  AITF1P_AMV ){ AOTFS1S_ZM = AITF1P_AMV; }
        AOTFS1S_ZV =  AOTFS1S_ZM;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOTFS1S_OM < 0  ){ AOTFS1S_OM =0;   }
    if (AOTFS1S_OM > 100){ AOTFS1S_OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOTFS1SLOV =AOTFS1SLOM;
    AOTFS1SHOV =AOTFS1SHOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOTFS1SLPV =AOTFS1SLPM;
    AOTFS1SHPV =AOTFS1SHPM;
    // �����樥��� ॣ����
    AOTFS1S_PV =AOTFS1S_PM;
    AOTFS1S_IV =AOTFS1S_IM;
    AOTFS1S_DV =AOTFS1S_DM;
    AOTFS1S_MV =AOTFS1S_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOTFS1S_OV=Regulator(RN, AITF1P___V,
                              AOTFS1S_PV, AOTFS1S_IV, AOTFS1S_DV, AOTFS1S_MV,
                              AOTFS1S_OM, AOTFS1S_RV,
                              AOTFS1S_ZV, AOTFS1S_ZV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOTFS1S_OV <  OL+AOTFS1SLOV){ AOTFS1S_OV=OL+AOTFS1SLOV; }
       if (AOTFS1S_OV >  OH-AOTFS1SHOV){ AOTFS1S_OV=OH-AOTFS1SHOV; }
       if (AOTFS1S_MV >= 0){ AOTFS1SOOV=100-AOTFS1S_OV; }
       else                { AOTFS1SOOV=AOTFS1S_OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------