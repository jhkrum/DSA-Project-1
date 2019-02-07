//
//	Created by Justin Krum 1/27/19
//

#include "Records.h"

using namespace std;

int main() {
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