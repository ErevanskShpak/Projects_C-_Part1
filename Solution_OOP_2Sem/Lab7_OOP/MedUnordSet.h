#pragma once
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class MedUnordSet {
	unordered_set<MedWorker, MedWorker::HashFunction> medUnordSet;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};
