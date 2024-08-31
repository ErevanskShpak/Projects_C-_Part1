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

	bool operator<(const MedWorker& ob) const{

		return name < ob.name;
	}

	bool operator==(const MedWorker& ob) const {
		return name == ob.name && major == ob.major;
	}

	class HashFunction {
	public:
		size_t operator()(const MedWorker& ob) const {
			int p = 31;
			long long hash = 0, p_pow = 1;
			string word = ob.getName();
			for (int i = 0; i < word.size(); i++)
			{
				hash += (word[i] - 'a' + 1) * p_pow;
				p_pow *= p;
			}
			return hash;
		}
 	};
};
