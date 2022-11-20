//---------------------------------------------------------------------------

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V4GNS1BS_V = 0;           // состояние кнопки включения гидронасоса

_f  far  I4KR_TMP_V = 0;           // текущ контрол значение выбран  крышки
_f  far  I4KR1CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка1
_f  far  I4KR1OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка1

_f  far  A4TVACUM_R = 6000;        // время вакуумирования (100 минут)
_f  far  I4MAXVCN_V = 0;           // счетчик превышения макс разрежения
_f  far  O4ZOPPO__Y = 0;           // сигнал откр задв остр пара на АК передат
_f  far  I4ZOPPO__Y = 0;           //
_f  far  A4RPZD___S = 0;           // шаг задания регулятора "НАБОРА ДАВЛЕНИЯ"
_f  far  A4ISPST__C = 0;           // счетчик пароля определения шага
_f  far  A4FLAG=0;                 // дополнительные переменные
_f  far  A4FLGP=0;                 //
_f  far  A4TEMP=0;                 //
_f  far  A4PPRT=0;                 // возврат из функций определения шага пер
_f  far  A4SBPT=0;                 // счетчик разблокировки СБУ
_f  far  A4SBPC=0;                 // счетчик блокировки СБУ
_f  far  A4SBPI=0;                 // счетчик ЗАКРЫТО исполнителей для СБУ
_f  far  A4CISP=0;                 // счетчик контроля состояния исполнителей


