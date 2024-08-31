#include "MedMap.h"

bool MedMap::isEmpty() const {
	if (medMap.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedMap::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medMap.insert(make_pair(cur.getName(), cur));
}

void MedMap::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medMap.size()) - 1;
	auto it = medMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMap.erase(it);
	cout << "Delete completed\n";
}

void MedMap::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medMap.size()) - 1;
	auto it = medMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medMap.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedMap::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	auto it = medMap.begin();
	for (; it != medMap.end(); ++it) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << it->second.getMajor() << "|" << setw(10) << it->second.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medMap.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medMap) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.second.getMajor() << "|" << setw(10) << el.second.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedMap::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medMap) {
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
