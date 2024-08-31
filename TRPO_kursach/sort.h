#pragma once

#include "main.h"
#include "check.h"
#include "vecStudWork.h"
#include <algorithm>

void sortStudByFio(vector<Student>&);         //сортировка записей о студентах по алфавиту
bool partSortByFio(Student, Student);         //часть для сортировки по алфавиту
void sortStudByAverageBall(vector<Student>&); //сортировка записей о студентах по убыванию среднего балла
bool partSortByAverageBall(Student, Student); //часть для сортировки по среднему баллу
void sortStudByGroup(vector<Student>&);       //сортировка записей о студентах по номеру группы
bool partSortByGroup(Student, Student);       //часть для сортировки по номеру группы
void sortStud(vector<Student>&);              //меню сортировки записей о студентах