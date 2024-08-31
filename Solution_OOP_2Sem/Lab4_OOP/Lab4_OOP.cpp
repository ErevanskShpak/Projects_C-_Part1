#include <iostream>
#include "University.h"

using namespace std;

int main() {
	University university;
	bool main_menu = true;
	int choice;
	while (main_menu) {
		cout << "Main Menu:\n";
		cout << "1. Show\n";
		cout << "2. Add new\n";
		cout << "3. Edit\n";
		cout << "4. Delete\n";
		cout << "5. Find\n";
		cout << "6. Sort\n";
		cout << "0. Exit\n";
		cout << "Input: ";

		choice = inputNumber(0, 9);
		system("cls");
		switch (choice) {
		case 1: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Show all exams\n";
				cout << "2. Show all teachers\n";
				cout << "3. Show all student\n";
				cout << "4. Show individual student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 4);
				system("cls");
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
				cout << "Menu:\n";
				cout << "1. Add new exam\n";
				cout << "2. Add new teacher\n";
				cout << "3. Add new student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				system("cls");
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
		case 3: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Edit exam\n";
				cout << "2. Edit teacher\n";
				cout << "3. Edit student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				system("cls");
				switch (choice) {
				case 1:
					university.editExam();
					break;
				case 2:
					university.editTeacher();
					break;
				case 3:
					university.editStudent();
					break;
				case 0:
					menu = 0;
					break;
				}
			}
			break;
		}
		case 4: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Delete exam\n";
				cout << "2. Delete teacher\n";
				cout << "3. Delete student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				system("cls");
				switch (choice) {
				case 1:
					university.deleteExam();
					break;
				case 2:
					university.deleteTeacher();
					break;
				case 3:
					university.deleteStudent();
					break;
				case 0:
					menu = 0;
					break;
				}
			}
			break;
		}
		case 5: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Find exam\n";
				cout << "2. Find teacher\n";
				cout << "3. Find student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				system("cls");
				switch (choice) {
				case 1:
					university.findExam();
					break;
				case 2:
					university.findTeacher();
					break;
				case 3:
					university.findStudent();
					break;
				case 0:
					menu = 0;
					break;
				}
			}
			break;
		}
		case 6: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Sort exam\n";
				cout << "2. Sort teacher\n";
				cout << "3. Sort student\n";
				cout << "0. Back\n";
				cout << "Input: ";

				choice = inputNumber(0, 3);
				system("cls");
				switch (choice) {
				case 1:
					university.sortExam();
					break;
				case 2:
					university.sortTeacher();
					break;
				case 3:
					university.sortStudent();
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