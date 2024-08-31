#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <stdio.h>

using namespace std;

struct St
{
	char FIO[50];
	char Group[10];
	int math, physics, inf;
	double sr_ball;
};

void Create(FILE*);
void InfaStudentov(St);
void PokazatStudents(FILE*);
void Individ(FILE*);
void Redact(FILE*);
void Delete(FILE*);
bool SravnenieBukv(char[], char[]);
void SortFIO(FILE* file);
void Sort_Sr_ball_Vbivanie(FILE*);
void Sort_Sr_ball_Vozrastanie(FILE*);
void LinPoisk(FILE*);
void partition(St[], int&, int&);
void Quicksort(FILE*);
void PryamVibor(FILE*);
void DelPopolam(FILE*);

struct Stack
{
	int info;
	Stack* next;
};

void push(Stack*&, int);
void pop(Stack*&);

void Menu() 
{
	FILE* file = fopen("students_Lab7.txt", "rb");
	fclose(file);
	bool menu = 1;
	while (menu == 1) {
		cout << "1. Создать студента" << endl;
		cout << "2. Просмотреть всех студентов" << endl;
		cout << "3. Решение индивидуального задания" << endl;
		cout << "4. Изменить информацию" << endl;
		cout << "5. Удалить студента" << endl;
		cout << "6. Сортировка по фамилиям(по алфавиту)" << endl;
		cout << "7. Сортировка по среднему баллу(возрастание)" << endl;
		cout << "8. Сортировка по среднему баллу(убывание)" << endl;
		cout << "9. Линейный поиск" << endl;
		cout << "10. Quicksort" << endl;
		cout << "11. Сортировка методом прямого выбора" << endl;
		cout << "12. Поиск делением пополам" << endl;
		cout << "0. Выйти из программы" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1: 
			Create(file);
			break;
		case 2: 
			PokazatStudents(file); 
			break;
		case 3: 
			Individ(file);
			break;
		case 4: 
			Redact(file); 
			break;
		case 5: 
			Delete(file); 
			break;
		case 6: 
			SortFIO(file); 
			break;
		case 7: 
			Sort_Sr_ball_Vozrastanie(file); 
			break;
		case 8: 
			Sort_Sr_ball_Vbivanie(file); 
			break;
		case 9: 
			LinPoisk(file);
			break;
		case 10: 
			Quicksort(file); 
			break;
		case 11: 
			PryamVibor(file); 
			break;
		case 12: 
			Quicksort(file);
			DelPopolam(file); 
			break;
		case 0: 
			menu = 0; 
			break;
		default: cout << "Такого пункта нет"<<endl;
		}
	}
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	Menu();
	return 0;
}

void Create(FILE* file) 
{
	file = fopen("students_Lab7.txt", "ab");
	cout << "Введите фамилию, номер группы, оценки за математику, физику и информатику\n";
	St s;
	cin >> s.FIO >> s.Group >> s.math >> s.physics >> s.inf;
	s.sr_ball = (s.math + s.physics + s.inf) / 3.;
	fwrite(&s, sizeof(St), 1, file);
	fclose(file);
}

void InfaStudentov(St s)
{
	cout << "Фамилия: " << s.FIO << "\nГруппа: " << s.Group << endl;
	cout << "Оценки:\nМатематика: " << s.math << "\nФизика: " << s.physics << " \nИнформатика: " << s.inf << endl;
	cout << "Ср балл: " << s.sr_ball << endl << endl;
}

void PokazatStudents(FILE* file) 
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "rb");
	St s;
	while (fread(&s, size, 1, file))
		InfaStudentov(s);
	fclose(file);
}

void Individ(FILE* file) 
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "rb");
	St s;
	char choose[10];
	bool k1 = 0;
	cout << "Введите номер интересуюшей группы" <<endl;
	cin >> choose;
	cout << endl;
	while (fread(&s, size, 1, file))
	{
		if (!strcmp(s.Group, choose))
			if (s.sr_ball >= 9)
			{
				InfaStudentov(s);
				k1 = 1;
			}
	}
	if (k1 == 0) cout << "В этой группе нет отличников" << endl;
	fclose(file);
}

void Redact(FILE* file) 
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "r+b");
	cout << "Введите номер студента\n";
	int n;
	cin >> n;
	St s;
	fseek(file, size * (n-1), 0);
	cout << "Введите фамилию, номер группы, оценки за математику, физику и информатику\n";
	cin >> s.FIO >> s.Group >> s.math >> s.physics >> s.inf;
	s.sr_ball = (s.math + s.physics + s.inf) / 3;
	fwrite(&s, size, 1, file);
	fclose(file);
}

void Delete(FILE* file) 
{
	file = fopen("students_Lab7.txt", "r+b");
	int size = sizeof(St);
	int kolvo = _filelength(_fileno(file)) / size;
	int n;
	cout << "Введите номер студента" << endl;
	cin >> n;
	cout << "Вы уверены, что хотите удалить студента?\n 0.Да\n 1.Нет\n";
	bool choose;
	cin >> choose;
	if (choose == 0)
	{
		St s;
		for (int i = n-1; i < kolvo - 1; i++)
		{
			fseek(file, size, 1);
			fread(&s, size, 1, file);
			fseek(file, size * i, 0);
			fwrite(&s, size, 1, file);
		}
		kolvo--;
		int k = _chsize(_fileno(file), size * kolvo);
	}
	fclose(file);
}

