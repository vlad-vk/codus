//---------------------------------------------------------------------------
#include "..\_libpath.inc"
#include "..\prg\run_prgv.h"
#include "..\prg\run_prgr.h"

#include "other_e.h"

//---------------------------------------------------------------------------
ui  far Ctrl_AI(_f far Val ,_f far VMin,
                _f far VMax,ui far VF,
                ui far VMinMes,ui far VNorMes,ui far VMaxMes,
                ui far BN,     ui far BV){
  // Выход параметра за верхнюю границу
  if ((Val>VMax)&&(VF==1)){ Message(VMaxMes); Bell(BN,BV); VF=2; }
  // Выход параметра за нижнюю границу
  if ((Val<VMin)&&(VF==1)){ Message(VMinMes); Bell(BN,BV); VF=0; }
  // Восстановление парраметра из верхней границы
  if ((Val<VMax-(VMax*0.01))&&(VF==2)){ Message(VNorMes); Bell(BN,0); VF=1; }
  // Восстановление парраметра из нижней границы
  if ((Val>VMin+(VMax*0.01))&&(VF==0)){ Message(VNorMes); Bell(BN,0); VF=1; }
  if ((Val>VMin+(VMax*0.01))&&(Val<VMax-(VMax*0.01))){ VF=1; }
  return(VF);
}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//  Сигнализация и блокировки
vd  far L_Signal(vd){
    // контроль максимального давления в магистрали
    AIP12M1__S=Ctrl_AI(AIP12M___V,  AIP12M_AZV, A1MAXPM__R, AIP12M1__S, 
                       251+A1BNM ,  252+A1BNM , 253+A1BNM , 1, 1);
    AIP12M2__S=Ctrl_AI(AIP12M___V,  AIP12M_AZV, A2MAXPM__R, AIP12M2__S, 
                       251+A2BNM ,  252+A2BNM , 253+A2BNM , 2, 1);
    // контроль разницы температур в автоклаве
    A1TTTB___S=Ctrl_AI(A1TTTB___V,         -20, A1ZDTAK__R, A1TTTB___S, 
                       255+A1BNM ,  256+A1BNM , 257+A1BNM , 1, 1);
    A2TTTB___S=Ctrl_AI(A2TTTB___V,         -20, A2ZDTAK__R, A2TTTB___S, 
                       255+A2BNM ,  256+A2BNM , 257+A2BNM , 2, 1);
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // DIS601___S = Control_DI( DIS601___V, DIS601___S, 100, 101 );
    // DIS602___S = Control_DI( DIS602___V, DIS602___S, 102, 103 );

    return;
}
//----------------------------------------------------------------------------
