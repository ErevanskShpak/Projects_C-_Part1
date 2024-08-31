#pragma once
#include "Clothes.h"
#include <string>

class Jacket : public Clothes {
	string color;

public:
	Jacket() :Clothes() {
		color = "black";
	}
	Jacket(short length, short width, string type) :Clothes(length, width) {
		this->color = type;
	}

	void showWho() override {
		cout << "I am jacket";
	}
};
