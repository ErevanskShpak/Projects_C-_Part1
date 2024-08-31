#include <iostream>
#include "GraphRed.h"

int main() {
	GraphRed graph;
	History history;
	bool main_menu = true;
	int choice;
	
	while (main_menu) {
		cout << "Main menu of Graph Editor:\n";
		cout << "1. Interaction with files\n";
		cout << "2. Interaction with history\n";
		cout << "0. Exit\n";
		cout << "Input: ";
		cin >> choice;
		while (!isNumberNumeric() || !(choice >= 0 && choice <= 2)) {
			cout << "Invalid input, please try again. The number must consist of digits and be less or equal than 2\n";
			cin >> choice;
		}
		cout << endl;

		switch (choice) {
			case 1: {
				bool menu = true;
				while (menu) {
					cout << "Menu:\n";
					cout << "1. Show list of files\n";
					cout << "2. Show one file\n";
					cout << "3. Add new file\n";
					cout << "4. Delete file\n";
					cout << "5. Edit file\n";
					cout << "6. Convert file\n";
					cout << "0. Back\n";
					cout << "Input: ";
					cin >> choice;
					while (!isNumberNumeric() || !(choice >= 0 && choice <= 6)) {
						cout << "Invalid input, please try again. The number must consist of digits and be less or equal than 6\n";
						cin >> choice;
					}
					cout << endl;
					switch (choice) {
						case 1: {
							graph.showAll();
							break;
						}
						case 2: {
							graph.show();
							break;
						}
						case 3: {
							graph.push_back();
							break;
						}
						case 4: {
							graph.erase();
							break;
						}
						case 5: {
							graph.edit();
							break;
						}
						case 6: {
							graph.convert(history);
							break;
						}
						case 0: {
							menu = false;
							break;
						}
					}
					cout << endl;
				}
				break;
			}
			case 2: {
				bool menu = true;
				while (menu) {
					cout << "Menu:\n";
					cout << "1. Show all conversion\n";
					cout << "2. Show individual user conversion\n";
					cout << "3. Show from individual format conversion\n";
					cout << "4. Show to individual format conversion\n";
					cout << "0. Back\n";
					cout << "Input: ";
					cin >> choice;
					while (!isNumberNumeric() || !(choice >= 0 && choice <= 6)) {
						cout << "Invalid input, please try again. The number must consist of digits and be less or equal than 6\n";
						cin >> choice;
					}
					cout << endl;

					switch (choice) {
						case 1: {
							history.showAll();
							break;
						}
						case 2: {
							history.showEditor();
							break;
						}
						case 3: {
							history.showFormatStart();
							break;
						}
						case 4: {
							history.showFormatEnd();
							break;
						}
						case 0: {
							menu = false;
							break;
						}
					}
					cout << endl;
				}
				break;
			}
			case 0: {
				main_menu = false;
				break;
			}
		}
	}
	
	return 0;
}
