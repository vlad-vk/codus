//----------------------------------------------------------------------------
//  COM1, 7042, N0B
#define     M0BC00M       DON038A__M
#define     M0BC01M       DON038C__M
#define     M0BC02M       DON068A__M
#define     M0BC03M       DON069A__M
#define     M0BC04M       DON091A__M
#define     M0BC05M       DON092A__M
#define     M0BC06M       DON092K__M
#define     M0BC07M       M0BC07___M
#define     M0BC08M       M0BC08___M
#define     M0BC09M       M0BC09___M
#define     M0BC10M       DON2x12__M
#define     M0BC11M       M0BC11___M
#define     M0BC12M       M0BC12___M

#define     M0BC00V       DON038A__V
#define     M0BC01V       DON038C__V
#define     M0BC02V       DON068A__V
#define     M0BC03V       DON069A__V
#define     M0BC04V       DON091A__V
#define     M0BC05V       DON092A__V
#define     M0BC06V       DON092K__V
#define     M0BC07V       M0BC07___V
#define     M0BC08V       M0BC08___V
#define     M0BC09V       M0BC09___V
#define     M0BC10V       DON2x12__V
#define     M0BC11V       M0BC11___V
#define     M0BC12V       M0BC12___V

rec=11;

    if(M0BC00M==SWITCH){ M0BC00V=(M0BC00V==OFF) then_ ON else_ OFF; }; M0BC00M=OFF; 
    if(M0BC01M==SWITCH){ M0BC01V=(M0BC01V==OFF) then_ ON else_ OFF; }; M0BC01M=OFF; 
    if(M0BC02M==SWITCH){ M0BC02V=(M0BC02V==OFF) then_ ON else_ OFF; }; M0BC02M=OFF; 
    if(M0BC03M==SWITCH){ M0BC03V=(M0BC03V==OFF) then_ ON else_ OFF; }; M0BC03M=OFF; 
    if(M0BC04M==SWITCH){ M0BC04V=(M0BC04V==OFF) then_ ON else_ OFF; }; M0BC04M=OFF; 
    if(M0BC05M==SWITCH){ M0BC05V=(M0BC05V==OFF) then_ ON else_ OFF; }; M0BC05M=OFF; 
    if(M0BC06M==SWITCH){ M0BC06V=(M0BC06V==OFF) then_ ON else_ OFF; }; M0BC06M=OFF; 
    if(M0BC07M==SWITCH){ M0BC07V=(M0BC07V==OFF) then_ ON else_ OFF; }; M0BC07M=OFF; 
    if(M0BC08M==SWITCH){ M0BC08V=(M0BC08V==OFF) then_ ON else_ OFF; }; M0BC08M=OFF; 
    if(M0BC09M==SWITCH){ M0BC09V=(M0BC09V==OFF) then_ ON else_ OFF; }; M0BC09M=OFF; 
//  if(M0BC10M==SWITCH){ M0BC10V=(M0BC10V==OFF) then_ ON else_ OFF; }; M0BC10M=OFF;
    M0BC10V=M0BC10M;
    if(M0BC11M==SWITCH){ M0BC11V=(M0BC11V==OFF) then_ ON else_ OFF; }; M0BC11M=OFF; 
    if(M0BC12M==SWITCH){ M0BC12V=(M0BC12V==OFF) then_ ON else_ OFF; }; M0BC12M=OFF; 

    SetMODV (COMU1,rec, 0,  M0BC00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M0BC01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M0BC02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M0BC03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M0BC04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M0BC05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M0BC06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M0BC07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M0BC08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M0BC09V,  0, 0);
    SetMODV (COMU1,rec,10,  M0BC10V,  0, 0);
    SetMODV (COMU1,rec,11,  M0BC11V,  0, 0);
    SetMODV (COMU1,rec,12,  M0BC12V,  0, 0);

//----------------------------------------------------------------------------
