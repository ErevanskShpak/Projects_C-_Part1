#include <iostream>

using namespace std;

struct Stack
{
	int number = 0;
	Stack* next = NULL;
};

struct Info {
	int number = 0;
};

struct Tree {
	Info info;
	Tree* left = NULL, * right = NULL;
};

void createTree(Tree*&, Info);
void delTree(Tree*&);
void addList(Tree*, Info);

void delKey(Tree*&, int);
//void showKey(Tree*&, int);

void showNice(Tree*, int);
void showToDown(Tree*);
void showVozrast(Tree*);
void showToUp(Tree*);

int countUzl(Tree*);
int countLevel(Tree*);
void delSred(Tree* );
void countLists2(Tree* , int* , int);
void delOtriz(Tree*&, Tree*&);

void createBalanceTree(Tree*&, int, int, Info*);
void balance(Tree*&);
void balancePart(Tree*, int&, Info*);

//void countLists(Tree*, Stack*);

int check(int op) {
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

int main()
{
	setlocale(LC_ALL, "rus");
	Tree* root = NULL;

	bool menu = 1;
	int lever = 0;
	while (menu) {
		cout << "Меню:\n";
		cout << "1. Создать дерево\n";
		cout << "2. Добавить лист\n";
		cout << "3. Сбалансировать дерево\n";
		cout << "4. Просмотреть дерево ключей\n";
		cout << "5. Удалить дерево\n";
		cout << "6. Удалить узел с заданным ключом\n";
		//cout << "7. Просмотреть узел по заданному ключу\n";
		cout << "8. Просмотреть дерево сверху вниз\n";
		cout << "9. Просмотреть дерево по возрастанию ключа\n";
		cout << "10. Просмотреть дерево снизу вверх\n";
		cout << "11. Определить количество записей в левой ветви дерева\n";
		cout << "0. Выход\n";

		lever = check(lever);
		switch (lever) {
		case 1: {
			Info op;
			cout << "Введите номер паспорта человека\n";
			op.number = check(op.number);

			createTree(root, op);
			break;
		}
		case 2: {
			if (root == NULL)
			{
				cout << "Сначала создайте дерево!\n";
				break;
			}

			Info op;
			cout << "Введите номер паспорта человека\n";
			op.number = check(op.number);

			addList(root, op);
			break;
		}
		case 3:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}

			balance(root);
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
			delTree(root);
			root = NULL;
			cout << "Удаление завершено\n";
			break;
		case 6: {
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}

			int op = 0;
			cout << "Введите номер, который надо удалить\n";
			op = check(op);

			delKey(root, op);
			break;
		}
		/*case 7: {
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}

			int op = 0;
			cout << "Введите номер, который надо посмотреть\n";
			op = check(op);

			showKey(root, op);
			break;
		}*/
		case 8:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}

			showToDown(root);
			break;
		case 9:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			showVozrast(root);
			break;
		case 10:
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}
			showToUp(root);
			break;
		case 11: {
			if (root == NULL)
			{
				cout << "Дерева нет\n";
				break;
			}

			/*int k = 0;
			k = countUzl(root->left);
			cout << "Количество записей в левой ветви дерева = " << k << endl;*/
			//delSred(root);
			/*int n = countLevel(root);
			int* arr = new int[n];
			int i = 0;
			for (; i < n; i++) {
				arr[i] = 0;
			}

			countLists2(root, arr, 0);

			for (i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}

			delete[]arr;*/
			delOtriz(root, root);
			break;
		}
		/*case 12:
		{
			Stack* start = new Stack;
			countLists(root, start);

			Stack* tool;
			int level = 0;
			while (start != NULL)
			{
				cout << "На " << ++level << "-м уровне: " << start->number << endl;
				tool = start;
				start = start->next;
				delete tool;
			}
			delete start;
		}
		break;*/
		case 0:
			menu = 0;
			break;
		default:
			cout << "Некорректный ввод. Повторите попытку\n";
		}
	}

	return 0;
}

void createBalanceTree(Tree*& t, int n, int k, Info* a) {
	if (n == k) {
		t = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		t = new Tree;
		t->info = a[m];
		createBalanceTree(t->left, n, m, a);
		createBalanceTree(t->right, m + 1, k, a);
	}
}

int countUzl(Tree* t)
{
	if (t == NULL)
		return 0;

	return 1 + countUzl(t->left) + countUzl(t->right);
}

void balance(Tree*& root)
{
	int kolvo = countUzl(root);
	Info* arr = new Info[kolvo];
	int i = 0;
	balancePart(root, i, arr);
	delTree(root);
	root = NULL;
	createBalanceTree(root, 0, kolvo, arr);
	delete[]arr;
}

void balancePart(Tree* t, int& i, Info* arr)
{
	if (t != NULL) {
		balancePart(t->left, i, arr);
		arr[i++] = t->info;
		balancePart(t->right, i, arr);
	}
}

