#pragma once
#include<iostream>
#include <vector>
#include <string>
#include "ElementHistory.h"
#include <iomanip>

using namespace std;

class History {
	static const vector<string> all_formats;
	vector<ElementHistory> history;

	bool isEditorCorrect(string);
	bool isFormatCorrect(string);
public:
	History();
	void push_back(ElementHistory obj);
	void showAll() const;
	void showEditor();
	void showFormatStart();
	void showFormatEnd();
};
