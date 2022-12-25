//---------------------------------------------------------------------------

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "regul_e.h"

_f  far  V2GNS1BS_V = 0;           // состояние кнопки включения гидронасоса

_f  far  I2KR_TMP_V = 0;           // текущ контрол значение выбран  крышки
_f  far  I2KR1CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка1
_f  far  I2KR2CBS_V = 0;           // сост кнопки "Закрыть автоклав" крышка2
_f  far  I2KR1OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка1
_f  far  I2KR2OBS_V = 0;           // сост кнопки "Открыть автоклав" крышка2

_f  far  A2TVACUM_R = 6000;        // время вакуумирования (100 минут)
_f  far  I2MAXVCN_V = 0;           // счетчик превышения макс разрежения
_f  far  O2ZOPPO__Y = 0;           // сигнал откр задв остр пара на АК передат
_f  far  I2ZOPPO__Y = 0;           //
_f  far  A2RPZD___S = 0;           // шаг задания регулятора "НАБОРА ДАВЛЕНИЯ"
_f  far  A2ISPST__C = 0;           // счетчик пароля определения шага
_f  far  A2FLAG=0;                 // дополнительные переменные
_f  far  A2FLGP=0;                 //
_f  far  A2TEMP=0;                 //
_f  far  A2PPRT=0;                 // возврат из функций определения шага пер
_f  far  A2SBPT=0;                 // счетчик разблокировки СБУ
_f  far  A2SBPC=0;                 // счетчик блокировки СБУ
_f  far  A2SBPI=0;                 // счетчик ЗАКРЫТО исполнителей для СБУ
_f  far  A2CISP=0;                 // счетчик контроля состояния исполнителей


