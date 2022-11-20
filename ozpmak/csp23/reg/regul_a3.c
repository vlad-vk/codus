//---------------------------------------------------------------------------

#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V3GNS1BS_V = 0;           // состояние кнопки включения гидронасоса

_f  far  I3KR_TMP_V = 0;           // текущ контрол значение выбран  крышки
_f  far  I3KR1CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка1
_f  far  I3KR1OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка1

_f  far  A3TVACUM_R = 6000;        // время вакуумирования (100 минут)
_f  far  I3MAXVCN_V = 0;           // счетчик превышения макс разрежения
_f  far  O3ZOPPO__Y = 0;           // сигнал откр задв остр пара на АК передат
_f  far  I3ZOPPO__Y = 0;           //
_f  far  A3RPZD___S = 0;           // шаг задания регулятора "НАБОРА ДАВЛЕНИЯ"
_f  far  A3ISPST__C = 0;           // счетчик пароля определения шага
_f  far  A3FLAG=0;                 // дополнительные переменные
_f  far  A3FLGP=0;                 //
_f  far  A3TEMP=0;                 //
_f  far  A3PPRT=0;                 // возврат из функций определения шага пер
_f  far  A3SBPT=0;                 // счетчик разблокировки СБУ
_f  far  A3SBPC=0;                 // счетчик блокировки СБУ
_f  far  A3SBPI=0;                 // счетчик ЗАКРЫТО исполнителей для СБУ
_f  far  A3CISP=0;                 // счетчик контроля состояния исполнителей


