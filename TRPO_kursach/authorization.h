#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "fileWork.h"
#include "vecAccWork.h"
#include <iterator>

int login(vector<User>);                 //�����������
void registrationAdmin(vector<User>&);   //����������� ���������������
void registrationUser(vector<User>&);    //����������� �������������
void confirmRegistration(vector<User>&); //������������� ����������� ���������������
void firstRegistration();                //�������� ������� �������� �������������� ��� ���������� ��� ������