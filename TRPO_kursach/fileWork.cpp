#include "fileWork.h"

int getCountOfStudInFile()
{
	ifstream fs;
	fs.open(FILE_OF_STUDENTS, ifstream::ate);
	int number_of_stud = fs.tellg() / sizeof(Student);
	fs.close();
	return number_of_stud;
}

bool readFileStud(vector<Student>& vec_of_stud)
{
	ifstream fs;
	fs.open(FILE_OF_STUDENTS);
	bool isOpen = false;
	if (!fs.is_open())
	{
		cout << "Не удалось открыть файл записей о студентах!\n";
		isOpen = true;
	}
	else
	{
		Student stud;
		while (fs.read((char*)&stud, sizeof(Student)))
			vec_of_stud.push_back(stud);
	}
	fs.close();
	return isOpen;
}

void writeFileStud(vector<Student>& vec_of_stud)
{
	ofstream fs;
	fs.open(FILE_OF_STUDENTS);
	if (!fs.is_open())
		cout << "Не удалось открыть файл записей о студентах! Изменения не сохранены!\n";
	else
	{
		Student stud;
		for (int i = 0; i < vec_of_stud.size(); i++)
		{
			stud = vec_of_stud[i];
			fs.write((char*)&stud, sizeof(Student));
		}
		cout << "Сохранение успешно\n";
	}
	fs.close();
}

void addFileStud(Student stud)
{
	ofstream fs;
	fs.open(FILE_OF_STUDENTS, ofstream::app);
	if (!fs.is_open())
		cout << "Не удалось открыть файл записей о студентах! Изменения не сохранены!\n";
	else
	{
		fs.write((char*)&stud, sizeof(Student));
		cout << "Сохранение успешно\n";
	}
	fs.close();
}

void createFileStud()
{
	fstream fs;
	fs.open(FILE_OF_STUDENTS, fstream::in);
	if (!fs.is_open())
	{
		fs.open(FILE_OF_STUDENTS, fstream::out);
		fs.close();
	}
}

int getCountOfUserInFile()
{
	ifstream fs;
	fs.open(FILE_OF_USERS, ifstream::ate);
	int number_of_users = fs.tellg() / sizeof(User);
	fs.close();
	return number_of_users;
}

bool readFileUser(vector<User>& vec_of_user)
{
	ifstream fs;
	fs.open(FILE_OF_USERS);
	bool isOpen = false;
	if (!fs.is_open())
	{
		cout << "Не удалось открыть файл аккаунтов!\n";
		isOpen = true;
	}
	else
	{
		User user;
		while (fs.read((char*)&user, sizeof(User)))
			vec_of_user.push_back(user);
	}
	fs.close();
	return isOpen;
}

void writeFileUser(vector<User>& vec_of_user)
{
	ofstream fs;
	fs.open(FILE_OF_USERS);
	if (!fs.is_open())
		cout << "Не удалось открыть файл аккаунтов! Изменения не сохранены!\n";
	else
	{
		User user;
		for (int i = 0; i < vec_of_user.size(); i++)
		{
			user = vec_of_user[i];
			fs.write((char*)&user, sizeof(User));
		}
		cout << "Сохранение успешно\n";
	}
	fs.close();
}

void addFileUser(User user)
{
	ofstream fs;
	fs.open(FILE_OF_USERS, ofstream::app);
	if (!fs.is_open())
		cout << "Не удалось открыть файл аккаунтов! Регистрация провалена!\n";
	else
		fs.write((char*)&user, sizeof(User));
	fs.close();
}

void createFileUser()
{
	fstream fs;
	fs.open(FILE_OF_USERS, fstream::in);
	if (!fs.is_open())
	{
		fs.open(FILE_OF_USERS, fstream::out);
		fs.close();
	}
}