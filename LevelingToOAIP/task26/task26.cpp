#include <iostream>

using namespace std;

struct Queue {
	char info;
	Queue* next = NULL, * prev = NULL;
};

void create(Queue*&, Queue*&, char);
void push(Queue*&, char);
void popAll(Queue*&);
void showAll(Queue*);
void task(Queue*);

int main() { //двунаправ очередь. удалить каждый четный
	setlocale(LC_ALL, "ru");
	Queue* begin = NULL, * end = NULL;
	
	char info;
	for (int i = 0; i < 9; i++) {
		cout << "Введите " << i + 1 << "-й элемент очереди\n";
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

	task(begin);
	showAll(begin);

	popAll(begin);
	showAll(begin);

	return 0;
}

void create(Queue*& begin, Queue*& end, char info) {
	Queue* t = new Queue;
	t->info = info;
	begin = end = t;
}

void push(Queue*& end, char info) {
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

void task(Queue* begin) {
	Queue* t = begin;

	int kolvo = 0;
	while (t != NULL) {
		t = t->next;
		kolvo++;
	}
	kolvo = kolvo / 2;
	
	t = begin;
	for (int i = 0; i < kolvo - 1; i++) {
		t = t->next;
	}

	Queue* temp = new Queue;
	temp->info = 'W';
	temp->prev = t;
	temp->next = t->next;
	t->next->prev = temp;
	t->next = temp;
}