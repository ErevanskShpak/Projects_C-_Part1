#pragma once
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class MedUnordMap {
	unordered_map<string, MedWorker> medUnordMap;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};
