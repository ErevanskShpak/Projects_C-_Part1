#include "MedMultiMap.h"

bool MedMultiMap::isEmpty() const {
	if (medMultiMap.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedMultiMap::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medMultiMap.insert(make_pair(cur.getName(), cur));
}

void MedMultiMap::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medMultiMap.size()) - 1;
	auto it = medMultiMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMultiMap.erase(it);
	cout << "Delete completed\n";
}

void MedMultiMap::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medMultiMap.size()) - 1;
	auto it = medMultiMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMultiMap.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedMultiMap::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	auto it = medMultiMap.begin();
	for (; it != medMultiMap.end(); ++it) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << it->second.getMajor() << "|" << setw(10) << it->second.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medMultiMap.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medMultiMap) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.second.getMajor() << "|" << setw(10) << el.second.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedMultiMap::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medMultiMap) {
		if (el.second.getName() == name) {
			el.second.show();
			isBe = 1;
			break;
		}
	}

	if (!isBe) {
		cout << "There is no such object\n";
	}

	cout << "Search completed\n";
}
