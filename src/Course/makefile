CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Course.o Course.cpp
	mv Course.o ../../build/

test:
	$(CC) -o CourseTester Course.cpp courseTester.cpp
	mv CourseTester ../../tests/

clean:
	rm -f Course.o CourseTester
