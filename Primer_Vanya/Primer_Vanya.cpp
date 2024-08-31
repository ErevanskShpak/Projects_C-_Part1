#include <iostream>

using namespace std;

double func(double *mas,int n)
{
	double sum=0,r;
	int i, kolvo=0, min_i=0, max_i=0;
	for (i = 0; i < n; i++)
	{
		if (mas[i] < 0)
		{
			sum += mas[i];
			kolvo++;
		}
		if (mas[i] < mas[min_i])
			min_i = i;
		if (mas[i] > mas[max_i])
			max_i = i;
	}
	if (min_i > max_i)
	{
		int p = min_i;
		min_i = max_i;
		max_i = p;
	}
	for (i = min_i+1; i < max_i/2.; i++)
	{
		r = mas[i];
		mas[i] = mas[max_i - i];
		mas[max_i - i] = r;
	}
	if (kolvo)
		return sum / kolvo;
	else
		return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double* mas, res;
	int n,i;
	cout << "Введите размер массива"<<endl;
	cin >> n;
	mas = new double[n];
	cout << "Введите элементы массива" << endl;
	for (i = 0; i < n; i++)
		cin >> mas[i];
	cout << "Начальный массив" << endl;
	for (i = 0; i < n; i++)
		cout << mas[i]<<" ";
	cout << endl;
	if (res=func(mas, n))
		cout << "Среднее арифметическое отрицательных = " << res << endl;
	else
		cout << "Нет отрицательных чисел" << endl;
	cout << "Конечный массив" << endl;
	for (i = 0; i < n; i++)
		cout << mas[i] << " ";
	return 0;
}