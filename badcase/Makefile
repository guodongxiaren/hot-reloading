LIB = libkids.so
BIN = main
SOURCE = $(wildcard *.cpp)
OBJECT = $(SOURCE:%.cpp=%.o)
DIR = $(shell dirname `pwd`)/lib
CC = g++
CFLAGS = -std=c++11 -Werror=return-type

ALL: $(BIN) $(LIB)

$(LIB): alice.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) -fPIC -c -o $@ $^

#$(BIN): main.cpp test.o
$(BIN): main.cpp
	$(CC) $(CFLAGS) $^ -o $@ -ldl

.PHONY: clean install
clean:
	rm -rf *.out *.o *.so *.so.* *.lib
install:
	install -m 755 $(LIB) /usr/local/lib/
