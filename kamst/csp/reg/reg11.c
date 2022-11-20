//---------------------------------------------------------------------------
// ���室 �����⪮���� ������ �� �᭮���� ��䥪���

//---------------------------------------------------------------------------
vd  far Reg_11(vd){
    //-----------------------------------------------------------------------
    ui RN=11;                              // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=140.00;                           // �室��� 誠�� (������ �࠭��) 
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
    if (AOFIMOD_RM!=AOFIMOD_RV){ 
        AOFIMOD_RV =AOFIMOD_RM; 
        if(AOFIMOD_RV>0){ Message(120); }
        else            { Message(121); AOFIMOD_OM=AOFIMOD_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ���४��
    AOFIMODZKV=AOFIMODZKM;                  // ������� ���४樨
    AOFIMODPKV=AOFIMODPKM;                  // ��業� ���४樨 (ᮮ⭮襭��)
    // ����祭��-�몫�祭�� ���४樨
    if(AOFIMODRKM==SWITCH){
       AOFIMODRKV=(AOFIMODRKV==ON) then_ OFF else_ ON;  AOFIMODRKM = OFF;
    }
    // ��室 ���४樨
    AOFIMODOKV=-((AOFIMODZKV-AIFDFS___V)*AOFIMODPKV);
    // �᫨ ���४�� �몫�祭�- ��室 ���४樨 ࠢ�� 0
    if(AOFIMODRKV==OFF){ KRZ=0; }
    else               { KRZ=AOFIMODOKV; }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOFIMOD_ZM <  IL         ){ AOFIMOD_ZM = IL; }
    if (AOFIMOD_ZM >  AIFIMBMAMV ){ AOFIMOD_ZM = AIFIMBMAMV; }
    AOFIMOD_ZV =  AOFIMOD_ZM;
    // ������� � ��⮬ ���४樨
    AOFIMODZNV =  AOFIMOD_ZV+KRZ;
    if (AOFIMODZNV <  IL         ){ AOFIMODZNV = IL; }
    if (AOFIMODZNV >  AIFIMBMAMV ){ AOFIMODZNV = AIFIMBMAMV; }
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOFIMOD_OM < 0  ){ AOFIMOD_OM =0;   }
    if (AOFIMOD_OM > 100){ AOFIMOD_OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOFIMODLOV =AOFIMODLOM;
    AOFIMODHOV =AOFIMODHOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOFIMODLPV =AOFIMODLPM;
    AOFIMODHPV =AOFIMODHPM;
    // �����樥��� ॣ����
    AOFIMOD_PV =AOFIMOD_PM;
    AOFIMOD_IV =AOFIMOD_IM;
    AOFIMOD_DV =AOFIMOD_DM;
    AOFIMOD_MV =AOFIMOD_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOFIMOD_OV=Regulator(RN, AIFIMBM__V,
                              AOFIMOD_PV, AOFIMOD_IV, AOFIMOD_DV, AOFIMOD_MV,
                              AOFIMOD_OM, AOFIMOD_RV,
                              AOFIMODZNV, AOFIMODZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOFIMOD_OV <  OL+AOFIMODLOV){ AOFIMOD_OV=OL+AOFIMODLOV; }
       if (AOFIMOD_OV >  OH-AOFIMODHOV){ AOFIMOD_OV=OH-AOFIMODHOV; }
       if (AOFIMOD_MV >= 0){ AOFIMODOOV=100-AOFIMOD_OV; }
       else                { AOFIMODOOV=AOFIMOD_OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
