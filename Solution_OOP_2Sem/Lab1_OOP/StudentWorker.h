#pragma once
#include "Person.h"
#include "Student.h"
#include "Worker.h"

class StudentWorker :
    public Student,
    public Worker
{
public:
    StudentWorker(){}
    StudentWorker(string name, string surname, string school, list<Grade> grades, Money salary):
        Person(name, surname), Student(name, surname, school, grades), Worker(name, surname, salary) {}

    void showMainInfo() const override {
        cout << "StudentWorker: ";
        Person::showMainInfo();
    }
    void showAchievement() const override {
        Student::showAchievement();
        Worker::showAchievement();
    }
};