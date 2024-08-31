#include "authorizationModule.h"

void initialRegistration()
{
	cout << "------��������� �����������------\n";
	cout << "������� ������ �� ����������. �������� ���: \n";
	User user;
	user.role = 1;
	cout << "������� �����: ";
	inputLogin(user.login);
	string password;
	inputPassword(password);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		user.salt[i] = (char)(rand() % 26 + 97);
	password = password + user.salt;
	user.salted_hash_password = hashFunc(password);
	addFileOfUser(user);
	cout << "����������� �������\n\n";
}

int authorization(vector<User> vecUser)
{
	cout << "------�����������------\n";
	cout << "������� �����: ";
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
					cout << "����������� �������!\n\n";
					return i;
				}
			}
			else
			{
				cout << "��� ������� ��� �� ���������� �����\n\n";
				return -1;
			}
		}
	cout << "�������� ����� ��� ������, ���������� ������.\n\n";
	return -1;
}

void registrationAdmin(vector<User>& vecUser)
{
	cout << "------�����������------\n";
	User user;
	cout << "���������������� ������ ��� ������������?\n";
	cout << "1. �����\n";
	cout << "0. ������������\n";
	cout << "�����: ";
	user.role = inputNumber(0, 1);
	if (inputUser(vecUser, user)) //�������� �� ���������� �����
		return;
	addFileOfUser(user);
	cout << "����������� �������\n";
}

void registrationUser(vector<User>& vecUser)
{
	cout << "------�����������------\n";
	User user;
	user.access = 0;
	if (inputUser(vecUser, user)) //�������� �� ���������� �����
		return;
	addFileOfUser(user);
	cout << "�������� ������������� ����������� ���������������\n\n";
}

void confirmRegistration(vector<User>& vecUser)
{
	cout << "------������������� �����������------\n";
	bool isExist = 0;
	for (int i = 0, n = vecUser.size(); i < n; i++)
		if (vecUser[i].access == 0)
		{
			isExist = 1;
			cout << "����������� ������������ � �������: " << vecUser[i].login << " ?\n";
			cout << "1. ��\n0. ���\n";
			if (inputNumber(0, 1))
			{
				vecUser[i].access = 1;
				cout << "����������� ������������\n";
			}
			else
			{
				vector<User>::iterator itErase = vecUser.begin();
				vecUser.erase(itErase + i);
				cout << "����������� ���������\n";
				writeFileOfUser(vecUser);
			}
		}
	if (!isExist)  //�������� �� ������������� ��������� ��� �������������
		cout << "��� ��������� ��� �������������\n";
}

