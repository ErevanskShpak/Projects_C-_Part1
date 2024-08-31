#include <iostream>

using namespace std;

double func(double**, int, int*, int*);

int main()
{
	setlocale(LC_ALL, "rus");
	double** mas;
	int n, i, j, kolvo_ne0=0, kolvo_avg=0;
	cout << "Введите размер матрицы n\n";
	cin >> n;
	mas = new double* [n];
	for (i = 0; i < n; i++)
		mas[i] = new double[n];
	cout << "Введите элементы массива\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> mas[i][j];
	cout << "Начальная матрица\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mas[i][j] << "\t";
		cout << endl;
	}
	cout << "Среднее арифметическое элементов = " << func(mas, n, &kolvo_ne0, &kolvo_avg) << endl;
	cout << "Количество элементов меньше среднего = " << kolvo_avg << endl;
	cout << "Количество столбцов не с 0 = " << kolvo_ne0 << endl;
	cout << "Конечная матрица\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mas[i][j] << "\t";
		cout << endl;
	}
	for (i = 0; i < n; i++)
		delete[]mas[i];
	delete[]mas;
	return 0;
}

double func(double** mas, int n, int *kolvo_ne0, int *kolvo_avg)
{
	int i,j,min_i=0,min_j=0;
	double sum=0,avg,*r;
	for (j = 0; j < n; j++)
	{
		if (mas[0][j] != 0) *kolvo_ne0+=1;
		for (i = 0; i < n; i++)
		{
			sum += mas[i][j];
			if (mas[i][j] < mas[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}
	avg = sum / (n * n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (mas[i][j] < avg) *kolvo_avg+=1;
	r = mas[0];
	mas[0] = mas[min_i];
	mas[min_i] = r;
	return avg;
}
