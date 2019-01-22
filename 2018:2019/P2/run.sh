#!/bin/bash

reset
if [ -d built ];then
	cd built
	rm -R *
else
	mkdir built
	cd built
fi

cmake ..
make
echo "##### Running the program"
./a.out

cd ..
echo "##### Creating plot of times.txt"
./getplot.sh