//---------------------------------------------------------------------------
//  управление исполнителями задвижек и клапанов АК4
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS4(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  острого пара
    if (i1==  ON){ O4ZIOPO__M= ON; O4ZIOPC__M=OFF; }   //  открыть
    if (i1== OFF){ O4ZIOPO__M=OFF; O4ZIOPC__M= ON; }   //  закрыть
    if (i1==STOP){ O4ZIOPO__M=OFF; O4ZIOPC__M=OFF; }   //  остановить
    // перепускного пара входящего
    if (i2==  ON){ O4ZIPPO__M= ON; O4ZIPPC__M=OFF; }
    if (i2== OFF){ O4ZIPPO__M=OFF; O4ZIPPC__M= ON; }
    if (i2==STOP){ O4ZIPPO__M=OFF; O4ZIPPC__M=OFF; }
    // перепускного пара выходящего
    if (i3==  ON){ O4ZOPPO__M= ON; O4ZOPPC__M=OFF; }
    if (i3== OFF){ O4ZOPPO__M=OFF; O4ZOPPC__M= ON; }
    if (i3==STOP){ O4ZOPPO__M=OFF; O4ZOPPC__M=OFF; }
    // сброса в атмосферу
    if (i4==  ON){ O4ZOPAO__M= ON; O4ZOPAC__M=OFF; }
    if (i4== OFF){ O4ZOPAO__M=OFF; O4ZOPAC__M= ON; }
    if (i4==STOP){ O4ZOPAO__M=OFF; O4ZOPAC__M=OFF; }
    // вакуумная задвижка
    if (i5==  ON){ O4VZO____M= ON; O4VZC____M=OFF; }
    if (i5== OFF){ O4VZO____M=OFF; O4VZC____M= ON; }
    if (i5==STOP){ O4VZO____M=OFF; O4VZC____M=OFF; }
    // клапан впуска пара
    if (i6==  ON){ O4KIPO___M= ON; O4KIPO___V= ON; O4KIPC___M=OFF; O4KIPC___V=OFF; }
    if (i6== OFF){ O4KIPO___M=OFF; O4KIPO___V=OFF; O4KIPC___M= ON; O4KIPC___V= ON; }
    if (i6==STOP){ O4KIPO___M=OFF; O4KIPO___V=OFF; O4KIPC___M=OFF; O4KIPC___V=OFF; }
    // клапан выпуска пара
    if (i7==  ON){ O4KOPO___M= ON; O4KOPO___V= ON; O4KOPC___M=OFF; O4KOPC___V=OFF; }
    if (i7== OFF){ O4KOPO___M=OFF; O4KOPO___V=OFF; O4KOPC___M= ON; O4KOPC___V= ON; }
    if (i7==STOP){ O4KOPO___M=OFF; O4KOPO___V=OFF; O4KOPC___M=OFF; O4KOPC___V=OFF; }
    // клапан сброса конденсата
    if (i8==  ON){ O4KOCO___M= ON; O4KOCO___V= ON; O4KOCC___M=OFF; O4KOCC___V=OFF; }
    if (i8== OFF){ O4KOCO___M=OFF; O4KOCO___V=OFF; O4KOCC___M= ON; O4KOCC___V= ON; }
    if (i8==STOP){ O4KOCO___M=OFF; O4KOCO___V=OFF; O4KOCC___M=OFF; O4KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  управление исполнителями крышек АК5
//              NUM       BY        HM        KR 
vd  far Set_KR4(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // байонет
       if (b==  ON){ O4BY1O___M= ON; O4BY1C___M=OFF; }   //  открыть
       if (b== OFF){ O4BY1O___M=OFF; O4BY1C___M= ON; }   //  закрыть
       if (b==STOP){ O4BY1O___M=OFF; O4BY1C___M=OFF; }   //  остановить
       // хомут
       if (h==  ON){ O4HM1UP__M= ON; O4HM1DN__M=OFF; }
       if (h== OFF){ O4HM1UP__M=OFF; O4HM1DN__M= ON; }
       if (h==STOP){ O4HM1UP__M=OFF; O4HM1DN__M=OFF; }
       // крышка
       if (k==  ON){ O4KR1O___M= ON; O4KR1C___M=OFF; }
       if (k== OFF){ O4KR1O___M=OFF; O4KR1C___M= ON; }
       if (k==STOP){ O4KR1O___M=OFF; O4KR1C___M=OFF; }
    }
    if(n==2){
       // байонет
       if (b==  ON){ O4BY2O___M= ON; O4BY2C___M=OFF; }
       if (b== OFF){ O4BY2O___M=OFF; O4BY2C___M= ON; }
       if (b==STOP){ O4BY2O___M=OFF; O4BY2C___M=OFF; }
       // хомут
       if (h==  ON){ O4HM2UP__M= ON; O4HM2DN__M=OFF; }
       if (h== OFF){ O4HM2UP__M=OFF; O4HM2DN__M= ON; }
       if (h==STOP){ O4HM2UP__M=OFF; O4HM2DN__M=OFF; }
       // крышка
       if (k==  ON){ O4KR2O___M= ON; O4KR2C___M=OFF; }
       if (k== OFF){ O4KR2O___M=OFF; O4KR2C___M= ON; }
       if (k==STOP){ O4KR2O___M=OFF; O4KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Очистка всех таймеров и счетчика
vd  far Clear_TA4(vd){
    Clear_TO(A4BTM+ 1); Clear_TO(A4BTM+ 2); 
    Clear_TO(A4BTM+ 3); Clear_TO(A4BTM+ 4); 
    Clear_TO(A4BTM+ 5); Clear_TO(A4BTM+ 6);
    Clear_TO(A4BTM+ 7); Clear_TO(A4BTM+ 8); 
    Clear_TO(A4BTM+ 9); Clear_TO(A4BTM+10);
    Clear_TO(A4BTM+11); Clear_TO(A4BTM+12);
    Clear_TO(A4BTM+13); Clear_TO(A4BTM+14);
    Clear_TO(A4BTM+15); Clear_TO(A4BTM+16);
    Clear_TO(A4BTM+17); Clear_TO(A4BTM+18);
    Clear_TO(A4BTM+19);
    A4STEPZ__V=0; A4STEPC__V=0;
}
//---------------------------------------------------------------------------
//  установка начальных значений при смене режима работы автоклава
vd  far Set_BV4(_f far A4STEPWPRV){
    // запомнить номер предыдущего шага
    A4STEPP__V =A4STEP___V;
    A4STEPWP_V =A4STEPWPRV;
    // сбросить  флаги паролей
    A4CYCRN__V =OFF; A4CYCRN__M=OFF;
    A4CYCST__V =OFF; A4CYCST__M=OFF;
    A4ISPST__V =OFF; A4ISPST__M=OFF;
    // обнулить счетчики режимов и таймеров
    A4STEPH__V =0;   A4STEPM__V=0; A4STEPS__V=0; 
    // сбросить флаги выбора крышек для открытия и закрытия
    I4KR1OBS_V =0;
    I4KR1CBS_V =0;
    I4KR_TMP_V=-1;
    // снять команды со всех исполнителей крышек
    Set_KR4(1,STOP,STOP,STOP);
    Set_KR4(2,STOP,STOP,STOP);
    //  обнуление значений таймеров
    Clear_TA4();
    // снять команды на хомуты
    O4HM1UP__M=OFF; O4HM1DN__M=OFF;
    O4HM2UP__M=OFF; O4HM2DN__M=OFF;
    // снять команды на байонеты
    O4BY1O___M=OFF; O4BY1C___M=OFF;
    O4BY2O___M=OFF; O4BY2C___M=OFF;
    // снять команды на крышки
    O4KR1O___M=OFF; O4KR1C___M=OFF;
    O4KR2O___M=OFF; O4KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  установка текущего шага режима работы автоклава
vd  far Set_ST4(int SS){
    A4STEPW__V=SS;
    A4STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  получение значений из переменных удаленных контроллеров
//  A3PPSTEP_V - номер шага программы текущ АК
//  A3RPPSTEPV - принимаемое с АК-пер значение,сигнализирующее о выполнении на
//               АК-пер текущего шага
_f  far Get_RV4(vd){
    // если выбран номер 0- набор пара делается с магистрали
    if(A4NAKPPREM==0){ return(0); }
    A4RPPSTEPV=0;
    if(A4NAKPPREM==1){ A4RPPSTEPV=A1PPSTEP_V; AIPRP4___V=AIP1P____V; }
    if(A4NAKPPREM==2){ A4RPPSTEPV=A2PPSTEP_V; AIPRP4___V=AIP2P____V; }
    if(A4NAKPPREM==3){ A4RPPSTEPV=A3PPSTEP_V; AIPRP4___V=AIP3P____V; }
    if(A4NAKPPREM==5){ A4RPPSTEPV=A5PPSTEP_V; AIPRP4___V=AIP5P____V; }
    if(A4NAKPPREM==6){ A4RPPSTEPV=A6PPSTEP_V; AIPRP4___V=AIP6P____V; }
    if(A4RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // если текущий АК находится в режиме НАБОРА пер.паром
    if(A4PPSTEP_V==420){
       // если АК-пер перешел в режим ПЕРЕБРОСА и открыл задвижку вып пер.пара
       if(A4RPPSTEPV==700) return(1); return(0);
    }
    // текущий АК ожидает открытия клапана вып пер.пара на АК-пер
    if(A4PPSTEP_V==425){
       if(A4RPPSTEPV==704) return(2); return(0);
    }
    // текущий АК ожидает закрытия исполнителей выпуска пара на АК-пер
    if(A4PPSTEP_V==480){
       // если на АК-пер исполнители закрылись
       if(A4RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Получение текущего шага АК-инициатора (АК-при) при отдаче пара
_f  far Get_RA4(int mode){
    // проверить что другие автоклавы не находятся в режиме переброса
    // определять по состоянию перепускных задвижек (впуск,выпуск)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A2PPSTEP_V>=700 or 
          A3PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // Определить номер АК, который запрашивает текущий для отдачи пара
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==4){ A4IPPNUM_V=1; return(1); }
       if(A2PPSTEP_V==420 and A2NAKPP__R==4){ A4IPPNUM_V=2; return(2); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==4){ A4IPPNUM_V=3; return(3); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==4){ A4IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==4){ A4IPPNUM_V=6; return(6); }
       return(0);
    }
    // Определить текущий шаг на АК-инициаторе (АК-при)
    if(mode==2){
       if(A4IPPNUM_V==1){ A4IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A4IPPNUM_V==2){ A4IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A4IPPNUM_V==3){ A4IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A4IPPNUM_V==5){ A4IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A4IPPNUM_V==6){ A4IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка блокировки СБУ
int Chk_SBP4(vd){
    //-------------------------------------------
    // Если программа не на шаге работы с крышками
    if(A4STEPW__V<100||(A4STEPW__V>290&&A4STEPW__V<800)||A4STEPW__V>890){
      // Если разблокировали СБУ - выдать команду на закрытие
      // всех задвижек и перейти в режим ожидания
      if(I4SBP1R__V>0){
        // cбросить счетчик блокировки СБУ (защита от дребезга)
        A4SBPC=0;
        // Если не закрыт хоть один из проверяемых исполнителей
        if(I4ZIOPC__V!=ON|| I4ZIPPC__V!=ON||I4ZOPPC__V!=ON||I4ZOPAC__V!=ON||
           I4VZC____V!=ON||(I4KOCC___V!=ON&&(A4STEPP__V==3||A4STEP___V==3))){
////СБУ РАЗБЛОКИРОВАНО.ЧТО-ТО ОТКРЫТО.        
           // cбросить счетчик стабильного состояния ЗАКРЫТО исполнителей
           A4SBPI=0;
           //-----------
           // если програма сюда зашла с шага меньше, чем 910(другой режим)
           if(A4STEPW__V<910){
              // увеличить счетчик сработки СБУ (считаем 5сек) и выйти
              if(A4SBPT <5){ A4SBPT++; return(1); }
              // последний раз после проверки счетчика перед проверкой
              // исполнителей- обнулить счетчики и таймеры (когда прошло 5сек)
              A4STEPZ__V=0; A4STEPC__V=0; Set_BV4(A4STEPW__V);
              Message(107+A4BNM);
           }
           //-----------
           // установить режим закрытия исполнителей по разблокировке СБУ
           Set_ST4(910);
           // выдать команду на закрытие всех исполнителей
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // задвижка впуска острого пара закрыта?
           Set_ST4(911);
           switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return(1); }
             case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return(1); }
           }
           // задвижка впуска перепускного пара закрыта? 
           Set_ST4(912);
           switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return(1); }
             case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM); Bell(4,1); return(1); }
           }
           // задвижка выпуска перепускного пара закрыта?
           Set_ST4(913);
           switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return(1); }
             case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM); Bell(4,1); return(1); }
           }
           // задвижка выпуска пара в атмосферу закрыта?
           Set_ST4(914);
           switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return(1); }
             case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM); Bell(4,1); return(1); }
           }
           // задвижка вакуума закрыта?
           Set_ST4(915);
           switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return(1); }
             case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM); Bell(4,1); return(1); }
           }
           // если СБУ было разблокировано в режиме ВАКУУМИРОВАНИЯ
           if(A4STEPP__V==3){
           // клапан выпуска конденсата закрыт?
           Set_ST4(916);
           switch ( Check_TO(A4BTM+6, A4RCHKF__R* SEC, I4KOCC___V,'=',ON,  1 )){
             case RUN: { A4STEPZ__V=A4RCHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return(1); }
             case BAD: { Clear_TO(A4BTM+6); Message(146+A4BNM); Bell(4,1); return(1); }
           } }
           // если все закрыто- перейти в режим ожидания разблокировки СБУ
           Set_ST4(917); return(1);
        } else {
////СБУ РАЗБЛОКИРОВАНО.ВСЕ ЗАКРЫТО.        
           // если все проверяемые исполнители закрыты- уменьшить счетчик и
           // ждать на шаге 900, пока заблокируют СБУ
           if(A4SBPI<5){ A4SBPI++; return(1); }
           // после счетчика стабильного закрытия исполнителей-
           // сбросить счетчик ожидания  закрытия исполнителей
           A4SBPT=0;
           // если разблокировали СБУ в каком-то режиме,но все исполнители
           // закрыты- выдать сообщение с указанием режима на котором 
           // заблокировали СБУ
           if(A4STEPW__V<900){ Set_BV4(A4STEPW__V); Message(106+A4BNM); }
           // если исполнители были закрыты после разблокировки СБУ-
           // выдать сообщение о том, что исполнители закрыли
           if(A4STEPW__V>900){ Message(108+A4BNM ); }
           Set_ST4(900);
        }
      } else {
////СБУ ЗАБЛОКИРОВАНО.
        // если СБУ заблокированы и последний выполняемый шаг был закрытие
        // задвижек при разблокировке СБУ
        if(A4STEPW__V>=900){
           // ожидать 5сек стабильной блокировки СБУ
           if(A4SBPC<5){ A4SBPC++; return(1); }
           // перейти в режим ожидания
           Message(109+A4BNM); Set_BV4(910); Set_ST4(50); return(1);
        }
        // когда СБУ заблокированы- сбросить счетчики блокировки СБУ и выйти
        A4SBPT=0;
        A4SBPC=0;
        A4SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка исполнителей при работе с крышками
int Chk_IF4(int mode){
    // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
    if(I4ZIOPC__V!=ON){ Message(141+A4BNM); return(0); }
    // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
    if(I4ZIPPC__V!=ON){ Message(142+A4BNM); return(0); }
    // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
    if(I4ZOPPC__V!=ON){ Message(143+A4BNM); return(0); }
    // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
    if(I4ZOPAC__V!=ON){ Message(144+A4BNM); return(0); }
    // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
    if(I4VZC____V!=ON){ Message(145+A4BNM); return(0); }
    // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
    if(I4KOCC___V!=ON){ Message(146+A4BNM); return(0); }
    // СБУ разблокирован?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I4SBP1R__V==0){ Message(149+A4BNM); return(0); }
    }
    // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I4P1_N___V==0){ Message(156+A4BNM); return(0); }
    }
    // есть напряжение на щите управл гидронасосом? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I4VACKR__V!=ON){ Message(157+A4BNM); return(0); }
    }
    // режим управления крышками автоклава дистанц? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I4LUCDU__V!=ON){ Message(158+A4BNM); return(0); }
    }
    // режим управления автоклавом дистанция(ПК)?
    if(mode==0 or mode==1){
      if(I4DU_____V!=ON){ Message(188+A4BNM); return(0); }
    }
    // проверка работы (включенного состояния) гидронасоса 
    // ожидание включения гидронасоса               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I4GNS_1__V!=ON){ Message(160+A4BNM); return(0); }
    }
    // если нажата кнопка СТОП
    if(mode>0){
       // если ДА - переходим в режим ГИДРОНАСОС
       if(I4KR1SB__V==ON || I4GNS0B__V==ON){
          A4CISP=0; Message(168+A4BNM); Set_BV4(870); Set_ST4(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_04(vd){

    // установить флаг ввода пароля запуска цикла и перейти
    // на режим  "ВАКУУМИРОВАНИЕ"
    if (A4CYCRN__M>OFF){ A4CYCRN__V=ON; A4CYCRN__M=OFF; Set_ST4(300); }
    // установить флаг ввода пароля остановки цикла
    if (A4CYCST__M>OFF){ A4CYCST__V=ON; A4CYCST__M=OFF; Set_ST4(50);  }
    // установить флаг ввода пароля перехода на заданный шаг
    if (A4ISPST__M>OFF){ A4ISPST__V=ON; A4ISPST__M=OFF; }

    // определение номера режима из шага
    A4STEP___V=floor( A4STEPW__V*0.01);
    // проверка граничного значения введенного шага
    if (A4STEPW__M<0  or A4STEPW__M>900){ A4STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  Если был изменен шаг работы автоклава и введен пароль изменения шага
    if (A4STEPW__M!=A4STEPW__V and A4ISPST__V==ON){
        //  если выбран РУЧНОЙ РЕЖИМ управления и введен пароль
        //  запуска или останова цикла
        if((A4STEPW__M<=10)){
            A4STEPW__V =A4STEPW__M; Message(130+A4BNM);
        }
        //  если выбран режим "ОТКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=100) and (A4STEPW__M< 200) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(131+A4BNM);
        }
        //  если выбран режим "ЗАКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=200) and (A4STEPW__M< 300) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(132+A4BNM);
        }
        //  если выбран режим "ВАКУУМИРОВАНИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=300) and (A4STEPW__M< 400) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(133+A4BNM);
        }
        //  если выбран режим "НАБОР ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=400) and (A4STEPW__M< 500) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(134+A4BNM); A4NAKPPREM=A4NAKPP__R;
        }
        //  если выбран режим "ВЫДЕРЖКА" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=500) and (A4STEPW__M< 600) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(135+A4BNM);
        }
        //  если выбран режим "СБРОС ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A4STEPW__M>=600) and (A4STEPW__M< 700) and (A4STEPW__V<=10)){
            A4STEPW__V =A4STEPW__M;  Message(136+A4BNM);
        }
        //-------------------------------------------------------------------
        //  установка вновь определенного режима работы 
        if (A4STEPW__M == A4STEPW__V){ Set_BV4(0); }
        else                         { A4STEPW__M=A4STEPW__V; }
    }
