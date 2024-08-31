#include "NetList.h"

bool NetList::isEmpty() const {
	if (listNet.empty()) {
		cout << "List is empty\n";
		return true;
	}

	return false;
}

void NetList::add() {
	shared_ptr<ComputerNet> cur(new ComputerNet);
	string name = Input::inputWord("name"), type = Input::inputType();
	cur->setName(name);
	cur->setType(type);

	listNet.push_back(cur);
}

void NetList::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, listNet.size() - 1) - 1;
	auto it = listNet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	listNet.erase(it);
	cout << "Delete completed\n";
}

void NetList::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, listNet.size() - 1) - 1;
	auto it = listNet.begin();
	for (int i = 0; i < index; ++i) {
		it++;
	}
	(*it)->setName(Input::inputWord("name"));
	(*it)->setType(Input::inputType());
	cout << "Edit completed\n";
}

void NetList::showAll() const {
	if (isEmpty()) {
		return;
	}

	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : listNet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("listNet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : listNet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void NetList::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : listNet) {
		if (el->getName() == name) {
			el->show();
			isBe = 1;
			break;
		}
	}

	if (!isBe) {
		cout << "There is no such object\n";
	}

	cout << "Search completed\n";
}

void NetList::sortAll() {
	if (isEmpty()) {
		return;
	}

	listNet.sort([](shared_ptr<ComputerNet> a, shared_ptr<ComputerNet> b) {
		return a->getType() > b->getType();
		});
	cout << "Sort completed\n";
	showAll();
}
