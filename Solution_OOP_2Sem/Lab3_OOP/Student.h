#pragma once
#include "Person.h"
#include "Mark.h"
#include "Exam.h"
#include <vector>

class Student :
    public Person 
{
    Exam exam;
    string group;
    vector<Mark*> marks;
    
    bool isGroupCorrect(string&) const;
    short inputNumberMarks() const;
public:
    Student(){}
    Student(Exam exam) { this->exam = exam; }
    Student(string name, string surname, string group, vector<Mark*> mark, Exam exam) :Person(name, surname) {
        this->group = group;
        this->marks = mark;
        this->exam = exam;
    }

    void setGroup();
    void setGroup(string group) { this->group = group; }
    void setMarks() {
        unsigned int number = inputNumberMarks();

        marks.resize(number);

        Mark* mark = new Mark;
        for (unsigned int i = 0; i < number; i++) {
            mark->setSubject();
            mark->setValue();
            marks[i] = mark;
            mark = new Mark;
        }
    }
    void setMarks(vector<Mark*> marks) { this->marks = marks; }
    string getGroup() const { return group; }
    vector<Mark*> getMarks() const { return marks; }
    Exam getExam() const { return exam; }
};

istream& operator>>(istream& is, Student*& op);
ostream& operator<<(ostream&, Student& op);