//----------------------------------------------------------------------------
//  COM2, 7042, N43
#define     M43C00M       DON221B__M
#define     M43C01M       DON229B1_M
#define     M43C02M       DON228B__M
#define     M43C03M       DON229B2_M
#define     M43C04M       DON221D__M
#define     M43C05M       DON229D1_M
#define     M43C06M       DON228D__M
#define     M43C07M       DON229D2_M
#define     M43C08M       DON220F__M
#define     M43C09M       DON221F__M
#define     M43C10M       DON280S__M
#define     M43C11M       M43C11___M
#define     M43C12M       M43C12___M

#define     M43C00V       DON221B__V
#define     M43C01V       DON229B1_V
#define     M43C02V       DON228B__V
#define     M43C03V       DON229B2_V
#define     M43C04V       DON221D__V
#define     M43C05V       DON229D1_V
#define     M43C06V       DON228D__V
#define     M43C07V       DON229D2_V
#define     M43C08V       DON220F__V
#define     M43C09V       DON221F__V
#define     M43C10V       DON280S__V
#define     M43C11V       M43C11___V
#define     M43C12V       M43C12___V

rec=18;

    if(M43C00M==SWITCH){ M43C00V=(M43C00V==OFF) then_ ON else_ OFF; }; M43C00M=OFF; 
    if(M43C01M==SWITCH){ M43C01V=(M43C01V==OFF) then_ ON else_ OFF; }; M43C01M=OFF; 
    if(M43C02M==SWITCH){ M43C02V=(M43C02V==OFF) then_ ON else_ OFF; }; M43C02M=OFF; 
    if(M43C03M==SWITCH){ M43C03V=(M43C03V==OFF) then_ ON else_ OFF; }; M43C03M=OFF; 
    if(M43C04M==SWITCH){ M43C04V=(M43C04V==OFF) then_ ON else_ OFF; }; M43C04M=OFF; 
    if(M43C05M==SWITCH){ M43C05V=(M43C05V==OFF) then_ ON else_ OFF; }; M43C05M=OFF; 
    if(M43C06M==SWITCH){ M43C06V=(M43C06V==OFF) then_ ON else_ OFF; }; M43C06M=OFF; 
    if(M43C07M==SWITCH){ M43C07V=(M43C07V==OFF) then_ ON else_ OFF; }; M43C07M=OFF; 
    if(M43C08M==SWITCH){ M43C08V=(M43C08V==OFF) then_ ON else_ OFF; }; M43C08M=OFF; 
    if(M43C09M==SWITCH){ M43C09V=(M43C09V==OFF) then_ ON else_ OFF; }; M43C09M=OFF; 
    if(M43C10M==SWITCH){ M43C10V=(M43C10V==OFF) then_ ON else_ OFF; }; M43C10M=OFF; 
    if(M43C11M==SWITCH){ M43C11V=(M43C11V==OFF) then_ ON else_ OFF; }; M43C11M=OFF; 
    if(M43C12M==SWITCH){ M43C12V=(M43C12V==OFF) then_ ON else_ OFF; }; M43C12M=OFF; 

    SetMODV (COMU2,rec, 0,  M43C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M43C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M43C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M43C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M43C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M43C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M43C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M43C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M43C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M43C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M43C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M43C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M43C12V,  0, 0);

//----------------------------------------------------------------------------
