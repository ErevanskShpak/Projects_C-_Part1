#pragma once
#include <iostream>
#include <string>

using namespace std;

class ComputerNet {
	string name;
	string type; // global, local
public:
	ComputerNet() {}
	ComputerNet(string name, string type):name(name), type(type) {}

	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	string getName() { return name; }
	string getType() { return type; }

	void show() const;
};
