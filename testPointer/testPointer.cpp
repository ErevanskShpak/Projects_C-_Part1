#include <iostream>

using namespace std;

int main()
{
	int* a = new int;
	*a = 5;
	int* b = a;
	*a = 10;
	cout << *b;
}