//  coding=cp866; version=2013013112; title="";
//----------------------------------------------------------------------------
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f  far UchetInReg=1;

//----------------------------------------------------------------------------
//  Подсчет веса дозируемых компонентов
vd  far UchetCMP(vd){

    //-----------------------------------------------------------------------
    // Контроль количества дозировок отходов
    if (RegRUN==ON){
        // если вес больше 200 кг и флаг счетчика=0 увеличить счетчик загрузки
        if(AIW252___V>200 and FLAG_OTDZC==0)  { FLAG_OTDZZ++; }
        else                                  { FLAG_OTDZZ=0; }
        // если вес меньше 50  кг и флаг счетчика=1 увеличить счетчик выгрузки
        if(AIW252___V<50  and FLAG_OTDZC==1)  { FLAG_OTDZV++; }
        else                                  { FLAG_OTDZV=0; }
        //---------
        // если вес удерживается более 7 сек - считаем, что дозатор загружен
        if(AIW252___V>200 and FLAG_OTDZC==0 and FLAG_OTDZZ== 7 ){
           FLAG_OTDZC=1;
        }
        // если вес удерживается более 7 сек - считаем, что дозатор выгружен
        // (прошла одна дозировка мокрого)
        if(AIW252___V<50  and FLAG_OTDZC==1 and FLAG_OTDZV== 7 ){
           FLAG_OTDZC=0;  COUN_OTDZC++;
        }
        //---------
        if(FLAG_OTDZZ>100){ FLAG_OTDZZ=100; }
        if(FLAG_OTDZV>100){ FLAG_OTDZV=100; }
    }
    //-----------------------------------------------------------------------


/*
if(UchetInReg==0){
    // Если идет выгрузка сухого- установить флаг дозатора сухого в 1
    if(DIS193___V==ON){ FL_DZSH__V=1; }
    // Если идет выгрузка мокрого- установить флаг дозатора мокрого в 1
    if(DIS231___V==ON){ FL_DZMK__V=1; }
    // Если идет выгрузка пасты- установить флаг дозатора пасты в 1
    if(DIS291___V==ON){ FL_DZPA__V=1; }

    // Если выгрузка мокрого закончилась- флаг дозатора мокрого в 2
    if(FL_DZMK__V==1 and DIS231___V==OFF){
       FL_DZMK__V =2;
       if(CROTH____F==0 and CRSLM____F==0 and CRVODD___F==1){ CRVODD___F=2; }
       if(CROTH____F==2 and CRVODD___F==2 and CRSLM____F==1){ CRSLM____F=2; }
    }

    //------------------------------------------------------------------------
    // Если выгрузка сухого закончилась- флаг дозатора сухого в 2
    // Посчитать накопления по дозаторам сухого и мокрого и обнулить счетчики
    if(FL_DZSH__V==1 and DIS193___V==OFF){
       FL_DZSH__V =2;
       //--------
       // передача значений в переменные накопления:
       // текущая смена
       TSCEMA_CSV=TSCEMA_CSV+CRCEMA___V;
       TSCEMB_CSV=TSCEMB_CSV+CRCEMB___V;
       TSCEMS_CSV=TSCEMS_CSV+CRCEMS___V;
       TSVYGA_CSV=TSVYGA_CSV+CRVYGA___V;
       TSVYGB_CSV=TSVYGB_CSV+CRVYGB___V;
       TSVYGS_CSV=TSVYGS_CSV+CRVYGS___V;
       //
       TSVODP_CSV=TSVODP_CSV+CRVODP___V;
       TSOTH__CSV=TSOTH__CSV+CROTH____V;
       TSSLM__CSV=TSSLM__CSV+CRSLM____V;
       TSVODD_CSV=TSVODD_CSV+CRVODD___V;
       // с начала текущего месяц
       TSCEMA_CMV=TSCEMA_CMV+CRCEMA___V;
       TSCEMB_CMV=TSCEMB_CMV+CRCEMB___V;
       TSCEMS_CMV=TSCEMS_CMV+CRCEMS___V;
       TSVYGA_CMV=TSVYGA_CMV+CRVYGA___V;
       TSVYGB_CMV=TSVYGB_CMV+CRVYGB___V;
       TSVYGS_CMV=TSVYGS_CMV+CRVYGS___V;
       //
       TSVODP_CMV=TSVODP_CMV+CRVODP___V;
       TSOTH__CMV=TSOTH__CMV+CROTH____V;
       TSSLM__CMV=TSSLM__CMV+CRSLM____V;
       TSVODD_CMV=TSVODD_CMV+CRVODD___V;
       // общее накопление
       TSCEMA_NKV=TSCEMA_NKV+CRCEMA___V;
       TSCEMB_NKV=TSCEMB_NKV+CRCEMB___V;
       TSCEMS_NKV=TSCEMS_NKV+CRCEMS___V;
       TSVYGA_NKV=TSVYGA_NKV+CRVYGA___V;
       TSVYGB_NKV=TSVYGB_NKV+CRVYGB___V;
       TSVYGS_NKV=TSVYGS_NKV+CRVYGS___V;
       //
       TSVODP_NKV=TSVODP_NKV+CRVODP___V;
       TSOTH__NKV=TSOTH__NKV+CROTH____V;
       TSSLM__NKV=TSSLM__NKV+CRSLM____V;
       TSVODD_NKV=TSVODD_NKV+CRVODD___V;
       // за прошлый месяц
       if(NewMonth==1){
          TSCEMA_PMV=TSCEMA_CMV;   TSCEMA_CMV=0;
          TSCEMB_PMV=TSCEMB_CMV;   TSCEMB_CMV=0;
          TSCEMS_PMV=TSCEMS_CMV;   TSCEMS_CMV=0;
          TSVYGA_PMV=TSVYGA_CMV;   TSVYGA_CMV=0;
          TSVYGB_PMV=TSVYGB_CMV;   TSVYGB_CMV=0;
          TSVYGS_PMV=TSVYGS_CMV;   TSVYGS_CMV=0;
          //
          TSVODP_PMV=TSVODP_CMV;   TSVODP_CMV=0;
          TSOTH__PMV=TSOTH__CMV;   TSOTH__CMV=0;
          TSSLM__PMV=TSSLM__CMV;   TSSLM__CMV=0;
          TSVODD_PMV=TSVODD_CMV;   TSVODD_CMV=0;
       }
       // прошлая смена
       if(NewSmena==1){
          TSCEMA_PSV=TSCEMA_CSV;   TSCEMA_CSV=0;
          TSCEMB_PSV=TSCEMB_CSV;   TSCEMB_CSV=0;
          TSCEMS_PSV=TSCEMS_CSV;   TSCEMS_CSV=0;
          TSVYGA_PSV=TSVYGA_CSV;   TSVYGA_CSV=0;
          TSVYGB_PSV=TSVYGB_CSV;   TSVYGB_CSV=0;
          TSVYGS_PSV=TSVYGS_CSV;   TSVYGS_CSV=0;
          //
          TSVODP_PSV=TSVODP_CSV;   TSVODP_CSV=0;
          TSOTH__PSV=TSOTH__CSV;   TSOTH__CSV=0;
          TSSLM__PSV=TSSLM__CSV;   TSSLM__CSV=0;
          TSVODD_PSV=TSVODD_CSV;   TSVODD_CSV=0;
       }
       //--------
       // предыдущая дозировка
       if(FLSHPZ==1){
          FLSHPZ =0;
          TSCEMA_PZV=CRCEMA___V;
          TSCEMB_PZV=CRCEMB___V;
          TSCEMS_PZV=CRCEMS___V;
          TSVYGA_PZV=CRVYGA___V;
          TSVYGB_PZV=CRVYGB___V;
          TSVYGS_PZV=CRVYGS___V;
          //                    
          TSVODP_PZV=CRVODP___V;
          TSOTH__PZV=CROTH____V;
          TSSLM__PZV=CRSLM____V;
          TSVODD_PZV=CRVODD___V;
       }
       //--------
       // обнуление текущих счетчиков
       CRCEMA___V =0; CRCEMA___F =0;
       CRCEMB___V =0; CRCEMB___F =0;
       CRCEMS___V =0; CRCEMS___F =0;
       CRVYGA___V =0; CRVYGA___F =0;
       CRVYGB___V =0; CRVYGB___F =0;
       CRVYGS___V =0; CRVYGS___F =0;
       //
       CRVODP___V =0; CRVODP___F =0;
       CROTH____V =0; CROTH____F =0;
       CRSLM____V =0; CRSLM____F =0;
       CRVODD___V =0; CRVODD___F =0;
    }
    AIW190___P=TSCEMS_PZV+TSVYGS_PZV;
    AIW230___P=TSVODP_PZV+TSOTH__PZV+TSSLM__PZV+TSVODD_PZV;
    //------------------------------------------------------------------------


    // Если выгрузка пасты закончилась- флаг дозатора пасты в 2
    if(FL_DZPA__V==1 and DIS291___V==OFF){
       FL_DZPA__V =2;
       TSPAS__CSV=TSPAS__CSV+CRPAS____V;
       TSPAS__CMV=TSPAS__CMV+CRPAS____V;
       TSPAS__NKV=TSPAS__NKV+CRPAS____V;
       if(NewMonth==1){
          TSPAS__PMV=TSPAS__CMV;   TSPAS__CMV=0;
       }
       if(NewSmena==1){
          TSPAS__PSV=TSPAS__CSV;   TSPAS__CSV=0;
       }
       if(FLPAPZ==1){ FLPAPZ =0; TSPAS__PZV=CRPAS____V; }
//     CRPAS____V=0; 
       CRPAS____F =0;
    }

    if(FL_ZALIV_V<0 or FL_ZALIV_V>1){ FL_ZALIV_V=0; }
    // Проверка состояния герметизатора
    if(DIS31A___V==ON  and FL_ZALIV_V==0){ FL_ZALIV_V=1; }
    // Если герметизатор поднят и сухое выгружено- заливка прошла
    if(DIS31A___V==OFF and FL_ZALIV_V==1 and FL_DZSH__V==2){
       FLSHPZ    =1;
       FLPAPZ    =1;
       FLPUPZ    =1;
       FL_ZALIV_V=0;
       // При перезагрузке не учитываем
       if(FirstCall>20){
          CN_ZALCS_V++;
          CN_ZALCM_V++;
          CN_ZALNK_V++;
       }
       if(NewMonth==1){
          CN_ZALPM_V=CN_ZALCM_V; CN_ZALCM_V=0;
       }
       if(NewSmena==1){
          CN_ZALPS_V=CN_ZALCS_V; CN_ZALCS_V=0;
       }
    }
    if(NewMonth==1){ NewMonth=2; }
    if(NewSmena==1){ NewSmena=2; }


    //------------------------------------------------------------------------
    // Если идет загрузка цемента из аспирации
    if(FL_DZSH__V >1 and DIS162___V==ON){
       // Считать вес цемента из аспирации
       if(CRCEMA___F==0){ CRCEMA___F=1; SV_DZSHCAV=AIW190___V; } 
       else             { CRCEMA___V=AIW190___V-SV_DZSHCAV;    }
    }
    // Если идет загрузка цемента из бункера
    if(FL_DZSH__V >1 and DIS182___V==ON){
       // посчитать вес цемента из аспирации
       if(CRCEMA___F==1){ CRCEMA___F=2; CRCEMA___V=AIW190___V-SV_DZSHCAV; }
       // считать вес цемента из бункера
       if(CRCEMB___F==0){ CRCEMB___F=1; SV_DZSHCBV=AIW190___V; }
       else             { CRCEMB___V=AIW190___V-SV_DZSHCBV;    }
       // считать общий вес цемента
       CRCEMS___V=CRCEMA___V+CRCEMB___V;
    }
    // Если идет загрузка вяжущего из аспирации
    if(FL_DZSH__V >1 and DIS132___V==ON){
       // посчитать вес цемента из бункера
       if(CRCEMB___F==1){ CRCEMB___F=2; CRCEMB___V=AIW190___V-SV_DZSHCBV; }
       // считать вес вяжущего из аспирации
       if(CRVYGA___F==0){ CRVYGA___F=1; SV_DZSHVAV=AIW190___V; }
       else             { CRVYGA___V=AIW190___V-SV_DZSHVAV;    }
    }
    // Если идет загрузка вяжущего из бункера
    if(FL_DZSH__V >1 and DIS152___V==ON){
       // посчитать вес цемента из бункера если не считали при наборе из асп
       if(CRCEMB___F==1){ CRCEMB___F=2; CRCEMB___V=AIW190___V-SV_DZSHCBV; }
       // посчитать вес вяжущего из аспирации
       if(CRVYGA___F==1){ CRVYGA___F=2; CRVYGA___V=AIW190___V-SV_DZSHVAV; }
       // считать вес вяжущего из бункера
       if(CRVYGB___F==0){ CRVYGB___F=1; SV_DZSHVBV=AIW190___V; }
       else             { CRVYGB___V=AIW190___V-SV_DZSHVBV;    }
    }
    // Считать общий вес цемента и вяжущего
    if(FL_DZSH__V >1){
       // считать вес вяжущего (добора) из бункера
       if(CRVYGB___F==1){ CRVYGB___V=AIW190___V-SV_DZSHVBV; }
       // считать вес цемента общий
       CRCEMS___V=CRCEMA___V+CRCEMB___V;
       // считать вес вяжущего общий
       CRVYGS___V=CRVYGA___V+CRVYGB___V;
       // суммарный вес дозируемых компонентов сухого
       AIW190___E=CRCEMS___V+CRVYGS___V;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Если идет загрузка воды промывки
    if(FL_DZMK__V >1 and DIS232___V==ON){
       // считать вес воды промывки
       if(CRVODP___F==0){ CRVODP___F=1; SV_DZMKVPV=AIW230___V; } 
       else             { CRVODP___V=AIW230___V-SV_DZMKVPV;    }
    }
    // Если идет загрузка отходов
    if(FL_DZMK__V >1 and DIS211___V==ON){
       // посчитать вес воды промывки
       if(CRVODP___F==1){ CRVODP___F=2; CRVODP___V=AIW230___V-SV_DZMKVPV;    } 
       // считать вес отходов
       if(CROTH____F==0){ CROTH____F=1; SV_DZMKOTV=AIW230___V; } 
       else             { CROTH____V=AIW230___V-SV_DZMKOTV;    }
    }
    // Если идет загрузка шлама
    if(FL_DZMK__V >1 and DIS221___V==ON){
       // посчитать вес отходов
       if(CROTH____F==1){ CROTH____F=2; CROTH____V=AIW230___V-SV_DZMKOTV; }
       // Считать вес шлама
       if(CRSLM____F==0){ CRSLM____F=1; SV_DZMKSLV=AIW230___V; } 
       else             { CRSLM____V=AIW230___V-SV_DZMKSLV;    }
    }
    // Если шлам набираем последним- считать нарастающий вес к шламу
    // пока закрыт клапан выгрузки
    if(CROTH____F==2 and CRVODD___F==2 and DIS231___V==OFF){
       if(CRSLM____F==1){ CRSLM____V=AIW230___V-SV_DZMKSLV;    }
    }

    // Если идет загрузка воды доливки
    if(FL_DZMK__V >1 and (DIS202___V==ON or DIS203___V==ON)){
       if(CRSLM____F==1){ CRSLM____F=2; CRSLM____V=AIW230___V-SV_DZMKSLV; } 
       // Считать вес воды доливки
       if(CRVODD___F==0){ CRVODD___F=1; SV_DZMKVDV=AIW230___V; } 
       else             { CRVODD___V=AIW230___V-SV_DZMKVDV;    }
    }
    // Если воду доливки набираем первой- считать пока закрыт клапан выгрузки
    if(CROTH____F==0 and CRSLM____F==0 and CRVODD___F==1 and DIS231___V==OFF){ 
       CRVODD___V=AIW230___V-SV_DZMKVDV;
    }

    // суммарный вес дозируемых компонентов мокрого
    if(FL_DZMK__V >1){
       AIW230___E=CRVODP___V+CROTH____V+CRSLM____V+CRVODD___V;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // Если идет загрузка пасты- считать вес пасты
    if(FL_DZPA__V >1 and DIS281___V==ON){
       if(CRPAS____F==0){ CRPAS____F=1; SV_DZPA__V=AIW290___V; } 
    }
    if(FL_DZPA__V >1 and CRPAS____F==1){
       CRPAS____V=AIW290___V-SV_DZPA__V;
    }
    //------------------------------------------------------------------------
}


    //------------------------------------------------------------------------
    // Обнуление накоплений (DBB[2595]=FL_NAKOP_V)
    // текущая смена:
    if(FL_NAKOP_V==1){
       TSCEMA_CSV=0;
       TSCEMB_CSV=0;
       TSCEMS_CSV=0;
       TSVYGA_CSV=0;
       TSVYGB_CSV=0;
       TSVYGS_CSV=0;
       TSVODP_CSV=0;
       TSOTH__CSV=0;
       TSSLM__CSV=0;
       TSVODD_CSV=0;
       TSPAS__CSV=0;
       CN_ZALCS_V=0;
    }
    // прошлая смена:
    if(FL_NAKOP_V==2){
       TSCEMA_PSV=0;
       TSCEMB_PSV=0;
       TSCEMS_PSV=0;
       TSVYGA_PSV=0;
       TSVYGB_PSV=0;
       TSVYGS_PSV=0;
       TSVODP_PSV=0;
       TSOTH__PSV=0;
       TSSLM__PSV=0;
       TSVODD_PSV=0;
       TSPAS__PSV=0;
       CN_ZALPS_V=0;
    }
    // текущий месяц:
    if(FL_NAKOP_V==3){
       TSCEMA_CMV=0;
       TSCEMB_CMV=0;
       TSCEMS_CMV=0;
       TSVYGA_CMV=0;
       TSVYGB_CMV=0;
       TSVYGS_CMV=0;
       TSVODP_CMV=0;
       TSOTH__CMV=0;
       TSSLM__CMV=0;
       TSVODD_CMV=0;
       TSPAS__CMV=0;
       CN_ZALCM_V=0;
    }
    // прошлый месяц:
    if(FL_NAKOP_V==4){
       TSCEMA_PMV=0;
       TSCEMB_PMV=0;
       TSCEMS_PMV=0;
       TSVYGA_PMV=0;
       TSVYGB_PMV=0;
       TSVYGS_PMV=0;
       TSVODP_PMV=0;
       TSOTH__PMV=0;
       TSSLM__PMV=0;
       TSVODD_PMV=0;
       TSPAS__PMV=0;
       CN_ZALPM_V=0;
    }
    // накопление:
    if(FL_NAKOP_V==5){
       TSCEMA_NKV=0;
       TSCEMB_NKV=0;
       TSCEMS_NKV=0;
       TSVYGA_NKV=0;
       TSVYGB_NKV=0;
       TSVYGS_NKV=0;
       TSVODP_NKV=0;
       TSOTH__NKV=0;
       TSSLM__NKV=0;
       TSVODD_NKV=0;
       TSPAS__NKV=0;
       CN_ZALNK_V=0;
    }
    // прошлая заливка
    if(FL_NAKOP_V==6){
       TSCEMA_PZV=0;
       TSCEMB_PZV=0;
       TSCEMS_PZV=0;
       TSVYGA_PZV=0;
       TSVYGB_PZV=0;
       TSVYGS_PZV=0;
       TSVODP_PZV=0;
       TSOTH__PZV=0;
       TSSLM__PZV=0;
       TSVODD_PZV=0;
       TSPAS__PZV=0;
    }
    // текущая заливка
    if(FL_NAKOP_V==7){
       CRCEMA___V=0;
       CRCEMB___V=0;
       CRCEMS___V=0;
       CRVYGA___V=0;
       CRVYGB___V=0;
       CRVYGS___V=0;
       CRVODP___V=0;
       CROTH____V=0;
       CRSLM____V=0;
       CRVODD___V=0;
       CRVODV___V=0;
       CRPAS____V=0;
    }
    //------------------------------------------------------------------------

*/

    return;
}
//----------------------------------------------------------------------------
