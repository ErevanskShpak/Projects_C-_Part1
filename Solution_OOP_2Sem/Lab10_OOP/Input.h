#pragma once
#include <iostream>
#include <string>
#include "ShapeSpec.h"

using namespace std;

class Input {
public:
	static bool isNumberNumeric();
	static bool isNumberRangeCorrect(float, float, float);
	static float inputNumber(string, float, float);
	static bool isWordCorrect(string&);
	static string inputWord(string);
	static ShapeSpec* inputShape(short);
};
