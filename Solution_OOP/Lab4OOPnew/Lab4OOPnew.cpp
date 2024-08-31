#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class LocalTime;
class LocalDate;
class LocalDateTime;
class Route;
class Stack;
class Stack2;
class Stack3;
class Stack4;

class Basis {
protected:
	string nazv;
public:
	void nazv_func() {
		cout << "Введите название маршрута\n";
		cin.ignore();
		getline(cin, nazv);
	}
	virtual void getData() = 0;
	virtual void setData() = 0;
};

class LocalTime : public Basis {
protected:
	string time;
public:
	void setData() {
		nazv_func();
		cout << "Введите время отправки\n";
		cin.ignore();
		getline(cin, time);
	}
	void getData() {
		cout << "Маршрут " << nazv << "\nВремя отправки: " << time << endl << endl;
	}
};

class LocalDate : public Basis {
protected:
	string date;
public:
	void setData() {
		nazv_func();
		cout << "Введите дату отправки\n";
		cin.ignore();
		getline(cin, date);
	}
	void getData() {
		cout << "Маршрут " << nazv << "\nДата отправки: " << date << endl << endl;
	}
};

class LocalDateTime : public LocalTime, public LocalDate {
protected:
	string nazv2;
public:
	void setData() {
		cout << "Введите название маршрута: ";
		cin.ignore();
		getline(cin, nazv2);
		cout << "Введите дату отправки\n";
		cin.ignore();
		getline(cin, date);
		cout << "Введите время отправки\n";
		cin.ignore();
		getline(cin, time);
	}
	void getData() {
		cout << "Дата отправки: " << date << "\nВремя отправки: " << time << endl << endl;
	}
};

class Route : public LocalDateTime {
	int kilo = 0;
public:
	Route() : kilo(0) {}
	Route(string date, string time, string nazv, int kilo) {
		this->date = date;
		this->time = time;
		this->nazv2 = nazv;
		this->kilo = kilo;
	}
	Route(const Route& ob) {
		nazv2 = ob.nazv2;
		date = ob.date;
		time = ob.time;
		kilo = ob.kilo;
	}
	void setData() {
		cout << "Введите название маршрута: ";
		cin.ignore();
		getline(cin, nazv2);
		cout << "Введите дату отправки\n";
		cin.ignore();
		getline(cin, date);
		cout << "Введите время отправки\n";
		cin.ignore();
		getline(cin, time);
		cout << "Введите километраж маршрута: ";
		cin >> kilo;
	}
	void getData() {
		cout << "Маршрут " << nazv2;
		cout << "\nДата отправки: " << date << "\nВремя отправки: " << time;
		cout << "\nКилометраж: " << kilo << endl << endl;
	}
	friend void seek(Stack*, FILE*, char*);
};

class Stack
{
	Route info;
	Stack* next = NULL;

	friend void push(Stack*& start, Route in)
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
		cout << "\nПолноценные\n\n";
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
	friend void seek(Stack*, FILE*, char*);
};

class Stack2
{
	LocalDateTime info;
	Stack2* next = NULL;

	friend void push2(Stack2*& start, LocalDateTime in)
	{
		Stack2* tool;
		tool = new Stack2;
		tool->info = in;
		tool->next = start;
		start = tool;
	}
	friend void show2(Stack2* start)
	{
		Stack2* tool;
		tool = start;
		cout << "\nПо дате и времени\n\n";
		while (tool != NULL)
		{
			tool->info.getData();
			tool = tool->next;
		}
	}
	friend void pop_all2(Stack2*& start)
	{
		Stack2* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next;
			delete tool;
		}
	}
};

class Stack3
{
	LocalDate info;
	Stack3* next = NULL;

	friend void push3(Stack3*& start, LocalDate in)
	{
		Stack3* tool;
		tool = new Stack3;
		tool->info = in;
		tool->next = start;
		start = tool;
	}
	friend void show3(Stack3* start)
	{
		Stack3* tool;
		tool = start;
		cout << "\nПо дате\n\n";
		while (tool != NULL)
		{
			tool->info.getData();
			tool = tool->next;
		}
	}
	friend void pop_all3(Stack3*& start)
	{
		Stack3* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next;
			delete tool;
		}
	}
};

class Stack4
{
	LocalTime info;
	Stack4* next = NULL;

	friend void push4(Stack4*& start, LocalTime in)
	{
		Stack4* tool;
		tool = new Stack4;
		tool->info = in;
		tool->next = start;
		start = tool;
	}
	friend void show4(Stack4* start)
	{
		Stack4* tool;
		tool = start;
		cout << "\nПо времени\n\n";
		while (tool != NULL)
		{
			tool->info.getData();
			tool = tool->next;
		}
	}
	friend void pop_all4(Stack4*& start)
	{
		Stack4* tool;
		while (start != NULL)
		{
			tool = start;
			start = start->next;
			delete tool;
		}
	}
};

void seek(Stack* start, FILE* file, char* filename)
{
	file = fopen(filename, "a");
	Stack* t = start;
	Stack* r = t;
	while (t != NULL)
	{
		if (t->info.kilo < r->info.kilo)
			r = t;
		t = t->next;
	}
	t = start;
	while (t != NULL)
	{
		if (t->info.kilo == r->info.kilo)
		{
			t->info.getData();
			fwrite(&(t->info), sizeof(Route), 1, file);
		}
		t = t->next;
	}
	fclose(file);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* start = NULL;
	Stack2* start2 = NULL;
	Stack3* start3 = NULL;
	Stack4* start4 = NULL;
	bool menu = 1;
	int lever;
	FILE* file = NULL;
	char filename[30] = "";
	cout << "Введите имя файла\n";
	cin >> filename;
	while (menu)
	{
		cout << "Меню:" << endl;
		cout << "1. Добавить в список Маршрут только с временем" << endl;
		cout << "2. Добавить в список Маршрут только с датой" << endl;
		cout << "3. Добавить в список Маршрут без километража" << endl;
		cout << "4. Добавить в список полноценный Маршрут" << endl;
		cout << "5. Просмотреть список" << endl;
		cout << "6. Удалить содержимое списка" << endl;
		cout << "7. Найти маршруты с наименьшим километражем" << endl;
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
			LocalTime oop1, * op1 = &oop1;
			op1->setData();
			push4(start4, oop1);
			break;
		}
		case 2:
		{
			LocalDate oop2, * op2 = &oop2;
			op2->setData();
			push3(start3, oop2);
			break;
		}
		case 3:
		{
			LocalDateTime oop3, * op3 = &oop3;
			op3->setData();
			push2(start2, oop3);
			break;
		}
		case 4:
		{
			Route oop4, * op4 = &oop4;
			op4->setData();
			push(start, oop4);
			break;
		}
		case 5:
			if (start == NULL && start2 == NULL && start3 == NULL && start4 == NULL) {
				cout << "Список пуст\n";
				break;
			}
			show(start);
			show2(start2);
			show3(start3);
			show4(start4);
			break;
		case 6:
			pop_all(start);
			pop_all2(start2);
			pop_all3(start3);
			pop_all4(start4);
			cout << "Удаление завершено\n";
			break;
		case 7:
			seek(start, file, filename);
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