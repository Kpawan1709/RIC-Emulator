all: ric_emulator

ric_emulator:./src/Ric_hdl.c 
	gcc -g -I ./inc/ ./src/Ric_hdl.c -lsctp -L ./lib/ -le2ducommon -le2dumain -lcipher -lricmain -lasn1rt -lasn -lasn1per -lrichdl -o ./bin/ric_emulator


clean:
	 rm -f ./bin/*
	
