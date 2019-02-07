//
//	Created by Justin Krum 1/30/19
//

#include "Menu.h"

using namespace std;

int main() {

	Database d("default.csv", "coursesDefaults.csv");
	Menu menu(d);

	menu.displayMenu();

	return 0;
}