#include <iostream>
#include <cmath>

using namespace std;

double CountY(double x, int&k)
{
	return (exp(x) - exp(-x)) / 2;
}

double CountS(double x, int &k)
{
	double rec, s;
	s = x;
	rec = 1;
	for (k = 1;; k ++)
	{
		rec *= x * x / (2 * k * (2 * k + 1));
		s += rec;
		if (abs(CountY(x, k) - s) >= 0.001) break;
	}
	return s;
}

double raznost(double x, int &k)
{
	return abs(CountY(x, k) - CountS(x, k));
}

void out_rez(double (*choosen) (double x1, int &k1), double x, int k, bool lever)
{
	cout << "Результат = " << choosen(x, k)<<" ";
	if (lever==0)
	cout << "Количество иттераций = " <<k+1<<endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, h, x;
	int choose, k{};
	cout << "Введите значение а. а = ";
	cin >> a;
	cout << "Введите значение b. b = ";
	cin >> b;
	cout << "Введите значение h. h = ";
	cin >> h;
	cout << "Выберите результат:" << endl << "1. Y(x)" << endl << "2. S(x)" << endl << "3. |Y(x)-S(x)|" << endl;
	cin >> choose;
	while (choose != 1 && choose != 2 && choose != 3) { cout << "Некорректный выбор. Повторите попытку" << endl; cin >> choose; }
	switch (choose)
	{
	case 1: for (x = a; x <= b; x += h) out_rez(CountY, x, 0, 1); break;
	case 2: for (x = a; x <= b; x += h) out_rez(CountS, x, k, 0); break;
	case 3: for (x = a; x <= b; x += h) out_rez(raznost, x, k, 0);
	}
	return 0;
}
