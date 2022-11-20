//---------------------------------------------------------------------------
#define   COMWS      COM1           // номер порта для обмена с рабочей станц
#define   COMU1      COM2           // номер порта для работы с УСО 1-ой группы

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
const ui far WDATP=(60*30);             // период  для автоматической записи данных
ui  far CDATP=0;                        // счетчик для переодической  записи данных
_i  far RegRUN=0;                       // флаг выполнения функций регуляторов
_i  far NewSEC=0;                       // флаг новой секунды
_f  far ZERO=0;                         // пустая переменная для временных циклов
_f  far CHANGE=0;                       // общая переменная выбора
_f  far AITEMP=0;
_f  far A3NAKPPREM = 0;                 // N АК-передатчика пара при перепуске
_f  far A4NAKPPREM = 0;                 // N АК-передатчика пара при перепуске
ui  far UDP=0;                          // флаг работы по UDP
uc  far IPTOS1[20];                     // IP адрес 1го узла для посылки
uc  far IPTOS2[20];                     // IP адрес 2го узла для посылки
ui  far IPPORT=1234;
//---------------------------------------------------------------------------
//  описание вызова функций
vd  far blocking(vd);
vd  far InpDataA(vd);
vd  far InpDataS(vd);
vd  far UpdDataT(vd);
vd  far UpdDataS(vd);
vd  far L_Signal(vd);
vd  far OutDataA(vd);
vd  far OutDataD(vd);
vd  far SetDefVL(vd);
vd  far InpDataD(vd);
vd  far CPInit(vd){ SYSTEMAF=2; AUTHCNTZ=255; return; }
//---------------------------------------------------------------------------
ex  vd  far  Regul_up(vd);
ex  vd  far  Regul_03(vd);
ex  vd  far  Regul_04(vd);
ex  vd  far  Regul_3c(vd);
ex  vd  far  Regul_3p(vd);
ex  vd  far  Regul_3z(vd);
ex  vd  far  Regul_4c(vd);
ex  vd  far  Regul_4p(vd);
ex  vd  far  Regul_4z(vd);
ex  vd  far  DebugVal(vd);
ex  vd  far  Mod_AR  (vd);
ex  vd  far  Mod_BS  (vd);
ex  vd  far  SetVal(vd);
ex  vd  far  CheckIsp(vd);
ex  _i  far  Get_NetVal(_i);
ex  vd  far  NBW_SetValForReq(vd);
//---------------------------------------------------------------------------
//  флаги работы сети NetBIOS и по COM порту
_i  far HNBWANS=0;
_i  far HNBWCNT=0;
_i  far HCOMANS=0;
_i  far HCOMCNT=0;
//----------------------------------------------------------------------------


//  Переменные проверки сработки исполнителей
//----------------------------------------------------------------------------
_f  far I3ZIOPO__T=0;   // счетчик сработки концевика
_f  far I3ZIOPO__W=0;   // флаг стабильной сработки концевика
_f  far I3ZIOPO__C=0;   // счетчик времени ожидания сработки концевика
_f  far I3ZIOPO__E=0;   // флаг ошибки времени ожидания сработки концевика

_f  far I3ZIOPC__T=0;   _f  far I3ZIOPC__W=0;   
_f  far I3ZIOPC__C=0;   _f  far I3ZIOPC__E=0;
                                                                                             
_f  far I3ZIPPO__T=0;   _f  far I3ZIPPO__W=0;   
_f  far I3ZIPPO__C=0;   _f  far I3ZIPPO__E=0;
_f  far I3ZIPPC__T=0;   _f  far I3ZIPPC__W=0;   
_f  far I3ZIPPC__C=0;   _f  far I3ZIPPC__E=0;
                                                                                             
_f  far I3ZOPPO__T=0;   _f  far I3ZOPPO__W=0;   
_f  far I3ZOPPO__C=0;   _f  far I3ZOPPO__E=0;
_f  far I3ZOPPC__T=0;   _f  far I3ZOPPC__W=0;   
_f  far I3ZOPPC__C=0;   _f  far I3ZOPPC__E=0;
                                                                                             
_f  far I3ZOPAO__T=0;   _f  far I3ZOPAO__W=0;   
_f  far I3ZOPAO__C=0;   _f  far I3ZOPAO__E=0;
_f  far I3ZOPAC__T=0;   _f  far I3ZOPAC__W=0;   
_f  far I3ZOPAC__C=0;   _f  far I3ZOPAC__E=0;
                                                                                             
