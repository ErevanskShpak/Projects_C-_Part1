#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "mainModule.h"
#include "fileModule.h"
#include "checkModule.h"
#include <ctime>
#include <iomanip>

void generateVecOfUser(vector<User>&);        //��������� ������ ��� ������� ���������
void deleteVecOfUser(vector<User>&);          //������������ ������ ������� �������� ���������
bool inputUser(vector<User>&, User&);       //���� ������ �� ��������
long long hashFunc(string);                 //���-�������
void outputUser(User);                      //����� ������ �� ��������
void showVecOfUser(vector<User>);             //����� ������� ���������
int searchUserForDeleteOrEdit(vector<User>);    //����� �������� ��� �������� ��� ��������������
void deleteUserFromVec(vector<User>&, string); //�������� �������� �� ������� � �����
void editUserFromVec(vector<User>&);      //�������������� �������� � ������� � �����