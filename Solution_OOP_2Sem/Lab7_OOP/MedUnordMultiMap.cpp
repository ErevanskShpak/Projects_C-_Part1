#include "MedUnordMultiMap.h"

bool MedUnordMultiMap::isEmpty() const {
	if (medUnordMultiMap.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedUnordMultiMap::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medUnordMultiMap.insert(make_pair(cur.getName(), cur));
}

void MedUnordMultiMap::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medUnordMultiMap.size()) - 1;
	auto it = medUnordMultiMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMultiMap.erase(it);
	cout << "Delete completed\n";
}

void MedUnordMultiMap::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medUnordMultiMap.size()) - 1;
	auto it = medUnordMultiMap.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMultiMap.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedUnordMultiMap::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	auto it = medUnordMultiMap.begin();
	for (; it != medUnordMultiMap.end(); ++it) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << it->second.getMajor() << "|" << setw(10) << it->second.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medUnordMultiMap.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medUnordMultiMap) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.second.getMajor() << "|" << setw(10) << el.second.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedUnordMultiMap::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medUnordMultiMap) {
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
