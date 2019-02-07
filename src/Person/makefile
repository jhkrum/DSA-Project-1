CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Person.o Person.cpp
	mv Person.o ../../build/

test:
	$(CC) -o PersonTester Person.cpp PersonTester.cpp
	mv PersonTester ../../tests/

clean:
	rm -f Person.o PersonTester
