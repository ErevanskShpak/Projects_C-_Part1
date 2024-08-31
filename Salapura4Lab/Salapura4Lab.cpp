//#include <fstream>
//#include <iostream>
//using namespace std;
//class Person {
//protected:
//	int name;//имя
//	int age;//возраст
//public:
//	void getData() {//получить данные о человеке
//		cout << "\nВведите имя: ";
//		cin >> name;
//		cout << "Введите возраст: ";
//		cin >> age;
//	}
//	void showData() {//вывод данных о человеке
//		cout << "\n Имя: " << name;
//		cout << "\n Возраст: " << age;
//	}
//};
//int main() {
//	system("chcp 1251");
//	system("cls");
//	char ch;
//	Person pers;
//	fstream file;//создать файл для ввода/вывода
//	//открыть файл для дозаписи
//	file.open("Group.dat", ios::app | ios::out | ios::in |
//		ios::binary);
//	do {
//		cout << "Введите данные о человеке:";
//		pers.getData();
//		//записать данные в файл
//		file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
//		cout << "Продолжить ввод (y/n)? ";
//		cin >> ch;
//	} while (ch == 'y');
//	cout<<file.tellg() << " " << file.tellp();
//	file.seekg(0);//поместить указатель текущей позиции в началофайла
//	//считать данные о первом человеке
//	file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
//	while (!file.eof()) {
//		cout << "\nСотрудник:";
//		pers.showData();
//		file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
//	}
//	cout << endl;
//	return 0;
//}

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>//для typeid()
#include <process.h>
#include <vector>

