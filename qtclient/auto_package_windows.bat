md .\pkg
xcopy /Y build\Release\qtclient.exe pkg\
pushd .\pkg
windeployqt.exe qtclient.exe
pause