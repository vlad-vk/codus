#-----------------------------------------------------------------------------
#  The commands in this file are called 18 times/second (every user tick)
#  x0000 - (7) temporary variables
#  p0000 - (0) common array variables (channel bases)
#  l0000 - (1) local array variables
#  c0000 - COM port array variables
#  n0000 - NetBIOS array variables
#  t0000 - TCPIP array variables
#  y0000 - command array variables 'y'

#-----------------------------------------------------------------------------
#  Definition of variables
   % = 0                                 ;
   % = 1                                 ;
   % = 0                                 ;
   % = 1                                 ;
   % = 0                             ;
   %   = 1                             ;
   % = 1                             ;
   % = 2                             ;
   %  = 3                             ;
   %___ = l0069           ;
   %____ = y0069           ;
   %_ = x0101                   ;
   %_ = x0100                   ;
   %_ = l0041                   ;
   %_  = x0081                      ;
   %_ = x0082                      ;
   %_  = x0083                      ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#  max number of lines of the current view file (to display the number of lines)
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
#  Status of dosing controls for highlighting (S M P)
if $REG06GL__V = %                       ;
   %_  = %                   ;
el                                          ;
   %_  = %                   ;
fi                                          ;
if $REG06R___V = %                       ;  
   %_  = %                   ;
fi                                          ;
#--------------------------------------------
if $REG07GL__V = %                       ;
   %_ = %                   ;
el                                          ;
   %_ = %                   ;
fi                                          ;
if $REG07R___V = %                       ;
   %_ = %                   ;
fi                                          ;
#--------------------------------------------
if $REG08GL__V = %                       ;
   %_  = %                   ;
el                                          ;
   %_  = %                   ;
fi                                          ;
if $REG08R___V = %                       ;
   %_  = %                   ;
fi                                          ;
#--------------------------------------------
if $REG09R___V    = %                    ;
   if $REG08___V  = %                    ;
      %_  = %                ;
   fi                                       ;
el                                          ;
   if $REG09GL__V = %                    ;
      %_  = %                ;
   el                                       ;
      %_  = %                ;
   fi                                       ;
fi                                          ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
l0020 = 0 ;                  # change disable flag
l0021 = 0 ;                  # menu disable flag
l0046 = 787878 ;             # master password
l0048 = 454545 ;             # technologist password

x0021 = 0 ;                  # inscription color when the MASTER password is entered
x0022 = 0 ;                  # the color of the inscription when the TECHNOLOGY password is entered

   x0041 = 0       ;         # output for selection operator PASTE-POWDER
   x0042 = 0       ;  
if $TRPAS__VIB > 0 ;         # PASTE
   x0041 = 1       ;
fi                 ;
if $TRPUD__VIB > 0 ;         # POWDER
   x0042 = 1       ;
fi                 ;

if l0045 ! l0046 ;            
   x0021 = 8 ;               # the color of the inscription when the MASTER password is not entered
fi ;
if l0047 ! l0048 ;           
   x0022 = 8 ;               # inscription color when TECHNOLOGY password is not entered
fi ;

x0025 = 0 ;                  # screen is password controlled
if l0031 = 6 ;               # "SETTINGS" screen
   x0025 = 1 ;
fi ;
if l0031 = 4 ;               # "RANGE" screen
   x0025 = 1 ;
fi ;
if l0031 = 8 ;               # "I7042 MODULES" screen
   x0025 = 1 ;
fi ;
if l0031 = 7 ;               # "CONTROL SETTINGS" screen
   x0025 = 1 ;
fi ;
if l0031 = 5 ;               # "ALARM" screen
   x0025 = 2 ;
fi ;


#-----------------------------------------------------------------------------
# initial setting of variable values
if x0000 = 0 ;
   x0000 = 1 ;
fi ;

#-----------------------------------------------------------------------------
# transmission of the message number (taken from the variable N14 of the common channel base)
l0010 = p0014 ;

#-----------------------------------------------------------------------------
# COM port and NetBIOS network operation flag, which are transmitted to and received by the CS
x0003 = x0003 + 1 ;
if x0003 > 10 ;
   x0003 =  0 ;

   p0029 = p0029 + 1 ;                      # COM
   p0030 = p0030 + 1 ;                      # NBW
   if p0029 > 1000 ;                        # COM
      p0029 = 1 ;
   fi ;
   if p0030 > 1000 ;                        # NBW
      p0030 = 1 ;
   fi ;

   if x0004 ! p0031 ;                       # COM
      x0005 = x0005 + 1 ;
      if x0005 > 8  ;
         x0005 = 1  ;
      fi ;
      x0004 = p0031 ;
      x0006 = 0 ;
   el ;
      x0006 = x0006 + 1 ;
      if x0006 > 20 ;
         x0005 =  0 ;
      fi ;
   fi ;

   if x0007 ! p0032 ;                       # NBW
      x0008 = x0008 + 1 ;
      if x0008 > 8  ;
         x0008 = 1  ;
      fi ;
      x0007 = p0032 ;
      x0009 = 0 ;
   el ;
      x0009 = x0009 + 1 ;
      if x0009 > 10 ;
         x0008 =  0 ;
      fi ;
   fi ;
fi ;

#-----------------------------------------------------------------------------
# flag for displaying error messages (displaying the ATTENTION sign)
if p0020 > 0 ;                         # if call flag is set
   x0001 = x0001 + 1 ;                 # tick count time variable
el ;
   l0043 =  0 ;                        # changes from base locale for animation output
fi ;
if x0001 >  9 ;
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
# CPU usage display color
   l0044 = %   ;
if l0001 < 50000     ;
   l0044 = %  ;
fi                   ;
if l0001 < 20000     ;
   l0044 = %    ;
fi                   ;
if l0001 < 1000      ;
   l0044 = %  ;
fi                   ;
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
