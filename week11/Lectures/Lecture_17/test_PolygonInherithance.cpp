#include "PolygonInherithance.h"

void test_inherithance()
{
	
	basic_polygon test_polygon;
	rectangle_inh test_polygon_r;
	square_inh test_polygon_s;
	triangle_inh test_polygon_t;

	test_polygon.printPolygonInfo();
	//
	test_polygon_r.inputSides(1,10);
	//test_polygon_r.printPolygonInfo();
	int temp=1;
	while(temp%2)
	{
		test_polygon_r.printPolygonInfo();
		test_polygon_r.setUnitFromKeyboard();
		test_polygon_r.printPolygonInfo();
		cout<<"enter an odd number if you intend to change unit again (even to stop);" << endl;
		cin >> temp;

	}
	//
	test_polygon_s.inputRandomSides();
	test_polygon_s.printPolygonInfo();
	//
	test_polygon_t.inputSides(3,4,5);
	test_polygon_t.printPolygonInfo();

	cout << endl;
}

void test_inherithance_virtual()
{
	// compile and run the following using the files as provided
	// then comment out the keyword virtual (/*virtual*/); complie and execute 
	basic_polygon test_polygon;
	rectangle_inh test_polygon_r;
	square_inh test_polygon_s;
	//
	test_polygon.printPolygonInfo();
	//
	test_polygon_r.inputRandomSides();
	test_polygon_r.printPolygonInfo();
	//
	test_polygon_s.inputRandomSides();
	test_polygon_s.printPolygonInfo();
	//
	basic_polygon* test_polygon_ptr1;
	basic_polygon* test_polygon_ptr2;
	basic_polygon* test_polygon_ptr3;
	//
	test_polygon_ptr1 = &test_polygon;
	test_polygon_ptr2 = &test_polygon_r;
	test_polygon_ptr3 = &test_polygon_s;
	//
	test_polygon_ptr1->printPolygonInfo();
	test_polygon_ptr2->printPolygonInfo();
	test_polygon_ptr3->printPolygonInfo();
}

int main()
{
	test_inherithance();
	test_inherithance_virtual();
	return 0;
}
