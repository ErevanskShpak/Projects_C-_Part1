#include <iostream>

using namespace std;

struct Stack {
	int info;
	Stack* next = NULL;
};

void push(Stack*&, int);
void popAll(Stack*&);
void showAll(Stack*);
void task(Stack*&);

int main() { //стек. вставить перед каждым отрицательным новый элем
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL;

	cout << "Введите 8 элементов стека\n";
	for (int i = 0; i < 8; i++) {
		static int info;
		cin >> info;
		push(begin, info);
	}
	showAll(begin);

	task(begin);
	showAll(begin);

	popAll(begin);
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

void task(Stack*& begin) {
	Stack* t = begin, * temp;

	if (begin->info < 0) {
		cout << "Введите новый элемент\n";
		temp = new Stack;
		cin >> temp->info;
		temp->next = begin;
		begin = temp;
	}

	while (t->next != NULL) {
		if (t->next->info < 0) {
			cout << "Введите новый элемент\n";
			temp = new Stack;
			cin >> temp->info;
			temp->next = t->next;
			t->next = temp;
			t = t->next;
		}
		t = t->next;
	}
}