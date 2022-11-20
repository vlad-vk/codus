//----------------------------------------------------------------------------
//  COM1, 7042, N11
#define     M11C00M       DON043A__M
#define     M11C01M       DON044A__M
#define     M11C02M       DON045A__M
#define     M11C03M       DON046A__M
#define     M11C04M       DON043B__M
#define     M11C05M       DON044B__M
#define     M11C06M       DON045B__M
#define     M11C07M       DON046B__M
#define     M11C08M       M11C08___M
#define     M11C09M       M11C09___M
#define     M11C10M       M11C10___M
#define     M11C11M       M11C11___M
#define     M11C12M       M11C12___M

#define     M11C00V       DON043A__V
#define     M11C01V       DON044A__V
#define     M11C02V       DON045A__V
#define     M11C03V       DON046A__V
#define     M11C04V       DON043B__V
#define     M11C05V       DON044B__V
#define     M11C06V       DON045B__V
#define     M11C07V       DON046B__V
#define     M11C08V       M11C08___V
#define     M11C09V       M11C09___V
#define     M11C10V       M11C10___V
#define     M11C11V       M11C11___V
#define     M11C12V       M11C12___V

rec=13;

    if(M11C00M==SWITCH){ M11C00V=(M11C00V==OFF) then_ ON else_ OFF; }; M11C00M=OFF; 
    if(M11C01M==SWITCH){ M11C01V=(M11C01V==OFF) then_ ON else_ OFF; }; M11C01M=OFF; 
    if(M11C02M==SWITCH){ M11C02V=(M11C02V==OFF) then_ ON else_ OFF; }; M11C02M=OFF; 
    if(M11C03M==SWITCH){ M11C03V=(M11C03V==OFF) then_ ON else_ OFF; }; M11C03M=OFF; 
    if(M11C04M==SWITCH){ M11C04V=(M11C04V==OFF) then_ ON else_ OFF; }; M11C04M=OFF; 
    if(M11C05M==SWITCH){ M11C05V=(M11C05V==OFF) then_ ON else_ OFF; }; M11C05M=OFF; 
    if(M11C06M==SWITCH){ M11C06V=(M11C06V==OFF) then_ ON else_ OFF; }; M11C06M=OFF; 
    if(M11C07M==SWITCH){ M11C07V=(M11C07V==OFF) then_ ON else_ OFF; }; M11C07M=OFF; 
    if(M11C08M==SWITCH){ M11C08V=(M11C08V==OFF) then_ ON else_ OFF; }; M11C08M=OFF; 
    if(M11C09M==SWITCH){ M11C09V=(M11C09V==OFF) then_ ON else_ OFF; }; M11C09M=OFF; 
    if(M11C10M==SWITCH){ M11C10V=(M11C10V==OFF) then_ ON else_ OFF; }; M11C10M=OFF; 
    if(M11C11M==SWITCH){ M11C11V=(M11C11V==OFF) then_ ON else_ OFF; }; M11C11M=OFF; 
    if(M11C12M==SWITCH){ M11C12V=(M11C12V==OFF) then_ ON else_ OFF; }; M11C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M11C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M11C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M11C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M11C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M11C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M11C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M11C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M11C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M11C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M11C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M11C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M11C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M11C12V,  0, 0);

//----------------------------------------------------------------------------
