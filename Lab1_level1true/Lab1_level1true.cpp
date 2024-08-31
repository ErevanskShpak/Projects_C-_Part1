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
	double a, b, z1, z2;
	cout << "Введите значение переменной a в радианах. a = ";
	cin >> a;
	a = check(a);
	if (a <= 0)
	{
		cout << "Недопустимое значение переменной a";
		return 1;
	}
	cout << "Введите значение переменной b в радианах. b = ";
	cin >> b;
	b = check(b);
	if (b < 0)
	{
		cout << "Недопустимое значение переменной b";
		return 1;
	}
	if ((sqrt(pow(a, 3) * b) + a * b + pow(a, 2) - a) == 0)
	{
		cout << "Недопустимое сочетание переменных a и b ";
		return 1;
	}
	z1 = ((a - 1) * sqrt(a) - (b - 1) * sqrt(b)) / (sqrt(a * a * a * b) + a * b + a * a - a);
	z2 = (sqrt(a) - sqrt(b)) / a;
	cout << "Значение z1 = " << z1 << endl << "Значение z2 = " << z2;
	return 0;
}