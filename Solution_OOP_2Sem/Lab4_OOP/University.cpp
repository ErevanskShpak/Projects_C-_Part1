#include "University.h"

unsigned int University::findIndex(string what, int length) const {
	cout << "Input index of " << what << ": ";
	unsigned int i;
	while (true) {
		try {
			cin >> i;
			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (!(i > 0 && i <= length)) {
				throw out_of_range("out_of_range");
			}
			break;
		}
		catch (out_of_range&) {
			cout << "Incorrect input, value is out of range\n";
			cout << "Input: ";
		}
		catch (...) {
			cout << "Incorrect input, input is no numeric\n";
			cout << "Input: ";
		}
	}

	return i - 1;
}

template <typename T>
void University::readDataFromFile(string filename, vector<T*>& vec) {
	ifstream fs;
	fs.open(filename, ios::binary);
	if (!fs) {
		cout << "Unable to open file " << filename << endl;
		return;
	}
	fs.seekg(0, ios::end);
	short number = fs.tellg() / sizeof(T);
	vec.resize(number);
	fs.seekg(0);
	T* el = new T;
	for (auto& it : vec) {
		fs.read((char*)el, sizeof(T));
		it = el;
		el = new T;
	}
}

void University::readStudentFromFile() {
	ifstream fs;
	fs.open("students.DAT", ios::binary);
	if (!fs) {
		cout << "Unable to open file students.DAT" << endl;
		return;
	}
	
	Student* el = new Student;
	while (true) {
		int size;
		fs >> size;
		fs.read((char*)el, sizeof(string) * 5);
		if (fs.eof()) {
			break;
		}
		vector<Mark*> vec;
		vec.resize(size);
		for (int i = 0; i < size; ++i) {
			vec[i] = new Mark;
			fs.read((char*)vec[i], sizeof(Mark));
		}
		el->setMarks(vec);
		vecStud.push_back(el);
		el = new Student;
	}
}

template <typename T>
void University::writeDataToFile(string filename, vector<T*>& vec) {
	ofstream fs;
	fs.open(filename, ios::trunc | ios::binary);
	for (auto& el:vec) {
		fs.write((char*)el, sizeof(T));
	}
}

void University::writeStudentToFile() {
	ofstream fs;
	fs.open("students.DAT", ios::binary);

	for (auto& it : vecStud) {
		int size = it->getMarks().size();
		fs << size;
		fs.write((char*)it, sizeof(string) * 5);
		
		vector<Mark*> vec(it->getMarks());
		for (int i = 0; i < size; ++i) {
			fs.write((char*)vec[i], sizeof(Mark));
		}
	}
}

University::University() {
	readDataFromFile("exams.DAT", vecExam);
	readDataFromFile("teachers.DAT", vecTeach);
	readStudentFromFile();
}

void University::pushExam() {
	cout << "Input exam\n";
	Exam* exam = new Exam;
	cin >> exam;

	vecExam.push_back(exam);
	writeDataToFile("exams.DAT", vecExam);
}

void University::pushStudent() {
	unsigned int i = findIndex("exam", vecExam.size());
	Student* stud = new Student(*vecExam[i]);
	cout << "Input student\n";
	cin >> stud;

	vecStud.push_back(stud);
	writeStudentToFile();
}

void University::pushTeacher() {
	unsigned int i = findIndex("exam", vecExam.size());
	Teacher* teach = new Teacher(*vecExam[i]);
	cout << "Input teacher\n";
	cin >> teach;

	vecTeach.push_back(teach);
	writeDataToFile("teachers.DAT", vecTeach);
}

void University::showAllExam() const {
	cout << "------------------------------\n";
	cout << "|" << setw(6) <<"Number" << "|" << setw(10) << "Subject" << "|" << setw(10) << "Date" << "|" << endl;
	cout << "------------------------------\n";
	int i = 1;
	for (auto& exam : vecExam) {
		cout << "|" << setw(6) << i++ << "|" << setw(10) << exam->getSubject() << "|" << setw(10) << exam->getDate() << "|" << endl;
		cout << "------------------------------\n";
	}
	cout << endl;
}

