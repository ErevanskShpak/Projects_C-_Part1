#include <iostream>

using namespace std;

bool isNumberNumeric();

int main()
{
	setlocale(LC_ALL, "rus");
	bool menu = true;
	int lever;
	cout << "Choose lab work\n";
	cout << "1. First lab" << endl;
	cout << "0. Exit" << endl;
	cin >> lever;
	while (!isNumberNumeric() || !(lever>=0 && lever<=2)) {
		cout << "Incorrect input. Input must be consist of digits\n";
		cin >> lever;
	}
	switch (lever)
	{
	case 1:
		system("C:\\My_projects\\Solution_OOP_2Sem\\x64\\Debug\\Lab1_OOP.exe");
		break;
	case 2:
		system("C:\\My_projects\\Solution_OOP_2Sem\\x64\\Debug\\Lab2_OOP.exe");
		break;
	case 0:
		menu = false;
		break;
	}
	return 0;
}

bool isNumberNumeric() {
	if (std::cin.get() == '\n')
		return true;
	else {
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return false;
	}
}