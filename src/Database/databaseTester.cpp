//
//	Created by Justin Krum 1/27/19
//

#include "Database.h"

using namespace std;

int main() {
	Database d("default.csv", "coursesDefaults.csv");
	d.loadFiles();

	return 0;
}