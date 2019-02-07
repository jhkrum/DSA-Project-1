CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Menu.o Menu.cpp
	mv Menu.o ../../build/

test:
	$(CC) -o MenuTester Menu.cpp MenuTester.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp ../Records/Records.cpp ../Database/Database.cpp
	mv MenuTester ../../tests/

clean:
	rm -f Menu.o MenuTester