_f  far I3VZO____T=0;   _f  far I3VZO____W=0;   
_f  far I3VZO____C=0;   _f  far I3VZO____E=0;
_f  far I3VZC____T=0;   _f  far I3VZC____W=0;   
_f  far I3VZC____C=0;   _f  far I3VZC____E=0;
                                                                                             
_f  far I3KIPO___T=0;   _f  far I3KIPO___W=0;   
_f  far I3KIPO___C=0;   _f  far I3KIPO___E=0;
_f  far I3KIPC___T=0;   _f  far I3KIPC___W=0;   
_f  far I3KIPC___C=0;   _f  far I3KIPC___E=0;
                                                                                             
_f  far I3KOPO___T=0;   _f  far I3KOPO___W=0;   
_f  far I3KOPO___C=0;   _f  far I3KOPO___E=0;
_f  far I3KOPC___T=0;   _f  far I3KOPC___W=0;   
_f  far I3KOPC___C=0;   _f  far I3KOPC___E=0;
                                                                                             
_f  far I3KOCO___T=0;   _f  far I3KOCO___W=0;   
_f  far I3KOCO___C=0;   _f  far I3KOCO___E=0;
_f  far I3KOCC___T=0;   _f  far I3KOCC___W=0;   
_f  far I3KOCC___C=0;   _f  far I3KOCC___E=0;
                                                                                             
_f  far I3HM1UP__T=0;   _f  far I3HM1UP__W=0;   
_f  far I3HM1UP__C=0;   _f  far I3HM1UP__E=0;
_f  far I3HM1DN__T=0;   _f  far I3HM1DN__W=0;   
_f  far I3HM1DN__C=0;   _f  far I3HM1DN__E=0;
                                                                                             
_f  far I3KR1O___T=0;   _f  far I3KR1O___W=0;   
_f  far I3KR1O___C=0;   _f  far I3KR1O___E=0;
_f  far I3KR1C___T=0;   _f  far I3KR1C___W=0;   
_f  far I3KR1C___C=0;   _f  far I3KR1C___E=0;
                                                                                             
_f  far I3BY1O___T=0;   _f  far I3BY1O___W=0;   
_f  far I3BY1O___C=0;   _f  far I3BY1O___E=0;
_f  far I3BY1C___T=0;   _f  far I3BY1C___W=0;   
_f  far I3BY1C___C=0;   _f  far I3BY1C___E=0;
                                                                                             
_f  far I3HM2UP__T=0;   _f  far I3HM2UP__W=0;   
_f  far I3HM2UP__C=0;   _f  far I3HM2UP__E=0;
_f  far I3HM2DN__T=0;   _f  far I3HM2DN__W=0;   
_f  far I3HM2DN__C=0;   _f  far I3HM2DN__E=0;
                                                                                             
_f  far I3KR2O___T=0;   _f  far I3KR2O___W=0;   
_f  far I3KR2O___C=0;   _f  far I3KR2O___E=0;
_f  far I3KR2C___T=0;   _f  far I3KR2C___W=0;   
_f  far I3KR2C___C=0;   _f  far I3KR2C___E=0;
                                                                                             
_f  far I3BY2O___T=0;   _f  far I3BY2O___W=0;   
_f  far I3BY2O___C=0;   _f  far I3BY2O___E=0;
_f  far I3BY2C___T=0;   _f  far I3BY2C___W=0;   
_f  far I3BY2C___C=0;   _f  far I3BY2C___E=0;
                                                                                             
//-------------------------------------------
                                                                                             
_f  far I4ZIOPO__T=0;   _f  far I4ZIOPO__W=0;   
_f  far I4ZIOPO__C=0;   _f  far I4ZIOPO__E=0;
_f  far I4ZIOPC__T=0;   _f  far I4ZIOPC__W=0;   
_f  far I4ZIOPC__C=0;   _f  far I4ZIOPC__E=0;
                                                                                             
_f  far I4ZIPPO__T=0;   _f  far I4ZIPPO__W=0;   
_f  far I4ZIPPO__C=0;   _f  far I4ZIPPO__E=0;
_f  far I4ZIPPC__T=0;   _f  far I4ZIPPC__W=0;   
_f  far I4ZIPPC__C=0;   _f  far I4ZIPPC__E=0;
                                                                                             
