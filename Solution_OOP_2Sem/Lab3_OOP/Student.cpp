#include "Student.h"

bool Student::isGroupCorrect(string& input) const {
	if (input.size() != 6) {
		return false;
	}

	for (char& symbol : input) {
		if (!(symbol >= '0' && symbol <= '9')) {
			return false;
		}
	}

	return true;
}

short Student::inputNumberMarks() const {
	cout << "Input number of marks: ";
	short number;
	while (true) {
		try {
			cin >> number;
			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (!(number > 0 && number <= 3)) {
				throw out_of_range("out_of_range");
			}
			break;
		}
		catch (out_of_range&) {
			cout << "Incorrect input, value is out of range\n";
			cout << "Input: ";
		}
		catch (...) {
			cout << "Incorrect input, input is no numeric\n";
			cout << "Input: ";
		}
	}
	
	return number;
}

void Student::setGroup() {
	cout << "Input group: ";
	while (true) {
		try {
			getline(cin, group, '\n');
			if (!isGroupCorrect(group)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, group must consist only digits and be 6 digits\n";
			cout << "Input: ";
		}
	}
}

istream& operator>>(istream& is, Student*& op) {
	op->setName();
	op->setSurname();
	op->setGroup();
	op->setMarks();

	return is;
}

ostream& operator<<(ostream& os, Student& op) {
	cout << "Name: " << op.getName() << "\nSurname: " << op.getSurname() << "\nGroup: " << op.getGroup() << endl;
	cout << "Marks\n";
	for (auto& mark : op.getMarks()) {
		cout << "Subject: " << mark->getSubject() << " Mark: " << mark->getValue() << endl;
	}
	return os;
}
