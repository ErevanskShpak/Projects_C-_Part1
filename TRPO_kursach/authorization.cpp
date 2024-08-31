#include "authorization.h"

int login(vector<User> vec_of_user)
{
	cout << "------�����������------\n";
	cout << "������� �����: ";
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

void registrationAdmin(vector<User>& vec_of_user)
{
	cout << "------�����������------\n";
	User user;
	cout << "���������������� ������ ��� ������������?\n";
	cout << "1. �����\n";
	cout << "0. ������������\n";
	cout << "�����: ";
	user.role = inputNumber(0, 1);
	if (inputUser(vec_of_user, user)) //�������� �� ���������� �����
		return;
	addFileUser(user);
	cout << "����������� �������\n";
}

void registrationUser(vector<User>& vec_of_user)
{
	cout << "------�����������------\n";
	User user;
	user.access = 0;
	if (inputUser(vec_of_user, user)) //�������� �� ���������� �����
		return;
	addFileUser(user);
	cout << "�������� ������������� ����������� ���������������\n\n";
}

void confirmRegistration(vector<User>& vec_of_user)
{
	cout << "------������������� �����������------\n";
	bool isBe = 0;
	for (int i = 0, n = vec_of_user.size(); i < n; i++)
		if (vec_of_user[i].access == 0)
		{
			isBe = 1;
			cout << "����������� ������������ � �������: " << vec_of_user[i].login << " ?\n";
			cout << "1. ��\n0. ���\n";
			if (inputNumber(0, 1))
			{
				vec_of_user[i].access = 1;
				cout << "����������� ������������\n";
			}
			else
			{
				vector<User>::iterator itErase = vec_of_user.begin();
				vec_of_user.erase(itErase + i);
				cout << "����������� ���������\n";
				writeFileUser(vec_of_user);
			}
		}
	if (!isBe)  //�������� �� ������������� ��������� ��� �������������
		cout << "��� ��������� ��� �������������\n";
}

void firstRegistration()
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
	addFileUser(user);
	cout << "����������� �������\n\n";
}