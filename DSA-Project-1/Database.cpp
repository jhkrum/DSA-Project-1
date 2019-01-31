//
//	Created by Justin Krum 1/27/19
//

#include "Database.h"

using namespace std;

vector<Student> Database::loadStudents() {

	ifstream fin(studentFile);
	vector<Student> students;
	string line;

	//while boolean statement grabs uid
	while (getline(fin, line, ',')) {
		//uid,"Name",age, Total Credit Hours, Number of Courses, gpa
		Student s;

		//Sets uid
		s.setUid(stoi(line));

		//Grabs and sets name
		getline(fin, line, ',');
		s.setName(line.substr(line.find_first_not_of(' ')).substr(1, line.length() - 3));

		//Grabs and sets age
		getline(fin, line, ',');
		s.setAge(stoi(line.substr(line.find_first_not_of(' '))));

		//Grabs and sets total credit hours
		getline(fin, line, ',');
		s.setTotalCreditHours(stoi(line.substr(line.find_first_not_of(' '))));

		//Grabs and sets number of courses
		getline(fin, line, ',');
		s.setNumberOfCourses(stoi(line.substr(line.find_first_not_of(' '))));

		//Grabs and sets gpa
		getline(fin, line);
		s.setGPA(stod(line.substr(line.find_first_not_of(' '))));

		students.push_back(s);
	}
	return students;
}

vector<Course> Database::loadCourses(vector<Student> students) {
	ifstream fin(courseFile);
	vector<Course> courses;
	string line;

	//while boolean statement grabs uid
	while (getline(fin, line, ',')) {
		//uid, "Course Code", "Course Title", Credit Hours, Grade
		Course c;

		//Sets uid
		int tempUid = stoi(line);

		//Grabs and sets name
		getline(fin, line, ',');
		c.setCode(line.substr(line.find_first_not_of(' ')).substr(1, line.length() - 3));

		//Grabs and sets age
		getline(fin, line, ',');
		c.setTitle(line.substr(line.find_first_not_of(' ')).substr(1, line.length() - 3));

		//Grabs and sets total credit hours
		getline(fin, line, ',');
		c.setCreditHour(stoi(line.substr(line.find_first_not_of(' '))));

		//Grabs and sets grade
		getline(fin, line);
		c.setGrade(stod(line.substr(line.find_first_not_of(' '))));

		courses.push_back(c);

		for (int i = 0; i < studentList.size(); i++) {
			if (tempUid == studentList.at(i).getUid()) {
				studentList.at(i).addCourse(c);
			}
		}
	}
	return courses;
}

void Database::loadFiles() {
	studentList = loadStudents();
	courseList = loadCourses(studentList);
}

string Database::getStudentFile() {
	return studentFile;
}

void Database::setStudentFile(string studentFile) {
	Database::studentFile = studentFile;
}

string Database::getCourseFile() {
	return courseFile;
}

void Database::setCourseFile(string courseFile) {
	Database::courseFile = courseFile;
}

vector<Student> Database::getStudentList() {
	return studentList;
}

void Database::setStudentList(vector<Student> studentList) {
	Database::studentList = studentList;
}

vector<Course> Database::getCourseList() {
	return courseList;
}

void Database::setCourseList(vector<Course> courseList) {
	Database::courseList = courseList;
}

Database::Database(string studentFilePar, string courseFilePar) {
	studentFile = studentFilePar;
	courseFile = courseFilePar;
	loadFiles();
}

Database::Database() {

}