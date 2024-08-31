#include <iostream>

using namespace std;

struct Stack {
	int info;
	Stack* next = NULL;
};

void push(Stack*&, int);
void pop_all(Stack*&);
void show_all(Stack*);
void task(Stack*&);
int searchMax(Stack*);

int main() //стек. переместить макс в начало
{
	setlocale(LC_ALL, "ru");
	Stack* begin = NULL;
	cout << "Введите 9 элементов стека\n";
	for (int i = 0; i < 9; i++) {
		static int info;
		cin >> info;
		push(begin, info);
	}
	show_all(begin);
	task(begin);
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

void task(Stack*& begin) {
	int max = searchMax(begin);
	if (begin->info == max) {
		cout << "Первый элемент является максимальным\n";
		return;
	}
	Stack* prev_max = begin;
	while (prev_max->next->info != max)
		prev_max = prev_max->next;
	Stack* temp=prev_max->next;
	prev_max->next = prev_max->next->next;
	temp->next = begin;
	begin = temp;
}

int searchMax(Stack* t) {
	int max = t->info;
	while (t != NULL) {
		if (t->info > max)
			max = t->info;
		t = t->next;
	}
	return max;
}