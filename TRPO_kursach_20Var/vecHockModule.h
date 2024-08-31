#pragma once

#include "mainModule.h"
#include "fileModule.h"
#include "checkModule.h"
#include <iterator>
#include <iomanip>

Hockey inputHock(Hockey);                //���� ������ �� ��������
void outputHock(Hockey);                  //����� ������ � ��������
void generateVecOfHock(vector<Hockey>&);    //��������� ������ ��� ������� ������� � ���������
void deleteVecOfHock(vector<Hockey>&);      //������������ ������ ������� �������� ������� � ���������
void showVecOfHock(vector<Hockey>);         //����� ������� ������� � ���������
void addHockInVec(vector<Hockey>&);   //���������� ������ � �������� � ������
int searchHockForDeleteAndEdit(vector<Hockey>); //����� ������ � �������� ��� �������� ��� ��������������
void deleteHockFromVec(vector<Hockey>&);     //�������� ������ � �������� �� ������� � �����
void editHockFromVec(vector<Hockey>&);  //�������������� ������ � �������� � ������� � �����