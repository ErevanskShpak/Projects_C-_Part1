#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Сareer {         //Структура, хранящая в себе данные об успеваемости студента, а именно:
	int match = 0;         //оценки
	int puck = 0;     //зачеты/незачеты
	int assist = 0; //средний балл
	int time = 0;            //кол-во задолженностей(незачетов)
};

struct Hockey {          //Структура, хранящая в себе данные о студенте, а именно:
	char fio[100]{};       //ФИО
	char date[100]{};      //дата рождения
	Сareer info; //данные об успеваемости
};

struct User {                           //Структура, хранящая в себе данные об аккаунте, а именно:
	char login[100]{};                   //логин
	char salt[6]{};                     //"соль"
	long long salted_hash_password = 0; //результат обработки хеш-функцией пароля с присоединенной к нему "солью"
	bool role = 0;                      //роль, то есть администратор или пользователь
	bool access = 1;                    //доступ, поле необходимое при регистрации аккаунта пользователем
};

static const char* FILE_OF_USERS = "user.txt";          //файл с аккаунтами
static const char* FILE_OF_HOCKEY = "hockey.txt"; //файл с записями о студентах