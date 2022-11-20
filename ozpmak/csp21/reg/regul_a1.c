//---------------------------------------------------------------------------

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V1GNS1BS_V = 0;           // состояние кнопки включения гидронасоса

_f  far  I1KR_TMP_V = 0;           // текущ контрол значение выбран  крышки
_f  far  I1KR1CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка1
_f  far  I1KR2CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка2
_f  far  I1KR1OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка1
_f  far  I1KR2OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка2

_f  far  A1TVACUM_R = 6000;        // время вакуумирования (100 минут)
_f  far  I1MAXVCN_V = 0;           // счетчик превышения макс разрежения
_f  far  O1ZOPPO__Y = 0;           // сигнал откр задв остр пара на АК передат
_f  far  I1ZOPPO__Y = 0;           //
_f  far  A1RPZD___S = 0;           // шаг задания регулятора "НАБОРА ДАВЛЕНИЯ"
_f  far  A1ISPST__C = 0;           // счетчик пароля определения шага
_f  far  A1FLAG=0;                 // дополнительные переменные
_f  far  A1FLGP=0;                 //
_f  far  A1TEMP=0;                 //
_f  far  A1PPRT=0;                 // возврат из функций определения шага пер
_f  far  A1SBPT=0;                 // счетчик разблокировки СБУ
_f  far  A1SBPC=0;                 // счетчик блокировки СБУ
_f  far  A1SBPI=0;                 // счетчик ЗАКРЫТО исполнителей для СБУ
_f  far  A1CISP=0;                 // счетчик контроля состояния исполнителей


