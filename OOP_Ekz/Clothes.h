#pragma once
#include <iostream>

using namespace std;

class Clothes {
	short length;
	short width;

public:
	Clothes():length(0), width(0) {}
	Clothes(short length, short width):length(length), width(width) {}

	virtual void showWho() = 0;
};

