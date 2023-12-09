#ifndef RectangleExample_h
#define RectangleExample_h

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>     


class rectangle {
protected:
	// static member variable used for count
	static int rectangle_instances_created_count;
	static int rectangle_instances_alive_count;
	static int initialized_rectangle_instances_count;
	
	// progressive ID for each rectangle
	
	// const int rectangle_ID;	
	// temporary: non-constant (comment out)
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
		if (isInitialized())
			area = sideA * sideB;
	}
	void computePerimeter()
	{
		if (isInitialized())
			perimeter = 2 * (sideA + sideB);
	}

	void set_init_flag(bool setval)
	{
		if (init_flag != setval)
		{
			init_flag = setval;
			if (setval)
				initialized_rectangle_instances_count++;
			else
				initialized_rectangle_instances_count--;
		}
	}
	void basicInitialization()
	{
		// basic initialization (init_flag is still undetermined)
		init_flag = false;
		//set the ID and update the count.
		//rectangle_ID=rectangle_instances_created_count++;
		rectangle_instances_alive_count++;
	}
public:
	// constructor
	rectangle() : rectangle_ID(rectangle_instances_created_count++)
	{
		basicInitialization();
	}
	// overloaded constructor
	rectangle(double in_sideA, double in_sideB) : rectangle_ID(rectangle_instances_created_count++)
	{
		basicInitialization();
		inputSides(in_sideA, in_sideB);
	}
	// destructor
	~rectangle()
	{
		set_init_flag(false);
		rectangle_instances_alive_count--;
	}

	void copyFrom(const rectangle& other)
	{
		//const rectangle* test_this = this;
		if ((this != &other) && (other.isInitialized()))
		{
			resetRectangle();
			inputSides(other.getSide(1), other.getSide(2));
		}
	}
	// copy constructor
	rectangle(const rectangle& other) : rectangle_ID(rectangle_instances_created_count++)
	{
		basicInitialization();
		copyFrom(other);
		// temporarily: notify this has been done
		cout << " ====> Element copied via constructor" << endl;
	}

	// operator "="
	rectangle& operator = (const rectangle& other)
	{
		this->copyFrom(other);
		return *this;
	}

	// connect to the operator "+="
	void addSidesFrom(const rectangle& other)
	{
		// if this object is not initialized: 
		// just copy the other object (if initialized)
		if (!(isInitialized()))
			copyFrom(other);
		else
			if (other.isInitialized())
			{	// both this and the other object are initialized: 
				//copy the current sides (prior to reset)
				double tempA_this = getSide(1); double tempB_this = getSide(2);
				double tempA_other = other.getSide(1); double tempB_other = other.getSide(2);
				resetRectangle();// then add the two sides
				inputSides(tempA_this + tempA_other, tempB_this + tempB_other);
			}
	}

	// operator "+="
	rectangle& operator += (const rectangle& other)
	{
		// add the other object to the curren one;
		addSidesFrom(other);
		// return the reference to the current object;
		return *this;
	}
	
	// operator "+"
	rectangle operator + (const rectangle& other)
	{
		// temp variable is created copying content from this object
		rectangle temp(*this);
		// temp is "incremented" with the other object 
		temp += other;
		// return (by value) temp 
		return temp;
	}

	// connect to the operator "<"
	bool isAvgSideSmallerThan(const rectangle& other) const
	{
		bool result = false;
		// both objects need to be initialized to compare
		if (isInitialized() && other.isInitialized())
		{
			double this_avg_side = (getSide(1) + getSide(2)) / 2;
			double other_avg_side = (other.getSide(1) + other.getSide(2)) / 2;
			if (this_avg_side < other_avg_side)
				result = true;
		}
		return result;
	}

	// operator "<"
	bool operator < (const rectangle& other) const 
	{ 
		return isAvgSideSmallerThan(other); 
	}

	// connect to the operator "<"
	bool isAvgSideSmallerThan(const double& threshold) const
	{
		bool result = false;
		// object needs to be initialized to compare
		if (isInitialized())
		{
			double this_avg_side = (getSide(1) + getSide(2)) / 2;
			if (this_avg_side < threshold)
				result = true;
		}
		return result;
	}

	// operator "<"
	bool operator < (const double& threshold) const 
	{ 
		return isAvgSideSmallerThan(threshold); 
	}

	// gets	
	double getArea() const
	{
		if (isInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;
	}

	double getPerimeter() const
	{
		if (isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;
	}

	bool isInitialized() const { return init_flag; }

	double getSide(int sidenum) const
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
				set_init_flag(true);
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

	void printRectangleInfo() const
	{
		cout << "Rectangle ID is: " << getRectangleID() << endl;
		if (isInitialized())
		{
			cout << "Rectangle side A is: " << getSide(1) << endl;
			cout << "Rectangle side B is: " << getSide(2) << endl;
			cout << "Rectangle area is: " << getArea() << endl;
			cout << "Rectangle perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << "printRectangleInfo(): Rectangle dimensions not initialized " << endl;
	}

	// selects random values for each side, within [0, max_val]
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

	// selects random values for each side, within [0, max_val]
	void inputRandomSides(double min_val, double max_val)
	{
		if (!isInitialized())
		{
			if (min_val > 0 && min_val < max_val)
			{
				double in_sideA, in_sideB;
				// set random sides in the range [0, (max_val - min_val)]
				inputRandomSides(max_val - min_val);
				in_sideA = getSide(1); in_sideB = getSide(2);
				// offset each side by min_val: values are now in the requred range
				in_sideA += min_val; in_sideB += min_val;
				// use the set function to enter these new values;
				reset(); inputSides(in_sideA, in_sideB);
			}
			else
				cout << "Error in inputRandomSides(): input bounds not valid" << endl;
		}
		else
			cout << "Error in inputRandomSides(): Rectangle is already initialized " << endl;
	}

	void resetRectangle() 
	{ 
		set_init_flag(false); 
	}

	void reset() 
	{ 
		resetRectangle(); 
	} // a duplicate: just because I used the short name in some eamples

	int getRectangleID() const 
	{ 
		return rectangle_ID; 
	}

	int getAciveRectanglesCount() const 
	{ 
		return rectangle_instances_alive_count; 
	}

	int getInitializedRectanglesCount() const 
	{ 
		return initialized_rectangle_instances_count; 
	}

	// static function to get the 
	static void printRectangleCount()
	{
		cout << "Total numbers for Rectangle instantiations: " << endl;
		cout << " TOT instatntiated Rectangles (currently active or not): " << rectangle_instances_created_count << endl;
		cout << " TOT currently Active Rectangles: " << rectangle_instances_alive_count << endl;
		cout << " TOT currently Initialized Rectangles: " << initialized_rectangle_instances_count << endl;
	}
};

// init static members only once (otherwise complier tries to allocate twice)
int rectangle::rectangle_instances_created_count = 0;
int rectangle::rectangle_instances_alive_count = 0;
int rectangle::initialized_rectangle_instances_count = 0;


#endif
