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
   %MAN = 0                                 ;
   %AUT = 1                                 ;
   %OFF = 0                                 ;
   %ON_ = 1                                 ;
   
   %RED    = 0                              ;
   %BLUE   = 1                              ;
   %GREEN  = 2                              ;
   %YELLOW = 3                              ;
   
   %LINES_IN_CUR_FILE = l0069               ;
   %LINES_TFL_FOR_CODUS = y0069             ;
   
   %SECUND_NEW = x0101                      ;
   %SECUND_REC = x0100                      ;
   %SECUND_COD = l0041                      ;
   
   %DZ_DRY = x0081                          ;
   %DZ_WET = x0082                          ;
   %DZ_ALU = x0083                          ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#  max number of lines of the current view file (to display the number of lines)
   %LINES_TFL_FOR_CODUS = %LINES_IN_CUR_FILE    ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
   %SECUND_NEW = %OFF                       ;
if %SECUND_REC ! %SECUND_COD                ;
   %SECUND_NEW = %ONN                       ;
fi                                          ; 
   %SECUND_REC = %SECUND_COD                ;
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#  Status of dosing controls for highlighting (S M P)
if $REG06GL__V = %MAN                       ;
   %DZ_DRY  = %BLUE                         ;
el                                          ;
   %DZ_DRY  = %GREEN                        ;
fi                                          ;
if $REG06R___V = %OFF                       ;  
   %DZ_DRY  = %RED                          ;
fi                                          ;
#--------------------------------------------
if $REG07GL__V = %MAN                       ;
   %DZ_WET = %BLUE                          ;
el                                          ;
   %DZ_WET = %GREEN                         ;
fi                                          ;
if $REG07R___V = %OFF                       ;
   %DZ_WET = %RED                           ;
fi                                          ;
#--------------------------------------------
if $REG08GL__V = %MAN                       ;
   %DZ_ALU  = %BLUE                         ;
el                                          ;
   %DZ_ALU  = %GREEN                        ;
fi                                          ;
if $REG08R___V = %OFF                       ;
   %DZ_ALU  = %RED                          ;
fi                                          ;
#--------------------------------------------
if $REG09R___V    = %MAN                    ;
   if $REG08___V  = %MAN                    ;
      %DZ_ALU  = %RED                       ;
   fi                                       ;
el                                          ;
   if $REG09GL__V = %OFF                    ;
      %DZ_ALU  = %BLUE                      ;
   el                                       ;
      %DZ_ALU  = %GREEN                     ;
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
   l0044 = %YELLOW      ;
if l0001 < 50000        ;
   l0044 = %GREEN       ;
fi                      ;
if l0001 < 20000        ;
   l0044 = %BLUE        ;
fi                      ;
if l0001 < 1000         ;
   l0044 = %RED         ;
fi                      ;
#-----------------------------------------------------------------------------
if l0031 = 1 ;               # if it is screen N1 (SCIM)
   if l0007 = 64 ;           # if the TAB key is pressed
      l0007 = 56 ;           # set keystroke F10 (CHART Channels)
      l0032 = 1  ;           # set the click handling flag in CODUS
   fi ;
fi ;
if l0031 = 2 ;               # if it is screen N2 (SCHEME Channels)
   if l0007 = 64 ;           # if the TAB key is pressed
      l0007 = 48 ;           # set pressing the F2 key (SCIM)
      l0032 = 1  ;           # set the click handling flag in CODUS
   fi ;
fi ;

#-----------------------------------------------------------------------------
#  when you press the ESC key after closing the input or query window - 
#  the sound signal is removed
if x0030 > 0            ;    # after pressing the ESC key, it generates
   if x0101 = 1         ;    
      l0007 = x0030     ;    # pressing the 'S' key to clear the error signal
      x0030 = 0         ;    
      l0032 = 1         ;    # set the click handling flag in CODUS
      l0005 = 0         ;    # reset the code after the generated operator lock keys
   fi                   ;
fi                      ;    
if l0007 = 59           ;    # if the ESC key is pressed
   x0030 = 19           ;    # set keystroke 'S' for next cycle
fi                      ;    
if l0005 = 59           ;    # ESC key generated by operator request
   x0030 = 19           ;    # set keystroke 'S' for next cycle
fi                      ;    

#-----------------------------------------------------------------------------
if l0007 = 57 ;                        # if transition to the "TEST1" screen is selected
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;
if l0007 = 58 ;                        # if transition to the "TEST2" screen is selected
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;

#-----------------------------------------------------------------------------

if l0006 = 0 ;               # If there is no input

   if l0045 ! l0046 ;        # If the master password is not entered
      if x0025 = 1 ;         # if it is a controlled screen
         l0020 = 1 ;         # disable menu actions
         l0021 = 1 ;         # prohibit changes
         if l0007 = 67 ;     # if the ENTER key is pressed -
            l0033 = 5  ;     # display a warning message
            l0035 = 1  ;     # display message as error
         fi ;
      fi ;
      if l0007 = 12 ;        # If the 'D' key is pressed - (RANGE)
         l0007 = 0  ;        # ignore this press.
         l0032 = 1  ;        # Set the click handling flag in CODUS
         l0033 = 4  ;        # Display a warning message.
         l0034 = 10 ;        # Message display 10 sec
         l0035 = 1  ;        # Display the message as an error.
      fi ;
      if l0007 = 5  ;        # If the 'Y' key is pressed - (SETTINGS)
         l0007 = 0  ;        # ignore this press.
         l0032 = 1  ;        # Set the click handling flag in CODUS
         l0033 = 4  ;        # display a warning message.
         l0034 = 10 ;        # Message display 10 sec
         l0035 = 1  ;        # Display the message as an error.
      fi ;
   fi ;

   if l0047 ! l0048 ;        # If the TECHNOLOGY password is not entered
      if x0025 = 2 ;         # if on the "ALARMS" screen
         l0020 = 1 ;         # disable menu actions
         l0021 = 1 ;         # prohibit changes
         if l0007 = 67 ;     # if the ENTER key is pressed -
            l0033 = 7  ;     # display a warning message
            l0035 = 1  ;     # display message as error
         fi ;
      fi ;
      if l0007 = 3  ;        # If the 'C' key is pressed - (ALARM)
         l0007 = 0  ;        # ignore this press.
         l0032 = 1  ;        # Set the click handling flag in CODUS
         l0033 = 6  ;        # display a warning message.
         l0034 = 10 ;        # Message display 10 sec
         l0035 = 1  ;        # Display the message as an error.
      fi ;
   fi ;

fi ;
#-----------------------------------------------------------------------------
