#include"People.h"

int main() {
	People university;
	bool menu = true;
	int choice;
	while (menu) {
		cout << "Menu:\n";
		cout << "1. Show all persons\n";
		cout << "2. Show one person\n";
		cout << "3. Add new person\n";
		cout << "4. Delete one person\n";
		cout << "5. Sort persons\n";
		cout << "0. Exit\n";
		cout << "Input: ";
		cin >> choice;
		while (!isNumberNumeric() || !(choice >= 0 && choice <= 5)) {
			cout << "Invalid input, please try again. The number must consist of digits and be less than the size of the array\n";
			cin >> choice;
		}
		cout << endl;
		switch (choice) {
			case 1: {
				university.showAll();
				break;
			}
			case 2: {
				university.showPerson();
				break;
			}
			case 3: {
				university.push_back();
				break;
			}
			case 4: {
				university.erase();
				break;
			}
			case 5: {
				university.sortPersons();
				break;
			}
			case 0: {
				menu = false;
				break;
			}
		}
		cout << endl;
	}

	return 0;
}
