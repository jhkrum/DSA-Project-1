//
//	Created by Justin Krum 1/30/19
//

#include "Menu.h"

using namespace std;

void Menu::displayMenu() {
	//Runs in loop
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

		//Switches based on choice of input
		switch (choice) {
		case 1:
			printAllRecords();
			break;
		case 2:
			studentRecord();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			deleteStudent();
			break;
		case 5:
			addCourseToStudent();
			break;
		case 6:
			deleteCourseFromStudent();
			break;
		default:
			cout << "Invalid input. Please try again." << endl;
			break;
		}
	}
}

//Prints all the records for every student in the database
void Menu::printAllRecords() {
	cout << "\n\n" << endl;
	for (Student s : loadedFiles.getStudentList()) {
		cout << s << endl; //Outputs each student from the Student List
	}

}

//Prints the record for a single student in the database
void Menu::studentRecord() {
	char tempString[30];
	cin.ignore();
	cout << "\n\nPlease enter the name of the Student you are looking for: ";
	cin.getline(tempString, 30); //Input the name of the student

	for (Student s : loadedFiles.getStudentList()) {
		if (tempString == s.getName()) {
			cout << "\n\n" <<  s; //Outputs the Student where the names are the same
		}
	}
}

void Menu::addStudent() {

	Student s;
	int tempInput = 0;
	string tempString;

	//Ensures that 2 students cannot have the same Uid
	while (tempInput == 0) {
		cout << "\n\nPlease enter a new Unique ID: ";
		cin >> tempInput;

		//Validates that 2 students cannot have the same uid
		for (Student s : loadedFiles.getStudentList()) {
			if (tempInput == s.getUid()) {
				tempInput = 0;
				cout << "Please enter another ID, the entered one is currently in use." << endl;
			}
		}
	}
	s.setUid(tempInput);

	cout << "Please enter the Student's name: ";
	cin >> tempString;	//Enter the name of the student
	s.setName(tempString);

	cout << "Please enter the Student's age: ";
	cin >> tempInput;	//Enter the student's age
	s.setAge(tempInput);

	bool flag = false;

	cout << "Would you like to add Courses to this Student? [Yes = 1 // No = 0]" << endl;
	cin >> tempInput;
	if (tempInput == 1) {
		s = addCourseToStudent(s);	//Adds course to Student
	}
	else if(tempInput == 0){
		//Sets everything to 0 if no Courses to be added
		s.setTotalCreditHours(0);
		s.setGPA(0);
		s.setNumberOfCourses(0);
	}
	vector <Student> studentList = loadedFiles.getStudentList();
	studentList.push_back(s);	//Adds the new student to the list

	loadedFiles.setStudentList(studentList);	//Sets the new studentList into the Database
}

//Deletes a student 
void Menu::deleteStudent() {
	vector<Student> studentList = loadedFiles.getStudentList();
	char studentName[30];
	cout << "\n\nPlease enter the name of a student you wish to delete: ";
	cin.ignore();
	cin.getline(studentName, 30);	//Inputs the name of the student

	string sName = studentName;

	for (int i = 0; i < loadedFiles.getStudentList().size(); i++) {
		Student student = loadedFiles.getStudentList().at(i);
		if (sName == student.getName()) {
			studentList.erase(studentList.begin() + i);	//Erases the student if the name is the same as the inputted name
		}
	}

	loadedFiles.setStudentList(studentList);	//Sets the new studentList into the Database
}


