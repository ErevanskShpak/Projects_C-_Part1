#include <iostream>

using namespace std;

long long task(long long);

int main() //����������� ���������� ����� ������ ����
{
	setlocale(LC_ALL, "ru");
	cout << "������� �����\n";
	long long n;
	cin >> n;
	cout << "����� ������ ����: " << task(n);
	return 0;
}

long long task(long long n) {
	if (n < 10) {
		if (n % 2 == 0)
			return n;
		else
			return 0;
	}
	long long a = n % 10;
	if (a % 2 != 0)
		a = 0;
	return a + task(n / 10);
}