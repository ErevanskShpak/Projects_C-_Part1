#include <iostream>

using namespace std;

int func(int*, int&, int*);

int main()
{
	setlocale(LC_ALL, "rus");
	int* mas, n, i, proiz=0;
	cout << "Введит рамзмер массива\n";
	cin >> n;
	mas = new int[n];
	cout << "Введите элементы массива\n";
	for (i = 0; i < n; i++)
		cin >> mas[i];
	cout << "Сумма четных элементов равна = " << func(mas, n, &proiz);
	if (proiz)
		cout << "\nПроизвдение последних трех членов равно = " << proiz;
	else
		cout << "В массиве меньше трех членов";
	cout << "\nКонечный массив\n";
	for (i = 0; i < n; i++)
		cout << mas[i] << " ";
	delete[]mas;
	return 0;
}

int func(int *mas, int& n, int* proiz)
{
	int sum=0, sum_all=0, i,j;
	for (i = 0; i < n; i++)
	{
		sum_all += mas[i];
		if (mas[i] % 2 == 0)
			sum += mas[i];
	}
	if (n>2)
		*proiz = mas[n - 1] * mas[n - 2] * mas[n - 3];
	double avg = (double)sum_all / n;
	for (i=0;i<n;i++)
		if (mas[i] < avg)
		{
			for (j = i; j < n-1; j++)
				mas[j] = mas[j + 1];
			n--;
			i--;
		}
	return sum;
}