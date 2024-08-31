#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "mainModule.h"
#include "fileModule.h"
#include "checkModule.h"
#include <ctime>
#include <iomanip>

void generateVecOfUser(vector<User>&);        //выделение памяти для вектора аккаунтов
void deleteVecOfUser(vector<User>&);          //освобождение памяти занятой вектором аккаунтов
bool inputUser(vector<User>&, User&);       //ввод данных об аккаунте
long long hashFunc(string);                 //хеш-функция
void outputUser(User);                      //показ данных об аккаунте
void showVecOfUser(vector<User>);             //показ вектора аккаунтов
int searchUserForDeleteOrEdit(vector<User>);    //поиск аккаунта для удаления или редактирования
void deleteUserFromVec(vector<User>&, string); //удаление аккаунта из вектора и файла
void editUserFromVec(vector<User>&);      //редактирование аккаунта в векторе и файле