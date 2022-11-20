//---------------------------------------------------------------------------
// ���室 ����㧨������ ᮪�

//---------------------------------------------------------------------------
vd  far Reg_02(vd){
    //-----------------------------------------------------------------------
    ui RN=2;                               // ����� ॣ����                
    _f IL=0;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=160;                             // �室��� 誠�� (������ �࠭��) 
    _f OL=0.000;                           // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                           // ��室��� 誠�� (������),%, �.��.
    _f DM=10.00;                           // ���� ���� ��� ॣ����      
    _f ZN=IH*0.001;                        // ���� �����⢨⥫쭮��          
    _f PR=20.00;                           // ��業� ��ᮣ��ᮢ����         
    ui CC=20;                              // ����஫�� 横�                
    ui TP=1;                               // ��� ॣ����                  
    //-----------------------------------------------------------------------
    // �஢�ઠ ����������
    if (AOFDFS__RM!=AOFDFS__RV){ 
        AOFDFS__RV =AOFDFS__RM; 
        if(AOFDFS__RV>0){ Message(102); }
        else            { Message(103); AOFDFS__OM=AOFDFS__OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOFDFS__ZM <  IL ){ AOFDFS__ZM = IL; }
    if (AOFDFS__ZM >  AIFDFS_AMV ){ AOFDFS__ZM = AIFDFS_AMV; }
//  if (AOFDFS__ZM >  IH ){ AOFDFS__ZM = IH; }
        AOFDFS__ZV =  AOFDFS__ZM;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOFDFS__OM < 0  ){ AOFDFS__OM =0;   }
    if (AOFDFS__OM > 100){ AOFDFS__OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOFDFS_LOV =AOFDFS_LOM;
    AOFDFS_HOV =AOFDFS_HOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOFDFS_LPV =AOFDFS_LPM;
    AOFDFS_HPV =AOFDFS_HPM;
    // �����樥��� ॣ����
    AOFDFS__PV =AOFDFS__PM;
    AOFDFS__IV =AOFDFS__IM;
    AOFDFS__DV =AOFDFS__DM;
    AOFDFS__MV =AOFDFS__MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOFDFS__OV=Regulator(RN, AIFDFS___V,
                              AOFDFS__PV, AOFDFS__IV, AOFDFS__DV, AOFDFS__MV,
                              AOFDFS__OM, AOFDFS__RV,
                              AOFDFS__ZV, AOFDFS__ZV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOFDFS__OV <  OL+AOFDFS_LOV){ AOFDFS__OV=OL+AOFDFS_LOV; }
       if (AOFDFS__OV >  OH-AOFDFS_HOV){ AOFDFS__OV=OH-AOFDFS_HOV; }
       if (AOFDFS__MV >= 0){ AOFDFS_OOV=100-AOFDFS__OV; }
       else                { AOFDFS_OOV=AOFDFS__OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