//---------------------------------------------------------------------------
//  управление исполнителями задвижек и клапанов АК3
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS3(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  острого пара
    if (i1==  ON){ O3ZIOPO__M= ON; O3ZIOPC__M=OFF; }   //  открыть
    if (i1== OFF){ O3ZIOPO__M=OFF; O3ZIOPC__M= ON; }   //  закрыть
    if (i1==STOP){ O3ZIOPO__M=OFF; O3ZIOPC__M=OFF; }   //  остановить
    // перепускного пара входящего
    if (i2==  ON){ O3ZIPPO__M= ON; O3ZIPPC__M=OFF; }
    if (i2== OFF){ O3ZIPPO__M=OFF; O3ZIPPC__M= ON; }
    if (i2==STOP){ O3ZIPPO__M=OFF; O3ZIPPC__M=OFF; }
    // перепускного пара выходящего
    if (i3==  ON){ O3ZOPPO__M= ON; O3ZOPPC__M=OFF; }
    if (i3== OFF){ O3ZOPPO__M=OFF; O3ZOPPC__M= ON; }
    if (i3==STOP){ O3ZOPPO__M=OFF; O3ZOPPC__M=OFF; }
    // сброса в атмосферу
    if (i4==  ON){ O3ZOPAO__M= ON; O3ZOPAC__M=OFF; }
    if (i4== OFF){ O3ZOPAO__M=OFF; O3ZOPAC__M= ON; }
    if (i4==STOP){ O3ZOPAO__M=OFF; O3ZOPAC__M=OFF; }
    // вакуумная задвижка
    if (i5==  ON){ O3VZO____M= ON; O3VZC____M=OFF; }
    if (i5== OFF){ O3VZO____M=OFF; O3VZC____M= ON; }
    if (i5==STOP){ O3VZO____M=OFF; O3VZC____M=OFF; }
    // клапан впуска пара
    if (i6==  ON){ O3KIPO___M= ON; O3KIPO___V= ON; O3KIPC___M=OFF; O3KIPC___V=OFF; }
    if (i6== OFF){ O3KIPO___M=OFF; O3KIPO___V=OFF; O3KIPC___M= ON; O3KIPC___V= ON; }
    if (i6==STOP){ O3KIPO___M=OFF; O3KIPO___V=OFF; O3KIPC___M=OFF; O3KIPC___V=OFF; }
    // клапан выпуска пара
    if (i7==  ON){ O3KOPO___M= ON; O3KOPO___V= ON; O3KOPC___M=OFF; O3KOPC___V=OFF; }
    if (i7== OFF){ O3KOPO___M=OFF; O3KOPO___V=OFF; O3KOPC___M= ON; O3KOPC___V= ON; }
    if (i7==STOP){ O3KOPO___M=OFF; O3KOPO___V=OFF; O3KOPC___M=OFF; O3KOPC___V=OFF; }
    // клапан сброса конденсата
    if (i8==  ON){ O3KOCO___M= ON; O3KOCO___V= ON; O3KOCC___M=OFF; O3KOCC___V=OFF; }
    if (i8== OFF){ O3KOCO___M=OFF; O3KOCO___V=OFF; O3KOCC___M= ON; O3KOCC___V= ON; }
    if (i8==STOP){ O3KOCO___M=OFF; O3KOCO___V=OFF; O3KOCC___M=OFF; O3KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  управление исполнителями крышек АК3
//              NUM       BY        HM        KR 
vd  far Set_KR3(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // байонет
       if (b==  ON){ O3BY1O___M= ON; O3BY1C___M=OFF; }   //  открыть
       if (b== OFF){ O3BY1O___M=OFF; O3BY1C___M= ON; }   //  закрыть
       if (b==STOP){ O3BY1O___M=OFF; O3BY1C___M=OFF; }   //  остановить
       // хомут
       if (h==  ON){ O3HM1UP__M= ON; O3HM1DN__M=OFF; }
       if (h== OFF){ O3HM1UP__M=OFF; O3HM1DN__M= ON; }
       if (h==STOP){ O3HM1UP__M=OFF; O3HM1DN__M=OFF; }
       // крышка
       if (k==  ON){ O3KR1O___M= ON; O3KR1C___M=OFF; }
       if (k== OFF){ O3KR1O___M=OFF; O3KR1C___M= ON; }
       if (k==STOP){ O3KR1O___M=OFF; O3KR1C___M=OFF; }
    }
    if(n==2){
       // байонет
       if (b==  ON){ O3BY2O___M= ON; O3BY2C___M=OFF; }
       if (b== OFF){ O3BY2O___M=OFF; O3BY2C___M= ON; }
       if (b==STOP){ O3BY2O___M=OFF; O3BY2C___M=OFF; }
       // хомут
       if (h==  ON){ O3HM2UP__M= ON; O3HM2DN__M=OFF; }
       if (h== OFF){ O3HM2UP__M=OFF; O3HM2DN__M= ON; }
       if (h==STOP){ O3HM2UP__M=OFF; O3HM2DN__M=OFF; }
       // крышка
       if (k==  ON){ O3KR2O___M= ON; O3KR2C___M=OFF; }
       if (k== OFF){ O3KR2O___M=OFF; O3KR2C___M= ON; }
       if (k==STOP){ O3KR2O___M=OFF; O3KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Очистка всех таймеров и счетчика
vd  far Clear_TA3(vd){
    Clear_TO(A3BTM+ 1); Clear_TO(A3BTM+ 2); 
    Clear_TO(A3BTM+ 3); Clear_TO(A3BTM+ 4); 
    Clear_TO(A3BTM+ 5); Clear_TO(A3BTM+ 6);
    Clear_TO(A3BTM+ 7); Clear_TO(A3BTM+ 8); 
    Clear_TO(A3BTM+ 9); Clear_TO(A3BTM+10);
    Clear_TO(A3BTM+11); Clear_TO(A3BTM+12);
    Clear_TO(A3BTM+13); Clear_TO(A3BTM+14);
    Clear_TO(A3BTM+15); Clear_TO(A3BTM+16);
    Clear_TO(A3BTM+17); Clear_TO(A3BTM+18);
    Clear_TO(A3BTM+19);
    A3STEPZ__V=0; A3STEPC__V=0;
}
//---------------------------------------------------------------------------
//  установка начальных значений при смене режима работы автоклава
vd  far Set_BV3(_f far A3STEPWPRV){
    // запомнить номер предыдущего шага
    A3STEPP__V =A3STEP___V;
    A3STEPWP_V =A3STEPWPRV;
    // сбросить  флаги паролей
    A3CYCRN__V =OFF; A3CYCRN__M=OFF;
    A3CYCST__V =OFF; A3CYCST__M=OFF;
    A3ISPST__V =OFF; A3ISPST__M=OFF;
    // обнулить счетчики режимов и таймеров
    A3STEPH__V =0;   A3STEPM__V=0; A3STEPS__V=0; 
    // сбросить флаги выбора крышек для открытия и закрытия
    I3KR1OBS_V =0;
    I3KR1CBS_V =0; 
    I3KR_TMP_V=-1;
    // снять команды со всех исполнителей крышек
    Set_KR3(1,STOP,STOP,STOP);
    Set_KR3(2,STOP,STOP,STOP);
    //  обнуление значений таймеров
    Clear_TA3();
    // снять команды на хомуты
    O3HM1UP__M=OFF; O3HM1DN__M=OFF;
    O3HM2UP__M=OFF; O3HM2DN__M=OFF;
    // снять команды на байонеты
    O3BY1O___M=OFF; O3BY1C___M=OFF;
    O3BY2O___M=OFF; O3BY2C___M=OFF;
    // снять команды на крышки
    O3KR1O___M=OFF; O3KR1C___M=OFF;
    O3KR2O___M=OFF; O3KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  установка текущего шага режима работы автоклава
vd  far Set_ST3(int SS){
    A3STEPW__V=SS;
    A3STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  получение значений из переменных удаленных контроллеров
//  A3PPSTEP_V - номер шага программы текущ АК
//  A3RPPSTEPV - принимаемое с АК-пер значение,сигнализирующее о выполнении на
//               АК-пер текущего шага
_f  far Get_RV3(vd){
    // если выбран номер 0- набор пара делается с магистрали
    if(A3NAKPPREM==0){ return(0); }
    A3RPPSTEPV=0;
    if(A3NAKPPREM==1){ A3RPPSTEPV=A1PPSTEP_V; AIPRP3___V=AIP1P____V; }
    if(A3NAKPPREM==2){ A3RPPSTEPV=A2PPSTEP_V; AIPRP3___V=AIP2P____V; }
    if(A3NAKPPREM==4){ A3RPPSTEPV=A4PPSTEP_V; AIPRP3___V=AIP4P____V; }
    if(A3NAKPPREM==5){ A3RPPSTEPV=A5PPSTEP_V; AIPRP3___V=AIP5P____V; }
    if(A3NAKPPREM==6){ A3RPPSTEPV=A6PPSTEP_V; AIPRP3___V=AIP6P____V; }
    if(A3RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // если текущий АК находится в режиме НАБОРА пер.паром
    if(A3PPSTEP_V==420){
       // если АК-пер перешел в режим ПЕРЕБРОСА и открыл задвижку вып пер.пара
       if(A3RPPSTEPV==700) return(1); return(0);
    }
    // текущий АК ожидает открытия клапана вып пер.пара на АК-пер
    if(A3PPSTEP_V==425){
       if(A3RPPSTEPV==704) return(2); return(0);
    }
    // текущий АК ожидает закрытия исполнителей выпуска пара на АК-пер
    if(A3PPSTEP_V==480){
       // если на АК-пер исполнители закрылись
       if(A3RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Получение текущего шага АК-инициатора (АК-при) при отдаче пара
_f  far Get_RA3(int mode){
    // проверить что другие автоклавы не находятся в режиме переброса
    // определять по состоянию перепускных задвижек (впуск,выпуск)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A2PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // Определить номер АК, который запрашивает текущий для отдачи пара
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==3){ A3IPPNUM_V=1; return(1); }
       if(A2PPSTEP_V==420 and A2NAKPP__R==3){ A3IPPNUM_V=2; return(2); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==3){ A3IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==3){ A3IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==3){ A3IPPNUM_V=6; return(6); }
       return(0);
    }
    // Определить текущий шаг на АК-инициаторе (АК-при)
    if(mode==2){
       if(A3IPPNUM_V==1){ A3IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A3IPPNUM_V==2){ A3IPPSTEPV=A2PPSTEP_V; return(2); }
       if(A3IPPNUM_V==4){ A3IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A3IPPNUM_V==5){ A3IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A3IPPNUM_V==6){ A3IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка блокировки СБУ
int Chk_SBP3(vd){
    //-------------------------------------------
    // Если программа не на шаге работы с крышками
    if(A3STEPW__V<100||(A3STEPW__V>290&&A3STEPW__V<800)||A3STEPW__V>890){
      // Если разблокировали СБУ - выдать команду на закрытие
      // всех задвижек и перейти в режим ожидания
      if(I3SBP1R__V>0){
        // cбросить счетчик блокировки СБУ (защита от дребезга)
        A3SBPC=0;
        // Если не закрыт хоть один из проверяемых исполнителей
        if(I3ZIOPC__V!=ON|| I3ZIPPC__V!=ON||I3ZOPPC__V!=ON||I3ZOPAC__V!=ON||
           I3VZC____V!=ON||(I3KOCC___V!=ON&&(A3STEPP__V==3||A3STEP___V==3))){
////СБУ РАЗБЛОКИРОВАНО.ЧТО-ТО ОТКРЫТО.        
           // cбросить счетчик стабильного состояния ЗАКРЫТО исполнителей
           A3SBPI=0;
           //-----------
           // если програма сюда зашла с шага меньше, чем 910(другой режим)
           if(A3STEPW__V<910){
              // увеличить счетчик сработки СБУ (считаем 5сек) и выйти
              if(A3SBPT <5){ A3SBPT++; return(1); }
              // последний раз после проверки счетчика перед проверкой
              // исполнителей- обнулить счетчики и таймеры (когда прошло 5сек)
              A3STEPZ__V=0; A3STEPC__V=0; Set_BV3(A3STEPW__V);
              Message(107+A3BNM);
           }
           //-----------
           // установить режим закрытия исполнителей по разблокировке СБУ
           Set_ST3(910);
           // выдать команду на закрытие всех исполнителей
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // задвижка впуска острого пара закрыта?
           Set_ST3(911);
           switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return(1); }
             case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return(1); }
           }
           // задвижка впуска перепускного пара закрыта? 
           Set_ST3(912);
           switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return(1); }
             case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM); Bell(3,1); return(1); }
           }
           // задвижка выпуска перепускного пара закрыта?
           Set_ST3(913);
           switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return(1); }
             case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM); Bell(3,1); return(1); }
           }
           // задвижка выпуска пара в атмосферу закрыта?
           Set_ST3(914);
           switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return(1); }
             case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM); Bell(3,1); return(1); }
           }
           // задвижка вакуума закрыта?
           Set_ST3(915);
           switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return(1); }
             case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM); Bell(3,1); return(1); }
           }
           // если СБУ было разблокировано в режиме ВАКУУМИРОВАНИЯ
           if(A3STEPP__V==3){
           // клапан выпуска конденсата закрыт?
           Set_ST3(916);
           switch ( Check_TO(A3BTM+6, A3RCHKF__R* SEC, I3KOCC___V,'=',ON,  1 )){
             case RUN: { A3STEPZ__V=A3RCHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return(1); }
             case BAD: { Clear_TO(A3BTM+6); Message(146+A3BNM); Bell(3,1); return(1); }
           } }
           // если все закрыто- перейти в режим ожидания разблокировки СБУ
           Set_ST3(917); return(1);
        } else {
////СБУ РАЗБЛОКИРОВАНО.ВСЕ ЗАКРЫТО.        
           // если все проверяемые исполнители закрыты- уменьшить счетчик и
           // ждать на шаге 900, пока заблокируют СБУ
           if(A3SBPI<5){ A3SBPI++; return(1); }
           // после счетчика стабильного закрытия исполнителей-
           // сбросить счетчик ожидания  закрытия исполнителей
           A3SBPT=0;
           // если разблокировали СБУ в каком-то режиме,но все исполнители
           // закрыты- выдать сообщение с указанием режима на котором 
           // заблокировали СБУ
           if(A3STEPW__V<900){ Set_BV3(A3STEPW__V); Message(106+A3BNM); }
           // если исполнители были закрыты после разблокировки СБУ-
           // выдать сообщение о том, что исполнители закрыли
           if(A3STEPW__V>900){ Message(108+A3BNM ); }
           Set_ST3(900);
        }
      } else {
////СБУ ЗАБЛОКИРОВАНО.
        // если СБУ заблокированы и последний выполняемый шаг был закрытие
        // задвижек при разблокировке СБУ
        if(A3STEPW__V>=900){
           // ожидать 5сек стабильной блокировки СБУ
           if(A3SBPC<5){ A3SBPC++; return(1); }
           // перейти в режим ожидания
           Message(109+A3BNM); Set_BV3(910); Set_ST3(50); return(1);
        }
        // когда СБУ заблокированы- сбросить счетчики блокировки СБУ и выйти
        A3SBPT=0;
        A3SBPC=0;
        A3SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка исполнителей при работе с крышками
int Chk_IF3(int mode){
    // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
    if(I3ZIOPC__V!=ON){ Message(141+A3BNM); return(0); }
    // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
    if(I3ZIPPC__V!=ON){ Message(142+A3BNM); return(0); }
    // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
    if(I3ZOPPC__V!=ON){ Message(143+A3BNM); return(0); }
    // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
    if(I3ZOPAC__V!=ON){ Message(144+A3BNM); return(0); }
    // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
    if(I3VZC____V!=ON){ Message(145+A3BNM); return(0); }
    // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
    if(I3KOCC___V!=ON){ Message(146+A3BNM); return(0); }
    // СБУ разблокирован?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I3SBP1R__V==0){ Message(149+A3BNM); return(0); }
    }
    // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I3P1_N___V==0){ Message(156+A3BNM); return(0); }
    }
    // есть напряжение на щите управл гидронасосом? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I3VACKR__V!=ON){ Message(157+A3BNM); return(0); }
    }
    // режим управления крышками автоклава дистанц? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I3LUCDU__V!=ON){ Message(158+A3BNM); return(0); }
    }
    // режим управления автоклавом дистанция(ПК)?
    if(mode==0 or mode==1){
      if(I3DU_____V!=ON){ Message(188+A3BNM); return(0); }
    }
    // проверка работы (включенного состояния) гидронасоса 
    // ожидание включения гидронасоса               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I3GNS_1__V!=ON){ Message(160+A3BNM); return(0); }
    }
    // если нажата кнопка СТОП
    if(mode>0){
       // если ДА - переходим в режим ГИДРОНАСОС
       if(I3KR1SB__V==ON || I3GNS0B__V==ON){
          A3CISP=0; Message(168+A3BNM); Set_BV3(870); Set_ST3(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_03(vd){

    // установить флаг ввода пароля запуска цикла и перейти
    // на режим  "ВАКУУМИРОВАНИЕ"
    if (A3CYCRN__M>OFF){ A3CYCRN__V=ON; A3CYCRN__M=OFF; Set_ST3(300); }
    // установить флаг ввода пароля остановки цикла
    if (A3CYCST__M>OFF){ A3CYCST__V=ON; A3CYCST__M=OFF; Set_ST3(50);  }
    // установить флаг ввода пароля перехода на заданный шаг
    if (A3ISPST__M>OFF){ A3ISPST__V=ON; A3ISPST__M=OFF; }

    // определение номера режима из шага
    A3STEP___V=floor( A3STEPW__V*0.01);
    // проверка граничного значения введенного шага
    if (A3STEPW__M<0  or A3STEPW__M>900){ A3STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  Если был изменен шаг работы автоклава и введен пароль изменения шага
    if (A3STEPW__M!=A3STEPW__V and A3ISPST__V==ON){
        //  если выбран РУЧНОЙ РЕЖИМ управления и введен пароль
        //  запуска или останова цикла
        if((A3STEPW__M<=10)){
            A3STEPW__V =A3STEPW__M; Message(130+A3BNM);
        }
        //  если выбран режим "ОТКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=100) and (A3STEPW__M< 200) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(131+A3BNM);
        }
        //  если выбран режим "ЗАКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=200) and (A3STEPW__M< 300) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(132+A3BNM);
        }
        //  если выбран режим "ВАКУУМИРОВАНИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=300) and (A3STEPW__M< 400) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(133+A3BNM);
        }
        //  если выбран режим "НАБОР ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=400) and (A3STEPW__M< 500) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(134+A3BNM); A3NAKPPREM=A3NAKPP__R;
        }
        //  если выбран режим "ВЫДЕРЖКА" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=500) and (A3STEPW__M< 600) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(135+A3BNM);
        }
        //  если выбран режим "СБРОС ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A3STEPW__M>=600) and (A3STEPW__M< 700) and (A3STEPW__V<=10)){
            A3STEPW__V =A3STEPW__M;  Message(136+A3BNM);
        }
        //-------------------------------------------------------------------
        //  установка вновь определенного режима работы 
        if (A3STEPW__M == A3STEPW__V){ Set_BV3(0); }
        else                         { A3STEPW__M=A3STEPW__V; }
    }
