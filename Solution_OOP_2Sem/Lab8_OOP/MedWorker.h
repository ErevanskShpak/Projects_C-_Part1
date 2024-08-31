#pragma once
#include <iostream>
#include <string>

using namespace std;

class MedWorker {
	string name;
	string major;
public:
	MedWorker() {}
	MedWorker(string name, string major) :name(name), major(major) {}

	void setName(string name) { this->name = name; }
	void setMajor(string major) { this->major = major; }
	string getName() const { return name; }
	string getMajor() const { return major; }

	void show() const;

	bool operator<(const MedWorker& ob) const {

		return major < ob.major;
	}
};
