#pragma once
#include "Heart.h"
#include "Shape.h"

class Rectangle : public Shape {
	float length;
	float width;
public:
	Rectangle(string color, float length, float width) :Shape(color) {
		this->length = length;
		this->width = width;
	}
	Rectangle(RectangleSpec* spec) :Shape(spec->color) {
		this->name = spec->name;
		this->length = spec->length;
		this->width = spec->width;
	}
	void setData() {
		this->length = Input::inputNumber("length", 0, 1000);
		this->width = Input::inputNumber("width", 0, 1000);
	}
	Shapes getType() const { return RECTANGLE; }
	float getLength() const { return length; }
	float getWidth() const { return width; }
	Shape* makeUnit() const {
		return new Heart(new HeartSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputWord("type"),
			Input::inputNumber("length", 0, 1000),
			Input::inputNumber("width", 0, 1000)));
	}
	Shape* clone() const { return new Rectangle(*this); }
};

