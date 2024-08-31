#pragma once

#include "main.h"
#include <fstream>

int getCountOfStudInFile();            //���������� ���-�� ������� � ��������� � �����
bool readFileStud(vector <Student>&);  //��������� �� ����� ������� � ���������
void writeFileStud(vector <Student>&); //��������� ���� ������� � ��������� � ����(������������ ��� ��������/�������������� ����������� �����)
void addFileStud(Student);             //���������� ����� ������ � �������� � ����
void createFileStud();                 //�������� ����� � �������� � ��������� ��� ��� ����������
int getCountOfUserInFile();            //���������� ���-�� ��������� � �����
bool readFileUser(vector<User>&);      //��������� �� ����� ���������
void writeFileUser(vector<User>&);     //��������� ���� ��������� � ����(������������ ��� ��������/�������������� ����������� �����)
void addFileUser(User);                //���������� ������ �������� � ����
void createFileUser();                 //�������� ����� � ���������� ��� ��� ����������