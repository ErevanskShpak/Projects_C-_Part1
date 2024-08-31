#pragma once

#include "mainModule.h"
#include <fstream>

void createFileOfHock();                 //�������� ����� � �������� � ��������� ��� ��� ����������
int getAmountOfHockInFile();            //���������� ���-�� ������� � ��������� � �����
bool readFileOfHock(vector <Hockey>&);  //��������� �� ����� ������� � ���������
void writeFileOfHock(vector <Hockey>&); //��������� ���� ������� � ��������� � ����(������������ ��� ��������/�������������� ����������� �����)
void addFileOfHock(Hockey);             //���������� ����� ������ � �������� � ����
void createFileOfUser();                 //�������� ����� � ���������� ��� ��� ����������
int getAmountOfUserInFile();            //���������� ���-�� ��������� � �����
bool readFileOfUser(vector<User>&);      //��������� �� ����� ���������
void writeFileOfUser(vector<User>&);     //��������� ���� ��������� � ����(������������ ��� ��������/�������������� ����������� �����)
void addFileOfUser(User);                //���������� ������ �������� � ����