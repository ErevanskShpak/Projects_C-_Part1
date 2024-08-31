#pragma once

#include "main.h"
#include "fileWork.h"
#include "check.h"
#include <iterator>
#include <iomanip>

Student inputStud(Student);                //ввод данных об студенте
void getDolg(Student&);                    //расчет задолженност студента
void outputStud(Student);                  //вывод данных о студенте
void generateStudVec(vector<Student>&);    //выделение памяти для вектора записей о студентах
void deleteStudVec(vector<Student>&);      //освобождение памяти занятой вектором записей о студентах
void addStudInVec(vector<Student>&);       //добавление записи о студенте в вектор
void delStudFromVec(vector<Student>&);     //удаление записи о студенте из вектора и файла
void redactStudFromVec(vector<Student>&);  //редактирование записи о студенте в векторе и файле
int poiskFioForDelAndRed(vector<Student>); //поиск записи о студенте для удаления или редактирования
void showStudVec(vector<Student>);         //показ вектора записей о студентах