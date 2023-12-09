#ifndef PolygonWcolor_h
#define PolygonWcolor_h

#include "RectangleExample.h"
#include "RightTriangleExample.h"


class polygonColor{
public:
	// enumerator: finite set of choices for the colors 
	// blank and color_stop "bookend" the allowed colors	
	enum polygonColorOptions{blank=0, white, red, orange, yellow, green, 
	light_blue, dark_blue, purple, brown, black, color_stop};
private:
	polygonColorOptions color;
public:
	polygonColor(){color=blank;}
	// get
	polygonColorOptions getColor(){return color;}
	// set
	void setColor(polygonColorOptions inp_color)
	{
		// only set once
		if (color == blank)
		{
			// make sure input color is within the limits
			if ((inp_color > blank) && (inp_color < color_stop))
				color = inp_color;
		}
	}
	void inputColorFromKeyboard()
	{
		if(color==blank)
		{
			int inp_color;
			cout << "Please choose one of the following colors for the Rectangle (then hit ENTER)" << endl;
			cout << " white = " << white << ";" << endl;
			cout << " red = " << red << ";" << endl;
			cout << " orange = " << orange << ";" << endl;
			cout << " yellow = " << yellow << ";" << endl;
			cout << " green = " << green << ";" << endl;
			cout << " light_blue = " << light_blue << ";" << endl;
			cout << " dark_blue = " << dark_blue << ";" << endl;
			cout << " purple = " << purple << "." << endl;
			cout << " brown = " << brown << "." << endl;
			cout << " black = " << black << "." << endl;
			cin >> inp_color;
			setColor((polygonColorOptions)inp_color);
		}
		else
			cout << "Error in inputColorFromKeyboard(): Color is already initialized " << endl;
	}
	void inputRandomColor()
	{
		// this produces a random integer within [0 , RAND_MAX]
		unsigned int rand_value = rand();
		// this produces a random int within [1 , color_stop-1]
		int inp_color = (int)((((double)rand_value) / RAND_MAX) * (color_stop - 2) + 1);

		setColor((polygonColorOptions)inp_color);
	}
	//utility of class polygonColor
	
	void printColorInfo()
	{
		if (color != blank)
			cout << "Rectangle color is: " << colorToString(color) << "." << endl;
		else
			cout << "printInfo(): Color is not initialized " << endl;
	}

	/*void printColorInfo()
	{
		if(color!=blank)
		{
			cout << "Rectangle color is: ";
			switch(color){
			case white:
				cout << " white." << endl;
				break;
			case red:
				cout << " red." << endl;
				break;
			case orange:
				cout << " orange." << endl;
				break;
			case yellow:
				cout << " yellow." << endl;
				break;
			case green:
				cout << " green." << endl;
				break;
			case light_blue:
				cout << " light_blue." << endl;
				break;
			case dark_blue:
				cout << " dark_blue." << endl;
				break;
			case purple:
				cout << " purple." << endl;
				break;
			case brown:
				cout << " brown." << endl;
				break;
			case black:
				cout << " black." << endl;
				break;
			default:
				cout << "Error in printInfo(): Color num not recognized" << endl;
			}
		}
		else
			cout << "printInfo(): Color is not initialized " << endl;
	}*/	
	bool isInitialized()
	{
		if (color > blank && color < color_stop)
			return true;
		return false;
	}
	
	string colorToString(polygonColorOptions inp_color)
	{
		string result = "Color not Initialized";
		if (inp_color != blank)
		{
			switch (inp_color) {
			case white:
				result = "white";		break;
			case red:
				result = "red";			break;
			case orange:
				result = "orange";		break;
			case yellow:
				result = "yellow";		break;
			case green:
				result = "green";		break;
			case light_blue:
				result = "light_blue";	break;
			case dark_blue:
				result = "dark_blue";	break;
			case purple:
				result = "purple";		break;
			case brown:
				result = "brown";		break;
			case black:
				result = "black";		break;
			default:
				cout << "Color enum not recognized";
			}
		}
		return result;
	}
	// overloaded version with no argument
	string colorToString()
	{
		return colorToString(color);
	}
};

class rectangleWcolor{
public:
	rectangle the_rectangle;
	polygonColor the_color;	
public:	
	void inputFromKeyboard()
	{
		the_rectangle.inputSidesFromKeyboard();
		the_color.inputColorFromKeyboard();
	}	
	void printInfo()
	{
		if( (the_rectangle.isInitialized()) || (the_color.getColor()!= polygonColor::blank) )
		{
			cout << endl << " ----------- " << endl;
			the_rectangle.printRectangleInfo();
			the_color.printColorInfo();
			cout << " ----------- " << endl;
		}
		else
			cout << " printInfo(): Rectangle w Color not intialized" << endl;
	}
	void inputRandomValues(double max_val=100)
	{
		the_rectangle.inputRandomSides(max_val);
		the_color.inputRandomColor();
	}
	void inputRandomValues(polygonColor::polygonColorOptions inp_color, double max_val = 100)
	{
		the_rectangle.inputRandomSides(max_val);
		the_color.setColor(inp_color);
	}

	void inputValues(double in_sideA, double in_sideB, polygonColor::polygonColorOptions inp_color)
	{
		if (!the_rectangle.isInitialized())
			the_rectangle.inputSides(in_sideA, in_sideB);
		if (!the_color.isInitialized())
			the_color.setColor(inp_color);
	}
};



#endif
