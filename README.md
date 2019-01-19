# GalacticGloves
Build18 project for Jan 2019!
By Ariel Uy, Jade Traiger, Cassandra Chen

Play a Space Invaders-like game on an LED display, controlled by physical inputs on a glove.

To compile:

g++ -c gunner.cc bullet.cc monster.cc draw.cc model.cc 

g++ gunner.o bullet.o monster.o draw.o model.o ./rpi-rgb-led-matrix-master/\*.o -pthread -lwiringPi -lncurses -o gg

To run:

sudo ./gg
