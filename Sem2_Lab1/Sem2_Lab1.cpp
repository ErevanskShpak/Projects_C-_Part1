#include <iostream>

using namespace std;

double recursiv(int, int);
double usual2(int, int);

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k, lever;
	cout << "Введите n\n";
	cin >> n;
	cout << "Введите k\n";
	cin >> k;
	cout << "Выберите какой функцией выполнить расчет:\n1. Рекурсивной\n2. Обычной\n";
	cin >> lever;
	switch (lever)
	{
	default: cout << "Такого варианта нет. Автоматический выбран рекусривный способ";
	case 1: cout << "Результат С равен = " << recursiv(n, k); break;
	case 2: cout << "Результат С равен = " << usual2(n,k);
	}
	return 0;
}

double recursiv(int x, int y)
{
	if (y == 0 || y == x)
		return 1;
	else
		return recursiv(x - 1, y - 1) + recursiv(x - 1, y);
}

double usual2(int x, int y)
{
	double res = 1;
	int i, raz = x - y;
	for (i = x; i >y; i--) res *= i;
	for (i = 2; i <= raz; i++) res /= i;
	return res;
}