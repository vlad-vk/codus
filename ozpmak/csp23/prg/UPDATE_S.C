//----------------------------------------------------------------------------
//  Обновление значений каждую секунду
vd  far UpdDataS(vd){

    // послать данные на указанные контроллеры
    WS_UDP_SetSDat(); ptSetIP(&ptSND1,IPTOS1,1071);
    net_writeto(desSND1,504,no_block,ptBsnd,&ptSND1);
    WS_UDP_SetSDat(); ptSetIP(&ptSND2,IPTOS2,1075);
    net_writeto(desSND2,504,no_block,ptBsnd,&ptSND2);

    // проверка таймаутов посылок данных от других контроллеров
    if(WS_UDP_YesNoVFN(IPTOS1)<1) PCCS3T21_V++;
    else                          PCCS3T21_V=0;
    if(WS_UDP_YesNoVFN(IPTOS2)<1) PCCS3T25_V++;
    else                          PCCS3T25_V=0;
    if(PCCS3T21_V> 10000) PCCS3T21_V=0;
    if(PCCS3T25_V> 10000) PCCS3T25_V=0;

/*
    // проверка счетчика принятых пакетов от контроллера N20 (WS оператора)
    HNBWANS=WS_NB__YesNoVFN(20);
    // если были ответы от контроллера N20 увеличить счетчик ответов
    if(HNBWANS>0){ NBLiveT3_V=0; HNBWCNT++; if(HNBWCNT>10000) HNBWCNT=1; }
    else         { HNBWCNT   =0; }

    //-----------------------------------------------------------------------
    // Контроль обмена по сети NetBIOS
    if(HNBWCNT>0){
*/
       NBLive3__V++;  if(NBLive3__V>8){ NBLive3__V=1; }
/*
    }

    //-----------------------------------
    // Контроль обмена по сети COM порта
    if(HCOMANS>0){ HCOMANS=0; HCOMCNT++; CPLiveT3_V=0; }
    if(HCOMCNT>0){
       CPLive3__V++; if(CPLive3__V>8){ CPLive3__V=1; }
       HCOMCNT=0;
    } 

    //-----------------------------------
    // Увеличить счетчики таймаутов
    NBLiveT3_V++; if(NBLiveT3_V>10){ NBLiveT3_V=10; }
    CPLiveT3_V++; if(CPLiveT3_V>10){ CPLiveT3_V=10; }
*/
    // Установка переменной, отображающей работоспособность сети
    NetLive3_V++; if(NetLive3_V> 8){ NetLive3_V=0;  }
    NBStat=1; NBLiveT3_V=0; CPLiveT3_V=10;
    //-----------------------------------------------------------------------
    // флаг работы контроллера
    PCCS3WR__V = (PCCS3WR__V != OFF) then_ OFF else_ ON;
    PCCS4WR__V =  PCCS3WR__V;

    return;
}
//----------------------------------------------------------------------------
