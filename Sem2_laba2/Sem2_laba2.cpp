#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

struct Student {
	char fio[40]{};
	int math = 0, physics = 0, inf = 0;
	double sr_ball = 0;
};

void create(char*);
void add(char*);
void show(Student*);
void show_all(char*);
void linPoisk(char*);
void quicksort_part(Student*, int&, int&);
void quicksort(char*);
void pryamVibor(char*);
void dvoichPoisk(char*);
int check(int);
double average(char*);
void show_average(char*);

struct Stack
{
	int info = 0;
	Stack* next = NULL;
};

void push(Stack*&, int);
void pop(Stack*&);

int main()
{
	setlocale(LC_ALL, "ru");
	bool menu = 1;
	int lever = 0;
	char filename[30] = "";
	cout << "Введите имя файла\n";
	cin >> filename;
	while (menu)
	{
		cout << "Меню:" << endl;
		cout << "1. Создать массив студентов в файле" << endl;
		cout << "2. Добавить нового студента в файл" << endl;
		cout << "3. Просмотреть весь файл" << endl;
		cout << "4. Удалить содержимое файла" << endl;
		cout << "5. Линейный поиск студента" << endl;
		cout << "6. Двоичный поиск студента" << endl;
		cout << "7. Quicksort содержимого файла" << endl;
		cout << "8. Сортировка методом прямого выбора содержимого файла" << endl;
		cout << "9. Найти средний балл по университету" << endl;
		cout << "10. Вывести студентов с баллом больше среднего по университету" << endl;
		cout << "0. Выход" << endl;
		lever = check(lever);
		switch (lever)
		{
		case 1:
			create(filename);
			break;
		case 2:
			add(filename);
			break;
		case 3:
			show_all(filename);
			break;
		case 4:
		{
			FILE* file = fopen(filename, "wb");
			fclose(file);
			cout << "Удаление завершено\n";
			break;
		}
		case 5:
			linPoisk(filename);
			break;
		case 6:
			quicksort(filename);
			dvoichPoisk(filename);
			break;
		case 7:
			quicksort(filename);
			break;
		case 8:
			pryamVibor(filename);
			break;
		case 9:
			if (double aver = average(filename))
				cout << "Средний балл по университету = " << aver << endl;
			else
				cout << "Файл пуст\n";
			break;
		case 10:
			pryamVibor(filename);
			show_average(filename);
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

void create(char* filename)
{
	int kolvo;
	cout << "Введите кол-во студентов\n";
	cin >> kolvo;
	FILE* file = fopen(filename, "ab");
	Student* arr = new Student[kolvo];
	for (int i = 0; i < kolvo; i++)
	{
		cout << "Введите ФИО " << i + 1 << "-го студента\n";
		cin.ignore();
		cin.getline(arr[i].fio, 40);
		cout << "Введите оценки " << i + 1 << "-го студента\n";
		arr[i].math = check(arr[i].math);
		arr[i].physics = check(arr[i].physics);
		arr[i].inf = check(arr[i].inf);
		arr[i].sr_ball = (arr[i].math + arr[i].physics + arr[i].inf) / 3.;
		fwrite(&arr[i], sizeof(Student), 1, file);
	}
	fclose(file);
	delete[]arr;
}

void add(char* filename)
{
	FILE* file = fopen(filename, "ab");
	Student s;
	cout << "Введите ФИО студента\n";
	cin.ignore();
	cin.getline(s.fio, 40);
	cout << "Введите оценки студента\n";
	s.math = check(s.math);
	s.physics = check(s.physics);
	s.inf = check(s.inf);
	s.sr_ball = (s.math + s.physics + s.inf) / 3.;
	fwrite(&s, sizeof(Student), 1, file);
	fclose(file);
}

void show(Student* s)
{
	cout << "Фамилия: " << s->fio << endl;
	cout << "Оценки:\nМатематика: " << s->math << "\nФизика: " << s->physics << " \nИнформатика: " << s->inf << endl;
	cout << "Ср балл: " << s->sr_ball << endl << endl;
}

void show_all(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	Student s;
	while (fread(&s, sizeof(Student), 1, file))
		show(&s);
	fclose(file);
}

void linPoisk(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	double sred;
	cout << "Введите минимальный средний балл, который должен быть у искомых студентов\n";
	cin >> sred;
	cout << endl;
	Student s;
	bool isBe = 0;
	while (fread(&s, sizeof(Student), 1, file))
	{
		if (s.sr_ball >= sred)
		{
			show(&s);
			isBe = 1;
		}
	}
	if (isBe == 0)
		cout << "Нет таких студентов\n";
	fclose(file);
}

void quicksort_part(Student* arr, int& i, int& j)
{
	Student r;
	double x = arr[(i + j) / 2].sr_ball;
	while (i <= j) {
		while (arr[i].sr_ball < x) i++;
		while (arr[j].sr_ball > x) j--;
		if (i <= j) {
			r = arr[i];
			arr[i] = arr[j];
			arr[j] = r;
			i++; j--;
		}
	}
}

void quicksort(char* filename)
{ 
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	int size = sizeof(Student);
	int kolvo = _filelength(_fileno(file)) / size;
	Student* arr, s;
	arr = new Student[kolvo];
	for (int i = 0; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	fclose(file);
	Stack* start = NULL;
	int left = 0, right = kolvo - 1, i = 0, j = 0;
	push(start, right);
	push(start, left);
	while (start != NULL)
	{
		left = (*start).info;
		right = (*(start->next)).info;
		pop(start);
		pop(start);
		quicksort_part(arr, i = left, j = right);
		if (left < j)
		{
			push(start, j);
			push(start, left);
		}
		if (i < right)
		{
			push(start, right);
			push(start, i);
		}
	}
	file = fopen(filename, "wb");
	for (i = 0; i < kolvo; i++)
		fwrite(&arr[i], size, 1, file);
	delete[]arr;
	fclose(file);
}

void push(Stack*& start, int in)
{
	Stack* tool = new Stack;
	tool->info = in;
	tool->next = start;
	start = tool;
}

void pop(Stack*& start)
{
	Stack* tool = start->next;
	delete start;
	start = tool;
}

void pryamVibor(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	int size = sizeof(Student);
	int kolvo = _filelength(_fileno(file)) / size;
	Student* arr, s, r;
	int i = 0;
	arr = new Student[kolvo];
	for (; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	fclose(file);
	int m = 0, j = 0;
	for (i = 0; i < kolvo - 1; i++) {
		m = i;
		for (j = i + 1; j < kolvo; j++)
			if (arr[j].sr_ball > arr[m].sr_ball) 
				m = j;
		r = arr[m];
		arr[m] = arr[i];
		arr[i] = r;
	}
	file = fopen(filename, "wb");
	for (i = 0; i < kolvo; i++)
		fwrite(&arr[i], size, 1, file);
	delete[]arr;
	fclose(file);
}

void dvoichPoisk(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	int size = sizeof(Student);
	int kolvo = _filelength(_fileno(file)) / size;
	Student* arr, s;
	arr = new Student[kolvo];
	for (int i = 0; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	fclose(file);
	double ball;
	int i_key = 0, j_key = kolvo - 1, m = 0;
	cout << "Введите средний балл, который должен быть у искомого студента\n";
	cin >> ball;
	while (i_key < j_key) {
		m = (i_key + j_key) / 2;
		if (arr[m].sr_ball < ball) i_key = m + 1;
		else j_key = m;
	}
	if (arr[i_key].sr_ball != ball)
		cout << "Нет такого студента\n";
	else
		show(&arr[i_key]);
	delete[]arr;
}

int check(int op)
{
	cin >> op;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Некорректный ввод, повторите попытку.\n";
		cin >> op;
	}
	return op;
}

double average(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return 0;
	}
	Student s;
	int kolvo = 0;
	double average_ball = 0;
	while (fread(&s, sizeof(Student), 1, file))
	{
		average_ball += s.sr_ball;
		kolvo++;
	}
	fclose(file);
	return average_ball / kolvo;
}

void show_average(char* filename)
{
	FILE* file = fopen(filename, "rb");
	if (_filelength(_fileno(file)) == 0)
	{
		cout << "Файл пуст\n";
		fclose(file);
		return;
	}
	Student s;
	double sred = average(filename);
	while (fread(&s, sizeof(Student), 1, file))
		if (s.sr_ball >= sred)
			show(&s);
	fclose(file);
}