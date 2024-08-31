#pragma once
#include "Cloud.h"
#include "Shape.h"

class Star : public Shape {
	short amount;
	float radius;
public:
	Star(string color, short amount, float radius) :Shape(color) {
		this->amount = amount;
		this->radius = radius;
	}
	Star(StarSpec* spec) :Shape(spec->color) {
		this->name = spec->name;
		this->amount = spec->amount;
		this->radius = spec->radius;
	}
	void setData() {
		this->amount = Input::inputNumber("amount", 0, 1000);
		this->radius = Input::inputNumber("radius", 0, 1000);
	}
	Shapes getType() const { return STAR; }
	short getAmount() const { return amount; }
	float getRadius() const { return radius; }
	Shape* makeUnit() const {
		return new Cloud(new CloudSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputWord("type"),
			Input::inputNumber("length", 0, 1000),
			Input::inputNumber("width", 0, 1000)));
	}

	Shape* clone() const { return new Star(*this); }
};

