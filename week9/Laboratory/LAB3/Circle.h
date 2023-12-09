#ifndef Circle_h
#define Circle_h

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>     
static const double pi_val = 3.1415926;

class circle{
protected:
	// variables
	double radius, area, perimeter, Cx, Cy;
	// initialization flag
	bool shape_init_flag, coord_init_flag;
	// functions
	void computeArea()
	{
		if(isShapeInitialized())
			area= radius * radius * pi_val;
	}
	void computePerimeter()
	{
		if(isShapeInitialized())
			perimeter=2* radius * pi_val;
	}
	void basicInit()
	{
		// basic initialization
		shape_init_flag = false;
		coord_init_flag = false;
	}
	
public:
	// constructor
	circle() {basicInit();}
	~circle()
	{
		//update counters:
		reset(); 
		//rectangle_instances_alive_count--;		
	}
	// gets	
	double getArea() 
	{
		if(isShapeInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;		
	}
	double getPerimeter() 	
	{
		if(isShapeInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;		
	}	
	double getSide()
	{
		double out;
		if (isShapeInitialized())
			out = radius;		
		else
		{
			cout << "Error in getSide(): Circe is not initialized" << endl;
			out=0;
		}
		return out;
	}
	// if shape coordinates are initialized: return true and set:
	// out_Cx = Center X coordinate; out_Cy = Center Y coordinate.
	// Return false otherwise.
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
			cout << "Error in getCoord(): Circe coord not initialized" << endl;
		return out;
	}
	// checks
	bool isShapeInitialized() { return shape_init_flag; }
	bool isCoordInitialized() { return coord_init_flag; }
	// set
	bool inputSide(double in_radius)
	{
		bool result = false;
		if(!isShapeInitialized())
		{
			if(in_radius>0)
			{
				radius = in_radius;
				shape_init_flag=true;
				computeArea();
				computePerimeter();
				result = true;
			}
			else
				cout << "Error in inputSide(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputSide(): Rectangle is already initialized " << endl;
		return result;
	}
	// ask for user input 
	bool inputSideFromKeyboard()
	{
		if(!isShapeInitialized())
		{
			double in_side;
			cout << "Please enter dimension of radius of circle (then hit ENTER)" << endl;
			cin >> in_side;
			return inputSide(in_side);
		}
		else
			cout << "Error in inputSideFromKeyboard(): Circle is already initialized " << endl;
		return false;
	}
	// generate random side within (0, max_val]
	bool inputRandomSide(double max_val = 10)
	{
		if (!isShapeInitialized())
		{
			double in_sideA, in_sideB;
			int rand_valueA = 0;

			// check that max_val is a meaningful value
			if (max_val <= 0)
				max_val = 100;

			// this produces a random integer within (0 , RAND_MAX]
			while (rand_valueA == 0)
				rand_valueA = rand();
			// this produces a random double within (0 , max_val]
			in_sideA = (((double)rand_valueA) / (RAND_MAX)) * max_val;
			return inputSide(in_sideA);
		}
		else
			cout << "Error in inputRandomSides(): Circle is already initialized " << endl;
		return false;
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
			cout << "Please enter X coordinate of circle center (then hit ENTER)" << endl;
			cin >> in_Cx;
			cout << "Please enter Y coordinate of circle center (then hit ENTER)" << endl;
			cin >> in_Cy;
			return inputCoord(in_Cx, in_Cy);
		}
		else
			cout << "Error in inputSideFromKeyboard(): Circle is already initialized " << endl;
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
			cout << "Error in inputRandomSides(): Circle is already initialized " << endl;
		return false;
	}
	void resetShape()
	{
		if (isShapeInitialized())
			shape_init_flag = false;
	}
	void resetCoord()
	{
		if (isCoordInitialized())
			coord_init_flag = false;
	}
	void reset()
	{
		resetShape();
		resetCoord();
	}
	// Print shape info (side and center coordinates) to screen
	void printShapeAndCoordInfo()
	{
		cout << "Circle summary: " << endl;
		if(isShapeInitialized())
		{
			cout << " Radius is: " << getSide() << endl;
			cout << " Area is: " << getArea() << endl;	
			cout << " Perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << " Circle dimensions not initialized " << endl;
		if (isCoordInitialized())
		{
			cout << " Center X coordinate is: " << Cx << endl;
			cout << " Center Y coordinate is: " << Cy << endl;
		}
		else
			cout << " Circle center not initialized " << endl;
		cout << endl;
	}
};

/// Part 2 : start
// circle
void fillCircleArray(circle in_array[], int tot_items)
{
	for (int i = 0; i < tot_items; i++)
	{
		in_array[i].inputRandomCoord();
		in_array[i].inputRandomSide();
	}
}

void printCircleArray(circle in_array[], int tot_items)
{
	for (int i = 0; i < tot_items; i++)
	{
		cout << "Item i = " << i << " :" << endl;
		in_array[i].printShapeAndCoordInfo();
		cout << endl << endl;
	}
}

bool verifyCircleMatch(int ruleindex, double distance_targ_to_curr, double curr_radius, double targ_radius)
{
	// rule 0: Center of current_item is inside Target // V
	// rule 1: Center of Target is inside current_item // V
	// rule 2: Target is entirely inside current_item // V
	// rule 3: current_item is entirely inside Target // V
	// rule 4: current_item and Target overlap (one partly or entirely inside the other)

	bool match_found=false;
	switch (ruleindex) {
	case 0:	// rule 0: Center of current_item is inside Target
		if (distance_targ_to_curr <= (targ_radius))
			match_found = true;
		break;
	case 1:	// rule 1: Center of Target is inside current_item
		if (distance_targ_to_curr <= (curr_radius))
			match_found = true;
		break;
	case 2:	// rule 2: Target is entirely inside current_item
		if ((distance_targ_to_curr + targ_radius) <= (curr_radius))
			match_found = true;
		break;
	case 3:	//rule 3 : current_item is entirely inside Target
		if ((distance_targ_to_curr + curr_radius) <= (targ_radius))
			match_found = true;
		break;
	case 4: // rule 4: current_item and Target overlap (one partly or entirely inside the other)
		if (distance_targ_to_curr <= (curr_radius + targ_radius))
			match_found = true; 
		break;
	default:
		cout << "Rule index not supported" << endl;
	}
	return match_found;
}

int findMatchingCircles(circle target, circle in_array[], circle out_array[], int tot_items, int ruleindex)
{
	bool match_found = false;
	int tot_matches=0;
	double targ_Cx, targ_Cy, targ_radius;
	double curr_Cx, curr_Cy, curr_radius;
	double distance_targ_Cx_to_curr_Cx, distance_targ_Cy_to_curr_Cy, distance_targ_to_curr;
	// check the target is fully initialized; otherwise abort
	if (!target.getCoord(targ_Cx, targ_Cy))
	{
		cout << "Target coordinates not set: abort" << endl;
		return 0;
	}
	targ_radius = target.getSide();
	if (targ_radius <= 0)
	{
		cout << "Target side not set: abort" << endl;
		return 0;
	}
	for (int i = 0; i < tot_items; i++)
	{
		cout << "Checking Item i = " << i << " :" << endl;		
		// check the item is fully initialized; otherwise skip to next iteration
		if (!in_array[i].getCoord(curr_Cx, curr_Cy))
		{ cout << "Item coordinates not set: skip" << endl;	continue; }
		curr_radius = in_array[i].getSide();
		if (curr_radius <= 0)
		{ cout << "Item side not set: skip" << endl; continue; }
		// printout to cross check
		cout << " Target" << endl;
		target.printShapeAndCoordInfo();
		cout << endl<< " Current " << endl;
		in_array[i].printShapeAndCoordInfo();
		cout << "  ---- " << endl << endl;
		//
		// check match		
		distance_targ_Cx_to_curr_Cx = targ_Cx - curr_Cx;
		distance_targ_Cy_to_curr_Cy = targ_Cy - curr_Cy;
		distance_targ_to_curr =  sqrt( (distance_targ_Cx_to_curr_Cx*distance_targ_Cx_to_curr_Cx) + (distance_targ_Cy_to_curr_Cy*distance_targ_Cy_to_curr_Cy) );
		match_found = verifyCircleMatch(ruleindex, distance_targ_to_curr, curr_radius, targ_radius);
		// set the correponding item of out_array[]
		if(match_found)
		{
			cout << " --- vvv --- Match found: set output Item j = " << tot_matches << endl << endl;
			//out_array[tot_matches].resetCoord();
			out_array[tot_matches].inputCoord(curr_Cx, curr_Cy);
			//out_array[tot_matches].resetShape();
			out_array[tot_matches].inputSide(curr_radius);
			tot_matches++;
		}
		else
			cout << " --- xxx --- Match not found." << endl << endl;		
	}

	cout << "Search complete; total match(es) found: " << tot_matches << endl << endl;
	return tot_matches;
}
/// Part 2 : stop

#endif
