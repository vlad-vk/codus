# coding:cp866
#-----------------------------------------------------------------------------
#  ฎฌฌ ญค๋ ํโฎฃฎ ไ ฉซ  ข๋ง๋ข ๎โแ๏ 18 เ ง/แฅชใญคใ (ช ฆค๋ฉ ฏฎซ์งฎข โฅซ์แชจฉ โจช)
#  p0000 - (0) ฏฅเฅฌฅญญ๋ฅ ฎก้ฅฃฎ ฌ แแจข  (ก ง๋ ช ญ ซฎข)
#  l0000 - (1) ฏฅเฅฌฅญญ๋ฅ ซฎช ซ์ญฎฃฎ ฌ แแจข 
#  c0000 - ฏฅเฅฌฅญญ๋ฅ ฌ แแจข  COM ฏฎเโ 
#  n0000 - ฏฅเฅฌฅญญ๋ฅ ฌ แแจข  NetBIOS
#  t0000 - ฏฅเฅฌฅญญ๋ฅ ฌ แแจข  TCPIP
#  y0000 - (6) ฏฅเฅฌฅญญ๋ฅ ฌ แแจข  ชฎฌฌ ญค๋ 'y'
#  x0000 - (7) ขเฅฌฅญญ๋ฅ  ฏฅเฅฌฅญญ๋ฅ
#-----------------------------------------------------------------------------


#   :
#-----------------------------------------------------------------------------
   %            = 0                      ;
   %            = 1                      ;
   %            = 0                      ;
   %            = 1                      ;
   %            = 0                      ;
   %             = 1                      ;
#--------------------------------------------
   %_               = 787878         ;
   %_               = 454545         ;
   %_           = 12             ;
   %_            = 56             ;
   %__        = 90             ;
   %__       = x0031          ;
   %__        = x0032          ;
   %___    = x0033          ;
#--------------------------------------------
   %_              = 5              ;
   %_              = 12             ;
   %_              = 3              ;
   %_S              = 19             ;
   %_F11            = 57             ;
   %_F12            = 58             ;
   %_ESC            = 59             ;
   %_ENTER          = 67             ;
   %_ZERO           = 0              ;
   %__    = x0023          ;
   %__    = x0024          ;
#--------------------------------------------
   %_           = l0004          ;
   %_      = l0032          ;
   %_        = l0007          ;
   %_   = l0005          ;
   %_    = x0030          ;
   %_            = l0006          ;
#--------------------------------------------
   %__ = l0019          ;
   %___  = l0069          ;
   %____  = y0069          ;
#--------------------------------------------
   %_          = x0101          ;
   %_          = x0100          ;
   %_          = l0041          ;
   %_          = x0001          ;
   %           = l0043          ;
   %_1         = x0002          ;
   %_      = x0003          ;
#--------------------------------------------
   %_           = l0031          ;
   %__   = x0025          ;
   %__ = l0020          ;
   %__      = l0021          ;
   %___       = l0045          ;
   %__       = l0046          ;
   %___       = l0047          ;
   %__       = l0048          ;
#--------------------------------------------
   %__ = l0033          ;
   %__  = l0034          ;
   %_       = l0035          ;
#--------------------------------------------


#   :
#-----------------------------------------------------------------------------
#  ฎฏเฅคฅซฅญจฅ ฏ เฎซฅฉ
   %__       = %_      ;
   %__       = %_      ;
#-----------------------------------------------------------------------------
#  ฌ ชแ ชฎซ แโเฎช โฅชใ้ ไ ฉซ  ฏเฎแฌฎโเ  (คซ๏ ข๋ขฎค  ชฎซ แโเฎช)
   %____ = %___    ;
#-----------------------------------------------------------------------------
#  ใแโ ญฎขช  ไซ ฃ  ญฎขฎฉ แฅชใญค๋
   %_ = %                    ;
if %_ ! %_          ;
   %_ = %                    ;
fi                                          ;
   %_ = %_          ;
#-----------------------------------------------------------------------------
#  ช ฆคใ๎ ญฎขใ๎ แฅชใญคใ                     ;
if %_ = %                    ;
   x0047 = x0047 + 1
