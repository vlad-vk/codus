#-----------------------------------------------------------------------------
# The commands in this file are called 18 times/second (every user tick)
# x0000 - temporary variables
# p0000 - common array variables (channel bases)
# l0000 - local array variables
# c0000 - COM port array variables
# n0000 - NetBIOS array variables
# t0000 - TCPIP array variables

l0020 = 0 ;                  # no change flag
l0021 = 0 ;                  # menu disable flag
l0046 = l0045 ;              # master password
l0048 = l0047 ;              # technologist password
l0012 = 255  ;
l0013 = 12   ;

x0021 = 0 ;                  # inscription color when the MASTER password is entered
x0022 = 0 ;                  # the color of the inscription when the TECHNOLOGY password is entered

if l0045 ! l0046 ;            
   x0021 = 8 ;               # the color of the inscription when the MASTER password is not entered
fi ;
if l0047 ! l0048 ;           
   x0022 = 8 ;               # inscription color when TECHNOLOGY password is not entered
fi ;

x0025 = 0 ;                  # screen is password controlled
if l0031 = 6 ;               # SETTINGS screen [6]
   x0025 = 1 ;
fi ;
if l0031 = 4 ;               # RANGE screen [4]
   x0025 = 1 ;               
fi ;
if l0031 = 8 ;               # "I7042 MODULES" screen [8]
   x0025 = 1 ;
fi ;
if l0031 = 7 ;               # CONTROL SETTINGS screen [7]
   x0025 = 1 ;
fi ;
if l0031 = 5 ;               # ALARM screen [5]
   x0025 = 2 ;
fi ;

#-----------------------------------------------------------------------------
# initial setting of variable values
if x0000 = 0 ;
   x0000 = 1 ;
fi ;

#-----------------------------------------------------------------------------
# transmission of the message number (taken from the variable N14 of the common channel base)
l0010 = $CurMESSAGE ;

#-----------------------------------------------------------------------------
# flag for displaying error messages (output ATTENTION sign)
if $ErrBell__V > 0 ;                   # if call flag is set
   x0001 = x0001 + 1 ;                 # time tick count variable
el ;
   l0043 =  0 ;                        # changes from locale base for anime output
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
# program loading display:             # yellow - easy operation
   l0044 = 3 ;
if l0001 < 50000 ;                     # green  - weak loading
   l0044 = 2 ;
fi ;
if l0001 < 20000 ;                     # blue   - medium load
   l0044 = 1 ;
fi ;
if l0001 < 1000  ;                     # red    - heavy load
   l0044 = 0 ;
fi ;


#-----------------------------------------------------------------------------
if l0031 = 1 ;               # if it is screen N1 (SCIM)
   if l0007 = 64 ;           # if the TAB key is pressed
      l0007 = 56 ;           # set keystroke F10 (CHART Channels)
      l0032 = 1  ;           # set the click handling flag in CODUS
   fi ;
fi ;
if l0031 = 2 ;               # set the click handling flag in CODUS
   if l0007 = 64 ;           # if the TAB key is pressed
      l0007 = 48 ;           # set pressing the F2 key (SCIM)
      l0032 = 1  ;           # set the click handling flag in CODUS
   fi ;
fi ;

#-----------------------------------------------------------------------------
if l0007 = 57 ;              # if transition to the "TEST1" screen is selected
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;
if l0007 = 58 ;              # if transition to the "TEST2" screen is selected
   if l0045 ! l0046 ;
      l0007 = 0 ;
      l0032 = 1 ;
   fi ;
fi ;

#-----------------------------------------------------------------------------

if l0006 = 0 ;               # If there is no input

   if l0045 ! l0046 ;        # If the MASTER password is not entered
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
# Transformation for displaying pH values on graphs
  $AOHBM6__OR = $AOHBM6__OV / 100 ; 
  $AOHBM6__OR = $AOHBM6__OR * 5   ; 
  $AOHBM6__OR = $AOHBM6__OR + 7.5 ; 
;
  $AOFDFS__OR = $AOFDFS__OV / 100 ; 
  $AOFDFS__OR = $AOFDFS__OR * 160 ;
;
  $AOH1ST__OR = $AOH1ST__OV / 100 ; 
  $AOH1ST__OR = $AOH1ST__OR * 5   ; 
  $AOH1ST__OR = $AOH1ST__OR + 7.5 ; 
;
  $AOH2ST__OR = $AOH2ST__OV / 100 ; 
  $AOH2ST__OR = $AOH2ST__OR * 5   ; 
  $AOH2ST__OR = $AOH2ST__OR + 8   ; 
;
  $AOTNS11_OR = $AOTNS11_OV       ; 
  $AOTNS12_OR = $AOTNS12_OV       ; 
  $AOTNS13_OR = $AOTNS13_OV       ; 
  $AOTFS1S_OR = $AOTFS1S_OV       ; 
;
  $AOPGOK__OR = $AOPGOK__OV / 100 ; 
;
  $AOFIMOD_OR = $AOFIMOD_OV * 0.4 ; 
  $AOFSVZ__OR = $AOFSVZ__OV * 0.8 ; 
  $AOFIM2S_OR = $AOFIM2S_OV * 0.4 ; 
  $AOFSPBM_OR = $AOFSPBM_OV * 0.4 ; 

#-----------------------------------------------------------------------------
# COM port and NetBIOS network operation flag, which are transmitted to and received by the CS
# (transmission to the network must be the last one in this file)
# (only one variable can be passed to the network at a time)
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
#

