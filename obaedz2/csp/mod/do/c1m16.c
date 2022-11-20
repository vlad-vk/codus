//----------------------------------------------------------------------------
//  COM1, 7042, N16
#define     M16C00M       DON2131__M
#define     M16C01M       DON213N__M
#define     M16C02M       DON2132__M
#define     M16C03M       DON2141__M
#define     M16C04M       DON214N__M
#define     M16C05M       DON2142__M
#define     M16C06M       DON211A1_M
#define     M16C07M       DON211B1_M
#define     M16C08M       DON211C1_M
#define     M16C09M       DON211A2_M
#define     M16C10M       DON211B2_M
#define     M16C11M       DON211C2_M
#define     M16C12M       M16C12___M

#define     M16C00V       DON2131__V
#define     M16C01V       DON213N__V
#define     M16C02V       DON2132__V
#define     M16C03V       DON2141__V
#define     M16C04V       DON214N__V
#define     M16C05V       DON2142__V
#define     M16C06V       DON211A1_V
#define     M16C07V       DON211B1_V
#define     M16C08V       DON211C1_V
#define     M16C09V       DON211A2_V
#define     M16C10V       DON211B2_V
#define     M16C11V       DON211C2_V
#define     M16C12V       M16C12___V

rec=18;

    if(M16C00M==SWITCH){ M16C00V=(M16C00V==OFF) then_ ON else_ OFF; }; M16C00M=OFF; 
    if(M16C01M==SWITCH){ M16C01V=(M16C01V==OFF) then_ ON else_ OFF; }; M16C01M=OFF; 
    if(M16C02M==SWITCH){ M16C02V=(M16C02V==OFF) then_ ON else_ OFF; }; M16C02M=OFF; 
    if(M16C03M==SWITCH){ M16C03V=(M16C03V==OFF) then_ ON else_ OFF; }; M16C03M=OFF; 
    if(M16C04M==SWITCH){ M16C04V=(M16C04V==OFF) then_ ON else_ OFF; }; M16C04M=OFF; 
    if(M16C05M==SWITCH){ M16C05V=(M16C05V==OFF) then_ ON else_ OFF; }; M16C05M=OFF; 
    if(M16C06M==SWITCH){ M16C06V=(M16C06V==OFF) then_ ON else_ OFF; }; M16C06M=OFF; 
    if(M16C07M==SWITCH){ M16C07V=(M16C07V==OFF) then_ ON else_ OFF; }; M16C07M=OFF; 
    if(M16C08M==SWITCH){ M16C08V=(M16C08V==OFF) then_ ON else_ OFF; }; M16C08M=OFF; 
    if(M16C09M==SWITCH){ M16C09V=(M16C09V==OFF) then_ ON else_ OFF; }; M16C09M=OFF; 
    if(M16C10M==SWITCH){ M16C10V=(M16C10V==OFF) then_ ON else_ OFF; }; M16C10M=OFF; 
    if(M16C11M==SWITCH){ M16C11V=(M16C11V==OFF) then_ ON else_ OFF; }; M16C11M=OFF; 
    if(M16C12M==SWITCH){ M16C12V=(M16C12V==OFF) then_ ON else_ OFF; }; M16C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M16C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M16C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M16C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M16C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M16C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M16C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M16C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M16C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M16C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M16C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M16C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M16C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M16C12V,  0, 0);

//----------------------------------------------------------------------------