//  // ----------------------------------------------------------------------





         

//  // ----------------------------------------------------------------------
//  // Проверки и контроль для каждой новой секунды
    if(NewSEC>0){ 
       //-------------------------------------------
       // подсчет времени работы в текущем режиме
       // считать секунды
       A4STEPS__V++;
       // считать минуты
       if(A4STEPS__V>59){ A4STEPM__V++; A4STEPS__V=0; }
       // считать часы
       if(A4STEPM__V>59){ A4STEPH__V++; A4STEPM__V=0; }
       // через 99 часов время считается сначала (4,5 суток)
       if(A4STEPH__V>99){ A4STEPH__V=0; A4STEPM__V=0; A4STEPS__V=0; }
       //-------------------------------------------
       // если был введен пароль- устанавливается флаг ввода пароля, который
       // действителен 10 секунд
       if(A4ISPST__V==ON or A4CYCST__V==ON or A4CYCRN__V==ON){ A4ISPST__C++; }
       // если прошло более 10 сек после ввода пароля- сбросить флаг ввода 
       // пароля  и счетчик секунд (пароль нужно вводить заново)
       if(A4ISPST__C >10){ 
          A4ISPST__C=0; A4ISPST__V=OFF; A4CYCST__V=OFF; A4CYCRN__V=OFF;
       }
       //-------------------------------------------
       // если был изменен режим управления работой автоклава (ЩТ/ПК)
       if(S4MDUP___V!=S4MDU____V){
          // переведено на ЩИТ - перевести программу в режим "ОЖИДАНИЕ"
          if(S4MDU____V==0){
             Message(137+A4BNM); Set_BV4(0); Set_ST4(50);
          }
          // переведено на ПК  - выдать сообщение  и в режим "ОЖИДАНИЕ"
          if(S4MDU____V==1){
             Message(138+A4BNM); Set_BV4(0); Set_ST4(50);
          }
       }; S4MDUP___V=S4MDU____V;
       //-------------------------------------------
       if(Chk_SBP4()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОЖИДАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Ожидание нажатия кнопок открытия-закрытия автоклава из режима "ОЖИДАНИЕ"
    if (A4STEPW__V<=10||A4STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // Ожидание нажатия кнопки включения гидронасоса
        // Если нажата- перейти на шаг 870
        if(V4GNS1BS_V<1){
           if(I4GNS1B__V>0){
              Message(183+A4BNM); O4GNS____M=ON; A4CISP=0;
              Set_BV4(50); V4GNS1BS_V=1; Set_ST4(870); return;
           }
        }
        // Выключение гидронасоса
        if(I4GNS0B__V>0){ 
           V4GNS1BS_V=0; O4GNS____M=OFF; 
        }
        //-----------
        // контроль готовности автоклава перейти в режим "ПЕРЕБРОСА"
        //(давление в автоклаве д.б.  >1 и закрыты все задвижки, клапана и
        // исполнители крышек, АК на дистанции).
        if(AIP4P____V>1 and I4ZIOPC__V>0 and I4ZIPPC__V>0 and I4ZOPPC__V>0 and
           I4VZC____V>0 and I4ZOPAC__V>0 and I4KIPC___V>0 and I4KOPC___V>0 and
           I4DU_____V>0 and
           I4SBP1Z__V>0 ){
           // определить, что другие АК не находятся в режиме перепуска
           if(Get_RA4(0)>0){
              // если какой-то АК запрашивает данный для ПЕРЕПУСКА-
              // определить его номер
              if(Get_RA4(1)>0){
                 // перейти на режим ПЕРЕБРОС
                 Message(129+A4BNM); Set_BV4(0); Set_ST4(700);
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
    if (A4STEPW__V>=50 and A4STEPW__V<70){
       // если ушли с шага 232:- опустить хомут
       if(A4STEPWP_V==232){

       }
       // снять команды со всех исполнителей
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS4(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR4(1,STOP,STOP,STOP);
       Set_KR4(2,STOP,STOP,STOP);
       // выключить гидронасос
       O4GNS____M=OFF;
       // сбросить команду включения гидронасоса
       V4GNS1BS_V=0;
       // снять галочки с выбора режимов цикла
       A4NAKPP_YM=OFF;  A4NAKPP_YV=A4NAKPP_YM;
       A4RAZVK_YM=OFF;  A4RAZVK_YV=A4RAZVK_YM;
       A4PPP___YM=OFF;  A4PPP___YV=A4PPP___YM;
       A4PVID__YM=OFF;  A4PVID__YV=A4PVID__YM;
       A4SP____YM=OFF;  A4SP____YV=A4SP____YM;
       // очистить текущие таймеры и счетчики
       Clear_TA4();
       A4PPSTEP_V=0;
       // перейти в режим ОЖИДАНИЕ
       Message(189+A4BNM); Set_BV4(50); Set_ST4(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  Включение ГИДРОНАСОСА
//  // ----------------------------------------------------------------------
    if (A4STEPW__V>=870 and A4STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST4(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        //-----------
        // если нажата кнопка выключения гидронасоса- выдать комманду на 
        // выключение гидронасоса
        if(I4GNS0B__V==ON){ 
           Message(184+A4BNM);
           // выдать команду на выключение гидронасоса
           O4GNS____M=OFF;
           // сбросить флаг состояния кнопки включения гидронасоса
           V4GNS1BS_V=0; 
        }
        // если поступила команда на выключение гидронасоса
        if(V4GNS1BS_V==0&&O4GNS____M==OFF){
           // снять команды с исполнителей механизмов крышки
           //      N BY   HM   KR
           Set_KR4(1,STOP,STOP,STOP);
           Set_KR4(2,STOP,STOP,STOP);
           // снять команды с исполнителей задвижек
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ждать выключение гидронасоса
           switch( Check_TO(A4BTM+1,60*SEC, I4GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A4BNM); Bell(4,1); break; }
              case END: { Message(185+A4BNM); break; }
           }
           // перейти в режим ожидания
           Set_BV4(870); Set_ST4(50); return;
        }
        // проверка состояния исполнителей
        if(Chk_IF4(0)==0){
           A4CISP++; 
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(50); 
           }
           return; 
        }; A4CISP=0;
        //-----------
        // выдать комманду на включение гидронасоса:
        O4GNS____M= ON;
        //-----------
        // ожидание нажатия кнопки "Открыть автоклав"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I4KR1OBS_V<1 and I4KR1CBS_V<1){
           if(I4KR1OB__V>0){
              Message(174+A4BNM); A4CISP=0;
              Set_BV4(50); I4KR1OBS_V=1; V4GNS1BS_V=1; Set_ST4(100); return;
           }
        }
        //-----------
        // ожидание нажатия кнопки "Закрыть автоклав"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I4KR1OBS_V<1 and I4KR1CBS_V<1){
           if(I4KR1CB__V>0){
              Message(176+A4BNM);  A4CISP=0;
              Set_BV4(50); I4KR1CBS_V=1; V4GNS1BS_V=1; Set_ST4(200); return;
           }
        }
        //-----------
        Clear_TA4();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОТКРЫТИЯ" АК4
//  // ----------------------
//  //  Проверка начального состояния исполнителей:
    if (A4STEPW__V>=100 and A4STEPW__V< 130){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O4GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        // сообщение о начале режима
        if(A4STEPW__V!=126){ Message(195+A4BNM); }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST4(126);
        I4KR_TMP_V=-1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(126); Set_ST4(870); return;}
        switch ( Check_TO(A4BTM+14,A4THMUP__R*SEC, I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R;A4STEPC__V =CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(151+A4BNM);
                        // если это первый шаг контроля- увеличить счетчик 
                        // контроля и дать команду на поднятие хомута
                        if(A4TEMP<1){ 
                           if(I4KR1OBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
                           A4TEMP++;
                        }
                        // если это второй шаг контроля- звонок и переход в
                        // режим ОЖИДАНИЯ
                        else        { Bell(4,1); Set_BV4(126); Set_ST4(870); }
                        return;
                      }
        }
        // очистить таймеры и счетчики
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15);
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        Clear_TO(A4BTM+18); Clear_TO(A4BTM+19);
        A4STEPZ__V=0; A4STEPC__V=0;
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        Set_ST4(130);  A4TEMP=0;
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ОТКРЫТИЕ АВТОКЛАВА":
    if (A4STEPW__V>=130 and A4STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O4GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST4(132);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4BY1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(132); Set_ST4(870); return;}
        // если байонет не открыт
        if(I4KR_TMP_V==OFF){
//         // команда на открытие байонета              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // подается импульсами: 2сек импульс, 2сек пауза
           if(A4TEMP<2){
             // импульс на открытие
             if(I4KR1OBS_V>0){ O4BY1O___M=ON; O4BY1C___M=OFF; }
             A4TEMP++;
           } else {
             // пауза
             if(A4TEMP<4){
                O4BY1O___M=OFF; O4BY1C___M=OFF;
                O4BY2O___M=OFF; O4BY2C___M=OFF;
                A4TEMP++;
             } else {
             // переход после паузы на импульс
                if(A4TEMP<7) A4TEMP=0;
             }
           }  
        }
        switch (Check_TO( A4BTM+16,A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(154+A4BNM); Bell(4,1); 
                        Set_BV4(132); Set_ST4(870);
                        return; 
                      }
        }
        // сброс флага подачи импульсного сигнала на байонет
        A4TEMP=10;
        // снять команду на открытие байонетов          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O4BY1O___M=OFF; O4BY1C___M=OFF;
        O4BY2O___M=OFF; O4BY2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A4BTM+17,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+17]; return; }
        }
//      // команда на поднятие хомута                   [x6.o01 (OxHM1UP) = 1]
        if(I4KR1OBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        Set_ST4(131);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(131); Set_ST4(870); return;}
        switch (Check_TO( A4BTM+14,A4THMUP__R*SEC,I4KR_TMP_V, '=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(151+A4BNM); Bell(4,1);
                        Set_BV4(131); Set_ST4(870);    return;
                      }
        }
        // снять команду на поднятие хомута             [x6.o01 (OxHM1UP) = 0]
        O4HM1UP__M=OFF; O4HM1DN__M=OFF;
        O4HM2UP__M=OFF; O4HM2DN__M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        //--------
//      // команда на открытие крышки                   [x6.o03 (OxKR1O_) = 1]
        if(I4KR1OBS_V>0){ O4KR1O___M=ON; O4KR1C___M=OFF; }
        // крышки открыты?                              [x7.i02 (IxKR1O_) = 1]
        Set_ST4(133);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4KR1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(133); Set_ST4(870);  return;}
        switch (Check_TO( A4BTM+18,A4TKRO___R*SEC, I4KR_TMP_V, '=',ON,1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+18); Message(152+A4BNM); Bell(4,1); 
                        Set_BV4(133); Set_ST4(870);
                        return; 
                      }
        }
        // команды с крышек снимем после опускания хомута

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO(A4BTM+19,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+19]; return; }
        }
        // очистить таймеры и счетчики
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15);
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        Clear_TO(A4BTM+18); Clear_TO(A4BTM+19);
        A4STEPZ__V=0; A4STEPC__V=0;
        //
        Set_ST4(134); A4TEMP=0; return;
    }