//---------------------------------------------------------------------------
//  управление исполнителями задвижек и клапанов АК4
//              ZIOP       ZIPP       ZOPP       ZOPA       VZ
vd  far Set_IS2(_f far i1, _f far i2, _f far i3, _f far i4, _f far i5, 
//              KIP        KOP        KOC
                _f far i6, _f far i7, _f far i8){
    //  острого пара
    if (i1==  ON){ O2ZIOPO__M= ON; O2ZIOPC__M=OFF; }   //  открыть
    if (i1== OFF){ O2ZIOPO__M=OFF; O2ZIOPC__M= ON; }   //  закрыть
    if (i1==STOP){ O2ZIOPO__M=OFF; O2ZIOPC__M=OFF; }   //  остановить
    // перепускного пара входящего
    if (i2==  ON){ O2ZIPPO__M= ON; O2ZIPPC__M=OFF; }
    if (i2== OFF){ O2ZIPPO__M=OFF; O2ZIPPC__M= ON; }
    if (i2==STOP){ O2ZIPPO__M=OFF; O2ZIPPC__M=OFF; }
    // перепускного пара выходящего
    if (i3==  ON){ O2ZOPPO__M= ON; O2ZOPPC__M=OFF; }
    if (i3== OFF){ O2ZOPPO__M=OFF; O2ZOPPC__M= ON; }
    if (i3==STOP){ O2ZOPPO__M=OFF; O2ZOPPC__M=OFF; }
    // сброса в атмосферу
    if (i4==  ON){ O2ZOPAO__M= ON; O2ZOPAC__M=OFF; }
    if (i4== OFF){ O2ZOPAO__M=OFF; O2ZOPAC__M= ON; }
    if (i4==STOP){ O2ZOPAO__M=OFF; O2ZOPAC__M=OFF; }
    // вакуумная задвижка
    if (i5==  ON){ O2VZO____M= ON; O2VZC____M=OFF; }
    if (i5== OFF){ O2VZO____M=OFF; O2VZC____M= ON; }
    if (i5==STOP){ O2VZO____M=OFF; O2VZC____M=OFF; }
    // клапан впуска пара
    if (i6==  ON){ O2KIPO___M= ON; O2KIPO___V= ON; O2KIPC___M=OFF; O2KIPC___V=OFF; }
    if (i6== OFF){ O2KIPO___M=OFF; O2KIPO___V=OFF; O2KIPC___M= ON; O2KIPC___V= ON; }
    if (i6==STOP){ O2KIPO___M=OFF; O2KIPO___V=OFF; O2KIPC___M=OFF; O2KIPC___V=OFF; }
    // клапан выпуска пара
    if (i7==  ON){ O2KOPO___M= ON; O2KOPO___V= ON; O2KOPC___M=OFF; O2KOPC___V=OFF; }
    if (i7== OFF){ O2KOPO___M=OFF; O2KOPO___V=OFF; O2KOPC___M= ON; O2KOPC___V= ON; }
    if (i7==STOP){ O2KOPO___M=OFF; O2KOPO___V=OFF; O2KOPC___M=OFF; O2KOPC___V=OFF; }
    // клапан сброса конденсата
    if (i8==  ON){ O2KOCO___M= ON; O2KOCO___V= ON; O2KOCC___M=OFF; O2KOCC___V=OFF; }
    if (i8== OFF){ O2KOCO___M=OFF; O2KOCO___V=OFF; O2KOCC___M= ON; O2KOCC___V= ON; }
    if (i8==STOP){ O2KOCO___M=OFF; O2KOCO___V=OFF; O2KOCC___M=OFF; O2KOCC___V=OFF; }
    return;
}
//---------------------------------------------------------------------------
//  управление исполнителями крышек АК5
//              NUM       BY        HM        KR 
vd  far Set_KR2(_f far n, _f far b, _f far h, _f far k){
    if(n==1){
       // байонет
       if (b==  ON){ O2BY1O___M= ON; O2BY1C___M=OFF; }   //  открыть
       if (b== OFF){ O2BY1O___M=OFF; O2BY1C___M= ON; }   //  закрыть
       if (b==STOP){ O2BY1O___M=OFF; O2BY1C___M=OFF; }   //  остановить
       // хомут
       if (h==  ON){ O2HM1UP__M= ON; O2HM1DN__M=OFF; }
       if (h== OFF){ O2HM1UP__M=OFF; O2HM1DN__M= ON; }
       if (h==STOP){ O2HM1UP__M=OFF; O2HM1DN__M=OFF; }
       // крышка
       if (k==  ON){ O2KR1O___M= ON; O2KR1C___M=OFF; }
       if (k== OFF){ O2KR1O___M=OFF; O2KR1C___M= ON; }
       if (k==STOP){ O2KR1O___M=OFF; O2KR1C___M=OFF; }
    }
    if(n==2){
       // байонет
       if (b==  ON){ O2BY2O___M= ON; O2BY2C___M=OFF; }
       if (b== OFF){ O2BY2O___M=OFF; O2BY2C___M= ON; }
       if (b==STOP){ O2BY2O___M=OFF; O2BY2C___M=OFF; }
       // хомут
       if (h==  ON){ O2HM2UP__M= ON; O2HM2DN__M=OFF; }
       if (h== OFF){ O2HM2UP__M=OFF; O2HM2DN__M= ON; }
       if (h==STOP){ O2HM2UP__M=OFF; O2HM2DN__M=OFF; }
       // крышка
       if (k==  ON){ O2KR2O___M= ON; O2KR2C___M=OFF; }
       if (k== OFF){ O2KR2O___M=OFF; O2KR2C___M= ON; }
       if (k==STOP){ O2KR2O___M=OFF; O2KR2C___M=OFF; }
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Очистка всех таймеров и счетчика
vd  far Clear_TA2(vd){
    Clear_TO(A2BTM+ 1); Clear_TO(A2BTM+ 2); 
    Clear_TO(A2BTM+ 3); Clear_TO(A2BTM+ 4); 
    Clear_TO(A2BTM+ 5); Clear_TO(A2BTM+ 6);
    Clear_TO(A2BTM+ 7); Clear_TO(A2BTM+ 8); 
    Clear_TO(A2BTM+ 9); Clear_TO(A2BTM+10);
    Clear_TO(A2BTM+11); Clear_TO(A2BTM+12);
    Clear_TO(A2BTM+13); Clear_TO(A2BTM+14);
    Clear_TO(A2BTM+15); Clear_TO(A2BTM+16);
    Clear_TO(A2BTM+17); Clear_TO(A2BTM+18);
    Clear_TO(A2BTM+19);
    A2STEPZ__V=0; A2STEPC__V=0;
}
//---------------------------------------------------------------------------
//  установка начальных значений при смене режима работы автоклава
vd  far Set_BV2(_f far A2STEPWPRV){
    // запомнить номер предыдущего шага
    A2STEPP__V =A2STEP___V;
    A2STEPWP_V =A2STEPWPRV;
    // сбросить  флаги паролей
    A2CYCRN__V =OFF; A2CYCRN__M=OFF;
    A2CYCST__V =OFF; A2CYCST__M=OFF;
    A2ISPST__V =OFF; A2ISPST__M=OFF;
    // обнулить счетчики режимов и таймеров
    A2STEPH__V =0;   A2STEPM__V=0; A2STEPS__V=0; 
    // сбросить флаги выбора крышек для открытия и закрытия
    I2KR1OBS_V =0;   I2KR2OBS_V =0;
    I2KR1CBS_V =0;   I2KR2CBS_V =0;
    I2KR_TMP_V=-1;
    // снять команды со всех исполнителей крышек
    Set_KR2(1,STOP,STOP,STOP);
    Set_KR2(2,STOP,STOP,STOP);
    //  обнуление значений таймеров
    Clear_TA2();
    // снять команды на хомуты
    O2HM1UP__M=OFF; O2HM1DN__M=OFF;
    O2HM2UP__M=OFF; O2HM2DN__M=OFF;
    // снять команды на байонеты
    O2BY1O___M=OFF; O2BY1C___M=OFF;
    O2BY2O___M=OFF; O2BY2C___M=OFF;
    // снять команды на крышки
    O2KR1O___M=OFF; O2KR1C___M=OFF;
    O2KR2O___M=OFF; O2KR2C___M=OFF;
}
//---------------------------------------------------------------------------
//  установка текущего шага режима работы автоклава
vd  far Set_ST2(int SS){
    A2STEPW__V=SS;
    A2STEPW__M=SS;
    return;
}
//---------------------------------------------------------------------------
//  получение значений из переменных удаленных контроллеров
//  A2PPSTEP_V - номер шага программы текущ АК
//  A2RPPSTEPV - принимаемое с АК-пер значение,сигнализирующее о выполнении на
//               АК-пер текущего шага
_f  far Get_RV2(vd){
    // если выбран номер 0- набор пара делается с магистрали
    if(A2NAKPPREM==0){ return(0); }
    A2RPPSTEPV=0;
    if(A2NAKPPREM==1){ A2RPPSTEPV=A1PPSTEP_V; AIPRP2___V=AIP1P____V; }
    if(A2NAKPPREM==3){ A2RPPSTEPV=A3PPSTEP_V; AIPRP2___V=AIP3P____V; }
    if(A2NAKPPREM==4){ A2RPPSTEPV=A4PPSTEP_V; AIPRP2___V=AIP4P____V; }
    if(A2NAKPPREM==5){ A2RPPSTEPV=A5PPSTEP_V; AIPRP2___V=AIP5P____V; }
    if(A2NAKPPREM==6){ A2RPPSTEPV=A6PPSTEP_V; AIPRP2___V=AIP6P____V; }
    if(A2RPPSTEPV==0){ return(0); }
    //-----------------------------------------------------------------------
    // если текущий АК находится в режиме НАБОРА пер.паром
    if(A2PPSTEP_V==420){
       // если АК-пер перешел в режим ПЕРЕБРОСА и открыл задвижку вып пер.пара
       if(A2RPPSTEPV==700) return(1); return(0);
    }
    // текущий АК ожидает открытия клапана вып пер.пара на АК-пер
    if(A2PPSTEP_V==425){
       if(A2RPPSTEPV==704) return(2); return(0);
    }
    // текущий АК ожидает закрытия исполнителей выпуска пара на АК-пер
    if(A2PPSTEP_V==480){
       // если на АК-пер исполнители закрылись
       if(A2RPPSTEPV==705) return(3); return(0);
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Получение текущего шага АК-инициатора (АК-при) при отдаче пара
_f  far Get_RA2(int mode){
    // проверить что другие автоклавы не находятся в режиме переброса
    // определять по состоянию перепускных задвижек (впуск,выпуск)
    if(mode==0){
       if(A1PPSTEP_V>=700 or A3PPSTEP_V>=700 or 
          A4PPSTEP_V>=700 or A5PPSTEP_V>=700 or A6PPSTEP_V>=700)  
       return(0);
       return(1);
    }
    // Определить номер АК, который запрашивает текущий для отдачи пара
    if(mode==1){
       if(A1PPSTEP_V==420 and A1NAKPP__R==2){ A2IPPNUM_V=1; return(1); }
       if(A3PPSTEP_V==420 and A3NAKPP__R==2){ A2IPPNUM_V=3; return(3); }
       if(A4PPSTEP_V==420 and A4NAKPP__R==2){ A2IPPNUM_V=4; return(4); }
       if(A5PPSTEP_V==420 and A5NAKPP__R==2){ A2IPPNUM_V=5; return(5); }
       if(A6PPSTEP_V==420 and A6NAKPP__R==2){ A2IPPNUM_V=6; return(6); }
       return(0);
    }
    // Определить текущий шаг на АК-инициаторе (АК-при)
    if(mode==2){
       if(A2IPPNUM_V==1){ A2IPPSTEPV=A1PPSTEP_V; return(1); }
       if(A2IPPNUM_V==3){ A2IPPSTEPV=A3PPSTEP_V; return(3); }
       if(A2IPPNUM_V==4){ A2IPPSTEPV=A4PPSTEP_V; return(4); }
       if(A2IPPNUM_V==5){ A2IPPSTEPV=A5PPSTEP_V; return(5); }
       if(A2IPPNUM_V==6){ A2IPPSTEPV=A6PPSTEP_V; return(6); }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка блокировки СБУ
int Chk_SBP2(vd){
    //-------------------------------------------
    // Если программа не на шаге работы с крышками
    if(A2STEPW__V<100||(A2STEPW__V>290&&A2STEPW__V<800)||A2STEPW__V>890){
      // Если разблокировали один из СБУ - выдать команду на закрытие
      // всех задвижек и перейти в режим ожидания
      if(I2SBP1R__V>0||I2SBP2R__V>0){
        // cбросить счетчик блокировки СБУ (защита от дребезга)
        A2SBPC=0;
        // Если не закрыт хоть один из проверяемых исполнителей
        if(I2ZIOPC__V!=ON|| I2ZIPPC__V!=ON||I2ZOPPC__V!=ON||I2ZOPAC__V!=ON||
           I2VZC____V!=ON||(I2KOCC___V!=ON&&(A2STEPP__V==3||A2STEP___V==3))){
////СБУ РАЗБЛОКИРОВАНО.ЧТО-ТО ОТКРЫТО.        
           // cбросить счетчик стабильного состояния ЗАКРЫТО исполнителей
           A2SBPI=0;
           //-----------
           // если програма сюда зашла с шага меньше, чем 910(другой режим)
           if(A2STEPW__V<910){
              // увеличить счетчик сработки СБУ (считаем 5сек) и выйти
              if(A2SBPT <5){ A2SBPT++; return(1); }
              // последний раз после проверки счетчика перед проверкой
              // исполнителей- обнулить счетчики и таймеры (когда прошло 5сек)
              A2STEPZ__V=0; A2STEPC__V=0; Set_BV2(A2STEPW__V);
              Message(107+A2BNM,0);
           }
           //-----------
           // установить режим закрытия исполнителей по разблокировке СБУ
           Set_ST2(910);
           // выдать команду на закрытие всех исполнителей
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           // задвижка впуска острого пара закрыта?
           Set_ST2(911);
           switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return(1); }
             case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return(1); }
           }
           // задвижка впуска перепускного пара закрыта? 
           Set_ST2(912);
           switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return(1); }
             case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return(1); }
           }
           // задвижка выпуска перепускного пара закрыта?
           Set_ST2(913);
           switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return(1); }
             case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return(1); }
           }
           // задвижка выпуска пара в атмосферу закрыта?
           Set_ST2(914);
           switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return(1); }
             case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return(1); }
           }
           // задвижка вакуума закрыта?
           Set_ST2(915);
           switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return(1); }
             case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return(1); }
           }
           // если СБУ было разблокировано в режиме ВАКУУМИРОВАНИЯ
           if(A2STEPP__V==3){
           // клапан выпуска конденсата закрыт?
           Set_ST2(916);
           switch ( Check_TO(A2BTM+6, A2RCHKF__R* SEC, I2KOCC___V,'=',ON,  1 )){
             case RUN: { A2STEPZ__V=A2RCHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return(1); }
             case BAD: { Clear_TO(A2BTM+6); Message(146+A2BNM,0); Bell(2,1); return(1); }
           } }
           // если все закрыто- перейти в режим ожидания разблокировки СБУ
           Set_ST2(917); return(1);
        } else {
////СБУ РАЗБЛОКИРОВАНО.ВСЕ ЗАКРЫТО.        
           // если все проверяемые исполнители закрыты- уменьшить счетчик и
           // ждать на шаге 900, пока заблокируют СБУ
           if(A2SBPI<5){ A2SBPI++; return(1); }
           // после счетчика стабильного закрытия исполнителей-
           // сбросить счетчик ожидания  закрытия исполнителей
           A2SBPT=0;
           // если разблокировали СБУ в каком-то режиме,но все исполнители
           // закрыты- выдать сообщение с указанием режима на котором 
           // заблокировали СБУ
           if(A2STEPW__V<900){ Set_BV2(A2STEPW__V); Message(106+A2BNM,0); }
           // если исполнители были закрыты после разблокировки СБУ-
           // выдать сообщение о том, что исполнители закрыли
           if(A2STEPW__V>900){ Message(108+A2BNM,0); }
           Set_ST2(900);
        }
      } else {
////СБУ ЗАБЛОКИРОВАНО.
        // если СБУ заблокированы и последний выполняемый шаг был закрытие
        // задвижек при разблокировке СБУ
        if(A2STEPW__V>=900){
           // ожидать 5сек стабильной блокировки СБУ
           if(A2SBPC<5){ A2SBPC++; return(1); }
           // перейти в режим ожидания
           Message(109+A2BNM,0); Set_BV2(910); Set_ST2(50); return(1);
        }
        // когда СБУ заблокированы- сбросить счетчики блокировки СБУ и выйти
        A2SBPT=0;
        A2SBPC=0;
        A2SBPI=0;
      }
    }
    return(0);
}
//---------------------------------------------------------------------------
//  Проверка исполнителей при работе с крышками
int Chk_IF2(int mode){
    // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
    if(I2ZIOPC__V!=ON){ Message(141+A2BNM,0); return(0); }
    // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
    if(I2ZIPPC__V!=ON){ Message(142+A2BNM,0); return(0); }
    // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
    if(I2ZOPPC__V!=ON){ Message(143+A2BNM,0); return(0); }
    // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
    if(I2ZOPAC__V!=ON){ Message(144+A2BNM,0); return(0); }
    // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
    if(I2VZC____V!=ON){ Message(145+A2BNM,0); return(0); }
    // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
    if(I2KOCC___V!=ON){ Message(146+A2BNM,0); return(0); }
    // СБУ разблокирован?                           [x7.i09 (IxSBP1R) = 1]
    //                                              [x8.i09 (IxSBP2R) = 1]
    if(mode==0 or mode==1){
      if(I2SBP1R__V==0||I2SBP2R__V==0){ Message(149+A2BNM,0); return(0); }
    }
    // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
    //                                              [x8.i07 (IxP1_N_) = 1]        
    if(mode==0 or mode==1){
      if(I2P1_N___V==0||I2P2_N___V==0){ Message(156+A2BNM,0); return(0); }
    }
    // есть напряжение на щите управл гидронасосом? [x5.i00 (IxVACKR) = 1]
    if(mode==0 or mode==1){
      if(I2VACKR__V!=ON){ Message(157+A2BNM,0); return(0); }
    }
    // режим управления крышками автоклава дистанц? [x5.i03 (IxLUCDU) = 1]
    if(mode==0 or mode==1){
      if(I2LUCDU__V!=ON){ Message(158+A2BNM,0); return(0); }
    }
    // режим управления автоклавом дистанция(ПК)?
    if(mode==0 or mode==1){
      if(I2DU_____V!=ON){ Message(188+A2BNM,0); return(0); }
    }
    // проверка работы (включенного состояния) гидронасоса 
    // ожидание включения гидронасоса               [x5.i01 (IxGNS_1) = 1]
    if(mode>0){
      if(I2GNS_1__V!=ON){ Message(160+A2BNM,0); return(0); }
    }
    // если нажата кнопка СТОП
    if(mode>0){
       // если ДА - переходим в режим ГИДРОНАСОС
       if(I2KR1SB__V==ON||I2KR2SB__V==ON||I2GNS0B__V>0){
          A2CISP=0; Message(168+A2BNM,0); Set_BV2(870); Set_ST2(870); return(0);
       }
    }
    return(1);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
vd  far Regul_02(vd){

    // установить флаг ввода пароля запуска цикла и перейти
    // на режим  "ВАКУУМИРОВАНИЕ"
    if (A2CYCRN__M>OFF){ A2CYCRN__V=ON; A2CYCRN__M=OFF; Set_ST2(300); }
    // установить флаг ввода пароля остановки цикла
    if (A2CYCST__M>OFF){ A2CYCST__V=ON; A2CYCST__M=OFF; Set_ST2(50);  }
    // установить флаг ввода пароля перехода на заданный шаг
    if (A2ISPST__M>OFF){ A2ISPST__V=ON; A2ISPST__M=OFF; }

    // определение номера режима из шага
    A2STEP___V=floor( A2STEPW__V*0.01);
    // проверка граничного значения введенного шага
    if (A2STEPW__M<0  or A2STEPW__M>900){ A2STEPW__M=0; }







//  // ----------------------------------------------------------------------
//  //  Если был изменен шаг работы автоклава и введен пароль изменения шага
    if (A2STEPW__M!=A2STEPW__V and A2ISPST__V==ON){
        //  если выбран РУЧНОЙ РЕЖИМ управления и введен пароль
        //  запуска или останова цикла
        if((A2STEPW__M<=10)){
            A2STEPW__V =A2STEPW__M; Message(130+A2BNM,0);
        }
        //  если выбран режим "ОТКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=100) and (A2STEPW__M< 200) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(131+A2BNM,0);
        }
        //  если выбран режим "ЗАКРЫТИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=200) and (A2STEPW__M< 300) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(132+A2BNM,0);
        }
        //  если выбран режим "ВАКУУМИРОВАНИЕ" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=300) and (A2STEPW__M< 400) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(133+A2BNM,0);
        }
        //  если выбран режим "НАБОР ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=400) and (A2STEPW__M< 500) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(134+A2BNM,0); A2NAKPPREM=A2NAKPP__R;
        }
        //  если выбран режим "ВЫДЕРЖКА" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=500) and (A2STEPW__M< 600) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(135+A2BNM,0);
        }
        //  если выбран режим "СБРОС ДАВЛЕНИЯ" и текущий режим "ОЖИДАНИЕ"
        if((A2STEPW__M>=600) and (A2STEPW__M< 700) and (A2STEPW__V<=10)){
            A2STEPW__V =A2STEPW__M;  Message(136+A2BNM,0);
        }
        //-------------------------------------------------------------------
        //  установка вновь определенного режима работы 
        if (A2STEPW__M == A2STEPW__V){ Set_BV2(0); }
        else                         { A2STEPW__M=A2STEPW__V; }
    }
