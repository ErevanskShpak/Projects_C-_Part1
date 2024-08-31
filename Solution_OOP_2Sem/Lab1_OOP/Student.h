#pragma once
#include "Person.h"
#include<list>

using namespace std;

class Student :
    public virtual Person
{
public:
    class Grade {
        string subject;
        int mark;

        bool isSubjectCorrect() const;
    public:
        Grade():mark(0) {};
        Grade(string subject, int mark) :subject(subject), mark(mark) {};

        void setSubject();
        void setSubject(string subject) { this->subject = subject; }
        void setMark();
        void setMark(int mark) { this->mark = mark; }
        string getSubject() const { return subject; }
        int getMark() const { return mark; }
    };
protected:
    string school;
    list<Grade> grades;

    bool isSchoolCorrect();
public:
    Student() {}
    Student(string name, string surname, string school, list<Grade> grades) :
        Person(name, surname), school(school), grades(grades) {}

    void setSchool();
    void setSchool(string school) { this->school = school; }
    void setGrades();
    void setGrades(list<Grade> grades) { this->grades = grades; }
    string getSchool() const { return school; }
    list<Grade> getGrades() const { return grades; }

    void showMainInfo() const override {
        cout << "Student: ";
        Person::showMainInfo();
    }
    virtual void showAchievement() const override;
};