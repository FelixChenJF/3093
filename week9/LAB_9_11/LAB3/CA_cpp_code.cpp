// CA_cpp_code.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Circle.h"
#include "Square.h"
void testPart1()
{
	const int tot_test = 10;	
	circle testobj_array[tot_test];
	for (int i = 0; i < tot_test; i++)
	{
		cout<< "Test item i=" << i << endl;
		cout << "Init shape :" << endl;
		testobj_array[i].inputRandomSide();

		cout << "Init coordinates:" << endl;
		testobj_array[i].inputRandomCoord();
		testobj_array[i].printShapeAndCoordInfo();

		cout << "Done" << endl<< endl;
	}
	
}

void testPart2Circle()
{
	static const int TOT_ITEMS = 20;
	circle in_array[TOT_ITEMS], out_array[TOT_ITEMS];
	int tot_matching_items;
	circle target;
	// rule 0: Center of item_i is inside Target
	// rule 1: Center of Target is inside item_i
	// rule 2: Target is entirely inside item_i
	// rule 3: item_i is entirely inside Target
	// rule 4: item_i and Target overlap (one partly or entirely inside the other)
	int ruleindex = 0;

	// set the target 
	target.inputCoord(0.0, 0.0);
	target.inputSide(10.0);

	// fill the input array
	fillCircleArray(in_array, TOT_ITEMS);
	//cout << "Input array" << endl <<  endl;
	//printCircleArray(in_array, TOT_ITEMS);

	// search in_array[], find all items that match the target (tot_matching_items); 
	// Set elements of out_array so that: 
	// out_array[0] is the first element in in_array[] that matches the target
	// out_array[1] is the second element in in_array[] that matches the target
	// ...
	// out_array[tot_matching_items-1] is the last element in in_array[] that matches the target
	tot_matching_items = findMatchingCircles(target, in_array, out_array, TOT_ITEMS, ruleindex);

	// print the result:
	cout << "Target:" << endl;
	target.printShapeAndCoordInfo();
	cout << endl << "All " << tot_matching_items << " matching items" << endl;
	printCircleArray(out_array, tot_matching_items);
}

void testPart2Square()
{
	static const int TOT_ITEMS = 20;
	square in_array[TOT_ITEMS], out_array[TOT_ITEMS];
	int tot_matching_items;
	square target;
	// rule 0: Center of item_i is inside Target
	// rule 1: Center of Target is inside item_i
	// rule 2: Target is entirely inside item_i
	// rule 3: item_i is entirely inside Target
	// rule 4: item_i and Target overlap (one partly or entirely inside the other)
	int ruleindex = 0;

	// set the target 
	target.inputCoord(0.0, 0.0);
	target.inputSide(10.0);
	// print to screen:
	//cout << "Target:" << endl;
	//target.printShapeAndCoordInfo();
	// fill the input array
	fillSquareArray(in_array, TOT_ITEMS);
	//cout << "Input array" << endl <<  endl;
	//printCircleArray(in_array, TOT_ITEMS);

	// search in_array[], find all items that match the target (tot_matching_items); 
	// Set elements of out_array so that: 
	// out_array[0] is the first element in in_array[] that matches the target
	// out_array[1] is the second element in in_array[] that matches the target
	// ...
	// out_array[tot_matching_items-1] is the last element in in_array[] that matches the target
	tot_matching_items = findMatchingSquares(target, in_array, out_array, TOT_ITEMS, ruleindex);

	// print the result:
	cout << "Target:" << endl;
	target.printShapeAndCoordInfo();
	cout << endl << "All " << tot_matching_items << " matching items" << endl;
	printSquareArray(out_array, tot_matching_items);
}

int main()
{
	// testPart1();
	testPart2Circle();
	// testPart2Square();
	//cout << "Hello World!\n";
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
