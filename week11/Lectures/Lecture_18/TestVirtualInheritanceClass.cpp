// #pragma once

#include <iostream>
#include <string>
using namespace std;


class baseClass {
protected:
	int baseVal;
public:
	baseClass() { baseVal = 10; }
	// try with and without specifing the qualifier: "virtual". 
	// Note: when you specify "virtual" before printInfo, you should do it for BOTH the base and ALL its derived classes 	
	virtual void printInfo()	
	{
		cout << "This is function printInfo() as defined by baseClass" << endl;		
		cout << " baseVal: " << baseVal << endl << endl;
	}
	
	void testFunction()
	{
		cout << "This is function testFunction() as defined by baseClass." << endl;
		cout << "This function now calls fuction printInfo(): " << endl;
		// printInfo();
	}	
};


class derivedClassA : public baseClass {
protected:
	float derivedVal;
public:	
	derivedClassA() { baseVal = 20; derivedVal = 200.5; }
	virtual void printInfo()
	{
		cout << "This is function printInfo() as defined by derivedClass" << endl;
		cout << " baseVal: " << baseVal << endl;
		cout << " derivedVal: " << derivedVal << endl << endl;
	}
};


class derivedClassB : public baseClass {
protected:
	string derivedValB;
public:
	derivedClassB() { baseVal = 30; derivedValB = "a different type of variable"; }
	virtual void printInfo()
	{
		cout << "This is function printInfo() as defined by derivedClassB" << endl;
		cout << " baseVal: " << baseVal << endl;
		cout << " derivedValB: " << derivedValB << endl << endl;
	}
};

void TestVirtualInheritance()
{
	int temp_num;
	baseClass testBase;
	derivedClassA testDeriv;
	derivedClassB testDerivB;

	//First: try printinfo not defined as virtual
	//  step 1: test printinfo
	//  Step 2: test testFunction
	//Second: try printinfo defined as virtual
	//  step 1: test printinfo
	//  Step 2: test testFunction
	
	bool test_printInfo = true;
	///
	bool test_testFunction = test_printInfo;


	cout << "Base first:" << endl;
	if (test_printInfo)
		testBase.printInfo();
	if (test_testFunction)
		testBase.testFunction();


	cout << endl << "Now DerivA:" << endl;
	if (test_printInfo)
		testDeriv.printInfo();
	if (test_testFunction)
		testDeriv.testFunction();


	cout << endl << "Now Deriv B:" << endl;
	if (test_printInfo)
		testDerivB.printInfo();
	if (test_testFunction)
		testDerivB.testFunction();


	//cout << "Pause; Insert number + ENTER to progress\n";
	//cin >> temp_num;
}

int main(){

	TestVirtualInheritance();
	return 0;
}
