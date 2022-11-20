PRG=run_prg

CL=$(BC)\bin\bcc.exe
LN=$(BC)\bin\tlink.exe

FLG=-c -1 -mh -DBCC -Ic:\inc -I$(BC)\inc -Ld:\ -L$(BC)\lib

all: cmp
cmp:
     $(CL)  $(FLG) $(PRG).c
