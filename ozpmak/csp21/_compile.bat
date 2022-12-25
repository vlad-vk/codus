@echo off

if exist c:\prog\bc31\bin\bcc.exe set BC=c:\prog\bc31
if exist d:\prog\bc31\bin\bcc.exe set BC=d:\prog\bc31
if exist l:\prog\bc31\bin\bcc.exe set BC=l:\prog\bc31

set PATH=%BC%\bin;%PATH%
set file=ozpmak21

..\bin\version1 1 > prg\version.h

make   > _compile.log

if exist *.obj copy *.obj obj   >> _compile.log
if exist *.obj del  *.obj       >> _compile.log

tlink  @makefile.lnk >> _compile.log

if exist  *.map del    *.map >> _compile.log
if exist  %file%.exe ..\bin\pklite  %file%.exe >> _compile.log

rem pause
if exist _compile.log ..\bin\readme _compile.log

exit
