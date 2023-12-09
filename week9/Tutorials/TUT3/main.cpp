#include <cstdlib>

#include "Polygon_w_color.h"
#include "square.h"
//#include <iostream>
//using namespace std;

// rand, srand
#include <time.h>

void test_static_counters()
{
    cout << "Opening printout; before any rectangle is instantiated" << endl;
    rectangle::printRectangleCount();
    rectangle testobj1;
    cout << endl<< "Next printout: one rectangle instantiated" << endl; 
    rectangle::printRectangleCount();
    cout << "testobj1 ID: " << testobj1.getRectangleID() << endl;
    testobj1.inputRandomSides();
    cout << endl << "Next printout: that rectangle has also been initialized with valid geometry" << endl;
    rectangle::printRectangleCount();
    {
        cout << endl << "Entering a local scope:" << endl;
        const int localaraysize = 5;
        rectangle testobjarray[localaraysize];
        cout << endl << "Next printout: array of rectangles instantiated" << endl;
        rectangle::printRectangleCount();
        for (int i = 0; i < localaraysize; i++)
        {
            cout << "  testobjarray[" << i << "] ID: " << testobjarray[i].getRectangleID() << endl;
            cout << "  input random sides and then print summary." << endl;
            testobjarray[i].inputRandomSides();
            rectangle::printRectangleCount();
        }
        cout << endl << "Exiting local scope" << endl << endl;
    }
    cout << "Print summary (again)" << endl;
    rectangle::printRectangleCount();
    
    cout << endl << "Reset one rectangle and print summary again" << endl;
    testobj1.reset();
    rectangle::printRectangleCount();
    cout << "Set random values again " << endl;
    testobj1.inputRandomSides();
    testobj1.printRectangleInfo();

    {
        cout << endl << "Enteing (another) local scope and instantiating testobj2: " << endl;
        rectangle testobj2; 
        testobj2.printRectangleInfo();

        cout << endl << "perform 'brute force copy' obj2 = obj1;" << endl;
        testobj2 = testobj1;
        // instead, do this:
        //testobj2.inputSides(testobj1.getSide(1) , testobj1.getSide(2));
        
        cout << "Print summary for obj1" << endl;
        testobj1.printRectangleInfo();
        cout << endl << "Print summary for obj2" << endl;
        testobj2.printRectangleInfo();
        cout << endl << "Do you see the problem?" << endl;
    }
    cout << endl << "Exiting local scope; Printing summary (last time)" << endl;
    rectangle::printRectangleCount();
    cout << "Print summary for obj1" << endl;
    testobj1.printRectangleInfo();
    cout << endl << "Do you see the even bigger problem now?" << endl;
        
}

void main()
{
    test_static_counters();
    system("PAUSE");
}


