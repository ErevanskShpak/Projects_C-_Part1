#include "sort.h"

void sortStudByFio(vector<Student>& vec_of_stud)
{
	sort(vec_of_stud.begin(), vec_of_stud.end(), partSortByFio);
	cout << "Сортировка завершена\n\n";
	showStudVec(vec_of_stud);
}

bool partSortByFio(Student student_a, Student student_b)
{
	string a = student_a.fio;
	string b = student_b.fio;
	return a < b;
}

void sortStudByAverageBall(vector<Student>& vec_of_stud)
{
	sort(vec_of_stud.begin(), vec_of_stud.end(), partSortByAverageBall);
	cout << "Сортировка завершена\n\n";
	showStudVec(vec_of_stud);
}

bool partSortByAverageBall(Student student_a, Student student_b)
{
	return student_a.info.average_ball > student_b.info.average_ball;
}

void sortStudByGroup(vector<Student>& vec_of_stud)
{
	sort(vec_of_stud.begin(), vec_of_stud.end(), partSortByGroup);
	cout << "Сортировка завершена\n\n";
	showStudVec(vec_of_stud);
}

bool partSortByGroup(Student student_a, Student student_b)
{
	return student_a.group < student_b.group;
}

void sortStud(vector<Student>& vec_of_stud)
{
	cout << "------Сортировка записей о студентах------\n";
	if (!isEmpty(vec_of_stud))
		return;
	int lever = 0;
	bool menu = 1;
	while (menu)
	{
		cout << "Меню сортировки:\n";
		cout << "1. По алфавиту\n";
		cout << "2. По убыванию среднего балла\n";
		cout << "3. По возрастанию номера группы\n";
		cout << "0. Назад\n";
		cout << "Выберите пункт меню: ";
		lever = inputNumber(0, 3);
		switch (lever)
		{
		case 1:
			sortStudByFio(vec_of_stud);
			break;
		case 2:
			sortStudByAverageBall(vec_of_stud);
			break;
		case 3:
			sortStudByGroup(vec_of_stud);
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
}