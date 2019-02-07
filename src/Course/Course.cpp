//
//	Created by Justin Krum 1/24/19
//

#include "Course.h"

using namespace std;

//Sets all the values for the course, without initializing a new course
void Course::setAll(const string code, const string title, double grade, uint8_t creditHour) {
	Course::setCode(code);
	Course::setTitle(title);
	Course::setGrade(grade);
	Course::setCreditHour(creditHour);
}

//Gets the course code
const string Course::getCode() {
	return code;
}

//Sets the course code
void Course::setCode(const string code) {
	Course::code = code;
}

//Gets the course title
const string Course::getTitle() {
	return title;
}

//Sets the course title
void Course::setTitle(const string title) {
	Course::title = title;
}

//Gets the grade in the course
double Course::getGrade() {
	return grade;
}

//Sets the grade in the course
void Course::setGrade(double grade) {
	Course::grade = grade;
}

//Gets the credit hours the course is worth
uint8_t Course::getCreditHour() {
	return creditHour;
}

//Sets the credit hours the course is worth
void Course::setCreditHour(uint8_t creditHour) {
	Course::creditHour = creditHour;
}

//Default constructor
Course::Course() {

}

//Parametrized constructor
Course::Course(string codePar, string titlePar, double gradePar, uint8_t creditHourPar) {
	code = codePar;
	title = titlePar;
	grade = gradePar;
	creditHour = creditHourPar;
}

ostream& operator<<(ostream& os, const Course &c)
{
	os << c.code << ": " << c.title << " ( GPA: " << c.grade << " ) " << unsigned(c.creditHour) << " Credit Hour(s)" << endl;
	return os;
}