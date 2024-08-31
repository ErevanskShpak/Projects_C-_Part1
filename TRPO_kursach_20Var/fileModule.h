#pragma once

#include "mainModule.h"
#include <fstream>

void createFileOfHock();                 //создание файла с записями о студентах при его отсутствии
int getAmountOfHockInFile();            //нахождение кол-ва записей о студентах в файле
bool readFileOfHock(vector <Hockey>&);  //прочтение из файла записей о студентах
void writeFileOfHock(vector <Hockey>&); //занесение всех записей о студентах в файл(используется при удалении/редактировании содержимого файла)
void addFileOfHock(Hockey);             //добавление новой записи о студенте в файл
void createFileOfUser();                 //создание файла с аккаунтами при его отсутствии
int getAmountOfUserInFile();            //нахождение кол-ва аккаунтов в файле
bool readFileOfUser(vector<User>&);      //прочтение из файла аккаунтов
void writeFileOfUser(vector<User>&);     //занесение всех аккаунтов в файл(используется при удалении/редактировании содержимого файла)
void addFileOfUser(User);                //добавление нового аккаунта в файл