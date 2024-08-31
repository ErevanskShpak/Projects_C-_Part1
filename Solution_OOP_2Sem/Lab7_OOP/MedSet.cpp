#include "MedSet.h"

bool MedSet::isEmpty() const {
	if (medSet.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedSet::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medSet.insert(cur);
}

void MedSet::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medSet.size()) - 1;
	auto it = medSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medSet.erase(it);
	cout << "Delete completed\n";
}

void MedSet::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medSet.size()) - 1;
	auto it = medSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medSet.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedSet::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	auto it = medSet.begin();
	for (; it != medSet.end();++it) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << (*it).getMajor() << "|" << setw(10) << (*it).getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medSet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medSet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedSet::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medSet) {
		if (el.getName() == name) {
			el.show();
			isBe = 1;
			break;
		}
	}

	if (!isBe) {
		cout << "There is no such object\n";
	}

	cout << "Search completed\n";
}
