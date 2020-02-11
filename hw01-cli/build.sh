#!/bin/bash
# Build a project in 'build' directory

sudo apt-get install libboost-dev

export CC=gcc-7
export CXX=g++-7

mkdir build
cd build
cmake ..
make
cd ..
