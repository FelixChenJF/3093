#include "RectangleExample.h"
#include "RightTriangleExample.h"
#include "Polygon_w_color.h"

#include <time.h>  
// Scope Resolution, i.e. operator :: (required for member function definition) 
double rectangle::getArea(){
	if(isInitialized()){
		return area;
	}else{
		cout << "Error in getArea(): Rectangle is not initialied" << endl;
		return 0;
	}
}

double rectangle::getPerimeter(){
	if(isInitialized()){
		return perimeter;
	}else{
		cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;
	}
}

bool rectangle::isInitialized(){
	return init_flag;
}

double rectangle::getSide(int sidenum){
	double out;
	if(isInitialized())
		{
			switch(sidenum){
			case 1:
				out=sideA;
				break;
			case 2:
				out=sideB;
				break;
			default:
				cout << "Error in getSide(): Incorrect sidenum value" << endl;
				out=-1;
			}
		}else{
			cout << "Error in getSide(): Rectangle is not initialized" << endl;
			out=-1;
		}
		return out;
}

void Part_1(right_triangle obj_array[], int arraysize)
{
	for(int i=0; i<arraysize; i++)		
	{
		cout << "object position "<< i << ":" << endl;
		obj_array[i].inputSidesFromKeyboard();
		cout << endl << "object side A is: " << obj_array[i].getSide(1) << endl;
		cout << "object side B is: " << obj_array[i].getSide(2) << endl;
		cout << "object side C is: " << obj_array[i].getSide(3) << endl;
		cout << "object Area is: " << obj_array[i].getArea() << endl;
		cout << " ******** " << endl << endl;

	}
}

void Part_2(right_triangle obj_array[], int arraysize)
{
	// intialize this to the value of the first entry in the array
	int minval_index=-1;
	double val, minval;	

	// scan all objects
	for(int i=0; i<arraysize; i++)		
	{
		// current area
		val=obj_array[i].getArea();	
		
		if( ( (minval_index==-1)||(val<minval) ) && (val>0) )
		{
			// the current object has the smallest noon-zero area
			minval=val;
			minval_index=i;
		}		
	}
	if(minval_index>=0)
	{
		cout << endl << "object position "<< minval_index << " has the smallest area:" << endl;
		cout << "object side A is: " << obj_array[minval_index].getSide(1) << endl;
		cout << "object side B is: " << obj_array[minval_index].getSide(2) << endl;
		cout << "object side C is: " << obj_array[minval_index].getSide(3) << endl;
		cout << "object Area is: " << obj_array[minval_index].getArea() << endl;
	}
	else
		cout << endl << " No object matched the search cirteria." << endl;

	cout << " ******** " << endl << endl;
}

void Part_4(double min_area, polygonColorOptions pcolr_target)
{
	double area;
	polygonColorOptions pcolr;
	const int arraysize=100;	
	int count=0;
	
	// these are N instantiations (objects) of the class rectangle
	// i.e. variables of the user-defined type "right_triangleWcolor" 
	right_triangleWcolor obj_array_1[arraysize];
	right_triangleWcolor obj_array_2[arraysize];
	
	// initialize random seed via srand() 
	// using the current time to set the seed
	srand(time(NULL));
	/////

	for(int i=0; i<arraysize; i++)
	{
		obj_array_1[i].inputRandomValues();
		obj_array_1[i].printInfo();
	}
	cout << endl << endl << "      ////////////  " << endl << endl;	
	for(int i=0; i<arraysize; i++)
	{
		area=obj_array_1[i].the_triangle.getArea();		
		pcolr=obj_array_1[i].the_color.getColor();
		if( (area>min_area) && (pcolr==pcolr_target)  ) 
		{
			obj_array_2[count]=obj_array_1[i];
			count++;
		}
	}

	cout << endl << " " << count << " objects out of " << arraysize << " matched the search criteria." << endl;
	
	for(int i=0; i<count; i++)
		obj_array_2[i].printInfo();

}

int main(int argc, char** argv) 
{
	// these are N instantiations (objects) of the class rectangle
	// i.e. variables of the user-defined type "rectangle" 
	const int arraysize=10;
	right_triangle obj_array[arraysize];
	
	// Part 1:
	// The content of "obj_array" can be changed by the following function; 
	// the content of "arraysize" will not. Why? (It has nothing to do with "arraysize" being "const".) 
	Part_1(obj_array, arraysize);

	// Part 2:
	// Part_2(obj_array, arraysize);


	// Part 3:
	right_triangleWcolor test_object;


	// Part 4:
	double min_area=30;
	polygonColorOptions pcolr_target=orange;
	// Part_4(min_area, pcolr_target);
	

	char final[10];
	cout << " Press any key then Enter to finish ";
	cin >> final;
	
	return 0;
}
