//
//	Created by Justin Krum 1/24/19
//

#include "Course.h"

using namespace std;


void Course::setAll(const string code, const string title, double grade, uint8_t creditHour) {
	Course::setCode(code);
	Course::setTitle(title);
	Course::setGrade(grade);
	Course::setCreditHour(creditHour);
}

const string &Course::getCode() {
	return code;
}

void Course::setCode(const string code) {
	Course::code = code;
}

const string &Course::getTitle() {
	return title;
}

void Course::setTitle(const string title) {
	Course::title = title;
}

double Course::getGrade() {
	return grade;
}

void Course::setGrade(double grade) {
	Course::grade = grade;
}

uint8_t Course::getCreditHour() {
	return creditHour;
}

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