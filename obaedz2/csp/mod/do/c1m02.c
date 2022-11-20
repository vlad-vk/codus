//----------------------------------------------------------------------------
//  COM1, 7042, N02
#define     M02C00M       DON210N__M
#define     M02C01M       DON210O__M
#define     M02C02M       DON210P__M
#define     M02C03M       DON210R__M
#define     M02C04M       DON210S__M
#define     M02C05M       DON210T__M
#define     M02C06M       DON210W__M
#define     M02C07M       DON210X__M
#define     M02C08M       M02C08___M
#define     M02C09M       M02C09___M
#define     M02C10M       DON092N__M
#define     M02C11M       M02C11___M
#define     M02C12M       M02C12___M

#define     M02C00V       DON210N__V
#define     M02C01V       DON210O__V
#define     M02C02V       DON210P__V
#define     M02C03V       DON210R__V
#define     M02C04V       DON210S__V
#define     M02C05V       DON210T__V
#define     M02C06V       DON210W__V
#define     M02C07V       DON210X__V
#define     M02C08V       M02C08___V
#define     M02C09V       M02C09___V
#define     M02C10V       DON092N__V
#define     M02C11V       M02C11___V
#define     M02C12V       M02C12___V

rec=2;

    // ручное переключение с компьютера выходов на исполнители
    if(M02C00M==SWITCH){ M02C00V=(M02C00V==OFF) then_ ON else_ OFF; }; M02C00M=OFF; 
    if(M02C01M==SWITCH){ M02C01V=(M02C01V==OFF) then_ ON else_ OFF; }; M02C01M=OFF; 
    if(M02C02M==SWITCH){ M02C02V=(M02C02V==OFF) then_ ON else_ OFF; }; M02C02M=OFF; 
    if(M02C03M==SWITCH){ M02C03V=(M02C03V==OFF) then_ ON else_ OFF; }; M02C03M=OFF; 
    if(M02C04M==SWITCH){ M02C04V=(M02C04V==OFF) then_ ON else_ OFF; }; M02C04M=OFF; 
    if(M02C05M==SWITCH){ M02C05V=(M02C05V==OFF) then_ ON else_ OFF; }; M02C05M=OFF; 
    if(M02C06M==SWITCH){ M02C06V=(M02C06V==OFF) then_ ON else_ OFF; }; M02C06M=OFF; 
    if(M02C07M==SWITCH){ M02C07V=(M02C07V==OFF) then_ ON else_ OFF; }; M02C07M=OFF; 
    if(M02C08M==SWITCH){ M02C08V=(M02C08V==OFF) then_ ON else_ OFF; }; M02C08M=OFF; 
    if(M02C09M==SWITCH){ M02C09V=(M02C09V==OFF) then_ ON else_ OFF; }; M02C09M=OFF; 
    if(M02C10M==SWITCH){ M02C10V=(M02C10V==OFF) then_ ON else_ OFF; }; M02C10M=OFF; 
    if(M02C11M==SWITCH){ M02C11V=(M02C11V==OFF) then_ ON else_ OFF; }; M02C11M=OFF; 
    if(M02C12M==SWITCH){ M02C12V=(M02C12V==OFF) then_ ON else_ OFF; }; M02C12M=OFF; 

    // выход на каналы модулей УСО:
    SetMODV (COMU1,rec, 0,  M02C00V,  0, 0);
    SetMODV (COMU1,rec, 1,  M02C01V,  0, 0);
    SetMODV (COMU1,rec, 2,  M02C02V,  0, 0);
    SetMODV (COMU1,rec, 3,  M02C03V,  0, 0);
    SetMODV (COMU1,rec, 4,  M02C04V,  0, 0);
    SetMODV (COMU1,rec, 5,  M02C05V,  0, 0);
    SetMODV (COMU1,rec, 6,  M02C06V,  0, 0);
    SetMODV (COMU1,rec, 7,  M02C07V,  0, 0);
    SetMODV (COMU1,rec, 8,  M02C08V,  0, 0);
    SetMODV (COMU1,rec, 9,  M02C09V,  0, 0);
    SetMODV (COMU1,rec,10,  M02C10V,  0, 0);
    SetMODV (COMU1,rec,11,  M02C11V,  0, 0);
    SetMODV (COMU1,rec,12,  M02C12V,  0, 0);

//----------------------------------------------------------------------------
