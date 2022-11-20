//----------------------------------------------------------------------------
//  COM2, 7042, N45
#define     M45C00M       DONDM1K__M
#define     M45C01M       DONDM2K__M
#define     M45C02M       DONDS1K__M
#define     M45C03M       DONDS2K__M
#define     M45C04M       DONDP1K__M
#define     M45C05M       DONDP2K__M
#define     M45C06M       M45C06___M
#define     M45C07M       M45C07___M
#define     M45C08M       M45C08___M
#define     M45C09M       M45C09___M
#define     M45C10M       M45C10___M
#define     M45C11M       M45C11___M
#define     M45C12M       M45C12___M

#define     M45C00V       DONDM1K__V
#define     M45C01V       DONDM2K__V
#define     M45C02V       DONDS1K__V
#define     M45C03V       DONDS2K__V
#define     M45C04V       DONDP1K__V
#define     M45C05V       DONDP2K__V
#define     M45C06V       M45C06___V
#define     M45C07V       M45C07___V
#define     M45C08V       M45C08___V
#define     M45C09V       M45C09___V
#define     M45C10V       M45C10___V
#define     M45C11V       M45C11___V
#define     M45C12V       M45C12___V

rec=25;

    if(M45C00M==SWITCH){ M45C00V=(M45C00V==OFF) then_ ON else_ OFF; }; M45C00M=OFF; 
    if(M45C01M==SWITCH){ M45C01V=(M45C01V==OFF) then_ ON else_ OFF; }; M45C01M=OFF; 
    if(M45C02M==SWITCH){ M45C02V=(M45C02V==OFF) then_ ON else_ OFF; }; M45C02M=OFF; 
    if(M45C03M==SWITCH){ M45C03V=(M45C03V==OFF) then_ ON else_ OFF; }; M45C03M=OFF; 
    if(M45C04M==SWITCH){ M45C04V=(M45C04V==OFF) then_ ON else_ OFF; }; M45C04M=OFF; 
    if(M45C05M==SWITCH){ M45C05V=(M45C05V==OFF) then_ ON else_ OFF; }; M45C05M=OFF; 
    if(M45C06M==SWITCH){ M45C06V=(M45C06V==OFF) then_ ON else_ OFF; }; M45C06M=OFF; 
    if(M45C07M==SWITCH){ M45C07V=(M45C07V==OFF) then_ ON else_ OFF; }; M45C07M=OFF; 
    if(M45C08M==SWITCH){ M45C08V=(M45C08V==OFF) then_ ON else_ OFF; }; M45C08M=OFF; 
    if(M45C09M==SWITCH){ M45C09V=(M45C09V==OFF) then_ ON else_ OFF; }; M45C09M=OFF; 
    if(M45C10M==SWITCH){ M45C10V=(M45C10V==OFF) then_ ON else_ OFF; }; M45C10M=OFF; 
    if(M45C11M==SWITCH){ M45C11V=(M45C11V==OFF) then_ ON else_ OFF; }; M45C11M=OFF; 
    if(M45C12M==SWITCH){ M45C12V=(M45C12V==OFF) then_ ON else_ OFF; }; M45C12M=OFF; 

    SetMODV (COMU2,rec, 0,  M45C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M45C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M45C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M45C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M45C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M45C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M45C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M45C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M45C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M45C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M45C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M45C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M45C12V,  0, 0);

//----------------------------------------------------------------------------
