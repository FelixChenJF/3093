#pragma once

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>     

////// class square
class rectangle {
protected:
	// variables
	double sideA, sideB;
	double area;
	double perimeter;
	// initialization flag
	bool init_flag;
	// functions
	void computeArea()
	{
		if (isInitialized())
			area = sideA * sideB;
	}
	void computePerimeter()
	{
		if (isInitialized())
			perimeter = 2 * (sideA + sideB);
	}
public:
	// constructor
	rectangle()
	{
		// basic initialization
		init_flag = false;
	}
	// destructor
	~rectangle()
	{
		//update counters:
		reset();
	}
	// gets	
	double getArea()
	{
		if (isInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;
	}
	double getPerimeter()
	{
		if (isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;
	}
	bool isInitialized() { return init_flag; }
	double getSide(int sidenum)
	{
		double out;
		if (isInitialized())
		{
			switch (sidenum) {
			case 1:
				out = sideA;
				break;
			case 2:
				out = sideB;
				break;
			default:
				cout << "Error in getSide(): Incorrect sidenum value" << endl;
				out = -1;
			}
		}
		else
		{
			cout << "Error in getSide(): Rectangle is not initialized" << endl;
			out = -1;
		}
		return out;
	}
	void inputSides(double in_sideA, double in_sideB)
	{
		if (!isInitialized())
		{
			if (in_sideA > 0 && in_sideB > 0)
			{
				sideA = in_sideA;
				sideB = in_sideB;
				init_flag = true;
				computeArea();
				computePerimeter();
			}
			else
				cout << "Error in inputSides(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputSides(): Rectangle is already initialized " << endl;
	}
	void inputSidesFromKeyboard()
	{
		if (!isInitialized())
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
		if (isInitialized())
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
	void inputRandomSides(double max_val = 100)
	{
		if (!isInitialized())
		{
			double in_sideA, in_sideB;
			int rand_valueA = 0;
			int rand_valueB = 0;

			// check that max_val is a meaningful value
			if (max_val <= 0)
				max_val = 100;

			// this produces a random integer within (0 , RAND_MAX]
			while (rand_valueA == 0)
				rand_valueA = rand();
			while (rand_valueB == 0)
				rand_valueB = rand();
			// this produces a random double within (0 , max_val]
			in_sideA = (((double)rand_valueA) / (RAND_MAX)) * max_val;
			in_sideB = (((double)rand_valueB) / (RAND_MAX)) * max_val;
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
		}
	}
};
class square {
protected:
	// variables
	rectangle rect_eq_side;
	double Cx, Cy;
	// initialization flag
	bool coord_init_flag;
public:
	// constructor // nothing needed here
	square() { coord_init_flag = false; }
	~square() { reset(); }
	// gets	
	double getArea() { return rect_eq_side.getArea(); }
	double getPerimeter() { return rect_eq_side.getPerimeter(); }
	double getSide() { return rect_eq_side.getSide(1); }
	bool getCoord(double& out_Cx, double& out_Cy)
	{
		bool out = false;
		if (isCoordInitialized())
		{
			out_Cx = Cx;
			out_Cy = Cy;
			out = true;
		}
		else
			cout << "Error in getCoord(): Square coord not initialized" << endl;
		return out;
	}
	// input
	void inputSide(double in_side) { rect_eq_side.inputSides(in_side, in_side); }
	void inputSideFromKeyboard()
	{
		if (!isShapeInitialized())
		{
			double in_side;
			cout << "Please enter dimension of side of the Square (then hit ENTER)" << endl;
			cin >> in_side;
			rect_eq_side.inputSides(in_side, in_side);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Square is already initialized " << endl;
	}
	void inputRandomSide(double max_val = 100)
	{
		if (!isShapeInitialized())
		{
			rect_eq_side.inputRandomSides(max_val);
			double in_side = rect_eq_side.getSide(1);
			reset();
			inputSide(in_side);
		}
		else
			cout << "Error in inputRandomSide(): Square is already initialized " << endl;
	}
	bool inputCoord(double in_Cx, double in_Cy)
	{
		if (!isCoordInitialized())
		{
			Cx = in_Cx;
			Cy = in_Cy;
			coord_init_flag = true;
			return true;
		}
		else
			cout << "Error in inputCoord(): Center is already initialized " << endl;
		return false;
	}
	bool inputCoordFromKeyboard()
	{
		if (!isCoordInitialized())
		{
			double in_Cx, in_Cy;
			cout << "Please enter X coordinate of square center (then hit ENTER)" << endl;
			cin >> in_Cx;
			cout << "Please enter Y coordinate of square center (then hit ENTER)" << endl;
			cin >> in_Cy;
			return inputCoord(in_Cx, in_Cy);
		}
		else
			cout << "Error in inputSideFromKeyboard(): square is already initialized " << endl;
		return false;
	}
	// generate random coords within [-max_val, max_val]
	bool inputRandomCoord(double max_val = 25)
	{
		if (!isCoordInitialized())
		{
			double in_sideA, in_sideB;
			int rand_valueA, rand_valueB;
			// check that max_val is a meaningful value
			if (max_val <= 0)
				max_val = 100;
			// this produces a random integer within [0 , RAND_MAX]
			rand_valueA = rand();
			rand_valueB = rand();
			// this produces a random double within [0 , max_val]
			in_sideA = (((double)rand_valueA) / (RAND_MAX)) * max_val;
			in_sideB = (((double)rand_valueB) / (RAND_MAX)) * max_val;
			// randomly flip the sign
			if (rand() % 2)
				in_sideA *= (-1);
			if (rand() % 2)
				in_sideB *= (-1);
			return inputCoord(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputRandomSides(): Square is already initialized " << endl;
		return false;
	}
	//checks
	bool isShapeInitialized() { return rect_eq_side.isInitialized(); }
	bool isCoordInitialized() { return coord_init_flag; }
	// extra
	void printSquareInfo()
	{
		if (isShapeInitialized())
		{
			cout << "Square side is: " << rect_eq_side.getSide(1) << endl;
			cout << "Square area is: " << rect_eq_side.getArea() << endl;
			cout << "Square perimeter is: " << rect_eq_side.getPerimeter() << endl;
		}
		else
			cout << "printSquareInfo(): Square dimensions not initialized " << endl;
	}
	void printShapeAndCoordInfo()
	{
		cout << "Square summary: " << endl;
		if (isShapeInitialized())
		{
			cout << " Side is: " << getSide() << endl;
			cout << " Area is: " << getArea() << endl;
			cout << " Perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << " Square dimensions not initialized " << endl;
		if (isCoordInitialized())
		{
			cout << " Center X coordinate is: " << Cx << endl;
			cout << " Center Y coordinate is: " << Cy << endl;
		}
		else
			cout << " Square center not initialized " << endl;
		cout << endl;
	}
	void resetShape()
	{
		if (isShapeInitialized())
			rect_eq_side.reset();
	}
	void resetCoord()
	{
		if (isCoordInitialized())
			coord_init_flag = false;
	}
	void reset() { resetShape(); resetCoord(); }
};
/////

// part 2: start
// square
void fillSquareArray(square in_array[], int tot_items)
{
	for (int i = 0; i < tot_items; i++)
	{
		in_array[i].inputRandomCoord();
		//in_array[i].inputRandomSide();
		in_array[i].inputSide(1.0 + 2*i);
	}
}
void printSquareArray(square in_array[], int tot_items)
{
	for (int i = 0; i < tot_items; i++)
	{
		cout << "Item i = " << i << " :" << endl;
		in_array[i].printShapeAndCoordInfo();
		cout << endl << endl;
	}
}
struct coordpoint
{
	double x, y;
};
struct cornerpoints
{
	coordpoint TopLeft, TopRight, BottomLeft, BottomRight;
};

bool verifySquareMatch(int ruleindex, cornerpoints targ, cornerpoints curr, coordpoint targ_C, coordpoint curr_C)
{
	// rule 0: Center of current_item is inside Target // V
	// rule 1: Center of Target is inside current_item // V
	// rule 2: Target is entirely inside current_item // V
	// rule 3: current_item is entirely inside Target // V
	// rule 4: current_item and Target overlap (one partly [or entirely] inside the other)

	bool match_found = false;
	// rule 0: Center of current_item is inside Target
	bool curr_Cy__below__targTop_y = false;
	bool curr_Cy__above__targBottom_y = false;
	bool curr_Cx__left__targRight_x = false;
	bool curr_Cx__right__targLeft_x = false;

	// rule 1: Center of Target is inside current_item
	bool targ_Cy__below__currTop_y = false;
	bool targ_Cy__above__currBottom_y = false;
	bool targ_Cx__left__currRight_x = false;
	bool targ_Cx__right__currLeft_x = false;

	// rule 2: Target is entirely inside current_item // 
	bool targTop_y__below__currTop_y = false;
	bool targBottom_y__above__currBottom_y = false;
	bool targRight_x__left__currRight_x = false;
	bool targLeft_x__right__currLeft_x = false;

	// rule 3: current_item is entirely inside Target // 
	bool currTop_y__below__targTop_y = false;
	bool currBottom_y__above__targBottom_y = false;
	bool currRight_x__left__targRight_x = false;
	bool currLeft_x__right__targLeft_x = false;

	// rule 4: current_item and Target overlap (one partly [or entirely] inside the other)
	// check if any corner of Target is inside current_item; or 
	// check if any corner of current_item is inside Target; or	
	
	//
	switch (ruleindex) {
	case 0:	// rule 0: Center of current_item is inside Target
		if(curr_C.y <= targ.TopLeft.y)
			curr_Cy__below__targTop_y = true;
		if (curr_C.y >= targ.BottomLeft.y)
			curr_Cy__above__targBottom_y = true;
		if(curr_C.x <= targ.TopRight.x)
			curr_Cx__left__targRight_x = true;
		if (curr_C.x >= targ.TopLeft.x)
			curr_Cx__right__targLeft_x = true;
		if (curr_Cy__below__targTop_y && curr_Cy__above__targBottom_y && curr_Cx__left__targRight_x && curr_Cx__right__targLeft_x)
			match_found = true;
		break;
	case 1:	// rule 1: Center of Target is inside current_item
		if (targ_C.y <= curr.TopLeft.y)
			targ_Cy__below__currTop_y = true;
		if (targ_C.y >= curr.BottomLeft.y)
			targ_Cy__above__currBottom_y = true;
		if (targ_C.x <= curr.TopRight.x)
			targ_Cx__left__currRight_x = true;
		if (targ_C.x >= curr.TopLeft.x)
			targ_Cx__right__currLeft_x = true;
		if (targ_Cy__below__currTop_y && targ_Cy__above__currBottom_y && targ_Cx__left__currRight_x && targ_Cx__right__currLeft_x)
			match_found = true;
		break;
	case 2:	// rule 2: Target is entirely inside current_item
		if (targ.TopLeft.y <= curr.TopLeft.y)
			targTop_y__below__currTop_y = true;
		if (targ.BottomLeft.y >= curr.BottomLeft.y)
			targBottom_y__above__currBottom_y = true;
		if (targ.TopRight.x <= curr.TopRight.x)
			targRight_x__left__currRight_x = true;
		if (targ.TopLeft.x >= curr.TopLeft.x)
			targLeft_x__right__currLeft_x = true;
		if (targTop_y__below__currTop_y && targBottom_y__above__currBottom_y && targRight_x__left__currRight_x && targLeft_x__right__currLeft_x)
			match_found = true;
		break;
	case 3:	//rule 3 : current_item is entirely inside Target
		if (curr.TopLeft.y <= targ.TopLeft.y)
			currTop_y__below__targTop_y = true;
		if (curr.BottomLeft.y >= targ.BottomLeft.y)
			currBottom_y__above__targBottom_y = true;
		if (curr.TopRight.x <= targ.TopRight.x)
			currRight_x__left__targRight_x = true;
		if (curr.TopLeft.x >= targ.TopLeft.x)
			currLeft_x__right__targLeft_x = true;
		if (currTop_y__below__targTop_y && currBottom_y__above__targBottom_y && currRight_x__left__targRight_x && currLeft_x__right__targLeft_x)
			match_found = true;
		break;
	case 4: // rule 4: current_item and Target overlap (one partly or entirely inside the other)
		// Target TL, BL, TR, BR, inside Current:  
		if( (targ.TopLeft.y <= curr.TopLeft.y) && (targ.TopLeft.y >= curr.BottomLeft.y) && (targ.TopLeft.x >= curr.TopLeft.x) && (targ.TopLeft.x <= curr.TopRight.x) )
		{
			match_found = true; 
			break;
		}
		if((targ.BottomLeft.y >= curr.BottomLeft.y) && (targ.BottomLeft.y <= curr.TopLeft.y) && (targ.BottomLeft.x >= curr.BottomLeft.x) && (targ.BottomLeft.x <= curr.BottomRight.x))
		{
			match_found = true;
			break;
		}
		if ((targ.TopRight.y <= curr.TopRight.y) && (targ.TopRight.y >= curr.BottomRight.y) && (targ.TopRight.x >= curr.TopLeft.x) && (targ.TopRight.x <= curr.TopRight.x))
		{
			match_found = true;
			break;
		}
		if ((targ.BottomRight.y >= curr.BottomRight.y) && (targ.BottomRight.y <= curr.TopRight.y) && (targ.BottomRight.x >= curr.BottomLeft.x) && (targ.BottomRight.x <= curr.BottomRight.x))
		{
			match_found = true;
			break;
		}
		
		// Current TL, BL, TR, BR, inside Target: 
		if ((curr.TopLeft.y <= targ.TopLeft.y) && (curr.TopLeft.y >= targ.BottomLeft.y) && (curr.TopLeft.x >= targ.TopLeft.x) && (curr.TopLeft.x <= targ.TopRight.x))
		{
			match_found = true;
			break;
		}
		if ((curr.BottomLeft.y >= targ.BottomLeft.y) && (curr.BottomLeft.y <= targ.TopLeft.y) && (curr.BottomLeft.x >= targ.BottomLeft.x) && (curr.BottomLeft.x <= targ.BottomRight.x))
		{
			match_found = true;
			break;
		}
		if ((curr.TopRight.y <= targ.TopRight.y) && (curr.TopRight.y >= targ.BottomRight.y) && (curr.TopRight.x >= targ.TopLeft.x) && (curr.TopRight.x <= targ.TopRight.x))
		{
			match_found = true;
			break;
		}
		if ((curr.BottomRight.y >= targ.BottomRight.y) && (curr.BottomRight.y <= targ.TopRight.y) && (curr.BottomRight.x >= targ.BottomLeft.x) && (curr.BottomRight.x <= targ.BottomRight.x))
		{
			match_found = true;
			break;
		}
		break;
	default:
		cout << "Rule index not supported" << endl;
	}
	return match_found;
}
int findMatchingSquares(square target, square in_array[], square out_array[], int tot_items, int ruleindex)
{
	bool match_found = false;
	int tot_matches = 0;
	double targ_Cx, targ_Cy, targ_side;
	double curr_Cx, curr_Cy, curr_side;
	//coordinates of corner points: TopLeft, TopRight, BottomLeft, BottomRight
	cornerpoints targ, curr;
	coordpoint targ_C, curr_C;
	// check the target is fully initialized; otherwise abort
	if (!target.getCoord(targ_Cx, targ_Cy))
	{
		cout << "Target coordinates not set: abort" << endl;
		return 0;
	}
	targ_side = target.getSide();
	if (targ_side <= 0)
	{
		cout << "Target side not set: abort" << endl;
		return 0;
	}
	targ.BottomLeft.x =targ.TopLeft.x = targ_Cx - (targ_side/2);
	targ.BottomRight.x = targ.TopRight.x = targ_Cx + (targ_side / 2);
	targ.TopLeft.y = targ_Cy + (targ_side / 2); targ.TopRight.y = targ.TopLeft.y;
	targ.BottomLeft.y = targ_Cy - (targ_side / 2); targ.BottomRight.y = targ.BottomLeft.y;
	targ_C.x = targ_Cx; targ_C.y = targ_Cy;
	for (int i = 0; i < tot_items; i++)
	{
		// printout to cross check
		cout << " Target" << endl;
		target.printShapeAndCoordInfo();
		//
		cout << "Checking Item i = " << i << " :" << endl;
		// check the item is fully initialized; otherwise skip to next iteration
		if (!in_array[i].getCoord(curr_Cx, curr_Cy))
		{
			cout << "Item coordinates not set: skip" << endl;	continue;
		}
		curr_side = in_array[i].getSide();
		if (curr_side <= 0)
		{
			cout << "Item side not set: skip" << endl; continue;
		}
		//// printout to cross check
		cout << endl << " Current " << endl;
		in_array[i].printShapeAndCoordInfo();
		cout << "  ---- " << endl << endl;
		//
		// check match
		curr.BottomLeft.x = curr.TopLeft.x = curr_Cx - (curr_side / 2);
		curr.BottomRight.x = curr.TopRight.x = curr_Cx + (curr_side / 2);
		curr.TopLeft.y = curr_Cy + (curr_side / 2); curr.TopRight.y = curr.TopLeft.y;
		curr.BottomLeft.y = curr_Cy - (curr_side / 2); curr.BottomRight.y = curr.BottomLeft.y;
		curr_C.x = curr_Cx; curr_C.y = curr_Cy;
		match_found = verifySquareMatch(ruleindex, targ, curr, targ_C, curr_C);
		// set the correponding item of out_array[]
		if (match_found)
		{
			cout << " --- vvv --- Match found: set output Item j = " << tot_matches << endl << endl;
			//out_array[tot_matches].resetCoord();
			out_array[tot_matches].inputCoord(curr_Cx, curr_Cy);
			//out_array[tot_matches].resetShape();
			out_array[tot_matches].inputSide(curr_side);
			tot_matches++;
		}
		else
			cout << " --- xxx --- Match not found." << endl << endl;
		cout << endl;
	}

	cout << "Search complete; total match(es) found: " << tot_matches << endl << endl;
	return tot_matches;
}

// part 2: stop