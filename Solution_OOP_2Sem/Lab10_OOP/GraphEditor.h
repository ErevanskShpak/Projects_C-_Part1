#pragma once
#include "ShapeSpec.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Star.h"
#include "CLoud.h"
#include "Heart.h"
#include <vector>
#include <memory>
#include <iomanip>
#include <fstream>

using namespace std;

class GraphEditor {
	vector<Shape*> vec;

	bool isEmpty() const;
	auto find();

	Shape* makeBaseShape(ShapeSpec*);
	auto makeStrangeShape(short);
public:
	~GraphEditor() {
		for (auto& el : vec) {
			delete el;
		}
		vec.clear();
	}
	void add();
	void del();
	void edit();
	void showAll() const;
};

