//----------------------------------------------------------------------------
//  Обновление значений каждую секунду
vd  far UpdDataS(vd){

    // послать данные на указанные контроллеры
    WS_UDP_SetSDat(); ptSetIP(&ptSND1,IPTOS1,1073);
    net_writeto(desSND1,504,no_block,ptBsnd,&ptSND1);
    WS_UDP_SetSDat(); ptSetIP(&ptSND2,IPTOS2,1075);
    net_writeto(desSND2,504,no_block,ptBsnd,&ptSND2);

    // проверка таймаутов посылок данных от других контроллеров
    if(WS_UDP_YesNoVFN(IPTOS1)<1) PCCS1T23_V++; 
    else                          PCCS1T23_V=0; 
    if(WS_UDP_YesNoVFN(IPTOS2)<1) PCCS1T25_V++; 
    else                          PCCS1T25_V=0; 
    if(PCCS1T23_V> 10000) PCCS1T23_V=0;
    if(PCCS1T25_V> 10000) PCCS1T25_V=0;

/*
    // проверка счетчика принятых пакетов от контроллера N20 (WS оператора)
    HNBWANS=WS_NB__YesNoVFN(20);
    // если были ответы от контроллера N20 увеличить счетчик ответов
    if(HNBWANS>0){ NBLiveT1_V=0; HNBWCNT++; if(HNBWCNT>10000) HNBWCNT=1; }
    else         { HNBWCNT   =0; }

    //-----------------------------------------------------------------------
    // Контроль обмена по сети NetBIOS
    if(HNBWCNT>0){
*/
        NBLive1__V++; if(NBLive1__V>8){ NBLive1__V=1; }
/*
    }

    //-----------------------------------
    // Контроль обмена по сети COM порта
    if(HCOMANS>0){ HCOMANS=0; HCOMCNT++; CPLiveT1_V=0; }
    if(HCOMCNT>0){
       CPLive1__V++; if(CPLive1__V>8){ CPLive1__V=1; }
       HCOMCNT=0;
    } 

    //-----------------------------------
    // Увеличить счетчики таймаутов
    NBLiveT1_V++; if(NBLiveT1_V>10){ NBLiveT1_V=10; }
    CPLiveT1_V++; if(CPLiveT1_V>10){ CPLiveT1_V=10; }
*/
    // Установка переменной, отображающей работоспособность сети
    NetLive1_V++; if(NetLive1_V> 8){ NetLive1_V=0;  }
    NBStat=1; NBLiveT1_V=0; CPLiveT1_V=10;

    //-----------------------------------------------------------------------
    // флаг работы контроллера
    PCCS1WR__V = (PCCS1WR__V != OFF) then_ OFF else_ ON;
    PCCS2WR__V =  PCCS1WR__V;

    return;
}
//----------------------------------------------------------------------------
