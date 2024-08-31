#include <iostream>
#include "NetVec.h"
#include "NetList.h"
#include "NetArray.h"

int main() {
	NetVec vecNet;
	NetList listNet;
	NetArray arrNet;

	bool main_menu = true;
	short choice;
	while (main_menu) {
		cout << "Main Menu:\n";
		cout << "1. Work with Vector\n";
		cout << "2. Work with List\n";
		cout << "3. Work with Array\n";
		cout << "0. Exit\n";

		choice = Input::inputNumber("", 0, 3);
		system("cls");
		switch (choice) {
		case 1: {
			bool menu = true;
			while (menu) {
				cout << "Menu:\n";
				cout << "1. Add\n";
				cout << "2. Delete\n";
				cout << "3. Edit\n";
				cout << "4. Show all\n";
				cout << "5. Find\n";
				cout << "6. Sort\n";
				cout << "0. Back\n";

				choice = Input::inputNumber("choice", 0, 6);
				system("cls");
				switch (choice) {
				case 1:
					vecNet.add();
					break;
				case 2:
					vecNet.del();
					break;
				case 3:
					vecNet.edit();
					break;
				case 4:
					vecNet.showAll();
					break;
				case 5:
					vecNet.find();
					break;
				case 6:
					vecNet.sortAll();
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
				cout << "1. Add\n";
				cout << "2. Delete\n";
				cout << "3. Edit\n";
				cout << "4. Show all\n";
				cout << "5. Find\n";
				cout << "6. Sort\n";
				cout << "0. Back\n";

				choice = Input::inputNumber("choice", 0, 6);
				system("cls");
				switch (choice) {
				case 1:
					listNet.add();
					break;
				case 2:
					listNet.del();
					break;
				case 3:
					listNet.edit();
					break;
				case 4:
					listNet.showAll();
					break;
				case 5:
					listNet.find();
					break;
				case 6:
					listNet.sortAll();
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
				cout << "1. Edit\n";
				cout << "2. Show all\n";
				cout << "3. Find\n";
				cout << "4. Sort\n";
				cout << "0. Back\n";

				choice = Input::inputNumber("choice", 0, 4);
				system("cls");
				switch (choice) {
				case 1:
					arrNet.edit();
					break;
				case 2:
					arrNet.showAll();
					break;
				case 3:
					arrNet.find();
					break;
				case 4:
					arrNet.sortAll();
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