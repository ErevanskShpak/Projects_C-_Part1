#pragma once
#include "Person.h"
#include "Exam.h"

class Teacher :
    public Person
{
    Exam exam;
public:
    Teacher(){}
    Teacher(Exam exam) { this->exam = exam; }
    Teacher(string name, string surname, Exam exam) :Person(name, surname) { this->exam = exam; }

    Exam getExam() const { return exam; }
};

istream& operator>>(istream& is, Teacher*& op);