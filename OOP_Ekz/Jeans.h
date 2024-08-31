#pragma once
#include "Clothes.h"
#include <string>

class Jeans: public Clothes {
	string type;

public:
	Jeans() :Clothes() {
		type = "usual";
	}
	Jeans(short length, short width, string type) :Clothes(length, width) {
		this->type = type;
	}

	void showWho() override {
		cout << "I am jeans";
	}
};