//  // ----------------------------------------------------------------------







//  // ----------------------------------------------------------------------
//  // Проверки и контроль для каждой новой секунды
    if(NewSEC>0){ 
       //-------------------------------------------
       // подсчет времени работы в текущем режиме
       // считать секунды
       A3STEPS__V++;
       // считать минуты
       if(A3STEPS__V>59){ A3STEPM__V++; A3STEPS__V=0; }
       // считать часы
       if(A3STEPM__V>59){ A3STEPH__V++; A3STEPM__V=0; }
       // через 99 часов время считается сначала (4,5 суток)
       if(A3STEPH__V>99){ A3STEPH__V=0; A3STEPM__V=0; A3STEPS__V=0; }
       //-------------------------------------------
       // если был введен пароль- устанавливается флаг ввода пароля, который
       // действителен 10 секунд
       if(A3ISPST__V==ON or A3CYCST__V==ON or A3CYCRN__V==ON){ A3ISPST__C++; }
       // если прошло более 10 сек после ввода пароля- сбросить флаг ввода 
       // пароля  и счетчик секунд (пароль нужно вводить заново)
       if(A3ISPST__C >10){ 
          A3ISPST__C=0; A3ISPST__V=OFF; A3CYCST__V=OFF; A3CYCRN__V=OFF;
       }
       //-------------------------------------------
       // если был изменен режим управления работой автоклава (ЩТ/ПК)
       if(S3MDUP___V!=S3MDU____V){
          // переведено на ЩИТ - перевести программу в режим "ОЖИДАНИЕ"
          if(S3MDU____V==0){
             Message(137+A3BNM); Set_BV3(0); Set_ST3(50);
          }
          // переведено на ПК  - выдать сообщение  и в режим "ОЖИДАНИЕ"
          if(S3MDU____V==1){
             Message(138+A3BNM); Set_BV3(0); Set_ST3(50);
          }
       }; S3MDUP___V=S3MDU____V;
       //-------------------------------------------
       if(Chk_SBP3()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОЖИДАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Ожидание нажатия кнопок открытия-закрытия автоклава из режима "ОЖИДАНИЕ"
    if (A3STEPW__V<=10||A3STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // Ожидание нажатия кнопки включения гидронасоса
        // Если нажата- перейти на шаг 870
        if(V3GNS1BS_V<1){
           if(I3GNS1B__V>0){
              Message(183+A3BNM); O3GNS____M=ON; A3CISP=0;
              Set_BV3(50); V3GNS1BS_V=1; Set_ST3(870); return;
           }
        }
        // Выключение гидронасоса
        if(I3GNS0B__V>0){
           V3GNS1BS_V=0; O3GNS____M=OFF;
        }
        //-----------
        // контроль готовности автоклава перейти в режим "ПЕРЕБРОСА"
        //(давление в автоклаве д.б.  >1 и закрыты все задвижки, клапана и
        // исполнители крышек, АК на дистанции).
        if(AIP3P____V>1 and I3ZIOPC__V>0 and I3ZIPPC__V>0 and I3ZOPPC__V>0 and
           I3VZC____V>0 and I3ZOPAC__V>0 and I3KIPC___V>0 and I3KOPC___V>0 and
           I3DU_____V>0 and
           I3SBP1Z__V>0 ){
           // определить, что другие АК не находятся в режиме перепуска
           if(Get_RA3(0)>0){
              // если какой-то АК запрашивает данный для ПЕРЕПУСКА-
              // определить его номер
              if(Get_RA3(1)>0){
                 // перейти на режим ПЕРЕБРОС
                 Message(129+A3BNM); Set_BV3(0); Set_ST3(700);
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
    if (A3STEPW__V>=50 and A3STEPW__V<70){
       // если ушли с шага 232:- опустить хомут 
       if(A3STEPWP_V==232){

       }
       // снять команды со всех исполнителей
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS3(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR3(1,STOP,STOP,STOP);
       Set_KR3(2,STOP,STOP,STOP);
       // выключить гидронасос
       O3GNS____M=OFF;
       // сбросить команду включения гидронасоса
       V3GNS1BS_V=0;
       // снять галочки с выбора режимов цикла
       A3NAKPP_YM=OFF;  A3NAKPP_YV=A3NAKPP_YM;
       A3RAZVK_YM=OFF;  A3RAZVK_YV=A3RAZVK_YM;
       A3PPP___YM=OFF;  A3PPP___YV=A3PPP___YM;
       A3PVID__YM=OFF;  A3PVID__YV=A3PVID__YM;
       A3SP____YM=OFF;  A3SP____YV=A3SP____YM;
       // очистить текущие таймеры и счетчики
       Clear_TA3();
       A3PPSTEP_V=0;
       // перейти в режим ОЖИДАНИЕ
       Message(189+A3BNM); Set_BV3(50); Set_ST3(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  Включение ГИДРОНАСОСА
//  // ----------------------------------------------------------------------
    if (A3STEPW__V>=870 and A3STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST3(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        //-----------
        // если нажата кнопка выключения гидронасоса- выдать комманду на 
        // выключение гидронасоса
        if(I3GNS0B__V==ON){ 
           Message(184+A3BNM);
           // выдать команду на выключение гидронасоса
           O3GNS____M=OFF;
           // сбросить флаг состояния кнопки включения гидронасоса
           V3GNS1BS_V=0; 
        }
        // если поступила команда на выключение гидронасоса
        if(V3GNS1BS_V==0&&O3GNS____M==OFF){
           // снять команды с исполнителей механизмов крышки
           //      N BY   HM   KR
           Set_KR3(1,STOP,STOP,STOP);
           Set_KR3(2,STOP,STOP,STOP);
           // снять команды с исполнителей задвижек
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ждать выключение гидронасоса
           switch( Check_TO(A3BTM+1,60*SEC, I3GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A3BNM); Bell(3,1); break; }
              case END: { Message(185+A3BNM); break; }
           }
           // перейти в режим ожидания
           Set_BV3(870); Set_ST3(50); return;
        }
        // проверка состояния исполнителей
        if(Chk_IF3(0)==0){
           A3CISP++; 
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(50); 
           }
           return; 
        }; A3CISP=0;
        //-----------
        // выдать комманду на включение гидронасоса:
        O3GNS____M= ON;
        //-----------
        // ожидание нажатия кнопки "Открыть автоклав"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I3KR1OBS_V<1 and I3KR1CBS_V<1){
           if(I3KR1OB__V>0){
              Message(174+A3BNM); A3CISP=0;
              Set_BV3(50); I3KR1OBS_V=1; V3GNS1BS_V=1; Set_ST3(100); return;
           }
        }
        //-----------
        // ожидание нажатия кнопки "Закрыть автоклав"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I3KR1OBS_V<1 and I3KR1CBS_V<1){
           if(I3KR1CB__V>0){
              Message(176+A3BNM);  A3CISP=0;
              Set_BV3(50); I3KR1CBS_V=1; V3GNS1BS_V=1; Set_ST3(200); return;
           }
        }
        //-----------
        Clear_TA3();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОТКРЫТИЯ" АК3
//  // ----------------------
//  //  Проверка начального состояния исполнителей:
    if (A3STEPW__V>=100 and A3STEPW__V< 130){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O3GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        // сообщение о начале режима
        if(A3STEPW__V!=126){ Message(195+A3BNM); }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST3(126);
        I3KR_TMP_V=-1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(126); Set_ST3(870); return;}
        switch ( Check_TO(A3BTM+14,A3THMUP__R*SEC, I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R;A3STEPC__V =CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(151+A3BNM);
                        // если это первый шаг контроля- увеличить счетчик 
                        // контроля и дать команду на поднятие хомута
                        if(A3TEMP<1){ 
                           if(I3KR1OBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
                           A3TEMP++;
                        }
                        // если это второй шаг контроля- звонок и переход в
                        // режим ОЖИДАНИЯ
                        else        { Bell(3,1); Set_BV3(126); Set_ST3(870); }
                        return;
                      }
        }
        // очистить таймеры и счетчики
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15);
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        Clear_TO(A3BTM+18); Clear_TO(A3BTM+19);
        A3STEPZ__V=0; A3STEPC__V=0;
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        Set_ST3(130);  A3TEMP=0;
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ОТКРЫТИЕ АВТОКЛАВА":
    if (A3STEPW__V>=130 and A3STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O3GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST3(132);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3BY1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(132); Set_ST3(870); return;}
        // если байонет не открыт
        if(I3KR_TMP_V==OFF){
//         // команда на открытие байонета              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // подается импульсами: 2сек импульс, 2сек пауза
           if(A3TEMP<2){
             // импульс на открытие
             if(I3KR1OBS_V>0){ O3BY1O___M=ON; O3BY1C___M=OFF; }
             A3TEMP++;
           } else {
             // пауза
             if(A3TEMP<4){
                O3BY1O___M=OFF; O3BY1C___M=OFF;
                O3BY2O___M=OFF; O3BY2C___M=OFF;
                A3TEMP++;
             } else {
             // переход после паузы на импульс
                if(A3TEMP<7) A3TEMP=0;
             }
           }  
        }
        switch (Check_TO( A3BTM+16,A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(154+A3BNM); Bell(3,1); 
                        Set_BV3(132); Set_ST3(870);
                        return; 
                      }
        }
        // сброс флага подачи импульсного сигнала на байонет
        A3TEMP=10;
        // снять команду на открытие байонетов          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O3BY1O___M=OFF; O3BY1C___M=OFF;
        O3BY2O___M=OFF; O3BY2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A3BTM+17,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+17]; return; }
        }
//      // команда на поднятие хомута                   [x6.o01 (OxHM1UP) = 1]
        if(I3KR1OBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        Set_ST3(131);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(131); Set_ST3(870); return;}
        switch (Check_TO( A3BTM+14,A3THMUP__R*SEC,I3KR_TMP_V, '=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(151+A3BNM); Bell(3,1);
                        Set_BV3(131); Set_ST3(870);    return;
                      }
        }
        // снять команду на поднятие хомута             [x6.o01 (OxHM1UP) = 0]
        O3HM1UP__M=OFF; O3HM1DN__M=OFF;
        O3HM2UP__M=OFF; O3HM2DN__M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        //--------
//      // команда на открытие крышки                   [x6.o03 (OxKR1O_) = 1]
        if(I3KR1OBS_V>0){ O3KR1O___M=ON; O3KR1C___M=OFF; }
        // крышки открыты?                              [x7.i02 (IxKR1O_) = 1]
        Set_ST3(133);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3KR1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(133); Set_ST3(870);  return;}
        switch (Check_TO( A3BTM+18,A3TKRO___R*SEC, I3KR_TMP_V, '=',ON,1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+18); Message(152+A3BNM); Bell(3,1); 
                        Set_BV3(133); Set_ST3(870);
                        return; 
                      }
        }
        // команды с крышек снимем после опускания хомута

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO(A3BTM+19,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+19]; return; }
        }
        // очистить таймеры и счетчики
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15);
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        Clear_TO(A3BTM+18); Clear_TO(A3BTM+19);
        A3STEPZ__V=0; A3STEPC__V=0;
        //
        Set_ST3(134); A3TEMP=0; return;
    }
