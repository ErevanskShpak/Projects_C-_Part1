#include <iostream>
#include <string>

using namespace std;

class MyClass {
	int data;
	int number;
	int time;
public:
	MyClass():data(0),number(0),time(0) {

		cout << "Вызвался конструктор по умолчанию\n";
	}

	MyClass(int data, int number, int time):data(data), number(number), time(time) {

		cout << "Вызвался конструктор\n";
	}

	MyClass(const MyClass& other) {
		data = other.data;
		number = other.number;
		time = other.time;

		cout << "Вызвался конструктор копирования\n";
	}

	MyClass(MyClass&& other) noexcept {
		data = other.data;
		number = other.number;
		time = other.time;

		cout << "Вызвался конструктор перемещения\n";
	}

	~MyClass() {

		cout << "Вызвался деструктор\n";
	}

	MyClass& operator = (const MyClass& other) {
		data = other.data;

		return *this;
	}

	MyClass operator ++(int) {
		MyClass temp(*this);

		data++;

		return temp;
	}

	MyClass& operator ++() {
		data++;

		return *this;
	}

	virtual int getData() {

		return data;
	}
};

class Kid :public MyClass {
	int new_data;

public:
	virtual int getData() override {
		cout<< MyClass:: getData();
		cout << "Бебра\n";
		return 0;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	

	/*Kid test(12);
	MyClass* ptr = &test;
	ptr->getData();*/

	/*MyClass a(10);
	a++.getData();
	a.getData();*/

	/*MyClass a(5);
	MyClass b(6);
	MyClass c(9);

	a = b = c;*/

	/*int a = 5;
	int* pa = &a;
	int& aref = a;
	int* ppa = &aref;
	cout << pa << endl;
	cout << ppa << endl;*/

	/*int* ptr_c = new int;

	cout << ptr_c << endl;
	delete ptr_c;
	if (ptr_c!=nullptr) 
	cout << ptr_c << endl;*/

	/*MyClass a(5, 10);
	MyClass b(2, 4);
	MyClass* ptr_a=&a;
	MyClass* ptr_b = &b;

	cout << ptr_a << endl;
	cout << ptr_b << endl;

	a = b;

	cout << ptr_a << endl;
	cout << ptr_b << endl;*/

	return 0;
}