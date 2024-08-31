#include "History.h"

const vector<string> History::all_formats{"PNG", "JPG", "PSD", "BMP", "EPS", "GIF", "TIF", "PICT", "JPEG"};

bool History::isEditorCorrect(string editor) {
	if (!(editor[0] >= 'A' && editor[0] <= 'Z')) {
		return false;
	}

	size_t size = editor.size();
	for (int i = 1; i < size; ++i) {
		if (!(editor[i] >= 'a' && editor[i] <= 'z')) {
			return false;
		}
	}

	return true;
}

bool History::isFormatCorrect(string format) {
	for (string el : all_formats) {
		if (format == el) {
			return true;
		}
	}

	return false;
}

History::History() {
	history.resize(5);
	history[0] = ElementHistory("Dmitry", "ghoul", "PSD", "PNG", true);
	history[1] = ElementHistory("Dmitry", "mage", "JPG", "PNG", false);
	history[2] = ElementHistory("Bebra", "pirate", "TIF", "PSD", false);
	history[3] = ElementHistory("Bebra", "sheep", "PSD", "BMP", true);
	history[4] = ElementHistory("Andrey", "mage", "PSD", "BMP", true);
}

void History::push_back(ElementHistory obj) {
	history.push_back(obj);
}

void History::showAll() const {
	cout <<setw(10)<< left<<"Name" << setw(10) << left <<"Editor" << setw(15) << left << "From format" << setw(15) << left << "To format" << setw(10) << left << "Success" << endl;
	for (auto& el : history) {
		cout <<setw(10) << el.getName() << setw(10) << el.getEditor() << setw(15) << el.getFormatStart() << setw(15) << el.getFormatEnd() << setw(10) << (el.getSuccess()?"yes":"no") << endl;
	}
	cout << endl;
}

void History::showEditor() {
	cout << "Input editor: ";
	string editor;
	getline(cin, editor, '\n');
	while (!isEditorCorrect(editor)) {
		cout << "Invalid input, please try again. The editor must be without spaces, consist only of letters and begin with a capital letter\n";
		getline(cin, editor, '\n');
	}

	cout << setw(10) << left << "\nName" << setw(10) << left << "Editor" << setw(15) << left << "From format" << setw(15) << left << "To format" << setw(10) << left << "Success" << endl;
	for (auto& el : history) {
		if (el.getEditor() == editor) {
			cout << setw(10) << el.getName() << setw(10) << el.getEditor() << setw(15) << el.getFormatStart() << setw(15) << el.getFormatEnd() << setw(10) << (el.getSuccess() ? "yes" : "no") << endl;
		}
	}
	cout << endl;
}

void History::showFormatStart() {
	cout << "Input format: ";
	string format;
	getline(cin, format, '\n');
	while (!isFormatCorrect(format)) {
		cout << "Invalid input, please try again. The format must consist only of capital letters and exist\n";
		getline(cin, format, '\n');
	}

	cout << setw(10) << left << "\nName" << setw(10) << left << "format" << setw(15) << left << "From format" << setw(15) << left << "To format" << setw(10) << left << "Success" << endl;
	for (auto& el : history) {
		if (el.getFormatStart() == format) {
			cout << setw(10) << el.getName() << setw(10) << el.getEditor() << setw(15) << el.getFormatStart() << setw(15) << el.getFormatEnd() << setw(10) << (el.getSuccess() ? "yes" : "no") << endl;
		}
	}
	cout << endl;
}

void History::showFormatEnd() {
	cout << "Input format: ";
	string format;
	getline(cin, format, '\n');
	while (!isFormatCorrect(format)) {
		cout << "Invalid input, please try again. The format must consist only of capital letters and exist\n";
		getline(cin, format, '\n');
	}

	cout << setw(10) << left << "\nName" << setw(10) << left << "format" << setw(15) << left << "From format" << setw(15) << left << "To format" << setw(10) << left << "Success" << endl;
	for (auto& el : history) {
		if (el.getFormatEnd() == format) {
			cout << setw(10) << el.getName() << setw(10) << el.getEditor() << setw(15) << el.getFormatStart() << setw(15) << el.getFormatEnd() << setw(10) << (el.getSuccess() ? "yes" : "no") << endl;
		}
	}
	cout << endl;
}
