#pragma once

#include "mainModule.h"
#include <conio.h>

bool isNumberNumeric();                   //�������� �� �������� ����
bool isNumberRangeCorrect(int, int, int); //�������� �� ���������� �������� �����
int inputNumber(int, int);                //���� �����
bool isEmpty(vector<Hockey>);            //�������� �� ������ ���� � �������� � ���������
void inputDate(char*);
bool isDateCorrect(char*);
bool isDateNumbersCorrect(char*);
void inputFio(char*);
bool isFioCorrect(char*);
void inputLogin(char*);
bool isLoginCorrect(char*);
void inputPassword(string&);
bool isPasswordCorrect(string);