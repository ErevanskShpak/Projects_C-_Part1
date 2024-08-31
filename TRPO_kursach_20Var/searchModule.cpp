#include "searchModule.h"

bool searchMatch(vector<Hockey> vecHock)
{
	cout << "Введите искомое минимальное кол-во сыгранных матчей: ";
	double matchSearch = inputNumber(0, 2000);
	bool isExist = 0;
	for (int i = 0; i < vecHock.size(); i++)
	{
		if (vecHock[i].info.match >= matchSearch)
		{
			outputHock(vecHock[i]);
			isExist = 1;
		}
	}
	if (isExist) //проверка на нахождение хотя бы одного студента
		return 1;
	else
		return 0;
}

bool searchFio(vector<Hockey> vecHock)
{
	cout << "Введите искомое ФИО: ";
	char fioSearch[100];
	inputFio(fioSearch);
	for (int i = 0; i < vecHock.size(); i++)
	{
		if (!strcmp(vecHock[i].fio, fioSearch))
		{
			outputHock(vecHock[i]);
			return 1;
		}
	}
	return 0;
}

bool searchPuck(vector<Hockey> vecHock)
{
	cout << "Введите искомое минимальное число заброшенных шайб: ";
	int puckSearch = inputNumber(0, 1000);
	bool isExist = 0;
	for (int i = 0; i < vecHock.size(); i++)
	{
		if (vecHock[i].info.puck >= puckSearch)
		{
			outputHock(vecHock[i]);
			isExist = 1;
		}
	}
	if (isExist) //проверка на нахождение хотя бы одного студента
		return 1;
	else
		return 0;
}

void searchHock(vector<Hockey> vecHock)
{
	cout << "------Поиск записей о хоккеистах------\n";
	if (!isEmpty(vecHock))
		return;	
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Меню поиска:\n";
		cout << "1. По ФИО\n";
		cout << "2. По минимальному количеству сыгранных матчей\n";
		cout << "3. По минимальному числу сыгранных матчей\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 1:
			if (!searchFio(vecHock)) //проверка на нахождение хотя бы одного студента
				cout << "Нет хоккеистов с такой ФИО\n";
			break;
		case 2:
			if (!searchMatch(vecHock)) //проверка на нахождение хотя бы одного студента
				cout << "Нет хоккеистов с таким кол-вом сыгранных матчей\n";
			break;
		case 3:
			if (!searchPuck(vecHock)) //проверка на нахождение хотя бы одного студента
				cout << "Нет хоккеистов с таким числом заброшенных шайб\n";
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}