//  // ----------------------
//  //  Опускание хомута
    if (A4STEPW__V>=134 and A4STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O4GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
//      // команда на опускание хомутов                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I4KR1OBS_V>0){ O4HM1DN__M=ON; O4HM1UP__M=OFF; }
        // хомуты опущены?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST4(134);
        I4KR_TMP_V= -1;
        if(I4KR1OBS_V>0){ I4KR_TMP_V=I4HM1DN__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(134); Set_ST4(870);  return;}
        switch (Check_TO( A4BTM+14,A4THMUP__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(150+A4BNM); Bell(4,1); 
                        Set_BV4(134); Set_ST4(870);
                        return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        Message(191+A4BNM);
        // перевод управления автоклавом в режим "ГИДРОНАСОС"->"ОЖИДАНИЕ"|"СБУ"
        Message(197+A4BNM); Set_BV4(141); Set_ST4(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ЗАКРЫТИЯ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A4STEPW__V>=200 and A4STEPW__V< 230){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O4GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        // сообщение о начале режима
        if(A4STEPW__V==200){ Message(196+A4BNM); }
        //--------
        // хомут опущен?                                [x7.i01 (IxHM1DN) = 1]
        Set_ST4(226);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4HM1DN__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(226);  Set_ST4(870); return;}
        switch ( Check_TO (A4BTM+14, A4THMUP__R*SEC,   I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V = CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(150+A4BNM); Bell(4,1); 
                        Set_BV4(226); Set_ST4(870);   return; 
                      }
        }
        // выдать комманду на открытие байонета
        if(I4KR1CBS_V>0){ O4BY1O___M=ON; O4BY1C___M=OFF; }
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        // если байонет не открылся- выйти
        Set_ST4(228);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4BY1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(228); Set_ST4(870); return;}
        switch ( Check_TO (A4BTM+15, A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+15); Message(154+A4BNM); Bell(4,1);
                        Set_BV4(228); Set_ST4(870);   return; 
                      }
        }
        // снять команду с байонета
        O4BY1O___M=OFF; O4BY1C___M=OFF;
        O4BY2O___M=OFF; O4BY2C___M=OFF;
        //
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15); 
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(230);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": приподнять перед закрытием
    if (A4STEPW__V>=230 and A4STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O4GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // команда на приподнятие крышки                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I4KR1CBS_V>0){ O4KR1O___M=ON; O4KR1C___M=OFF; }
        // крышка поднята?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST4(231);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4KR1O___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(231); Set_ST4(870); return;}
        switch (Check_TO(A4BTM+14,A4TKRO___R*SEC, I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(152+A4BNM); Bell(4,1);
                        Set_BV4(231); Set_ST4(870);   return; 
                      }
        }
        // снять команду на поднятие крышки             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O4KR1O___M=OFF; O4KR1C___M=OFF;
        O4KR2O___M=OFF; O4KR2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        // подать команду на поднятие хомута            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I4KR1CBS_V>0){ O4HM1UP__M=ON; O4HM1DN__M=OFF; }
        Set_ST4(232);
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4HM1UP__V;   }
        if(I4KR_TMP_V<0){ Set_BV4(232); Set_ST4(870); return;}
        switch (Check_TO(A4BTM+16,A4THMUP__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4THMUP__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(151+A4BNM); Bell(4,1);
                        Set_BV4(232); Set_ST4(870);   return; 
                      }
        }
        // после поднятия хомута команда не снимается

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A4BTM+17,A4TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+17]; return; }
        }
        Clear_TO(A4BTM+14); Clear_TO(A4BTM+15); 
        Clear_TO(A4BTM+16); Clear_TO(A4BTM+17);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(235);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": закрыть крышки
    if (A4STEPW__V>=235 and A4STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O4GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF4(1)==0){
           A4CISP++;
           if(A4CISP>1){ 
              O4GNS____M=OFF; V4GNS1BS_V=0;
              Message(187+A4BNM); Set_BV4(870); Set_ST4(870); 
           }
           return;
        }; A4CISP=0;
        //--------
        // команда на закрытие крышек                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I4KR1CBS_V>0){ O4KR1C___M=ON; O4KR1O___M=OFF; }
        // крышка закрыта?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST4(236);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4KR1C___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(236); Set_ST4(870); return;}
        switch (Check_TO (A4BTM+14,A4TKRO___R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TKRO___R; A4STEPC__V=CNTTO[A4BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+14); Message(153+A4BNM); Bell(4,1);
                        Set_BV4(236); Set_ST4(870); return; 
                      }
        }
        // снять команду на закрытие крышек             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O4KR1C___M=OFF; O4KR1O___M=OFF;
        O4KR2C___M=OFF; O4KR2O___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A4BTM+15,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+15]; return; }
        }
        // команда на закрытие байонетов                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I4KR1CBS_V>0){ O4BY1C___M=ON; O4BY1O___M=OFF; }
        // байонеты закрыты?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST4(237);
        I4KR_TMP_V=-1;
        if(I4KR1CBS_V>0){ I4KR_TMP_V=I4BY1C___V;   }
        if(I4KR_TMP_V<0){ Set_BV4(237); Set_ST4(870); return;}
        switch (Check_TO (A4BTM+16,A4TBYRT__R*SEC,I4KR_TMP_V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TBYRT__R; A4STEPC__V=CNTTO[A4BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A4BTM+16); Message(155+A4BNM); Bell(4,1);
                        Set_BV4(237); Set_ST4(870);   return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR4(1,STOP,STOP,STOP);
        Set_KR4(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        Message(193+A4BNM);
        // перевод управления автоклавом в режим "ГИДРОНАСОС"
        Message(198+A4BNM); Set_BV4(235); Set_ST4(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ВАКУУМИРОВАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A4STEPW__V>=300 and A4STEPW__V<320){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "ВАКУУМИРОВАНИЕ"- перейти на сл режим
        if(A4RAZVK_YV==OFF){ Set_BV4(300); Set_ST4(400); return; }
        // проверка  вакуумирования других автоклавов
        // (на вакуумировании может находится  ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==300||A2PPSTEP_V==300||A3PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV4(300); Set_ST4(50); return; 
        }
        A4PPSTEP_V=300;
        // сообщение о начале режима
        if(A4STEPW__V==300){ Message(200+A4BNM); }
        //
        Set_ST4(311);
        // перевести регулятор конденсата в Авт режим, чтобы закрылся клапан
        A4RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST4(301);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST4(302);
        switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM); Bell(4,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST4(303);
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM); Bell(4,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST4(304);
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM); Bell(4,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST4(305);
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM); Bell(4,1); return; }
        }
        // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
        Set_ST4(306);
        switch ( Check_TO(A4BTM+6, A4RCHKF__R* SEC, I4KOCC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4RCHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(146+A4BNM); Bell(4,1); return; }
        }
        // СПУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST4(307);
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM); Bell(4,1); return; }
        }
        // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST4(308);
        switch ( Check_TO(A4BTM+8, 60*SEC,I4P1_N___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+8]; return; }
            case BAD: { Clear_TO(A4BTM+8); Message(156+A4BNM); Bell(4,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST4(309);
        switch ( Check_TO(A4BTM+9, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+9]; return; }
            case BAD: { Clear_TO(A4BTM+9); Message(147+A4BNM); Bell(4,1); return; }
        }
        // дистанционный режим работы вакуумнасоса      [x2.i08 (IxVNMD_) = 1]
        Set_ST4(310);
        switch ( Check_TO(A4BTM+10, 60*SEC, I4VNMD___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+10]; return; }
            case BAD: { Clear_TO(A4BTM+10); Message(162+A4BNM); Bell(4,1); return; }
        }
        // дистанционный режим работы задвижки          [x2.i07 (IxVZMD_) = 1]
        Set_ST4(311);
        switch ( Check_TO(A4BTM+11, 60*SEC, I4VZMD___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+11]; return; }
            case BAD: { Clear_TO(A4BTM+11); Message(182+A4BNM); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6);
        Clear_TO(A4BTM+7); Clear_TO(A4BTM+8); Clear_TO(A4BTM+9);
        Clear_TO(A4BTM+10); 
        Clear_TO(A4BTM+11);
        A4STEPZ__V=0; A4STEPC__V=0;
        I4MAXVCN_V=0;
        Set_ST4(320);
        return;
    }
