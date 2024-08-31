#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct �areer {         //���������, �������� � ���� ������ �� ������������ ��������, � ������:
	int match = 0;         //������
	int puck = 0;     //������/��������
	int assist = 0; //������� ����
	int time = 0;            //���-�� ��������������(���������)
};

struct Hockey {          //���������, �������� � ���� ������ � ��������, � ������:
	char fio[100]{};       //���
	char date[100]{};      //���� ��������
	�areer info; //������ �� ������������
};

struct User {                           //���������, �������� � ���� ������ �� ��������, � ������:
	char login[100]{};                   //�����
	char salt[6]{};                     //"����"
	long long salted_hash_password = 0; //��������� ��������� ���-�������� ������ � �������������� � ���� "�����"
	bool role = 0;                      //����, �� ���� ������������� ��� ������������
	bool access = 1;                    //������, ���� ����������� ��� ����������� �������� �������������
};

static const char* FILE_OF_USERS = "user.txt";          //���� � ����������
static const char* FILE_OF_HOCKEY = "hockey.txt"; //���� � �������� � ���������