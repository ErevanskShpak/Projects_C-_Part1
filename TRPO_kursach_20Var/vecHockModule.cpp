#include "vecHockModule.h"

Hockey inputHock()
{
	Hockey hock;
	cout << "������� ��� ���������: ";
	inputFio(hock.fio);
	cout << "������� ���� �������� ���������: ";
	inputDate(hock.date);
	cout << "������� ���������� ��������� ������ ���������: ";
	hock.info.match = inputNumber(0, 2000);
	cout << "������� ����� ����������� ���� ���������: ";
	hock.info.puck = inputNumber(0, 1000);
	cout << "������� ���������� ������� ������� ���������: ";
	hock.info.assist = inputNumber(0, 2000);
	cout << "������� ���������� �������� ����� ���������: ";
	hock.info.time = inputNumber(0, 10000);
	return hock;
}

void outputHock(Hockey hock)
{
	cout << "|-----------------------------|-----------|-----------------|-------------------|------------------|-----------------|\n";
	cout << "|" << setw(29) << hock.fio;
	cout << "|" << setw(11) << hock.date;
	cout << "|" << setw(17) << hock.info.match;
	cout << "|" << setw(19) << hock.info.puck;
	cout << "|" << setw(18) << hock.info.assist;
	cout << "|" << setw(17) << hock.info.time << "|\n";
}

void generateVecOfHock(vector<Hockey>& vecHock)
{
	vecHock.reserve(getAmountOfHockInFile());
}

void deleteVecOfHock(vector<Hockey>& vecHock)
{
	vector<Hockey>().swap(vecHock);
}

void showVecOfHock(vector<Hockey> vecHock)
{
	cout << "------�������� ���� ������� ����������------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "|             ���             |    ����   | ��������� ����� | ����������� ����� | ������� �������� | �������� ������ |\n";
	int amountHock = vecHock.size();
	for (int i = 0; i < amountHock; i++)
		outputHock(vecHock[i]);
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
}

void addHockInVec(vector<Hockey>& vecHock)
{
	cout << "------���������� ������ � ���������------\n";
	Hockey hock = inputHock();
	vecHock.push_back(hock);
	cout << "���������� ���������\n";
	addFileOfHock(hock);
}

int searchHockForDeleteAndEdit(vector<Hockey> vecHock)
{
	char fioSearch[100];
	inputFio(fioSearch);
	int numberSearch = 0;
	int amountHock = vecHock.size();
	for (int i = 0; i < amountHock; i++)
	{
		if (!strcmp(vecHock[i].fio, fioSearch))
			return numberSearch;
		numberSearch++;
	}
	cout << "��� ��������� � ����� ���\n";
	return -1;
}

void deleteHockFromVec(vector<Hockey>& vecHock)
{
	cout << "------�������� ������ � ���������------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "������� ��� ���������, ���������� � ������� ���� �������: ";
	int numberDeleteHock = searchHockForDeleteAndEdit(vecHock);
	if (numberDeleteHock == -1) //�������� �� ���������� ��������
		return;
	cout << "�� �������, ��� ������ ������� ���������� � ���������?\n";
	cout << "1. ��\n";
	cout << "0. ���\n";
	cout << "�����: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) //������������� �������� ������ � ��������
	{
		vector<Hockey>::iterator itErase = vecHock.begin();
		vecHock.erase(itErase + numberDeleteHock);
		cout << "�������� ���������\n";
		writeFileOfHock(vecHock);
	}
}

void editHockFromVec(vector<Hockey>& vecHock)
{
	cout << "------�������������� ������ � ���������------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "������� ��� ���������, ������ � ������� ���� ���������������: ";
	int numberEditHock = searchHockForDeleteAndEdit(vecHock);
	if (numberEditHock == -1) //�������� �� ���������� ��������
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "��� ��������� ���������������?\n";
		cout << "1. ��� ���������\n";
		cout << "2. ���� �������� ���������\n";
		cout << "3. ���-�� ��������� ������\n";
		cout << "4. ����� ����������� ����\n";
		cout << "5. ���-�� ������� �������\n";
		cout << "6. ���-�� �������� �����\n";
		cout << "0. ����� �� ��������������\n";
		cout << "�����: ";
		lever = inputNumber(0, 4);
		switch (lever)
		{
		case 1:
			cout << "������� ����� ���: ";
			inputFio(vecHock[numberEditHock].fio);
			isUsed = 1;
			break;
		case 2:
			cout << "������� ����� ���� ��������: ";
			inputDate(vecHock[numberEditHock].date);
			isUsed = 1;
			break;
		case 3:
			cout << "������� ����� ���-�� ��������� ������: ";
			vecHock[numberEditHock].info.match = inputNumber(0, 2000);
			isUsed = 1;
			break;
		case 4:
			cout << "������� ����� ����� ����������� ����: ";
			vecHock[numberEditHock].info.puck = inputNumber(0, 1000);
			isUsed = 1;
			break;
		case 5:
			cout << "������� ����� ���-�� ������� �������: ";
			vecHock[numberEditHock].info.assist = inputNumber(0, 2000);
			isUsed = 1;
			break;
		case 6:
			cout << "������� ����� ���-�� �������� �����: ";
			vecHock[numberEditHock].info.time = inputNumber(0, 10000);
			isUsed = 1;
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	if (isUsed) //��������, ���� �� ��������� �������������� ����-����
	{
		cout << "�������������� ���������\n";
		writeFileOfHock(vecHock);
	}
}