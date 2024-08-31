#pragma once
#include "Shapes.h"
#include <string>

using namespace std;

class ShapeSpec {
public:
	string name;
	string color;
	virtual Shapes getType() const = 0;
	ShapeSpec() {}
	ShapeSpec(string name, string color):name(name), color(color){}
};

class CircleSpec : public ShapeSpec {
public:
	float radius;
	Shapes getType() const { return CIRCLE; }
	CircleSpec():radius(0) {}
	CircleSpec(string name, string color, float radius) :ShapeSpec(name, color) {
		this->radius = radius;
	}
};

class RectangleSpec : public ShapeSpec {
public:
	float length;
	float width;
	Shapes getType() const { return RECTANGLE; }
	RectangleSpec():length(0), width(0) {}
	RectangleSpec(string name, string color, float length, float width) :ShapeSpec(name, color) {
		this->length = length;
		this->width = width;
	}
};

class StarSpec : public ShapeSpec {
public:
	short amount;
	float radius;
	Shapes getType() const { return STAR; }
	StarSpec():amount(0), radius(0) {}
	StarSpec(string name, string color, short amount, float radius) :ShapeSpec(name, color) {
		this->amount = amount;
		this->radius = radius;
	}
};

class CloudSpec : public ShapeSpec {
public:
	string type;
	float length;
	float width;
	Shapes getType() const { return CLOUD; }
	CloudSpec():length(0), width(0) {}
	CloudSpec(string name, string color, string type, float length, float width) :ShapeSpec(name, color) {
		this->type = type;
		this->length = length;
		this->width = width;
	}
};

class HeartSpec : public ShapeSpec {
public:
	string type;
	float length;
	float width;
	Shapes getType() const { return HEART; }
	HeartSpec(): length(0), width(0) {}
	HeartSpec(string name, string color, string type, float length, float width) :ShapeSpec(name, color) {
		this->type = type;
		this->length = length;
		this->width = width;
	}
};
