// coding=cp866
//---------------------------------------------------------------------------
//  Генерация отчета
vd  far RepGen(vd){
    _i  a=0, b=0;
//  _f  t=0;

    if(CurDayWk_V!=CurDayWk_M){ CurDayWk_V=CurDayWk_M; }
    if(CurDayWk_V<0){ CurDayWk_V=0; }
    if(CurDayWk_V>6){ CurDayWk_V=6; }

    // дата генерируемого отчета
    GenDay___V=DBA[CurDayWk_V].dayC;
    GenMon___V=DBA[CurDayWk_V].monC;
    GenYear__V=DBA[CurDayWk_V].yeaC;

// printf("GenYear=[%f]\n",GenYear__V);

    // для каждого парамметра
    for(a=0;a<PARM;a++)
    {
        // обнулить суммарные значения за смены и за сутки
        for(b=0;b<RECL;b++){ DBB[ BEGP + RECL * a + b  ] = 0; }

        // для каждого часа (для каждой ячейки в записи)
        for(b=0;b<24;b++)
        {
            // Заполнить запись параметра в базе каналов значениями из структуры DBA[]
            DBB[ BEGP + RECL * a + b ]=DBA[CurDayWk_V].pr[a].data[b];
            // суммарные значения за 1ю смену
            if(b>=0&&b< 8){
               DBB[ BEGP + RECL * a + 24 ] =
               DBB[ BEGP + RECL * a + 24 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // суммарные значения за 2ю смену
            if(b>=8&&b<16){
               DBB[ BEGP + RECL * a + 25 ] =
               DBB[ BEGP + RECL * a + 25 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // суммарные значения за 3ю смену
            if(b>=16&&b<24){
               DBB[ BEGP + RECL * a + 26 ] =
               DBB[ BEGP + RECL * a + 26 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // суммарное значение за сутки
               DBB[ BEGP + RECL * a + 27 ] =
               DBB[ BEGP + RECL * a + 27 ] + DBA[CurDayWk_V].pr[a].data[b];
        }

        // обработать ячейки со средними значениями

        // по P(17,21),T(18,22)газа, T(24-29)воды - среднее значение (K1,K2)
        if(a==17||a==18||a==21||a==22||a>23){
           DBB[ BEGP + RECL * a + 24 ] = DBB[ BEGP + RECL * a + 24 ] / 8;  // 1 смена
           DBB[ BEGP + RECL * a + 25 ] = DBB[ BEGP + RECL * a + 25 ] / 8;  // 2 смена
           DBB[ BEGP + RECL * a + 26 ] = DBB[ BEGP + RECL * a + 26 ] / 8;  // 3 смена
           DBB[ BEGP + RECL * a + 27 ] = DBB[ BEGP + RECL * a + 27 ] /24;  // сутки
        }
        // расчет тепла переданного на ТП4 с K2: AIX0C1HC_V(p12)=AIF332HC_V(p8)*(AIT332HC_V(p29)-AIT331HC_V(p28))
        if(a==12){
           DBB[ BEGP+RECL*12+24 ] = (DBB[ BEGP+RECL*8+24 ]*( DBB[ BEGP+RECL*29+24 ]-DBB[ BEGP+RECL*28+24 ] ))/1000;
           DBB[ BEGP+RECL*12+25 ] = (DBB[ BEGP+RECL*8+25 ]*( DBB[ BEGP+RECL*29+25 ]-DBB[ BEGP+RECL*28+25 ] ))/1000;
           DBB[ BEGP+RECL*12+26 ] = (DBB[ BEGP+RECL*8+26 ]*( DBB[ BEGP+RECL*29+26 ]-DBB[ BEGP+RECL*28+26 ] ))/1000;
           DBB[ BEGP+RECL*12+27 ] = (DBB[ BEGP+RECL*8+27 ]*( DBB[ BEGP+RECL*29+27 ]-DBB[ BEGP+RECL*28+27 ] ))/1000;
        }
        // расчет тепла переданного на ТП4 с K1: AIQ4TP_HCV(p15)=AIF304HC_V(p6)*(AIT105HC_V(p26)-AIT104HC_V(p25))
        if(a==15){
           DBB[ BEGP+RECL*15+24 ] = (DBB[ BEGP+RECL*6+24 ]*( DBB[ BEGP+RECL*26+24 ]-DBB[ BEGP+RECL*25+24 ] ))/1000;
           DBB[ BEGP+RECL*15+25 ] = (DBB[ BEGP+RECL*6+25 ]*( DBB[ BEGP+RECL*26+25 ]-DBB[ BEGP+RECL*25+25 ] ))/1000;
           DBB[ BEGP+RECL*15+26 ] = (DBB[ BEGP+RECL*6+26 ]*( DBB[ BEGP+RECL*26+26 ]-DBB[ BEGP+RECL*25+26 ] ))/1000;
           DBB[ BEGP+RECL*15+27 ] = (DBB[ BEGP+RECL*6+27 ]*( DBB[ BEGP+RECL*26+27 ]-DBB[ BEGP+RECL*25+27 ] ))/1000;
        }
        // по U(19) газа - среднее значение (K1)
        if(a==19){
//         printf("gas/(par*0.563)=%f\n", t);
//         printf("N=%d\n", BEGP + RECL * 19 + 24 );
           // не передаются значения для DBB[1075]!? дублирующая передача через DBB[55]! проверить CODUS!!!
           DBB[55]=MDivF(DBB[ BEGP + RECL * 16 + 24 ],DBB[ BEGP + RECL * 0 + 24 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 24 ] = MDivF(DBB[ BEGP + RECL * 16 + 24 ],DBB[ BEGP + RECL * 0 + 24 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 25 ] = MDivF(DBB[ BEGP + RECL * 16 + 25 ],DBB[ BEGP + RECL * 0 + 25 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 26 ] = MDivF(DBB[ BEGP + RECL * 16 + 26 ],DBB[ BEGP + RECL * 0 + 26 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 27 ] = MDivF(DBB[ BEGP + RECL * 16 + 27 ],DBB[ BEGP + RECL * 0 + 27 ] * 0.563);
           // если значения расхода пара или газа маленькие- не считать удельный расход газа (нет смысла)
           if(DBB[ BEGP + RECL * 16 + 24 ]<10||DBB[ BEGP + RECL * 0 + 24 ]<0.2) DBB[ BEGP + RECL * 19 + 24 ]=0;
           if(DBB[ BEGP + RECL * 16 + 25 ]<10||DBB[ BEGP + RECL * 0 + 25 ]<0.2) DBB[ BEGP + RECL * 19 + 25 ]=0;
           if(DBB[ BEGP + RECL * 16 + 27 ]<10||DBB[ BEGP + RECL * 0 + 27 ]<0.2) DBB[ BEGP + RECL * 19 + 27 ]=0;
           if(DBB[ BEGP + RECL * 16 + 26 ]<10||DBB[ BEGP + RECL * 0 + 26 ]<0.2) DBB[ BEGP + RECL * 19 + 26 ]=0;
        }
        // по U(23) газа - среднее значение (K2)
        if(a==23){
           DBB[ BEGP + RECL * 23 + 24 ] = MDivF(DBB[ BEGP + RECL * 20 + 24 ],DBB[ BEGP + RECL * 2 + 24 ] * 0.563);
           DBB[ BEGP + RECL * 23 + 25 ] = MDivF(DBB[ BEGP + RECL * 20 + 25 ],DBB[ BEGP + RECL * 2 + 25 ] * 0.563);
           DBB[ BEGP + RECL * 23 + 26 ] = MDivF(DBB[ BEGP + RECL * 20 + 26 ],DBB[ BEGP + RECL * 2 + 26 ] * 0.563);
           DBB[ BEGP + RECL * 23 + 27 ] = MDivF(DBB[ BEGP + RECL * 20 + 27 ],DBB[ BEGP + RECL * 2 + 27 ] * 0.563);
           if(DBB[ BEGP + RECL * 20 + 24 ]<10||DBB[ BEGP + RECL * 2 + 24 ]<0.2) DBB[ BEGP + RECL * 23 + 24 ]=0;
           if(DBB[ BEGP + RECL * 20 + 25 ]<10||DBB[ BEGP + RECL * 2 + 25 ]<0.2) DBB[ BEGP + RECL * 23 + 25 ]=0;
           if(DBB[ BEGP + RECL * 20 + 26 ]<10||DBB[ BEGP + RECL * 2 + 26 ]<0.2) DBB[ BEGP + RECL * 23 + 26 ]=0;
           if(DBB[ BEGP + RECL * 20 + 27 ]<10||DBB[ BEGP + RECL * 2 + 27 ]<0.2) DBB[ BEGP + RECL * 23 + 27 ]=0;
        }
    }
    return;
}
//---------------------------------------------------------------------------
