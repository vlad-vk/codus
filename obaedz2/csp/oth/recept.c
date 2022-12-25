//---------------------------------------------------------------------------
//  coding=cp866; version=2013013112; title="";
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  Выбор рецепта загрузки
vd  far DefRecept(vd){

    //-----------------------------------------------------------------------
    if(RECEPT_01M>0){
       RECEPT_01V=1; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=0; RECEPT_06V=0;
       RECEPT_CNV=1; Message(81,NOKV);
    }
    if(RECEPT_02M>0){
       RECEPT_01V=0; RECEPT_02V=1; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=0; RECEPT_06V=0;
       RECEPT_CNV=2; Message(82,NOKV);
    }
    if(RECEPT_03M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=1; RECEPT_04V=0; RECEPT_05V=0; RECEPT_06V=0;
       RECEPT_CNV=3; Message(83,NOKV);
    }
    if(RECEPT_04M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=1; RECEPT_05V=0; RECEPT_06V=0;
       RECEPT_CNV=4; Message(84,NOKV);
    }
    if(RECEPT_05M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=1; RECEPT_06V=0;
       RECEPT_CNV=5; Message(85,NOKV);
    }

    if(RECEPT_06M>0){
       RECEPT_01V=0; RECEPT_02V=0; RECEPT_03V=0; RECEPT_04V=0; RECEPT_05V=0; RECEPT_06V=1;
       RECEPT_CNV=6; Message(86,NOKV);
    }

    TRCM1S_01V=TRCM1B_01V+TRCEMS_01V;
    TRCM1S_02V=TRCM1B_02V+TRCEMS_02V;
    TRCM1S_03V=TRCM1B_03V+TRCEMS_03V;
    TRCM1S_04V=TRCM1B_04V+TRCEMS_04V;
    TRCM1S_05V=TRCM1B_05V+TRCEMS_05V;
    TRCM1S_06V=TRCM1B_06V+TRCEMS_06V;
    
    // Выбор рецепта
    if(RECEPT_01V>0){
       TRCM1B_VIB=TRCM1B_01V;
       TRCEMS_VIB=TRCEMS_01V; 
       TRCM1S_VIB=TRCM1S_01V;
       TRVYGS_VIB=TRVYGS_01V;
       TROTH__VIB=TROTH__01V;
       TRSLM__VIB=TRSLM__01V;
       TRVODD_VIB=TRVODD_01V;
       TRPAS__VIB=TRPAS__01V;
       TRVODV_VIB=TRVODD_01V;
    }

    if(RECEPT_02V>0){
       TRCM1B_VIB=TRCM1B_02V;
       TRCEMS_VIB=TRCEMS_02V; 
       TRCM1S_VIB=TRCM1S_02V;
       TRVYGS_VIB=TRVYGS_02V;
       TROTH__VIB=TROTH__02V;
       TRSLM__VIB=TRSLM__02V;
       TRVODD_VIB=TRVODD_02V;
       TRPAS__VIB=TRPAS__02V;
       TRVODV_VIB=TRVODD_02V;
    }

    if(RECEPT_03V>0){
       TRCM1B_VIB=TRCM1B_03V;
       TRCEMS_VIB=TRCEMS_03V; 
       TRCM1S_VIB=TRCM1S_03V;
       TRVYGS_VIB=TRVYGS_03V;
       TROTH__VIB=TROTH__03V;
       TRSLM__VIB=TRSLM__03V;
       TRVODD_VIB=TRVODD_03V;
       TRPAS__VIB=TRPAS__03V;
       TRVODV_VIB=TRVODD_03V;
    }

    if(RECEPT_04V>0){
       TRCM1B_VIB=TRCM1B_04V;
       TRCEMS_VIB=TRCEMS_04V; 
       TRCM1S_VIB=TRCM1S_04V;
       TRVYGS_VIB=TRVYGS_04V;
       TROTH__VIB=TROTH__04V;
       TRSLM__VIB=TRSLM__04V;
       TRVODD_VIB=TRVODD_04V;
       TRPAS__VIB=TRPAS__04V;
       TRVODV_VIB=TRVODD_04V;
    }
        
    if(RECEPT_05V>0){
       TRCM1B_VIB=TRCM1B_05V;
       TRCEMS_VIB=TRCEMS_05V; 
       TRCM1S_VIB=TRCM1S_05V;
       TRVYGS_VIB=TRVYGS_05V;
       TROTH__VIB=TROTH__05V;
       TRSLM__VIB=TRSLM__05V;
       TRVODD_VIB=TRVODD_05V;
       TRPAS__VIB=TRPAS__05V;
       TRVODV_VIB=TRVODD_05V;
    }

    if(RECEPT_06V>0){
       TRCM1B_VIB=TRCM1B_06V;
       TRCEMS_VIB=TRCEMS_06V; 
       TRCM1S_VIB=TRCM1S_06V;
       TRVYGS_VIB=TRVYGS_06V;
       TROTH__VIB=TROTH__06V;
       TRSLM__VIB=TRSLM__06V;
       TRVODD_VIB=TRVODD_06V;
       TRPAS__VIB=TRPAS__06V;
       TRVODV_VIB=TRVODD_06V;
    }
    TRCEMB_VIB=TRCEMS_VIB;
    TRVYGB_VIB=TRVYGS_VIB;
    TRSLO__VIB=TRSLM__VIB;

    RECEPT_01M=0; RECEPT_02M=0; RECEPT_03M=0; RECEPT_04M=0; RECEPT_05M=0; RECEPT_06M=0;
    //-----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
