#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <stdio.h>

using namespace std;

class Matrix {

	int** arr;
	int rows;
	int cols;

public:

	Matrix() : arr(NULL), rows(0), cols(0) {}

	Matrix(int rows, int cols) : arr(new int* [rows]), rows(rows), cols(cols) {
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
	}

	Matrix(const Matrix& ob) : arr(NULL), rows(0), cols(0) {
		rows = ob.rows;
		cols = ob.cols;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				arr[i][j] = ob.arr[i][j];
			}
		}
	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	int getRows() {
		return rows;
	}

	int getCols() {
		return cols;
	}

	void getMatrix() {
		cout << endl;
		int i, j;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
	}

	void setElement(int i, int j, int value) {
		arr[i][j] = value;
	}

	bool operator==(const Matrix&);
	Matrix operator!();
	Matrix operator*(int);

	friend ostream& operator<<(ostream& os, const Matrix& matrix) {
		for (int i = 0; i < matrix.rows; i++) {
			for (int j = 0; j < matrix.cols; j++) {
				os << matrix.arr[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, Matrix& matrix) {
		for (int i = 0; i < matrix.rows; i++) {
			for (int j = 0; j < matrix.cols; j++) {
				is >> matrix.arr[i][j];
			}
		}
		return is;
	}

	friend void add(FILE*, char*);
	friend void show1(FILE*, char*);
	friend void show_all(FILE*, char*);
	friend void delete_all(FILE*, char*);
	friend void seek(FILE*, int);
	friend void zapis(FILE*, Matrix&);
	friend void chtenie(FILE*, Matrix&);
	friend void trans(FILE* file, char* filename);
	friend void scalar(FILE* file, char* filename);
	friend void sravn(FILE* file, char* filename);
};

bool Matrix:: operator==(const Matrix& ob) {
	if (rows != ob.rows || cols != ob.cols) {
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] != ob.arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix:: operator!() {
	Matrix transposed(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposed.setElement(j, i, arr[i][j]);
		}
	}
	return transposed;
}

Matrix Matrix:: operator*(int scalar) {
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result.setElement(i, j, arr[i][j] * scalar);
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* file = NULL;
	char filename[30] = "";
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
		cout << "5. Транспонировать матрицу" << endl;
		cout << "6. Умножить матрицу" << endl;
		cout << "7. Сравнить матрицы" << endl;
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
			trans(file, filename);
			break;
		case 6:
			scalar(file, filename);
			break;
		case 7:
			sravn(file, filename);
			break;
		case 0:
			menu = 0;
			break;
		default:
			cout << "Некорректный ввод. Повторите попытку\n";
		}
	}
	return 0;
}

void zapis(FILE* file, Matrix& m)
{
	int i, j;
	fwrite(&m.rows, sizeof(int), 1, file);
	fwrite(&m.cols, sizeof(int), 1, file);
	for (i = 0; i < m.rows; i++)
	{
		for (j = 0; j < m.cols; j++)
			fwrite(&m.arr[i][j], sizeof(int), 1, file);
	}
}

void chtenie(FILE* file, Matrix& m)
{
	int i, j;
	fread(&m.rows, sizeof(int), 1, file);
	fread(&m.cols, sizeof(int), 1, file);
	m.arr = new int* [m.rows];
	for (i = 0; i < m.rows; i++)
		m.arr[i] = new int[m.cols];
	for (i = 0; i < m.rows; i++)
	{
		for (j = 0; j < m.cols; j++)
			fread(&m.arr[i][j], sizeof(int), 1, file);
	}
}

void add(FILE* file, char* filename)
{
	int rows = 0, cols = 0;
	file = fopen(filename, "ab");
	cout << "Введите кол-во строк и столбцов матрицы\n";
	cin >> rows;
	cin >> cols;
	Matrix m(rows, cols);
	cout << "Введите матрицу\n";
	cin >> m;
	zapis(file, m);
	fclose(file);
}

void seek(FILE* file, int n)
{
	int rows, cols;
	for (int i = 0; i < n - 1; i++)
	{
		fread(&rows, sizeof(int), 1, file);
		fread(&cols, sizeof(int), 1, file);
		fseek(file, sizeof(int) * rows * cols, 1);
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
	cout << m;
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
	cout << "\tМатрицы\n";
	while (feof(file) == NULL)
	{
		Matrix m;
		chtenie(file, m);
		cout << m << endl;
	}
	fclose(file);
}

void delete_all(FILE* file, char* filename)
{
	file = fopen(filename, "wb");
	fclose(file);
	cout << "Удаление завершено\n";
}

void trans(FILE* file, char* filename)
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
	Matrix r = !m;
	fseek(file, 0, 0);
	seek(file, n);
	zapis(file, r);
	fclose(file);
}

void scalar(FILE* file, char* filename)
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
	cout << "На что умножить матрицу?\n";
	int chislo;
	cin >> chislo;
	Matrix r = m * chislo;
	fseek(file, 0, 0);
	seek(file, n);
	zapis(file, r);
	fclose(file);
}

void sravn(FILE* file, char* filename)
{
	file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		return;
	}
	int n;
	cout << "Введите номер первой матрицы\n";
	cin >> n;
	seek(file, n);
	Matrix m;
	chtenie(file, m);
	fseek(file, 0, 0);
	cout << "Введите номер второй матрицы\n";
	cin >> n;
	seek(file, n);
	Matrix r;
	chtenie(file, r);
	if (m == r)
	{
		cout << "Равны\n";
	}
	else
		cout << "Не равны\n";
	fclose(file);
}