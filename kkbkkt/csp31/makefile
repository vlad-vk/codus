PROG=kkbkkt

EXE=run_prog.exe

CL=$(BC)\bin\bcc.exe

CFLAG=-mh -1 -DBCC -I$(BC)\inc -I$(BC)\inc -Ld:\ -L$(BC)\lib -e$(EXE)

all: cmp

cmp:
     $(CL) -c $(CFLAG) $(PROG).c

