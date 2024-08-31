#pragma once

#include "main.h"
#include "check.h"
#include "vecStudWork.h"
#include <algorithm>

void sortStudByDolg(vector<Student>&);                  //���������� ������� � ��������� �� ���-�� ��������������
bool partSortByDolg(Student, Student);                  //������ ��� ���������� �������
void showByDolg(vector<Student>);                       //����� ������� � ��������� � ������� �������� ��������������
void showByAverageBall(vector<Student>);                //����� �������� ����� ��������� ������ � ������ � �����
double poiskGroupForAverageBall(vector<Student>, int&); //����� ������� � ��������� ������������ ������ ��� ���������� �������� �����
void outputStudAverageBall(Student);                    //����� ��� �������� � ��� �������� �����