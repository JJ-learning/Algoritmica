#!/bin/bash

reset
if [ -d built ];then
	cd built
	rm -rf *
else
	mkdir built
	cd built
fi

cmake ..
make
if [ -f a.out ]; then
	reset
fi
echo "##### Running the program"
./a.out
