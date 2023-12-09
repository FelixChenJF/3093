// #pragma once
#include "RectangleExample.h"

void testRectangleOperators()
{
	rectangle rctA, rctB;
	cout << "Rectangle A:" << endl;
	rctA.inputRandomSides();
	rctA.printRectangleInfo();
	cout << endl;
	cout << "Rectangle B:" << endl;
	rctB.inputRandomSides();
	rctB.printRectangleInfo();
	cout << endl;
	cout << "Set B = A and print B:" << endl;
	rctB = rctA;
	//rctB.copyFrom(rctA);
	cout << "Rectangle B:" << endl;
	rctB.printRectangleInfo();
	cout << endl;
	cout << "Set B = A + B and print B:" << endl;
	rctB = rctA + rctB;
	rctB.printRectangleInfo();
	cout << endl;

	cout << "Compare A and B" << endl;
	bool result;
	result = rctA < rctB;
	if (result) {
		cout << "A < B: " << result << endl;
	} else cout << "A > B: " << result << endl;


}

int main(){

	testRectangleOperators();
	return 0;
}
