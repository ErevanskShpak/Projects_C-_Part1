#include <iostream>

using namespace std;

long long task(long long);

int main() //����������� ���������� ���� ����� � �����
{
	setlocale(LC_ALL, "ru");
	cout << "������� �����\n";
	long long n;
	cin >> n;
	cout << "���� �����: " << task(n);
	return 0;
}

long long task(long long n) {
	if (n < 10)
		return n;
	long long a = task(n / 10);
	long long b = n % 10;
	return a > b ? a : b;
}