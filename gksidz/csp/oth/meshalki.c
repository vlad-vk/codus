//---------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

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
    if(CONT_MSH1S==ON and DIS050___V==OFF){
       if (Check_TO(180,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (180); Bell(1); Clear_TO(180);
       }
    } else { Clear_TO(180); }

    // мешалка ШБ №2
    if(CONT_MSH2W==SWITCH){
       CONT_MSH2S=(CONT_MSH2S==OFF)?ON:OFF;
    }; CONT_MSH2W= CONT_MSH2S;
    if(CONT_MSH2S==ON and DIS040___V==OFF){
       if (Check_TO(181,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (181); Bell(1); Clear_TO(181);
       }
    } else { Clear_TO(181); }

    // мешалка ШБ №3
    if(CONT_MSH3W==SWITCH){
       CONT_MSH3S=(CONT_MSH3S==OFF)?ON:OFF;
    }; CONT_MSH3W= CONT_MSH3S;
    if(CONT_MSH3S==ON and DIS030___V==OFF){
       if (Check_TO(182,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (182); Bell(1); Clear_TO(182);
       }
    } else { Clear_TO(182); }

    // мешалка отходов РК
    if(CONT_MORKW==SWITCH){
       CONT_MORKS=(CONT_MORKS==OFF)?ON:OFF;
    }; CONT_MORKW= CONT_MORKS;
    if(CONT_MORKS==ON and DIS070___V==OFF){
       if (Check_TO(183,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (183); Bell(1); Clear_TO(183);
       }
    } else { Clear_TO(183); }

    // мешалка отходов
    if(CONT_MOTHW==SWITCH){
       CONT_MOTHS=(CONT_MOTHS==OFF)?ON:OFF;
    }; CONT_MOTHW= CONT_MOTHS;
    if(CONT_MOTHS==ON and DIS210___V==OFF){
       if (Check_TO(184,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (184); Bell(1); Clear_TO(184);
       }
    } else { Clear_TO(184); }

    // мешалка шлама
    if(CONT_MSHLW==SWITCH){
       CONT_MSHLS=(CONT_MSHLS==OFF)?ON:OFF;
    }; CONT_MSHLW= CONT_MSHLS;
    if(CONT_MSHLS==ON and DIS220___V==OFF){
       if (Check_TO(185,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (185); Bell(1); Clear_TO(185);
       }
    } else { Clear_TO(185); }

    // мешалка суспензии ал.пасты верхняя
    if(CONT_MAPVW==SWITCH){
       CONT_MAPVS=(CONT_MAPVS==OFF)?ON:OFF;
    }; CONT_MAPVW= CONT_MAPVS;
    if(CONT_MAPVS==ON and DIS280___V==OFF){
       if (Check_TO(187,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (187); Bell(1); Clear_TO(187);
       }
    } else { Clear_TO(187); }

    // мешалка суспензии ал.пасты нижняя
    if(CONT_MAPNW==SWITCH){
       CONT_MAPNS=(CONT_MAPNS==OFF)?ON:OFF;
    }; CONT_MAPNW= CONT_MAPNS;
    if(CONT_MAPNS==ON and DIS300___V==OFF){
       if (Check_TO(188,  TIME_MSVCW, ZERO, '=', ON,  1 ) == BAD){
           Message (188); Bell(1); Clear_TO(188);
       }
    } else { Clear_TO(188); }

    return;
}
//----------------------------------------------------------------------------
