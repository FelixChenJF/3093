#include "RectangleExample.h"
#include "RightTriangleExample.h"
#include "Polygon_w_color.h"
#include "Pet_w_color.h"
#include <time.h>      

void test_pet()
{
	const int arraysize = 5;
	petWcolor pet_array[arraysize];

	pet::petTypeOptions in_petType = pet::cat;
	double in_weight_kg = 0.5;
	petColor::petColorOptions inp_color = petColor::white;

	for (int i = 0; i < arraysize; i++)
	{
		cout << "Array item " << i << endl;
		//pet_array[i].inputFromKeyboard();	
		pet_array[i].inputValues(in_petType, in_weight_kg + i, inp_color);
		pet_array[i].printInfo();
		cout << endl;
	}
}

void test_color_print()
{
	rectangleWcolor test_rct;
	test_rct.inputRandomValues();
	cout << "rectangle color is: " << test_rct.the_color.colorToString() << endl << endl;
}

void test_pet_and_polygon()
{
	const int arraysize = 5;
	petWcolor pet_array[arraysize];
	pet::petTypeOptions in_petType = pet::cat;
	double in_weight_kg = 0.5;
	petColor::petColorOptions pet_inp_color = petColor::orange;	
	rectangleWcolor rec_array[arraysize];
	polygonColor::polygonColorOptions rec_inp_color = polygonColor::orange;
	
	cout << "petColorOptions enum: Orange enum value: "     <<      petColor::orange << endl;
	cout << "polygonColorOptions enum: Orange enum value: " <<  polygonColor::orange << endl << endl;
	
	for (int i = 0; i < arraysize; i++)
	{
		cout << "Pet Array item " << i << endl;
		pet_array[i].inputValues(in_petType, in_weight_kg + i, pet_inp_color);
		pet_array[i].printInfo();
		cout << endl;

		cout << "Rectangle Array item " << i << endl;
		rec_array[i].inputValues(1+i, 2*(1 + i), rec_inp_color);
		rec_array[i].printInfo();
		cout << endl << endl;
	}
}

void test_overload()
{
	rectangle test_rc; int max_val, min_val; min_val = 8; max_val = 10;
	cout << "First version, with sides up to the default value" << endl;
	test_rc.inputRandomSides(); test_rc.printRectangleInfo();
	cout << endl << "First version, with sides up to " << max_val << endl;
	test_rc.reset(); test_rc.inputRandomSides(10); test_rc.printRectangleInfo();	
	cout << endl << "Second version, with sides in [ " << min_val << " , " << max_val << " ]" << endl;
	test_rc.reset(); test_rc.inputRandomSides(min_val, max_val); test_rc.printRectangleInfo();
}


int main(int argc, char** argv) 
{
	char final[10];
	//test_color_print();
	//test_pet_and_polygon();
	//test_pet();
	test_overload();
	cout << " Press any number/letter key then Enter to finish ";
	cin >> final;	
	return 0;
}
