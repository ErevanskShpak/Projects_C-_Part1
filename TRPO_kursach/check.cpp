#include "check.h"

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return false;
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		return false;
}

int inputNumber(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range))
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

string isZachet(int predmet)
{
	if (predmet)
		return "зачет";
	else
		return "незачет";
}

bool isEmpty(vector<Student> vec_of_stud)
{
	if (!vec_of_stud.size())
	{
		cout << "На данный момент в файле отсутствуют записи о студентах\n\n";
		return 0;
	}
	return 1;
}

void inputFio(char* fio)
{
	while (true)
	{
		cin.getline(fio, 100);
		if (isFioOk(fio))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

bool isFioOk(char* fio)
{
	string str = fio;
	int n = str.size();
	if (!((int)str[0] >= 65 && (int)str[0] <= 90) || !((int)str[n - 1] >= 97 && (int)str[n - 1] <= 122))
		return false;
	int kolvo_of_space = 0;
	int number_s;
	for (int i = 1; i < n - 1; i++)
	{
		number_s = (int)str[i];
		if (!((number_s >= 65 && number_s <= 90) || (number_s >= 97 && number_s <= 122) || number_s == 32))
			return false;
		if (str[i] == ' ')
		{
			if (!((int)str[i + 1] >= 65 && (int)str[i + 1] <= 90))
				return false;
			else
				kolvo_of_space++;
		}
		if (str[i - 1] != ' ' && ((int)str[i] >= 65 && (int)str[i] <= 90))
			return false;
	}
	if (kolvo_of_space > 2)
		return false;
	return true;
}

void inputLogin(char* login)
{
	while (true)
	{
		cin.getline(login, 100);
		if (isLoginOk(login))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

bool isLoginOk(char* login)
{
	string str = login;
	int n = str.size();
	if (n > 32)
		return false;
	for (int i = 0; i < n; i++)
		if (str[i] == ' ')
			return false;
	return true;
}

void inputPassword(string& password)
{
	char c;
	cout << "Введите пароль: ";
	while (true)
	{
		while ((c = _getch()) != '\r') {
			if (c == '\b') {
				if (password.length() > 0) {
					password.pop_back();
					cout << "\b \b";
				}
			}
			else {
				password.push_back(c);
				cout << "*";
			}
		}
		cout << endl;
		if (isPasswordOk(password))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
		password.clear();
	}
}

bool isPasswordOk(string password)
{
	int n = password.size();
	if (n > 32)
		return false;
	for (int i = 0; i < n; i++)
		if (password[i] == ' ')
			return false;
	return true;
}