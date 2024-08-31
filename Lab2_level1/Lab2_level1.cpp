#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double z, x, y;
	cout << "Введите значение переменной z. z = ";
	cin >> z;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024,'\n');
		cout << "Переменная z введена неверно, повторите попытку. z =";
		cin >> z;
	}
	if (z > 0)
	{
		x = sqrt(z);
		cout << "Вычисление y происходило при z>0. y = ";
	}
	else
	{
		x = 3 * z * z * z - z - 5;
		cout << "Вычисление y происходило при z<=0. y =";
	}
	y = y = cos(5 * x) + sin((double)1 / 5 * x) + exp(x);
	cout << y;
	return 0;
}