// coding=cp866; version=2013013112; title="";
//---------------------------------------------------------------------------
// Подкачка цемента

#include "..\prg\_libpath.inc"
#include "..\prg\run_prgv.h"

#include "regul_e.h"

_f far *DONPR05;                 // текущий сигнал (комманда) выхода на исполн
_i far  DONCN05=0;               // счетчик цикла передергивания              
_i far  DONCH05=2;               // заданное кол-во циклов для передергивания 
_i far  DONTM05=2;               // кол-во секунд вкл и паузы

//---------------------------------------------------------------------------
//  Определения для передергивания исполнителей регулятора при несработке
vd  Isp05PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR05= IOPNT;
    DONCH05= hM;
    DONTM05= hS;
    STEP05 = Step; 
    STEP05_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  управление исполнителями
vd  far Set_IS5(_f far VNT, _f far SHN, _f far PIT, _f far KLP){
    if(VNT!=ASIS) if(VNT==ON) DON043B__V=ON; else DON043B__V=OFF;
    if(SHN!=ASIS) if(SHN==ON) DON044B__V=ON; else DON044B__V=OFF;
    if(PIT!=ASIS) if(PIT==ON) DON045B__V=ON; else DON045B__V=OFF;
    if(KLP!=ASIS) if(KLP==ON) DON046B__V=ON; else DON046B__V=OFF;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  В режиме [К] управлять исполнителями вручную нельзя
vd  far ModeKO_05(vd){
    if(REG05R___V==ON){
        DON043B__M=OFF;
        DON044B__M=OFF;
        DON045B__M=OFF;
        DON046B__M=OFF;
}   }
//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_05off(vd){
    Set_IS5(OFF,OFF,OFF,OFF);
    STEP05F=OFF;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  Выполнение действий при выключении и выключеном регуляторе
vd  far Regul_05m(vd){
    //-----------------------------------------------------------------------
    if ( STEP05  == 101 ){
         REG05SW__V=1001;
         // комманда на выключение исполнителей регуляторов
         Regul_05off();
         STEP05F   =0;
         // сброс таймеров
         Clear_TO(51);
         Clear_TO(52);
         Clear_TO(53);
         Clear_TO(54);
         Clear_TO(55);
         Clear_TO(56);
         Clear_TO(57);
         Clear_TO(58);
         STEP05 =  102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP05    == 102 ){
         STEP05P    = 102;
         REG05SW__V = 1002;
         REG05R___M = OFF;
         STEP05_BACK= 0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP05=101;
    return;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//  Вкл-выкл регулятора и работа в автоматическом режиме
vd  far Regul_05(vd){
    //  Время паузы между включениями исполнителей
    if (TIME_CMPKW <  0){ TIME_CMPKW = 5;  }                     // 5 SEC
    if (CTRL_LLBCW <  0){ CTRL_LLBCW = 1;  }                     // 1-да
    if (CTRL_HLBCW <  0){ CTRL_HLBCW = 1;  }                     // 1-да

    // включение-выключение регулятора
    if ( REG05RS__M == SWITCH ){ 
         REG05R___M = (REG05R___M==ON) then_ OFF else_ ON; REG05RS__M=OFF;
    }
    if ( REG05R___M != REG05R___V ){ 
         REG05R___M  =(REG05R___M==ON) then_ ON else_ OFF;
         REG05R___V  = REG05R___M;
         if ( REG05R___V == ON ){ Message(360,NOKV); STEP05 =   0; }
         else                   { Message(361,NOKV); STEP05 = 101; }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    // Начальные проверки для включения
    if ( STEP05 == 0 ){
       if(STEP05P!=0){
            Clear_TO(51);
       }; STEP05P =0;
       Regul_05off();
       // если нет вызова регулятора или регулятор выключен - выйти
       if ( RegRUN==OFF || REG05R___V==OFF ){ return; }
       // если ключ подкачки цемента в режиме Наладка - выйти
       REG05SW__V = 0;
       if ( DIS049B__V == 1 ){ return; }
       // если есть сигнал верхнего уровня бункера цемента - выйти
       REG05SW__V = 1;
       if (CTRL_HLBCW==ON){
          switch ( Check_TO (51,TIME_LSTBV*2*SEC, DIS033H__V,'=',OFF,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(51); return; }
          }   
       }
       // если идет дозировка цемента - выйти
       REG05SW__V = 3;
       if((STEP06c>0 and STEP06c<6) or (STEP06c==51)){ return; }

       Clear_TO(51);
       STEP05 = 1;
       return;
    }
    //------------------------------------------------------------------------
    if ( STEP05 ==1){
      if(STEP05P!=1){
         Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54); TIME_CMPKC=0;
      }; STEP05P =1;
      if(RegRUN==OFF){ return; }

      // включить вентилятор аспирации цемента
      //      VNT SHN PIT KLP
      Set_IS5(ON ,OFF,OFF,OFF);
      REG05SW__V= 10;
      if(DIS043B__V==OFF){ CNTTO[51]=0; return; }
      if(Check_TO(51,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[51]; return; }

      // открыть клапан аспирации цемента
      Set_IS5(ON ,OFF,OFF,ON );
      REG05SW__V= 11;
      if(DIS046B__V==OFF){ CNTTO[52]=0; return; }
      if(Check_TO(52,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[52]; return; }

      // включить шнек аспирации цемента
      Set_IS5(ON ,ON ,OFF,ON );
      REG05SW__V= 12;
      if(DIS044B__V==OFF){ CNTTO[53]=0; return; }
      if(Check_TO(53,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[53]; return; }

      // включить питатель аспирации цемента
      Set_IS5(ON ,ON ,ON ,ON );
      REG05SW__V= 13;
      switch ( Check_TO  (54, TIME_ISPRV*SEC, DIS045B__V,'=',ON,  1 )){
          case RUN: { return;; }
          case BAD: { Clear_TO(54); return; }
      }

      Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54);
      STEP05 = 2;
      return;
    }
    //------------------------------------------------------------------------
    // Ожидание набора верхнего уровня бункера цемента
    // Если во время ожидания верхнего уровня начинается дозировка цемента -
    // выключить исполнители и ждать окончания дозировки (???)
    if( STEP05 == 2){
      if(STEP05P!=2){
         Clear_TO(51);
      }; STEP05P =2;
      if(RegRUN==OFF){ return; }
      REG05SW__V =20;
      if (CTRL_HLBCW==ON){
          switch ( Check_TO (51,TIME_LSTBV*2*SEC, DIS033H__V,'=',ON,2)){
              case RUN: { return;; }
              case BAD: { Clear_TO(51); return; }
          }   
      }
      Clear_TO(51);
      Clear_TO(55); Clear_TO(56); Clear_TO(57); TIME_CMPKC=0;
      STEP05=3;
      return;
    }
    //------------------------------------------------------------------------
    // Выключение исполнителей аспирации
    if( STEP05 == 3){
      if(RegRUN==OFF){ return; }

      // выключить питатель аспирации цемента
      //      VNT SHN PIT KLP
      Set_IS5(ON ,ON ,OFF,ON );
      REG05SW__V= 31;
      switch ( Check_TO  (51, TIME_ISPRV*SEC, DIS045B__V,'=',OFF,  1 )){ 
          case RUN: { return; }
          case BAD: { Clear_TO(51); return; }
      }
      if(Check_TO(55,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[55]; return; }

      // выключить шнек аспирации цемента
      Set_IS5(ON ,OFF,OFF,ON );
      REG05SW__V= 32;
      switch ( Check_TO  (52, TIME_ISPRV*SEC, DIS044B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(52); return; }
      }
      if(Check_TO(56,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[56]; return; }

      // закрыть клапан аспирации цемента
      Set_IS5(ON ,OFF,OFF,OFF);
      REG05SW__V= 33;
      switch ( Check_TO  (53, TIME_ISPRV*SEC, DIS046B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(53); return; }
      }
      if(Check_TO(57,TIME_CMPKW*SEC,ZERO,'=',ON,1)==RUN){ TIME_CMPKC=CNTTO[57]; return; }

      // выключить вентилятор аспирации цемента
      Set_IS5(OFF,OFF,OFF,OFF);
      REG05SW__V= 34;
      switch ( Check_TO  (54, TIME_ISPRV*SEC, DIS043B__V,'=',OFF,  1 )){
          case RUN: { return; }
          case BAD: { Clear_TO(54); return; }
      }

      Clear_TO(51); Clear_TO(52); Clear_TO(53); Clear_TO(54);
      Clear_TO(55); Clear_TO(56); Clear_TO(57);
      if(STEP05P==2) STEP05=4;
      return;
    }
    //------------------------------------------------------------------------
    // Ожидание нижнего уровня (кол-ва дозировок) и сигнала со склада
    if(STEP05==4){
      if(STEP05P!=4){
         ;;
      }; STEP05P =4;
      Set_IS5(OFF,OFF,OFF,OFF);
      if(RegRUN==OFF){ return; }
      REG05SW__V=40;
      if(DIS033M__V==0 && DIS033L__V==0) STEP05=0;
      return;
    }
    //------------------------------------------------------------------------
    //  Ожидание окончания дозировки сухого для продолжения подкачки
    if(STEP05==40){
      if(STEP05P!=40){
         ;;
      }; STEP05P =40;
      REG05SW__V =400;
      return;
    }
    //------------------------------------------------------------------------
    //  Ожидание закрытия клапанов дозировки цемента для продолжения
    //  подкачек
    if ( STEP05 == 50 ){
      if(STEP05P!=50){
         ;;
      }; STEP05P =50;
      REG05SW__V =500;
      return;
    }
    //------------------------------------------------------------------------
    

    //------------------------------------------------------------------------
    // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
    //------------------------------------------------------------------------
    if( STEP05 ==70 ){
        if(STEP05P!=70){
           ;;
        }; STEP05P =70;
        if(RegRUN==OFF){ return; }
        if(DONCN05>=DONCH05){ STEP05 = STEP05_PRBK; return; }
        REG05SW__V =700;
        if(Check_TO(205, DONTM05*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(205);
       *DONPR05=(*DONPR05!=ON)?ON:OFF;
        DONCN05++;
        STEP05 = STEP05_PRBK;
        return;
    }
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // если задан несуществующий шаг регулятора - регулятор в ручной режим
    Regul_05m();
    return;
}
//---------------------------------------------------------------------------