//---------------------------------------------------------------------------
//  управление исполнителями задвижек и клапанов АК3
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS1(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  острого пара
    if (i1==  ON){ O1ZIOPO__M= ON; O1ZIOPC__M=OFF; }   //  открыть
    if (i1== OFF){ O1ZIOPO__M=OFF; O1ZIOPC__M= ON; }   //  закрыть
    if (i1==STOP){ O1ZIOPO__M=OFF; O1ZIOPC__M=OFF; }   //  остановить
    // перепускного пара входящего
    if (i2==  ON){ O1ZIPPO__M= ON; O1ZIPPC__M=OFF; }
    if (i2== OFF){ O1ZIPPO__M=OFF; O1ZIPPC__M= ON; }
    if (i2==STOP){ O1ZIPPO__M=OFF; O1ZIPPC__M=OFF; }
    // перепускного пара выходящего
    if (i3==  ON){ O1ZOPPO__M= ON; O1ZOPPC__M=OFF; }
    if (i3== OFF){ O1ZOPPO__M=OFF; O1ZOPPC__M= ON; }
    if (i3==STOP){ O1ZOPPO__M=OFF; O1ZOPPC__M=OFF; }
    // сброса в атмосферу
    if (i4==  ON){ O1ZOPAO__M= ON; O1ZOPAC__M=OFF; }
    if (i4== OFF){ O1ZOPAO__M=OFF; O1ZOPAC__M= ON; }
    if (i4==STOP){ O1ZOPAO__M=OFF; O1ZOPAC__M=OFF; }
    // вакуумная задвижка
    if (i5==  ON){ O1VZO____M= ON; O1VZC____M=OFF; }
    if (i5== OFF){ O1VZO____M=OFF; O1VZC____M= ON; }
    if (i5==STOP){ O1VZO____M=OFF; O1VZC____M=OFF; }
    // клапан впуска пара
    if (i6==  ON){ O1KIPO___M= ON; O1KIPO___V= ON; O1KIPC___M=OFF; O1KIPC___V=OFF; }
    if (i6== OFF){ O1KIPO___M=OFF; O1KIPO___V=OFF; O1KIPC___M= ON; O1KIPC___V= ON; }
    if (i6==STOP){ O1KIPO___M=OFF; O1KIPO___V=OFF; O1KIPC___M=OFF; O1KIPC___V=OFF; }
    // клапан выпуска пара
    if (i7==  ON){ O1KOPO___M= ON; O1KOPO___V= ON; O1KOPC___M=OFF; O1KOPC___V=OFF; }
    if (i7== OFF){ O1KOPO___M=OFF; O1KOPO___V=OFF; O1KOPC___M= ON; O1KOPC___V= ON; }
    if (i7==STOP){ O1KOPO___M=OFF; O1KOPO___V=OFF; O1KOPC___M=OFF; O1KOPC___V=OFF; }
    // клапан сброса конденсата
    if (i8==  ON){ O1KOCO___M= ON; O1KOCO___V= ON; O1KOCC___M=OFF; O1KOCC___V=OFF; }
    if (i8== OFF){ O1KOCO___M=OFF; O1KOCO___V=OFF; O1KOCC___M= ON; O1KOCC___V= ON; }
    if (i8==STOP){ O1KOCO___M=OFF; O1KOCO___V=OFF; O1KOCC___M=OFF; O1KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  управление исполнителями крышек АК3
//              NUM       BY        HM        KR 
vd  far Set_KR1(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // байонет
       if (b==  ON){ O1BY1O___M= ON; O1BY1C___M=OFF; }   //  открыть
       if (b== OFF){ O1BY1O___M=OFF; O1BY1C___M= ON; }   //  закрыть
       if (b==STOP){ O1BY1O___M=OFF; O1BY1C___M=OFF; }   //  остановить
       // хомут
       if (h==  ON){ O1HM1UP__M= ON; O1HM1DN__M=OFF; }
       if (h== OFF){ O1HM1UP__M=OFF; O1HM1DN__M= ON; }
       if (h==STOP){ O1HM1UP__M=OFF; O1HM1DN__M=OFF; }
       // крышка
       if (k==  ON){ O1KR1O___M= ON; O1KR1C___M=OFF; }
       if (k== OFF){ O1KR1O___M=OFF; O1KR1C___M= ON; }
       if (k==STOP){ O1KR1O___M=OFF; O1KR1C___M=OFF; }
    }
    if(n==2){
       // байонет
       if (b==  ON){ O1BY2O___M= ON; O1BY2C___M=OFF; }
       if (b== OFF){ O1BY2O___M=OFF; O1BY2C___M= ON; }
       if (b==STOP){ O1BY2O___M=OFF; O1BY2C___M=OFF; }
       // хомут
       if (h==  ON){ O1HM2UP__M= ON; O1HM2DN__M=OFF; }
       if (h== OFF){ O1HM2UP__M=OFF; O1HM2DN__M= ON; }
       if (h==STOP){ O1HM2UP__M=OFF; O1HM2DN__M=OFF; }
       // крышка
       if (k==  ON){ O1KR2O___M= ON; O1KR2C___M=OFF; }
       if (k== OFF){ O1KR2O___M=OFF; O1KR2C___M= ON; }
       if (k==STOP){ O1KR2O___M=OFF; O1KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Очистка всех таймеров и счетчика
vd  far Clear_TA1(vd){
    Clear_TO(A1BTM+ 1); Clear_TO(A1BTM+ 2); 
    Clear_TO(A1BTM+ 3); Clear_TO(A1BTM+ 4); 
    Clear_TO(A1BTM+ 5); Clear_TO(A1BTM+ 6);
    Clear_TO(A1BTM+ 7); Clear_TO(A1BTM+ 8); 
    Clear_TO(A1BTM+ 9); Clear_TO(A1BTM+10);
    Clear_TO(A1BTM+11); Clear_TO(A1BTM+12);
    Clear_TO(A1BTM+13); Clear_TO(A1BTM+14);
    Clear_TO(A1BTM+15); Clear_TO(A1BTM+16);
    Clear_TO(A1BTM+17); Clear_TO(A1BTM+18);
    Clear_TO(A1BTM+19);
    A1STEPZ__V=0; A1STEPC__V=0;
}
//---------------------------------------------------------------------------
//  установка начальных значений при смене режима работы автоклава
vd  far Set_BV1(_f far A1STEPWPRV){
    // запомнить номер предыдущего шага
    A1STEPP__V =A1STEP___V;
    A1STEPWP_V =A1STEPWPRV;
    // сбросить  флаги паролей
    A1CYCRN__V =OFF; A1CYCRN__M=OFF;
    A1CYCST__V =OFF; A1CYCST__M=OFF;
    A1ISPST__V =OFF; A1ISPST__M=OFF;
    // обнулить счетчики режимов и таймеров
    A1STEPH__V =0;   A1STEPM__V=0; A1STEPS__V=0; 
    // сбросить флаги выбора крышек для открытия и закрытия
    I1KR1OBS_V =0;   I1KR2OBS_V =0;
    I1KR1CBS_V =0;   I1KR2CBS_V =0; 
    I1KR_TMP_V=-1;
    // снять команды со всех исполнителей крышек
    Set_KR1(1,STOP,STOP,STOP);
    Set_KR1(2,STOP,STOP,STOP);
    //  обнуление значений таймеров
    Clear_TA1();
    // снять команды на хомуты
    O1HM1UP__M=OFF; O1HM1DN__M=OFF;
    O1HM2UP__M=OFF; O1HM2DN__M=OFF;
    // снять команды на байонеты
    O1BY1O___M=OFF; O1BY1C___M=OFF;
    O1BY2O___M=OFF; O1BY2C___M=OFF;
    // снять команды на крышки
    O1KR1O___M=OFF; O1KR1C___M=OFF;
    O1KR2O___M=OFF; O1KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  установка текущего шага режима работы автоклава
vd  far Set_ST1(int SS){
    A1STEPW__V=SS;
    A1STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  получение значений из переменных удаленных контроллеров
//  A1PPSTEP_V - номер шага программы текущ АК
//  A1RPPSTEPV - принимаемое с АК-пер значение,сигнализирующее о выполнении на
//               АК-пер текущего шага
_f  far Get_RV1(vd){
    // если выбран номер 0- набор пара делается с магистрали
    if(A1NAKPPREM==0){ return(0); }
    A1RPPSTEPV=0;
    if(A1NAKPPREM==2){ A1RPPSTEPV=A2PPSTEP_V; AIPRP1___V=AIP2P____V; }
    if(A1NAKPPREM==3){ A1RPPSTEPV=A3PPSTEP_V; AIPRP1___V=AIP3P____V; }
    if(A1NAKPPREM==4){ A1RPPSTEPV=A4PPSTEP_V; AIPRP1___V=AIP4P____V; }
    if(A1NAKPPREM==5){ A1RPPSTEPV=A5PPSTEP_V; AIPRP1___V=AIP5P____V; }
    if(A1NAKPPREM==6){ A1RPPSTEPV=A6PPSTEP_V; AIPRP1___V=AIP6P____V; }
    if(A1RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // если текущий АК находится в режиме НАБОРА пер.паром
    if(A1PPSTEP_V==420){
       // если АК-пер перешел в режим ПЕРЕБРОСА и открыл задвижку вып пер.пара
       if(A1RPPSTEPV==700) return(1); return(0);
    }
    // текущий АК ожидает открытия клапана вып пер.пара на АК-пер
    if(A1PPSTEP_V==425){
       if(A1RPPSTEPV==704) return(2); return(0);
    }
    // текущий АК ожидает закрытия исполнителей выпуска пара на АК-пер
    if(A1PPSTEP_V==480){
       // если на АК-пер исполнители закрылись
       if(A1RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Получение текущего шага АК-инициатора (АК-при) при отдаче пара
_f  far Get_RA1(int mode){
    // проверить что другие автоклавы не находятся в режиме переброса
    // определять по состоянию перепускных задвижек (впуск,выпуск)
    if(mode==0){
       if(A2PPSTEP_V>=700 or A3PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // Определить номер АК, который запрашивает текущий для отдачи пара
    if(mode==1){
       if(A2PPSTEP_V==420 and A2NAKPP__R==1){ A1IPPNUM_V=2; return(2); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==1){ A1IPPNUM_V=3; return(3); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==1){ A1IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==1){ A1IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==1){ A1IPPNUM_V=6; return(6); }
       return(0);
    }
    // Определить текущий шаг на АК-инициаторе (АК-при)
    if(mode==2){
       if(A1IPPNUM_V==2){ A1IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A1IPPNUM_V==3){ A1IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A1IPPNUM_V==4){ A1IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A1IPPNUM_V==5){ A1IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A1IPPNUM_V==6){ A1IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка блокировки СБУ
int Chk_SBP1(vd){
    //-------------------------------------------
    // Если программа не на шаге работы с крышками
    if(A1STEPW__V<100||(A1STEPW__V>290&&A1STEPW__V<800)||A1STEPW__V>890){
      // Если разблокировали один из СБУ - выдать команду на закрытие
      // всех задвижек и перейти в режим ожидания
      if(I1SBP1R__V>0||I1SBP2R__V>0){
        // cбросить счетчик блокировки СБУ (защита от дребезга)
        A1SBPC=0;
        // Если не закрыт хоть один из проверяемых исполнителей
        if(I1ZIOPC__V!=ON|| I1ZIPPC__V!=ON||I1ZOPPC__V!=ON||I1ZOPAC__V!=ON||
           I1VZC____V!=ON||(I1KOCC___V!=ON&&(A1STEPP__V==3||A1STEP___V==3))){
////СБУ РАЗБЛОКИРОВАНО.ЧТО-ТО ОТКРЫТО.        
           // cбросить счетчик стабильного состояния ЗАКРЫТО исполнителей
           A1SBPI=0;
           //-----------
           // если програма сюда зашла с шага меньше, чем 910(другой режим)
           if(A1STEPW__V<910){
              // увеличить счетчик сработки СБУ (считаем 5сек) и выйти
              if(A1SBPT <5){ A1SBPT++; return(1); }
              // последний раз после проверки счетчика перед проверкой
              // исполнителей- обнулить счетчики и таймеры (когда прошло 5сек)
              A1STEPZ__V=0; A1STEPC__V=0; Set_BV1(A1STEPW__V);
              Message(107+A1BNM);
           }
           //-----------
           // установить режим закрытия исполнителей по разблокировке СБУ
           Set_ST1(910);
           // выдать команду на закрытие всех исполнителей
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // задвижка впуска острого пара закрыта?
           Set_ST1(911);
           switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return(1); }
             case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return(1); }
           }
           // задвижка впуска перепускного пара закрыта? 
           Set_ST1(912);
           switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return(1); }
             case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return(1); }
           }
           // задвижка выпуска перепускного пара закрыта?
           Set_ST1(913);
           switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return(1); }
             case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return(1); }
           }
           // задвижка выпуска пара в атмосферу закрыта?
           Set_ST1(914);
           switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return(1); }
             case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return(1); }
           }
           // задвижка вакуума закрыта?
           Set_ST1(915);
           switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return(1); }
             case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return(1); }
           }
           // если СБУ было разблокировано в режиме ВАКУУМИРОВАНИЯ
           if(A1STEPP__V==3){
           // клапан выпуска конденсата закрыт?
           Set_ST1(916);
           switch ( Check_TO(A1BTM+6, A1RCHKF__R* SEC, I1KOCC___V,'=',ON,  1 )){
             case RUN: { A1STEPZ__V=A1RCHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return(1); }
             case BAD: { Clear_TO(A1BTM+6); Message(146+A1BNM); Bell(1,1); return(1); }
           } }
           // если все закрыто- перейти в режим ожидания разблокировки СБУ
           Set_ST1(917); return(1);
        } else {
////СБУ РАЗБЛОКИРОВАНО.ВСЕ ЗАКРЫТО.        
           // если все проверяемые исполнители закрыты- уменьшить счетчик и
           // ждать на шаге 900, пока заблокируют СБУ
           if(A1SBPI<5){ A1SBPI++; return(1); }
           // после счетчика стабильного закрытия исполнителей-
           // сбросить счетчик ожидания  закрытия исполнителей
           A1SBPT=0;
           // если разблокировали СБУ в каком-то режиме,но все исполнители
           // закрыты- выдать сообщение с указанием режима на котором 
           // заблокировали СБУ
           if(A1STEPW__V<900){ Set_BV1(A1STEPW__V); Message(106+A1BNM); }
           // если исполнители были закрыты после разблокировки СБУ-
           // выдать сообщение о том, что исполнители закрыли
           if(A1STEPW__V>900){ Message(108+A1BNM ); }
           Set_ST1(900);
        }
      } else {
////СБУ ЗАБЛОКИРОВАНО.
        // если СБУ заблокированы и последний выполняемый шаг был закрытие
        // задвижек при разблокировке СБУ
        if(A1STEPW__V>=900){
           // ожидать 5сек стабильной блокировки СБУ
           if(A1SBPC<5){ A1SBPC++; return(1); }
           // перейти в режим ожидания
           Message(109+A1BNM); Set_BV1(910); Set_ST1(50); return(1);
        }
        // когда СБУ заблокированы- сбросить счетчики блокировки СБУ и выйти
        A1SBPT=0;
        A1SBPC=0;
        A1SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка исполнителей при работе с крышками
int Chk_IF1(int mode){
    // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
    if(I1ZIOPC__V!=ON){ Message(141+A1BNM); return(0); }
    // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
    if(I1ZIPPC__V!=ON){ Message(142+A1BNM); return(0); }
    // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
    if(I1ZOPPC__V!=ON){ Message(143+A1BNM); return(0); }
    // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
    if(I1ZOPAC__V!=ON){ Message(144+A1BNM); return(0); }
    // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
    if(I1VZC____V!=ON){ Message(145+A1BNM); return(0); }
    // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
    if(I1KOCC___V!=ON){ Message(146+A1BNM); return(0); }
    // СБУ разблокирован?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I1SBP1R__V==0||I1SBP2R__V==0){ Message(149+A1BNM); return(0); }
    }
    // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I1P1_N___V==0||I1P2_N___V==0){ Message(156+A1BNM); return(0); }
    }
    // есть напряжение на щите управл гидронасосом? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I1VACKR__V!=ON){ Message(157+A1BNM); return(0); }
    }
    // режим управления крышками автоклава дистанц? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I1LUCDU__V!=ON){ Message(158+A1BNM); return(0); }
    }
    // режим управления автоклавом дистанция(ПК)?
    if(mode==0 or mode==1){
      if(I1DU_____V!=ON){ Message(188+A1BNM); return(0); }
    }
    // проверка работы (включенного состояния) гидронасоса 
    // ожидание включения гидронасоса               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I1GNS_1__V!=ON){ Message(160+A1BNM); return(0); }
    }
    // если нажата кнопка СТОП
    if(mode>0){
       // если ДА - переходим в режим ГИДРОНАСОС
       if(I1KR1SB__V==ON||I1KR2SB__V==ON||I1GNS0B__V>0){
          A1CISP=0; Message(168+A1BNM); Set_BV1(870); Set_ST1(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_01(vd){

    // установить флаг ввода пароля запуска цикла и перейти
    // на режим  "ВАКУУМИРОВАНИЕ"
    if (A1CYCRN__M>OFF){ A1CYCRN__V=ON; A1CYCRN__M=OFF; Set_ST1(300); }
    // установить флаг ввода пароля остановки цикла
    if (A1CYCST__M>OFF){ A1CYCST__V=ON; A1CYCST__M=OFF; Set_ST1(50);  }
    // установить флаг ввода пароля перехода на заданный шаг
    if (A1ISPST__M>OFF){ A1ISPST__V=ON; A1ISPST__M=OFF; }

    // определение номера режима из шага
    A1STEP___V=floor( A1STEPW__V*0.01);
    // проверка граничного значения введенного шага
    if (A1STEPW__M<0  or A1STEPW__M>900){ A1STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  Если был изменен шаг работы автоклава и введен пароль изменения шага
    if (A1STEPW__M!=A1STEPW__V and A1ISPST__V==ON){
        //  если выбран РУЧНОЙ РЕЖИМ управления и введен пароль
        //  запуска или останова цикла
        if((A1STEPW__M<=10)){
            A1STEPW__V =A1STEPW__M; Message(130+A1BNM);
        }
        //  если выбран режим "ОТКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=100) and (A1STEPW__M< 200) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(131+A1BNM);
        }
        //  если выбран режим "ЗАКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=200) and (A1STEPW__M< 300) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(132+A1BNM);
        }
        //  если выбран режим "ВАКУУМИРОВАНИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=300) and (A1STEPW__M< 400) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(133+A1BNM);
        }
        //  если выбран режим "НАБОР ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=400) and (A1STEPW__M< 500) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(134+A1BNM); A1NAKPPREM=A1NAKPP__R;
        }
        //  если выбран режим "ВЫДЕРЖКА" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=500) and (A1STEPW__M< 600) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(135+A1BNM);
        }
        //  если выбран режим "СБРОС ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A1STEPW__M>=600) and (A1STEPW__M< 700) and (A1STEPW__V<=10)){
            A1STEPW__V =A1STEPW__M;  Message(136+A1BNM);
        }
        //-------------------------------------------------------------------
        //  установка вновь определенного режима работы 
        if (A1STEPW__M == A1STEPW__V){ Set_BV1(0); }
        else                         { A1STEPW__M=A1STEPW__V; }
    }
