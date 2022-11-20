// coding=cp866
//---------------------------------------------------------------------------
//  ������� ����
vd  far RepGen(vd){
    _i  a=0, b=0;
//  _f  t=0;

    if(CurDayWk_V!=CurDayWk_M){ CurDayWk_V=CurDayWk_M; }
    if(CurDayWk_V<0){ CurDayWk_V=0; }
    if(CurDayWk_V>6){ CurDayWk_V=6; }

    // ��� ������㥬��� ����
    GenDay___V=DBA[CurDayWk_V].dayC;
    GenMon___V=DBA[CurDayWk_V].monC;
    GenYear__V=DBA[CurDayWk_V].yeaC;

// printf("GenYear=[%f]\n",GenYear__V);

    // ��� ������� ��ࠬ����
    for(a=0;a<PARM;a++)
    {
        // ���㫨�� �㬬��� ���祭�� �� ᬥ�� � �� ��⪨
        for(b=0;b<RECL;b++){ DBB[ BEGP + RECL * a + b  ] = 0; }

        // ��� ������� �� (��� ������ �祩�� � �����)
        for(b=0;b<24;b++)
        {
            // ��������� ������ ��ࠬ��� � ���� ������� ���祭�ﬨ �� �������� DBA[]
            DBB[ BEGP + RECL * a + b ]=DBA[CurDayWk_V].pr[a].data[b];
            // �㬬��� ���祭�� �� 1� ᬥ��
            if(b>=0&&b< 8){
               DBB[ BEGP + RECL * a + 24 ] =
               DBB[ BEGP + RECL * a + 24 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // �㬬��� ���祭�� �� 2� ᬥ��
            if(b>=8&&b<16){
               DBB[ BEGP + RECL * a + 25 ] =
               DBB[ BEGP + RECL * a + 25 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // �㬬��� ���祭�� �� 3� ᬥ��
            if(b>=16&&b<24){
               DBB[ BEGP + RECL * a + 26 ] =
               DBB[ BEGP + RECL * a + 26 ] + DBA[CurDayWk_V].pr[a].data[b];
            }
            // �㬬�୮� ���祭�� �� ��⪨
               DBB[ BEGP + RECL * a + 27 ] =
               DBB[ BEGP + RECL * a + 27 ] + DBA[CurDayWk_V].pr[a].data[b];
        }

        // ��ࠡ���� �祩�� � �।���� ���祭�ﬨ

        // �� P(17,21),T(18,22)����, T(24-29)���� - �।��� ���祭�� (K1,K2)
        if(a==17||a==18||a==21||a==22||a>23){
           DBB[ BEGP + RECL * a + 24 ] = DBB[ BEGP + RECL * a + 24 ] / 8;  // 1 ᬥ��
           DBB[ BEGP + RECL * a + 25 ] = DBB[ BEGP + RECL * a + 25 ] / 8;  // 2 ᬥ��
           DBB[ BEGP + RECL * a + 26 ] = DBB[ BEGP + RECL * a + 26 ] / 8;  // 3 ᬥ��
           DBB[ BEGP + RECL * a + 27 ] = DBB[ BEGP + RECL * a + 27 ] /24;  // ��⪨
        }
        // ���� ⥯�� ��।������ �� ��4 � K2: AIX0C1HC_V(p12)=AIF332HC_V(p8)*(AIT332HC_V(p29)-AIT331HC_V(p28))
        if(a==12){
           DBB[ BEGP+RECL*12+24 ] = (DBB[ BEGP+RECL*8+24 ]*( DBB[ BEGP+RECL*29+24 ]-DBB[ BEGP+RECL*28+24 ] ))/1000;
           DBB[ BEGP+RECL*12+25 ] = (DBB[ BEGP+RECL*8+25 ]*( DBB[ BEGP+RECL*29+25 ]-DBB[ BEGP+RECL*28+25 ] ))/1000;
           DBB[ BEGP+RECL*12+26 ] = (DBB[ BEGP+RECL*8+26 ]*( DBB[ BEGP+RECL*29+26 ]-DBB[ BEGP+RECL*28+26 ] ))/1000;
           DBB[ BEGP+RECL*12+27 ] = (DBB[ BEGP+RECL*8+27 ]*( DBB[ BEGP+RECL*29+27 ]-DBB[ BEGP+RECL*28+27 ] ))/1000;
        }
        // ���� ⥯�� ��।������ �� ��4 � K1: AIQ4TP_HCV(p15)=AIF304HC_V(p6)*(AIT105HC_V(p26)-AIT104HC_V(p25))
        if(a==15){
           DBB[ BEGP+RECL*15+24 ] = (DBB[ BEGP+RECL*6+24 ]*( DBB[ BEGP+RECL*26+24 ]-DBB[ BEGP+RECL*25+24 ] ))/1000;
           DBB[ BEGP+RECL*15+25 ] = (DBB[ BEGP+RECL*6+25 ]*( DBB[ BEGP+RECL*26+25 ]-DBB[ BEGP+RECL*25+25 ] ))/1000;
           DBB[ BEGP+RECL*15+26 ] = (DBB[ BEGP+RECL*6+26 ]*( DBB[ BEGP+RECL*26+26 ]-DBB[ BEGP+RECL*25+26 ] ))/1000;
           DBB[ BEGP+RECL*15+27 ] = (DBB[ BEGP+RECL*6+27 ]*( DBB[ BEGP+RECL*26+27 ]-DBB[ BEGP+RECL*25+27 ] ))/1000;
        }
        // �� U(19) ���� - �।��� ���祭�� (K1)
        if(a==19){
//         printf("gas/(par*0.563)=%f\n", t);
//         printf("N=%d\n", BEGP + RECL * 19 + 24 );
           // �� ��।����� ���祭�� ��� DBB[1075]!? �㡫������ ��।�� �१ DBB[55]! �஢���� CODUS!!!
           DBB[55]=MDivF(DBB[ BEGP + RECL * 16 + 24 ],DBB[ BEGP + RECL * 0 + 24 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 24 ] = MDivF(DBB[ BEGP + RECL * 16 + 24 ],DBB[ BEGP + RECL * 0 + 24 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 25 ] = MDivF(DBB[ BEGP + RECL * 16 + 25 ],DBB[ BEGP + RECL * 0 + 25 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 26 ] = MDivF(DBB[ BEGP + RECL * 16 + 26 ],DBB[ BEGP + RECL * 0 + 26 ] * 0.563);
           DBB[ BEGP + RECL * 19 + 27 ] = MDivF(DBB[ BEGP + RECL * 16 + 27 ],DBB[ BEGP + RECL * 0 + 27 ] * 0.563);
           // �᫨ ���祭�� ��室� ��� ��� ���� �����쪨�- �� ����� 㤥��� ��室 ���� (��� ��᫠)
           if(DBB[ BEGP + RECL * 16 + 24 ]<10||DBB[ BEGP + RECL * 0 + 24 ]<0.2) DBB[ BEGP + RECL * 19 + 24 ]=0;
           if(DBB[ BEGP + RECL * 16 + 25 ]<10||DBB[ BEGP + RECL * 0 + 25 ]<0.2) DBB[ BEGP + RECL * 19 + 25 ]=0;
           if(DBB[ BEGP + RECL * 16 + 27 ]<10||DBB[ BEGP + RECL * 0 + 27 ]<0.2) DBB[ BEGP + RECL * 19 + 27 ]=0;
           if(DBB[ BEGP + RECL * 16 + 26 ]<10||DBB[ BEGP + RECL * 0 + 26 ]<0.2) DBB[ BEGP + RECL * 19 + 26 ]=0;
        }
        // �� U(23) ���� - �।��� ���祭�� (K2)
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