fi                                          ;
#----------
#  ใแโ ญฎขช  ฏฅเฅฌฅญญ๋ๅ ฎคจญ เ ง ข ญ ็ ซฅ ฏเฎฃเ ฌฌ๋
if l0014 = 1                                ; 
   l0014 = 2                                ; ซ ฃ ง ฏใแช  ฏเฎฃเ ฌฌ๋ CODUS
   x0046 = 0                                ;  ฃ ฃฅญฅเ ๆจจ ฎโ็ฅโ 
   x0047 = 1                                ; ็ฅโ็จช แฅชใญค เ กฎโ๋ ฏเฎฃเ ฌฌ๋
   x0048 = 0                                ; ซ ฃ ฃฅญฅเ ๆจจ ฎโ็ฅโ 
   x0049 = 1                                ; ็ฅโ็จช แฅชใญค ข ฃฅญฅเ ๆจจ ฎโ็ฅโ 
   l0077 = 1
fi                                          ;
#  ช ฆค๋ฅ ญฎข๋ฅ แใโชจ เ กฎโ๋ ฏเฎฃเ ฌฌ๋
if x0047 = 86400                            ;
   x0047 = 1                                ;
   x0049 = 1                                ;
fi                                          ;
#-----------------------------------------------------------------------------


#    ""  :
#-----------------------------------------------------------------------------
   %_ = %          ;
if $ErrBell1_V ! %                 ; # ฅแซจ ใแโ ญฎขซฅญ ไซ ฃ งขฎญช 
   %_ = %           ;
fi                                     ;
if $ErrBell3_V ! %                 ; 
   %_ = %           ;
fi                                     ;
if $ErrBell5_V ! %                 ; 
   %_ = %           ;
fi                                     ;
if %_ ! %          ; # ฅแซจ ใแโ ญฎขซฅญ ไซ ฃ งขฎญช  -
   %_ = %_ + 1 ; # แ็ฅโ โ์ โจชจ
el                                     ;
   %  = %              ; # ฏฅเฅฌฅญ จง ซฎช ซ ก ง๋ 
fi                                     ; # คซ๏ ข๋ขฎค   ญจฌจเฎข ญญฎฃฎ งญ ็ช  (!)
if %_   >  9               ;
   %_   =  0               ; # ช ฆค๋ฅ ฏฎซ แฅชใญค๋ ฌฅญ๏โ์ 
   if % >  0               ; # จงฎกเ ฆฅญจฅ (ฌจฃ ๎้จฉ งญ ็ฅช)
      % =  0               ;
   el                                  ;
      if %_1 = 1           ;
         %   = 2           ;
      el                               ;
         %   = 1           ;
      fi                               ;
      %_1 = %  ;
   fi                                  ;
fi                                     ;
#-----------------------------------------------------------------------------


#      :
#-----------------------------------------------------------------------------
%__ = 0  ;    # ไซ ฃ ง ฏเฅโ  จงฌฅญฅญจฉ
%__      = 0  ;    # ไซ ฃ ง ฏเฅโ  ฌฅญ๎

%__    = %            ; # ํชเ ญ ชฎญโเฎซจเใฅโแ๏ ฏ เฎซฅฌ

if %_ = 3                        ; # ํชเ ญ "" (E 3)
   %__ = %             ;
fi                                          ;
if %_ = 8                        ; # ํชเ ญ ""
   %__ = %             ;
fi                                          ;
if %_ = 4                        ; # ํชเ ญ "" | ""
   %__ = %             ;
fi                                          ;
if %_ = 5                        ; # ํชเ ญ ""
   %__ = %             ;
fi                                          ;
#-----------------------------------------------------------------------------


#     "1" จ "2"
#-----------------------------------------------------------------------------
if %_ = %_F11           ; # ข๋กเ ญ ฏฅเฅๅฎค ญ  ํชเ ญ "1"
   if %__  ! %___ ; # ฅแซจ ญฅ ขขฅคฅญ ฏ เฎซ์  จ 
      %_   = %_ZERO     ;
      %_ = %              ; # ชซ ขจ่จ (ญจช ชจๅ คฅฉแโขจฉ)
      %__ = 4            ;
      %__  = 10           ;
      %_  = %              ;
   fi                                        ;
fi                                           ;
#---------------------------------------------
if %_ = %_F12           ; # ข๋กเ ญ ฏฅเฅๅฎค ญ  ํชเ ญ "2"
   if %__  ! %___ ;
      %_   = %_ZERO     ;
      %_ = %              ;
      %__ = 4            ;
      %__  = 60           ;
      %_  = %              ;
   fi                                        ;
fi                                           ;
#-----------------------------------------------------------------------------


