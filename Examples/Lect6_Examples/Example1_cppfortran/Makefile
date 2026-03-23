FSRC = $(wildcard *.F)
FOBJ = $(addsuffix .o,$(basename $(FSRC)))

OPT = -O -Wall -fPIC
INC = -I.
LIBS = -L. -lPrint

FC = gfortran
CPP = g++

.F.o:
	$(FC) $(OPT) $(INC) -c $^ -o $@
.cc.o:
	$(FC) $(OPT) $(INC) -c $^ -o $@

all:
	$(MAKE) libPrint.so
	$(MAKE) test

libPrint.so: $(FOBJ) interface.o 
	$(FC) -shared  $(FOBJ) interface.o -o libPrint.so

test: main.o libPrint.so
	$(CPP) main.o $(LIBS) -o test

clean:
	rm -f *.o *~

cleanAll:
	$(MAKE) clean
	rm -rf libPrint.so test
