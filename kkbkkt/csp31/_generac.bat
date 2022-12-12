@echo off

set nprj=kkbkkt

set sdir=csp31

if not exist ..\codus_gn.ini goto no1
if exist run_prgv.h del run_prgv.h

cd ..\..\..
call prj\codus_gn.bat prj\%nprj% %sdir%

cd prj\%nprj%\%sdir%
goto end

:no1
 echo ERROR: Not found file ..\codus_gn.ini
 echo.
 goto end

:end

if exist regul*.* del regul*.*
pause