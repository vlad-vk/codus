//---------------------------------------------------------------------------
#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "other_e.h"

//----------------------------------------------------------------------------
//  Проверка сработки исполнителей (вызывается раз в секунду):
vd  far CheckIsp(vd){
    if (TIME_ISPPW<1 or TIME_ISPPW>5){ TIME_ISPPW=1; }

    //----------------------------------------------------
    // если сигнал (DON011___V), посылаемый контроллером на исполнитель
    // не совпадает с сигналом (DIS011___V), приходящим с исполнителя и
    // исполнитель находится в автоматическом режиме работы
    if ( DON011___V != DIS011___V and DIR010___V == ON ){
         // если за определенное время исполнитель не сработал
         if ( Check_TO(100,  TIME_ISPKV,  ZERO,'=',ON,  1 ) == OFF ){
              // выдать сообщение оператору и установить флаг ошибки
              if(DON011___V==ON  and DIS011___V==OFF){ Message(500); }
              if(DON011___V==OFF and DIS011___V==ON ){ Message(600); }
              DIS011W = ON;
         }
         // если установлен флаг ошибки попеременно вкл-выкл выделение
         // исполнителя на экране
         if ( DIS011W == ON ){
              DIS011W__V = ( DIS011W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS011W__V = OFF; DIS011W = OFF; Clear_TO(100); }
    //----------------------------------------------------


    //----------------------------------------------------
    //   DIS012___V  - клапан загрузки шлама в пневмонасос шлама N1
    if ( DON012___V != DIS012___V and DIR010___V == ON ){
         if ( Check_TO(101,  TIME_ISPKV,  ZERO,'=',ON,  1 ) == OFF ){
              if(DON012___V==ON  and DIS012___V==OFF){ Message(501); }
              if(DON012___V==OFF and DIS012___V==ON ){ Message(601); }
              DIS012W = ON;
         }
         if ( DIS012W == ON ){
              DIS012W__V = ( DIS012W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS012W__V = OFF; DIS012W = OFF; Clear_TO(101); }
    //----------------------------------------------------
    //   DIS021___V  - клапан подачи воздуха в пневмонасос шлама N2
    if ( DON021___V != DIS021___V and DIR020___V == ON ){
         if ( Check_TO(102,  TIME_ISPKV,  ZERO,'=',ON,  1 ) == OFF ){
              if(DON021___V==ON  and DIS021___V==OFF){ Message(502); }
              if(DON021___V==OFF and DIS021___V==ON ){ Message(602); }
              DIS021W = ON;
         }
         if ( DIS021W == ON ){
              DIS021W__V = ( DIS021W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS021W__V = OFF; DIS021W = OFF; Clear_TO(102); }
    //----------------------------------------------------
    //   DIS022___V  - клапан загрузки шлама в пневмонасос шлама N2
    if ( DON022___V != DIS022___V and DIR020___V == ON ){
         if ( Check_TO(103,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON022___V==ON  and DIS022___V==OFF){ Message(503); }
              if(DON022___V==OFF and DIS022___V==ON ){ Message(603); }
              DIS022W = ON;
         }
         if ( DIS022W == ON ){
              DIS022W__V = ( DIS022W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS022W__V = OFF; DIS022W = OFF; Clear_TO(103); }
    //----------------------------------------------------
    //   DIS032___V  - пн.клапан шламобассейна N3
    if ( DON032___V != DIS032___V and DIR031___V == ON ){
         if ( Check_TO(104,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON032___V==ON  and DIS032___V==OFF){ Message(504); }
              if(DON032___V==OFF and DIS032___V==ON ){ Message(604); }
              DIS032W = ON;
         }
         if ( DIS032W == ON ){
              DIS032W__V = ( DIS032W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS032W__V = OFF; DIS032W = OFF; Clear_TO(104); }
    //----------------------------------------------------
    //   DIS042___V  - пн.клапан шламобассейна N2
    if ( DON042___V != DIS042___V and DIR041___V == ON ){
         if ( Check_TO(105,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON042___V==ON  and DIS042___V==OFF){ Message(505); }
              if(DON042___V==OFF and DIS042___V==ON ){ Message(605); }
              DIS042W = ON;
         }
         if ( DIS042W == ON ){
              DIS042W__V = ( DIS042W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS042W__V = OFF; DIS042W = OFF; Clear_TO(105); }
    //----------------------------------------------------
    //   DIS052___V  - пн.клапан шламобассейна N1
    if ( DON052___V != DIS052___V and DIR051___V == ON ){
         if ( Check_TO(106,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON052___V==ON  and DIS052___V==OFF){ Message(506); }
              if(DON052___V==OFF and DIS052___V==ON ){ Message(606); }
              DIS052W = ON;
         }
         if ( DIS052W == ON ){
              DIS052W__V = ( DIS052W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS052W__V = OFF; DIS052W = OFF; Clear_TO(106); }
    //----------------------------------------------------
    //   DIS031___V  - клапан шламобассейна N3
    if ( DON031___V != DIS031___V and DIR031___V == ON ){
         if ( Check_TO(107,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON031___V==ON  and DIS031___V==OFF){ Message(507); }
              if(DON031___V==OFF and DIS031___V==ON ){ Message(607); }
              DIS031W = ON;
         }
         if ( DIS031W == ON ){
              DIS031W__V = ( DIS031W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS031W__V = OFF; DIS031W = OFF; Clear_TO(107); }
    //----------------------------------------------------
    //   DIS041___V  - клапан шламобассейна N2
    if ( DON041___V != DIS041___V and DIR041___V == ON ){
         if ( Check_TO(108,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON041___V==ON  and DIS041___V==OFF){ Message(508); }
              if(DON041___V==OFF and DIS041___V==ON ){ Message(608); }
              DIS041W = ON;
         }
         if ( DIS041W == ON ){
              DIS041W__V = ( DIS041W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS041W__V = OFF; DIS041W = OFF; Clear_TO(108); }
    //----------------------------------------------------
    //   DIS051___V  - клапан шламобассейна N1
    if ( DON051___V != DIS051___V and DIR051___V == ON ){
         if ( Check_TO(109,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON051___V==ON  and DIS051___V==OFF){ Message(509); }
              if(DON051___V==OFF and DIS051___V==ON ){ Message(609); }
              DIS051W = ON;
         }
         if ( DIS051W == ON ){
              DIS051W__V = ( DIS051W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS051W__V = OFF; DIS051W = OFF; Clear_TO(109); }
    //----------------------------------------------------
    //   DIS061___V  - насос подачи конденсата в сборник воды
    if ( DON061___V != DIS061___V and DIR061___V == ON ){
         if ( Check_TO(110,  TIME_ISNSV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON061___V==ON  and DIS061___V==OFF){ Message(510); }
              if(DON061___V==OFF and DIS061___V==ON ){ Message(610); }
              DIS061W = ON;
         }
         if ( DIS061W == ON ){
              DIS061W__V = ( DIS061W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS061W__V = OFF; DIS061W = OFF; Clear_TO(110); }
    //----------------------------------------------------
    //   DIS071___V  - клапан подачи воды в мешалку отходов РК
    if ( DON071___V != DIS071___V and DIR070___V == ON ){
         if ( Check_TO(111,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON071___V==ON  and DIS071___V==OFF){ Message(511); }
              if(DON071___V==OFF and DIS071___V==ON ){ Message(611); }
              DIS071W = ON;
         }
         if ( DIS071W == ON ){
              DIS071W__V = ( DIS071W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS071W__V = OFF; DIS071W = OFF; Clear_TO(111); }
    //----------------------------------------------------
    //   DIS081___V  - клапан подачи отходов в пн.насос загрузки отходов
    if ( DON081___V != DIS081___V and DIR070___V == ON ){
         if ( Check_TO(112,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON081___V==ON  and DIS081___V==OFF){ Message(512); }
              if(DON081___V==OFF and DIS081___V==ON ){ Message(612); }
              DIS081W = ON;
         }
         if ( DIS081W == ON ){
              DIS081W__V = ( DIS081W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS081W__V = OFF; DIS081W = OFF; Clear_TO(112); }
    //----------------------------------------------------
    //   DIS082___V  - клапан подачи воздуха в пн.насос загрузки отходов
    if ( DON082___V != DIS082___V and DIR070___V == ON ){
         if ( Check_TO(113,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF){
              if(DON082___V==ON  and DIS082___V==OFF){ Message(513); }
              if(DON082___V==OFF and DIS082___V==ON ){ Message(613); }
              DIS082W = ON;
         }
         if ( DIS082W == ON ){
              DIS082W__V = ( DIS082W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS082W__V = OFF; DIS082W = OFF; Clear_TO(113); }
    //----------------------------------------------------
    //   DIS111___V  - клапан подачи воздуха в гомогенизатор N1
    if ( DON111___V != DIS111___V and DIR110___V == ON ){
         if ( Check_TO(114,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON111___V==ON  and DIS111___V==OFF){ Message(514); }
              if(DON111___V==OFF and DIS111___V==ON ){ Message(614); }
              DIS111W = ON;
         }
         if ( DIS111W == ON ){
              DIS111W__V= ( DIS111W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS111W__V = OFF; DIS111W = OFF; Clear_TO(114); }
    //----------------------------------------------------
    //   DIS112___V  - клапан подачи воздуха на инжектор гомогенизатора N1
    if ( DON112___V != DIS112___V and DIR110___V == ON ){
         if ( Check_TO(115,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON112___V==ON  and DIS112___V==OFF){ Message(515); }
              if(DON112___V==OFF and DIS112___V==ON ){ Message(615); }
              DIS112W = ON;
         }
         if ( DIS112W == ON ){
              DIS112W__V = ( DIS112W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS112W__V = OFF; DIS112W = OFF; Clear_TO(115); }
    //----------------------------------------------------
    //   DIS121___V  - клапан подачи воздуха в гомогенизатор N2
    if ( DON121___V != DIS121___V and DIR120___V == ON ){
         if ( Check_TO(116,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON121___V==ON  and DIS121___V==OFF){ Message(516); }
              if(DON121___V==OFF and DIS121___V==ON ){ Message(616); }
              DIS121W = ON;
         }
         if ( DIS121W == ON ){
              DIS121W__V = ( DIS121W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS121W__V = OFF; DIS121W = OFF; Clear_TO(116); }
    //----------------------------------------------------
    //   DIS122___V  - клапан подачи воздуха на инжектор гомогенизатора N2
    if ( DON122___V != DIS122___V and DIR120___V == ON ){
         if ( Check_TO(117,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON122___V==ON  and DIS122___V==OFF){ Message(517); }
              if(DON122___V==OFF and DIS122___V==ON ){ Message(617); }
              DIS122W = ON;
         }
         if ( DIS122W == ON ){
              DIS122W__V = ( DIS122W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS122W__V = OFF; DIS122W = OFF; Clear_TO(117); }
    //----------------------------------------------------
    //   DIS101___V  - клапан подачи воздуха на пн.насос загрузки цемента
    if ( DON101___V != DIS101___V and DIR100___V == ON ){
         if ( Check_TO(118,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON101___V==ON  and DIS101___V==OFF){ Message(518); }
              if(DON101___V==OFF and DIS101___V==ON ){ Message(618); }
              DIS101W = ON;
         }
         if ( DIS101W == ON ){
              DIS101W__V = ( DIS101W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS101W__V = OFF; DIS101W = OFF; Clear_TO(118); }
    //----------------------------------------------------
    //   DIS102___V  - клапан подачи цемента на пн.насос загрузки цемента
    if ( DON102___V != DIS102___V and DIR100___V == ON ){
         if ( Check_TO(119,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON102___V==ON  and DIS102___V==OFF){ Message(519); }
              if(DON102___V==OFF and DIS102___V==ON ){ Message(619); }
              DIS102W = ON;
         }
         if ( DIS102W == ON ){
              DIS102W__V = ( DIS102W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS102W__V = OFF; DIS102W = OFF; Clear_TO(119); }
    //----------------------------------------------------        
    //   DIS131___V  - вентилятор аспирации вяжущего
    if ( DON131___V != DIS131___V and DIR131___V == ON ){
         if ( Check_TO(120,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON131___V==ON  and DIS131___V==OFF){ Message(520); }
              if(DON131___V==OFF and DIS131___V==ON ){ Message(620); }
              DIS131W = ON;
         }
         if ( DIS131W == ON ){
              DIS131W__V = ( DIS131W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS131W__V = OFF; DIS131W = OFF; Clear_TO(120); }
    //----------------------------------------------------
    //   DIS132___V  - шнек аспирации вяжущего
    if ( DON132___V != DIS132___V and DIR130___V == ON ){
         if ( Check_TO(121,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON132___V==ON  and DIS132___V==OFF){ Message(521); }
              if(DON132___V==OFF and DIS132___V==ON ){ Message(621); }
              DIS132W = ON;
         }
         if ( DIS132W == ON ){
              DIS132W__V = ( DIS132W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS132W__V = OFF; DIS132W = OFF; Clear_TO(121); }
    //----------------------------------------------------
    //   DIS141___V  - клапан подачи воздуха в бункер вяжущего
    if ( DON141___V != DIS141___V and DIR140___V == ON ){
         if ( Check_TO(122,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON141___V==ON  and DIS141___V==OFF){ Message(522); }
              if(DON141___V==OFF and DIS141___V==ON ){ Message(622); }
              DIS141W = ON;
         }
         if ( DIS141W == ON ){
              DIS141W__V = ( DIS141W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS141W__V = OFF; DIS141W = OFF; Clear_TO(122); }
    //----------------------------------------------------
    //   DIS142___V  - клапан подачи вяжущего из бункера вяжущего на шнек
    if ( DON142___V != DIS142___V and DIR140___V == ON ){
         if ( Check_TO(123,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON142___V==ON  and DIS142___V==OFF){ Message(523); }
              if(DON142___V==OFF and DIS142___V==ON ){ Message(623); }
              DIS142W = ON;
         }
         if ( DIS142W == ON ){
              DIS142W__V = ( DIS142W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS142W__V = OFF; DIS142W = OFF; Clear_TO(123); }
    //----------------------------------------------------
    //   DIS143___V  - вибратор бункера вяжущего
    if ( DON143___V != DIS143___V and DIR140___V == ON ){
         if ( Check_TO(124,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON143___V==ON  and DIS143___V==OFF){ Message(524); }
              if(DON143___V==OFF and DIS143___V==ON ){ Message(624); }
              DIS143W = ON;
         }
         if ( DIS143W == ON ){
              DIS143W__V = ( DIS143W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS143W__V = OFF; DIS143W = OFF; Clear_TO(124); }
    //----------------------------------------------------
    //   DIS152___V  - клапан дозировки вяжущего ТОЧНО
    if ( DON152___V != DIS152___V and DIR140___V == ON ){
         if ( Check_TO(127,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON152___V==ON  and DIS152___V==OFF){ Message(527); }
              if(DON152___V==OFF and DIS152___V==ON ){ Message(627); }
              DIS152W = ON;
         }
         if ( DIS152W == ON ){
              DIS152W__V = ( DIS152W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS152W__V = OFF; DIS152W = OFF; Clear_TO(127); }
    //----------------------------------------------------
    //   DIS161___V  - вентилятор аспирации цемента
    if ( DON161___V != DIS161___V and DIR161___V == ON ){
         if ( Check_TO(128,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON161___V==ON  and DIS161___V==OFF){ Message(528); }
              if(DON161___V==OFF and DIS161___V==ON ){ Message(628); }
              DIS161W = ON;
         }
         if ( DIS161W == ON ){
              DIS161W__V = ( DIS161W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS161W__V = OFF; DIS161W = OFF; Clear_TO(128); }
    //----------------------------------------------------
    //   DIS162___V  - шнек аспирации цемента
    if ( DON162___V != DIS162___V and DIR160___V == ON ){
         if ( Check_TO(129,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON162___V==ON  and DIS162___V==OFF){ Message(529); }
              if(DON162___V==OFF and DIS162___V==ON ){ Message(629); }
              DIS162W = ON;
         }
         if ( DIS162W == ON ){
              DIS162W__V = ( DIS162W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS162W__V = OFF; DIS162W = OFF; Clear_TO(129); }
    //----------------------------------------------------
    //   DIS171___V  - клапан воздуха бункера цемента
    if ( DON171___V != DIS171___V and DIR170___V == ON ){
         if ( Check_TO(130,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON171___V==ON  and DIS171___V==OFF){ Message(530); }
              if(DON171___V==OFF and DIS171___V==ON ){ Message(630); }
              DIS171W = ON;
         }
         if ( DIS171W == ON ){
              DIS171W__V = ( DIS171W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS171W__V = OFF; DIS171W = OFF; Clear_TO(130); }
    //----------------------------------------------------
    //   DIS172___V  - клапан подачи цемента на шнек
    if ( DON172___V != DIS172___V and DIR170___V == ON ){
         if ( Check_TO(131,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON172___V==ON  and DIS172___V==OFF){ Message(531); }
              if(DON172___V==OFF and DIS172___V==ON ){ Message(631); }
              DIS172W = ON;
         }
         if ( DIS172W == ON ){
              DIS172W__V = ( DIS172W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS172W__V = OFF; DIS172W = OFF; Clear_TO(131); }
    //----------------------------------------------------
    //   DIS173___V  - вибратор бункера цемента
    if ( DON173___V != DIS173___V and DIR170___V == ON ){
         if ( Check_TO(132,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON173___V==ON  and DIS173___V==OFF){ Message(532); }
              if(DON173___V==OFF and DIS173___V==ON ){ Message(632); }
              DIS173W = ON;
         }
         if ( DIS173W == ON ){
              DIS173W__V = ( DIS173W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS173W__V = OFF; DIS173W = OFF; Clear_TO(132); }
    //----------------------------------------------------
    //   DIS180___V  - шнек дозировки цемента
    if ( DON180___V != DIS180___V and DIR170___V == ON ){
         if ( Check_TO(133,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON180___V==ON  and DIS180___V==OFF){ Message(533); }
              if(DON180___V==OFF and DIS180___V==ON ){ Message(633); }
              DIS180W = ON;
         }
         if ( DIS180W == ON ){
              DIS180W__V = ( DIS180W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS180W__V = OFF; DIS180W = OFF; Clear_TO(133); }
    //----------------------------------------------------
    //   DIS181___V  - клапан дозировки цемента ГРУБО
    if ( DON181___V != DIS181___V and DIR170___V == ON ){
         if ( Check_TO(134,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON181___V==ON  and DIS181___V==OFF){ Message(534); }
              if(DON181___V==OFF and DIS181___V==ON ){ Message(634); }
              DIS181W = ON;
         }
         if ( DIS181W == ON ){
              DIS181W__V = ( DIS181W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS181W__V = OFF; DIS181W = OFF; Clear_TO(134); }
    //----------------------------------------------------
    //   DIS182___V  - клапан дозировки цемента ТОЧНО
    if ( DON182___V != DIS182___V and DIR170___V == ON ){
         if ( Check_TO(135,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON182___V==ON  and DIS182___V==OFF){ Message(535); }
              if(DON182___V==OFF and DIS182___V==ON ){ Message(635); }
              DIS182W = ON;
         }
         if ( DIS182W == ON ){
              DIS182W__V = ( DIS182W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS182W__V = OFF; DIS182W = OFF; Clear_TO(135); }
    //----------------------------------------------------
    //   DIS191___V  - вибратор дозатора сухого
    if ( DON191___V != DIS191___V and DIR190___V == ON ){
         if ( Check_TO(136,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON191___V==ON  and DIS191___V==OFF){ Message(536); }
              if(DON191___V==OFF and DIS191___V==ON ){ Message(636); }
              DIS191W = ON;
         }
         if ( DIS191W == ON ){
              DIS191W__V = ( DIS191W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS191W__V = OFF; DIS191W = OFF; Clear_TO(136); }
    //----------------------------------------------------
    //   DIS192___V  - вентилятор выгрузки дозатора сухого
    if ( DON192___V != DIS192___V and DIR190___V == ON ){
         if ( Check_TO(137,  TIME_ISPRV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON192___V==ON  and DIS192___V==OFF){ Message(537); }
              if(DON192___V==OFF and DIS192___V==ON ){ Message(637); }
              DIS192W = ON;
         }
         if ( DIS192W == ON ){
              DIS192W__V = ( DIS192W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS192W__V = OFF; DIS192W = OFF; Clear_TO(137); }
    //----------------------------------------------------
    //   DIS193___V  - клапан выгрузки дозатора сухого
    if ( DON193___V != DIS193___V and DIR190___V == ON ){
         if ( Check_TO(138,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON193___V==ON  and DIS193___V==OFF){ Message(538); }
              if(DON193___V==OFF and DIS193___V==ON ){ Message(638); }
              DIS193W = ON;
         }
         if ( DIS193W == ON ){
              DIS193W__V = ( DIS193W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS193W__V = OFF; DIS193W = OFF; Clear_TO(138); }
    //----------------------------------------------------
    //   DIS201___V  - клапан подачи тех воды в сборник воды
    if ( DON201___V != DIS201___V and DIR200___V == ON ){
         if ( Check_TO(139,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON201___V==ON  and DIS201___V==OFF){ Message(539); }
              if(DON201___V==OFF and DIS201___V==ON ){ Message(639); }
              DIS201W = ON;
         }
         if ( DIS201W == ON ){
              DIS201W__V = ( DIS201W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS201W__V = OFF; DIS201W = OFF; Clear_TO(139); }
    //----------------------------------------------------
    //   DIS202___V  - клапан подачи воды в дозатор мокрого
    if ( DON202___V != DIS202___V and DIR230___V == ON ){
         if ( Check_TO(140,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON202___V==ON  and DIS202___V==OFF){ Message(540); }
              if(DON202___V==OFF and DIS202___V==ON ){ Message(640); }
              DIS202W = ON;
         }
         if ( DIS202W == ON ){
              DIS202W__V = ( DIS202W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS202W__V = OFF; DIS202W = OFF; Clear_TO(140); }
    //----------------------------------------------------
    //   DIS211___V  - клапан дозировки отходов ГРУБО
    if ( DON211___V != DIS211___V and DIR210___V == ON ){
         if ( Check_TO(141,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON211___V==ON  and DIS211___V==OFF){ Message(541); }
              if(DON211___V==OFF and DIS211___V==ON ){ Message(641); }
              DIS211W = ON;
         }
         if ( DIS211W == ON ){
              DIS211W__V = ( DIS211W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS211W__V = OFF; DIS211W = OFF; Clear_TO(141); }
    //----------------------------------------------------
    //   DIS212___V  - клапан дозировки отходов ТОЧНО
    if ( DON212___V != DIS212___V and DIR210___V == ON ){
         if ( Check_TO(142,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON212___V==ON  and DIS212___V==OFF){ Message(542); }
              if(DON212___V==OFF and DIS212___V==ON ){ Message(642); }
              DIS212W = ON;
         }
         if ( DIS212W == ON ){
              DIS212W__V = ( DIS212W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS212W__V = OFF; DIS212W = OFF; Clear_TO(142); }
    //----------------------------------------------------
    //   DIS221___V    - клапан дозировки шлама ГРУБО
    if ( DON221___V != DIS221___V and DIR220___V == ON ){
         if ( Check_TO(143,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON221___V==ON  and DIS221___V==OFF){ Message(543); }
              if(DON221___V==OFF and DIS221___V==ON ){ Message(643); }
              DIS221W = ON;
         }
         if ( DIS221W == ON ){
              DIS221W__V = ( DIS221W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS221W__V = OFF; DIS221W = OFF; Clear_TO(143); }
    //----------------------------------------------------
    //   DIS222___V
    if ( DON222___V != DIS222___V and DIR220___V == ON ){
         if ( Check_TO(144,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON222___V==ON  and DIS222___V==OFF){ Message(544); }
              if(DON222___V==OFF and DIS222___V==ON ){ Message(644); }
              DIS222W = ON;
         }
         if ( DIS222W == ON ){
              DIS222W__V = ( DIS222W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS222W__V = OFF; DIS222W = OFF; Clear_TO(144); }
    //----------------------------------------------------
    //   DIS231___V  - клапан выгрузки дозатора мокрого
    if ( DON231___V != DIS231___V and DIR230___V == ON ){
         if ( Check_TO(145,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON231___V==ON  and DIS231___V==OFF){ Message(545); }
              if(DON231___V==OFF and DIS231___V==ON ){ Message(645); }
              DIS231W = ON;
         }
         if ( DIS231W == ON ){
              DIS231W__V = ( DIS231W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS231W__V = OFF; DIS231W = OFF; Clear_TO(145); }
    //----------------------------------------------------
    //   DIS232___V  - клапан подачи промывочной воды в дозатор мокрого
    if ( DON232___V != DIS232___V and DIR230___V == ON ){
         if ( Check_TO(146,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON232___V==ON  and DIS232___V==OFF){ Message(546); }
              if(DON232___V==OFF and DIS232___V==ON ){ Message(646); }
              DIS232W = ON;
         }
         if ( DIS232W == ON ){
              DIS232W__V = ( DIS232W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS232W__V = OFF; DIS232W = OFF; Clear_TO(146); }
    //----------------------------------------------------


    //----------------------------------------------------
    //   DIS285___V  - привод мешалки миксера ал.пасты
    if ( DON285___V != DIS285___V and DIR280___V == ON ){
         if ( Check_TO(151,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON285___V==ON  and DIS285___V==OFF){ Message(551); }
              if(DON285___V==OFF and DIS285___V==ON ){ Message(651); }
              DIS285W = ON;
         }
         if ( DIS285W == ON ){
              DIS285W__V = ( DIS285W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS285W__V = OFF; DIS285W = OFF; Clear_TO(151); }
    //----------------------------------------------------
    //   DIS286___V  - клапан подачи ал.пасты в дозатор ал.пасты
    if ( DON286___V != DIS286___V and DIR280___V == ON ){
         if ( Check_TO(152,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON286___V==ON  and DIS286___V==OFF){ Message(552); }
              if(DON286___V==OFF and DIS286___V==ON ){ Message(652); }
              DIS286W = ON;
         }
         if ( DIS286W == ON ){
              DIS286W__V = ( DIS286W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS286W__V = OFF; DIS286W = OFF; Clear_TO(152); }
    //----------------------------------------------------
    //   DIS272___V  - клапан подачи воды в емкость вода-ПАВ
    if ( DON272___V != DIS272___V and DIR270___V == ON ){
         if ( Check_TO(153,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON272___V==ON  and DIS272___V==OFF){ Message(553); }
              if(DON272___V==OFF and DIS272___V==ON ){ Message(653); }
              DIS272W = ON;
         }
         if ( DIS272W == ON ){
              DIS272W__V = ( DIS272W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS272W__V = OFF; DIS272W = OFF; Clear_TO(153); }
    //----------------------------------------------------
    //   DIS274___V  - клапан загрузки ПАВ в мешалку ал.суспензии пасты
    if ( DON274___V != DIS274___V and DIR270___V == ON ){
         if ( Check_TO(154,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON274___V==ON  and DIS274___V==OFF){ Message(554); }
              if(DON274___V==OFF and DIS274___V==ON ){ Message(654); }
              DIS274W = ON;
         }
         if ( DIS274W == ON ){
              DIS274W__V = ( DIS274W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS274W__V = OFF; DIS274W = OFF; Clear_TO(154); }
    //----------------------------------------------------
    //   DIS281___V  - клапан дозировки ал.суспензии пасты
    if ( DON281___V != DIS281___V and DIR280___V == ON ){
         if ( Check_TO(155,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON281___V==ON  and DIS281___V==OFF){ Message(555); }
              if(DON281___V==OFF and DIS281___V==ON ){ Message(655); }
              DIS281W = ON;
         }
         if ( DIS281W == ON ){
              DIS281W__V = ( DIS281W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS281W__V = OFF; DIS281W = OFF; Clear_TO(155); }
    //----------------------------------------------------
    //   DIS291___V  - клапан выгрузки из дозатора ал.суспензии пасты
    if ( DON291___V != DIS291___V and DIR290___V == ON ){
         if ( Check_TO(156,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON291___V==ON  and DIS291___V==OFF){ Message(556); }
              if(DON291___V==OFF and DIS291___V==ON ){ Message(656); }
              DIS291W = ON;
         }
         if ( DIS291W == ON ){
              DIS291W__V = ( DIS291W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS291W__V = OFF; DIS291W = OFF; Clear_TO(156); }
    //----------------------------------------------------
    //   DIS301___V  - насос алюминевой суспензии пасты
    if ( DON301___V != DIS301___V and DIR300___V == ON ){
         if ( Check_TO(157,  TIME_ISNSV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON301___V==ON  and DIS301___V==OFF){ Message(557); }
              if(DON301___V==OFF and DIS301___V==ON ){ Message(657); }
              DIS301W = ON;
         }
         if ( DIS301W == ON ){
              DIS301W__V = ( DIS301W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS301W__V = OFF; DIS301W = OFF; Clear_TO(157); }
    //----------------------------------------------------
    //   DIS311___V  - вибратор ВГБМ
    if ( DON311___V != DIS311___V and DIR310___V == ON ){
         if ( Check_TO(158,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON311___V==ON  and DIS311___V==OFF){ Message(558); }
              if(DON311___V==OFF and DIS311___V==ON ){ Message(658); }
              DIS311W = ON;
         }
         if ( DIS311W == ON ){
              DIS311W__V = ( DIS311W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS311W__V = OFF; DIS311W = OFF; Clear_TO(158); }
    //----------------------------------------------------
    //   DIS312___V  - вибратор ВГБМ
    if ( DON312___V != DIS312___V and DIR310___V == ON ){
         if ( Check_TO(159,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON312___V==ON  and DIS312___V==OFF){ Message(559); }
              if(DON312___V==OFF and DIS312___V==ON ){ Message(659); }
              DIS312W = ON;
         }
         if ( DIS312W == ON ){
              DIS312W__V = ( DIS312W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS312W__V = OFF; DIS312W = OFF; Clear_TO(159); }
    //----------------------------------------------------
    //   DIS313___V  - вибратор ВГБМ
    if ( DON313___V != DIS313___V and DIR310___V == ON ){
         if ( Check_TO(160,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON313___V==ON  and DIS313___V==OFF){ Message(560); }
              if(DON313___V==OFF and DIS313___V==ON ){ Message(660); }
              DIS313W = ON;
         }
         if ( DIS313W == ON ){
              DIS313W__V = ( DIS313W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS313W__V = OFF; DIS313W = OFF; Clear_TO(160); }
    //----------------------------------------------------
    //   DIS314___V  - вибратор ВГБМ
    if ( DON314___V != DIS314___V and DIR310___V == ON ){
         if ( Check_TO(161,  TIME_ISVBV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON314___V==ON  and DIS314___V==OFF){ Message(561); }
              if(DON314___V==OFF and DIS314___V==ON ){ Message(661); }
              DIS314W = ON;
         }
         if ( DIS314W == ON ){
              DIS314W__V = ( DIS314W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS314W__V = OFF; DIS314W = OFF; Clear_TO(161); }
    //----------------------------------------------------
    //   DIS316___V  - клапан выгрузки из ВГБМ
    if ( DON316___V != DIS316___V and DIR310___V == ON ){
         if ( Check_TO(162,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON316___V==ON  and DIS316___V==OFF){ Message(562); }
              if(DON316___V==OFF and DIS316___V==ON ){ Message(662); }
              DIS316W = ON;
         }
         if ( DIS316W == ON ){
              DIS316W__V = ( DIS316W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS316W__V = OFF; DIS316W = OFF; Clear_TO(162); }
    //----------------------------------------------------
    //   DIS317___V  - клапан выгрузки из ВГБМ
    if ( DON317___V != DIS317___V and DIR310___V == ON ){
         if ( Check_TO(163,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON317___V==ON  and DIS317___V==OFF){ Message(563); }
              if(DON317___V==OFF and DIS317___V==ON ){ Message(663); }
              DIS317W = ON;
         }
         if ( DIS317W == ON ){
              DIS317W__V = ( DIS317W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS317W__V = OFF; DIS317W = OFF; Clear_TO(163); }
    //----------------------------------------------------
    //   DIS31A___V  - клапан подачи воздуха в ВГБМ
    if ( DON31A___V != DIS31A___V and DIR310___V == ON ){
         if ( Check_TO(164,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON31A___V==ON  and DIS31A___V==OFF){ Message(564); }
              if(DON31A___V==OFF and DIS31A___V==ON ){ Message(664); }
              DIS31AW = ON;
         }
         if ( DIS31AW == ON ){
              DIS31AW__V = ( DIS31AW__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS31AW__V = OFF; DIS31AW = OFF; Clear_TO(164); }
    //------------------------------------------------------------------------


    //----------------------------------------------------
    //   DIS203___V  - клапан подачи воды в дозатор мокрого ТОЧНО
    if ( DON203___V != DIS203___V and DIR230___V == ON ){
         if ( Check_TO(165,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON203___V==ON  and DIS203___V==OFF){ Message(565); }
              if(DON203___V==OFF and DIS203___V==ON ){ Message(665); }
              DIS203W = ON;
         }
         if ( DIS203W == ON ){
              DIS203W__V = ( DIS203W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS203W__V = OFF; DIS203W = OFF; Clear_TO(165); }
    //----------------------------------------------------
    //   DIS223___V  - клапан дозировки шлама ТОЧНО
    if ( DON223___V != DIS223___V and DIR220___V == ON ){
         if ( Check_TO(166,  TIME_ISPKV, ZERO, '=', ON,  1 ) == OFF ){
              if(DON223___V==ON  and DIS223___V==OFF){ Message(566); }
              if(DON223___V==OFF and DIS223___V==ON ){ Message(666); }
              DIS223W = ON;
         }
         if ( DIS223W == ON ){
              DIS223W__V = ( DIS223W__V == ON ) then_ OFF else_ ON;
         }
    }  else { DIS223W__V = OFF; DIS223W = OFF; Clear_TO(166); }
    //----------------------------------------------------


    return;
}
//----------------------------------------------------------------------------
