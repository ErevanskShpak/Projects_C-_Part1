#pragma once
#include <queue>
#include <iomanip>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class Queue {
	queue<MedWorker> medQueue;

	bool isEmpty() const;
public:
	void add();
	void del();
	void showAll();
};
