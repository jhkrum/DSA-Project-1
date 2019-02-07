CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Database.o Database.cpp
	mv Database.o ../../build/

test:
	$(CC) -o DatabaseTester Database.cpp DatabaseTester.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp ../Records/Records.cpp
	mv DatabaseTester ../../tests/

clean:
	rm -f Records.o RecordsTester