//  // ----------------------------------------------------------------------







//  // ----------------------------------------------------------------------
//  // Проверки и контроль для каждой новой секунды
    if(NewSEC>0){ 
       //-------------------------------------------
       // подсчет времени работы в текущем режиме
       // считать секунды
       A1STEPS__V++;
       // считать минуты
       if(A1STEPS__V>59){ A1STEPM__V++; A1STEPS__V=0; }
       // считать часы
       if(A1STEPM__V>59){ A1STEPH__V++; A1STEPM__V=0; }
       // через 99 часов время считается сначала (4,5 суток)
       if(A1STEPH__V>99){ A1STEPH__V=0; A1STEPM__V=0; A1STEPS__V=0; }
       //-------------------------------------------
       // если был введен пароль- устанавливается флаг ввода пароля, который
       // действителен 10 секунд
       if(A1ISPST__V==ON or A1CYCST__V==ON or A1CYCRN__V==ON){ A1ISPST__C++; }
       // если прошло более 10 сек после ввода пароля- сбросить флаг ввода 
       // пароля  и счетчик секунд (пароль нужно вводить заново)
       if(A1ISPST__C >10){ 
          A1ISPST__C=0; A1ISPST__V=OFF; A1CYCST__V=OFF; A1CYCRN__V=OFF;
       }
       //-------------------------------------------
       // если был изменен режим управления работой автоклава (ЩТ/ПК)
       if(S1MDUP___V!=S1MDU____V){
          // переведено на ЩИТ - перевести программу в режим "ОЖИДАНИЕ"
          if(S1MDU____V==0){
             Message(137+A1BNM); Set_BV1(0); Set_ST1(50);
          }
          // переведено на ПК  - выдать сообщение  и в режим "ОЖИДАНИЕ"
          if(S1MDU____V==1){
             Message(138+A1BNM); Set_BV1(0); Set_ST1(50);
          }
       }; S1MDUP___V=S1MDU____V;
       //-------------------------------------------
       if(Chk_SBP1()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОЖИДАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Ожидание нажатия кнопок открытия-закрытия автоклава из режима "ОЖИДАНИЕ"
    if (A1STEPW__V<=10||A1STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // Ожидание нажатия кнопки включения гидронасоса
        // Если нажата- перейти на шаг 870
        if(V1GNS1BS_V<1){
           if(I1GNS1B__V>0){
              Message(183+A1BNM); O1GNS____M=ON; A1CISP=0;
              Set_BV1(50); V1GNS1BS_V=1; Set_ST1(870); return;
           }
        }
        // нажата кнопка выключения гидронасоса
        if(I1GNS0B__V>0){ V1GNS1BS_V=0; O1GNS____M=OFF; }
        //-----------
        // контроль готовности автоклава перейти в режим "ПЕРЕБРОСА"
        //(давление в автоклаве д.б.  >1 и закрыты все задвижки, клапана и
        // исполнители крышек, АК на дистанции).
        if(AIP1P____V>1 and I1ZIOPC__V>0 and I1ZIPPC__V>0 and I1ZOPPC__V>0 and
           I1VZC____V>0 and I1ZOPAC__V>0 and I1KIPC___V>0 and I1KOPC___V>0 and
           I1DU_____V>0 and
           I1SBP1Z__V>0 and I1SBP2Z__V>0){
           // определить, что другие АК не находятся в режиме перепуска
           if(Get_RA1(0)>0){
              // если какой-то АК запрашивает данный для ПЕРЕПУСКА -
              // определить его номер
              if(Get_RA1(1)>0){
                 // перейти на режим ПЕРЕБРОС
                 Message(129+A1BNM); Set_BV1(0); Set_ST1(700);
              }
           }
        }
        return;
    }
//  // ----------------------------------------------------------------------







//  // ОСТАНОВКА режимов работы. Если был выбран пункт меню "Остановка цикла"
//  // или нажата кнопка "СТОП"  или  прекращена работа программы из-за
//  // кого-то нарушения (в каком-то  из режимов не сработал концевик и т.п.).
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=50 and A1STEPW__V<70){
       // если ушли с шага 232:- опустить хомут 
       if(A1STEPWP_V==232){

       }
       // снять команды со всех исполнителей
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS1(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR1(1,STOP,STOP,STOP);
       Set_KR1(2,STOP,STOP,STOP);
       // выключить гидронасос
       O1GNS____M=OFF;
       // сбросить команду включения гидронасоса
       V1GNS1BS_V=0;
       // снять галочки с выбора режимов цикла
       A1NAKPP_YM=OFF;  A1NAKPP_YV=A1NAKPP_YM;
       A1RAZVK_YM=OFF;  A1RAZVK_YV=A1RAZVK_YM;
       A1PPP___YM=OFF;  A1PPP___YV=A1PPP___YM;
       A1PVID__YM=OFF;  A1PVID__YV=A1PVID__YM;
       A1SP____YM=OFF;  A1SP____YV=A1SP____YM;
       // очистить текущие таймеры и счетчики
       Clear_TA1();
       A1PPSTEP_V=0;
       // перейти в режим ОЖИДАНИЕ
       Message(189+A1BNM); Set_BV1(50); Set_ST1(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  Включение ГИДРОНАСОСА
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=870 and A1STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST1(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        //-----------
        // если нажата кнопка выключения гидронасоса- выдать комманду на 
        // выключение гидронасоса
        if(I1GNS0B__V==ON){ 
           Message(184+A1BNM);
           // выдать команду на выключение гидронасоса
           O1GNS____M=OFF;
           // сбросить флаг состояния кнопки включения гидронасоса
           V1GNS1BS_V=0; 
        }
        // если поступила команда на выключение гидронасоса
        if(V1GNS1BS_V==0&&O1GNS____M==OFF){
           // снять команды с исполнителей механизмов крышки
           //      N BY   HM   KR
           Set_KR1(1,STOP,STOP,STOP);
           Set_KR1(2,STOP,STOP,STOP);
           // снять команды с исполнителей задвижек
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ждать выключение гидронасоса
           switch( Check_TO(A1BTM+1,60*SEC, I1GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A1BNM); Bell(1,1); break; }
              case END: { Message(185+A1BNM); break; }
           }
           // перейти в режим ожидания
           Set_BV1(870); Set_ST1(50); return;
        }
        // проверка состояния исполнителей
        if(Chk_IF1(0)==0){
           A1CISP++; 
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(50); 
           }
           return; 
        }; A1CISP=0;
        //-----------
        // выдать комманду на включение гидронасоса:
        O1GNS____M= ON;
        //-----------
        // ожидание нажатия кнопки "Открыть автоклав"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR1OB__V>0){
              Message(174+A1BNM); A1CISP=0;
              Set_BV1(50); I1KR1OBS_V=1; V1GNS1BS_V=1; Set_ST1(100); return;
           }
        }
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR2OB__V>0){
              Message(175+A1BNM); A1CISP=0;
              Set_BV1(50); I1KR2OBS_V=1; V1GNS1BS_V=1; Set_ST1(100); return;
           }
        }
        //-----------
        // ожидание нажатия кнопки "Закрыть автоклав"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR1CB__V>0){
              Message(176+A1BNM);  A1CISP=0;
              Set_BV1(50); I1KR1CBS_V=1; V1GNS1BS_V=1; Set_ST1(200); return;
           }
        }
        if(I1KR1OBS_V<1 and I1KR2OBS_V<1 and I1KR1CBS_V<1 and I1KR2CBS_V<1){
           if(I1KR2CB__V>0){
              Message(177+A1BNM);  A1CISP=0;
              Set_BV1(50); I1KR2CBS_V=1; V1GNS1BS_V=1; Set_ST1(200); return;
           }
        }
        //-----------
        Clear_TA1();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОТКРЫТИЯ" АК3
