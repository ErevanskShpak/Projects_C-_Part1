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
		cout << "1. ������� ������ ������� ������\n2. �������� ��������\n3. �������� ������\n4. ������� ���� ������\n0. �����\n";
		cin >> lever;
		switch (lever)
		{
		case 1:
			cout << "������� ������ ������� ������\n";
			cin >> in;
			
			create(begin, end, in);
			break;
		case 2:
			if (!begin)
			{
				cout << "������ ����\n";
				break;
			}

			cout << "������� ���-�� = ";
			cin >> n;

			for (i = 0; i < n; i++)
			{
				cout << "������� ������� ������\n";
				cin >> in;

				add(begin, end, in);
			}
			break;
		case 3:
			if (!begin)
			{
				cout << "������ ����\n";
				break;
			}

			showAll(begin, end);
			break;
		case 4:
			popAll(begin);
			cout << "������ �������\n";
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
	cout << "�������� � ������ ��� ����� ������?\n0. � ������\n1. � �����\n";
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
	cout << "����������� � ������ ��� � ����� ������?\n0. � ������\n1. � �����\n";
	cin >> isWhen;

	cout << "--- ������ ---\n";
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