bool SravnenieBukv(char a[], char b[])
{
	int i;
	for (i = 0;; i++)
	{
      if (a[i] > b[i]) return true;
	  if (a[i] < b[i]) return false;
	}
}

void SortFIO(FILE* file)
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "r+b");
	int kolvo = _filelength(_fileno(file)) / size;
	St s1, s2;
	for (int i = 0; i <kolvo-1; i++)
		for (int j = i+1; j < kolvo; j++)
		{
			
			fseek(file, size * i, 0);
			fread(&s1, size, 1, file);
			fseek(file, size * j, 0);
			fread(&s2, size, 1, file);
			if (SravnenieBukv(s1.FIO, s2.FIO)) 
			{
				fseek(file, size * i, 0);
				fwrite(&s2, size, 1, file);
				fseek(file, size * j, 0);
				fwrite(&s1, size, 1, file);
			}
		}
	fclose(file);
}

void Sort_Sr_ball_Vbivanie(FILE* file) 
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "r+b");
	int kolvo = _filelength(_fileno(file)) / size;
	St s1, s2;
	for (int i = 0; i <kolvo-1; i++)
		for (int j = i+1; j < kolvo; j++) {
			
			fseek(file, size * i, 0);
			fread(&s1, size, 1, file);
			fseek(file, size * j, 0);
			fread(&s2, size, 1, file);
			if (s1.sr_ball < s2.sr_ball) {
				fseek(file, size * i, 0);
				fwrite(&s2, size, 1, file);
				fseek(file, size * j, 0);
				fwrite(&s1, size, 1, file);
			}
		}
	fclose(file);
}

void Sort_Sr_ball_Vozrastanie(FILE* file) 
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "r+b");
	int kolvo = _filelength(_fileno(file)) / size;
	St s1, s2;
	for (int i = 0; i < kolvo -1; i++)
		for (int j = i+1; j < kolvo; j++) {
			
			fseek(file, size * i, 0);
			fread(&s1, size, 1, file);
			fseek(file, size * j, 0);
			fread(&s2, size, 1, file);
			if (s1.sr_ball > s2.sr_ball) {
				fseek(file, size * i, 0);
				fwrite(&s2, size, 1, file);
				fseek(file, size * j, 0);
				fwrite(&s1, size, 1, file);
			}
		}
	fclose(file);
}

void LinPoisk(FILE* file)
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "rb");
	St s;
	bool k1 = 0;
	double sred;
	cout << "Введите минимальный средний балл, который должен быть у искомых студентов\n";
	cin >> sred;
	cout << endl;
	while (fread(&s, size, 1, file))
	{
		if (s.sr_ball >= sred)
		{
			InfaStudentov(s);
			k1 = 1;
		}
	}
	if (k1 == 0) cout << "Нет таких студентов" << endl;
	fclose(file);
}

void partition(St arr[], int &i, int &j)
{
	St r;
	double x = arr[(i+ j) / 2].sr_ball;
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

void Quicksort(FILE* file)
{
	int size = sizeof(St), pivot=0;
	file = fopen("students_Lab7.txt", "rb");
	int kolvo = _filelength(_fileno(file)) / size;
	St* arr, s;
	arr = new St[kolvo];
	for (int i = 0; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	Stack* start=NULL;
	int left = 0, right = kolvo - 1, i = 0, j = 0;
	push(start, right);
	push(start, left);
	while (start != NULL)
	{
		left = (*start).info;
		right = (*(start->next)).info;
		pop(start);
		pop(start);
		partition(arr, i = left, j = right);
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
	fclose(file);
	file = fopen("students_Lab7.txt", "wb");
	for (i = 0; i < kolvo; i++)
		fwrite(&arr[i], size, 1, file);
	delete[]arr;
	fclose(file);
}

void push(Stack*&start, int in)
{
	Stack* tool;
	tool = new Stack;
	tool->info = in;
	tool->next = start;
	start = tool;
}

void pop(Stack*& start)
{
	Stack* tool;
	if (start == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	tool = start->next;
	delete start;
	start = tool;
}

void PryamVibor(FILE* file)
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "rb");
	int kolvo = _filelength(_fileno(file)) / size;
	St* arr, s, r;
	int pivot = 0, i = 0, m = 0, j = 0;
	arr = new St[kolvo];
	for (; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	for (i = 0; i < kolvo - 1; i++) {
		m = i;
		for (j = i + 1; j < kolvo; j++)
			if (arr[j].sr_ball < arr[m].sr_ball) m = j;
		r = arr[m];
		arr[m] = arr[i];
		arr[i] = r;
	}
	fclose(file);
	file = fopen("students_Lab7.txt", "wb");
	for (i = 0; i < kolvo; i++)
		fwrite(&arr[i], size, 1, file);
	delete[]arr;
	fclose(file);
}

void DelPopolam(FILE* file)
{
	int size = sizeof(St);
	file = fopen("students_Lab7.txt", "rb");
	int kolvo = _filelength(_fileno(file)) / size;
	int i_key = 0, j_key = kolvo - 1, m = 0;
	St* arr, s;
	arr = new St[kolvo];
	for (int i = 0; i < kolvo; i++)
	{
		fread(&s, size, 1, file);
		arr[i] = s;
	}
	double ball;
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
		InfaStudentov(arr[i_key]);
	delete[]arr;
	fclose(file);
}