void University::showAllStudent() const {
	cout.setf(ios::left);
	cout << "-------------------------------------------------------------------------------\n";
	cout << "|" << setw(6) << "" << "|" << setw(20) << "" << "|" << setw(20) << "" << "|" << setw(10) << "" << "|" << setw(17) << "Exam" << "|" << endl;
	cout << "|" << setw(6) << "Number" << "|" << setw(20) << "Surname" << "|" << setw(20) << "Name" << "|" << setw(10) << "Group" << "|-----------------|\n";
	cout << "|" << setw(6) << "" << "|" << setw(20) << "" << "|" << setw(20) << "" << "|" << setw(10) << "" << "|" << setw(10) << "Subject" << "|" << setw(6) << "Date" << "|" << endl;
	cout << "-------------------------------------------------------------------------------\n";
	int i = 1;
	for (auto& stud : vecStud) {
		cout <<"|" <<setw(6)<<i++ << "|" << setw(20) << stud->getSurname() << "|" << setw(20) << stud->getName() << "|" << setw(10) << stud->getGroup()
			<< "|" << setw(10) << stud->getExam().getSubject() << "|" << setw(6) << stud->getExam().getDate() << "|" << endl;
		cout << "-------------------------------------------------------------------------------\n";
	}
	cout << endl;
}

void University::showAllTeacher() const {
	cout.setf(ios::left);
	cout << "--------------------------------------------------------------------\n";
	cout << "|" << setw(6) <<"" << "|" << setw(20) << "" << "|" << setw(20) << "" << "|" << setw(17) << "Exam" << "|" << endl;
	cout << "|" << setw(6) <<"Number" << "|" << setw(20) << "Surname" << "|" << setw(20) << "Name" << "|-----------------|\n";
	cout << "|" << setw(6) <<"" << "|" << setw(20) << "" << "|" << setw(20) << "" << "|" << setw(10) << "Subject" << "|" << setw(6) << "Date" << "|" << endl;
	cout << "--------------------------------------------------------------------\n";
	int i = 1;
	for (auto& teach : vecTeach) {
		cout << "|" << setw(6) <<i++<< "|" << setw(20) << teach->getSurname() << "|" << setw(20) << teach->getName() << "|" << setw(10) << teach->getExam().getSubject()
			<< "|" << setw(6) << teach->getExam().getDate() << "|" << endl;
		cout << "--------------------------------------------------------------------\n";
	}
	cout << endl;
}

void University::showStudent() const {
	showAllStudent();
	unsigned int i = findIndex("student", vecStud.size());

	cout << *vecStud[i] << endl;
}

void University::editExam() {
	showAllExam();
	unsigned int i = findIndex("exam", vecExam.size());
	cout << "Edit exam\n";
	cin >> vecExam[i];

	writeDataToFile("exams.DAT", vecExam);
}

void University::editStudent() {
	showAllStudent();
	unsigned int i = findIndex("student", vecStud.size());
	cout << "Edit student\n";
	cin >> vecStud[i];

	writeStudentToFile();
}

void University::editTeacher() {
	showAllTeacher();
	unsigned int i = findIndex("teacher", vecTeach.size());
	cout << "Edit teacher\n";
	cin >> vecTeach[i];

	writeDataToFile("teachers.DAT", vecTeach);
}

void University::deleteExam() {
	showAllExam();
	unsigned int i = findIndex("exam", vecExam.size());
	vecExam.erase(vecExam.begin() + i);
	cout << "\nDelete completed\n";

	writeDataToFile("exams.DAT", vecExam);
}

void University::deleteStudent() {
	showAllStudent();
	unsigned int i = findIndex("student", vecStud.size());
	vecStud.erase(vecStud.begin() + i);
	cout << "\nDelete completed\n";

	writeStudentToFile();
}

