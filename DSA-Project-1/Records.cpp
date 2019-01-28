//
//	Created by Justin Krum 1/27/19
//

#include "Records.h"

using namespace std;

uint32_t Records::getNumberOfStudents() {
	return numberOfStudents;
}

void Records::setNumberOfStudents(uint32_t numberOfStudents) {
	Records::numberOfStudents = numberOfStudents;
}

double Records::getAverageGPA() {
	return averageGPA;
}

void Records::setAverageGPA(double averageGPA) {
	Records::averageGPA = averageGPA;
}

Records::Records(vector<Student> studentsPar) {
	students = studentsPar;
	numberOfStudents = students.size();
	averageGPA = 0;
	if (numberOfStudents != 0) {
		for (Student s : students) {
			averageGPA += s.getGPA();
		}
		averageGPA = averageGPA / numberOfStudents;
	}
}

Records::Records() {
	
}

ostream& operator<<(ostream &os, const Records &r) {
	os << "Number of Students: " << r.numberOfStudents << "\nAverage GPA = " << r.averageGPA << endl;

	for (Student s : r.students) {
		os << "\n" << s;
	}

	return os;
}