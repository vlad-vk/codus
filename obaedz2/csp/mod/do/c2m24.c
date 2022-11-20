//----------------------------------------------------------------------------
//  COM2, 7042, N24
#define     M24C00M       DON2x00__M
#define     M24C01M       DON2x01__M
#define     M24C02M       DON2x02__M
#define     M24C03M       DON2x03__M
#define     M24C04M       DON2x04__M
#define     M24C05M       DON252F2_M
#define     M24C06M       DON252H2_M
#define     M24C07M       DON2x07__M
#define     M24C08M       M24C08___M
#define     M24C09M       M24C09___M
#define     M24C10M       DON215F__M
#define     M24C11M       DON215G__M
#define     M24C12M       DON215G__M

#define     M24C00V       DON2x00__V
#define     M24C01V       DON2x01__V
#define     M24C02V       DON2x02__V
#define     M24C03V       DON2x03__V
#define     M24C04V       DON2x04__V
#define     M24C05V       DON252F2_V
#define     M24C06V       DON252H2_V
#define     M24C07V       DON2x07__V
#define     M24C08V       M24C08___V
#define     M24C09V       M24C09___V
#define     M24C10V       DON215F__V
#define     M24C11V       DON215G__V
#define     M24C12V       DON215G__V

rec=4;

    if(M24C00M==SWITCH){ M24C00V=(M24C00V==OFF) then_ ON else_ OFF; }; M24C00M=OFF; 
    if(M24C01M==SWITCH){ M24C01V=(M24C01V==OFF) then_ ON else_ OFF; }; M24C01M=OFF; 
    if(M24C02M==SWITCH){ M24C02V=(M24C02V==OFF) then_ ON else_ OFF; }; M24C02M=OFF; 
    if(M24C03M==SWITCH){ M24C03V=(M24C03V==OFF) then_ ON else_ OFF; }; M24C03M=OFF; 
    if(M24C04M==SWITCH){ M24C04V=(M24C04V==OFF) then_ ON else_ OFF; }; M24C04M=OFF; 
    if(M24C05M==SWITCH){ M24C05V=(M24C05V==OFF) then_ ON else_ OFF; }; M24C05M=OFF; 
    if(M24C06M==SWITCH){ M24C06V=(M24C06V==OFF) then_ ON else_ OFF; }; M24C06M=OFF; 
    if(M24C07M==SWITCH){ M24C07V=(M24C07V==OFF) then_ ON else_ OFF; }; M24C07M=OFF; 
    if(M24C08M==SWITCH){ M24C08V=(M24C08V==OFF) then_ ON else_ OFF; }; M24C08M=OFF; 
    if(M24C09M==SWITCH){ M24C09V=(M24C09V==OFF) then_ ON else_ OFF; }; M24C09M=OFF; 
    if(M24C10M==SWITCH){ M24C10V=(M24C10V==OFF) then_ ON else_ OFF; }; M24C10M=OFF; 
    if(M24C11M==SWITCH){ M24C11V=(M24C11V==OFF) then_ ON else_ OFF; }; M24C11M=OFF; 
    if(M24C12M==SWITCH){ M24C12V=(M24C12V==OFF) then_ ON else_ OFF; }; M24C12M=OFF;

    SetMODV (COMU2,rec, 0,  M24C00V,  0, 0);
    SetMODV (COMU2,rec, 1,  M24C01V,  0, 0);
    SetMODV (COMU2,rec, 2,  M24C02V,  0, 0);
    SetMODV (COMU2,rec, 3,  M24C03V,  0, 0);
    SetMODV (COMU2,rec, 4,  M24C04V,  0, 0);
    SetMODV (COMU2,rec, 5,  M24C05V,  0, 0);
    SetMODV (COMU2,rec, 6,  M24C06V,  0, 0);
    SetMODV (COMU2,rec, 7,  M24C07V,  0, 0);
    SetMODV (COMU2,rec, 8,  M24C08V,  0, 0);
    SetMODV (COMU2,rec, 9,  M24C09V,  0, 0);
    SetMODV (COMU2,rec,10,  M24C10V,  0, 0);
    SetMODV (COMU2,rec,11,  M24C11V,  0, 0);
    SetMODV (COMU2,rec,12,  M24C12V,  0, 0);

//----------------------------------------------------------------------------
