#pragma once
#include <vector>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "ComputerNet.h"

using namespace std;

class NetVec {
	vector<shared_ptr<ComputerNet>> vecNet;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};
