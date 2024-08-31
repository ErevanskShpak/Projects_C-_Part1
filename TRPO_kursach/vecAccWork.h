#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "fileWork.h"
#include "check.h"
#include <ctime>
#include <iomanip>

void generateUserVec(vector<User>&);        //��������� ������ ��� ������� ���������
void deleteUserVec(vector<User>&);          //������������ ������ ������� �������� ���������
bool inputUser(vector<User>&, User&);       //���� ������ �� ��������
long long hashFunc(string);                 //���-�������
void showUserVec(vector<User>);             //����� ������� ���������
void outputUser(User);                      //����� ������ �� ��������
void delUserFromVec(vector<User>&, string); //�������� �������� �� ������� � �����
int poiskUserForDelAndRed(vector<User>);    //����� �������� ��� �������� ��� ��������������
void redactUserFromVec(vector<User>&);      //�������������� �������� � ������� � �����