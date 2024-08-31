#include "fileModule.h"

void createFileOfHock()
{
	fstream file;
	file.open(FILE_OF_HOCKEY, fstream::in);
	if (!file.is_open())
	{
		file.open(FILE_OF_HOCKEY, fstream::out);
		file.close();
	}
}

int getAmountOfHockInFile()
{
	ifstream file;
	file.open(FILE_OF_HOCKEY, ifstream::ate);
	int number_of_hock = file.tellg() / sizeof(Hockey);
	file.close();
	return number_of_hock;
}

bool readFileOfHock(vector<Hockey>& vec_of_hock)
{
	ifstream file;
	file.open(FILE_OF_HOCKEY);
	bool isOpen = false;
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл записей о студентах!\n";
		isOpen = true;
	}
	else
	{
		Hockey hock;
		while (file.read((char*)&hock, sizeof(Hockey)))
			vec_of_hock.push_back(hock);
	}
	file.close();
	return isOpen;
}

void writeFileOfHock(vector<Hockey>& vec_of_hock)
{
	ofstream file;
	file.open(FILE_OF_HOCKEY);
	if (!file.is_open())
		cout << "Не удалось открыть файл записей о студентах! Изменения не сохранены!\n";
	else
	{
		Hockey hock;
		for (int i = 0; i < vec_of_hock.size(); i++)
		{
			hock = vec_of_hock[i];
			file.write((char*)&hock, sizeof(Hockey));
		}
		cout << "Сохранение успешно\n";
	}
	file.close();
}

void addFileOfHock(Hockey hock)
{
	ofstream file;
	file.open(FILE_OF_HOCKEY, ofstream::app);
	if (!file.is_open())
		cout << "Не удалось открыть файл записей о студентах! Изменения не сохранены!\n";
	else
	{
		file.write((char*)&hock, sizeof(Hockey));
		cout << "Сохранение успешно\n";
	}
	file.close();
}

void createFileOfUser()
{
	fstream file;
	file.open(FILE_OF_USERS, fstream::in);
	if (!file.is_open())
	{
		file.open(FILE_OF_USERS, fstream::out);
		file.close();
	}
}

int getAmountOfUserInFile()
{
	ifstream file;
	file.open(FILE_OF_USERS, ifstream::ate);
	int number_of_users = file.tellg() / sizeof(User);
	file.close();
	return number_of_users;
}

bool readFileOfUser(vector<User>& vec_of_user)
{
	ifstream file;
	file.open(FILE_OF_USERS);
	bool isOpen = false;
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл аккаунтов!\n";
		isOpen = true;
	}
	else
	{
		User user;
		while (file.read((char*)&user, sizeof(User)))
			vec_of_user.push_back(user);
	}
	file.close();
	return isOpen;
}

void writeFileOfUser(vector<User>& vec_of_user)
{
	ofstream file;
	file.open(FILE_OF_USERS);
	if (!file.is_open())
		cout << "Не удалось открыть файл аккаунтов! Изменения не сохранены!\n";
	else
	{
		User user;
		for (int i = 0; i < vec_of_user.size(); i++)
		{
			user = vec_of_user[i];
			file.write((char*)&user, sizeof(User));
		}
		cout << "Сохранение успешно\n";
	}
	file.close();
}

void addFileOfUser(User user)
{
	ofstream file;
	file.open(FILE_OF_USERS, ofstream::app);
	if (!file.is_open())
		cout << "Не удалось открыть файл аккаунтов! Регистрация провалена!\n";
	else
		file.write((char*)&user, sizeof(User));
	file.close();
}