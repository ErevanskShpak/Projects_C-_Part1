#pragma once

#include "main.h"
#include "check.h"
#include "vecStudWork.h"
#include <algorithm>

void sortStudByDolg(vector<Student>&);                  //сортировка записей о студентах по кол-ву задолженностей
bool partSortByDolg(Student, Student);                  //нужная для сортировки функция
void showByDolg(vector<Student>);                       //показ записей о студентах в порядке убывания задолженностей
void showByAverageBall(vector<Student>);                //показ среднего балла студентов группы и группы в целом
double poiskGroupForAverageBall(vector<Student>, int&); //поиск записей о студентах определенной группы для нахождения среднего балла
void outputStudAverageBall(Student);                    //показ ФИО студента и его среднего балла