//---------------------------------------------------------------------------
// Расход сока возврата 1 сатурации

//---------------------------------------------------------------------------
vd  far Reg_12(vd){
    //-----------------------------------------------------------------------
    ui RN=12;                              // Номер регулятора                
    _f IL=0;                               // Входная шкала (нижняя граница)  
    _f IH=80;                              // Входная шкала (верхняя граница) 
    _f OL=0.000;                           // Выходная шкала (клапан),%, н.гр.
    _f OH=100.0;                           // Выходная шкала (клапан),%, в.гр.
    _f DM=10.00;                           // Макс приращ вых регулятора      
    _f ZN=IH*0.001;                        // Зона нечуствительности          
    _f PR=20.00;                           // Процент рассогласования         
    ui CC=20;                              // Контрольный цикл                
    ui TP=1;                               // Тип регулятора                  
    _f KRZ=0;                              // Корректировка задания
    //-----------------------------------------------------------------------
    // проверка диапазонов
    if (AOFSVZ__RM!=AOFSVZ__RV){ 
        AOFSVZ__RV =AOFSVZ__RM; 
        if(AOFSVZ__RV>0){ Message(122); }
        else            { Message(123); AOFSVZ__OM=AOFSVZ__OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // Коррекция
    AOFSVZ_ZKV=AOFSVZ_ZKM;                  // Задание коррекции
    AOFSVZ_PKV=AOFSVZ_PKM;                  // Процент коррекции (соотношение)
    // Включение-выключение коррекции
    if(AOFSVZ_RKM==SWITCH){
       AOFSVZ_RKV=(AOFSVZ_RKV==ON) then_ OFF else_ ON;  AOFSVZ_RKM = OFF;
    }
    // Выход коррекции
    AOFSVZ_OKV=-((AOFSVZ_ZKV-AIFDFS___V)*AOFSVZ_PKV);
    // Если коррекция выключена- выход коррекции равен 0
    if(AOFSVZ_RKV==OFF){ KRZ=0; }
    else               { KRZ=AOFSVZ_OKV; }
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    // установка задания
    if (AOFSVZ__ZM <  IL         ){ AOFSVZ__ZM = IL; }
    if (AOFSVZ__ZM >  AIFSVZ_AMV ){ AOFSVZ__ZM = AIFSVZ_AMV; }
    AOFSVZ__ZV =  AOFSVZ__ZM;
    // задание с учетом коррекции
    AOFSVZ_ZNV =  AOFSVZ__ZV+KRZ;
    if (AOFSVZ_ZNV <  IL         ){ AOFSVZ_ZNV = IL; }
    if (AOFSVZ_ZNV >  AIFSVZ_AMV ){ AOFSVZ_ZNV = AIFSVZ_AMV; }
    // выход на клапан ручного управления
    if (AOFSVZ__OM < 0  ){ AOFSVZ__OM =0;   }
    if (AOFSVZ__OM > 100){ AOFSVZ__OM =100; }
    //-----------------------------------------------------------------------
    // ограничение выхода регулятора снизу и сверху
    AOFSVZ_LOV =AOFSVZ_LOM;
    AOFSVZ_HOV =AOFSVZ_HOM;
    // ограничение выхода на приборы снизу и сверху
    AOFSVZ_LPV =AOFSVZ_LPM;
    AOFSVZ_HPV =AOFSVZ_HPM;
    // коэффициенты регулятора
    AOFSVZ__PV =AOFSVZ__PM;
    AOFSVZ__IV =AOFSVZ__IM;
    AOFSVZ__DV =AOFSVZ__DM;
    AOFSVZ__MV =AOFSVZ__MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // аналоговый регулятор
       AOFSVZ__OV=Regulator(RN, AIFSVZ___V,
                              AOFSVZ__PV, AOFSVZ__IV, AOFSVZ__DV, AOFSVZ__MV,
                              AOFSVZ__OM, AOFSVZ__RV,
                              AOFSVZ_ZNV, AOFSVZ_ZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ограничение выхода, %
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
