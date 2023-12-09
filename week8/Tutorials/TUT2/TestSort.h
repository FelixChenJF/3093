//#pragma once

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>   

// helper function 
bool sortedInsertion(int elem, int sorted_array[], int& tot_sorted, int MAX_ELEMENTS)
{
	bool result = false;
	if (tot_sorted < MAX_ELEMENTS)
	{
		int ins_index;

		// scan all sored elements till the insertion point is found
		for (ins_index = 0; ins_index < tot_sorted; ins_index++)
			if (elem < sorted_array[ins_index])
				break;

		// make space: shift all items (past ins_index) towards the end; start from last elem
		for (int j = tot_sorted; j > ins_index; j--)
			sorted_array[j] = sorted_array[j - 1];

		// insert and update
		sorted_array[ins_index] = elem;
		tot_sorted++;
		result = true;
	}
	else
		cout << "Error: array full" << endl;

	return result;
}

// main function sorting array of integers
void sortIntArray(int inp_array[], int sorted_array[], int MAX_ELEMENTS)
{
	bool result;
	int curr_elem, tot_sorted = 0;

	// scan all elements of input 
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		curr_elem = inp_array[i];
		cout << "Inserting element " << i << " out of  " << MAX_ELEMENTS << "; value is " << curr_elem << endl;
		// sorted insertion of the current element
		result = sortedInsertion(curr_elem, sorted_array, tot_sorted, MAX_ELEMENTS);
		if (!result)
		{
			cout << "Insertion failed after " << tot_sorted << " items out of  " << MAX_ELEMENTS << endl;
			break;
		}
		else
		{
			cout << "Insertion succeeded. Sorted array so far:" << endl;
			for (int j = 0; j < tot_sorted; j++)
				cout << "  Sorted item " << j << " = " << sorted_array[j] << endl;
			cout << endl;
		}
	}
}

// test function
void testsorting()
{
	const int MAX_ELEMENTS = 10;
	int inp_array[MAX_ELEMENTS], sorted_array[MAX_ELEMENTS];

	// fill with random values
	for (int i = 0; i < MAX_ELEMENTS; i++)
		inp_array[i] = rand();

	// print input 
	cout << "input array" << endl;
	for (int i = 0; i < MAX_ELEMENTS; i++)
		cout << "item " << i << " = " << inp_array[i] << endl;

	sortIntArray(inp_array, sorted_array, MAX_ELEMENTS);

	// print input 
	cout << endl << "output array" << endl;
	for (int i = 0; i < MAX_ELEMENTS; i++)
		cout << "item " << i << " = " << sorted_array[i] << endl;
}