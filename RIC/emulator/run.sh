#! /bin/bash


ulimit -q unlimited
ulimit -c unlimited
export LD_LIBRARY_PATH=/home/lakshmipriya/Emulator/RIC/emulator/lib
#export LD_LIBRARY_PATH=/app/RIC/emulator/lib
rm -f core* ric_log.logs


#./bin/ric_emulator 2>&1 | tee ric_log.logs  ./bin/ric_emulator 
  ./bin/ric_emulator

