@echo off

if exist c:\prog\bc31\bin\bcc.exe set BC=c:\prog\bc31
if exist d:\prog\bc31\bin\bcc.exe set BC=d:\prog\bc31

set PATH=%BC%\bin;%PATH%
set file=obaedz2

..\bin\version > prg\version.h

make   > 0_comp.log

if exist *.obj copy *.obj obj   >> 0_comp.log
if exist *.obj del  *.obj       >> 0_comp.log

tlink  @makefile.lnk >> 0_comp.log

if exist  *.map del    *.map >> 0_comp.log

rem pause

if exist 0_comp.log ..\bin\readme 0_comp.log

:if exist %file%.exe ..\bin\pklite %file%.exe

exit
