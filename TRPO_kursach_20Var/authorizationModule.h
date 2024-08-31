#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "mainModule.h"
#include "fileModule.h"
#include "vecUserModule.h"
#include <iterator>

void initialRegistration();                //�������� ������� �������� �������������� ��� ���������� ��� ������
int authorization(vector<User>);                 //�����������
void registrationAdmin(vector<User>&);   //����������� ���������������
void registrationUser(vector<User>&);    //����������� �������������
void confirmRegistration(vector<User>&); //������������� ����������� ���������������