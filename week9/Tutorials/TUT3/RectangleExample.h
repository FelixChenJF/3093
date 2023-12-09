#ifndef RectangleExample_h
#define RectangleExample_h

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>     

class rectangle{
protected:
	// static member variable used for count

	// one for all rectangles ever "created"
	static int rectangle_instances_created_count;

	// one for rectangles currently "alive"
	static int rectangle_instances_alive_count;

	// one for rectangles alive and set with valid sides
	static int rectangle_initialized_instances_count;

	// Unique ID
	int rectangle_ID;

	// variables
	double sideA, sideB;
	double area;
	double perimeter;

	// initialization flag
	bool init_flag;

	// functions
	void computeArea()
	{
		if(isInitialized())
			area=sideA*sideB;
	}
	void computePerimeter()
	{
		if(isInitialized())
			perimeter=2*(sideA+sideB);
	}

public:
	// constructor
	rectangle()
	{
		// basic initialization
		init_flag=false;
		rectangle_ID = rectangle_instances_created_count;
		//update counters:
		rectangle_instances_alive_count++;
		rectangle_instances_created_count++;
	}
	// destructor
	~rectangle()
	{
		//update counters:
		reset(); 
		rectangle_instances_alive_count--;	
	}

	// gets	
	double getArea() 
	{
		if(isInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;		
	}
	double getPerimeter() 	
	{
		if(isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;		
	}
	bool isInitialized(){return init_flag;}
	double getSide(int sidenum)
	{
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
		}
		else
		{
			cout << "Error in getSide(): Rectangle is not initialized" << endl;
			out=-1;
		}
		return out;
	}
	void inputSides(double in_sideA, double in_sideB)
	{
		if(!isInitialized())
		{
			if(in_sideA>0 && in_sideB>0)
			{
				sideA=in_sideA;
				sideB=in_sideB;
				init_flag=true;
				computeArea();
				computePerimeter();
				// update counters
				rectangle_initialized_instances_count++;
			}
			else
				cout << "Error in inputSides(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputSides(): Rectangle is already initialized " << endl;

	}
	void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;

			cout << "Please enter dimension of side A of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideA;

			cout << "Please enter dimension of side B of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideB;

			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Rectangle is already initialized " << endl;
	}
	void printRectangleInfo()
	{
		cout << "Rectangle summary: " << endl;
		cout << " ID is: " << getRectangleID() << endl;
		if(isInitialized())
		{
			cout << " Side A is: " << getSide(1) << endl;
			cout << " Side B is: " << getSide(2) << endl;
			cout << " Area is: " << getArea() << endl;	
			cout << " Perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << " Rectangle dimensions not initialized " << endl;
		cout << endl;
	}
	void inputRandomSides(double max_val=100)
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;
			int rand_valueA=0;
			int rand_valueB=0;
			
			// check that max_val is a meaningful value
			if(max_val<=0)
				max_val=100;

			// this produces a random integer within (0 , RAND_MAX]
			while(rand_valueA==0)
				rand_valueA=rand();
			while(rand_valueB==0)
				rand_valueB=rand();
			// this produces a random double within (0 , max_val]
			in_sideA=( ((double)rand_valueA)/(RAND_MAX) )*max_val;
			in_sideB=( ((double)rand_valueB)/(RAND_MAX) )*max_val;
			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputRandomSides(): Rectangle is already initialized " << endl;
	}
	void reset()
	{
		if (init_flag)
		{
			// de-initialization
			init_flag = false;
			rectangle_initialized_instances_count--;
		}		
	}
	int getRectangleID() { return rectangle_ID; }
	static void printRectangleCount()
	{
		cout << "Status of the Rectangle counters:"<<endl;
		cout << " Number of Rectangles ever created: " << rectangle_instances_created_count << endl;
		cout << " Number of Rectangles currently active: " << rectangle_instances_alive_count << endl;
		cout << " Number of Rectangles currently set (valid geometry): " << rectangle_initialized_instances_count << endl;
	}
};

// Define static member variables so that the compile can Allocate memory space.
// Done only once, after (outside) class definition
// At the same time, you can set the initializetion value
int rectangle::rectangle_instances_created_count=0;
int rectangle::rectangle_instances_alive_count=0;
int rectangle::rectangle_initialized_instances_count=0;



#endif
