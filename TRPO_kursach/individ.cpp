#include "individ.h"

void sortStudByDolg(vector<Student>& vec_of_stud)
{
	sort(vec_of_stud.begin(), vec_of_stud.end(), partSortByDolg);
}

bool partSortByDolg(Student student_a, Student student_b)
{
	return student_a.info.dolg > student_b.info.dolg;
}

void showByDolg(vector<Student> vec_of_stud)
{
	cout << "------�������� ������� � ��������� � ������� �������� ��������������------\n";
	if (!isEmpty(vec_of_stud)) //�������� �� ������ ���� ������� � ���������
		return;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|              |                             |                  ������                 |              |               �������� � �������                |                           |\n";
	cout << "| ����� ������ |             ���             |-----------------------------------------| ������� ���� |-------------------------------------------------| ���������� �������������� |\n";
	cout << "|              |                             | ���������� | ������ | ���� | ���� | ��� |              | ����������� | ������ |   ��   |   ���  |   ���  |                           |\n";
	sortStudByDolg(vec_of_stud);
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		cout << "|--------------|-----------------------------|------------|--------|------|------|-----|--------------|-------------|--------|--------|--------|--------|---------------------------|\n";
		outputStud(vec_of_stud[i]);
		cout << setw(27) << vec_of_stud[i].info.dolg << "|\n";
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void showByAverageBall(vector<Student> vec_of_stud)
{
	cout << "------�������� �������� ����� ��������� ������������ ������------\n";
	if (!isEmpty(vec_of_stud)) //�������� �� ������ ���� ������� � ���������
		return;
	int kolvo_in_group = 0;
	double general_average_ball = poiskGroupForAverageBall(vec_of_stud, kolvo_in_group);
	if (general_average_ball)
		cout << "\n\n������� ���� ���� ������: " << general_average_ball / kolvo_in_group << endl;
}

double poiskGroupForAverageBall(vector<Student> vec_of_stud, int& kolvo_in_group)
{
	cout << "������� ������� ����� ������: ";
	int group_poisk = inputNumber(100000, 999999);
	double general_average_ball = 0;
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].group == group_poisk)
		{
			outputStudAverageBall(vec_of_stud[i]);
			isFind = 1;
			general_average_ball += vec_of_stud[i].info.average_ball;
			kolvo_in_group++;
		}
	}
	if (!isFind)  //�������� �� ������������� ���� �� ����� ��������
		cout << "��� ��������� � ����� ������� ������\n";
	return general_average_ball;
}

void outputStudAverageBall(Student stud)
{
	cout << "\n\n���: " << stud.fio;
	cout << "\n������� ����: " << stud.info.average_ball;
}