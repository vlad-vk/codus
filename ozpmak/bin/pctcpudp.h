// The PCTCP interface  API for C  (Lite UDP only version)

//---------------------------------------------------------------------------
// Receive application buffer
extern struct
{
  uc Code;                 // 1
  //-------------------------------------------------------------------------
  union
  {
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=1)
      uc NData;            // 1  (How variables REQ)
      uc Const0;           // 1
      uc NReq;             // 1  (REQ number)
      uc Const1;           // 1
      uc Const2;           // 1
      ui ReqData[124];     // 2*124=248  (Channel numbers for REQ)
      ui ChNum  [124];     // 2*124=248
      uc Const3;           // 1
    } req;                 // 
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=2)
      uc NReq;             // 1
      ul Time;             // 4
      _f Data [C124];      // 4*124=496
      uc Const;            // 1
    } ans;                 //
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=7)
      uc Const0;           // 1
      ui NData;            // 2
      ui ChNum [C080];     // 2*80=160
      _f ChData[C080];     // 4*80=320
      uc Const3[19];       // 19
    } set;                 // 
    //-----------------------------------------------------------------------
    // ответ на запрос с номерами каналов
    struct
    {                      // (Code=27)
      uc Const0;           // 1
      ui NData;            // 2
      ui ChNum [80];       // 2*80=160
      _f ChData[80];       // 4*80=320
      uc Const3[18];       // 18         
      uc NReq;             // 1
    } anv;                 // 
    //-----------------------------------------------------------------------
  } u;
  uc  NWS;                 // Номер станции с которой послан пакет
  //-------------------------------------------------------------------------
} far WS_RD[MNCB+2];       // Всего: 504 байта = LNCB
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// 
extern struct
{
  uc Code;
  //-------------------------------------------------------------------------
  union
  {
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=1)
      uc NData;            // 1  (How variables REQ)
      uc Const0;           // 1
      uc NReq;             // 1  (REQ number)
      uc Const1;           // 1
      uc Const2;           // 1
      ui ReqData[124];     // 2*124=248  (Channel numbers for REQ)
      uc ChNum  [124];     // 2*124=248  
      uc Const3;           // 1
    } req;                 // 
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=2)
      uc NReq;             // 1
      ul Time;             // 4
      _f Data [C124];      // 4*124=496
      uc Const;            // 1         
    } ans;                 // 
    //-----------------------------------------------------------------------
    struct
    {                      // (Code=7)
      uc Const0;           // 1
      ui NData;            // 2
      ui ChNum [C080];     // 2*80=160
      _f ChData[C080];     // 4*80=320
      uc Const3[19];       // 19
    } set;                 // 
    //-----------------------------------------------------------------------
    // ответ на запрос с номерами каналов
    struct
    {                      // (Code=27)
      uc Const0;           // 1
      ui NData;            // 2
      ui ChNum [80];       // 2*80=160
      _f ChData[80];       // 4*80=320
      uc Const3[18];       // 18         
      uc NReq;             // 1
    } anv;                 // 
    //-----------------------------------------------------------------------
  } u;
  uc  NWS;                 // Номер станции с которой послан пакет
  //-------------------------------------------------------------------------
} far WS_SD[MNCB+2];       // Всего: 504 байта = LNCB
//---------------------------------------------------------------------------

// Constants for protocol type
#define  protocol_raw_net           1       //
#define  protocol_raw_ip            2       //
#define  protocol_datagram          3       // UDP protocol
#define  protocol_stream            4       // TCP protocol
#define  protocol_raw_icmp          5       //

// Constants for send options
#define  urgent                     1       // Signal urgent data on destenation
#define  rerout                     8       // Attempt rerouting on non-stream calls if first attempt fails
#define  push                       16      // send data with push flag (Nagle's algorithm is not overridden)
#define  no_trunc                   32      // abort send if datagram must be truncated
#define  no_block                   64      // abort send if call must be blocked
#define  broadcast                  128     //

// Constants for receive options
#define  no_remove                  2       // data is to be copied from the queue but not removed
#define  no_copy                    4       // data is to be removed from the queue but not copied
// #define  no_trunc                32      // abort if datagram needs to be truncated (same as send opt)
// #define  no_block                64      // abort if call must be blocked (same as send options)

struct UDP_connection_stats {
   uc  unused1[28];
   _l  packets_discarded;
   _l  packets_sent;
   _l  packets_received;
   _l  bad_checksums;
   _l  port_listening_errors;
   uc  unused2[4];
   _l  truncated_receives;
   uc  unused3[8];
} UDP_connection_stats;

// uc - 1byte(byte), ui - 2byte(word), ul - 4byte(dword), _l - longint;
struct ptIP{
   uc  a;
   uc  b;
   uc  c;
   uc  d;
} ptIP;

