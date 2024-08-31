#include <iostream>

using namespace std;

long long task(long long);

int main() //рекурсивное нахождение макс цифры в числе
{
	setlocale(LC_ALL, "ru");
	cout << "Введите число\n";
	long long n;
	cin >> n;
	cout << "Макс цифра: " << task(n);
	return 0;
}

long long task(long long n) {
	if (n < 10)
		return n;
	long long a = task(n / 10);
	long long b = n % 10;
	return a > b ? a : b;
}