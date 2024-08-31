#include "Person.h"

bool Person::isFIOCorrect(string& input) const {
	if (!(input[0] >= 'A' && input[0] <= 'Z')) {
		return false;
	}

	for (int i = 1; i < input.size(); ++i) {
		if (!(input[i] >= 'a' && input[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

void Person::setName() {
	cout << "Input name: ";
	while (true) {
		try {
			getline(cin, name, '\n');
			if (!isFIOCorrect(name)) {
				throw 1;
			}
			break;
		}
		catch(...) {
			cout << "Incorrect input, name must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}
}

void Person::setSurname() {
	cout << "Input surname: ";
	while (true) {
		try {
			getline(cin, surname, '\n');
			if (!isFIOCorrect(surname)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, surname must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}
}