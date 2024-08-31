#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Performance {         //Структура, хранящая в себе данные об успеваемости студента, а именно:
	int marks[5]{};          //оценки
	bool zacheti[5]{};       //зачеты/незачеты
	double average_ball = 0; //средний балл
	int dolg = 0;            //кол-во задолженностей(незачетов)
};

struct Student {      //Структура, хранящая в себе данные о студенте, а именно:
	int group = 0;    //номер группы
	char fio[100]{};   //ФИО
	Performance info; //данные об успеваемости
};

struct User {                           //Структура, хранящая в себе данные об аккаунте, а именно:
	char login[100]{};                   //логин
	long long salted_hash_password = 0; //результат обработки хеш-функцией пароля с присоединенной к нему "солью"
	char salt[6]{};                     //"соль"
	bool role = 0;                      //роль, то есть администратор или пользователь
	bool access = 1;                    //доступ, поле необходимое при регистрации аккаунта пользователем
};

static const char* FILE_OF_USERS = "user";          //файл с аккаунтами
static const char* FILE_OF_STUDENTS = "university"; //файл с записями о студентах