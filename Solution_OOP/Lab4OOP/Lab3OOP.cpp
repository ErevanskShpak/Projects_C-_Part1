#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Stack;
class Stack2;
class Stack3;
class Worker;
class Head;
class IT;

class Person {
protected:
	string fio;
	string age;
	string adress;
public:
	void getData()
	{
		cout << "ФИО: " << fio << endl;
		cout << "Дата рождения: " << age << endl;
		cout << "Адрес регистрации: " << adress << endl;
	}
	void setData() {
		cin.ignore();
		cout << "Введите ФИО: ";
		getline(cin, fio);
		cout << "Введите дату рождения: ";
		getline(cin, age);
		cout << "Введите адрес регистрации: ";
		getline(cin, adress);
	}
	friend class Stack;
	friend class Stack2;
	friend class Stack3;
	friend void seek(Stack*, Stack2*, Stack3*, FILE*, char*);
};

class Worker : public Person {
public:
	void getData()
	{
		Person::getData();
		cout << endl;
	}
	friend class Stack;
};

class Head : public Person {
	int podch=0;
public:
	void getData()
	{
		Person::getData();
		cout << "Кол-во подчиненных: " << podch << endl << endl;
	}
	void setData() {
		Person::setData();
		cout << "Введите кол-во подчиненных: ";
		cin >> podch;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> podch;
		}
	}
	friend class Stack2;
};

class IT : public Person {
	int stagh=0;
public:
	void getData()
	{
		Person::getData();
		cout << "Стаж работы: " << stagh << endl << endl;
	}
	void setData() {
		Person::setData();
		cout << "Введите стаж работы: ";
		cin >> stagh;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> stagh;
		}
	}
	friend class Stack3;
};

class Stack
{
	Worker info;
	Stack* next = NULL;

	friend void push(Stack*& start, Worker in)
	{
		Stack* tool;
		tool = new Stack;
		tool->info = in;
		tool->next = start;
		start = tool;
	}
	friend void show(Stack* start)
	{
		Stack* tool;
		tool = start;
		cout <<"\nРабочие\n";
		while (tool != NULL)
		{
			tool->info.getData();
			tool = tool->next;
		}
	}
	friend void pop_all(Stack*& start)
	{
		Stack* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next;
			delete tool;
		}
	}
	friend void seek(Stack*, Stack2*, Stack3*, FILE*, char*);
};

class Stack2
{
	Head info2;
	Stack2* next2 = NULL;

	friend void push2(Stack2*& start, Head in)
	{
		Stack2* tool;
		tool = new Stack2;
		tool->info2 = in;
		tool->next2 = start;
		start = tool;
	}
	friend void show2(Stack2* start)
	{
		Stack2* tool;
		tool = start;
		cout << "\nРуководители\n";
		while (tool != NULL)
		{
			tool->info2.getData();
			tool = tool->next2;
		}
	}
	friend void pop_all2(Stack2*& start)
	{
		Stack2* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next2;
			delete tool;
		}
	}
	friend void seek(Stack*, Stack2*, Stack3*, FILE*, char*);
};

class Stack3
{
	IT info3;
	Stack3* next3=NULL;

	friend void push3(Stack3*& start, IT in)
	{
		Stack3* tool;
		tool = new Stack3;
		tool->info3 = in;
		tool->next3 = start;
		start = tool;
	}
	friend void show3(Stack3* start)
	{
		Stack3* tool;
		tool = start;
		cout << "\nIT-сотрудники\n";
		while (tool != NULL)
		{
			tool->info3.getData();
			tool = tool->next3;
		}
	}
	friend void pop_all3(Stack3*& start)
	{
		Stack3* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next3;
			delete tool;
		}
	}
	friend void seek(Stack*, Stack2*, Stack3*, FILE*, char*);
};

void seek(Stack* start, Stack2* start2, Stack3* start3, FILE* file, char* filename)
{
	bool lever = 1;
	cout << "Введите интересующий адрес регистрации: ";
	string key;
	cin.ignore();
	getline(cin, key);
	file = fopen(filename, "a");
	Stack* t = start;
	while (t != NULL)
	{
		if (t->info.adress == key)
		{
			lever = 0;
			t->info.getData();
			fwrite(&(t->info), sizeof(Worker), 1, file);
		}
		t = t->next;
	}
	Stack2* t2 = start2;
	while (t2 != NULL)
	{
		if (t2->info2.adress == key)
		{
			lever = 0;
			t2->info2.getData();
			fwrite(&(t2->info2), sizeof(Head), 1, file);
		}
		t2 = t2->next2;
	}
	Stack3* t3 = start3;
	while (t3 != NULL)
	{
		if (t3->info3.adress == key)
		{
			lever = 0;
			t3->info3.getData();
			fwrite(&(t3->info3), sizeof(IT), 1, file);
		}
		t3 = t3->next3;
	}
	fclose(file);
	if (lever)
		cout << "Нет таких людей";
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* start = NULL;
	Stack2* start2 = NULL;
	Stack3* start3 = NULL;
	bool menu = 1;
	int lever;
	FILE* file = NULL;
	char filename[30] = "";
	cout << "Введите имя файла\n";
	cin >> filename;
	while (menu)
	{
		cout << "Меню:" << endl;
		cout << "1. Добавить в список Рабочего" << endl;
		cout << "2. Добавить в список Руководителя" << endl;
		cout << "3. Добавить в список IT-сотрудника" << endl;
		cout << "4. Просмотреть список" << endl;
		cout << "5. Удалить содержимое списка" << endl;
		cout << "6. Найти людей по адресу" << endl;
		cout << "0. Выход" << endl;
		cin >> lever;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin >> lever;
		}
		switch (lever)
		{
		case 1:
		{
			Worker op1;
			op1.setData();
			push(start, op1);
			break;
		}
		case 2:
		{
			Head op1;
			op1.setData();
			push2(start2, op1);
			break;
		}
		case 3:
		{
			IT op1;
			op1.setData();
			push3(start3, op1);
			break;
		}
		case 4:
			if (start == NULL && start2 == NULL && start3 == NULL) {
				cout << "Список пуст\n";
				break;
			}
			show(start);
			show2(start2);
			show3(start3);
			break;
		case 5:
			pop_all(start);
			pop_all2(start2);
			pop_all3(start3);
			cout << "Удаление завершено\n";  
			break;
		case 6:
			seek(start, start2, start3, file, filename);
			break;
		case 0:
			menu = 0;
			break;
		default:
			cout << "Некорректный ввод. Повторите попытку\n";
		}
	}
	return 0;
}