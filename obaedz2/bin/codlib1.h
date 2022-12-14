// coding: cp866
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <bios.h>
#include <conio.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <process.h>
#include <signal.h>
#include <setjmp.h>
#include <float.h>
#include <mem.h>
#include <alloc.h>
#include <math.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys\stat.h>
#include <dir.h>

//---------------------------------------------------------------------------
typedef unsigned        _u;
typedef unsigned char   uc;
typedef unsigned short  us;
typedef unsigned int    ui;
typedef unsigned long   ul;
typedef char            _c;
typedef short           _s;
typedef int             _i;
typedef long            _l;
typedef float           _f;
typedef double          db;
typedef void            vd;
typedef FILE            FL;
//
#define   ex            extern
// ?ࠢ?????
#define   NO            0
#define   YES           1
#define   OFF           0
#define   ON            1
#define   ASIS          2
#define   STOP          3
#define   MANUAL        0
#define   AUTO          1
#define   KVIT          1
#define   NOKV          0
#define   SWITCH        5
#define   REQ           11
#define   OTHER         3
#define   AND           &&
#define   and           &&
#define   OR            ||
#define   or            ||
#define   THEN_         ?
#define   then_         ?
#define   ELSE_         :
#define   else_         :
// ????稪?
#define   NOE           4         // ?? ????? ?६? ????? ?? ?⠡?????஢????
#define   NOS           3         // ???⠡??쭮? ??????? ࠡ????饣? ????稪?
#define   END           2         // ????稪 ?ࠡ?⠫ (???? ????????? ᨣ???)
#define   RUN           1         // ????稪 ??? ࠡ?⠥? (???? ???? ?६???)
#define   BAD           0         // ?? ????? ?६? ????? ?? ?ࠡ?? (??? ᨣ?)
#define   STY           1         // ????稪 "??饫????????" 
#define   STN           0         // ????稪 ࠡ?⠥? ?????ﭭ?
// ?६?
#define   VAG           0         // ???? ????訢???? (?????? BAD ??? ????稪?)
#define   SEC           1         // ?????⥫? ᥪ㭤
#define   MIN           60        // ?????⥫? ?????
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#define  NVMAX          50
//  ???ᨬ??쭮? ???-?? ??६?????  ??? ??।????? ???祭?? ???-?? ?㭪権
//  AISet(), ?.?.䠩?????᪨ ??? ???-?? AI ???????
//---------------------------------------------------------------------------
#define  CVMAX          30
//  ???ᨬ??쭮? ???-?? ?祥? ??? ???????? ?।???? ???祭?? ?? ??????
//  AI ??????
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  ANALOG         0
#define  IMPULS         1
//  ??? ????稪?? ??।?????
//---------------------------------------------------------------------------
#define  MAXAV          30
//  ???ᨬ??쭮? ???????⢮ ????稪?? ??।????? AAverRun()
//---------------------------------------------------------------------------
#define  MAXAA         (MAXAV*2)
//  ???? ???-?? ???祭?? ??।?????
#define  MAXCL          60                
//  ???? ???-?? ?祥? ? ???ᨢ?? ??।?????
#define  SMNHOW         5
//  ???? ???-?? ????????? ᬥ?
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#define  MBS            20
#define  MBA            10
//  ?????? ?????? ᮮ?饭??
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  MAXDBB         8000
#define  SIZDBB        32000    
//  ???ᨬ??쭮? ???????⢮ ??????⮢ ???ᨢ? ?????? SIZDBB=MAXDBB*4
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  MAXSTRE        79
//  ???ᨬ??쭠? ?????? ??ப? ??࠭?
#define  STRLN          255 
//  ???ᨬ??쭠? ?????? ??ப? ? 䠩???
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  LCMD           20
//  ???ᨬ??쭠? ?????? ???뫠???? ??ப? ????????
//---------------------------------------------------------------------------
#define  LANS           60
//  ???ᨬ??쭠? ?????? ?⢥??
//---------------------------------------------------------------------------
#define  MCF            40
//  ???ᨬ??쭮? ???????⢮ ????ᥩ ???㫥? ???
//---------------------------------------------------------------------------
#define  MVAL           14
//  ???ᨬ??쭮? ???????⢮ ??६????? ? ?⢥?? ?? ??????
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  ???ᨬ??쭮? ???????⢮ ???⮢ + 1
#define  MCOM           5
//---------------------------------------------------------------------------
#define  RBFSZ          512
//  ?????? ?????? ?⥭?? ?????? ?? COM ?????
//---------------------------------------------------------------------------
#define  NOU            0
#define  USO            1
#define  WST            2
//  ?ਧ??? ?????祭?? ????? (??? ?????? ? ??? ??? ࠡ?祩 ?⠭樥? (WST))
//---------------------------------------------------------------------------
#define  COM1     1
#define  COM2     2
#define  COM3     3
#define  COM4     4
//  ?????? COM ???⮢
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  MaxTT          20
//  ???ᨬ??쭮? ???-?? ⠩??஢ ?ணࠬ?? ???짮??⥫?
#define  MAXCNTTO       500
//  ???ᨬ??쭮? ???-?? ????稪?? ⠩?????
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  HFI            100
//  ???????⢮ ??????⮢ ???ᨢ? 䨫????樨 DI ᨣ?????
//---------------------------------------------------------------------------
#define  MDI            20
//  ???????⢮ ?祥? 䨫????樨 DI ᨣ????? ? ????? ????????
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  LNAM           16
//  ???????⢮ ᨬ????? ? ????? ?⠭樨 ??? NBW
//---------------------------------------------------------------------------
#define  HOWMAXWS       20
//  ???ᨬ??쭮? ???-?? ?⠭権 ??? ????஫? ????祭?? ??⠭???? ??????
//---------------------------------------------------------------------------
#define  MNCB           8
//  ???ᨬ??쭮? ???-?? NCB
//---------------------------------------------------------------------------
#define  LNCB           504
//  ?????? ???뫠????? NCB ? ??????
//---------------------------------------------------------------------------
#define  C250           250
#define  C124           124
#define  C080           80
#define  C020           20
#define  C002           2
//  ?????? ???ᨢ??
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  NREGUL         20
//  ???ᨬ??쭮? ???-?? ॣ?????஢ ? ?ணࠬ??
//---------------------------------------------------------------------------
#define  RNA           -1
#define  RMINUS         0
#define  RSTOP          1
#define  RPLUS          2
//  ???祭?? ??????⭮?? ??室? ॣ???????
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  u5648count 5
//  ???ᨬ??쭮? ???????⢮ ???? 5648
#define  BegC   0
#define  EndC   7
#define  BegA   8
#define  EndA  15
#define  BegB  16
#define  EndB  24
//  ??।?????? ????஢ ??????? ??? ???⮢
#define  pA 0
#define  pB 1
#define  pC 2
//  ???冷? ???⮢ Port A,B,C
//---------------------------------------------------------------------------
#define  u5700count 5
//  ???ᨬ??쭮? ???????⢮ ???? 5700
//---------------------------------------------------------------------------
#define  u5750count 5
//  ???ᨬ??쭮? ???????⢮ ???? 5750
//---------------------------------------------------------------------------
#define  TICKS_in_CYCLE    18
//  ???????⢮ ⨪?? ? 横??
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define  MINCKVAL   -10000
#define  MAXCKVAL    9000000000
//  ???????-???ᨬ?? ???祭?? ?஢?ન ?࠭?? ??६?????
//---------------------------------------------------------------------------
#define  MNOCHECK    10
//  ???????⢮ ??६????? ?? ?????????? ?஢?થ
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define   VAGSLEN     30
// ?????? ?⢥?? ?? ?????? ????
//---------------------------------------------------------------------------
#define   MAXHC       50
// ???ᨬ??쭮? ???????⢮ ???-????? ??????? ??? ?ਡ?஢ OWEN
//---------------------------------------------------------------------------
