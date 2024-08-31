#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "fileWork.h"
#include "check.h"
#include <ctime>
#include <iomanip>

void generateUserVec(vector<User>&);        //выделение памяти для вектора аккаунтов
void deleteUserVec(vector<User>&);          //освобождение памяти занятой вектором аккаунтов
bool inputUser(vector<User>&, User&);       //ввод данных об аккаунте
long long hashFunc(string);                 //хеш-функция
void showUserVec(vector<User>);             //показ вектора аккаунтов
void outputUser(User);                      //показ данных об аккаунте
void delUserFromVec(vector<User>&, string); //удаление аккаунта из вектора и файла
int poiskUserForDelAndRed(vector<User>);    //поиск аккаунта для удаления или редактирования
void redactUserFromVec(vector<User>&);      //редактирование аккаунта в векторе и файле