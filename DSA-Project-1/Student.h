//
//	Created by Justin Krum 1/24/19
//

#ifndef COP3530_STUDENT_H
#define COP3530_STUDENT_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include "Course.h"
#include "Person.h"

class Student : public Person{

private:
	uint32_t totalCreditHours;
	uint32_t numberOfCourses;
	uint32_t uid;
	double gpa;
	std::vector<Course> courses;
	
	double recalculateGPA();
public:

	Student();
	Student(std::string name, uint8_t age, uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uidPar, std::vector<Course> coursesPar);

	void addCourse(Course c);
	void deleteCourse(std::string courseCode);

	uint32_t getTotalCreditHours();
	void setTotalCreditHours(uint32_t totalCreditHours);

	uint32_t getNumberOfCourses();;
	void setNumberOfCourses(uint32_t numberOfCourses);

	uint32_t getUid();
	void setUid(uint32_t uid);

	double getGPA();
	void setGPA(double gpa);

	std::vector<Course> getCourses();
	void setCourses(std::vector<Course> courses);

	friend std::ostream& operator<<(std::ostream &os, const Student &s);
};

#endif //COP3530_STUDENT_H