struct ptADDR {
   uc  ip[4];
   ui  rport;
   ui  lport;
   uc  proto;
} ptADDR;

uc tmpIP[4]={0,0,0,0};
uc stmIP[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uc sttIP[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ui IntNUM=0x61;
uc HostName[127];
_i ptErr=0, ptSubErr=0;
_i Descriptor=-1;
ui bWrit=0;
ui bRead=0;

//----------------------------------------------------------------------------
// Check for PCTCP installed on memory 
_i pctcp_installed(ui intN){
    char sig[6]={'T','C','P','T','S','R'}, smm[6];
    long drvvec=(long)getvect(intN);
    _fmemcpy(smm,MK_FP(FP_SEG(drvvec),FP_OFF(drvvec)+3),6);
    return !strncmp(smm,sig,6);
}
//----------------------------------------------------------------------------
// Get the internet address related to a descriptor
_i get_addr(ui des){
   union REGS regs;
   regs.h.ah = 0x5;
   regs.x.bx = des;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr = regs.x.ax; return 0; }
   ptIP.a=regs.h.al;
   ptIP.b=regs.h.ah;
   ptIP.c=regs.h.dl;
   ptIP.d=regs.h.dh;
   sprintf(sttIP,"%d.%d.%d.%d",ptIP.a,ptIP.b,ptIP.c,ptIP.d);
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Get network interface statistics
_i net_info(ui des, vd* r){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x6;
   regs.x.bx = des;
   sregs.ds  = FP_SEG(r);
   regs.x.si = FP_OFF(r);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Release a valid allocated network descriptor
_i net_release(ui des){
   union  REGS regs;
   regs.h.ah = 0x8;
   regs.x.bx = des;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Close all non-global descriptors (globals must be closed individualy)
_i net_releaseall(vd){
   union  REGS regs;
   regs.h.ah = 0x9;
   int86(IntNUM,&regs,&regs);
   return 1;
}
//----------------------------------------------------------------------------
// Get statistics of UDP connection
_i net_stat_UDP(vd* r){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0xc;
   regs.x.bx = 0xfffd;
   sregs.ds  = FP_SEG(r);
   regs.x.dx = FP_OFF(r);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Open a network connection with descriptor.  If the descriptor supplied
// is equal to 0xFFFF a descriptor is automatically allocated and returned
// in DESCRIPTOR after the connection is made.
_i net_connect(ui des,ui protocol,vd* addr_struct){
   struct ptADDR as;
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x13;
   regs.x.bx = des;
   regs.x.dx = protocol;
   sregs.ds  = FP_SEG(addr_struct);
   regs.x.si = FP_OFF(addr_struct);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return regs.x.ax;
}
//----------------------------------------------------------------------------
// Close transmition side of connection.  The connection remains open, but
// data can no longer be transmited onto the network, though data may still
// be read
_i net_eof(ui des){
   union  REGS regs;
   regs.x.bx = des;
   regs.h.ah = 0x18;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Imdediatley close a connection
_i net_abort(ui des){
   union  REGS regs;
   regs.x.bx = des;
   regs.h.ah = 0x19;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Write data to the network
_i net_write(ui des,ui size,ui send_options,uc* bufsnd){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x1a;
   regs.x.bx = des;
   regs.x.cx = size;
   regs.x.dx = send_options;
   sregs.ds  = FP_SEG(bufsnd);
   regs.x.si = FP_OFF(bufsnd);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; bWrit=0; return 0; }
   bWrit=regs.x.ax;  ptErr=0; return  1;
}
//----------------------------------------------------------------------------
// Read data from the network
_i net_read(ui des,ui size,ui receive_options,uc* bufrcv,vd* addr_struct){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x1b;
   regs.x.bx = des;
   regs.x.cx = size;
   regs.x.dx = receive_options;
   sregs.ds  = FP_SEG(bufrcv);
   regs.x.si = FP_OFF(bufrcv);
   sregs.es  = FP_SEG(addr_struct);
   regs.x.di = FP_OFF(addr_struct);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; bRead=0; return 0; }
   bRead=regs.x.ax;  ptErr=0;  return 1;
}
//----------------------------------------------------------------------------
// Write a datagram to the network
_i net_writeto(ui des,ui size,ui send_options,uc* bufsnd,vd* addr_struct){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x1c;
   regs.x.bx = des;
   regs.x.cx = size;
   regs.x.dx = send_options;
   sregs.ds  = FP_SEG(bufsnd);
   regs.x.si = FP_OFF(bufsnd);
   sregs.es  = FP_SEG(addr_struct);
   regs.x.di = FP_OFF(addr_struct);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; bWrit=0; return 0; }
   bWrit=regs.x.ax;  ptErr=0; return  1;
}
//----------------------------------------------------------------------------
// Read datagram from the network
// This function is for use with only datagram or raw descriptors
_i net_readfrom(ui des,ui size,ui receive_options,uc* bufrcv,vd* addr_struct){
   union  REGS   regs;
   struct SREGS sregs;
   segread(&sregs);
   regs.h.ah = 0x1d;
   regs.x.bx = des;
   regs.x.cx = size;
   regs.x.dx = receive_options;
   sregs.ds  = FP_SEG(bufrcv);
   regs.x.si = FP_OFF(bufrcv);
   sregs.es  = FP_SEG(addr_struct);
   regs.x.di = FP_OFF(addr_struct);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; bRead=0; return 0; }
   bRead=regs.x.ax;  ptErr=0; return  1;
}
//----------------------------------------------------------------------------
// Transmit all pending data imediatley
_i net_flush(ui des){
   union  REGS regs;
   regs.x.bx = des;
   regs.h.ah = 0x1e;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1;
}
//----------------------------------------------------------------------------
// Allocates a network descriptor
_i net_getdesc(vd){
   union REGS regs;
   regs.h.ah = 0x22;
   int86(IntNUM,&regs,&regs);
   if(regs.x.cflag){ ptErr = regs.x.ax; return 0; }
   Descriptor=regs.x.ax; ptErr=0; return Descriptor;
}
//----------------------------------------------------------------------------
// Listen for incomming connections
_i net_listen(ui des,ui service_type, void* addr_struct){
   union  REGS   regs;
   struct SREGS sregs;
   regs.h.ah = 0x23;
   regs.x.bx = des;
   regs.x.dx = service_type;
   sregs.ds  = FP_SEG(addr_struct);
   regs.x.si = FP_OFF(addr_struct);
   int86x(IntNUM,&regs,&regs,&sregs);
   if(regs.x.cflag){ ptErr=regs.x.ax; return 0; }
   ptErr=0; return 1; 
}
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//  This is private section. It will be write on user applications.

#define  ptBSZ    512
struct   ptADDR   ptUDPS;
uc       ptBsnd[ptBSZ];
uc       ptBrcv[ptBSZ];
//----------------------------------------------------------------------------
vd  ptSetIP(struct ptADDR * sADDR, uc* sIP, ui Port){
    ui  a=0,b=0,c=0;
    uc  s[4]={0,0,0,0};
    for(a=0,b=0;a<strlen(sIP);a++){ 
       if(sIP[a]=='.'){ sADDR->ip[b]=atoi(s); if(b<4)b++; c=0; continue; } 
       s[c]=sIP[a];  if(c<3){ c++; s[c]=0; }
    }; sADDR->ip[b]=atoi(s);
    sADDR->rport=Port;
}   
//----------------------------------------------------------------------------
vd  ptGetIP(vd){
    sprintf(sttIP,"%d.%d.%d.%d",(uc)ptUDPS.ip[0],(uc)ptUDPS.ip[1],(uc)ptUDPS.ip[2],(uc)ptUDPS.ip[3]);
}
//----------------------------------------------------------------------------
//  PCTCP API initialization
_i  ptInit(ui ListPort){
    int r=0;
    ptUDPS.lport = ListPort;
    ptUDPS.proto = protocol_datagram;
    for(r=0x60;r<0x80;r++) if(pctcp_installed(r)) break;
    if (r>=0x80) return 1; IntNUM=r;
    Descriptor=net_getdesc(); if(ptErr) return 2;
    net_listen(Descriptor,protocol_datagram,&ptUDPS); if(ptErr) return 3;
    get_addr(Descriptor); strcpy(stmIP,sttIP);
    return 0;
}
//----------------------------------------------------------------------------
//  PCTCP API release
vd  ptDel(vd){
    net_eof(Descriptor); net_releaseall();
}
//----------------------------------------------------------------------------
//  Network UDP exchange data part on slave (server) mode
vd  ptExchange(ui size, ui mode){
    if(size>ptBSZ)size=ptBSZ;
    if(mode=='r') net_read   (Descriptor,size,no_block,ptBrcv,&ptUDPS);
    if(mode=='s') net_writeto(Descriptor,size,no_block,ptBsnd,&ptUDPS);
}
//----------------------------------------------------------------------------
//  обмен данными по PCTCP UDP
vd  ptLocalExchange(vd){
    ptEX=1;
    ptExchange(504,'r');
    if(bRead>0){
       ptGetIP(); // Source address in sttIP
//printf(" %s ",sttIP);
       memcpy(&WS_RD[MNCB],&ptBrcv,504);
       memset(&ptBrcv,0,504);
    }
    // ответ на запрос значений
    if (WS_RD[MNCB].Code==1){
        if(WS_RD[MNCB].u.req.Const0== 0) WS_NB__Answer  (MNCB,MNCB);
        if(WS_RD[MNCB].u.req.Const0==27) WS_NB__Answer27(MNCB,MNCB);
        memcpy(&ptBsnd,&WS_SD[MNCB],504);
        memset(&WS_SD[MNCB],0,504);
        ptExchange(504,'s');
//printf(" A->S ");
    }
    // если принят код установки - меняем значения каналов в DBB[]
    if (WS_RD[MNCB].Code==7){ WS_NB__GetFromNet(MNCB); }
    ptEX=0;
}
//---------------------------------------------------------------------------
// Посылка данных на другие контроллеры
vd far WS_UDP_SetSDat(vd){
   _i  a=0,  b=0, n=0;
   // Очистить буфер и структуру посылки установок
   memset(&WS_SD[MNCB],0,504);
   // Установить код команды посылки данных
   WS_SD[MNCB].Code=7;
   for(a=0,b=0,HNBWREQ=0; a<C080; a++){
      if(DBC[a]>0&&DBN[a]>0&&DBN[a]<MAXDBB){
         // Установить номера каналов для посылки данных
         WS_SD[MNCB].u.set.ChNum [b]=DBN[a]; n=(ui)DBN[a];
         // Установить значение передаваемого канала
         WS_SD[MNCB].u.set.ChData[b]=DBB[n];
         // Кол-во запрашиваемых каналов
         HNBWREQ++; b++;
      }
   }
   // Установить кол-во запрашиваемых каналов
   WS_SD[MNCB].u.set.NData=HNBWREQ;
   // Переопределить номер для следующего запроса
   NNBWREQ++; if(NNBWREQ >250) NNBWREQ=1;
   // Последний байт- номер текущей станции
   WS_SD[MNCB].NWS=WS_NB_GetNWS();
   // Передать сформированную структуру в массив обмена по UDP
   memcpy (&ptBsnd,&WS_SD[MNCB],504);
   memset (&WS_SD[MNCB],0,504);
}
//--------------------------------------------------------------------------



//--------------------------------------------------------------------------
//  Контроль ответов от контроллеров
ui  far WSUDPHOW=0;          // текущий номер в списке контроллеров
uc  far WSUDPNUM[100][4];    // номера (адреса IP) проверяемых контроллеров
ui  far WSUDPCNT[100];       // значения счетчиков ответов от контроллеров
ui  far WSUDPPRV[100];       // предыдущие значения счетчиков 
_i  far WSUDPCUR=0;          // номер в списке проверяемого контроллера
//--------------------------------------------------------------------------
//  контроль адресов станций в принятых пакетах
vd  far WS_UDP_CheckNIP(vd){
    ui  i=0;
    uc  c[20], nws[4];
    // получить номер станции от которой пришел пакет
    memcpy(&nws,&ptUDPS.ip,4);
    for(i=0;i<WSUDPHOW;i++){
       // если станция с указанным номером в списке есть- изменить счетчик
       if(memicmp(&nws,&WSUDPNUM[i],4)==0){ 
          WSUDPCNT[i]++; if(WSUDPCNT[i]>10000) WSUDPCNT[i]=1; break; 
       }
    }
    // если номера станции в списке нет- добавить
    if(i>=WSUDPHOW){
       memcpy(WSUDPNUM[WSUDPHOW],nws,4); if(WSUDPHOW<99){ WSUDPHOW++; }
    }
}
//--------------------------------------------------------------------------
//  контроль счетчика приема пакетов от указанной рабочей станции
_i  far WS_UDP_CheckVFN(uc* IP){
    _i  a=0,b=0,i=0;
    uc  c[4];
    // IP адрес в 4е байта
    for(a=0;a<strlen(IP);a++){
        if(IP[a]=='.'){ c[b]=0; tmpIP[i]=(uc)atoi(c); if(i<3)i++; b=0; continue; } 
        c[b]=IP[a]; if(b<3)b++;
    };  tmpIP[i]=(uc)atoi(c);
    // если станция в списке есть- вернуть ее текущий счетчик
    for(a=0;a<WSUDPHOW;a++){ 
        if(memicmp(&tmpIP,WSUDPNUM[a],4)==0){ WSUDPCUR=a; return(WSUDPCNT[a]); }
    }
    // если нет- венуть ноль
    return(-1);
}
//--------------------------------------------------------------------------
//  запрос флага смены счетчика для указанного контроллера
//  Возврат: 0-от указанного контроллера ответов не было,1- были ответы
ui  far WS_UDP_YesNoVFN(uc* IP){
    ui  a =WS_UDP_CheckVFN(IP);
    if (a!=WSUDPPRV[WSUDPCUR]){ 
           WSUDPPRV[WSUDPCUR]=WSUDPCNT[WSUDPCUR]; return(1);
    }
    return(0);
}
//--------------------------------------------------------------------------
