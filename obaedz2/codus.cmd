# coding: cp866
#-----------------------------------------------------------------------------
#  ®¬¬ ­¤ė ķā®£® ä ©«  ¢ė§ė¢ īāįļ Ŗ ¦¤ė„ 10 ¬į„Ŗ
#  x0000 - (7) ¢ą„¬„­­ė„  Æ„ą„¬„­­ė„
#  p0000 - (0) Æ„ą„¬„­­ė„ ®”é„£® ¬ įįØ¢  (” §ė Ŗ ­ «®¢)
#  l0000 - (1) Æ„ą„¬„­­ė„ «®Ŗ «ģ­®£® ¬ įįØ¢ 
#  c0000 - Æ„ą„¬„­­ė„ ¬ įįØ¢  COM Æ®ąā 
#  n0000 - Æ„ą„¬„­­ė„ ¬ įįØ¢  NetBIOS
#  t0000 - Æ„ą„¬„­­ė„ ¬ įįØ¢  TCPIP
#  y0000 - Æ„ą„¬„­­ė„ ¬ įįØ¢  Ŗ®¬¬ ­¤ė 'y'


#   :
#-----------------------------------------------------------------------------
   %            = 0                      ;
   %            = 1                      ;
   %            = 0                      ;
   %            = 1                      ;
   %            = 0                      ;
   %             = 1                      ;
#--------------------------------------------
   %                = 0              ;
   %                  = 1              ;
   %                = 1              ;
   %                = 2              ;
   %                 = 3              ;
#--------------------------------------------
   %_               = 787878         ;
   %_               = 454545         ;
   %_           = 12             ;
   %_            = 56             ;
   %__        = 90             ;
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
    y0007                  = l0007          ;
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
   %_              = x0081          ;
   %_             = x0082          ;
   %_              = x0083          ;
#-----------------------------------------------------------------------------



#-----------------------------------------------------------------------------
#  ¬ Ŗį Ŗ®« įāą®Ŗ ā„Ŗćé ä ©«  Æą®į¬®āą  (¤«ļ ¢ė¢®¤  Ŗ®« įāą®Ŗ)
   %____ = %___    ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
   %_ = %                    ;
if %_ ! %_          ;
   %_ = %                    ;
fi                                          ; 
   %_ = %_          ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#  ®įā®ļ­Ø„ ą„£ć«ļā®ą®¢ ¤®§Øą®¢ŖØ ¤«ļ ®ā®”ą ¦„­Øļ (  )
   x0086            = 0                     ;
   x0087            = 0                     ;
   x0089            = 0                     ;
if $RegPublicV      = 1                     ;
    if $REG06GL__V  = 1                     ;
        x0086       = 1                     ;
    fi                                      ;
    if $REG07GL__V  = 1                     ;
        x0087       = 1                     ;
    fi                                      ;
    if $REG09GL__V  = 1                     ;
        x0089       = 1                     ;
    fi                                      ;
fi                                          ;
if $REG06GL__V      = 0                     ;
if $REG06R___V      = 1                     ;
    x0086           = 1                     ;
fi                                          ;
fi                                          ;
if $REG07GL__V      = 0                     ;
if $REG07R___V      = 1                     ;
    x0087           = 1                     ;
fi                                          ;
fi                                          ;
if $REG09GL__V      = 0                     ;
if $REG09R___V      = 1                     ;
    x0089           = 1                     ;
fi                                          ;
fi                                          ;
#-----------------------------------------------------------------------------
# ā®”ą ¦„­Ø„ § ¤ ­Ø© ą„£ć«ļā®ą®¢               ;
if $REG06SW__V      < 150                       ; § £ąć§Ŗ  ę„¬„­ā  Ø ¢ļ¦ćé„£®
    x0076           = $TRCEMS_VIB + $TRVYGS_VIB ;
fi                                              ;
if $REG06SW__V      < 60                        ; § £ąć§Ŗ  ę„¬„­ā 
    x0076           = $TRCEMS_VIB               ;
fi                                              ;
#-------------
if $REG07SW__V      > 220                       ; § £ąć§Ŗ  ¢®¤ė
if $REG07SW__V      < 250                       ; 
    x0077           = $TRVODD_VIB               ;
fi                                              ;
fi                                              ;
if $REG07SW__V      < 160                       ; § £ąć§Ŗ  č« ¬  Ø ®”ą č«
    x0077           = $TROTH__VIB + $TRSLM__VIB ;
