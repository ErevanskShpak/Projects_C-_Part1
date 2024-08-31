#include "Check.h"

bool isNumberNumeric() {
	if (std::cin.get() == '\n')
		return true;
	else {
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return false;
	}
}