//  // ----------------------------------------------------------------------





         

//  // ----------------------------------------------------------------------
//  // Проверки и контроль для каждой новой секунды
    if(NewSEC>0){ 
       //-------------------------------------------
       // подсчет времени работы в текущем режиме
       // считать секунды
       A2STEPS__V++;
       // считать минуты
       if(A2STEPS__V>59){ A2STEPM__V++; A2STEPS__V=0; }
       // считать часы
       if(A2STEPM__V>59){ A2STEPH__V++; A2STEPM__V=0; }
       // через 99 часов время считается сначала (4,5 суток)
       if(A2STEPH__V>99){ A2STEPH__V=0; A2STEPM__V=0; A2STEPS__V=0; }
       //-------------------------------------------
       // если был введен пароль- устанавливается флаг ввода пароля, который
       // действителен 10 секунд
       if(A2ISPST__V==ON or A2CYCST__V==ON or A2CYCRN__V==ON){ A2ISPST__C++; }
       // если прошло более 10 сек после ввода пароля- сбросить флаг ввода 
       // пароля  и счетчик секунд (пароль нужно вводить заново)
       if(A2ISPST__C >10){ 
          A2ISPST__C=0; A2ISPST__V=OFF; A2CYCST__V=OFF; A2CYCRN__V=OFF;
       }
       //-------------------------------------------
       // если был изменен режим управления работой автоклава (ЩТ/ПК)
       if(S2MDUP___V!=S2MDU____V){
          // переведено на ЩИТ - перевести программу в режим "ОЖИДАНИЕ"
          if(S2MDU____V==0){
             Message(137+A2BNM,0); Set_BV2(0); Set_ST2(50);
          }
          // переведено на ПК  - выдать сообщение  и в режим "ОЖИДАНИЕ"
          if(S2MDU____V==1){
             Message(138+A2BNM,0); Set_BV2(0); Set_ST2(50);
          }
       }; S2MDUP___V=S2MDU____V;
       //-------------------------------------------
       if(Chk_SBP2()>0) return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОЖИДАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Ожидание нажатия кнопок открытия-закрытия автоклава из режима "ОЖИДАНИЕ"
    if (A2STEPW__V<=10||A2STEPW__V==900){
        if(NewSEC){ return; }
        //-----------
        // Ожидание нажатия кнопки включения гидронасоса
        // Если нажата- перейти на шаг 870
        if(V2GNS1BS_V<1){
           if(I2GNS1B__V>0){
              Message(183+A2BNM,0); O2GNS____M=ON; A2CISP=0;
              Set_BV2(50); V2GNS1BS_V=1; Set_ST2(870); return;
           }
        }
        // нажата кнопка выключения гидронасоса
        if(I2GNS0B__V>0){ V2GNS1BS_V=0; O2GNS____M=OFF; }
        //-----------
        // контроль готовности автоклава перейти в режим "ПЕРЕБРОСА"
        //(давление в автоклаве д.б.  >1 и закрыты все задвижки, клапана и
        // исполнители крышек, АК на дистанции).
        if(AIP2P____V>1 and I2ZIOPC__V>0 and I2ZIPPC__V>0 and I2ZOPPC__V>0 and
           I2VZC____V>0 and I2ZOPAC__V>0 and I2KIPC___V>0 and I2KOPC___V>0 and
           I2DU_____V>0 and
           I2SBP1Z__V>0 and I2SBP2Z__V>0){
           // определить, что другие АК не находятся в режиме перепуска
           if(Get_RA2(0)>0){
              // если какой-то АК запрашивает данный для ПЕРЕПУСКА-
              // определить его номер
              if(Get_RA2(1)>0){
                 // перейти на режим ПЕРЕБРОС
                 Message(129+A2BNM,0); Set_BV2(0); Set_ST2(700);
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
    if (A2STEPW__V>=50 and A2STEPW__V<70){
       // если ушли с шага 232:- опустить хомут
       if(A2STEPWP_V==232){

       }
       // снять команды со всех исполнителей
       //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
       Set_IS2(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
       Set_KR2(1,STOP,STOP,STOP);
       Set_KR2(2,STOP,STOP,STOP);
       // выключить гидронасос
       O2GNS____M=OFF;
       // сбросить команду включения гидронасоса
       V2GNS1BS_V=0;
       // снять галочки с выбора режимов цикла
       A2NAKPP_YM=OFF;  A2NAKPP_YV=A2NAKPP_YM;
       A2RAZVK_YM=OFF;  A2RAZVK_YV=A2RAZVK_YM;
       A2PPP___YM=OFF;  A2PPP___YV=A2PPP___YM;
       A2PVID__YM=OFF;  A2PVID__YV=A2PVID__YM;
       A2SP____YM=OFF;  A2SP____YV=A2SP____YM;
       // очистить текущие таймеры и счетчики
       Clear_TA2();
       A2PPSTEP_V=0;
       // перейти в режим ОЖИДАНИЕ
       Message(189+A2BNM,0); Set_BV2(50); Set_ST2(0);
       return;
    }
//  // ----------------------------------------------------------------------






//  //  Включение ГИДРОНАСОСА
//  // ----------------------------------------------------------------------
    if (A2STEPW__V>=870 and A2STEPW__V< 890){
        if(!NewSEC){ return; }
        Set_ST2(870);
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        //-----------
        // если нажата кнопка выключения гидронасоса- выдать комманду на 
        // выключение гидронасоса
        if(I2GNS0B__V==ON){ 
           Message(184+A2BNM,0);
           // выдать команду на выключение гидронасоса
           O2GNS____M=OFF;
           // сбросить флаг состояния кнопки включения гидронасоса
           V2GNS1BS_V=0; 
        }
        // если поступила команда на выключение гидронасоса
        if(V2GNS1BS_V==0&&O2GNS____M==OFF){
           // снять команды с исполнителей механизмов крышки
           //      N BY   HM   KR
           Set_KR2(1,STOP,STOP,STOP);
           Set_KR2(2,STOP,STOP,STOP);
           // снять команды с исполнителей задвижек
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2(STOP,STOP,STOP,STOP,STOP,STOP,STOP,STOP);
           // ждать выключение гидронасоса
           switch( Check_TO(A2BTM+1,60*SEC, I2GNS0B__V,'=',ON, 1)){
              case RUN: { return; }
              case BAD: { Message(186+A2BNM,0); Bell(2,1); break; }
              case END: { Message(185+A2BNM,0); break; }
           }
           // перейти в режим ожидания
           Set_BV2(870); Set_ST2(50); return;
        }
        // проверка состояния исполнителей
        if(Chk_IF2(0)==0){
           A2CISP++; 
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(50); 
           }
           return; 
        }; A2CISP=0;
        //-----------
        // выдать комманду на включение гидронасоса:
        O2GNS____M= ON;
        //-----------
        // ожидание нажатия кнопки "Открыть автоклав"   [x7.i12 (IxKR1OB) = 1]
        //                                              [x8.i12 (IxKR2OB) = 1]
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR1OB__V>0){
              Message(174+A2BNM,0); A2CISP=0;
              Set_BV2(50); I2KR1OBS_V=1; V2GNS1BS_V=1; Set_ST2(100); return;
           }
        }
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR2OB__V>0){
              Message(175+A2BNM,0); A2CISP=0;
              Set_BV2(50); I2KR2OBS_V=1; V2GNS1BS_V=1; Set_ST2(100); return;
           }
        }
        //-----------
        // ожидание нажатия кнопки "Закрыть автоклав"   [x7.i13 (IxKR1CB) = 1]
        //                                              [x8.i13 (IxKR2CB) = 1]
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR1CB__V>0){
              Message(176+A2BNM,0);  A2CISP=0;
              Set_BV2(50); I2KR1CBS_V=1; V2GNS1BS_V=1; Set_ST2(200); return;
           }
        }
        if(I2KR1OBS_V<1 and I2KR2OBS_V<1 and I2KR1CBS_V<1 and I2KR2CBS_V<1){
           if(I2KR2CB__V>0){
              Message(177+A2BNM,0);  A2CISP=0;
              Set_BV2(50); I2KR2CBS_V=1; V2GNS1BS_V=1; Set_ST2(200); return;
           }
        }
        //-----------
        Clear_TA2();
        return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ОТКРЫТИЯ" АК4
//  // ----------------------
//  //  Проверка начального состояния исполнителей:
    if (A2STEPW__V>=100 and A2STEPW__V< 130){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O2GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        // сообщение о начале режима
        if(A2STEPW__V!=126){ Message(195+A2BNM,0); }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST2(126);
        I2KR_TMP_V=-1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(126); Set_ST2(870); return;}
        switch ( Check_TO(A2BTM+14,A2THMUP__R*SEC, I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R;A2STEPC__V =CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(151+A2BNM,0);
                        // если это первый шаг контроля- увеличить счетчик 
                        // контроля и дать команду на поднятие хомута
                        if(A2TEMP<1){ 
                           if(I2KR1OBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
                           if(I2KR2OBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
                           A2TEMP++;
                        }
                        // если это второй шаг контроля- звонок и переход в
                        // режим ОЖИДАНИЯ
                        else        { Bell(2,1); Set_BV2(126); Set_ST2(870); }
                        return;
                      }
        }
        // очистить таймеры и счетчики
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15);
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        Clear_TO(A2BTM+18); Clear_TO(A2BTM+19);
        A2STEPZ__V=0; A2STEPC__V=0;
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        Set_ST2(130);  A2TEMP=0;
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ОТКРЫТИЕ АВТОКЛАВА":
    if (A2STEPW__V>=130 and A2STEPW__V< 134){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O2GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        Set_ST2(132);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2BY1O___V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2BY2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(132); Set_ST2(870); return;}
        // если байонет не открыт
        if(I2KR_TMP_V==OFF){
//         // команда на открытие байонета              [x6.o05 (OxBY1O_) = 1]
           //                                           [x6.o11 (OxBY2O_) = 1]
           // подается импульсами: 2сек импульс, 2сек пауза
           if(A2TEMP<2){
             // импульс на открытие
             if(I2KR1OBS_V>0){ O2BY1O___M=ON; O2BY1C___M=OFF; }
             if(I2KR2OBS_V>0){ O2BY2O___M=ON; O2BY2C___M=OFF; }
             A2TEMP++;
           } else {
             // пауза
             if(A2TEMP<4){
                O2BY1O___M=OFF; O2BY1C___M=OFF;
                O2BY2O___M=OFF; O2BY2C___M=OFF;
                A2TEMP++;
             } else {
             // переход после паузы на импульс
                if(A2TEMP<7) A2TEMP=0;
             }
           }  
        }
        switch (Check_TO( A2BTM+16,A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(154+A2BNM,0); Bell(2,1); 
                        Set_BV2(132); Set_ST2(870);
                        return; 
                      }
        }
        // сброс флага подачи импульсного сигнала на байонет
        A2TEMP=10;
        // снять команду на открытие байонетов          [x6.o05 (OxBY1O_) = 0]
        //                                              [x6.o11 (OxBY2O_) = 0]
        O2BY1O___M=OFF; O2BY1C___M=OFF;
        O2BY2O___M=OFF; O2BY2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A2BTM+17,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+17]; return; }
        }
