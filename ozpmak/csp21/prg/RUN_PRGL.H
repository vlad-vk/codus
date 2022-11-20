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
_f  far A1NAKPPREM = 0;                 // N АК-передатчика пара при перепуске
_f  far A2NAKPPREM = 0;                 // N АК-передатчика пара при перепуске
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
ex  vd  far  Regul_01(vd);
ex  vd  far  Regul_02(vd);
ex  vd  far  Regul_1c(vd);
ex  vd  far  Regul_1p(vd);
ex  vd  far  Regul_1z(vd);
ex  vd  far  Regul_2c(vd);
ex  vd  far  Regul_2p(vd);
ex  vd  far  Regul_2z(vd);
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
_f  far I1ZIOPO__T=0;   // счетчик сработки концевика
_f  far I1ZIOPO__W=0;   // флаг стабильной сработки концевика
_f  far I1ZIOPO__C=0;   // счетчик времени ожидания сработки концевика
_f  far I1ZIOPO__E=0;   // флаг ошибки времени ожидания сработки концевика

_f  far I1ZIOPC__T=0;   _f  far I1ZIOPC__W=0;   
_f  far I1ZIOPC__C=0;   _f  far I1ZIOPC__E=0;
                                                                                             
_f  far I1ZIPPO__T=0;   _f  far I1ZIPPO__W=0;   
_f  far I1ZIPPO__C=0;   _f  far I1ZIPPO__E=0;
_f  far I1ZIPPC__T=0;   _f  far I1ZIPPC__W=0;   
_f  far I1ZIPPC__C=0;   _f  far I1ZIPPC__E=0;
                                                                                             
_f  far I1ZOPPO__T=0;   _f  far I1ZOPPO__W=0;   
_f  far I1ZOPPO__C=0;   _f  far I1ZOPPO__E=0;
_f  far I1ZOPPC__T=0;   _f  far I1ZOPPC__W=0;   
_f  far I1ZOPPC__C=0;   _f  far I1ZOPPC__E=0;
                                                                                             
_f  far I1ZOPAO__T=0;   _f  far I1ZOPAO__W=0;   
_f  far I1ZOPAO__C=0;   _f  far I1ZOPAO__E=0;
_f  far I1ZOPAC__T=0;   _f  far I1ZOPAC__W=0;   
_f  far I1ZOPAC__C=0;   _f  far I1ZOPAC__E=0;
                                                                                             
_f  far I1VZO____T=0;   _f  far I1VZO____W=0;   
_f  far I1VZO____C=0;   _f  far I1VZO____E=0;
_f  far I1VZC____T=0;   _f  far I1VZC____W=0;   
_f  far I1VZC____C=0;   _f  far I1VZC____E=0;
                                                                                             
_f  far I1KIPO___T=0;   _f  far I1KIPO___W=0;   
_f  far I1KIPO___C=0;   _f  far I1KIPO___E=0;
_f  far I1KIPC___T=0;   _f  far I1KIPC___W=0;   
_f  far I1KIPC___C=0;   _f  far I1KIPC___E=0;
                                                                                             
_f  far I1KOPO___T=0;   _f  far I1KOPO___W=0;   
_f  far I1KOPO___C=0;   _f  far I1KOPO___E=0;
_f  far I1KOPC___T=0;   _f  far I1KOPC___W=0;   
_f  far I1KOPC___C=0;   _f  far I1KOPC___E=0;
                                                                                             
_f  far I1KOCO___T=0;   _f  far I1KOCO___W=0;   
_f  far I1KOCO___C=0;   _f  far I1KOCO___E=0;
_f  far I1KOCC___T=0;   _f  far I1KOCC___W=0;   
_f  far I1KOCC___C=0;   _f  far I1KOCC___E=0;
                                                                                             
_f  far I1HM1UP__T=0;   _f  far I1HM1UP__W=0;   
_f  far I1HM1UP__C=0;   _f  far I1HM1UP__E=0;
_f  far I1HM1DN__T=0;   _f  far I1HM1DN__W=0;   
_f  far I1HM1DN__C=0;   _f  far I1HM1DN__E=0;
                                                                                             
_f  far I1KR1O___T=0;   _f  far I1KR1O___W=0;   
_f  far I1KR1O___C=0;   _f  far I1KR1O___E=0;
_f  far I1KR1C___T=0;   _f  far I1KR1C___W=0;   
_f  far I1KR1C___C=0;   _f  far I1KR1C___E=0;
                                                                                             
_f  far I1BY1O___T=0;   _f  far I1BY1O___W=0;   
_f  far I1BY1O___C=0;   _f  far I1BY1O___E=0;
_f  far I1BY1C___T=0;   _f  far I1BY1C___W=0;   
_f  far I1BY1C___C=0;   _f  far I1BY1C___E=0;
                                                                                             
_f  far I1HM2UP__T=0;   _f  far I1HM2UP__W=0;   
_f  far I1HM2UP__C=0;   _f  far I1HM2UP__E=0;
_f  far I1HM2DN__T=0;   _f  far I1HM2DN__W=0;   
_f  far I1HM2DN__C=0;   _f  far I1HM2DN__E=0;
                                                                                             
_f  far I1KR2O___T=0;   _f  far I1KR2O___W=0;   
_f  far I1KR2O___C=0;   _f  far I1KR2O___E=0;
_f  far I1KR2C___T=0;   _f  far I1KR2C___W=0;   
_f  far I1KR2C___C=0;   _f  far I1KR2C___E=0;
                                                                                             
