//---------------------------------------------------------------------------
// pH � ��⫥ 2 ����樨

//---------------------------------------------------------------------------
vd  far Reg_04(vd){
    //-----------------------------------------------------------------------
    ui RN=4;                               // ����� ॣ����                
    _f IL=8;                               // �室��� 誠�� (������ �࠭��)  
    _f IH=13;                              // �室��� 誠�� (������ �࠭��) 
    _f OL=0.000;                           // ��室��� 誠�� (������),%, �.��.
    _f OH=100.0;                           // ��室��� 誠�� (������),%, �.��.
    _f DM=10.00;                           // ���� ���� ��� ॣ����      
    _f ZN=IH*0.001;                        // ���� �����⢨⥫쭮��          
    _f PR=20.00;                           // ��業� ��ᮣ��ᮢ����         
    ui CC=20;                              // ����஫�� 横�                
    ui TP=1;                               // ��� ॣ����                  
    //-----------------------------------------------------------------------
    // �஢�ઠ ����������
    if (AOH2ST__RM!=AOH2ST__RV){ 
        AOH2ST__RV =AOH2ST__RM; 
        if(AOH2ST__RV>0){ Message(106); }
        else            { Message(107); AOH2ST__OM=AOH2ST__OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // ��⠭���� �������
    if (AOH2ST__ZM <  IL         ){ AOH2ST__ZM = IL; }
    if (AOH2ST__ZM >  AIH2ST_AMV ){ AOH2ST__ZM = AIH2ST_AMV; }
        AOH2ST__ZV =  AOH2ST__ZM;
    // ��室 �� ������ ��筮�� �ࠢ�����
    if (AOH2ST__OM < 0  ){ AOH2ST__OM =0;   }
    if (AOH2ST__OM > 100){ AOH2ST__OM =100; }
    //-----------------------------------------------------------------------
    // ��࠭�祭�� ��室� ॣ���� ᭨�� � ᢥ���
    AOH2ST_LOV =AOH2ST_LOM;
    AOH2ST_HOV =AOH2ST_HOM;
    // ��࠭�祭�� ��室� �� �ਡ��� ᭨�� � ᢥ���
    AOH2ST_LPV =AOH2ST_LPM;
    AOH2ST_HPV =AOH2ST_HPM;
    // �����樥��� ॣ����
    AOH2ST__PV =AOH2ST__PM;
    AOH2ST__IV =AOH2ST__IM;
    AOH2ST__DV =AOH2ST__DM;
    AOH2ST__MV =AOH2ST__MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // ��������� ॣ����
       AOH2ST__OV=Regulator(RN, AIH2ST___V,
                              AOH2ST__PV, AOH2ST__IV, AOH2ST__DV, AOH2ST__MV,
                              AOH2ST__OM, AOH2ST__RV,
                              AOH2ST__ZV, AOH2ST__ZV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ��࠭�祭�� ��室�, %
       if (AOH2ST__OV <  OL+AOH2ST_LOV){ AOH2ST__OV=OL+AOH2ST_LOV; }
       if (AOH2ST__OV >  OH-AOH2ST_HOV){ AOH2ST__OV=OH-AOH2ST_HOV; }
       if (AOH2ST__MV >= 0){ AOH2ST_OOV=100-AOH2ST__OV; }
       else                { AOH2ST_OOV=AOH2ST__OV; }
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
