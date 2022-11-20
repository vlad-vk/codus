//---------------------------------------------------------------------------
//  Проверка открытых исполнителей (задвижек)
//  переданный номер задвижки  num  не проверяется -
//  это исполнитель на который подается сигнал (проверяются все остальные)
_i  far check_isp_open(_i ak, _i num){
    //-----------------------------------------------------------------------
    if (ak==3){
    //  проверка состояния задвижки впуска острого пара
    if (num!= 1){
        if (O3ZIOPO__M>OFF||O3ZIOPO__V>OFF||S3ZIOP___V>OFF) return(1);
    }
    //  проверка состояния задвижки впуска перепускного пара
    if (num!= 2){
        if (O3ZIPPO__M>OFF||O3ZIPPO__V>OFF||S3ZIPP___V>OFF) return(2);
    }
    //  проверка состояния задвижки выпуска перепускного пара
    if (num!= 3){
        if (O3ZOPPO__M>OFF||O3ZOPPO__V>OFF||S3ZOPP___V>OFF) return(3);
    }
    //  проверка состояния задвижки выпуска пара в атмосферу
    if (num!= 4){
        if (O3ZOPAO__M>OFF||O3ZOPAO__V>OFF||S3ZOPA___V>OFF) return(4);
    }
    //  проверка состояния вакуумной задвижки
    if (num!= 5){
        if (O3VZO____M>OFF||O3VZO____V>OFF||S3VZ_____V>OFF) return(5);
    }
    //  проверка состояния СБУ и байонета
        if(I3SBP1Z__V!=ON ||I3BY1C___V!=ON )
        return(6);
    //  если все закрыто- вернуть 0
        return(0); 
    } 
    //-----------------------------------------------------------------------
    if (num!=11){
        if (O4ZIOPO__M>OFF||O4ZIOPO__V>OFF||S4ZIOP___V>OFF) return(11);
    }
    if (num!=12){
        if (O4ZIPPO__M>OFF||O4ZIPPO__V>OFF||S4ZIPP___V>OFF) return(12);
    }
    if (num!=13){
        if (O4ZOPPO__M>OFF||O4ZOPPO__V>OFF||S4ZOPP___V>OFF) return(13);
    }
    if (num!=14){
        if (O4ZOPAO__M>OFF||O4ZOPAO__V>OFF||S4ZOPA___V>OFF) return(14);
    }
    if (num!=15){
        if (O4VZO____M>OFF||O4VZO____V>OFF||S4VZ_____V>OFF) return(15);
    }
    //  проверка состояния СБУ и байонета
        if(I4SBP1Z__V!=ON ||I4BY1C___V!=ON )
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
    // хоть одна конкурирующая задвижка- снять сигнал на открытие
    // и выдать соответствующее сообщение
    for(a=0;a<1;a++){
        if(O3ZIOPO__M>OFF and (O3ZIOPO__V==OFF and O3ZIOPC__V==OFF)){
           if((a=check_isp_open(5, 1))>0){
               O3ZIOPO__M=OFF; Message(A3BNM+100+a); break;
           }
        }
        if(O3ZIPPO__M>OFF and (O3ZIPPO__V==OFF and O3ZIPPC__V==OFF)){
           if((a=check_isp_open(5, 2))>0){
               O3ZIPPO__M=OFF; Message(A3BNM+100+a); break;
           }
        }
        if(O3ZOPPO__M>OFF and (O3ZOPPO__V==OFF and O3ZOPPC__V==OFF)){
           if((a=check_isp_open(5, 3))>0){
               O3ZOPPO__M=OFF; Message(A3BNM+100+a); break;
           }
        }
        if(O3ZOPAO__M>OFF and (O3ZOPAO__V==OFF and O3ZOPAC__V==OFF)){
           if((a=check_isp_open(5, 4))>0){ 
               O3ZOPAO__M=OFF; Message(A3BNM+100+a); break;
           }
        }
        if(O3VZO____M>OFF and (O3VZO____V==OFF and O3VZC____V==OFF)){
           if((a=check_isp_open(5, 5))>0){ 
               O3VZO____M=OFF; Message(A3BNM+100+a); break; 
           }
        }
    }
    //-----------------------------------------------------------------------
    for(a=0;a<1;a++){
        if(O4ZIOPO__M>OFF and (O4ZIOPO__V==OFF and O4ZIOPC__V==OFF)){
           if((a=check_isp_open(6,11))>0&&O4ZIOPO__M>OFF){ 
               O4ZIOPO__M=OFF; Message(A4BNM+100+a); break;
           }
        }
        if(O4ZIPPO__M>OFF and (O4ZIPPO__V==OFF and O4ZIPPC__V==OFF)){
           if((a=check_isp_open(6,12))>0&&O4ZIPPO__M>OFF){ 
               O4ZIPPO__M=OFF; Message(A4BNM+100+a); break;
           }
        }
        if(O4ZOPPO__M>OFF and (O4ZOPPO__V==OFF and O4ZOPPC__V==OFF)){
           if((a=check_isp_open(6,13))>0&&O4ZOPPO__M>OFF){ 
               O4ZOPPO__M=OFF; Message(A4BNM+100+a); break;
          }
        }
        if(O4ZOPAO__M>OFF and (O4ZOPAO__V==OFF and O4ZOPAC__V==OFF)){
           if((a=check_isp_open(6,14))>0&&O4ZOPAO__M>OFF){ 
               O4ZOPAO__M=OFF; Message(A4BNM+100+a); break;
           }
        }
        if(O4VZO____M>OFF and (O4VZO____V==OFF and O4VZC____V==OFF)){
           if((a=check_isp_open(6,15))>0&&O4VZO____M>OFF){ 
               O4VZO____M=OFF; Message(A4BNM+100+a); break;
           }
        }
    }
    //-----------------------------------------------------------------------
    return;
}
//---------------------------------------------------------------------------
