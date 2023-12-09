// #pragma once

#include "IntArrayInheritance.h"

void testIntArrayInheritance()
{
	intArray testArr;
	intArrayWithBounds testArrWb;

	cout << "Filling every array elelment with a random number" << endl;
	// (50% positive values, 50% negative values)
	for (int i = 0; i < intArray::MAX_SIZE; i++)
		if (rand() % 2)
			testArr.insertItem(rand(), i);
		else
			testArr.insertItem((-1) * rand(), i);
	cout << endl;
	cout << "Now print the array content to screen" << endl;
	testArr.printArrayContent();	
	cout << endl << endl;

	cout << "Now with the bounds." << endl;
	int inp_min_val, inp_max_val;
	cout << "Inset MIN array value: "; cin >> inp_min_val; cout	<< endl;
	cout << "Inset MAX array value: "; cin >> inp_max_val; cout << endl;
	testArrWb.setBounds(inp_min_val, inp_max_val);
	cout << "Filling every array element with a random number (within the limits)" << endl;
	// (50% positive values, 50% negative values)
	for (int i = 0; i < intArray::MAX_SIZE; i++)
		if (rand() % 2)
			testArrWb.insertItem(rand(), i);
		else
			testArrWb.insertItem((-1) * rand(), i);
	cout << endl;
	cout << "Now print the array content to screen" << endl;
	testArrWb.printArrayContent();
}

int main(){
	testIntArrayInheritance();

	return 0;
}
