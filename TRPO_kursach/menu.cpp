#include "menu.h"

void menuAdmin(vector<User>& vec_of_user, string current_login)
{
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Меню администратора:\n";
		cout << "1. Работа с данными\n";
		cout << "2. Работа с аккаунтами\n";
		cout << "0. Выйти из аккаунта\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 2);
		cout << endl;
		switch (lever)
		{
		case 1:
			menuAdminData();
			break;
		case 2:
			menuAdminAccount(vec_of_user, current_login);
			break;
		case 0:
			menu = 0;
		}
	}
}

void menuAdminAccount(vector<User>& vec_of_user, string current_login)
{
	bool menu = 1;
	int lever = 0;
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
		lever = inputNumber(0, 5);
		cout << endl;
		switch (lever)
		{
		case 1:
			showUserVec(vec_of_user);
			break;
		case 2:
			registrationAdmin(vec_of_user);
			break;
		case 3:
			redactUserFromVec(vec_of_user);
			break;
		case 4:
			delUserFromVec(vec_of_user, current_login);
			break;
		case 5:
			confirmRegistration(vec_of_user);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}

void menuAdminData()
{
	createFileStud();
	vector<Student> vec_of_stud; //объявление вектора записей о студентах
	generateStudVec(vec_of_stud);
	if (readFileStud(vec_of_stud))
		return;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Меню работы с данными:\n";
		cout << "1. Просмотр всех записей о студентах\n";
		cout << "2. Добавить запись о новом студенте\n";
		cout << "3. Удалить запись о студенте\n";
		cout << "4. Редактировать запись о студенте\n";
		cout << "5. Вывести все записи о студентах в порядке убывания задолженностей\n";
		cout << "6. Вывести средний балл студентов определенной группы\n";
		cout << "7. Поиск записей о студентах\n";
		cout << "8. Сортировка записей о студентах\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 8);
		cout << endl;
		switch (lever)
		{
		case 1:
			showStudVec(vec_of_stud);
			break;
		case 2:
			addStudInVec(vec_of_stud);
			break;
		case 3:
			delStudFromVec(vec_of_stud);
			break;
		case 4:
			redactStudFromVec(vec_of_stud);
			break;
		case 5:
			showByDolg(vec_of_stud);
			break;
		case 6:
			showByAverageBall(vec_of_stud);
			break;
		case 7:
			poiskStud(vec_of_stud);
			break;
		case 8:
			sortStud(vec_of_stud);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	deleteStudVec(vec_of_stud);
}

void menuUser()
{
	createFileStud();
	vector<Student> vec_of_stud; //объявление вектора записе о студентах
	generateStudVec(vec_of_stud);
	if (readFileStud(vec_of_stud))
		return;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Меню пользователя:\n";
		cout << "1. Просмотр всех записей о студентах\n";
		cout << "2. Вывести все записи о студентах в порядке убывания задолженностей\n";
		cout << "3. Вывести средний балл студентов определенной группы\n";
		cout << "4. Поиск записей о студентах\n";
		cout << "5. Сортировка записей о студентах\n";
		cout << "0. Выйти из аккаунта\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 5);
		cout << endl;
		switch (lever)
		{
		case 1:
			showStudVec(vec_of_stud);
			break;
		case 2:
			showByDolg(vec_of_stud);
			break;
		case 3:
			showByAverageBall(vec_of_stud);
			break;
		case 4:
			poiskStud(vec_of_stud);
			break;
		case 5:
			sortStud(vec_of_stud);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	deleteStudVec(vec_of_stud);
}

void menuAuthorization()
{
	createFileUser();
	if (!getCountOfUserInFile())
		firstRegistration();
	vector<User> vec_of_user; //объявление вектора аккаунтов
	generateUserVec(vec_of_user);
	if (readFileUser(vec_of_user))
		return;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Главное меню:\n";
		cout << "1. Регистрация\n";
		cout << "2. Вход\n";
		cout << "0. Выйти из программы\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 2);
		cout << endl;
		switch (lever)
		{
		case 1:
			registrationUser(vec_of_user);
			break;
		case 2:
		{
			int rez = login(vec_of_user);
			if (rez != -1) //проверка на существование аккаунта
			{
				if (vec_of_user[rez].role)
					menuAdmin(vec_of_user, vec_of_user[rez].login);
				else
					menuUser();
			}
			break;
		}
		case 0:
			menu = 0;
		}
	}
	deleteUserVec(vec_of_user);
	cout << "Программа завершена\n";
}