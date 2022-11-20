//----------------------------------------------------------------------------
//  COM2, 7042, N2B
#define     M2BC00M       DON069B__M
#define     M2BC01M       DON069C__M
#define     M2BC02M       DON069D__M
#define     M2BC03M       DON069E__M
#define     M2BC04M       M2BC04___M
#define     M2BC05M       DON091B__M
#define     M2BC06M       DON091C__M
#define     M2BC07M       DON091D__M
#define     M2BC08M       DON091E__M
#define     M2BC09M       DON092B__M
#define     M2BC10M       DON092C__M
#define     M2BC11M       DON092D__M
#define     M2BC12M       DON092E__M

#define     M2BC00V       DON069B__V
#define     M2BC01V       DON069C__V
#define     M2BC02V       DON069D__V
#define     M2BC03V       DON069E__V
#define     M2BC04V       M2BC04___V
#define     M2BC05V       DON091B__V
#define     M2BC06V       DON091C__V
#define     M2BC07V       DON091D__V
#define     M2BC08V       DON091E__V
#define     M2BC09V       DON092B__V
#define     M2BC10V       DON092C__V
#define     M2BC11V       DON092D__V
#define     M2BC12V       DON092E__V

rec=14;

    if(M2BC00M==SWITCH){ M2BC00V=(M2BC00V==OFF) then_ ON else_ OFF; }; M2BC00M=OFF; 
    if(M2BC01M==SWITCH){ M2BC01V=(M2BC01V==OFF) then_ ON else_ OFF; }; M2BC01M=OFF; 
    if(M2BC02M==SWITCH){ M2BC02V=(M2BC02V==OFF) then_ ON else_ OFF; }; M2BC02M=OFF; 
    if(M2BC03M==SWITCH){ M2BC03V=(M2BC03V==OFF) then_ ON else_ OFF; }; M2BC03M=OFF; 
    if(M2BC04M==SWITCH){ M2BC04V=(M2BC04V==OFF) then_ ON else_ OFF; }; M2BC04M=OFF; 
    if(M2BC05M==SWITCH){ M2BC05V=(M2BC05V==OFF) then_ ON else_ OFF; }; M2BC05M=OFF; 
    if(M2BC06M==SWITCH){ M2BC06V=(M2BC06V==OFF) then_ ON else_ OFF; }; M2BC06M=OFF; 
    if(M2BC07M==SWITCH){ M2BC07V=(M2BC07V==OFF) then_ ON else_ OFF; }; M2BC07M=OFF; 
    if(M2BC08M==SWITCH){ M2BC08V=(M2BC08V==OFF) then_ ON else_ OFF; }; M2BC08M=OFF; 
    if(M2BC09M==SWITCH){ M2BC09V=(M2BC09V==OFF) then_ ON else_ OFF; }; M2BC09M=OFF; 
    if(M2BC10M==SWITCH){ M2BC10V=(M2BC10V==OFF) then_ ON else_ OFF; }; M2BC10M=OFF; 
    if(M2BC11M==SWITCH){ M2BC11V=(M2BC11V==OFF) then_ ON else_ OFF; }; M2BC11M=OFF; 
    if(M2BC12M==SWITCH){ M2BC12V=(M2BC12V==OFF) then_ ON else_ OFF; }; M2BC12M=OFF; 

    SetMODV (COMU2,rec, 0,  M2BC00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M2BC01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M2BC02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M2BC03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M2BC04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M2BC05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M2BC06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M2BC07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M2BC08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M2BC09V,  0, 0);
    SetMODV (COMU2,rec,10,  M2BC10V,  0, 0);
    SetMODV (COMU2,rec,11,  M2BC11V,  0, 0);
    SetMODV (COMU2,rec,12,  M2BC12V,  0, 0);

//----------------------------------------------------------------------------
