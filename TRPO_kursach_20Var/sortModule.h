#pragma once

#include "mainModule.h"
#include "checkModule.h"
#include "vecHockModule.h"
#include <algorithm>

void sortHockByFio(vector<Hockey>&);         //���������� ������� � ��������� �� ��������
bool partSortByFio(Hockey, Hockey);         //����� ��� ���������� �� ��������
void sortHockByMatch(vector<Hockey>&); //���������� ������� � ��������� �� �������� �������� �����
bool partSortByMatch(Hockey, Hockey); //����� ��� ���������� �� �������� �����
void sortHockByPuck(vector<Hockey>&);       //���������� ������� � ��������� �� ������ ������
bool partSortByPuck(Hockey, Hockey);       //����� ��� ���������� �� ������ ������
void sortHock(vector<Hockey>&);              //���� ���������� ������� � ���������