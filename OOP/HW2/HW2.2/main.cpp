#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
		
	// (6)
	static Example example_6(2333);
	for(int i = 0;i < n;i++)
		e[i]->getData();
	for(int i = 0;i < n;i++)
		delete e[i];
	
	example_6.getData();
	cout << "--------create_example is over--------\n";
}

// (7)
Example example_1(23);

int main() {

	cout << "--------main_function is ready--------\n";
	Example example_2(233);
	// (8)
		
	create_example(3);
	Example example_7(23333);
	example_1.getData();
	example_2.getData();
	example_7.getData();
	// (9)

	cout << "--------main_function is over---------\n";

	return 0;
}
