//---------------------------------------------------------------------------
// ���室 ᮪� ������ 1 ����樨

//---------------------------------------------------------------------------
vd  far Reg_12(vd){
    //-----------------------------------------------------------------------
    ui RN=12;                              // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=80;                              // �室��� 誠�� (������ �࠭��) 
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
    if (AOFSVZ__RM!=AOFSVZ__RV){ 
        AOFSVZ__RV =AOFSVZ__RM; 
        if(AOFSVZ__RV>0){ Message(122); }
        else            { Message(123); AOFSVZ__OM=AOFSVZ__OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ���४��
    AOFSVZ_ZKV=AOFSVZ_ZKM;                  // ������� ���४樨
    AOFSVZ_PKV=AOFSVZ_PKM;                  // ��業� ���४樨 (ᮮ⭮襭��)
    // ����祭��-�몫�祭�� ���४樨
    if(AOFSVZ_RKM==SWITCH){
       AOFSVZ_RKV=(AOFSVZ_RKV==ON) then_ OFF else_ ON;  AOFSVZ_RKM = OFF;
    }
    // ��室 ���४樨
    AOFSVZ_OKV=-((AOFSVZ_ZKV-AIFDFS___V)*AOFSVZ_PKV);
    // �᫨ ���४�� �몫�祭�- ��室 ���४樨 ࠢ�� 0
    if(AOFSVZ_RKV==OFF){ KRZ=0; }
    else               { KRZ=AOFSVZ_OKV; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOFSVZ__ZM <  IL         ){ AOFSVZ__ZM = IL; }
    if (AOFSVZ__ZM >  AIFSVZ_AMV ){ AOFSVZ__ZM = AIFSVZ_AMV; }
    AOFSVZ__ZV =  AOFSVZ__ZM;
    // ������� � ��⮬ ���४樨
    AOFSVZ_ZNV =  AOFSVZ__ZV+KRZ;
    if (AOFSVZ_ZNV <  IL         ){ AOFSVZ_ZNV = IL; }
    if (AOFSVZ_ZNV >  AIFSVZ_AMV ){ AOFSVZ_ZNV = AIFSVZ_AMV; }
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOFSVZ__OM < 0  ){ AOFSVZ__OM =0;   }
    if (AOFSVZ__OM > 100){ AOFSVZ__OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOFSVZ_LOV =AOFSVZ_LOM;
    AOFSVZ_HOV =AOFSVZ_HOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOFSVZ_LPV =AOFSVZ_LPM;
    AOFSVZ_HPV =AOFSVZ_HPM;
    // �����樥��� ॣ����
    AOFSVZ__PV =AOFSVZ__PM;
    AOFSVZ__IV =AOFSVZ__IM;
    AOFSVZ__DV =AOFSVZ__DM;
    AOFSVZ__MV =AOFSVZ__MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOFSVZ__OV=Regulator(RN, AIFSVZ___V,
                              AOFSVZ__PV, AOFSVZ__IV, AOFSVZ__DV, AOFSVZ__MV,
                              AOFSVZ__OM, AOFSVZ__RV,
                              AOFSVZ_ZNV, AOFSVZ_ZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOFSVZ__OV <  OL+AOFSVZ_LOV){ AOFSVZ__OV=OL+AOFSVZ_LOV; }
       if (AOFSVZ__OV >  OH-AOFSVZ_HOV){ AOFSVZ__OV=OH-AOFSVZ_HOV; }
       if (AOFSVZ__MV >= 0){ AOFSVZ_OOV=100-AOFSVZ__OV; }
       else                { AOFSVZ_OOV=AOFSVZ__OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
