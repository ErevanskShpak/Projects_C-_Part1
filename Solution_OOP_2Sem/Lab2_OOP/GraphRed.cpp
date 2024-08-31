#include "GraphRed.h"

bool GraphRed::isEmpty() const {
	if (!graph.size()) {
		cout << "There are no files\n";
		return 1;
	}
	return 0;
}

unsigned int GraphRed::inputNumber() {
	unsigned int i;
	cout << "Enter number of file\n";
	cin >> i;
	while (!isNumberNumeric() || !(i > 0 && i <= graph.size())) {
		cout << "Invalid input, please try again. The number must consist of digits and be less than the size of the array\n";
		cin >> i;
	}

	return i;
}

bool GraphRed::isAgreeChange(unsigned int i) {
	cout << "Do you want to agree with changes?\n1. Yes; 0. No\nInput: ";
	bool isChange;
	cin >> isChange;
	while (!isNumberNumeric()) {
		cout << "Invalid input, please try again. The number must be only 1 or 0\n";
		cin >> isChange;
	}
	if (isChange) {
		graph[i - 1].commit();
	}
	else {
		graph[i - 1].deleteTransactions();
	}

	return isChange;
}

GraphRed::GraphRed() {
	graph.resize(5);
	graph[0] = Transaction<File>(File("SunFile", "Sun", "JPG"));
	graph[1] = Transaction<File>(File("Aqua", "Ocean", "JPG"));
	graph[2] = Transaction<File>(File("Man", "Portrait", "PNG"));
	graph[3] = Transaction<File>(File("Important", "Family", "PSD"));
	graph[4] = Transaction<File>(File("BSUIR", "University", "TIF"));
}

void GraphRed::push_back() {
	Transaction<File> file;
	file->setName();
	file->setData();
	file->setFormat();
	graph.push_back(file);
}

void GraphRed::erase() {
	if (isEmpty()) { return; }

	unsigned int i = inputNumber();
	graph.erase(graph.begin() + i - 1);
}

void GraphRed::edit() {
	if (isEmpty()) { return; }

	unsigned int i = inputNumber();
	graph[i - 1].beginTransactions();
	graph[i - 1]->setName();
	graph[i - 1]->setData();

	cout << "\nFile: ";
	graph[i - 1]->showFullName();
	cout << "Data: " << graph[i - 1]->getData() << endl;
	isAgreeChange(i);
}

void GraphRed::convert(History& history) {
	if (isEmpty()) { return; }

	ElementHistory note;
	note.setEditor();

	unsigned int i = inputNumber();
	note.setName(graph[i - 1]->getName());
	note.setFormatStart(graph[i - 1]->getFormat());

	graph[i - 1].beginTransactions();
	graph[i - 1]->setFormat();

	note.setFormatEnd(graph[i - 1]->getFormat());

	cout << "\nConvertion to ";
	graph[i - 1]->showFullName();

	note.setSuccess(isAgreeChange(i));
	history.push_back(note);
}

void GraphRed::show() {
	if (isEmpty()) { return; }

	unsigned int i = inputNumber();
	cout << "\nFile: ";
	graph[i - 1]->showFullName();
	cout << "Data: " << graph[i - 1]->getData() << endl;
}

void GraphRed::showAll() {
	if (isEmpty()) { return; }

	cout << "List of all files\n\n";
	for (int i = 0; i < graph.size();i++) {
		cout << i + 1 << ". ";
		graph[i]->showFullName();
	}
}
