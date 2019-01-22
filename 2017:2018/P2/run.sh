#!/bin/bash

reset
echo "############### Compiling program..."
cd built
cmake ..
make
#reset 
echo "############### Program compiled, let's run it!"
./Chess.out
#cd ..
#./getplot.sh