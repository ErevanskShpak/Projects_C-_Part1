#include "File.h"

const vector<string> File::all_formats{"PNG", "JPG", "PSD", "BMP", "EPS", "GIF", "TIF", "PICT", "JPEG"};

bool File::isNameCorrect() {
	size_t size = name.size();
	for (int i = 0; i < size; ++i) {
		if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] >= '0' && name[i] <= '9' || name[i] == '-' || name[i] == '_')) {
			return false;
		}
	}

	return true;
}

bool File::isDataCorrect() {
	if (!(data[0] >= 'A' && data[0] <= 'Z')) {
		return false;
	}

	size_t size = data.size();
	for (int i = 1; i < size; ++i) {
		if (!(data[i] >= 'a' && data[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

bool File::isFormatCorrect() {
	for (string el : all_formats) {
		if (format == el) {
			return true;
		}
	}

	return false;
}

void File::setName() {
	cout << "Input name of file: ";
	getline(cin, name, '\n');
	while (!isNameCorrect()) {
		cout << "Invalid input, please try again. The name must consist only of letters, digits, '-' and '_'\n";
		getline(cin, name, '\n');
	}
}

void File::setData() {
	cout << "Input data: ";
	getline(cin, data, '\n');
	while (!isDataCorrect()) {
		cout << "Invalid input, please try again. The data must be without spaces, consist only of letters and begin with a capital letter\n";
		getline(cin, data, '\n');
	}
}

void File::setFormat() {
	cout << "Input format: ";
	getline(cin, format, '\n');
	while (!isFormatCorrect()) {
		cout << "Invalid input, please try again. The format must consist only of capital letters and exist\n";
		getline(cin, format, '\n');
	}
}

void File::showFullName() const {
	string temp = format;
	for (char& it : temp) {
		it += 'a' - 'A';
	}

	cout << name << "." << temp << endl;
}
