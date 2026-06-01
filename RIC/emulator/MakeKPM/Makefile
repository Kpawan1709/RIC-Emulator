all:../bin/ric_emulator

../bin/ric_emulator:../ric_emulator.o 
	gcc -g  ../ric_emulator.o ../lib/e2sm_rc_asn_enc_dec_3gpp.o  -lsctp -L ../lib/ -le2ducommon -le2dumain -lcipher -lricmain -lasn1rt -lasn -lasn1per -lrichdl -o ../bin/ric_emulator


../ric_emulator.o:../src/Ric_hdl.c 
	gcc -g -c -I ../inc/  ../src/Ric_hdl.c -o ../ric_emulator.o

	

clean:
	 rm -f ../bin/* && rm -f ../ric_emulator.o	
