#include "mainModule.h"
#include "vecUserModule.h"
#include "vecHockModule.h"
#include "authorizationModule.h"
#include "searchModule.h"
#include "individualModule.h"
#include "sortModule.h"

void menuAdministrator(vector<User>&, string);        //меню администратора
void menuAdministratorAccount(vector<User>&, string); //меню работы с аккаунтами для администратора
void menuAdministratorData();                         //меню работы с данными для администратора
void menuUser();                              //меню пользователя
void menuMain();                     //главное меню

int main()
{
	setlocale(LC_ALL, "ru");
	menuMain();
	return 0;
}

void menuAdministrator(vector<User>& vecUser, string loginNow)
{
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Меню администратора:\n";
		cout << "1. Работа с данными\n";
		cout << "2. Работа с аккаунтами\n";
		cout << "0. Выйти из аккаунта\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 2);
		cout << endl;
		switch (choice)
		{
		case 1:
			menuAdministratorData();
			break;
		case 2:
			menuAdministratorAccount(vecUser, loginNow);
			break;
		case 0:
			menu = 0;
		}
	}
}

void menuAdministratorAccount(vector<User>& vecUser, string loginNow)
{
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Меню работы с аккаунтами:\n";
		cout << "1. Просмотр аккаунтов\n";
		cout << "2. Регистрация аккаунтов\n";
		cout << "3. Редактирование аккаунтов\n";
		cout << "4. Удаление аккаунтов\n";
		cout << "5. Подтверждение регистрации пользователей\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 5);
		cout << endl;
		switch (choice)
		{
		case 1:
			showVecOfUser(vecUser);
			break;
		case 2:
			registrationAdmin(vecUser);
			break;
		case 3:
			editUserFromVec(vecUser);
			break;
		case 4:
			deleteUserFromVec(vecUser, loginNow);
			break;
		case 5:
			confirmRegistration(vecUser);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}

void menuAdministratorData()
{
	createFileOfHock();
	vector<Hockey> vecHock; //объявление вектора записей о студентах
	generateVecOfHock(vecHock);
	if (readFileOfHock(vecHock))
		return;
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Меню работы с данными:\n";
		cout << "1. Просмотр всех записей о хоккеистах\n";
		cout << "2. Добавить запись о новом хоккеисте\n";
		cout << "3. Удалить запись о хоккеисте\n";
		cout << "4. Редактировать запись о хоккеисте\n";
		cout << "5. Вывести шесть лучших игроков\n";
		cout << "6. Поиск записей о хоккеистах\n";
		cout << "7. Сортировка записей о хоккеистах\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 7);
		cout << endl;
		switch (choice)
		{
		case 1:
			showVecOfHock(vecHock);
			break;
		case 2:
			addHockInVec(vecHock);
			break;
		case 3:
			deleteHockFromVec(vecHock);
			break;
		case 4:
			editHockFromVec(vecHock);
			break;
		case 5:
			showByBest(vecHock);
			break;
		case 6:
			searchHock(vecHock);
			break;
		case 7:
			sortHock(vecHock);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	deleteVecOfHock(vecHock);
}

void menuUser()
{
	createFileOfHock();
	vector<Hockey> vecHock; //объявление вектора записе о студентах
	generateVecOfHock(vecHock);
	if (readFileOfHock(vecHock))
		return;
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Меню пользователя:\n";
		cout << "1. Просмотр всех записей о студентах\n";
		cout << "2. Вывести шесть лучших игроков\n";
		cout << "3. Поиск записей о студентах\n";
		cout << "4. Сортировка записей о студентах\n";
		cout << "0. Выйти из аккаунта\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 4);
		cout << endl;
		switch (choice)
		{
		case 1:
			showVecOfHock(vecHock);
			break;
		case 2:
			showByBest(vecHock);
			break;
		case 3:
			searchHock(vecHock);
			break;
		case 4:
			sortHock(vecHock);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	deleteVecOfHock(vecHock);
}

void menuMain()
{
	createFileOfUser();
	if (!getAmountOfUserInFile())
		initialRegistration();
	vector<User> vecUser; //объявление вектора аккаунтов
	generateVecOfUser(vecUser);
	if (readFileOfUser(vecUser))
		return;
	bool menu = 1;
	int choice = 0;
	while (menu)
	{
		cout << "Главное меню:\n";
		cout << "1. Регистрация\n";
		cout << "2. Вход\n";
		cout << "0. Выйти из программы\n";
		cout << "Выберите пункт меню: ";
		choice = inputNumber(0, 2);
		cout << endl;
		switch (choice)
		{
		case 1:
			registrationUser(vecUser);
			break;
		case 2:
		{
			int rez = authorization(vecUser);
			if (rez != -1) //проверка на существование аккаунта
			{
				if (vecUser[rez].role)
					menuAdministrator(vecUser, vecUser[rez].login);
				else
					menuUser();
			}
			break;
		}
		case 0:
			menu = 0;
		}
	}
	deleteVecOfUser(vecUser);
	cout << "Программа завершена\n";
}