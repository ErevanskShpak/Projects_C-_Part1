#include "checkModule.h"

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

bool isEmpty(vector<Hockey> vec_of_hock)
{
	if (!vec_of_hock.size())
	{
		cout << "На данный момент в файле отсутствуют записи о хоккеистах\n\n";
		return 0;
	}
	return 1;
}

void inputDate(char* date)
{
	while (true)
	{
		cin.getline(date, 100);
		if (isDateCorrect(date))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

bool isDateCorrect(char* date)
{
	string str = date;
	if (str.size() != 10)
		return false;
	if (str[2] != '.' || str[5] != '.')
		return false;
	int numberCharacter;
	for (int i = 0; i < 10; i++)
	{
		numberCharacter = (int)str[i];
		if (!(numberCharacter >= 48 && numberCharacter <= 57 || numberCharacter == 46))
			return false;
		if (str[i] == '.' && i != 2 && i != 5)
			return false;
	}
	if (!isDateNumbersCorrect(date))
		return false;
	return true;
}

bool isDateNumbersCorrect(char* date)
{
	int age = (date[9] - '0') + (date[8] - '0') * 10 + (date[7] - '0') * 100 + (date[6] - '0') * 1000;
	int month = (date[4] - '0') + (date[3] - '0') * 10;
	int number = (date[1] - '0') + (date[0] - '0') * 10;
	if (month > 12 || month == 0 || number == 0 || age > 2023)
		return false;
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (number > 31)
			return false;
		break;
	case 2:
		if (number > 28)
			return false;
		break;
	case 4:case 6:case 9:case 11:
		if (number > 31)
			return false;
		break;
	}
}

void inputFio(char* fio)
{
	while (true)
	{
		cin.getline(fio, 100);
		if (isFioCorrect(fio))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

bool isFioCorrect(char* fio)
{
	string str = fio;
	int n = str.size();
	if (!((int)str[0] >= 65 && (int)str[0] <= 90) || !((int)str[n-1] >= 97 && (int)str[n-1] <= 122))
		return false;
	int amountSpace = 0;
	int numberCharacter;
	for (int i = 1; i < n - 1; i++)
	{
		numberCharacter = (int)str[i];
		if (!((numberCharacter >= 65 && numberCharacter <= 90) || (numberCharacter >= 97 && numberCharacter <= 122) || numberCharacter == 32))
			return false;
		if (str[i] == ' ')
		{
			if (!((int)str[i + 1] >= 65 && (int)str[i + 1] <= 90))
				return false;
			else
				amountSpace++;
		}
		if (str[i - 1] != ' ' && ((int)str[i] >= 65 && (int)str[i] <= 90))
			return false;
	}
	if (amountSpace > 2)
		return false;
	return true;
}

void inputLogin(char* login)
{
	while (true)
	{
		cin.getline(login, 100);
		if (isLoginCorrect(login))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}

bool isLoginCorrect(char* login)
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
		if (isPasswordCorrect(password))
			return;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
		password.clear();
	}
}

bool isPasswordCorrect(string password)
{
	int n = password.size();
	if (n > 32)
		return false;
	for (int i = 0; i < n; i++)
		if (password[i] == ' ')
			return false;
	return true;
}