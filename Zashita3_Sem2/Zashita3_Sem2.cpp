#include <iostream>

using namespace std;

struct Stack
{
	int info;
	Stack* next;
};

void push(Stack*&, int);
void show(Stack*);
void pop(Stack*&);
void pop_all(Stack*&);
void delete2(Stack*);
void Sort_p(Stack*);
void Sort_info(Stack*);
void NewStack(Stack* start, Stack*& start2);
void NewStack2(Stack* start, Stack*& start2);

int main()
{
	setlocale(LC_ALL, "rus");
	int i, in, n, lever;
	Stack* start = NULL;
	Stack * start2=NULL;
	while (true)
	{
		cout << "1. Добавить элементы\n2. Показать стек\n3. Удалить один элемент\n4. Удалить весь стек\n5. Удалить каждый второй\n6. Сортировать перестановкой адресов\n7. Сортировать перестановкой информации\n0. Выйти\n";
		cin >> lever;
		switch (lever)
		{
		case 1:
			cout << "Введите кол-во = ";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> in;
				push(start, in);
			}
			break;
		case 2:
			if (!start)
			{
				cout << "Стек пуст\n";
				break;
			}
			cout << "--- Стек ---\n";
			show(start);
			break;
		case 3:
			pop(start);
			break;
		case 4:
			pop_all(start);
			cout << "Память очищена\n";
			break;
		case 5:
			delete2(start);
			break;
		case 6:
			push(start, 10);
			Sort_p(start);
			pop(start);
			break;
		case 7:
			Sort_info(start);
			break;
		case 8:
			NewStack2(start, start2);
			show(start2);
			break;
		case 0:
			if (start != NULL)
				pop_all(start);
			return 0;
		}
	}
}

void push(Stack*& start, int in)
{
	Stack* tool;
	tool = new Stack;
	tool->info = in;
	tool->next = start;
	start = tool;
}

void show(Stack* start)
{
	Stack* tool;
	tool = start;
	while (tool != NULL)
	{
		cout << " " << tool->info << endl;
		tool = tool->next;
	}
	start = NULL;
}

void pop(Stack*& start)
{
	Stack* tool;
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	tool = start->next;
	delete start;
	start = tool;
}

void pop_all(Stack*& start)
{
	Stack* tool;
	while (start != NULL)
	{
		tool = start;
		start = start->next;
		delete tool;
	}
}

void delete2(Stack* start)
{
	Stack* tool;
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* t1 = start;
	while (t1 != NULL && t1->next != NULL)
	{
		tool = t1->next;
		t1->next = tool->next;
		delete tool;
		t1 = t1->next;
	}
}

void NewStack(Stack* start, Stack*& start2)
{
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* t1 = start;
	Stack* tool = NULL;
	while (t1->next != NULL)
	{
		if ((t1->next)->info < 5)
		{
			tool = t1->next;
			t1->next = tool->next;
			tool->next = start2;
			start2 = tool;
		}
		else
			t1 = t1->next;
	}
}

void NewStack2(Stack* start, Stack*& start2)
{
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* t1 = start;
	Stack* tool = NULL;
	while (t1 != NULL && t1->next != NULL && t1->next->next!=NULL)
	{
		t1 = t1->next;
		tool = t1->next;
		t1->next = tool->next;
		tool->next = start2;
		start2 = tool;
		t1 = t1->next;
	}
}

void Sort_p(Stack* start)
{
	Stack* tool;
	if (start->next == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* t1, * r;
	tool = NULL;
	if (start->next->next == NULL) return;
	do {
		for (t1 = start; t1->next->next != tool; t1 = t1->next)
			if (t1->next->info > t1->next->next->info)
			{
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		tool = t1->next;
	} while (start->next->next != tool);
}

void Sort_info(Stack* start)
{
	Stack* tool;
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* t1;
	int r;
	tool = NULL;
	do {
		for (t1 = start; t1->next != tool; t1 = t1->next)
			if (t1->info > t1->next->info)
			{
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		tool = t1;
	} while (start->next != tool);
}