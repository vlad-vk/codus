//----------------------------------------------------------------------------
//  COM1, 7042, N18
#define     M18C00M       DON203N__M
#define     M18C01M       M18C01___M
#define     M18C02M       DON204D__M
#define     M18C03M       DON204A__M
#define     M18C04M       DON204B__M
#define     M18C05M       M18C05___M
#define     M18C06M       M18C06___M
#define     M18C07M       M18C07___M
#define     M18C08M       M18C08___M
#define     M18C09M       M18C09___M
#define     M18C10M       M18C10___M
#define     M18C11M       DON204V__M
#define     M18C12M       DON290N__M

#define     M18C00V       DON203N__V
#define     M18C01V       M18C01___V
#define     M18C02V       DON204D__V
#define     M18C03V       DON204A__V
#define     M18C04V       DON204B__V
#define     M18C05V       M18C05___V
#define     M18C06V       M18C06___V
#define     M18C07V       M18C07___V
#define     M18C08V       M18C08___V
#define     M18C09V       M18C09___V
#define     M18C10V       M18C10___V
#define     M18C11V       DON204V__V
#define     M18C12V       DON290N__V

rec=20;

    if(M18C00M==SWITCH){ M18C00V=(M18C00V==OFF) then_ ON else_ OFF; }; M18C00M=OFF; 
    if(M18C01M==SWITCH){ M18C01V=(M18C01V==OFF) then_ ON else_ OFF; }; M18C01M=OFF; 
    if(M18C02M==SWITCH){ M18C02V=(M18C02V==OFF) then_ ON else_ OFF; }; M18C02M=OFF; 
    if(M18C03M==SWITCH){ M18C03V=(M18C03V==OFF) then_ ON else_ OFF; }; M18C03M=OFF; 
    if(M18C04M==SWITCH){ M18C04V=(M18C04V==OFF) then_ ON else_ OFF; }; M18C04M=OFF; 
    if(M18C05M==SWITCH){ M18C05V=(M18C05V==OFF) then_ ON else_ OFF; }; M18C05M=OFF; 
    if(M18C06M==SWITCH){ M18C06V=(M18C06V==OFF) then_ ON else_ OFF; }; M18C06M=OFF; 
    if(M18C07M==SWITCH){ M18C07V=(M18C07V==OFF) then_ ON else_ OFF; }; M18C07M=OFF; 
    if(M18C08M==SWITCH){ M18C08V=(M18C08V==OFF) then_ ON else_ OFF; }; M18C08M=OFF; 
    if(M18C09M==SWITCH){ M18C09V=(M18C09V==OFF) then_ ON else_ OFF; }; M18C09M=OFF; 
    if(M18C10M==SWITCH){ M18C10V=(M18C10V==OFF) then_ ON else_ OFF; }; M18C10M=OFF; 
    if(M18C11M==SWITCH){ M18C11V=(M18C11V==OFF) then_ ON else_ OFF; }; M18C11M=OFF; 
    if(M18C12M==SWITCH){ M18C12V=(M18C12V==OFF) then_ ON else_ OFF; }; M18C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M18C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M18C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M18C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M18C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M18C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M18C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M18C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M18C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M18C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M18C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M18C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M18C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M18C12V,  0, 0);

//----------------------------------------------------------------------------
