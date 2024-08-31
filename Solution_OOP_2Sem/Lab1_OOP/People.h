#pragma once
#include "Person.h"
#include "Student.h"
#include "Worker.h"
#include "StudentWorker.h"
#include <vector>
#include <algorithm>

class People {
	vector<Person*> vec;
	int size;
public:
	People();
	void push_back();
	void erase();
	void showPerson() const;
	void showAll() const;
	void sortPersons();
};