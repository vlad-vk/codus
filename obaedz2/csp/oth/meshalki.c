//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "other_e.h"

//----------------------------------------------------------------------------
//  Контроль состояния мешалок
vd  far Meshalki(vd){

    // по умолчанию время контроля = 20 секунд
    if(TIME_MSVCW<1){ TIME_MSVCW=20; }

    // мешалка ШБ №1
    if(CONT_MSH1W==SWITCH){
       CONT_MSH1S=(CONT_MSH1S==OFF)?ON:OFF;
    }; CONT_MSH1W= CONT_MSH1S;
    // если включен контроль мешалки и мешалка выключена
    if(CONT_MSH1S==ON and DIS2011__V==OFF){
       if (Check_TO(180,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (180,NOKV); Bell(1,1); Clear_TO(180);
       }
    } else { Clear_TO(180); }

    // мешалка ШБ №2
    if(CONT_MSH2W==SWITCH){
       CONT_MSH2S=(CONT_MSH2S==OFF)?ON:OFF;
    }; CONT_MSH2W= CONT_MSH2S;
    if(CONT_MSH2S==ON and DIS2012__V==OFF){
       if (Check_TO(181,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (181,NOKV); Bell(1,1); Clear_TO(181);
       }
    } else { Clear_TO(181); }

    // мешалка ШБ №3
    if(CONT_MSH3W==SWITCH){
       CONT_MSH3S=(CONT_MSH3S==OFF)?ON:OFF;
    }; CONT_MSH3W= CONT_MSH3S;
    if(CONT_MSH3S==ON and DIS2031__V==OFF){
       if (Check_TO(182,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (182,NOKV); Bell(1,1); Clear_TO(182);
       }
    } else { Clear_TO(182); }

    // мешалка ШБ №4     
    if(CONT_MSH4W==SWITCH){
       CONT_MSH4S=(CONT_MSH4S==OFF)?ON:OFF;
    }; CONT_MSH4W= CONT_MSH4S;
    if(CONT_MSH4S==ON and DIS2032__V==OFF){
       if (Check_TO(183,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (183,NOKV); Bell(1,1); Clear_TO(183);
       }
    } else { Clear_TO(183); }

    // мешалка обр шлама
    if(CONT_MOTHW==SWITCH){
       CONT_MOTHS=(CONT_MOTHS==OFF)?ON:OFF;
    }; CONT_MOTHW= CONT_MOTHS;
    if(CONT_MOTHS==ON and DIS056P__V==OFF){
       if (Check_TO(184,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (184,NOKV); Bell(1,1); Clear_TO(184);
       }
    } else { Clear_TO(184); }

    // мешалка шлама
    if(CONT_MSHLW==SWITCH){
       CONT_MSHLS=(CONT_MSHLS==OFF)?ON:OFF;
    }; CONT_MSHLW= CONT_MSHLS;
    if(CONT_MSHLS==ON and DIS064P__V==OFF){
       if (Check_TO(185,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (185,NOKV); Bell(1,1); Clear_TO(185);
       }
    } else { Clear_TO(185); }

    // мешалка суспензии ал.пасты 1       
    if(CONT_MAPVW==SWITCH){
       CONT_MAPVS=(CONT_MAPVS==OFF)?ON:OFF;
    }; CONT_MAPVW= CONT_MAPVS;
    if(CONT_MAPVS==ON and DIS068P__V==OFF){
       if (Check_TO(186,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (186,NOKV); Bell(1,1); Clear_TO(186);
       }
    } else { Clear_TO(187); }

    // мешалка суспензии ал.пасты 2      
    if(CONT_MAPNW==SWITCH){
       CONT_MAPNS=(CONT_MAPNS==OFF)?ON:OFF;
    }; CONT_MAPNW= CONT_MAPNS;
    if(CONT_MAPNS==ON and DIS069P__V==OFF){
       if (Check_TO(187,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (187,NOKV); Bell(1,1); Clear_TO(187);
       }
    } else { Clear_TO(187); }

    // мешалка грязной воды
    if(CONT_MGRVW==SWITCH){
       CONT_MGRVS=(CONT_MGRVS==OFF)?ON:OFF;
    }; CONT_MGRVW= CONT_MGRVS;
    if(CONT_MGRVS==ON and DIS212N__V==OFF){
       if (Check_TO(188,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (188,NOKV); Bell(1,1); Clear_TO(188);
       }
    } else { Clear_TO(188); }

    // мешалка ШБ обр шлама
    if(CONT_MSOSW==SWITCH){
       CONT_MSOSS=(CONT_MSOSS==OFF)?ON:OFF;
    }; CONT_MSOSW= CONT_MSOSS;
    if(CONT_MSOSS==ON and DIS206N__V==OFF){
       if (Check_TO(189,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (189,NOKV); Bell(1,1); Clear_TO(189);
       }
    } else { Clear_TO(189); }

    // мешалка подготовки обр шлама
    if(CONT_MOSHW==SWITCH){
       CONT_MOSHS=(CONT_MOSHS==OFF)?ON:OFF;
    }; CONT_MOSHW= CONT_MOSHS;
    if(CONT_MOSHS==ON and DIS203N__V==OFF){
       if (Check_TO(190,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (190,NOKV); Bell(1,1); Clear_TO(190);
       }
    } else { Clear_TO(190); }

    return;
}
//----------------------------------------------------------------------------
