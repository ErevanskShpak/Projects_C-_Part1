#pragma once
#include "Student.h"
#include "Teacher.h"
#include <iomanip>
#include <fstream>
#include <algorithm>

class University {
	vector<Exam*> vecExam;
	vector<Student*> vecStud;
	vector<Teacher*> vecTeach;

	unsigned int findIndex(string, int) const;
	template <typename T>
	void readDataFromFile(string, vector<T*>&);
	void readStudentFromFile();
	template <typename T>
	void writeDataToFile(string, vector<T*>&);
	void writeStudentToFile();
public:
	University();

	void pushExam();
	void pushStudent();
	void pushTeacher();
	void showAllExam() const;
	void showAllStudent() const;
	void showAllTeacher() const;
	void showStudent() const;
	void editExam();
	void editStudent();
	void editTeacher();
	void deleteExam();
	void deleteStudent();
	void deleteTeacher();
	void findExam() const;
	void findStudent() const;
	void findTeacher() const;
	void sortExam();
	void sortStudent();
	void sortTeacher();
};
