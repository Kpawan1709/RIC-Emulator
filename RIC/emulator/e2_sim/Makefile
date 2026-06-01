all: bin/ric_emulator

bin/ric_emulator: ric_emulator.o lib/e2sm_rc_asn_enc_dec_3gpp.o
	gcc -g ric_emulator.o lib/e2sm_rc_asn_enc_dec_3gpp.o lib/libe2cucommonutils.a lib/libe2ducommon.a lib/libe2dumain.a lib/librichdl.a lib/libricmain.a -Llib -lsctp -le2ducommon -le2dumain -lcipher -lricmain -lasn1rt -lasn -lasn1per -lrichdl -o ./bin/ric_emulator

ric_emulator.o: main.c
	gcc -g -c -I ./inc main.c -o ric_emulator.o

clean:
	rm -f ./bin/* ric_emulator.o

