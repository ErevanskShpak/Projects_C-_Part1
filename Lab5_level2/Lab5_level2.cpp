#include <iostream>

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
	int** mat, m{}, n{}, i, j, min_j{}, max_j{}, min_i{}, max_i{},  r;
	cout << "Введите значение n" << endl;
	n = check(n);
	cout << "Введите значение m" << endl;
	m = check(m);
	mat = new int* [n];
	for (i = 0;i < n;i++) mat[i] = new int[m]();
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
		{
			cout << "Введите значение элемента mat[" << i << "][" << j << "]" << endl;
			mat[i][j] = check(mat[i][j]);
		}
	cout << "Исходная матрица" << endl;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++) cout << mat[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
		{
			if (mat[i][j] < mat[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
			if (mat[i][j] > mat[max_i][max_j])
			{
				max_i = i;
				max_j = j;
			}
		}
	if (min_i == max_i) {
		cout << "Минимальный и максимальный элементы находятся в одной строке. Нельзя поменять местами строки.";
		return 1;
	}
	r = **(mat + min_i);
	**(mat + min_i) = **(mat + max_i);
	**(mat + max_i) = r;
	cout << "Итоговая матрица" << endl;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++) cout << mat[i][j] << "\t";
		cout << endl;
	}
	for (i = 0;i < n;i++) delete[]mat[i];
	delete[]mat;
	return 0;
}
