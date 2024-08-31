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
	int mas[20]{}, i, j, n{}, amount, max_amount, min_element;
	cout << "Введите значение n"<<endl;
	do
	{
		n = check(n);
	} while (n <= 0 || n > 20);
	for (i = 0;i < n;i++)
	{
		cout << "Введите значение элемента mas[" << i << "]"<<endl;
		mas[i] = check(mas[i]);

	}
	max_amount = 1;
	min_element = mas[0];
	for (i = 0;i < n;i++)
	{
		amount = 0;
		for (j = 0;j < n;j++) if (mas[j] == mas[i]) amount += 1;
		if (amount >= max_amount)
		{
			max_amount = amount;
			if (mas[i]<min_element)	min_element = mas[i];
		}
	}
	cout << "Наименьншее число максимальное количество раз = " << min_element;
	return 0;
}