all: ric_emulator

ric_emulator:ric_emulator.o trl8.o config.o  ric_control.o dec_ind.o
	gcc -g  ric_emulator.o  trl8.o config.o  ric_control.o dec_ind.o ./lib/e2sm_rc_asn_enc_dec_3gpp.o  -lsctp -L ./lib/ -le2ducommon -le2dumain -lcipher -lricmain -lasn1rt -lasn -lasn1per -lrichdl -o ./bin/ric_emulator


ric_emulator.o:./e2smrc/Ric_hdl.c
	#gcc -g -c -I ./inc/  ./e2smrc/Ric_hdl.c -o ric_emulator.o
	gcc -g -c -I ./inc -I .. ./e2smrc/Ric_hdl.c -o ric_emulator.o
	#gcc -g -c -I ./inc/ -I /app/RIC ./e2smrc/Ric_hdl.c -o ric_emulator.o
trl8.o:./e2smrc/trl8.c
	gcc -g -c -I ./inc/  ./e2smrc/trl8.c -o trl8.o
	#gcc -g -c -I ./inc/ -I /app/RIC ./e2smrc/trl8.c -o trl8.o
config.o: ./e2smrc/config.c
	gcc -g -c -I ./inc/ ./e2smrc/config.c -o config.o

ric_control.o:./e2smrc/ric_control.c
	#gcc -g -c -I ./inc/  ./e2smrc/ric_control.c -o ric_control.o
	gcc -g -c -I ./inc/ -I ..  ./e2smrc/ric_control.c -o ric_control.o        
dec_ind.o: ./e2smrc/dec_ind.c
	gcc -g -c -I ./inc -I ..  ./e2smrc/dec_ind.c -o dec_ind.o
	#gcc -g -c -I ./inc/  ./e2smrc/dec_ind.c -o dec_ind.o

clean:
	rm -f ./bin/* && rm -f ric_emulator.o
	rm -f ./bin/* && rm -f ric_control.o
	rm -f ./bin/* && rm -f dec_ind.o 
