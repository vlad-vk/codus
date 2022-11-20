//----------------------------------------------------------------------------
//  COM1, 7042, N06
#define     M06C00M       DON213W__M
#define     M06C01M       DON213V__M
#define     M06C02M       DON213A__M
#define     M06C03M       DON213B__M
#define     M06C04M       DON213C__M
#define     M06C05M       M06C05___M
#define     M06C06M       M06C06___M
#define     M06C07M       M06C07___M
#define     M06C08M       M06C08___M
#define     M06C09M       M06C09___M
#define     M06C10M       M06C10___M
#define     M06C11M       M06C11___M
#define     M06C12M       M06C12___M

#define     M06C00V       DON213W__V
#define     M06C01V       DON213V__V
#define     M06C02V       DON213A__V
#define     M06C03V       DON213B__V
#define     M06C04V       DON213C__V
#define     M06C05V       M06C05___V
#define     M06C06V       M06C06___V
#define     M06C07V       M06C07___V
#define     M06C08V       M06C08___V
#define     M06C09V       M06C09___V
#define     M06C10V       M06C10___V
#define     M06C11V       M06C11___V
#define     M06C12V       M06C12___V

rec=6;

    if(M06C00M==SWITCH){ M06C00V=(M06C00V==OFF) then_ ON else_ OFF; }; M06C00M=OFF; 
    if(M06C01M==SWITCH){ M06C01V=(M06C01V==OFF) then_ ON else_ OFF; }; M06C01M=OFF; 
    if(M06C02M==SWITCH){ M06C02V=(M06C02V==OFF) then_ ON else_ OFF; }; M06C02M=OFF; 
    if(M06C03M==SWITCH){ M06C03V=(M06C03V==OFF) then_ ON else_ OFF; }; M06C03M=OFF; 
    if(M06C04M==SWITCH){ M06C04V=(M06C04V==OFF) then_ ON else_ OFF; }; M06C04M=OFF; 
    if(M06C05M==SWITCH){ M06C05V=(M06C05V==OFF) then_ ON else_ OFF; }; M06C05M=OFF; 
    if(M06C06M==SWITCH){ M06C06V=(M06C06V==OFF) then_ ON else_ OFF; }; M06C06M=OFF; 
    if(M06C07M==SWITCH){ M06C07V=(M06C07V==OFF) then_ ON else_ OFF; }; M06C07M=OFF; 
    if(M06C08M==SWITCH){ M06C08V=(M06C08V==OFF) then_ ON else_ OFF; }; M06C08M=OFF; 
    if(M06C09M==SWITCH){ M06C09V=(M06C09V==OFF) then_ ON else_ OFF; }; M06C09M=OFF; 
    if(M06C10M==SWITCH){ M06C10V=(M06C10V==OFF) then_ ON else_ OFF; }; M06C10M=OFF; 
    if(M06C11M==SWITCH){ M06C11V=(M06C11V==OFF) then_ ON else_ OFF; }; M06C11M=OFF; 
    if(M06C12M==SWITCH){ M06C12V=(M06C12V==OFF) then_ ON else_ OFF; }; M06C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M06C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M06C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M06C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M06C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M06C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M06C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M06C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M06C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M06C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M06C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M06C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M06C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M06C12V,  0, 0);

//----------------------------------------------------------------------------
