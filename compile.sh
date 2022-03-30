#!/bin/bash

cmake -B ./build/ -S .
cd ./build/
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./HashMap