#ifndef PolygonInherithance_h
#define PolygonInherithance_h

// for rand() and sqrt()
#include <cstdlib>
#include <math.h> 

#include <iostream>
using namespace std;

class polygonUnits{
public:		
	enum polygonUnitsOptions{blank=0, mm, cm, m, km, inch, foot, mile, upperNonValid};
	polygonUnitsOptions the_unit;
private:
	static const int MAX_SIZE=10;
	static double conversionFactorMatrixFrom_i_To_j[MAX_SIZE][MAX_SIZE];
	static bool conversionFactorMatrixSet;
	void setConversionFactorMatrix()
	{
		// this is performed only once (at first use)
		if(!conversionFactorMatrixSet)
		{
			int i, j; // conversion from i to j:
			//        0      1   2  3  4    5      6    7
 			// i = blank=0, mm, cm, m, km, inch, foot, mile;
			// j = blank=0, mm, cm, m, km, inch, foot, mile;
			i=1; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=0.1;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1/1000.0;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=(1/1000.0) * (1/1000.0);
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=1/25.4;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=1/304.8;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(1.609*1000000);
			//
			i=2; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=10;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1/100.0;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=(1/100.0)/1000.0;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=1/2.54;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=1/30.48;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(1.6093*100000);
			//
			i=3; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=1000;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=100;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=1/1000.0;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=39.3701;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=3.28084;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(1609.344);
			//
			i=4; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=1000*1000;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=100*1000;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1000;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=39370.079;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=3280.84;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(1609.0);
			//
			i=5; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=25.4;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=2.54;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1/39.37;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=1/39370.079;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=1/12.0;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(63360);
			//
			i=6; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=304.8;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=30.48;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1/3.281;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=1/3280.84;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=12;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1/(5280.0);
			//
			i=7; j=1; conversionFactorMatrixFrom_i_To_j[i][j]=1609344.9;
			j=2; conversionFactorMatrixFrom_i_To_j[i][j]=160934.44;
			j=3; conversionFactorMatrixFrom_i_To_j[i][j]=1609.344;
			j=4; conversionFactorMatrixFrom_i_To_j[i][j]=1.6093;
			j=5; conversionFactorMatrixFrom_i_To_j[i][j]=63360;
			j=6; conversionFactorMatrixFrom_i_To_j[i][j]=5280;
			j=7; conversionFactorMatrixFrom_i_To_j[i][j]=1;
			//
			conversionFactorMatrixSet=true;
		}
	}
public:
	polygonUnits(){the_unit=blank;}
	bool checkUnit(polygonUnitsOptions inp_val) const 
	{
		bool result;
		switch(inp_val){
		case mm:
		case cm:
		case m:
		case km:
		case inch:
		case foot:
		case mile:
			result=true;
			break;
		default:
			cout << "Error in polygonUnits checkUnit(): init not recognized" << endl;
			result=false;
		}
		return result;
	}
	bool setUnit(polygonUnitsOptions inp_val)
	{
		bool result = checkUnit(inp_val);
		if(result)
			the_unit=inp_val;
		else
			cout << "Error in polygonUnits setUnit(): init not recognized" << endl;
		return result;
	}
	polygonUnitsOptions getUnit() const {return the_unit;}
	double conversionFactor(polygonUnitsOptions from_val, polygonUnitsOptions to_val) 
	{
		setConversionFactorMatrix();
		if( (from_val>=0 && from_val<MAX_SIZE) && (to_val>=0 && to_val<MAX_SIZE) )
			if( (from_val>blank && from_val<upperNonValid) && (to_val>blank && to_val<upperNonValid) )
				return conversionFactorMatrixFrom_i_To_j[from_val][to_val];
		cout << " Error in conversionFactor(): invalid input value(s)" << endl;
		return 1;
	}	
	void printAllUnitOptions() const
	{
		for(int i=mm; i<upperNonValid; i++)
		{
			cout << " Select " << i << " to set";
			printUnit((polygonUnitsOptions)i);
		}
	}
	void printUnit(polygonUnitsOptions inp_val) const
	{
		switch(inp_val){
		case mm:
			cout << " mm " << endl;			
			break;
		case cm:
			cout << " cm " << endl;			
			break;
		case m:
			cout << " m " << endl;			
			break;
		case km:
			cout << " km " << endl;			
			break;
		case inch:
			cout << " inch " << endl;			
			break;
		case foot:
			cout << " foot " << endl;			
			break;
		case mile:
			cout << " mile " << endl;			
			break;
		default:
			cout << " Unsupported unit ";
		};
	}	
};

