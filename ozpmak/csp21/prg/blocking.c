//---------------------------------------------------------------------------
//  Проверка открытых исполнителей (задвижек)
//  переданный номер задвижки  num  не проверяется -
//  это исполнитель на который подается сигнал (проверяются все остальные)
_i  far check_isp_open(_i ak, _i num){
    if (ak == 1){
    //-----------------------------------------------------------------------
    //  проверка состояния задвижки впуска острого пара
    if (num!= 1){
        if (O1ZIOPO__M>OFF||O1ZIOPO__V>OFF||S1ZIOP___V>OFF) return(1);
    }
    //  проверка состояния задвижки впуска перепускного пара
    if (num!= 2){
        if (O1ZIPPO__M>OFF||O1ZIPPO__V>OFF||S1ZIPP___V>OFF) return(2);
    }
    //  проверка состояния задвижки выпуска перепускного пара
    if (num!= 3){
        if (O1ZOPPO__M>OFF||O1ZOPPO__V>OFF||S1ZOPP___V>OFF) return(3);
    }
    //  проверка состояния задвижки выпуска пара в атмосферу
    if (num!= 4){
        if (O1ZOPAO__M>OFF||O1ZOPAO__V>OFF||S1ZOPA___V>OFF) return(4);
    }
    //  проверка состояния вакуумной задвижки
    if (num!= 5){
        if (O1VZO____M>OFF||O1VZO____V>OFF||S1VZ_____V>OFF) return(5);
    }
    //  проверка состояния СБУ и байонета
        if(I1SBP1Z__V!=ON||I1SBP2Z__V!=ON||I1BY1C___V!=ON||I1BY2C___V!=ON)
        return(6);
    //  если все закрыто- вернуть 0
        return(0); 
    } 
    //-----------------------------------------------------------------------
    if (num!=11){
        if (O2ZIOPO__M>OFF||O2ZIOPO__V>OFF||S2ZIOP___V>OFF) return(11);
    }
    if (num!=12){
        if (O2ZIPPO__M>OFF||O2ZIPPO__V>OFF||S2ZIPP___V>OFF) return(12);
    }
    if (num!=13){
        if (O2ZOPPO__M>OFF||O2ZOPPO__V>OFF||S2ZOPP___V>OFF) return(13);
    }
    if (num!=14){
        if (O2ZOPAO__M>OFF||O2ZOPAO__V>OFF||S2ZOPA___V>OFF) return(14);
    }
    if (num!=15){
        if (O2VZO____M>OFF||O2VZO____V>OFF||S2VZ_____V>OFF) return(15);
    }
    //  проверка состояния СБУ и байонета
        if(I2SBP1Z__V!=ON||I2SBP2Z__V!=ON||I2BY1C___V!=ON||I2BY2C___V!=ON)
        return(6);
    //  если все закрыто- вернуть 0
        return(0); 
}
//---------------------------------------------------------------------------
//  Блокировки одновременного включения исполнителей
vd  far blocking(vd){
    int a=0;
    //-----------------------------------------------------------------------
    // АК 5
    // если выдан сигнал на открытие задвижки и открыта
    // хоть одна конкурирующая задвижка,СБУ или байонет - 
    // снять сигнал на открытиеи выдать соответствующее сообщение
    for(a=0;a<1;a++){
        if(O1ZIOPO__M>OFF and (O1ZIOPO__V==OFF and O1ZIOPC__V==OFF)){
           if((a=check_isp_open(5, 1))>0){
               O1ZIOPO__M=OFF; Message(A1BNM+100+a); break;
           }
        }
        if(O1ZIPPO__M>OFF and (O1ZIPPO__V==OFF and O1ZIPPC__V==OFF)){
           if((a=check_isp_open(5, 2))>0){
               O1ZIPPO__M=OFF; Message(A1BNM+100+a); break;
           }
        }
        if(O1ZOPPO__M>OFF and (O1ZOPPO__V==OFF and O1ZOPPC__V==OFF)){
           if((a=check_isp_open(5, 3))>0){
               O1ZOPPO__M=OFF; Message(A1BNM+100+a); break;
           }
        }
        if(O1ZOPAO__M>OFF and (O1ZOPAO__V==OFF and O1ZOPAC__V==OFF)){
           if((a=check_isp_open(5, 4))>0){ 
               O1ZOPAO__M=OFF; Message(A1BNM+100+a); break;
           }
        }
        if(O1VZO____M>OFF and (O1VZO____V==OFF and O1VZC____V==OFF)){
           if((a=check_isp_open(5, 5))>0){ 
               O1VZO____M=OFF; Message(A1BNM+100+a); break; 
           }
        }
    }
    //-----------------------------------------------------------------------
    for(a=0;a<1;a++){
        if(O2ZIOPO__M>OFF and (O2ZIOPO__V==OFF and O2ZIOPC__V==OFF)){
           if((a=check_isp_open(6,11))>0&&O2ZIOPO__M>OFF){ 
               O2ZIOPO__M=OFF; Message(A2BNM+100+a); break;
           }
        }
        if(O2ZIPPO__M>OFF and (O2ZIPPO__V==OFF and O2ZIPPC__V==OFF)){
           if((a=check_isp_open(6,12))>0&&O2ZIPPO__M>OFF){ 
               O2ZIPPO__M=OFF; Message(A2BNM+100+a); break;
           }
        }
        if(O2ZOPPO__M>OFF and (O2ZOPPO__V==OFF and O2ZOPPC__V==OFF)){
           if((a=check_isp_open(6,13))>0&&O2ZOPPO__M>OFF){ 
               O2ZOPPO__M=OFF; Message(A2BNM+100+a); break;
          }
        }
        if(O2ZOPAO__M>OFF and (O2ZOPAO__V==OFF and O2ZOPAC__V==OFF)){
           if((a=check_isp_open(6,14))>0&&O2ZOPAO__M>OFF){ 
               O2ZOPAO__M=OFF; Message(A2BNM+100+a); break;
           }
        }
        if(O2VZO____M>OFF and (O2VZO____V==OFF and O2VZC____V==OFF)){
           if((a=check_isp_open(6,15))>0&&O2VZO____M>OFF){ 
               O2VZO____M=OFF; Message(A2BNM+100+a); break;
           }
        }
    }
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------
