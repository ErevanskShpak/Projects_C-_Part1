#include <iostream>

using namespace std;

struct Spis
{
	int info;
	Spis* next, *prev;
};

void create(Spis*&, Spis*&, int);
void add(Spis*&, Spis*&, int);
void show(Spis*, Spis*);
void pop_all(Spis*&);
void delete2(Spis*&, Spis*&);
//void Sort_p(Stack*);
//void Sort_info(Stack*);
//Spis* individ(Spis* b);
void delete4(Spis*& start, Spis*& end);

int main()
{
	setlocale(LC_ALL, "rus");
	int i, in, n, lever;
	Spis* start = NULL, *end = NULL;
	while (true)
	{
		cout << "1. Создать первый элемент списка\n2. Добавить элементы\n3. Показать список\n4. Удалить весь список\n5. Удалить каждый второй\n0. Выйти\n";
		cin >> lever;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> lever;
		}
		switch (lever)
		{
		case 1:
			cout << "Введите первый элемент списка\n";
			cin >> in;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "Некорректный ввод, повторите попытку." << endl;
				cin >> in;
			}
			create(start, end, in);
			break;
		case 2:
			if (!start)
			{
				cout << "Список пуст\n";
				break;
			}
			cout << "Введите кол-во = ";
			cin >> n;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "Некорректный ввод, повторите попытку." << endl;
				cin >> n;
			}
			for (i = 0; i < n; i++)
			{
				cout << "Введите элемент списка\n";
				cin >> in;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "Некорректный ввод, повторите попытку." << endl;
					cin >> in;
				}
				add(start, end, in);
			}
			break;
		case 3:
			if (!start)
			{
				cout << "Список пуст\n";
				break;
			}
			show(start, end);
			break;
		case 4:
			pop_all(start);
			cout << "Память очищена\n";
			break;
		case 5:
			if (!start)
			{
				cout << "Список пуст\n";
				break;
			}
			delete2(start, end);
			break;
		/*case 6:
			start= individ(start);
			break;*/
		case 7:
			delete4(start, end);
			break;
		/*case 6:
			push(start, 10);
			Sort_p(start);
			pop(start);
			break;
		case 7:
			Sort_info(start);
			break;*/
		case 0:
			if (start != NULL)
				pop_all(start);
			return 0;
		}
	}
}

void create(Spis*& start, Spis*& end, int in)
{
	Spis* tool = new Spis;
	tool->info = in;
	tool->next = tool->prev = NULL;
	start = end = tool;
}

void add(Spis*& start, Spis*& end, int in)
{
	Spis* tool = new Spis;
	tool->info = in;
	int lever = 0;
	cout << "Добавить в начало или конец списка?\n0. В начало\n1. В конец\n";
	cin >> lever;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Некорректный ввод, повторите попытку." << endl;
		cin >> lever;
	}
	switch (lever)
	{
	default:
		cout << "Некорректный ввод, по умолчанию будет добавлено в начало";
	case 0:
		tool->prev = NULL;
		tool->next = start;
		start->prev = tool;
		start = tool;
		break;
	case 1:
		tool->next = NULL;
		tool->prev = end;
		end->next = tool;
		end = tool;
	}
}

void show(Spis* start, Spis*end)
{
	Spis* tool;
	int lever = 0;
	cout << "Просмотреть с начала или с конца списка?\n0. С начала\n1. С конца\n";
	cin >> lever;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Некорректный ввод, повторите попытку." << endl;
		cin >> lever;
	}
	switch (lever)
	{
	default:
		cout << "Некорректный ввод, по умолчанию будет просмотрено с начала";
	case 0:
		cout << "--- Список ---\n";
		tool = start;
		while (tool != NULL)
		{
			cout << " " << tool->info << endl;
			tool = tool->next;
		}
		break;
	case 1:
		cout << "--- Список ---\n";
		tool = end;
		while (tool != NULL)
		{
			cout << " " << tool->info << endl;
			tool = tool->prev;
		}
	}
	
}

