#ifndef PetWcolor_h
#define PetWcolor_h
#include "PetExample.h"

class petColor{
public:
	// enumerator: finite set of choices for the colors 
	// blank and color_stop "bookend" the allowed colors
	enum petColorOptions{blank=0, white, orange, brown, black, color_stop};
private:
	petColorOptions color;
public:
	// constructor
	petColor(){color=blank;}
	//set
	bool setColor(petColorOptions inp_color)
	{
		bool result = false;
		// only set once
		if(color==blank)
		{
			// make sure input color is within the limits
			if ((inp_color > blank) && (inp_color < color_stop))
			{
				color = inp_color;
				result = true;
			}
		}
		return result;
	}
	bool inputColorFromKeyboard()
	{
		bool result = false;
		if (color == blank)
		{
			int inp_color;
			cout << "Please choose one of the following colors for the Pet (then hit ENTER)" << endl;
			cout << " white = " << white << ";" << endl;
			cout << " orange = " << orange << ";" << endl;
			cout << " brown = " << brown << "." << endl;
			cout << " black = " << black << "." << endl;
			cin >> inp_color;
			result = setColor((petColorOptions)inp_color);
		}
		else
			cout << "Error in inputColorFromKeyboard(): Color is already initialized " << endl;
		return result;
	}
	void inputRandomColor()
	{
		// this produces a random integer within [0 , RAND_MAX]
		unsigned int rand_value = rand();
		// this produces a random int within [1 , color_stop-1]
		int inp_color = (int)((((double)rand_value) / RAND_MAX) * (color_stop - 2) + 1);

		setColor((petColorOptions)inp_color);
	}
	void reset()
	{
		if(isInitialized())
			color = blank;
	}
	// get
	petColorOptions getColor(){return color;}
	// utilities
	bool isInitialized()
	{
		bool result = false;
		if (color > blank && color < color_stop)
			result = true;
		return result;
	}
	void printColorInfo()
	{
		if(color!=blank)
		{
			cout << "Pet color is: ";
			switch(color){
			case white:
				cout << " white." << endl;
				break;
			case orange:
				cout << " orange." << endl;
				break;			
			case brown:
				cout << " brown." << endl;
				break;
			case black:
				cout << " black." << endl;
				break;
			default:
				cout << "Error in printColorInfo(): Color num not recognized" << endl;
			}
		}
		else
			cout << "printColorInfo(): Color is not initialized " << endl;
	}		
};

class petWcolor{
public:
	pet the_pet;
	petColor the_color;	
public:	
	// set
	void inputFromKeyboard()
	{
		bool result = false;
		if ((!the_pet.isInitialized()) || (the_color.getColor() == petColor::blank))
		{
			if (the_pet.inputPetAndWeightFromKeyboard())
			{
				if (the_color.inputColorFromKeyboard())
					result = true;
				else
					reset();
			}			
		}
		else
			cout << " printInfo(): Pet w Color not intialized" << endl;
	}	
	bool inputValues(pet::petTypeOptions in_petType, double in_weight_kg, petColor::petColorOptions inp_color)
	{
		bool result = false;
		if (!the_pet.isInitialized())
			result = the_pet.inputPetAndWeight(in_petType, in_weight_kg);
		else
			cout << "Pet type and wight already initialized." << endl;
		if (!the_color.isInitialized())
			result &= the_color.setColor(inp_color);
		else
			cout << "Pet color already initialized." << endl;
		
		return result;
	}
	void inputRandomValues(double max_val = 10)
	{
		the_pet.inputRandomValues(max_val);
		the_color.inputRandomColor();
	}
	void reset()
	{
		the_pet.reset();
		the_color.reset();
	}
	//utilities
	void printInfo()
	{
		if( (the_pet.isInitialized()) || (the_color.getColor()!= petColor::blank) )
		{
			cout << endl << " ----------- " << endl;
			the_pet.printPetInfo();
			the_color.printColorInfo();
			cout << " ----------- " << endl;
		}
		else
			cout << " printInfo(): Pet w Color not intialized" << endl;
	}	
	bool isInitialized()
	{
		bool result = false;
		if(the_pet.isInitialized() && the_color.isInitialized())
			result = true;
		return result;
	}
};

#endif