_f  far I1BY2O___T=0;   _f  far I1BY2O___W=0;   
_f  far I1BY2O___C=0;   _f  far I1BY2O___E=0;
_f  far I1BY2C___T=0;   _f  far I1BY2C___W=0;   
_f  far I1BY2C___C=0;   _f  far I1BY2C___E=0;
                                                                                             
//-------------------------------------------
                                                                                             
_f  far I2ZIOPO__T=0;   _f  far I2ZIOPO__W=0;   
_f  far I2ZIOPO__C=0;   _f  far I2ZIOPO__E=0;
_f  far I2ZIOPC__T=0;   _f  far I2ZIOPC__W=0;   
_f  far I2ZIOPC__C=0;   _f  far I2ZIOPC__E=0;
                                                                                             
_f  far I2ZIPPO__T=0;   _f  far I2ZIPPO__W=0;   
_f  far I2ZIPPO__C=0;   _f  far I2ZIPPO__E=0;
_f  far I2ZIPPC__T=0;   _f  far I2ZIPPC__W=0;   
_f  far I2ZIPPC__C=0;   _f  far I2ZIPPC__E=0;
                                                                                             
_f  far I2ZOPPO__T=0;   _f  far I2ZOPPO__W=0;   
_f  far I2ZOPPO__C=0;   _f  far I2ZOPPO__E=0;
_f  far I2ZOPPC__T=0;   _f  far I2ZOPPC__W=0;   
_f  far I2ZOPPC__C=0;   _f  far I2ZOPPC__E=0;
                                                                                             
_f  far I2ZOPAO__T=0;   _f  far I2ZOPAO__W=0;   
_f  far I2ZOPAO__C=0;   _f  far I2ZOPAO__E=0;
_f  far I2ZOPAC__T=0;   _f  far I2ZOPAC__W=0;   
_f  far I2ZOPAC__C=0;   _f  far I2ZOPAC__E=0;
                                                                                             
_f  far I2VZO____T=0;   _f  far I2VZO____W=0;   
_f  far I2VZO____C=0;   _f  far I2VZO____E=0;
_f  far I2VZC____T=0;   _f  far I2VZC____W=0;   
_f  far I2VZC____C=0;   _f  far I2VZC____E=0;
                                                                                             
_f  far I2KIPO___T=0;   _f  far I2KIPO___W=0;   
_f  far I2KIPO___C=0;   _f  far I2KIPO___E=0;
_f  far I2KIPC___T=0;   _f  far I2KIPC___W=0;   
_f  far I2KIPC___C=0;   _f  far I2KIPC___E=0;
                                                                                             
_f  far I2KOPO___T=0;   _f  far I2KOPO___W=0;   
_f  far I2KOPO___C=0;   _f  far I2KOPO___E=0;
_f  far I2KOPC___T=0;   _f  far I2KOPC___W=0;   
_f  far I2KOPC___C=0;   _f  far I2KOPC___E=0;
                                                                                             
_f  far I2KOCO___T=0;   _f  far I2KOCO___W=0;   
_f  far I2KOCO___C=0;   _f  far I2KOCO___E=0;
_f  far I2KOCC___T=0;   _f  far I2KOCC___W=0;   
_f  far I2KOCC___C=0;   _f  far I2KOCC___E=0;
                                                                                             
_f  far I2HM1UP__T=0;   _f  far I2HM1UP__W=0;   
_f  far I2HM1UP__C=0;   _f  far I2HM1UP__E=0;
_f  far I2HM1DN__T=0;   _f  far I2HM1DN__W=0;   
_f  far I2HM1DN__C=0;   _f  far I2HM1DN__E=0;
                                                                                             
_f  far I2KR1O___T=0;   _f  far I2KR1O___W=0;   
_f  far I2KR1O___C=0;   _f  far I2KR1O___E=0;
_f  far I2KR1C___T=0;   _f  far I2KR1C___W=0;   
_f  far I2KR1C___C=0;   _f  far I2KR1C___E=0;
                                                                                             
_f  far I2BY1O___T=0;   _f  far I2BY1O___W=0;   
_f  far I2BY1O___C=0;   _f  far I2BY1O___E=0;
_f  far I2BY1C___T=0;   _f  far I2BY1C___W=0;   
_f  far I2BY1C___C=0;   _f  far I2BY1C___E=0;
                                                                                             
_f  far I2HM2UP__T=0;   _f  far I2HM2UP__W=0;   
_f  far I2HM2UP__C=0;   _f  far I2HM2UP__E=0;
_f  far I2HM2DN__T=0;   _f  far I2HM2DN__W=0;   
_f  far I2HM2DN__C=0;   _f  far I2HM2DN__E=0;
                                                                                             
_f  far I2KR2O___T=0;   _f  far I2KR2O___W=0;   
_f  far I2KR2O___C=0;   _f  far I2KR2O___E=0;
_f  far I2KR2C___T=0;   _f  far I2KR2C___W=0;   
_f  far I2KR2C___C=0;   _f  far I2KR2C___E=0;
                                                                                             
_f  far I2BY2O___T=0;   _f  far I2BY2O___W=0;   
_f  far I2BY2O___C=0;   _f  far I2BY2O___E=0;
_f  far I2BY2C___T=0;   _f  far I2BY2C___W=0;   
_f  far I2BY2C___C=0;   _f  far I2BY2C___E=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//  Флаги сигнализации
ui  far AIP12M1__S=0;
ui  far AIP12M2__S=0;
ui  far A1TTTB___S=0;
ui  far A2TTTB___S=0;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
_f  far AIPRP1___V=0;
_f  far AIPRP2___V=0;
//----------------------------------------------------------------------------
