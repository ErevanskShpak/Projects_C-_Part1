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
	double a, b, h, x, sum, rec,y;
	int k, n;
	cout << "Введите значение а. а = ";
	cin >> a;
	a = check(a);
	cout << "Введите значение b. b = ";
	cin >> b;
	b = check(b);
	cout << "Введите значение h. h = ";
	cin >> h;
	h = check(h);
	cout << "Введите значение n. n = ";
	cin >> n;
	n = check(n);
	for (x = a;x <= b;x += h)
	{
		sum = x;
		rec = 1;
		y = (exp(x) - exp(-x)) / 2;
		for (k = 1;k <= n;k += 1)
		{
			rec *= x * x / (2 * k * (2 * k + 1));
			sum += rec;
		}
		cout <<"Y(x) = " << y << "\tСумма S(x) = " << sum << "\t|Y(x)-S(x)| = " << abs(y - sum) << endl;
	}
	return 0;
}