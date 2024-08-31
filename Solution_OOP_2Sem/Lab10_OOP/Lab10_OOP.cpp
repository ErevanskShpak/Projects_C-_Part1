#include <iostream>
#include <windows.h>
#include "GraphEditor.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	GraphEditor graph;

	bool main_menu = true;
	short choice;
	while (main_menu) {
		cout << "Main Menu:\n";
		cout << "1. Add\n";
		cout << "2. Delete\n";
		cout << "3. Edit\n";
		cout << "4. Show all\n";
		cout << "0. Exit\n";

		choice = Input::inputNumber("", 0, 4);
		system("cls");
		switch (choice) {
		case 1:
			graph.add();
			break;
		case 2:
			graph.del();
			break;
		case 3:
			graph.edit();
			break;
		case 4:
			graph.showAll();
			break;
		case 0:
			main_menu = 0;
			break;
		}
	}

	return 0;
}