//
//	Created by Justin Krum 1/30/19
//

#include "Course.h"

using namespace std;

int main() {
	Course c("COP3530", "Data Structures & Algortihms", 3.5, 4);

	cout << c << "\n\n";

	c.setAll("Test", "Test2", 1, 2);

	cout << c << endl;

	return 0;
}