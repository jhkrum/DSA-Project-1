CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Records.o Records.cpp
	mv Records.o ../../build/

test:
	$(CC) -o RecordsTester Records.cpp recordsTester.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp
	mv RecordsTester ../../tests/

clean:
	rm -f Records.o RecordsTester
