#pragma once

#include "mainModule.h"
#include <conio.h>

bool isNumberNumeric();                   //проверка на числовой ввод
bool isNumberRangeCorrect(int, int, int); //проверка на правильный диапазон числа
int inputNumber(int, int);                //ввод числа
bool isEmpty(vector<Hockey>);            //проверка на пустой файл с записями о студентах
void inputDate(char*);
bool isDateCorrect(char*);
bool isDateNumbersCorrect(char*);
void inputFio(char*);
bool isFioCorrect(char*);
void inputLogin(char*);
bool isLoginCorrect(char*);
void inputPassword(string&);
bool isPasswordCorrect(string);