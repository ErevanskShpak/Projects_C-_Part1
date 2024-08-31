#include <iostream>

using namespace std;

struct Element {
	int info = 0;
	Element* next = NULL;
};

Element** hash_create(int k_hash, Element**& hash);
void hash_add(int info, int k_hash, Element** hash);
Element* hash_seek(int info, int k_hash, Element** hash);
void hash_show(int k_hash, Element** hash);
void hash_delete(int k_hash, Element** hash);
int* create_arr(int* arr, int k_arr);
void show_arr(int* arr, int k_arr);
int check(int op);

int main()
{
	setlocale(LC_ALL, "rus");
	int* arr = NULL, k_arr = 0, k_hash = 0;
	Element** hash = NULL;
	bool menu = 1;
	int lever = 0;
	while (menu)
	{
		cout << "Меню:" << endl;
		cout << "1. Ввести массив и создать хеш-таблицу" << endl;
		cout << "2. Просмотреть массив и хеш-таблицу" << endl;
		cout << "3. Удалить массив и хеш-таблицу" << endl;
		cout << "4. Найти элемент" << endl;
		cout << "0. Выход" << endl;
		lever = check(lever);
		switch (lever)
		{
		case 1:
			cout << "Введите размер массива\n";
			k_arr = check(k_arr);
			arr = create_arr(arr, k_arr);
			cout << "Введите размер хеш-таблицы\n";
			k_hash = check(k_hash);
			hash = hash_create(k_hash, hash);
			for (int i = 0; i < k_arr; i++)
				hash_add(arr[i], k_hash, hash);
			break;
		case 2:
			if (arr == NULL)
			{
				cout << "Массив пуст\n";
				break;
			}
			show_arr(arr, k_arr);
			hash_show(k_hash, hash);
			break;
		case 3:
			if (arr == NULL)
			{
				cout << "Массив пуст\n";
				break;
			}
			hash_delete(k_hash, hash);
			hash = NULL;
			delete[]arr;
			arr = NULL;
			cout << "Удаление завершено\n";
			break;
		case 4:
		{
			if (arr == NULL)
			{
				cout << "Массив пуст\n";
				break;
			}
			int key = 0;
			Element* rez;
			cout << "Введите искомое число\n";
			key = check(key);
			rez = hash_seek(key, k_hash, hash);
			if (rez)
				cout << "Результат = " << rez->info << endl;
			else
				cout << "Такого числа в массиве нет\n";
			break;
		}
		case 0:
			menu = 0;
			break;
		default:
			cout << "Некорректный ввод. Повторите попытку\n";
		}
	}
	return 0;
}

Element** hash_create(int k_hash, Element**& hash)
{
	hash = new Element * [k_hash];
	for (int i = 0; i < k_hash; i++)
		hash[i] = NULL;
	return hash;
}

void hash_add(int info, int k_hash, Element** hash)
{
	Element* el = new Element;
	el->info = info;
	int i = info % k_hash;
	if (hash[i] == NULL)
		hash[i] = el;
	else
	{
		el->next = hash[i];
		hash[i] = el;
	}
}

Element* hash_seek(int info, int k_hash, Element** hash)
{
	int i = info % k_hash;
	Element* el = hash[i];
	while (el != NULL)
	{
		if (el->info == info)
			return el;
		el = el->next;
	}
	return NULL;
}

void hash_show(int k_hash, Element** hash)
{
	Element* el;
	cout << "Хеш-таблица\n";
	for (int i = 0; i < k_hash; i++)
	{
		if (hash[i] == NULL)
			cout << "-1 ";
		el = hash[i];
		while (el != NULL)
		{
			cout << el->info << " ";
			el = el->next;
		}
	}
	cout << endl;
}

void hash_delete(int k_hash, Element** hash)
{
	Element* el, * del;
	for (int i = 0; i < k_hash; i++)
	{
		el = hash[i];
		while (el != NULL)
		{
			del = el;
			el = el->next;
			delete del;
		}
	}
	delete[] hash;
}

int* create_arr(int* arr, int k_arr)
{
	arr = new int[k_arr];
	cout << "Введите элементы массива\n";
	for (int i = 0; i < k_arr; i++)
	{
		arr[i] = 0;
		arr[i] = check(arr[i]);
	}
	return arr;
}

void show_arr(int* arr, int k_arr)
{
	cout << "Массив\n";
	for (int i = 0; i < k_arr; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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