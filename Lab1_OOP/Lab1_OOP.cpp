#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <stdio.h>
#include "Lab1_OOP.h"

using namespace std;

void add(FILE*, char*);
void show1(FILE*, char*);
void show_all(FILE*, char*);
void delete_all(FILE*, char*);
void zamenaMinMax(FILE*, char*);
void zamena_strok(FILE*, char*);
void seek(FILE*, int);

class Matrix {
public:
	double** arr;
	int size1;
	int size2;
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& ob);
	~Matrix();
	void setValues();
	void showMatrix();
	void MinMax();
	void perestanovka();
};

void zapis(FILE*, Matrix&);
void chtenie(FILE*, Matrix&);

void lab1()
{
	setlocale(LC_ALL, "rus");
	FILE* file=NULL;
	char filename[30]="";
	bool menu = 1;
	int lever;
	cout << "Введите имя файла\n";
	cin >> filename;
	while (menu)
	{
		cout << "Меню:" << endl;
		cout << "1. Добавить матрицу" << endl;
		cout << "2. Просмотреть определенную матрицу" << endl;
		cout << "3. Просмотреть все матрицы" << endl;
		cout << "4. Удалить все матрицы" << endl;
		cout << "5. Поменять местами мин и макс значение в матрице" << endl;
		cout << "6. Поменять местами строки в матрице" << endl;
		cout << "0. Выход" << endl;
		cin >> lever;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> lever;
		}
		switch (lever)
		{
		case 1:
			add(file, filename);
			break;
		case 2:
			show1(file, filename);
			break;
		case 3:
			show_all(file, filename);
			break;
		case 4:
			delete_all(file, filename);
			break;
		case 5:
			zamenaMinMax(file, filename);
			break;
		case 6:
			zamena_strok(file, filename);
			break;
		case 0:
			menu = 0;
			break;
		default:
			cout << "Некорректный ввод. Повторите попытку\n";
		}
	}
}

Matrix::Matrix() : size1(0), size2(0), arr(NULL) {}

Matrix::Matrix(int size1, int size2)
{
	this->size1 = size1;
	this->size2 = size2;
	arr = NULL;
}

Matrix::Matrix(const Matrix& ob) {
	int i, j;
	size1 = ob.size1;
	size2 = ob.size2;
	arr = new double* [size1];
	for (i = 0; i < size1; i++)
		arr[i] = new double[size2];
	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
			arr[i][j] = ob.arr[i][j];
}

Matrix:: ~Matrix() {
	for (int i = 0; i < size1; i++)
		delete[] arr[i];
	delete[] arr;
}

void Matrix::setValues() {
	int i, j;
	if (size1 == 0 || size2 == 0) {
		cout << "Введите кол-во строк матрицы: " << endl;
		cin >> size1;
		while (cin.fail() || size1 < 1)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> size1;
		}
		cout << "Введите кол-во столбцов матрицы: " << endl;
		cin >> size2;
		while (cin.fail() || size2 < 1)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> size2;
		}
		arr = new double*[size1];
		for (i = 0; i < size1; i++)
			arr[i] = new double[size2];
	}
	cout << "Введите элементы в матрицу" << endl;
	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
		{
			cin >> arr[i][j];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "Некорректный ввод, повторите попытку." << endl;
				cin >> arr[i][j];
			}
		}
}

void Matrix::showMatrix() {
	cout << endl;
	int i, j;
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; j++)
			cout << arr[i][j]<< " ";
		cout << endl;
	}
	
}

void Matrix::MinMax() {
	int i_max = 0, i_min = 0, j_max = 0, j_min=0, i, j;
	double r;
	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
		{
			if (arr[i_max][j_max] < arr[i][j]) {
				i_max = i;
				j_max = j;
			}
			if (arr[i_min][j_min] > arr[i][j]) {
				i_min = i;
				j_min = j;
			}
		}
	r = arr[i_max][j_max];
	arr[i_max][j_max] = arr[i_min][j_min];
	arr[i_min][j_min] = r;
}

void Matrix::perestanovka() {
	double* r;
	int z = size1;
	if (size1 % 2 != 0)
		z--;
	for (int i = 0; i<z; i+=2)
	{
		r = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = r;
	}
}

void zapis(FILE* file, Matrix &m)
{
	int i, j;
	fwrite(&m.size1, sizeof(int), 1, file);
	fwrite(&m.size2, sizeof(int), 1, file);
	for (i = 0; i < m.size1; i++)
	{
		for (j = 0; j < m.size2; j++)
			fwrite(&m.arr[i][j], sizeof(double), 1, file);
	}
}

void chtenie(FILE* file, Matrix &m)
{
	int i, j;
	fread(&m.size1, sizeof(int), 1, file);
	fread(&m.size2, sizeof(int), 1, file);
	m.arr = new double* [m.size1];
	for (i = 0; i < m.size1; i++)
		m.arr[i] = new double[m.size2];
	for (i = 0; i < m.size1; i++)
	{
		for (j = 0; j < m.size2; j++)
			fread(&m.arr[i][j], sizeof(double), 1, file);
	}
}

void add(FILE* file, char* filename)
{
	file = fopen(filename, "ab");
	Matrix m;
	m.setValues();
	zapis(file, m);
	fclose(file);
}

void seek(FILE* file, int n)
{
	int size1, size2;
	for(int i=0;i<n-1;i++)
	{
		fread(&size1, sizeof(int), 1, file);
		fread(&size2, sizeof(int), 1, file);
		fseek(file, sizeof(double)*size1*size2, 1);
	}
	
}

void show1(FILE* file, char* filename)
{
	file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		return;
	}
	int n;
	cout << "Введите номер матрицы\n";
	cin >> n;
	seek(file, n);
	Matrix m;
	chtenie(file, m);
	m.showMatrix();
	fclose(file);
}

void show_all(FILE* file, char* filename)
{
	file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		return;
	}
	while (feof(file) == NULL)
	{
		Matrix m;
		chtenie(file, m);
		m.showMatrix();
	}
	fclose(file);
}

void delete_all(FILE* file, char* filename)
{
	file = fopen(filename, "wb");
	fclose(file);
	cout << "Удаление завершено\n";
}

void zamenaMinMax(FILE* file, char* filename)
{
	file = fopen(filename, "r+b");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		return;
	}
	int n;
	cout << "Введите номер матрицы\n";
	cin >> n;
	seek(file, n);
	Matrix m;
	chtenie(file, m);
	m.MinMax();
	fseek(file, 0, 0);
	seek(file, n);
	zapis(file, m);
	fclose(file);
}

void zamena_strok(FILE* file, char* filename)
{
	file = fopen(filename, "r+b");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		return;
	}
	int n;
	cout << "Введите номер матрицы\n";
	cin >> n;
	seek(file, n);
	Matrix m;
	chtenie(file, m);
	m.perestanovka();
	fseek(file, 0, 0);
	seek(file, n);
	zapis(file, m);
	fclose(file);
}