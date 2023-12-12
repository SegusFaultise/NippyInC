#!/bin/bash

echo building ...
cd build/

cmake ..
make
./nippy
