#include "vecStudWork.h"

Student inputStud()
{
	Student stud;
	cout << "������� ����� ������: ";
	stud.group = inputNumber(100000, 999999);
	cout << "������� ��� ��������: ";
	inputFio(stud.fio);
	int i = 0;
	cout << "������� ������ �������� �� ���� ���������\n";
	for (; i < 5; i++)
	{
		cout << "������� ������ ";
		switch (i)
		{
		case 0:
			cout << "�� ����������: ";
			break;
		case 1:
			cout << "�� ������: ";
			break;
		case 2:
			cout << "�� ����: ";
			break;
		case 3:
			cout << "�� ����: ";
			break;
		case 4:
			cout << "�� ���: ";
			break;
		}
		stud.info.marks[i] = inputNumber(0, 10);
		stud.info.average_ball += stud.info.marks[i];
	}
	stud.info.average_ball /= 5.;
	cout << "������� �������� � ������� ��������\n" << "���� ������� ������� �����, ������� 1, ����� ������� 0\n";
	for (i = 0; i < 5; i++)
	{
		cout << "������� ����� ";
		switch (i)
		{
		case 0:
			cout << "�� �����������: ";
			break;
		case 1:
			cout << "�� ������: ";
			break;
		case 2:
			cout << "�� ��: ";
			break;
		case 3:
			cout << "�� ���: ";
			break;
		case 4:
			cout << "�� ���: ";
			break;
		}
		stud.info.zacheti[i] = inputNumber(0, 1);
	}
		getDolg(stud);
	return stud;
}

void getDolg(Student& stud)
{
	for (int i = 0; i < 5; i++)
		if (stud.info.zacheti[i] == 0)
			stud.info.dolg++;
}

//void outputStud(Student stud)
//{
//	cout << "\n����� ������: " << stud.group;
//	cout << "\n���: " << stud.fio;
//	cout << "\n������\n";
//	int i = 0;
//	cout << "����������: " << stud.info.marks[i++];
//	cout << "   ������: " << stud.info.marks[i++];
//	cout << "   ����: " << stud.info.marks[i++];
//	cout << "   ����: " << stud.info.marks[i++];
//	cout << "   ���: " << stud.info.marks[i];
//	cout << "\n������� ����: " << stud.info.average_ball;
//	cout << "\n�������� � �������\n";
//	i = 0;
//	cout << "�����������: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ������: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ��: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ���: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ���: " << isZachet(stud.info.zacheti[i]) << endl;
//}

void outputStud(Student stud)
{
	cout << "|" << setw(14) << stud.group;
	cout << "|" << setw(29) << stud.fio;
	int i = 0;
	cout << "|" << setw(12) << stud.info.marks[i++];
	cout << "|" << setw(8) << stud.info.marks[i++];
	cout << "|" << setw(6) << stud.info.marks[i++];
	cout << "|" << setw(6) << stud.info.marks[i++];
	cout << "|" << setw(5) << stud.info.marks[i];
	cout << "|" << setw(14) << stud.info.average_ball;
	i = 0;
	cout << "|" << setw(13) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i]) << "|";
}

void generateStudVec(vector<Student>& vec_of_stud)
{
	vec_of_stud.reserve(getCountOfStudInFile());
}

void deleteStudVec(vector<Student>& vec_of_stud)
{
	vector<Student>().swap(vec_of_stud);
}

void addStudInVec(vector<Student>& vec_of_stud)
{
	cout << "------���������� ������ � ��������------\n";
	Student stud = inputStud();
	vec_of_stud.push_back(stud);
	cout << "���������� ���������\n";
	addFileStud(stud);
}

void delStudFromVec(vector<Student>& vec_of_stud)
{
	cout << "------�������� ������ � ��������------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "������� ��� ��������, ������ � ������� ���� �������: ";
	int number_of_deleted_stud = poiskFioForDelAndRed(vec_of_stud);
	if (number_of_deleted_stud == -1) //�������� �� ���������� ��������
		return;
	cout << "�� �������, ��� ������ ������� ���������� � ��������?\n";
	cout << "1. ��\n";
	cout << "0. ���\n";
	cout << "�����: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) //������������� �������� ������ � ��������
	{
		vector<Student>::iterator itErase = vec_of_stud.begin();
		vec_of_stud.erase(itErase + number_of_deleted_stud);
		cout << "�������� ���������\n";
		writeFileStud(vec_of_stud);
	}
}

