//---------------------------------------------------------------------------
// ���室 ��ᯥ���� �� �।��䥪��� �ਣ���-���

//---------------------------------------------------------------------------
vd  far Reg_14(vd){
    //-----------------------------------------------------------------------
    ui RN=14;                              // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=40.00;                           // �室��� 誠�� (������ �࠭��) 
    _f OL=0.000;                           // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                           // ��室��� 誠�� (������),%, �.��.
    _f DM=10.00;                           // ���� ���� ��� ॣ����      
    _f ZN=IH*0.001;                        // ���� �����⢨⥫쭮��          
    _f PR=20.00;                           // ��業� ��ᮣ��ᮢ����         
    ui CC=20;                              // ����஫�� 横�                
    ui TP=1;                               // ��� ॣ����                  
    _f KRZ=0;                              // ���४�஢�� �������
    //-----------------------------------------------------------------------
    if (AOFSPBM_RM!=AOFSPBM_RV){ 
        AOFSPBM_RV =AOFSPBM_RM; 
        if(AOFSPBM_RV>0){ Message(126); }
        else            { Message(127); AOFSPBM_OM=AOFSPBM_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ���४��
    AOFSPBMZKV=AOFSPBMZKM;                  // ������� ���४樨
    AOFSPBMPKV=AOFSPBMPKM;                  // ��業� ���४樨 (ᮮ⭮襭��)
    // ����祭��-�몫�祭�� ���४樨
    if(AOFSPBMRKM==SWITCH){
       AOFSPBMRKV=(AOFSPBMRKV==ON) then_ OFF else_ ON;  AOFSPBMRKM = OFF;
    }
    // ��室 ���४樨
    AOFSPBMOKV=-((AOFSPBMZKV-AIFSD2S__V)*AOFSPBMPKV);
    // �᫨ ���४�� �몫�祭�- ��室 ���४樨 ࠢ�� 0
    if(AOFSPBMRKV==OFF){ KRZ=0; }
    else               { KRZ=AOFSPBMOKV; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOFSPBM_ZM <  IL         ){ AOFSPBM_ZM = IL; }
    if (AOFSPBM_ZM >  AIFSP2SAMV ){ AOFSPBM_ZM = AIFSP2SAMV; }
    AOFSPBM_ZV =  AOFSPBM_ZM;
    // ������� � ��⮬ ���४樨
    AOFSPBMZNV =  AOFSPBM_ZV+KRZ;
    if (AOFSPBMZNV <  IL         ){ AOFSPBMZNV = IL; }
    if (AOFSPBMZNV >  AIFSP2SAMV ){ AOFSPBMZNV = AIFSP2SAMV; }
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOFSPBM_OM < 0  ){ AOFSPBM_OM =0;   }
    if (AOFSPBM_OM > 100){ AOFSPBM_OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOFSPBMLOV =AOFSPBMLOM;
    AOFSPBMHOV =AOFSPBMHOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOFSPBMLPV =AOFSPBMLPM;
    AOFSPBMHPV =AOFSPBMHPM;
    // �����樥��� ॣ����
    AOFSPBM_PV =AOFSPBM_PM;
    AOFSPBM_IV =AOFSPBM_IM;
    AOFSPBM_DV =AOFSPBM_DM;
    AOFSPBM_MV =AOFSPBM_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOFSPBM_OV=Regulator(RN, AIFSP2S__V,
                              AOFSPBM_PV, AOFSPBM_IV, AOFSPBM_DV, AOFSPBM_MV,
                              AOFSPBM_OM, AOFSPBM_RV,
                              AOFSPBMZNV, AOFSPBMZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOFSPBM_OV <  OL+AOFSPBMLOV){ AOFSPBM_OV=OL+AOFSPBMLOV; }
       if (AOFSPBM_OV >  OH-AOFSPBMHOV){ AOFSPBM_OV=OH-AOFSPBMHOV; }
       if (AOFSPBM_MV >= 0){ AOFSPBMOOV=100-AOFSPBM_OV; }
       else                { AOFSPBMOOV=AOFSPBM_OV; }
//     ��� ���
//     AOFSPBMOOV=AOFSPBM_OV;
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
