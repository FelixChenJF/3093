#include "RectangleExample.h"

void setArrayRandomVals(rectangle in_array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "-->Setting array element " << i << endl;
		in_array[i].inputRandomSides();
		in_array[i].printRectangleInfo();
	}
}

void setSingleRectangleVals(rectangle in_rct)
{
	cout << "Setting individual rectangle" << endl;
	in_rct.inputRandomSides();
	in_rct.printRectangleInfo();
}

void testQuestion()
{
	char check[10];
	// defint the array size used for static allocation
	static const int ARRAY_SIZE = 3;
	rectangle rct, rct_array[ARRAY_SIZE];

	cout << " This function intends to perform the following steps:" << endl;
	cout << " (1) Call a function to fill an array of rectangles with (pseudo) random values." << endl;
	cout << "     The function prints to screen the info for each rectangle." << endl;
	cout << " (2) Call a function to fill a single rectangles with random values." << endl;
	cout << "     The function prints to screen the info for the rectangle." << endl;
	cout << " (3) Cross-check that both the array and the rectangle have been filled with random values" << endl;
	cout << "     (by  printing to screen the info for both of them)." << endl << endl;

	cout << " Read the section above, then press any number/letter key (then Enter) to continue ";
	cin >> check; cout << endl << endl;

	
	cout << " Set all rectangles in the array (size "<< ARRAY_SIZE << ") with random values" << endl;
	setArrayRandomVals(rct_array, ARRAY_SIZE);
	cout << " Done" << endl << endl;;

	cout << " Now Set the individual rectangle with random values" << endl;
	setSingleRectangleVals(rct);
	cout << " Done" << endl << endl;

	cout << " Read the section above, then press any number/letter key (then Enter) to continue ";
	cin >> check; cout << endl << endl;

	cout << " Now print the array:" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		rct_array[i].printRectangleInfo();
	cout << " Done" << endl << endl << endl;

	cout << " Now print the individual rectangle:" << endl;
	rct.printRectangleInfo();		
	cout << " Done" << endl << endl << endl;


	cout << " Does the result match the objectives (1) to (3) set above for this function? " << endl;
	cout << " If not, why? How can the problem be solved?" << endl;
	cout << " Note: if file TestQuestion.h was missing a single symbol, in order to perform objectives (1) to (3)," << endl;
	cout << " would you know which symbol and where to put it?" << endl;
	cout << " Check the code in TestQuestion.h and give your answer" << endl;
	cout << endl << endl << endl;
	cout << " End of TestQuestion()" << endl;

}