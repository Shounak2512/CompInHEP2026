all: libMET.so testMET

libMET.so: MET.o
	g++ -shared -o libMET.so MET.o

MET.o: MET.cc MET.hh
	g++ -std=c++11 -c MET.cc -o MET.o

testMET: test.o libMET.so
	g++ test.o -o testMET -L. -lMET

test.o: test.cc MET.hh
	g++ -c test.cc -o test.o

test: testMET
	LD_LIBRARY_PATH=. ./testMET

clean:
	rm *.o libMET.so testMET