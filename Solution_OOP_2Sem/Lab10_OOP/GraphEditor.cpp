#include "GraphEditor.h"

bool GraphEditor::isEmpty() const {
	if (vec.empty()) {
		cout << "Vector is empty\n";
		return true;
	}

	return false;
}

auto GraphEditor::find() {
	string name = Input::inputWord("name");

	auto it = vec.begin();
	for (; it != vec.end(); ++it) {
		if ((*it)->getName() == name) {
			return it;
		}
	}

	cout << "There is no such object\n";
	return it;
}

Shape* GraphEditor::makeBaseShape(ShapeSpec* shapeSpec) {
	switch (shapeSpec->getType()) {
	case CIRCLE: return new Circle(static_cast<CircleSpec*>(shapeSpec));
	case RECTANGLE: return new Rectangle(static_cast<RectangleSpec*>(shapeSpec));
	case STAR: return new Star(static_cast<StarSpec*>(shapeSpec));
	}
}

auto GraphEditor::makeStrangeShape(short i) {
	auto it = find();
	if (it != vec.end()) {
		Shapes type = (*it)->getType();

		switch (i) {
		case 4:
			if (!(type == CIRCLE || type == RECTANGLE)) {
				it = vec.end();
			}
			break;
		case 5:
			if (!(type == STAR)) {
				it = vec.end();
			}
			break;
		}
	}
	return it;
}

void GraphEditor::add() {
	cout << "Input choice of shape\n";
	cout << "1. Circle\n";
	cout << "2. Rectangle\n";
	cout << "3. Star\n";
	cout << "4. Cloud\n";
	cout << "5. Heart\n";

	Shape* cur;
	short choice = Input::inputNumber("choice", 1, 5);
	switch (choice) {
	case 1:case 2:case 3: cur = makeBaseShape(Input::inputShape(choice)); break;
	case 4:case 5: { 
		auto it = makeStrangeShape(choice);
		if (it == vec.end()) {
			cout << "Incorrect object for creation\n";
			return;
		}
		cur = (*it)->makeUnit();
	}
	}

	vec.push_back(cur);
}

void GraphEditor::del() {
	if (isEmpty()) { return; }
	showAll();

	auto it = find();
	if (it != vec.end()) {
		delete (*it);
		vec.erase(it);
		cout << "Delete completed\n";
	}
}

void GraphEditor::edit() {
	if (isEmpty()) { return; }
	showAll();

	auto it = find();
	if (it != vec.end()) {
		(*it)->setData();
		cout << "Edit completed\n";
	}
}

void GraphEditor::showAll() const {
	if (isEmpty()) { return; }

	vector<Circle*> vecCir;
	vector<Rectangle*> vecRec;
	vector<Star*> vecStar;
	vector<Cloud*> vecCloud;
	vector<Heart*> vecHeart;
	for (auto& el : vec) {
		switch (el->getType()) {
		case CIRCLE: vecCir.push_back(static_cast<Circle*>(el)); break;
		case RECTANGLE: vecRec.push_back(static_cast<Rectangle*>(el)); break;
		case STAR: vecStar.push_back(static_cast<Star*>(el)); break;
		case CLOUD: vecCloud.push_back(static_cast<Cloud*>(el)); break;
		case HEART: vecHeart.push_back(static_cast<Heart*>(el)); break;
		}
	}

	ofstream fout("vec.txt");
	if (!vecCir.empty()) {
		string line(30, '-');
		cout << "\nCircles\n";
		fout << "\nCircles\n";
		cout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Radius" << "|" << endl << line << endl;
		fout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Radius" << "|" << endl << line << endl;
		short i = 0;
		for (auto& el : vecCir) {
			cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getRadius() << "|" << endl << line << endl;
			fout << "|" << setw(6) << i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getRadius() << "|" << endl << line << endl;
		}
	}
	else {
		cout << "There is no circles\n";
	}

	if (!vecRec.empty()) {
		string line(41, '-');
		cout << "\nRectangles\n";
		fout << "\nRectangles\n";
		cout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		fout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		short i = 0;
		for (auto& el : vecRec) {
			cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
			fout << "|" << setw(6) << i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
		}
	}
	else {
		cout << "There is no rectangles\n";
	}

	if (!vecStar.empty()) {
		string line(41, '-');
		cout << "\nStars\n";
		fout << "\nStars\n";
		cout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Amount" << "|" << setw(10) << "Radius" << "|" << endl << line << endl;
		fout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|"
			<< setw(10) << "Amount" << "|" << setw(10) << "Radius" << "|" << endl << line << endl;
		short i = 0;
		for (auto& el : vecStar) {
			cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getAmount() << "|" << setw(10) << el->getRadius() << "|" << endl << line << endl;
			fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|"
				<< setw(10) << el->getAmount() << "|" << setw(10) << el->getRadius() << "|" << endl << line << endl;
		}
	}
	else {
		cout << "There is no stars\n";
	}

	if (!vecCloud.empty()) {
		string line(52, '-');
		cout << "\nClouds\n";
		fout << "\nClouds\n";
		cout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|" << setw(10) << "Type" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		fout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|" << setw(10) << "Type" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		short i = 0;
		for (auto& el : vecCloud) {
			cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|" << setw(10) << el->getTypeH() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
			fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|" << setw(10) << el->getTypeH() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
		}
	}
	else {
		cout << "There is no clouds\n";
	}

	if (!vecHeart.empty()) {
		string line(52, '-');
		cout << "\nHearts\n";
		fout << "\nHearts\n";
		cout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|" << setw(10) << "Type" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		fout << line << endl << "|" << setw(6) << "Number" << "|" << setw(10) << "Name" << "|" << setw(10) << "Type" << "|"
			<< setw(10) << "Length" << "|" << setw(10) << "Width" << "|" << endl << line << endl;
		short i = 0;
		for (auto& el : vecHeart) {
			cout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|" << setw(10) << el->getTypeH() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
			fout << "|" << setw(6) << ++i << "|" << setw(10) << el->getName() << "|" << setw(10) << el->getTypeH() << "|"
				<< setw(10) << el->getLength() << "|" << setw(10) << el->getWidth() << "|" << endl << line << endl;
		}
	}
	else {
		cout << "There is no hearts\n";
	}
}