//  // ----------------------
//  //  Проверка начального состояния исполнителей:
    if (A1STEPW__V>=100 and A1STEPW__V< 130){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O1GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        // сообщение о начале режима
        if(A1STEPW__V!=126){ Message(195+A1BNM); }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST1(126);
        I1KR_TMP_V=-1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(126); Set_ST1(870); return;}
        switch ( Check_TO(A1BTM+14,A1THMUP__R*SEC, I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R;A1STEPC__V =CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(151+A1BNM);
                        // если это первый шаг контроля- увеличить счетчик 
                        // контроля и дать команду на поднятие хомута
                        if(A1TEMP<1){ 
                           if(I1KR1OBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
                           if(I1KR2OBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
                           A1TEMP++;
                        }
                        // если это второй шаг контроля- звонок и переход в
                        // режим ОЖИДАНИЯ
                        else        { Bell(1,1); Set_BV1(126); Set_ST1(870); }
                        return;
                      }
        }
        // очистить таймеры и счетчики
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15);
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        Clear_TO(A1BTM+18); Clear_TO(A1BTM+19);
        A1STEPZ__V=0; A1STEPC__V=0;
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        Set_ST1(130);  A1TEMP=0;
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ОТКРЫТИЕ АВТОКЛАВА":
    if (A1STEPW__V>=130 and A1STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O1GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST1(132);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1BY1O___V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1BY2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(132); Set_ST1(870); return;}
        // если байонет не открыт
        if(I1KR_TMP_V==OFF){
//         // команда на открытие байонета              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // подается импульсами: 2сек импульс, 2сек пауза
           if(A1TEMP<2){
             // импульс на открытие
             if(I1KR1OBS_V>0){ O1BY1O___M=ON; O1BY1C___M=OFF; }
             if(I1KR2OBS_V>0){ O1BY2O___M=ON; O1BY2C___M=OFF; }
             A1TEMP++;
           } else {
             // пауза
             if(A1TEMP<4){
                O1BY1O___M=OFF; O1BY1C___M=OFF;
                O1BY2O___M=OFF; O1BY2C___M=OFF;
                A1TEMP++;
             } else {
             // переход после паузы на импульс
                if(A1TEMP<7) A1TEMP=0;
             }
           }  
        }
        switch (Check_TO( A1BTM+16,A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(154+A1BNM); Bell(1,1); 
                        Set_BV1(132); Set_ST1(870);
                        return; 
                      }
        }
        // сброс флага подачи импульсного сигнала на байонет
        A1TEMP=10;
        // снять команду на открытие байонетов          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O1BY1O___M=OFF; O1BY1C___M=OFF;
        O1BY2O___M=OFF; O1BY2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A1BTM+17,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+17]; return; }
        }
//      // команда на поднятие хомута                   [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I1KR1OBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
        if(I1KR2OBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST1(131);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(131); Set_ST1(870); return;}
        switch (Check_TO( A1BTM+14,A1THMUP__R*SEC,I1KR_TMP_V, '=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(151+A1BNM); Bell(1,1);
                        Set_BV1(131); Set_ST1(870);    return;
                      }
        }
        // снять команду на поднятие хомута             [x6.o01 (OxHM1UP) = 0]
        //                                              [x6.o07 (OxHM2UP) = 0]
        O1HM1UP__M=OFF; O1HM1DN__M=OFF;
        O1HM2UP__M=OFF; O1HM2DN__M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        //--------
//      // команда на открытие крышки                   [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I1KR1OBS_V>0){ O1KR1O___M=ON; O1KR1C___M=OFF; }
        if(I1KR2OBS_V>0){ O1KR2O___M=ON; O1KR2C___M=OFF; }
        // крышки открыты?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST1(133);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1KR1O___V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1KR2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(133); Set_ST1(870);  return;}
        switch (Check_TO( A1BTM+18,A1TKRO___R*SEC, I1KR_TMP_V, '=',ON,1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+18); Message(152+A1BNM); Bell(1,1); 
                        Set_BV1(133); Set_ST1(870);
                        return; 
                      }
        }
        // команды с крышек снимем после опускания хомута

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO(A1BTM+19,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+19]; return; }
        }
        // очистить таймеры и счетчики
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15);
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        Clear_TO(A1BTM+18); Clear_TO(A1BTM+19);
        A1STEPZ__V=0; A1STEPC__V=0;
        //
        Set_ST1(134); A1TEMP=0; return;
    }
