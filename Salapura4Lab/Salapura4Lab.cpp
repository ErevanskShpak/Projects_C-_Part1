//#include <fstream>
//#include <iostream>
//using namespace std;
//class Person {
//protected:
//	int name;//���
//	int age;//�������
//public:
//	void getData() {//�������� ������ � ��������
//		cout << "\n������� ���: ";
//		cin >> name;
//		cout << "������� �������: ";
//		cin >> age;
//	}
//	void showData() {//����� ������ � ��������
//		cout << "\n ���: " << name;
//		cout << "\n �������: " << age;
//	}
//};
//int main() {
//	system("chcp 1251");
//	system("cls");
//	char ch;
//	Person pers;
//	fstream file;//������� ���� ��� �����/������
//	//������� ���� ��� ��������
//	file.open("Group.dat", ios::app | ios::out | ios::in |
//		ios::binary);
//	do {
//		cout << "������� ������ � ��������:";
//		pers.getData();
//		//�������� ������ � ����
//		file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
//		cout << "���������� ���� (y/n)? ";
//		cin >> ch;
//	} while (ch == 'y');
//	cout<<file.tellg() << " " << file.tellp();
//	file.seekg(0);//��������� ��������� ������� ������� � �����������
//	//������� ������ � ������ ��������
//	file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
//	while (!file.eof()) {
//		cout << "\n���������:";
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
#include <typeinfo>//��� typeid()
#include <process.h>
#include <vector>

using namespace std;
const int MAXEMPL = 100;//������������ ����� ����������
enum EmployeeType { manager, scientist, laborer };
class Employee {
	string name;//������� ���������
	unsigned long number;//����� ���������
	static int emplNum;//������� ���������� ����������
	static vector<Employee*> staff;//������ ����������
public:
	Employee() {
		name = "N/A";
		number = 0;
	}
	virtual void getData() {
		cin.ignore(10, '\n');
		cout << "������� ������� ����������: "; getline(cin, name);
		cout << "������� ����� ����������: "; cin >> number;
	}
	virtual void putData() {
		cout << "\n�������: " << name;
		cout << "\n�����: " << number;
	}
	virtual EmployeeType getType();//�������� ��� ����������
	static void add();//�������� ���������� � ����
	static void display();//������� ������ ��� ���� �����������
	static void read();//������ ������ �� �����
	static void write();//������ ������ � ����
};
int Employee::emplNum;//������� ����� ����������
vector<Employee*> Employee::staff(5);//������ ����������
class Manager : public Employee {
private:
	string title;//��������� ("����-���������" � �.�.)
	float dues;//������ �����-�����
public:
	Manager() {
		title = "";
		dues = 0;
	}
	void getData() {
		Employee::getData();
		cin.ignore();
		cout << "������� ���������: "; getline(cin, title);
		cout << "������� ������: "; cin >> dues;
	}
	void putData() {
		Employee::putData();
		cout << "\n���������: " << title;
		cout << "\n������ �����-�����: " << dues;
	}
};
class Scientist : public Employee {
private:
	int numbPubl;//���������� ����������
public:
	Scientist() {
		numbPubl = 0;
	}
	void getData() {
		Employee::getData();
		cout << "������� ���������� ����������: ";
		cin >> numbPubl;
	}
	void putData() {
		Employee::putData();
		cout << "\n���������� ����������: " << numbPubl;
	}
};
class Laborer : public Employee {};
void Employee::add() {
	char userChoice;
	cout << "'m' ��� ���������� ���������"
		"\n's' ��� ���������� �������"
		"\n'l' ��� ���������� ��������"
		"\n��� �����: ";
	cin >> userChoice;
	switch (userChoice) {//������� ������ ���������� ����
	case 'm': staff[emplNum] = new Manager; break;
	case 's': staff[emplNum] = new Scientist; break;
	case 'l': staff[emplNum] = new Laborer; break;
	default: cout << "\n����������� ��� ���������\n";
		return;
	}
	staff[emplNum++]->getData();//�������� ������ �� ������������
}
void Employee::display() {//������� ������ ��� ���� ����������
	for (int j = 0; j < emplNum; j++) {
		cout << (j + 1);//������� �����
		switch (staff[j]->getType()) {//������� ��� ���������
		case EmployeeType::manager:cout << ". ���: ��������"; break;
		case EmployeeType::scientist:cout << ". ���: ������"; break;
		case EmployeeType::laborer: cout << ". ���: �������"; break;
		default: cout << ". ����������� ���";
		}
		staff[j]->putData();//����� ������
		cout << endl;
	}
}
EmployeeType Employee::getType() {//������� ���� �������
	if (typeid(*this) == typeid(Manager))return
		EmployeeType::manager;
	else if (typeid(*this) == typeid(Scientist)) return
		EmployeeType::scientist;
	else if (typeid(*this) == typeid(Laborer)) return
		EmployeeType::laborer;
	else {
		cerr << "\n������������ ��� ���������";
		exit(1);
	}
	return EmployeeType::manager;
}
void Employee::write() {//�������� ��� ������� � ����
	int size = sizeof(Manager);
	cout << "���� ������ " << emplNum << " ����������.\n";
	ofstream ouf;//������� ofstream
	EmployeeType etype;//��� ������� ������� Employee
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	for (int j = 0; j < emplNum; j++) {//��� ������� ������� �������� ���
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
		ouf.write((char*)(staff[j]), size);//������ ������� Employee
		if (!ouf) {
			cout << "\n������ � ���� ����������\n";
			return;
		}
	}
}
void Employee::read() {//������ ���� ������ �� �����
	int size = sizeof(Manager);//������ ������� Employee
	EmployeeType etype;//��� ���������
	ifstream inf;
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	emplNum = 0;//� ������ ���������� ���
	while (true) {
		inf.read((char*)&etype, sizeof(etype));//������ ���� ���������
			if (inf.eof()) break;
		if (!inf) {//������ ������ ����
			cout << "\n���������� ������ ����\n";
			return;
		}
		//switch (etype) {
		//	//������� ������ ���������
		//case EmployeeType::manager://����������� ����
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
		//default: cout << "\n����������� ��� � �����\n"; return;
		//}//������ ������ �� �����
		staff[emplNum] = new Manager;
		inf.read((char*)staff[emplNum], size);
		if (!inf) {//������, �� �� EOF
			cout << "\n������ ������ �� ����� ����������\n";
			return;
		}
		emplNum++;//������� ���������� ���������
	}//end while
	cout << "���� ������ " << emplNum << " ����������\n";
}
int main() {
	system("chcp 1251");
	system("cls");
	char userChoice;
	while (true) {
		cout << "'a' - ���������� �������� � ���������"
			"\n'd' - ������� �������� ��� ���� ����������"
			"\n'w' - �������� ��� ������ � ����"
			"\n'r' - ��������� ��� ������ �� �����"
			"\n'x' - �����"
			"\n��� �����: ";
		cin >> userChoice;
		switch (userChoice) {
		case 'a'://�������� ���������
			Employee::add(); break;
		case 'd'://������� ��� ��������
			Employee::display(); break;
		case 'w'://������ � ����
			Employee::write(); break;
		case 'r'://������ ���� ������ �� �����
			Employee::read(); break;
		case 'x': exit(0);//�����
		default: cout << "\n����������� �������";
		}
	}
	return 0;
}

