//----------------------------------------------------------------------------
//  COM1, 7042, N04
#define     M04C00M       DON211W__M
#define     M04C01M       DON211NV_M
#define     M04C02M       DON211KA_M
#define     M04C03M       DON211KB_M
#define     M04C04M       DON211KC_M
#define     M04C05M       M04C05___M
#define     M04C06M       M04C06___M
#define     M04C07M       M04C07___M
#define     M04C08M       M04C08___M
#define     M04C09M       M04C09___M
#define     M04C10M       M04C10___M
#define     M04C11M       M04C11___M
#define     M04C12M       M04C12___M

#define     M04C00V       DON211W__V
#define     M04C01V       DON211NV_V
#define     M04C02V       DON211KA_V
#define     M04C03V       DON211KB_V
#define     M04C04V       DON211KC_V
#define     M04C05V       M04C05___V
#define     M04C06V       M04C06___V
#define     M04C07V       M04C07___V
#define     M04C08V       M04C08___V
#define     M04C09V       M04C09___V
#define     M04C10V       M04C10___V
#define     M04C11V       M04C11___V
#define     M04C12V       M04C12___V

rec=4;

    if(M04C00M==SWITCH){ M04C00V=(M04C00V==OFF) then_ ON else_ OFF; }; M04C00M=OFF; 
    if(M04C01M==SWITCH){ M04C01V=(M04C01V==OFF) then_ ON else_ OFF; }; M04C01M=OFF; 
    if(M04C02M==SWITCH){ M04C02V=(M04C02V==OFF) then_ ON else_ OFF; }; M04C02M=OFF; 
    if(M04C03M==SWITCH){ M04C03V=(M04C03V==OFF) then_ ON else_ OFF; }; M04C03M=OFF; 
    if(M04C04M==SWITCH){ M04C04V=(M04C04V==OFF) then_ ON else_ OFF; }; M04C04M=OFF; 
    if(M04C05M==SWITCH){ M04C05V=(M04C05V==OFF) then_ ON else_ OFF; }; M04C05M=OFF; 
    if(M04C06M==SWITCH){ M04C06V=(M04C06V==OFF) then_ ON else_ OFF; }; M04C06M=OFF; 
    if(M04C07M==SWITCH){ M04C07V=(M04C07V==OFF) then_ ON else_ OFF; }; M04C07M=OFF; 
    if(M04C08M==SWITCH){ M04C08V=(M04C08V==OFF) then_ ON else_ OFF; }; M04C08M=OFF; 
    if(M04C09M==SWITCH){ M04C09V=(M04C09V==OFF) then_ ON else_ OFF; }; M04C09M=OFF; 
    if(M04C10M==SWITCH){ M04C10V=(M04C10V==OFF) then_ ON else_ OFF; }; M04C10M=OFF; 
    if(M04C11M==SWITCH){ M04C11V=(M04C11V==OFF) then_ ON else_ OFF; }; M04C11M=OFF; 
    if(M04C12M==SWITCH){ M04C12V=(M04C12V==OFF) then_ ON else_ OFF; }; M04C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M04C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M04C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M04C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M04C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M04C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M04C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M04C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M04C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M04C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M04C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M04C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M04C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M04C12V,  0, 0);

//----------------------------------------------------------------------------
