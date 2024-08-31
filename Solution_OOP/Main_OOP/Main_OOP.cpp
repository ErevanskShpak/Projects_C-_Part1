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
		system("C:\\My_projects\\Solution_OOP\\x64\\Debug\\Lab1OOP.exe");
		break;
	case 2:
		system("C:\\My_projects\\Solution_OOP\\x64\\Debug\\Lab2OOP.exe");
		break;
	case 3:
		system("C:\\My_projects\\Solution_OOP\\x64\\Debug\\Lab3OOP.exe");
		break;
	case 4:
		system("C:\\My_projects\\Solution_OOP\\x64\\Debug\\Lab4OOP_n.exe");
		break;
	case 0:
		menu = 0;
		break;
	default:
		cout << "Некорректный ввод. Повторите попытку\n";
	}
	return 0;
}