#  ฏเจ ญ ฆ โจจ ชซ ขจ่จ ESC ฏฎแซฅ ง ชเ๋โจ๏ ฎชญ  ขขฎค  จซจ ง ฏเฎแ -
#  แญจฌ ฅโแ๏ งขใชฎขฎฉ แจฃญ ซ
#-----------------------------------------------------------------------------
if %_ > 0                      ; # ฏฎแซฅ ญ ฆ โ ชซ ขจ่จ ESC 
   if %_    = %                    ; # ฃฅญฅเจเใฅโแ๏
      %_  = %_   ; # ญ ฆ โจฅ ชซ ขจ่จ 'S' คซ๏ 
      %_  = %_ZERO      ; # แญ๏โจ๏ แจฃญ ซ  ฎ่จกชจ
      %_    = %               ;
      %_ = %_ZERO      ; # แกเฎแจโ์ ชฎค ฏฎแซ ฃฅญฅเจเ 
   fi                                            ; # ชซ ขจ่จ ง ฏเ ฎฏฅเ โฎเ 
fi                                               ;
if %_ = %_ESC               ; # ฅแซจ ญ ฆ โ  ชซ ขจ่  ESC
   %_  = %_S            ; # ใแโ ญฎขจโ์ ญ ฆ โจฅ ชซ ขจ่จ
fi                                               ; # 'S' คซ๏  แซฅค ๆจชซ 
if %_ = %_ESC          ; # ชซ ขจ่ ESC ฃฅญฅเจเ ง ฏเฎแ
   %_  = %_S            ; # ใแโ ญฎขจโ์ ญ ฆ โจฅ ชซ ขจ่จ 
fi                                               ; # 'S' คซ๏ แซฅค ๆจชซ 
#-----------------------------------------------------------------------------



#     :
#-----------------------------------------------------------------------------
if %_  = %                          ;
   if %__  ! %___      ;
      if %__   = %           ;
         %__ = %           ;
         %__      = %           ;
         if %_     = %_ENTER ;
            %__ = 5           ;
            %__  = 10          ;
            %_    = %           ;
         fi                                       ;
      fi                                          ;
      # แซจ ญ ฆ โ  ชซ ขจ่  ''() จ ญฅ ขขฅคฅญ ฏ เฎซ์- ฏเฅคใฏเฅฆคฅญจฅ
      if %_        = %_     ;        
         %_        = %_ZERO  ;
         %_      = %           ;
         %__ = 4              ;
         %__  = 10             ;
         %_       = %           ;
      fi                                          ;
   fi                                             ;
   if %__  ! %___      ;
      if %__   = 2              ;
         %__ = %           ;
         %__      = %           ;
         if %_     = %_ENTER ;
            %__ = 7           ;
            %__  = 10          ;
            %_    = %           ;
         fi                                       ;
      fi                                          ;
      # แซจ ญ ฆ โ  ชซ ขจ่  ''() จ ญฅ ขขฅคฅญ ฏ เฎซ์-ฏเฅคใฏเฅฆคฅญจฅ
      if %_        = %_     ;        
         %_        = %_ZERO  ;
         %_      = %           ;
         %__ = 6              ;
         %__  = 10             ;
         %_       = %           ;
      fi                                          ;
   fi                                             ;
fi                                                ;
#-----------------------------------------------------------------------------


# ขโฎฌ โจ็ฅแช ๏ ฃฅญฅเ ๆจ๏ ฎโ็ฅโฎข จ ง ฏจแ์ จๅ ข ไ ฉซ
# -----------------------------------------------------------------------------
%_  = 7
%_1 = 7
%_2 = 8
%_3 = 9
%_  = 7

# ---------                                 ;
#  ็ ซฎ ฃฅญฅเ ๆจจ ฎโ็ฅโ                    ;
if x0046 = 0                                ;
if l0039 = %_                   ;  แ
if l0041 = %_                   ; ฅชใญค 

l0007 = 0                                   ;
if l0040 = %_1                  ; จญใโ 
l0007 = 446                                 ; ฎค ญ ฆ โฎฉ ชซ ขจ่จ (ฅญ๎ - ฎโฅซ1)
fi                                          ; 

if l0040 = %_2                  ; จญใโ 
l0007 = 447                                 ; ฎค ญ ฆ โฎฉ ชซ ขจ่จ (ฅญ๎ - ฎโฅซ2)
fi                                          ;

