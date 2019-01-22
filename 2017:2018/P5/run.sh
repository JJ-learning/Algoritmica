#!/bin/bash

reset
echo "########### Creating built..."
cd built
echo "############### Compiling program..."
cmake ..
make
#reset 
echo "############### Program compiled, let's run it!"
./Cambio.out
