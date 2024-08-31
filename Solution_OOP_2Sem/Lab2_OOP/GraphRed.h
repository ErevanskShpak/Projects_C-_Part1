#pragma once
#include "Check.h"
#include "File.h"
#include "Transactions.h"
#include "ElementHistory.h"
#include "History.h"

class GraphRed {
	vector<Transaction<File>> graph;

	bool isEmpty() const;
	unsigned int inputNumber();
	bool isAgreeChange(unsigned int );
public:
	GraphRed();
	void push_back();
	void erase();
	void edit();
	void convert(History& history);
	void show();
	void showAll();
};

