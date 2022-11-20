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
    AIP34M3__S=Ctrl_AI(AIP34M___V,  AIP34M_AZV, A3MAXPM__R, AIP34M3__S, 
                       251+A3BNM ,  252+A3BNM , 253+A3BNM , 3, 1);
    AIP34M4__S=Ctrl_AI(AIP34M___V,  AIP34M_AZV, A4MAXPM__R, AIP34M4__S, 
                       251+A4BNM ,  252+A4BNM , 253+A4BNM , 4, 1);
    // контроль разницы температур в автоклаве
    A3TTTB___S=Ctrl_AI(A3TTTB___V,         -20, A3ZDTAK__R, A3TTTB___S, 
                       255+A3BNM ,  256+A3BNM , 257+A3BNM , 3, 1);
    A4TTTB___S=Ctrl_AI(A4TTTB___V,         -20, A4ZDTAK__R, A4TTTB___S, 
                       255+A4BNM ,  256+A4BNM , 257+A4BNM , 4, 1);
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // DIS601___S = Control_DI( DIS601___V, DIS601___S, 100, 101 );
    // DIS602___S = Control_DI( DIS602___V, DIS602___S, 102, 103 );

    return;
}
//----------------------------------------------------------------------------
