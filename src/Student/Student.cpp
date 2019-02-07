//
//	Created by Justin Krum 1/24/19
//

#include "Student.h"

using namespace std;

//Adds a course onto the Student's courseList
void Student::addCourse(Course c) {
	courses.push_back(c);	//Adds the course to the list
	numberOfCourses = courses.size();	//Recalculates number of courses
	uint32_t temp = 0;
	for (Course c : courses) {
		temp += c.getCreditHour();	//Calculates total Credit hours
	}
	totalCreditHours = temp;
	gpa = recalculateGPA();	//Recalculates GPA
}

//Deletes course from a Student's courseList
void Student::deleteCourse(string courseCode) {
	for (int i = 0; i < courses.size(); i++) {
		if (courses.at(i).getCode().compare(courseCode) == 0) {
			totalCreditHours -= courses.at(i).getCreditHour();	//Calculates total credit hours
			courses.erase(courses.begin() + i);	//Removes course from the list
			numberOfCourses--;	//Recalculates the number of courses
			gpa = recalculateGPA();	//Recaulcuates GPA
		}
	}
}

//Recalculates GPA of students
double Student::recalculateGPA() {
	double newGPA = 0;
	if (Student::courses.size() == 0) return 0;
	for (Course c : Student::courses) {
		newGPA += c.getGrade()*c.getCreditHour();	//Adds the weighted gpas of every course together
	}

	newGPA /= totalCreditHours;	//Divides by the new credit hours

	return newGPA;
}

//Sets the total amount of credit hours for the Student
uint32_t Student::getTotalCreditHours() {
	return totalCreditHours;
}

//Sets the total amount of credit hours for the Student
void Student::setTotalCreditHours(uint32_t totalCreditHours) {
	Student::totalCreditHours = totalCreditHours;
}

//Gets the number of courses for the Student
uint32_t Student::getNumberOfCourses() {
	return numberOfCourses;
}

//Sets the number of courses for the Student
void Student::setNumberOfCourses(uint32_t numberOfCourses) {
	Student::numberOfCourses = numberOfCourses;
}

//Gets the unique id for the Student
uint32_t Student::getUid() {
	return uid;
}

//Sets the unique id for the Student
void Student::setUid(uint32_t uid) {
	Student::uid = uid;
}

//Gets the gpa for the Student
double Student::getGPA() {
	return gpa;
}

//Sets the gpa for the Student
void Student::setGPA(double gpa) {
	Student::gpa = gpa;
}

//Gets the list of courses for the Student
vector<Course> Student::getCourses() {
	return courses;
}

//Sets the list of courses for the Student
void Student::setCourses(vector<Course> courses) {
	Student::courses = courses;
}

//Sets the total amount of credit hours for the Student
Student::Student(string name, uint8_t age, uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uidPar, vector<Course> coursesPar) : Person(name, age) {
	totalCreditHours = totalCreditHoursPar;
	numberOfCourses = numberOfCoursesPar;
	uid = uidPar;
	courses = coursesPar;
	gpa = recalculateGPA();
}

//Sets the total amount of credit hours for the Student
Student::Student() : Person(){
	totalCreditHours = 0;
	numberOfCourses = 0;
	gpa = 0;
}

ostream& operator<<(std::ostream &os, const Student &s) {
	os << "Name: " << s.name << "\nAge: " << s.age << "\nCredit Hours: " << s.totalCreditHours << "\nGPA: " << s.gpa << "\nNumber of Courses: " << s.numberOfCourses << endl;

	for (Course c : s.courses) {
		os << c;
	}

	return os;
}