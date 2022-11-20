//----------------------------------------------------------------------------
//  COM1, 7042, N15
#define     M15C00M       DON206N__M
#define     M15C01M       DON2081__M
#define     M15C02M       DON208N__M
#define     M15C03M       DON2082__M
#define     M15C04M       DON2091__M
#define     M15C05M       DON209N__M
#define     M15C06M       DON2092__M
#define     M15C07M       DON206K__M
#define     M15C08M       DON2071__M
#define     M15C09M       DON207N__M
#define     M15C10M       DON207P__M
#define     M15C11M       DON2072__M
#define     M15C12M       DON212N__M

#define     M15C00V       DON206N__V
#define     M15C01V       DON2081__V
#define     M15C02V       DON208N__V
#define     M15C03V       DON2082__V
#define     M15C04V       DON2091__V
#define     M15C05V       DON209N__V
#define     M15C06V       DON2092__V
#define     M15C07V       DON206K__V
#define     M15C08V       DON2071__V
#define     M15C09V       DON207N__V
#define     M15C10V       DON207P__V
#define     M15C11V       DON2072__V
#define     M15C12V       DON212N__V

rec=17;

    if(M15C00M==SWITCH){ M15C00V=(M15C00V==OFF) then_ ON else_ OFF; }; M15C00M=OFF; 
    if(M15C01M==SWITCH){ M15C01V=(M15C01V==OFF) then_ ON else_ OFF; }; M15C01M=OFF; 
    if(M15C02M==SWITCH){ M15C02V=(M15C02V==OFF) then_ ON else_ OFF; }; M15C02M=OFF; 
    if(M15C03M==SWITCH){ M15C03V=(M15C03V==OFF) then_ ON else_ OFF; }; M15C03M=OFF; 
    if(M15C04M==SWITCH){ M15C04V=(M15C04V==OFF) then_ ON else_ OFF; }; M15C04M=OFF; 
    if(M15C05M==SWITCH){ M15C05V=(M15C05V==OFF) then_ ON else_ OFF; }; M15C05M=OFF; 
    if(M15C06M==SWITCH){ M15C06V=(M15C06V==OFF) then_ ON else_ OFF; }; M15C06M=OFF; 
    if(M15C07M==SWITCH){ M15C07V=(M15C07V==OFF) then_ ON else_ OFF; }; M15C07M=OFF; 
    if(M15C08M==SWITCH){ M15C08V=(M15C08V==OFF) then_ ON else_ OFF; }; M15C08M=OFF; 
    if(M15C09M==SWITCH){ M15C09V=(M15C09V==OFF) then_ ON else_ OFF; }; M15C09M=OFF; 
    if(M15C10M==SWITCH){ M15C10V=(M15C10V==OFF) then_ ON else_ OFF; }; M15C10M=OFF; 
    if(M15C11M==SWITCH){ M15C11V=(M15C11V==OFF) then_ ON else_ OFF; }; M15C11M=OFF; 
    if(M15C12M==SWITCH){ M15C12V=(M15C12V==OFF) then_ ON else_ OFF; }; M15C12M=OFF; 

    SetMODV (COMU1,rec, 0,  M15C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M15C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M15C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M15C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M15C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M15C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M15C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M15C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M15C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M15C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M15C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M15C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M15C12V,  0, 0);

//----------------------------------------------------------------------------
