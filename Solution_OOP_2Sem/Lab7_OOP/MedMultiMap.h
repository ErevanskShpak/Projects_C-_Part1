#pragma once
#include <map>
#include <iomanip>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class MedMultiMap {
	map<string, MedWorker> medMultiMap;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
};
