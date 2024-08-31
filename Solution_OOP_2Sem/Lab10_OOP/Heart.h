#pragma once
#include "Shape.h"

class Heart : public Shape {
	string type;
	float length;
	float width;
public:
	Heart(string color, string type, float length, float width) :Shape(color) {
		this->type = type;
		this->length = length;
		this->width = width;
	}
	Heart(HeartSpec* spec) :Shape(spec->color) {
		this->name = spec->name;
		this->type = spec->type;
		this->length = spec->length;
		this->width = spec->width;
	}
	void setData() {
		this->type = Input::inputWord("type");
		this->length = Input::inputNumber("length", 0, 1000);
		this->width = Input::inputNumber("width", 0, 1000);
	}
	Shapes getType() const { return HEART; }
	string getTypeH() const { return type; }
	float getLength() const { return length; }
	float getWidth() const { return width; }

	Shape* clone() const { return new Heart(*this); }
};

