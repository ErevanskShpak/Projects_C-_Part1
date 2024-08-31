#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char str[255] = "";
	int i, k{}, max{}, number{}, place{}, max_number{};
	cout << "Введите строку" << endl;
	cin.getline(str, 255);
	strcat_s(str, " ");
	for (i = 0;i<strlen(str);i++)
	{
		if (str[i] != ' ') k++;
		else if (k)
		{
			number++;
			if (k > max)
			{
				max = k;
				max_number = number;
				place = i - k + 1;
			}
			k = 0;
		}
	}
	cout << "Порядковый номер слова = " << max_number << " Номер позиции начала слова = "<<place;*/
	return 0;
}