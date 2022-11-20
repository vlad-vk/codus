//----------------------------------------------------------------------------
//  COM2, 7042, N44
#define     M44C00M       DON251E1_M
#define     M44C01M       DON251F1_M
#define     M44C02M       DON251H1_M
#define     M44C03M       DON251G1_M
#define     M44C04M       DON251E2_M
#define     M44C05M       DON251F2_M
#define     M44C06M       DON251H2_M
#define     M44C07M       DON251G2_M
#define     M44C08M       M44C08___M
#define     M44C09M       M44C09___M
#define     M44C10M       DON216F__M
#define     M44C11M       DON216G__M
#define     M44C12M       M44C12___M

#define     M44C00V       DON251E1_V
#define     M44C01V       DON251F1_V
#define     M44C02V       DON251H1_V
#define     M44C03V       DON251G1_V
#define     M44C04V       DON251E2_V
#define     M44C05V       DON251F2_V
#define     M44C06V       DON251H2_V
#define     M44C07V       DON251G2_V
#define     M44C08V       M44C08___V
#define     M44C09V       M44C09___V
#define     M44C10V       DON216F__V
#define     M44C11V       DON216G__V
#define     M44C12V       M44C12___V

rec=19;

    if(M44C00M==SWITCH){ M44C00V=(M44C00V==OFF) then_ ON else_ OFF; }; M44C00M=OFF; 
    if(M44C01M==SWITCH){ M44C01V=(M44C01V==OFF) then_ ON else_ OFF; }; M44C01M=OFF; 
    if(M44C02M==SWITCH){ M44C02V=(M44C02V==OFF) then_ ON else_ OFF; }; M44C02M=OFF; 
    if(M44C03M==SWITCH){ M44C03V=(M44C03V==OFF) then_ ON else_ OFF; }; M44C03M=OFF; 
    if(M44C04M==SWITCH){ M44C04V=(M44C04V==OFF) then_ ON else_ OFF; }; M44C04M=OFF; 
    if(M44C05M==SWITCH){ M44C05V=(M44C05V==OFF) then_ ON else_ OFF; }; M44C05M=OFF; 
    if(M44C06M==SWITCH){ M44C06V=(M44C06V==OFF) then_ ON else_ OFF; }; M44C06M=OFF; 
    if(M44C07M==SWITCH){ M44C07V=(M44C07V==OFF) then_ ON else_ OFF; }; M44C07M=OFF; 
    if(M44C08M==SWITCH){ M44C08V=(M44C08V==OFF) then_ ON else_ OFF; }; M44C08M=OFF; 
    if(M44C09M==SWITCH){ M44C09V=(M44C09V==OFF) then_ ON else_ OFF; }; M44C09M=OFF; 
    if(M44C10M==SWITCH){ M44C10V=(M44C10V==OFF) then_ ON else_ OFF; }; M44C10M=OFF; 
    if(M44C11M==SWITCH){ M44C11V=(M44C11V==OFF) then_ ON else_ OFF; }; M44C11M=OFF; 
    if(M44C12M==SWITCH){ M44C12V=(M44C12V==OFF) then_ ON else_ OFF; }; M44C12M=OFF; 

    SetMODV (COMU2,rec, 0,  M44C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M44C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M44C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M44C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M44C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M44C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M44C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M44C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M44C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M44C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M44C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M44C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M44C12V,  0, 0);

//----------------------------------------------------------------------------
