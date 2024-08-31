#pragma once
#include <iostream>
#include <string>
#include "Check.h"

using namespace std;

class Mark {
	string subject;
	int value;

	bool isSubjectCorrect(string&) const;
public:
	Mark():value(1) {};
	Mark(string subject, int value) :subject(subject), value(value){}

	void setSubject();
	void setSubject(string subject) { this->subject = subject; }
	void setValue();
	void setValue(int value){}
	string getSubject() const { return subject; }
	int getValue() const { return value; }
};

