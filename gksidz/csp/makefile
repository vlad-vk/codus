PRG=run_prg
EXE=run_prg.exe
CL=$(BC)\bin\bcc.exe
OB=regul.obj
FLG=-ml -G -DBCC -I$(BC)\inc -I$(BC)\include -Ld:\ -L$(BC)\lib -e$(EXE)

all: reg cmp
cmp:
     $(CL) $(FLG) $(PRG).c $(OB)
     $(VVK)\bin\pklite $(EXE)
reg:
     $(CL) -c $(FLG) regul.c 

