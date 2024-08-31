#include "Exam.h"

bool Exam::isSubjectCorrect(string& input) const {
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

bool Exam::isDateCorrect(string& input) const {
	if (input.size() != 5) {
		return false;
	}

	if (input[2] != '.') {
		return false;
	}

	int month = (input[3] - '0') * 10 + (input[4] - '0');
	if (!(month > 0 && month <= 12)) {
		return false;
	}
	int day = (input[0] - '0') * 10 + (input[1] - '0');
	switch (month) {
	case 2:
		if (!(day > 0 && day <= 28)) {
			return false;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (!(day > 0 && day <= 30)) {
			return false;
		}
		break;
	default:
		if (!(day > 0 && day <= 31)) {
			return false;
		}

	}

	return true;
}

void Exam::setSubject() {
	cout << "Input subject: ";
	while (true) {
		try {
			getline(cin, subject, '\n');
			if (!isSubjectCorrect(subject)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, subject must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}
}

void Exam::setDate() {
	cout << "Input date: ";
	while (true) {
		try {
			getline(cin, date, '\n');
			if (!isDateCorrect(date)) {
				throw exception();
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, date must be like this 12.06\n";
			cout << "Input: ";
		}
	}
}

istream& operator>>(istream& is, Exam*& op) {
	op->setSubject();
	op->setDate();

	return is;
}
