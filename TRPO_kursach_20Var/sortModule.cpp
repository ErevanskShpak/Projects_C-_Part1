#include "sortModule.h"

void sortHockByFio(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByFio);
	cout << "Сортировка завершена\n\n";
	showVecOfHock(vecHock);
}

bool partSortByFio(Hockey hockA, Hockey hockB)
{
	string a = hockA.fio;
	string b = hockB.fio;
	return a < b;
}

void sortHockByMatch(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByMatch);
	cout << "Сортировка завершена\n\n";
	showVecOfHock(vecHock);
}

bool partSortByMatch(Hockey hockA, Hockey hockB)
{
	return hockA.info.match > hockB.info.match;
}

void sortHockByPuck(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByPuck);
	cout << "Сортировка завершена\n\n";
	showVecOfHock(vecHock);
}

bool partSortByPuck(Hockey hockA, Hockey hockB)
{
	return hockA.info.puck > hockB.info.puck;
}

void sortHock(vector<Hockey>& vecHock)
{
	cout << "------Сортировка записей о хоккеистах------\n";
	if (!isEmpty(vecHock))
		return;
	int choice = 0;
	bool menu = 1;
	while (menu)
	{
		cout << "Меню сортировки:\n";
		cout << "1. По алфавиту\n";
		cout << "2. По убыванию кол-ва сыгранных матчей\n";
		cout << "3. По убыванию числа заброшенных шайб\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 1:
			sortHockByFio(vecHock);
			break;
		case 2:
			sortHockByMatch(vecHock);
			break;
		case 3:
			sortHockByPuck(vecHock);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}