//
//	Created by Justin Krum 1/27/19
//

#ifndef COP3530_Database_H
#define COP3530_Database_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Student.h"
#include "Course.h"

class Database {

private:

	std::string studentFile;
	std::string courseFile;
	char splitChar;

public:

	Database();
	Database(std::string studentFilePar, std::string courseFilePar, char splitCharPar);

	std::vector<Student> loadStudents();
	std::vector<Course> loadCourses();

	std::string getStudentFile();
	void setStudentFile(std::string studentFile);

	std::string getCourseFile();
	void setCourseFile(std::string courseFile);

	char getSplitChar();
	void setSplitChar(char splitChar);


};

#endif