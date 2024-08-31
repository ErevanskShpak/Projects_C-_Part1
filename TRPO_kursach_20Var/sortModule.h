#pragma once

#include "mainModule.h"
#include "checkModule.h"
#include "vecHockModule.h"
#include <algorithm>

void sortHockByFio(vector<Hockey>&);         //сортировка записей о студентах по алфавиту
bool partSortByFio(Hockey, Hockey);         //часть для сортировки по алфавиту
void sortHockByMatch(vector<Hockey>&); //сортировка записей о студентах по убыванию среднего балла
bool partSortByMatch(Hockey, Hockey); //часть для сортировки по среднему баллу
void sortHockByPuck(vector<Hockey>&);       //сортировка записей о студентах по номеру группы
bool partSortByPuck(Hockey, Hockey);       //часть для сортировки по номеру группы
void sortHock(vector<Hockey>&);              //меню сортировки записей о студентах