::...::..:::...::..::.:.::
::    SciTE Debug	::  
::...::..:::...::..::.:.::

@echo off
set PATH=E:\MinGW\bin;%PATH%;
set DEBUG=1
setlocal

::mode 150,15
echo ::...::..:::...::..::.:.::
echo ::    SciTE Debug	::  
echo ::...::..:::...::..::.:.::

cd scintilla\win32
mingw32-make -j %NUMBER_OF_PROCESSORS%
if errorlevel 1 goto :error

cd ..\..\scite\win32
mingw32-make -j %NUMBER_OF_PROCESSORS%
if errorlevel 1 goto :error
copy ..\bin\scite.exe ..\..\

echo ------------------------------------------------
goto end

:error
pause

:end
cd ..\..
echo ------------------------------------------------
ECHO Waiting before closeing the window.
pause
EXIT
