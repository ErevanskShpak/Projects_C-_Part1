#pragma once

#include "main.h"
#include <conio.h>

bool isNumberNumeric();                   //проверка на числовой ввод
bool isNumberRangeCorrect(int, int, int); //проверка на правильный диапазон числа
int inputNumber(int, int);                //ввод числа
string isZachet(int);                     //проверка на полученный зачет
bool isEmpty(vector<Student>);            //проверка на пустой файл с записями о студентах
void inputFio(char*);                     //ввод фамилии
bool isFioOk(char*);                      //проверка на правильность ввода фамилили
void inputLogin(char*);                   //ввод логина
bool isLoginOk(char*);                    //проверка на правильность ввода логина
void inputPassword(string&);              //ввод пароля
bool isPasswordOk(string);                //проверка на правильность ввода пароля