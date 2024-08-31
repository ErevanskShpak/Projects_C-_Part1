#include <iostream>

using namespace std;

struct Stack {
	int info;
	Stack* next = NULL;
};

void push(Stack*&, int);
void popAll(Stack*&);
void showAll(Stack*);
void task(Stack*&, Stack*&, int);

int main() { //стек. поместить первый во второй
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL, * begin2 = NULL;

	int info;
	cout << "Введите  элементы первого стека из 3\n";
	for (int i = 0; i < 3; i++) {
		cin >> info;
		push(begin, info);
	}
	cout << "Введите  элементы второго стека из 4\n";
	for (int i = 0; i < 4; i++) {
		cin >> info;
		push(begin2, info);
	}
	showAll(begin);
	showAll(begin2);

	cout << "Введите позицию, куда вставить первый стек: ";
	int pos;
	cin >> pos;
	while (pos < 1 || pos>5) {
		cout << "Некорректное место! Введите заново: ";
		cin >> pos;
	}
	task(begin, begin2, pos);
	showAll(begin2);

	popAll(begin2);
	showAll(begin2);

	showAll(begin);

	return 0;
}

void push(Stack*& begin, int info) {
	Stack* t = new Stack;
	t->info = info;
	t->next = begin;
	begin = t;
}

void popAll(Stack*& begin) {
	if (begin == NULL) {
		cout << "Удаление. Стек пуст\n";
		return;
	}

	while (begin != NULL) {
		static Stack* t;
		t = begin->next;
		delete begin;
		begin = t;
	}
}

void showAll(Stack* t) {
	if (t == NULL) {
		cout << "Просмотр. Стек пуст\n";
		return;
	}

	while (t != NULL) {
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

void task(Stack*& begin, Stack*& begin2, int pos) {
	Stack* t;

	if (pos == 1) {
		t = begin;
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = begin2;
		begin2 = begin;
		begin = NULL;
		return;
	}

	t = begin2;
	for (int i = 0; i < pos - 2; i++) {
		t = t->next;
	}

	Stack* temp = t->next;
	t->next = begin;
	t = begin;
	while (t->next != NULL) {
		t = t->next;
	}
	t->next = temp;
	begin = NULL;
}