#include "PriorityQueue.h"

bool PriorityQueue::isEmpty() const {
	if (medPriorityQueue.empty()) {
		cout << "Container is empty\n";
		return true;
	}

	return false;
}

void PriorityQueue::add() {
	MedWorker cur;
	string name = Input::inputWord("name"), type = Input::inputWord("major");

	cur.setName(name);
	cur.setMajor(type);

	medPriorityQueue.push(cur);
}

void PriorityQueue::del() {
	if (isEmpty()) {
		return;
	}
	showAll();

	medPriorityQueue.pop();
	cout << "Delete completed\n";
}

void PriorityQueue::showAll() {
	if (isEmpty()) {
		return;
	}

	string line(30, '-');
	cout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	cout << line << endl;

	ofstream fout("medStack.txt");
	fout << "|" << setw(6) << "Number" << "|" << setw(10) << "Major" << "|" << setw(10) << "Name" << "|" << endl;
	fout << line << endl;

	priority_queue<MedWorker> copy(medPriorityQueue);
	MedWorker cur;
	short i = 0;
	while (!copy.empty()) {
		cur = copy.top();
		copy.pop();

		cout << "|" << setw(6) << ++i << "|" << setw(10) << cur.getMajor() << "|" << setw(10) << cur.getName() << "|" << endl;
		cout << line << endl;

		fout << "|" << setw(6) << i << "|" << setw(10) << cur.getMajor() << "|" << setw(10) << cur.getName() << "|" << endl;
		fout << line << endl;
	}
}
