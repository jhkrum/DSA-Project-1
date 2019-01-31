//
//	Created by Justin Krum 1/30/19
//

#include "Menu.h"

using namespace std;

void Menu::displayMenu() {
	while (true) {
		int choice = 0;

		cout << "\n\n\n\n\t\tWelcome to FlPoly Simple Student Record System" << endl;
		cout << "\t\t----------------------------------------------" << endl;
		cout << "Please select one of the following:" << endl;
		cout << "[1] Print all records" << endl;
		cout << "[2] Print the record for a single student" << endl;
		cout << "[3] Add a student" << endl;
		cout << "[4] Delete a student" << endl;
		cout << "[5] Add a course to a student" << endl;
		cout << "[6] Delete a course from a student" << endl;
		cout << "\nEnter your selection: ";
		
		cin >> choice;

		switch (choice) {
		case 1:
			printAllRecords();
			break;
		case 2:
			studentRecord();
			break;
		case 3:
			cout << "Case 3" << endl;
			addStudent();
			break;
		case 4:
			cout << "Case 4" << endl;
			deleteStudent();
			break;
		case 5:
			cout << "Case 5" << endl;
			addCourseToStudent();
			break;
		case 6:
			cout << "Case 6" << endl;
			deleteCourseFromStudent();
			break;
		default:
			cout << "Default Case" << endl;
			break;
		}
	}
}

void Menu::printAllRecords() {
	cout << "\n\n" << endl;
	for (Student s : loadedFiles.getStudentList()) {
		cout << s << endl;
	}

}

void Menu::studentRecord() {
	int tempUid;
	cout << "\n\nPlease enter the Unique ID of the Student you are looking for: ";
	cin >> tempUid;

	for (Student s : loadedFiles.getStudentList()) {
		if (tempUid == s.getUid()) {
			cout << "\n\n" <<  s;
		}
	}
}

void Menu::addStudent() {

	Student s;
	int tempInput = 0;
	string tempString;
	double tempDouble;

	//Ensures that 2 students cannot have the same Uid
	while (tempInput == 0) {
		cout << "\nPlease enter a new Unique ID: ";
		cin >> tempInput;
		for (Student s : loadedFiles.getStudentList()) {
			if (tempInput == s.getUid()) {
				tempInput = 0;
				cout << "Please enter another ID, the entered one is currently in use." << endl;
			}
		}
	}
	s.setUid(tempInput);

	cout << "Please enter the Student's name: ";
	cin >> tempString;
	s.setName(tempString);



}

void Menu::deleteStudent() {

}

void Menu::addCourseToStudent() {

}

void Menu::deleteCourseFromStudent() {

}

void Menu::clearScreen() {
	for (int i = 0; i < 200; i++) cout << endl;
}

Menu::Menu(Database loadedFilesPar) {
	loadedFiles = loadedFilesPar;
}

Menu::Menu() {

}