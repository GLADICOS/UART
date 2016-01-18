
g++ -c -ldl -fpic ../vpi/env_uart.cpp  -std=c++11 -Wwrite-strings -fpermissive -lboost_thread 

g++ -shared  -oenv_uart.vpi env_uart.o -lvpi -std=c++11 -Wwrite-strings -fpermissive -lboost_thread


iverilog -oenv_uart ../rtl/*.v ../testbench/module_tb.v 


vvp -M. -menv_uart env_uart
