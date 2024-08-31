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
void task(Queue*&, Queue*&, Queue*&, Queue*&);
void partTask(Queue*&, Queue*&, Queue*);

int main() { //двунаправ очередь. полож перенести в новую очередь
	setlocale(LC_ALL, "ru");
	Queue* begin = NULL, * end = NULL, * begin2 = NULL, * end2 = NULL;

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
	showAll(begin);

	task(begin, end, begin2, end2);
	showAll(begin);

	popAll(begin);
	showAll(begin);

	showAll(begin2);

	popAll(begin2);
	showAll(begin2);

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

void task(Queue*& begin, Queue*& end, Queue*& begin2, Queue*& end2) {
	Queue* temp;

	while (begin->info > 0 && begin->next != NULL) {
		temp = begin;
		begin = begin->next;
		begin->prev = NULL;
		partTask(begin2, end2, temp);
	}

	Queue* t = begin;
	while (t->next != NULL) {
		if (t->info > 0) {
			temp = t;
			t->prev->next = t->next;
			t->next->prev = t->prev;
			t = t->next;
			partTask(begin2, end2, temp);
		}
		else {
			t = t->next;
		}
	}

	if (t->info > 0) {
		end = t->prev;
		if (end == NULL) {
			begin = NULL;
		}
		else {
			end->next = NULL;
		}
		partTask(begin2, end2, t);
	}
}

void partTask(Queue*& begin2, Queue*& end2, Queue* temp) {
	if (begin2 == NULL) {
		temp->next = temp->prev = NULL;
		begin2 = end2 = temp;
	}
	else {
		end2->next = temp;
		temp->prev = end2;
		temp->next = NULL;
		end2 = temp;
	}
}