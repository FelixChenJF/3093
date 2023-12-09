#include <cstdlib>
#include <time.h>
#include "Polygon_w_color.h"
#include "square.h"
//#include <iostream>
//using namespace std;


void test_part_4(squareWcolor  array_sq[], squareWcolor array_sq_sorted[], int arraysize)
{
     // Solution not provided for the advanced part:
     // students who have implemented this function partially 
     // (or completely but get an incorrect result) 
     // are encouraged to discuss their solution with course staff 
     // at the Tutorial or at any other opportunity after that. 
     
}

void test_part_3c(rectangleWcolor array_rc[], squareWcolor array_sq[], int arraysize)
{
    double area, in_side;
    polygonColorOptions in_color;
	for(int i=0; i<arraysize; i++)
	{
		cout << "VVVVVVVVVVVVV" <<endl;
        cout << "  Rectangle " << i << " :" << endl;
		array_rc[i].printInfo();
        // read color and area from the rectangle
        area=array_rc[i].the_rectangle.getArea(); 
		in_color=array_rc[i].the_color.getColor(); 
		// set color and side to the square
        in_side=sqrt(area);
		array_sq[i].the_square.inputSide(in_side);
		array_sq[i].the_color.setColor(in_color);
        cout << "  Square " << i << " :" <<endl;
        array_sq[i].printInfo();        
        cout << "^^^^^^^^^^^^^" << endl << endl;
	}
}

void test_part_3b(rectangleWcolor array_rc[], int arraysize)
{
     // initialize random seed via srand() 
	// using the current time to set the seed
	srand(time(NULL));
	/////
	for(int i=0; i<arraysize; i++)
	{
		array_rc[i].inputRandomValues();
		array_rc[i].printInfo();
	}
}

void test_part_1to3()
{
     rectangle obj1;
     right_triangle obj2;
     rectangleWcolor obj3;
     right_triangleWcolor obj4;
     squareWcolor obj5;
     
     cout << "object 1:" << endl;
     obj1.inputRandomSides();
     obj1.printRectangleInfo();
     cout << "object 1 (again):" << endl;
     obj1.reset();
     obj1.inputRandomSides();
     obj1.printRectangleInfo();
     cout << endl << endl;
     cout << "object 2:" << endl;
     obj2.inputRandomSides();
     obj2.printTriangleInfo();
     cout << endl << endl;
     cout << "object 3:" << endl;
     obj3.inputRandomValues();
     obj3.printInfo();
     cout << endl << endl;
     cout << "object 4:" << endl;
     obj4.inputRandomValues();
     obj4.printInfo();     
     cout << "object 4 (again):" << endl;
     obj4.reset();
     obj4.inputRandomValues();
     obj4.printInfo();
     cout << endl << endl;
     cout << "object 5:" << endl;
     obj5.inputRandomValues();
     obj5.printInfo();
}


int main(int argc, char *argv[])
{
    //test_part_1to3();
    //cout << "this works" << endl;
    const int arraysize=10;
    rectangleWcolor array_rc[arraysize];
    squareWcolor array_sq[arraysize];
    
    test_part_3b(array_rc, arraysize);
    cout << "this works too" << endl;
    
    test_part_3c(array_rc, array_sq, arraysize);
    cout << " and this works as well" << endl;
    
    
    squareWcolor array_sq_sorted[arraysize];
    test_part_4(array_sq, array_sq_sorted, arraysize);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
