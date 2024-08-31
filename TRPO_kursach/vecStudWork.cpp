#include "vecStudWork.h"

Student inputStud()
{
	Student stud;
	cout << "Введите номер группы: ";
	stud.group = inputNumber(100000, 999999);
	cout << "Введите ФИО студента: ";
	inputFio(stud.fio);
	int i = 0;
	cout << "Введите оценки студента по пяти экзаменам\n";
	for (; i < 5; i++)
	{
		cout << "Введите оценку ";
		switch (i)
		{
		case 0:
			cout << "по математике: ";
			break;
		case 1:
			cout << "по физике: ";
			break;
		case 2:
			cout << "по ТРПО: ";
			break;
		case 3:
			cout << "по ОАИП: ";
			break;
		case 4:
			cout << "по ООП: ";
			break;
		}
		stud.info.marks[i] = inputNumber(0, 10);
		stud.info.average_ball += stud.info.marks[i];
	}
	stud.info.average_ball /= 5.;
	cout << "Введите сведения о зачетах студента\n" << "Если студент получил зачет, введите 1, иначе введите 0\n";
	for (i = 0; i < 5; i++)
	{
		cout << "Введите зачет ";
		switch (i)
		{
		case 0:
			cout << "по физкультуре: ";
			break;
		case 1:
			cout << "по логике: ";
			break;
		case 2:
			cout << "по ДМ: ";
			break;
		case 3:
			cout << "по ОКГ: ";
			break;
		case 4:
			cout << "по ИКИ: ";
			break;
		}
		stud.info.zacheti[i] = inputNumber(0, 1);
	}
		getDolg(stud);
	return stud;
}

void getDolg(Student& stud)
{
	for (int i = 0; i < 5; i++)
		if (stud.info.zacheti[i] == 0)
			stud.info.dolg++;
}

//void outputStud(Student stud)
//{
//	cout << "\nНомер группы: " << stud.group;
//	cout << "\nФИО: " << stud.fio;
//	cout << "\nОценки\n";
//	int i = 0;
//	cout << "Математика: " << stud.info.marks[i++];
//	cout << "   Физика: " << stud.info.marks[i++];
//	cout << "   ТРПО: " << stud.info.marks[i++];
//	cout << "   ОАИП: " << stud.info.marks[i++];
//	cout << "   ООП: " << stud.info.marks[i];
//	cout << "\nСредний балл: " << stud.info.average_ball;
//	cout << "\nСведения о зачетах\n";
//	i = 0;
//	cout << "Физкультура: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   Логика: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ДМ: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ОКГ: " << isZachet(stud.info.zacheti[i++]);
//	cout << "   ИКИ: " << isZachet(stud.info.zacheti[i]) << endl;
//}

void outputStud(Student stud)
{
	cout << "|" << setw(14) << stud.group;
	cout << "|" << setw(29) << stud.fio;
	int i = 0;
	cout << "|" << setw(12) << stud.info.marks[i++];
	cout << "|" << setw(8) << stud.info.marks[i++];
	cout << "|" << setw(6) << stud.info.marks[i++];
	cout << "|" << setw(6) << stud.info.marks[i++];
	cout << "|" << setw(5) << stud.info.marks[i];
	cout << "|" << setw(14) << stud.info.average_ball;
	i = 0;
	cout << "|" << setw(13) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i++]);
	cout << "|" << setw(8) << isZachet(stud.info.zacheti[i]) << "|";
}

void generateStudVec(vector<Student>& vec_of_stud)
{
	vec_of_stud.reserve(getCountOfStudInFile());
}

void deleteStudVec(vector<Student>& vec_of_stud)
{
	vector<Student>().swap(vec_of_stud);
}

void addStudInVec(vector<Student>& vec_of_stud)
{
	cout << "------Добавление записи о студенте------\n";
	Student stud = inputStud();
	vec_of_stud.push_back(stud);
	cout << "Добавление завершено\n";
	addFileStud(stud);
}

void delStudFromVec(vector<Student>& vec_of_stud)
{
	cout << "------Удаление записи о студенте------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "Введите ФИО студента, запись о котором надо удалить: ";
	int number_of_deleted_stud = poiskFioForDelAndRed(vec_of_stud);
	if (number_of_deleted_stud == -1) //проверка на нахождение студента
		return;
	cout << "Вы уверены, что хотите удалить информацию о студенте?\n";
	cout << "1. Да\n";
	cout << "0. Нет\n";
	cout << "Выбор: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) //подтверждение удаления данных о студенте
	{
		vector<Student>::iterator itErase = vec_of_stud.begin();
		vec_of_stud.erase(itErase + number_of_deleted_stud);
		cout << "Удаление завершено\n";
		writeFileStud(vec_of_stud);
	}
}

