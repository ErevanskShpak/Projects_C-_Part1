#include "Lab1_OOP.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	bool menu = 1;
	int lever;
	cout << "�������� ����� ������������ ������\n";
	cout << "1. ������ ����" << endl;
	cout << "2. ������ ����" << endl;
	cout << "3. ������ ����" << endl;
	cout << "4. ���������� ����" << endl;
	cout << "0. �����" << endl;
	cin >> lever;
	while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������������ ����, ��������� �������." << endl;
			cin >> lever;
		}
	switch (lever)
	{
	case 1:
		lab1();
		break;
	case 2:
	case 3:
	case 4:
		cout << "���� ��� �� ����������\n";
		break;
	case 0:
		menu = 0;
		break;
	default:
		cout << "������������ ����. ��������� �������\n";
	}
	return 0;
}