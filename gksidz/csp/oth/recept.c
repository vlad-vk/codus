//---------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  Выбор рецепта загрузки
vd  far DefRecept(vd){

    //-----------------------------------------------------------------------
    if(RECEPT_01M>0){
       RECEPT_01V=1; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=0; 
       RECEPT_CNV=1; Message( 81);
    }
    if(RECEPT_02M>0){
       RECEPT_01V=0; RECEPT_02V=1; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=0; 
       RECEPT_CNV=2; Message( 82);
    }
    if(RECEPT_03M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=1; RECEPT_04V=0; RECEPT_05V=0; 
       RECEPT_CNV=3; Message( 83);
    }
    if(RECEPT_04M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=1; RECEPT_05V=0; 
       RECEPT_CNV=4; Message( 84);
    }
    if(RECEPT_05M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=1;
       RECEPT_CNV=5; Message( 85);
    }

    // Выбор рецепта
    if(RECEPT_01V>0){
       TRCEMA_VIB=TRCEMA_01V; 
       TRCEMS_VIB=TRCEMS_01V; 
       TRVYGA_VIB=TRVYGA_01V;
       TRVYGS_VIB=TRVYGS_01V;
       TRVODP_VIB=TRVODP_01V;
       TROTH__VIB=TROTH__01V;
       TRSLM__VIB=TRSLM__01V;
       TRVODD_VIB=TRVODD_01V;
       TRPAS__VIB=TRPAS__01V;
       TRVODV_VIB=TRVODD_01V-TRVODP_01V;
    }

    if(RECEPT_02V>0){
       TRCEMA_VIB=TRCEMA_02V; 
       TRCEMS_VIB=TRCEMS_02V; 
       TRVYGA_VIB=TRVYGA_02V;
       TRVYGS_VIB=TRVYGS_02V;
       TRVODP_VIB=TRVODP_02V;
       TROTH__VIB=TROTH__02V;
       TRSLM__VIB=TRSLM__02V;
       TRVODD_VIB=TRVODD_02V;
       TRPAS__VIB=TRPAS__02V;
       TRVODV_VIB=TRVODD_02V-TRVODP_02V;
    }

    if(RECEPT_03V>0){
       TRCEMA_VIB=TRCEMA_03V; 
       TRCEMS_VIB=TRCEMS_03V; 
       TRVYGA_VIB=TRVYGA_03V;
       TRVYGS_VIB=TRVYGS_03V;
       TRVODP_VIB=TRVODP_03V;
       TROTH__VIB=TROTH__03V;
       TRSLM__VIB=TRSLM__03V;
       TRVODD_VIB=TRVODD_03V;
       TRPAS__VIB=TRPAS__03V;
       TRVODV_VIB=TRVODD_03V-TRVODP_03V;
    }

    if(RECEPT_04V>0){
       TRCEMA_VIB=TRCEMA_04V; 
       TRCEMS_VIB=TRCEMS_04V; 
       TRVYGA_VIB=TRVYGA_04V;
       TRVYGS_VIB=TRVYGS_04V;
       TRVODP_VIB=TRVODP_04V;
       TROTH__VIB=TROTH__04V;
       TRSLM__VIB=TRSLM__04V;
       TRVODD_VIB=TRVODD_04V;
       TRPAS__VIB=TRPAS__04V;
       TRVODV_VIB=TRVODD_04V-TRVODP_04V;
    }
        
    if(RECEPT_05V>0){
       TRCEMA_VIB=TRCEMA_05V; 
       TRCEMS_VIB=TRCEMS_05V; 
       TRVYGA_VIB=TRVYGA_05V;
       TRVYGS_VIB=TRVYGS_05V;
       TRVODP_VIB=TRVODP_05V;
       TROTH__VIB=TROTH__05V;
       TRSLM__VIB=TRSLM__05V;
       TRVODD_VIB=TRVODD_05V;
       TRPAS__VIB=TRPAS__05V;
       TRVODV_VIB=TRVODD_05V-TRVODP_05V;
    }

    TRCEMB_VIB=TRCEMS_VIB-TRCEMA_VIB;
    TRVYGB_VIB=TRVYGS_VIB-TRVYGA_VIB;
    TRSLO__VIB=TRSLM__VIB+TROTH__VIB;

    RECEPT_01M=0; RECEPT_02M=0; RECEPT_03M=0; RECEPT_04M=0; RECEPT_05M=0;
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
