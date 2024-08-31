#include <iostream>
#include <cmath>
using namespace std;

double check(double op1)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Переменная введена неверно, повторите попытку."<<endl;
		cin >> op1;
	}
	return op1;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double z, x, y, a, b, function;
	int selection;
	cout << "Введите значение переменной z. z = ";
	cin >> z;
	z = check(z);
	if (z > 0)
	{
		x = sqrt(z);
	}
	else
	{
		x = 3 * z + 1;
	}
	cout << "Введите значение переменной а. a = ";
	cin >> a;
	a = check(a);
	cout << "Введите значение переменной b. b = ";
	cin >> b;
	b = check(b);
	cout << "Выберите функцию f(x)" << endl << "\t1. f(x) = 2*x" << endl<<"\t2. f(x) = x^2" << endl<<"\t3. f(x) = x/3"<< endl<<"Номер функции = ";
		cin >> selection;
		selection = check(selection);
		switch (selection)
		{
		default:
			cout << "Вы неправильно выбрали функцию. Автоматически выберется 1 функция. ";
		case 1:
			function = 2 * x;
			cout << "Вычисление y происходило при f(x) = 2*x и ";
			break;
		case 2:
			function = x * x;
			cout << "Вычисление y происходило при f(x) = x^2 и ";
			break;
		case 3:
			function = x / 3;
			cout << "Вычисление y происходило при f(x) = x/3 и ";
			break;
		}
	if (z > 0)
	{
		cout << "при z>0. y = ";
	}
	else
	{
		cout << "при z<=0. y = ";
	}
	y = b * cos(a * function) + sin(x / 5) + a * exp(x);
	cout << y;
	return 0;
}