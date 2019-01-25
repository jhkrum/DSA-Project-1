//
//	Created by Justin Krum 1/24/19
//

#include <iostream>
#include "Course.h"
#include "Person.h"

using namespace std;

//Formerly personTest.cpp
//Reduced to a function to reduce complexity
static int personTest() {
	Person p("John Doe", 38);

	cout << p;

	return 0;
}

//Formerly courseTest.cpp
//Reduced to a function to reduce complexity
static int courseTest() {
	Course c("COP3530", "Data Structures & Algortihms", 3.5, 4);

	cout << c << "\n\n";

	c.setAll("Test", "Test2", 1, 2);

	cout << c << endl;

	return 0;
}

int main() {

	//personTest();
	//courseTest();

	return 0;
}