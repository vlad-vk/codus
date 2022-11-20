//---------------------------------------------------------------------------
// Продувки

#define  HEMPR  8             // кол-во емкостей для продувок

_f far DONPBM3__F=0;          // Флаг продувки
_f far csBM3     =0;          // Заданное значение времени продувки
_f far DONPBM6__F=0;
_f far csBM6     =0;
_f far DONPHDF__F=0;
_f far csHDF     =0;
_f far DONPGDF__F=0;
_f far csGDF     =0;
_f far DONPP1S__F=0;
_f far csP1S     =0;
_f far DONP1ST__F=0;
_f far cs1ST     =0;
_f far DONPD2S__F=0;
_f far csD2S     =0;
_f far DONP2ST__F=0;
_f far cs2ST     =0;

ui far PRARRQ[10]={0,0,0,0,0,0,0,0,0,0};    // Очередь продувок
ui far PRNQC=0;                             // Текущий элемент очереди

//---------------------------------------------------------------------------
//  установка в очередь продувок
vd  far SetPRQ(_i np){ 
    _i  a=0;
    for(a=0;a<HEMPR;a++){
       if(PRARRQ[a]==0||PRARRQ[a]==np){ PRARRQ[a]=np; break; }
    }
    return;
}
//---------------------------------------------------------------------------
//  удаление из очереди продувок
vd  far DelPRQ(_i np){ 
    _i  a=0, b=0;
    for(a=0; a<HEMPR;a++){
       if(PRARRQ[a]==np){ break; }
    }
    for(b=a-1; b<HEMPR;b++){
        PRARRQ[b]=PRARRQ[b+1];
    }   PRARRQ[b]=0;
    return;
}
//---------------------------------------------------------------------------
//  получить из очереди номер следующей емкости для продувки
_i  GetPRQ(vd){
    _i  a=0, r=PRARRQ[0];
    for(a=0; a<HEMPR;a++){
        PRARRQ[a]=PRARRQ[a+1];
    }   PRARRQ[a]=0;
    return(r);
}
//---------------------------------------------------------------------------
//  вернуть номер следующего элемента в очереди продувок
_i  Is_PRQ(vd){
    return(PRARRQ[0]);
}
//---------------------------------------------------------------------------
//  проверить идет ли в данный момент продувка
_i  RunPRQ(vd){
    if( DONPBM3__V==ON ){ return(1); }
    if( DONPBM6__V==ON ){ return(2); }
    if( DONPHD___V==ON ){ return(3); }
    if( DONPGD___V==ON ){ return(4); }
    if( DONPP1___V==ON ){ return(5); }
    if( DONP1ST__V==ON ){ return(6); }
    if( DONPD2S__V==ON ){ return(7); }
    if( DONP2ST__V==ON ){ return(8); }
    return(0);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
vd  far Reg_15(vd){


    //-----------------------------------------------------------------------
    //  Управление насосом сборника продувок
    if (REG15R___M!=REG15R___V){ 
        REG15R___V =REG15R___M; 
        if(REG15R___V>0){ Message(128); }
        else            { Message(129); DONNZP___V = OFF; }
    };

    if (DONNZP___V==ON) DONNZP2__V=OFF;
        else            DONNZP2__V=ON;

    //-----------------------------------------------------------------------
    //  переключение режима продувок Ручное-Автомат
    //  (при переключении счетчики времени сбрасываются и клапана закрываются)
    if (PRBM3_RA_M==SWITCH){
        if(PRBM3_RA_V!= ON){ PRBM3_RA_V=ON;; Message(130); SetPRQ(1); }
        else               { PRBM3_RA_V=OFF; Message(131); DelPRQ(1); }
        TMWH_BM3_C=0; TMWM_BM3_C=0; TMWS_BM3_C=0; TMPM_BM3_C=0; TMPS_BM3_C=0;
        DONPBM3__V=OFF; csBM3=0;
    };  PRBM3_RA_M=OFF;
    //
    if (PRBM6_RA_M==SWITCH){
        if(PRBM6_RA_V!= ON){ PRBM6_RA_V=ON;; Message(132); SetPRQ(2); }
        else               { PRBM6_RA_V=OFF; Message(133); DelPRQ(2); }
        TMWH_BM6_C=0; TMWM_BM6_C=0; TMWS_BM6_C=0; TMPM_BM6_C=0; TMPS_BM6_C=0;
        DONPBM6__V=OFF;
    };  PRBM6_RA_M=OFF;
    //
    if (PRHDF_RA_M==SWITCH){
        if(PRHDF_RA_V!= ON){ PRHDF_RA_V=ON;; Message(134); SetPRQ(3); }
        else               { PRHDF_RA_V=OFF; Message(135); DelPRQ(3); }
        TMWH_HDF_C=0; TMWM_HDF_C=0; TMWS_HDF_C=0; TMPM_HDF_C=0; TMPS_HDF_C=0;
        DONPHD___V=OFF;
    };  PRHDF_RA_M=OFF;
    //
    if (PRGDF_RA_M==SWITCH){
        if(PRGDF_RA_V!= ON){ PRGDF_RA_V=ON;; Message(136); SetPRQ(4); }
        else               { PRGDF_RA_V=OFF; Message(137); DelPRQ(4); }
        TMWH_GDF_C=0; TMWM_GDF_C=0; TMWS_GDF_C=0; TMPM_GDF_C=0; TMPS_GDF_C=0;
        DONPGD___V=OFF;
    };  PRGDF_RA_M=OFF;
    //
    if (PRP1S_RA_M==SWITCH){
        if(PRP1S_RA_V!= ON){ PRP1S_RA_V=ON;; Message(138); SetPRQ(5); }
        else               { PRP1S_RA_V=OFF; Message(139); DelPRQ(5); }
        TMWH_P1S_C=0; TMWM_P1S_C=0; TMWS_P1S_C=0; TMPM_P1S_C=0; TMPS_P1S_C=0;
        DONPP1___V=OFF;
    };  PRP1S_RA_M=OFF;
    //
    if (PR1ST_RA_M==SWITCH){
        if(PR1ST_RA_V!= ON){ PR1ST_RA_V=ON;; Message(140); SetPRQ(6); }
        else               { PR1ST_RA_V=OFF; Message(141); DelPRQ(6); }
        TMWH_1ST_C=0; TMWM_1ST_C=0; TMWS_1ST_C=0; TMPM_1ST_C=0; TMPS_1ST_C=0;
        DONP1ST__V=OFF;
    };  PR1ST_RA_M=OFF;
    //
    if (PRD2S_RA_M==SWITCH){
        if(PRD2S_RA_V!= ON){ PRD2S_RA_V=ON;; Message(142); SetPRQ(7); }
        else               { PRD2S_RA_V=OFF; Message(143); DelPRQ(7); }
        TMWH_D2S_C=0; TMWM_D2S_C=0; TMWS_D2S_C=0; TMPM_D2S_C=0; TMPS_D2S_C=0;
        DONPD2S__V=OFF;
    };  PRD2S_RA_M=OFF;
    //
    if (PR2ST_RA_M==SWITCH){
        if(PR2ST_RA_V!= ON){ PR2ST_RA_V=ON;; Message(144); SetPRQ(8); }
        else               { PR2ST_RA_V=OFF; Message(145); DelPRQ(8); }
        TMWH_2ST_C=0; TMWM_2ST_C=0; TMWS_2ST_C=0; TMPM_2ST_C=0; TMPS_2ST_C=0;
        DONP2ST__V=OFF;
    };  PR2ST_RA_M=OFF;

    if (RegRUN==OFF){ return; }


    // Бригель-Мюллера 3 зона:
    //-----------------------------------------------------------------------
    // Если продувка включена на автомат
    if (PRBM3_RA_V==ON){
        DONPBM3__V=OFF;
        // если текущие минуты и секунды продувки меньше заданных - 
        // комманда на открытие клапана и считать время продувки 
        csBM3= TMPM_BM3_W*60+TMPS_BM3_W;
        if(PRNQC==1){
           if( TMPM_BM3_C*60+TMPS_BM3_C<csBM3 && DONPBM3__F==0){
               DONPBM3__V=ON;
               TMPS_BM3_C++;
               if(TMPS_BM3_C>59){ TMPM_BM3_C++; TMPS_BM3_C=0; }
           } else {
               // изменить флаг продувки, удалить элемент из очереди продувок
               // и обнулить счетчики времени
               if(DONPBM3__F==0){
                  DONPBM3__F =1; DelPRQ(1);
                  TMWH_BM3_C =0; TMWM_BM3_C=0; TMWS_BM3_C=0; 
                                 TMPM_BM3_C=0; TMPS_BM3_C=0;
               }
           }
        }
        // если текущ часы,минуты и секунды ожидания продувки меньше заданных- 
        // комманда на закрытие клапана и считать время ожидания
        csBM3= TMWH_BM3_W*3600+TMWM_BM3_W*60+TMWS_BM3_W;
        if( TMWH_BM3_C*3600+TMWM_BM3_C*60+TMWS_BM3_C<csBM3 && DONPBM3__F==1){
            DONPBM3__V=OFF;
            TMWS_BM3_C++;
            if(TMWS_BM3_C>59){ TMWM_BM3_C++; TMWS_BM3_C=0; }
            if(TMWM_BM3_C>59){ TMWH_BM3_C++; TMWM_BM3_C=0; }
        } else {
            // изменить флаг продувки, установить элемент в очереди продувок
            // и обнулить счетчики времени
            if(DONPBM3__F==1){
               DONPBM3__F =0; SetPRQ(1);
               TMWH_BM3_C =0; TMWM_BM3_C=0; TMWS_BM3_C=0; 
                              TMPM_BM3_C=0; TMPS_BM3_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Бригель-Мюллера 6 зона:
    //-----------------------------------------------------------------------
    if (PRBM6_RA_V==ON){
        DONPBM6__V=OFF;
        csBM6= TMPM_BM6_W*60+TMPS_BM6_W;
        if(PRNQC==2){
           if( TMPM_BM6_C*60+TMPS_BM6_C<csBM6 && DONPBM6__F==0){
               DONPBM6__V=ON;
               TMPS_BM6_C++;
               if(TMPS_BM6_C>59){ TMPM_BM6_C++; TMPS_BM6_C=0; }
           } else {
               if(DONPBM6__F==0){
                  DONPBM6__F =1; DelPRQ(2);
                  TMWH_BM6_C =0; TMWM_BM6_C=0; TMWS_BM6_C=0; 
                                 TMPM_BM6_C=0; TMPS_BM6_C=0;
               }
           }
        }
        csBM6= TMWH_BM6_W*3600+TMWM_BM6_W*60+TMWS_BM6_W;
        if( TMWH_BM6_C*3600+TMWM_BM6_C*60+TMWS_BM6_C<csBM6 && DONPBM6__F==1){
            DONPBM6__V=OFF;
            TMWS_BM6_C++;
            if(TMWS_BM6_C>59){ TMWM_BM6_C++; TMWS_BM6_C=0; }
            if(TMWM_BM6_C>59){ TMWH_BM6_C++; TMWM_BM6_C=0; }
        } else {
            if(DONPBM6__F==1){
               DONPBM6__F =0; SetPRQ(2);
               TMWH_BM6_C =0; TMWM_BM6_C=0; TMWS_BM6_C=0; 
                              TMPM_BM6_C=0; TMPS_BM6_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Холодный дефекатор:
    //-----------------------------------------------------------------------
    if (PRHDF_RA_V==ON){
        DONPHD___V=OFF;
        csHDF= TMPM_HDF_W*60+TMPS_HDF_W;
        if(PRNQC==3){
           if( TMPM_HDF_C*60+TMPS_HDF_C<csHDF && DONPHDF__F==0){
               DONPHD___V=ON;
               TMPS_HDF_C++;
               if(TMPS_HDF_C>59){ TMPM_HDF_C++; TMPS_HDF_C=0; }
           } else {
               if(DONPHDF__F==0){
                  DONPHDF__F =1; DelPRQ(3);
                  TMWH_HDF_C =0; TMWM_HDF_C=0; TMWS_HDF_C=0; 
                                 TMPM_HDF_C=0; TMPS_HDF_C=0;
               }
           }
        }
        csHDF= TMWH_HDF_W*3600+TMWM_HDF_W*60+TMWS_HDF_W;
        if( TMWH_HDF_C*3600+TMWM_HDF_C*60+TMWS_HDF_C<csHDF && DONPHDF__F==1){
            DONPHD___V=OFF;
            TMWS_HDF_C++;
            if(TMWS_HDF_C>59){ TMWM_HDF_C++; TMWS_HDF_C=0; }
            if(TMWM_HDF_C>59){ TMWH_HDF_C++; TMWM_HDF_C=0; }
        } else {
            if(DONPHDF__F==1){
               DONPHDF__F =0; SetPRQ(3);
               TMWH_HDF_C =0; TMWM_HDF_C=0; TMWS_HDF_C=0; 
                              TMPM_HDF_C=0; TMPS_HDF_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Горячий дефекатор:
    //-----------------------------------------------------------------------
    if (PRGDF_RA_V==ON){
        DONPGD___V=OFF;
        csGDF= TMPM_GDF_W*60+TMPS_GDF_W;
        if(PRNQC==4){
           if( TMPM_GDF_C*60+TMPS_GDF_C<csGDF && DONPGDF__F==0){
               DONPGD___V=ON;
               TMPS_GDF_C++;
               if(TMPS_GDF_C>59){ TMPM_GDF_C++; TMPS_GDF_C=0; }
           } else {
               if(DONPGDF__F==0){
                  DONPGDF__F =1; DelPRQ(4);
                  TMWH_GDF_C =0; TMWM_GDF_C=0; TMWS_GDF_C=0; 
                                 TMPM_GDF_C=0; TMPS_GDF_C=0;
               }
           }
        }
        csGDF= TMWH_GDF_W*3600+TMWM_GDF_W*60+TMWS_GDF_W;
        if( TMWH_GDF_C*3600+TMWM_GDF_C*60+TMWS_GDF_C<csGDF && DONPGDF__F==1){
            DONPGD___V=OFF;
            TMWS_GDF_C++;
            if(TMWS_GDF_C>59){ TMWM_GDF_C++; TMWS_GDF_C=0; }
            if(TMWM_GDF_C>59){ TMWH_GDF_C++; TMWM_GDF_C=0; }
        } else {
            if(DONPGDF__F==1){
               DONPGDF__F =0; SetPRQ(4);
               TMWH_GDF_C =0; TMWM_GDF_C=0; TMWS_GDF_C=0; 
                              TMPM_GDF_C=0; TMPS_GDF_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Предсатуратор 1 сатурации:
    //-----------------------------------------------------------------------
    if (PRP1S_RA_V==ON){
        DONPP1___V=OFF;
        csP1S= TMPM_P1S_W*60+TMPS_P1S_W;
        if(PRNQC==5){
           if( TMPM_P1S_C*60+TMPS_P1S_C<csP1S && DONPP1S__F==0){
               DONPP1___V=ON;
               TMPS_P1S_C++;
               if(TMPS_P1S_C>59){ TMPM_P1S_C++; TMPS_P1S_C=0; }
           } else {
               if(DONPP1S__F==0){
                  DONPP1S__F =1; DelPRQ(5);
                  TMWH_P1S_C =0; TMWM_P1S_C=0; TMWS_P1S_C=0; 
                                 TMPM_P1S_C=0; TMPS_P1S_C=0;
               }
           }
        }
        csP1S= TMWH_P1S_W*3600+TMWM_P1S_W*60+TMWS_P1S_W;
        if( TMWH_P1S_C*3600+TMWM_P1S_C*60+TMWS_P1S_C<csP1S && DONPP1S__F==1){
            DONPP1___V=OFF;
            TMWS_P1S_C++;
            if(TMWS_P1S_C>59){ TMWM_P1S_C++; TMWS_P1S_C=0; }
            if(TMWM_P1S_C>59){ TMWH_P1S_C++; TMWM_P1S_C=0; }
        } else {
            if(DONPP1S__F==1){
               DONPP1S__F =0; SetPRQ(5);
               TMWH_P1S_C =0; TMWM_P1S_C=0; TMWS_P1S_C=0; 
                              TMPM_P1S_C=0; TMPS_P1S_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Котел 1 сатурации:
    //-----------------------------------------------------------------------
    if (PR1ST_RA_V==ON){
        DONP1ST__V=OFF;
        cs1ST= TMPM_1ST_W*60+TMPS_1ST_W;
        if(PRNQC==6){
           if( TMPM_1ST_C*60+TMPS_1ST_C<cs1ST && DONP1ST__F==0){
               DONP1ST__V=ON;
               TMPS_1ST_C++;
               if(TMPS_1ST_C>59){ TMPM_1ST_C++; TMPS_1ST_C=0; }
           } else {
               if(DONP1ST__F==0){
                  DONP1ST__F =1; DelPRQ(6);
                  TMWH_1ST_C =0; TMWM_1ST_C=0; TMWS_1ST_C=0; 
                                 TMPM_1ST_C=0; TMPS_1ST_C=0;
               }
           }
        }
        cs1ST= TMWH_1ST_W*3600+TMWM_1ST_W*60+TMWS_1ST_W;
        if( TMWH_1ST_C*3600+TMWM_1ST_C*60+TMWS_1ST_C<cs1ST && DONP1ST__F==1){
            DONP1ST__V=OFF;
            TMWS_1ST_C++;
            if(TMWS_1ST_C>59){ TMWM_1ST_C++; TMWS_1ST_C=0; }
            if(TMWM_1ST_C>59){ TMWH_1ST_C++; TMWM_1ST_C=0; }
        } else {
            if(DONP1ST__F==1){
               DONP1ST__F =0; SetPRQ(6);
               TMWH_1ST_C =0; TMWM_1ST_C=0; TMWS_1ST_C=0; 
                              TMPM_1ST_C=0; TMPS_1ST_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Дефекатор 2 сатурации:
    //-----------------------------------------------------------------------
    if (PRD2S_RA_V==ON){
        DONPD2S__V=OFF;
        csD2S= TMPM_D2S_W*60+TMPS_D2S_W;
        if(PRNQC==7){
           if( TMPM_D2S_C*60+TMPS_D2S_C<csD2S && DONPD2S__F==0){
               DONPD2S__V=ON;
               TMPS_D2S_C++;
               if(TMPS_D2S_C>59){ TMPM_D2S_C++; TMPS_D2S_C=0; }
           } else {
               if(DONPD2S__F==0){
                  DONPD2S__F =1; DelPRQ(7);
                  TMWH_D2S_C =0; TMWM_D2S_C=0; TMWS_D2S_C=0; 
                                 TMPM_D2S_C=0; TMPS_D2S_C=0;
               }
           }
        }
        csD2S= TMWH_D2S_W*3600+TMWM_D2S_W*60+TMWS_D2S_W;
        if( TMWH_D2S_C*3600+TMWM_D2S_C*60+TMWS_D2S_C<csD2S && DONPD2S__F==1){
            DONPD2S__V=OFF;
            TMWS_D2S_C++;
            if(TMWS_D2S_C>59){ TMWM_D2S_C++; TMWS_D2S_C=0; }
            if(TMWM_D2S_C>59){ TMWH_D2S_C++; TMWM_D2S_C=0; }
        } else {
            if(DONPD2S__F==1){
               DONPD2S__F =0; SetPRQ(7);
               TMWH_D2S_C =0; TMWM_D2S_C=0; TMWS_D2S_C=0; 
                              TMPM_D2S_C=0; TMPS_D2S_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    // Котел 2 сатурации:
    //-----------------------------------------------------------------------
    if (PR2ST_RA_V==ON){
        DONP2ST__V=OFF;
        cs2ST= TMPM_2ST_W*60+TMPS_2ST_W;
        if(PRNQC==8){
           if( TMPM_2ST_C*60+TMPS_2ST_C<cs2ST && DONP2ST__F==0){
               DONP2ST__V=ON;
               TMPS_2ST_C++;
               if(TMPS_2ST_C>59){ TMPM_2ST_C++; TMPS_2ST_C=0; }
           } else {
               if(DONP2ST__F==0){
                  DONP2ST__F =1; DelPRQ(8);
                  TMWH_2ST_C =0; TMWM_2ST_C=0; TMWS_2ST_C=0; 
                                 TMPM_2ST_C=0; TMPS_2ST_C=0;
               }
           }
        }
        cs2ST= TMWH_2ST_W*3600+TMWM_2ST_W*60+TMWS_2ST_W;
        if( TMWH_2ST_C*3600+TMWM_2ST_C*60+TMWS_2ST_C<cs2ST && DONP2ST__F==1){
            DONP2ST__V=OFF;
            TMWS_2ST_C++;
            if(TMWS_2ST_C>59){ TMWM_2ST_C++; TMWS_2ST_C=0; }
            if(TMWM_2ST_C>59){ TMWH_2ST_C++; TMWM_2ST_C=0; }
        } else {
            if(DONP2ST__F==1){
               DONP2ST__F =0; SetPRQ(8);
               TMWH_2ST_C =0; TMWM_2ST_C=0; TMWS_2ST_C=0; 
                              TMPM_2ST_C=0; TMPS_2ST_C=0;
            }
        }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    //  Если в данный момент ничего не продувается
    if (RunPRQ()==0){
        //  Если очередь продувок не пустая- взять из очереди элемет
        if (Is_PRQ()>0){ PRNQC=GetPRQ(); }
        else           { PRNQC=0;        }
    }
    //-----------------------------------------------------------------------


    //-----------------------------------------------------------------------
    //  Управление насосом зборника продувок
    if (AILZPR_L_M< 0){ AILZPR_L_M=0; }
    if (AILZPR_H_M<=AILZPR_L_M+0.1){ AILZPR_H_M=AILZPR_L_M+0.1; }
    AILZPR_H_V=AILZPR_H_M;
    AILZPR_L_V=AILZPR_L_M;
    if(REG15R___V==ON){
       //  Если текущий уровень больше или равен уровню включения насоса
       // (верхнее ограничение) и нет продувок перед горячим дефекатором-
       //  включить насос для откачки
       if (AILZPR___V >= AILZPR_H_V && (RunPRQ()<1 || RunPRQ()>4) ){
           DONNZP___V  = ON;
       }
       //  Если текущий уровень меньше или равен уровню выключения насоса
       //  (нижнее ограничение) или включена продувка горячего дефекатора- 
       //  выключить насос
       if (AILZPR___V <= AILZPR_L_V || RunPRQ()==4 ){
           DONNZP___V  = OFF;
       }
    }
    //-----------------------------------------------------------------------
    //  включение-выключение насоса сборника продувок в ручном режиме
    if (DONNZP___M==SWITCH and REG15R___V==OFF){
        DONNZP___V=(DONNZP___V==OFF) then_ ON else_ OFF; 
    };  DONNZP___M=OFF;

    //-----------------------------------------------------------------------


    return;
}
//---------------------------------------------------------------------------
