//---------------------------------------------------------------------------
// Дозировка сухого

#include "..\lib\codlib.h"
#include "..\lib\codipccs.def"
#include "..\lib\codipccs.h"
#include "..\run_prgv.h"

#include "regul_e.h"

_f far *DONPR06;
_i far  DONCN06=0;                // счетчик цикла передергивания
_i far  DONCH06=2;                // заданное кол-во циклов для передергивания
_i far  DONTM06=2;                // кол-во секунд вкл и паузы

_i far  FLVB_ON=0;                // флаг очередности включения вибр-возд
_i far  IS06ERR=0;                // флаг ошибки сработки исполнителей
_f far  TMVIBRUN=0;               // время включения вибратора|воздуха

//---------------------------------------------------------------------------
//  Определения для передергивание исполнителей регулятора при несработке
vd  Isp06PD(_f *IOPNT,_i far hM,_i far hS,_i far Step,_i far Step_Back,_i far ClearTON){
    DONPR06= IOPNT;
    DONCH06= hM;
    DONTM06= hS;
    STEP06 = Step;
    STEP06_PRBK = Step_Back;
    Clear_TO(ClearTON);
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выключение исполнителей регулятора
vd  far Regul_06off(vd){
    DON132___V =  OFF;
    DON141___V =  OFF;
    DON142___V =  OFF;
    DON143___V =  OFF;
    DON150___V =  OFF;
    DON151___V =  OFF;
    DON152___V =  OFF;

    DON162___V =  OFF;
    DON171___V =  OFF;
    DON172___V =  OFF;
    DON173___V =  OFF;
    DON180___V =  OFF;
    DON181___V =  OFF;
    DON182___V =  OFF;

    DON191___V =  OFF;
    DON192___V =  OFF;
    DON193___V =  OFF;
    return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Выполнение действий при выключеном регуляторе
vd  far Regul_06m(vd){
    //-----------------------------------------------------------------------
    if ( STEP06 == 101 ){
         REG06SW__V=1001;
         if(RegRUN==OFF){ return; }
         Regul_06off();
         FLAG_0605A=OFF;
         FLAG_05WTA=OFF;
         STEP06 = 102;
         return;
    }
    //-----------------------------------------------------------------------
    if ( STEP06 == 102 ){
         STEP06P = 102;
         REG06SW__V=1002;
         REG06R___M=OFF;
         AIW190FV_V=0;
         return;
    }
    //-----------------------------------------------------------------------
    STEP06=101;
    return;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Regul_06(vd){

    //  выбор режима выгрузки из дозатора сухого
    if (VGR_SHALLM==SWITCH){
        VGR_SHALLV=ON;; VGR_SHRECV=OFF; VGR_SHIZLV=OFF;
    }
    if (VGR_SHRECM==SWITCH){
        VGR_SHALLV=OFF; VGR_SHRECV=ON;; VGR_SHIZLV=OFF;
    }
    if (VGR_SHIZLM==SWITCH){
        VGR_SHALLV=OFF; VGR_SHRECV=OFF; VGR_SHIZLV=ON;;
    };  VGR_SHALLM=OFF; VGR_SHRECM=OFF; VGR_SHIZLM=OFF;

    if (BLCEMP___M== SWITCH){
        BLCEMP___V =(BLCEMP___V==ON) then_ OFF else_ ON; BLCEMP___M=OFF;
    }
    if (BLVYGP___M== SWITCH){
        BLVYGP___V =(BLVYGP___V==ON) then_ OFF else_ ON; BLVYGP___M=OFF;
    }
    if (BLNSUH___M== SWITCH){
        BLNSUH___V =(BLNSUH___V==ON) then_ OFF else_ ON; BLNSUH___M=OFF;
    }

    //  включение-выключение регулятора
    if ( REG06RS__M == SWITCH ){
         REG06R___M = (REG06R___M==ON) then_ OFF else_ ON; REG06RS__M=OFF;
    }
    if ( REG06R___M != REG06R___V ){
         REG06R___M  =(REG06R___M==ON) then_ ON else_ OFF;
         REG06R___V  = REG06R___M;
         if ( REG06R___V == ON ){ Message(370); STEP06 =   0; }   // автомат
         else                   { Message(371); STEP06 = 101; }   // ручное
    }
    //  загрузка-выгрузка
    if ( REG06ZV__M != REG06ZV__V ){
         REG06ZV__M  =(REG06ZV__M>=ON) then_ ON else_ OFF;
         REG06ZV__V  = REG06ZV__M;
         if(REG06ZV__V>0){ Message(372); }                        // загрузка
         else            { Message(373); }                        // выгрузка
    }
    //  общий-локальный
    if ( REG06GL__M != REG06GL__V ){
         REG06GL__M  =(REG06GL__M==ON) then_ ON else_ OFF;
         REG06GL__V  = REG06GL__M;
         if(REG06GL__V>0){ Message(374); }                        // общий
         else            { Message(375); }                        // локальный
    }
    //  если регулятор выключен - выйти
    if ( REG06R___V == OFF ){ Regul_06m(); return; }

    //  если во время выгрузки сухого поднялся герметизатор-
    //  закрыть клапан выгрузки и выключить регулятор
    if (STEP06>=32 and STEP06<=33 and DIS31A___V==OFF){
        Bell(1); Message(115); Message(676); Regul_06off(); 
        REG06R___M=OFF; return;
    }


    //  ПРОВЕРКА СОСТОЯНИЯ РЕГУЛЯТОРА:
    //-----------------------------------------------------------------------
    if ( STEP06 == 0 ){
        if(STEP06P!=0){
           ;;
        }; STEP06P =0;
        if (RegRUN==OFF){ return; }

        Regul_06off();

        //-------------------------------
        //  ключ бункера цемента
        REG06SW__V =0;
        if(DIR170___V==MANUAL and (REG06ZV__V==ON or DON801___V==0)){ return; }

        //  ключ бункера вяжущего
        REG06SW__V =1;
        if(DIR140___V==MANUAL and (REG06ZV__V==ON or DON801___V==0)){ return; }

        //  ключ дозатора сухого
        REG06SW__V =2;
        if(DIR190___V==MANUAL){ return; }

        //-------------------------------
        //  проверка начального состояния исполнителей бункера цемента
        REG06SW__V =3;
        if (DIR170___V==AUTO and
           (DIS171___V==ON or DIS172___V==ON or DIS173___V==ON or
            DIS180___V==ON or DIS181___V==ON or DIS182___V==ON)){
            switch(Check_TO(61,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(61); return;; }
            }
        };  Clear_TO(61);

        //  проверка начального состояния исполнителей бункера вяжущего
        REG06SW__V =4;
        if (DIR140___V==AUTO and
           (DIS141___V==ON or DIS142___V==ON or DIS143___V==ON or
            DIS150___V==ON or DIS151___V==ON or DIS152___V==ON)){
            switch(Check_TO(62,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(62); return;; }
            }
        };  Clear_TO(62);

        //  проверка начального состояния исполнителей дозатора сухого
        REG06SW__V =5;
        if (DIR190___V==AUTO and
           (DIS191___V==ON or DIS192___V==ON or DIS193___V==ON)){
            switch(Check_TO(63,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(63); return;; }
            }
        };  Clear_TO(63);

        //  проверка начального состояния шнеков
        REG06SW__V =6;
        if((DIR130___V==AUTO and DIS132___V==ON) or
           (DIR160___V==AUTO and DIS162___V==ON) ){
            switch(Check_TO(64,60*SEC, ZERO,'=',ON, 1)){
                case RUN: { return;; }
                case BAD: { Message(267); Bell(1); Clear_TO(64); return;; }
            }
        };  Clear_TO(64);

        //  проверка нижнего уровня бункера цемента
        REG06SW__V =7;
        if(DIL170___V==ON and CTRL_LLBCV==ON){
           // делать проверку если регулятр в общем режиме или если
           // регулятор в локальном режиме и включена загрузка
           if(REG06GL__V==ON  and DON801___V==0 ){ return; }
           if(REG06GL__V==OFF and REG06ZV__V==ON){ return; }
        };

        //  проверка нижнего уровня бункера вяжущего
        if(DIL140___V==ON and CTRL_LLBVV==ON){
           // делать проверку если регулятр в общем режиме или если
           // регулятор в локальном режиме и включена загрузка
           if(REG06GL__V==ON  and DON801___V==0 ){ return; }
           if(REG06GL__V==OFF and REG06ZV__V==ON){ return; }
        };

        //  проверка флага работоспособности прибора дозатора сухого
        REG06SW__V =8;
        if( COM2ER01FL==ON ){ return; }

        REG06SW__V =9;
        //-------------------------------
        //  ЗАГРУЗКА:
        //  регулятор включен на загрузку для ЛОКАЛЬНОЙ работы
        if( REG06ZV__V == ON and REG06GL__V == OFF){
            // проверка положения ВГБМ (дб OFF)
            if(DIS315___V==ON){ return; }
            // проверка герметизатора  (дб OFF)
            if(DIS31A___V==ON){ return; }
            DON801___V=0;
            STEP06 = 1;
        }

        //  регулятор включен для ОБЩЕЙ работы и дозатор сухого выгружен
        if( RegPublicV == ON  and REG06GL__V == ON and DON801___V == 0 ){
            // проверка положения ВГБМ (дб OFF)
            if(DIS315___V==ON){ return; }
            // проверка герметизатора  (дб OFF)
            if(DIS31A___V==ON){ return; }
            STEP06 = 1;
        }
        //-------------------------------

        //-------------------------------
        //  ВЫГРУЗКА общая
        //  Если дозатор сухого загружен и дозатор мокрого выгружен
        //  и включен общий регулятор и вес дозатора мокрого меньше допустим-
        //  перейти на шаг выгрузки
        if( DON801___V==1 and DON802___V==2 and RegPublicV==ON and
            REG06GL__V==ON ){
            STEP06=31;
        }

        //  ВЫГРУЗКА локальная
        //  Если включен локальный регулятор и включена выгрузка
        //  и дозатор мокрого выгружен или регулятор 07 выключен
        //  и вес дозатора мокрого меньше остаточного -
        //  перейти на шаг выгрузки
        if( REG06GL__V==OFF and REG06ZV__V==OFF and
          ( DON802___V==2   or  REG07R___V==OFF )){
            STEP06=31;
        }
        //-------------------------------

        Clear_TO(61);

        // Обнулять данные набора только вначале загрузки
        if(STEP06==1){
           CRCEMA___V=0;
           CRCEMB___V=0;
           CRCEMS___V=0;
           CRVYGA___V=0;
           CRVYGB___V=0;
           CRVYGS___V=0;
           AIW190FV_V=0;
           AIW190NV_V=AIW190___V;           // начальный вес дозатора сухого
        }

        return;
    }
    //-----------------------------------------------------------------------


   // ДОЗИРОВКА ЦЕМЕНТА ИЗ АСПИРАЦИИ:
   //------------------------------------------------------------------------
   if ( STEP06 == 1 ){
       if(STEP06P!=1){
          Regul_06off();
       }; STEP06P =1;
       if(RegRUN==OFF){ return; }
       KRCEM____F = 0;                 // флаг корректировки воды для цемента
       AIW190VO_V = TRCEMA_VIB+KRVYGS___V-DPCEMA___V;
       AIW190VZ_V = TRCEMA_VIB+KRVYGS___V;
       AIW190VB_V = TRCEMA_VIB+KRVYGS___V+BLCEMA___V;

       REG06SW__V =10;

       //  если шнек дозатор цемент в руч режиме- перейти на набор из бункера
       if (DIR160___V == MANUAL){ STEP06 = 3; return; }

       //  если рецептный вес цемента аспирации равен 0- перейти на шаг 3
       if (TRCEMA_VIB == 0){ STEP06 = 3; return; }

       //  если вес дозатора больше рецептного веса цемента аспирации минус
       //  вес допуска набора цемента аспирации- перейти на шаг 3
       if (AIW190___V>=TRCEMA_VIB){ STEP06 = 3; return; }

       //  вес цемента из аспирации
       CRCEMA___V = AIW190___V-AIW190NV_V; AIW190FV_V=1;

       //  включить шнек аспирации цемента
       REG06SW__V = 11;
       DON162___V = ON;
       switch ( Check_TO  (61, TIME_ISPRV*SEC, DIS162___V,'=',ON,  1 )){
           case RUN: { return;; }
           case BAD: {
                        if(DONCN06 > 1){ break;; }
                        Isp06PD(&DON162___V,3,TIME_ISPPW,70,  1, 61);
                        return;;
                     }
       }; DONCN06=0;
       Clear_TO(61);
       STEP06=2;
       return;
   }
   //------------------------------------------------------------------------
   if ( STEP06 == 2 ){
        if(STEP06P!=2){
           AIW190___O=AIW190___V;
           AIW190___C=0;
           TMST_CAV_C=0;
        }; STEP06P =2;
        AIW190VO_V = TRCEMA_VIB+KRVYGS___V-DPCEMA___V;
        AIW190VZ_V = TRCEMA_VIB+KRVYGS___V;
        AIW190VB_V = TRCEMA_VIB+KRVYGS___V+BLCEMA___V;

        REG06SW__V = 20;

        //  если текущий вес больше рецептного для набора цемента из аспирации
        //  минус вес допуска цемента аспирации- перейти на шаг 3.
        if (AIW190___V>=AIW190VO_V){ STEP06=3; return; }

        //  вес цемента из аспирации
        CRCEMA___V = AIW190___V - AIW190NV_V; AIW190FV_V=2;

        //  проверка стабилизации веса
        if (RegRUN==ON){ TMST_CAV_C++; }
        if (TMST_CAV_C>= TMST_CAV_W){
            if(AIW190___V-AIW190___O<VSST_CA__W){ AIW190___C++; }
            else                                { AIW190___C=0; }
            TMST_CAV_C=0;
            AIW190___O=AIW190___V;
        }

        //  если вес стабилизировался (нет прироста веса)- на следующий шаг
        if (AIW190___C>2){ STEP06=3; return; }
        return;
   }
   //------------------------------------------------------------------------


   // ДОЗИРОВКА ЦЕМЕНТА ИЗ БУНКЕРА
   //------------------------------------------------------------------------
   if ( STEP06 == 3 ){
        if(STEP06P!=3){
           // если набирали цемент из аспирации- запомнить вес
           if(AIW190FV_V==2){ CRCEMA___V=AIW190___V-AIW190NV_V; }
           KRCEM____F=0;               // флаг корректировки воды для цемента
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06off();
        }; STEP06P =3;
        if(RegRUN==OFF){ return; }
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        REG06SW__V = 30;

        //  выключить шнек аспирации цемента
        DON162___V = OFF;

        //  если дозировка цемента в ручном режиме
        if (DIR170___V == MANUAL){ STEP06 = 7; return; }

        //  если вес дозатора больше рецептного веса цемента минус
        //  вес допуска набора цемента- перейти на шаг 7
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-DPCEMS___V){ STEP06=7; return; }

        //  если не набрали вес до заданного ГРУБО
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  открыть клапан воздуха в бункер
           REG06SW__V = 31;
           DON171___V = ON;
           switch ( Check_TO  (61, TMKV_PDC_W*SEC, ZERO,'=',ON,  1 )){
               case RUN: { return;; }
           }
        }

        //  закрыть клапан воздуха в бункер
        DON171___V = OFF;
        Clear_TO(61);
        STEP06 =  4;
        return;
   }
   //------------------------------------------------------------------------

   // ОТКРЫТИЕ исполнителей набора цемента из бункера цемента
   //------------------------------------------------------------------------
   if ( STEP06 == 4 ){
        if(STEP06P!=4){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
        }; STEP06P =4;
        if(RegRUN==OFF){ return; }
        DONCM_FR_V=0;
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        //  открыть клапан дозировки цемента ТОЧНО
        REG06SW__V = 41;
        DON182___V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS182___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON182___V,3,TIME_ISPPW,70, 4, 61); return;;
                      }
            case END: { DONCN06=0; break;; }
        }

        // если текущий вес дозатора меньше рецептного веса цемента плюс вес
        // коррекции по вяжущему и минус вес отсечки ГРУБО
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  открыть клапан дозировки цемента ГРУБО
           REG06SW__V = 42;
           DON181___V = ON;
           switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS181___V,'=',ON,  1 )){
               case RUN: { return;; }
               case BAD: {
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; return;; 
                           }
                           Isp06PD(&DON181___V,3,TIME_ISPPW,70, 4, 62); return;;
                         }
               case END: { DONCN06=0; break;; }
           }
        }
        //  включить шнек дозировки цемента
        REG06SW__V = 43;
        DON180___V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS180___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON180___V,2,TIME_ISPPW,70, 4, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        if(AIW190___V<TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW){
           //  открыть клапан подачи цемента на шнек
           REG06SW__V = 44;
           DON172___V = ON;
           switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS172___V,'=',ON,  1 )){
               case RUN: { return;; }
               case BAD: {
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; return;; 
                           }
                           Isp06PD(&DON172___V,3,TIME_ISPPW,70, 4, 64); return;;
                         }
               case END: { DONCN06=0; break;; }
           }
        }
        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        STEP06 = 5;
        return;
   }
   //------------------------------------------------------------------------


   // ПРОВЕРКА НАБОРА ВЕСА ЦЕМЕНТА ИЗ БУНКЕРА
   //------------------------------------------------------------------------
   if ( STEP06 == 5 ){
        if(STEP06P!=5){
           AIW190___O=AIW190___V;      // запомнить текущий вес
           AIW190___C=0;               // счетчик циклов повторов
           TMVB_CB__C=0;               // счет врем провер веса включ вибрат
           TMVIBRUN=TIME_VCONW;        // задание времени работы вибр|возд
           TIME_VCONC=0;               // счет врем включ вибратора
           FLVB_ON=8;                  // флаг включения вибратора|воздуха
        }; STEP06P=5;
        REG06SW__V=50;
        CNST_CB__C=0;
        AIW190VO_V=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW;
        AIW190VZ_V=TRCEMS_VIB+KRVYGS___V;
        AIW190VB_V=TRCEMS_VIB+BLCEMS___V;

        //  если текущий вес больше общего заданного для набора цемента минус
        //  заданный вес отсечки ГРУБО- комм закрыт клапан подачи цем на шнек
        //  остановка шнека и закрытия клапана ГРУБО
        if( AIW190___V>=TRCEMS_VIB+KRVYGS___V-LOAD_CCGRW ){
            AIW190VO_V =TRCEMS_VIB+KRVYGS___V-VSOT_SSC_W;  // вес отсеч ШНЕКА
            if (DONCM_FR_V<1){
                DON172___V=OFF;
                DON180___V=ON;;
                DON181___V=OFF;
            }
        }

        //  если текущий вес больше общего заданного для набора цемента минус
        //  заданный вес выключения шнека- комманда  на выключение шнека
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-VSOT_SSC_W){
            AIW190VO_V =TRCEMS_VIB+KRVYGS___V-LOAD_CCTCW;  // вес отсеч ТОЧНО
            if (DONCM_FR_V<1){ DON180___V=OFF; }
        }

        //  если текущий вес больше общего заданного для набора цемента минус
        //  заданный вес отсечки ТОЧНО- комманд на закрытие клапана ТОЧНО
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-LOAD_CCTCW){
            DON172___V =OFF; DON180___V=OFF; DON181___V=OFF; DON182___V=OFF;
            STEP06=51; return;
        }

        //  отображение веса отсечки для оператора в таблице (с убыванием)
        if (DIS181___V==ON){ LOAD_CCGRC=TRCEMS_VIB+KRVYGS___V-AIW190___V; }
        if (DIS182___V==ON){ LOAD_CCTCC=TRCEMS_VIB+KRVYGS___V-AIW190___V; }

        //  вес цемента из бункера и общий
        CRCEMB___V=AIW190___V-CRCEMA___V-AIW190NV_V;
        CRCEMS___V=CRCEMA___V+CRCEMB___V;
        AIW190FV_V=5;

        //-------------------------------------------------------------------
        //  временные счетчики
        if (RegRUN==ON){
            // счетчик времени включения вибратора
            TIME_VCONC++;
            if(TIME_VCONC>= TMVIBRUN){
               // если включался воздух
               if(FLVB_ON==7){
                  DON173___V=OFF; DON172___V=ON; DON171___V=OFF;
                  FLVB_ON=8; TMVB_CB__C=0; AIW190___O=AIW190___V;
               }
               // если включался вибратор
               if(FLVB_ON==1){
                  DON173___V=OFF; DON171___V=OFF;
                  FLVB_ON=9; TMVB_CB__C=0; AIW190___O=AIW190___V;
               }
               // если включается воздух
               if(FLVB_ON==2){
                  if(BLCEMP___V==YES){ DON172___V=OFF; }
                  else               { DON172___V=ON;; }
                  DON173___V=OFF; 
                  DON171___V=ON;
                  FLVB_ON=7; TIME_VCONC=0;
               }
            }
            //  проверка веса для включения вибратора
            VSVB_CB__C=AIW190___V-AIW190___O;
            // счетчик времени проверки веса набора для включения вибратора
            TMVB_CB__C++;
            if (TMVB_CB__C>= TMVB_CB__W){
                // если запомненный вес + вес включения вибратора больше
                // текущего веса дозатора сухого (нет набора)
                if(AIW190___O+VSVB_CB__W>AIW190___V){
                   // если клапана набора закрыты- открыть клапана,
                   // обнулить счетчики и на начало шага (добрать со шнека)
                   if(DON171___V==OFF and  DON172___V==OFF and DON173___V==OFF){
                      DON180___V=ON;;
                      DON181___V=OFF;
                      DON182___V=ON;;
                      TMVB_CB__C=0;
                      AIW190___O=AIW190___V;  AIW190___C=0; DONCM_FR_V=2;
                      return;
                   }
                   // включить вибратор
                   if(FLVB_ON==8){
                      DON173___V=ON;; FLVB_ON=1; TIME_VCONC=0;
                      TMVIBRUN=TIME_VCONW;       // время вкл вибратора
                   }
                   // включить воздух
                   if(FLVB_ON==9){
                      if(BLCEMP___V==YES){ DON172___V=OFF; }
                      else               { DON172___V=ON;; }
                      FLVB_ON=2; 
                      TIME_VCONC=0;
                      TMVIBRUN=TMKV_RDC_W;       // время вкл воздуха
                   }
                   // увеличить счетчик ненабора веса
                   AIW190___C++;
                   REG06SW__V = 51;
                // если набор веса идет нормально- сбросить счетчик ненабора
                } else {
                   AIW190___C=0;
                }
                TMVB_CB__C=0;               // сбросить счет проверки веса
                AIW190___O=AIW190___V;      // запомнить текущий вес дозатора
            }
            //  если включена блокировка ненабора сухих и
            //  если после 5 циклов включения вибратора|воздуха нет прироста
            //  веса - закрыть все клапана дозировки и выключить регулятор
            if (BLNSUH___V==ON){
               if (AIW190___C>5){
                   DON171___V=OFF; DON173___V=OFF; DON172___V=OFF;
                   DON180___V=OFF; DON181___V=OFF; DON182___V=OFF;
                   REG06R___M=OFF; Message(146); Message(676); Bell(1); return;
               }
            }
        }
        //-------------------------------------------------------------------

        return;
   }
   //------------------------------------------------------------------------

   // ПРОВЕРКА ЗАКРЫТИЯ ИСПОЛНИТЕЛЕЙ набора цемента и
   // стабилизации веса набора цемента
   //------------------------------------------------------------------------
   if ( STEP06 == 51 ){
        if(STEP06P!=51){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           TMST_CBV_C =0;
           IS06ERR =0;
           AIW190___C=0;
        }; STEP06P =51;
        if(RegRUN==OFF){ return; }
        Regul_06off();

        //  проверка закрытия исполнителей дозировки цемента
        REG06SW__V = 52;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS182___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=4; DONCN06=0; break;; }
                        Isp06PD(&DON182___V,3,TIME_ISPPW,70, 51, 61); return;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS181___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=3; DONCN06=0; break;; }
                        Isp06PD(&DON181___V,3,TIME_ISPPW,70, 51, 62); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (63, TIME_ISPKV*SEC, DIS180___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=2; DONCN06=0; break;; }
                        Isp06PD(&DON180___V,3,TIME_ISPPW,70, 51, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS172___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: {
                        if(DONCN06>1){ IS06ERR=1; DONCN06=0; break;; }
                        Isp06PD(&DON172___V,3,TIME_ISPPW,70, 51, 64); return;;
                      }
            case END: { DONCN06=0; break;; }
        }

        //  ждать время стабилизации веса
        AIW190___O=AIW190___V;
        REG06SW__V = 53;
        switch ( Check_TO  (65, TMST_CBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_CBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);

        //  если после передергивания клапана дозировки не закр- выкл регулятор
        if(AIW190___C>1){
           AIW190___C=0; REG06R___M=OFF; Message(141); Message(676); Bell(1); 
           return; 
        }
        if(IS06ERR   >0){
           AIW190___C++; return;
        }

        //  если вес не стабилизировался после заданного кол-ва проверок-
        //  выключить регулятор
        if(CNST_CB__C>=CNST_CB__W){
           STEP06=0; REG06R___M=OFF; Message(144); Message(676); Bell(1); 
           return;
        }

        //  если нет стабилизации веса- проверить еще раз (ШАГ 51)
        if(AIW190___V+VSST_CB__W<AIW190___O){
           STEP06P=5; STEP06=51; CNST_CB__C++; return;
        } else {
           CNST_CB__C=0;
        }

        //  если текущий вес равен рецептному для набора цемента минус
        //  или плюс заданный вес допуска- перейти на следующий шаг
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V-DPCEMS___V or
            AIW190___V<=TRCEMS_VIB+KRVYGS___V+DPCEMS___V ){
            STEP06=6; return;
        }

        //  если текущий вес больше рецептного плюс вес допуска и
        //  меньше веса блокировки для набора цемента 
        if (AIW190___V>=TRCEMS_VIB+KRVYGS___V+DPCEMS___V and
            AIW190___V<=TRCEMS_VIB+KRVYGS___V+BLCEMS___V){
            // установить флаг корректировки воды для цемента
            KRCEM____F=1;
            // сообщение о корректировке воды, звонок и переход на след шаг
            Message(140); Bell(1); STEP06=6; return;
        }

        //  если текущий вес больше веса блокировки- выключить регулятор
        if (AIW190___V>TRCEMS_VIB+KRVYGS___V+BLCEMS___V){ 
            Message(376); Message(676); REG06R___M=OFF; return; 
        }
        return;
   }
   //------------------------------------------------------------------------


   //------------------------------------------------------------------------
   //  ПАУЗА МЕЖДУ НАБОРОМ КОМПОНЕНТОВ
   if ( STEP06 == 6 ){
        if(STEP06P!=6){
           TIME_CVPSC=0;
           Clear_TO(61);
        }; STEP06P =6;
        if (RegRUN==OFF){ return; }
        Regul_06off();
        DON801___V=0.2;
        //  Пауза между загрузкой цемента и вяжущего
        REG06SW__V = 60;
        switch ( Check_TO  (61, TIME_CVPSW*SEC, ZERO,'=',ON,  1 )){
            case RUN: { TIME_CVPSC++; return;; }
        };  Clear_TO(61);
        STEP06 = 7;
        return;
   }
   //------------------------------------------------------------------------



   // ДОЗИРОВКА ВЯЖУЩЕГО ИЗ АСПИРАЦИИ:
   //------------------------------------------------------------------------
   if ( STEP06 == 7 ){
       if(STEP06P!=7){
          // если перед этим была дозировка цемента- запомнить вес цемента
          if(AIW190FV_V==5){
             CRCEMB___V=AIW190___V-CRCEMA___V-AIW190NV_V;
             CRCEMS___V=CRCEMA___V+CRCEMB___V;
          }
          Regul_06off();
       }; STEP06P =7;
       if(RegRUN==OFF){ return; }
       KRVYG____F = 0;                 // сброс флага корректир воды для вяжущ
       REG06SW__V = 70;                // текущ подшаг регулятора

       //  если шнек дозатор вяжущего в руч режиме- перейти на набор из бункера
       if (DIR130___V == MANUAL){ STEP06= 9; return; }

       //  если рецептный вес вяжущего аспирации равен 0- перейти на шаг 9
       if (TRVYGA_VIB == 0){ STEP06= 9; return; }

       //  если вес дозатора больше рецептного веса вяжущего аспирации минус 
       //  вес допуска набора вяжущего аспирации- перейти на шаг 9
       if (AIW190___V>=TRCEMS_VIB+TRVYGA_VIB-DPVYGA___V){ 
           STEP06=9; return; 
       }

       //  вес вяжущего из аспирации
       CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
       AIW190FV_V=7;

       //  включить шнек аспирации вяжущего
       REG06SW__V = 71;
       DON132___V = ON;
       switch ( Check_TO  (61, TIME_ISPRV*SEC, DIS132___V,'=',ON,  1 )){
           case RUN: {  return;; }
           case BAD: { 
                        if(DONCN06>1){ break;; }
                        Isp06PD(&DON132___V,3,TIME_ISPPW,70, 7, 61); return;; 
                     }
       }; DONCN06=0;
       Clear_TO(61);
       STEP06=8;
       return;
   }
   //------------------------------------------------------------------------

   // ПРОВЕРКА набора веса вяжущего из аспирации вяжущего
   //------------------------------------------------------------------------
   if ( STEP06 == 8 ){
        if(STEP06P!=8){
           AIW190___O=AIW190___V;
           AIW190___C=0;
           TMST_VAV_C=0;
        }; STEP06P =8;
        AIW190VO_V =TRCEMS_VIB+TRVYGA_VIB-DPVYGA___V;
        AIW190VZ_V =TRCEMS_VIB+TRVYGA_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGA_VIB+BLVYGA___V;

        REG06SW__V = 80;
        //  если текущий вес больше рецептного для набора вяжущего аспирации
        //  минус вес допуска вяжущего аспирации- перейти на ШАГ 9
        if (AIW190___V>=AIW190VO_V){ STEP06=9; return; }

        //  вес вяжущего из аспирации
        CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
        AIW190FV_V=8;

        //  проверка стабилизации веса
        if (RegRUN==ON){ TMST_VAV_C++; }
        if (TMST_VAV_C>= TMST_VAV_W){
            if(AIW190___V-AIW190___O<VSST_VA__W){ AIW190___C++; }
            else                                { AIW190___C=0; }
            TMST_VAV_C=0;
            AIW190___O=AIW190___V;
        }

        //  если вес стабилизировался (нет прироста веса)- на следующий шаг
        if (AIW190___C>2){ STEP06=9; return; }
        return;
   }
   //------------------------------------------------------------------------


   //  ДОЗИРОВКА ВЯЖУЩЕГО ИЗ БУНКЕРА
   //------------------------------------------------------------------------
   if ( STEP06 == 9 ){
        if(STEP06P!=9){
           //  вес вяжущего из аспирации
           if(AIW190FV_V==8){
              CRVYGA___V=AIW190___V-CRCEMS___V-AIW190NV_V;
           }
           Clear_TO(61);
           Regul_06off();
        }; STEP06P =9;
        if(RegRUN==OFF){ return; }

        REG06SW__V = 90;

        //  выключить шнек аспирации вяжущего
        DON132___V = OFF; 

        //  если дозировка вяжущего в ручном режиме
        if (DIR140___V == MANUAL){ STEP06 = 15; return; }

        //  если вес дозатора больше рецептного веса вяжущего минус 
        //  вес допуска набора вяжущего- перейти на шаг 15
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-DPVYGS___V and
            AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW){ 
            STEP06= 15; return;
        }

        //  если не набрали вес до заданного ГРУБО
        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  открыть клапан воздуха в бункер вяжущего
           //  (подрыв перед началом дозировки)
           REG06SW__V = 91;
           DON141___V = ON;
           switch ( Check_TO  (61, TMKV_PDV_W*SEC, ZERO,'=',ON,  1 )){
               case RUN: { return;; }
           }
        }

        //  закрыть клапан воздуха в бункер вяжущего
        DON141___V = OFF;
        Clear_TO(61);
        STEP06 = 10;
        return;
   }
   //------------------------------------------------------------------------

   // ОТКРЫТИЕ исполнителей набора вяжущего из бункера вяжущего
   //------------------------------------------------------------------------
   if ( STEP06 ==10 ){
        if(STEP06P!=10){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
        }; STEP06P =10;
        if(RegRUN==OFF){ return; }
        DONVG_FR_V =0;
        AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW;
        AIW190VZ_V =TRCEMS_VIB+TRVYGS_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V;

        //  открыть клапана дозировки вяжущего ТОЧНО
        REG06SW__V = 101;
        DON152___V = ON;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS152___V,'=',ON,  2 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON152___V,3,TIME_ISPPW,70, 9, 61); return;; 
                      }
            case END: { DONCN06=0; break;; }
        }

        // если текущий вес дозатора меньше рецептного веса цемента плюс вес
        // коррекции по вяжущему и минус вес отсечки ГРУБО
        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  открыть клапана дозировки вяжущего ГРУБО
           REG06SW__V = 102;
           DON151___V = ON;
           switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS151___V,'=',ON,  2 )){
               case RUN: { return;; }
               case BAD: { 
                           if(DONCN06>2){ 
                              Message(670); Message(6767); REG06R___M=OFF; 
                              return;; 
                           }
                           Isp06PD(&DON151___V,3,TIME_ISPPW,70, 9, 62); return;; 
                         }
               case END: { DONCN06=0; break;; }
           }
        }

        //  включить шнек дозировки вяжущего
        REG06SW__V = 103;
        DON150___V = ON;
        switch ( Check_TO  (63, TIME_ISPRV*SEC, DIS150___V,'=',ON,  2 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>2){ 
                           Message(670); Message(676); REG06R___M=OFF; return;; 
                        }
                        Isp06PD(&DON150___V,3,TIME_ISPPW,70, 10, 63); return;; 
                      }
            case END: { DONCN06=0; break;; }
        }

        if(AIW190___V<TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
           //  открыть клапан подачи вяжущего на шнек
           REG06SW__V = 104;
           DON142___V = ON;
           switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS142___V,'=',ON,  2 )){
               case RUN: { return;; }
               case BAD: { 
                           if(DONCN06>2){ 
                              Message(670); Message(676); REG06R___M=OFF; 
                              return;; 
                           }
                           Isp06PD(&DON142___V,3,TIME_ISPPW,70, 10, 64); return;; 
                         }
               case END: { DONCN06=0; break;; }
           }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);

        STEP06 = 11;
        return;
   }
   //------------------------------------------------------------------------


   // ПРОВЕРКА НАБОРА ВЕСА ВЯЖУЩЕГО ИЗ БУНКЕРА:
   //------------------------------------------------------------------------
   if ( STEP06 == 11 ){
        if(STEP06P!=11){
           AIW190___O=AIW190___V;      // запомнить текущий вес
           AIW190___C=0;               // счетчик циклов повторов
           TMVB_VB__C=0;               // счет врем провер веса включ вибрат
           TIME_VVONC=0;               // счет врем включ вибратора
           FLVB_ON=8;                  // флаг включения вибратора|воздуха
        }; STEP06P=11;
        REG06SW__V = 110;
        CNST_VB__C = 0;

        AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW;
        AIW190VZ_V =TRCEMS_VIB+TRVYGS_VIB;
        AIW190VB_V =TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V;

        //  если текущий вес больше общего заданного для набора вяжущего минус
        //  заданный вес отсечки ГРУБО- комм закрыт клапан подачи вяжущ на шнек
        //  закрытия клапана ГРУБО
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGGRW){
            AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-VSOT_SSV_W;  // вес отсеч ШНЕКА
            if(DONVG_FR_V<1){
               DON142___V=OFF; 
               DON150___V=ON;;
               DON151___V=OFF;
            }
        }

        //  если текущий вес больше общего заданного для набора вяжущего минус
        //  заданный вес выключения шнека- комманда  на выключение шнека
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-VSOT_SSV_W){
            AIW190VO_V =TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW;  // вес отсеч ТОЧНО
            if(DONVG_FR_V<1){ DON150___V =OFF; }
        }

        //  если текущий вес больше общего заданного для набора вяжущего минус
        //  заданный вес отсечки ТОЧНО- комманд на закрытие клапана ТОЧНО
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-LOAD_VGTCW){
            DON142___V =OFF; DON150___V =OFF; DON151___V=OFF; DON152___V =OFF; 
            STEP06=12; return;
        }

        //  отображение веса при котором сработал клапан отсечки
        if (DIS151___V==ON){ LOAD_VGGRC=TRCEMS_VIB+TRVYGS_VIB-AIW190___V; }
        if (DIS152___V==ON){ LOAD_VGTCC=TRCEMS_VIB+TRVYGS_VIB-AIW190___V; }

        //  вес вяжущего из бункера
        CRVYGB___V=AIW190___V-CRCEMS___V-CRVYGA___V-AIW190NV_V;
        CRVYGS___V=CRVYGB___V+CRVYGA___V;
        AIW190FV_V=11;

        //-------------------------------------------------------------------
        //  временные счетчики
        if (RegRUN==ON){
            // счетчик времени включения вибратора
            TIME_VVONC++;
            if(TIME_VVONC>= TIME_VVONW){
               // если включался воздух
               if(FLVB_ON==7){ 
                  DON143___V=OFF; DON142___V=ON; DON141___V=OFF; 
                  FLVB_ON=8; TMVB_VB__C=0; AIW190___O=AIW190___V;
               }
               // если включался вибратор
               if(FLVB_ON==1){ 
                  DON143___V=OFF; DON141___V=OFF; 
                  FLVB_ON=9; TMVB_VB__C=0; AIW190___O=AIW190___V;
               }
               // если включается воздух
               if(FLVB_ON==2){ 
                     DON143___V=OFF; 
                     if(BLVYGP___V==YES){ DON142___V=OFF; }
                     else               { DON142___V=ON;  }
                     DON141___V=ON; 
                     FLVB_ON=7; TIME_VVONC=0; 
               }
            }
            //  проверка веса для включения вибратора
            VSVB_VB__C=AIW190___V-AIW190___O;
            // счетчик времени проверки веса набора для включения вибратора
            TMVB_VB__C++;
            if (TMVB_VB__C>= TMVB_VB__W){
                // если запомненный вес + вес включения вибратора больше
                // текущего веса дозатора (нет набора)
                if(AIW190___O+VSVB_VB__W>AIW190___V){ 
                   // если клапана набора закрыты- открыть клапана,
                   // обнулить счетчики и на начало шага (добрать со шнека)
                   if(DON141___V==OFF and  DON142___V==OFF and DON143___V==OFF){
                      DON150___V=ON;; 
                      DON151___V=OFF; 
                      DON152___V=ON;; 
                      TMVB_VB__C=0;
                      AIW190___O=AIW190___V;  AIW190___C=0; DONVG_FR_V=2;
                      return;
                   }
                   // включить вибратор
                   if(FLVB_ON==8){ 
                      DON143___V=ON;; 
                      FLVB_ON=1; 
                      TIME_VVONC=0; 
                   }
                   // включить воздух
                   if(FLVB_ON==9){ 
                      // если в настройках включено закрытие вяжущего на шнек
                      // при подрыве- комманда на закр клапана на шнек
                      if(BLVYGP___V==YES){ DON142___V=OFF; }
                      else               { DON142___V=ON;; }
                      FLVB_ON=2; 
                      TIME_VVONC=0; 
                   }
                   // увеличить счетчик ненабора веса
                   AIW190___C++;
                // если набор веса идет нормально- сбросить счетчик ненабора
                } else {
                   AIW190___C=0;
                }
                TMVB_VB__C=0;               // сбросить счет проверки веса
                AIW190___O=AIW190___V;      // запомнить текущий вес дозатора
            }
            //  если включена блокировка непоступления сухих и
            //  если после 5 циклов включения вибратора|воздуха нет прироста
            //  веса - закрыть все клапана дозировки и выключить регулятор
            if (BLNSUH___V==ON){
               if (AIW190___C>5){
                   DON141___V=OFF; DON143___V=OFF; DON142___V=OFF;
                   DON150___V=OFF; DON151___V=OFF; DON152___V=OFF;
                   REG06R___M=OFF; Message(147); Message(676); Bell(1); return;
               }
            }
        }
        //-------------------------------------------------------------------
        return;
   }
   //------------------------------------------------------------------------

   // ПРОВЕРКА закрытия исполнителей набора вяжущего из бункера вяжущего и
   // стабилизация веса набора вяжущего
   //------------------------------------------------------------------------
   if ( STEP06 == 12 ){
        if(STEP06P!=12){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           IS06ERR =0;
           TMST_VBV_C=0;
           AIW190___C=0;
           AIW190___O=AIW190___V;
        }; STEP06P =12;
        if(RegRUN==OFF){ return; }
        Regul_06off();

        //  вес вяжущего из бункера
        CRVYGB___V=AIW190___V-CRCEMS___V-CRVYGA___V-AIW190NV_V;
        CRVYGS___V=CRVYGB___V+CRVYGA___V;
        AIW190FV_V=12;

        //  проверка закрытия клапанов набора вяжущего
        REG06SW__V = 120;
        switch ( Check_TO  (61, TIME_ISPKV*SEC, DIS152___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=1; DONCN06=0; break;; }
                        Isp06PD(&DON152___V,3,TIME_ISPPW,70, 12, 61); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (62, TIME_ISPKV*SEC, DIS151___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=2; DONCN06=0; break;; }
                        Isp06PD(&DON151___V,3,TIME_ISPPW,70, 12, 62); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (63, TIME_ISPKV*SEC, DIS150___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=3; DONCN06=0; break;; }
                        Isp06PD(&DON150___V,3,TIME_ISPPW,70, 12, 63); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        switch ( Check_TO  (64, TIME_ISPKV*SEC, DIS142___V,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { 
                        if(DONCN06>1){ IS06ERR=4; DONCN06=0; break;; }
                        Isp06PD(&DON142___V,3,TIME_ISPPW,70, 12, 64); return;;
                      }
            case END: { DONCN06=0; break;; }
        }
        DONCN06=0;

        //  ждать время стабилизации веса
        REG06SW__V=121;
        AIW190___O=AIW190___V;
        switch ( Check_TO  (65, TMST_VBV_W*SEC, ZERO,'=',ON, 1)){
            case RUN: { TMST_VBV_C++; return;; }
            case BAD: { break;;  }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);

        //  после цикла загрузки обнулить коррекцию по вяжущему
        KRVYGS___M=0; KRVYGS___V=0;

        //  если вес не стабилизировался после заданного кол-ва проверок-
        //  выключить регулятор
        if(CNST_VB__C>=CNST_VB__W){
           Bell(1); Message(145); Message(676); 
           REG06R___M=OFF; STEP06=0; return;
        }

        //  если нет стабилизации веса- повторить проверку (ШАГ 12) еще раз
        if(AIW190___V+VSST_VB__W<AIW190___O){
           STEP06P=5; STEP06=12; CNST_VB__C++; return;
        } else {
           CNST_VB__C=0;
        }

        //  если после передергивания клапана дозировки не закр- выкл регулятор
        if(AIW190___C>1){ 
           AIW190___C=0; Bell(1); Message(142); Message(676);
           REG06R___M=OFF; return; 
        }
        if(IS06ERR   >0){ 
           AIW190___C++; return; 
        }

        //  если текущий вес равен рецептному для набора вяжущего минус
        //  или плюс заданный вес допуска- перейти на следующий шаг
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB-DPVYGS___V or
            AIW190___V<=TRCEMS_VIB+TRVYGS_VIB+DPVYGS___V ){
            STEP06=15; return;
        }

        //  если текущий вес больше рецептного плюс вес допуска и
        //  меньше веса блокировки для набора вяжущего 
        if (AIW190___V>=TRCEMS_VIB+TRVYGS_VIB+DPVYGS___V and
            AIW190___V<=TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V){
            // установить флаг запроса на корректировку воды для вяжущего
            KRVYG____F=1;
            // сообщение, звонок и переход на следующий шаг
            Message(143); Bell(1); STEP06=15; return;
        }

        //  если текущий вес больше веса блокировки- выключить регулятор
        if (AIW190___V>TRCEMS_VIB+TRVYGS_VIB+BLVYGS___V){ 
            Message(376); Message(676); REG06R___M=OFF; return; 
        }
        return;
   }
   //------------------------------------------------------------------------

   // ОКОНЧАНИЕ ЗАГРУЗКИ СУХОГО
   //------------------------------------------------------------------------
   if ( STEP06 == 15 ){
        if(STEP06P!=15){
           ;;
        }; STEP06P =15;
        AIW190VO_V =0;
        //  установить флаг загрузки сухого
        DON801___V =1;
        //  если регулятор в локальном режиме- выключить его
        if (REG06GL__V==OFF){
            Message(486); Message(676); REG06R___M= OFF;
        }
        //  перейти на шаг 0
        STEP06 =  0;
        return;
   }
   //------------------------------------------------------------------------



   //  ВЫГРУЗКА ИЗ ДОЗАТОРА СУХОГО
   //------------------------------------------------------------------------
   if ( STEP06 == 31 ){
        _f RUKAVA=OFF;
        if(STEP06P!=31){
           Regul_06off();              // комманда на закрытие всех клапанов
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Clear_TO(64);
           Clear_TO(65);
           Clear_TO(66);
        }; STEP06P =31;
        if(RegRUN==OFF){ return; }
        AIW190PVZV =AIW190___V;

        //  если ВГБМ нет на месте - выйти
        REG06SW__V =311;
        switch ( Check_TO  (61, 1*MIN, DIS315___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(61); Message(385); Bell(1); return;; }
        }

        //  если ВГБМ не включена - выйти
        REG06SW__V =312;
        switch ( Check_TO  (62, 1*MIN, DIS310___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(62); Message(386); Bell(1); return;; }
        }

        //  если герметизатор не опущен - выйти
        REG06SW__V =313;
        switch ( Check_TO  (63, 1*MIN, DIS31A___V,'=',ON,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(63); Message(387); Bell(1); return;; }
        }

        //  если рукава не закрыты - выйти
        REG06SW__V =314;
        if(DIS316___V==ON or DIS317___V==ON){ RUKAVA=ON; }
        switch ( Check_TO  (64, 1*MIN, RUKAVA,'=',OFF,  1 )){
            case RUN: { return;; }
            case BAD: { Clear_TO(64); Message(295); Bell(1); return;; }
        }

        //  дать комманду на включение вентилятора выгрузки
        REG06SW__V= 315;
        DON192___V= ON;
        switch ( Check_TO  (65, TIME_ISPKV*SEC, DIS192___V,'=',ON, 1 )){
            case RUN: { return;; }
        } 
        //  комманда на открытие клапана выгрузки
        REG06SW__V= 316;
        DON193___V= ON;
        switch ( Check_TO  (66, TIME_ISPKV*SEC, DIS193___V,'=',ON, 1 )){
            case RUN: { return;; }
        }
        //  вместе с открытием клапана сразу включить вибратор
        DON191___V= ON;
        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Clear_TO(64);
        Clear_TO(65);
        Clear_TO(66);

        CNT_VIGRUZ_S=0;

        STEP06 =  32;
        return;
   }
   //------------------------------------------------------------------------


   //  ПРОВЕРКА ВЕСА ВЫГРУЗКИ ДОЗАТОРА СУХОГО
   //------------------------------------------------------------------------
   if ( STEP06 == 32 ){
        if(STEP06P!=32){
           AIW190___O =AIW190___V;
           AIW190___S =AIW190___V;
           AIW190___C =0;
        }; STEP06P =32;
        REG06SW__V =320;
        AIW190VZ_V =0;
        AIW190VB_V =0;

        //  если запомненный вес минус текущий вес дозатора больше веса
        //  порции выгрузки- выключить вибратор и закрыть клапан выгрузки
        if( AIW190___O-AIW190___V>=LOAD_SVPVW){
            DON191___V=OFF; DON193___V=OFF;
        }
        //  ВЫГРУЗКА РЕЦЕПТА
        //  если текущий вес меньше веса отсечки выгрузки- 
        //  выключить вибратор и закрыть клапан  выгрузки 
        //  выгрузить рецептный вес
        if( VGR_SHRECV==ON){
            AIW190VO_V =AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB-VSOT_SHV_W);
            AIW190VZ_V =AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB);
            if(AIW190VO_V > AIW190___V){
               DON191___V=OFF; 
               DON193___V=OFF;
               Message(302);
               STEP06=33; 
               return;
            }
        }
        //  ВЫГРУЗКА ЛИШНЕГО ВЕСА (до рецепта)
        if( VGR_SHIZLV==ON){
            AIW190VO_V =AIW190PVZV-(AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB-VSOT_SHV_W));
            AIW190VZ_V =AIW190PVZV-(AIW190PVZV-(TRCEMS_VIB+TRVYGS_VIB));
            if(AIW190VO_V > AIW190___V){
               DON191___V=OFF; 
               DON193___V=OFF; 
               Message(303);
               STEP06=33; 
               return;
            }
        }
        //  для отображения оператору
        LOAD_SVPVC=AIW190___O-AIW190___V;

        if(RegRUN==OFF){ return; }

        //  если клапан закрыт: 
        if(DIS193___V==OFF){
           // выключить вибратор
           DON191___V = OFF;
           // считать время паузы
           switch ( Check_TO  (61, TIME_PONVW*SEC, ZERO,'=',ON, 1 )){
               case RUN: { TIME_PONVC++; return;; }
           };  Clear_TO(61);
           TIME_PONVC=0;
           // когда время паузы прошло:
           // запомнить текущий вес дозатора сухого
           AIW190___O = AIW190___V;
           // открыть клапан выгрузки
           DON193___V = ON;
           // вместе с клапаном включать вибратор
           DON191___V = ON; TIME_VIONC=0;
        }
        //  счетчик проверки стабилизации веса дозатора сухого при выгрузке
        TMST_VIS_C++;
        if (TMST_VIS_C>= TMST_VIS_W){
            // если запомненный вес дозатора минус текущий вес меньше
            // заданного веса стабилизации (вес дозатора не меняется
            // или меняется медленно)- включить вибратор(если открыт клапан)
            if(AIW190___V+VSST_VIS_W>AIW190___O){
               AIW190___C++;
            } else {
            // если вес меняется нормально- обнулить счетчик циклов проверки
               AIW190___C=0;
            }
            TMST_VIS_C=0;
            AIW190___O=AIW190___V;
        }
        // если после определенного кол-ва циклов проверки вес дозатора 
        // не уходит- след шаг
        if(AIW190___V<50){
           if(AIW190___C> CNST_VVS_W){ 
              DON193___V=OFF;  
              DON191___V=OFF; 
              STEP06=33; 
              return; 
           }
        }
        return;
   }
   //------------------------------------------------------------------------
   if ( STEP06 == 33 ){
        if(STEP06P!=33){
           Clear_TO(61);
           Clear_TO(62);
           Clear_TO(63);
           Regul_06off(); TIME_SHVVC=0;
           TMST_VIS_C=0;
        }; STEP06P =33;
        if(RegRUN==OFF){ return; }
        REG06SW__V =331;

        // флаг выгрузки дозатора
        DON801___V=2;

        // ожидание времени стабилизации после выгрузки
        switch ( Check_TO  (62, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
            case BAD: { AIW190___O=AIW190___V; break;; }
        }

        // ожидание времени стабилизации после выгрузки
        switch ( Check_TO  (62, TMST_VIS_W*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TMST_VIS_C++; return;; }
        }

        // проверка веса стабилизации выгрузки
        // если нет стабилизации (вес уходит)- перейти на шаг начала выгрузки
        if(AIW190___V+VSST_VIS_W<AIW190___O){
           Message(304);
        }

        // ожидание перед выключением вентилятора выгрузки сухого
        REG06SW__V =332;
        switch ( Check_TO  (63, TIME_SHVVW*SEC, ZERO,'=',ON, 1 )){
            case RUN: { TIME_SHVVC++; return;; }
        }

        Clear_TO(61);
        Clear_TO(62);
        Clear_TO(63);
        Regul_06off();

        //  если регулятор в локальном режиме- выключить регулятор
        if (REG06GL__V==OFF){ 
            Message(487); Message(676); REG06R___M=OFF; 
        }

        //  дозатор мокрого выгружается 1-ым, сухого 2-ым затем паста
        //  последний выключает цикл общего регулятора
        //  если регулятор пасты не включен для общей работы или
        //  выключен- выключить общий регулятор
        if (RegPublicV==ON and (REG09GL__V==OFF or REG09R___V==OFF)){ 
            RegPublicM =OFF; 
        }

        STEP06= 0;
        return;
   }
   //------------------------------------------------------------------------


   //-----------------------------------------------------------------------
   // ПЕРЕДЕРГИВАНИЕ КЛАПАНОВ
   //-----------------------------------------------------------------------
   if ( STEP06 ==70 ){
        if(STEP06P!=70){
           ;;
        }; STEP06P =70;
        if(DONCN06>=DONCH06){ STEP06 = STEP06_PRBK; return; }
        REG06SW__V =700;
        if(RegRUN==OFF){ return; }
        if(Check_TO(206, DONTM06*SEC, ZERO,'=',ON, 1 )==RUN){ return; }
           Clear_TO(206);
       *DONPR06=(*DONPR06!=ON)?ON:OFF;
        DONCN06++;
        STEP06 = STEP06_PRBK;
        return;
   }
   //-----------------------------------------------------------------------


   //------------------------------------------------------------------------
   // если задан несуществующий шаг регулятора - регулятор в ручной режим
   Regul_06m();
   return;
}
//---------------------------------------------------------------------------
