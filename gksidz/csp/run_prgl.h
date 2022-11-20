// #define  OFFICE     1
// #define  TESTVAGI   1
//---------------------------------------------------------------------------
#ifndef   OFFICE
  #define   COMU1      COM1         // номер порта для работы с УСО 1-ой группы
  #define   COMU2      COM2         // номер порта для работы с УСО 2-ой группы
  #define   COMWS      COM3         // номер порта для обмена с рабочей станц
#endif

#ifdef    OFFICE
  #define   COMWS      COM2         // номер порта для обмена с рабочей станц
  #ifndef TESTVAGI
    #define COMU2      0            // порт  не рабочий
    #define COMU1      COM1         // номер порта для работы с УСО 1-ой группы
  #else
    #define COMU1      0            // порт  не рабочий
    #define COMU2      COM1         // номер порта для работы с УСО 2-ой группы
  #endif
  ul  far   vg_cnt=0;               // номер текущего запроса
  ul  far   vg_erq=0;               // номер первого  ошибочного ответа
  ui  far   vg_flg=0;               // флаг обновления счета
  ui  far   vg_err=0;               // флаг ошибок тестирования прибора
#endif

#define   NUWS       0              // не использовать связь по COM порту
#define   USWS       1              // использовать ...

#define   DONLC      50             // пауза при приеме значения в переменную
#define   PAINP      18*5           // пауза для начала обработки AI сигналов
#define   PAMSG      18*8           // пауза для начала обработки сообщений
#define   PAMAX      18*10          // максимальное значение паузы
#define   WRITE_DAT_PERIOD  120     // период в минутах записи данных на флэш
//---------------------------------------------------------------------------
_i  far houC=0, minC=0, secC=0, yeaC=0, monC=0, dayC=0;
_i  far RunLocal=0;                     // флаг запуска программы в локал режиме
_i  far WriteFL=0;                      // флаг записи данных на диск
_f  far rpDC=0;                         // дата  компиляции
_f  far rpTC=0;                         // время компиляции
_i  far COM1HSMD_C=0;                   // счетчик циклов подсчета сост модулей
_i  far COM2HSMD_C=0;                   // счетчик циклов подсчета сост модулей
_i  far PCCSWork=0;                     // флаг работы контроллера
const ui far WDATP=(60*60*12);          // период  для автоматической записи данных
ui  far CDATP=0;                        // счетчик для переодической  записи данных
_i  far RegRUN=0;                       // флаг выполнения функций регуляторов
_f  far ZERO=0;                         // пустая переменная для временных циклов
_f  far CHANGE=0;                       // общая переменная выбора
//---------------------------------------------------------------------------
//  описание вызова функций
vd  far InpDataA(vd);
vd  far InpDataS(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far Signal  (vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far SetDefVL(vd);
vd  far InpDataD(vd);
vd  far CPInit(vd){ SYSTEMAF=1; return; }
//---------------------------------------------------------------------------
ex  vd  far  Regul_up(vd);
ex  vd  far  Regul_01(vd);
ex  vd  far  Regul_02(vd);
ex  vd  far  Regul_03(vd);
ex  vd  far  Regul_04(vd);
ex  vd  far  Regul_05(vd);
ex  vd  far  Regul_06(vd);
ex  vd  far  Regul_07(vd);
ex  vd  far  Regul_08(vd);
ex  vd  far  Regul_09(vd);
ex  vd  far  Regul_10(vd);
ex  vd  far  Regul_11(vd);
ex  vd  far  Regul_12(vd);
ex  vd  far  Regul_13(vd);
ex  vd  far  Regul_14(vd);
ex  vd  far  DebugVal(vd);
ex  vd  far  SetStepReg(vd);
ex  vd  far  SetVal(vd);
ex  vd  far  CheckIsp(vd);
ex  vd  far  DefRecept(vd);
ex  vd  far  Check_Regul_Manual(vd);
ex  vd  far  Reg_ZvMs(vd);
ex  vd  far  AutoManM(vd);
ex  vd  far  Meshalki(vd);
//---------------------------------------------------------------------------
//  флаги работы сети NetBIOS и по COM порту
_i  far NBLF=0;
_i  far CPLF=0;
//---------------------------------------------------------------------------
//  флаги сработки исполнителей
_f  far DIS011W =0;
_f  far DIS012W =0;
_f  far DIS021W =0;
_f  far DIS022W =0;
_f  far DIS032W =0;
_f  far DIS042W =0;
_f  far DIS052W =0;
_f  far DIS031W =0;
_f  far DIS041W =0;
_f  far DIS051W =0;
_f  far DIS061W =0;
_f  far DIS071W =0;
_f  far DIS081W =0;
_f  far DIS082W =0;
_f  far DIS111W =0;
_f  far DIS112W =0;
_f  far DIS121W =0;
_f  far DIS122W =0;
_f  far DIS101W =0;
_f  far DIS102W =0;
_f  far DIS131W =0;
_f  far DIS132W =0;
_f  far DIS141W =0;
_f  far DIS142W =0;
_f  far DIS143W =0;
_f  far DIS285W =0;
_f  far DIS286W =0;
_f  far DIS152W =0;
_f  far DIS161W =0;
_f  far DIS162W =0;
_f  far DIS171W =0;
_f  far DIS172W =0;
_f  far DIS173W =0;
_f  far DIS180W =0;
_f  far DIS181W =0;
_f  far DIS182W =0;
_f  far DIS191W =0;
_f  far DIS192W =0;
_f  far DIS193W =0;
_f  far DIS201W =0;
_f  far DIS202W =0;
_f  far DIS211W =0;
_f  far DIS212W =0;
_f  far DIS221W =0;
_f  far DIS222W =0;
_f  far DIS231W =0;
_f  far DIS232W =0;
_f  far DIS241W =0;
_f  far DIS250W =0;
_f  far DIS251W =0;
_f  far DIS252W =0;
_f  far DIS261W =0;
_f  far DIS271W =0;
_f  far DIS272W =0;
_f  far DIS274W =0;
_f  far DIS281W =0;
_f  far DIS291W =0;
_f  far DIS301W =0;
_f  far DIS311W =0;
_f  far DIS312W =0;
_f  far DIS313W =0;
_f  far DIS314W =0;
_f  far DIS316W =0;
_f  far DIS317W =0;
_f  far DIS31AW =0;
_f  far DIS203W =0;
_f  far DIS223W =0;
//---------------------------------------------------------------------------
//  шаги регуляторов
ex _i far STEP01, STEP02, STEP03, STEP04, STEP05;
ex _i far STEP06, STEP07, STEP08, STEP09, STEP10;
//---------------------------------------------------------------------------
//  выбранный рецепт загрузки
_i  far RECEPT_VIB = 1;
//---------------------------------------------------------------------------
_f  far DIL140___L=0;
_f  far DIH140___L=0;

_f  far DIL170___L=0;
_f  far DIH170___L=0;

_f  far DIL200___L=0;
_f  far DIM200___L=0;

_f  far DIL210___L=0;
_f  far DIH210___L=0;

_f  far DIL220___L=0;
_f  far DIH220___L=0;

_f  far DIL060___L=0;

_f  far DIL240___L=0;

_f  far DIL260___L=0;
_f  far DIH260___L=0;

_f  far DIL270___L=0;
_f  far DIH270___L=0;

_f  far DIL280___L=0;
_f  far DIH280___L=0;

_f  far DIL300___L=0;
_f  far DIH300___L=0;
//---------------------------------------------------------------------------