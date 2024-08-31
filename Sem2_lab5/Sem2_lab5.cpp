#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct Stack
{
	char info = '\0';
	Stack* next = NULL;
};

void push(Stack*& start, char in)
{
	Stack* tool = new Stack;
	tool->info = in;
	tool->next = start;
	start = tool;
}

void out(Stack*& start, char& out) {
	Stack* tool = start; 
	out = start->info;
	start = start->next;
	delete tool;
}

void pop_all(Stack*& start)
{
	Stack* tool;
	while (start != NULL)
	{
		tool = start;
		start = start->next;
		delete tool;
	}
}

bool check_str(char* InStr);
void perevod(char* InStr, char* OutStr, Stack*& start);
void raschet(char* OutStr, Stack* start, Stack* start2);
void anti_povtor(char* OutStr, Stack*& start2, bool& isOne);
int check(int op);

int prior(char a)
{
	switch (a)
	{
	case '^': return 4;
	case '*':
	case '/': return 3;
	case '+':
	case '-': return 2;
	case '(': return 1;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* start = NULL;
	Stack* start2 = NULL;
	char InStr[20] = "";
	char OutStr[20] = "";
	cout << "Введите вырадение в инфиксной форме\n";
	cin.getline(InStr, 20);
	if (check_str(InStr))
	{
		cout << "Выражение введено некорректно";
		return 1;
	}
	perevod(InStr, OutStr, start);
	cout << "\nРасчет\n";
	bool isOne = 0;
	anti_povtor(OutStr, start2, isOne);
	if (isOne)
		return 0;
	raschet(OutStr, start, start2);
	pop_all(start);
	pop_all(start2);
	return 0;
}

bool check_str(char* InStr)
{
	char* che = InStr;
	strcat(che, "+");
	int i = 0, lever = 0;
	int len = strlen(InStr);
	if (che[0] != '+' && che[0] != '-' && che[0] != '*' && che[0] != '/' && che[0] != '^' && che[0] != ')')
		for (; i < len && lever >= 0 && (che[i] >= 'a' && che[i] <= 'z' || che[i] == '(' || che[i] == ')' || che[i] == '+' || che[i] == '-' || che[i] == '*' || che[i] == '/' || che[i] == '^'); i++)
		{
			if (che[i] == '(')
			{
				if (che[i + 1] == '+' || che[i + 1] == '-' || che[i + 1] == '*' || che[i + 1] == '/' || che[i + 1] == ')' || che[i + 2] == ')')
				{
					cout << "После открывающей скобки пропущен операнд\n";
					break;
				}
				lever++;
				continue;
			}

			if (che[i] >= 'a' && che[i] <= 'z')
			{
				if (che[i + 1] >= 'a' && che[i + 1] <= 'z' || che[i + 1] == '(')
				{
					cout << "После операнда пропущен знак операции или закрывающая скобка \n";
					break;
				}
				continue;
			}
			if (che[i] == '+' || che[i] == '-' || che[i] == '*' || che[i] == '/' || che[i] == '^')
			{
				if (che[i + 1] == '+' || che[i + 1] == '-' || che[i + 1] == '*' || che[i + 1] == '/' || che[i + 1] == '^' || che[i + 1] == ')')
				{
					cout << "После знака операции пропущен операнд или открывающая скобка\n";
					break;
				}
				continue;
			}
			if (che[i] == ')')
			{
				if (che[i + 1] >= 'a' && che[i + 1] <= 'z' || che[i + 1] == '(')
				{
					cout << "После закрывающей скобки пропущен знак операции\n";
					break;
				}
				lever--;
				continue;
			}
		}
	else
		cout << "Недопустимый первый символ\n";
	che[len - 1] = '\0';
	if (i < len || lever != 0)
		return true;
	return false;
}

void perevod(char* InStr, char* OutStr, Stack*& start)
{
	char ss, a;
	int k = 0;
	int len = strlen(InStr);
	for (int i = 0; i < len; i++)
	{
		ss = InStr[i];
		if (ss == '(')
		{
			push(start, ss);
			continue;
		}
		if (ss >= 'a' && ss <= 'z')
		{
			OutStr[k++] = ss;
			continue;
		}
		if (ss == ')')
		{
			while (start != NULL && (start->info) != '(')
			{
				out(start, a);
				OutStr[k++] = a;
			}
			out(start, a);
			continue;
		}
		while (start != NULL && prior(start->info) >= prior(ss))
		{
			out(start, a);
			OutStr[k++] = a;
		}
		push(start, ss);
	}
	while (start != NULL)
	{
		out(start, a);
		OutStr[k++] = a;
	}
	cout << "\nВыражение в постфикскной форме\n" << OutStr;
}

void raschet(char* OutStr, Stack* start, Stack* start2)
{
	double mas[40]{};
	Stack* t2 = start2;
	char ss;
	int chislo;
	while (t2 != NULL)
	{
		ss = t2->info;
		chislo = (int)ss - 97;
		cout << "Введите " << ss << endl;
		mas[chislo] = check(mas[chislo]);
		t2 = t2->next;
	}
	char chr = 'z' + 1;
	char ch1, ch2;
	double op1, op2, rez = 0;
	for (int i = 0; i < strlen(OutStr); i++)
	{
		ss = OutStr[i];
		if (ss >= 'a' && ss <= 'z')
		{
			push(start, ss);
			continue;
		}
		out(start, ch1);
		out(start, ch2);
		op1 = mas[(int)ch1 - 97];
		op2 = mas[(int)ch2 - 97];
		switch (ss)
		{
		case '+':
			rez = op2 + op1; break;
		case '-':
			rez = op2 - op1; break;
		case '*':
			rez = op2 * op1; break;
		case '/':
		{
			if (op1 == 0)
			{
				cout << "Внимание! Замечено деление на 0. Попробуйте ввести значения снова\n";
				raschet(OutStr, start, start2);
				return;
			}
			rez = op2 / op1;break;
		}
		case '^':
			rez = pow(op2, op1);
		}
		mas[(int)chr - 97] = rez;
		push(start, chr);
		chr++;
	}
	cout << "Результат вычисления = " << rez;
}

int check(int op)
{
	cin >> op;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Некорректный ввод, повторите попытку." << endl;
		cin >> op;
	}
	return op;
}

void anti_povtor(char* OutStr, Stack*& start2, bool& isOne)
{
	int len = strlen(OutStr);
	if (len == 1)
	{
		cout << "Введите " << OutStr[0] << endl;
		cin >> OutStr[0];
		cout << "Результат вычисления = " << OutStr[0];
		isOne = 1;
		return;
	}
	for (int i = 0; i < len; i++)
		if (OutStr[i] >= 'a' && OutStr[i] <= 'z')
			push(start2, OutStr[i]);
	Stack* t1, * tool, * t2 = start2;
	char ss;
	while (t2 != NULL)
	{
		ss = t2->info;
		t1 = t2;
		while (t1 != NULL && t1->next != NULL)
		{
			if ((t1->next)->info == ss)
			{
				tool = t1->next;
				t1->next = tool->next;
				delete tool;
			}
			else
				t1 = t1->next;
		}
		t2 = t2->next;
	}
}