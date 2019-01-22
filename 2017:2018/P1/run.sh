#!/bin/bash

reset
echo "########### Creating built..."
make funcion
echo "############### Program compiled, let's run it!"
cd built
./exe.out
cd ..
echo "############### Creating plot of data.txt"
./getplot.sh	
