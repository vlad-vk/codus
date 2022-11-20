//---------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "other_e.h"

//---------------------------------------------------------------------------
//  Присвоение значений переменным
vd  far SetVal(vd){

    //-----------------------------------------------------------------------
    // Обновление значений диапазонов
    AIT050_SZV=AIT050_SZM; AIT050_SDV=AIT050_SDM;
    AIT050__FV=AIT050__FM; AIT050__AV=AIT050__AM;

    AIT040_SZV=AIT040_SZM; AIT040_SDV=AIT040_SDM;
    AIT040__FV=AIT040__FM; AIT040__AV=AIT040__AM;

    AIT030_SZV=AIT030_SZM; AIT030_SDV=AIT030_SDM;
    AIT030__FV=AIT030__FM; AIT030__AV=AIT030__AM;

    AIT220_SZV=AIT220_SZM; AIT220_SDV=AIT220_SDM;
    AIT220__FV=AIT220__FM; AIT220__AV=AIT220__AM;

    AIT270_SZV=AIT270_SZM; AIT270_SDV=AIT270_SDM;
    AIT270__FV=AIT270__FM; AIT270__AV=AIT270__AM;

    AIT200_SZV=AIT200_SZM; AIT200_SDV=AIT200_SDM;
    AIT200__FV=AIT200__FM; AIT200__AV=AIT200__AM;

    AIW290_SZV=AIW290_SZM; AIW290_SDV=AIW290_SDM;
    AIW290__FV=AIW290__FM; AIW290__AV=AIW290__AM;

    AIW230_SZV=AIW230_SZM; AIW230_SDV=AIW230_SDM;
    AIW230__FV=AIW230__FM; AIW230__AV=AIW230__AM;

    AIW190_SZV=AIW190_SZM; AIW190_SDV=AIW190_SDM;
    AIW190__FV=AIW190__FM; AIW190__AV=AIW190__AM;

    AIX0304SZV=AIX0304SZM; AIX0304SDV=AIX0304SDM;
    AIX0304_FV=AIX0304_FM; AIX0304_AV=AIX0304_AM;

    AIX0305SZV=AIX0305SZM; AIX0305SDV=AIX0305SDM;
    AIX0305_FV=AIX0305_FM; AIX0305_AV=AIX0305_AM;

    AIX0306SZV=AIX0306SZM; AIX0306SDV=AIX0306SDM;
    AIX0306_FV=AIX0306_FM; AIX0306_AV=AIX0306_AM;

    AIX0307SZV=AIX0307SZM; AIX0307SDV=AIX0307SDM;
    AIX0307_FV=AIX0307_FM; AIX0307_AV=AIX0307_AM;

    // Обновление значений сигнализации
    AIT050_AZV=AIT050_AZM; AIT050_AMV=AIT050_AMM;
    AIT040_AZV=AIT040_AZM; AIT040_AMV=AIT040_AMM;
    AIT030_AZV=AIT030_AZM; AIT030_AMV=AIT030_AMM;
    AIT270_AZV=AIT270_AZM; AIT270_AMV=AIT270_AMM;
    AIT220_AZV=AIT220_AZM; AIT220_AMV=AIT220_AMM;
    AIT200_AZV=AIT200_AZM; AIT200_AMV=AIT200_AMM;

    // Обновление парамметров установок
    // ...

    // Обновление таблицы загрузок
    TRCEMA_01V=TRCEMA_01M;
    TRCEMA_02V=TRCEMA_02M;
    TRCEMA_03V=TRCEMA_03M;
    TRCEMA_04V=TRCEMA_04M;
    TRCEMA_05V=TRCEMA_05M; 
    TRCEMS_01V=TRCEMS_01M;
    TRCEMS_02V=TRCEMS_02M;
    TRCEMS_03V=TRCEMS_03M;
    TRCEMS_04V=TRCEMS_04M;
    TRCEMS_05V=TRCEMS_05M; 

    TRVYGA_01V=TRVYGA_01M;
    TRVYGA_02V=TRVYGA_02M;
    TRVYGA_03V=TRVYGA_03M;
    TRVYGA_04V=TRVYGA_04M;
    TRVYGA_05V=TRVYGA_05M;
    TRVYGS_01V=TRVYGS_01M;
    TRVYGS_02V=TRVYGS_02M;
    TRVYGS_03V=TRVYGS_03M;
    TRVYGS_04V=TRVYGS_04M;
    TRVYGS_05V=TRVYGS_05M;

    TRVODP_01V=TRVODP_01M;
    TRVODP_02V=TRVODP_02M;
    TRVODP_03V=TRVODP_03M;
    TRVODP_04V=TRVODP_04M;
    TRVODP_05V=TRVODP_05M;

    TROTH__01V=TROTH__01M;
    TROTH__02V=TROTH__02M;
    TROTH__03V=TROTH__03M;
    TROTH__04V=TROTH__04M;
    TROTH__05V=TROTH__05M;

    TRSLM__01V=TRSLM__01M;
    TRSLM__02V=TRSLM__02M;
    TRSLM__03V=TRSLM__03M;
    TRSLM__04V=TRSLM__04M;
    TRSLM__05V=TRSLM__05M;

    TRVODD_01V=TRVODD_01M;
    TRVODD_02V=TRVODD_02M;
    TRVODD_03V=TRVODD_03M;
    TRVODD_04V=TRVODD_04M;
    TRVODD_05V=TRVODD_05M;

    TRPAS__01V=TRPAS__01M;
    TRPAS__02V=TRPAS__02M;
    TRPAS__03V=TRPAS__03M;
    TRPAS__04V=TRPAS__04M;
    TRPAS__05V=TRPAS__05M;

    KRCEMA___V=KRCEMA___M;
    KRVYGA___V=KRVYGA___M;
    KRCEMS___V=KRCEMS___M;
    if(KRVYGS___V!=KRVYGS___M){
       if(KRVYGS___M>AIW190___V){ KRVYGS___M=AIW190___V; }
          KRVYGS___V=KRVYGS___M;
    }

    KRVODP___V=KRVODP___M;
    KROTH____V=KROTH____M;
    if(KRSLM____V!=KRSLM____M){ KRSLM____V=KRSLM____M; }
    if(KRVODD___V!=KRVODD___M){ 
       if(KRVODD___M>AIW230___V){ KRVODD___M=AIW230___V; }
       KRVODD___V=KRVODD___M; 
    }

    KRPAS____V=KRPAS____M;

    DPCEMA___V=DPCEMA___M; 
    DPCEMS___V=DPCEMS___M; 
    DPVYGA___V=DPVYGA___M;
    DPVYGS___V=DPVYGS___M;
    DPVODP___V=DPVODP___M;
    DPOTH____V=DPOTH____M;
    DPSLM____V=DPSLM____M;
    DPVODD___V=DPVODD___M;
    DPPAS____V=DPPAS____M;

    BLCEMA___V=BLCEMA___M; 
    BLCEMS___V=BLCEMS___M; 
    BLVYGA___V=BLVYGA___M;
    BLVYGS___V=BLVYGS___M;
    BLVODP___V=BLVODP___M;
    BLOTH____V=BLOTH____M;
    BLSLM____V=BLSLM____M;
    BLVODD___V=BLVODD___M;
    BLPAS____V=BLPAS____M;

    //------------------------------------------------------------------------
    // задание отображение состояния загрузки дозаторов
    // состояние загрузки дозаторов может изменяться оператором только если
    // регулятор дозатора выключен

    // дозатор сухого
    if(DON801___M==SWITCH){
       if(REG06R___V==OFF){
              if(DON801___V==0  ){ DON801___V=1; }
         else if(DON801___V==0.2){ DON801___V=1; }
         else if(DON801___V==1  ){ DON801___V=2; }
         else if(DON801___V==2  ){ DON801___V=0; }
         else                    { DON801___V=0; }
       }
    }

    // дозатор мокрого
    if(DON802___M==SWITCH){
       if(REG07R___V==OFF){
              if(DON802___V==0  ){ DON802___V=1; }
         else if(DON802___V==0.2){ DON802___V=1; }
         else if(DON802___V==1  ){ DON802___V=2; }
         else if(DON802___V==2  ){ DON802___V=0; }
         else                    { DON802___V=0; }
       } else {
          // если мокрое загружено и выгружено и дозатор сухого или 
          // пасты набран
          if(DON802___V==1 and 
            (DON801___V==1 or DON803___V==1)){
             DON802___V = (DON802___V==1) then_ 2 else_ 1;
          }
       }
    }

    // дозатор пасты
    if(DON803___M==SWITCH){
       if(REG09R___V==OFF){
          DON803___V++; if(DON803___V>2){ DON803___V=0; }
       }
    }
    DON801___M=OFF; DON802___M=OFF; DON803___M=OFF;

    return;
}
//---------------------------------------------------------------------------
