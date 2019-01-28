//
//	Created by Justin Krum 1/27/19
//

#ifndef COP3530_RECORDS_H
#define COP3530_RECORDS_H

#include <iostream>
#include <cstdint>
#include <vector>
#include "Student.h"

class Records{

private:
	
	uint32_t numberOfStudents;
	double averageGPA;
	std::vector<Student> students;

public:
	
	Records();
	Records(std::vector<Student> studentsPar);

	uint32_t getNumberOfStudents();
	void setNumberOfStudents(uint32_t numberOfStudents);

	double getAverageGPA();
	void setAverageGPA(double averageGPA);

	friend std::ostream& operator<<(std::ostream &os, const Records &r);
};

#endif //COP3530_RECORDS_H