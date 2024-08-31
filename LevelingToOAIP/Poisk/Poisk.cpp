#include <iostream>

using namespace std;

int binPoisk(int*, int, int);
int interPoisk(int*, int, int);

int main() {
	setlocale(LC_ALL, "ru");

	cout << "������� ������ �������\n";
	int n;
	cin >> n;

	int* arr = new int[n];
	cout << "������� �������\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "������\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n������� ����\n";
	int key;
	cin >> key;

	cout << "�����: " << binPoisk(arr, n, key) + 1;
	//cout << "\n�����: " << interPoisk(arr, n, key) + 1;

	return 0;
}

int binPoisk(int* arr, int kolvo, int key) {
	int i = 0, j = kolvo - 1, mid;

	while (i < j) {
		mid = (i + j) / 2;
		if (key > arr[mid]) {
			i = mid + 1;
		}
		else {
			j = mid;
		}
	}

	if (arr[i] == key) {
		return i;
	}
	else {
		return -1;
	}
}

int interPoisk(int* arr, int kolvo, int key) {
	int i = 0, j = kolvo - 1, mid;

	while (i < j) {
		if (arr[i] == arr[j]) {
			if (arr[i] == key) {
				return i;
			}
			else {
				return -1;
			}
		}
		mid = i + (j - i) * (key - arr[i]) / (arr[j] - arr[i]);
		if (arr[mid] == key) {
			return mid;
		}
		else {
			if (key > arr[mid]) {
				i = mid + 1;
			}
			else {
				j = mid - 1;
			}
		}
	}
	return -1;
}