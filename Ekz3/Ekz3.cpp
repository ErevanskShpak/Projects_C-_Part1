#include <iostream>

using namespace std;

struct st
{
	char name[20];
	int kolvo;
	double price;
	int date;
};

bool func1(st*, int);
bool func2(st*, int);

int main()
{
	setlocale(LC_ALL, "rus");
	st* mas;
	int n,i;
	bool bol1 = 0, bol2=0;
	cout << "Введите размер списка n\n";
	cin >> n;
	mas = new st[n];
	for ( i = 0; i < n; i++)
	{
		cout << "Введите имя " << i+1 << "-го товара, его кол-во, стоимость и дату поступления\n";
		cin >> mas[i].name;
		cin >> mas[i].kolvo;
		cin >> mas[i].price;
		cin >> mas[i].date;
	}
	cout << "\nТовары поступившие между 2 и 10\n\n";
	for (i = 0; i < n; i++)
		if (func1(mas, i))
		{
			cout << "Имя товара - " << mas[i].name<<endl;
			cout << "Количество товара - " << mas[i].kolvo << endl;
			cout << "Стоимость товара - " << mas[i].price << endl;
			cout << "Дата поставки товара - " << mas[i].date << "\n\n";
			bol1 = 1;
		}
	if (bol1 == 0)
		cout << "Нет таких товаров\n";
	cout << "\nТовары, лежащие более 8 дней\n\n";
	for (i = 0; i < n; i++)
		if (func2(mas, i))
		{
			cout << "Имя товара - " << mas[i].name << endl;
			cout << "Количество товара - " << mas[i].kolvo << endl;
			cout << "Стоимость товара - " << mas[i].price << endl;
			cout << "Дата поставки товара - " << mas[i].date << "\n\n";
			bol2 = 1;
		}
	if (bol2 == 0)
		cout << "Нет таких товаров";
	delete[]mas;
	return 0;
}

bool func1(st *mas, int i)
{
	if (mas[i].date > 2 && mas[i].date < 10)
		return true;
	return false;
}

bool func2(st* mas, int i)
{
	if (mas[i].date < 23)
		return true;
	return false;
}