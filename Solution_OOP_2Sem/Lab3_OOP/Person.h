#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	string surname;

	bool isFIOCorrect(string&) const;
public:
	Person() {}
	Person(string name, string surname) :name(name), surname(surname) {}

	void setName();
	void setName(string name) { this->name = name; }
	void setSurname();
	void setSurname(string surname) { this->surname = surname; }
	string getName() const { return this->name; }
	string getSurname() const { return this->surname; }
};

