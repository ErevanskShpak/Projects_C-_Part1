#pragma once
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class MedUnordMultiSet {
	unordered_multiset<MedWorker, MedWorker::HashFunction> medUnordMultiSet;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};
