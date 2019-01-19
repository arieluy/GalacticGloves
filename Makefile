CXX=g++
CFLAGS=-Wall -O3 -g -Wextra -Wno-unused-parameter -lncurses -lwiringPi -pthread
CXXFLAGS=$(CFLAGS)
OBJECTS=monster.o gunner.o bullet.o draw.o model.o

all : gg

gg : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(OBJECTS)

monster.o : monster.cc
gunner.o : gunner.cc
bullet.o : bullet.cc
draw.o : draw.cc
model.o : model.cc

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(BINARIES)

FORCE:
.PHONY: FORCE
