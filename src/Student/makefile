CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Student.o Student.cpp
	mv Student.o ../../build/

test:
	$(CC) -o StudentTester Student.cpp StudentTester.cpp ../Person/Person.cpp ../Course/Course.cpp
	mv StudentTester ../../tests/

clean:
	rm -f Student.o StudentTester
