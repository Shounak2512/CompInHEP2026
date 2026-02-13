OBJS_TRACK = 4-mom.o
OBJS_SIM = SimParticle.o

LIB_TRACK = libtrack.a
LIB_SIM = libSimParticle.a

all: $(LIB_TRACK) $(LIB_SIM) test_tracks

4-mom.o: 4-mom.cpp 4-mom.h
	g++ -c 4-mom.cpp -o 4-mom.o

SimParticle.o: SimParticle.cpp SimParticle.h 4-mom.h
	g++ -c SimParticle.cpp -o SimParticle.o

$(LIB_TRACK): $(OBJS_TRACK)
	ar rcs $(LIB_TRACK) $(OBJS_TRACK)

$(LIB_SIM): $(OBJS_SIM)
	ar rcs $(LIB_SIM) $(OBJS_SIM)

test_tracks: test.cpp $(LIB_TRACK) $(LIB_SIM)
	g++ test.cpp -L. -lSimParticle -ltrack -o test_tracks


clean:
	rm -f *.o *.a test_tracks

#Used a LLM for the library building commands