#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Performance {         //���������, �������� � ���� ������ �� ������������ ��������, � ������:
	int marks[5]{};          //������
	bool zacheti[5]{};       //������/��������
	double average_ball = 0; //������� ����
	int dolg = 0;            //���-�� ��������������(���������)
};

struct Student {      //���������, �������� � ���� ������ � ��������, � ������:
	int group = 0;    //����� ������
	char fio[100]{};   //���
	Performance info; //������ �� ������������
};

struct User {                           //���������, �������� � ���� ������ �� ��������, � ������:
	char login[100]{};                   //�����
	long long salted_hash_password = 0; //��������� ��������� ���-�������� ������ � �������������� � ���� "�����"
	char salt[6]{};                     //"����"
	bool role = 0;                      //����, �� ���� ������������� ��� ������������
	bool access = 1;                    //������, ���� ����������� ��� ����������� �������� �������������
};

static const char* FILE_OF_USERS = "user";          //���� � ����������
static const char* FILE_OF_STUDENTS = "university"; //���� � �������� � ���������