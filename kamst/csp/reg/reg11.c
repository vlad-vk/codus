//---------------------------------------------------------------------------
// Расход известкового молока на основную дефекацию

//---------------------------------------------------------------------------
vd  far Reg_11(vd){
    //-----------------------------------------------------------------------
    ui RN=11;                              // Номер регулятора                
    _f IL=0;                               // Входная шкала (нижняя граница)  
    _f IH=140.00;                           // Входная шкала (верхняя граница) 
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
    if (AOFIMOD_RM!=AOFIMOD_RV){ 
        AOFIMOD_RV =AOFIMOD_RM; 
        if(AOFIMOD_RV>0){ Message(120); }
        else            { Message(121); AOFIMOD_OM=AOFIMOD_OV=WO_Skip[RN]; }
    }
    //-----------------------------------------------------------------------
    // Коррекция
    AOFIMODZKV=AOFIMODZKM;                  // Задание коррекции
    AOFIMODPKV=AOFIMODPKM;                  // Процент коррекции (соотношение)
    // Включение-выключение коррекции
    if(AOFIMODRKM==SWITCH){
       AOFIMODRKV=(AOFIMODRKV==ON) then_ OFF else_ ON;  AOFIMODRKM = OFF;
    }
    // Выход коррекции
    AOFIMODOKV=-((AOFIMODZKV-AIFDFS___V)*AOFIMODPKV);
    // Если коррекция выключена- выход коррекции равен 0
    if(AOFIMODRKV==OFF){ KRZ=0; }
    else               { KRZ=AOFIMODOKV; }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // установка задания
    if (AOFIMOD_ZM <  IL         ){ AOFIMOD_ZM = IL; }
    if (AOFIMOD_ZM >  AIFIMBMAMV ){ AOFIMOD_ZM = AIFIMBMAMV; }
    AOFIMOD_ZV =  AOFIMOD_ZM;
    // задание с учетом коррекции
    AOFIMODZNV =  AOFIMOD_ZV+KRZ;
    if (AOFIMODZNV <  IL         ){ AOFIMODZNV = IL; }
    if (AOFIMODZNV >  AIFIMBMAMV ){ AOFIMODZNV = AIFIMBMAMV; }
    // выход на клапан ручного управления
    if (AOFIMOD_OM < 0  ){ AOFIMOD_OM =0;   }
    if (AOFIMOD_OM > 100){ AOFIMOD_OM =100; }
    //-----------------------------------------------------------------------
    // ограничение выхода регулятора снизу и сверху
    AOFIMODLOV =AOFIMODLOM;
    AOFIMODHOV =AOFIMODHOM;
    // ограничение выхода на приборы снизу и сверху
    AOFIMODLPV =AOFIMODLPM;
    AOFIMODHPV =AOFIMODHPM;
    // коэффициенты регулятора
    AOFIMOD_PV =AOFIMOD_PM;
    AOFIMOD_IV =AOFIMOD_IM;
    AOFIMOD_DV =AOFIMOD_DM;
    AOFIMOD_MV =AOFIMOD_MM;
    //-----------------------------------------------------------------------
    if (RegRUN>0){
       //--------------------------------------------------------------------
       // аналоговый регулятор
       AOFIMOD_OV=Regulator(RN, AIFIMBM__V,
                              AOFIMOD_PV, AOFIMOD_IV, AOFIMOD_DV, AOFIMOD_MV,
                              AOFIMOD_OM, AOFIMOD_RV,
                              AOFIMODZNV, AOFIMODZNV,
                                IL,  IH,  OL,  OH,
                                DM,  ZN,  PR,  CC,  TP
       );
       // ограничение выхода, %
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
