#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double a, z1, z2;
	cout << "Введите значение переменной a в радианах. a = ";
	cin >> a;
	while (cin.fail())
	{
		cout << "Переменная a введена некорректно, повторите попытку. a = ";
		cin.clear();
		cin.ignore(1024,'\n');
		cin >> a;
	}
	z1 = 1 - 0.25 * pow(sin(2 * a), 2) + cos(2 * a);
	z2 = pow(cos(a), 2) + pow(cos(a), 4);
	cout << "Значение z1 = " << z1 << endl << "Значение z2 = " << z2;
	return 0;
}