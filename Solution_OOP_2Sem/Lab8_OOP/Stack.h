#pragma once
#include <stack>
#include <iomanip>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class Stack {
	stack<MedWorker> medStack;

	bool isEmpty() const;
public:
	void add();
	void del();
	void showAll();
};