void redactStudFromVec(vector<Student>& vec_of_stud)
{
	cout << "------�������������� ������ � ��������------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "������� ��� ��������, ���������� � ������� ���� ���������������: ";
	int number_of_redact_stud = poiskFioForDelAndRed(vec_of_stud);
	if (number_of_redact_stud == -1) //�������� �� ���������� ��������
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "��� ���� ���������������?\n";
		cout << "1. ����� ������ ��������\n";
		cout << "2. ��� ��������\n";
		cout << "3. ������ ��������\n";
		cout << "4. �������� � ������� ��������\n";
		cout << "0. ����� �� ��������������\n";
		cout << "�����: ";
		lever = inputNumber(0, 4);
		switch (lever)
		{
		case 1:
			cout << "������� ����� ����� ������: ";
			vec_of_stud[number_of_redact_stud].group = inputNumber(100000, 999999);
			isUsed = 1;
			break;
		case 2:
			cout << "������� ����� ���: ";
			inputFio(vec_of_stud[number_of_redact_stud].fio);
			isUsed = 1;
			break;
		case 3:
			vec_of_stud[number_of_redact_stud].info.average_ball = 0;
			cout << "������� ����� ������ �������� �� ���� ���������\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "������� ������ ";
				switch (i)
				{
				case 0:
					cout << "�� ����������: ";
					break;
				case 1:
					cout << "�� ������: ";
					break;
				case 2:
					cout << "�� ����: ";
					break;
				case 3:
					cout << "�� ����: ";
					break;
				case 4:
					cout << "�� ���: ";
					break;
				}
				vec_of_stud[number_of_redact_stud].info.marks[i] = inputNumber(0, 10);
				vec_of_stud[number_of_redact_stud].info.average_ball += vec_of_stud[number_of_redact_stud].info.marks[i];
			}
			vec_of_stud[number_of_redact_stud].info.average_ball /= 5.;
			isUsed = 1;
			break;
		case 4:
			vec_of_stud[number_of_redact_stud].info.dolg = 0;
			cout << "������� ����� �������� � ������� ��������\n" << "���� ������� ������� �����, ������� 1, ����� ������� 0\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "������� ����� ";
				switch (i)
				{
				case 0:
					cout << "�� �����������: ";
					break;
				case 1:
					cout << "�� ������: ";
					break;
				case 2:
					cout << "�� ��: ";
					break;
				case 3:
					cout << "�� ���: ";
					break;
				case 4:
					cout << "�� ���: ";
					break;
				}
				vec_of_stud[number_of_redact_stud].info.zacheti[i] = inputNumber(0, 1);
			}
			getDolg(vec_of_stud[number_of_redact_stud]);
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
		writeFileStud(vec_of_stud);
	}
}

int poiskFioForDelAndRed(vector<Student> vec_of_stud)
{
	char fio_poisk[100];
	inputFio(fio_poisk);
	int number_poisk = 0;
	int kolvo_stud = vec_of_stud.size();
	for (int i = 0; i < kolvo_stud; i++)
	{
		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
			return number_poisk;
		number_poisk++;
	}
	cout << "��� �������� � ����� ���\n";
	return -1;
}

//int poiskFioForDelAndRed(vector<Student> vec_of_stud)
//{
//	char fio_poisk[100];
//	inputFio(fio_poisk);
//	int number_poisk = 0;
//	int kolvo_stud = vec_of_stud.size();
//	for (int i = 0; i < kolvo_stud; i++)
//	{
//		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
//			break;
//		number_poisk++;
//	}
//	if (number_poisk == kolvo_stud)
//	{
//		cout << "��� �������� � ����� ���\n";
//		number_poisk = -1;
//	}
//	return number_poisk;
//}

void showStudVec(vector<Student> vec_of_stud)
{
	cout << "------�������� ���� ������� ���������------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|              |                             |                  ������                 |              |               �������� � �������                |\n";
	cout << "| ����� ������ |             ���             |-----------------------------------------| ������� ���� |-------------------------------------------------|\n";
	cout << "|              |                             | ���������� | ������ | ���� | ���� | ��� |              | ����������� | ������ |   ��   |   ���  |   ���  |\n";
	cout << "|" << setw(8) << "�����" << setw(4) << "|\n";
	int kolvo_stud = vec_of_stud.size();
	for (int i = 0; i < kolvo_stud; i++)
	{
		cout << "|--------------|-----------------------------|------------|--------|------|------|-----|--------------|-------------|--------|--------|--------|--------|\n";
		outputStud(vec_of_stud[i]);
		cout << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}