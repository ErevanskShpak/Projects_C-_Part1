#include <iostream>
#include <cmath>

using namespace std;

int check(int op1)
{
	cin >> op1;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Значение введено некорректно, повторите попытку." << endl;
		cin >> op1;
	}
	return op1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int mas[20], i, n, min_ind{}, sum{};
	cout << "Введите значение n" << endl;
	do
	{
		cin >> n;
		n = check(n);
	} while (n <= 0 || n > 20);
	for (i = 0;i < n;i++)
	{
		cout << "Введите значение элемента mas[" << i << "]" << endl;
		cin >> mas[i];
		mas[i] = check(mas[i]);
	}
	for (i = 0;i < n;i++)
	{
		if (abs(mas[i]) <= mas[min_ind])
		{
			min_ind = i;
		}
	}
	for (i = min_ind + 1;i < n;i++) sum += abs(mas[i]);
	if (sum != 0) cout << "Сумма модулей элементов равна = " << sum;
	else cout << "Наименьший по модулю элемент стоит в конце, поэтому задачу выполнить нельзя";
	return 0;
}