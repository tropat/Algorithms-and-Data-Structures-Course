CC	:= g++

.PHONY: all run clean

all: main.x 

main.x: main.cpp bubbleSort.cpp mergeSort.cpp

%.x: %.cpp
	$(CC) -o $@ $^

run:
	make clean; make; clear; ./main.x; python3 wykresy.py

clean:
	$(RM) *.x *.data