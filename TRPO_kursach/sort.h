#pragma once

#include "main.h"
#include "check.h"
#include "vecStudWork.h"
#include <algorithm>

void sortStudByFio(vector<Student>&);         //���������� ������� � ��������� �� ��������
bool partSortByFio(Student, Student);         //����� ��� ���������� �� ��������
void sortStudByAverageBall(vector<Student>&); //���������� ������� � ��������� �� �������� �������� �����
bool partSortByAverageBall(Student, Student); //����� ��� ���������� �� �������� �����
void sortStudByGroup(vector<Student>&);       //���������� ������� � ��������� �� ������ ������
bool partSortByGroup(Student, Student);       //����� ��� ���������� �� ������ ������
void sortStud(vector<Student>&);              //���� ���������� ������� � ���������