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
	virtual void getData() = 0;
	virtual void setData() = 0;
};

class LocalTime : public Basis {
protected:
	string time;
public:
	void setData() {
		cout << "Введите название маршрута\n";
		cin.ignore();
		getline(cin, nazv);
		cout << "Введите время отправки\n";
		cin.ignore();
		getline(cin, time);
	}
	void getData() {
		cout << "Маршрут " << nazv << "\nВремя отправки: " << time;
	}
};

class LocalDate : public Basis {
protected:
	string date;
public:
	void setData() {
		cout << "Введите название маршрута\n";
		cin.ignore();
		getline(cin, nazv);
		cout << "Введите дату отправки\n";
		cin.ignore();
		getline(cin, date);
	}
	void getData() {
		cout << "Маршрут " << nazv << "\nДата отправки: " << date;
	}
};

class LocalDateTime : public LocalTime, public LocalDate {
public:
	void setData() {
		cout << "Введите название маршрута\n";
		cin.ignore();
		getline(cin, nazv);
		cout << "Введите дату отправки\n";
		cin.ignore();
		getline(cin, date);
		cout << "Введите время отправки\n";
		cin.ignore();
		getline(cin, time);
	}
	void getData() {
		cout << "Дата отправки: " << date << "\nВремя отправки: " << time;
	}
};

class Route : public LocalDateTime {
	int kilo = 0;
public:
	Route(): date("Неизвестно"), time("Неизвестно"), nazv("Неизвестно"), kilo(0) {}
	Route(string date, string time, string nazv, int kilo) {
		this->date = date;
		this->time = time;
		this->nazv = nazv;
		this->kilo = kilo;
	}
	Route(const Route& ob) {
		nazv = ob.nazv;
		date = ob.date;
		time = ob.time;
		kilo = ob.kilo;
	}
	void setData() {
		cout << "Введите название маршрута: ";
		cin.ignore();
		getline(cin, nazv);
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
		cout << "Маршрут" << nazv;
		cout << "Дата отправки: " << date << "\nВремя отправки: " << time;
		cout << "Километраж: " << kilo;
	}
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
		cout << "Рабочие\n";
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
		cout << "Рабочие\n";
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
		cout << "Рабочие\n";
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
		cout << "Рабочие\n";
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

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* start = NULL;
	Stack2* start2 = NULL;
	Stack3* start3 = NULL;
	Stack4* start4 = NULL;
	bool menu = 1;
	int lever;
	/*FILE* file = NULL;
	char filename[30] = "";
	cout << "Введите имя файла\n";
	cin >> filename;*/
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
			LocalTime oop1, *op1=&oop1;
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
			if (start == NULL && start2 == NULL && start3 == NULL && start4 == NULL)
				cout << "Список пуст";
			show(start);
			show2(start2);
			show3(start3);
			show4(start4);
			break;
		case 6:
			pop_all(start);
			pop_all2(start2);
			pop_all3(start3);
			pop_all(start4);
			cout << "Удаление завершено";
			break;
		case 7:
			
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