//  // ----------------------
//  //  Включение вакуумирования
    if (A4STEPW__V>=320 and A4STEPW__V<325){
        if(!NewSEC){ return; }
        // команда на открытие вакуумной задвижки       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // вакуумная задвижка открыта?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST4(321);
        switch ( Check_TO(A4BTM+1, A4TVZO___R* SEC, I4VZO____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(163+A4BNM); return; }
        }
        // снять команду на открытие вакуумной задвижки [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // закрывается клапан на вакуумном насосе       [x4.o04 (OxAZVO_) = 1]
        O4AZVO___V=ON; O4AZVO___M=OFF;
        // команда на включение вакуумного насоса       [x4.o05 (OxVN_1_) = 1]
        O4VN_1___V=ON; O4VN_1___M=OFF;
        Set_ST4(322);
        // вакуумный насос включен?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A4BTM+2, 60*SEC, I4VN_1___V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(164+A4BNM); Bell(4,1); return; }
        }
        // проверка канала максимального разрежения с   [x2.i06 (IxMAXV_) = 1]
        // эл.контактного манометра
        if(I4MAXV___V>0){ I4MAXVCN_V++; }
        else            { I4MAXVCN_V=0; }
        if(I4MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
           Set_ST4(325);
           return;
        }
        // проверка величины разрежения в автоклаве     [x0.06 (AIPxyV__) = ?]
        // (ждать зад вел или счет)
        Set_ST4(323);
        switch ( Check_TO(A4BTM+3, A4TVACUM_R* SEC, AIP34V___V,'<',A4RAZVK__R, 3)){
            case RUN: { A4STEPZ__V=A4TVACUM_R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Message(165+A4BNM); break; }
        }
        // дать комманду на закрытие вакуумной задвижки [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(325);
        return;
    }
//  // ----------------------
//  //  Выключение вакуумирования
    if (A4STEPW__V>=325 and A4STEPW__V<330){
        if(!NewSEC){ return; }
        // команда на закрытие вакуумной задвижки       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // вакуумная задвижка закрыта?                  [x2.i02 (IxVZC__) = 1]
        Set_ST4(326);
        switch ( Check_TO(A4BTM+1, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(166+A4BNM); return; }
        }
        // ждать некоторое время перед включением следующего исполнителя
        Set_ST4(327);
        switch (Check_TO (A4BTM+3,A4TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TBONIS_R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
        }
        // открыть клапан атмосферы на вакуумном насосе [x4.o04 (OxAZVO_) = 1]
        O4AZVO___V=OFF; O4AZVO___M=OFF;
        // выключить вакуумный насос                    [x4.o05 (OxVN_1_) = 0]
        O4VN_1___V=OFF; O4VN_1___M=OFF;
        Set_ST4(328);
        // вакуумный насос выключен?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A4BTM+4,  120*SEC, I4VN_1___V,'=',OFF, 1)){
            case RUN: { A4STEPZ__V=120; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(167+A4BNM); return; }
        }
        //
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); 
        Clear_TO(A4BTM+3); Clear_TO(A4BTM+4);
        A4STEPZ__V=0; A4STEPC__V=0;
        // сообщение об окончании режима
        Message(190+A4BNM); Set_ST4(330);
        return;
    }
