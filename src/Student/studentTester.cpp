//
//	Created by Justin Krum 1/24/19
//

#include "Student.h"

using namespace std;

int main() {
	Course c("COP3530", "Data Structures & Algortihms", 3.5, 4);
	vector<Course> temp;
	temp.push_back(c);

	Student s("Justin", 20, 4, 1, 1111, temp);

	cout << s << "\n\n";

	s.deleteCourse("COP3530");

	cout << s << endl;

	return 0;
}