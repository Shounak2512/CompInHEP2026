ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)   

CXX      = g++
CXXFLAGS = -O2 -std=c++17 $(ROOTCFLAGS)

SRC = randgen plot

all: $(SRC)

randgen: randgen.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(ROOTLIBS)

plot: plot.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(ROOTLIBS)

clean:
	rm -f $(SRC) *.o