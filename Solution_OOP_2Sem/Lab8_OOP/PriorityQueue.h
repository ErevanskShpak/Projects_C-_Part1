#pragma once
#include <queue>
#include <iomanip>
#include <fstream>
#include "Input.h"
#include "MedWorker.h"

using namespace std;

class PriorityQueue {
	priority_queue<MedWorker> medPriorityQueue;

	bool isEmpty() const;
public:
	void add();
	void del();
	void showAll();
};