void University::deleteTeacher() {
	showAllTeacher();
	unsigned int i = findIndex("teacher", vecTeach.size());
	vecTeach.erase(vecTeach.begin() + i);
	cout << "\nDelete completed\n";

	writeDataToFile("teachers.DAT", vecTeach);
}

void University::findExam() const {
	string subject;
	cout << "Input subject: ";
	while (true) {
		try {
			getline(cin, subject, '\n');
			if (!isWordCorrect(subject)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, subject must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}

	bool isBe = 0;
	for (auto& el : vecExam) {
		if (el->getSubject() == subject) {
			isBe = 1;
		}
	}

	if (isBe) {
		cout << setw(10) << left << "Subject" << setw(10) << left << "Date" << endl << endl;
		for (auto& el : vecExam) {
			if (el->getSubject() == subject) {
				cout << setw(10) << left << el->getSubject() << setw(10) << left << el->getDate() << endl;
			}
		}
	}
	else {
		cout << "No such exams\n";
	}
}

void University::findStudent() const {
	string fio;
	cout << "Input name and surname: ";
	while (true) {
		try {
			getline(cin, fio, '\n');
			if (!isFIOCorrect(fio)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, name and surname must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}

	bool isBe = 0;
	for (auto& el : vecStud) {
		string temp = el->getName() + " " + el->getSurname();
		if (temp == fio) {
			isBe = 1;
		}
	}

	if (isBe) {
		cout << setw(20) << left << "Name" << setw(20) << left << "Surname" << setw(10) << left << "Group" << setw(20) << left << "\tExam" << endl;
		cout << setw(50) << left << " " << setw(10) << left << "Subject" << setw(10) << left << "Date" << endl << endl;
		for (auto& stud : vecStud) {
			string temp = stud->getName() + " " + stud->getSurname();
			if (temp == fio) {
				cout << setw(20) << left << stud->getName() << setw(20) << left << stud->getSurname() << setw(10) << left << stud->getGroup()
					<< setw(10) << left << stud->getExam().getSubject() << setw(10) << left << stud->getExam().getDate() << endl;
			}
		}
	}
	else {
		cout << "No such students\n";
	}
}

void University::findTeacher() const {
	string fio;
	cout << "Input name and surname: ";
	while (true) {
		try {
			getline(cin, fio, '\n');
			if (!isFIOCorrect(fio)) {
				throw 1;
			}
			break;
		}
		catch (...) {
			cout << "Incorrect input, name and surname must consist only letters and starts from upper letter\n";
			cout << "Input: ";
		}
	}

	bool isBe = 0;
	for (auto& el : vecTeach) {
		string temp = el->getName() + " " + el->getSurname();
		if (temp == fio) {
			isBe = 1;
		}
	}

	if (isBe) {
		cout << setw(20) << left << "Name" << setw(20) << left << "Surname" << setw(20) << left << "\tExam" << endl;
		cout << setw(40) << left << " " << setw(10) << left << "Subject" << setw(10) << left << "Date" << endl << endl;
		for (auto& teach : vecTeach) {
			string temp = teach->getName() + " " + teach->getSurname();
			if (temp == fio) {
				cout << setw(20) << left << teach->getName() << setw(20) << left << teach->getSurname() << setw(10) << left << teach->getExam().getSubject()
					<< setw(10) << left << teach->getExam().getDate() << endl;
			}
		}
	}
	else {
		cout << "No such teachers\n";
	}
}

void University::sortExam() {
	sort(vecExam.begin(), vecExam.end(), [](Exam* a, Exam* b) {
		return a->getSubject() < b->getSubject();
		});
	showAllExam();
}

void University::sortStudent() {
	sort(vecStud.begin(), vecStud.end(), [](Student* a, Student* b) {
		return a->getSurname() < b->getSurname();
		});
	showAllStudent();
}

void University::sortTeacher() {
	sort(vecTeach.begin(), vecTeach.end(), [](Teacher* a, Teacher* b) {
		return a->getSurname() < b->getSurname();
		});
	showAllTeacher();
}