//      // команда на поднятие хомута                   [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I2KR1OBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
        if(I2KR2OBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM2UP) = 1]
        Set_ST2(131);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(131); Set_ST2(870); return;}
        switch (Check_TO( A2BTM+14,A2THMUP__R*SEC,I2KR_TMP_V, '=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(151+A2BNM,0); Bell(2,1);
                        Set_BV2(131); Set_ST2(870);    return;
                      }
        }
        // снять команду на поднятие хомута             [x6.o01 (OxHM1UP) = 0]
        //                                              [x6.o07 (OxHM2UP) = 0]
        O2HM1UP__M=OFF; O2HM1DN__M=OFF;
        O2HM2UP__M=OFF; O2HM2DN__M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        //--------
//      // команда на открытие крышки                   [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I2KR1OBS_V>0){ O2KR1O___M=ON; O2KR1C___M=OFF; }
        if(I2KR2OBS_V>0){ O2KR2O___M=ON; O2KR2C___M=OFF; }
        // крышки открыты?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST2(133);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2KR1O___V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2KR2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(133); Set_ST2(870);  return;}
        switch (Check_TO( A2BTM+18,A2TKRO___R*SEC, I2KR_TMP_V, '=',ON,1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+18]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+18); Message(152+A2BNM,0); Bell(2,1); 
                        Set_BV2(133); Set_ST2(870);
                        return; 
                      }
        }
        // команды с крышек снимем после опускания хомута

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO(A2BTM+19,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+19]; return; }
        }
        // очистить таймеры и счетчики
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15);
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        Clear_TO(A2BTM+18); Clear_TO(A2BTM+19);
        A2STEPZ__V=0; A2STEPC__V=0;
        //
        Set_ST2(134); A2TEMP=0; return;
    }
//  // ----------------------
//  //  Опускание хомута
    if (A2STEPW__V>=134 and A2STEPW__V< 135){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // команда на включение гидронасоса
        O2GNS____M=ON;
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
//      // команда на опускание хомутов                 [x6.o02 (OxHM1DN) = 1]
        //                                              [x6.o08 (OxHM2DN) = 1]
        if(I2KR1OBS_V>0){ O2HM1DN__M=ON; O2HM1UP__M=OFF; }
        if(I2KR2OBS_V>0){ O2HM2DN__M=ON; O2HM2UP__M=OFF; }
        // хомуты опущены?                              [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST2(134);
        I2KR_TMP_V= -1;
        if(I2KR1OBS_V>0){ I2KR_TMP_V=I2HM1DN__V;   }
        if(I2KR2OBS_V>0){ I2KR_TMP_V=I2HM2DN__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(134); Set_ST2(870);  return;}
        switch (Check_TO( A2BTM+14,A2THMUP__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(150+A2BNM,0); Bell(2,1); 
                        Set_BV2(134); Set_ST2(870);
                        return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        if(I2KR1OBS_V>0){ Message(191+A2BNM,0); }
        if(I2KR2OBS_V>0){ Message(192+A2BNM,0); }
        // перевод управления автоклавом в режим "ГИДРОНАСОС"->"ОЖИДАНИЕ"|"СБУ"
        Message(197+A2BNM,0); Set_BV2(134); Set_ST2(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ЗАКРЫТИЯ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A2STEPW__V>=200 and A2STEPW__V< 230){
        if(!NewSEC){ return; }
        // команда на включение гидронасоса
        O2GNS____M=ON;
        // команда на закрытие исполнителей задвижек
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        // сообщение о начале режима
        if(A2STEPW__V==200){ Message(196+A2BNM,0); }
        //--------
        // хомут опущен?                                [x7.i01 (IxHM1DN) = 1]
        //                                              [x8.i01 (IxHM2DN) = 1]
        Set_ST2(226);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2HM1DN__V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2HM2DN__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(226);  Set_ST2(870); return;}
        switch ( Check_TO (A2BTM+14, A2THMUP__R*SEC,   I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(150+A2BNM,0); Bell(2,1); 
                        Set_BV2(226); Set_ST2(870);   return; 
                      }
        }
        // выдать комманду на открытие байонета
        if(I2KR1CBS_V>0){ O2BY1O___M=ON; O2BY1C___M=OFF; }
        if(I2KR2CBS_V>0){ O2BY2O___M=ON; O2BY2C___M=OFF; }
        // байонет открыт?                              [x7.i04 (IxBY1O_) = 1]
        //                                              [x8.i04 (IxBY2O_) = 1]
        // если байонет не открылся- выйти
        Set_ST2(228);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2BY1O___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2BY2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(228); Set_ST2(870); return;}
        switch ( Check_TO (A2BTM+15, A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+15); Message(154+A2BNM,0); Bell(2,1);
                        Set_BV2(228); Set_ST2(870);   return; 
                      }
        }
        // снять команду с байонета
        O2BY1O___M=OFF; O2BY1C___M=OFF;
        O2BY2O___M=OFF; O2BY2C___M=OFF;
        //
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15); 
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(230);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": приподнять перед закрытием
    if (A2STEPW__V>=230 and A2STEPW__V< 235){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O2GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // команда на приподнятие крышки                [x6.o03 (OxKR1O_) = 1]
        //                                              [x6.o09 (OxKR2O_) = 1]
        if(I2KR1CBS_V>0){ O2KR1O___M=ON; O2KR1C___M=OFF; }
        if(I2KR2CBS_V>0){ O2KR2O___M=ON; O2KR2C___M=OFF; }
        // крышка поднята?                              [x7.i02 (IxKR1O_) = 1]
        //                                              [x8.i02 (IxKR2O_) = 1]
        Set_ST2(231);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2KR1O___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2KR2O___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(231); Set_ST2(870); return;}
        switch (Check_TO(A2BTM+14,A2TKRO___R*SEC, I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(152+A2BNM,0); Bell(2,1);
                        Set_BV2(231); Set_ST2(870);   return; 
                      }
        }
        // снять команду на поднятие крышки             [x6.o03 (OxKR1O_) = 0]
        //                                              [x6.o09 (OxKR2O_) = 0]
        O2KR1O___M=OFF; O2KR1C___M=OFF;
        O2KR2O___M=OFF; O2KR2C___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        // подать команду на поднятие хомута            [x6.o01 (OxHM1UP) = 1]
        //                                              [x6.o07 (OxHM2UP) = 1]
        if(I2KR1CBS_V>0){ O2HM1UP__M=ON; O2HM1DN__M=OFF; }
        if(I2KR2CBS_V>0){ O2HM2UP__M=ON; O2HM2DN__M=OFF; }
        Set_ST2(232);
        // хомут поднят?                                [x7.i00 (IxHM1UP) = 1]
        //                                              [x8.i00 (IxHM1UP) = 1]
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2HM1UP__V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2HM2UP__V;   }
        if(I2KR_TMP_V<0){ Set_BV2(232); Set_ST2(870); return;}
        switch (Check_TO(A2BTM+16,A2THMUP__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2THMUP__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(151+A2BNM,0); Bell(2,1);
                        Set_BV2(232); Set_ST2(870);   return; 
                      }
        }
        // после поднятия хомута команда не снимается

        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A2BTM+17,A2TBONIS_R*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+17]; return; }
        }
        Clear_TO(A2BTM+14); Clear_TO(A2BTM+15); 
        Clear_TO(A2BTM+16); Clear_TO(A2BTM+17);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(235);
        return;
    }
//  // ----------------------
//  //  Выполнение команды "ЗАКРЫТИЕ АВТОКЛАВА": закрыть крышки
    if (A2STEPW__V>=235 and A2STEPW__V< 240){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        O2GNS____M=ON;
        //--------
        // проверка состояния исполнителей задвижек в работе
        if(Chk_IF2(1)==0){
           A2CISP++;
           if(A2CISP>1){ 
              O2GNS____M=OFF; V2GNS1BS_V=0;
              Message(187+A2BNM,0); Set_BV2(870); Set_ST2(870); 
           }
           return;
        }; A2CISP=0;
        //--------
        // команда на закрытие крышек                   [x6.o04 (OxKR1C_) = 1]
        //                                              [x6.o10 (OxKR2C_) = 1]
        if(I2KR1CBS_V>0){ O2KR1C___M=ON; O2KR1O___M=OFF; }
        if(I2KR2CBS_V>0){ O2KR2C___M=ON; O2KR2O___M=OFF; }
        // крышка закрыта?                              [x7.i03 (IxKR1C_) = 1]
        //                                              [x8.i03 (IxKR2C_) = 1]
        Set_ST2(236);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2KR1C___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2KR2C___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(236); Set_ST2(870); return;}
        switch (Check_TO (A2BTM+14,A2TKRO___R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TKRO___R; A2STEPC__V=CNTTO[A2BTM+14]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+14); Message(153+A2BNM,0); Bell(2,1);
                        Set_BV2(236); Set_ST2(870); return; 
                      }
        }
        // снять команду на закрытие крышек             [x6.o04 (OxKR1C_) = 0]
        //                                              [x6.o10 (OxKR2C_) = 0]
        O2KR1C___M=OFF; O2KR1O___M=OFF;
        O2KR2C___M=OFF; O2KR2O___M=OFF;
        // ждать некоторое время перед включением следующего исполнителя
        switch (Check_TO (A2BTM+15,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+15]; return; }
        }
        // команда на закрытие байонетов                [x6.o06 (OxBY1C_) = 1]
        //                                              [x6.o12 (OxBY2C_) = 1]
        if(I2KR1CBS_V>0){ O2BY1C___M=ON; O2BY1O___M=OFF; }
        if(I2KR2CBS_V>0){ O2BY2C___M=ON; O2BY2O___M=OFF; }
        // байонеты закрыты?                            [x7.i05 (IxBY1C_) = 1]
        //                                              [x8.i05 (IxBY1C_) = 1]
        Set_ST2(237);
        I2KR_TMP_V=-1;
        if(I2KR1CBS_V>0){ I2KR_TMP_V=I2BY1C___V;   }
        if(I2KR2CBS_V>0){ I2KR_TMP_V=I2BY2C___V;   }
        if(I2KR_TMP_V<0){ Set_BV2(237); Set_ST2(870); return;}
        switch (Check_TO (A2BTM+16,A2TBYRT__R*SEC,I2KR_TMP_V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TBYRT__R; A2STEPC__V=CNTTO[A2BTM+16]; return; }
            case BAD: { 
                        Clear_TO(A2BTM+16); Message(155+A2BNM,0); Bell(2,1);
                        Set_BV2(237); Set_ST2(870);   return; 
                      }
        }
        // снять команды с исполнителей крышек
        //      N BY   HM   KR
        Set_KR2(1,STOP,STOP,STOP);
        Set_KR2(2,STOP,STOP,STOP);
        // сообщение об окончании режима
        if(I2KR1OBS_V>0){ Message(193+A2BNM,0); }
        if(I2KR2OBS_V>0){ Message(194+A2BNM,0); }
        // перевод управления автоклавом в режим "ГИДРОНАСОС"
        Message(198+A2BNM,0); Set_BV2(235); Set_ST2(870); return;
    }
