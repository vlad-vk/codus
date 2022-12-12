PROG=kkbkkt

EXE=run_prog.exe

CL=$(BC)\bin\bcc.exe

CFLAG=-mh -1 -DBCC -I$(BC)\inc -IC:\codus\lib -L$(BC)\lib -LC:\codus\lib

all: cmp

cmp:
     $(CL) -c $(CFLAG) $(PROG).c

