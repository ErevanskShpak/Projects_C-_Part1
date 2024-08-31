#include "authorizationModule.h"

void initialRegistration()
{
	cout << "------Начальная регистрация------\n";
	cout << "Первого админа не существует. Создайте его: \n";
	User user;
	user.role = 1;
	cout << "Введите логин: ";
	inputLogin(user.login);
	string password;
	inputPassword(password);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		user.salt[i] = (char)(rand() % 26 + 97);
	password = password + user.salt;
	user.salted_hash_password = hashFunc(password);
	addFileOfUser(user);
	cout << "Регистрация успешна\n\n";
}

int authorization(vector<User> vecUser)
{
	cout << "------Авторизация------\n";
	cout << "Введите логин: ";
	char username[100];
	inputLogin(username);
	string password;
	inputPassword(password);
	int amountUser = getAmountOfUserInFile();
	for (int i = 0; i < amountUser; i++)
		if (!strcmp(vecUser[i].login, username))
		{
			if (vecUser[i].access == 1)
			{
				string passwordWithSalt = password;
				passwordWithSalt += vecUser[i].salt;
				if (hashFunc(passwordWithSalt) == vecUser[i].salted_hash_password)
				{
					cout << "Авторизация успешна!\n\n";
					return i;
				}
			}
			else
			{
				cout << "Ваш аккаунт еще не подтвердил админ\n\n";
				return -1;
			}
		}
	cout << "Неверный логин или пароль, попробуйте заново.\n\n";
	return -1;
}

void registrationAdmin(vector<User>& vecUser)
{
	cout << "------Регистрация------\n";
	User user;
	cout << "Зарегистрировать админа или пользователя?\n";
	cout << "1. Админ\n";
	cout << "0. Пользователь\n";
	cout << "Выбор: ";
	user.role = inputNumber(0, 1);
	if (inputUser(vecUser, user)) //проверка на одинаковый логин
		return;
	addFileOfUser(user);
	cout << "Регистрация успешна\n";
}

void registrationUser(vector<User>& vecUser)
{
	cout << "------Регистрация------\n";
	User user;
	user.access = 0;
	if (inputUser(vecUser, user)) //проверка на одинаковый логин
		return;
	addFileOfUser(user);
	cout << "Ожидайте подтверждения регистрации администратором\n\n";
}

void confirmRegistration(vector<User>& vecUser)
{
	cout << "------Подтверждение регистрации------\n";
	bool isExist = 0;
	for (int i = 0, n = vecUser.size(); i < n; i++)
		if (vecUser[i].access == 0)
		{
			isExist = 1;
			cout << "Подтвердить пользователя с логином: " << vecUser[i].login << " ?\n";
			cout << "1. Да\n0. Нет\n";
			if (inputNumber(0, 1))
			{
				vecUser[i].access = 1;
				cout << "Регистрация подтверждена\n";
			}
			else
			{
				vector<User>::iterator itErase = vecUser.begin();
				vecUser.erase(itErase + i);
				cout << "Регистрация отклонена\n";
				writeFileOfUser(vecUser);
			}
		}
	if (!isExist)  //проверка на существование аккаунтов для подтверждения
		cout << "Нет аккаунтов для подтверждения\n";
}