//  // ----------------------------------------------------------------------







//  //  Режим "ВАКУУМИРОВАНИЕ"
//  // ----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A2STEPW__V>=300 and A2STEPW__V<320){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "ВАКУУМИРОВАНИЕ"- перейти на сл режим
        if(A2RAZVK_YV==OFF){ Set_BV2(300); Set_ST2(400); return; }
        // проверка  вакуумирования других автоклавов
        // (на вакуумировании может находится  ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==300||A3PPSTEP_V==300||A4PPSTEP_V==300||
           A5PPSTEP_V==300||A6PPSTEP_V==300){
           Set_BV2(300); Set_ST2(50); return; 
        }
        A2PPSTEP_V=300;
        // сообщение о начале режима
        if(A2STEPW__V==300){ Message(200+A2BNM,0); }
        //
        Set_ST2(311);
        // перевести регулятор конденсата в Авт режим, чтобы закрылся клапан
        A2RCRA___M=ON;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST2(301);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST2(302);
        switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST2(303);
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST2(304);
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST2(305);
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        // клапан выпуска конденсата закрыт?            [x5.i07 (IxKOCC_) = 1]
        Set_ST2(306);
        switch ( Check_TO(A2BTM+6, A2RCHKF__R* SEC, I2KOCC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2RCHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(146+A2BNM,0); Bell(2,1); return; }
        }
        // СПУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST2(307);
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        // нет давления в автоклаве?                    [x7.i07 (IxP1_N_) = 1]
        //                                              [x8.i07 (IxP1_N_) = 1]
        Set_ST2(308);
        switch ( Check_TO(A2BTM+8, 60*SEC,(I2P1_N___V and I2P2_N___V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+8]; return; }
            case BAD: { Clear_TO(A2BTM+8); Message(156+A2BNM,0); Bell(2,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST2(309);
        switch ( Check_TO(A2BTM+9, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+9]; return; }
            case BAD: { Clear_TO(A2BTM+9); Message(147+A2BNM,0); Bell(2,1); return; }
        }
        // дистанционный режим работы вакуумнасоса      [x2.i08 (IxVNMD_) = 1]
        Set_ST2(310);
        switch ( Check_TO(A2BTM+10, 60*SEC, I2VNMD___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+10]; return; }
            case BAD: { Clear_TO(A2BTM+10); Message(162+A2BNM,0); Bell(2,1); return; }
        }
        // дистанционный режим работы задвижки          [x2.i07 (IxVZMD_) = 1]
        Set_ST2(311);
        switch ( Check_TO(A2BTM+11, 60*SEC, I2VZMD___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+11]; return; }
            case BAD: { Clear_TO(A2BTM+11); Message(182+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6);
        Clear_TO(A2BTM+7); Clear_TO(A2BTM+8); Clear_TO(A2BTM+9);
        Clear_TO(A2BTM+10); 
        Clear_TO(A2BTM+11);
        A2STEPZ__V=0; A2STEPC__V=0;
        I2MAXVCN_V=0;
        Set_ST2(320);
        return;
    }
//  // ----------------------
//  //  Включение вакуумирования
    if (A2STEPW__V>=320 and A2STEPW__V<325){
        if(!NewSEC){ return; }
        // команда на открытие вакуумной задвижки       [x4.o02 (OxVZO__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, ON , OFF, OFF, OFF);
        // вакуумная задвижка открыта?                  [x2.i01 (IxVZO__) = 1] 
        Set_ST2(321);
        switch ( Check_TO(A2BTM+1, A2TVZO___R* SEC, I2VZO____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(163+A2BNM,0); return; }
        }
        // снять команду на открытие вакуумной задвижки [x4.o02 (OxVZO__) = 0]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF,ASIS, OFF, OFF, OFF);
        // закрывается клапан на вакуумном насосе       [x4.o04 (OxAZVO_) = 1]
        O2AZVO___V=ON; O2AZVO___M=OFF;
        // команда на включение вакуумного насоса       [x4.o05 (OxVN_1_) = 1]
        O2VN_1___V=ON; O2VN_1___M=OFF;
        Set_ST2(322);
        // вакуумный насос включен?                     [x2.i05 (IxVN_1_) = 1]
        switch ( Check_TO(A2BTM+2, 60*SEC, I2VN_1___V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(164+A2BNM,0); Bell(2,1); return; }
        }
        // проверка канала максимального разрежения с   [x2.i06 (IxMAXV_) = 1]
        // эл.контактного манометра
        if(I2MAXV___V>0){ I2MAXVCN_V++; }
        else            { I2MAXVCN_V=0; }
        if(I2MAXVCN_V>5){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
           Set_ST2(325);
           return;
        }
        // проверка величины разрежения в автоклаве     [x0.06 (AIPxyV__) = ?]
        // (ждать зад вел или счет)
        Set_ST2(323);
        switch ( Check_TO(A2BTM+3, A2TVACUM_R* SEC, AIP12V___V,'<',A2RAZVK__R, 3)){
            case RUN: { A2STEPZ__V=A2TVACUM_R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Message(165+A2BNM,0); break; }
        }
        // дать комманду на закрытие вакуумной задвижки [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(325);
        return;
    }
//  // ----------------------
//  //  Выключение вакуумирования
    if (A2STEPW__V>=325 and A2STEPW__V<330){
        if(!NewSEC){ return; }
        // команда на закрытие вакуумной задвижки       [x4.o03 (OxVZC__) = 1]
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // вакуумная задвижка закрыта?                  [x2.i02 (IxVZC__) = 1]
        Set_ST2(326);
        switch ( Check_TO(A2BTM+1, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(166+A2BNM,0); return; }
        }
        // ждать некоторое время перед включением следующего исполнителя
        Set_ST2(327);
        switch (Check_TO (A2BTM+3,A2TBONIS_R*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TBONIS_R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
        }
        // открыть клапан атмосферы на вакуумном насосе [x4.o04 (OxAZVO_) = 1]
        O2AZVO___V=OFF; O2AZVO___M=OFF;
        // выключить вакуумный насос                    [x4.o05 (OxVN_1_) = 0]
        O2VN_1___V=OFF; O2VN_1___M=OFF;
        Set_ST2(328);
        // вакуумный насос выключен?                    [x2.i05 (IxVN_1_) = 0]
        switch ( Check_TO(A2BTM+4,  120*SEC, I2VN_1___V,'=',OFF, 1)){
            case RUN: { A2STEPZ__V=120; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(167+A2BNM,0); return; }
        }
        //
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); 
        Clear_TO(A2BTM+3); Clear_TO(A2BTM+4);
        A2STEPZ__V=0; A2STEPC__V=0;
        // сообщение об окончании режима
        Message(190+A2BNM,0); Set_ST2(330);
        return;
    }
//  // ----------------------
//  //  ВАКУУМИРОВАНИЕ ЗАКОНЧЕНО
    if (A2STEPW__V>=330 and A2STEPW__V<335){
        if(!NewSEC){ return; }
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF);
        // перевод управления автоклавом в ручной режим
        Set_BV2(330); Set_ST2(400);
        A2RAZVK_YM=OFF;  A2RAZVK_YV=A2RAZVK_YM;
        return;
    }
//  // -----------------------------------------------------------------------