//  // ----------------------
//  //  Опускание хомута
    if (A3STEPW__V>=134 and A3STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O3GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
//      // команда на опускание хомутов                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I3KR1OBS_V>0){ O3HM1DN__M=ON; O3HM1UP__M=OFF; }
        // хомуты опущены?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST3(134);
        I3KR_TMP_V= -1;
        if(I3KR1OBS_V>0){ I3KR_TMP_V=I3HM1DN__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(134); Set_ST3(870);  return;}
        switch (Check_TO( A3BTM+14,A3THMUP__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(150+A3BNM); Bell(3,1); 
                        Set_BV3(134); Set_ST3(870);
                        return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        Message(191+A3BNM);
        // перевод управления автоклавом в режим "ГИДРОНАСОС"->"ОЖИДАНИЕ"|"СБУ"
        Message(197+A3BNM); Set_BV3(141); Set_ST3(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ЗАКРЫТИЯ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A3STEPW__V>=200 and A3STEPW__V< 230){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O3GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        // сообщение о начале режима
        if(A3STEPW__V==200){ Message(196+A3BNM); }
        //--------
        // хомут опущен?                                [x7.i01 (IxHM1DN) = 1]
        Set_ST3(226);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3HM1DN__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(226);  Set_ST3(870); return;}
        switch ( Check_TO (A3BTM+14, A3THMUP__R*SEC,   I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V = CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(150+A3BNM); Bell(3,1); 
                        Set_BV3(226); Set_ST3(870);   return; 
                      }
        }
        // выдать комманду на открытие байонета
        if(I3KR1CBS_V>0){ O3BY1O___M=ON; O3BY1C___M=OFF; }
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        // если байонет не открылся- выйти
        Set_ST3(228);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3BY1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(228); Set_ST3(870); return;}
        switch ( Check_TO (A3BTM+15, A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+15); Message(154+A3BNM); Bell(3,1);
                        Set_BV3(228); Set_ST3(870);   return; 
                      }
        }
        // снять команду с байонета
        O3BY1O___M=OFF; O3BY1C___M=OFF;
        O3BY2O___M=OFF; O3BY2C___M=OFF;
        //
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15); 
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(230);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": приподнять перед закрытием
    if (A3STEPW__V>=230 and A3STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O3GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // команда на приподнятие крышки                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I3KR1CBS_V>0){ O3KR1O___M=ON; O3KR1C___M=OFF; }
        // крышка поднята?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST3(231);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3KR1O___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(231); Set_ST3(870); return;}
        switch (Check_TO(A3BTM+14,A3TKRO___R*SEC, I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(152+A3BNM); Bell(3,1);
                        Set_BV3(231); Set_ST3(870);   return; 
                      }
        }
        // снять команду на поднятие крышки             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O3KR1O___M=OFF; O3KR1C___M=OFF;
        O3KR2O___M=OFF; O3KR2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        // подать команду на поднятие хомута            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I3KR1CBS_V>0){ O3HM1UP__M=ON; O3HM1DN__M=OFF; }
        Set_ST3(232);
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3HM1UP__V;   }
        if(I3KR_TMP_V<0){ Set_BV3(232); Set_ST3(870); return;}
        switch (Check_TO(A3BTM+16,A3THMUP__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3THMUP__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(151+A3BNM); Bell(3,1);
                        Set_BV3(232); Set_ST3(870);   return; 
                      }
        }
        // после поднятия хомута команда не снимается

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A3BTM+17,A3TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+17]; return; }
        }
        Clear_TO(A3BTM+14); Clear_TO(A3BTM+15); 
        Clear_TO(A3BTM+16); Clear_TO(A3BTM+17);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(235);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": закрыть крышки
    if (A3STEPW__V>=235 and A3STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O3GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF3(1)==0){
           A3CISP++;
           if(A3CISP>1){ 
              O3GNS____M=OFF; V3GNS1BS_V=0;
              Message(187+A3BNM); Set_BV3(870); Set_ST3(870); 
           }
           return;
        }; A3CISP=0;
        //--------
        // команда на закрытие крышек                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I3KR1CBS_V>0){ O3KR1C___M=ON; O3KR1O___M=OFF; }
        // крышка закрыта?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST3(236);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3KR1C___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(236); Set_ST3(870); return;}
        switch (Check_TO (A3BTM+14,A3TKRO___R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TKRO___R; A3STEPC__V=CNTTO[A3BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+14); Message(153+A3BNM); Bell(3,1);
                        Set_BV3(236); Set_ST3(870); return; 
                      }
        }
        // снять команду на закрытие крышек             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O3KR1C___M=OFF; O3KR1O___M=OFF;
        O3KR2C___M=OFF; O3KR2O___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A3BTM+15,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+15]; return; }
        }
        // команда на закрытие байонетов                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I3KR1CBS_V>0){ O3BY1C___M=ON; O3BY1O___M=OFF; }
        // байонеты закрыты?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST3(237);
        I3KR_TMP_V=-1;
        if(I3KR1CBS_V>0){ I3KR_TMP_V=I3BY1C___V;   }
        if(I3KR_TMP_V<0){ Set_BV3(237); Set_ST3(870); return;}
        switch (Check_TO (A3BTM+16,A3TBYRT__R*SEC,I3KR_TMP_V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TBYRT__R; A3STEPC__V=CNTTO[A3BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A3BTM+16); Message(155+A3BNM); Bell(3,1);
                        Set_BV3(237); Set_ST3(870);   return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR3(1,STOP,STOP,STOP);
        Set_KR3(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        Message(193+A3BNM);
        // перевод управления автоклавом в режим "ГИДРОНАСОС"
        Message(198+A3BNM); Set_BV3(235); Set_ST3(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ВАКУУМИРОВАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A3STEPW__V>=300 and A3STEPW__V<320){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "ВАКУУМИРОВАНИЕ"- перейти на сл режим
        if(A3RAZVK_YV==OFF){ Set_BV3(300); Set_ST3(400); return; }
        // проверка  вакуумирования других автоклавов
        // (на вакуумировании может находится  ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==300||A2PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV3(300); Set_ST3(50); return; 
        }
        A3PPSTEP_V=300;
        // сообщение о начале режима
        if(A3STEPW__V==300){ Message(200+A3BNM); }
        //
        Set_ST3(311);
        // перевести регулятор конденсата в Авт режим, чтобы закрылся клапан
        A3RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST3(301);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST3(302);
        switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM); Bell(3,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST3(303);
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM); Bell(3,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST3(304);
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM); Bell(3,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST3(305);
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM); Bell(3,1); return; }
        }
        // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
        Set_ST3(306);
        switch ( Check_TO(A3BTM+6, A3RCHKF__R* SEC, I3KOCC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3RCHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(146+A3BNM); Bell(3,1); return; }
        }
        // СПБ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST3(307);
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM); Bell(3,1); return; }
        }
        // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST3(308);
        switch ( Check_TO(A3BTM+8, 60*SEC,I3P1_N___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+8]; return; }
            case BAD: { Clear_TO(A3BTM+8); Message(156+A3BNM); Bell(3,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST3(309);
        switch ( Check_TO(A3BTM+9, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+9]; return; }
            case BAD: { Clear_TO(A3BTM+9); Message(147+A3BNM); Bell(3,1); return; }
        }
        // дистанционный режим работы вакуумнасоса      [x2.i08 (IxVNMD_) = 1]
        Set_ST3(310);
        switch ( Check_TO(A3BTM+10, 60*SEC, I3VNMD___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+10]; return; }
            case BAD: { Clear_TO(A3BTM+10); Message(162+A3BNM); Bell(3,1); return; }
        }
        // дистанционный режим работы задвижки          [x2.i07 (IxVZMD_) = 1]
        Set_ST3(311);
        switch ( Check_TO(A3BTM+11, 60*SEC, I3VZMD___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+11]; return; }
            case BAD: { Clear_TO(A3BTM+11); Message(182+A3BNM); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6); 
        Clear_TO(A3BTM+7); Clear_TO(A3BTM+8); Clear_TO(A3BTM+9); 
        Clear_TO(A3BTM+10);
        Clear_TO(A3BTM+11);
        A3STEPZ__V=0; A3STEPC__V=0;
        I3MAXVCN_V=0;
        Set_ST3(320);
        return;
    }