_f  far I4ZOPPO__T=0;   _f  far I4ZOPPO__W=0;   
_f  far I4ZOPPO__C=0;   _f  far I4ZOPPO__E=0;
_f  far I4ZOPPC__T=0;   _f  far I4ZOPPC__W=0;   
_f  far I4ZOPPC__C=0;   _f  far I4ZOPPC__E=0;
                                                                                             
_f  far I4ZOPAO__T=0;   _f  far I4ZOPAO__W=0;   
_f  far I4ZOPAO__C=0;   _f  far I4ZOPAO__E=0;
_f  far I4ZOPAC__T=0;   _f  far I4ZOPAC__W=0;   
_f  far I4ZOPAC__C=0;   _f  far I4ZOPAC__E=0;
                                                                                             
_f  far I4VZO____T=0;   _f  far I4VZO____W=0;   
_f  far I4VZO____C=0;   _f  far I4VZO____E=0;
_f  far I4VZC____T=0;   _f  far I4VZC____W=0;   
_f  far I4VZC____C=0;   _f  far I4VZC____E=0;
                                                                                             
_f  far I4KIPO___T=0;   _f  far I4KIPO___W=0;   
_f  far I4KIPO___C=0;   _f  far I4KIPO___E=0;
_f  far I4KIPC___T=0;   _f  far I4KIPC___W=0;   
_f  far I4KIPC___C=0;   _f  far I4KIPC___E=0;
                                                                                             
_f  far I4KOPO___T=0;   _f  far I4KOPO___W=0;   
_f  far I4KOPO___C=0;   _f  far I4KOPO___E=0;
_f  far I4KOPC___T=0;   _f  far I4KOPC___W=0;   
_f  far I4KOPC___C=0;   _f  far I4KOPC___E=0;
                                                                                             
_f  far I4KOCO___T=0;   _f  far I4KOCO___W=0;   
_f  far I4KOCO___C=0;   _f  far I4KOCO___E=0;
_f  far I4KOCC___T=0;   _f  far I4KOCC___W=0;   
_f  far I4KOCC___C=0;   _f  far I4KOCC___E=0;
                                                                                             
_f  far I4HM1UP__T=0;   _f  far I4HM1UP__W=0;   
_f  far I4HM1UP__C=0;   _f  far I4HM1UP__E=0;
_f  far I4HM1DN__T=0;   _f  far I4HM1DN__W=0;   
_f  far I4HM1DN__C=0;   _f  far I4HM1DN__E=0;
                                                                                             
_f  far I4KR1O___T=0;   _f  far I4KR1O___W=0;   
_f  far I4KR1O___C=0;   _f  far I4KR1O___E=0;
_f  far I4KR1C___T=0;   _f  far I4KR1C___W=0;   
_f  far I4KR1C___C=0;   _f  far I4KR1C___E=0;
                                                                                             
_f  far I4BY1O___T=0;   _f  far I4BY1O___W=0;   
_f  far I4BY1O___C=0;   _f  far I4BY1O___E=0;
_f  far I4BY1C___T=0;   _f  far I4BY1C___W=0;   
_f  far I4BY1C___C=0;   _f  far I4BY1C___E=0;
                                                                                             
_f  far I4HM2UP__T=0;   _f  far I4HM2UP__W=0;   
_f  far I4HM2UP__C=0;   _f  far I4HM2UP__E=0;
_f  far I4HM2DN__T=0;   _f  far I4HM2DN__W=0;   
_f  far I4HM2DN__C=0;   _f  far I4HM2DN__E=0;
                                                                                             
_f  far I4KR2O___T=0;   _f  far I4KR2O___W=0;   
_f  far I4KR2O___C=0;   _f  far I4KR2O___E=0;
_f  far I4KR2C___T=0;   _f  far I4KR2C___W=0;   
_f  far I4KR2C___C=0;   _f  far I4KR2C___E=0;
                                                                                             
_f  far I4BY2O___T=0;   _f  far I4BY2O___W=0;   
_f  far I4BY2O___C=0;   _f  far I4BY2O___E=0;
_f  far I4BY2C___T=0;   _f  far I4BY2C___W=0;   
_f  far I4BY2C___C=0;   _f  far I4BY2C___E=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//  Флаги сигнализации
ui  far AIP34M3__S=0;
ui  far AIP34M4__S=0;
ui  far A3TTTB___S=0;
ui  far A4TTTB___S=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
_f  far AIPRP3___V=0;
_f  far AIPRP4___V=0;
//----------------------------------------------------------------------------
