#include <iostream>

using namespace std;

struct Element {
	char nazv[20]{};
	int stran = 0;
	int god = 0;
};

void hash_add(int info, int k_hash, int* hash);
int hash_seek(int info, int k_hash, int* hash);
void hash_show(int* hash, int k_hash);
Element* create_arr(Element* arr, int k_arr);
void show_arr(Element* arr, int k_arr);
int check(int op);

int main()
{
	setlocale(LC_ALL, "rus");
	Element* arr = NULL;
	int k_arr = 0, k_hash = 0;
	int* hash = NULL;
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
			hash = new int[k_hash];
			for (int i = 0; i < k_hash; i++)
				hash[i] = -1;
			for (int i = 0; i < k_arr; i++)
				hash_add(arr[i].god, k_hash, hash);
			break;
		case 2:
			if (arr == NULL)
			{
				cout << "Массив пуст\n";
				break;
			}
			show_arr(arr, k_arr);
			hash_show(hash, k_hash);
			break;
		case 3:
			if (arr == NULL)
			{
				cout << "Массив пуст\n";
				break;
			}
			delete[]hash;
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
			int rez;
			cout << "Введите искомое число\n";
			key = check(key);
			rez = hash_seek(key, k_hash, hash);
			if (rez != -1)
			{
				cout << "Результат = " << hash[rez] << endl;
				for (int i = 0; i < k_arr; i++)
				{
					if (arr[i].god == key)
					{
						cout << "Название: " << arr[i].nazv << endl;
						cout << "Кол-во страниц: " << arr[i].stran << endl;
						cout << "Год издания: " << arr[i].god << endl << endl;
					}
				}
			}
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

void hash_add(int info, int k_hash, int* hash)
{
	int i = info % k_hash;
	if (hash[i] == info)
		return;
	int p = 0;
	if (hash[i] != -1)
		while (hash[i] != -1)
		{
			p++;
			i = (i + p * p) % k_hash;
		}
	hash[i] = info;
}

int hash_seek(int info, int k_hash, int* hash)
{
	int i = info % k_hash;
	int p = 0;
	while (hash[i] != -1)
	{
		if (hash[i] == info)
			return i;
		p++;
		i = (i + p * p) % k_hash;
	}
	return -1;
}

void hash_show(int* hash, int k_hash)
{
	cout << "Хеш-таблица\n";
	for (int i = 0; i < k_hash; i++)
	{
		cout << hash[i] << " ";
	}
	cout << endl;
}

Element* create_arr(Element* arr, int k_arr)
{
	arr = new Element[k_arr];
	cout << "Введите элементы массива\n";
	for (int i = 0; i < k_arr; i++)
	{
		cout << "Введите Название " << i + 1 << "-й книги\n";
		cin >> arr[i].nazv;
		cout << "Введите Кол-во страниц " << i + 1 << "-й книги\n";
		arr[i].stran = check(arr[i].stran);
		cout << "Введите Год издания " << i + 1 << "-й книги\n";
		arr[i].god = check(arr[i].god);
	}
	return arr;
}

void show_arr(Element* arr, int k_arr)
{
	cout << "Массив\n";
	for (int i = 0; i < k_arr; i++)
	{
		cout << "Название: " << arr[i].nazv << endl;
		cout << "Кол-во страниц: " << arr[i].stran << endl;
		cout << "Год издания: " << arr[i].god << endl << endl;
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