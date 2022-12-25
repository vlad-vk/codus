@echo off

set BC=C:\prog\bc31
if  exist D:\prog\bc31\bin\bcc.exe set BC=D:\prog\bc31
if  exist E:\prog\bc31\bin\bcc.exe set BC=E:\prog\bc31
set PATH=%BC%\bin;%ND%\sdos\bin;%PATH%
set LOG=0_comp.log

make   > %LOG%

if exist *.obj  copy  *.obj ..\obj >> %LOG%
if exist *.obj  del   *.obj        >> %LOG%

if exist %LOG% readme %LOG%

exit