// initiialization of the static member
bool polygonUnits::conversionFactorMatrixSet=false;
double polygonUnits::conversionFactorMatrixFrom_i_To_j[polygonUnits::MAX_SIZE][polygonUnits::MAX_SIZE];


class basic_polygon{
protected:
	// variables
	double area;
	double perimeter;
	// initialization flag
	bool init_flag;
	polygonUnits unit;
	void basic_initialization()
	{
		init_flag=false;
		// default unit
		unit.setUnit(polygonUnits::cm);
	}
	virtual void updateSides(double factor)
	{
		cout << "to be done for each derived class" << endl;
	}
	void set_init_flag(bool setval)
	{
		if(init_flag!=setval)
		{
			init_flag=setval;			
		}
	}
	// this produces a random double within (0 , max_val]
	double getRandomSide(double max_val=100) const
	{
			double in_sideA;
			int rand_valueA=0;
			// check that max_val is a meaningful value
			if(max_val<=0)
				max_val=100;
			// this produces a random integer within (0 , RAND_MAX]
			while(rand_valueA==0)
				rand_valueA=rand();
			// this produces a random double within (0 , max_val]
			in_sideA=( ((double)rand_valueA)/(RAND_MAX) )*max_val;
			return in_sideA;
	}
	void updateUnit(polygonUnits::polygonUnitsOptions inp_val)
	{
		polygonUnits::polygonUnitsOptions curr_val=unit.getUnit();
		if(curr_val != inp_val && unit.checkUnit(inp_val))
		{
			double factor=unit.conversionFactor(curr_val, inp_val);
			updateSides(factor);
			perimeter*=factor;
			area*=(factor*factor);
		}
	}
public:
	basic_polygon(){basic_initialization();}
	void setUnit(polygonUnits::polygonUnitsOptions inp_val)
	{
		if(unit.checkUnit(inp_val))
		{
			if(init_flag)
				updateUnit(inp_val);
			unit.setUnit(inp_val);
		}
		else
			cout << "Input unit is not valid" << endl;
	}
	void setUnitFromKeyboard()
	{
		polygonUnits::polygonUnitsOptions inp_val;
		int temp_inp_val;
		cout << " Current unit:" << endl; printUnit();
		cout << " Possible options are: " << endl; unit.printAllUnitOptions();
		cout << "Please enter the preferred unit (then hit ENTER)" << endl;
		cin >> temp_inp_val;
		inp_val=(polygonUnits::polygonUnitsOptions) temp_inp_val;
		setUnit(inp_val);
		printUnit();
	}
	void printUnit() const 
	{
		cout << " Unit is : ";
		unit.printUnit(unit.getUnit());
		cout << endl;		
	}
	double getArea() const  
	{
		if(isInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;		
	}
	double getPerimeter() const  	
	{
		if(isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;		
	}
	bool isInitialized() const {return init_flag;}
	void resetPolygon(){set_init_flag(false);}
	virtual void printPolygonInfo() const 
	{
		if(isInitialized())
		{
			cout << " Area is: " << getArea() << endl;	
			cout << " Perimeter is: " << getPerimeter() << endl;			
		}
		else
			cout << "printPolygonInfo(): Polygon dimensions not initialized " << endl;
		printUnit();
	}
};

class rectangle_inh : public basic_polygon{
protected:	
	// variables
	double sideA, sideB;
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
	virtual void updateSides(double factor)
	{
		sideA *= factor;
		sideB *= factor;
	}
public:		
	double getSide(int sidenum) const 
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
	virtual void inputSides(double in_sideA, double in_sideB)
	{
		if(!isInitialized())
		{
			if(in_sideA>0 && in_sideB>0)
			{
				sideA=in_sideA;
				sideB=in_sideB;
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
	virtual void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;
			printUnit();
			cout << "Please enter dimension of side A of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideA;
			cout << "Please enter dimension of side B of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideB;
			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Rectangle is already initialized " << endl;
	}
	virtual void printPolygonInfo() const 
	{
		if(isInitialized())
		{
			cout << "Rectangle:" << endl;
			cout << " Side A is: " << getSide(1) << endl;
			cout << " Side B is: " << getSide(2) << endl;
			basic_polygon::printPolygonInfo();
		}
		else
			cout << "printPolygonInfo(): Rectangle dimensions not initialized " << endl;
	}
	virtual void inputRandomSides(double max_val=100)
	{
		if(!isInitialized())
		{
			// this produces a random double within (0 , max_val]
			double in_sideA=getRandomSide(max_val);
			double in_sideB=getRandomSide(max_val);
			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputRandomSides(): Rectangle is already initialized " << endl;
	}
};

class square_inh : public rectangle_inh{
public:	
	double getSide(int sidenum=1) const 
	{
		return rectangle_inh::getSide(1);
	}
	virtual void inputSides(double in_sideA, double in_sideB=0)
	{
		rectangle_inh::inputSides(in_sideA, in_sideA);
	}
	void inputSide(double in_side) { inputSides(in_side);}
	virtual void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA;
			printUnit();
			cout << "Please enter dimension of side of the Square (then hit ENTER)" << endl;
			cin >> in_sideA;
			inputSides(in_sideA);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Square is already initialized " << endl;
	}
	virtual void printPolygonInfo() const 
	{
		if(isInitialized())
		{
			cout << "Square :" << endl;
			cout << " Side is: " << getSide(1) << endl;
			basic_polygon::printPolygonInfo();
		}
		else
			cout << "printPolygonInfo(): Square dimensions not initialized " << endl;
	}
	virtual void inputRandomSides(double max_val=100)
	{	
		if(!isInitialized())
		{
			//rectangle_inh::inputRandomSides(max_val);
			//double rand_side=getSide();
			//resetPolygon();
			double rand_side = getRandomSide(max_val);
			inputSides(rand_side);
		}
		else
			cout << "Error in inputRandomSides(): Square is already initialized " << endl;
	}
};


class triangle_inh : public basic_polygon{
protected:	
	// variables
	double sideA, sideB, sideC;
	void computeArea()
	{
		if(isInitialized())
		{
			// Using Heron's formula
			double semiper=(sideA + sideB + sideC)/2;
			area=sqrt( semiper*(semiper-sideA)*(semiper-sideB)*(semiper-sideC)  );			
		}
	}
	void computePerimeter()
	{
		if(isInitialized())
			perimeter=(sideA+sideB+sideC);
	}	
	bool checkSides(double in_sideA, double in_sideB, double in_sideC)
	{
		bool result = false;
		if(in_sideA>0 && in_sideB>0 && in_sideC>0)
		{
			// find the longest side:
			double largest=0;
			largest=(in_sideA>largest ? in_sideA : largest);
			largest=(in_sideB>largest ? in_sideB : largest);
			largest=(in_sideC>largest ? in_sideC : largest);
			// longest side must be smaller than the sum of the other two
			if( largest<(in_sideA+in_sideB+in_sideC-largest) )
				result = true;
		}
		return result;
	}
	virtual void updateSides(double factor)
	{
		sideA *= factor;
		sideB *= factor;
		sideC *= factor;
	}
public:	
	double getSide(int sidenum) const 
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
	void inputSides(double in_sideA, double in_sideB, double in_sideC)
	{
		if(!isInitialized())
		{
			if(checkSides(in_sideA, in_sideB, in_sideC))
			{
				sideA=in_sideA;
				sideB=in_sideB;
				sideC=in_sideC;
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
	virtual void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB, in_sideC;
			printUnit();
			cout << "Please enter dimension of side A of the Triangle (then hit ENTER)" << endl;
			cin >> in_sideA;
			cout << "Please enter dimension of side B of the Triangle (then hit ENTER)" << endl;
			cin >> in_sideB;
			cout << "Please enter dimension of side C of the Triangle (then hit ENTER)" << endl;
			cin >> in_sideC;
			inputSides(in_sideA, in_sideB, in_sideC);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Triangle is already initialized " << endl;
	}
	void printPolygonInfo() const 
	{
		if(isInitialized())
		{
			cout << "Triangle:" << endl;
			cout << " Side A is: " << getSide(1) << endl;
			cout << " Side B is: " << getSide(2) << endl;
			cout << " Side C is: " << getSide(3) << endl;
			basic_polygon::printPolygonInfo();
		}
		else
			cout << "printPolygonInfo(): Triangle dimensions not initialized " << endl;
	}
	virtual void inputRandomSides(double max_val=100)
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB, in_sideC;			
			while((!isInitialized()))
			{	
				// this produces a random double within (0 , max_val]
				in_sideA=getRandomSide(max_val);
				in_sideB=getRandomSide(max_val);
				in_sideC=getRandomSide(max_val);
				if(checkSides(in_sideA, in_sideB, in_sideC))
					inputSides(in_sideA, in_sideB, in_sideC);
			}
		}
		else
			cout << "Error in inputRandomSides(): Rectangle is already initialized " << endl;
	}
};

// left to students: implement a class for the "right angle triangle" using inherithance. 

#endif
