#include "Check.h"

bool isNumberNumeric() {
	if (cin.get() == '\n')
		return true;
	else {
		cin.clear();
		cin.ignore(1024, '\n');
		return false;
	}
}

bool isWordCorrect(string& input) {
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

bool isFIOCorrect(string& input) {
	if (!(input[0] >= 'A' && input[0] <= 'Z')) {
		return false;
	}

	int i = 1;
	for (i = 1; i < input.size() && input[i]!=' '; ++i) {
		if (!(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')) {
			return false;
		}
	}

	if (i++ == input.size()) {
		return false;
	}

	if (!(input[i] >= 'A' && input[i] <= 'Z')) {
		return false;
	}

	for (; i < input.size() && input[i] != ' '; ++i) {
		if (!(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')) {
			return false;
		}
	}

	return true;
}