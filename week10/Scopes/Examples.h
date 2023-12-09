#pragma once

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h> 

// correct, but uses the globas scope; 
// as a result the identifiers (words): "color" "green", "blue", "violet", "pink", "white", "black", 
// (and relative enumerator values) cannot be used with different meaning (or numerical value) 
// enywhere else 
//enum color { green, blue, violet, pink, white, black};


// Instead you can place these in a class like so:
class property {
public:
	// All colors supported for this exercise
	enum color { color_start, red, green, blue, violet, white, black, color_stop };
	// All materials supported for this exercise
	enum material { mat_start, wood, steel, paper, wax, plastic, copper, mat_stop };
	// helper function to obtain a string with the name correponding to the enumerator
	static string colorEnum2name(color color_enum)
	{
		string result;
		switch (color_enum) {
		case red:
			result = "red";
			break;
		case green:
			result = "green";
			break;
		case blue:
			result = "blue";
			break;
		case violet:
			result = "violet";
			break;
		case white:
			result = "white";
			break;
		case black:
			result = "black";
			break;
		default:
			result = "No match";
			cout << "Error in colorEnum2name(): no color match found" << endl;
		}
		return result;
	}
	// helper function to obtain a string with the name correponding to the enumerator
	static string materialEnum2name(material material_enum)
	{
		string result;
		switch (material_enum) {
		case wood:
			result = "wood";
			break;
		case steel:
			result = "steel";
			break;
		case paper:
			result = "paper";
			break;
		case wax:
			result = "wax";
			break;
		case plastic:
			result = "plastic";
			break;
		case copper:
			result = "copper";
			break;
		default:
			result = "No match";
			cout << "Error in materialEnum2name(): no material match found" << endl;
		}
		return result;
	}
};

// you can also have a different use of the same keywords elsewhere, like so.

class rainbow {
public:
	// All colors supported for this exercise
	enum color { red, orange, yellow, green, blue, indigo, violet };	
};

