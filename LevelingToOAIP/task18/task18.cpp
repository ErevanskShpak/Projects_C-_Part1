#include <iostream>

using namespace std;

struct Queue {
	int info = 0;
	Queue* next = NULL, * prev = NULL;
};

void create(Queue*&, Queue*&, int);
void push(Queue*&, int);
void popAll(Queue*&);
void showAll(Queue*);
void task(Queue*, Queue*&);

int main() { //двунаправ очередь. удалить каждый на четной позиции
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
	showAll(begin);

	task(begin, end);
	showAll(begin);

	popAll(begin);
	showAll(begin);

	return 0;
}

void create(Queue*& begin, Queue*& end, int info) {
	Queue* t = new Queue;
	t->info = info;
	begin = end = t;
}

void push(Queue*& end, int info) {
	Queue* t = new Queue;
	t->info = info;
	end->next = t;
	t->prev = end;
	end = t;
}

void popAll(Queue*& begin) {
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

void showAll(Queue* t) {
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

void task(Queue* begin, Queue*& end) {
	Queue* t = begin, * temp;

	while (t->next != NULL && t->next->next!=NULL) {
		t = t->next;
		temp = t;
		t->prev->next = t->next;
		t->next->prev = t->prev;
		t = t->next;
		delete temp;
	}

	if (t->next != NULL) {
		t = t->next;
		end = t->prev;
		end->next = NULL;
		delete t;
	}
}