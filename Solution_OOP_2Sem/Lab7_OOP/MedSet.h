#pragma once
#include <set>
#include <iomanip>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class MedSet {
	set<MedWorker> medSet;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
};
