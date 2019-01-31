//
//	Created by Justin Krum 1/24/19
//

#include "Student.h"

using namespace std;

void Student::addCourse(Course c) {
	courses.push_back(c);
	numberOfCourses++;
	gpa = recalculateGPA();
}

void Student::deleteCourse(string courseCode) {
	for (int i = 0; i < courses.size(); i++) {
		if (courses.at(i).getCode().compare(courseCode) == 0) {
			totalCreditHours -= courses.at(i).getCreditHour();
			courses.erase(courses.begin() + i);
			numberOfCourses--;
			gpa = recalculateGPA();
		}
	}
}

double Student::recalculateGPA() {
	double newGPA = 0;
	if (Student::courses.size() == 0) return 0;
	for (Course c : Student::courses) {
		newGPA += c.getGrade()*c.getCreditHour();
	}

	newGPA /= totalCreditHours;

	return newGPA;
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

Student::Student(string name, uint8_t age, uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uidPar, vector<Course> coursesPar) : Person(name, age) {
	totalCreditHours = totalCreditHoursPar;
	numberOfCourses = numberOfCoursesPar;
	uid = uidPar;
	courses = coursesPar;
	gpa = recalculateGPA();
}

Student::Student() : Person(){

}

ostream& operator<<(std::ostream &os, const Student &s) {
	os << "Name: " << s.name << "\nAge: " << s.age << "\nCredit Hours: " << s.totalCreditHours << "\nGPA: " << s.gpa << "\nNumber of Courses: " << s.numberOfCourses << endl;

	for (Course c : s.courses) {
		os << c;
	}

	return os;
}