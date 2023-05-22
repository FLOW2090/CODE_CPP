#include <iostream>
#include "Example.h"

using namespace std;

int Example::size = 0;// (2)

Example::Example(int data) {
	_data = data;
	size++;
	id = size;
	cout << "Example #" << id << " is created" << endl;
	// (3)
}

void Example::getData() {
	cout << "The data of Example #" << id << " is " << _data << endl;
	// (4)
}

Example::~Example() {
	cout << "Example #" << id << " is destroyed" << endl;
	// (5)
}