#pragma once
#include <string>
#include "Input.h"
#include "ShapeSpec.h"

using namespace std;

class Shape {
protected:
	string name;
	string color;
public:
	Shape(string color):color(color){}
	virtual void setData() {
		this->color = Input::inputWord("color");
	}
	string getName() const { return name; }
	virtual Shapes getType() const = 0;
	virtual Shape* makeUnit() const { return nullptr; }
	virtual Shape* clone() const = 0;
};

