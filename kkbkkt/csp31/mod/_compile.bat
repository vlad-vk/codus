@echo off

set BC=C:\prog\bc31
set PATH=%BC%\bin;%ND%\sdos\bin;%PATH%

make   > _compile.log

if exist *.obj  copy  *.obj ..\obj >> _compile.log
if exist *.obj  del   *.obj        >> _compile.log

pause