//  // ----------------------
//  //  Включение вакуумирования
    if (A3STEPW__V>=320 and A3STEPW__V<325){
        if(!NewSEC){ return; }
        // команда на открытие вакуумной задвижки       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // вакуумная задвижка открыта?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST3(321);
        switch ( Check_TO(A3BTM+1, A3TVZO___R* SEC, I3VZO____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(163+A3BNM); return; }
        }
        // снять команду на открытие вакуумной задвижки [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // закрывается клапан на вакуумном насосе       [x4.o04 (OxAZVO_) = 1]
        O3AZVO___V=ON; O3AZVO___M=OFF;
        // команда на включение вакуумного насоса       [x4.o05 (OxVN_1_) = 1]
        O3VN_1___V=ON; O3VN_1___M=OFF;
        Set_ST3(322);
        // вакуумный насос включен?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A3BTM+2, 60*SEC, I3VN_1___V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(164+A3BNM); Bell(3,1); return; }
        }
        // проверка канала максимального разрежения с   [x2.i06 (IxMAXV_) = 1]
        // эл.контактного манометра
        if(I3MAXV___V>0){ I3MAXVCN_V++; }
        else            { I3MAXVCN_V=0; }
        if(I3MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
           Set_ST3(325);
           return;
        }
        // проверка величины разрежения в автоклаве     [x0.06 (AIPxyV__) = ?]
        // (ждать зад вел или счет)
        Set_ST3(323);
        switch ( Check_TO(A3BTM+3, A3TVACUM_R* SEC, AIP34V___V,'<',A3RAZVK__R, 3)){
            case RUN: { A3STEPZ__V=A3TVACUM_R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Message(165+A3BNM); break; }
        }
        // дать комманду на закрытие вакуумной задвижки [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(325);
        return;
    }
//  // ----------------------
//  //  Выключение вакуумирования
    if (A3STEPW__V>=325 and A3STEPW__V<330){
        if(!NewSEC){ return; }
        // команда на закрытие вакуумной задвижки       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // вакуумная задвижка закрыта?                  [x2.i02 (IxVZC__) = 1]
        Set_ST3(326);
        switch ( Check_TO(A3BTM+1, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(166+A3BNM); return; }
        }
        // ждать некоторое время перед включением следующего исполнителя
        Set_ST3(327);
        switch (Check_TO (A3BTM+3,A3TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TBONIS_R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
        }
        // открыть клапан атмосферы на вакуумном насосе [x4.o04 (OxAZVO_) = 1]
        O3AZVO___V=OFF; O3AZVO___M=OFF;
        // выключить вакуумный насос                    [x4.o05 (OxVN_1_) = 0]
        O3VN_1___V=OFF; O3VN_1___M=OFF;
        Set_ST3(328);
        // вакуумный насос выключен?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A3BTM+4,  120*SEC, I3VN_1___V,'=',OFF, 1)){
            case RUN: { A3STEPZ__V=120; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(167+A3BNM); return; }
        }
        //
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); 
        Clear_TO(A3BTM+3); Clear_TO(A3BTM+4);
        A3STEPZ__V=0; A3STEPC__V=0;
        // сообщение об окончании режима
        Message(190+A3BNM); Set_ST3(330);
        return;
    }
