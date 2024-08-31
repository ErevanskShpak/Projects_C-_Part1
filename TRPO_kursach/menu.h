#pragma once

#include "main.h"
#include "vecAccWork.h"
#include "vecStudWork.h"
#include "authorization.h"
#include "poisk.h"
#include "individ.h"
#include "sort.h"

void menuAdmin(vector<User>&, string);        //меню администратора
void menuAdminAccount(vector<User>&, string); //меню работы с аккаунтами для администратора
void menuAdminData();                         //меню работы с данными для администратора
void menuUser();                              //меню пользователя
void menuAuthorization();                     //главное меню