void createTree(Tree*& root, Info info) {
	root = new Tree;
	root->info = info;
}

void delTree(Tree*& t) {
	if (t != NULL) {
		delTree(t->left);
		delTree(t->right);
		delete t;
	}
}

void addList(Tree* t, Info key) {
	Tree* prev = NULL;

	while (t != NULL) {
		prev = t;
		if (key.number == t->info.number) {
			cout << "Человек с таким номером уже существует\n";
			return;
		}
		else
			if (key.number < t->info.number)
				t = t->left;
			else
				t = t->right;
	}

	t = new Tree;
	t->info = key;
	if (key.number < prev->info.number)
		prev->left = t;
	else
		prev->right = t;
}

void delKey(Tree*& root, int key) {
	Tree* del = root, * prev_del = NULL;

	//ищем del и prev_del
	while (del != NULL && del->info.number != key) {
		prev_del = del;
		if (key < del->info.number)
			del = del->left;
		else
			del = del->right;
	}
	if (del == NULL)
	{
		cout << "Элемента с таким номером нет";
		return;
	}

	//Ищем замену для del
	Tree* re_del;
	if (del->right == NULL) {
		re_del = del->left;
	}
	else {
		if (del->left == NULL) {
			re_del = del->right;
		}
		else {
			Tree* prev_re_del = del;
			//Ищем самый правый узел в левом поддереве(то есть у которого справа свободно)
			re_del = del->left;
			while (re_del->right != NULL) {
				prev_re_del = re_del;
				re_del = re_del->right;
			}

			re_del->right = del->right;
			if (prev_re_del != del) { // т. е. если вошло в пред цикл
				prev_re_del->right = re_del->left;
				re_del->left = prev_re_del;
			}
		}
	}

	//Заменяем del на re_del
	if (del == root) {
		root = re_del;
	}
	else {
		if (del->info.number < prev_del->info.number) {
			prev_del->left = re_del;
		}
		else {
			prev_del->right = re_del;
		}
	}
	delete del;
}

//void showKey(Tree*& root, int key) {
//	Tree* Sho = root, * Prev_Sho = NULL;
//	while (Sho != NULL && Sho->info.number != key) {
//		Prev_Sho = Sho;
//		if (Sho->info.number > key)
//			Sho = Sho->left;
//		else
//			Sho = Sho->right;
//	}
//	if (Sho == NULL)
//	{
//		cout << "Человека с таким номером нет";
//		return;
//	}
//	cout << "\nНомер: " << Sho->info.number << endl;
//}

void showToDown(Tree* t) {
	if (t != NULL) {
		cout << "\nНомер: " << t->info.number << endl;
		showToDown(t->left);
		showToDown(t->right);
	}
}

void showVozrast(Tree* t) {
	if (t != NULL) {
		showVozrast(t->left);
		cout << "\nНомер: " << t->info.number << endl;
		showVozrast(t->right);
	}
}

void showToUp(Tree* t) {
	if (t != NULL) {
		showToUp(t->left);
		showToUp(t->right);
		cout << "\nНомер: " << t->info.number << endl;
	}
}

void showNice(Tree* t, int level) {
	if (t != NULL)
	{
		showNice(t->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "   ";
		cout << t->info.number << endl;
		showNice(t->left, level + 1);
	}
}



//void countLists(Tree* t_tree, Stack* t_stack) {
//	if (t_tree == NULL)
//		return;
//
//	if (t_tree->right == NULL && t_tree->left == NULL) {
//		t_stack->number++;
//	}
//	else {
//		if (t_stack->next == NULL) {
//			t_stack->next = new Stack;
//		}
//		countLists(t_tree->right, t_stack->next);
//		countLists(t_tree->left, t_stack->next);
//	}
//}

void countLists2(Tree* t, int* arr, int i) {
	if (t == NULL) {
		return;
	}

	arr[i++]++;

	if (t->left != NULL) {
		countLists2(t->left, arr, i);
	}
	if (t->right != NULL) {
		countLists2(t->right, arr, i);
	}
}

int countLevel(Tree* t) {
	if (t == NULL) {
		return 0;
	}

	int a = countLevel(t->left);
	int b = countLevel(t->right);

	return (a >= b ? a : b) + 1;
}

void delSred(Tree* root) {
	int high = countLevel(root);
	high /= 2;

	Tree* t = root;
	for (int i = 0; i < high; i++) {
		if (countLevel(t->left) > countLevel(t->right)) {
			t=t->left;
		}
		else {
			t=t->right;
		}
	}
	delKey(root, t->info.number);
}

void delOtriz(Tree*& t, Tree*& root) {
	if (t != NULL) {
		delOtriz(t->left, root);
		delOtriz(t->right, root);
		if (t->info.number < 0) {
			delKey(root, t->info.number);
		}
	}
}