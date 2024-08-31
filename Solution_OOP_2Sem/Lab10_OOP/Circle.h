#pragma once
#include "Heart.h"
#include "Shape.h"

class Circle : public Shape {
	float radius;
public:
	Circle(string color, float radius) :Shape(color) {
		this->radius = radius;
	}
	Circle(CircleSpec* spec) :Shape(spec->color) {
		this->name = spec->name;
		this->radius = spec->radius;
	}
	void setData() {
		this->radius = Input::inputNumber("radius", 0, 1000);
	}
	Shapes getType() const { return CIRCLE; }
	float getRadius() const { return radius; }
	Shape* makeUnit() const {
		return new Heart(new HeartSpec(Input::inputWord("name"),
			Input::inputWord("color"),
			Input::inputWord("type"),
			Input::inputNumber("length", 0, 1000),
			Input::inputNumber("width", 0, 1000)));
	}

	Shape* clone() const { return new Circle(*this); }
};

