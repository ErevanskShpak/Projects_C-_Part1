#include <iostream>

using namespace std;

int task(int*, int);

int main() { //����������� ���������� ��� � �������
	setlocale(LC_ALL, "ru");

	cout << "������� ������ ������� n: ";
	int n;
	cin >> n;

	cout << "������� ������\n";
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "������\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n��� �����: " << task(arr, n);

	return 0;
}

int task(int* arr, int n) {
	if (n == 1) {
		return arr[0];
	}

	int a = task(arr, n / 2);
	int b = task(arr + n / 2, n - n / 2);
	return a <= b ? a : b;
}