#include <iostream>
#include <cmath>

using namespace std;

double check(double op1)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Переменная введена некорректно, повторите попытку." << endl;
		cin >> op1;
	}
	return op1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, h, x, y, ma, mi, first;
	int k = 1;
	cout << "Введите значение а"<<endl;
	cin >> a;
	a = check(a);
	cout << "Введите значение b"<<endl;
	cin >> b;
	b = check(b);
	cout << "Введите значение h"<<endl;
	cin >> h;
	h = check(h);
	first = 1 / (a * a - a + 1);
	ma = first;
	mi = first;
	cout << "Порядковый номер = " << k << "\tЗначение аргумента = " << a << "\tЗначение функции = " << first << endl;
	for (x = a+h;x <= b;x += h)
	{
		k++;
		y = 1 / (x * x - x + 1);
		if (y > ma)
		{
			ma = y;
		}
		if (y < mi)
		{
			mi = y;
		}
		cout << "Порядковый номер = " << k << "\tЗначение аргумента = " << x << "\tЗначение функции = " << y << endl;
	}
	cout << "Максимальное значение y = " << ma << endl << "Минимальное значение y = " << mi;
	return 0;
 }