#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() { //бинарный файл
	setlocale(LC_ALL, "ru");

	FILE* file = NULL;

	file=fopen("file", "wb");
	cout << "¬ведите 8 чисел дл€ записи в файл\n";
	double info;
	for (int i = 0; i < 8; i++) {
		cin >> info;
		fwrite(&info, sizeof(double), 1, file);
	}
	fclose(file);

	file = fopen("file", "rb");
	cout << "„исла из файла\n";
	while (fread(&info, sizeof(double), 1, file)) {
		cout << info << " ";
	}
	fclose(file);

	return 0;
}