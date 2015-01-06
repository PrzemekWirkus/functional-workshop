
CDIR=c:/Work/toolchains/tdm-gcc-4.9.2\bin/

CC=$(CDIR)gcc
CPP=$(CDIR)g++
CFLAGS=-I./src
CPPFLAGS=-std=c++11 -fdiagnostics-color=always
DEPS=utest.h
SRC=./src

TEST_CONF_OBJ=testconf.o

%.o: $(SRC)/%.cpp $(SRC)/$(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

# Test configuration rule
testconf: $(TEST_CONF_OBJ)
	$(CPP) -o $@ $^ $(CFLAGS) $(CPPFLAGS)

closure1: closure1.o
	$(CPP) -o $@ $^ $(CFLAGS) $(CPPFLAGS)

closure2: closure2.o
	$(CPP) -o $@ $^ $(CFLAGS) $(CPPFLAGS)

bind: bind.o
	$(CPP) -o $@ $^ $(CFLAGS) $(CPPFLAGS)

.PHONY: clean
clean:
	rm -f *.o *.exe