fi                                              ;
if $REG07SW__V      < 80                        ; § £ąć§Ŗ  ®”ą č« ¬ 
    x0077           = $TROTH__VIB               ;
fi                                              ;
#-------------
if $REG06SW__V      > 1000                      ; ąćē­®© ą„¦Ø¬
    x0076           = 0                         ;
fi                                              ;
if $REG07SW__V      > 1000                      ;
    x0077           = 0                         ;
fi                                              ;
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
l0020 = 0 ;                  # ä« £ § Æą„ā  Ø§¬„­„­Ø©
l0021 = 0 ;                  # ä« £ § Æą„ā  ¬„­ī
l0046 = 787878 ;             # Æ ą®«ģ  Ø 
l0048 = 454545 ;             # Æ ą®«ģ ā„å­®«®£ 

x0021 = 0 ;                  # ę¢„ā ­ ¤ÆØįØ Ŗ®£¤  ¢¢„¤„­ Æ ą®«ģ  Ø 
x0022 = 0 ;                  # ę¢„ā ­ ¤ÆØįØ Ŗ®£¤  ¢¢„¤„­ Æ ą®«ģ 

if l0045 ! l0046 ;            
   x0021 = 8 ;               # ę¢„ā ­ ¤ÆØįØ Ŗ®£¤  ­„ ¢¢„¤„­ Æ ą®«ģ  Ø 
fi ;
if l0047 ! l0048 ;           
   x0022 = 8 ;               # ę¢„ā ­ ¤ÆØįØ Ŗ®£¤  ­„ ¢¢„¤„­ Æ ą®«ģ 
fi ;

x0025 = 0 ;                  # ķŖą ­ Ŗ®­āą®«Øąć„āįļ Æ ą®«„¬
if l0031 = 6 ;               # ķŖą ­ ""
   x0025 = 1 ;
fi ;
if l0031 = 4 ;               # ķŖą ­ ""
   x0025 = 1 ;
fi ;
if l0031 = 8 ;               # ķŖą ­ " I7042"
   x0025 = 1 ;
fi ;
if l0031 = 7 ;               # ķŖą ­ " "
   x0025 = 1 ;
fi ;

if l0031 = 5 ;               # ķŖą ­ ""
   x0025 = 2 ;
fi ;
if l0031 = 1 ;               # ķŖą ­ ""
   x0025 = 2 ;
fi ;

if l0031 = 9                                ; # ķŖą ­ " "
   if l0006      = 0                        ; #
      if x0032   = 1                        ; # „į«Ø § Ŗ®­ēØ«Ø ¢¢®¤ ¤ ­­ėå
         l0067   = 68                       ; # ­®¬„ą ini-ä ©«  ¤«ļ § £ąć§ŖØ
         l0068   = 1                        ; # ¢Ŗ«īēØāģ § £ąć§Ŗć
#        o_Set_l67_l68                      ;
      fi                                    ; #
   fi                                       ; #
   x0032 = l0006                            ; # %_ = l0006
fi                                          ;


#-----------------------------------------------------------------------------
# ­ ē «ģ­ ļ ćįā ­®¢Ŗ  §­ ē„­Ø© Æ„ą„¬„­­ėå
if x0000 = 0                                ;
   x0000 = 1                                ;
   x0010 = l0057                            ; 
   x0017 = 1                                ;
fi                                          ;

#-----------------------------------------------------------------------------
#  Ŗ ¦¤ćī ­®¢ćī į„Ŗć­¤ć:
if %_ = %                    ;   
   #----------------------------------------;
   if x0010 ! l0057                         ;   # ®ā®”ą ¦„­Ø„ ¢ Æą ¢®¬ ¢„ąå­„¬
      x0017 = x0017  + 1                    ;   # ć£«ć ą ”®āė į„āØ            
      if x0017 >  8                         ;
         x0017 =  1                         ;
      fi                                    ;
   fi                                       ;
   x0010 = l0057                            ;
   #----------------------------------------;

fi                                          ;

#-----------------------------------------------------------------------------
# Æ„ą„¤ ē  ­®¬„ą  į®®”é„­Øļ (”„ą„āįļ Ø§ Æ„ą„¬„­­®© N14 ®”é„© ” §ė Ŗ ­ «®¢)
l0010 = p0014 ;


