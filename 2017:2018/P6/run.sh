#!/bin/bash

reset
echo "########### Creating built..."
cd built
cmake ..
make
echo "############### Program compiled, let's run it!"
./board.out
