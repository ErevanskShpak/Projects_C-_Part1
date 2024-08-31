#include <iostream>

using namespace std;

struct Spis
{
	int info;
	Spis* next = NULL, * prev = NULL;
};

void create(Spis*&, Spis*&, int);
void add(Spis*&, Spis*&, int);
void showAll(Spis*, Spis*);
void popAll(Spis*&);
void delete2(Spis*&, Spis*&);

int main()
{
	setlocale(LC_ALL, "rus");
	int i, in, n, lever;
	Spis* begin = NULL, * end = NULL;
	while (true)
	{
		cout << "1. Создать первый элемент списка\n2. Добавить элементы\n3. Показать список\n4. Удалить весь список\n0. Выйти\n";
		cin >> lever;
		switch (lever)
		{
		case 1:
			cout << "Введите первый элемент списка\n";
			cin >> in;
			
			create(begin, end, in);
			break;
		case 2:
			if (!begin)
			{
				cout << "Список пуст\n";
				break;
			}

			cout << "Введите кол-во = ";
			cin >> n;

			for (i = 0; i < n; i++)
			{
				cout << "Введите элемент списка\n";
				cin >> in;

				add(begin, end, in);
			}
			break;
		case 3:
			if (!begin)
			{
				cout << "Список пуст\n";
				break;
			}

			showAll(begin, end);
			break;
		case 4:
			popAll(begin);
			cout << "Память очищена\n";
			break;
		case 0:
			if (begin != NULL)
				popAll(begin);
			return 0;
		}
	}
}

void create(Spis*& begin, Spis*& end, int info)
{
	Spis* tool = new Spis;
	tool->info = info;
	begin = end = tool;
}

void add(Spis*& begin, Spis*& end, int info)
{
	Spis* tool = new Spis;
	tool->info = info;

	bool isWhen;
	cout << "Добавить в начало или конец списка?\n0. В начало\n1. В конец\n";
	cin >> isWhen;

	if (!isWhen) {
		tool->next = begin;
		begin->prev = tool;
		begin = tool;
	}
	else {
		tool->prev = end;
		end->next = tool;
		end = tool;
	}
}

void showAll(Spis* begin, Spis* end)
{
	Spis* tool;

	bool isWhen;
	cout << "Просмотреть с начала или с конца списка?\n0. С начала\n1. С конца\n";
	cin >> isWhen;

	cout << "--- Список ---\n";
	if (!isWhen) {
		tool = begin;
		while (tool != NULL)
		{
			cout << tool->info << " ";
			tool = tool->next;
		}
	}
	else {
		tool = end;
		while (tool != NULL)
		{
			cout << tool->info << " ";
			tool = tool->prev;
		}
	}
}

void popAll(Spis*& begin)
{
	Spis* tool;
	while (begin != NULL)
	{
		tool = begin;
		begin = begin->next;
		delete tool;
	}
}