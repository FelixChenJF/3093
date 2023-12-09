#ifndef PetExample_h
#define PetExample_h
#include "RectangleExample.h"

class pet{
public:
	// enumerator: finite set of choices for the colors 
	// blank and color_stop "bookend" the allowed colors
	enum petTypeOptions { blank = 0, dog, cat, fish, rabbit, hamster, pet_stop };
protected:	
	// variables
	double weight_kg;
	petTypeOptions petType;
	// initialization flag
	bool init_flag;		
public:
	// constructor
	pet()
	{
		// basic initialization
		init_flag = false;
		petType = blank;
	}
	// gets	
	bool getWeight(double& out_weight_kg)
	{
		bool success = false;
		if (isInitialized())
		{
			out_weight_kg = weight_kg;
			success = true;
		}
		else
			cout << "Error in getWeight(): Pet weight NOT initialized " << endl;
		return success;
	}
	bool getPetType(petTypeOptions& out_petType)
	{
		bool success = false;
		if (petType != blank)		
		{
			out_petType = petType;
			success = true;
		}
		else
			cout << "Error in getPetType(): Pet type NOT initialized " << endl;
		return success;
	}
	bool getPetType(string& out_petType_str)
	{
		petTypeOptions out_petType;
		out_petType_str = "Not assigned";
		bool success = getPetType(out_petType);
		if (success)
			switch (out_petType) {
			case blank:
				out_petType_str = "blank";
				break;
			case dog:
				out_petType_str = "dog";
				break;
			case cat:
				out_petType_str = "cat";
				break;
			case fish:
				out_petType_str = "fish";
				break;
			case rabbit:
				out_petType_str = "rabbit";
				break;
			case hamster:
				out_petType_str = "hamster";
				break;
			case pet_stop:
				out_petType_str = "petstop";
				break;
			}				
		return success;
	}
	// set
	bool inputPetAndWeight(petTypeOptions in_petType, double in_weight_kg)
	{
		bool result = false;
		if (!isInitialized())
		{
			if ((in_weight_kg > 0) && (in_petType > blank) && (in_petType < pet_stop))
			{
				weight_kg = in_weight_kg;
				petType = in_petType;
				init_flag = true;
				result = true;
			}
			else
				cout << "Error in inputPetAndWeight(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputPetAndWeight(): Pet is already initialized " << endl;
		return result;

	}
	bool inputPetAndWeightFromKeyboard()
	{
		if (!isInitialized())
		{
			int in_petType;
			cout << "Please choose one of the following Pet types (then hit ENTER)" << endl;
			cout << " dog = " << dog << ";" << endl;
			cout << " cat = " << cat << ";" << endl;
			cout << " fish = " << fish << "." << endl;
			cout << " rabbit = " << rabbit << "." << endl;
			cout << " hamster = " << hamster << "." << endl;
			cin >> in_petType;

			double in_weight_kg;
			cout << "Please enter pet weight in kg (then hit ENTER)" << endl;
			cin >> in_weight_kg;
			return inputPetAndWeight((petTypeOptions)in_petType, in_weight_kg);
		}
		else
			cout << "Error in inputPetAndWeightFromKeyboard(): Pet is already initialized " << endl;
		return false;
	}
	bool updatePetWeight(double in_weight_kg)
	{
		bool out;
		if (isInitialized())
		{
			if ((in_weight_kg > 0))
			{
				weight_kg = in_weight_kg;
			}else{
				cout << "Error in updatePetWeight(): Incorrect input values" << endl;
				out = false;
			}
		}else{
			cout << "Error in updatePetWeight(): Pet is not initialized " << endl;
			out = false;
		}
		return out;

	}
	void inputRandomValues(double max_weight_kg = 10)
	{
		if (!isInitialized())
		{
			double in_weight_kg;
			int rand_weight_kg = 0;
			int in_petType, rand_petType = 0;

			// check that max_val is a meaningful value
			if (max_weight_kg <= 0)
				max_weight_kg = 10;

			// this produces a random integer within (0 , RAND_MAX]
			while (rand_weight_kg == 0)
				rand_weight_kg = rand();
			while (rand_petType == 0)
				rand_petType = rand();
			// this produces a random double within (0 , max_val]
			in_weight_kg = (((double)rand_weight_kg) / (RAND_MAX)) * max_weight_kg;
			in_petType = (((double)rand_petType) / (RAND_MAX)) * (pet_stop - 1);
			inputPetAndWeight((petTypeOptions)in_petType, in_weight_kg);
		}
		else
			cout << "Error in inputRandomValues(): Rectangle is already initialized " << endl;
	}
	void reset()
	{
		if (isInitialized())
			init_flag = false;
	}
	// utility
	bool isInitialized(){return init_flag;}
	void printPetInfo()
	{
		if(isInitialized())
		{
			string out_petType_str;
			getPetType(out_petType_str);
			cout << "Pet Type is: " << out_petType_str << " (" << petType << ")" << endl;
			cout << "Pet Weight is: " << weight_kg << " kg" << endl;
		}
		else
			cout << "printPetInfo(): Pet not initialized " << endl;
	}
};
#endif
