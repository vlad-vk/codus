//----------------------------------------------------------------------------
//  COM2, 7042, N2A
#define     M2AC00M       DON056E__M
#define     M2AC01M       DON057E__M
#define     M2AC02M       DON064E__M
#define     M2AC03M       DON065E__M
#define     M2AC04M       DON056C__M
#define     M2AC05M       DON057C__M
#define     M2AC06M       DON064C__M
#define     M2AC07M       DON065C__M
#define     M2AC08M       DON068B__M
#define     M2AC09M       DON068C__M
#define     M2AC10M       DON068D__M
#define     M2AC11M       DON068E__M
#define     M2AC12M       M2AC12___M

#define     M2AC00V       DON056E__V
#define     M2AC01V       DON057E__V
#define     M2AC02V       DON064E__V
#define     M2AC03V       DON065E__V
#define     M2AC04V       DON056C__V
#define     M2AC05V       DON057C__V
#define     M2AC06V       DON064C__V
#define     M2AC07V       DON065C__V
#define     M2AC08V       DON068B__V
#define     M2AC09V       DON068C__V
#define     M2AC10V       DON068D__V
#define     M2AC11V       DON068E__V
#define     M2AC12V       M2AC12___V

rec=13;

    if(M2AC00M==SWITCH){ M2AC00V=(M2AC00V==OFF) then_ ON else_ OFF; }; M2AC00M=OFF; 
    if(M2AC01M==SWITCH){ M2AC01V=(M2AC01V==OFF) then_ ON else_ OFF; }; M2AC01M=OFF; 
    if(M2AC02M==SWITCH){ M2AC02V=(M2AC02V==OFF) then_ ON else_ OFF; }; M2AC02M=OFF; 
    if(M2AC03M==SWITCH){ M2AC03V=(M2AC03V==OFF) then_ ON else_ OFF; }; M2AC03M=OFF; 
    if(M2AC04M==SWITCH){ M2AC04V=(M2AC04V==OFF) then_ ON else_ OFF; }; M2AC04M=OFF; 
    if(M2AC05M==SWITCH){ M2AC05V=(M2AC05V==OFF) then_ ON else_ OFF; }; M2AC05M=OFF; 
    if(M2AC06M==SWITCH){ M2AC06V=(M2AC06V==OFF) then_ ON else_ OFF; }; M2AC06M=OFF; 
    if(M2AC07M==SWITCH){ M2AC07V=(M2AC07V==OFF) then_ ON else_ OFF; }; M2AC07M=OFF; 
    if(M2AC08M==SWITCH){ M2AC08V=(M2AC08V==OFF) then_ ON else_ OFF; }; M2AC08M=OFF; 
    if(M2AC09M==SWITCH){ M2AC09V=(M2AC09V==OFF) then_ ON else_ OFF; }; M2AC09M=OFF; 
    if(M2AC10M==SWITCH){ M2AC10V=(M2AC10V==OFF) then_ ON else_ OFF; }; M2AC10M=OFF; 
    if(M2AC11M==SWITCH){ M2AC11V=(M2AC11V==OFF) then_ ON else_ OFF; }; M2AC11M=OFF; 
    if(M2AC12M==SWITCH){ M2AC12V=(M2AC12V==OFF) then_ ON else_ OFF; }; M2AC12M=OFF; 

    SetMODV (COMU2,rec, 0,  M2AC00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M2AC01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M2AC02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M2AC03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M2AC04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M2AC05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M2AC06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M2AC07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M2AC08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M2AC09V,  0, 0);
    SetMODV (COMU2,rec,10,  M2AC10V,  0, 0);
    SetMODV (COMU2,rec,11,  M2AC11V,  0, 0);
    SetMODV (COMU2,rec,12,  M2AC12V,  0, 0);

//----------------------------------------------------------------------------