#-----------------------------------------------------------------------------
# ä« £ ¢ė¢®¤  į®®”é„­Ø© ®” ®čØ”Ŗ„ (¢ė¢®¤ §­ Ŗ  )
if p0020 > 0 ;                         # „į«Ø ćįā ­®¢«„­ ä« £ §¢®­Ŗ 
   x0001 = x0001 + 1 ;                 # ¢ą„¬ Æ„ą„¬„­­ ļ įē„ā  āØŖ®¢
el ;
   l0043 =  0 ;                        # Æ„ą„¬„­ Ø§ «®Ŗ « ” §ė ¤«ļ ¢ė¢®¤   ­Ø¬
fi ;
# Ŗ ¦¤ė„ Æ®« į„Ŗć­¤ė
if x0001 >  50 ;
   x0001 =  0 ;
   if l0043 > 0 ;
      l0043 = 0 ;
   el ;
      if x0002 = 1 ;
         l0043 = 2 ;
      el ;
         l0043 = 1 ;
      fi ;
      x0002 = l0043 ;
   fi ;
fi ;

#-----------------------------------------------------------------------------
if l0031 = 1 ;               # „į«Ø ķā® ķŖą ­ N1 ( )
   if l0007 = 64 ;           # „į«Ø ­ ¦ ā  Ŗ« ¢Øč  TAB
      l0007 = 56 ;           # ćįā ­®¢Øāģ ­ ¦ āØ„ Ŗ« ¢ØčØ F10 (  ­ «ė)
      l0032 = 1  ;           # ćįā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
   fi ;
fi ;
if l0031 = 2 ;               # „į«Ø ķā® ķŖą ­ N2 (  ­ «ė)
   if l0007 = 64 ;           # „į«Ø ­ ¦ ā  Ŗ« ¢Øč  TAB
      l0007 = 48 ;           # ćįā ­®¢Øāģ ­ ¦ āØ„ Ŗ« ¢ØčØ F2  ( )
      l0032 = 1  ;           # ćįā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
   fi ;
fi ;

#-----------------------------------------------------------------------------
#  ÆąØ ­ ¦ āØØ Ŗ« ¢ØčØ ESC Æ®į«„ § ŖąėāØļ ®Ŗ­  ¢¢®¤  Ø«Ø § Æą®į - 
#  į­Ø¬ „āįļ §¢ćŖ®¢®© įØ£­ «
if x0030 > 0            ;    # Æ®į«„ ­ ¦ āØļ Ŗ« ¢ØčØ ESC £„­„ąØąć„āįļ
   if x0101 = 1         ;    
      l0007 = x0030     ;    # ­ ¦ āØ„ Ŗ« ¢ØčØ 'S' ¤«ļ į­ļāØļ įØ£­ «  ®čØ”ŖØ
      x0030 = 0         ;    
      l0032 = 1         ;    # ćįā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
      l0005 = 0         ;    # į”ą®įØāģ Ŗ®¤ Æ®į« £„­„ąØą Ŗ« ¢ØčØ § Æą ®Æ„ą ā®ą 
   fi                   ;
fi                      ;    
if l0007 = 59           ;    # „į«Ø ­ ¦ ā  Ŗ« ¢Øč  ESC
   x0030 = 19           ;    # ćįā ­®¢Øāģ ­ ¦ āØ„ Ŗ« ¢ØčØ 'S' ¤«ļ į«„¤ ęØŖ« 
fi                      ;    
if l0005 = 59           ;    # Ŗ« ¢Øč  ESC į£„­„ąØą § Æą®į®¬ ®Æ„ą ā®ą 
   x0030 = 19           ;    # ćįā ­®¢Øāģ ­ ¦ āØ„ Ŗ« ¢ØčØ 'S' ¤«ļ į«„¤ ęØŖ« 
fi                      ;    

#-----------------------------------------------------------------------------
if l0007 = 57 ;                        # „į«Ø ¢ė”ą ­ Æ„ą„å®¤ ­  ķŖą ­ "1"
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;
if l0007 = 58 ;                        # „į«Ø ¢ė”ą ­ Æ„ą„å®¤ ­  ķŖą ­ "2"
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;

#-----------------------------------------------------------------------------

