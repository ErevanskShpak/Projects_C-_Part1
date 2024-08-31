#include <iostream>

using namespace std;

struct Stack {
	int info = 0;
	Stack* next = NULL;
};

void push(Stack*&, int);
void pop_all(Stack*&);
void show_all(Stack*);
void perenos(Stack*& , Stack*& );

int main() //стек. перенос отриц в другой
{
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL, * begin2 = NULL;

	cout << "Введите 8 элементов стека\n";
	for (int i = 0; i < 8; i++) {
		static int info;
		cin >> info;
		push(begin, info);
	}
	show_all(begin);

	perenos(begin, begin2);
	show_all(begin);

	pop_all(begin);
	show_all(begin);

	show_all(begin2);

	pop_all(begin2);
	show_all(begin2);

	return 0;
}

void push(Stack*& begin, int info)
{
	Stack* t = new Stack;
	t->info = info;
	t->next = begin;
	begin = t;
}

void pop_all(Stack*& begin)
{
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

void show_all(Stack* t)
{
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

void perenos(Stack*& begin, Stack*& begin2) {
	Stack* temp;

	while (begin != NULL && begin->info < 0) {
		temp = begin->next;
		begin->next = begin2;
		begin2 = begin;
		begin = temp;
	}

	Stack* t = begin;
	while (t != NULL && t->next != NULL) {
		if (t->next->info < 0) {
			temp = t->next;
			t->next = t->next->next;
			temp->next = begin2;
			begin2 = temp;
			continue;
		}
		t = t->next;
	}
}