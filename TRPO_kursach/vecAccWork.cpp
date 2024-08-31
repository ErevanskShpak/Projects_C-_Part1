#include "vecAccWork.h"

void generateUserVec(vector<User>& vec_of_user)
{
	vec_of_user.reserve(getCountOfUserInFile());
}

void deleteUserVec(vector<User>& vec_of_user)
{
	vector<User>().swap(vec_of_user);
}

bool inputUser(vector<User>& vec_of_user, User& user) {
	cout << "������� �����: ";
	inputLogin(user.login);
	int n = getCountOfUserInFile();
	for (int i = 0; i < n; i++)
		if (!strcmp(vec_of_user[i].login, user.login)) //�������� �� ��� ������������ �����
		{
			cout << "������� � ����� ������� ��� ����������!\n\n";
			return 1;
		}
	string password;
	inputPassword(password);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		user.salt[i] = (char)(rand() % 26 + 97);
	password = password + user.salt;
	user.salted_hash_password = hashFunc(password);
	vec_of_user.push_back(user);
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

void showUserVec(vector<User> vec_of_user)
{
	cout << "------�������� ���� ���������------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "|        �����       | ���� |       ���      | ���� | ������ |\n";
	int kolvo_user = vec_of_user.size();
	for (int i = 0; i < kolvo_user; i++)
		outputUser(vec_of_user[i]);
	cout << "--------------------------------------------------------------\n";
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

void delUserFromVec(vector<User>& vec_of_user, string current_login)
{
	cout << "------�������� ��������------\n";
	cout << "������� ����� ��������, ������� ���� �������: ";
	int number_of_deleted_user = poiskUserForDelAndRed(vec_of_user);
	if (number_of_deleted_user == -1) //�������� �� ���������� ��������
		return;
	if (vec_of_user[number_of_deleted_user].login == current_login) //�������� �� �������� ������������ ��������
	{
		cout << "�� �� ������ ������� ����������� �������\n";
		return;
	}
	cout << "�� �������, ��� ������ ������� ?\n";
	cout << "1. ��\n";
	cout << "0. ���\n";
	cout << "�����: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) ////�������� �� ��, ����� �� ������������ ������� ������
	{
		vector<User>::iterator itErase = vec_of_user.begin();
		vec_of_user.erase(itErase + number_of_deleted_user);
		cout << "�������� ���������\n";
		writeFileUser(vec_of_user);
	}
}

int poiskUserForDelAndRed(vector<User> vec_of_user)
{
	char login_poisk[100];
	inputLogin(login_poisk);
	int number_poisk = 0;
	int kolvo_stud = vec_of_user.size();
	for (int i = 0; i < kolvo_stud; i++)
	{
		if (!strcmp(vec_of_user[i].login, login_poisk))
			return number_poisk;
		number_poisk++;
	}
	cout << "��� �������� � ����� �������\n";
	return -1;
}

void redactUserFromVec(vector<User>& vec_of_user)
{
	cout << "------�������������� ��������------\n";
	cout << "������� ����� ��������, ������� ���� ���������������: ";
	int number_of_redact_user = poiskUserForDelAndRed(vec_of_user);
	if (number_of_redact_user == -1) //�������� �� ���������� ��������
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "��� ���� ���������������?\n";
		cout << "1. �����\n";
		cout << "2. ����\n";
		cout << "0. ����� �� ��������������\n";
		cout << "�����: ";
		lever = inputNumber(0, 2);
		switch (lever)
		{
		case 1:
			cout << "������� ����� �����: ";
			inputLogin(vec_of_user[number_of_redact_user].login);
			isUsed = 1;
			break;
		case 2:
			cout<<"��� ������� ���� �������������� ������� 1. ��� ������� ���� ������������ ������� 0\n";
			cout << "������� ����� ����: ";
			vec_of_user[number_of_redact_user].role = inputNumber(0, 1);
			isUsed = 1;
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	if (isUsed) //�������� �� ��, ���� �� ��������� �������������� ����-����
	{
		cout << "�������������� ���������\n";
		writeFileUser(vec_of_user);
	}
}