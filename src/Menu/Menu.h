//
// Created by Justin Krum on 1/30/19.
//

#ifndef COP3530_MENU_H
#define COP3530_MENU_H

#include <iostream>
#include <cstdint>
#include <string>
#include "../Course/Course.h"
#include "../Person/Person.h"
#include "../Student/Student.h"
#include "../Records/Records.h"
#include "../Database/Database.h"

class Menu {

private:
	Database loadedFiles;

public:

	Menu();
	Menu(Database loadedFilesPar);

	void displayMenu();
	void printAllRecords();
	void studentRecord();
	void addStudent();
	void deleteStudent();
	Student addCourseToStudent(Student s);
	void addCourseToStudent();
	void deleteCourseFromStudent();
	void clearScreen();
};


#endif //COP3530_MENU_H
