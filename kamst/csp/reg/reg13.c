//---------------------------------------------------------------------------
// ���室 �����⪮���� ������ �� 2 ������

//---------------------------------------------------------------------------
vd  far Reg_13(vd){
    //-----------------------------------------------------------------------
    ui RN=13;                              // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=100.00;                          // �室��� 誠�� (������ �࠭��) 
    _f OL=0.000;                           // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                           // ��室��� 誠�� (������),%, �.��.
    _f DM=10.00;                           // ���� ���� ��� ॣ����      
    _f ZN=IH*0.001;                        // ���� �����⢨⥫쭮��          
    _f PR=20.00;                           // ��業� ��ᮣ��ᮢ����         
    ui CC=20;                              // ����஫�� 横�                
    ui TP=1;                               // ��� ॣ����                  
    _f KRZ=0;                              // ���४�஢�� �������
    //-----------------------------------------------------------------------
    // �஢�ઠ ����������
    if (AOFIM2S_RM!=AOFIM2S_RV){ 
        AOFIM2S_RV =AOFIM2S_RM; 
        if(AOFIM2S_RV>0){ Message(124); }
        else            { Message(125); AOFIM2S_OM=AOFIM2S_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ���४��
    AOFIM2SZKV=AOFIM2SZKM;                  // ������� ���४樨
    AOFIM2SPKV=AOFIM2SPKM;                  // ��業� ���४樨 (ᮮ⭮襭��)
    // ����祭��-�몫�祭�� ���४樨
    if(AOFIM2SRKM==SWITCH){
       AOFIM2SRKV=(AOFIM2SRKV==ON) then_ OFF else_ ON;  AOFIM2SRKM = OFF;
    }
    // ��室 ���४樨
    AOFIM2SOKV=-((AOFIM2SZKV-AIFSD2S__V)*AOFIM2SPKV);
    // �᫨ ���४�� �몫�祭�- ��室 ���४樨 ࠢ�� 0
    if(AOFIM2SRKV==OFF){ KRZ=0; }
    else               { KRZ=AOFIM2SOKV; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOFIM2S_ZM <  IL         ){ AOFIM2S_ZM = IL; }
    if (AOFIM2S_ZM >  AIFIM2SAMV ){ AOFIM2S_ZM = AIFIM2SAMV; }
    AOFIM2S_ZV =  AOFIM2S_ZM;
    // ������� � ��⮬ ���४樨
    AOFIM2SZNV =  AOFIM2S_ZV+KRZ;
    if (AOFIM2SZNV <  IL         ){ AOFIM2SZNV = IL; }
    if (AOFIM2SZNV >  AIFIM2SAMV ){ AOFIM2SZNV = AIFIM2SAMV; }
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOFIM2S_OM < 0  ){ AOFIM2S_OM =0;   }
    if (AOFIM2S_OM > 100){ AOFIM2S_OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOFIM2SLOV =AOFIM2SLOM;
    AOFIM2SHOV =AOFIM2SHOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOFIM2SLPV =AOFIM2SLPM;
    AOFIM2SHPV =AOFIM2SHPM;
    // �����樥��� ॣ����
    AOFIM2S_PV =AOFIM2S_PM;
    AOFIM2S_IV =AOFIM2S_IM;
    AOFIM2S_DV =AOFIM2S_DM;
    AOFIM2S_MV =AOFIM2S_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOFIM2S_OV=Regulator(RN, AIFIM2S__V,
                              AOFIM2S_PV, AOFIM2S_IV, AOFIM2S_DV, AOFIM2S_MV,
                              AOFIM2S_OM, AOFIM2S_RV,
                              AOFIM2SZNV, AOFIM2SZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOFIM2S_OV <  OL+AOFIM2SLOV){ AOFIM2S_OV=OL+AOFIM2SLOV; }
       if (AOFIM2S_OV >  OH-AOFIM2SHOV){ AOFIM2S_OV=OH-AOFIM2SHOV; }
       if (AOFIM2S_MV >= 0){ AOFIM2SOOV=100-AOFIM2S_OV; }
       else                { AOFIM2SOOV=AOFIM2S_OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
