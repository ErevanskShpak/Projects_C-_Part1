#pragma once

#include "mainModule.h"
#include "vecHockModule.h"
#include <algorithm>

void sortHockByBest(vector<Hockey>&);                  //���������� ������� � ��������� �� ���-�� ��������������
bool partSortByBest(Hockey, Hockey);                  //������ ��� ���������� �������
void showByBest(vector<Hockey>);                       //����� ������� � ��������� � ������� �������� ��������������