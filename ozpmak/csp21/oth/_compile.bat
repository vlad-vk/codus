@echo off

if exist c:\prog\bc31\bin\bcc.exe set BC=c:\prog\bc31
if exist d:\prog\bc31\bin\bcc.exe set BC=d:\prog\bc31
if exist l:\prog\bc31\bin\bcc.exe set BC=l:\prog\bc31

set HARD=IPCCS
set PATH=%BC%\bin;%PATH%

make   > _compile.log

if exist *.obj  copy  *.obj ..\obj >> _compile.log
if exist *.obj  del   *.obj        >> _compile.log

if exist _compile.log ..\..\bin\readme _compile.log

exit
