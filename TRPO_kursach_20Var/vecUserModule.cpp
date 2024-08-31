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
	cout << "������� �����: ";
	inputLogin(user.login);
	int amountUser = getAmountOfUserInFile();
	for (int i = 0; i < amountUser; i++)
		if (!strcmp(vecUser[i].login, user.login)) //�������� �� ��� ������������ �����
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
	cout << "------�������� ���� ���������------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "|        �����       | ���� |       ���      | ���� | ������ |\n";
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
	cout << "��� �������� � ����� �������\n";
	return -1;
}

void deleteUserFromVec(vector<User>& vecUser, string current_login)
{
	cout << "------�������� ��������------\n";
	cout << "������� ����� ��������, ������� ���� �������: ";
	int numberDeleteUser = searchUserForDeleteOrEdit(vecUser);
	if (numberDeleteUser == -1) //�������� �� ���������� ��������
		return;
	if (vecUser[numberDeleteUser].login == current_login) //�������� �� �������� ������������ ��������
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
		vector<User>::iterator itErase = vecUser.begin();
		vecUser.erase(itErase + numberDeleteUser);
		cout << "�������� ���������\n";
		writeFileOfUser(vecUser);
	}
}

void editUserFromVec(vector<User>& vecUser)
{
	cout << "------�������������� ��������------\n";
	cout << "������� ����� ��������, ������� ���� ���������������: ";
	int numberEditUser = searchUserForDeleteOrEdit(vecUser);
	if (numberEditUser == -1) //�������� �� ���������� ��������
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
			inputLogin(vecUser[numberEditUser].login);
			isUsed = 1;
			break;
		case 2:
			cout<<"��� ������� ���� �������������� ������� 1. ��� ������� ���� ������������ ������� 0\n";
			cout << "������� ����� ����: ";
			vecUser[numberEditUser].role = inputNumber(0, 1);
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
		writeFileOfUser(vecUser);
	}
}