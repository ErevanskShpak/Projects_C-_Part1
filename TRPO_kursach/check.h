#pragma once

#include "main.h"
#include <conio.h>

bool isNumberNumeric();                   //�������� �� �������� ����
bool isNumberRangeCorrect(int, int, int); //�������� �� ���������� �������� �����
int inputNumber(int, int);                //���� �����
string isZachet(int);                     //�������� �� ���������� �����
bool isEmpty(vector<Student>);            //�������� �� ������ ���� � �������� � ���������
void inputFio(char*);                     //���� �������
bool isFioOk(char*);                      //�������� �� ������������ ����� ��������
void inputLogin(char*);                   //���� ������
bool isLoginOk(char*);                    //�������� �� ������������ ����� ������
void inputPassword(string&);              //���� ������
bool isPasswordOk(string);                //�������� �� ������������ ����� ������