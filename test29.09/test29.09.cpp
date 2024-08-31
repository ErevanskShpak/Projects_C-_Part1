#include <iostream>
#include <string>
#include <fstream>
#include <process.h>
#include <vector>

using namespace std;

class A {
public:
    
    string surname;
    string name;
	A(){}
	A(string name, string surname):name(name), surname(surname) {}
};

class B {
public:
	vector<A> vec;
	B(){}
	B(vector<A> vec):vec(vec){}
};
enum EmployeeType {
    hui
};

void write(vector<A*> staff) {//Записать все объекты в файл
	int size = sizeof(A);
	ofstream ouf;//открыть ofstream
	EmployeeType etype = hui;//тип каждого объекта Employee
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	for (int j = 0; j < 1; j++) {
		//Для каждого объекта получить тип
		ouf.write((char*)&etype, sizeof(etype));
		ouf.write((char*)(staff[j]), size);//запись объекта Employee
		if (!ouf) {
			cout << "\nЗапись в файл невозможна\n";
			return;
		}
	}
}

void read(vector<A*> staff) {//чтение всех данных из файла
	int size = sizeof(A);//размер объекта Employee
	EmployeeType etype;//тип работника
	ifstream inf;
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	int emplNum = 0;
	while (true) {
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof()) break;
		if (!inf) {//ошибка чтения типа
			cout << "\nНевозможно чтение типа\n";
			return;
		}
		inf.read((char*)staff[emplNum], size);
		if (!inf) {//ошибка, но не EOF
			cout << "\nЧтение данных из файла невозможно\n";
			return;
		}
		emplNum++;//счетчик работников увеличить
	}//end while
}

int main() {
	/*A* el = new A;
	EmployeeType el2;*/

	B* b = new B({new A("hui", "hui"), new A("her", "her")});

 //   ofstream fs;
 //   fs.open("test.DAT", ios::trunc | ios::binary);
	//int size1 = b->vec.size();
	//fs << size1;
	//for (int i = 0; i < size1; i++) {
	//	
	//	fs.write((char*)b->vec[i], sizeof(A));
	//}
 //   //fs.write((char*)b, sizeof(B));
 //   fs.close();

	B* temp = new B;
    ifstream ifs;
    ifs.open("test.DAT", ios::binary);
	int size;
	ifs >> size;
	temp->vec.resize(size);
	for (int i = 0; i < size; i++) {
		temp->vec[i] = el;
		ifs.read((char*)temp->vec[i], sizeof(A));
	}
    //ifs.read((char*)temp, sizeof(*b));
	for (int i = 0; i < temp->vec.size(); ++i) {
		cout << temp->vec[i]->name;
	}
	//vector<A*> staff(5);
	//staff[0] = new A;
	//staff[0]->name = "N/A";
	//staff[0]->surname = "Hui";
	////write(staff);
	//read(staff);
}
