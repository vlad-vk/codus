PRG=run_prg
EXE=run_prg.exe
CL=$(BC)\bin\bcc.exe
OB=reg\reg.obj
FLG=-mh -DBCC -Ic:\inc -I$(BC)\inc -Ld:\ -L$(BC)\lib -e$(EXE)

all: cmp
cmp:
     $(CL)  $(FLG) $(PRG).c $(OB) lib\codipccs.lib
     pklite $(EXE)
