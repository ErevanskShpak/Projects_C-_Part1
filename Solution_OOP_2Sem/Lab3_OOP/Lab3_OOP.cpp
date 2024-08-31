#include <iostream>
#include "University.h"

using namespace std;

int main() {
	University university;
	bool main_menu = true;
	int choice;
	while (main_menu) {
		cout << "\nMain Menu:\n";
		cout << "1. Show\n";
		cout << "2. Add new\n";
		cout << "3. Throw exception in constrcutor\n";
		cout << "4. Throw exception with operator new\n";
		cout << "5. Throw my own exception\n";
		cout << "0. Exit\n";
		cout << "Input: ";

		choice = inputNumber(0, 9);
		switch (choice) {
		case 1: {
			bool menu = true;
			while (menu) {
				cout << "\nMenu:\n";
				cout << "1. Show all exams\n";
				cout << "2. Show all teachers\n";
				cout << "3. Show all student\n";
				cout << "4. Show individual student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 4);
				switch (choice) {
				case 1:
					university.showAllExam();
					break;
				case 2:
					university.showAllTeacher();
					break;
				case 3:
					university.showAllStudent();
					break;
				case 4:
					university.showStudent();
					break;
				case 0:
					menu = 0;
					break;
				}
			}
			break;
		}
		case 2: {
			bool menu = true;
			while (menu) {
				cout << "\nMenu:\n";
				cout << "1. Add new exam\n";
				cout << "2. Add new teacher\n";
				cout << "3. Add new student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				switch (choice) {
				case 1:
					university.pushExam();
					break;
				case 2:
					university.pushTeacher();
					break;
				case 3:
					university.pushStudent();
					break;
				case 0:
					menu = 0;
					break;
				}
			}
			break;
		}
		case 0:
			main_menu = 0;
			break;
		}
	}

	return 0;
}