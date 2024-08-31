#pragma once
#include <iostream>
#include <string>

using namespace std;

class Input {
public:
	static bool isNumberNumeric();
	static bool isNumberRangeCorrect(short, short, short);
	static short inputNumber(string, short, short);
	static bool isWordCorrect(string&);
	static string inputWord(string);
	static string inputType();
};
