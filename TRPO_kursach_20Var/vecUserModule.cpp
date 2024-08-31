#include "vecUserModule.h"

void generateVecOfUser(vector<User>& vecUser)
{
	vecUser.reserve(getAmountOfUserInFile());
}

void deleteVecOfUser(vector<User>& vecUser)
{
	vector<User>().swap(vecUser);
}

bool inputUser(vector<User>& vecUser, User& user)
{
	cout << "Введите логин: ";
	inputLogin(user.login);
	int amountUser = getAmountOfUserInFile();
	for (int i = 0; i < amountUser; i++)
		if (!strcmp(vecUser[i].login, user.login)) //проверка на уже существующий логин
		{
			cout << "Аккаунт с таким логином уже существует!\n\n";
			return 1;
		}
	string password;
	inputPassword(password);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		user.salt[i] = (char)(rand() % 26 + 97);
	password = password + user.salt;
	user.salted_hash_password = hashFunc(password);
	vecUser.push_back(user);
	return 0;
}

long long hashFunc(string password)
{
	int p = 31;
	long long hash = 0, p_pow = 1;
	for (int i = 0; i < password.size(); i++)
	{
		hash += (password[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	return hash;
}

void outputUser(User user)
{
	cout << "|--------------------|------|----------------|------|--------|\n";
	cout << "|" << setw(20) << user.login;
	cout << "|" << setw(6) << user.salt;
	cout << "|" << setw(16) << user.salted_hash_password;
	cout << "|" << setw(6) << user.role;
	cout << "|" << setw(8) << user.access << "|\n";
}

void showVecOfUser(vector<User> vecUser)
{
	cout << "------Просмотр всех аккаунтов------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "|        Логин       | Соль |       Хеш      | Роль | Доступ |\n";
	int amountUser = vecUser.size();
	for (int i = 0; i < amountUser; i++)
		outputUser(vecUser[i]);
	cout << "--------------------------------------------------------------\n";
}

int searchUserForDeleteOrEdit(vector<User> vecUser)
{
	char loginSearch[100];
	inputLogin(loginSearch);
	int numberSearch = 0;
	int amountStud = vecUser.size();
	for (int i = 0; i < amountStud; i++)
	{
		if (!strcmp(vecUser[i].login, loginSearch))
			return numberSearch;
		numberSearch++;
	}
	cout << "Нет аккаунта с таким логином\n";
	return -1;
}

void deleteUserFromVec(vector<User>& vecUser, string current_login)
{
	cout << "------Удаление аккаунта------\n";
	cout << "Введите логин аккаунта, который надо удалить: ";
	int numberDeleteUser = searchUserForDeleteOrEdit(vecUser);
	if (numberDeleteUser == -1) //проверка на нахождение аккаунта
		return;
	if (vecUser[numberDeleteUser].login == current_login) //проверка на удаление собственного аккаунта
	{
		cout << "Вы не можете удалить собственный аккаунт\n";
		return;
	}
	cout << "Вы уверены, что хотите удалить ?\n";
	cout << "1. Да\n";
	cout << "0. Нет\n";
	cout << "Выбор: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) ////проверка на то, хочет ли пользователь удалить данные
	{
		vector<User>::iterator itErase = vecUser.begin();
		vecUser.erase(itErase + numberDeleteUser);
		cout << "Удаление завершено\n";
		writeFileOfUser(vecUser);
	}
}

void editUserFromVec(vector<User>& vecUser)
{
	cout << "------Редактирование аккаунта------\n";
	cout << "Введите логин аккаунта, который надо отредактировать: ";
	int numberEditUser = searchUserForDeleteOrEdit(vecUser);
	if (numberEditUser == -1) //проверка на нахождение аккаунта
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Что надо отредактировать?\n";
		cout << "1. Логин\n";
		cout << "2. Роль\n";
		cout << "0. Выйти из редактирования\n";
		cout << "Выбор: ";
		lever = inputNumber(0, 2);
		switch (lever)
		{
		case 1:
			cout << "Введите новый логин: ";
			inputLogin(vecUser[numberEditUser].login);
			isUsed = 1;
			break;
		case 2:
			cout<<"Для придачи роли администратора введите 1. Для придачи роли пользователя введите 0\n";
			cout << "Введите новую роль: ";
			vecUser[numberEditUser].role = inputNumber(0, 1);
			isUsed = 1;
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	if (isUsed) //проверка на то, было ли проведено редактирование чего-либо
	{
		cout << "Редактирвоание завершено\n";
		writeFileOfUser(vecUser);
	}
}