//  // ----------------------
//  //  ВАКУУМИРОВАНИЕ ЗАКОНЧЕНО
    if (A3STEPW__V>=330 and A3STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // перевод управления автоклавом в ручной режим
        Set_BV3(330); Set_ST3(400);
        A3RAZVK_YM=OFF; A3RAZVK_YV=A3RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  Режим "НАБОР ДАВЛЕНИЯ"
//  // -----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A3STEPW__V>=400 and A3STEPW__V<420){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "НАБОР ДАВЛЕНИЯ"- перейти на сл режим
        if(A3PPP___YV==OFF){ Set_BV3 (400); Set_ST3(500); return; }
        A3PPSTEP_V=400;
        // сообщение о начале режима
        if(A3STEPW__V==400){ 
           Message(201+A3BNM); 
           A3RPRA___M=OFF; A3RPUU1__M=RMINUS; Set_ST3(401); return; 
        }
        //
        A3NAKPPREM=A3NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST3(401);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST3(402);
        switch ( Check_TO(A3BTM+2, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(142+A3BNM); Bell(3,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST3(403);
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM); Bell(3,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST3(404);
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM); Bell(3,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST3(405);
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM); Bell(3,1); return; }
        }
        // клапан впуска пара закрыт?
        Set_ST3(406);
        switch ( Check_TO(A3BTM+6, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(128+A3BNM); Bell(3,1); return; }
        }
        // СБУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST3(407);
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM); Bell(3,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST3(409);
        switch ( Check_TO(A3BTM+9, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+9]; return; }
            case BAD: { Clear_TO(A3BTM+9); Message(147+A3BNM); Bell(3,1); return; }
        }
        // режим управления автоклавом "Дистанция"?     [x1.i13 (IxDU___) = 1]
        Set_ST3(410);
        switch ( Check_TO(A3BTM+10, 60*SEC, I3VAC____V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*1; A3STEPC__V=CNTTO[A3BTM+10]; return; }
            case BAD: { Clear_TO(A3BTM+10); Message(159+A3BNM); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6); 
        Clear_TO(A3BTM+7); Clear_TO(A3BTM+8); Clear_TO(A3BTM+9); 
        Clear_TO(A3BTM+10);
        A3STEPZ__V=0; A3STEPC__V=0;
        // выбран режим набора давления магистральным паром?
        if(A3NAKPPREM==0) Set_ST3(430);
        else              Set_ST3(420);
        A3TEMP=0; A3FLAG=0; A3PPRT=0; A3RPRA___M=ON; A3RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Проверка готовности автоклава-передатчика (открытие на нем задвижки)
    if (A3STEPW__V>=420 and A3STEPW__V<422){
        if(!NewSEC){ return; }
        A3PPSTEP_V=420;
        Set_ST3(421);
        // ждать подтверждения о готовности к перепуску с автоклава
        // передатчика
        if(A3PPRT<1){
           A3PPRT=Get_RV3(); 
           return;
        }
        Set_ST3(422);
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Открытие исполнителей:
    if (A3STEPW__V>=422 and A3STEPW__V<425){
        if(!NewSEC){ return; }
        A3PPSTEP_V=422;
        // дать команду на открытие задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара открыта?   [x3.o02 (OxZIPPO) = 1]
        Set_ST3(423);
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZIPPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(161+A3BNM); Bell(3,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки пер.пара
        switch (Check_TO (A3BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // снять команду с задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        // перейти на следующий шаг
        Set_ST3(425);
        return;
    }
//  // ----------------------
//  // ожидание открытия на АК-пер клапана выпуска пара
    if (A3STEPW__V>=425 and A3STEPW__V<427){
        if(!NewSEC){ return; }
        A3PPSTEP_V=425;
        // ждать подтверждения об откр клапана выпуска пара на автоклаве
        // передатчике
        if(A3PPRT<2){
           A3PPRT=Get_RV3(); 
           return;
        }
        // перейти на управление клапаном (на регулятор)
        Set_ST3(440); A3RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  С магистрали
    if (A3STEPW__V>=430 and A3STEPW__V<435){
        if(!NewSEC){ return; }
        // дать команду на открытие задвижки магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистрального пара открыта? [x1.i00 (IxZIOPO) = 1]
        Set_ST3(431);
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(171+A3BNM); Bell(3,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки острого пара
        switch (Check_TO (A3BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // снять команду с задвижки впуска острого пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        // перейти на управление клапаном (на регулятор)
        Set_ST3(440); A3RPZD___S=0; A3RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  Формирование задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ"
    if (A3STEPW__V>=440 and A3STEPW__V<445){
        if(!NewSEC){ return; }
        // определяем задание расхода для ПИД регулятора из таблицы 
        // "НАБОР ТЕМПЕРАТУРЫ"
        Set_ST3(441);
        //-----------
        // Для набора температуры острым паром:
        if(A3NAKPPREM==0){
            // если текущая Т автоклава больше очередной заданой в таблице-
            // установить задание расхода для ПИД регулятора набора давления
            if(A3RPZD___S==0){ 
               A3RPZD___M =A31NTOF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=1;
            }
            if(AIT3P____V>=A31NTOP02R  and A3RPZD___S<=2){ 
               A3RPZD___M =A31NTOF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=2;
            }
            if(AIT3P____V>=A31NTOP03R  and A3RPZD___S<=3){ 
               A3RPZD___M =A31NTOF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=3;
            }
            if(AIT3P____V>=A31NTOP04R  and A3RPZD___S<=4){ 
               A3RPZD___M =A31NTOF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=4;
            }
            if(AIT3P____V>=A31NTOP05R  and A3RPZD___S<=5){ 
               A3RPZD___M =A31NTOF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=5;
            }
        } else {
        // Для набора температуры перепускным паром:
            if(A3RPZD___S==0){
               A3RPZD___M =A31NTPF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=1;
            }
            if(AIT3P____V>=A31NTPP02R  and A3RPZD___S<=2){
               A3RPZD___M =A31NTPF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=2;
            }
            if(AIT3P____V>=A31NTPP03R  and A3RPZD___S<=3){
               A3RPZD___M =A31NTPF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=3;
            }
            if(AIT3P____V>=A31NTPP04R  and A3RPZD___S<=4){
               A3RPZD___M =A31NTPF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=4;
            }
            if(AIT3P____V>=A31NTPP05R  and A3RPZD___S<=5){
               A3RPZD___M =A31NTPF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=5;
            }
        }
        //-----------
        // если давление в автоклаве больше того, что определено
        // в первой строке таблицы "НАБОР ДАВЛЕНИЯ" - определяем задание
        // расхода  для ПИД регулятора из таблицы "НАБОР ДАВЛЕНИЯ"
        // Для набора давления острым паром:
        if(A3NAKPPREM==0){
            if(AIP3P____V>=A31NPOP01R  and A3RPZD___S<=6){ 
               A3RPZD___M =A31NPOF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=6;
            }
            if(AIP3P____V>=A31NPOP02R  and A3RPZD___S<=7){ 
               A3RPZD___M =A31NPOF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=7;
            }
            if(AIP3P____V>=A31NPOP03R  and A3RPZD___S<=8){ 
               A3RPZD___M =A31NPOF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=8;
            }
            if(AIP3P____V>=A31NPOP04R  and A3RPZD___S<=9){ 
               A3RPZD___M =A31NPOF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=9; 
            }
            if(AIP3P____V>=A31NPOP05R  and A3RPZD___S<=10){ 
               A3RPZD___M =A31NPOF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=10;
            }
            if(AIP3P____V>=A31NPOP06R  and A3RPZD___S<=11){ 
               A3RPZD___M =A31NPOF06R; A3RPZD___V=A3RPZD___M; A3RPZD___S=11;
            }
            if(AIP3P____V>=A31NPOP07R  and A3RPZD___S<=12){ 
               A3RPZD___M =A31NPOF07R; A3RPZD___V=A3RPZD___M; A3RPZD___S=12;
            }
            if(AIP3P____V>=A31NPOP08R  and A3RPZD___S<=13){ 
               A3RPZD___M =A31NPOF08R; A3RPZD___V=A3RPZD___M; A3RPZD___S=13;
            }
            if(AIP3P____V>=A31NPOP09R  and A3RPZD___S<=14){ 
               A3RPZD___M =A31NPOF09R; A3RPZD___V=A3RPZD___M; A3RPZD___S=14;
            }
            if(AIP3P____V>=A31NPOP10R  and A3RPZD___S<=15){ 
               A3RPZD___M =A31NPOF10R; A3RPZD___V=A3RPZD___M; A3RPZD___S=15;
            }
        } else {
        // Для набора давления перепускным паром:
            if(AIP3P____V>=A31NPPP01R  and A3RPZD___S<=6){ 
               A3RPZD___M =A31NPPF01R; A3RPZD___V=A3RPZD___M; A3RPZD___S=6;
            }
            if(AIP3P____V>=A31NPPP02R  and A3RPZD___S<=7){ 
               A3RPZD___M =A31NPPF02R; A3RPZD___V=A3RPZD___M; A3RPZD___S=7;
            }
            if(AIP3P____V>=A31NPPP03R  and A3RPZD___S<=8){ 
               A3RPZD___M =A31NPPF03R; A3RPZD___V=A3RPZD___M; A3RPZD___S=8;
            }
            if(AIP3P____V>=A31NPPP04R  and A3RPZD___S<=9){ 
               A3RPZD___M =A31NPPF04R; A3RPZD___V=A3RPZD___M; A3RPZD___S=9;
            }
            if(AIP3P____V>=A31NPPP05R  and A3RPZD___S<=10){ 
               A3RPZD___M =A31NPPF05R; A3RPZD___V=A3RPZD___M; A3RPZD___S=10;
            }
            if(AIP3P____V>=A31NPPP06R  and A3RPZD___S<=11){ 
               A3RPZD___M =A31NPPF06R; A3RPZD___V=A3RPZD___M; A3RPZD___S=11;
            }
            if(AIP3P____V>=A31NPPP07R  and A3RPZD___S<=12){ 
               A3RPZD___M =A31NPPF07R; A3RPZD___V=A3RPZD___M; A3RPZD___S=12;
            }
            if(AIP3P____V>=A31NPPP08R  and A3RPZD___S<=13){ 
               A3RPZD___M =A31NPPF08R; A3RPZD___V=A3RPZD___M; A3RPZD___S=13;
            }
            if(AIP3P____V>=A31NPPP09R  and A3RPZD___S<=14){ 
               A3RPZD___M =A31NPPF09R; A3RPZD___V=A3RPZD___M; A3RPZD___S=14;
            }
            if(AIP3P____V>=A31NPPP10R  and A3RPZD___S<=15){ 
               A3RPZD___M =A31NPPF10R; A3RPZD___V=A3RPZD___M; A3RPZD___S=15;
            }
        }
        //-----------
        // если автоклав в режиме набора давления перепускным  паром и
        // если разница давлений между АК-передатчиком и АК-приемником
        // меньше заданному (AxZPPRE__R) -перейти на шаг
        // закрытия исполнителей набора перепускного пара и формирование
        // задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ" по острому пару
        A3PPSTEP_V=440; Get_RV3();
        if(A3NAKPPREM>0 and AIPRP3___V-AIP3P____V < A3ZPPRE__R){
           Set_ST3(480); A3PPRT=0; return;
        }

        //-----------
        // если давление в автоклаве больше заданного в "НАСТРОЙКАХ ЦИКЛА"-
        // перейти на шаг закрытия исполнителей магистрального пара
        if(A3NAKPPREM==0 and A3PPP____R>0 and AIP3P____V>=A3PPP____R){
           if(A3TEMP <7){ 
              A3TEMP++;     
           } else { 
              Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
              Set_ST3 (450);
           }
           return;
        } else {
           A3TEMP=0;
        }
        //-----------
        // если набор давления идет с магистрали и давление в автоклаве 
        // больше,чем давление в магистрали- закрыть задвижку впуска остр пара
        if(A3NAKPPREM==0 and AIP3P____V>=AIP34M___V){
           Set_ST3(442);
           // дать команду на закрытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // если перепад давления между АК и магистралью стабилизировался
        if(A3NAKPPREM==0 and AIP3P____V< AIP34M___V-A3ZNPM___R){
           Set_ST3(443);
           // дать команду на открытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS3(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей магистрального пара и переход на "ВЫДЕРЖКУ"
    if (A3STEPW__V>=450 and A3STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A3BTM+2, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(128+A3BNM); Bell(3,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_BV3(440); Set_ST3(500);
        A3PPP___YM=OFF;  A3PPP___YV=A3PPP___YM;  
        // сообщение об окончании режима
        Message(202+A3BNM);
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей перепускного пара на АК-пер
    if (A3STEPW__V>=480 and A3STEPW__V<482){
        if(!NewSEC){ return; }
        A3PPSTEP_V=480;
        Set_ST3(481);
        // ждать подтверждения о закрытии исполнителей выпуска пара на
        // автоклаве передатчике
        if(A3PPRT<3){
           A3PPRT=Get_RV3(); return;
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(482);
        return;
    }
//  // ----------------------
    if (A3STEPW__V>=482 and A3STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST3(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара закрыта?
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(142+A3BNM); Bell(3,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A3BTM+2, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(128+A3BNM); Bell(3,1); return; }
        }
        // при закрытии всех  исполнителей перепускного пара, возвращаемся
        // на формирование задания расхода пара регулятора НАБОРА ДАВЛЕНИЯ
        // по острому пару
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(440);
        A3NAKPPREM=0; A3RPZD___S=0; A3RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  Режим "ВЫДЕРЖКА"
//  // ----------------------------------------------------------------------
    if ((A3STEPW__V==500)||(A3STEPW__V>510&&A3STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST3(500);
        // если в цикл не включен режим "ВЫДЕРЖКА"- перейти на сл режим
        if(A3PVID__YV==OFF){ Set_BV3(500); Set_ST3(600); return; }
        A3PPSTEP_V=500;
        // сообщение о начале режима
        if(A3STEPW__V==500){ Message(203+A3BNM); }
        // выдержка автоклава под давлением проводится магистральным паром
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST3(511);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(512);
        // клапан впуска пара закрыт?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A3BTM+2, A3RPHKF__R, I3KIPC___V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(169+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(513);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(514);
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A3BTM+4, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(144+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(515);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(516);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A3BTM+6, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(142+A3BNM); Bell(3,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
        Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); Clear_TO(A3BTM+6);
        A3STEPZ__V=0; A3STEPC__V=0;
        //
        Set_ST3(501);
        // установить процент начального открытия клапана впуска пара (30%)
        A3TEMP=0.3;
        A3RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A3STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST3(501);
        //-----------
        // если давление в автоклаве больше заданного-
        // перейти на  шаг закрытия клапана впуска пара
        if(AIP3P____V>=A3PPP____R){
           Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=0; 
           return;
        }
        //-----------
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // перейти на шаг закрытия задвижки и клапана впуска острого пара
        if(AIP3P____V> A3ZPAKX__R or AIP3P____V>AIP34M___V){
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=1;
           return;
        }
        //-----------
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A3STEPH__V>=A3PVIDH__R and A3STEPM__V>=A3PVIDM__R){
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2); Clear_TO(A3BTM+3); 
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(502); A3FLAG=2;
           return;
        }
        //-----------

        //-----------
        // выдержка автоклава под давлением  проводится магистральным паром
        // открыть  задвижку  магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задвижка впуска магистральн пара открыта?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPO__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(171+A3BNM); Bell(3,1); return; }
        }
        //-----------
        // снять  команду с  задвижки впуска  острого пара  и
        // выдать команду на открытие клапана впуска  пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A3BTM+3]==0) Set_IS3(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A3BTM+3]==1) Set_IS3(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ждать A3TEMP %  секунд от полного  хода клапана впуска пара
        // или пока не сработает концевик открытия клапана
        if(I3KIPO___V<1){
           switch ( Check_TO(A3BTM+2,A3RPHKF__R*A3TEMP,ZERO,'=',ON, 1)){
               case RUN: { A3STEPZ__V=A3RPHKF__R*A3TEMP; A3STEPC__V=CNTTO[A3BTM+2]; 
                           return; 
                         }
           }
        }
        // снять команду с клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задержка 30 секунд
        switch ( Check_TO(A3BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A3STEPZ__V=30; A3STEPC__V=CNTTO[A3BTM+3]; return; }
        }
        if(AIP3P____V< A3PPP____R){
        // если давление в автоклаве не поднялось до заданного и клапан
        // открыт не полностью- увеличить время открытия клапана и повторить
        // текущий шаг 
        //(впринципе,так можно открывать клапан более плавно +0.3,+0.3...)
           if(A3TEMP<0.8){
              A3TEMP=0.3;
              Clear_TO(A3BTM+2); Clear_TO(A3BTM+3);
              A3STEPZ__V=0; A3STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A3STEPW__V>=502 and A3STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST3(502);
        // установить процент начального открытия клапана впуска пара (30%)
        A3TEMP=0.3;
        // если текущее давление в автоклаве меньше заданного-
        // перейти назад на  шаг открытия  задвижки и клапана впуска пара
        if(AIP3P____V<A3PPP____R-A3ZNVD___R and 
           AIP3P____V<AIP34M___V-A3ZNPM___R and A3FLAG<2){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(501); return;
        }
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // закрыть задвижку впуска острого пара
        if(AIP3P____V> A3ZPAKX__R or AIP3P____V>AIP34M___V){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); 
           A3STEPZ__V=0; A3STEPC__V=0; A3FLAG=1;
        }
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A3STEPH__V>=A3PVIDH__R and A3STEPM__V>=A3PVIDM__R){
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5); 
           A3STEPZ__V=0; A3STEPC__V=0; A3FLAG=2;
        }
        // если это контроль максимально допустимого давления или разницы или
        // выход из режима - закрыть задвижку впуска острого пара
        if(A3FLAG>0){
          // дать команду на закрытие всех исполнителей
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // задвижка впуска острого пара закрыта?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A3BTM+5, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(141+A3BNM); Bell(3,1); return; }
          }
        }
        // дать команду на закрытие клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверить  состоян клапана впуска пара       [x1.i05 (IxKIPC_) = 1]
        // клапан впуска пара закрыт?            
        switch ( Check_TO(A3BTM+4, A3RPHKF__R* SEC, I3KIPC___V,'=',ON,  1 )){
            case RUN: { A3STEPZ__V=A3RPHKF__R; A3STEPC__V=CNTTO[A3BTM+4]; return; }
            case BAD: { Clear_TO(A3BTM+4); Message(170+A3BNM); Bell(3,1); return; }
        }
        // если был установлен флаг выхода- перейти на режим "СБРОС ДАВЛЕНИЯ"
        if(A3FLAG==2){ 
           Clear_TO(A3BTM+4); Clear_TO(A3BTM+5);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_BV3(502); Set_ST3(600);
           A3PVID__YM=OFF;  A3PVID__YV=A3PVID__YM;
           // сообщение об окончании режима
           Message(204+A3BNM);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  Режим "СБРОС ДАВЛЕНИЯ"
    // ----------------------------------------------------------------------
    if ((A3STEPW__V==600)||(A3STEPW__V>610&&A3STEPW__V<620)){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "СБРОС ДАВЛЕНИЯ"- перейти на руч.режим
        if(A3SP____YV==OFF){ Set_BV3(600); Set_ST3(50); return; }
        // проверка СБРОСА ДАВЛЕНИЯ других автоклавов
        // (на СБРОСЕ ДАВЛЕНИЯ может находится ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==600||A2PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV3(600); Set_ST3(50); Message(110+A3BNM); return; 
        }
        A3PPSTEP_V=600;
        // сообщение о начале режима
        if(A3STEPW__V==600){ Message(205+A3BNM); }
        //
        A3RPRA___M=ON;
        //-----------
        // определение первоначального процента открытия клапана сброса пара
        A3FLAG=0; A3FLGP=0; if(A3TKLO___R==0) A3TKLO___R=100;
        A3FLAG=5; A3TEMP=A31SPKK05R; 
        if(A3SPAT___R>0) A3TEMP=A31SPAK05R; if(A3TEMP==0) A3TEMP=20;
        // если определен сброс пара в атмосферу
        if(A3SPAT___R>0){ A3TEMP=A3TKLO___R*0.01*A3TEMP; }
        // если определен сброс пара в акумулятор
        else            { A3TEMP=A3TKLO___R*0.01*A3TEMP; }
        // дать команду на закрытие всех исполнителей
        if(A3SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS3( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST3(611);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A3BTM+1, A3TZOPO__R* SEC, I3ZIOPC__V,'=',ON,1)){
            case RUN: { A3STEPZ__V=A3TZOPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(141+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(613);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A3BTM+3, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+3]; return; }
            case BAD: { Clear_TO(A3BTM+3); Message(143+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(615);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A3BTM+5, A3TVZO___R* SEC, I3VZC____V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TVZO___R; A3STEPC__V=CNTTO[A3BTM+5]; return; }
            case BAD: { Clear_TO(A3BTM+5); Message(145+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(616);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A3BTM+6, A3TZPPO__R* SEC, I3ZIPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+6]; return; }
            case BAD: { Clear_TO(A3BTM+6); Message(142+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(617);
        // СБУ заблокирован?                            [x7.i08 (IxSBP1Z) = 1]
        switch ( Check_TO(A3BTM+7,5*60*SEC,I3SBP1Z__V,'=',ON, 1)){
            case RUN: { A3STEPZ__V=60*5; A3STEPC__V=CNTTO[A3BTM+7]; return; }
            case BAD: { Clear_TO(A3BTM+7); Message(148+A3BNM); Bell(3,1); return; }
        }
        Set_ST3(618);
        // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
        // атмосферу
        if(A3SPAT___R>0){
          // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
          // атмосферу
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A3BTM+8, A3TZSPA__R* SEC, I3ZOPAO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+8]; return; }
            case BAD: { Clear_TO(A3BTM+8); Message(173+A3BNM); Bell(3,1); return; }
          }
        }
        Clear_TO(A3BTM+1);  Clear_TO(A3BTM+2);  Clear_TO(A3BTM+3);  
        Clear_TO(A3BTM+4);  Clear_TO(A3BTM+5);  Clear_TO(A3BTM+6);  
        Clear_TO(A3BTM+7);  Clear_TO(A3BTM+8);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_ST3(602);
        return;
    }
//  // ----------------------
//  //  сброс пара по таблице
    if (A3STEPW__V>=602 and A3STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST3(602);
        // присвоить переменной процент(время в секундах) открытия клапана 
        // (от полного  времени хода клапана) по таблице  соответственно
        // текущего давления  в автоклаве
        // таблица просматривается от большего к меньшему (снизу вверх)
        // без возврата на предыдущий шаг

        // если текущее давление меньше-1 или текущее давление
        // меньше последнего указанного в таблице "СБРОС ДАВЛЕНИЯ"(снизу-вверх)
        // или разблокирован один из СБУ- перейти на след режим
        if(AIP3P____V<-1 or A3FLAG==1 or I3SBP1R__V>0){
           Set_ST3(605); Clear_TO(A3BTM+2); A3STEPZ__V=0; A3STEPC__V=0; A3FLGP=0;
           return;
        }
        
        // если определен сброс пара в атмосферу
        if(A3SPAT___R>0){
           Set_ST3(603);
           if(AIP3P____V<A31SPAP04R and A3FLAG>=5){
              // считается разница процента открытия клапана между 
              // предыдущим и текущим шагом
              A3TEMP=A3TKLO___R*0.01*(A31SPAK04R-A31SPAK05R); A3FLAG=4;
           }
           if(AIP3P____V<A31SPAP03R and A3FLAG>=4){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK03R-A31SPAK04R); A3FLAG=3;
           }
           if(AIP3P____V<A31SPAP02R and A3FLAG>=3){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK02R-A31SPAK03R); A3FLAG=2;
           }
           if(AIP3P____V<A31SPAP01R and A3FLAG>=2){
              A3TEMP=A3TKLO___R*0.01*(A31SPAK01R-A31SPAK02R); A3FLAG=1;
           }
        } else {
           Set_ST3(604);
        // если выбран сброс пара в акумулятор
           if(AIP3P____V<A31SPKP04R and A3FLAG>=5){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK04R-A31SPKK05R); A3FLAG=4;
           }
           if(AIP3P____V<A31SPKP03R and A3FLAG>=4){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK03R-A31SPKK04R); A3FLAG=3;
           }
           if(AIP3P____V<A31SPKP02R and A3FLAG>=3){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK02R-A31SPKK03R); A3FLAG=2;
           }
           if(AIP3P____V<A31SPKP01R and A3FLAG>=2){
              A3TEMP=A3TKLO___R*0.01*(A31SPKK01R-A31SPKK02R); A3FLAG=1;
           }
        }
        // если был переход на новый шаг
        if(A3FLGP!=A3FLAG){
           // если значение A3TEMP > 0 - открываем клапан выпуска пара,
           // иначе - закрываем
           if(A3TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS3( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // обновить значения
           A3TEMP=fabs(A3TEMP);  
           A3FLGP=A3FLAG;
           // обнулить таймер и счетчики для отработки новых значений
           Clear_TO(A3BTM+1); A3STEPZ__V=0;  A3STEPC__V=0;
        }
        // считаем время воздействия сигнала на клапан
        switch ( Check_TO(A3BTM+1, A3TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=A3TEMP; A3STEPC__V=CNTTO[A3BTM+1]; return; }
        }
        // после отработки таймера- снять сигналы с исполнителей
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  повторная проверка и выход из текущего режима в режим "ОЖИДАНИЕ"
    if (A3STEPW__V>=605 and A3STEPW__V<607){
        if(!NewSEC){ return; }
        // если текущее  давление меньше или равно  нулю 
        // или  меньшему значению в таблице- увелич счетчик
        if(AIP3P____V<=0 or A3FLAG==1 or I3SBP1R__V>0){
           A3FLGP++; 
        // иначе - уменьшить
        } else { 
           A3FLGP--; 
        }
        // 10 сек ожидание 
        switch ( Check_TO(A3BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A3STEPZ__V=10; A3STEPC__V=CNTTO[A3BTM+2]; return; }
        }
        // если счетчик положительный - 
        // перейти на шаг закрытия исполнителей
        if(A3FLGP>2){
           Set_ST3(607); Clear_TO(A3BTM+1);
        } else {
        // если счетчик отрицательный - вернуться на СБРОС ДАВЛЕНИЯ
           Set_ST3(603); A3FLGP=A3FLAG;
        }; Clear_TO(A3BTM+2); A3STEPZ__V =0; A3STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  закрытие исполнителей СБРОСА ДАВЛЕНИЯ и выход из режима
    if (A3STEPW__V>=607 and A3STEPW__V<609){
        if(!NewSEC){ return; }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки сброса пара в атмосферу
        switch ( Check_TO(A3BTM+1, A3TZSPA__R* SEC, I3ZOPAC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZSPA__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(144+A3BNM); Bell(3,1); return; }
        }
        // проверка закрытия клапана выпуска пара
        switch ( Check_TO(A3BTM+2, A3TKLO___R* SEC, I3KOPC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(139+A3BNM); Bell(3,1); return; }
        }
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0; A3STEPC__V=0;
        Set_BV3(602); Set_ST3(50);
        A3SP____YM=OFF; A3SP____YV=A3SP____YM;
        // сообщение об окончании режима
        Message(206+A3BNM);
        return;
    }
//  // ----------------------







    //  Режим "ПЕРЕБРОС ДАВЛЕНИЯ" АК3
    //  Если автоклав идет на переброс, оператор не ставит у него галочку
    //  "СБРОС ДАВЛЕНИЯ".  Тогда после "ВЫДЕРЖКИ" автоклав переходит в режим
    //  "ОЖИДАНИЕ". В этом режиме он может находится сколь угодно долго.
    //  В этот момент оператор может управлять автоклавом вручную или со щита.
    //  Но для работы в режиме "ПЕРЕБРОС" автоклав должен находится в режиме
    //  ПК с закрытыми задвижками и клапанами.
    //  Как только пришел  запрос на переброс с этого автоклава - автоклав
    //  переходит в режим "ПЕРЕБРОС"
//  // ----------------------------------------------------------------------
    if (A3STEPW__V>=700 and A3STEPW__V<702){
        if(!NewSEC){ return; }
        A3RPRA___M=ON;
        // открыть задвижку выпуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // проверка открытия задвижки выпуска перепускного пара
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZOPPO__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(179+A3BNM); Bell(3,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A3PPSTEP_V=700;
        // перейти на следующий шаг
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_ST3(702);
        return;
    }
//  // ----------------------
//  //  открытие клапана выпуска пара
    if (A3STEPW__V>=702 and A3STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA3(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A3IPPSTEPV>=400&&A3IPPSTEPV<500){
           // ожидать открытия задвижки на АК-при
           if(A3IPPSTEPV!=425){ return; }
        } else {
        // если АК-при перешел из режима НАБОРА ДАВЛЕНИЯ в другой режим-
        // перейти  на закрытие исполнителей (нестандартная ситуация)
           Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
           A3STEPZ__V=0; A3STEPC__V=0;
           Set_ST3(704); return;
        }
        // открыть клапан выпуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // проверка открытия клапана выпуска пара
        switch ( Check_TO(A3BTM+1, A3TKLO___R* SEC, I3KOPO___V,'=',ON, 2 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(181+A3BNM); Bell(3,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A3PPSTEP_V=704;
        // перейти на следующий шаг
        Clear_TO(A3BTM+1);  Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_ST3(704);
        return;
    }
//  // ----------------------
//  // закрытие исполнителей выпуска перепускного пара
    if (A3STEPW__V>=704 and A3STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA3(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A3IPPSTEPV>=400&&A3IPPSTEPV<500){
           // ожидать пока АК-при не наберет нужного давления и не
           // перейдет  на шаг закрытия исполнителей
           if(A3IPPSTEPV!=480){ return; }
           // если АК-инициатор ушел из режима НАБОР ДАВЛЕНИЯ- закрываем
           // исполнители и переходим в режим  ОЖИДАНИЯ
           //(нестандартная ситуация)
        }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS3( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки выпуска перепускного пара
        switch ( Check_TO(A3BTM+1, A3TZPPO__R* SEC, I3ZOPPC__V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TZPPO__R; A3STEPC__V=CNTTO[A3BTM+1]; return; }
            case BAD: { Clear_TO(A3BTM+1); Message(143+A3BNM); Bell(3,1); return; }
        }
        // закрыть клапан выпуска пара
        switch ( Check_TO(A3BTM+2, A3TKLO___R* SEC, I3KOPC___V,'=',ON, 1 )){
            case RUN: { A3STEPZ__V=A3TKLO___R; A3STEPC__V=CNTTO[A3BTM+2]; return; }
            case BAD: { Clear_TO(A3BTM+2); Message(139+A3BNM); Bell(3,1); return; }
        }
        // после закрытия установить флаг подтверждения закрытия исполнителей
        A3PPSTEP_V=705;
        // после окончания перепуска пара автоклав переключается в режим
        // "СБРОС ДАВЛЕНИЯ"
        Clear_TO(A3BTM+1); Clear_TO(A3BTM+2);
        A3STEPZ__V=0;  A3STEPC__V=0;
        Set_BV3(704);  Set_ST3(600);
        // если АК-при не в режиме НАБОРА ДАВЛЕНИЯ (нестандартная ситуация)
        // перевести этот АК в режим ОЖИДАНИЯ
        if(A3IPPSTEPV<400||A3IPPSTEPV>500){ Set_ST3(50); }
        A3SP____YM=OFF; A3SP____YV=ON;
        // сообщение об окончании режима
        Message(207+A3BNM);
        return;
    }
//  // ----------------------------------------------------------------------

    return;
}
//---------------------------------------------------------------------------
