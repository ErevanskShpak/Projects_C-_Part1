#include "MedUnordSet.h"

bool MedUnordSet::isEmpty() const {
	if (medUnordSet.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void MedUnordSet::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");
	cur.setName(name);
	cur.setMajor(type);

	medUnordSet.insert(cur);
}

void MedUnordSet::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, medUnordSet.size()) - 1;
	auto it = medUnordSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordSet.erase(it);
	cout << "Delete completed\n";
}

void MedUnordSet::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, medUnordSet.size()) - 1;
	auto it = medUnordSet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	medUnordSet.erase(it);
	add();
	cout << "Edit completed\n";
}

void MedUnordSet::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : medUnordSet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("medUnordSet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : medUnordSet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el.getMajor() << "|" << setw(10) << el.getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void MedUnordSet::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : medUnordSet) {
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

void MedUnordSet::sortAll() {
	if (isEmpty()) {
		return;
	}

	/*sort(medUnordSet.begin(), medUnordSet.end(), [](MedWorker a, MedWorker b) {
		return a.getMajor() > b.getMajor();
		});*/
	cout << "Sort completed\n";
	showAll();
}
