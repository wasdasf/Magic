#!/bin/zsh

clear

cmake -D CMAKE_C_COMPILER=i686-w64-mingw32-gcc -D CMAKE_CXX_COMPILER=i686-w64-mingw32-g++ -Wno-dev zydis -B zydis

cmake -D CMAKE_C_COMPILER=i686-w64-mingw32-gcc -D CMAKE_CXX_COMPILER=i686-w64-mingw32-g++ -Wno-dev zydis/dependencies/zycore -B zydis/dependencies/zycore

cmake -D CMAKE_C_COMPILER=i686-w64-mingw32-gcc -D CMAKE_CXX_COMPILER=i686-w64-mingw32-g++ -Wno-dev -B CMake

make -C CMake -s
