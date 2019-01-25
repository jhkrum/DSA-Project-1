//
//	Created by Justin Krum 1/24/19
//

#ifndef COP3530_STUDENT_H
#define COP3530_STUDENT_H

#include <iostream>
#include <cstdint>
#include <vector>
#include "Course.h"

class Student {

private:
	uint32_t totalCreditHours;
	uint32_t numberOfCourses;
	uint32_t uid;
	double gpa;
	std::vector<Course> courses;

public:

	Student();
	Student(uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uidPar, double gpaPar, std::vector<Course> coursesPar);

	//TODO addCourse & deleteCourse
	//need more clarification on what to do specifically
};

#endif //COP3530_STUDENT_H