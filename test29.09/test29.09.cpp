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

void write(vector<A*> staff) {//�������� ��� ������� � ����
	int size = sizeof(A);
	ofstream ouf;//������� ofstream
	EmployeeType etype = hui;//��� ������� ������� Employee
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	for (int j = 0; j < 1; j++) {
		//��� ������� ������� �������� ���
		ouf.write((char*)&etype, sizeof(etype));
		ouf.write((char*)(staff[j]), size);//������ ������� Employee
		if (!ouf) {
			cout << "\n������ � ���� ����������\n";
			return;
		}
	}
}

void read(vector<A*> staff) {//������ ���� ������ �� �����
	int size = sizeof(A);//������ ������� Employee
	EmployeeType etype;//��� ���������
	ifstream inf;
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	int emplNum = 0;
	while (true) {
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof()) break;
		if (!inf) {//������ ������ ����
			cout << "\n���������� ������ ����\n";
			return;
		}
		inf.read((char*)staff[emplNum], size);
		if (!inf) {//������, �� �� EOF
			cout << "\n������ ������ �� ����� ����������\n";
			return;
		}
		emplNum++;//������� ���������� ���������
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
