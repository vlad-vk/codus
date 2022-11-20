//----------------------------------------------------------------------------
//  COM2, 7042, N25
#define     M25C00M       DON266E__M
#define     M25C01M       DON251B1_M
#define     M25C02M       DON251C1_M
#define     M25C03M       DON251D1_M
#define     M25C04M       DON258E__M
#define     M25C05M       DON251B2_M
#define     M25C06M       DON251C2_M
#define     M25C07M       DON251D2_M
#define     M25C08M       DON092PO_M
#define     M25C09M       DON092PC_M
#define     M25C10M       M25C10___M
#define     M25C11M       M25C11___M
#define     M25C12M       M25C12___M

#define     M25C00V       DON266E__V
#define     M25C01V       DON251B1_V
#define     M25C02V       DON251C1_V
#define     M25C03V       DON251D1_V
#define     M25C04V       DON258E__V
#define     M25C05V       DON251B2_V
#define     M25C06V       DON251C2_V
#define     M25C07V       DON251D2_V
#define     M25C08V       DON092PO_V
#define     M25C09V       DON092PC_V
#define     M25C10V       M25C10___V
#define     M25C11V       M25C11___V
#define     M25C12V       M25C12___V

DON251D1_M=DON251E1_M;
DON251D1_V=DON251E1_V;
DON251D2_M=DON251E2_M;
DON251D2_V=DON251E2_V;

rec=5;

    if(M25C00M==SWITCH){ M25C00V=(M25C00V==OFF) then_ ON else_ OFF; }; M25C00M=OFF; 
    if(M25C01M==SWITCH){ M25C01V=(M25C01V==OFF) then_ ON else_ OFF; }; M25C01M=OFF; 
    if(M25C02M==SWITCH){ M25C02V=(M25C02V==OFF) then_ ON else_ OFF; }; M25C02M=OFF; 
    if(M25C03M==SWITCH){ M25C03V=(M25C03V==OFF) then_ ON else_ OFF; }; M25C03M=OFF; 
    if(M25C04M==SWITCH){ M25C04V=(M25C04V==OFF) then_ ON else_ OFF; }; M25C04M=OFF; 
    if(M25C05M==SWITCH){ M25C05V=(M25C05V==OFF) then_ ON else_ OFF; }; M25C05M=OFF; 
    if(M25C06M==SWITCH){ M25C06V=(M25C06V==OFF) then_ ON else_ OFF; }; M25C06M=OFF; 
    if(M25C07M==SWITCH){ M25C07V=(M25C07V==OFF) then_ ON else_ OFF; }; M25C07M=OFF; 
    if(M25C08M==SWITCH){ M25C08V=(M25C08V==OFF) then_ ON else_ OFF; }; M25C08M=OFF; 
    if(M25C09M==SWITCH){ M25C09V=(M25C09V==OFF) then_ ON else_ OFF; }; M25C09M=OFF; 
    if(M25C10M==SWITCH){ M25C10V=(M25C10V==OFF) then_ ON else_ OFF; }; M25C10M=OFF; 
    if(M25C11M==SWITCH){ M25C11V=(M25C11V==OFF) then_ ON else_ OFF; }; M25C11M=OFF; 
    if(M25C12M==SWITCH){ M25C12V=(M25C12V==OFF) then_ ON else_ OFF; }; M25C12M=OFF; 

    SetMODV (COMU2,rec, 0,  M25C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M25C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M25C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M25C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M25C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M25C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M25C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M25C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M25C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M25C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M25C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M25C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M25C12V,  0, 0);

//----------------------------------------------------------------------------