//  // ----------------------
//  //  ВАКУУМИРОВАНИЕ ЗАКОНЧЕНО
    if (A4STEPW__V>=330 and A4STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // перевод управления автоклавом в ручной режим
        Set_BV4(330); Set_ST4(400);
        A4RAZVK_YM=OFF; A4RAZVK_YV=A4RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  Режим "НАБОР ДАВЛЕНИЯ"
//  // -----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A4STEPW__V>=400 and A4STEPW__V<420){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "НАБОР ДАВЛЕНИЯ"- перейти на сл режим
        if(A4PPP___YV==OFF){ Set_BV4 (400); Set_ST4(500); return; }
        A4PPSTEP_V=400;
        // сообщение о начале режима
        if(A4STEPW__V==400){ 
           Message(201+A4BNM); 
           A4RPRA___M=OFF; A4RPUU1__M=RMINUS; Set_ST4(401); return; 
        }
        //
        A4NAKPPREM=A4NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST4(401);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST4(402);
        switch ( Check_TO(A4BTM+2, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(142+A4BNM); Bell(4,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST4(403);
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM); Bell(4,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST4(404);
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM); Bell(4,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST4(405);
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM); Bell(4,1); return; }
        }
        // клапан впуска пара закрыт?
        Set_ST4(406);
        switch ( Check_TO(A4BTM+6, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(128+A4BNM); Bell(4,1); return; }
        }
        // СБУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST4(407);
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM); Bell(4,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST4(409);
        switch ( Check_TO(A4BTM+9, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+9]; return; }
            case BAD: { Clear_TO(A4BTM+9); Message(147+A4BNM); Bell(4,1); return; }
        }
        // режим управления автоклавом "Дистанция"?     [x1.i13 (IxDU___) = 1]
        Set_ST4(410);
        switch ( Check_TO(A4BTM+10, 60*SEC, I4VAC____V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*1; A4STEPC__V=CNTTO[A4BTM+10]; return; }
            case BAD: { Clear_TO(A4BTM+10); Message(159+A4BNM); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6); 
        Clear_TO(A4BTM+7); Clear_TO(A4BTM+8); Clear_TO(A4BTM+9); 
        Clear_TO(A4BTM+10);
        A4STEPZ__V=0; A4STEPC__V=0;
        // выбран режим набора давления магистральным паром?
        if(A4NAKPPREM==0) Set_ST4(430);
        else              Set_ST4(420);
        A4TEMP=0; A4FLAG=0; A4PPRT=0; A4RPRA___M=ON; A4RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Проверка готовности автоклава-передатчика (открытие на нем задвижки)
    if (A4STEPW__V>=420 and A4STEPW__V<422){
        if(!NewSEC){ return; }
        A4PPSTEP_V=420;
        Set_ST4(421);
        // ждать подтверждения о готовности к перепуску с автоклава
        // передатчика
        if(A4PPRT<1){
           A4PPRT=Get_RV4(); 
           return;
        }
        Set_ST4(422);
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Открытие исполнителей:
    if (A4STEPW__V>=422 and A4STEPW__V<425){
        if(!NewSEC){ return; }
        A4PPSTEP_V=422;
        // дать команду на открытие задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара открыта?   [x3.o02 (OxZIPPO) = 1]
        Set_ST4(423);
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZIPPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(161+A4BNM); Bell(4,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки пер.пара
        switch (Check_TO (A4BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // снять команду с задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        // перейти на следующий шаг
        Set_ST4(425);
        return;
    }
//  // ----------------------
//  // ожидание открытия на АК-пер клапана выпуска пара
    if (A4STEPW__V>=425 and A4STEPW__V<427){
        if(!NewSEC){ return; }
        A4PPSTEP_V=425;
        // ждать подтверждения об откр клапана выпуска пара на автоклаве
        // передатчике
        if(A4PPRT<2){
           A4PPRT=Get_RV4(); 
           return;
        }
        // перейти на управление клапаном (на регулятор)
        Set_ST4(440); A4RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  С магистрали
    if (A4STEPW__V>=430 and A4STEPW__V<435){
        if(!NewSEC){ return; }
        // дать команду на открытие задвижки магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистрального пара открыта? [x1.i00 (IxZIOPO) = 1]
        Set_ST4(431);
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(171+A4BNM); Bell(4,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки острого пара
        switch (Check_TO (A4BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // снять команду с задвижки впуска острого пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        // перейти на управление клапаном (на регулятор)
        Set_ST4(440); A4RPZD___S=0; A4RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  Формирование задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ"
    if (A4STEPW__V>=440 and A4STEPW__V<445){
        if(!NewSEC){ return; }
        // определяем задание расхода для ПИД регулятора из таблицы 
        // "НАБОР ТЕМПЕРАТУРЫ"
        Set_ST4(441);
        //-----------
        // Для набора температуры острым паром:
        if(A4NAKPPREM==0){
            // если текущая Т автоклава больше очередной заданой в таблице-
            // установить задание расхода для ПИД регулятора набора давления
            if(A4RPZD___S==0){ 
               A4RPZD___M =A41NTOF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=1;
            }
            if(AIT4P____V>=A41NTOP02R  and A4RPZD___S<=2){ 
               A4RPZD___M =A41NTOF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=2;
            }
            if(AIT4P____V>=A41NTOP03R  and A4RPZD___S<=3){ 
               A4RPZD___M =A41NTOF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=3;
            }
            if(AIT4P____V>=A41NTOP04R  and A4RPZD___S<=4){ 
               A4RPZD___M =A41NTOF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=4;
            }
            if(AIT4P____V>=A41NTOP05R  and A4RPZD___S<=5){ 
               A4RPZD___M =A41NTOF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=5;
            }
        } else {
        // Для набора температуры перепускным паром:
            if(A4RPZD___S==0){
               A4RPZD___M =A41NTPF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=1;
            }
            if(AIT4P____V>=A41NTPP02R  and A4RPZD___S<=2){
               A4RPZD___M =A41NTPF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=2;
            }
            if(AIT4P____V>=A41NTPP03R  and A4RPZD___S<=3){
               A4RPZD___M =A41NTPF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=3;
            }
            if(AIT4P____V>=A41NTPP04R  and A4RPZD___S<=4){
               A4RPZD___M =A41NTPF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=4;
            }
            if(AIT4P____V>=A41NTPP05R  and A4RPZD___S<=5){
               A4RPZD___M =A41NTPF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=5;
            }
        }
        //-----------
        // если давление в автоклаве больше того, что определено
        // в первой строке таблицы "НАБОР ДАВЛЕНИЯ" - определяем задание
        // расхода  для ПИД регулятора из таблицы "НАБОР ДАВЛЕНИЯ"
        // Для набора давления острым паром:
        if(A4NAKPPREM==0){
            if(AIP4P____V>=A41NPOP01R  and A4RPZD___S<=6){ 
               A4RPZD___M =A41NPOF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=6;
            }
            if(AIP4P____V>=A41NPOP02R  and A4RPZD___S<=7){ 
               A4RPZD___M =A41NPOF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=7;
            }
            if(AIP4P____V>=A41NPOP03R  and A4RPZD___S<=8){ 
               A4RPZD___M =A41NPOF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=8;
            }
            if(AIP4P____V>=A41NPOP04R  and A4RPZD___S<=9){ 
               A4RPZD___M =A41NPOF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=9; 
            }
            if(AIP4P____V>=A41NPOP05R  and A4RPZD___S<=10){ 
               A4RPZD___M =A41NPOF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=10;
            }
            if(AIP4P____V>=A41NPOP06R  and A4RPZD___S<=11){ 
               A4RPZD___M =A41NPOF06R; A4RPZD___V=A4RPZD___M; A4RPZD___S=11;
            }
            if(AIP4P____V>=A41NPOP07R  and A4RPZD___S<=12){ 
               A4RPZD___M =A41NPOF07R; A4RPZD___V=A4RPZD___M; A4RPZD___S=12;
            }
            if(AIP4P____V>=A41NPOP08R  and A4RPZD___S<=13){ 
               A4RPZD___M =A41NPOF08R; A4RPZD___V=A4RPZD___M; A4RPZD___S=13;
            }
            if(AIP4P____V>=A41NPOP09R  and A4RPZD___S<=14){ 
               A4RPZD___M =A41NPOF09R; A4RPZD___V=A4RPZD___M; A4RPZD___S=14;
            }
            if(AIP4P____V>=A41NPOP10R  and A4RPZD___S<=15){ 
               A4RPZD___M =A41NPOF10R; A4RPZD___V=A4RPZD___M; A4RPZD___S=15;
            }
        } else {
        // Для набора давления перепускным паром:
            if(AIP4P____V>=A41NPPP01R  and A4RPZD___S<=6){ 
               A4RPZD___M =A41NPPF01R; A4RPZD___V=A4RPZD___M; A4RPZD___S=6;
            }
            if(AIP4P____V>=A41NPPP02R  and A4RPZD___S<=7){ 
               A4RPZD___M =A41NPPF02R; A4RPZD___V=A4RPZD___M; A4RPZD___S=7;
            }
            if(AIP4P____V>=A41NPPP03R  and A4RPZD___S<=8){ 
               A4RPZD___M =A41NPPF03R; A4RPZD___V=A4RPZD___M; A4RPZD___S=8;
            }
            if(AIP4P____V>=A41NPPP04R  and A4RPZD___S<=9){ 
               A4RPZD___M =A41NPPF04R; A4RPZD___V=A4RPZD___M; A4RPZD___S=9;
            }
            if(AIP4P____V>=A41NPPP05R  and A4RPZD___S<=10){ 
               A4RPZD___M =A41NPPF05R; A4RPZD___V=A4RPZD___M; A4RPZD___S=10;
            }
            if(AIP4P____V>=A41NPPP06R  and A4RPZD___S<=11){ 
               A4RPZD___M =A41NPPF06R; A4RPZD___V=A4RPZD___M; A4RPZD___S=11;
            }
            if(AIP4P____V>=A41NPPP07R  and A4RPZD___S<=12){ 
               A4RPZD___M =A41NPPF07R; A4RPZD___V=A4RPZD___M; A4RPZD___S=12;
            }
            if(AIP4P____V>=A41NPPP08R  and A4RPZD___S<=13){ 
               A4RPZD___M =A41NPPF08R; A4RPZD___V=A4RPZD___M; A4RPZD___S=13;
            }
            if(AIP4P____V>=A41NPPP09R  and A4RPZD___S<=14){ 
               A4RPZD___M =A41NPPF09R; A4RPZD___V=A4RPZD___M; A4RPZD___S=14;
            }
            if(AIP4P____V>=A41NPPP10R  and A4RPZD___S<=15){ 
               A4RPZD___M =A41NPPF10R; A4RPZD___V=A4RPZD___M; A4RPZD___S=15;
            }
        }
        //-----------
        // если автоклав в режиме набора давления перепускным  паром и
        // если разница давлений между АК-передатчиком и АК-приемником
        // меньше заданному (AxZPPRE__R) -перейти на шаг
        // закрытия исполнителей набора перепускного пара и формирование
        // задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ" по острому пару
        A4PPSTEP_V=440; Get_RV4();
        if(A4NAKPPREM>0 and AIPRP4___V-AIP4P____V < A4ZPPRE__R){
           Set_ST4(480); A4PPRT=0; return;
        }

        //-----------
        // если давление в автоклаве больше заданного в "НАСТРОЙКАХ ЦИКЛА"-
        // перейти на шаг закрытия исполнителей магистрального пара
        if(A4NAKPPREM==0 and A4PPP____R>0 and AIP4P____V>=A4PPP____R){
           if(A4TEMP <7){ 
              A4TEMP++;     
           } else { 
              Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
              Set_ST4 (450);
           }
           return;
        } else {
           A4TEMP=0;
        }
        //-----------
        // если набор давления идет с магистрали и давление в автоклаве 
        // больше,чем давление в магистрали- закрыть задвижку впуска остр пара
        if(A4NAKPPREM==0 and AIP4P____V>=AIP34M___V){
           Set_ST4(442);
           // дать команду на закрытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // если перепад давления между АК и магистралью стабилизировался
        if(A4NAKPPREM==0 and AIP4P____V< AIP34M___V-A4ZNPM___R){
           Set_ST4(443);
           // дать команду на открытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS4(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей магистрального пара и переход на "ВЫДЕРЖКУ"
    if (A4STEPW__V>=450 and A4STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A4BTM+2, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(128+A4BNM); Bell(4,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_BV4(440); Set_ST4(500);
        A4PPP___YM=OFF;  A4PPP___YV=A4PPP___YM;
        // сообщение об окончании режима
        Message(202+A4BNM);
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей перепускного пара на АК-пер
    if (A4STEPW__V>=480 and A4STEPW__V<482){
        if(!NewSEC){ return; }
        A4PPSTEP_V=480;
        Set_ST4(481);
        // ждать подтверждения о закрытии исполнителей выпуска пара на
        // автоклаве передатчике
        if(A4PPRT<3){
           A4PPRT=Get_RV4(); return;
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(482);
        return;
    }
//  // ----------------------
    if (A4STEPW__V>=482 and A4STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST4(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара закрыта?
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(142+A4BNM); Bell(4,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A4BTM+2, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(128+A4BNM); Bell(4,1); return; }
        }
        // при закрытии всех  исполнителей перепускного пара, возвращаемся
        // на формирование задания расхода пара регулятора НАБОРА ДАВЛЕНИЯ
        // по острому пару
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(440);
        A4NAKPPREM=0; A4RPZD___S=0; A4RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  Режим "ВЫДЕРЖКА"
//  // ----------------------------------------------------------------------
    if ((A4STEPW__V==500)||(A4STEPW__V>510&&A4STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST4(500);
        // если в цикл не включен режим "ВЫДЕРЖКА"- перейти на сл режим
        if(A4PVID__YV==OFF){ Set_BV4(500); Set_ST4(600); return; }
        A4PPSTEP_V=500;
        // сообщение о начале режима
        if(A4STEPW__V==500){ Message(203+A4BNM); }
        // выдержка автоклава под давлением проводится магистральным паром
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST4(511);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(512);
        // клапан впуска пара закрыт?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A4BTM+2, A4RPHKF__R, I4KIPC___V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(169+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(513);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(514);
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A4BTM+4, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(144+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(515);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(516);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A4BTM+6, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(142+A4BNM); Bell(4,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
        Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); Clear_TO(A4BTM+6);
        A4STEPZ__V=0; A4STEPC__V=0;
        //
        Set_ST4(501);
        // установить процент начального открытия клапана впуска пара (30%)
        A4TEMP=0.3;
        A4RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A4STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST4(501);
        //-----------
        // если давление в автоклаве больше заданного-
        // перейти на  шаг закрытия клапана впуска пара
        if(AIP4P____V>=A4PPP____R){
           Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=0; 
           return;
        }
        //-----------
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // перейти на шаг закрытия задвижки и клапана впуска острого пара
        if(AIP4P____V> A4ZPAKX__R or AIP4P____V>AIP34M___V){
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=1;
           return;
        }
        //-----------
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A4STEPH__V>=A4PVIDH__R and A4STEPM__V>=A4PVIDM__R){
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2); Clear_TO(A4BTM+3); 
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(502); A4FLAG=2;
           return;
        }
        //-----------

        //-----------
        // выдержка автоклава под давлением  проводится магистральным паром
        // открыть  задвижку  магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задвижка впуска магистральн пара открыта?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPO__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(171+A4BNM); Bell(4,1); return; }
        }
        //-----------
        // снять  команду с  задвижки впуска  острого пара  и
        // выдать команду на открытие клапана впуска  пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A4BTM+3]==0) Set_IS4(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A4BTM+3]==1) Set_IS4(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ждать A4TEMP %  секунд от полного  хода клапана впуска пара
        // или пока не сработает концевик открытия клапана
        if(I4KIPO___V<1){
           switch ( Check_TO(A4BTM+2,A4RPHKF__R*A4TEMP,ZERO,'=',ON, 1)){
               case RUN: { A4STEPZ__V=A4RPHKF__R*A4TEMP; A4STEPC__V=CNTTO[A4BTM+2]; 
                           return;
                         }
           }
        }
        // снять команду с клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задержка 30 секунд
        switch ( Check_TO(A4BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A4STEPZ__V=30; A4STEPC__V=CNTTO[A4BTM+3]; return; }
        }
        if(AIP4P____V< A4PPP____R){
        // если давление в автоклаве не поднялось до заданного и клапан
        // открыт не полностью- увеличить время открытия клапана и повторить
        // текущий шаг 
        //(впринципе,так можно открывать клапан более плавно +0.3,+0.3...)
           if(A4TEMP<0.8){
              A4TEMP=0.3;
              Clear_TO(A4BTM+2); Clear_TO(A4BTM+3);
              A4STEPZ__V=0; A4STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A4STEPW__V>=502 and A4STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST4(502);
        // установить процент начального открытия клапана впуска пара (30%)
        A4TEMP=0.3;
        // если текущее давление в автоклаве меньше заданного-
        // перейти назад на  шаг открытия  задвижки и клапана впуска пара
        if(AIP4P____V<A4PPP____R-A4ZNVD___R and 
           AIP4P____V<AIP34M___V-A4ZNPM___R and A4FLAG<2){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(501); return;
        }
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // закрыть задвижку впуска острого пара
        if(AIP4P____V> A4ZPAKX__R or AIP4P____V>AIP34M___V){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); 
           A4STEPZ__V=0; A4STEPC__V=0; A4FLAG=1;
        }
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A4STEPH__V>=A4PVIDH__R and A4STEPM__V>=A4PVIDM__R){
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5); 
           A4STEPZ__V=0; A4STEPC__V=0; A4FLAG=2;
        }
        // если это контроль максимально допустимого давления или разницы или
        // выход из режима - закрыть задвижку впуска острого пара
        if(A4FLAG>0){
          // дать команду на закрытие всех исполнителей
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // задвижка впуска острого пара закрыта?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A4BTM+5, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(141+A4BNM); Bell(4,1); return; }
          }
        }
        // дать команду на закрытие клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверить  состоян клапана впуска пара       [x1.i05 (IxKIPC_) = 1]
        // клапан впуска пара закрыт?            
        switch ( Check_TO(A4BTM+4, A4RPHKF__R* SEC, I4KIPC___V,'=',ON,  1 )){
            case RUN: { A4STEPZ__V=A4RPHKF__R; A4STEPC__V=CNTTO[A4BTM+4]; return; }
            case BAD: { Clear_TO(A4BTM+4); Message(170+A4BNM); Bell(4,1); return; }
        }
        // если был установлен флаг выхода- перейти на режим "СБРОС ДАВЛЕНИЯ"
        if(A4FLAG==2){ 
           Clear_TO(A4BTM+4); Clear_TO(A4BTM+5);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_BV4(502); Set_ST4(600);
           A4PVID__YM=OFF;  A4PVID__YV=A4PVID__YM;
           // сообщение об окончании режима
           Message(204+A4BNM);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  Режим "СБРОС ДАВЛЕНИЯ"
    // ----------------------------------------------------------------------
    if ((A4STEPW__V==600)||(A4STEPW__V>610&&A4STEPW__V<620)){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "СБРОС ДАВЛЕНИЯ"- перейти на руч.режим
        if(A4SP____YV==OFF){ Set_BV4(600); Set_ST4(50); return; }
        // проверка СБРОСА ДАВЛЕНИЯ других автоклавов
        // (на СБРОСЕ ДАВЛЕНИЯ может находится ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==600||A2PPSTEP_V==600||A3PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV4(600); Set_ST4(50); Message(110+A4BNM); return; 
        }
        A4PPSTEP_V=600;
        // сообщение о начале режима
        if(A4STEPW__V==600){ Message(205+A4BNM); }
        //
        A4RPRA___M=ON;
        //-----------
        // определение первоначального процента открытия клапана сброса пара
        A4FLAG=0; A4FLGP=0; if(A4TKLO___R==0) A4TKLO___R=100;
        A4FLAG=5; A4TEMP=A41SPKK05R; 
        if(A4SPAT___R>0) A4TEMP=A41SPAK05R; if(A4TEMP==0) A4TEMP=20;
        // если определен сброс пара в атмосферу
        if(A4SPAT___R>0){ A4TEMP=A4TKLO___R*0.01*A4TEMP; }
        // если определен сброс пара в акумулятор
        else            { A4TEMP=A4TKLO___R*0.01*A4TEMP; }
        // дать команду на закрытие всех исполнителей
        if(A4SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS4( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST4(611);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A4BTM+1, A4TZOPO__R* SEC, I4ZIOPC__V,'=',ON,1)){
            case RUN: { A4STEPZ__V=A4TZOPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(141+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(613);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A4BTM+3, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+3]; return; }
            case BAD: { Clear_TO(A4BTM+3); Message(143+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(615);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A4BTM+5, A4TVZO___R* SEC, I4VZC____V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TVZO___R; A4STEPC__V=CNTTO[A4BTM+5]; return; }
            case BAD: { Clear_TO(A4BTM+5); Message(145+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(616);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A4BTM+6, A4TZPPO__R* SEC, I4ZIPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+6]; return; }
            case BAD: { Clear_TO(A4BTM+6); Message(142+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(617);
        // СБУ заблокирован?                            [x7.i08 (IxSBP1Z) = 1]
        switch ( Check_TO(A4BTM+7,5*60*SEC,I4SBP1Z__V,'=',ON, 1)){
            case RUN: { A4STEPZ__V=60*5; A4STEPC__V=CNTTO[A4BTM+7]; return; }
            case BAD: { Clear_TO(A4BTM+7); Message(148+A4BNM); Bell(4,1); return; }
        }
        Set_ST4(618);
        // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
        // атмосферу
        if(A4SPAT___R>0){
          // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
          // атмосферу
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A4BTM+8, A4TZSPA__R* SEC, I4ZOPAO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+8]; return; }
            case BAD: { Clear_TO(A4BTM+8); Message(173+A4BNM); Bell(4,1); return; }
          }
        }
        Clear_TO(A4BTM+1);  Clear_TO(A4BTM+2);  Clear_TO(A4BTM+3);  
        Clear_TO(A4BTM+4);  Clear_TO(A4BTM+5);  Clear_TO(A4BTM+6);  
        Clear_TO(A4BTM+7);  Clear_TO(A4BTM+8);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_ST4(602);
        return;
    }
//  // ----------------------
//  //  сброс пара по таблице
    if (A4STEPW__V>=602 and A4STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST4(602);
        // присвоить переменной процент(время в секундах) открытия клапана 
        // (от полного  времени хода клапана) по таблице  соответственно
        // текущего давления  в автоклаве
        // таблица просматривается от большего к меньшему (снизу вверх)
        // без возврата на предыдущий шаг

        // если текущее давление меньше-1 или текущее давление
        // меньше последнего указанного в таблице "СБРОС ДАВЛЕНИЯ"(снизу-вверх)
        // или разблокирован один из СБУ- перейти на след режим
        if(AIP4P____V<-1 or A4FLAG==1 or I4SBP1R__V>0){
           Set_ST4(605); Clear_TO(A4BTM+2); A4STEPZ__V=0; A4STEPC__V=0; A4FLGP=0;
           return;
        }
        
        // если определен сброс пара в атмосферу
        if(A4SPAT___R>0){
           Set_ST4(603);
           if(AIP4P____V<A41SPAP04R and A4FLAG>=5){
              // считается разница процента открытия клапана между
              // предыдущим и текущим шагом
              A4TEMP=A4TKLO___R*0.01*(A41SPAK04R-A41SPAK05R); A4FLAG=4;
           }
           if(AIP4P____V<A41SPAP03R and A4FLAG>=4){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK03R-A41SPAK04R); A4FLAG=3;
           }
           if(AIP4P____V<A41SPAP02R and A4FLAG>=3){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK02R-A41SPAK03R); A4FLAG=2;
           }
           if(AIP4P____V<A41SPAP01R and A4FLAG>=2){
              A4TEMP=A4TKLO___R*0.01*(A41SPAK01R-A41SPAK02R); A4FLAG=1;
           }
        } else {
           Set_ST4(604);
        // если выбран сброс пара в акумулятор
           if(AIP4P____V<A41SPKP04R and A4FLAG>=5){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK04R-A41SPKK05R); A4FLAG=4;
           }
           if(AIP4P____V<A41SPKP03R and A4FLAG>=4){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK03R-A41SPKK04R); A4FLAG=3;
           }
           if(AIP4P____V<A41SPKP02R and A4FLAG>=3){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK02R-A41SPKK03R); A4FLAG=2;
           }
           if(AIP4P____V<A41SPKP01R and A4FLAG>=2){
              A4TEMP=A4TKLO___R*0.01*(A41SPKK01R-A41SPKK02R); A4FLAG=1;
           }
        }
        // если был переход на новый шаг
        if(A4FLGP!=A4FLAG){
           // если значение A4TEMP > 0 - открываем клапан выпуска пара,
           // иначе - закрываем
           if(A4TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS4( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // обновить значения
           A4TEMP=fabs(A4TEMP);  
           A4FLGP=A4FLAG;
           // обнулить таймер и счетчики для отработки новых значений
           Clear_TO(A4BTM+1); A4STEPZ__V=0;  A4STEPC__V=0;
        }
        // считаем время воздействия сигнала на клапан
        switch ( Check_TO(A4BTM+1, A4TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=A4TEMP; A4STEPC__V=CNTTO[A4BTM+1]; return; }
        }
        // после отработки таймера- снять сигналы с исполнителей
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  повторная проверка и выход из текущего режима в режим "ОЖИДАНИЕ"
    if (A4STEPW__V>=605 and A4STEPW__V<607){
        if(!NewSEC){ return; }
        // если текущее  давление меньше или равно  нулю 
        // или  меньшему значению в таблице- увелич счетчик
        if(AIP4P____V<=0 or A4FLAG==1 or I4SBP1R__V>0){
           A4FLGP++;
        // иначе - уменьшить
        } else { 
           A4FLGP--; 
        }
        // 10 сек ожидание 
        switch ( Check_TO(A4BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A4STEPZ__V=10; A4STEPC__V=CNTTO[A4BTM+2]; return; }
        }
        // если счетчик положительный - 
        // перейти на шаг закрытия исполнителей
        if(A4FLGP>2){
           Set_ST4(607); Clear_TO(A4BTM+1);
        } else {
        // если счетчик отрицательный - вернуться на СБРОС ДАВЛЕНИЯ
           Set_ST4(603); A4FLGP=A4FLAG;
        }; Clear_TO(A4BTM+2); A4STEPZ__V =0; A4STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  закрытие исполнителей СБРОСА ДАВЛЕНИЯ и выход из режима
    if (A4STEPW__V>=607 and A4STEPW__V<609){
        if(!NewSEC){ return; }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки сброса пара в атмосферу
        switch ( Check_TO(A4BTM+1, A4TZSPA__R* SEC, I4ZOPAC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZSPA__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(144+A4BNM); Bell(4,1); return; }
        }
        // проверка закрытия клапана выпуска пара
        switch ( Check_TO(A4BTM+2, A4TKLO___R* SEC, I4KOPC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(139+A4BNM); Bell(4,1); return; }
        }
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0; A4STEPC__V=0;
        Set_BV4(602); Set_ST4(50);
        A4SP____YM=OFF; A4SP____YV=A4SP____YM;
        // сообщение об окончании режима
        Message(206+A4BNM);
        return;
    }
//  // ----------------------







    //  Режим "ПЕРЕБРОС ДАВЛЕНИЯ" АК5
    //  Если автоклав идет на переброс, оператор не ставит у него галочку
    //  "СБРОС ДАВЛЕНИЯ".  Тогда после "ВЫДЕРЖКИ" автоклав переходит в режим
    //  "ОЖИДАНИЕ". В этом режиме он может находится сколь угодно долго.
    //  В этот момент оператор может управлять автоклавом вручную или со щита.
    //  Но для работы в режиме "ПЕРЕБРОС" автоклав должен находится в режиме
    //  ПК с закрытыми задвижками и клапанами.
    //  Как только пришел  запрос на переброс с этого автоклава - автоклав
    //  переходит в режим "ПЕРЕБРОС"
//  // ----------------------------------------------------------------------
    if (A4STEPW__V>=700 and A4STEPW__V<702){
        if(!NewSEC){ return; }
        A4RPRA___M=ON;
        // открыть задвижку выпуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // проверка открытия задвижки выпуска перепускного пара
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZOPPO__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(179+A4BNM); Bell(4,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A4PPSTEP_V=700;
        // перейти на следующий шаг
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_ST4(702);
        return;
    }
//  // ----------------------
//  //  открытие клапана выпуска пара
    if (A4STEPW__V>=702 and A4STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA4(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A4IPPSTEPV>=400&&A4IPPSTEPV<500){
           // ожидать открытия задвижки на АК-при
           if(A4IPPSTEPV!=425){ return; }
        } else {
        // если АК-при перешел из режима НАБОРА ДАВЛЕНИЯ в другой режим-
        // перейти  на закрытие исполнителей (нестандартная ситуация)
           Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
           A4STEPZ__V=0; A4STEPC__V=0;
           Set_ST4(704); return;
        }
        // открыть клапан выпуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // проверка открытия клапана выпуска пара
        switch ( Check_TO(A4BTM+1, A4TKLO___R* SEC, I4KOPO___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(181+A4BNM); Bell(4,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A4PPSTEP_V=704;
        // перейти на следующий шаг
        Clear_TO(A4BTM+1);  Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_ST4(704);
        return;
    }
//  // ----------------------
//  // закрытие исполнителей выпуска перепускного пара
    if (A4STEPW__V>=704 and A4STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA4(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A4IPPSTEPV>=400&&A4IPPSTEPV<500){
           // ожидать пока АК-при не наберет нужного давления и не
           // перейдет  на шаг закрытия исполнителей
           if(A4IPPSTEPV!=480){ return; }
           // если АК-инициатор ушел из режима НАБОР ДАВЛЕНИЯ- закрываем
           // исполнители и переходим в режим  ОЖИДАНИЯ
           //(нестандартная ситуация)
        }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS4( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки выпуска перепускного пара
        switch ( Check_TO(A4BTM+1, A4TZPPO__R* SEC, I4ZOPPC__V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TZPPO__R; A4STEPC__V=CNTTO[A4BTM+1]; return; }
            case BAD: { Clear_TO(A4BTM+1); Message(143+A4BNM); Bell(4,1); return; }
        }
        // закрыть клапан выпуска пара
        switch ( Check_TO(A4BTM+2, A4TKLO___R* SEC, I4KOPC___V,'=',ON, 1 )){
            case RUN: { A4STEPZ__V=A4TKLO___R; A4STEPC__V=CNTTO[A4BTM+2]; return; }
            case BAD: { Clear_TO(A4BTM+2); Message(139+A4BNM); Bell(4,1); return; }
        }
        // после закрытия установить флаг подтверждения закрытия исполнителей
        A4PPSTEP_V=705;
        // после окончания перепуска пара автоклав переключается в режим
        // "СБРОС ДАВЛЕНИЯ"
        Clear_TO(A4BTM+1); Clear_TO(A4BTM+2);
        A4STEPZ__V=0;  A4STEPC__V=0;
        Set_BV4(704);  Set_ST4(600);
        // если АК-при не в режиме НАБОРА ДАВЛЕНИЯ (нестандартная ситуация)
        // перевести этот АК в режим ОЖИДАНИЯ
        if(A4IPPSTEPV<400||A4IPPSTEPV>500){ Set_ST4(50); }
        A4SP____YM=OFF; A4SP____YV=ON;
        // сообщение об окончании режима
        Message(207+A4BNM);
        return;
    }
//  // ----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
