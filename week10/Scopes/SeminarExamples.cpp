// SeminarExamples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Examples.h"


int main()
{
    
    property::color the_color = property::green;
    string color_name;

    color_name = property::colorEnum2name(the_color);

    cout << "Color enum is: " << the_color << endl;

    cout << "Color name is: " << color_name << endl;

    property::material the_material = property::wood;
    string material_name;

    material_name = property::materialEnum2name(the_material);

    cout << "Material enum is: " << the_material << endl;

    cout << "Material name is: " << material_name << endl;
    // another variable using different colors with the same name

    rainbow::color rainbow_col;
    rainbow_col = rainbow::green;
    cout << "Rainbow Color enum is: " << rainbow_col << endl;

    cout << "Done !\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
