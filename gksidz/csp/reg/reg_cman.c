#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

//---------------------------------------------------------------------------
//  Контроль нахождения регуляторов в ручном режиме 
vd  far Check_Regul_Manual(vd){
    if (TIME_RGMCW<1||TIME_RGMCW>60*24){ TIME_RGMCW=10; }

    // подкачка шлама
    REG01TCW_V=REG01TCW_M;  if(REG01TCW_V<1){ REG01TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (19, REG01TCW_V*MIN, REG01R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(329); Clear_TO(19); break;;
        case END: Clear_TO(19); break;;
    };  
    // подкачка воды
    REG02TCW_V=REG02TCW_M;  if(REG02TCW_V<1){ REG02TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (29, REG02TCW_V*MIN, REG02R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(339); Clear_TO(29); break;;
        case END: Clear_TO(29); break;;
    };  
    // подкачка отходов 
    REG03TCW_V=REG03TCW_M;  if(REG03TCW_V<1){ REG03TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (39, REG03TCW_V*MIN, REG03R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(349); Clear_TO(39); break;;
        case END: Clear_TO(39); break;;
    };  
    // подкачка вяжущего
    REG04TCW_V=REG04TCW_M;  if(REG04TCW_V<1){ REG04TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (49, REG04TCW_V*MIN, REG04R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(359); Clear_TO(49); break;;
        case END: Clear_TO(49); break;;
    };  
    // подкачка цемента
    REG05TCW_V=REG05TCW_M;  if(REG05TCW_V<1){ REG05TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (59, REG05TCW_V*MIN, REG05R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(369); Clear_TO(59); break;;
        case END: Clear_TO(59); break;;
    };  
    // дозировка сухого
    REG06TCW_V=REG06TCW_M;  if(REG06TCW_V<1){ REG06TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (69, REG06TCW_V*MIN, REG06R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(379); Clear_TO(69); break;;
        case END: Clear_TO(69); break;;
    };  
    // дозировка мокрого
    REG07TCW_V=REG07TCW_M;  if(REG07TCW_V<1){ REG07TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (79, REG07TCW_V*MIN, REG07R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(398); Clear_TO(79); break;;
        case END: Clear_TO(79); break;;
    };  
    // дозировка пасты
    REG09TCW_V=REG09TCW_M;  if(REG09TCW_V<1){ REG09TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (99, REG09TCW_V*MIN, REG09R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(409); Clear_TO(99); break;;
        case END: Clear_TO(99); break;;
    };  
    // управление ВГБМ
    REG10TCW_V=REG10TCW_M;  if(REG10TCW_V<1){ REG10TCW_V=TIME_RGMCW; }
    switch ( Check_TO  (98, REG10TCW_V*MIN, REG10R___V, '=', ON, 2 )){
        case RUN: break;;
        case BAD: Message(419); Clear_TO(98); break;;
        case END: Clear_TO(98); break;;
    };  

    return;
}
//---------------------------------------------------------------------------
