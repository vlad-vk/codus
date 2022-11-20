//----------------------------------------------------------------------------
//  COM2, 7042, N23
#define     M23C00M       DON221A__M
#define     M23C01M       DON2211__M
#define     M23C02M       DON228A__M
#define     M23C03M       DON2212__M
#define     M23C04M       DON221C__M
#define     M23C05M       DON2293__M
#define     M23C06M       DON228C__M
#define     M23C07M       DON2294__M
#define     M23C08M       DON220E__M
#define     M23C09M       DON221E__M
#define     M23C10M       DON280___M
#define     M23C11M       DON064PO_M
#define     M23C12M       DON064PC_M

#define     M23C00V       DON221A__V
#define     M23C01V       DON2211__V
#define     M23C02V       DON228A__V
#define     M23C03V       DON2212__V
#define     M23C04V       DON221C__V
#define     M23C05V       DON2293__V
#define     M23C06V       DON228C__V
#define     M23C07V       DON2294__V
#define     M23C08V       DON220E__V
#define     M23C09V       DON221E__V
#define     M23C10V       DON280___V
#define     M23C11V       DON064PO_V
#define     M23C12V       DON064PC_V

rec=3;

    if(M23C00M==SWITCH){ M23C00V=(M23C00V==OFF) then_ ON else_ OFF; }; M23C00M=OFF; 
    if(M23C01M==SWITCH){ M23C01V=(M23C01V==OFF) then_ ON else_ OFF; }; M23C01M=OFF; 
    if(M23C02M==SWITCH){ M23C02V=(M23C02V==OFF) then_ ON else_ OFF; }; M23C02M=OFF; 
    if(M23C03M==SWITCH){ M23C03V=(M23C03V==OFF) then_ ON else_ OFF; }; M23C03M=OFF; 
    if(M23C04M==SWITCH){ M23C04V=(M23C04V==OFF) then_ ON else_ OFF; }; M23C04M=OFF; 
    if(M23C05M==SWITCH){ M23C05V=(M23C05V==OFF) then_ ON else_ OFF; }; M23C05M=OFF; 
    if(M23C06M==SWITCH){ M23C06V=(M23C06V==OFF) then_ ON else_ OFF; }; M23C06M=OFF; 
    if(M23C07M==SWITCH){ M23C07V=(M23C07V==OFF) then_ ON else_ OFF; }; M23C07M=OFF; 
    if(M23C08M==SWITCH){ M23C08V=(M23C08V==OFF) then_ ON else_ OFF; }; M23C08M=OFF; 
    if(M23C09M==SWITCH){ M23C09V=(M23C09V==OFF) then_ ON else_ OFF; }; M23C09M=OFF; 
    if(M23C10M==SWITCH){ M23C10V=(M23C10V==OFF) then_ ON else_ OFF; }; M23C10M=OFF; 
    if(M23C11M==SWITCH){ M23C11V=(M23C11V==OFF) then_ ON else_ OFF; }; M23C11M=OFF; 
    if(M23C12M==SWITCH){ M23C12V=(M23C12V==OFF) then_ ON else_ OFF; }; M23C12M=OFF; 

    SetMODV (COMU2,rec, 0,  M23C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M23C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M23C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M23C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M23C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M23C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M23C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M23C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M23C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M23C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M23C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M23C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M23C12V,  0, 0);

//----------------------------------------------------------------------------
