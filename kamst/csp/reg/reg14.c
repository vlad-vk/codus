//---------------------------------------------------------------------------
// Расход суспензии на преддефекатор Бригель-Мюллера

//---------------------------------------------------------------------------
vd  far Reg_14(vd){
    //-----------------------------------------------------------------------
    ui RN=14;                              // Номер регулятора                
    _f IL=0;                               // Входная шкала (нижняя граница)  
    _f IH=40.00;                           // Входная шкала (верхняя граница) 
    _f OL=0.000;                           // Выходная шкала (клапан),%, н.гр.
    _f OH=100.0;                           // Выходная шкала (клапан),%, в.гр.
    _f DM=10.00;                           // Макс приращ вых регулятора      
    _f ZN=IH*0.001;                        // Зона нечуствительности          
    _f PR=20.00;                           // Процент рассогласования         
    ui CC=20;                              // Контрольный цикл                
    ui TP=1;                               // Тип регулятора                  
    _f KRZ=0;                              // Корректировка задания
    //-----------------------------------------------------------------------
    if (AOFSPBM_RM!=AOFSPBM_RV){ 
        AOFSPBM_RV =AOFSPBM_RM; 
        if(AOFSPBM_RV>0){ Message(126); }
        else            { Message(127); AOFSPBM_OM=AOFSPBM_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // Коррекция
    AOFSPBMZKV=AOFSPBMZKM;                  // Задание коррекции
    AOFSPBMPKV=AOFSPBMPKM;                  // Процент коррекции (соотношение)
    // Включение-выключение коррекции
    if(AOFSPBMRKM==SWITCH){
       AOFSPBMRKV=(AOFSPBMRKV==ON) then_ OFF else_ ON;  AOFSPBMRKM = OFF;
    }
    // Выход коррекции
    AOFSPBMOKV=-((AOFSPBMZKV-AIFSD2S__V)*AOFSPBMPKV);
    // Если коррекция выключена- выход коррекции равен 0
    if(AOFSPBMRKV==OFF){ KRZ=0; }
    else               { KRZ=AOFSPBMOKV; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // установка задания
    if (AOFSPBM_ZM <  IL         ){ AOFSPBM_ZM = IL; }
    if (AOFSPBM_ZM >  AIFSP2SAMV ){ AOFSPBM_ZM = AIFSP2SAMV; }
    AOFSPBM_ZV =  AOFSPBM_ZM;
    // задание с учетом коррекции
    AOFSPBMZNV =  AOFSPBM_ZV+KRZ;
    if (AOFSPBMZNV <  IL         ){ AOFSPBMZNV = IL; }
    if (AOFSPBMZNV >  AIFSP2SAMV ){ AOFSPBMZNV = AIFSP2SAMV; }
    // выход на клапан ручного управления
    if (AOFSPBM_OM < 0  ){ AOFSPBM_OM =0;   }
    if (AOFSPBM_OM > 100){ AOFSPBM_OM =100; }
    //-----------------------------------------------------------------------
    // ограничение выхода регулятора снизу и сверху
    AOFSPBMLOV =AOFSPBMLOM;
    AOFSPBMHOV =AOFSPBMHOM;
    // ограничение выхода на приборы снизу и сверху
    AOFSPBMLPV =AOFSPBMLPM;
    AOFSPBMHPV =AOFSPBMHPM;
    // коэффициенты регулятора
    AOFSPBM_PV =AOFSPBM_PM;
    AOFSPBM_IV =AOFSPBM_IM;
    AOFSPBM_DV =AOFSPBM_DM;
    AOFSPBM_MV =AOFSPBM_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // аналоговый регулятор
       AOFSPBM_OV=Regulator(RN, AIFSP2S__V,
                              AOFSPBM_PV, AOFSPBM_IV, AOFSPBM_DV, AOFSPBM_MV,
                              AOFSPBM_OM, AOFSPBM_RV,
                              AOFSPBMZNV, AOFSPBMZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ограничение выхода, %
       if (AOFSPBM_OV <  OL+AOFSPBMLOV){ AOFSPBM_OV=OL+AOFSPBMLOV; }
       if (AOFSPBM_OV >  OH-AOFSPBMHOV){ AOFSPBM_OV=OH-AOFSPBMHOV; }
       if (AOFSPBM_MV >= 0){ AOFSPBMOOV=100-AOFSPBM_OV; }
       else                { AOFSPBMOOV=AOFSPBM_OV; }
//     для теста
//     AOFSPBMOOV=AOFSPBM_OV;
       //--------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
