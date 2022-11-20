//----------------------------------------------------------------------------
//  COM1, 7042, N0A
#define     M0AC00M       DON056___M
#define     M0AC01M       DON057___M
#define     M0AC02M       DON064___M
#define     M0AC03M       DON065___M
#define     M0AC04M       DON068___M
#define     M0AC05M       DON069___M
#define     M0AC06M       DON056A__M
#define     M0AC07M       DON057A__M
#define     M0AC08M       DON064A__M
#define     M0AC09M       DON065A__M
#define     M0AC10M       DON064B__M
#define     M0AC11M       DON065B__M
#define     M0AC12M       DON090___M

#define     M0AC00V       DON056___V
#define     M0AC01V       DON057___V
#define     M0AC02V       DON064___V
#define     M0AC03V       DON065___V
#define     M0AC04V       DON068___V
#define     M0AC05V       DON069___V
#define     M0AC06V       DON056A__V
#define     M0AC07V       DON057A__V
#define     M0AC08V       DON064A__V
#define     M0AC09V       DON065A__V
#define     M0AC10V       DON064B__V
#define     M0AC11V       DON065B__V
#define     M0AC12V       DON090___V

rec=10;

    if(M0AC00M==SWITCH){ M0AC00V=(M0AC00V==OFF) then_ ON else_ OFF; }; M0AC00M=OFF; 
    if(M0AC01M==SWITCH){ M0AC01V=(M0AC01V==OFF) then_ ON else_ OFF; }; M0AC01M=OFF; 
    if(M0AC02M==SWITCH){ M0AC02V=(M0AC02V==OFF) then_ ON else_ OFF; }; M0AC02M=OFF; 
    if(M0AC03M==SWITCH){ M0AC03V=(M0AC03V==OFF) then_ ON else_ OFF; }; M0AC03M=OFF; 
    if(M0AC04M==SWITCH){ M0AC04V=(M0AC04V==OFF) then_ ON else_ OFF; }; M0AC04M=OFF; 
    if(M0AC05M==SWITCH){ M0AC05V=(M0AC05V==OFF) then_ ON else_ OFF; }; M0AC05M=OFF; 
    if(M0AC06M==SWITCH){ M0AC06V=(M0AC06V==OFF) then_ ON else_ OFF; }; M0AC06M=OFF; 
    if(M0AC07M==SWITCH){ M0AC07V=(M0AC07V==OFF) then_ ON else_ OFF; }; M0AC07M=OFF; 
    if(M0AC08M==SWITCH){ M0AC08V=(M0AC08V==OFF) then_ ON else_ OFF; }; M0AC08M=OFF; 
    if(M0AC09M==SWITCH){ M0AC09V=(M0AC09V==OFF) then_ ON else_ OFF; }; M0AC09M=OFF; 
    if(M0AC10M==SWITCH){ M0AC10V=(M0AC10V==OFF) then_ ON else_ OFF; }; M0AC10M=OFF; 
    if(M0AC11M==SWITCH){ M0AC11V=(M0AC11V==OFF) then_ ON else_ OFF; }; M0AC11M=OFF; 
    if(M0AC12M==SWITCH){ M0AC12V=(M0AC12V==OFF) then_ ON else_ OFF; }; M0AC12M=OFF; 

    SetMODV (COMU1,rec, 0,  M0AC00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M0AC01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M0AC02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M0AC03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M0AC04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M0AC05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M0AC06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M0AC07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M0AC08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M0AC09V,  0, 0);
    SetMODV (COMU1,rec,10,  M0AC10V,  0, 0);
    SetMODV (COMU1,rec,11,  M0AC11V,  0, 0);
    SetMODV (COMU1,rec,12,  M0AC12V,  0, 0);

//----------------------------------------------------------------------------
