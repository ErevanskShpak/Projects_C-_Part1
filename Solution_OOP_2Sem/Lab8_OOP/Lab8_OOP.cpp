#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

int main() {
	Stack stack;
	Queue queue;
	PriorityQueue priority_queue;

	string menuLine = "Menu:\n1. Add\n2. Delete\n3. Show all\n0. Back\n";

	bool main_menu = true;
	short choice;
	while (main_menu) {
		cout << "Main Menu:\n";
		cout << "1. Work with Stack\n";
		cout << "2. Work with Queue\n";
		cout << "3. Work with PriorityQueue\n";
		cout << "0. Exit\n";

		choice = Input::inputNumber("", 0, 3);
		system("cls");
		switch (choice) {
		case 1: {
			bool menu = true;
			while (menu) {
				cout << menuLine;

				choice = Input::inputNumber("", 0, 3);
				system("cls");
				switch (choice) {
				case 1:
					stack.add();
					break;
				case 2:
					stack.del();
					break;
				case 3: 
					stack.showAll();
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
				cout << menuLine;

				choice = Input::inputNumber("", 0, 3);
				system("cls");
				switch (choice) {
				case 1:
					queue.add();
					break;
				case 2:
					queue.del();
					break;
				case 3:
					queue.showAll();
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
				cout << menuLine;

				choice = Input::inputNumber("", 0, 3);
				system("cls");
				switch (choice) {
				case 1:
					priority_queue.add();
					break;
				case 2:
					priority_queue.del();
					break;
				case 3:
					priority_queue.showAll();
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