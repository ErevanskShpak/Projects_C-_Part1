#pragma once
#include <array>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <fstream>
#include "Input.h"
#include "ComputerNet.h"

using namespace std;

class NetArray {
	array<shared_ptr<ComputerNet>, 5> arrNet;
public:
	NetArray() {
		arrNet[0] = make_shared<ComputerNet>("myNet", "local");
		arrNet[1] = make_shared<ComputerNet>("BSUIR", "global");
		arrNet[2] = make_shared<ComputerNet>("Andrey", "local");
		arrNet[3] = make_shared<ComputerNet>("colour", "local");
		arrNet[4] = make_shared<ComputerNet>("banana", "global");
	}

	void edit();
	void showAll() const;
	void find() const;
	void sortAll();
};

