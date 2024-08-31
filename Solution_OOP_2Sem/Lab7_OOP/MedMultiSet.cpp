#include "MedMultiSet.h"

bool MedMultiSet::isEmpty() const {
	if (medMultiSet.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedMultiSet::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medMultiSet.insert(cur);
}

void MedMultiSet::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medMultiSet.size()) - 1;
	auto it = medMultiSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMultiSet.erase(it);
	cout << "Delete completed\n";
}

void MedMultiSet::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medMultiSet.size()) - 1;
	auto it = medMultiSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMultiSet.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedMultiSet::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : medMultiSet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medMultiSet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medMultiSet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedMultiSet::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medMultiSet) {
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
