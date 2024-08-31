#include "MedUnordMultiSet.h"

bool MedUnordMultiSet::isEmpty() const {
	if (medUnordMultiSet.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedUnordMultiSet::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medUnordMultiSet.insert(cur);
}

void MedUnordMultiSet::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medUnordMultiSet.size()) - 1;
	auto it = medUnordMultiSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMultiSet.erase(it);
	cout << "Delete completed\n";
}

void MedUnordMultiSet::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medUnordMultiSet.size()) - 1;
	auto it = medUnordMultiSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordMultiSet.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedUnordMultiSet::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : medUnordMultiSet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medUnordMultiSet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medUnordMultiSet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedUnordMultiSet::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medUnordMultiSet) {
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

void MedUnordMultiSet::sortAll() {
	if (isEmpty()) {
		return;
	}

	/*sort(medUnordMultiSet.begin(), medUnordMultiSet.end(), [](MedWorker a, MedWorker b) {
		return a.getMajor() > b.getMajor();
		});*/
	cout << "Sort completed\n";
	showAll();
}
