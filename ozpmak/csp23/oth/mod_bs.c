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

    // АК5
    // ЗАДВИЖКА ВПУСКА ОСТРОГО ПАРА
    Chk_IT(I3ZIOPO__V,&I3ZIOPO__T,&I3ZIOPO__W,&O3ZIOPO__M,&I3ZIOPO__C, 
                       A3TZOPO__R,&I3ZIOPO__E,          5, A3BNM+ 50);
    Chk_IT(I3ZIOPC__V,&I3ZIOPC__T,&I3ZIOPC__W,&O3ZIOPC__M,&I3ZIOPC__C,
                       A3TZOPO__R,&I3ZIOPC__E,          5, A3BNM+ 51);
    // если ошибка исполнителя- снять с него комманду
    if(S3ZIOP___V==3){ O3ZIOPO__M=OFF; O3ZIOPC__M=OFF; }
    // если управление не переведено на ПК - снять команду с исполнителя
    if(I3DU_____V!=1){ O3ZIOPO__M=OFF; O3ZIOPC__M=OFF; }

    // ЗАДВИЖКА ВПУСКА ПЕРЕПУСКНОГО ПАРА                       
    Chk_IT(I3ZIPPO__V,&I3ZIPPO__T,&I3ZIPPO__W,&O3ZIPPO__M,&I3ZIPPO__C, 
                       A3TZPPO__R,&I3ZIPPO__E,          5, A3BNM+ 52);
    Chk_IT(I3ZIPPC__V,&I3ZIPPC__T,&I3ZIPPC__W,&O3ZIPPC__M,&I3ZIPPC__C,
                       A3TZPPO__R,&I3ZIPPC__E,          5, A3BNM+ 53);
    if(S3ZIPP___V==3){ O3ZIPPO__M=OFF; O3ZIPPC__M=OFF; }
    if(I3DU_____V!=1){ O3ZIPPO__M=OFF; O3ZIPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПЕРЕПУСКНОГО ПАРА                      
    Chk_IT(I3ZOPPO__V,&I3ZOPPO__T,&I3ZOPPO__W,&O3ZOPPO__M,&I3ZOPPO__C,
                       A3TZPPO__R,&I3ZOPPO__E,          5, A3BNM+ 54);
    Chk_IT(I3ZOPPC__V,&I3ZOPPC__T,&I3ZOPPC__W,&O3ZOPPC__M,&I3ZOPPC__C,
                       A3TZPPO__R,&I3ZOPPC__E,          5, A3BNM+ 55);
    if(S3ZOPP___V==3){ O3ZOPPO__M=OFF; O3ZOPPC__M=OFF; }
    if(I3DU_____V!=1){ O3ZOPPO__M=OFF; O3ZOPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПАРА В АТМОСФЕРУ                       
    Chk_IT(I3ZOPAO__V,&I3ZOPAO__T,&I3ZOPAO__W,&O3ZOPAO__M,&I3ZOPAO__C, 
                       A3TZSPA__R,&I3ZOPAO__E,          5, A3BNM+ 56);
    Chk_IT(I3ZOPAC__V,&I3ZOPAC__T,&I3ZOPAC__W,&O3ZOPAC__M,&I3ZOPAC__C, 
                       A3TZSPA__R,&I3ZOPAC__E,          5, A3BNM+ 57);
    if(S3ZOPA___V==3){ O3ZOPAO__M=OFF; O3ZOPAC__M=OFF; }
    if(I3DU_____V!=1){ O3ZOPAO__M=OFF; O3ZOPAC__M=OFF; }

    // ЗАДВИЖКА ВАКУУМА                                        
    Chk_IT(I3VZO____V,&I3VZO____T,&I3VZO____W,&O3VZO____M,&I3VZO____C,
                       A3TVZO___R,&I3VZO____E,          5, A3BNM+ 58);
    Chk_IT(I3VZC____V,&I3VZC____T,&I3VZC____W,&O3VZC____M,&I3VZC____C,
                       A3TVZO___R,&I3VZC____E,          5, A3BNM+ 59);
    if(S3VZ_____V==3){ O3VZO____M=OFF; O3VZC____M=OFF; }
    if(I3DU_____V!=1){ O3VZO____M=OFF; O3VZC____M=OFF; }

    // КЛАПАН ВПУСКА ПАРА                                     
    Chk_IT(I3KIPO___V,&I3KIPO___T,&I3KIPO___W,&O3KIPO___M,&I3KIPO___C, 
                       A3RPHKF__R,&I3KIPO___E,          5, A3BNM+ 60);
    Chk_IT(I3KIPC___V,&I3KIPC___T,&I3KIPC___W,&O3KIPC___M,&I3KIPC___C,
                       A3RPHKF__R,&I3KIPC___E,          5, A3BNM+ 61);
    if(S3KIP____V==3){ O3KIPO___M=OFF; O3KIPC___M=OFF; }
    if(I3DU_____V!=1){ O3KIPO___M=OFF; O3KIPC___M=OFF; }

    // КЛАПАН ВЫПУСКА ПАРА                                    
    Chk_IT(I3KOPO___V,&I3KOPO___T,&I3KOPO___W,&O3KOPO___M,&I3KOPO___C,
                       A3TKLO___R,&I3KOPO___E,          5, A3BNM+ 62);
    Chk_IT(I3KOPC___V,&I3KOPC___T,&I3KOPC___W,&O3KOPC___M,&I3KOPC___C, 
                       A3TKLO___R,&I3KOPC___E,          5, A3BNM+ 63);
    if(S3KOP____V==3){ O3KOPO___M=OFF; O3KOPC___M=OFF; }
    if(I3DU_____V!=1){ O3KOPO___M=OFF; O3KOPC___M=OFF; }

    // КЛАПАН СБРОСА КОНДЕНСАТА                                            
    Chk_IT(I3KOCO___V,&I3KOCO___T,&I3KOCO___W,&O3KOCO___M,&I3KOCO___C,
                       A3RCHKF__R,&I3KOCO___E,          5, A3BNM+ 64);
    Chk_IT(I3KOCC___V,&I3KOCC___T,&I3KOCC___W,&O3KOCC___M,&I3KOCC___C,
                       A3RCHKF__R,&I3KOCC___E,          5, A3BNM+ 65);
    if(S3KOC____V==3){ O3KOCO___M=OFF; O3KOCC___M=OFF; }
    if(I3DU_____V!=1){ O3KOCO___M=OFF; O3KOCC___M=OFF; }

    // ХОМУТ  1 (СЛЕВА)                                                    
    Chk_IT(I3HM1UP__V,&I3HM1UP__T,&I3HM1UP__W,&O3HM1UP__M,&I3HM1UP__C,
                       A3THMUP__R,&I3HM1UP__E,          5, A3BNM+ 66);
    Chk_IT(I3HM1DN__V,&I3HM1DN__T,&I3HM1DN__W,&O3HM1DN__M,&I3HM1DN__C, 
                       A3THMUP__R,&I3HM1DN__E,          5, A3BNM+ 67);
    if(S3HM1____V==3){ O3HM1UP__M=OFF; O3HM1DN__M=OFF; }
    if(I3DU_____V!=1){ O3HM1UP__M=OFF; O3HM1DN__M=OFF; }

    // КРЫШКА 1 (СЛЕВА)                                                    
    Chk_IT(I3KR1O___V,&I3KR1O___T,&I3KR1O___W,&O3KR1O___M,&I3KR1O___C, 
                       A3TKRO___R,&I3KR1O___E,          5, A3BNM+ 68);
    Chk_IT(I3KR1C___V,&I3KR1C___T,&I3KR1C___W,&O3KR1C___M,&I3KR1C___C,
                       A3TKRC___R,&I3KR1C___E,          5, A3BNM+ 69);
    if(S3KR1____V==3){ O3KR1O___M=OFF; O3KR1C___M=OFF; }
    if(I3DU_____V!=1){ O3KR1O___M=OFF; O3KR1C___M=OFF; }

    // БАЙОНЕТ1 (СЛЕВА)                                                    
    Chk_IT(I3BY1O___V,&I3BY1O___T,&I3BY1O___W,&O3BY1O___M,&I3BY1O___C,
                       A3TBYRT__R,&I3BY1O___E,          5, A3BNM+ 70);
    Chk_IT(I3BY1C___V,&I3BY1C___T,&I3BY1C___W,&O3BY1C___M,&I3BY1C___C,
                       A3TBYRT__R,&I3BY1C___E,          5, A3BNM+ 71);
    if(S3BY1____V==3){ O3BY1O___M=OFF; O3BY1C___M=OFF; }
    if(I3DU_____V!=1){ O3BY1O___M=OFF; O3BY1C___M=OFF; }


    // АК6
    // ЗАДВИЖКА ВПУСКА ОСТРОГО ПАРА
    Chk_IT(I4ZIOPO__V,&I4ZIOPO__T,&I4ZIOPO__W,&O4ZIOPO__M,&I4ZIOPO__C, 
                       A4TZOPO__R,&I4ZIOPO__E,          6, A4BNM+ 50);
    Chk_IT(I4ZIOPC__V,&I4ZIOPC__T,&I4ZIOPC__W,&O4ZIOPC__M,&I4ZIOPC__C,
                       A4TZOPO__R,&I4ZIOPC__E,          6, A4BNM+ 51);
    if(S4ZIOP___V==3){ O4ZIOPO__M=OFF; O4ZIOPC__M=OFF; }
    if(I4DU_____V!=1){ O4ZIOPO__M=OFF; O4ZIOPC__M=OFF; }

    // ЗАДВИЖКА ВПУСКА ПЕРЕПУСКНОГО ПАРА                                       
    Chk_IT(I4ZIPPO__V,&I4ZIPPO__T,&I4ZIPPO__W,&O4ZIPPO__M,&I4ZIPPO__C,
                       A4TZPPO__R,&I4ZIPPO__E,          6, A4BNM+ 52);
    Chk_IT(I4ZIPPC__V,&I4ZIPPC__T,&I4ZIPPC__W,&O4ZIPPC__M,&I4ZIPPC__C,
                       A4TZPPO__R,&I4ZIPPC__E,          6, A4BNM+ 53);
    if(S4ZIPP___V==3){ O4ZIPPO__M=OFF; O4ZIPPC__M=OFF; }
    if(I4DU_____V!=1){ O4ZIPPO__M=OFF; O4ZIPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПЕРЕПУСКНОГО ПАРА                                      
    Chk_IT(I4ZOPPO__V,&I4ZOPPO__T,&I4ZOPPO__W,&O4ZOPPO__M,&I4ZOPPO__C,
                       A4TZPPO__R,&I4ZOPPO__E,          6, A4BNM+ 54);
    Chk_IT(I4ZOPPC__V,&I4ZOPPC__T,&I4ZOPPC__W,&O4ZOPPC__M,&I4ZOPPC__C, 
                       A4TZPPO__R,&I4ZOPPC__E,          6, A4BNM+ 55);
    if(S4ZOPP___V==3){ O4ZOPPO__M=OFF; O4ZOPPC__M=OFF; }
    if(I4DU_____V!=1){ O4ZOPPO__M=OFF; O4ZOPPC__M=OFF; }

    // ЗАДВИЖКА ВЫПУСКА ПАРА В АТМОСФЕРУ                                       
    Chk_IT(I4ZOPAO__V,&I4ZOPAO__T,&I4ZOPAO__W,&O4ZOPAO__M,&I4ZOPAO__C, 
                       A4TZSPA__R,&I4ZOPAO__E,          6, A4BNM+ 56);
    Chk_IT(I4ZOPAC__V,&I4ZOPAC__T,&I4ZOPAC__W,&O4ZOPAC__M,&I4ZOPAC__C, 
                       A4TZSPA__R,&I4ZOPAC__E,          6, A4BNM+ 57);
    if(S4ZOPA___V==3){ O4ZOPAO__M=OFF; O4ZOPAC__M=OFF; }
    if(I4DU_____V!=1){ O4ZOPAO__M=OFF; O4ZOPAC__M=OFF; }

    // ЗАДВИЖКА ВАКУУМА                                                        
    Chk_IT(I4VZO____V,&I4VZO____T,&I4VZO____W,&O4VZO____M,&I4VZO____C, 
                       A4TVZO___R,&I4VZO____E,          6, A4BNM+ 58);
    Chk_IT(I4VZC____V,&I4VZC____T,&I4VZC____W,&O4VZC____M,&I4VZC____C, 
                       A4TVZO___R,&I4VZC____E,          6, A4BNM+ 59);
    if(S4VZ_____V==3){ O4VZO____M=OFF; O4VZC____M=OFF; }
    if(I4DU_____V!=1){ O4VZO____M=OFF; O4VZC____M=OFF; }

    // КЛАПАН ВПУСКА ПАРА                                         
    Chk_IT(I4KIPO___V,&I4KIPO___T,&I4KIPO___W,&O4KIPO___M,&I4KIPO___C, 
                       A4RPHKF__R,&I4KIPO___E,          6, A4BNM+ 60);
    Chk_IT(I4KIPC___V,&I4KIPC___T,&I4KIPC___W,&O4KIPC___M,&I4KIPC___C, 
                       A4RPHKF__R,&I4KIPC___E,          6, A4BNM+ 61);
    if(S4KIP____V==3){ O4KIPO___M=OFF; O4KIPC___M=OFF; }
    if(I4DU_____V!=1){ O4KIPO___M=OFF; O4KIPC___M=OFF; }

    // КЛАПАН ВЫПУСКА ПАРА                                        
    Chk_IT(I4KOPO___V,&I4KOPO___T,&I4KOPO___W,&O4KOPO___M,&I4KOPO___C, 
                       A4TKLO___R,&I4KOPO___E,          6, A4BNM+ 62);
    Chk_IT(I4KOPC___V,&I4KOPC___T,&I4KOPC___W,&O4KOPC___M,&I4KOPC___C, 
                       A4TKLO___R,&I4KOPC___E,          6, A4BNM+ 63);
    if(S4KOP____V==3){ O4KOPO___M=OFF; O4KOPC___M=OFF; }
    if(I4DU_____V!=1){ O4KOPO___M=OFF; O4KOPC___M=OFF; }

    // КЛАПАН СБРОСА КОНДЕНСАТА                                                
    Chk_IT(I4KOCO___V,&I4KOCO___T,&I4KOCO___W,&O4KOCO___M,&I4KOCO___C, 
                       A4RCHKF__R,&I4KOCO___E,          6, A4BNM+ 64);
    Chk_IT(I4KOCC___V,&I4KOCC___T,&I4KOCC___W,&O4KOCC___M,&I4KOCC___C, 
                       A4RCHKF__R,&I4KOCC___E,          6, A4BNM+ 65);
    if(S4KOC____V==3){ O4KOCO___M=OFF; O4KOCC___M=OFF; }
    if(I4DU_____V!=1){ O4KOCO___M=OFF; O4KOCC___M=OFF; }

    // ХОМУТ  1 (СЛЕВА)                                                        
    Chk_IT(I4HM1UP__V,&I4HM1UP__T,&I4HM1UP__W,&O4HM1UP__M,&I4HM1UP__C, 
                       A4THMUP__R,&I4HM1UP__E,          6, A4BNM+ 66);
    Chk_IT(I4HM1DN__V,&I4HM1DN__T,&I4HM1DN__W,&O4HM1DN__M,&I4HM1DN__C,
                       A4THMUP__R,&I4HM1DN__E,          6, A4BNM+ 67);
    if(S4HM1____V==3){ O4HM1UP__M=OFF; O4HM1DN__M=OFF; }
    if(I4DU_____V!=1){ O4HM1UP__M=OFF; O4HM1DN__M=OFF; }

    // КРЫШКА 1 (СЛЕВА)                                                        
    Chk_IT(I4KR1O___V,&I4KR1O___T,&I4KR1O___W,&O4KR1O___M,&I4KR1O___C, 
                       A4TKRO___R,&I4KR1O___E,          6, A4BNM+ 68);
    Chk_IT(I4KR1C___V,&I4KR1C___T,&I4KR1C___W,&O4KR1C___M,&I4KR1C___C,
                       A4TKRC___R,&I4KR1C___E,          6, A4BNM+ 69);
    if(S4KR1____V==3){ O4KR1O___M=OFF; O4KR1C___M=OFF; }
    if(I4DU_____V!=1){ O4KR1O___M=OFF; O4KR1C___M=OFF; }

    // БАЙОНЕТ1 (СЛЕВА)                                                        
    Chk_IT(I4BY1O___V,&I4BY1O___T,&I4BY1O___W,&O4BY1O___M,&I4BY1O___C, 
                       A4TBYRT__R,&I4BY1O___E,          6, A4BNM+ 70);
    Chk_IT(I4BY1C___V,&I4BY1C___T,&I4BY1C___W,&O4BY1C___M,&I4BY1C___C,
                       A4TBYRT__R,&I4BY1C___E,          6, A4BNM+ 71);
    if(S4BY1____V==3){ O4BY1O___M=OFF; O4BY1C___M=OFF; }
    if(I4DU_____V!=1){ O4BY1O___M=OFF; O4BY1C___M=OFF; }

    return;                                                                 
}
//----------------------------------------------------------------------------