//Adds a new course to a student
void Menu::addCourseToStudent() {

	vector<Student> studentList = loadedFiles.getStudentList();
	int index = 0;
	Student s;
	char studentName[30];

	cout << "Please enter the name of the Student you wish to add to: ";
	cin.ignore();
	cin.getline(studentName, 30);	//Inputs the name of student to add to

	string sName = studentName;

	for (int i = 0; i < loadedFiles.getStudentList().size(); i++) {
		Student student = loadedFiles.getStudentList().at(i);
		if (sName == student.getName()) {
			index = i;	//Grabs the index of the student in the vector of Students
			s = student;
		}
	}

	char tempString[50];
	double tempDouble;
	bool flag = false;
	vector<Course> courses = s.getCourses();

	do {
		int tempInput;
		Course c;

		cout << "Please enter the Courses's code: ";
		cin.ignore();
		cin.getline(tempString, 50);	//Sets the new Course code
		c.setCode(tempString);

		cout << "Please enter the Courses's title: ";
		cin.getline(tempString, 50);	//Sets the new Course title
		c.setTitle(tempString);

		cout << "Please enter the Courses's credit hour(s): ";
		cin >> tempInput;
		c.setCreditHour(tempInput);	//Sets the new Course credit hour amount

		cout << "Please enter " << s.getName() << "'s grade in " << c.getCode() << ": ";
		cin >> tempDouble;
		c.setGrade(tempDouble);	//Sets the new Course grade

		s.addCourse(c);	//Adds the course to the student

		cout << "Would you like to continue to add Courses to this Student? [Yes = 1 // No = 0]" << endl;
		cin >> tempInput;
		if (tempInput == 0) flag = true;	//Keeps the loop of adding courses, otherwise exits

	} while (!flag);

	studentList.at(index) = s;	//Sets the new student back into the vector

	loadedFiles.setStudentList(studentList);	//Resets the new Student List

}

//Adds course to a pre-established Student -- used for addStudent()
Student Menu::addCourseToStudent(Student s) {
	char tempString[30];
	double tempDouble;
	bool flag = false;
	vector<Course> courses = s.getCourses();

	do  {
		int tempInput;
		Course c;

		cout << "Please enter the Courses's code: ";
		cin.ignore();
		cin.getline(tempString, 30);//Sets the new Course code
		c.setCode(tempString);

		cout << "Please enter the Courses's title: ";//Sets the new Course title
		cin.getline(tempString, 30);
		c.setTitle(tempString);

		cout << "Please enter the Courses's credit hour(s): ";//Sets the new Course credit hour amount
		cin >> tempInput;
		c.setCreditHour(tempInput);

		cout << "Please enter " << s.getName() << "'s grade in " << c.getCode() << ": ";
		cin >> tempDouble;
		c.setGrade(tempDouble);//Sets the new Course grade

		s.addCourse(c);//Adds the course to the student

		cout << "Would you like to continue to add Courses to this Student? [Yes = 1 // No = 0]" << endl;
		cin >> tempInput;
		if (tempInput == 0) flag = true;	//Keeps the loop of adding courses, otherwise exits

	} while (!flag);

	return s;	//returns the student back to addStudent()
}

void Menu::deleteCourseFromStudent() {
	vector<Student> studentList = loadedFiles.getStudentList();
	char studentName[30], courseCode[20];
	int indexStudent;
	cout << "\n\nPlease enter the name of the Student you wish to delete from: ";
	cin.ignore();
	cin.getline(studentName, 30); //Inputs the name of the target student

	string sName = studentName;

	Student deleteFrom;

	for (int i = 0; i < loadedFiles.getStudentList().size(); i++) {
		Student student = loadedFiles.getStudentList().at(i);
		if (sName == student.getName()) {
			deleteFrom = student;
			indexStudent = i;	//Grabs the index of the student in the student vector
		}
	}

	vector<Course> courseList = deleteFrom.getCourses();

	cout << deleteFrom << endl;
	cout << "\n\nEnter the Course Code for the Course to delete: ";
	cin.getline(courseCode, 20);	//Grabs the course code to delete

	string cCode = courseCode;

	deleteFrom.deleteCourse(cCode);	//Deletes the course and all related attributes of Student

	studentList.at(indexStudent) = deleteFrom;

	loadedFiles.setStudentList(studentList);	//Syncs the updated student list
}

//Parametrized constructor
Menu::Menu(Database loadedFilesPar) {
	loadedFiles = loadedFilesPar;
}

//Default constructor
Menu::Menu() {

}