using namespace std;
const int MAXEMPL = 100;//максимальное число работников
enum EmployeeType { manager, scientist, laborer };
class Employee {
	string name;//фамилия работника
	unsigned long number;//номер работника
	static int emplNum;//текущее количество работников
	static vector<Employee*> staff;//массив указателей
public:
	Employee() {
		name = "N/A";
		number = 0;
	}
	virtual void getData() {
		cin.ignore(10, '\n');
		cout << "Введите фамилию сотрудника: "; getline(cin, name);
		cout << "Введите номер сотрудника: "; cin >> number;
	}
	virtual void putData() {
		cout << "\nФамилия: " << name;
		cout << "\nНомер: " << number;
	}
	virtual EmployeeType getType();//получить тип сотрудника
	static void add();//добавить сотрудника в штат
	static void display();//вывести данные обо всех сотрудниках
	static void read();//чтение данных из файла
	static void write();//запись данных в файл
};
int Employee::emplNum;//текущее число работников
vector<Employee*> Employee::staff(5);//массив указателей
class Manager : public Employee {
private:
	string title;//должность ("вице-президент" и т.д.)
	float dues;//Налоги гольф-клуба
public:
	Manager() {
		title = "";
		dues = 0;
	}
	void getData() {
		Employee::getData();
		cin.ignore();
		cout << "Введите должность: "; getline(cin, title);
		cout << "Введите налоги: "; cin >> dues;
	}
	void putData() {
		Employee::putData();
		cout << "\nДолжность: " << title;
		cout << "\nНалоги гольф-клуба: " << dues;
	}
};
class Scientist : public Employee {
private:
	int numbPubl;//количество публикаций
public:
	Scientist() {
		numbPubl = 0;
	}
	void getData() {
		Employee::getData();
		cout << "Введите количество публикаций: ";
		cin >> numbPubl;
	}
	void putData() {
		Employee::putData();
		cout << "\nКоличество публикаций: " << numbPubl;
	}
};
class Laborer : public Employee {};
void Employee::add() {
	char userChoice;
	cout << "'m' для добавления менеджера"
		"\n's' для добавления ученого"
		"\n'l' для добавления рабочего"
		"\nВаш выбор: ";
	cin >> userChoice;
	switch (userChoice) {//создать объект указанного типа
	case 'm': staff[emplNum] = new Manager; break;
	case 's': staff[emplNum] = new Scientist; break;
	case 'l': staff[emplNum] = new Laborer; break;
	default: cout << "\nНеизвестный тип работника\n";
		return;
	}
	staff[emplNum++]->getData();//Получить данные от пользователя
}
void Employee::display() {//Вывести данные обо всех работниках
	for (int j = 0; j < emplNum; j++) {
		cout << (j + 1);//вывести номер
		switch (staff[j]->getType()) {//вывести тип работника
		case EmployeeType::manager:cout << ". Тип: Менеджер"; break;
		case EmployeeType::scientist:cout << ". Тип: Ученый"; break;
		case EmployeeType::laborer: cout << ". Тип: Рабочий"; break;
		default: cout << ". Неизвестный тип";
		}
		staff[j]->putData();//Вывод данных
		cout << endl;
	}
}
EmployeeType Employee::getType() {//Возврат типа объекта
	if (typeid(*this) == typeid(Manager))return
		EmployeeType::manager;
	else if (typeid(*this) == typeid(Scientist)) return
		EmployeeType::scientist;
	else if (typeid(*this) == typeid(Laborer)) return
		EmployeeType::laborer;
	else {
		cerr << "\nНеправильный тип работника";
		exit(1);
	}
	return EmployeeType::manager;
}
void Employee::write() {//Записать все объекты в файл
	int size = sizeof(Manager);
	cout << "Идет запись " << emplNum << " работников.\n";
	ofstream ouf;//открыть ofstream
	EmployeeType etype;//тип каждого объекта Employee
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	for (int j = 0; j < emplNum; j++) {//Для каждого объекта получить тип
			//etype = staff[j]->getType();
		ouf.write((char*)&etype, sizeof(etype));
		/*switch (etype) {
		case EmployeeType::manager:
			size = sizeof(Manager); break;
		case EmployeeType::scientist:
			size = sizeof(Scientist); break;
		case EmployeeType::laborer:
			size = sizeof(Laborer); break;
		}*/
		ouf.write((char*)(staff[j]), size);//запись объекта Employee
		if (!ouf) {
			cout << "\nЗапись в файл невозможна\n";
			return;
		}
	}
}
void Employee::read() {//чтение всех данных из файла
	int size = sizeof(Manager);//размер объекта Employee
	EmployeeType etype;//тип работника
	ifstream inf;
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	emplNum = 0;//В памяти работников нет
	while (true) {
		inf.read((char*)&etype, sizeof(etype));//чтение типа работника
			if (inf.eof()) break;
		if (!inf) {//ошибка чтения типа
			cout << "\nНевозможно чтение типа\n";
			return;
		}
		//switch (etype) {
		//	//создать нового работника
		//case EmployeeType::manager://корректного типа
		//	staff[emplNum] = new Manager;
		//	size = sizeof(Manager);
		//	break;
		//case EmployeeType::scientist:
		//	staff[emplNum] = new Scientist;
		//	size = sizeof(Scientist);
		//	break;
		//case EmployeeType::laborer:
		//	staff[emplNum] = new Laborer;
		//	size = sizeof(Laborer);
		//	break;
		//default: cout << "\nНеизвестный тип в файле\n"; return;
		//}//чтение данных из файла
		staff[emplNum] = new Manager;
		inf.read((char*)staff[emplNum], size);
		if (!inf) {//ошибка, но не EOF
			cout << "\nЧтение данных из файла невозможно\n";
			return;
		}
		emplNum++;//счетчик работников увеличить
	}//end while
	cout << "Идет чтение " << emplNum << " работников\n";
}
int main() {
	system("chcp 1251");
	system("cls");
	char userChoice;
	while (true) {
		cout << "'a' - добавление сведений о работнике"
			"\n'd' - вывести сведения обо всех работниках"
			"\n'w' - записать все данные в файл"
			"\n'r' - прочитать все данные из файла"
			"\n'x' - выход"
			"\nВаш выбор: ";
		cin >> userChoice;
		switch (userChoice) {
		case 'a'://добавить работника
			Employee::add(); break;
		case 'd'://вывести все сведения
			Employee::display(); break;
		case 'w'://запись в файл
			Employee::write(); break;
		case 'r'://чтение всех данных из файла
			Employee::read(); break;
		case 'x': exit(0);//выход
		default: cout << "\nНеизвестная команда";
		}
	}
	return 0;
}

