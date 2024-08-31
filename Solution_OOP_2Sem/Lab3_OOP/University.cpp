#include "University.h"

unsigned int University::findIndexExam() const {
	cout << "Input index of exam: ";
	unsigned int i;
	while (true) {
		try {
			cin >> i;
			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (!(i>0 && i <= vecExam.size())) {
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

unsigned int University::findIndexStudent() const {
	cout << "Input index of student: ";
	unsigned int i;
	while (true) {
		try {
			cin >> i;
			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (!(i > 0 && i <= vecStud.size())) {
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

University::University() {
	vecExam = {
		Exam("OOP", "10.06"),
		Exam("OAIP", "12.06")
	};
	vecStud = {
		Student("Daniil", "Paulouski", "224401", {new Mark("OOP", 10), new Mark("OAIP", 9)}, vecExam[0]),
		Student("Aleksandra", "Soloduha", "224401", {new Mark("OOP", 9), new Mark("OAIP", 8)}, vecExam[0]),
		Student("Vadim", "Banushevich", "224403", {new Mark("OOP", 2), new Mark("OAIP", 2)}, vecExam[0])
	};
	vecTeach = {
		Teacher("Dmitry", "Kukin", vecExam[1]),
		Teacher("Marina", "Salapura", vecExam[0])
	};
}

void University::pushExam() {
	cout << "Input exam\n";
	Exam exam;
	exam.setSubject();
	exam.setDate();

	vecExam.push_back(exam);
}

void University::pushStudent() {
	unsigned int i = findIndexExam();
	Student stud(vecExam[i]);
	cout << "Input student\n";
	stud.setName();
	stud.setSurname();
	stud.setGroup();
	stud.setMarks();

	vecStud.push_back(stud);
}

void University::pushTeacher() {
	unsigned int i = findIndexExam();
	Teacher teach(vecExam[i]);
	cout << "Input teacher\n";
	teach.setName();
	teach.setSurname();

	vecTeach.push_back(teach);
}

void University::showAllExam() const {
	cout << setw(10) << left << "Subject" << setw(10) << left << "Date" << endl << endl;
	for (const Exam& exam : vecExam) {
		cout << setw(10) << left << exam.getSubject() << setw(10) << left << exam.getDate() << endl;
	}
}

void University::showAllStudent() const {
	cout << setw(20) << left << "Name" << setw(20) << left << "Surname" <<setw(10)<<left<< "Group"<<setw(20) << left << "\tExam" << endl;
	cout << setw(50) << left << " " << setw(10) << left << "Subject" << setw(10) << left << "Date" << endl << endl;
	for (const Student& stud : vecStud) {
		cout << setw(20) << left << stud.getName() << setw(20) << left << stud.getSurname() << setw(10) << left << stud.getGroup() << setw(10) << left << stud.getExam().getSubject() << setw(10) << left << stud.getExam().getDate() << endl;
	}
}

void University::showAllTeacher() const {
	cout << setw(20) << left << "Name" << setw(20) << left << "Surname" << setw(20) << left << "\tExam" <<endl;
	cout << setw(40) << left <<" " << setw(10) << left << "Subject" << setw(10) << left << "Date" <<endl<<endl;
	for (const Teacher& teach : vecTeach) {
		cout <<setw(20) << left << teach.getName() << setw(20) << left << teach.getSurname() << setw(10) << left << teach.getExam().getSubject() << setw(10) << left << teach.getExam().getDate() << endl;
	}
}

void University::showStudent() const {
	unsigned int i = findIndexStudent();

	//cout << vecStud[i] << endl;
}
