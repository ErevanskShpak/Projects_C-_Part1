#include "NetVec.h"

bool NetVec::isEmpty() const {
	if (vecNet.empty()) {
		cout << "Vector is empty\n";
		return true;
	}

	return false;
}

void NetVec::add() {
	shared_ptr<ComputerNet> cur(new ComputerNet);
	string name = Input::inputWord("name"), type = Input::inputType();
	cur->setName(name);
	cur->setType(type);

	vecNet.push_back(cur);
}

void NetVec::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to delete", 1, vecNet.size() - 1) - 1;
	vecNet.erase(vecNet.begin() + index);
	cout << "Delete completed\n";
}

void NetVec::edit() {
	if (isEmpty()) {
		return;
	}
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, vecNet.size() - 1) - 1;
	vecNet[index]->setName(Input::inputWord("name"));
	vecNet[index]->setType(Input::inputType());
	cout << "Edit completed\n";
}

void NetVec::showAll() const {
	if (isEmpty()) {
		return;
	}
	
	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : vecNet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("vecNet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : vecNet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void NetVec::find() const {
	if (isEmpty()) {
		return;
	}

	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : vecNet) {
		if (el->getName() == name) {
			el->show();
			isBe = 1;
			break;
		}
	}

	if (!isBe) {
		cout << "There is no such object\n";
	}

	cout<<"Search completed\n";
}

void NetVec::sortAll() {
	if (isEmpty()) {
		return;
	}

	sort(vecNet.begin(), vecNet.end(), [](shared_ptr<ComputerNet> a, shared_ptr<ComputerNet> b) {
		return a->getType() > b->getType();
		});
	cout << "Sort completed\n";
	showAll();
}
