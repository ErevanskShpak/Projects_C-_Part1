#include <iostream>
#include <cmath>
using namespace std;
double check(double op1)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Переменная введена некорректно, повторите попытку."<<endl;
		cin >> op1;
	}
	return op1;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double x, y, z, g;
	cout << "Введите значение переменной x. x = ";
	cin >> x;
	x = check(x);
	cout << "Введите значение переменной y. y = ";
	cin >> y;
	y = check(y);
	if (y < 0)
	{
		cout << "Неправильное значение переменной y";
		return 1;
	}
	if (x + y == 0)
	{
		cout << "Недопустимое сочетание переменных x и y";
		return 1;
	}
	cout << "Введите значение переменной z. z = ";
	cin >> z;
	z = check(z);
	if (sin(z) == 0)
	{
		cout << "Недопустимое значение переменной z";
		return 1;
	}
	g = pow(y, x + 1) / (pow(fabs(y - 2), (double)1 / 3) + 3) + (x + y / 2) / (2 * fabs(x + y)) * pow(x + 1, (double)(-1) / sin(z));
	cout << "Значение g = " << g;
	return 0;
}