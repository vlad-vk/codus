//----------------------------------------------------------------------------
#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"
                                                                                            
//----------------------------------------------------------------------------
//  Функция снятия сигнала с исполнителя, если сработан концевик исполнителя
//  IV(in ) - текущее
//  IT(out) - счетчик сработки концевика
//  IW(out) - флаг стабильной сработки концевика
//  OM(out) - команда на исполнитель
//  CT(out) - счетчик времени контроля сработки концевика
//  TM(in ) - время контроля сработки концевика
//  ER(out) - флаг ошибки сработки концевика
//  AK(in ) - номер автоклава
//  MS(in ) - номер сообщения при несработки исполнителя
vd  far Chk_IT(_f far   IV, _f far * IT, _f far * IW, _f far * OM,
               _f far * CT, _f far   TM, _f far * ER, ui far AK,ui far MS ){
    //  счетчик максимального кол-ва тиков
    _f  TCMX=18;
    //  счетчик сработки исполнителя в тиках (18 тиков = 1 сек)
    _f  TCON=12;
    _f  TCOF= 2;
    //  если счетчик сработки концевика меньше 1 установить его в ноль
    if(*IT<  1){ *IT=0; }
    //  если сработан концевик исполнителя
    if(IV== ON){
       // увеличить счетчик сработки концевика
       if(*IT< TCMX){ *IT=*IT+1; }
    //  если концевик исполнителя выключен
    } else {
       // уменьшить счетчик сработки концевика
       if(*IT>    0){ *IT=*IT-1; }
       // если есть команда на исполнитель и нет сигнала от концевика
       if(*OM>0){
          // увеличить счетчик времени контроля сработки концевика
          if(*CT<(TM+7)*18){
             *CT=*CT+1; 
          // если сигнала от концевика нет больше заданного времени -
          // установить флаг ошибки сработки концевика,звонок,сообщение
          } else { 
             if(*ER<1){ *ER=1; *CT=0; Bell(AK,1); Message(MS,0); }
          }
       } else {
          // если нет команды на исполнитель- уменьшить счетчик времени
          // сработки концевика
          if(*CT> 0){ *CT=*CT-1; }
          //  сбросить флаг ошибки времени ожидания сработки концевика
          *ER = 0;
       }
    }
    // установить флаг стабильного сигнала сработки исполнителя(концевика),
    // если счетчик сработки исполнителя больше заданного и сбросить счетчик
    // времени контроля сработки концевика
    if(*IT>TCON){ *IW=1; *CT=0; *ER=0; *OM=OFF; }
    // сбросить флаг сработки исполнителя(концевика)
    if(*IT<TCOF){ *IW=0; }
    return;
}
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//  Modify before sets
//  Корректировки перед установкой сигналов
vd  far Mod_BS(vd){

    //------------------------------------------------------------------------
    // Контроль времени подачи сигнала на исполнители

    // АК1
    // ЗАДВИЖКА ВПУСКА ОСТРОГО ПАРА
    Chk_IT(I1ZIOPO__V,&I1ZIOPO__T,&I1ZIOPO__W,&O1ZIOPO__M,&I1ZIOPO__C, 
                       A1TZOPO__R,&I1ZIOPO__E,          5, A1BNM+ 50);
    Chk_IT(I1ZIOPC__V,&I1ZIOPC__T,&I1ZIOPC__W,&O1ZIOPC__M,&I1ZIOPC__C,
                       A1TZOPO__R,&I1ZIOPC__E,          5, A1BNM+ 51);
    // если ошибка исполнителя- снять с него команду
    if(S1ZIOP___V==3){ O1ZIOPO__M=OFF; O1ZIOPC__M=OFF; }
    // если управление не переведено на ПК - снять команду с исполнителя
    if(I1DU_____V!=1){ O1ZIOPO__M=OFF; O1ZIOPC__M=OFF; }

    // ЗАДВИЖКА ВПУСКА ПЕРЕПУСКНОГО ПАРА                       
    Chk_IT(I1ZIPPO__V,&I1ZIPPO__T,&I1ZIPPO__W,&O1ZIPPO__M,&I1ZIPPO__C, 
                       A1TZPPO__R,&I1ZIPPO__E,          5, A1BNM+ 52);
    Chk_IT(I1ZIPPC__V,&I1ZIPPC__T,&I1ZIPPC__W,&O1ZIPPC__M,&I1ZIPPC__C,
                       A1TZPPO__R,&I1ZIPPC__E,          5, A1BNM+ 53);
    if(S1ZIPP___V==3){ O1ZIPPO__M=OFF; O1ZIPPC__M=OFF; }
    if(I1DU_____V!=1){ O1ZIPPO__M=OFF; O1ZIPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПЕРЕПУСКНОГО ПАРА                      
    Chk_IT(I1ZOPPO__V,&I1ZOPPO__T,&I1ZOPPO__W,&O1ZOPPO__M,&I1ZOPPO__C,
                       A1TZPPO__R,&I1ZOPPO__E,          5, A1BNM+ 54);
    Chk_IT(I1ZOPPC__V,&I1ZOPPC__T,&I1ZOPPC__W,&O1ZOPPC__M,&I1ZOPPC__C,
                       A1TZPPO__R,&I1ZOPPC__E,          5, A1BNM+ 55);
    if(S1ZOPP___V==3){ O1ZOPPO__M=OFF; O1ZOPPC__M=OFF; }
    if(I1DU_____V!=1){ O1ZOPPO__M=OFF; O1ZOPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПАРА В АТМОСФЕРУ                       
    Chk_IT(I1ZOPAO__V,&I1ZOPAO__T,&I1ZOPAO__W,&O1ZOPAO__M,&I1ZOPAO__C, 
                       A1TZSPA__R,&I1ZOPAO__E,          5, A1BNM+ 56);
    Chk_IT(I1ZOPAC__V,&I1ZOPAC__T,&I1ZOPAC__W,&O1ZOPAC__M,&I1ZOPAC__C, 
                       A1TZSPA__R,&I1ZOPAC__E,          5, A1BNM+ 57);
    if(S1ZOPA___V==3){ O1ZOPAO__M=OFF; O1ZOPAC__M=OFF; }
    if(I1DU_____V!=1){ O1ZOPAO__M=OFF; O1ZOPAC__M=OFF; }

    // ЗАДВИЖКА ВАКУУМА                                        
    Chk_IT(I1VZO____V,&I1VZO____T,&I1VZO____W,&O1VZO____M,&I1VZO____C,
                       A1TVZO___R,&I1VZO____E,          5, A1BNM+ 58);
    Chk_IT(I1VZC____V,&I1VZC____T,&I1VZC____W,&O1VZC____M,&I1VZC____C,
                       A1TVZO___R,&I1VZC____E,          5, A1BNM+ 59);
    if(S1VZ_____V==3){ O1VZO____M=OFF; O1VZC____M=OFF; }
    if(I1DU_____V!=1){ O1VZO____M=OFF; O1VZC____M=OFF; }

    // КЛАПАН ВПУСКА ПАРА                                     
    Chk_IT(I1KIPO___V,&I1KIPO___T,&I1KIPO___W,&O1KIPO___M,&I1KIPO___C, 
                       A1RPHKF__R,&I1KIPO___E,          5, A1BNM+ 60);
    Chk_IT(I1KIPC___V,&I1KIPC___T,&I1KIPC___W,&O1KIPC___M,&I1KIPC___C,
                       A1RPHKF__R,&I1KIPC___E,          5, A1BNM+ 61);
    if(S1KIP____V==3){ O1KIPO___M=OFF; O1KIPC___M=OFF; }
    if(I1DU_____V!=1){ O1KIPO___M=OFF; O1KIPC___M=OFF; }

    // КЛАПАН ВЫПУСКА ПАРА                                    
    Chk_IT(I1KOPO___V,&I1KOPO___T,&I1KOPO___W,&O1KOPO___M,&I1KOPO___C,
                       A1TKLO___R,&I1KOPO___E,          5, A1BNM+ 62);
    Chk_IT(I1KOPC___V,&I1KOPC___T,&I1KOPC___W,&O1KOPC___M,&I1KOPC___C, 
                       A1TKLO___R,&I1KOPC___E,          5, A1BNM+ 63);
    if(S1KOP____V==3){ O1KOPO___M=OFF; O1KOPC___M=OFF; }
    if(I1DU_____V!=1){ O1KOPO___M=OFF; O1KOPC___M=OFF; }

    // КЛАПАН СБРОСА КОНДЕНСАТА                                            
    Chk_IT(I1KOCO___V,&I1KOCO___T,&I1KOCO___W,&O1KOCO___M,&I1KOCO___C,
                       A1RCHKF__R,&I1KOCO___E,          5, A1BNM+ 64);
    Chk_IT(I1KOCC___V,&I1KOCC___T,&I1KOCC___W,&O1KOCC___M,&I1KOCC___C,
                       A1RCHKF__R,&I1KOCC___E,          5, A1BNM+ 65);
    if(S1KOC____V==3){ O1KOCO___M=OFF; O1KOCC___M=OFF; }
    if(I1DU_____V!=1){ O1KOCO___M=OFF; O1KOCC___M=OFF; }

    // ХОМУТ  1 (СЛЕВА)                                                    
    Chk_IT(I1HM1UP__V,&I1HM1UP__T,&I1HM1UP__W,&O1HM1UP__M,&I1HM1UP__C,
                       A1THMUP__R,&I1HM1UP__E,          5, A1BNM+ 66);
    Chk_IT(I1HM1DN__V,&I1HM1DN__T,&I1HM1DN__W,&O1HM1DN__M,&I1HM1DN__C, 
                       A1THMUP__R,&I1HM1DN__E,          5, A1BNM+ 67);
    if(S1HM1____V==3){ O1HM1UP__M=OFF; O1HM1DN__M=OFF; }
    if(I1DU_____V!=1){ O1HM1UP__M=OFF; O1HM1DN__M=OFF; }

    // КРЫШКА 1 (СЛЕВА)                                                    
    Chk_IT(I1KR1O___V,&I1KR1O___T,&I1KR1O___W,&O1KR1O___M,&I1KR1O___C, 
                       A1TKRO___R,&I1KR1O___E,          5, A1BNM+ 68);
    Chk_IT(I1KR1C___V,&I1KR1C___T,&I1KR1C___W,&O1KR1C___M,&I1KR1C___C,
                       A1TKRC___R,&I1KR1C___E,          5, A1BNM+ 69);
    if(S1KR1____V==3){ O1KR1O___M=OFF; O1KR1C___M=OFF; }
    if(I1DU_____V!=1){ O1KR1O___M=OFF; O1KR1C___M=OFF; }

    // БАЙОНЕТ1 (СЛЕВА)                                                    
    Chk_IT(I1BY1O___V,&I1BY1O___T,&I1BY1O___W,&O1BY1O___M,&I1BY1O___C,
                       A1TBYRT__R,&I1BY1O___E,          5, A1BNM+ 70);
    Chk_IT(I1BY1C___V,&I1BY1C___T,&I1BY1C___W,&O1BY1C___M,&I1BY1C___C,
                       A1TBYRT__R,&I1BY1C___E,          5, A1BNM+ 71);
    if(S1BY1____V==3){ O1BY1O___M=OFF; O1BY1C___M=OFF; }
    if(I1DU_____V!=1){ O1BY1O___M=OFF; O1BY1C___M=OFF; }

    // ХОМУТ  2 (СПРАВА)                                                                  
    Chk_IT(I1HM2UP__V,&I1HM2UP__T,&I1HM2UP__W,&O1HM2UP__M,&I1HM2UP__C,
                       A1THMUP__R,&I1HM2UP__E,          5, A1BNM+ 72);
    Chk_IT(I1HM2DN__V,&I1HM2DN__T,&I1HM2DN__W,&O1HM2DN__M,&I1HM2DN__C,
                       A1THMUP__R,&I1HM2DN__E,          5, A1BNM+ 73);
    if(S1HM2____V==3){ O1HM2UP__M=OFF; O1HM2DN__M=OFF; }
    if(I1DU_____V!=1){ O1HM2UP__M=OFF; O1HM2DN__M=OFF; }

    // КРЫШКА 2 (СПРАВА)                                                   
    Chk_IT(I1KR2O___V,&I1KR2O___T,&I1KR2O___W,&O1KR2O___M,&I1KR2O___C,
                       A1TKRO___R,&I1KR2O___E,          5, A1BNM+ 74);
    Chk_IT(I1KR2C___V,&I1KR2C___T,&I1KR2C___W,&O1KR2C___M,&I1KR2C___C,
                       A1TKRC___R,&I1KR2C___E,          5, A1BNM+ 75);
    if(S1KR2____V==3){ O1KR2O___M=OFF; O1KR2C___M=OFF; }
    if(I1DU_____V!=1){ O1KR2O___M=OFF; O1KR2C___M=OFF; }

    // БАЙОНЕТ2 (СПРАВА)                                                   
    Chk_IT(I1BY2O___V,&I1BY2O___T,&I1BY2O___W,&O1BY2O___M,&I1BY2O___C,
                       A1TBYRT__R,&I1BY2O___E,          5, A1BNM+ 76);
    Chk_IT(I1BY2C___V,&I1BY2C___T,&I1BY2C___W,&O1BY2C___M,&I1BY2C___C,
                       A1TBYRT__R,&I1BY2C___E,          5, A1BNM+ 77);
    if(S1BY2____V==3){ O1BY2O___M=OFF; O1BY2C___M=OFF; }
    if(I1DU_____V!=1){ O1BY2O___M=OFF; O1BY2C___M=OFF; }


    // АК2
    // ЗАДВИЖКА ВПУСКА ОСТРОГО ПАРА
    Chk_IT(I2ZIOPO__V,&I2ZIOPO__T,&I2ZIOPO__W,&O2ZIOPO__M,&I2ZIOPO__C, 
                       A2TZOPO__R,&I2ZIOPO__E,          6, A2BNM+ 50);
    Chk_IT(I2ZIOPC__V,&I2ZIOPC__T,&I2ZIOPC__W,&O2ZIOPC__M,&I2ZIOPC__C,
                       A2TZOPO__R,&I2ZIOPC__E,          6, A2BNM+ 51);
    if(S2ZIOP___V==3){ O2ZIOPO__M=OFF; O2ZIOPC__M=OFF; }
    if(I2DU_____V!=1){ O2ZIOPO__M=OFF; O2ZIOPC__M=OFF; }

    // ЗАДВИЖКА ВПУСКА ПЕРЕПУСКНОГО ПАРА                                       
    Chk_IT(I2ZIPPO__V,&I2ZIPPO__T,&I2ZIPPO__W,&O2ZIPPO__M,&I2ZIPPO__C,
                       A2TZPPO__R,&I2ZIPPO__E,          6, A2BNM+ 52);
    Chk_IT(I2ZIPPC__V,&I2ZIPPC__T,&I2ZIPPC__W,&O2ZIPPC__M,&I2ZIPPC__C,
                       A2TZPPO__R,&I2ZIPPC__E,          6, A2BNM+ 53);
    if(S2ZIPP___V==3){ O2ZIPPO__M=OFF; O2ZIPPC__M=OFF; }
    if(I2DU_____V!=1){ O2ZIPPO__M=OFF; O2ZIPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПЕРЕПУСКНОГО ПАРА                                      
    Chk_IT(I2ZOPPO__V,&I2ZOPPO__T,&I2ZOPPO__W,&O2ZOPPO__M,&I2ZOPPO__C,
                       A2TZPPO__R,&I2ZOPPO__E,          6, A2BNM+ 54);
    Chk_IT(I2ZOPPC__V,&I2ZOPPC__T,&I2ZOPPC__W,&O2ZOPPC__M,&I2ZOPPC__C, 
                       A2TZPPO__R,&I2ZOPPC__E,          6, A2BNM+ 55);
    if(S2ZOPP___V==3){ O2ZOPPO__M=OFF; O2ZOPPC__M=OFF; }
    if(I2DU_____V!=1){ O2ZOPPO__M=OFF; O2ZOPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПАРА В АТМОСФЕРУ                                       
    Chk_IT(I2ZOPAO__V,&I2ZOPAO__T,&I2ZOPAO__W,&O2ZOPAO__M,&I2ZOPAO__C, 
                       A2TZSPA__R,&I2ZOPAO__E,          6, A2BNM+ 56);
    Chk_IT(I2ZOPAC__V,&I2ZOPAC__T,&I2ZOPAC__W,&O2ZOPAC__M,&I2ZOPAC__C, 
                       A2TZSPA__R,&I2ZOPAC__E,          6, A2BNM+ 57);
    if(S2ZOPA___V==3){ O2ZOPAO__M=OFF; O2ZOPAC__M=OFF; }
    if(I2DU_____V!=1){ O2ZOPAO__M=OFF; O2ZOPAC__M=OFF; }

    // ЗАДВИЖКА ВАКУУМА                                                        
    Chk_IT(I2VZO____V,&I2VZO____T,&I2VZO____W,&O2VZO____M,&I2VZO____C, 
                       A2TVZO___R,&I2VZO____E,          6, A2BNM+ 58);
    Chk_IT(I2VZC____V,&I2VZC____T,&I2VZC____W,&O2VZC____M,&I2VZC____C, 
                       A2TVZO___R,&I2VZC____E,          6, A2BNM+ 59);
    if(S2VZ_____V==3){ O2VZO____M=OFF; O2VZC____M=OFF; }
    if(I2DU_____V!=1){ O2VZO____M=OFF; O2VZC____M=OFF; }

    // КЛАПАН ВПУСКА ПАРА                                         
    Chk_IT(I2KIPO___V,&I2KIPO___T,&I2KIPO___W,&O2KIPO___M,&I2KIPO___C, 
                       A2RPHKF__R,&I2KIPO___E,          6, A2BNM+ 60);
    Chk_IT(I2KIPC___V,&I2KIPC___T,&I2KIPC___W,&O2KIPC___M,&I2KIPC___C, 
                       A2RPHKF__R,&I2KIPC___E,          6, A2BNM+ 61);
    if(S2KIP____V==3){ O2KIPO___M=OFF; O2KIPC___M=OFF; }
    if(I2DU_____V!=1){ O2KIPO___M=OFF; O2KIPC___M=OFF; }

    // КЛАПАН ВЫПУСКА ПАРА                                        
    Chk_IT(I2KOPO___V,&I2KOPO___T,&I2KOPO___W,&O2KOPO___M,&I2KOPO___C, 
                       A2TKLO___R,&I2KOPO___E,          6, A2BNM+ 62);
    Chk_IT(I2KOPC___V,&I2KOPC___T,&I2KOPC___W,&O2KOPC___M,&I2KOPC___C, 
                       A2TKLO___R,&I2KOPC___E,          6, A2BNM+ 63);
    if(S2KOP____V==3){ O2KOPO___M=OFF; O2KOPC___M=OFF; }
    if(I2DU_____V!=1){ O2KOPO___M=OFF; O2KOPC___M=OFF; }

    // КЛАПАН СБРОСА КОНДЕНСАТА                                                
    Chk_IT(I2KOCO___V,&I2KOCO___T,&I2KOCO___W,&O2KOCO___M,&I2KOCO___C, 
                       A2RCHKF__R,&I2KOCO___E,          6, A2BNM+ 64);
    Chk_IT(I2KOCC___V,&I2KOCC___T,&I2KOCC___W,&O2KOCC___M,&I2KOCC___C, 
                       A2RCHKF__R,&I2KOCC___E,          6, A2BNM+ 65);
    if(S2KOC____V==3){ O2KOCO___M=OFF; O2KOCC___M=OFF; }
    if(I2DU_____V!=1){ O2KOCO___M=OFF; O2KOCC___M=OFF; }

    // ХОМУТ  1 (СЛЕВА)                                                        
    Chk_IT(I2HM1UP__V,&I2HM1UP__T,&I2HM1UP__W,&O2HM1UP__M,&I2HM1UP__C, 
                       A2THMUP__R,&I2HM1UP__E,          6, A2BNM+ 66);
    Chk_IT(I2HM1DN__V,&I2HM1DN__T,&I2HM1DN__W,&O2HM1DN__M,&I2HM1DN__C,
                       A2THMUP__R,&I2HM1DN__E,          6, A2BNM+ 67);
    if(S2HM1____V==3){ O2HM1UP__M=OFF; O2HM1DN__M=OFF; }
    if(I2DU_____V!=1){ O2HM1UP__M=OFF; O2HM1DN__M=OFF; }

    // КРЫШКА 1 (СЛЕВА)                                                        
    Chk_IT(I2KR1O___V,&I2KR1O___T,&I2KR1O___W,&O2KR1O___M,&I2KR1O___C, 
                       A2TKRO___R,&I2KR1O___E,          6, A2BNM+ 68);
    Chk_IT(I2KR1C___V,&I2KR1C___T,&I2KR1C___W,&O2KR1C___M,&I2KR1C___C,
                       A2TKRC___R,&I2KR1C___E,          6, A2BNM+ 69);
    if(S2KR1____V==3){ O2KR1O___M=OFF; O2KR1C___M=OFF; }
    if(I2DU_____V!=1){ O2KR1O___M=OFF; O2KR1C___M=OFF; }

    // БАЙОНЕТ1 (СЛЕВА)                                                        
    Chk_IT(I2BY1O___V,&I2BY1O___T,&I2BY1O___W,&O2BY1O___M,&I2BY1O___C, 
                       A2TBYRT__R,&I2BY1O___E,          6, A2BNM+ 70);
    Chk_IT(I2BY1C___V,&I2BY1C___T,&I2BY1C___W,&O2BY1C___M,&I2BY1C___C,
                       A2TBYRT__R,&I2BY1C___E,          6, A2BNM+ 71);
    if(S2BY1____V==3){ O2BY1O___M=OFF; O2BY1C___M=OFF; }
    if(I2DU_____V!=1){ O2BY1O___M=OFF; O2BY1C___M=OFF; }

    // ХОМУТ  2 (СПРАВА)                                                       
    Chk_IT(I2HM2UP__V,&I2HM2UP__T,&I2HM2UP__W,&O2HM2UP__M,&I2HM2UP__C,
                       A2THMUP__R,&I2HM2UP__E,          6, A2BNM+ 72);
    Chk_IT(I2HM2DN__V,&I2HM2DN__T,&I2HM2DN__W,&O2HM2DN__M,&I2HM2DN__C, 
                       A2THMUP__R,&I2HM2DN__E,          6, A2BNM+ 73);
    if(S2HM2____V==3){ O2HM2UP__M=OFF; O2HM2DN__M=OFF; }
    if(I2DU_____V!=1){ O2HM2UP__M=OFF; O2HM2DN__M=OFF; }

    // КРЫШКА 2 (СПРАВА)                                                       
    Chk_IT(I2KR2O___V,&I2KR2O___T,&I2KR2O___W,&O2KR2O___M,&I2KR2O___C, 
                       A2TKRO___R,&I2KR2O___E,          6, A2BNM+ 74);
    Chk_IT(I2KR2C___V,&I2KR2C___T,&I2KR2C___W,&O2KR2C___M,&I2KR2C___C, 
                       A2TKRC___R,&I2KR2C___E,          6, A2BNM+ 75);
    if(S2KR2____V==3){ O2KR2O___M=OFF; O2KR2C___M=OFF; }
    if(I2DU_____V!=1){ O2KR2O___M=OFF; O2KR2C___M=OFF; }

    // БАЙОНЕТ2 (СПРАВА)                                                       
    Chk_IT(I2BY2O___V,&I2BY2O___T,&I2BY2O___W,&O2BY2O___M,&I2BY2O___C, 
                       A2TBYRT__R,&I2BY2O___E,          6, A2BNM+ 76);
    Chk_IT(I2BY2C___V,&I2BY2C___T,&I2BY2C___W,&O2BY2C___M,&I2BY2C___C,
                       A2TBYRT__R,&I2BY2C___E,          6, A2BNM+ 77);
    if(S2BY2____V==3){ O2BY2O___M=OFF; O2BY2C___M=OFF; }
    if(I2DU_____V!=1){ O2BY2O___M=OFF; O2BY2C___M=OFF; }

    return;                                                                 
}
//----------------------------------------------------------------------------
