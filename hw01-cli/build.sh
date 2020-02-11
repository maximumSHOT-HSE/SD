#!/bin/bash
# Build a project in 'build' directory

unset BOOST_ROOT
sudo apt install -y libboost-dev libboost-thread-dev libboost-system-dev libboost-date-time-dev libboost-regex-dev libboost-filesystem-dev libboost-random-dev libboost-chrono-dev libboost-serialization-dev

export CC=gcc-8
export CXX=g++-8

mkdir build
cd build
cmake ..
make
cd ..
