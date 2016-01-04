#!/bin/bash
gcc -shared -o libHello.so -fPIC lib.c
gcc start.c -ldl -o start
chmod +x start
chmod +x start.sh
mkdir build
mv libHello.so build/
mv start build/
cp start.sh build/
cd build
./start.sh
cd ..
