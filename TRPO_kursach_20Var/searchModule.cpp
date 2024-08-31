#include "searchModule.h"

bool searchMatch(vector<Hockey> vecHock)
{
	cout << "������� ������� ����������� ���-�� ��������� ������: ";
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
	if (isExist) //�������� �� ���������� ���� �� ������ ��������
		return 1;
	else
		return 0;
}

bool searchFio(vector<Hockey> vecHock)
{
	cout << "������� ������� ���: ";
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
	cout << "������� ������� ����������� ����� ����������� ����: ";
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
	if (isExist) //�������� �� ���������� ���� �� ������ ��������
		return 1;
	else
		return 0;
}

void searchHock(vector<Hockey> vecHock)
{
	cout << "------����� ������� � ����������------\n";
	if (!isEmpty(vecHock))
		return;	
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "���� ������:\n";
		cout << "1. �� ���\n";
		cout << "2. �� ������������ ���������� ��������� ������\n";
		cout << "3. �� ������������ ����� ��������� ������\n";
		cout << "0. �����\n";
		cout << "�������� ����� ����: ";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 1:
			if (!searchFio(vecHock)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ���������� � ����� ���\n";
			break;
		case 2:
			if (!searchMatch(vecHock)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ���������� � ����� ���-��� ��������� ������\n";
			break;
		case 3:
			if (!searchPuck(vecHock)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ���������� � ����� ������ ����������� ����\n";
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}