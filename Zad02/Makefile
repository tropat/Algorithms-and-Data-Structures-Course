CC	:= g++

.PHONY: all run clean

all: main.x 

main.x: main.cpp onewayList.cpp twowayList.cpp

%.x: %.cpp
	$(CC) -o $@ $^

run:
	make clean; make; clear; ./main.x;

clean:
	$(RM) *.x