if l0007 > 0                                ; 
l0032 = 1                                   ; ซ ฃ ขขฎค  ชฎค  ญ ฆ โฎฉ ชซ ขจ่จ
x0046 = 1                                   ; ซฅคใ๎้จฉ ่ ฃ ฃฅญฅเ ๆจจ ฎโ็ฅโ 
x0049 = x0047                               ; ฅชใ้จฉ แ็ฅโ็จช ญฎขฎฉ แฅชใญค๋
x0048 = 1                                   ; 
fi                                          ;

fi                                          ;
fi                                          ;
fi                                          ;

# ---------
# ขฎค คญ๏ ญฅคฅซจ:                          ;
if x0046 = 1                                ;  ฃ ฃฅญฅเ ๆจจ
if x0049 ! x0047                            ; แซจ ฏเฎ่ซ  แฅชใญค 
   o_TEST_LOC_018:#1.0018#                  ;
   x0050 = l0018 - 1                        ; เฅค๋คใ้จฉ คฅญ์ ญฅคฅซจ
if x0050 < 0                                ;
   x0050 = 6                                ;
fi                                          ;
$CurDayWk_M = x0050                         ; ฅญ์ ญฅคฅซจ ง  ชฎโฎเ๋ฉ ญใฆญฎ แฃฅญฅเจเฎข โ์ ฎโ็ฅโ
x0046 = 2                                   ; ซฅคใ๎้จฉ ่ ฃ ฃฅญฅเ ๆจจ ฎโ็ฅโ 
x0049 = x0047 + 15                          ; ฅชใ้จฉ แ็ฅโ็จช ญฎขฎฉ แฅชใญค๋ (ฆค โ์ 15แฅช คซ๏ จงฌฅญฅญจ๏ ขแฅๅ ฏฅเฅฌฅญญ๋ๅ)
o_CurWeekDay_M:#CurDayWk_M# 
o_CurWeekDay_V:#CurDayWk_V# 
o_TEST_TMP_050:#7.0050# 
o_TEST_TMP_047:#7.0047# 
fi                                          ;
fi                                          ;

# ----------                                ;
#  ฆ โ์ ชญฎฏชใ "" ญ  ํชเ ญฅ       ;
if x0046 = 2                                ;  ฃ ฃฅญฅเ ๆจจ
if x0049 < x0047                            ; แซจ ฏเฎ่ฅซ ฎกฌฅญ ฏฎ แฅโจ
l0007 = 303                                 ; ฎค ญ ฆ โฎฉ ชซ ขจ่จ
l0032 = 1                                   ; ซ ฃ ขขฎค  ชฎค  ญ ฆ โฎฉ ชซ ขจ่จ
x0046 = 3                                   ; ซฅคใ๎้จฉ ่ ฃ ฃฅญฅเ ๆจจ ฎโ็ฅโ 
x0049 = x0047                               ; ฅชใ้จฉ แ็ฅโ็จช ญฎขฎฉ แฅชใญค๋
fi                                          ;
fi                                          ;

# ---------                                 ;
#  ฆ โ์ ชญฎฏชใ "" ญ  ํชเ ญฅ          ;
if x0046 = 3                                ;  ฃ ฃฅญฅเ ๆจจ
if x0049 ! x0047                            ; แซจ ฏเฎ่ฅซ ฎกฌฅญ ฏฎ แฅโจ
l0007 = 716                                 ; ฎค ญ ฆ โฎฉ ชซ ขจ่จ
l0032 = 1                                   ; ซ ฃ ขขฎค  ชฎค  ญ ฆ โฎฉ ชซ ขจ่จ
x0046 = 0                                   ;
fi                                          ;
fi                                          ;

if l0040 = %_3                  ;
if x0048 > 0                                ;
x0048 = 0                                   ;
l0007 = 48                                  ; ฎค ญ ฆ โฎฉ ชซ ขจ่จ (F2 -  กซจๆ 1)
l0032 = 1                                   ; ซ ฃ ขขฎค  ชฎค  ญ ฆ โฎฉ ชซ ขจ่จ
fi                                          ;
fi                                          ;

if x0048 > 0                                ;
%__ = 8              ;
%__  = 10             ;
%_       = %           ;
fi                                          ;
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# ฏฅเฅแ็ฅโ ช ซ คซ๏ โฅชใ้ฅฃฎ ฎโ็ฅโ 
x0011 = $AIF301_D_V * 0.563  ;    # ชฎโฅซ 1
x0012 = $AIF311_D_V * 0.563  ;    # ชฎโฅซ 2
#-----------------------------------------------------------------------------
p1075 = p0055 ;
#-----------------------------------------------------------------------------
