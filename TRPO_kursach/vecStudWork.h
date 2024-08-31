#pragma once

#include "main.h"
#include "fileWork.h"
#include "check.h"
#include <iterator>
#include <iomanip>

Student inputStud(Student);                //���� ������ �� ��������
void getDolg(Student&);                    //������ ������������ ��������
void outputStud(Student);                  //����� ������ � ��������
void generateStudVec(vector<Student>&);    //��������� ������ ��� ������� ������� � ���������
void deleteStudVec(vector<Student>&);      //������������ ������ ������� �������� ������� � ���������
void addStudInVec(vector<Student>&);       //���������� ������ � �������� � ������
void delStudFromVec(vector<Student>&);     //�������� ������ � �������� �� ������� � �����
void redactStudFromVec(vector<Student>&);  //�������������� ������ � �������� � ������� � �����
int poiskFioForDelAndRed(vector<Student>); //����� ������ � �������� ��� �������� ��� ��������������
void showStudVec(vector<Student>);         //����� ������� ������� � ���������