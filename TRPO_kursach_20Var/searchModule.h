#pragma once

#include "mainModule.h"
#include "checkModule.h"
#include "vecHockModule.h"

bool searchMatch(vector<Hockey>); //поиск записей о студентах по среднему баллу
bool searchFio(vector<Hockey>);         //поиск записей о студентах по ФИО
bool searchPuck(vector<Hockey>);       //поиск записей о студентах по группе
void searchHock(vector<Hockey>);        //меню поиска записей о студентах