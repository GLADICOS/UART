# UART 8 bit + parity whit Self Checking using SystemC model
This project provide the necessary to run a env test a simple uart verilog using SystemC and running it on icarus verilog


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
 - gtk3
 - libboost
 - gtkmm
 - glade

*Obs: you need alredy know how to compile and understand concepts and how work icarus / SystemC / linux tools

###Configuration of Environment

To systemC , icarus verilog and gtkwave follow instalation guide provided by developers and make propely exports to linux distro see includes and objects used during build of environment. The folder work is where you need compile and execute the test using systemC and DUT in verilog. Note on env_uart.cpp some includes fail because location so you need set it where you have compiled or instaled icarus verilog. 

On work folder you should see after yoo installed systemC if is propely installed

```sh
$ ldd sc_uart.so
```

The result of command should be this 

```sh
	linux-vdso.so.1 (0x00007ffe3c1ec000)
	libsystemc-2.3.0.so => /systemc-2.3.0/lib-linux64/libsystemc-2.3.0.so (0x00007f752f1ef000)
	libgtkmm-3.0.so.1 => /usr/lib64/libgtkmm-3.0.so.1 (0x00007f752ea75000)
	libatkmm-1.6.so.1 => /usr/lib64/libatkmm-1.6.so.1 (0x00007f752e828000)
	libgdkmm-3.0.so.1 => /usr/lib64/libgdkmm-3.0.so.1 (0x00007f752e5e1000)
	libgiomm-2.4.so.1 => /usr/lib64/libgiomm-2.4.so.1 (0x00007f752e234000)
	libpangomm-1.4.so.1 => /usr/lib64/libpangomm-1.4.so.1 (0x00007f752e006000)
	libglibmm-2.4.so.1 => /usr/lib64/libglibmm-2.4.so.1 (0x00007f752dd8c000)
	libgtk-3.so.0 => /usr/lib64/libgtk-3.so.0 (0x00007f752d4ac000)
	libgdk-3.so.0 => /usr/lib64/libgdk-3.so.0 (0x00007f752d1ff000)
	libpangocairo-1.0.so.0 => /usr/lib64/libpangocairo-1.0.so.0 (0x00007f752cff2000)
	libpango-1.0.so.0 => /usr/lib64/libpango-1.0.so.0 (0x00007f752cda6000)
	libatk-1.0.so.0 => /usr/lib64/libatk-1.0.so.0 (0x00007f752cb80000)
	libcairo-gobject.so.2 => /usr/lib64/libcairo-gobject.so.2 (0x00007f752c977000)
	libgio-2.0.so.0 => /usr/lib64/libgio-2.0.so.0 (0x00007f752c5f7000)
	libcairomm-1.0.so.1 => /usr/lib64/libcairomm-1.0.so.1 (0x00007f752c3d1000)
	libcairo.so.2 => /usr/lib64/libcairo.so.2 (0x00007f752c0af000)
	libsigc-2.0.so.0 => /usr/lib64/libsigc-2.0.so.0 (0x00007f752bea8000)
	libgdk_pixbuf-2.0.so.0 => /usr/lib64/libgdk_pixbuf-2.0.so.0 (0x00007f752bc85000)
	libgobject-2.0.so.0 => /usr/lib64/libgobject-2.0.so.0 (0x00007f752ba34000)
	libglib-2.0.so.0 => /usr/lib64/libglib-2.0.so.0 (0x00007f752b724000)
	libboost_thread.so.1.54.0 => /usr/lib64/libboost_thread.so.1.54.0 (0x00007f752b50c000)
	libboost_system.so.1.54.0 => /usr/lib64/libboost_system.so.1.54.0 (0x00007f752b308000)
	libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x00007f752af83000)
	libm.so.6 => /lib64/libm.so.6 (0x00007f752ac82000)
	libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007f752aa6b000)
	libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f752a84d000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f752a4a5000)
	libgmodule-2.0.so.0 => /usr/lib64/libgmodule-2.0.so.0 (0x00007f752a2a0000)
	libX11.so.6 => /usr/lib64/libX11.so.6 (0x00007f7529f62000)
	libXi.so.6 => /usr/lib64/libXi.so.6 (0x00007f7529d52000)
	libXfixes.so.3 => /usr/lib64/libXfixes.so.3 (0x00007f7529b4b000)
	libatk-bridge-2.0.so.0 => /usr/lib64/libatk-bridge-2.0.so.0 (0x00007f752991d000)
	libepoxy.so.0 => /usr/lib64/libepoxy.so.0 (0x00007f7529623000)
	libpangoft2-1.0.so.0 => /usr/lib64/libpangoft2-1.0.so.0 (0x00007f752940e000)
	libfontconfig.so.1 => /usr/lib64/libfontconfig.so.1 (0x00007f75291d1000)
	libXinerama.so.1 => /usr/lib64/libXinerama.so.1 (0x00007f7528fce000)
	libXrandr.so.2 => /usr/lib64/libXrandr.so.2 (0x00007f7528dc2000)
	libXcursor.so.1 => /usr/lib64/libXcursor.so.1 (0x00007f7528bb7000)
	libXcomposite.so.1 => /usr/lib64/libXcomposite.so.1 (0x00007f75289b4000)
	libXdamage.so.1 => /usr/lib64/libXdamage.so.1 (0x00007f75287b0000)
	libXext.so.6 => /usr/lib64/libXext.so.6 (0x00007f752859e000)
	librt.so.1 => /lib64/librt.so.1 (0x00007f7528396000)
	libfreetype.so.6 => /usr/lib64/libfreetype.so.6 (0x00007f75280fe000)
	libz.so.1 => /lib64/libz.so.1 (0x00007f7527ee8000)
	libselinux.so.1 => /lib64/libselinux.so.1 (0x00007f7527cc3000)
	libresolv.so.2 => /lib64/libresolv.so.2 (0x00007f7527aac000)
	libpixman-1.so.0 => /usr/lib64/libpixman-1.so.0 (0x00007f7527801000)
	libEGL.so.1 => /usr/lib64/libEGL.so.1 (0x00007f75275d8000)
	libdl.so.2 => /lib64/libdl.so.2 (0x00007f75273d4000)
	libpng16.so.16 => /usr/lib64/libpng16.so.16 (0x00007f7527197000)
	libxcb-shm.so.0 => /usr/lib64/libxcb-shm.so.0 (0x00007f7526f93000)
	libxcb-render.so.0 => /usr/lib64/libxcb-render.so.0 (0x00007f7526d89000)
	libxcb.so.1 => /usr/lib64/libxcb.so.1 (0x00007f7526b69000)
	libXrender.so.1 => /usr/lib64/libXrender.so.1 (0x00007f752695e000)
	libGL.so.1 => /usr/lib64/libGL.so.1 (0x00007f75266cd000)
	libffi.so.4 => /usr/lib64/libffi.so.4 (0x00007f75264c3000)
	libpcre.so.1 => /usr/lib64/libpcre.so.1 (0x00007f752625d000)
	/lib64/ld-linux-x86-64.so.2 (0x0000563bbfa45000)
	libatspi.so.0 => /usr/lib64/libatspi.so.0 (0x00007f752602c000)
	libdbus-1.so.3 => /lib64/libdbus-1.so.3 (0x00007f7525de5000)
	libharfbuzz.so.0 => /usr/lib64/libharfbuzz.so.0 (0x00007f7525b85000)
	libexpat.so.1 => /usr/lib64/libexpat.so.1 (0x00007f752595a000)
	libbz2.so.1 => /usr/lib64/libbz2.so.1 (0x00007f752574b000)
	libX11-xcb.so.1 => /usr/lib64/libX11-xcb.so.1 (0x00007f7525548000)
	libxcb-dri2.so.0 => /usr/lib64/libxcb-dri2.so.0 (0x00007f7525343000)
	libxcb-xfixes.so.0 => /usr/lib64/libxcb-xfixes.so.0 (0x00007f752513c000)
	libgbm.so.1 => /usr/lib64/libgbm.so.1 (0x00007f7524f2d000)
	libwayland-client.so.0 => /usr/lib64/libwayland-client.so.0 (0x00007f7524d1f000)
	libwayland-server.so.0 => /usr/lib64/libwayland-server.so.0 (0x00007f7524b0d000)
	libdrm.so.2 => /usr/lib64/libdrm.so.2 (0x00007f75248fd000)
	libXau.so.6 => /usr/lib64/libXau.so.6 (0x00007f75246f9000)
	libglapi.so.0 => /usr/lib64/libglapi.so.0 (0x00007f75244ca000)
	libxcb-glx.so.0 => /usr/lib64/libxcb-glx.so.0 (0x00007f75242b2000)
	libxcb-dri3.so.0 => /usr/lib64/libxcb-dri3.so.0 (0x00007f75240af000)
	libxcb-present.so.0 => /usr/lib64/libxcb-present.so.0 (0x00007f7523eab000)
	libxcb-sync.so.1 => /usr/lib64/libxcb-sync.so.1 (0x00007f7523ca5000)
	libxshmfence.so.1 => /usr/lib64/libxshmfence.so.1 (0x00007f7523aa2000)
	libXxf86vm.so.1 => /usr/lib64/libXxf86vm.so.1 (0x00007f752389b000)
	libgraphite2.so.3 => /usr/lib64/libgraphite2.so.3 (0x00007f7523672000)
```

To Run environment just do the follow command

```sh
  bash run.sh
```

###What I have done till now

 - Graphical interface to a better experience 
 - Dinamic change clock during environment execution 
 - A set of baud rates i found across internet to test suit 
 - A output file in html format TX SystemC 2 RX Verilog contain data compared 

### BUGS ? :-(

 - Crashes when you change frequency with no specific baud rate
 - Log in html data goes wrong after a reset

### What i will do on future if i still alive :-D

 - Make output file in html format TX Verilog 2 RX SystemC contain data compared
 - Found the reason 'real one' to crash simulation on change clock
 - Make avaiable to user insert data during execution
