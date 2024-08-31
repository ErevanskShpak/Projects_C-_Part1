#include "Person.h"

bool Person::isNameCorrect() const {
	if (!(name[0] >= 'A' && name[0] <= 'Z')) {
		return false;
	}

	size_t size = name.size();
	for (int i = 1; i < size; ++i) {
		if (!(name[i] >= 'a' && name[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

bool Person::isSurnameCorrect() const {
	if (!(surname[0] >= 'A' && surname[0] <= 'Z')) {
		return false;
	}

	size_t size = surname.size();
	for (int i = 1; i < size; ++i) {
		if (!(surname[i] >= 'a' && surname[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

void Person::setName() {
	 cout << "Input name: ";
	 getline(cin, name, '\n');
	 while (!isNameCorrect()) {
		 cout << "Invalid input, please try again. The name must be without spaces, consist only of letters and begin with a capital letter\n";
		 getline(cin, name, '\n');
	 }
}

void Person::setSurname() {
	cout << "Input surname: ";
	getline(cin, surname, '\n');
	while (!isSurnameCorrect()) {
		cout<< "Invalid input, please try again. The surname must be without spaces, consist only of letters and begin with a capital letter\n";
		getline(cin, surname, '\n');
	}
}