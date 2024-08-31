#include <iostream>
#include "MedSet.h"
#include "MedMultiSet.h"
#include "MedUnordSet.h"
#include "MedUnordMultiSet.h"
#include "MedMap.h"
#include "MedMultiMap.h"
#include "MedUnordMap.h"
#include "MedUnordMultiMap.h"

int main() {
	MedSet set;
	MedMultiSet multiset;
	MedUnordSet unordered_set;
	MedUnordMultiSet unordered_multiset;
	MedMap map;
	MedMultiMap multimap;
	MedUnordMap unordered_map;
	MedUnordMultiMap unordered_multimap;

	string menuLine = "Menu:\n1. Add\n2. Delete\n3. Edit\n4. Show all\n5. Find\n6. Sort\n0. Back\n";

	bool main_menu = true;
	short choice;
	while (main_menu) {
		cout << "Main Menu:\n";
		cout << "1. Work with Set\n";
		cout << "2. Work with Map\n";
		cout << "0. Exit\n";

		choice = Input::inputNumber("", 0, 2);
		system("cls");
		switch (choice) {
		case 1:
			cout << "Menu:\n";
			cout << "1. Work with Set\n";
			cout << "2. Work with MultiSet\n";
			cout << "3. Work with UnorderedSet\n";
			cout << "4. Work with UnorderedMultiSet\n";
			cout << "0. Exit\n";

			choice = Input::inputNumber("", 0, 4);
			system("cls");
			switch (choice) {
			case 1: {
				bool menu = true;
				while (menu) {
					cout << menuLine;

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						set.add();
						break;
					case 2:
						set.del();
						break;
					case 3:
						set.edit();
						break;
					case 4:
						set.showAll();
						break;
					case 5:
						set.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
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

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						multiset.add();
						break;
					case 2:
						multiset.del();
						break;
					case 3:
						multiset.edit();
						break;
					case 4:
						multiset.showAll();
						break;
					case 5:
						multiset.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
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

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						unordered_set.add();
						break;
					case 2:
						unordered_set.del();
						break;
					case 3:
						unordered_set.edit();
						break;
					case 4:
						unordered_set.showAll();
						break;
					case 5:
						unordered_set.find();
						break;
					case 6:
						unordered_set.sortAll();
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
					cout << menuLine;

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						unordered_multiset.add();
						break;
					case 2:
						unordered_multiset.del();
						break;
					case 3:
						unordered_multiset.edit();
						break;
					case 4:
						unordered_multiset.showAll();
						break;
					case 5:
						unordered_multiset.find();
						break;
					case 6:
						unordered_multiset.sortAll();
						break;
					case 0:
						menu = 0;
						break;
					}
				}
				break;
			}
			}
		case 2:
			cout << "Menu:\n";
			cout << "1. Work with Map\n";
			cout << "2. Work with MultiMap\n";
			cout << "3. Work with UnorderedMap\n";
			cout << "4. Work with UnorderedMultiMap\n";
			cout << "0. Exit\n";

			choice = Input::inputNumber("", 0, 4);
			system("cls");
			switch (choice) {
			case 1: {
				bool menu = true;
				while (menu) {
					cout << menuLine;

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						map.add();
						break;
					case 2:
						map.del();
						break;
					case 3:
						map.edit();
						break;
					case 4:
						map.showAll();
						break;
					case 5:
						map.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
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

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						multimap.add();
						break;
					case 2:
						multimap.del();
						break;
					case 3:
						multimap.edit();
						break;
					case 4:
						multimap.showAll();
						break;
					case 5:
						multimap.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
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

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						unordered_map.add();
						break;
					case 2:
						unordered_map.del();
						break;
					case 3:
						unordered_map.edit();
						break;
					case 4:
						unordered_map.showAll();
						break;
					case 5:
						unordered_map.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
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
					cout << menuLine;

					choice = Input::inputNumber("choice", 0, 6);
					system("cls");
					switch (choice) {
					case 1:
						unordered_multimap.add();
						break;
					case 2:
						unordered_multimap.del();
						break;
					case 3:
						unordered_multimap.edit();
						break;
					case 4:
						unordered_multimap.showAll();
						break;
					case 5:
						unordered_multimap.find();
						break;
					case 6:
						cout << "There is no sort in this container\n";
						break;
					case 0:
						menu = 0;
						break;
					}
				}
				break;
			}
				  break;
			case 0:
				main_menu = 0;
				break;
			}
		}
		return 0;
	}
}