#include <iostream>

using namespace std;

struct Queue {
	int info = 0;
	Queue* next = NULL, * prev = NULL;
};

void create(Queue*&, Queue*&, int);
void push(Queue*&, int);
void pop_all(Queue*&);
void show_all(Queue*);
int task1(Queue*);
void task2(Queue*);

int main() //двунаправ очередь. cумма элемов и заменить каждый третий элем
{
	setlocale(LC_ALL, "ru");
	Queue* begin = NULL, * end = NULL;
	for (int i = 0; i < 6; i++) {
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
	cout << "Сумма всех элементов: " << task1(begin) << endl;
	task2(begin);
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
	t->prev = end;
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

int task1(Queue* t) {
	int sum = 0;
	while (t != NULL) {
		sum += t->info;
		t = t->next;
	}
	return sum;
}

void task2(Queue* t) {
	while (t!=NULL && t->next != NULL && t->next->next != NULL) {
		t = t->next->next;
		cout << "Введите новое значение элемента: ";
		cin >> t->info;
		t = t->next;
	}
}