if l0006 = 0 ;               # į«Ø ­„ā ¢¢®¤  ¤ ­­ėå

   if l0045 ! l0046 ;        # į«Ø ­„ ¢¢„¤„­ Æ ą®«ģ  Ø 
      if x0025 = 1 ;         # „į«Ø ķā® Ŗ®­āą®«Øąć„¬ė© ķŖą ­
         l0020 = 1 ;         # § Æą„āØāģ ¤„©įā¢Øļ ¬„­ī
         l0021 = 1 ;         # § Æą„āØāģ Ø§¬„­„­Øļ
         if l0007 = 67 ;     # „į«Ø ­ ¦ ā  Ŗ« ¢Øč  ENTER -
            l0033 = 5  ;     # ¢ė¢„įāØ Æą„¤ćÆą„¤Øā„«ģ­®„ į®®”é„­Ø„
            l0035 = 1  ;     # ¢ė¢„įāØ į®®”é„­Ø„, Ŗ Ŗ ®čØ”Ŗć
         fi ;
      fi ;
      if l0007 = 12 ;        # į«Ø ­ ¦ ā  Ŗ« ¢Øč  ''- ()
         l0007 = 0  ;        # Ø£­®ąØą®¢ āģ ķā® ­ ¦ āØ„.
         l0032 = 1  ;        # įā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
         l0033 = 4  ;        # ė¢„įāØ Æą„¤ćÆą„¤Øā„«ģ­®„ į®®”é„­Ø„.
         l0034 = 10 ;        # ā®”ą ¦„­Ø„ į®®”é„­Øļ 10 į„Ŗ
         l0035 = 1  ;        # ė¢„įāØ į®®”é„­Ø„, Ŗ Ŗ ®čØ”Ŗć.
      fi ;
      if l0007 = 5  ;        # į«Ø ­ ¦ ā  Ŗ« ¢Øč  ''- ()
         l0007 = 0  ;        # Ø£­®ąØą®¢ āģ ķā® ­ ¦ āØ„.
         l0032 = 1  ;        # įā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
         l0033 = 4  ;        # ¢ė¢„įāØ Æą„¤ćÆą„¤Øā„«ģ­®„ į®®”é„­Ø„.
         l0034 = 10 ;        # ā®”ą ¦„­Ø„ į®®”é„­Øļ 10 į„Ŗ
         l0035 = 1  ;        # ė¢„įāØ į®®”é„­Ø„, Ŗ Ŗ ®čØ”Ŗć.
      fi ;
   fi ;

   if l0047 ! l0048 ;        # į«Ø ­„ ¢¢„¤„­ Æ ą®«ģ 
      if x0025 = 2 ;         # „į«Ø ­  ķŖą ­„ ""
         l0020 = 1 ;         # § Æą„āØāģ ¤„©įā¢Øļ ¬„­ī
         l0021 = 1 ;         # § Æą„āØāģ Ø§¬„­„­Øļ
         if l0007 = 67 ;     # „į«Ø ­ ¦ ā  Ŗ« ¢Øč  ENTER -
            l0033 = 7  ;     # ¢ė¢„įāØ Æą„¤ćÆą„¤Øā„«ģ­®„ į®®”é„­Ø„
            l0035 = 1  ;     # ¢ė¢„įāØ į®®”é„­Ø„, Ŗ Ŗ ®čØ”Ŗć
         fi ;
      fi ;
      if l0007 = 3  ;        # į«Ø ­ ¦ ā  Ŗ« ¢Øč  ''- ()
         l0007 = 0  ;        # Ø£­®ąØą®¢ āģ ķā® ­ ¦ āØ„.
         l0032 = 1  ;        # įā ­®¢Øāģ ä« £ ®”ą ”®āŖØ ­ ¦ āØļ ¢ „
         l0033 = 6  ;        # ¢ė¢„įāØ Æą„¤ćÆą„¤Øā„«ģ­®„ į®®”é„­Ø„.
         l0034 = 10 ;        # ā®”ą ¦„­Ø„ į®®”é„­Øļ 10 į„Ŗ
         l0035 = 1  ;        # ė¢„įāØ į®®”é„­Ø„, Ŗ Ŗ ®čØ”Ŗć.
      fi ;
   fi ;

fi ;
#-----------------------------------------------------------------------------

p0201 = 29
p0202 = 27
p0203 = 28
p0204 = 25
p0205 = 01
p0206 = 64
p0207 = 5
p0208 = 0
p0209 = 63
p0210 = 2
p0211 = 6
p0212 = 12
p0213 = 5
p0214 = 3
p0215 = 14
p0216 = 15

#-----------------------------------------------------------------------------
