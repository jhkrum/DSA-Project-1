//
//	Created by Justin Krum 1/24/19
//

#include "Student.h"

using namespace std;

void Student::addCourse(string codePar, string titlePar, double gradePar, uint8_t creditHourPar) {
	Course newCourse(codePar, titlePar, gradePar, creditHourPar);
	courses.push_back(newCourse);
}

void Student::deleteCourse(string courseCode) {
	for (int i = 0; i < courses.size(); i++) {
		if (courses.at(i).getCode().compare(courseCode) == 0) {
			courses.erase(courses.begin() + i);
			numberOfCourses--;
		}
	}
}
uint32_t Student::getTotalCreditHours() {
	return totalCreditHours;
}

void Student::setTotalCreditHours(uint32_t totalCreditHours) {
	Student::totalCreditHours = totalCreditHours;
}

uint32_t Student::getNumberOfCourses() {
	return numberOfCourses;
}

void Student::setNumberOfCourses(uint32_t numberOfCourses) {
	Student::numberOfCourses = numberOfCourses;
}

uint32_t Student::getUid() {
	return uid;
}

void Student::setUid(uint32_t uid) {
	Student::uid = uid;
}

double Student::getGPA() {
	return gpa;
}

void Student::setGPA(double gpa) {
	Student::gpa = gpa;
}

vector<Course> Student::getCourses() {
	return courses;
}

void Student::setCourses(vector<Course> courses) {
	Student::courses = courses;
}

Student::Student(string name, uint8_t age, uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uidPar, double gpaPar, vector<Course> coursesPar) : Person(name, age) {
	totalCreditHours = totalCreditHoursPar;
	numberOfCourses = numberOfCoursesPar;
	uid = uidPar;
	gpa = gpaPar;
	courses = coursesPar;
}

Student::Student() : Person(){

}

ostream& operator<<(std::ostream &os, const Student &s) {
	os << "Name: " << s.name << "\nAge: " << s.age << "\nCredit Hours: " << s.totalCreditHours << "\nGPA:" << s.gpa << "\nNumber of Courses:" << s.numberOfCourses;

	for (Course c : s.courses) {
		os << "\n" << c << endl;
	}

	return os;
}