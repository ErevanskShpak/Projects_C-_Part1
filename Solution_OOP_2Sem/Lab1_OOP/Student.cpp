#include "Student.h"

bool Student::Grade::isSubjectCorrect() const {
	size_t size = subject.size();
	for (int i = 0; i < size; ++i) {
		if (!(subject[i] >= 'a' && subject[i] <= 'z' || subject[i] >= 'A' && subject[i] <= 'Z')) {
			return false;
		}
	}

	return true;
}

void Student::Grade::setSubject() {
	cout << "Input subject: ";
	getline(cin, subject, '\n');
	while (!isSubjectCorrect()) {
		cout << "Invalid input, please try again. The name must be without spaces, consist only of letters\n";
		getline(cin, subject, '\n');
	}
}

void Student::Grade::setMark() {
	cout << "Input mark: ";
	cin >> mark;
	while (!isNumberNumeric() || !(mark >= 0 && mark <= 10)) {
		cout << "Invalid input, please try again. The mark must consist only of digits and be greater than zero and be less than ten\n";
		cin >> mark;
	}
}

bool Student::isSchoolCorrect() {
	if (!(school[0] >= 'A' && school[0] <= 'Z')) {
		return false;
	}

	size_t size = school.size(), i = 1;
	for (; i < size && school[i]!=' '; ++i) {
		if (!(school[i] >= 'a' && school[i] <= 'z')) {
			return false;
		}
	}
	
	if (i++ > size - 2) {
		return false;
	}

	for (; i < size; ++i) {
		if (!(school[i] >= '0' && school[i] <= '9')) {
			return false;
		}
	}

	return true;
}

void Student::setSchool() {
	cout << "Input school: ";
	getline(cin, school, '\n');
	while (!isSchoolCorrect()) {
		cout << "Invalid input, please try again. The school must consist of a word and a number separated by a space\n";
		getline(cin, school, '\n');
	}
}

void Student::setGrades() {
	grades.clear();
	Grade cur;
	bool lever = true;
	while (lever) {
		cout << "Input grade\n";
		cur.setSubject();
		cur.setMark();
		grades.push_back(cur);

		cout << "Do you want to continue add\n1. Yes\n0. No\nInput: ";
		cin >> lever;
		while (!isNumberNumeric()) {
			cout << "Invalid input, please try again. You can input only 1 or 0\n";
			cin >> lever;
		}
	}
}

void Student::showAchievement() const {
	cout << "I study at " << school << endl;
	for (Grade el : grades) {
		cout << el.getSubject() << ": " << el.getMark() << endl;
	}
}