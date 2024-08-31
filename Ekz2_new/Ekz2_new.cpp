#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void func(char[], int*, int*);

int main()
{
	setlocale(LC_ALL, "rus");
	char str[255] = "";
	int kolvo_3=0, number_slovo=0;
	cout << "Введите строку\n";
	cin.getline(str, 255);
	func(str, &number_slovo, &kolvo_3);
	cout << "Количество слов с 3 и больше букв = " << kolvo_3 << endl;
	if (number_slovo)
		cout << "Порядковый номер слова = " << number_slovo;
	else
		cout << "Нет слов, уловлетворяющих условию";
	return 0;
}

void func(char str[], int* number_slovo, int* kolvo_3)
{
	int i, kolvo=0, number=0, bol3=0;
	bool bol1=0, bol2=1;
	if (str[strlen(str) - 1] != ' ')
		strcat(str, " ");
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			if (bol3 < 2)
			{
				if (str[i] == 'r') bol1 = 1;
				if (str[i] == 'a') bol2 = 0;
			}
			cout << str[i];
			kolvo++;
		}
		else
			if (kolvo)
			{
				cout << endl;
				number++;
				if (kolvo >= 3) *kolvo_3+=1;
				kolvo = 0;
				if (bol3 < 2)
				{
					if (bol1 == 1 && bol2 == 1)
					{
						if (bol3 == 1)
							*number_slovo = number;
						bol3++;
					}
					bol1 = 0;
					bol2 = 1;
				}
			}
	}
}