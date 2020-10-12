# GalacticGloves
Build18 project for Jan 2019!
By Ariel Uy, Jade Traiger, Cassandra Chen

<img src="https://lh3.googleusercontent.com/p-jZd-pDnktuaoaCoHK6gYK9weTLneu56oUVouiT7F-bz-RmFGdSaVkF3G68cjXesoIU7Sg9AHFUgGhuXMb4Rwk3DW3m4igsG00ZH_lE3_XYR4XvKsw=w1280">

Play a Space Invaders-like game on an LED display, controlled by physical inputs on a glove.

To compile:

g++ -c gunner.cc bullet.cc monster.cc draw.cc model.cc 

g++ gunner.o bullet.o monster.o draw.o model.o ./rpi-rgb-led-matrix-master/\*.o -pthread -lwiringPi -lncurses -o gg

To run:

sudo ./gg