void pop_all(Spis*& start)
{
	Spis* tool;
	while (start != NULL)
	{
		tool = start;
		start = start->next;
		delete tool;
	}
}

void delete2(Spis* &start, Spis* &end)
{
	Spis* tool, *t1=NULL;
	int lever = 0;
	cout << "Удалить с начала или с конца списка?\n0. С начала\n1. С конца\n";
	cin >> lever;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Некорректный ввод, повторите попытку." << endl;
		cin >> lever;
	}
	switch (lever)
	{
	default:
		cout << "Некорректный ввод, по умолчанию будет удалено с начала";
	case 0:
		t1 = start;
		while (t1 != NULL && t1->next != NULL && t1->next->next!=NULL)
		{
			tool = t1->next;
			t1->next = tool->next;
			(tool->next)->prev = t1;
			delete tool;
			t1 = t1->next;
		}
		if (t1!=NULL && t1->next!=NULL && t1->next->next == NULL)
		{
			end = end->prev;
			end->next = NULL;
			delete (t1->next);
		}
		break;
	case 1:
		t1 = end;
		while (t1 != NULL && t1->prev != NULL && t1->prev->prev != NULL)
		{
			tool = t1->prev;
			t1->prev = tool->prev;
			(tool->prev)->next = t1;
			delete tool;
			t1 = t1->prev;
		}
		if (t1 != NULL && t1->prev != NULL && t1->prev->prev == NULL)
		{
			start = start->next;
			start->prev = NULL;
			delete (t1->prev);
		}
	}
}

//Spis* individ(Spis* b)
//{
//	Spis* t = b, * z;
//	while (t->next != NULL) {
//
//		z = t->next;
//		if (z->info % 10 != 0 && z->info % 5 == 0) {
//			(z->prev)->next = z->next;
//			(z->next)->prev = z->prev;
//			delete z;
//		}
//		else
//			t = t->next;
//	}
//
//	t = b;
//	if (t->info % 10 != 0 && t->info % 5 == 0) {
//		b = b->next;
//		b->prev = NULL;
//		delete t;
//	}
//
//	return b;
//}

//void Sort_p(Stack* start)
//{
//	Stack* tool;
//	if (start->next == NULL)
//	{
//		cout << "Стек пуст\n";
//		return;
//	}
//	Stack* t1, * r;
//	tool = NULL;
//	if (start->next->next == NULL) return;
//	do {
//		for (t1 = start; t1->next->next != tool; t1 = t1->next)
//			if (t1->next->info > t1->next->next->info)
//			{
//				r = t1->next->next;
//				t1->next->next = r->next;
//				r->next = t1->next;
//				t1->next = r;
//			}
//		tool = t1->next;
//	} while (start->next->next != tool);
//}
//
//void Sort_info(Stack* start)
//{
//	Stack* tool;
//	if (start == NULL)
//	{
//		cout << "Стек пуст\n";
//		return;
//	}
//	Stack* t1;
//	int r;
//	tool = NULL;
//	do {
//		for (t1 = start; t1->next != tool; t1 = t1->next)
//			if (t1->info > t1->next->info)
//			{
//				r = t1->info;
//				t1->info = t1->next->info;
//				t1->next->info = r;
//			}
//		tool = t1;
//	} while (start->next != tool);
//}

void delete4(Spis*& start, Spis*& end)
{
	Spis *tool, * t1 = NULL;
		t1 = start->next;
		while (t1->next != NULL)
		{
			if (t1->info > 4)
			{
				tool = t1;
				t1 = t1->next;
				(tool->prev)->next = tool->next;
				(tool->next)->prev = tool->prev;
				delete tool;
			}
			else
				t1 = t1 -> next;
		}
		if (end->info>4)
		{
			end = end->prev;
			end->next = NULL;
			delete t1;
		}
		if (start->info > 4)
		{
			if (start->next != NULL)
			{
				t1 = start;
				start = start->next;
				start->prev = NULL;
				delete t1;
			}
			else
				start = NULL;
		}
}