//  // ----------------------
//  //  Опускание хомута
    if (A1STEPW__V>=134 and A1STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O1GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
//      // команда на опускание хомутов                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I1KR1OBS_V>0){ O1HM1DN__M=ON; O1HM1UP__M=OFF; }
        if(I1KR2OBS_V>0){ O1HM2DN__M=ON; O1HM2UP__M=OFF; }
        // хомуты опущены?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST1(134);
        I1KR_TMP_V= -1;
        if(I1KR1OBS_V>0){ I1KR_TMP_V=I1HM1DN__V;   }
        if(I1KR2OBS_V>0){ I1KR_TMP_V=I1HM2DN__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(134); Set_ST1(870);  return;}
        switch (Check_TO( A1BTM+14,A1THMUP__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(150+A1BNM); Bell(1,1); 
                        Set_BV1(134); Set_ST1(870);
                        return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        if(I1KR1OBS_V>0){ Message(191+A1BNM); }
        if(I1KR2OBS_V>0){ Message(192+A1BNM); }
        // перевод управления автоклавом в режим "ГИДРОНАСОС"->"ОЖИДАНИЕ"|"СБУ"
        Message(197+A1BNM); Set_BV1(134); Set_ST1(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ЗАКРЫТИЯ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A1STEPW__V>=200 and A1STEPW__V< 230){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O1GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        // сообщение о начале режима
        if(A1STEPW__V==200){ Message(196+A1BNM); }
        //--------
        // хомут опущен?                                [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST1(226);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1HM1DN__V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1HM2DN__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(226);  Set_ST1(870); return;}
        switch ( Check_TO (A1BTM+14, A1THMUP__R*SEC,   I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(150+A1BNM); Bell(1,1); 
                        Set_BV1(226); Set_ST1(870);   return; 
                      }
        }
        // выдать комманду на открытие байонета
        if(I1KR1CBS_V>0){ O1BY1O___M=ON; O1BY1C___M=OFF; }
        if(I1KR2CBS_V>0){ O1BY2O___M=ON; O1BY2C___M=OFF; }
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        // если байонет не открылся- выйти
        Set_ST1(228);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1BY1O___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1BY2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(228); Set_ST1(870); return;}
        switch ( Check_TO (A1BTM+15, A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+15); Message(154+A1BNM); Bell(1,1);
                        Set_BV1(228); Set_ST1(870);   return; 
                      }
        }
        // снять команду с байонета
        O1BY1O___M=OFF; O1BY1C___M=OFF;
        O1BY2O___M=OFF; O1BY2C___M=OFF;
        //
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15); 
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(230);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": приподнять перед закрытием
    if (A1STEPW__V>=230 and A1STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O1GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(870); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // команда на приподнятие крышки                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I1KR1CBS_V>0){ O1KR1O___M=ON; O1KR1C___M=OFF; }
        if(I1KR2CBS_V>0){ O1KR2O___M=ON; O1KR2C___M=OFF; }
        // крышка поднята?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST1(231);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1KR1O___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1KR2O___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(231); Set_ST1(870); return;}
        switch (Check_TO(A1BTM+14,A1TKRO___R*SEC, I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(152+A1BNM); Bell(1,1);
                        Set_BV1(231); Set_ST1(870);   return; 
                      }
        }
        // снять команду на поднятие крышки             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O1KR1O___M=OFF; O1KR1C___M=OFF;
        O1KR2O___M=OFF; O1KR2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        // подать команду на поднятие хомута            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I1KR1CBS_V>0){ O1HM1UP__M=ON; O1HM1DN__M=OFF; }
        if(I1KR2CBS_V>0){ O1HM2UP__M=ON; O1HM2DN__M=OFF; }
        Set_ST1(232);
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1HM1UP__V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1HM2UP__V;   }
        if(I1KR_TMP_V<0){ Set_BV1(232); Set_ST1(870); return;}
        switch (Check_TO(A1BTM+16,A1THMUP__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1THMUP__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(151+A1BNM); Bell(1,1);
                        Set_BV1(232); Set_ST1(870);   return; 
                      }
        }
        // после поднятия хомута команда не снимается

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A1BTM+17,A1TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+17]; return; }
        }
        Clear_TO(A1BTM+14); Clear_TO(A1BTM+15); 
        Clear_TO(A1BTM+16); Clear_TO(A1BTM+17);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(235);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": закрыть крышки
    if (A1STEPW__V>=235 and A1STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O1GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF1(1)==0){
           A1CISP++;
           if(A1CISP>1){ 
              O1GNS____M=OFF; V1GNS1BS_V=0;
              Message(187+A1BNM); Set_BV1(235); Set_ST1(870); 
           }
           return;
        }; A1CISP=0;
        //--------
        // команда на закрытие крышек                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I1KR1CBS_V>0){ O1KR1C___M=ON; O1KR1O___M=OFF; }
        if(I1KR2CBS_V>0){ O1KR2C___M=ON; O1KR2O___M=OFF; }
        // крышка закрыта?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST1(236);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1KR1C___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1KR2C___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(236); Set_ST1(870); return;}
        switch (Check_TO (A1BTM+14,A1TKRO___R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TKRO___R; A1STEPC__V=CNTTO[A1BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+14); Message(153+A1BNM); Bell(1,1);
                        Set_BV1(236); Set_ST1(870); return; 
                      }
        }
        // снять команду на закрытие крышек             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O1KR1C___M=OFF; O1KR1O___M=OFF;
        O1KR2C___M=OFF; O1KR2O___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A1BTM+15,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+15]; return; }
        }
        // команда на закрытие байонетов                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I1KR1CBS_V>0){ O1BY1C___M=ON; O1BY1O___M=OFF; }
        if(I1KR2CBS_V>0){ O1BY2C___M=ON; O1BY2O___M=OFF; }
        // байонеты закрыты?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST1(237);
        I1KR_TMP_V=-1;
        if(I1KR1CBS_V>0){ I1KR_TMP_V=I1BY1C___V;   }
        if(I1KR2CBS_V>0){ I1KR_TMP_V=I1BY2C___V;   }
        if(I1KR_TMP_V<0){ Set_BV1(237); Set_ST1(870); return;}
        switch (Check_TO (A1BTM+16,A1TBYRT__R*SEC,I1KR_TMP_V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TBYRT__R; A1STEPC__V=CNTTO[A1BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A1BTM+16); Message(155+A1BNM); Bell(1,1);
                        Set_BV1(237); Set_ST1(870);   return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR1(1,STOP,STOP,STOP);
        Set_KR1(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        if(I1KR1OBS_V>0){ Message(193+A1BNM); }
        if(I1KR2OBS_V>0){ Message(194+A1BNM); }
        // перевод управления автоклавом в режим "ГИДРОНАСОС"
        Message(198+A1BNM); Set_BV1(235); Set_ST1(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ВАКУУМИРОВАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A1STEPW__V>=300 and A1STEPW__V<320){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "ВАКУУМИРОВАНИЕ"- перейти на сл режим
        if(A1RAZVK_YV==OFF){ Set_BV1(300); Set_ST1(400); return; }
        // проверка  вакуумирования других автоклавов
        // (на вакуумировании может находится  ТОЛЬКО один автоклав)
        if(A2PPSTEP_V==300||A3PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV1(300); Set_ST1(50); return; 
        }
        A1PPSTEP_V=300;
        // сообщение о начале режима
        if(A1STEPW__V==300){ Message(200+A1BNM); }
        //
        Set_ST1(311);
        // перевести регулятор конденсата в Авт режим, чтобы закрылся клапан
        A1RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST1(301);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST1(302);
        switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST1(303);
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST1(304);
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST1(305);
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
        Set_ST1(306);
        switch ( Check_TO(A1BTM+6, A1RCHKF__R* SEC, I1KOCC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1RCHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(146+A1BNM); Bell(1,1); return; }
        }
        // СПБ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST1(307);
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST1(308);
        switch ( Check_TO(A1BTM+8, 60*SEC,(I1P1_N___V and I1P2_N___V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+8]; return; }
            case BAD: { Clear_TO(A1BTM+8); Message(156+A1BNM); Bell(1,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST1(309);
        switch ( Check_TO(A1BTM+9, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+9]; return; }
            case BAD: { Clear_TO(A1BTM+9); Message(147+A1BNM); Bell(1,1); return; }
        }
        // дистанционный режим работы вакуумнасоса      [x2.i08 (IxVNMD_) = 1]
        Set_ST1(310);
        switch ( Check_TO(A1BTM+10, 60*SEC, I1VNMD___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+10]; return; }
            case BAD: { Clear_TO(A1BTM+10); Message(162+A1BNM); Bell(1,1); return; }
        }
        // дистанционный режим работы задвижки          [x2.i07 (IxVZMD_) = 1]
        Set_ST1(311);
        switch ( Check_TO(A1BTM+11, 60*SEC, I1VZMD___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+11]; return; }
            case BAD: { Clear_TO(A1BTM+11); Message(182+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6); 
        Clear_TO(A1BTM+7); Clear_TO(A1BTM+8); Clear_TO(A1BTM+9); 
        Clear_TO(A1BTM+10);
        Clear_TO(A1BTM+11);
        A1STEPZ__V=0; A1STEPC__V=0;
        I1MAXVCN_V=0;
        Set_ST1(320);
        return;
    }
//  // ----------------------
//  //  Включение вакуумирования
    if (A1STEPW__V>=320 and A1STEPW__V<325){
        if(!NewSEC){ return; }
        // команда на открытие вакуумной задвижки       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // вакуумная задвижка открыта?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST1(321);
        switch ( Check_TO(A1BTM+1, A1TVZO___R* SEC, I1VZO____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(163+A1BNM); return; }
        }
        // снять команду на открытие вакуумной задвижки [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // закрывается клапан на вакуумном насосе       [x4.o04 (OxAZVO_) = 1]
        O1AZVO___V=ON; O1AZVO___M=OFF;
        // команда на включение вакуумного насоса       [x4.o05 (OxVN_1_) = 1]
        O1VN_1___V=ON; O1VN_1___M=OFF;
        Set_ST1(322);
        // вакуумный насос включен?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A1BTM+2, 60*SEC, I1VN_1___V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(164+A1BNM); Bell(1,1); return; }
        }
        // проверка канала максимального разрежения с   [x2.i06 (IxMAXV_) = 1]
        // эл.контактного манометра
        if(I1MAXV___V>0){ I1MAXVCN_V++; }
        else            { I1MAXVCN_V=0; }
        if(I1MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
           Set_ST1(325);
           return;
        }
        // проверка величины разрежения в автоклаве     [x0.06 (AIPxyV__) = ?]
        // (ждать зад вел или счет)
        Set_ST1(323);
        switch ( Check_TO(A1BTM+3, A1TVACUM_R* SEC, AIP12V___V,'<',A1RAZVK__R, 3)){
            case RUN: { A1STEPZ__V=A1TVACUM_R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Message(165+A1BNM); break; }
        }
        // дать комманду на закрытие вакуумной задвижки [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(325);
        return;
    }
//  // ----------------------
//  //  Выключение вакуумирования
    if (A1STEPW__V>=325 and A1STEPW__V<330){
        if(!NewSEC){ return; }
        // команда на закрытие вакуумной задвижки       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // вакуумная задвижка закрыта?                  [x2.i02 (IxVZC__) = 1]
        Set_ST1(326);
        switch ( Check_TO(A1BTM+1, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(166+A1BNM); return; }
        }
        // ждать некоторое время перед включением следующего исполнителя
        Set_ST1(327);
        switch (Check_TO (A1BTM+3,A1TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TBONIS_R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
        }
        // открыть клапан атмосферы на вакуумном насосе [x4.o04 (OxAZVO_) = 1]
        O1AZVO___V=OFF; O1AZVO___M=OFF;
        // выключить вакуумный насос                    [x4.o05 (OxVN_1_) = 0]
        O1VN_1___V=OFF; O1VN_1___M=OFF;
        Set_ST1(328);
        // вакуумный насос выключен?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A1BTM+4,  120*SEC, I1VN_1___V,'=',OFF, 1)){
            case RUN: { A1STEPZ__V=120; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(167+A1BNM); return; }
        }
        //
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); 
        Clear_TO(A1BTM+3); Clear_TO(A1BTM+4);
        A1STEPZ__V=0; A1STEPC__V=0;
        // сообщение об окончании режима
        Message(190+A1BNM); Set_ST1(330);
        return;
    }
//  // ----------------------
//  //  ВАКУУМИРОВАНИЕ ЗАКОНЧЕНО
    if (A1STEPW__V>=330 and A1STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // перевод управления автоклавом в ручной режим
        Set_BV1(330); Set_ST1(400);
        A1RAZVK_YM=OFF;  A1RAZVK_YV=A1RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  Режим "НАБОР ДАВЛЕНИЯ"
//  // -----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A1STEPW__V>=400 and A1STEPW__V<420){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "НАБОР ДАВЛЕНИЯ"- перейти на сл режим
        if(A1PPP___YV==OFF){ Set_BV1 (400); Set_ST1(500); return; }
        A1PPSTEP_V=400;
        // сообщение о начале режима
        if(A1STEPW__V==400){ 
           Message(201+A1BNM); 
           A1RPRA___M=OFF; A1RPUU1__M=RMINUS; Set_ST1(401); return;
        }
        //
        A1NAKPPREM=A1NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST1(401);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST1(402);
        switch ( Check_TO(A1BTM+2, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(142+A1BNM); Bell(1,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST1(403);
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST1(404);
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST1(405);
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        // клапан впуска пара закрыт?
        Set_ST1(406);
        switch ( Check_TO(A1BTM+6, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(128+A1BNM); Bell(1,1); return; }
        }
        // СБУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST1(407);
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST1(409);
        switch ( Check_TO(A1BTM+9, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+9]; return; }
            case BAD: { Clear_TO(A1BTM+9); Message(147+A1BNM); Bell(1,1); return; }
        }
        // режим управления автоклавом "Дистанция"?     [x1.i13 (IxDU___) = 1]
        Set_ST1(410);
        switch ( Check_TO(A1BTM+10, 60*SEC, I1VAC____V,'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*1; A1STEPC__V=CNTTO[A1BTM+10]; return; }
            case BAD: { Clear_TO(A1BTM+10); Message(159+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6); 
        Clear_TO(A1BTM+7); Clear_TO(A1BTM+8); Clear_TO(A1BTM+9); 
        Clear_TO(A1BTM+10);
        A1STEPZ__V=0; A1STEPC__V=0;
        // выбран режим набора давления магистральным паром?
        if(A1NAKPPREM==0) Set_ST1(430);
        else              Set_ST1(420);
        A1TEMP=0; A1FLAG=0; A1PPRT=0; A1RPRA___M=ON; A1RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Проверка готовности автоклава-передатчика (открытие на нем задвижки)
    if (A1STEPW__V>=420 and A1STEPW__V<422){
        if(!NewSEC){ return; }
        A1PPSTEP_V=420;
        Set_ST1(421);
        // ждать подтверждения о готовности к перепуску с автоклава
        // передатчика
        if(A1PPRT<1){
           A1PPRT=Get_RV1(); 
           return;
        }
        Set_ST1(422);
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Открытие исполнителей:
    if (A1STEPW__V>=422 and A1STEPW__V<425){
        if(!NewSEC){ return; }
        A1PPSTEP_V=422;
        // дать команду на открытие задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара открыта?   [x3.o02 (OxZIPPO) = 1]
        Set_ST1(423);
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZIPPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(161+A1BNM); Bell(1,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки пер.пара
        switch (Check_TO (A1BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // снять команду с задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        // перейти на следующий шаг
        Set_ST1(425);
        return;
    }
//  // ----------------------
//  // ожидание открытия на АК-пер клапана выпуска пара
    if (A1STEPW__V>=425 and A1STEPW__V<427){
        if(!NewSEC){ return; }
        // если АК-пер перешел из режима ПЕРЕБРОС в другой - закрыть все
        // задвижки  и перейти в  режим  ОЖИДАНИЕ (нестандартная ситуация) 
//!!!   if(A1RPPSTEPV<700||A1RPPSTEPV>710){ Set_ST1(50); return; }
        A1PPSTEP_V=425;
        // ждать подтверждения об откр клапана выпуска пара на автоклаве
        // передатчике
        if(A1PPRT<2){
           A1PPRT=Get_RV1(); 
           return;
        }
        // перейти на управление клапаном (на регулятор)
        Set_ST1(440); A1RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  С магистрали
    if (A1STEPW__V>=430 and A1STEPW__V<435){
        if(!NewSEC){ return; }
        // дать команду на открытие задвижки магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистрального пара открыта? [x1.i00 (IxZIOPO) = 1]
        Set_ST1(431);
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(171+A1BNM); Bell(1,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки острого пара
        switch (Check_TO (A1BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // снять команду с задвижки впуска острого пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        // перейти на управление клапаном (на регулятор)
        Set_ST1(440); A1RPZD___S=0; A1RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  Формирование задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ"
    if (A1STEPW__V>=440 and A1STEPW__V<445){
        if(!NewSEC){ return; }
        // определяем задание расхода для ПИД регулятора из таблицы 
        // "НАБОР ТЕМПЕРАТУРЫ"
        Set_ST1(441);
        //-----------
        // Для набора температуры острым паром:
        if(A1NAKPPREM==0){
            // если текущая Т автоклава больше очередной заданой в таблице-
            // установить задание расхода для ПИД регулятора набора давления
            if(A1RPZD___S==0){ 
               A1RPZD___M =A11NTOF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=1;
            }
            if(AIT1P____V>=A11NTOP02R  and A1RPZD___S<=2){ 
               A1RPZD___M =A11NTOF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=2;
            }
            if(AIT1P____V>=A11NTOP03R  and A1RPZD___S<=3){ 
               A1RPZD___M =A11NTOF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=3;
            }
            if(AIT1P____V>=A11NTOP04R  and A1RPZD___S<=4){ 
               A1RPZD___M =A11NTOF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=4;
            }
            if(AIT1P____V>=A11NTOP05R  and A1RPZD___S<=5){ 
               A1RPZD___M =A11NTOF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=5;
            }
        } else {
        // Для набора температуры перепускным паром:
            if(A1RPZD___S==0){
               A1RPZD___M =A11NTPF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=1;
            }
            if(AIT1P____V>=A11NTPP02R  and A1RPZD___S<=2){
               A1RPZD___M =A11NTPF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=2;
            }
            if(AIT1P____V>=A11NTPP03R  and A1RPZD___S<=3){
               A1RPZD___M =A11NTPF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=3;
            }
            if(AIT1P____V>=A11NTPP04R  and A1RPZD___S<=4){
               A1RPZD___M =A11NTPF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=4;
            }
            if(AIT1P____V>=A11NTPP05R  and A1RPZD___S<=5){
               A1RPZD___M =A11NTPF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=5;
            }
        }
        //-----------
        // если давление в автоклаве больше того, что определено
        // в первой строке таблицы "НАБОР ДАВЛЕНИЯ" - определяем задание
        // расхода  для ПИД регулятора из таблицы "НАБОР ДАВЛЕНИЯ"
        // Для набора давления острым паром:
        if(A1NAKPPREM==0){
            if(AIP1P____V>=A11NPOP01R  and A1RPZD___S<=6){ 
               A1RPZD___M =A11NPOF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=6;
            }
            if(AIP1P____V>=A11NPOP02R  and A1RPZD___S<=7){ 
               A1RPZD___M =A11NPOF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=7;
            }
            if(AIP1P____V>=A11NPOP03R  and A1RPZD___S<=8){ 
               A1RPZD___M =A11NPOF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=8;
            }
            if(AIP1P____V>=A11NPOP04R  and A1RPZD___S<=9){ 
               A1RPZD___M =A11NPOF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=9; 
            }
            if(AIP1P____V>=A11NPOP05R  and A1RPZD___S<=10){ 
               A1RPZD___M =A11NPOF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=10;
            }
            if(AIP1P____V>=A11NPOP06R  and A1RPZD___S<=11){ 
               A1RPZD___M =A11NPOF06R; A1RPZD___V=A1RPZD___M; A1RPZD___S=11;
            }
            if(AIP1P____V>=A11NPOP07R  and A1RPZD___S<=12){ 
               A1RPZD___M =A11NPOF07R; A1RPZD___V=A1RPZD___M; A1RPZD___S=12;
            }
            if(AIP1P____V>=A11NPOP08R  and A1RPZD___S<=13){ 
               A1RPZD___M =A11NPOF08R; A1RPZD___V=A1RPZD___M; A1RPZD___S=13;
            }
            if(AIP1P____V>=A11NPOP09R  and A1RPZD___S<=14){ 
               A1RPZD___M =A11NPOF09R; A1RPZD___V=A1RPZD___M; A1RPZD___S=14;
            }
            if(AIP1P____V>=A11NPOP10R  and A1RPZD___S<=15){ 
               A1RPZD___M =A11NPOF10R; A1RPZD___V=A1RPZD___M; A1RPZD___S=15;
            }
        } else {
        // Для набора давления перепускным паром:
            if(AIP1P____V>=A11NPPP01R  and A1RPZD___S<=6){ 
               A1RPZD___M =A11NPPF01R; A1RPZD___V=A1RPZD___M; A1RPZD___S=6;
            }
            if(AIP1P____V>=A11NPPP02R  and A1RPZD___S<=7){ 
               A1RPZD___M =A11NPPF02R; A1RPZD___V=A1RPZD___M; A1RPZD___S=7;
            }
            if(AIP1P____V>=A11NPPP03R  and A1RPZD___S<=8){ 
               A1RPZD___M =A11NPPF03R; A1RPZD___V=A1RPZD___M; A1RPZD___S=8;
            }
            if(AIP1P____V>=A11NPPP04R  and A1RPZD___S<=9){ 
               A1RPZD___M =A11NPPF04R; A1RPZD___V=A1RPZD___M; A1RPZD___S=9;
            }
            if(AIP1P____V>=A11NPPP05R  and A1RPZD___S<=10){ 
               A1RPZD___M =A11NPPF05R; A1RPZD___V=A1RPZD___M; A1RPZD___S=10;
            }
            if(AIP1P____V>=A11NPPP06R  and A1RPZD___S<=11){ 
               A1RPZD___M =A11NPPF06R; A1RPZD___V=A1RPZD___M; A1RPZD___S=11;
            }
            if(AIP1P____V>=A11NPPP07R  and A1RPZD___S<=12){ 
               A1RPZD___M =A11NPPF07R; A1RPZD___V=A1RPZD___M; A1RPZD___S=12;
            }
            if(AIP1P____V>=A11NPPP08R  and A1RPZD___S<=13){ 
               A1RPZD___M =A11NPPF08R; A1RPZD___V=A1RPZD___M; A1RPZD___S=13;
            }
            if(AIP1P____V>=A11NPPP09R  and A1RPZD___S<=14){ 
               A1RPZD___M =A11NPPF09R; A1RPZD___V=A1RPZD___M; A1RPZD___S=14;
            }
            if(AIP1P____V>=A11NPPP10R  and A1RPZD___S<=15){ 
               A1RPZD___M =A11NPPF10R; A1RPZD___V=A1RPZD___M; A1RPZD___S=15;
            }
        }
        //-----------
        // если автоклав в режиме набора давления перепускным  паром и
        // если разница давлений между АК-передатчиком и АК-приемником
        // меньше заданному (AxZPPRE__R) -перейти на шаг
        // закрытия исполнителей набора перепускного пара и формирование
        // задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ" по острому пару
        A1PPSTEP_V=440; Get_RV1();
        if(A1NAKPPREM>0 and AIPRP1___V-AIP1P____V < A1ZPPRE__R){
           Set_ST1(480); A1PPRT=0; return;
        }

        //-----------
        // если давление в автоклаве больше заданного в "НАСТРОЙКАХ ЦИКЛА"-
        // перейти на шаг закрытия исполнителей магистрального пара
        if(A1NAKPPREM==0 and A1PPP____R>0 and AIP1P____V>=A1PPP____R){
           if(A1TEMP <7){ 
              A1TEMP++;     
           } else { 
              Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); 
              Set_ST1 (450); 
           }
           return;
        } else {
           A1TEMP=0;
        }
        //-----------
        // если набор давления идет с магистрали и давление в автоклаве 
        // больше,чем давление в магистрали- закрыть задвижку впуска остр пара
        if(A1NAKPPREM==0 and AIP1P____V>=AIP12M___V){
           Set_ST1(442);
           // дать команду на закрытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // если перепад давления между АК и магистралью стабилизировался
        if(A1NAKPPREM==0 and AIP1P____V< AIP12M___V-A1ZNPM___R){
           Set_ST1(443);
           // дать команду на открытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS1(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей магистрального пара и переход на "ВЫДЕРЖКУ"
    if (A1STEPW__V>=450 and A1STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A1BTM+2, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(128+A1BNM); Bell(1,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(440); Set_ST1(500);
        A1PPP___YM=OFF;  A1PPP___YV=A1PPP___YM;  
        // сообщение об окончании режима
        Message(202+A1BNM);
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей перепускного пара на АК-пер
    if (A1STEPW__V>=480 and A1STEPW__V<482){
        if(!NewSEC){ return; }
        A1PPSTEP_V=480;
        Set_ST1(481);
        // ждать подтверждения о закрытии исполнителей выпуска пара на
        // автоклаве передатчике
        if(A1PPRT<3){
           A1PPRT=Get_RV1(); return;
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(482);
        return;
    }
//  // ----------------------
    if (A1STEPW__V>=482 and A1STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST1(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара закрыта?
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(142+A1BNM); Bell(1,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A1BTM+2, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(128+A1BNM); Bell(1,1); return; }
        }
        // при закрытии всех  исполнителей перепускного пара, возвращаемся
        // на формирование задания расхода пара регулятора НАБОРА ДАВЛЕНИЯ
        // по острому пару
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(440);
        A1NAKPPREM=0; A1RPZD___S=0; A1RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  Режим "ВЫДЕРЖКА"
//  // ----------------------------------------------------------------------
    if ((A1STEPW__V==500)||(A1STEPW__V>510&&A1STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST1(500);
        // если в цикл не включен режим "ВЫДЕРЖКА"- перейти на сл режим
        if(A1PVID__YV==OFF){ Set_BV1(500); Set_ST1(600); return; }
        A1PPSTEP_V=500;
        // сообщение о начале режима
        if(A1STEPW__V==500){ Message(203+A1BNM); }
        // выдержка автоклава под давлением проводится магистральным паром
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST1(511);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(512);
        // клапан впуска пара закрыт?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A1BTM+2, A1RPHKF__R, I1KIPC___V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(169+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(513);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(514);
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A1BTM+4, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(144+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(515);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(516);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A1BTM+6, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(142+A1BNM); Bell(1,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
        Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); Clear_TO(A1BTM+6);
        A1STEPZ__V=0; A1STEPC__V=0;
        //
        Set_ST1(501);
        // установить процент начального открытия клапана впуска пара (30%)
        A1TEMP=0.3;
        A1RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A1STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST1(501);
        //-----------
        // если давление в автоклаве больше заданного-
        // перейти на  шаг закрытия клапана впуска пара
        if(AIP1P____V>=A1PPP____R){
           Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=0; 
           return;
        }
        //-----------
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // перейти на шаг закрытия задвижки и клапана впуска острого пара
        if(AIP1P____V> A1ZPAKX__R or AIP1P____V>AIP12M___V){
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=1;
           return;
        }
        //-----------
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A1STEPH__V>=A1PVIDH__R and A1STEPM__V>=A1PVIDM__R){
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2); Clear_TO(A1BTM+3); 
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(502); A1FLAG=2;
           return;
        }
        //-----------

        //-----------
        // выдержка автоклава под давлением  проводится магистральным паром
        // открыть  задвижку  магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задвижка впуска магистральн пара открыта?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPO__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(171+A1BNM); Bell(1,1); return; }
        }
        //-----------
        // снять  команду с  задвижки впуска  острого пара  и
        // выдать команду на открытие клапана впуска  пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A1BTM+3]==0) Set_IS1(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A1BTM+3]==1) Set_IS1(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ждать A1TEMP %  секунд от полного  хода клапана впуска пара
        // или пока не сработает концевик открытия клапана
        if(I1KIPO___V<1){
           switch ( Check_TO(A1BTM+2,A1RPHKF__R*A1TEMP,ZERO,'=',ON, 1)){
               case RUN: { A1STEPZ__V=A1RPHKF__R*A1TEMP; A1STEPC__V=CNTTO[A1BTM+2]; 
                           return; 
                         }
           }
        }
        // снять команду с клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задержка 30 секунд
        switch ( Check_TO(A1BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A1STEPZ__V=30; A1STEPC__V=CNTTO[A1BTM+3]; return; }
        }
        if(AIP1P____V< A1PPP____R){
        // если давление в автоклаве не поднялось до заданного и клапан
        // открыт не полностью- увеличить время открытия клапана и повторить
        // текущий шаг 
        //(впринципе,так можно открывать клапан более плавно +0.3,+0.3...)
           if(A1TEMP<0.8){
              A1TEMP=0.3;
              Clear_TO(A1BTM+2); Clear_TO(A1BTM+3);
              A1STEPZ__V=0; A1STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A1STEPW__V>=502 and A1STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST1(502);
        // установить процент начального открытия клапана впуска пара (30%)
        A1TEMP=0.3;
        // если текущее давление в автоклаве меньше заданного-
        // перейти назад на  шаг открытия  задвижки и клапана впуска пара
        if(AIP1P____V<A1PPP____R-A1ZNVD___R and 
           AIP1P____V<AIP12M___V-A1ZNPM___R and A1FLAG<2){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(501); return;
        }
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // закрыть задвижку впуска острого пара
        if(AIP1P____V> A1ZPAKX__R or AIP1P____V>AIP12M___V){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); 
           A1STEPZ__V=0; A1STEPC__V=0; A1FLAG=1;
        }
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A1STEPH__V>=A1PVIDH__R and A1STEPM__V>=A1PVIDM__R){
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5); 
           A1STEPZ__V=0; A1STEPC__V=0; A1FLAG=2;
        }
        // если это контроль максимально допустимого давления или разницы или
        // выход из режима - закрыть задвижку впуска острого пара
        if(A1FLAG>0){
          // дать команду на закрытие всех исполнителей
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // задвижка впуска острого пара закрыта?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A1BTM+5, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(141+A1BNM); Bell(1,1); return; }
          }
        }
        // дать команду на закрытие клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверить  состоян клапана впуска пара       [x1.i05 (IxKIPC_) = 1]
        // клапан впуска пара закрыт?            
        switch ( Check_TO(A1BTM+4, A1RPHKF__R* SEC, I1KIPC___V,'=',ON,  1 )){
            case RUN: { A1STEPZ__V=A1RPHKF__R; A1STEPC__V=CNTTO[A1BTM+4]; return; }
            case BAD: { Clear_TO(A1BTM+4); Message(170+A1BNM); Bell(1,1); return; }
        }
        // если был установлен флаг выхода- перейти на режим "СБРОС ДАВЛЕНИЯ"
        if(A1FLAG==2){ 
           Clear_TO(A1BTM+4); Clear_TO(A1BTM+5);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_BV1(502); Set_ST1(600);
           A1PVID__YM=OFF;  A1PVID__YV=A1PVID__YM;
           // сообщение об окончании режима
           Message(204+A1BNM);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  Режим "СБРОС ДАВЛЕНИЯ"
    // ----------------------------------------------------------------------
    if ((A1STEPW__V==600)||(A1STEPW__V>610&&A1STEPW__V<620)){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "СБРОС ДАВЛЕНИЯ"- перейти на руч.режим
        if(A1SP____YV==OFF){ Set_BV1(600); Set_ST1(50); return; }
        // проверка СБРОСА ДАВЛЕНИЯ других автоклавов
        // (на СБРОСЕ ДАВЛЕНИЯ может находится ТОЛЬКО один автоклав)
        if(A2PPSTEP_V==600||A3PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV1(600); Set_ST1(50); Message(110+A1BNM); return;
        }
        A1PPSTEP_V=600;
        // сообщение о начале режима
        if(A1STEPW__V==600){ Message(205+A1BNM); }
        //
        A1RPRA___M=ON;
        //-----------
        // определение первоначального процента открытия клапана сброса пара
        A1FLAG=0; A1FLGP=0; if(A1TKLO___R==0) A1TKLO___R=100;
        A1FLAG=5; A1TEMP=A11SPKK05R; 
        if(A1SPAT___R>0) A1TEMP=A11SPAK05R; if(A1TEMP==0) A1TEMP=20;
        // если определен сброс пара в атмосферу
        if(A1SPAT___R>0){ A1TEMP=A1TKLO___R*0.01*A1TEMP; }
        // если определен сброс пара в акумулятор
        else            { A1TEMP=A1TKLO___R*0.01*A1TEMP; }
        // дать команду на закрытие всех исполнителей
        if(A1SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS1( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST1(611);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A1BTM+1, A1TZOPO__R* SEC, I1ZIOPC__V,'=',ON,1)){
            case RUN: { A1STEPZ__V=A1TZOPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(141+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(613);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A1BTM+3, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+3]; return; }
            case BAD: { Clear_TO(A1BTM+3); Message(143+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(615);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A1BTM+5, A1TVZO___R* SEC, I1VZC____V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TVZO___R; A1STEPC__V=CNTTO[A1BTM+5]; return; }
            case BAD: { Clear_TO(A1BTM+5); Message(145+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(616);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A1BTM+6, A1TZPPO__R* SEC, I1ZIPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+6]; return; }
            case BAD: { Clear_TO(A1BTM+6); Message(142+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(617);
        // СБУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        switch ( Check_TO(A1BTM+7,5*60*SEC,(I1SBP1Z__V and I1SBP2Z__V),'=',ON, 1)){
            case RUN: { A1STEPZ__V=60*5; A1STEPC__V=CNTTO[A1BTM+7]; return; }
            case BAD: { Clear_TO(A1BTM+7); Message(148+A1BNM); Bell(1,1); return; }
        }
        Set_ST1(618);
        // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
        // атмосферу
        if(A1SPAT___R>0){
          // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
          // атмосферу
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A1BTM+8, A1TZSPA__R* SEC, I1ZOPAO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+8]; return; }
            case BAD: { Clear_TO(A1BTM+8); Message(173+A1BNM); Bell(1,1); return; }
          }
        }
        Clear_TO(A1BTM+1);  Clear_TO(A1BTM+2);  Clear_TO(A1BTM+3);  
        Clear_TO(A1BTM+4);  Clear_TO(A1BTM+5);  Clear_TO(A1BTM+6);  
        Clear_TO(A1BTM+7);  Clear_TO(A1BTM+8);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_ST1(602);
        return;
    }
//  // ----------------------
//  //  сброс пара по таблице
    if (A1STEPW__V>=602 and A1STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST1(602);
        // присвоить переменной процент(время в секундах) открытия клапана 
        // (от полного  времени хода клапана) по таблице  соответственно
        // текущего давления  в автоклаве
        // таблица просматривается от большего к меньшему (снизу вверх)
        // без возврата на предыдущий шаг

        // если текущее давление меньше-1 или текущее давление
        // меньше последнего указанного в таблице "СБРОС ДАВЛЕНИЯ"(снизу-вверх)
        // или разблокирован один из СБУ- перейти на след режим
        if(AIP1P____V<-1 or A1FLAG==1 or I1SBP1R__V>0  or I1SBP2R__V>0){
           Set_ST1(605); Clear_TO(A1BTM+2); A1STEPZ__V=0; A1STEPC__V=0; A1FLGP=0;
           return;
        }
        
        // если определен сброс пара в атмосферу
        if(A1SPAT___R>0){
           Set_ST1(603);
           if(AIP1P____V<A11SPAP04R and A1FLAG>=5){
              // считается разница процента открытия клапана между 
              // предыдущим и текущим шагом
              A1TEMP=A1TKLO___R*0.01*(A11SPAK04R-A11SPAK05R); A1FLAG=4;
           }
           if(AIP1P____V<A11SPAP03R and A1FLAG>=4){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK03R-A11SPAK04R); A1FLAG=3;
           }
           if(AIP1P____V<A11SPAP02R and A1FLAG>=3){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK02R-A11SPAK03R); A1FLAG=2;
           }
           if(AIP1P____V<A11SPAP01R and A1FLAG>=2){
              A1TEMP=A1TKLO___R*0.01*(A11SPAK01R-A11SPAK02R); A1FLAG=1;
           }
        } else {
           Set_ST1(604);
        // если выбран сброс пара в акумулятор
           if(AIP1P____V<A11SPKP04R and A1FLAG>=5){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK04R-A11SPKK05R); A1FLAG=4;
           }
           if(AIP1P____V<A11SPKP03R and A1FLAG>=4){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK03R-A11SPKK04R); A1FLAG=3;
           }
           if(AIP1P____V<A11SPKP02R and A1FLAG>=3){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK02R-A11SPKK03R); A1FLAG=2;
           }
           if(AIP1P____V<A11SPKP01R and A1FLAG>=2){
              A1TEMP=A1TKLO___R*0.01*(A11SPKK01R-A11SPKK02R); A1FLAG=1;
           }
        }
        // если был переход на новый шаг
        if(A1FLGP!=A1FLAG){
           // если значение A1TEMP > 0 - открываем клапан выпуска пара,
           // иначе - закрываем
           if(A1TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS1( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // обновить значения
           A1TEMP=fabs(A1TEMP);  
           A1FLGP=A1FLAG;
           // обнулить таймер и счетчики для отработки новых значений
           Clear_TO(A1BTM+1); A1STEPZ__V=0;  A1STEPC__V=0;
        }
        // считаем время воздействия сигнала на клапан
        switch ( Check_TO(A1BTM+1, A1TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=A1TEMP; A1STEPC__V=CNTTO[A1BTM+1]; return; }
        }
        // после отработки таймера- снять сигналы с исполнителей
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  повторная проверка и выход из текущего режима в режим "ОЖИДАНИЕ"
    if (A1STEPW__V>=605 and A1STEPW__V<607){
        if(!NewSEC){ return; }
        // если текущее  давление меньше или равно  нулю 
        // или  меньшему значению в таблице- увелич счетчик
        if(AIP1P____V<=0 or A1FLAG==1 or I1SBP1R__V>0  or I1SBP2R__V>0){
           A1FLGP++; 
        // иначе - уменьшить
        } else { 
           A1FLGP--; 
        }
        // 10 сек ожидание 
        switch ( Check_TO(A1BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A1STEPZ__V=10; A1STEPC__V=CNTTO[A1BTM+2]; return; }
        }
        // если счетчик положительный - 
        // перейти на шаг закрытия исполнителей
        if(A1FLGP>2){
           Set_ST1(607); Clear_TO(A1BTM+1);
        } else {
        // если счетчик отрицательный - вернуться на СБРОС ДАВЛЕНИЯ
           Set_ST1(603); A1FLGP=A1FLAG;
        }; Clear_TO(A1BTM+2); A1STEPZ__V =0; A1STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  закрытие исполнителей СБРОСА ДАВЛЕНИЯ и выход из режима
    if (A1STEPW__V>=607 and A1STEPW__V<609){
        if(!NewSEC){ return; }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки сброса пара в атмосферу
        switch ( Check_TO(A1BTM+1, A1TZSPA__R* SEC, I1ZOPAC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZSPA__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(144+A1BNM); Bell(1,1); return; }
        }
        // проверка закрытия клапана выпуска пара
        switch ( Check_TO(A1BTM+2, A1TKLO___R* SEC, I1KOPC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(139+A1BNM); Bell(1,1); return; }
        }
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(602); Set_ST1(50);
        A1SP____YM=OFF; A1SP____YV=A1SP____YM;
        // сообщение об окончании режима
        Message(206+A1BNM);
        return;
    }
//  // ----------------------







    //  Режим "ПЕРЕБРОС ДАВЛЕНИЯ"
    //  Если автоклав идет на переброс, оператор не ставит у него галочку
    //  "СБРОС ДАВЛЕНИЯ".  Тогда после "ВЫДЕРЖКИ" автоклав переходит в режим
    //  "ОЖИДАНИЕ". В этом режиме он может находится сколь угодно долго.
    //  В этот момент оператор может управлять автоклавом вручную или со щита.
    //  Но для работы в режиме "ПЕРЕБРОС" автоклав должен находится в режиме
    //  ПК с закрытыми задвижками и клапанами.
    //  Как только пришел  запрос на переброс с этого автоклава - автоклав
    //  переходит в режим "ПЕРЕБРОС"
//  // ----------------------------------------------------------------------
    if (A1STEPW__V>=700 and A1STEPW__V<702){
        if(!NewSEC){ return; }
        A1RPRA___M=ON;
        // открыть задвижку выпуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // проверка открытия задвижки выпуска перепускного пара
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZOPPO__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(179+A1BNM); Bell(1,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A1PPSTEP_V=700;
        // перейти на следующий шаг
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0;  A1STEPC__V=0;
        Set_ST1(702);
        return;
    }
//  // ----------------------
//  //  открытие клапана выпуска пара
    if (A1STEPW__V>=702 and A1STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA1(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A1IPPSTEPV>=400&&A1IPPSTEPV<500){
           // ожидать открытия задвижки на АК-при
           if(A1IPPSTEPV!=425){ return; }
        } else {
        // если АК-при перешел из режима НАБОРА ДАВЛЕНИЯ в другой режим-
        // перейти  на закрытие исполнителей (нестандартная ситуация)
           Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
           A1STEPZ__V=0; A1STEPC__V=0;
           Set_ST1(704); return;
        }
        // открыть клапан выпуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // проверка открытия клапана выпуска пара
        switch ( Check_TO(A1BTM+1, A1TKLO___R* SEC, I1KOPO___V,'=',ON, 2 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(181+A1BNM); Bell(1,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A1PPSTEP_V=704;
        // перейти на следующий шаг
        Clear_TO(A1BTM+1);  Clear_TO(A1BTM+2);
        A1STEPZ__V=0;  A1STEPC__V=0;
        Set_ST1(704);
        return;
    }
//  // ----------------------
//  // закрытие исполнителей выпуска перепускного пара
    if (A1STEPW__V>=704 and A1STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA1(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A1IPPSTEPV>=400&&A1IPPSTEPV<500){
           // ожидать пока АК-при не наберет нужного давления и не
           // перейдет  на шаг закрытия исполнителей
           if(A1IPPSTEPV!=480){ return; }
           // если АК-инициатор ушел из режима НАБОР ДАВЛЕНИЯ- закрываем
           // исполнители и переходим в режим  ОЖИДАНИЯ
           //(нестандартная ситуация)
        }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS1( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки выпуска перепускного пара
        switch ( Check_TO(A1BTM+1, A1TZPPO__R* SEC, I1ZOPPC__V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TZPPO__R; A1STEPC__V=CNTTO[A1BTM+1]; return; }
            case BAD: { Clear_TO(A1BTM+1); Message(143+A1BNM); Bell(1,1); return; }
        }
        // закрыть клапан выпуска пара
        switch ( Check_TO(A1BTM+2, A1TKLO___R* SEC, I1KOPC___V,'=',ON, 1 )){
            case RUN: { A1STEPZ__V=A1TKLO___R; A1STEPC__V=CNTTO[A1BTM+2]; return; }
            case BAD: { Clear_TO(A1BTM+2); Message(139+A1BNM); Bell(1,1); return; }
        }
        // после закрытия установить флаг подтверждения закрытия исполнителей
        A1PPSTEP_V=705;
        // после окончания перепуска пара автоклав переключается в режим
        // "СБРОС ДАВЛЕНИЯ"
        Clear_TO(A1BTM+1); Clear_TO(A1BTM+2);
        A1STEPZ__V=0; A1STEPC__V=0;
        Set_BV1(704); Set_ST1(600);
        // если АК-при не в режиме НАБОРА ДАВЛЕНИЯ (нестандартная ситуация)
        // перевести этот АК в режим ОЖИДАНИЯ
        if(A1IPPSTEPV<400||A1IPPSTEPV>500){ Set_ST1(50); }
        A1SP____YM=OFF; A1SP____YV=ON;
        // сообщение об окончании режима
        Message(207+A1BNM);
        return;
    }
//  // ----------------------------------------------------------------------


    return;
}
//---------------------------------------------------------------------------
