#include <iostream>

using namespace std;

int fib(int);

int main() //�������� ��������
{
	setlocale(LC_ALL, "ru");

	cout << "������� ������� �������� n-�� �����\nn = ";
	int n;
	cin >> n;
	cout << fib(n);

	return 0;
}

int fib(int n) {
	if (n == 0)
		return 0;

	if (n == 1 || n == 2)
		return 1;

	return fib(n - 1) + fib(n - 2);
}