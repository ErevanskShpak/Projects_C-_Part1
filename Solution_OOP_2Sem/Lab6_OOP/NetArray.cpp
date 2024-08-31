#include "NetArray.h"

void NetArray::edit() {
	showAll();

	short index = Input::inputNumber("index of object to edit", 1, arrNet.size() - 1) - 1;
	arrNet[index]->setName(Input::inputWord("name"));
	arrNet[index]->setType(Input::inputType());
	cout << "Edit completed\n";
}

void NetArray::showAll() const {
	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	cout << "------------------------------" << endl;
	short i = 0;
	for (auto& el : arrNet) {
		cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		cout << "------------------------------" << endl;
	}

	ofstream fout("arrNet.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Type" << "|" << setw(10) << "Name" << "|" << endl;
	fout << "------------------------------" << endl;
	i = 0;
	for (auto& el : arrNet) {
		fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getType() << "|" << setw(10) << el->getName() << "|" << endl;
		fout << "------------------------------" << endl;
	}
}

void NetArray::find() const {
	string name = Input::inputWord("name");

	bool isBe = 0;
	for (auto& el : arrNet) {
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

void NetArray::sortAll() {
	sort(arrNet.begin(), arrNet.end(), [](shared_ptr<ComputerNet> a, shared_ptr<ComputerNet> b) {
		return a->getType() > b->getType();
		});
	cout << "Sort completed\n";
	showAll();
}
