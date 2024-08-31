#include <iostream>

using namespace std;
typedef struct Stck;

struct Stck
{
	int number = 0;
	Stck* next = NULL;
};

struct Info {
	char fio[20]{};
	int number{};
};

struct Tree {
	Info info;
	Tree* left = NULL, * right = NULL;
};

void create_arr(Tree*&);
void create_Tree(Tree*&, int, int, Info*);
void del_Tree(Tree*&);
void add(Tree*&, Info);
void del_Key(Tree*&, int);
void show_Key(Tree*&, int);
void showNice(Tree*, int);
void show_ToDown(Tree*);
void show_vozrast(Tree*);
void show_ToUp(Tree*);
int individ(Tree*, int);
int check(int);
void balance(Tree*&);
void balance_part(Tree*, int&, Info*);
void ind(Tree*);
void countLists(Tree* , Stck*);

int main()
{
	setlocale(LC_ALL, "rus");
	Tree* root = NULL;
	bool menu = 1;
	int lever = 0, k = 0;
	while (menu)
	{
		cout << "Меню:\n";
		cout << "1. Создать дерево\n";
		cout << "2. Добавить лист\n";
		cout << "3. Сбалансировать дерево\n";
		cout << "4. Просмотреть дерево ключей\n";
		cout << "5. Удалить дерево\n";
		cout << "6. Удалить узел с заданным ключом\n";
		cout << "7. Просмотреть узел по заданному ключу\n";
		cout << "8. Просмотреть дерево сверху вниз\n";
		cout << "9. Просмотреть дерево по возрастанию ключа\n";
		cout << "10. Просмотреть дерево снизу вверх\n";
		cout << "11. Определить количество записей в левой ветви дерева\n";
		cout << "0. Выход\n";
		lever = check(lever);
		switch (lever)
		{
		case 1:
			create_arr(root);
			break;
		case 2:
		{
			if (root == NULL)
			{
				cout << "Сначала создайте дерево!\n";
				break;
			}
			Info op;
			cout << "Введите ФИО человека\n";
			cin.ignore();
			cin.getline(op.fio, 20);
			cout << "Введите номер паспорта человека\n";
			op.number = check(op.number);
			add(root, op);
			break;
		}
		case 3:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			balance(root);
			//makeBalance(root);
			cout << "Балансировка завершена\n";
			break;
		case 4:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			cout << "------Дерево-----\n";
			showNice(root, 0);
			break;
		case 5:
			del_Tree(root);
			root = NULL;
			cout << "Удаление завершено\n";
			break;
		case 6:
		{
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			int op = 0;
			cout << "Введите номер, который надо удалить\n";
			op = check(op);
			del_Key(root, op);
			break;
		}
		case 7:
		{
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			int op = 0;
			cout << "Введите номер, который надо посмотреть\n";
			op = check(op);
			show_Key(root, op);
			break;
		}
		case 8:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			show_ToDown(root);
			break;
		case 9:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			show_vozrast(root);
			break;
		case 10:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			show_ToUp(root);
			break;
		case 11:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			k = individ(root->left, 0);
			cout << "Количество записей в левой ветви дерева = " << k << endl;
			k = 0;
			break;
		case 12:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			showNice(root, 0);
			break;
		case 13:
		{
			Stck* start = new Stck;
			countLists(root, start);
			int level = 0;
			Stck* tool;
			while (start != NULL)
			{
				cout << "На " << ++level << "-м уровне: " << start->number << endl;
				tool = start;
				start = start->next;
				delete tool;
			}
			delete start;
		}
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

void create_arr(Tree*& root)
{
	int kolvo, i;
	cout << "Введите кол-во элементов\n";
	cin >> kolvo;
	Info* arr = new Info[kolvo];
	for (i = 0; i < kolvo; i++)
	{
		cout << "Введите ФИО " << i + 1 << "-го человека\n";
		cin.ignore();
		cin.getline(arr[i].fio, 20);
		cout << "Введите номер паспорта " << i + 1 << "-го человека\n";
		arr[i].number = check(arr[i].number);
	}
	//Сортировка методом прямого выбора
	Info r;
	int j, m;
	for (i = 0; i < kolvo - 1; i++) {
		m = i;
		for (j = i + 1; j < kolvo; j++)
			if (arr[j].number < arr[m].number) m = j;
		r = arr[m];
		arr[m] = arr[i];
		arr[i] = r;
	}
	create_Tree(root, 0, kolvo, arr);
	delete[]arr;
}

void create_Tree(Tree*& p, int n, int k, Info* a) {
	if (n == k) {
		p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		p = new Tree;
		p->info = a[m];
		create_Tree(p->left, n, m, a);
		create_Tree(p->right, m + 1, k, a);
	}
}

void balance(Tree*& root)
{
	int kolvo = individ(root->left, 0) + individ(root->right, 0) + 1;
	Info* arr = new Info[kolvo];
	int i = 0;
	balance_part(root, i, arr);
	del_Tree(root);
	root = NULL;
	create_Tree(root, 0, kolvo, arr);
	delete[]arr;
}

void balance_part(Tree* t, int &i, Info* arr)
{
	if (t != NULL) {
		balance_part(t->left, i, arr);
		arr[i++] = t->info;
		balance_part(t->right, i, arr);
	}
}

void del_Tree(Tree*& t) {
	if (t != NULL) {
		del_Tree(t->left);
		del_Tree(t->right);
		delete t;
	}
}

void add(Tree*& root, Info key) {
	Tree* prev = root, * t = root;
	bool find = 1;
	while (t && find) {
		prev = t;
		if (key.number == t->info.number) {
			find = 0;
			cout << "Человек с таким номером уже существует\n";
		}
		else
			if (key.number < t->info.number)
				t = t->left;
			else
				t = t->right;
	}
	if (find) {
		t = new Tree;
		t->info = key;
		if (key.number < prev->info.number)
			prev->left = t;
		else
			prev->right = t;
	}
}

void del_Key(Tree*& root, int key) {
	Tree* Del = root, * Prev_Del = NULL, * R, * Prev_R;
	while (Del != NULL && Del->info.number != key) {
		Prev_Del = Del;
		if (Del->info.number > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)
	{
		cout << "Человека с таким номером нет";
		return;
	}
	if (Del->right == NULL)
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else {
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)
				R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root) root = R;
	else
		if (Del->info.number < Prev_Del->info.number)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	delete Del;
}

void show_Key(Tree*& root, int key) {
	Tree* Sho = root, * Prev_Sho = NULL;
	while (Sho != NULL && Sho->info.number != key) {
		Prev_Sho = Sho;
		if (Sho->info.number > key)
			Sho = Sho->left;
		else
			Sho = Sho->right;
	}
	if (Sho == NULL)
	{
		cout << "Человека с таким номером нет";
		return;
	}
	cout << "ФИО: " << Sho->info.fio << "\nНомер: " << Sho->info.number << endl;
}

void show_ToDown(Tree* t) {
	if (t != NULL) {
		cout << "ФИО: " << t->info.fio << "\nНомер: " << t->info.number << endl;
		show_ToDown(t->left);
		show_ToUp(t->right);
	}
}

void show_vozrast(Tree* t) {
	if (t != NULL) {
		show_vozrast(t->left);
		cout << "ФИО: " << t->info.fio << "\nНомер: " << t->info.number << endl;
		show_vozrast(t->right);
	}
}

void show_ToUp(Tree* t) {
	if (t != NULL) {
		show_ToDown(t->left);
		show_ToUp(t->right);
		cout << "ФИО: " << t->info.fio << "\nНомер: " << t->info.number << endl;
	}
}

void showNice(Tree* t, int level)
{
	if (t != NULL)
	{
		showNice(t->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "   ";
		cout << t->info.number << endl;
		showNice(t->left, level + 1);
	}
}

int individ(Tree* p, int k)
{
	if (p == NULL)
		return k;
	k=individ(p->left, k++);
	k=individ(p->right, k++);
	return ++k;
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

//bool Level(Tree* t, int level, int& counterN)
//{
//	if (t == NULL)
//		return false;
//	if (level == 1)
//	{
//		if (t->left==NULL && t->right==NULL)
//			counterN++;
//		return true;
//	}
//	/*bool left = Level(t->left, level - 1, counterN);
//	bool right = Level(t->right, level - 1, counterN);*/
//	return Level(t->left, level - 1, counterN) || Level(t->right, level - 1, counterN);
//}
//
//void ind(Tree* t)
//{
//	int level = 1, counterN = 0;
//	while (Level(t, level, counterN))
//	{
//		cout << "Уровень: " << level;
//		cout << "\tКол-во элементов: " << counterN << endl;
//		level++;
//	}
//}

void countLists(Tree* t_tree, Stck* t_stack)
{
	if (t_tree == NULL)
		return;
	if (t_tree->right == NULL && t_tree->left == NULL)
		t_stack->number++;
	else
	{
		t_stack->next = new Stck;
		t_stack->next->number += t_stack->number;
	}
	countLists(t_tree->right, t_stack->next);
	countLists(t_tree->left, t_stack->next);
}