void redactStudFromVec(vector<Student>& vec_of_stud)
{
	cout << "------Редактирование записи о студенте------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "Введите ФИО студента, информацию о котором надо отредактировать: ";
	int number_of_redact_stud = poiskFioForDelAndRed(vec_of_stud);
	if (number_of_redact_stud == -1) //проверка на нахождение студента
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Что надо отредактировать?\n";
		cout << "1. Номер группы студента\n";
		cout << "2. ФИО студента\n";
		cout << "3. Оценки студента\n";
		cout << "4. Сведения о зачетах студента\n";
		cout << "0. Выйти из редактирования\n";
		cout << "Выбор: ";
		lever = inputNumber(0, 4);
		switch (lever)
		{
		case 1:
			cout << "Введите новый номер группы: ";
			vec_of_stud[number_of_redact_stud].group = inputNumber(100000, 999999);
			isUsed = 1;
			break;
		case 2:
			cout << "Введите новое ФИО: ";
			inputFio(vec_of_stud[number_of_redact_stud].fio);
			isUsed = 1;
			break;
		case 3:
			vec_of_stud[number_of_redact_stud].info.average_ball = 0;
			cout << "Введите новые оценки студента по пяти экзаменам\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "Введите оценку ";
				switch (i)
				{
				case 0:
					cout << "по математике: ";
					break;
				case 1:
					cout << "по физике: ";
					break;
				case 2:
					cout << "по ТРПО: ";
					break;
				case 3:
					cout << "по ОАИП: ";
					break;
				case 4:
					cout << "по ООП: ";
					break;
				}
				vec_of_stud[number_of_redact_stud].info.marks[i] = inputNumber(0, 10);
				vec_of_stud[number_of_redact_stud].info.average_ball += vec_of_stud[number_of_redact_stud].info.marks[i];
			}
			vec_of_stud[number_of_redact_stud].info.average_ball /= 5.;
			isUsed = 1;
			break;
		case 4:
			vec_of_stud[number_of_redact_stud].info.dolg = 0;
			cout << "Введите новые сведения о зачетах студента\n" << "Если студент получил зачет, введите 1, иначе введите 0\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "Введите зачет ";
				switch (i)
				{
				case 0:
					cout << "по физкультуре: ";
					break;
				case 1:
					cout << "по логике: ";
					break;
				case 2:
					cout << "по ДМ: ";
					break;
				case 3:
					cout << "по ОКГ: ";
					break;
				case 4:
					cout << "по ИКИ: ";
					break;
				}
				vec_of_stud[number_of_redact_stud].info.zacheti[i] = inputNumber(0, 1);
			}
			getDolg(vec_of_stud[number_of_redact_stud]);
			isUsed = 1;
			break;
		case 0:
			menu = 0;
		}
		cout << endl;
	}
	if (isUsed) //проверка, было ли проведено редактирование чего-либо
	{
		cout << "Редактирование завершено\n";
		writeFileStud(vec_of_stud);
	}
}

int poiskFioForDelAndRed(vector<Student> vec_of_stud)
{
	char fio_poisk[100];
	inputFio(fio_poisk);
	int number_poisk = 0;
	int kolvo_stud = vec_of_stud.size();
	for (int i = 0; i < kolvo_stud; i++)
	{
		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
			return number_poisk;
		number_poisk++;
	}
	cout << "Нет студента с такой ФИО\n";
	return -1;
}

//int poiskFioForDelAndRed(vector<Student> vec_of_stud)
//{
//	char fio_poisk[100];
//	inputFio(fio_poisk);
//	int number_poisk = 0;
//	int kolvo_stud = vec_of_stud.size();
//	for (int i = 0; i < kolvo_stud; i++)
//	{
//		if (!strcmp(vec_of_stud[i].fio, fio_poisk))
//			break;
//		number_poisk++;
//	}
//	if (number_poisk == kolvo_stud)
//	{
//		cout << "Нет студента с такой ФИО\n";
//		number_poisk = -1;
//	}
//	return number_poisk;
//}

void showStudVec(vector<Student> vec_of_stud)
{
	cout << "------Просмотр всех записей студентов------\n";
	if (!isEmpty(vec_of_stud))
		return;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|              |                             |                  Оценки                 |              |               Сведения о зачетах                |\n";
	cout << "| Номер группы |             ФИО             |-----------------------------------------| Средний балл |-------------------------------------------------|\n";
	cout << "|              |                             | Математика | Физика | ТРПО | ОАИП | ООП |              | Физкультура | Логика |   ДМ   |   ОКГ  |   ИКИ  |\n";
	cout << "|" << setw(8) << "Логин" << setw(4) << "|\n";
	int kolvo_stud = vec_of_stud.size();
	for (int i = 0; i < kolvo_stud; i++)
	{
		cout << "|--------------|-----------------------------|------------|--------|------|------|-----|--------------|-------------|--------|--------|--------|--------|\n";
		outputStud(vec_of_stud[i]);
		cout << endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}