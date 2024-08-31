#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

struct User {
	char login[20];
	long long salted_hash_password = 0;
	char salt[5];
	bool role = 0;
	bool access = 1;
};
static const char* FILE_OF_USERS = "user.txt";


int main()
{
	setlocale(LC_ALL, "ru");
	char a[17];
	char b[17];
	cin.getline(a, 16);
	cin.getline(b, 16);
	if (strcmp(a, b) == 0)
	{
		cout << "Равны";
	}
	else
		cout << "ЯПошел нахуй";
}