#pragma once

#include "main.h"
#include <fstream>

int getCountOfStudInFile();            //нахождение кол-ва записей о студентах в файле
bool readFileStud(vector <Student>&);  //прочтение из файла записей о студентах
void writeFileStud(vector <Student>&); //занесение всех записей о студентах в файл(используется при удалении/редактировании содержимого файла)
void addFileStud(Student);             //добавление новой записи о студенте в файл
void createFileStud();                 //создание файла с записями о студентах при его отсутствии
int getCountOfUserInFile();            //нахождение кол-ва аккаунтов в файле
bool readFileUser(vector<User>&);      //прочтение из файла аккаунтов
void writeFileUser(vector<User>&);     //занесение всех аккаунтов в файл(используется при удалении/редактировании содержимого файла)
void addFileUser(User);                //добавление нового аккаунта в файл
void createFileUser();                 //создание файла с аккаунтами при его отсутствии