#!/bin/bash

echo building ...

mkdir build

cd build/

cmake ..
make
./nippy
