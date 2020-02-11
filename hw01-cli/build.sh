#!/bin/bash
# Build a project in 'build' directory

export CC=gcc-7
export CXX=g++-7

mkdir build
cd build
cmake ..
make
cd ..
