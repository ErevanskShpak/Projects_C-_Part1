#include "individ.h"

void sortStudByDolg(vector<Student>& vec_of_stud)
{
	sort(vec_of_stud.begin(), vec_of_stud.end(), partSortByDolg);
}

bool partSortByDolg(Student student_a, Student student_b)
{
	return student_a.info.dolg > student_b.info.dolg;
}

void showByDolg(vector<Student> vec_of_stud)
{
	cout << "------Просмотр записей о студентах в порядке убывания задолженностей------\n";
	if (!isEmpty(vec_of_stud)) //проверка на пустой файл записей о студентах
		return;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|              |                             |                  Оценки                 |              |               Сведения о зачетах                |                           |\n";
	cout << "| Номер группы |             ФИО             |-----------------------------------------| Средний балл |-------------------------------------------------| Количество задолженностей |\n";
	cout << "|              |                             | Математика | Физика | ТРПО | ОАИП | ООП |              | Физкультура | Логика |   ДМ   |   ОКГ  |   ИКИ  |                           |\n";
	sortStudByDolg(vec_of_stud);
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		cout << "|--------------|-----------------------------|------------|--------|------|------|-----|--------------|-------------|--------|--------|--------|--------|---------------------------|\n";
		outputStud(vec_of_stud[i]);
		cout << setw(27) << vec_of_stud[i].info.dolg << "|\n";
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void showByAverageBall(vector<Student> vec_of_stud)
{
	cout << "------Просмотр среднего балла студентов определенной группы------\n";
	if (!isEmpty(vec_of_stud)) //проверка на пустой файл записей о студентах
		return;
	int kolvo_in_group = 0;
	double general_average_ball = poiskGroupForAverageBall(vec_of_stud, kolvo_in_group);
	if (general_average_ball)
		cout << "\n\nСредний балл всей группы: " << general_average_ball / kolvo_in_group << endl;
}

double poiskGroupForAverageBall(vector<Student> vec_of_stud, int& kolvo_in_group)
{
	cout << "Введите искомый номер группы: ";
	int group_poisk = inputNumber(100000, 999999);
	double general_average_ball = 0;
	bool isFind = 0;
	for (int i = 0; i < vec_of_stud.size(); i++)
	{
		if (vec_of_stud[i].group == group_poisk)
		{
			outputStudAverageBall(vec_of_stud[i]);
			isFind = 1;
			general_average_ball += vec_of_stud[i].info.average_ball;
			kolvo_in_group++;
		}
	}
	if (!isFind)  //проверка на существавание хотя бы однго студента
		cout << "Нет студентов с таким номером группы\n";
	return general_average_ball;
}

void outputStudAverageBall(Student stud)
{
	cout << "\n\nФИО: " << stud.fio;
	cout << "\nСредний балл: " << stud.info.average_ball;
}