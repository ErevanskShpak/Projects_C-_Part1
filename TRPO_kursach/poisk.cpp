#include "poisk.h"

bool poiskAverageBall(vector<Student> vec_of_stud)
{
	cout << "Введите искомый минимальный средний балл: ";
	double ball_poisk = inputNumber(0, 10);
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].info.average_ball >= ball_poisk)
		{
			outputStud(vec_of_stud[i]);
			isFind = 1;
		}
	}
	if (isFind) //проверка на нахождение хотя бы одного студента
		return 1;
	else
		return 0;
}

bool poiskFio(vector<Student> vec_of_stud)
{
	cout << "Введите искомое ФИО: ";
	char fio_poisk[100];
	inputFio(fio_poisk);
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
		{
			outputStud(vec_of_stud[i]);
			return 1;
		}
	}
	return 0;
}

bool poiskGroup(vector<Student> vec_of_stud)
{
	cout << "Введите искомый номер группы: ";
	int group_poisk = inputNumber(100000, 999999);
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].group == group_poisk)
		{
			outputStud(vec_of_stud[i]);
			isFind = 1;
		}
	}
	if (isFind) //проверка на нахождение хотя бы одного студента
		return 1;
	else
		return 0;
}

void poiskStud(vector<Student> vec_of_stud)
{
	cout << "------Поиск записей о студентах------\n";
	if (!isEmpty(vec_of_stud))
		return;	
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Меню поиска:\n";
		cout << "1. По ФИО\n";
		cout << "2. По минимальному среднему баллу\n";
		cout << "3. По номеру группы\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 3);
		switch (lever)
		{
		case 1:
			if (!poiskFio(vec_of_stud)) //проверка на нахождение хотя бы одного студента
				cout << "Нет студентов с такой ФИО\n";
			break;
		case 2:
			if (!poiskAverageBall(vec_of_stud)) //проверка на нахождение хотя бы одного студента
				cout << "Нет студентов с таким средним баллом\n";
			break;
		case 3:
			if (!poiskGroup(vec_of_stud)) //проверка на нахождение хотя бы одного студента
				cout << "Нет студентов с таким номером группы\n";
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}