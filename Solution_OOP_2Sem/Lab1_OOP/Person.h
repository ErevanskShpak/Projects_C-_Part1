#pragma once
#include "Check.h"
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	string surname;

	bool isNameCorrect() const;
	bool isSurnameCorrect() const;
public:
	Person() {}
	Person(string name, string surname):name(name), surname(surname) {}

	void setName();
	void setName(string name) { this->name = name; }
	void setSurname();
	void setSurname(string surname) { this->surname = surname; }
	string getName() const { return name; }
	string getSurname() const { return surname; }

	virtual void showMainInfo() const {
		cout << getName() << " " << getSurname() << endl;
	}
	virtual void showAchievement() const = 0;
};