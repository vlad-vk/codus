//----------------------------------------------------------------------------
//  COM2, 7042, N0D

    rec=24;

    // ручное переключение с компьютера выходов на исполнители
    if(DONPBM3__M==SWITCH){ 
       DONPBM3__V=(DONPBM3__V==ON) then_ OFF else_ ON;
    }; DONPBM3__M= OFF;

    if(DONPBM6__M==SWITCH){ 
       DONPBM6__V=(DONPBM6__V==ON) then_ OFF else_ ON;
    }; DONPBM6__M= OFF;

    if(DONPHD___M==SWITCH){ 
       DONPHD___V=(DONPHD___V==ON) then_ OFF else_ ON;
    }; DONPHD___M= OFF;

    if(DONPGD___M==SWITCH){ 
       DONPGD___V=(DONPGD___V==ON) then_ OFF else_ ON;
    }; DONPGD___M= OFF;

    if(DONPP1___M==SWITCH){ 
       DONPP1___V=(DONPP1___V==ON) then_ OFF else_ ON;
    }; DONPP1___M= OFF;

    if(DONP1ST__M==SWITCH){ 
       DONP1ST__V=(DONP1ST__V==ON) then_ OFF else_ ON; 
    }; DONP1ST__M= OFF;

    if(DONPD2S__M==SWITCH){ 
       DONPD2S__V=(DONPD2S__V==ON) then_ OFF else_ ON; 
    }; DONPD2S__M= OFF;

    if(DONP2ST__M==SWITCH){ 
       DONP2ST__V=(DONP2ST__V==ON) then_ OFF else_ ON; 
    }; DONP2ST__M= OFF;

//  Включение-выключение насоса определено в файле reg15.c
  if(DONNZP___M==SWITCH){ 
     DONNZP___V=(DONNZP___V==ON) then_ OFF else_ ON; 
  }; DONNZP___M= OFF; 

    if(DONNZP2__M==SWITCH){ 
       DONNZP2__V=(DONNZP2__V==ON) then_ OFF else_ ON; 
    }; DONNZP2__M= OFF; 

    if(DOX0D10__M==SWITCH){ 
       DOX0D10__V=(DOX0D10__V==ON) then_ OFF else_ ON; 
    }; DOX0D10__M= OFF; 

    if(DONCSW___M==SWITCH){ 
       DONCSW___V=(DONCSW___V==ON) then_ OFF else_ ON; 
    }; DONCSW___M= OFF; 

    if(DONZVS___M==SWITCH){ 
       DONZVS___V=(DONZVS___V==ON) then_ OFF else_ ON; 
    }; DONZVS___M= OFF; 

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  DONPBM3__V,  0, 0);
    SetMODV (COMU1,rec, 1,  DONPBM6__V,  0, 0);
    SetMODV (COMU1,rec, 2,  DONPHD___V,  0, 0);
    SetMODV (COMU1,rec, 3,  DONPGD___V,  0, 0);
    SetMODV (COMU1,rec, 4,  DONPP1___V,  0, 0);
    SetMODV (COMU1,rec, 5,  DONP1ST__V,  0, 0);
    SetMODV (COMU1,rec, 6,  DONPD2S__V,  0, 0);
    SetMODV (COMU1,rec, 7,  DONP2ST__V,  0, 0);
    SetMODV (COMU1,rec, 8,  DONNZP___V,  0, 0);
    SetMODV (COMU1,rec, 9,  DONNZP2__V,  0, 0);
    SetMODV (COMU1,rec,10,  DOX0D10__V,  0, 0);
    SetMODV (COMU1,rec,11,  DONCSW___V,  0, 0);
    SetMODV (COMU1,rec,12,  DONZVS___V,  0, 0);

//----------------------------------------------------------------------------
