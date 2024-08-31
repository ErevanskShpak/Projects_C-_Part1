#include <iostream>

using namespace std;

void quickSort(int*, int, int);
void selectionSort(int*, int);		
void insertSort(int*, int);
void bubbleSort(int*, int);

int main() {
	setlocale(LC_ALL, "ru");
	
	cout << "Введите размер массива\n";
	int n;
	cin >> n;

	int* arr = new int[n];
	cout << "Введите массива\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "Массив\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	//quickSort(arr, 0, n - 1);
	//selectionSort(arr, n);
	insertSort(arr, n);
	//bubbleSort(arr, n);
	cout << "\nМассив\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

void quickSort(int* arr, int first, int last) {
	int i = first, j = last;
	int mid = arr[(first + last) / 2];
	int temp;

	while (i <= j) {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (first < j) {
		quickSort(arr, first, j);
	}
	if (i < last) {
		quickSort(arr, i, last);
	}
}

void selectionSort(int* arr, int kolvo) {
	int i_min = 0, i = 0, j, temp;

	for (; i < kolvo - 1; i++) {
		i_min = i;
		for (j = i + 1; j < kolvo; j++) {
			if (arr[j] < arr[i_min]) {
				i_min = j;
			}
		}
		temp = arr[i_min];
		arr[i_min] = arr[i];
		arr[i] = temp;
	}
}

void insertSort(int* arr, int kolvo) {
	int i = 0, j, temp;

	for (; i < kolvo; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void bubbleSort(int* arr, int kolvo) {
	int i = 0, j, temp;

	for (; i < kolvo - 1; i++) {
		for (j = i + 1; j < kolvo; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}