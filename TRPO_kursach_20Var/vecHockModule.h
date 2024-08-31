#pragma once

#include "mainModule.h"
#include "fileModule.h"
#include "checkModule.h"
#include <iterator>
#include <iomanip>

Hockey inputHock(Hockey);                //ввод данных об студенте
void outputHock(Hockey);                  //вывод данных о студенте
void generateVecOfHock(vector<Hockey>&);    //выделение памяти для вектора записей о студентах
void deleteVecOfHock(vector<Hockey>&);      //освобождение памяти занятой вектором записей о студентах
void showVecOfHock(vector<Hockey>);         //показ вектора записей о студентах
void addHockInVec(vector<Hockey>&);   //добавление записи о студенте в вектор
int searchHockForDeleteAndEdit(vector<Hockey>); //поиск записи о студенте для удаления или редактирования
void deleteHockFromVec(vector<Hockey>&);     //удаление записи о студенте из вектора и файла
void editHockFromVec(vector<Hockey>&);  //редактирование записи о студенте в векторе и файле