#pragma once

#include "main.h"
#include "vecAccWork.h"
#include "vecStudWork.h"
#include "authorization.h"
#include "poisk.h"
#include "individ.h"
#include "sort.h"

void menuAdmin(vector<User>&, string);        //���� ��������������
void menuAdminAccount(vector<User>&, string); //���� ������ � ���������� ��� ��������������
void menuAdminData();                         //���� ������ � ������� ��� ��������������
void menuUser();                              //���� ������������
void menuAuthorization();                     //������� ����