#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File {
	static const vector<string> all_formats;
	string name;
	string data;
	string format;

	bool isNameCorrect();
	bool isDataCorrect();
	bool isFormatCorrect();
public:
	File() {}
	File(string name, string data, string format) : name(name), data(data), format(format) {}

	void setName();
	void setName(string name) { this->name = name; }
	void setData();
	void setData(string data) { this->data = data; }
	void setFormat();
	void setFormat(string format) { this->format = format; }
	string getName() const { return name; }
	string getData() const { return data; }
	string getFormat() const { return format; }

	void showFullName() const;
};
