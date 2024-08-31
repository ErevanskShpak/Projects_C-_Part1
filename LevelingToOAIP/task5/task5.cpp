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
void zamena(Queue*&, Queue*&);
int searchMin(Queue*);

int main() //очередь. поменять вершину и мин
{
	setlocale(LC_ALL, "ru");
	Queue* begin = NULL, * end = NULL;
	for (int i = 0; i < 8; i++) {
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
	zamena(begin, end);
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

void zamena(Queue*& begin, Queue*& end) {
	int min = searchMin(begin);
	if (begin->info == min) {
		cout << "Первый элемент является минимальным\n";
		return;
	}
	Queue* prev_min = begin;
	while (prev_min->next->info != min)
		prev_min = prev_min->next;
	Queue* temp = begin->next;
	begin->next = prev_min->next->next;
	prev_min->next->next = temp;
	temp = prev_min->next;
	prev_min->next = begin;
	begin = temp;
	if (prev_min->next->next == NULL)
		end = prev_min->next;
}

int searchMin(Queue* t) {
	int min = t->info;
	while (t != NULL) {
		if (t->info < min)
			min = t->info;
		t = t->next;
	}
	return min;
}