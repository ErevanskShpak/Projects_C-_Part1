#include "sortModule.h"

void sortHockByFio(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByFio);
	cout << "���������� ���������\n\n";
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
	cout << "���������� ���������\n\n";
	showVecOfHock(vecHock);
}

bool partSortByMatch(Hockey hockA, Hockey hockB)
{
	return hockA.info.match > hockB.info.match;
}

void sortHockByPuck(vector<Hockey>& vecHock)
{
	sort(vecHock.begin(), vecHock.end(), partSortByPuck);
	cout << "���������� ���������\n\n";
	showVecOfHock(vecHock);
}

bool partSortByPuck(Hockey hockA, Hockey hockB)
{
	return hockA.info.puck > hockB.info.puck;
}

void sortHock(vector<Hockey>& vecHock)
{
	cout << "------���������� ������� � ����������------\n";
	if (!isEmpty(vecHock))
		return;
	int choice = 0;
	bool menu = 1;
	while (menu)
	{
		cout << "���� ����������:\n";
		cout << "1. �� ��������\n";
		cout << "2. �� �������� ���-�� ��������� ������\n";
		cout << "3. �� �������� ����� ����������� ����\n";
		cout << "0. �����\n";
		cout << "�������� ����� ����: ";
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