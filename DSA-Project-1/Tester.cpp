//
//	Created by Justin Krum 1/24/19
//

#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Records.h"
#include "Database.h"
#include "Menu.h"

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

static int studentTest() {
	Course c("COP3530", "Data Structures & Algortihms", 3.5, 4);
	vector<Course> temp;
	temp.push_back(c);

	Student s("Nisha", 20, 4, 1, 1111, temp);

	cout << s << "\n\n";

	s.deleteCourse("COP3530");

	cout << s << endl;

	return 0;
}

static int recordsTest() {
	Course c("COP3530", "Data Structures & Algortihms", 3.5, 4);
	vector<Course> courses;
	courses.push_back(c);
	Student s("Nisha", 20, 4, 2, 1111, courses);
	Student s2("Justin", 20, 4, 2, 1111, courses);
	vector<Student> students = {};

	Records r(students);

	cout << r;

	return 0;
}

static int databaseTest() {
	Database d("default.csv", "coursesDefaults.csv");
	d.loadFiles();
}

int main() {

	//personTest();
	//courseTest();
	//studentTest();
	//recordsTest();
	//databaseTest();

	Database d("default.csv", "coursesDefaults.csv");
	Menu menu(d);

	menu.displayMenu();

	return 0;
}