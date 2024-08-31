#include <iostream>

using namespace std;

struct Stack {
	int info = 0;
	Stack* next = NULL;
};

void push(Stack*&, int);
void popAll(Stack*&);
void showAll(Stack*);
void task(Stack*);

int main() { //стек. перед каждым третьим вставить 235
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL, * begin2 = NULL;

	cout << "Введите 5 элементов стека\n";
	int info;
	for (int i = 0; i < 5; i++) {
		cin >> info;
		push(begin, info);
	}
	showAll(begin);

	task(begin);
	showAll(begin);

	popAll(begin);
	showAll(begin);

	showAll(begin2);

	popAll(begin2);
	showAll(begin2);

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

void task(Stack* begin) {
	Stack* t = begin, * temp;
	while (t!=NULL && t->next != NULL && t->next->next!=NULL) {
		t = t->next;
		temp = new Stack;
		temp->info = 235;
		temp->next = t->next;
		t->next = temp;
		t = t->next->next->next;
	}
}