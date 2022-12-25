@echo off

set BC=d:\prog\bc31

set HARD=IPCCS
set PATH=%BC%\bin;c:\bin;%PATH%

..\bin\versiond > version.h

make
