#include <iostream>

using namespace std;

struct Queue {
	int info = 0;
	Queue* next = NULL;
};

void create(Queue*&, Queue*&, int);
void push(Queue*&, int);
void pop_all(Queue*&);
void show_all(Queue*);
void task(Queue*&);

int main() //очередь. вставить элем перед каждым 3
{
	setlocale(LC_ALL, "ru");
	Queue* begin = NULL, * end = NULL;
	for (int i = 0; i < 9; i++) {
		cout << "Введите " << i + 1 << "-й элемент очереди\n";
		static int info;
		cin >> info;
		switch (i) {
		case 0:
			create(begin, end, info);
			break;
		default:
			push(end, info);
		}
	}
	show_all(begin);
	task(begin);
	show_all(begin);
	pop_all(begin);
	show_all(begin);
	return 0;
}

void create(Queue*& begin, Queue*& end, int info) {
	Queue* t = new Queue;
	t->info = info;
	begin = end = t;
}

void push(Queue*& end, int info)
{
	Queue* t = new Queue;
	t->info = info;
	end->next = t;
	end = t;
}

void pop_all(Queue*& begin)
{

	if (begin == NULL) {
		cout << "Удаление. Очередь пуста\n";
		return;
	}
	while (begin != NULL) {
		static Queue* t;
		t = begin->next;
		delete begin;
		begin = t;
	}
}

void show_all(Queue* t)
{
	if (t == NULL) {
		cout << "Просмотр. Очередь пуста\n";
		return;
	}
	while (t != NULL) {
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

void task(Queue*& begin) {
	if (begin == NULL || begin->next == NULL || begin->next->next == NULL) {
		cout << "В очереди только меньше 3 человек\n";
		return;
	}

	Queue* t = begin;
	while (t != NULL && t->next != NULL && t->next->next != NULL) {
		t = t->next;

		cout << "Введите новый элемент\n";
		Queue* temp = new Queue;
		cin >> temp->info;
		temp->next = t->next;
		t->next = temp;

		t = t->next->next->next;
	}
}