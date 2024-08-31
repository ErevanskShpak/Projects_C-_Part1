#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

bool isNumberNumeric();

template<class T>
inline unsigned int inputNumber(T left, T right) {
	unsigned int i;
	cin.unsetf(ios::skipws);
	while (true) {
		try {
			cin >> i;
			if (!isNumberNumeric()) {
				throw "incorrect input";
			}
			if (i<left || i>right) {
				throw out_of_range("out_of_range");
			}
			break;
		}
		catch (out_of_range&) {
			cout << "Input is incorrect, the value is out of range\n";
			cout << "Input: ";
		}
		catch (...) {
			cout << "Input is incorrect, input is not numeric\n";
			cout << "Input: ";
		}
	}

	return i;
}

bool isWordCorrect(string&);
bool isFIOCorrect(string&);