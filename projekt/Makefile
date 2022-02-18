CC	:= g++

.PHONY: all run clean

all: test.x

test.x: test.cpp poly.cpp

%.x: %.cpp
	$(CC) -o $@ $^

run:
	make clean; make; clear; ./test.x;

clean:
	$(RM) *.x