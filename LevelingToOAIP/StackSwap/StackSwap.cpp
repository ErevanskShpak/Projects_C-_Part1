#include <iostream>

using namespace std;

struct Stack {
	int info;
	Stack* next;
};

void push(Stack*&, int);
void pop_all(Stack*&);
void show_all(Stack*);
void Task(Stack*&, int, int);
void pop(Stack*& );

int main()
{
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL;

	cout << "Введите 7 элементов стека\n";
	for (int i = 0; i < 7; i++) {
		int info;
		cin >> info;
		push(begin, info);
	}
	show_all(begin);

	Task(begin, 3, 5);
	show_all(begin);

	pop_all(begin);
	show_all(begin);

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

void Task(Stack*& begin, int a, int b)
{
	push(begin, 0);

	Stack* t = begin, * temp, * preva = NULL, * prevb = NULL;

	while (t->next)
	{
		if (t->next->info == a) {
			preva = t;
		}
		if (t->next->info == b) {
			prevb = t;
		}

		t = t->next;
	}

	if (!preva || !prevb)
	{
		cout << "Нет таких элементов!" << endl;
		pop(begin);
		return;
	}

	if (preva->next == prevb || prevb->next == preva) { //если рядом стоят
		if (prevb->next == preva) {
			temp = preva;
			preva = prevb;
			prevb = temp;
		}

		temp = prevb->next;
		preva->next->next = prevb->next->next;

		temp->next = preva->next;
		preva->next = temp;
		
		pop(begin);
		return;
	}

	temp = preva->next->next;
	preva->next->next = prevb->next->next;
	prevb->next->next = temp;

	temp = preva->next;
	preva->next = prevb->next;
	prevb->next = temp;

	pop(begin);
}

void pop(Stack*& begin) {
	Stack* t = begin;
	begin = begin->next;
	delete t;
}