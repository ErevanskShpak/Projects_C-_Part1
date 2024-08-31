#include "poisk.h"

bool poiskAverageBall(vector<Student> vec_of_stud)
{
	cout << "������� ������� ����������� ������� ����: ";
	double ball_poisk = inputNumber(0, 10);
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].info.average_ball >= ball_poisk)
		{
			outputStud(vec_of_stud[i]);
			isFind = 1;
		}
	}
	if (isFind) //�������� �� ���������� ���� �� ������ ��������
		return 1;
	else
		return 0;
}

bool poiskFio(vector<Student> vec_of_stud)
{
	cout << "������� ������� ���: ";
	char fio_poisk[100];
	inputFio(fio_poisk);
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
		{
			outputStud(vec_of_stud[i]);
			return 1;
		}
	}
	return 0;
}

bool poiskGroup(vector<Student> vec_of_stud)
{
	cout << "������� ������� ����� ������: ";
	int group_poisk = inputNumber(100000, 999999);
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].group == group_poisk)
		{
			outputStud(vec_of_stud[i]);
			isFind = 1;
		}
	}
	if (isFind) //�������� �� ���������� ���� �� ������ ��������
		return 1;
	else
		return 0;
}

void poiskStud(vector<Student> vec_of_stud)
{
	cout << "------����� ������� � ���������------\n";
	if (!isEmpty(vec_of_stud))
		return;	
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "���� ������:\n";
		cout << "1. �� ���\n";
		cout << "2. �� ������������ �������� �����\n";
		cout << "3. �� ������ ������\n";
		cout << "0. �����\n";
		cout << "�������� ����� ����: ";
		lever = inputNumber(0, 3);
		switch (lever)
		{
		case 1:
			if (!poiskFio(vec_of_stud)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ��������� � ����� ���\n";
			break;
		case 2:
			if (!poiskAverageBall(vec_of_stud)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ��������� � ����� ������� ������\n";
			break;
		case 3:
			if (!poiskGroup(vec_of_stud)) //�������� �� ���������� ���� �� ������ ��������
				cout << "��� ��������� � ����� ������� ������\n";
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}