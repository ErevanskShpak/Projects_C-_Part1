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

bool Input::isNumberRangeCorrect(float number, float left_range, float right_range) {
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		return false;
}

float Input::inputNumber(string word, float left_range, float right_range = INT_MAX) {
	float number;
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

ShapeSpec* Input::inputShape(short i) {
	switch (i) {
	case 1: {
		return new CircleSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputNumber("radius", 0, 1000));
	}
	case 2: {
		return new RectangleSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputNumber("length", 0, 1000),
			Input::inputNumber("width", 0, 1000));
	}
	case 3: {
		return new StarSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputNumber("amount", 1, 20),
			Input::inputNumber("radius", 0, 1000));
	}
	}
}
