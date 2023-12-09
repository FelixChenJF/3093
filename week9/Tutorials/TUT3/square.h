#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon_w_color.h"

class square{
protected:
	// variables
	rectangle rect_eq_side;

public:
	// constructor // nothing needed here
	square(){;}	
	// gets	
	double getArea(){return rect_eq_side.getArea();}
	double getPerimeter(){return rect_eq_side.getPerimeter();}		
	bool isInitialized(){return rect_eq_side.isInitialized();}
	double getSide(){return rect_eq_side.getSide(1);}	
	void inputSide(double in_side){rect_eq_side.inputSides(in_side,in_side);}
	void inputSideFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_side;
			cout << "Please enter dimension of side of the Square (then hit ENTER)" << endl;
			cin >> in_side;
			rect_eq_side.inputSides(in_side, in_side);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Square is already initialized " << endl;
	}
	void printSquareInfo()
	{
		if(isInitialized())
		{
			cout << "Square side is: " << rect_eq_side.getSide(1) << endl;
			cout << "Square area is: " << rect_eq_side.getArea() << endl;	
			cout << "Square perimeter is: " << rect_eq_side.getPerimeter() << endl;
		}
		else
			cout << "printSquareInfo(): Square dimensions not initialized " << endl;
	}
	void inputRandomSide(double max_val=100)
	{
		if(!isInitialized())
		{
			rect_eq_side.inputRandomSides(max_val);
			double in_side=rect_eq_side.getSide(1);
			reset();
            inputSide(in_side);
		}
		else
			cout << "Error in inputRandomSide(): Square is already initialized " << endl;
	}
	void reset(){rect_eq_side.reset();}
};


//// ----------------------------------------------------
class squareWcolor{
public:
	square the_square;
	polygonColor the_color;	
public:	
	void inputFromKeyboard()
	{
		the_square.inputSideFromKeyboard();
		the_color.inputColorFromKeyboard();
	}	
	void printInfo()
	{
		if( (the_square.isInitialized()) || (the_color.getColor()!=blank) )
		{
			cout << endl << " ----------- " << endl;
			the_square.printSquareInfo();
			the_color.printColorInfo();
			cout << " ----------- " << endl;
		}
		else
			cout << " printInfo(): Square w Color not intialized" << endl;
	}
	void inputRandomValues(double max_val=100)
	{
		the_square.inputRandomSide(max_val);
		the_color.inputRandomColor();
	}	
    void reset()
	{
		the_square.reset();
		the_color.reset();
	}
};
//// ----------------------------------------------------


#endif
