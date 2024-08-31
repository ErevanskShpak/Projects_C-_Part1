#pragma once
#include <list>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "ComputerNet.h"

using namespace std;

class NetList {
	list<shared_ptr<ComputerNet>> listNet;

	bool isEmpty() const;
public:
	void add();
	void del();
	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};
