#include "authorization.h"

int login(vector<User> vec_of_user)
{
	cout << "------Авторизация------\n";
	cout << "Введите логин: ";
	char login[100];
	inputLogin(login);
	string password;
	inputPassword(password);
	int kolvo_of_users = getCountOfUserInFile();
	for (int i = 0; i < kolvo_of_users; i++)
		if (!strcmp(vec_of_user[i].login, login))
		{
			if (vec_of_user[i].access == 1)
			{
				string password_salt = password;
				password_salt += vec_of_user[i].salt;
				if (hashFunc(password_salt) == vec_of_user[i].salted_hash_password)
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

void registrationAdmin(vector<User>& vec_of_user)
{
	cout << "------Регистрация------\n";
	User user;
	cout << "Зарегистрировать админа или пользователя?\n";
	cout << "1. Админ\n";
	cout << "0. Пользователь\n";
	cout << "Выбор: ";
	user.role = inputNumber(0, 1);
	if (inputUser(vec_of_user, user)) //проверка на одинаковый логин
		return;
	addFileUser(user);
	cout << "Регистрация успешна\n";
}

void registrationUser(vector<User>& vec_of_user)
{
	cout << "------Регистрация------\n";
	User user;
	user.access = 0;
	if (inputUser(vec_of_user, user)) //проверка на одинаковый логин
		return;
	addFileUser(user);
	cout << "Ожидайте подтверждения регистрации администратором\n\n";
}

void confirmRegistration(vector<User>& vec_of_user)
{
	cout << "------Подтверждение регистрации------\n";
	bool isBe = 0;
	for (int i = 0, n = vec_of_user.size(); i < n; i++)
		if (vec_of_user[i].access == 0)
		{
			isBe = 1;
			cout << "Подтвердить пользователя с логином: " << vec_of_user[i].login << " ?\n";
			cout << "1. Да\n0. Нет\n";
			if (inputNumber(0, 1))
			{
				vec_of_user[i].access = 1;
				cout << "Регистрация подтверждена\n";
			}
			else
			{
				vector<User>::iterator itErase = vec_of_user.begin();
				vec_of_user.erase(itErase + i);
				cout << "Регистрация отклонена\n";
				writeFileUser(vec_of_user);
			}
		}
	if (!isBe)  //проверка на существование аккаунтов для подтверждения
		cout << "Нет аккаунтов для подтверждения\n";
}

void firstRegistration()
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
	addFileUser(user);
	cout << "Регистрация успешна\n\n";
}