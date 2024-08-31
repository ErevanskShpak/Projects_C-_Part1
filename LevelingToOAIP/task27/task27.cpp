#include <iostream>

using namespace std;

struct Stack {
	char info;
	Stack* next = NULL;
};

void push(Stack*&, char);
void popAll(Stack*&);
void showAll(Stack*);
void task(Stack*&, Stack*&);

char main() { //стек. перенос нижнего регистра в другой
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL, * begin2 = NULL;

	cout << "Введите 9 элементов стека\n";
	char info;
	for (char i = 0; i < 9; i++) {
		cin >> info;
		push(begin, info);
	}
	showAll(begin);

	task(begin, begin2);
	showAll(begin);

	popAll(begin);
	showAll(begin);

	showAll(begin2);

	popAll(begin2);
	showAll(begin2);

	return 0;
}

void push(Stack*& begin, char info) {
	Stack* t = new Stack;
	t->info = info;
	t->next = begin;
	begin = t;
}

void popAll(Stack*& begin) {
	if (begin == NULL) {
		cout << "Стек пуст\n";
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
		cout << "Стек пуст\n";
		return;
	}

	while (t != NULL) {
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

void task(Stack*& begin, Stack*& begin2) {
	Stack* temp;

	while (begin != NULL && ((int)begin->info >= 'a' && (int)begin->info <= 'z')) {
		temp = begin->next;
		begin->next = begin2;
		begin2 = begin;
		begin = temp;
	}

	Stack* t = begin;
	while (t != NULL && t->next != NULL) {
		if (((int)begin->info >= 'a' && (int)begin->info <= 'z')) {
			temp = t->next;
			t->next = t->next->next;
			temp->next = begin2;
			begin2 = temp;
			continue;
		}
		t = t->next;
	}
}