md .\build
pushd .\build
del /a CMakeCache.txt
cmake -G "Visual Studio 15 2017 Win64"  ..
cmake --build . --config Release
cmake --build . --config Debug
pause