#include "Mark.h"

bool Mark::isSubjectCorrect(string& input) const {
    if (!(input[0] >= 'A' && input[0] <= 'Z')) {
		return false;
	}

	for (int i = 1; i < input.size(); ++i) {
		if (!(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')) {
			return false;
		}
	}

	return true;
}

void Mark::setSubject() {
	cout << "Input subject: ";
	while (true) {
		try {
			getline(cin, subject, '\n');
			if (!isSubjectCorrect(subject)) {
				throw "incorrect input";
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, subject must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}
}

void Mark::setValue() {
	cout << "Input value: ";
	while (true) {
		try {
			cin >> value;

			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (!(value >= 1 && value <= 10)) {
				throw out_of_range("out of range");
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
}
