#ifndef RightTriangleExample_h
#define RightTriangleExample_h

#include "RectangleExample.h"

#include <math.h>

class right_triangle{
protected:
	// variables
	// use an object rectangle to hold information about A & B
	rectangle SideAandSideB;
	
	// Hypotenuse
	double sideC;
	
	double area;
	double perimeter;

	// functions
	void computeArea()
	{
		// the area of the right triangle is half that of the rectangle
		if(SideAandSideB.isInitialized())
			area=(SideAandSideB.getArea())/2;
	}
	void computePerimeter()
	{
		// the area of the right triangle is: A + B + C;
		//  A + B is half the perimeter of the rectangle;
		if(SideAandSideB.isInitialized())
			perimeter=( (SideAandSideB.getPerimeter())/2 ) + sideC;
	}
	void computeHypotenuse()
	{
		if(isInitialized())
		{
			// given A and B the value of C is imposed by the Pythagorean theorem
			double in_sideA=SideAandSideB.getSide(1);
			double in_sideB=SideAandSideB.getSide(2);
			sideC=sqrt( (in_sideA*in_sideA) + (in_sideB*in_sideB) );
		}
	}
public:	
	double getPerimeter() 	
	{
		if(SideAandSideB.isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Triangle is not initialized " << endl;
		return 0;		
	}
	double getArea() 	
	{
		if(SideAandSideB.isInitialized())
			return area;
		else
			cout << "Error in getArea(): Triangle is not initialized " << endl;
		return 0;		
	}
	bool isInitialized(){return SideAandSideB.isInitialized();}
	double getSide(int sidenum)
	{
		double out;
		if(isInitialized())
		{

			switch(sidenum){
			case 1:				
			case 2:
				out=SideAandSideB.getSide(sidenum);
				break;
			case 3:
				out=sideC;
				break;			
			default:
				cout << "Error in getSide(): Incorrect sidenum value" << endl;
				out=-1;
			}
		}
		else
		{
			cout << "Error in getSide(): Triangle is not initialized" << endl;
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
				// set A and B (this initializes the rectangle)
				SideAandSideB.inputSides(in_sideA,in_sideB);
				
				// set C
				computeHypotenuse();
				
				// now the triangle is initializd; compute area and perimeter
				computeArea();
				computePerimeter();					
			}
			else
				cout << "Error in inputSides(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputSides(): Triangle is already initialized " << endl;

	}
	void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;

			cout << "Please enter dimension of side A of the Triangle (then hit ENTER)" << endl;
			cin >> in_sideA;

			cout << "Please enter dimension of side B of the Triangle (then hit ENTER)" << endl;
			cin >> in_sideB;

			// use these vlaues to set A, B and C; 
			// this initializes the rectangle, hence the triangle
			inputSides(in_sideA, in_sideB);
			
			if(isInitialized())
				cout << " Dimension of side C of the Triangle is: " << sideC << endl;
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Triangle is already initialized " << endl;
	}
	//
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
			cout << "Error in inputRandomSides(): Triangle is already initialized " << endl;
	}
	void printTriangleInfo()
	{
		if(isInitialized())
		{
			cout << "Rectangle side A is: " << getSide(1) << endl;
			cout << "Rectangle side B is: " << getSide(2) << endl;
			cout << "Rectangle side C is: " << getSide(3) << endl;
			cout << "Rectangle area is: " << getArea() << endl;	
			cout << "Rectangle perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << "printTriangleInfo(): Rectangle dimensions not initialized " << endl;
	}
	void reset(){SideAandSideB.reset();}
};





#endif