//  //  Режим "НАБОР ДАВЛЕНИЯ"
//  // -----------------------------------------------------------------------
//  //  Проверка начального состояния исполнителей:
    if (A2STEPW__V>=400 and A2STEPW__V<420){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "НАБОР ДАВЛЕНИЯ"- перейти на сл режим
        if(A2PPP___YV==OFF){ Set_BV2 (400); Set_ST2(500); return; }
        A2PPSTEP_V=400;
        // сообщение о начале режима
        if(A2STEPW__V==400){ 
           Message(201+A2BNM,0); 
           A2RPRA___M=OFF; A2RPUU1__M=RMINUS; Set_ST2(401); return;
        }
        //
        A2NAKPPREM=A2NAKPP__R;
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска острого пара закрыта?        [x1.i01 (IxZIOPC) = 1]
        Set_ST2(401);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        Set_ST2(402);
        switch ( Check_TO(A2BTM+2, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        Set_ST2(403);
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        Set_ST2(404);
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        Set_ST2(405);
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        // клапан впуска пара закрыт?
        Set_ST2(406);
        switch ( Check_TO(A2BTM+6, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // СПБ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        Set_ST2(407);
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        // наличие напряжения на щите впуска пара       [x2.i00 (IxVAC__) = 1]
        Set_ST2(409);
        switch ( Check_TO(A2BTM+9, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+9]; return; }
            case BAD: { Clear_TO(A2BTM+9); Message(147+A2BNM,0); Bell(2,1); return; }
        }
        // режим управления автоклавом "Дистанция"?     [x1.i13 (IxDU___) = 1]
        Set_ST2(410);
        switch ( Check_TO(A2BTM+10, 60*SEC, I2VAC____V,'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*1; A2STEPC__V=CNTTO[A2BTM+10]; return; }
            case BAD: { Clear_TO(A2BTM+10); Message(159+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6); 
        Clear_TO(A2BTM+7); Clear_TO(A2BTM+8); Clear_TO(A2BTM+9); 
        Clear_TO(A2BTM+10);
        A2STEPZ__V=0; A2STEPC__V=0;
        // выбран режим набора давления магистральным паром?
        if(A2NAKPPREM==0) Set_ST2(430);
        else              Set_ST2(420);
        A2TEMP=0; A2FLAG=0; A2PPRT=0; A2RPRA___M=ON; A2RPZD___M=0;
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Проверка готовности автоклава-передатчика (открытие на нем задвижки)
    if (A2STEPW__V>=420 and A2STEPW__V<422){
        if(!NewSEC){ return; }
        A2PPSTEP_V=420;
        Set_ST2(421);
        // ждать подтверждения о готовности к перепуску с автоклава
        // передатчика
        if(A2PPRT<1){
           A2PPRT=Get_RV2(); 
           return;
        }
        Set_ST2(422);
        return;
    }
//  // ----------------------
//  //  С перепуском
//  //  Открытие исполнителей:
    if (A2STEPW__V>=422 and A2STEPW__V<425){
        if(!NewSEC){ return; }
        A2PPSTEP_V=422;
        // дать команду на открытие задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF,  ON, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара открыта?   [x3.o02 (OxZIPPO) = 1]
        Set_ST2(423);
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZIPPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(161+A2BNM,0); Bell(2,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки пер.пара
        switch (Check_TO (A2BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // снять команду с задвижки впуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF,ASIS, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        // перейти на следующий шаг
        Set_ST2(425);
        return;
    }
//  // ----------------------
//  // ожидание открытия на АК-пер клапана выпуска пара
    if (A2STEPW__V>=425 and A2STEPW__V<427){
        if(!NewSEC){ return; }
        // если АК-пер перешел из режима ПЕРЕБРОС в другой - закрыть все
        // задвижки  и перейти в  режим  ОЖИДАНИЕ (нестандартная ситуация) 
//!!!   if(A2RPPSTEPV<700||A2RPPSTEPV>710){ Set_ST2(50); return; }
        A2PPSTEP_V=425;
        // ждать подтверждения об откр клапана выпуска пара на автоклаве
        // передатчике
        if(A2PPRT<2){
           A2PPRT=Get_RV2(); 
           return;
        }
        // перейти на управление клапаном (на регулятор)
        Set_ST2(440); A2RPZD___S=0;
        return;
    }
//  // ----------------------
//  //  С магистрали
    if (A2STEPW__V>=430 and A2STEPW__V<435){
        if(!NewSEC){ return; }
        // дать команду на открытие задвижки магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2(  ON, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистрального пара открыта? [x1.i00 (IxZIOPO) = 1]
        Set_ST2(431);
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(171+A2BNM,0); Bell(2,1); return; }
        }
        // задержка 10 сек перед снятием комманды с задвижки острого пара
        switch (Check_TO (A2BTM+2, 10* SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // снять команду с задвижки впуска острого пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // обнуление таймеров и счетчиков
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        // перейти на управление клапаном (на регулятор)
        Set_ST2(440); A2RPZD___S=0; A2RPRA___M=ON;
        return;
    }
//  // ----------------------
//  //  Формирование задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ"
    if (A2STEPW__V>=440 and A2STEPW__V<445){
        if(!NewSEC){ return; }
        // определяем задание расхода для ПИД регулятора из таблицы 
        // "НАБОР ТЕМПЕРАТУРЫ"
        Set_ST2(441);
        //-----------
        // Для набора температуры острым паром:
        if(A2NAKPPREM==0){
            // если текущая Т автоклава больше очередной заданой в таблице-
            // установить задание расхода для ПИД регулятора набора давления
            if(A2RPZD___S==0){ 
               A2RPZD___M =A21NTOF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=1;
            }
            if(AIT2P____V>=A21NTOP02R  and A2RPZD___S<=2){ 
               A2RPZD___M =A21NTOF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=2;
            }
            if(AIT2P____V>=A21NTOP03R  and A2RPZD___S<=3){ 
               A2RPZD___M =A21NTOF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=3;
            }
            if(AIT2P____V>=A21NTOP04R  and A2RPZD___S<=4){ 
               A2RPZD___M =A21NTOF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=4;
            }
            if(AIT2P____V>=A21NTOP05R  and A2RPZD___S<=5){ 
               A2RPZD___M =A21NTOF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=5;
            }
        } else {
        // Для набора температуры перепускным паром:
            if(A2RPZD___S==0){
               A2RPZD___M =A21NTPF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=1;
            }
            if(AIT2P____V>=A21NTPP02R  and A2RPZD___S<=2){
               A2RPZD___M =A21NTPF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=2;
            }
            if(AIT2P____V>=A21NTPP03R  and A2RPZD___S<=3){
               A2RPZD___M =A21NTPF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=3;
            }
            if(AIT2P____V>=A21NTPP04R  and A2RPZD___S<=4){
               A2RPZD___M =A21NTPF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=4;
            }
            if(AIT2P____V>=A21NTPP05R  and A2RPZD___S<=5){
               A2RPZD___M =A21NTPF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=5;
            }
        }
        //-----------
        // если давление в автоклаве больше того, что определено
        // в первой строке таблицы "НАБОР ДАВЛЕНИЯ" - определяем задание
        // расхода  для ПИД регулятора из таблицы "НАБОР ДАВЛЕНИЯ"
        // Для набора давления острым паром:
        if(A2NAKPPREM==0){
            if(AIP2P____V>=A21NPOP01R  and A2RPZD___S<=6){ 
               A2RPZD___M =A21NPOF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=6;
            }
            if(AIP2P____V>=A21NPOP02R  and A2RPZD___S<=7){ 
               A2RPZD___M =A21NPOF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=7;
            }
            if(AIP2P____V>=A21NPOP03R  and A2RPZD___S<=8){ 
               A2RPZD___M =A21NPOF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=8;
            }
            if(AIP2P____V>=A21NPOP04R  and A2RPZD___S<=9){ 
               A2RPZD___M =A21NPOF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=9; 
            }
            if(AIP2P____V>=A21NPOP05R  and A2RPZD___S<=10){ 
               A2RPZD___M =A21NPOF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=10;
            }
            if(AIP2P____V>=A21NPOP06R  and A2RPZD___S<=11){ 
               A2RPZD___M =A21NPOF06R; A2RPZD___V=A2RPZD___M; A2RPZD___S=11;
            }
            if(AIP2P____V>=A21NPOP07R  and A2RPZD___S<=12){ 
               A2RPZD___M =A21NPOF07R; A2RPZD___V=A2RPZD___M; A2RPZD___S=12;
            }
            if(AIP2P____V>=A21NPOP08R  and A2RPZD___S<=13){ 
               A2RPZD___M =A21NPOF08R; A2RPZD___V=A2RPZD___M; A2RPZD___S=13;
            }
            if(AIP2P____V>=A21NPOP09R  and A2RPZD___S<=14){ 
               A2RPZD___M =A21NPOF09R; A2RPZD___V=A2RPZD___M; A2RPZD___S=14;
            }
            if(AIP2P____V>=A21NPOP10R  and A2RPZD___S<=15){ 
               A2RPZD___M =A21NPOF10R; A2RPZD___V=A2RPZD___M; A2RPZD___S=15;
            }
        } else {
        // Для набора давления перепускным паром:
            if(AIP2P____V>=A21NPPP01R  and A2RPZD___S<=6){ 
               A2RPZD___M =A21NPPF01R; A2RPZD___V=A2RPZD___M; A2RPZD___S=6;
            }
            if(AIP2P____V>=A21NPPP02R  and A2RPZD___S<=7){ 
               A2RPZD___M =A21NPPF02R; A2RPZD___V=A2RPZD___M; A2RPZD___S=7;
            }
            if(AIP2P____V>=A21NPPP03R  and A2RPZD___S<=8){ 
               A2RPZD___M =A21NPPF03R; A2RPZD___V=A2RPZD___M; A2RPZD___S=8;
            }
            if(AIP2P____V>=A21NPPP04R  and A2RPZD___S<=9){ 
               A2RPZD___M =A21NPPF04R; A2RPZD___V=A2RPZD___M; A2RPZD___S=9;
            }
            if(AIP2P____V>=A21NPPP05R  and A2RPZD___S<=10){ 
               A2RPZD___M =A21NPPF05R; A2RPZD___V=A2RPZD___M; A2RPZD___S=10;
            }
            if(AIP2P____V>=A21NPPP06R  and A2RPZD___S<=11){ 
               A2RPZD___M =A21NPPF06R; A2RPZD___V=A2RPZD___M; A2RPZD___S=11;
            }
            if(AIP2P____V>=A21NPPP07R  and A2RPZD___S<=12){ 
               A2RPZD___M =A21NPPF07R; A2RPZD___V=A2RPZD___M; A2RPZD___S=12;
            }
            if(AIP2P____V>=A21NPPP08R  and A2RPZD___S<=13){ 
               A2RPZD___M =A21NPPF08R; A2RPZD___V=A2RPZD___M; A2RPZD___S=13;
            }
            if(AIP2P____V>=A21NPPP09R  and A2RPZD___S<=14){ 
               A2RPZD___M =A21NPPF09R; A2RPZD___V=A2RPZD___M; A2RPZD___S=14;
            }
            if(AIP2P____V>=A21NPPP10R  and A2RPZD___S<=15){ 
               A2RPZD___M =A21NPPF10R; A2RPZD___V=A2RPZD___M; A2RPZD___S=15;
            }
        }
        //-----------
        // если автоклав в режиме набора давления перепускным  паром и
        // если разница давлений между АК-передатчиком и АК-приемником
        // меньше заданному (AxZPPRE__R) -перейти на шаг
        // закрытия исполнителей набора перепускного пара и формирование
        // задания расхода для регулятора "НАБОРА ДАВЛЕНИЯ" по острому пару
        A2PPSTEP_V=440; Get_RV2();
        if(A2NAKPPREM>0 and AIPRP2___V-AIP2P____V < A2ZPPRE__R){
           Set_ST2(480); A2PPRT=0; return;
        }

        //-----------
        // если давление в автоклаве больше заданного в "НАСТРОЙКАХ ЦИКЛА"-
        // перейти на шаг закрытия исполнителей магистрального пара
        if(A2NAKPPREM==0 and A2PPP____R>0 and AIP2P____V>=A2PPP____R){
           if(A2TEMP <7){ 
              A2TEMP++;     
           } else { 
              Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
              Set_ST2 (450);
           }
           return;
        } else {
           A2TEMP=0;
        }
        //-----------
        // если набор давления идет с магистрали и давление в автоклаве 
        // больше,чем давление в магистрали- закрыть задвижку впуска остр пара
        if(A2NAKPPREM==0 and AIP2P____V>=AIP12M___V){
           Set_ST2(442);
           // дать команду на закрытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        //-----------
        // если перепад давления между АК и магистралью стабилизировался
        if(A2NAKPPREM==0 and AIP2P____V< AIP12M___V-A2ZNPM___R){
           Set_ST2(443);
           // дать команду на открытие задвижки магистрального пара
           //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
           Set_IS2(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        }
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей магистрального пара и переход на "ВЫДЕРЖКУ"
    if (A2STEPW__V>=450 and A2STEPW__V<455){
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A2BTM+2, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(440); Set_ST2(500);
        A2PPP___YM=OFF;  A2PPP___YV=A2PPP___YM;
        // сообщение об окончании режима
        Message(202+A2BNM,0);
        return;
    }
//  // ----------------------
//  //  Закрытие исполнителей перепускного пара на АК-пер
    if (A2STEPW__V>=480 and A2STEPW__V<482){
        if(!NewSEC){ return; }
        A2PPSTEP_V=480;
        Set_ST2(481);
        // ждать подтверждения о закрытии исполнителей выпуска пара на
        // автоклаве передатчике
        if(A2PPRT<3){
           A2PPRT=Get_RV2(); return;
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(482);
        return;
    }
//  // ----------------------
    if (A2STEPW__V>=482 and A2STEPW__V<484){
        if(!NewSEC){ return; }
        Set_ST2(482);
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // задвижка впуска перепускного пара закрыта?
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // клапан впуска пара закрыт?
        switch ( Check_TO(A2BTM+2, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(128+A2BNM,0); Bell(2,1); return; }
        }
        // при закрытии всех  исполнителей перепускного пара, возвращаемся
        // на формирование задания расхода пара регулятора НАБОРА ДАВЛЕНИЯ
        // по острому пару
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(440);
        A2NAKPPREM=0; A2RPZD___S=0; A2RPRA___M=ON;
        return;
    }
//  // ----------------------------------------------------------------------
  






//  //  Режим "ВЫДЕРЖКА"
//  // ----------------------------------------------------------------------
    if ((A2STEPW__V==500)||(A2STEPW__V>510&&A2STEPW__V<517)){
        if(!NewSEC){ return; }
        Set_ST2(500);
        // если в цикл не включен режим "ВЫДЕРЖКА"- перейти на сл режим
        if(A2PVID__YV==OFF){ Set_BV2(500); Set_ST2(600); return; }
        A2PPSTEP_V=500;
        // сообщение о начале режима
        if(A2STEPW__V==500){ Message(203+A2BNM,0); }
        // выдержка автоклава под давлением проводится магистральным паром
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        Set_ST2(511);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(512);
        // клапан впуска пара закрыт?                   [x1.i05 (IxKIPC_) = 1]
        switch ( Check_TO(A2BTM+2, A2RPHKF__R, I2KIPC___V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(169+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(513);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(514);
        // задвижка выпуска пара в атмосферу закрыта?   [x1.i09 (IxZOPAC) = 1]
        switch ( Check_TO(A2BTM+4, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(515);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(516);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A2BTM+6, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        // обнуление таймеров и счетчиков
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
        Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); Clear_TO(A2BTM+6);
        A2STEPZ__V=0; A2STEPC__V=0;
        //
        Set_ST2(501);
        // установить процент начального открытия клапана впуска пара (30%)
        A2TEMP=0.3;
        A2RPRA___M=ON;
        return;
    }
//  // ----------------------
    if (A2STEPW__V==501){
        if(!NewSEC){ return; }
        Set_ST2(501);
        //-----------
        // если давление в автоклаве больше заданного-
        // перейти на  шаг закрытия клапана впуска пара
        if(AIP2P____V>=A2PPP____R){
           Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=0; 
           return;
        }
        //-----------
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // перейти на шаг закрытия задвижки и клапана впуска острого пара
        if(AIP2P____V> A2ZPAKX__R or AIP2P____V>AIP12M___V){
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=1;
           return;
        }
        //-----------
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A2STEPH__V>=A2PVIDH__R and A2STEPM__V>=A2PVIDM__R){
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2); Clear_TO(A2BTM+3); 
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(502); A2FLAG=2;
           return;
        }
        //-----------

        //-----------
        // выдержка автоклава под давлением  проводится магистральным паром
        // открыть  задвижку  магистрального пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(  ON, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задвижка впуска магистральн пара открыта?    [x1.i00 (IxZIOPO) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPO__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(171+A2BNM,0); Bell(2,1); return; }
        }
        //-----------
        // снять  команду с  задвижки впуска  острого пара  и
        // выдать команду на открытие клапана впуска  пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        if(CNTTO[A2BTM+3]==0) Set_IS2(ASIS, OFF, OFF, OFF, OFF,  ON, OFF,ASIS);
        if(CNTTO[A2BTM+3]==1) Set_IS2(ASIS, OFF, OFF, OFF, OFF,STOP, OFF,ASIS);
        // ждать A2TEMP %  секунд от полного  хода клапана впуска пара
        // или пока не сработает концевик открытия клапана
        if(I2KIPO___V<1){
           switch ( Check_TO(A2BTM+2,A2RPHKF__R*A2TEMP,ZERO,'=',ON, 1)){
               case RUN: { A2STEPZ__V=A2RPHKF__R*A2TEMP; A2STEPC__V=CNTTO[A2BTM+2]; 
                           return;
                         }
           }
        }
        // снять команду с клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF,ASIS, OFF,ASIS);
        // задержка 30 секунд
        switch ( Check_TO(A2BTM+3, 30*SEC, ZERO,'=',ON,1)){
            case RUN: { A2STEPZ__V=30; A2STEPC__V=CNTTO[A2BTM+3]; return; }
        }
        if(AIP2P____V< A2PPP____R){
        // если давление в автоклаве не поднялось до заданного и клапан
        // открыт не полностью- увеличить время открытия клапана и повторить
        // текущий шаг 
        //(впринципе,так можно открывать клапан более плавно +0.3,+0.3...)
           if(A2TEMP<0.8){
              A2TEMP=0.3;
              Clear_TO(A2BTM+2); Clear_TO(A2BTM+3);
              A2STEPZ__V=0; A2STEPC__V=0;
           }
        }
        return;
    }
    // ----------------------------------------------------------------------
    if (A2STEPW__V>=502 and A2STEPW__V<505){
        if(!NewSEC){ return; }
        Set_ST2(502);
        // установить процент начального открытия клапана впуска пара (30%)
        A2TEMP=0.3;
        // если текущее давление в автоклаве меньше заданного-
        // перейти назад на  шаг открытия  задвижки и клапана впуска пара
        if(AIP2P____V<A2PPP____R-A2ZNVD___R and 
           AIP2P____V<AIP12M___V-A2ZNPM___R and A2FLAG<2){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(501); return;
        }
        // если текущее давление автоклава больше максимально доступного в
        // автоклаве или больше, чем давление в коллекторе -
        // закрыть задвижку впуска острого пара
        if(AIP2P____V> A2ZPAKX__R or AIP2P____V>AIP12M___V){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); 
           A2STEPZ__V=0; A2STEPC__V=0; A2FLAG=1;
        }
        // контроль времени нахождения автоклава в режиме "ВЫДЕРЖКА"
        // если время нахождения автоклава в текущем режиме больше или равно 
        // заданному- перейти на закрытие  и на  режим "СБРОС ДАВЛЕНИЯ"
        if(A2STEPH__V>=A2PVIDH__R and A2STEPM__V>=A2PVIDM__R){
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5); 
           A2STEPZ__V=0; A2STEPC__V=0; A2FLAG=2;
        }
        // если это контроль максимально допустимого давления или разницы или
        // выход из режима - закрыть задвижку впуска острого пара
        if(A2FLAG>0){
          // дать команду на закрытие всех исполнителей
          //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
          Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
          // задвижка впуска острого пара закрыта?      [x1.i01 (IxZIOPC) = 1]
          switch ( Check_TO(A2BTM+5, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(141+A2BNM,0); Bell(2,1); return; }
          }
        }
        // дать команду на закрытие клапана впуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2(ASIS, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверить  состоян клапана впуска пара       [x1.i05 (IxKIPC_) = 1]
        // клапан впуска пара закрыт?            
        switch ( Check_TO(A2BTM+4, A2RPHKF__R* SEC, I2KIPC___V,'=',ON,  1 )){
            case RUN: { A2STEPZ__V=A2RPHKF__R; A2STEPC__V=CNTTO[A2BTM+4]; return; }
            case BAD: { Clear_TO(A2BTM+4); Message(170+A2BNM,0); Bell(2,1); return; }
        }
        // если был установлен флаг выхода- перейти на режим "СБРОС ДАВЛЕНИЯ"
        if(A2FLAG==2){ 
           Clear_TO(A2BTM+4); Clear_TO(A2BTM+5);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_BV2(502); Set_ST2(600);
           A2PVID__YM=OFF;  A2PVID__YV=A2PVID__YM;
           // сообщение об окончании режима
           Message(204+A2BNM,0);
        }
        return;
    }
    // ----------------------------------------------------------------------







    //  Режим "СБРОС ДАВЛЕНИЯ"
    // ----------------------------------------------------------------------
    if ((A2STEPW__V==600)||(A2STEPW__V>610&&A2STEPW__V<620)){
        if(!NewSEC){ return; }
        // если в цикл не включен режим "СБРОС ДАВЛЕНИЯ"- перейти на руч.режим
        if(A2SP____YV==OFF){ Set_BV2(600); Set_ST2(50); return; }
        // проверка СБРОСА ДАВЛЕНИЯ других автоклавов
        // (на СБРОСЕ ДАВЛЕНИЯ может находится ТОЛЬКО один автоклав)
        if(A1PPSTEP_V==600||A3PPSTEP_V==600||A4PPSTEP_V==600||
           A5PPSTEP_V==600||A6PPSTEP_V==600){
           Set_BV2(600); Set_ST2(50); Message(110+A2BNM,0); return;
        }
        A2PPSTEP_V=600;
        // сообщение о начале режима
        if(A2STEPW__V==600){ Message(205+A2BNM,0); }
        //
        A2RPRA___M=ON;
        //-----------
        // определение первоначального процента открытия клапана сброса пара
        A2FLAG=0; A2FLGP=0; if(A2TKLO___R==0) A2TKLO___R=100;
        A2FLAG=5; A2TEMP=A21SPKK05R; 
        if(A2SPAT___R>0) A2TEMP=A21SPAK05R; if(A2TEMP==0) A2TEMP=20;
        // если определен сброс пара в атмосферу
        if(A2SPAT___R>0){ A2TEMP=A2TKLO___R*0.01*A2TEMP; }
        // если определен сброс пара в акумулятор
        else            { A2TEMP=A2TKLO___R*0.01*A2TEMP; }
        // дать команду на закрытие всех исполнителей
        if(A2SPAT___R>0){
           //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
           Set_IS2( OFF, OFF, OFF,ASIS, OFF, OFF, OFF,ASIS);
        } else {
           Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        }
        Set_ST2(611);
        // задвижка впуска магистральн пара закрыта?    [x1.i01 (IxZIOPC) = 1]
        switch ( Check_TO(A2BTM+1, A2TZOPO__R* SEC, I2ZIOPC__V,'=',ON,1)){
            case RUN: { A2STEPZ__V=A2TZOPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(141+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(613);
        // задвижка выпуска перепускного пара закрыта?  [x1.i07 (IxZOPPC) = 1]
        switch ( Check_TO(A2BTM+3, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+3]; return; }
            case BAD: { Clear_TO(A2BTM+3); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(615);
        // задвижка вакуума закрыта?                    [x2.i02 (IxVZC__) = 1]
        switch ( Check_TO(A2BTM+5, A2TVZO___R* SEC, I2VZC____V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TVZO___R; A2STEPC__V=CNTTO[A2BTM+5]; return; }
            case BAD: { Clear_TO(A2BTM+5); Message(145+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(616);
        // задвижка впуска перепускного пара закрыта?   [x1.i03 (IxZIPPC) = 1]
        switch ( Check_TO(A2BTM+6, A2TZPPO__R* SEC, I2ZIPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+6]; return; }
            case BAD: { Clear_TO(A2BTM+6); Message(142+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(617);
        // СБУ заблокированы?                           [x7.i08 (IxSBP1Z) = 1]
        //                                              [x8.i08 (IxSBP2Z) = 1]
        switch ( Check_TO(A2BTM+7,5*60*SEC,(I2SBP1Z__V and I2SBP2Z__V),'=',ON, 1)){
            case RUN: { A2STEPZ__V=60*5; A2STEPC__V=CNTTO[A2BTM+7]; return; }
            case BAD: { Clear_TO(A2BTM+7); Message(148+A2BNM,0); Bell(2,1); return; }
        }
        Set_ST2(618);
        // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
        // атмосферу
        if(A2SPAT___R>0){
          // если выбран сброс в атмосферу- открыть задвижку сброса пара в 
          // атмосферу
          //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
          Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
          switch ( Check_TO(A2BTM+8, A2TZSPA__R* SEC, I2ZOPAO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+8]; return; }
            case BAD: { Clear_TO(A2BTM+8); Message(173+A2BNM,0); Bell(2,1); return; }
          }
        }
        Clear_TO(A2BTM+1);  Clear_TO(A2BTM+2);  Clear_TO(A2BTM+3);  
        Clear_TO(A2BTM+4);  Clear_TO(A2BTM+5);  Clear_TO(A2BTM+6);  
        Clear_TO(A2BTM+7);  Clear_TO(A2BTM+8);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_ST2(602);
        return;
    }
//  // ----------------------
//  //  сброс пара по таблице
    if (A2STEPW__V>=602 and A2STEPW__V<605){
        if(!NewSEC){ return; }
        Set_ST2(602);
        // присвоить переменной процент(время в секундах) открытия клапана 
        // (от полного  времени хода клапана) по таблице  соответственно
        // текущего давления  в автоклаве
        // таблица просматривается от большего к меньшему (снизу вверх)
        // без возврата на предыдущий шаг

        // если текущее давление меньше-1 или текущее давление
        // меньше последнего указанного в таблице "СБРОС ДАВЛЕНИЯ"(снизу-вверх)
        // или разблокирован один из СБУ- перейти на след режим
        if(AIP2P____V<-1 or A2FLAG==1 or I2SBP1R__V>0  or I2SBP2R__V>0){
           Set_ST2(605); Clear_TO(A2BTM+2); A2STEPZ__V=0; A2STEPC__V=0; A2FLGP=0;
           return;
        }
        
        // если определен сброс пара в атмосферу
        if(A2SPAT___R>0){
           Set_ST2(603);
           if(AIP2P____V<A21SPAP04R and A2FLAG>=5){
              // считается разница процента открытия клапана между
              // предыдущим и текущим шагом
              A2TEMP=A2TKLO___R*0.01*(A21SPAK04R-A21SPAK05R); A2FLAG=4;
           }
           if(AIP2P____V<A21SPAP03R and A2FLAG>=4){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK03R-A21SPAK04R); A2FLAG=3;
           }
           if(AIP2P____V<A21SPAP02R and A2FLAG>=3){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK02R-A21SPAK03R); A2FLAG=2;
           }
           if(AIP2P____V<A21SPAP01R and A2FLAG>=2){
              A2TEMP=A2TKLO___R*0.01*(A21SPAK01R-A21SPAK02R); A2FLAG=1;
           }
        } else {
           Set_ST2(604);
        // если выбран сброс пара в акумулятор
           if(AIP2P____V<A21SPKP04R and A2FLAG>=5){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK04R-A21SPKK05R); A2FLAG=4;
           }
           if(AIP2P____V<A21SPKP03R and A2FLAG>=4){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK03R-A21SPKK04R); A2FLAG=3;
           }
           if(AIP2P____V<A21SPKP02R and A2FLAG>=3){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK02R-A21SPKK03R); A2FLAG=2;
           }
           if(AIP2P____V<A21SPKP01R and A2FLAG>=2){
              A2TEMP=A2TKLO___R*0.01*(A21SPKK01R-A21SPKK02R); A2FLAG=1;
           }
        }
        // если был переход на новый шаг
        if(A2FLGP!=A2FLAG){
           // если значение A2TEMP > 0 - открываем клапан выпуска пара,
           // иначе - закрываем
           if(A2TEMP>0){
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF,  ON,ASIS);
           } else {
              //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
              Set_IS2( OFF, OFF, OFF,  ON, OFF, OFF, OFF,ASIS);
           }
           // обновить значения
           A2TEMP=fabs(A2TEMP);  
           A2FLGP=A2FLAG;
           // обнулить таймер и счетчики для отработки новых значений
           Clear_TO(A2BTM+1); A2STEPZ__V=0;  A2STEPC__V=0;
        }
        // считаем время воздействия сигнала на клапан
        switch ( Check_TO(A2BTM+1, A2TEMP*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=A2TEMP; A2STEPC__V=CNTTO[A2BTM+1]; return; }
        }
        // после отработки таймера- снять сигналы с исполнителей
        //      ZIOP ZIPP ZOPP ZOPA   VZ  KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF,ASIS, OFF, OFF,STOP,ASIS);
        return;
    }
//  // ----------------------
//  //  повторная проверка и выход из текущего режима в режим "ОЖИДАНИЕ"
    if (A2STEPW__V>=605 and A2STEPW__V<607){
        if(!NewSEC){ return; }
        // если текущее  давление меньше или равно  нулю 
        // или  меньшему значению в таблице- увелич счетчик
        if(AIP2P____V<=0 or A2FLAG==1 or I2SBP1R__V>0  or I2SBP2R__V>0){
           A2FLGP++;
        // иначе - уменьшить
        } else { 
           A2FLGP--; 
        }
        // 10 сек ожидание 
        switch ( Check_TO(A2BTM+2, 10*SEC, ZERO,'=',ON, 1)){
            case RUN: { A2STEPZ__V=10; A2STEPC__V=CNTTO[A2BTM+2]; return; }
        }
        // если счетчик положительный - 
        // перейти на шаг закрытия исполнителей
        if(A2FLGP>2){
           Set_ST2(607); Clear_TO(A2BTM+1);
        } else {
        // если счетчик отрицательный - вернуться на СБРОС ДАВЛЕНИЯ
           Set_ST2(603); A2FLGP=A2FLAG;
        }; Clear_TO(A2BTM+2); A2STEPZ__V =0; A2STEPC__V=0;
        return;
    }
//  // ----------------------
//  //  закрытие исполнителей СБРОСА ДАВЛЕНИЯ и выход из режима
    if (A2STEPW__V>=607 and A2STEPW__V<609){
        if(!NewSEC){ return; }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки сброса пара в атмосферу
        switch ( Check_TO(A2BTM+1, A2TZSPA__R* SEC, I2ZOPAC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZSPA__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(144+A2BNM,0); Bell(2,1); return; }
        }
        // проверка закрытия клапана выпуска пара
        switch ( Check_TO(A2BTM+2, A2TKLO___R* SEC, I2KOPC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(139+A2BNM,0); Bell(2,1); return; }
        }
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(602); Set_ST2(50);
        A2SP____YM=OFF; A2SP____YV=A2SP____YM;
        // сообщение об окончании режима
        Message(206+A2BNM,0);
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
    if (A2STEPW__V>=700 and A2STEPW__V<702){
        if(!NewSEC){ return; }
        A2RPRA___M=ON;
        // открыть задвижку выпуска перепускного пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF,  ON, OFF, OFF, OFF, OFF,ASIS);
        // проверка открытия задвижки выпуска перепускного пара
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZOPPO__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(179+A2BNM,0); Bell(2,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A2PPSTEP_V=700;
        // перейти на следующий шаг
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0;  A2STEPC__V=0;
        Set_ST2(702);
        return;
    }
//  // ----------------------
//  //  открытие клапана выпуска пара
    if (A2STEPW__V>=702 and A2STEPW__V<704){
        if(!NewSEC){ return; }
        Get_RA2(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A2IPPSTEPV>=400&&A2IPPSTEPV<500){
           // ожидать открытия задвижки на АК-при
           if(A2IPPSTEPV!=425){ return; }
        } else {
        // если АК-при перешел из режима НАБОРА ДАВЛЕНИЯ в другой режим-
        // перейти  на закрытие исполнителей (нестандартная ситуация)
           Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
           A2STEPZ__V=0; A2STEPC__V=0;
           Set_ST2(704); return;
        }
        // открыть клапан выпуска пара
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF,ASIS, OFF, OFF, OFF,  ON,ASIS);
        // проверка открытия клапана выпуска пара
        switch ( Check_TO(A2BTM+1, A2TKLO___R* SEC, I2KOPO___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(181+A2BNM,0); Bell(2,1); return; }
        }
        // после открытия установить флаг подтверждения отрытия для АК-при
        A2PPSTEP_V=704;
        // перейти на следующий шаг
        Clear_TO(A2BTM+1);  Clear_TO(A2BTM+2);
        A2STEPZ__V=0;  A2STEPC__V=0;
        Set_ST2(704);
        return;
    }
//  // ----------------------
//  // закрытие исполнителей выпуска перепускного пара
    if (A2STEPW__V>=704 and A2STEPW__V<706){
        if(!NewSEC){ return; }
        Get_RA2(2);
        // если АК-инициатор(АК-при) находится на шаге набора пара
        if(A2IPPSTEPV>=400&&A2IPPSTEPV<500){
           // ожидать пока АК-при не наберет нужного давления и не
           // перейдет  на шаг закрытия исполнителей
           if(A2IPPSTEPV!=480){ return; }
           // если АК-инициатор ушел из режима НАБОР ДАВЛЕНИЯ- закрываем
           // исполнители и переходим в режим  ОЖИДАНИЯ
           //(нестандартная ситуация)
        }
        // выдать команду на закрытие всех исполнителей
        //      ZIOP ZIPP ZOPP ZOPA  VZ   KIP  KOP  KOC
        Set_IS2( OFF, OFF, OFF, OFF, OFF, OFF, OFF,ASIS);
        // проверка закрытия задвижки выпуска перепускного пара
        switch ( Check_TO(A2BTM+1, A2TZPPO__R* SEC, I2ZOPPC__V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TZPPO__R; A2STEPC__V=CNTTO[A2BTM+1]; return; }
            case BAD: { Clear_TO(A2BTM+1); Message(143+A2BNM,0); Bell(2,1); return; }
        }
        // закрыть клапан выпуска пара
        switch ( Check_TO(A2BTM+2, A2TKLO___R* SEC, I2KOPC___V,'=',ON, 1 )){
            case RUN: { A2STEPZ__V=A2TKLO___R; A2STEPC__V=CNTTO[A2BTM+2]; return; }
            case BAD: { Clear_TO(A2BTM+2); Message(139+A2BNM,0); Bell(2,1); return; }
        }
        // после закрытия установить флаг подтверждения закрытия исполнителей
        A2PPSTEP_V=705;
        // после окончания перепуска пара автоклав переключается в режим
        // "СБРОС ДАВЛЕНИЯ"
        Clear_TO(A2BTM+1); Clear_TO(A2BTM+2);
        A2STEPZ__V=0; A2STEPC__V=0;
        Set_BV2(704); Set_ST2(600);
        // если АК-при не в режиме НАБОРА ДАВЛЕНИЯ (нестандартная ситуация)
        // перевести этот АК в режим ОЖИДАНИЯ
        if(A2IPPSTEPV<400||A2IPPSTEPV>500){ Set_ST2(50); }
        A2SP____YM=OFF; A2SP____YV=ON;
        // сообщение об окончании режима
        Message(207+A2BNM,0);
        return;
    }
//  // ----------------------------------------------------------------------


    return;
}
//---------------------------------------------------------------------------
