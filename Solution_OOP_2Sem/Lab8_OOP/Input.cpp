#include "Input.h"

bool Input::isNumberNumeric() {
	if (cin.get() == '\n') {
		return true;
	}
	else {
		cin.clear();
		cin.ignore(1024, '\n');
		return false;
	}
}

bool Input::isNumberRangeCorrect(short number, short left_range, short right_range) {
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		return false;
}

short Input::inputNumber(string word, short left_range, short right_range = INT_MAX) {
	short number;
	cin.unsetf(ios::skipws);
	while (true) {
		cout << "Input " << word << ": ";
		try {
			cin >> number;
			if (!isNumberNumeric()) {
				throw 1;
			}
			if (!isNumberRangeCorrect(number, left_range, right_range)) {
				throw "incorrect range";
			}
			break;
		}
		catch (int) {
			cerr << "Incorrect input. Try again\n";
		}
		catch (...) {
			cerr << "Incorrect range. Try again\n";
		}
	}

	return number;
}

bool Input::isWordCorrect(string& word) {
	if (!(word[0] >= 'A' && word[0] <= 'Z')) {
		return false;
	}

	for (int i = 1; i < word.size(); ++i) {
		if (!(word[i] >= 'a' && word[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

string Input::inputWord(string word) {
	string input;

	while (true) {
		cout << "Input " << word << ": ";
		try {
			getline(cin, input, '\n');
			if (!isWordCorrect(input)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, " << word << " must consist only letters and starts from upper letter\n";
		}
	}

	return input;
}

string Input::inputType() {
	cout << "Input type of net\n";
	cout << "0. Global\n";
	cout << "1. Local\n";

	short choice = inputNumber("type", 0, 1);

	switch (choice) {
	case 0:
		return "global";
	case 1:
		return "local";
	}
}
