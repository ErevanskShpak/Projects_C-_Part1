#include "vecHockModule.h"

Hockey inputHock()
{
	Hockey hock;
	cout << "Введите ФИО хоккеиста: ";
	inputFio(hock.fio);
	cout << "Введите дату рождения хоккеиста: ";
	inputDate(hock.date);
	cout << "Введите количество сыгранных матчей хоккеиста: ";
	hock.info.match = inputNumber(0, 2000);
	cout << "Введите число заброшенных шайб хоккеиста: ";
	hock.info.puck = inputNumber(0, 1000);
	cout << "Введите количество голевых передач хоккеиста: ";
	hock.info.assist = inputNumber(0, 2000);
	cout << "Введите количество штрафных минут хоккеиста: ";
	hock.info.time = inputNumber(0, 10000);
	return hock;
}

void outputHock(Hockey hock)
{
	cout << "|-----------------------------|-----------|-----------------|-------------------|------------------|-----------------|\n";
	cout << "|" << setw(29) << hock.fio;
	cout << "|" << setw(11) << hock.date;
	cout << "|" << setw(17) << hock.info.match;
	cout << "|" << setw(19) << hock.info.puck;
	cout << "|" << setw(18) << hock.info.assist;
	cout << "|" << setw(17) << hock.info.time << "|\n";
}

void generateVecOfHock(vector<Hockey>& vecHock)
{
	vecHock.reserve(getAmountOfHockInFile());
}

void deleteVecOfHock(vector<Hockey>& vecHock)
{
	vector<Hockey>().swap(vecHock);
}

void showVecOfHock(vector<Hockey> vecHock)
{
	cout << "------Просмотр всех записей хоккеистов------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "|             ФИО             |    Дата   | Сыгранные матчи | Заброшенные шайбы | Голевые передачи | Штрафные минуты |\n";
	int amountHock = vecHock.size();
	for (int i = 0; i < amountHock; i++)
		outputHock(vecHock[i]);
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
}

void addHockInVec(vector<Hockey>& vecHock)
{
	cout << "------Добавление записи о хоккеисте------\n";
	Hockey hock = inputHock();
	vecHock.push_back(hock);
	cout << "Добавление завершено\n";
	addFileOfHock(hock);
}

int searchHockForDeleteAndEdit(vector<Hockey> vecHock)
{
	char fioSearch[100];
	inputFio(fioSearch);
	int numberSearch = 0;
	int amountHock = vecHock.size();
	for (int i = 0; i < amountHock; i++)
	{
		if (!strcmp(vecHock[i].fio, fioSearch))
			return numberSearch;
		numberSearch++;
	}
	cout << "Нет хоккеиста с такой ФИО\n";
	return -1;
}

void deleteHockFromVec(vector<Hockey>& vecHock)
{
	cout << "------Удаление записи о хоккеисте------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "Введите ФИО хоккеиста, информацию о котором надо удалить: ";
	int numberDeleteHock = searchHockForDeleteAndEdit(vecHock);
	if (numberDeleteHock == -1) //проверка на нахождение студента
		return;
	cout << "Вы уверены, что хотите удалить информацию о хоккеисте?\n";
	cout << "1. Да\n";
	cout << "0. Нет\n";
	cout << "Выбор: ";
	bool isAgree = inputNumber(0, 1);
	if (isAgree) //подтверждение удаления данных о студенте
	{
		vector<Hockey>::iterator itErase = vecHock.begin();
		vecHock.erase(itErase + numberDeleteHock);
		cout << "Удаление завершено\n";
		writeFileOfHock(vecHock);
	}
}

void editHockFromVec(vector<Hockey>& vecHock)
{
	cout << "------Редактирование записи о хоккеисте------\n";
	if (!isEmpty(vecHock))
		return;
	cout << "Введите ФИО хоккеиста, запись о котором надо отредактировать: ";
	int numberEditHock = searchHockForDeleteAndEdit(vecHock);
	if (numberEditHock == -1) //проверка на нахождение студента
		return;
	bool isUsed = 0;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Что требуется отредактировать?\n";
		cout << "1. ФИО хоккеиста\n";
		cout << "2. Дата рождения хоккеиста\n";
		cout << "3. Кол-во сыгранных матчей\n";
		cout << "4. Число заброшенных шайб\n";
		cout << "5. Кол-во голевых передач\n";
		cout << "6. Кол-во штрафных минут\n";
		cout << "0. Выйти из редактирования\n";
		cout << "Выбор: ";
		lever = inputNumber(0, 4);
		switch (lever)
		{
		case 1:
			cout << "Введите новое ФИО: ";
			inputFio(vecHock[numberEditHock].fio);
			isUsed = 1;
			break;
		case 2:
			cout << "Введите новую дату рождения: ";
			inputDate(vecHock[numberEditHock].date);
			isUsed = 1;
			break;
		case 3:
			cout << "Введите новое кол-во сыгранных матчей: ";
			vecHock[numberEditHock].info.match = inputNumber(0, 2000);
			isUsed = 1;
			break;
		case 4:
			cout << "Введите новое число заброшенных шайб: ";
			vecHock[numberEditHock].info.puck = inputNumber(0, 1000);
			isUsed = 1;
			break;
		case 5:
			cout << "Введите новое кол-во голевых передач: ";
			vecHock[numberEditHock].info.assist = inputNumber(0, 2000);
			isUsed = 1;
			break;
		case 6:
			cout << "Введите новое кол-во штрафных минут: ";
			vecHock[numberEditHock].info.time = inputNumber(0, 10000);
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
		writeFileOfHock(vecHock);
	}
}