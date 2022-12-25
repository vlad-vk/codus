@echo off

set BC=C:\prog\bc31
if  exist D:\prog\bc31\bin\bcc.exe set BC=D:\prog\bc31
if  exist E:\prog\bc31\bin\bcc.exe set BC=E:\prog\bc31
set PATH=%BC%\bin;%ND%\sdos\bin;%PATH%

make   > 0_comp.log

if exist *.obj  copy  *.obj ..\obj >> 0_comp.log
if exist *.obj  del   *.obj        >> 0_comp.log

if exist 0_comp.log readme 0_comp.log
exit
