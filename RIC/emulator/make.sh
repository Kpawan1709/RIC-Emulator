#!/bin/bash
echo $1

rm -f ric_emulator.o

if [ $1 -eq 1 ] ;then
	make clean
	make
elif [ $1 -eq 2  ] ; then
	cd e2smkpm
	make clean
	make
	cd ../

elif [ $1 -eq 3  ] ; then
	cd e2_sim
	make clean
	make
	cd ../
else
	cd MakeKPM && make clean && make && cd ../
fi


# add one more condition and compile your code  
