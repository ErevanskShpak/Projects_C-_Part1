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
	setlocale(LC_ALL, "rus");
	double x, y, f;
	int selection{};
	cout << selection;
	cout << "Введите переменную x. x = ";
	cin >> x;
	x = check(x);
	cout << "Введите переменную y. y = ";
	cin >> y;
	y = check(y);
	if (x > 0 && y >= 0)
	{
		selection = 1;
	}
	if (x < 0)
	{
		selection = 2;
	}
	switch (selection)
	{
	case 1:
		f = x > y + sqrt(x) ? x : y + sqrt(x);
		break;
	case 2:
		f = x < y ? x : y + pow(sin(x), 2) - cos(y * y);
		break;
	default:
		f = 0.5 * x + exp(y);
		break;
	}
	cout << "Значение выражения f = " << f;
	return 0;
}