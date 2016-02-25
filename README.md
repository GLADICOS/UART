# UART 8 bit + parity whit Self Checking using SystemC model
This project provide the necessary to run a env test a simple uart verilog using SystemC and running it on icarus verilog

###Donate and help us "Bitcoin is the future"

 - 1CSZ9nHBWxLaf1nU9E9E15GAjKcYXD1wnV

###ABOUT this UART

This consist in a simple UART 8 bit using opensource rtl simulator icarus verilog with mixed code vpi "verilog procedural interface" and systemC. This uart is alredy tested on ALTERA FPGA and it work well. But RX could be more elaborated to take signal since he take just catch signal on middle of counter and not see another point of signal. But this is the base to elaborate another applications on future or modify it to a specific propurse. SystemC model do the same way but i need finish just check parity from DUT "Device under test" to SystemC model. 

 This IP was developed in order to:

  - Concepts acquired in training in the digital stream
  - Integration with free software
  - Different forms of functional verification
  - Projects aimed at ASIC
  - IP facing low density - average
  - Promoting microelectronics interested people on Latin America
  - Teamwork


###Requisites

 - Linux Distro
 - Icarus verilog [http://iverilog.icarus.com/]
 - SystemC 2.3 [http://accellera.org/downloads/standards/systemc]
 - gtkwave [http://gtkwave.sourceforge.net/]

*Obs: you need alredy know how to compile and understand concepts and how work icarus / SystemC / linux tools

###Configuration of Environment

To systemC , icarus verilog and gtkwave follow instalation guide provided by developers and make propely exports to linux distro see includes and objects used during build of environment. The folder work is where you need compile and execute the test using systemC and DUT in verilog. Note on env_uart.cpp some includes fail because location so you need set it where you have compiled or instaled icarus verilog. 

On work folder you should see after yoo installed systemC if is propely installed

```sh
$ ldd sc_uart.so
```

The result of command should be this 

```sh
	linux-vdso.so.1 (0x00007ffd92ffe000)
	libsystemc-2.3.0.so => /lib64/libsystemc-2.3.0.so (0x00007f24c2420000)
	libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x00007f24c209d000)
	libm.so.6 => /lib64/libm.so.6 (0x00007f24c1d9c000)
	libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007f24c1b85000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f24c17de000)
	libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f24c15c0000)
	/lib64/ld-linux-x86-64.so.2 (0x000056321eb36000)
```

To Run environment just do the follow command

```sh
  bash run.sh
```

Whit this simulation you can generate till 1000 data. This a sample used to proof viability using icarus verilog like a simulator whit mixed code. More information enter in contact with some propose.  
