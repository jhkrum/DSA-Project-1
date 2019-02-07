//
//	Created by Justin Krum 1/27/19
//

#ifndef COP3530_Database_H
#define COP3530_Database_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include "../Student/Student.h"
#include "../Course/Course.h"

class Database {

private:

	std::string studentFile;
	std::string courseFile;
	std::vector<Student> studentList;
	std::vector<Course> courseList;

	std::vector<Student> loadStudents();
	std::vector<Course> loadCourses(std::vector<Student> students);

public:

	Database();
	Database(std::string studentFilePar, std::string courseFilePar);

	void loadFiles();

	std::string getStudentFile();
	void setStudentFile(std::string studentFile);

	std::string getCourseFile();
	void setCourseFile(std::string courseFile);

	std::vector<Student> getStudentList();
	void setStudentList(std::vector<Student> studentList);

	std::vector<Course> getCourseList();
	void setCourseList(std::vector<Course> courseList);
};

#endif
