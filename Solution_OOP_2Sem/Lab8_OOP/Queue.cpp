#include "Queue.h"

bool Queue::isEmpty() const {
	if (medQueue.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void Queue::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");

	cur.setName(name);
	cur.setMajor(type);

	medQueue.push(cur);
}

void Queue::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	medQueue.pop();
	cout << "Delete completed\n";
}

void Queue::showAll() {
	if (isEmpty()) {
		return;
	}

	string line(30, '-');
	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << line << endl;

	ofstream fout("medStack.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << line << endl;

	queue<MedWorker> copy(medQueue);
	MedWorker cur;
	short i = 0;
	while (!copy.empty()) {
		cur = copy.front();
		copy.pop();

		cout << "|" << setw(6) << ++i << "|" << setw(10) << cur.getMajor() << "|" << setw(10) << cur.getName() << "|" << endl;
		cout << line << endl;

		fout << "|" << setw(6) << i << "|" << setw(10) << cur.getMajor() << "|" << setw(10) << cur.getName() << "|" << endl;
		fout << line << endl;
	}
}
