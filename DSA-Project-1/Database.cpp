//
//	Created by Justin Krum 1/27/19
//

#include "Database.h"

using namespace std;

vector<Student> Database::loadStudents() {
	ifstream fin(studentFile);

	vector<Student> students;
	string line;

	while (getline(fin, line)) {
		
	}
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

char Database::getSplitChar() {
	return splitChar;
}

void Database::setSplitChar(char splitChar) {
	Database::splitChar = splitChar;
}

Database::Database(string studentFilePar, string courseFilePar, char splitCharPar) {
	studentFile = studentFilePar;
	courseFile = courseFilePar;
	splitChar = splitCharPar;
}

Database::Database() {

}