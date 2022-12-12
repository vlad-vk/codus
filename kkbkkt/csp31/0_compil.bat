@echo off

set BC=c:\prog\bc31

set PATH=%BC%\bin;%PATH%

set file=kkbkkt

make   > _compile.log

if exist *.obj copy *.obj obj   >> _compile.log
if exist *.obj del  *.obj       >> _compile.log

tlink  @makefile.lnk >> _compile.log

pause
