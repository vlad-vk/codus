//----------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
//  Сигнализация и блокировки
vd  far Signal(vd){

    //------------------------------------------------------------------------
    // DIS601___S = Control_DI( DIS601___V, DIS601___S, 100, 101 );
    // DIS602___S = Control_DI( DIS602___V, DIS602___S, 102, 103 );
    //------------------------------------------------------------------------
    // AIT010L__S=Control_AI(AIT010L__V,
    //                       AIT010LAZV,AIT010LAMV,AIT010L__S, 140,141,142, 1);
    //------------------------------------------------------------------------

/*
    //------------------------------------------------------------------------
    // БЛОКИРОВКА ПО ВЕСУ ДОЗАТОРОВ:

    //------------------------------------------------------------------------
    // Дозатор сухого:
    if(AIW190___V>TRCEMS_VIB+BLCEMS___V and 
      (DON181___V==ON or DON182___V==ON)){
       Message(100); Bell(1,1); 
       DON171___V=OFF; DON172___V=OFF; DON173___V=OFF;
       DON171___M=OFF; DON172___M=OFF; DON173___M=OFF;
       DON180___V=OFF; DON181___V=OFF; DON182___V=OFF;
       DON180___M=OFF; DON181___M=OFF; DON182___M=OFF;
    }
    if(AIW190___V>TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V and
      (DON151___V==ON or DON152___V==ON)){
       Message(101); Bell(1,1); 
       DON141___V=OFF; DON143___V=OFF; DON142___V=OFF;
       DON141___M=OFF; DON143___M=OFF; DON142___M=OFF;
       DON150___V=OFF; DON151___V=OFF; DON152___V=OFF;
       DON150___M=OFF; DON151___M=OFF; DON152___M=OFF;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Дозатор мокрого:

    // вода промывки (набирается всегда на пустой дозатор)
    if(AIW230___V>TRVODP_VIB+BLVODP___V and  DON232___V==ON){
       Message(107); Bell(1,1);         
       DON232___V=OFF; DON232___M=OFF;
       REG07R___M=OFF;                
    }

    // учитывать набор "ВСЕ ВМЕСТЕ" и "ПОКОМПОНЕНТНО"
    // отходы
    if(
        // если регулятор выключен
       ((REG07R___V==OFF and 
         AIW230___V >TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V) or
        // если регулятор включен в режиме набора всего вместе
        (REG07R___V==ON  and CHAN_MODEW >0 and  
         AIW230___V >TRVODP_VIB+TROTH__VIB+BLOTH____V) or
        // если регулятор включен в режиме набора покомпонентно
        (REG07R___V==ON  and CHAN_MODEW==0 and 
         AIW230___V>TROTH__VIB+BLOTH____V)) and
        // открыт один один из клапанов набора отходов
        (DON211___V==ON or DON212___V==ON)){
         Message(102); Bell(1,1); 
         DON211___V=OFF; DON211___M=OFF;
         DON212___V=OFF; DON212___M=OFF;
         REG07R___M=OFF;
    }

    // отходы+шлам
    if(
        // если регулятор выключен
       ((REG07R___V==OFF and 
         AIW230___V>TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V) or
        // если регулятор включен в режиме набора всего вместе
        (REG07R___V==ON  and CHAN_MODEW >0 and  
         AIW230___V>TRVODP_VIB+TROTH__VIB+TRSLM__VIB+BLSLM____V) or
        // если регулятор включен в режиме набора покомпонентно
        (REG07R___V==ON  and CHAN_MODEW==0 and 
         AIW230___V>TROTH__VIB+TRSLM__VIB+BLSLM____V)) and
        // открыт один один из клапанов набора шлама
        (DON221___V==ON or DON222___V==ON)){
         Message(103); Bell(1,1); 
         DON221___V=OFF; DON221___M=OFF;
         DON222___V=OFF; DON222___M=OFF;
         REG07R___M=OFF;
    }

    // вода доливки
    if(
        // если регулятор выключен
      ((REG07R___V==OFF and 
        AIW230___V >TROTH__VIB+TRSLM__VIB+TRVODD_VIB+BLVODD___V) or
        // если регулятор включен в режиме набора всего вместе
       (REG07R___V==ON  and CHAN_MODEW >0 and 
        AIW230___V >TROTH__VIB+TRSLM__VIB+TRVODD_VIB+BLVODD___V) or
        // если регулятор включен в режиме набора покомпонентно
       (REG07R___V==ON  and CHAN_MODEW==0 and 
        AIW230___V >
          // с учетом веса остатка
          ((FNSLMVOD_V==ON) then_ (AIW230VD_V+TRVODD_VIB+KRVODD___V+BLVODD___V)
          // без учета веса остатка
                            else_ (TRVODD_VIB+KRVODD___V+BLVODD___V))
       )) and
        // открыт один один из клапанов воды доливки
       (DON202___V==ON or DON203___V==ON)){
        Message(104); Bell(1,1); 
        DON202___V=OFF; DON202___M=OFF;
        DON203___V=OFF; DON203___M=OFF;
        REG07R___M=OFF;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Дозатор пасты:
    if(AIW290___V>TRPAS__VIB+BLPAS____V and
      (DON281___V==ON)){
       Message(105); Bell(1,1); 
       DON181___V=OFF;
       DON181___M=OFF;
    }
    //------------------------------------------------------------------------



    //------------------------------------------------------------------------
    // БЛОКИРОВКА ОДНОВРЕМЕННОГО ВКЛЮЧЕНИЯ НАБОРА И СЛИВА ДОЗАТОРОВ

    // Дозатор сухого:
    if(DON193___V==ON and DIS193___V==OFF and
      (DIS151___V==ON or  DON151___V==ON  or
       DIS152___V==ON or  DON152___V==ON  or
       DIS181___V==ON or  DON181___V==ON  or
       DIS182___V==ON or  DON182___V==ON) ){ 
       DON193___V=OFF;    DON193___M=OFF;
    }
    if(DON151___V==ON and DIS151___V==OFF and 
      (DIS193___V==ON or  DON193___V==ON) ){
       DON151___V=OFF;    DON151___M=OFF;
    }
    if(DON152___V==ON and DIS152___V==OFF and 
      (DIS193___V==ON or  DON193___V==ON) ){
       DON152___V=OFF;    DON151___M=OFF;
    }
    if(DON181___V==ON and DIS181___V==OFF and
      (DIS193___V==ON or  DON193___V==ON) ){
       DON181___V=OFF;    DON151___M=OFF;
    }
    if(DON182___V==ON and DIS182___V==OFF and
      (DIS193___V==ON or  DON193___V==ON) ){
       DON182___V=OFF;    DON151___M=OFF;
    }

    // Дозатор мокрого:
    if(DON231___V==ON and DIS231___V==OFF and
      (DIS211___V==ON or  DON211___V==ON  or
       DIS212___V==ON or  DON212___V==ON  or
       DIS221___V==ON or  DON221___V==ON  or
       DIS222___V==ON or  DON222___V==ON) ){ 
       DON231___V=OFF;    DON231___M=OFF;
    }
    if(DON211___V==ON and DIS211___V==OFF and 
      (DIS231___V==ON or  DON231___V==ON) ){
       DON211___V=OFF;    DON211___M=OFF;
    }
    if(DON212___V==ON and DIS212___V==OFF and 
      (DIS231___V==ON or  DON231___V==ON) ){
       DON212___V=OFF;    DON212___M=OFF;
    }
    if(DON221___V==ON and DIS221___V==OFF and 
      (DIS231___V==ON or  DON231___V==ON) ){
       DON221___V=OFF;    DON221___M=OFF;
    }
    if(DON222___V==ON and DIS222___V==OFF and 
      (DIS231___V==ON or  DON231___V==ON) ){
       DON222___V=OFF;    DON222___M=OFF;
    }

    // Нижн мешалка ал.пасты:
    if(DON274___V==ON and DIS274___V==OFF and 
      (DIS301___V==ON or  DON301___V==ON) ){
       DON274___V=OFF;    DON274___M=OFF;
    }
    if(DON301___V==ON and DIS301___V==OFF and 
      (DIS274___V==ON or  DON274___V==ON) ){
       DON301___V=OFF;    DON301___M=OFF;
    }

    // Емкость вода-ПАВ:
    if(DON272___V==ON and DIS272___V==OFF and 
      (DIS274___V==ON or  DON274___V==ON) ){
       DON272___V=OFF;    DON272___M=OFF;
    }
    if(DON274___V==ON and DIS274___V==OFF and 
      (DIS272___V==ON or  DON272___V==ON) ){
       DON274___V=OFF;    DON274___M=OFF;
    }

    // Верх мешалка ал.пасты:
    if(DON281___V==ON and DIS281___V==OFF and 
      (DIS286___V==ON or  DON286___V==ON) ){
       DON281___V=OFF;    DON281___M=OFF;
    }
    if(DON286___V==ON and DIS286___V==OFF and 
      (DIS281___V==ON or  DON281___V==ON) ){
       DON286___V=OFF;    DON286___M=OFF;
    }

    // Дозатор пасты:
    if(DON286___V==ON and DIS286___V==OFF and 
      (DIS291___V==ON or  DON291___V==ON) ){
       DON286___V=OFF;    DON286___M=OFF;
    }
    if(DON291___V==ON and DIS291___V==OFF and 
      (DIS286___V==ON or  DON286___V==ON) ){
       DON291___V=OFF;    DON291___M=OFF;
    }

*/

    return;
}
//----------------------------------------------------------------------------
