#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "fileWork.h"
#include "vecAccWork.h"
#include <iterator>

int login(vector<User>);                 //авторизация
void registrationAdmin(vector<User>&);   //регистрация администратором
void registrationUser(vector<User>&);    //регистрация пользователем
void confirmRegistration(vector<User>&); //подтверждение регистрации администратором
void firstRegistration();                //создание первого аккаунта администратора при отсутствии его раннее