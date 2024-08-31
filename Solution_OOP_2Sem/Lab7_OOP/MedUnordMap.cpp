#include "MedUnordMap.h"

bool MedUnordMap::isEmpty() const {
	if (medUnordMap.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedUnordMap::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medUnordMap.insert(make_pair(cur.getName(), cur));
}

void MedUnordMap::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medUnordMap.size()) - 1;
	auto it = medUnordMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMap.erase(it);
	cout << "Delete completed\n";
}

void MedUnordMap::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medUnordMap.size()) - 1;
	auto it = medUnordMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMap.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedUnordMap::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	auto it = medUnordMap.begin();
	for (; it != medUnordMap.end(); ++it) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << it->second.getMajor() << "|" << setw(10) << it->second.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medUnordMap.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medUnordMap) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.second.getMajor() << "|" << setw(10) << el.second.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedUnordMap::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medUnordMap) {
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
