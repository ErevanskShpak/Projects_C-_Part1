#pragma once

#include "mainModule.h"
#include "vecHockModule.h"
#include <algorithm>

void sortHockByBest(vector<Hockey>&);                  //сортировка записей о студентах по кол-ву задолженностей
bool partSortByBest(Hockey, Hockey);                  //нужная для сортировки функция
void showByBest(vector<Hockey>);                       //показ записей о студентах в порядке убывания задолженностей