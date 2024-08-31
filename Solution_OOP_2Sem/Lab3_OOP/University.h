#pragma once
#include "Student.h"
#include "Teacher.h"
#include <iomanip>

class University {
	vector<Exam> vecExam;
	vector<Student> vecStud;
	vector<Teacher> vecTeach;

	unsigned int findIndexExam() const;
	unsigned int findIndexStudent() const;
public:
	University();

	void pushExam();
	void pushStudent();
	void pushTeacher();
	void showAllExam() const;
	void showAllStudent() const;
	void showAllTeacher() const;
	void showStudent() const;
};

