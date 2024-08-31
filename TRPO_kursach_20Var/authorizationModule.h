#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "mainModule.h"
#include "fileModule.h"
#include "vecUserModule.h"
#include <iterator>

void initialRegistration();                //создание первого аккаунта администратора при отсутствии его раннее
int authorization(vector<User>);                 //авторизации
void registrationAdmin(vector<User>&);   //регистрации администратором
void registrationUser(vector<User>&);    //регистрация пользователем
void confirmRegistration(vector<User>&); //подтверждение регистрации администратором