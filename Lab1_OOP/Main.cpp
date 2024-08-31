#include "Lab1_OOP.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	bool menu = 1;
	int lever;
	cout << "Выберите номер лабораторной работы\n";
	cout << "1. Первая лаба" << endl;
	cout << "2. Вторая лаба" << endl;
	cout << "3. Третья лаба" << endl;
	cout << "4. Четвератая лаба" << endl;
	cout << "0. Выход" << endl;
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
		lab1();
		break;
	case 2:
	case 3:
	case 4:
		cout << "Лабы еще не существует\n";
		break;
	case 0:
		menu = 0;
		break;
	default:
		cout << "Некорректный ввод. Повторите попытку\n";
	}
	return 0;
}