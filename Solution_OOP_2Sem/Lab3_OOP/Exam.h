#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exam {
	string subject;
	string date;

	bool isSubjectCorrect(string&) const;
	bool isDateCorrect(string&) const;
public:
	Exam() {}
	Exam(string subject, string date):subject(subject), date(date){}

	void setSubject();
	void setSubject(string subject) { this->subject = subject; }
	void setDate();
	void setDate(string date) { this->date = date; }
	string getSubject() const { return subject; }
	string getDate() const { return date; }

};

istream& operator>>(istream& is, Exam*& op);