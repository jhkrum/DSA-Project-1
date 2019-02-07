//
//	Created by Justin Krum 1/27/19
//

#include "Records.h"

using namespace std;

//Returns the total number of students
uint32_t Records::getNumberOfStudents() {
	return numberOfStudents;
}

//Sets the total number of students
void Records::setNumberOfStudents(uint32_t numberOfStudents) {
	Records::numberOfStudents = numberOfStudents;
}

//Returns the average GPA
double Records::getAverageGPA() {
	return averageGPA;
}

//Sets the average GPA of students
void Records::setAverageGPA(double averageGPA) {
	Records::averageGPA = averageGPA;
}

//Parametrized operator
Records::Records(vector<Student> studentsPar) {
	students = studentsPar;
	numberOfStudents = students.size();	//Sets the number of students
	averageGPA = 0;
	if (numberOfStudents != 0) {
		for (Student s : students) {
			averageGPA += s.getGPA();	//Sums all GPAs together
		}
		averageGPA = averageGPA / numberOfStudents;	//Averages the GPAs
	}
}

//Default constructor
Records::Records() {
	
}

ostream& operator<<(ostream &os, const Records &r) {
	os << "Number of Students: " << r.numberOfStudents << "\nAverage GPA = " << r.averageGPA << endl;

	for (Student s : r.students) {
		os << "\n" << s;
	}

	return os;
}